256in1ロムファイルの作り方

256in1に含めたいROM/CASファイル(1～256ファイル)を用意し、以下の形式の名前にリネームします。

* ROMファイルの場合
<NNN>_<MAPPER>.rom

* CASファイルの場合
<NNN>_tape.cas

NNN=ROM番号(000～255)

MAPPER=ROMのマッパー形式(normal, ascii8k, ascii16k, konami, rtype の何れか)
* normal: 非メガROM
* ascii8k: メガROM ASCII8Kマッパー
* ascii16k: メガROM ASCII16Kマッパー
* konami: メガROM konamiマッパー
* rtype: メガROM R-TYPEマッパー

例:
000_normal.rom
001_ascii8k.rom
002_ascii16k.rom
003_konami.rom
004_rtype.rom
005_tape.cas

上記ROMファイルとmakerom.exeを同じディレクトリにおいてmakerom.exeを実行します。
コマンドプロンプトで実行すると以下のようなメッセージが出ます。
(ダブルクリックによる実行でも構いません)

～ ピーガー伝説の256in1ツール ～
[000] mapper:01 offset:00000000 name:000_normal.rom
[001] mapper:02 offset:00008000 name:001_ascii8k.rom
[002] mapper:03 offset:00088000 name:002_ascii16k.rom
[003] mapper:04 offset:000a8000 name:003_konami.rom
[004] mapper:05 offset:000e8000 name:004_rtype.rom
[005] mapper:10 offset:00168000 name:005_tape.cas

同ディレクトリに作成されるroms.binというファイルが256in1ロムファイルです。
