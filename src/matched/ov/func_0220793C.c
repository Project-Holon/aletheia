/*
 * function: func_0220793C
 * address:  0x0220793C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220793C   0x0220793C  thumb
 *   BTLV_GAUGE_CalcBarPixels 0x02208D38 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj00974.h"

extern int BTLV_GAUGE_CalcBarPixels(int a, int b, int c);

void func_0220793C(char *p)
{
    int a = ((struct Obj00974 *)p)->f48;
    int b = ((struct Obj00974 *)p)->f4C;

    if (b < 0x30)
        ((struct Obj00974 *)p)->f78 = (unsigned int)BTLV_GAUGE_CalcBarPixels(a << 8, b, 0x30) >> 8;
    else
        ((struct Obj00974 *)p)->f78 = (unsigned int)BTLV_GAUGE_CalcBarPixels(a, b, 0x30);
}

