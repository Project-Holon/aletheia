/*
 * file:     unit_0207DF60_p05.c
 * unit:     yes
 * function: func_0207E24C, func_0207E280
 * address:  0x0207E24C
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

typedef unsigned long u32_0207E24C;

typedef volatile u16 vu16;

typedef volatile u32_0207E24C vu32;

typedef unsigned int u32_1;

void *func_0207E24C(void);
u32_1 G2S_GetBG1CharPtr(void);


#define reg_GX_DISPCNT (*(vu32 *)0x04000000)

#define reg_G2_BGCNT (*(vu16 *)0x0400000A)


static inline int GetCharBase(void)
{
    return (reg_G2_BGCNT & 0x3C) >> 2;
}


/*
 * sdk:      G2_GetBG1CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E24C(void)
{
    int charBase = GetCharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(0x06000000 + baseBlock + charBase * 0x4000);
}


u32_1 G2S_GetBG1CharPtr(void)
{
    return (u32_1)((((*(volatile unsigned short *)0x0400100A & 0x3c) >> 2) << 14) + 0x6200000);
}
