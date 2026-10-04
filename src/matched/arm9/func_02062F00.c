/*
 * function: func_02062F00
 * address:  0x02062F00
 * packet:   pkt_02062D4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062D08    0x02062D08  arm
 */
#include "../include/Obj07015.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02062D08(void *p, u32 i);

int func_02062F00(void *s, u32 i)
{
    u32 r = func_02062D08(s, i);

    if (r != 0) {
        ((struct Obj07015 *)s)->f10 = 0;
    }
    return r;
}
