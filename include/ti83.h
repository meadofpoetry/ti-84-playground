__at 0x844B volatile unsigned char cur_row;
__at 0x844C volatile unsigned char cur_col;

inline void
clear_lcd_full() {
  __asm
    rst 0x28
    .dw 0x4540
  __endasm;
}

void
puts(char *s) {
  __asm
    ld l, 4(ix)
    ld h, 5(ix)
    rst #0x28
    .dw #0x450A
  __endasm;
}

void
putc(char c) {
   __asm
     ld a, 4(ix)
     rst 0x28
     .dw 0x4504
   __endasm;
   (void)c;
}

inline void
new_line() {
   __asm
     rst 0x28
     .dw 0x452E
   __endasm;
}

char
get_key() {
  __asm
    rst 0x28
    .dw 0x4972
    ld h, #0x0
    ld l, a
  __endasm;
}
