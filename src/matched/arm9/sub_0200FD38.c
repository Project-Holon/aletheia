/*
 * function: GFL_NET_ERR_SaveDisplayAndDraw
 * address:  0x0200FD38
 * packet:   pkt_0200FC0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010054             0x02010054  thumb
 *   GXx_GetMasterBrightness_  0x0207D55C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GX_HBlankIntr             0x0207D3AC  arm
 *   GX_VBlankIntr             0x0207D3E4  arm
 *   func_020808F4             0x020808F4  arm
 *   func_020809A0             0x020809A0  arm
 *   GX_SetBankForBG           0x0207FDCC  arm
 *   GX_SetGraphicsMode        0x0207D4B0  arm
 *   G2_GetBG1CharPtr          0x0207E24C  arm
 *   G2_GetBG1ScrPtr           0x0207DFB4  arm
 *   MIi_CpuCopy16             0x02082A60  arm
 *   func_02043668             0x02043668  arm
 *   func_020435F4             0x020435F4  arm
 *   GFL_NET_ERR_LoadScreenGraphics              0x02010068  thumb
 *   func_020101D4             0x020101D4  thumb
 *   gNetErrWork                0x0214617C  data
 *
 * net_err.c's graphics save-and-blank: saves both master brightness levels,
 * the H/V-blank interrupt enables, two VRAM bank states, DISPCNT, the sub
 * window mask and BG1CNT into the module object at 0x0214617C, reprograms
 * BG1 as a 16-colour text layer, backs up BG1's character, screen and the
 * first palette block (unless +0x59 is 0x60), then draws the error screen
 * (GFL_NET_ERR_LoadScreenGraphics and func_020101D4).  The SDK inlines are NitroSDK's gx.h /
 * g2.h shapes (GX_SetVisiblePlane, G2_SetBG1Control with the saved control
 * word's bgExtPltt bit, G2_BG1Mosaic).  The lever that closed it (the
 * earlier note was 20 bytes short): the two backup copies read their buffer
 * pointer and call the pointer getter into NAMED LOCALS, dst first, which
 * loads the buffer before the call and raises the pressure that spills a0
 * to [sp] exactly as the image does.
 */
#include "../include/Obj01327.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

typedef union {
    u16 raw;
    struct {
        u16 priority:2;
        u16 charBase:4;
        u16 mosaic:1;
        u16 colorMode:1;
        u16 screenBase:5;
        u16 bgExtPltt:1;
        u16 screenSize:2;
    };
} GXBg01Control;

extern u32  func_02010054(void);
extern int  GXx_GetMasterBrightness_(volatile u16 *reg);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int v);
extern u32  GX_HBlankIntr(BOOL on);
extern u32  GX_VBlankIntr(BOOL on);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void GX_SetBankForBG(u32 bank);
extern void GX_SetGraphicsMode(u32 dispMode, u32 bgMode, u32 bg0_2d3d);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG1ScrPtr(void);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern u32  func_02043668(void);
extern void func_020435F4(u32 a);
extern void GFL_NET_ERR_LoadScreenGraphics(u32 a);
extern void func_020101D4(u32 a, u32 b);
extern u8   gNetErrWork[];

#define reg_GX_MASTER_BRIGHT   (*(volatile u16 *)0x0400006C)
#define reg_GXS_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)
#define reg_GX_DISPCNT         (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT     (*(volatile u32 *)0x04001000)
#define reg_G2_BG1CNT          (*(volatile u16 *)0x0400000A)
#define reg_G2_BG1OFS          (*(volatile u32 *)0x04000014)
#define reg_G2_BLDCNT          (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT      (*(volatile u16 *)0x04001050)

static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1F00) | (plane << 8);
}

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

static inline int GXS_GetVisibleWnd(void)
{
    return (int)((reg_GXS_DB_DISPCNT & 0xE000) >> 13);
}

static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}

static inline GXBg01Control G2_GetBG1Control(void)
{
    return *(volatile GXBg01Control *)&reg_G2_BG1CNT;
}

static inline void G2_SetBG1Control(int screenSize, int colorMode, int screenBase,
                                    int charBase, int bgExtPltt)
{
    reg_G2_BG1CNT = (u16)((reg_G2_BG1CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) |
                          (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        reg_G2_BG1CNT |= 0x40;
    } else {
        reg_G2_BG1CNT &= ~0x40;
    }
}

void GFL_NET_ERR_SaveDisplayAndDraw(u32 a0, u32 a1)
{
    u8 *g = gNetErrWork;

    if (func_02010054() == 0) {
        return;
    }
    ((struct Obj01327 *)g)->f14 = GXx_GetMasterBrightness_(&reg_GX_MASTER_BRIGHT);
    ((struct Obj01327 *)g)->f18 = GXx_GetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    if (a1 == 0) {
        ((struct Obj01327 *)g)->f1C = GX_HBlankIntr(0);
        ((struct Obj01327 *)g)->f20 = GX_VBlankIntr(0);
    }
    ((struct Obj01327 *)g)->f24 = func_020808F4();
    ((struct Obj01327 *)g)->f28 = func_020809A0();
    GX_SetBankForBG(4);
    ((struct Obj01327 *)g)->fC = reg_GX_DISPCNT;
    GX_SetGraphicsMode(1, 0, 0);
    GX_SetVisiblePlane(2);
    GX_SetVisibleWnd(0);
    ((struct Obj01327 *)g)->f3C = GXS_GetVisibleWnd();
    GXS_SetVisibleWnd(0);
    *(GXBg01Control *)(g + 0x10) = G2_GetBG1Control();
    G2_SetBG1Control(0, 0, 0, 1, ((GXBg01Control *)(g + 0x10))->bgExtPltt);
    G2_BG1Mosaic(0);
    reg_G2_BG1OFS = 0;
    if (g[0x59] != 0x60) {
        void *dst;
        void *src;
        dst = ((struct Obj01327 *)g)->f0;
        src = G2_GetBG1CharPtr();
        MIi_CpuCopy16(src, dst, 0x4000);
        dst = ((struct Obj01327 *)g)->f4;
        src = G2_GetBG1ScrPtr();
        MIi_CpuCopy16(src, dst, 0x800);
        MIi_CpuCopy16((void *)0x05000000, ((struct Obj01327 *)g)->f8, 0x20);
    }
    ((struct Obj01327 *)g)->f34 = reg_G2_BLDCNT;
    ((struct Obj01327 *)g)->f34 = reg_G2S_DB_BLDCNT;
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    ((struct Obj01327 *)g)->f38 = func_02043668();
    func_020435F4(0);
    ((struct Obj01327 *)g)->f40 = *(volatile u16 *)0x05000400;
    *(volatile u16 *)0x05000400 = 0x7eea;
    if (gNetErrWork[0x59] == 0x60) {
        GFL_NET_ERR_LoadScreenGraphics(1);
    } else {
        GFL_NET_ERR_LoadScreenGraphics(0);
        func_020101D4(a0, a1);
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
}
