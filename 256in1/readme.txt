256in1ロムのファームウェアです。
最大256のROM/CASファイルをMSXπのフラッシュメモリに格納する事が出来ます。
ファイル格納用のフラッシュメモリ領域は16Mバイト弱です。
256in1ロムファイルの作成についてはtool以下のreadme.txtを読んでください。

対応ファイル形式
* 各種ROMファイル
  非メガROM、ASCII8Kマッパー、ASCII16Kマッパー、KONAMIマッパー、R-TYPEマッパーに対応
* TAPEファイル
  書込み、巻き戻し、テープ交換不可、ターボR非対応、MSXπは基本スロットに挿してください

使用法

1. 256in1.binファイルの後ろに使用する256in1ロムファイルを連結します。

unixのcatコマンドを使用する例
$ cat 256in1.bin roms.bin > firmware.bin

windowsのcopyコマンドを使用する例
>copy /b 256in1.bin + roms.bin firmware.bin

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

6. ゲーム起動方法

MSX起動時にInput ROM#:と表示されたらROM番号(000～255)を入力しリターンキーを押してください。
番号に対応したゲームが起動します。
対応するゲームが無い場合は再びInput ROM#:が表示されます。
