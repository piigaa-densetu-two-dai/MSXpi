.area _HEADER (ABS)
.org 0x8000
	; ROMヘッダ
	.db #0x41, #0x42, #0x10, #0x80, #0x00, #0x00, #0x00, #0x00
	.db #0x00, #0x00, #0x00, #0x00, #0x00, #0x00, #0x00, #0x00

	; スロット
	in	a, (0xa8)
	and	a, #0b00110000
	srl	a
	srl	a
	ld	b, a		; b=00001100
	srl	a
	srl	a		; a=00000011
	ld	c, a		; c=00000011
	or	a, b		; a=00001111
	ld	b, a		; b=00001111

	; BIOS入れ替え(MSXディスク無し環境用)
	ld	ix, #3		; sp+3に格納されているスロット情報を読み出し
	add	ix, sp
	ld	a, (ix)
	and	a, #0b11110000	; page0/page1部分を更新
	or	a, b
	ld	(ix), a		; 書き戻し

	; FCC1(ディスク環境用) FFF7(MSX2用)
	ld	ix, #0xfcc1
	ld	(ix), c
	ld	ix, #0xfff7
	ld	(ix), c

	; キー配列(KANAMD)をJISに設定
	ld	ix, #0xfcad
	ld	(ix), #1

	ret
