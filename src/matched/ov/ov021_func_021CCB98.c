/*
 * function: func_021CCB98
 * address:  0x021CCB98
 * packet:   pkt_ov021_021CCB98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 */
#include "../include/Obj09731.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Obj;
extern u32 func_0201AA18(void *p);
extern void func_0204B3B4(struct Obj *p);

void func_021CCB98(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(((struct Obj09731 *)p)->f4);
    for (i = 0; i < n; i++)
        func_0204B3B4(*(void **)(p + i * 4 + 0x1c));
    if (((struct Obj09731 *)p)->f8) {
        n = func_0201AA18(((struct Obj09731 *)p)->f8);
        for (i = 0; i < n; i++)
            func_0204B3B4(*(void **)(p + i * 4 + 0x34));
    }
}
