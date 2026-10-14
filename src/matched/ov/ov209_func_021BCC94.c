/*
 * function: ZUKAN_LIST_StateInit
 * address: 0x021BCC94
 * packet: pkt_ov209_021BCC94
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCCB0, 021BCCB2
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ZUKAN_LIST_InitPaletteAnim 0x021BC6C4 thumb ov209
 *   ZUKAN_LIST_SetVramBanks 0x021BC370 thumb ov209
 *   ZUKAN_LIST_InitBgSystem 0x021BC388 thumb ov209
 *   ZUKAN_LIST_LoadBgGraphics 0x021BC574 thumb ov209
 *   ZUKAN_LIST_CreateFontAndPrinter 0x021BC824 thumb ov209
 *   ZUKAN_LIST_CreateWindows 0x021BD398 thumb ov209
 *   ZUKAN_LIST_InitActors 0x021BD7F8 thumb ov209
 *   ZUKAN_LIST_LoadFormTable 0x021BC88C thumb ov209
 *   ZUKAN_LIST_CreateFrameList 0x021BC9A8 thumb ov209
 *   ZUKAN_LIST_DrawHeaderCounts 0x021BD628 thumb ov209
 *   ZUKAN_LIST_DrawHeaderNational 0x021BD704 thumb ov209
 *   ZUKAN_LIST_SetSubScreenBlendAlpha 0x021BC7B8 thumb ov209
 *   ZUKAN_LIST_EnableSubWindows 0x021BC7D0 thumb ov209
 *   ZUKAN_LIST_MoveScrollBarActorsIn 0x021BC8B4 thumb ov209
 *   ZUKAN_LIST_StartVBlankTask 0x021BC298 thumb ov209
 *   ZUKAN_LIST_StartHBlankTask 0x021BC2E4 thumb ov209
 */
#include "../include/Obj00123.h"
#include "../include/Obj25546.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char ov067_id[];
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern int func_02034AC4(int);
extern void BG_SYS_SetLcdSwap(u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void ZUKAN_LIST_SetVramBanks(void);
extern void ZUKAN_LIST_InitBgSystem(void);
extern void ZUKAN_LIST_LoadBgGraphics(void);
extern void ZUKAN_LIST_SetSubScreenBlendAlpha(void);
extern void ZUKAN_LIST_InitPaletteAnim(char *);
extern void ZUKAN_LIST_CreateFontAndPrinter(char *);
extern void ZUKAN_LIST_CreateWindows(char *);
extern void ZUKAN_LIST_InitActors(char *);
extern void ZUKAN_LIST_LoadFormTable(char *);
struct Context;
extern void ZUKAN_LIST_CreateFrameList(struct Context *p);
extern void ZUKAN_LIST_DrawHeaderCounts(char *);
extern void ZUKAN_LIST_DrawHeaderNational(char *);
extern void ZUKAN_LIST_MoveScrollBarActorsIn(char *);
extern void ZUKAN_LIST_StartVBlankTask(char *);
extern void ZUKAN_LIST_StartHBlankTask(char *);
extern void ZUKAN_LIST_EnableSubWindows(void);
int ZUKAN_LIST_StateInit(char *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetLcdSwap(0);
    ZUKAN_LIST_InitPaletteAnim(p);
    ZUKAN_LIST_SetVramBanks();
    ZUKAN_LIST_InitBgSystem();
    ZUKAN_LIST_LoadBgGraphics();
    ZUKAN_LIST_CreateFontAndPrinter(p);
    ZUKAN_LIST_CreateWindows(p);
    ZUKAN_LIST_InitActors(p);
    ZUKAN_LIST_LoadFormTable(p);
    ZUKAN_LIST_CreateFrameList((struct Context *)p);
    if (((struct Obj25546 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f8 == 0) ZUKAN_LIST_DrawHeaderCounts(p);
    else ZUKAN_LIST_DrawHeaderNational(p);
    GFL_NET_RestartWithDefaultTimeout(1, 0x6B);
    ZUKAN_LIST_SetSubScreenBlendAlpha();
    ZUKAN_LIST_EnableSubWindows();
    ZUKAN_LIST_MoveScrollBarActorsIn(p);
    ZUKAN_LIST_StartVBlankTask(p);
    ZUKAN_LIST_StartHBlankTask(p);
    return 3;
}
