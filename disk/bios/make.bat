cpm M80 =DISK
cpm L80 DISK/X/E/N/P:4000,DISK
arm-none-eabi-objcopy -I ihex -O binary DISK.HEX disk.rom
pause
