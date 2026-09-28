/*
 * function: func_0207DF60
 * address:  0x0207DF60
 * packet:   pkt_0207DF60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G2_GetBG0ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 *
 * symbols:
 *   (none)
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)
#define reg_G2_BGCNT (*(vu16 *)0x04000008)

static inline int GetScreenBase(void)
{
    return (reg_G2_BGCNT & 0x1F00) >> 8;
}

void *func_0207DF60(void)
{
    int screenBase = GetScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(0x06000000 + baseBlock + screenBase * 0x800);
}
