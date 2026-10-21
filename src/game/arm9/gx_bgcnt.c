/*
 * file:     gx_bgcnt.c
 * unit:     yes
 * function: G2_GetBG0ScrPtr, G2S_GetBG0ScrPtr, G2_GetBG1ScrPtr, G2S_GetBG1ScrPtr, G2_GetBG2ScrPtr, G2S_GetBG2ScrPtr, G2_GetBG3ScrPtr, G2S_GetBG3ScrPtr, G2_GetBG0CharPtr, G2S_GetBG0CharPtr, G2_GetBG1CharPtr, G2S_GetBG1CharPtr, G2_GetBG2CharPtr, G2S_GetBG2CharPtr, G2_GetBG3CharPtr, G2S_GetBG3CharPtr
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
#define reg_G2_BG0CNT (*(vu16 *)REG_BG0CNT_ADDR)
#define NULL ((void *)0)
#define reg_G2_BG2CNT      (*(vu16 *)REG_BG2CNT_ADDR)
#define reg_G2_BG3CNT      (*(vu16 *)REG_BG3CNT_ADDR)
#define reg_G2S_DB_BG2CNT  (*(vu16 *)REG_DB_BG2CNT_ADDR)
#define reg_G2S_DB_BG3CNT  (*(vu16 *)REG_DB_BG3CNT_ADDR)
#define GX_GetBGScrOffset()  ((u32)((reg_GX_DISPCNT & 0x38000000) >> 27))
#define GX_GetBGCharOffset() ((u32)((reg_GX_DISPCNT & 0x07000000) >> 24))
#define reg_G2_BG1CNT (*(vu16 *)REG_BG1CNT_ADDR)
#include "../types.h"
#include "../sdk_ioreg.h"

#define reg_GX_DISPCNT (*(vu32 *)REG_DISPCNT_ADDR)
#define reg_GXS_DB_DISPCNT (*(vu32 *)REG_DB_DISPCNT_ADDR)

typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;

void *G2_GetBG0ScrPtr(void);
void *G2S_GetBG0ScrPtr(void);
void *G2_GetBG1ScrPtr(void);
void *G2S_GetBG1ScrPtr(void);
void *G2_GetBG2ScrPtr(void);
void *G2S_GetBG2ScrPtr(void);
void *G2_GetBG3ScrPtr(void);
void *G2S_GetBG3ScrPtr(void);
void *G2_GetBG0CharPtr(void);
void *G2S_GetBG0CharPtr(void);
void *G2_GetBG1CharPtr(void);
void *G2S_GetBG1CharPtr(void);
void *G2_GetBG2CharPtr(void);
void *G2S_GetBG2CharPtr(void);
void *G2_GetBG3CharPtr(void);
void *G2S_GetBG3CharPtr(void);

static inline int GetBG0ScreenBase(void)
{
    return (reg_G2_BG0CNT & 0x1F00) >> 8;
}

/*
 * sdk:      G2_GetBG0ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *G2_GetBG0ScrPtr(void)
{
    int screenBase = GetBG0ScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(HW_BG_VRAM + baseBlock + screenBase * 0x800);
}

void *G2S_GetBG0ScrPtr(void)
{
    return (void *)((((*(volatile unsigned short *)REG_DB_BG0CNT_ADDR & 0x1f00) >> 8) << 11) + 0x6200000);
}

static inline int GetBG1ScreenBase(void)
{
    return (reg_G2_BG1CNT & 0x1F00) >> 8;
}

/*
 * sdk:      G2_GetBG1ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *G2_GetBG1ScrPtr(void)
{
    int screenBase = GetBG1ScreenBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x38000000) >> 27);

    return (void *)(HW_BG_VRAM + baseBlock + screenBase * 0x800);
}

void *G2S_GetBG1ScrPtr(void)
{
    return (void *)((((*(volatile unsigned short *)REG_DB_BG1CNT_ADDR & 0x1f00) >> 8) << 11) + 0x6200000);
}

/*
 * sdk:      G2_GetBG2ScrPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *G2_GetBG2ScrPtr(void)
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
void *G2S_GetBG2ScrPtr(void)
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
void *G2_GetBG3ScrPtr(void)
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
void *G2S_GetBG3ScrPtr(void)
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
void *G2_GetBG0CharPtr(void)
{
    int charBase = GetBG0CharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(HW_BG_VRAM + baseBlock + charBase * 0x4000);
}

void *G2S_GetBG0CharPtr(void)
{
    return (void *)((((*(volatile unsigned short *)REG_DB_BG0CNT_ADDR & 0x3c) >> 2) << 14) + 0x6200000);
}

static inline int GetBG1CharBase(void)
{
    return (reg_G2_BG1CNT & 0x3C) >> 2;
}

/*
 * sdk:      G2_GetBG1CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *G2_GetBG1CharPtr(void)
{
    int charBase = GetBG1CharBase();
    int baseBlock = 0x10000 * (int)((reg_GX_DISPCNT & 0x07000000) >> 24);

    return (void *)(HW_BG_VRAM + baseBlock + charBase * 0x4000);
}

void *G2S_GetBG1CharPtr(void)
{
    return (void *)((((*(volatile unsigned short *)REG_DB_BG1CNT_ADDR & 0x3c) >> 2) << 14) + 0x6200000);
}

/*
 * sdk:      G2_GetBG2CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 */
void *G2_GetBG2CharPtr(void)
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
void *G2S_GetBG2CharPtr(void)
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
void *G2_GetBG3CharPtr(void)
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
void *G2S_GetBG3CharPtr(void)
{
    GXBGMode bgMode = (GXBGMode)(reg_GXS_DB_DISPCNT & 7);
    u32 bg = reg_G2S_DB_BG3CNT;

    if (bgMode < GX_BGMODE_3 || (bgMode < GX_BGMODE_6 && !(bg & 0x80))) {
        return (void *)(HW_DB_BG_VRAM + 0x4000 * ((bg & 0x3c) >> 2));
    } else {
        return NULL;
    }
}
