日本語USBキーボード用BIOS作成ツールです。
使用する実機のBIOS(スロット0の先頭32KB、日本版のみ)ファイルが必要です。
MSX(PV-7/HX-21)で動作確認しました。MSX2/MSX2+にも想像だけで対応してみました。
多分うまく動かないと思いますのでソース一式を付けておきます。makeにはsdcc-4.2.0が要ります。

使用法
patcher.exe bios.rom patched.rom

patched.romを64KBのEPROM等に書き込んで一番若い基本スロットに挿してください。
MSXπはどこでも良いので空いているスロットに挿してください。

---- メモ ----
IOWR 0x08
	0x00-0x0b ROWの指定
	0x0c CAPS LED ON
	0x0d CAPS LED OFF
	0x0e かな LED ON
	0x0f かな LED OFF

IOWR 0x09
	何もしない

IORD 0x08
	ROWの取得

IORD 0x09
	指定されたROWのデータを取得
