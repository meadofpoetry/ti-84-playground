#include "../include/ti83.h"

__at 0x844B volatile unsigned int cur_row;
__at 0x844C volatile unsigned int cur_col;

void
clear_screen() {
  __asm
    rst 0x28
    .dw 0x4540
  __endasm;
}

void
get_key() {
  __asm
    rst 0x28
    .dw 0x4972
  __endasm;
}

int
main() {
  clear_screen();
  cur_row = 0;
  cur_col = 0;
  print("Hello, world\n");
  get_key();
  return 0;
}
