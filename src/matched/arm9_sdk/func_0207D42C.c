/*
 * function: GX_DispOff
 * address:  0x0207D42C
 * packet:   pkt_0207D42C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_DispOff (gx.o)
 *
 * symbols:
 *   PMi_SetDispOffCount              0x0208c944 arm
 *   sIsDispOn                        0x020a84bc data
 *   sDispMode                        0x02150e0c data
 */

#include "../include/G_GXBssState.h"
#include "../include/G_GXDataState.h"

#define reg_GX_DISPCNT (*(volatile unsigned long *)0x04000000)

extern void PMi_SetDispOffCount(void);
extern struct GXDataState sIsDispOn;
extern struct GXBssState sDispMode;

void GX_DispOff(void)
{
    unsigned long tmp = reg_GX_DISPCNT;

    (*(unsigned short *)&sIsDispOn) = 0;
    (*(unsigned short *)&sDispMode) = (unsigned short)((tmp & 0x30000) >> 16);
    reg_GX_DISPCNT = tmp & ~0x30000;
    PMi_SetDispOffCount();
}
