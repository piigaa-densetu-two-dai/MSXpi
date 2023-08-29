100in1ロムファイルの作り方

100in1に含めたいROMファイル(1～100ファイル)を用意し、以下の形式の名前にリネームします。

<NN>_<MAPPER>.rom

NN=ROM番号(00～99)

MAPPER=ROMのマッパー形式(normal, ascii8k, ascii16k, konami, rtype の何れか)
* normal: 非メガROM
* ascii8k: メガROM ASCII8Kマッパー
* ascii16k: メガROM ASCII16Kマッパー
* konami: メガROM konamiマッパー
* rtype: メガROM R-TYPEマッパー

例:
00_normal.rom
01_ascii8k.rom
02_ascii16k.rom
03_konami.rom
04_rtype.rom

上記ROMファイルとmakerom.exeを同じディレクトリにおいてmakerom.exeを実行します。
コマンドプロンプトで実行すると以下のようなメッセージが出ます。
(ダブルクリックによる実行でも構いません)

～ ピーガー伝説の100in1ツール ～
[00] mapper:1 offset:00000000 name:00_normal.rom
[01] mapper:2 offset:00008000 name:01_ascii8k.rom
[02] mapper:3 offset:00088000 name:02_ascii16k.rom
[03] mapper:4 offset:000a8000 name:03_konami.rom
[04] mapper:5 offset:000e8000 name:04_rtype.rom

同ディレクトリに作成されるroms.binというファイルが100in1ロムファイルです。
