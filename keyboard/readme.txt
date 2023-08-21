日本語USBキーボードインターフェースのファームウェアです。MSX/MSX2/MSX2+に対応。
使用する実機のBIOS(スロット0の先頭32KB、日本版のみ)ファイルが必要です。
相性の悪いキーボードがあるかもしれませんご注意ください。

使用法

1. keyboard.binファイルの後ろにBIOSファイルを連結します。

unixのcatコマンドを使用する例
$ cat keyboard.bin bios.rom > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b keyboard.bin + bios.rom firmware.bin

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

MSXπは一番若い番号の基本スロットに挿してください。
USB変換アダプター(OTGアダプター)が必要です。100円ショップ等で入手して下さい。
MSXπのHOSTジャンパをショートして下さい。
