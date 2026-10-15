/*
 * function: POKETRADE_2D_IsBoxIconFiltered
 * address: 0x021E4A84
 * packet: pkt_ov119_021E4A84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBoxIconFilter 0x021E82A4 data
 */
#include "../include/Obj22806.h"
extern const unsigned char gBoxIconFilter[];
int POKETRADE_2D_IsBoxIconFiltered(char *p, int i)
{
    int v = ((struct Obj22806 *)p)->f800;
    if (v != 0 && v - 1 == gBoxIconFilter[i]) {
        return 1;
    }
    return 0;
}
