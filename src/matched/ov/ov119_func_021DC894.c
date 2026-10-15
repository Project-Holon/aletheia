/*
 * function: POKETRADE_PROC_InitTradeWork
 * address: 0x021DC894
 * packet: pkt_ov119_021DC894
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   d_021E80B0 0x021E80B0 data a4
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   POKETRADE_PROC_SetupGameData 0x021DC538 thumb ov119
 *   POKETRADE_PROC_SetupBoxCounts 0x021DC5F0 thumb ov119
 *   POKETRADE_PROC_InitMcssSystem 0x021DC3EC thumb ov119
 *   POKETRADE_PROC_InitDisplay 0x021DC458 thumb ov119
 *   CLACT_CreateUnit 0x0204B100 arm
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021E7614 0x021E7614 data a4
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_020056A0 0x020056A0 thumb
 *   POKETRADE_PROC_VBlank 0x021DC500 thumb ov119
 *   POKETRADE_3D_Init3DScene 0x021E30EC thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepSaveCancelNotice 0x021E0B34 thumb ov119
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_PROC_LoadSceneResources 0x021DC494 thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_PROC_StepRestartNetSession 0x021DAC60 thumb ov119
 */
#include "../include/Obj03256.h"
#include "../include/Obj04478.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_02034AC4(int);
extern unsigned int POKE_TOOL_GetPartyParamSize(void);
extern int POKETRADE_PROC_IsNetSession(void *);
extern char ov067_id[],ov114_id[],ov117_id[],ov118_id[];
extern void BG_SYS_SetLcdSwap(unsigned int swap);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void BG_SYS_SetMainVisiblePlanes(unsigned int planes);
extern void BG_SYS_SetSubVisiblePlanes(unsigned int planes);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned int a, unsigned int b);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern const char d_021E80B0[];
extern char d_021E7614[];
extern void *ZUKAN_SAVE_GetFromGameData(void *);
typedef unsigned int   u32;
struct Bank;
struct Blk37;
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern void POKETRADE_PROC_SetupGameData(char *,void *,u16),POKETRADE_PROC_SetupBoxCounts(char *),POKETRADE_PROC_InitMcssSystem(char *),POKETRADE_PROC_InitDisplay(char *);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void GFL_NET_COMMAND_AddCommandTable(unsigned,unsigned,unsigned,unsigned);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void POKETRADE_PROC_VBlank(int a, char *p);
extern void POKETRADE_3D_Init3DScene(char *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_SAVE_StepSaveCancelNotice(char *p);
extern void POKETRADE_SAVE_CreateMessageResources(char *p);
extern void POKETRADE_2D_CreateFontResource(char *p);
extern void POKETRADE_PROC_LoadSceneResources(char *);
extern void POKETRADE_3D_CreateTouchbar(char *p);
extern void POKETRADE_3D_AddUnitAndInit(void *,int);
extern void POKETRADE_PROC_StepRestartNetSession(char *p);
#define I(o) (*(int *)(p+(o)))
#define H(o) (*(u16 *)(p+(o)))
int POKETRADE_PROC_InitTradeWork(int a,int b,char *q,char *p,int n)
{
    if(n<5) {func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);}
    if(n==0 || n==4) func_02034AC4((int)ov117_id);
    else func_02034AC4((int)ov118_id);
    BG_SYS_SetLcdSwap(1);
    H(0x5f4)=31;
    I(0x118c)=n;
    *(char * *)&((struct Obj03256 *)p)->f8=q;
    I(0x5dc)=(int)func_02030734(0x91,POKE_TOOL_GetPartyParamSize(),1,d_021E80B0,0x110b);
    I(0x5e0)=(int)func_02030734(0x91,POKE_TOOL_GetPartyParamSize(),1,d_021E80B0,0x110c);
    I(0x10a4)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110d);
    I(0x10a8)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110e);
    ((struct Obj03256 *)p)->f11F6=ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(((struct Obj04478 *)q)->f14));
    if(q) POKETRADE_PROC_SetupGameData(p,((struct Obj04478 *)q)->f14,((struct Obj04478 *)q)->f2E);
    POKETRADE_PROC_SetupBoxCounts(p);POKETRADE_PROC_InitMcssSystem(p);POKETRADE_PROC_InitDisplay(p);
    I(0x9c4)=(int)CLACT_CreateUnit(0x154,0,H(0x5f4));
    if(POKETRADE_PROC_IsNetSession(p)) {
        GFL_NET_COMMAND_AddCommandTable(0xc00,(unsigned)d_021E7614,24,(unsigned)p);
        GFL_NET_SetAutoExit(1);GFL_NET_SetLoginOption(1);
    }
    I(0x9c8)=(int)func_020056A0((void (*)(void *, void *))POKETRADE_PROC_VBlank,p,0);
    I(0xf60)=0;
    I(0xf84)=-1;I(0x109c)=-1;I(0xf7c)=-1;I(0xf80)=-1;I(0xf98)=-1;I(0xf94)=-1;
    POKETRADE_3D_Init3DScene(p);
    if(((struct Obj04478 *)q)->f8==1) {
        BG_SYS_SetMainVisiblePlanes(16);POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepSaveCancelNotice);((struct Obj04478 *)q)->f8=0;return 1;
    }
    POKETRADE_SAVE_CreateMessageResources(p);POKETRADE_2D_CreateFontResource(p);
    if(I(0x118c)<4) {POKETRADE_PROC_LoadSceneResources(p);POKETRADE_3D_CreateTouchbar(p);GFL_NET_RestartWithDefaultTimeout(1,H(0x5f4));}
    POKETRADE_3D_AddUnitAndInit(p,0);BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRestartNetSession);
    return 1;
}
