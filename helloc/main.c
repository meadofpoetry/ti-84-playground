#include "../include/ti83.h"

void
fmt_time(int h, int m, int s, char *dst) {
  dst[0] = ((h / 10) % 10) + '0';
  dst[1] = (h % 10) + '0';
  dst[2] = ':';
  dst[3] = ((m / 10) % 10) + '0';
  dst[4] = (m % 10) + '0';
  dst[5] = ':';
  dst[6] = ((s / 10) % 10) + '0';
  dst[7] = (s % 10) + '0';
  dst[8] = '\0';
}

int
main() {
  int h, m, s;
  char date[10];

  clear_lcd_full();

  while (!is_enter_pressed()) { 
    cur_row = 0;
    cur_col = 0;

    get_time(&h, &m, &s);

    fmt_time(h, m, s, date);
    puts(date);
    new_line();

    get_time_string(date);
    puts(date);
    new_line();

    puts("To exit press enter...");
    new_line();
  }
  
  return 0;
}
