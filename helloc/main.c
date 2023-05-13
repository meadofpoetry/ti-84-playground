#include "../include/ti83.h"

int
main() {
  clear_lcd_full();
  cur_row = 0;
  cur_col = 0;
  puts("Hello, world");
  new_line();
  get_key();
  return 0;
}
