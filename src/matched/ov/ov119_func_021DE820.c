/*
 * unit: yes
 * function: POKETRADE_NEGO_StepRebuildSceneAfterWipe, POKETRADE_NEGO_StepWaitMessageThenWipe
 * address: 0x021DE820
 * packet: pkt_ov119_021DE820
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021DE89A reads 0x04001000 before the store at 0x021DE89E.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKETRADE_PROC_DeleteAllResources 0x021DC720 thumb ov119
 *   POKETRADE_2D_SetDisplayConfig 0x021E57E8 thumb ov119
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 *   CLACT_CreateUnit 0x0204B100 arm
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepResetForNewRound 0x021DACE4 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_TickWifiTimer 0x021DD140 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_NEGO_StepRebuildSceneAfterWipe 0x021DE820 thumb ov119
 */
#include "../include/Obj00001.h"
#include "../include/Obj00252.h"

typedef unsigned short u16;
extern unsigned int WIPE_SYS_EndCheck(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern void POKETRADE_PROC_DeleteAllResources(char *p);
extern void POKETRADE_2D_SetDisplayConfig(int);
extern void POKETRADE_2D_SetupSubBgs(char *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void POKETRADE_SAVE_CreateMessageResources(char *p);
extern void POKETRADE_2D_RegisterIconSpriteResources(int p);
extern void POKETRADE_2D_CreateBoxIconActors(char *p);
extern void POKETRADE_2D_LoadBackgroundGfx(char *p);
extern void POKETRADE_2D_CreateFontResource(char *p);
extern void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p);
extern void POKETRADE_3D_AddUnitAndInit(void *,int);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void POKETRADE_3D_CreateTouchbar(char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepResetForNewRound(char *p);
void POKETRADE_NEGO_StepRebuildSceneAfterWipe(char *p)
{
    if(WIPE_SYS_EndCheck()) {
        POKETRADE_PROC_DeleteAllResources(p); POKETRADE_2D_SetDisplayConfig(0); POKETRADE_2D_SetupSubBgs(p);
        ((struct Obj00252 *)p)->f9C4=CLACT_CreateUnit(0x154,0,((struct Obj00252 *)p)->f5F4);
        POKETRADE_SAVE_CreateMessageResources(p); POKETRADE_2D_RegisterIconSpriteResources((int)p); POKETRADE_2D_CreateBoxIconActors(p);
        POKETRADE_2D_LoadBackgroundGfx(p); POKETRADE_2D_CreateFontResource(p); POKETRADE_2D_LoadMainGfxAndMessageWindow(p);
        POKETRADE_3D_AddUnitAndInit(p,0); BG_SYS_SetMainVisiblePlanes(31); BG_SYS_SetSubVisiblePlanes(30);
        POKETRADE_3D_CreateTouchbar(p); GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00252 *)p)->f5F4);
        *(volatile unsigned *)0x04001000 &= 0xffff1fff;
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetForNewRound);
    }
}

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int POKETRADE_PROC_TickWifiTimer(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void POKETRADE_NEGO_StepWaitMessageThenWipe(char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(POKETRADE_SAVE_IsMessagePrintDone(p) && POKETRADE_PROC_TickWifiTimer(p) && ((struct Obj00001 *)p)->fF2C>=120) {
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepRebuildSceneAfterWipe);
    }
}
