/*
 * function: func_020120A4
 * address:  0x020120A4
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15622.h"

extern int func_020123C4(void *p);
void func_020120A4(char *p)
{
    ((struct Obj15622 *)p)->f31 = (unsigned char)func_020123C4(p);
}
