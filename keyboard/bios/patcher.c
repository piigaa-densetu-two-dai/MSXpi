/*
 * ～ ピーガー伝説のUSB Keyboard BIOS Pacther ～
 */

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "loader.h"
#include "kana1.h"
#include "kana2.h"

static void patch_key(uint8_t *image, uint16_t start, uint16_t end)
{
	int i;
	/* mingwにはmemmem()が無い模様 */
	for (i = start ; i < end ; i++) {
		if ((image[i] == 0xdb) && (image[i + 1] == 0xaa)) { /* IN 0xaa */
			image[i + 1] = 0x08;
		}
		if ((image[i] == 0xd3) && (image[i + 1] == 0xaa)) { /* OUT 0xaa */
			image[i + 1] = 0x08;
		}
		if ((image[i] == 0xdb) && (image[i + 1] == 0xa9)) { /* IN 0xa9 */
			image[i + 1] = 0x09;
		}
	}
}

static void patch_led(uint8_t *image, uint16_t start, uint16_t end)
{
	int i;
	/* mingwにはmemmem()が無い模様 */
	for (i = start ; i < end ; i++) {
		if ((image[i] == 0xd3) && (image[i + 1] == 0xab)) { /* OUT 0xab */
			image[i + 1] = 0x08;
		}
	}
}

int main(int argc, char *argv[])
{
	int fd;
	uint8_t image[1024 * 64];

	if (argc != 3) {
		fprintf(stderr, "～ ピーガー伝説のUSB Keyboard BIOS Pacther ～\n");
		fprintf(stderr, "使い方: %s <入力ファイル> <出力ファイル>\n", argv[0]);
		return 1;
	}

	memset(image, 0xff, sizeof(image));

	/* BIOSファイル入力 */
	if ((fd = open(argv[1], O_BINARY | O_RDONLY)) < 0) {
		perror("open");
		return 1;
	}
	if (read(fd, &image[0x0000], 0x8000) != 0x8000) {
		perror("read");
		close(fd);
		return 1;
	}
	close(fd);

	/* BIOSにパッチ当て */
	switch (image[0x0002]) {
	case 0xd7: /* MSX */
		printf("Patching MSX ROM\n");
		patch_key(image, 0x046F, 0x049D - 1); /* BREAKX */
		patch_key(image, 0x0C3C, 0x0D6A - 1); /* KEYINT */
		patch_key(image, 0x11EE, 0x1253 - 1); /* GTSTCK */
		patch_key(image, 0x1452, 0x145F - 1); /* SNSMAT */
		patch_led(image, 0x0F3D, 0x0F64 - 1); /* CHGCAP (LED) */
		memcpy(&image[0x0F1F], kana1_bin, sizeof(kana1_bin)); /* MSX専用 かな (LED) */
		memcpy(&image[0x0E2B], "*+/0123456789-,.", 0x10); /* テンキーテーブル */
		break;
	case 0x16: /* MSX2以降 */
		printf("Ptaching MSX2/2+ ROM\n");
		patch_key(image, 0x0564, 0x0592 - 1); /* BREAKX */
		patch_key(image, 0x0C3C, 0x0D6A - 1); /* KEYINT */
		patch_key(image, 0x11E4, 0x1249 - 1); /* GTSTCK */
		patch_key(image, 0x0BEC, 0x0BF9 - 1); /* SNSMAT */
		patch_led(image, 0x0F3D, 0x0F64 - 1); /* CHGCAP (LED) */
		memcpy(&image[0x111C], kana2_bin, sizeof(kana2_bin)); /* MSX2以降専用 かな (LED) */
		memcpy(&image[0x0E2B], "*+/0123456789-,.", 0x10); /* テンキーテーブル */
		break;
	default:
		printf("Unknown ROM\n");
		return 1;
	}

	/* ローダープログラム */
	memcpy(&image[0x8000], loader_bin, sizeof(loader_bin));

	/* ROMファイル出力 */
	if ((fd = open(argv[2], O_BINARY | O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0) {
		perror("open");
		return 1;
	}
	write(fd, image, sizeof(image));
	close(fd);

	return 0;
}
