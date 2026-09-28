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
 * symbols:
 *   PMi_SetDispOffCount  0x0208C944  arm
 *   sIsDispOn            0x020A84BC  data
 *   sDispMode            0x02150E0C  data
 *
 * TwlSDK libgx gx.o. Stops displaying the MAIN engine and remembers the mode.
 */

typedef unsigned int u32;
typedef unsigned short u16;

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)

#define REG_GX_DISPCNT_MODE_MASK  0x00030000
#define REG_GX_DISPCNT_MODE_SHIFT 16

extern u16 sDispMode;
extern u16 sIsDispOn;

extern void PMi_SetDispOffCount(void);

void func_0207D42C(void)
{
    u32 tmp = reg_GX_DISPCNT;

    sIsDispOn = 0;
    sDispMode = (u16)((tmp & REG_GX_DISPCNT_MODE_MASK) >> REG_GX_DISPCNT_MODE_SHIFT);

    reg_GX_DISPCNT = tmp & ~REG_GX_DISPCNT_MODE_MASK;

    PMi_SetDispOffCount();
}
