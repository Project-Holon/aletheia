/*
 * function: POKETRADE_PROC_GetSlotMonPtr
 * address: 0x021D8E24
 * packet: pkt_ov119_021D8E24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   (none)
 */
#include "../include/Obj22705.h"

char *POKETRADE_PROC_GetSlotMonPtr(int a, int b, char *p)
{
    int n;

    if (a != -1) {
        n = ((struct Obj22705 *)p)->f630;
        if (a > n)
            return 0;
        if (a != n && b != -1)
            return p + 0x11fc + (a * 0x1e + 6 + b) * 4;
        if (b >= 0 && b < 6)
            return p + 0x11fc + b * 4;
        return 0;
    }
    return 0;
}
