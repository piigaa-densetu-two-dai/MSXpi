#include <stdio.h>
#include <string.h>
#include "uf2format.h"

int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: %s input.bin output.uf2\n", argv[0]);
		return 1;
	}
	FILE *f = fopen(argv[1], "rb");
	if (!f) {
		fprintf(stderr, "no such file: %s\n", argv[1]);
		return 1;
	}

	fseek(f, 0L, SEEK_END);
	uint32_t sz = ftell(f);
	fseek(f, 0L, SEEK_SET);

	const char *outname = argv[2];

	FILE *fout = fopen(outname, "wb");

	UF2_Block bl;
	memset(&bl, 0, sizeof(bl));

	bl.magicStart0 = UF2_MAGIC_START0;
	bl.magicStart1 = UF2_MAGIC_START1;
	bl.flags = 0x00002000;
	bl.magicEnd = UF2_MAGIC_END;
	bl.targetAddr = 0x10000000;
	bl.numBlocks = (sz + 255) / 256;
	bl.payloadSize = 256;
	bl.fileSize = 0xe48bff56;
	int numbl = 0;
	while (fread(bl.data, 1, bl.payloadSize, f)) {
		bl.blockNo = numbl++;
		fwrite(&bl, 1, sizeof(bl), fout);
		bl.targetAddr += bl.payloadSize;
		// clear for next iteration, in case we get a short read
		memset(bl.data, 0, sizeof(bl.data));
	}
	fclose(fout);
	fclose(f);
	return 0;
}
