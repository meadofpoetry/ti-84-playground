CC=sdcc-sdcc
AS=spasm
LD=binpac8x.py

CFLAGS=-mz80 --no-std-crt0 --reserve-regs-iy --data-loc 0x9872 --code-loc 0x9D95
