include ../common.mk

image: helloc.bin
	$(LD) helloc.bin helloc.8xp

helloc.bin: helloc.ihx
	hex2bin.py helloc.ihx > helloc.bin

helloc.ihx: crt
	$(CC) $(CFLAGS) --opt-code-size -o helloc.ihx ../crt/crt0.rel main.c

crt:
	make -C ../crt

clean:
	make -C ../crt clean
	rm *.{8xp,asm,bin,ihx,lk,lst,map,noi,rel,sym}
