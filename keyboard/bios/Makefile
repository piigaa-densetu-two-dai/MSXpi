#CC=i686-w64-mingw32-gcc -fexec-charset=cp932
CC=gcc

.SUFFIXES: .rel .ihx .bin

all: patcher

.s.rel:
	sdasz80 -o $<

.rel.ihx:
	sdldz80 -i $<

.ihx.bin:
	objcopy -I ihex -O binary $< $@

.bin.h:
	xxd -i $< | sed "s/unsigned char/const uint8_t/;/unsigned int/d" > $@

patcher: patcher.c loader.h kana1.h kana2.h
	$(CC) -O2 -Wall -o $@ $<

strip: patcher
	strip $<

clean:
	$(RM) loader.bin loader.h loader.ihx loader.rel kana1.bin kana1.h kana1.ihx kana1.rel kana2.bin kana2.h kana2.ihx kana2.rel patcher
