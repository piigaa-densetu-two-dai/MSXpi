Nextor対応！Sunrise IDE + 192kメモリーマッパーエミュレーターです。

USBメモリをSunrise IDEのマスター側に接続されたハードディスクとして使用する事ができます。

ご注意
拡張スロットでは動作しません。基本スロットに挿してご使用ください。
ソフトウエアによっては動作が遅くなったり処理落ちが生じやすくなります。
192kメモリーマッパー機能が不要な場合はメモリーマッパー無しのsunrise機能を使用する事をお勧めします。

使用法

1. SunriseIDE用のNextorカーネルをダウンロードします。

Nextorのgithubから以下のファイルをダウンロードして下さい。

https://github.com/Konamiman/Nextor/releases/download/v2.1.1/Nextor-2.1.1.SunriseIDE.MasterOnly.emulators.ROM
又は
https://github.com/Konamiman/Nextor/releases/download/v2.1.1/Nextor-2.1.1.SunriseIDE.emulators.ROM

(下のファイルを使用すると起動が僅かに遅くなります)
注意: 必ずemulatorsバージョンを使用して下さい。

2. sunrise.binファイルの後ろに1でダウンロードしたNextorカーネルを連結します。

unixのcatコマンドを使用する例
$ cat sunrise.bin Nextor-2.1.1.SunriseIDE.MasterOnly.emulators.ROM > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b sunrise.bin + Nextor-2.1.1.SunriseIDE.MasterOnly.emulators.ROM firmware.bin

3. uf2conv.exeを用いて2で作成したfirmware.binをuf2ファイルに変換します。

例: windowsコマンドプロンプト上で
uf2conv.exe firmware.bin firmware.uf2

uf2conv.exeはhttps://github.com/piigaa-densetu-two-dai/MSXpiにあります。

4. MSXに刺さっていない状態のMSXπをブートモードでPCに接続します。

MSXπのBOOTSELボタンを押しながらPCとUSB接続して下さい。
接続が成功するとドライブが認識されます。
HOSTジャンパの状態は不問です。

5. MSXπに3で作成したfirmware.uf2ファイルを書き込みします。

4で認識されたドライブにfirmware.uf2をドラッグアンドドロップ(コピー)します。
コピーが完了するとドライブが見えなくなります。

6. 書込みが終わったらPCから外して完了

注意：PCとの接続中はバスバッファの入力がフロート状態となります。
あまり良い状態ではないので長時間のPC接続は避けてください。

7. MSXπにUSBメモリを取り付けて完了

USB変換アダプター(OTGアダプター)が必要です。100円ショップ等で入手して下さい。
MSXπのHOSTジャンパをショートして下さい。

Nextorのセットアップ方法についてはこちらを参考にして下さい。
https://github.com/Konamiman/Nextor/blob/v2.1/docs/Nextor%202.1%20Getting%20Started%20Guide.md

注意
USBメモリ以外のUSB装置を接続しないでください。
USB装置のホットスワップに対応していません。
