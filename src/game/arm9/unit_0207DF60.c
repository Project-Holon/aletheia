/*
 * file:     unit_0207DF60.c
 * unit:     yes
 * function: func_0207DF60, func_0207DF94, func_0207DFB4, func_0207DFE8, func_0207E008, func_0207E08C, func_0207E100, func_0207E184, func_0207E1F8, func_0207E22C, func_0207E24C, func_0207E280, func_0207E2A0, func_0207E2F0, func_0207E330, func_0207E388
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
#define reg_G2_BG0CNT (*(vu16 *)0x04000008)
#define NULL ((void *)0)
#define HW_BG_VRAM      0x06000000
#define HW_DB_BG_VRAM   0x06200000
#define reg_G2_BG2CNT      (*(vu16 *)0x0400000C)
#define reg_G2_BG3CNT      (*(vu16 *)0x0400000E)
#define reg_G2S_DB_BG2CNT  (*(vu16 *)0x0400100C)
#define reg_G2S_DB_BG3CNT  (*(vu16 *)0x0400100E)
#define GX_GetBGScrOffset()  ((u32)((reg_GX_DISPCNT & 0x38000000) >> 27))
#define GX_GetBGCharOffset() ((u32)((reg_GX_DISPCNT & 0x07000000) >> 24))
#define reg_G2_BG1CNT (*(vu16 *)0x0400000A)
typedef unsigned short u16;


typedef volatile u16 vu16;


typedef unsigned long u32;

typedef volatile u32 vu32;

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)


typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;


void *func_0207DF60(void);
u32 G2S_GetBG0ScrPtr(void);
void *func_0207DFB4(void);
u32 G2S_GetBG1ScrPtr(void);
void *func_0207E008(void);
void *func_0207E08C(void);
void *func_0207E100(void);
void *func_0207E184(void);
void *func_0207E1F8(void);
u32 G2S_GetBG0CharPtr(void);
void *func_0207E24C(void);
u32 G2S_GetBG1CharPtr(void);
void *func_0207E2A0(void);
void *func_0207E2F0(void);
void *func_0207E330(void);
void *func_0207E388(void);


static inline int GetBG0ScreenBase(void)
{
    return (reg_G2_BG0CNT & 0x1F00) >> 8;
}


/*
 * sdk:      G2_GetBG0ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207DF60(void)
{
    int screenBase = GetBG0ScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(0x06000000 + baseBlock + screenBase * 0x800);
}


u32 G2S_GetBG0ScrPtr(void)
{
    return (u32)((((*(volatile unsigned short *)0x04001008 & 0x1f00) >> 8) << 11) + 0x6200000);
}


static inline int GetBG1ScreenBase(void)
{
    return (reg_G2_BG1CNT & 0x1F00) >> 8;
}


/*
 * sdk:      G2_GetBG1ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207DFB4(void)
{
    int screenBase = GetBG1ScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(0x06000000 + baseBlock + screenBase * 0x800);
}


u32 G2S_GetBG1ScrPtr(void)
{
    return (u32)((((*(volatile unsigned short *)0x0400100A & 0x1f00) >> 8) << 11) + 0x6200000);
}


/*
 * sdk:      G2_GetBG2ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E008(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GX_DISPCNT & 7);
    u32 bg = reg_G2_BG2CNT;
    u32 offset = GX_GetBGScrOffset() * 0x10000;
    u32 blockID = (bg & 0x1f00) >> 8;

    switch (bgMode) {
    case GX_BGMODE_0:
    case GX_BGMODE_1:
    case GX_BGMODE_2:
    case GX_BGMODE_3:
    case GX_BGMODE_4:
        return (void *)(HW_BG_VRAM + offset + 0x800 * blockID);
    case GX_BGMODE_5:
        if (bg & 0x80) {
            return (void *)(HW_BG_VRAM + 0x4000 * blockID);
        } else {
            return (void *)(HW_BG_VRAM + offset + 0x800 * blockID);
        }
    case GX_BGMODE_6:
        return (void *)HW_BG_VRAM;
    default:
        return NULL;
    }
}


/*
 * sdk:      G2S_GetBG2ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E08C(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GXS_DB_DISPCNT & 7);
    u32 bg = reg_G2S_DB_BG2CNT;
    u32 blockID = (bg & 0x1f00) >> 8;

    switch (bgMode) {
    case GX_BGMODE_0:
    case GX_BGMODE_1:
    case GX_BGMODE_2:
    case GX_BGMODE_3:
    case GX_BGMODE_4:
        return (void *)(HW_DB_BG_VRAM + 0x800 * blockID);
    case GX_BGMODE_5:
        if (bg & 0x80) {
            return (void *)(HW_DB_BG_VRAM + 0x4000 * blockID);
        } else {
            return (void *)(HW_DB_BG_VRAM + 0x800 * blockID);
        }
    case GX_BGMODE_6:
        return NULL;
    default:
        return NULL;
    }
}


/*
 * sdk:      G2_GetBG3ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E100(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GX_DISPCNT & 7);
    u32 bg = reg_G2_BG3CNT;
    u32 offset = GX_GetBGScrOffset() * 0x10000;
    u32 blockID = (bg & 0x1f00) >> 8;

    switch (bgMode) {
    case GX_BGMODE_0:
    case GX_BGMODE_1:
    case GX_BGMODE_2:
        return (void *)(HW_BG_VRAM + offset + 0x800 * blockID);
    case GX_BGMODE_3:
    case GX_BGMODE_4:
    case GX_BGMODE_5:
        if (bg & 0x80) {
            return (void *)(HW_BG_VRAM + 0x4000 * blockID);
        } else {
            return (void *)(HW_BG_VRAM + offset + 0x800 * blockID);
        }
    case GX_BGMODE_6:
        return NULL;
    default:
        return NULL;
    }
}


/*
 * sdk:      G2S_GetBG3ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E184(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GXS_DB_DISPCNT & 7);
    u32 bg = reg_G2S_DB_BG3CNT;
    u32 blockID = (bg & 0x1f00) >> 8;

    switch (bgMode) {
    case GX_BGMODE_0:
    case GX_BGMODE_1:
    case GX_BGMODE_2:
        return (void *)(HW_DB_BG_VRAM + 0x800 * blockID);
    case GX_BGMODE_3:
    case GX_BGMODE_4:
    case GX_BGMODE_5:
        if (bg & 0x80) {
            return (void *)(HW_DB_BG_VRAM + 0x4000 * blockID);
        } else {
            return (void *)(HW_DB_BG_VRAM + 0x800 * blockID);
        }
    case GX_BGMODE_6:
        return NULL;
    default:
        return NULL;
    }
}


static inline int GetBG0CharBase(void)
{
    return (reg_G2_BG0CNT & 0x3C) >> 2;
}


/*
 * sdk:      G2_GetBG0CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E1F8(void)
{
    int charBase = GetBG0CharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(0x06000000 + baseBlock + charBase * 0x4000);
}


u32 G2S_GetBG0CharPtr(void)
{
    return (u32)((((*(volatile unsigned short *)0x04001008 & 0x3c) >> 2) << 14) + 0x6200000);
}


static inline int GetBG1CharBase(void)
{
    return (reg_G2_BG1CNT & 0x3C) >> 2;
}


/*
 * sdk:      G2_GetBG1CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E24C(void)
{
    int charBase = GetBG1CharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(0x06000000 + baseBlock + charBase * 0x4000);
}


u32 G2S_GetBG1CharPtr(void)
{
    return (u32)((((*(volatile unsigned short *)0x0400100A & 0x3c) >> 2) << 14) + 0x6200000);
}


/*
 * sdk:      G2_GetBG2CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E2A0(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GX_DISPCNT & 7);
    u32 bg = reg_G2_BG2CNT;

    if (bgMode < GX_BGMODE_5 || !(bg & 0x80)) {
        return (void *)(HW_BG_VRAM + 0x10000 * GX_GetBGCharOffset() + 0x4000 * ((bg & 0x3c) >> 2));
    } else {
        return NULL;
    }
}


/*
 * sdk:      G2S_GetBG2CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E2F0(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GXS_DB_DISPCNT & 7);
    u32 bg = reg_G2S_DB_BG2CNT;

    if (bgMode < GX_BGMODE_5 || !(bg & 0x80)) {
        return (void *)(HW_DB_BG_VRAM + 0x4000 * ((bg & 0x3c) >> 2));
    } else {
        return NULL;
    }
}


/*
 * sdk:      G2_GetBG3CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E330(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GX_DISPCNT & 7);
    u32 bg = reg_G2_BG3CNT;

    if (bgMode < GX_BGMODE_3 || (bgMode < GX_BGMODE_6 && !(bg & 0x80))) {
        return (void *)(HW_BG_VRAM + 0x10000 * GX_GetBGCharOffset() + 0x4000 * ((bg & 0x3c) >> 2));
    } else {
        return NULL;
    }
}


/*
 * sdk:      G2S_GetBG3CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *func_0207E388(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GXS_DB_DISPCNT & 7);
    u32 bg = reg_G2S_DB_BG3CNT;

    if (bgMode < GX_BGMODE_3 || (bgMode < GX_BGMODE_6 && !(bg & 0x80))) {
        return (void *)(HW_DB_BG_VRAM + 0x4000 * ((bg & 0x3c) >> 2));
    } else {
        return NULL;
    }
}
