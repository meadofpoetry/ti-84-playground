include ../common.mk

.PHONY: image clean

image: hello.bin
	$(LD) hello.bin hello.8xp

hello.bin:
	$(AS) helloworld.s hello.bin

clean:
	rm *.bin *.8xp
