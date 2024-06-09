KANAST = 0xfcac

.org 0x0f1f
	ld	hl, #KANAST	; 元のまま
	ld	a, (hl)		; 元のまま
	cpl			; 元のまま
	ld	(hl), a		; 元のまま
	ld	a, (hl)		; 元のまま
	cpl			; 反転(CAPSと論理を合わせる為)
	and	#0x01		; 0か1
	add	a, #0x0e	; eを足してeかf
	out	(0x08), a	; LED設定
	ret

.org 0x0f35
	.db	#0xff		; パディング
