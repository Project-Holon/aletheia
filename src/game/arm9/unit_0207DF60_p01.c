/*
 * file:     unit_0207DF60_p01.c
 * unit:     yes
 * function: func_0207DF60, func_0207DF94
 * address:  0x0207DF60
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

typedef unsigned long u32_0207DF60;

typedef volatile u16 vu16;

typedef volatile u32_0207DF60 vu32;

typedef unsigned int u32_1;

void *func_0207DF60(void);
u32_1 G2S_GetBG0ScrPtr(void);


#define reg_GX_DISPCNT (*(vu32 *)0x04000000)

#define reg_G2_BGCNT (*(vu16 *)0x04000008)


static inline int GetScreenBase(void)
{
    return (reg_G2_BGCNT & 0x1F00) >> 8;
}


/*
 * sdk:      G2_GetBG0ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207DF60(void)
{
    int screenBase = GetScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(0x06000000 + baseBlock + screenBase * 0x800);
}


u32_1 G2S_GetBG0ScrPtr(void)
{
    return (u32_1)((((*(volatile unsigned short *)0x04001008 & 0x1f00) >> 8) << 11) + 0x6200000);
}
