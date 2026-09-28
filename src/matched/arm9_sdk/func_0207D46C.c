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
 * symbols:
 *   GX_DispOn  0x0207D46C  arm
 *   sIsDispOn  0x020A84BC  data
 *   sDispMode  0x02150E0C  data
 *
 * TwlSDK libgx gx.o. Restarts the MAIN engine display, restoring the mode that
 * GX_DispOff remembered (GRAPHICS when none was recorded).
 */

typedef unsigned int u32;
typedef unsigned short u16;

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)

#define REG_GX_DISPCNT_MODE_MASK  0x00030000
#define REG_GX_DISPCNT_MODE_SHIFT 16

#define GX_DISPMODE_OFF      0
#define GX_DISPMODE_GRAPHICS 1

extern u16 sDispMode;
extern u16 sIsDispOn;

void func_0207D46C(void)
{
    sIsDispOn = 1;
    if (sDispMode != (u16)GX_DISPMODE_OFF)
    {
        reg_GX_DISPCNT =
            ((reg_GX_DISPCNT & ~REG_GX_DISPCNT_MODE_MASK) |
             (sDispMode << REG_GX_DISPCNT_MODE_SHIFT));
    }
    else
    {
        reg_GX_DISPCNT = ((reg_GX_DISPCNT | (GX_DISPMODE_GRAPHICS << REG_GX_DISPCNT_MODE_SHIFT)));
    }
}
