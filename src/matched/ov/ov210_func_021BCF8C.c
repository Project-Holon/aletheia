/*
 * function: ZKNSEARCH_MAIN_InitSearchScreen
 * address:  0x021BCF8C
 * packet:   pkt_ov210_021BCF8C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id  0x00000043  data
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   ZUKAN_SAVE_GetViewMode  0x0200CA70  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   ZKNSEARCH_SYS_SetVramBanks  0x021BC3D4  thumb  ov210
 *   ZKNSEARCH_MAIN_InitBackgrounds  0x021BC3F0  thumb  ov210
 *   ZKNSEARCH_MAIN_LoadCommonGraphics  0x021BC5DC  thumb  ov210
 *   ZKNSEARCH_MAIN_InitTextSystem  0x021BC940  thumb  ov210
 *   ZKNSEARCH_MAIN_InitBmpWindows  0x021BE368  thumb  ov210
 *   ZKNSEARCH_MAIN_InitActorSystem  0x021BED2C  thumb  ov210
 *   ZKNSEARCH_MAIN_InitBlinkPalette  0x021BC9D0  thumb  ov210
 *   ZKNSEARCH_MAIN_InitScrollWindow  0x021BCA20  thumb  ov210
 *   ZKNSEARCH_MAIN_EnterResultLayout  0x021BCDA4  thumb  ov210
 *   ZKNSEARCH_MAIN_InitPaletteAnim  0x021BC790  thumb  ov210
 *   ZKNSEARCH_MAIN_RequestPaletteFade  0x021BC82C  thumb  ov210
 *   ZKNSEARCH_MAIN_LoadResultGraphics  0x021BCBB8  thumb  ov210
 *   ZKNSEARCH_MAIN_ConfigureWindow  0x021BC8EC  thumb  ov210
 *   ZKNSEARCH_SYS_RegisterVBlank  0x021BC294  thumb  ov210
 *   ZKNSEARCH_SYS_RegisterHBlank  0x021BC318  thumb  ov210
 *   ZKNSEARCH_MAIN_NormalizeRecordByte  0x021BCF0C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05546.h"
#include "../include/Obj25595.h"
#include "../include/Obj25596.h"
#include "../include/Obj25597.h"
#include "../include/Obj25598.h"
#include "../include/Obj25599.h"
#include "../include/Obj25600.h"
#include "../include/Obj25601.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 ov067_id[];
extern int func_02034AC4(s32 handle);
extern void BG_SYS_SetMainVisiblePlanes(u32 a);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void BG_SYS_SetLcdSwap(u32 a);
struct Blk37;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void ZKNSEARCH_SYS_SetVramBanks(void);
extern void ZKNSEARCH_MAIN_InitBackgrounds(void);
extern void ZKNSEARCH_MAIN_LoadCommonGraphics(void);
extern void ZKNSEARCH_MAIN_InitTextSystem(char *p);
extern void ZKNSEARCH_MAIN_InitBmpWindows(u8 *p);
extern void ZKNSEARCH_MAIN_InitActorSystem(int p);
extern void ZKNSEARCH_MAIN_InitBlinkPalette(int p);
extern void ZKNSEARCH_MAIN_InitScrollWindow(char *p);
extern void ZKNSEARCH_MAIN_EnterResultLayout(char *p);
extern void ZKNSEARCH_MAIN_InitPaletteAnim(char *p);
extern void ZKNSEARCH_MAIN_RequestPaletteFade(char *p, u8 b, u8 c);
extern void ZKNSEARCH_MAIN_LoadResultGraphics(char *p);
extern void ZKNSEARCH_MAIN_ConfigureWindow(void);
extern void ZKNSEARCH_SYS_RegisterVBlank(u8 *p);
extern void ZKNSEARCH_SYS_RegisterHBlank(u8 *p);
extern void ZKNSEARCH_MAIN_NormalizeRecordByte(u8 *p);

u32 ZKNSEARCH_MAIN_InitSearchScreen(u8 *p)
{
    u32 z;
    u32 ra = 0x04000050;
    u32 rb = 0x04001050;
    int m;

    func_02034AC4((u32)ov067_id);
    z = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)&((struct Obj25595 *)ra)->f0 = z;
    *(volatile u16 *)&((struct Obj25596 *)rb)->f0 = z;
    BG_SYS_SetLcdSwap(0);
    m = -16;
    GXx_SetMasterBrightness_((volatile u16 *)(ra + 0x1c), m);
    GXx_SetMasterBrightness_((volatile u16 *)(rb + 0x1c), m);
    if (ZUKAN_SAVE_GetViewMode((struct Blk37 *)(((struct Obj25597 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f4)) == 1) {
        ((struct Obj25599 *)(*(u8 * *)&((struct Obj25598 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f8))->f0 = z;
    } else {
        ((struct Obj25601 *)(*(u8 * *)&((struct Obj25600 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f8))->f0 = 1;
    }
    ZKNSEARCH_SYS_SetVramBanks();
    ZKNSEARCH_MAIN_InitBackgrounds();
    ZKNSEARCH_MAIN_LoadCommonGraphics();
    ZKNSEARCH_MAIN_InitTextSystem((char *)p);
    ZKNSEARCH_MAIN_InitBmpWindows(p);
    ZKNSEARCH_MAIN_InitActorSystem((int)p);
    ZKNSEARCH_MAIN_InitBlinkPalette((int)p);
    GFL_NET_RestartWithDefaultTimeout(1, 0x7b);
    ZKNSEARCH_MAIN_InitScrollWindow((char *)p);
    ZKNSEARCH_MAIN_EnterResultLayout((char *)p);
    ZKNSEARCH_MAIN_InitPaletteAnim((char *)p);
    ZKNSEARCH_MAIN_RequestPaletteFade((char *)p, 16, 16);
    ZKNSEARCH_MAIN_LoadResultGraphics((char *)p);
    ZKNSEARCH_MAIN_ConfigureWindow();
    ZKNSEARCH_SYS_RegisterVBlank(p);
    ZKNSEARCH_SYS_RegisterHBlank(p);
    p[0x2b9] = 0xff;
    ZKNSEARCH_MAIN_NormalizeRecordByte(p);
    return 3;
}
