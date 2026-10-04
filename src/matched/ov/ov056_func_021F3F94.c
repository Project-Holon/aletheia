/*
 * function: func_021F3F94
 * address:  0x021F3F94
 * packet:   pkt_021F3F94
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028B50  0x02028B50  thumb
 */
#include "../include/Obj07669.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02028B50(u8 *p, int a0);

void func_021F3F94(void *a, void *b, u8 *c)
{
    if (*(u16 *)(((struct Obj07669 *)c)->f0) != 0 && ((struct Obj07669 *)c)->f4 == 0) {
        func_02028B50((u8 *)(((struct Obj07669 *)c)->fC), 0x756);
        ((struct Obj07669 *)c)->f4 = 1;
    }
}
