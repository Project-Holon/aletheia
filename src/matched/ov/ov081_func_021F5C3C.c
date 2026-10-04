/*
 * function: func_021F5C3C
 * address:  0x021F5C3C
 * packet:   pkt_ov081_021F5C3C
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F5BFC  0x021F5BFC  thumb  ov081
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06199.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021F5BFC(u8 *w, int x, int y);

void func_021F5C3C(u8 *w, int k)
{
    int wd = ((struct Obj06199 *)w)->f3008;
    int x = k % wd;
    int y = k / wd;

    if (y - 1 >= 0)
        func_021F5BFC(w, x, y - 1);
    if (x + 1 < ((struct Obj06199 *)w)->f3008)
        func_021F5BFC(w, x + 1, y);
    if (y + 1 < ((struct Obj06199 *)w)->f300A)
        func_021F5BFC(w, x, y + 1);
    if (x - 1 >= 0)
        func_021F5BFC(w, x - 1, y);
}
