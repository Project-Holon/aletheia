/*
 * function: func_021BDC5C
 * address:  0x021BDC5C
 * packet:   pkt_ov091_021BDC5C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 */
#include "../include/Obj00009.h"

typedef unsigned int u32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);

int func_021BDC5C(char *p)
{
    int r = 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 6, 0) == 0x70)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 5, r) != 0x1E7)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6F, r) == 1)
        r = 1;
    return r;
}
