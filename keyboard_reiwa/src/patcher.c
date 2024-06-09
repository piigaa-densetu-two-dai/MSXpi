#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "kana1.h"
#include "kana2.h"

static void patch_key(uint8_t *bios, uint16_t start, uint16_t end)
{
	uint16_t i;
	/* mingwにはmemmem()が無い模様 */
	for (i = start ; i < end ; i++) {
		if ((bios[i] == 0xdb) && (bios[i + 1] == 0xaa)) { /* IN 0xaa */
			bios[i + 1] = 0x08;
		}
		if ((bios[i] == 0xd3) && (bios[i + 1] == 0xaa)) { /* OUT 0xaa */
			bios[i + 1] = 0x08;
		}
		if ((bios[i] == 0xdb) && (bios[i + 1] == 0xa9)) { /* IN 0xa9 */
			bios[i + 1] = 0x09;
		}
	}
}

static void patch_led(uint8_t *bios, uint16_t start, uint16_t end)
{
	uint16_t i;
	/* mingwにはmemmem()が無い模様 */
	for (i = start ; i < end ; i++) {
		if ((bios[i] == 0xd3) && (bios[i + 1] == 0xab)) { /* OUT 0xab */
			bios[i + 1] = 0x08;
		}
	}
}

int main(int argc, char *argv[])
{
	int fd;
	uint8_t bios[32768] = { 0 };

	if (argc != 3) {
		fprintf(stderr, "～ ピーガー伝説のUSBキーボードROMツール ～\n");
		fprintf(stderr, "使い方: %s <入力ROMファイル> <出力ROMファイル>\n", argv[0]);
		return 1;
	}
	if ((fd = open(argv[1], O_BINARY | O_RDONLY)) < 0) {
		perror("open");
		return 1;
	}
	if (read(fd, bios, sizeof(bios)) != sizeof(bios)) {
		perror("read");
		close(fd);
		return 1;
	}
	close(fd);

	/* BIOSにパッチ当て */
	if (bios[0x002d] == 0) { /* MSX */
		printf("MSX ROMにパッチ当て\n");
		patch_key(bios, 0x046F, 0x049D - 1); /* BREAKX */
		patch_key(bios, 0x0C3C, 0x0D6A - 1); /* KEYINT */
		patch_key(bios, 0x11EE, 0x1253 - 1); /* GTSTCK */
		patch_key(bios, 0x1452, 0x145F - 1); /* SNSMAT */
		patch_led(bios, 0x0F3D, 0x0F64 - 1); /* CHGCAP (LED) */
		memcpy(&bios[0x0F1F], kana1_bin, sizeof(kana1_bin)); /* MSX専用 かな (LED) */
		memcpy(&bios[0x0E2B], "*+/0123456789-,.", 0x10); /* テンキーテーブル */
		/* キー配列(KANAMD)を強制的にJISに設定 */
		bios[0x04B4] = 0x3e; /* JIS配列 */
		bios[0x04B5] = 0x01; /* JIS配列 */
	} else { /* MSX2以降 */
		printf("MSX2/2+/turboR ROMにパッチ当て\n");
		patch_key(bios, 0x0564, 0x0592 - 1); /* BREAKX */
		patch_key(bios, 0x0C3C, 0x0D6A - 1); /* KEYINT */
		patch_key(bios, 0x11E4, 0x1249 - 1); /* GTSTCK */
		patch_key(bios, 0x0BEC, 0x0BF9 - 1); /* SNSMAT */
		patch_led(bios, 0x0F3D, 0x0F64 - 1); /* CHGCAP (LED) */
		memcpy(&bios[0x111C], kana2_bin, sizeof(kana2_bin)); /* MSX2以降専用 かな (LED) */
		memcpy(&bios[0x0E2B], "*+/0123456789-,.", 0x10); /* テンキーテーブル */
		/* キー配列(KANAMD)を強制的にJISに設定 */
		bios[0x05A9] = 0x3e; /* JIS配列 */
		bios[0x05AA] = 0x01; /* JIS配列 */
	}

	if ((fd = open(argv[2], O_BINARY | O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0) {
		perror("open");
		return 1;
	}
	if (write(fd, bios, sizeof(bios)) != sizeof(bios)) {
		perror("write");
		close(fd);
		return 1;
	}
	close(fd);

	printf("完了\n");

	return 0;
}
