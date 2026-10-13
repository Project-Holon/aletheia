/*
 * function: ENCEFF_QueueGridSpreadNeighbors
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
 *   ENCEFF_QueueGridSpreadCell  0x021F5BFC  thumb  ov081
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06199.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void ENCEFF_QueueGridSpreadCell(u8 *w, int x, int y);

void ENCEFF_QueueGridSpreadNeighbors(u8 *w, int k)
{
    int wd = ((struct Obj06199 *)w)->f3008;
    int x = k % wd;
    int y = k / wd;

    if (y - 1 >= 0)
        ENCEFF_QueueGridSpreadCell(w, x, y - 1);
    if (x + 1 < ((struct Obj06199 *)w)->f3008)
        ENCEFF_QueueGridSpreadCell(w, x + 1, y);
    if (y + 1 < ((struct Obj06199 *)w)->f300A)
        ENCEFF_QueueGridSpreadCell(w, x, y + 1);
    if (x - 1 >= 0)
        ENCEFF_QueueGridSpreadCell(w, x - 1, y);
}
