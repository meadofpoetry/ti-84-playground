        .nolist
#include "../include/ti83plus.inc"
#define    ProgStart    $9D95
        .list
        .org ProgStart-2
        .db t2ByteTok, tAsmCmp
        
        bcall(_ClrLCDFull)
        ld hl, 0
        ld (curCol), hl
        ld (curRow), hl
        ld hl, msg
        bcall(_PutS)
        bcall(_GetKey)
        bcall(_NewLine)
        ret

msg:
        .db "Hello, World!",0
        .end
