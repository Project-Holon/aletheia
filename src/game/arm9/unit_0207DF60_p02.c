/*
 * file:     unit_0207DF60_p02.c
 * unit:     yes
 * function: func_0207DFB4, func_0207DFE8
 * address:  0x0207DFB4
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

typedef unsigned long u32_0207DFB4;

typedef volatile u16 vu16;

typedef volatile u32_0207DFB4 vu32;

typedef unsigned int u32_1;

void *func_0207DFB4(void);
u32_1 G2S_GetBG1ScrPtr(void);


#define reg_GX_DISPCNT (*(vu32 *)0x04000000)

#define reg_G2_BGCNT (*(vu16 *)0x0400000A)


static inline int GetScreenBase(void)
{
    return (reg_G2_BGCNT & 0x1F00) >> 8;
}


/*
 * sdk:      G2_GetBG1ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207DFB4(void)
{
    int screenBase = GetScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(0x06000000 + baseBlock + screenBase * 0x800);
}


u32_1 G2S_GetBG1ScrPtr(void)
{
    return (u32_1)((((*(volatile unsigned short *)0x0400100A & 0x1f00) >> 8) << 11) + 0x6200000);
}
