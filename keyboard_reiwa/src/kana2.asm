.org 0x111c
	cpl			; 反転(CAPSと論理を合わせる為)
	and	#0x01		; 0か1
	add	a, #0x0e	; eを足してeかf
	out	(0x08), a	; LED設定
	ret

.org 0x1130
	.db	#0xff		; パディング
