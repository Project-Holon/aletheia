/*
 * function: ZKNSEARCH_MAIN_ExitSearchScreen
 * address: 0x021BD064
 * packet: pkt_ov210_021BD064
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware stores at 0x021BD0D8 and 0x021BD0DC.
 * symbols:
 *   ZKNSEARCH_MAIN_UpdateScrollMove 0x021BCE58 thumb ov210
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   ZKNSEARCH_SYS_UnregisterHBlank 0x021BC330 thumb ov210
 *   ZKNSEARCH_SYS_UnregisterVBlank 0x021BC2AC thumb ov210
 *   ZKNSEARCH_MAIN_ResetWindow 0x021BC92C thumb ov210
 *   ZKNSEARCH_MAIN_DeleteResultGraphics 0x021BCC1C thumb ov210
 *   ZKNSEARCH_MAIN_DeleteScrollWindow 0x021BCA78 thumb ov210
 *   ZKNSEARCH_MAIN_DeletePaletteAnim 0x021BC800 thumb ov210
 *   ZKNSEARCH_MAIN_UpdateBlinkPalette 0x021BCA10 thumb ov210
 *   ZKNSEARCH_MAIN_DeleteActorSystem 0x021BED54 thumb ov210
 *   ZKNSEARCH_MAIN_DeleteBmpWindows 0x021BE3B4 thumb ov210
 *   ZKNSEARCH_MAIN_DeleteTextSystem 0x021BC99C thumb ov210
 *   ZKNSEARCH_MAIN_DeleteBackgrounds 0x021BC578 thumb ov210
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj00085.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
extern int ZKNSEARCH_MAIN_UpdateScrollMove(char *);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern u32 ZKNSEARCH_SYS_UnregisterHBlank(u8 *p);
extern u32 ZKNSEARCH_SYS_UnregisterVBlank(u8 *p);
extern void ZKNSEARCH_MAIN_ResetWindow(u32);
extern u32 ZKNSEARCH_MAIN_DeleteResultGraphics(u8 *);
extern void ZKNSEARCH_MAIN_DeleteScrollWindow(u8 *p);
extern void ZKNSEARCH_MAIN_DeletePaletteAnim(u8 *p);
extern u32 ZKNSEARCH_MAIN_UpdateBlinkPalette(u8 *);
extern void ZKNSEARCH_MAIN_DeleteActorSystem(int p);
extern void ZKNSEARCH_MAIN_DeleteBmpWindows(char *);
extern u32 ZKNSEARCH_MAIN_DeleteTextSystem(u8 *p);
extern void ZKNSEARCH_MAIN_DeleteBackgrounds(u32);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void func_02034A5C(int);
extern const char ov067_id[];
int ZKNSEARCH_MAIN_ExitSearchScreen(char *p)
{
    if (ZKNSEARCH_MAIN_UpdateScrollMove(p) == 1 || PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00085 *)p)->fC) != 0) return 1;
    ZKNSEARCH_SYS_UnregisterHBlank((u8 *)p);
    ZKNSEARCH_MAIN_ResetWindow(ZKNSEARCH_SYS_UnregisterVBlank((u8 *)p));
    ZKNSEARCH_MAIN_DeleteResultGraphics((u8 *)p);
    ZKNSEARCH_MAIN_DeleteScrollWindow((u8 *)p);
    ZKNSEARCH_MAIN_DeletePaletteAnim((u8 *)p);
    ZKNSEARCH_MAIN_UpdateBlinkPalette((u8 *)p);
    ZKNSEARCH_MAIN_DeleteActorSystem((int)p);
    ZKNSEARCH_MAIN_DeleteBmpWindows(p);
    ZKNSEARCH_MAIN_DeleteBackgrounds(ZKNSEARCH_MAIN_DeleteTextSystem((u8 *)p));
    GXx_SetMasterBrightness_((void *)0x0400006c, -16);
    GXx_SetMasterBrightness_((void *)0x0400106c, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return 27;
}
