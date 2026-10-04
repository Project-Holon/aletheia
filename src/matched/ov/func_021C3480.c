/*
 * function: func_021C3480
 * address:  0x021C3480
 * packet:   pkt_021C3480
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb

 * BLOCKED.  Unverifiable: func_020065D8 resolves only through the `matched` class and layout/matched/ov093 holds func_021B911C in two shards, which aborts every manifest load.
 */
#include "../include/Obj00146.h"


extern int func_02006650(int);
extern void func_020065D8(int);

void func_021C3480(int unused, char *p)
{
    int v;

    if (((struct Obj00146 *)p)->f68 != 0) {
        v = func_02006650(((struct Obj00146 *)p)->f68);
        if (v != 0)
            func_020065D8(v);
        ((struct Obj00146 *)p)->f68 = 0;
    }
    ((struct Obj00146 *)p)->f74 = 0;
}

