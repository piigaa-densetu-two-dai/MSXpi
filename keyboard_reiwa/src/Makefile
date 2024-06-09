CC=i686-w64-mingw32-gcc -O2 -fexec-charset=cp932 -Wall

.SUFFIXES: .asm .bin

all: patcher

.asm.bin:
	zasm --z80 -l0 -i $< -o $@

.bin.h:
	xxd -i $< | sed "s/unsigned char/const uint8_t/;/unsigned int/d" > $@

patcher: patcher.c kana1.h kana2.h
	$(CC) -o $@ $<
	strip $@

clean:
	$(RM) kana1.bin kana1.h kana2.bin kana2.h patcher
