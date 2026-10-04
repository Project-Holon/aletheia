/*
 * function: func_02204F00
 * address:  0x02204F00
 * packet:   pkt_02204F00
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020063B4 0x020063B4 thumb
 */
#include "../include/Obj10816.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);

void func_02204F00(int unused, char *p)
{
    if (((struct Obj10816 *)p)->f30 == 0)
    {
        ((struct Obj10816 *)p)->f34 = 0;
        func_020063B4((void *)0x3f3, (u32 *)(p + 0x34), 1);
        ((struct Obj10816 *)p)->f30 = 3;
    }
}
