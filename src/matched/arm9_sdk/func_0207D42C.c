/*
 * function: func_0207D42C
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

#define reg_GX_DISPCNT (*(volatile unsigned long *)0x04000000)

extern void PMi_SetDispOffCount(void);
extern unsigned short sIsDispOn;
extern unsigned short sDispMode;

void func_0207D42C(void)
{
    unsigned long tmp = reg_GX_DISPCNT;

    sIsDispOn = 0;
    sDispMode = (unsigned short)((tmp & 0x30000) >> 16);
    reg_GX_DISPCNT = tmp & ~0x30000;
    PMi_SetDispOffCount();
}
