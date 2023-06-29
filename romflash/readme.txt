非メガロムをpicoオンボードフラッシュメモリからロードする為のファームウェアです。

使用法

1. romflash.binファイルの後ろに使用するromファイル(通常32K以下)を連結します。

unixのcatコマンドを使用する例
$ cat romflash.bin game.rom > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b romflash.bin + game.rom firmware.bin

注意：出力ファイルの拡張子は.binにしてください。

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
