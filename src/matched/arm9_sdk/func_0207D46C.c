/*
 * function: func_0207D46C
 * address:  0x0207D46C
 * packet:   pkt_0207D46C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_DispOn (libgx.TWL.HYB.a gx.o)
 *
 * symbols:
 *   sDispMode  0x02150E0C  data
 *   sIsDispOn  0x020A84BC  data
 */

#include "../include/G_GXBssState.h"
#include "../include/G_GXDataState.h"

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u32 vu32;

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)

extern struct GXBssState sDispMode;
extern struct GXDataState sIsDispOn;

void func_0207D46C(void)
{
    (*(u16 *)&sIsDispOn) = 1;
    if ((*(u16 *)&sDispMode))
    {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x30000) | ((*(u16 *)&sDispMode) << 16);
    }
    else
    {
        reg_GX_DISPCNT = reg_GX_DISPCNT | 0x10000;
    }
}
