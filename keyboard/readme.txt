日本語USBキーボードインターフェースファームウェアです。
使用する実機のBIOS(スロット0の先頭32KB、日本版のみ)ファイルが必要です。
相性の悪いキーボードがあるかもしれませんご注意ください。

使用法

1. keyboard.binファイルの後ろにBIOSファイルを連結します。

unixのcatコマンドを使用する例
$ cat keyboard.bin bios.rom > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b keyboard.bin + bios.rom firmware.bin

注意
出力ファイルの拡張子は.binにしてください。

2. MSXに刺さっていない状態のMSXπをブートモードでPCに接続します。

picoのBOOTボタンを押しながらPCとUSB接続して下さい。
HOSTジャンパの状態は不問です。

3. picotoolでpicoにロード(書込み)します

binファイルはドラッグアンドドロップ書込み出来ないのでpico-sdk付属のpicotoolを使用します。

例
picotool load firmware.bin

4. 書込みが終わったらPCから外して完了

注意：PCとの接続中はバスバッファの入力がフロート状態となります。
あまり良い状態ではないので長時間のPC接続は避けてください。

MSXπは一番若い番号の基本スロットに挿してください。
USB変換アダプター(OTGアダプター)が必要です。100円ショップ等で入手して下さい。
MSXπのHOSTジャンパをショートして下さい。