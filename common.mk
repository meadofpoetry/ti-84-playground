CC=sdcc-sdcc
AS=spasm
LD=binpac8x.py

CFLAGS=-mz80 --no-std-crt0 --reserve-regs-iy --data-loc 0 --code-loc 0x9D9B
