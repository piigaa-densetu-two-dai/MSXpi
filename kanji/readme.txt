第一・第二水準漢字ロムのファームウェアです。
標準的なIOポート0xd8-0xdbを使用するタイプです。

使用法

1. kanji.binファイルの後ろに使用する第一・第二水準漢字ロムファイル(ファイルサイズ256Kのもの)を連結します。

unixのcatコマンドを使用する例
$ cat kanji.bin kanji.rom > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b kanji.bin + kanji.rom firmware.bin

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
