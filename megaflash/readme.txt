各種メガロムをpicoオンボードフラッシュメモリからロードする為のファームウェアです。

ファームウェアは各マッパー毎に異なります。

ascii8k.bin ASCII8Kマッパー用
ascii16k.bin ASCII16Kマッパー用
konami.bin コナミマッパー用
rtype.bin R-TYPEマッパー用

使用法

1. 上記binファイルの後ろに使用するromファイル(対応マッパーのもの)を連結します。

unixのcatコマンドを使用する例
$ cat ascii8k.bin game.rom > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b ascii8k.bin + game.rom firmware.bin

注意：出力ファイルの拡張子は.binにしてください。
お手持ちのROMファイルはマッパー形式が変換されている場合があります。
動かない場合はblueMSX等でマッパーの確認をしてください。

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
