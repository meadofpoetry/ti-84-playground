
void _PutC(char c) {
   __asm
      pop bc
      pop de
      pop hl
      ld a, l
      push hl
      push de
      push bc
      rst 0x28
      .dw 0x4504
   __endasm;
   (void)c;
}

void _NewLine() {
   __asm
      rst 0x28
      .dw 0x452E
   __endasm;
}

void print(char* str) {
   int i;
   for (i = 0; str[i] != 0; i++) {
      if (str[i] != '\n')
         _PutC(str[i]);
      else
         _NewLine();
   }
}
