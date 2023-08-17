ライセンスの問題によりDISK BIOSそのものを提供する事が出来ないので
ディスクドライバーのソースコードとビルド用バッチファイルのみの提供です。
ご自分の責任でdisk.macを入手の上、ビルドして下さい。

別途必要な物

* L80.COM, M80.COM
http://www.retroarchive.org/cpm/lang/MASM-80.ZIPに含まれています。

* arm-none-eabi-objcopy.exe
pico-sdkに含まれています。具体的な場所は以下の通りです。
インストール先/Pico SDK v1.5.1/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy.exe

* cpm.exe
CP/M実行環境のCP/M program EXEcutor for Win32です。以下からダウンロードして下さい。
https://www.vector.co.jp/soft/dl/win95/util/se378130.html

* msxsyssrcのdisk100/disk.mac (バージョン1.03 Aug 23, 1985)
DISK BIOS本体のソースコードです。アレなものなので気にされる方はご注意ください。

ビルド方法

このディレクトリに
L80.COM
M80.COM
arm-none-eabi-objcopy.exe
cpm.exe
disk.mac
をコピーしてmake.batを実行すればdisk.romという名前のDISK BIOSファイルが出来るはずです。
