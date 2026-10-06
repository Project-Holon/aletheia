/*
 * file:     unit_0207DF60_p04.c
 * unit:     yes
 * function: func_0207E1F8, func_0207E22C
 * address:  0x0207E1F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

typedef unsigned long u32_0207E1F8;

typedef volatile u16 vu16;

typedef volatile u32_0207E1F8 vu32;

typedef unsigned int u32_1;

void *func_0207E1F8(void);
u32_1 G2S_GetBG0CharPtr(void);


#define reg_GX_DISPCNT (*(vu32 *)0x04000000)

#define reg_G2_BGCNT (*(vu16 *)0x04000008)


static inline int GetCharBase(void)
{
    return (reg_G2_BGCNT & 0x3C) >> 2;
}


/*
 * sdk:      G2_GetBG0CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E1F8(void)
{
    int charBase = GetCharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(0x06000000 + baseBlock + charBase * 0x4000);
}


u32_1 G2S_GetBG0CharPtr(void)
{
    return (u32_1)((((*(volatile unsigned short *)0x04001008 & 0x3c) >> 2) << 14) + 0x6200000);
}
