/*
 * function: POKETRADE_SAVE_StepRebuildSceneAfterWipe
 * address: 0x021E0CC0
 * packet: pkt_ov119_021E0CC0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   POKETRADE_SAVE_CloseMessageWindow 0x021E106C thumb ov119
 *   POKETRADE_2D_ExitSubBgs 0x021E57A4 thumb ov119
 *   POKETRADE_2D_ExitSummaryBgs 0x021E53CC thumb ov119
 *   POKETRADE_2D_SetDisplayConfig 0x021E57E8 thumb ov119
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepResetForNewRound 0x021DACE4 thumb ov119
 */
#include "../include/Obj02828.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
struct Bank;
extern u32 WIPE_SYS_EndCheck(void);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void POKETRADE_SAVE_CloseMessageWindow(char *p);
extern void POKETRADE_2D_ExitSubBgs(int);
extern void POKETRADE_2D_ExitSummaryBgs(int p);
extern void POKETRADE_2D_SetDisplayConfig(int);
extern void POKETRADE_2D_SetupSubBgs(char *p);
extern void POKETRADE_2D_RegisterIconSpriteResources(int);
extern void POKETRADE_2D_CreateBoxIconActors(char *p);
extern void POKETRADE_2D_CreateBoxWindows(char *p);
extern void POKETRADE_2D_LoadBackgroundGfx(char *);
extern void POKETRADE_2D_CreateFontResource(char *p);
extern void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p);
extern void POKETRADE_3D_AddUnitAndInit(void *,int);
extern void POKETRADE_3D_CreateTouchbar(char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepResetForNewRound(char *p);
void POKETRADE_SAVE_StepRebuildSceneAfterWipe(char *p)
{
    if(((struct Obj02828 *)p)->fF2C>=6 && WIPE_SYS_EndCheck()) {
        if(((struct Obj02828 *)p)->f644) BG_SYS_DeleteHalf((int)6,(u16)(((struct Obj02828 *)p)->f644),(u16)(((struct Obj02828 *)p)->f644>>16));
        *(int *)&((struct Obj02828 *)p)->f644=0;
        BG_SYS_SetMainVisiblePlanes((int)0);BG_SYS_SetSubVisiblePlanes((int)0);
        CLACT_DeleteUnit(((struct Obj02828 *)p)->f9C4);
        ((struct Obj02828 *)p)->f9C4=CLACT_CreateUnit(0x154,0,((struct Obj02828 *)p)->f5F4);
        POKETRADE_SAVE_CloseMessageWindow(p);POKETRADE_2D_ExitSubBgs((int)p);POKETRADE_2D_ExitSummaryBgs((int)p);
        POKETRADE_2D_SetDisplayConfig(0);POKETRADE_2D_SetupSubBgs(p);POKETRADE_2D_RegisterIconSpriteResources((int)p);
        POKETRADE_2D_CreateBoxIconActors(p);POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_LoadBackgroundGfx(p);
        POKETRADE_2D_CreateFontResource(p);POKETRADE_2D_LoadMainGfxAndMessageWindow(p);POKETRADE_3D_AddUnitAndInit(p,0);
        BG_SYS_SetMainVisiblePlanes((int)31);BG_SYS_SetSubVisiblePlanes((int)30);POKETRADE_3D_CreateTouchbar(p);
        GFL_NET_RestartWithDefaultTimeout(1,((struct Obj02828 *)p)->f5F4);
        ((struct Obj02828 *)p)->f11FA=0;
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetForNewRound);
    }
}
