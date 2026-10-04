/*
 * function: func_022101FC
 * address:  0x022101FC
 * packet:   pkt_022101FC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02210C88 0x02210C88 thumb
 */
#include "../include/Obj03351.h"
#include "../include/Obj25233.h"

extern int func_02210C88(void *, int);

int func_022101FC(char *p)
{
    if (func_02210C88(p, 4) == 0)
    {
        return 0xf;
    }
    if (((struct Obj25233 *)((char *)((struct Obj03351 *)p)->f0))->f1F == 5)
    {
        return 0x1e;
    }
    return 7;
}
