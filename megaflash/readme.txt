各種メガロムのファームウェア(フラッシュメモリ使用バージョン)です。

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

お手持ちのROMファイルはマッパー形式が変換されている場合があります。
動かない場合はblueMSX等でマッパーの確認をしてください。

2. uf2conv.exeを用いて1で作成したfirmware.binをuf2ファイルに変換します。

例: windowsコマンドプロンプト上で
uf2conv.exe firmware.bin firmware.uf2

uf2conv.exeはhttps://github.com/piigaa-densetu-two-dai/MSXpiにあります。

3. MSXに刺さっていない状態のMSXπをブートモードでPCに接続します。

MSXπのBOOTSELボタンを押しながらPCとUSB接続して下さい。
接続が成功するとドライブが認識されます。
HOSTジャンパの状態は不問です。

4. MSXπに2で作成したfirmware.uf2ファイルを書き込みします。

3で認識されたドライブにfirmware.uf2をドラッグアンドドロップ(コピー)します。
コピーが完了するとドライブが見えなくなります。

5. 書込みが終わったらPCから外して完了

注意：PCとの接続中はバスバッファの入力がフロート状態となります。
あまり良い状態ではないので長時間のPC接続は避けてください。
