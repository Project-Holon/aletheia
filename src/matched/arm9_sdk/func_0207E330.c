/*
 * function: G2_GetBG3CharPtr
 * address:  0x0207E330
 * packet:   pkt_0207E330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G2_GetBG3CharPtr (libgx.TWL.HYB.a gx_bgcnt.o)
 *
 * symbols:
 *   (none)
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;

#define NULL ((void *)0)
#define HW_BG_VRAM      0x06000000
#define HW_DB_BG_VRAM   0x06200000

#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)
#define reg_G2_BG2CNT      (*(vu16 *)0x0400000C)
#define reg_G2_BG3CNT      (*(vu16 *)0x0400000E)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)
#define reg_G2S_DB_BG2CNT  (*(vu16 *)0x0400100C)
#define reg_G2S_DB_BG3CNT  (*(vu16 *)0x0400100E)

#define GX_GetBGScrOffset()  ((u32)((reg_GX_DISPCNT & 0x38000000) >> 27))
#define GX_GetBGCharOffset() ((u32)((reg_GX_DISPCNT & 0x07000000) >> 24))

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
