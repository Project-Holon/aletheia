/*
 * function: func_021D8D00
 * address:  0x021D8D00
 * packet:   pkt_021D8D00
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10410.h"

typedef unsigned int u32;

void func_021D8D00(char *p)
{
    if (*(void (**)(void))(p + 0x2c) != 0) {
        (*(void (**)(char *))(p + 0x2c))(p);
        if (((struct Obj10410 *)p)->f8 != 0)
            *(u32 *)&((struct Obj10410 *)p)->f2C = 0;
    }
}
