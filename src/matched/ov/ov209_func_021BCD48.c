/*
 * function: ZUKAN_LIST_StateExit
 * address: 0x021BCD48
 * packet: pkt_ov209_021BCD48
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCDB6, 021BCDBA
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_02034A5C 0x02034A5C arm
 *   ZUKAN_LIST_UpdateActorMove 0x021BC91C thumb ov209
 *   ZUKAN_LIST_StopHBlankTask 0x021BC2FC thumb ov209
 *   ZUKAN_LIST_StopVBlankTask 0x021BC2B0 thumb ov209
 *   ZUKAN_LIST_DisableSubWindows 0x021BC810 thumb ov209
 *   ZUKAN_LIST_DeleteFrameList 0x021BCB60 thumb ov209
 *   ZUKAN_LIST_FreeFormTable 0x021BC8A4 thumb ov209
 *   ZUKAN_LIST_ExitActors 0x021BD824 thumb ov209
 *   ZUKAN_LIST_DeleteWindows 0x021BD3E0 thumb ov209
 *   ZUKAN_LIST_DeleteFontAndPrinter 0x021BC868 thumb ov209
 *   ZUKAN_LIST_ExitBgSystem 0x021BC52C thumb ov209
 *   ZUKAN_LIST_ExitPaletteAnim 0x021BC704 thumb ov209
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 */
#include "../include/Obj00088.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char ov067_id[];
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern void func_02034A5C(int);
extern int ZUKAN_LIST_UpdateActorMove(char *);
extern void ZUKAN_LIST_DisableSubWindows(void);
extern void ZUKAN_LIST_ExitBgSystem(void);
extern void ZUKAN_LIST_StopHBlankTask(char *);
extern void ZUKAN_LIST_StopVBlankTask(char *);
extern void ZUKAN_LIST_DeleteFrameList(char *);
extern void ZUKAN_LIST_FreeFormTable(char *);
extern void ZUKAN_LIST_ExitActors(char *);
extern void ZUKAN_LIST_DeleteWindows(char *);
extern void ZUKAN_LIST_DeleteFontAndPrinter(char *);
extern void ZUKAN_LIST_ExitPaletteAnim(char *);
int ZUKAN_LIST_StateExit(char *p)
{
    if (ZUKAN_LIST_UpdateActorMove(p) == 1 || PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) != 0) return 1;
    ZUKAN_LIST_StopHBlankTask(p);
    ZUKAN_LIST_StopVBlankTask(p);
    ZUKAN_LIST_DisableSubWindows();
    ZUKAN_LIST_DeleteFrameList(p);
    ZUKAN_LIST_FreeFormTable(p);
    ZUKAN_LIST_ExitActors(p);
    ZUKAN_LIST_DeleteWindows(p);
    ZUKAN_LIST_DeleteFontAndPrinter(p);
    ZUKAN_LIST_ExitBgSystem();
    ZUKAN_LIST_ExitPaletteAnim(p);
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return 9;
}
