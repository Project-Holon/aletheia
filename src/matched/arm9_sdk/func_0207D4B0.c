/*
 * function: func_0207D4B0
 * address:  0x0207D4B0
 * packet:   pkt_0207D4B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_SetGraphicsMode (libgx.TWL.HYB.a gx.o)
 *
 * symbols:
 *   sIsDispOn  0x020A84BC  data
 *   sDispMode  0x02150E0C  data
 */

#include "../include/G_GXBssState.h"
#include "../include/G_GXDataState.h"

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u32 vu32;

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)

extern struct GXDataState sIsDispOn;
extern struct GXBssState sDispMode;

void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d)
{
    u32 cnt = reg_GX_DISPCNT;

    (*(u16 *)&sDispMode) = (u16)dispMode;
    if (!(*(u16 *)&sIsDispOn))
    {
        dispMode = 0;
    }
    reg_GX_DISPCNT = bgMode | ((cnt & 0xFFF0FFF0) | (dispMode << 16)) | (bg0_2d3d << 3);
    if (!(*(u16 *)&sDispMode))
    {
        (*(u16 *)&sIsDispOn) = 0;
    }
}
