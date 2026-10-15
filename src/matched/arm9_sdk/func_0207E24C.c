/*
 * function: G2_GetBG1CharPtr
 * address:  0x0207E24C
 * packet:   pkt_0207E24C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G2_GetBG1CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 *
 * symbols:
 *   (none)
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)
#define reg_G2_BGCNT (*(vu16 *)0x0400000A)

static inline int GetCharBase(void)
{
    return (reg_G2_BGCNT & 0x3C) >> 2;
}

void *G2_GetBG1CharPtr(void)
{
    int charBase = GetCharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(0x06000000 + baseBlock + charBase * 0x4000);
}
