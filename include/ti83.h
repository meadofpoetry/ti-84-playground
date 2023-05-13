__at 0x844B volatile unsigned char cur_row;
__at 0x844C volatile unsigned char cur_col;

inline void
clear_lcd_full() {
  __asm
    rst 0x28
    .dw 0x4540
  __endasm;
}

inline void
clear_lcd() {
  __asm
    rst 0x28
    .dw 0x4543
  __endasm;
}

inline void
clear_scrn_full() {
  __asm
    rst 0x28
    .dw 0x4546
  __endasm;
}

inline void
clear_scrn() {
  __asm
    rst 0x28
    .dw 0x4549
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

void
get_time_string(char *dst) {
  __asm
    ld e, 4(ix)
    ld d, 5(ix)
    ld a, 0x3F(iy)
    push af
    set 2, 0x3F(iy) // Set 24-hour format
    set 4, 0x3F(iy) // Use ASCII
    rst 0x28
    .dw 0x515E
    pop af
    ld 0x3F(iy), a
  __endasm;
  (void)dst;
}

void
get_time(int *h, int *m, int *s) {
  __asm
    // _getTime
    rst 0x28
    .dw 0x515B
    // Seconds
    // PopRealO1
    rst 0x28
    .dw 0x4390
    // ConvOP1
    rst 0x28
    .dw 0x4AEF

    ld l, 8(ix)
    ld h, 9(ix)
    ld (hl), e
    inc hl
    ld (hl), d

    // Minutes
    // PopRealO1
    rst 0x28
    .dw 0x4390
    // ConvOP1
    rst 0x28
    .dw 0x4AEF

    ld l, 6(ix)
    ld h, 7(ix)
    ld (hl), e
    inc hl
    ld (hl), d

    // Hours
    // PopRealO1
    rst 0x28
    .dw 0x4390
    // ConvOP1
    rst 0x28
    .dw 0x4AEF

    ld l, 4(ix)
    ld h, 5(ix)
    ld (hl), e
    inc hl
    ld (hl), d
    
  __endasm;
}

int
is_enter_pressed() {
  __asm
    ld a, #0xFD
    out (1), a
    nop
    nop
    in a, (1)
    bit 0, a
    jr z, is_set
    ld hl, #0
    ret
  is_set:
    ld hl, #1
  __endasm;
}

void
lcd_busy() {
  __asm
    rst 0x28
    .dw 0x4051
  __endasm;
}
