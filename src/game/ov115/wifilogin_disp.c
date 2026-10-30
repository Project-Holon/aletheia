/*
 * file:     wifilogin_disp.c
 * unit:     yes
 * function: WIFILOGIN_DISP_CreateDisplay, WIFILOGIN_DISP_Draw, WIFILOGIN_DISP_DeleteDisplay, WIFILOGIN_DISP_InitBgLayersA, WIFILOGIN_DISP_InitBgLayersB, WIFILOGIN_DISP_InitBgLayersC, WIFILOGIN_DISP_InitBgLayersD, WIFILOGIN_DISP_LoadPalette, WIFILOGIN_DISP_UpdatePalette, WIFILOGIN_DISP_CreateActors, WIFILOGIN_DISP_CreateUnit, WIFILOGIN_DISP_DrawActors, WIFILOGIN_DISP_DeleteActors, WIFILOGIN_DISP_ScanlineEffect, WIFILOGIN_DISP_VBlank, WIFILOGIN_DISP_SetPaletteFlag, WIFILOGIN_DISP_SetupScreen
 * address:  0x021D4D38
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifilogin_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIFILIST_GetWork 0x02009860 thumb
 *   WIFILIST_GetDwcFriendData 0x020099C8 thumb
 *   WIFILIST_MergeFriendRecord 0x02009C24 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_COMMON_IsCancelInput 0x021D4240 thumb ov115
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   APP_ENV_IsRunOnTwl 0x0202EB0C thumb
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DWC_RAP_ClearUserDataChanged 0x02156C98 thumb ov009
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   MYSTATUS_SetProfileIdOnce 0x02008540 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_STATE_WifiStartMatch 0x0203C8A8 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   d_021D6560 0x021D6560 data a4
 *   d_021D65C0 0x021D65C0 data a4
 *   gWifiloginDialogId 0x021D6640 data a4
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_ERR_WaitLinkClosed 0x0200FBB0 thumb
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_ERR_ResetState 0x0200FBA0 thumb
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   GFL_NET_ERR_HaltIfActive 0x0200FA84 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   WIFILIST_Init 0x02009800 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   APP_ENV_IsWirelessAvailable 0x0202EB44 thumb
 *   APP_ENV_IsEulaAgreed 0x0202EB4C thumb
 *   DWC_CheckHasProfile 0x020597C8 arm
 *   DWC_CheckValidConsole 0x02059760 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   DWC_SVLGetTokenAsync 0x02167FA8 arm ov009
 *   d_021D65D0 0x021D65D0 data a4
 *   DWC_SVLProcess 0x02168040 arm ov009
 *   GF_PANIC_Fail 0x02034714 arm
 *   GF_PANIC_FailPrintf 0x02034734 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   d_021D6614 0x021D6614 data a1
 *   d_021D65E4 0x021D65E4 data a4
 *   d_021D65D4 0x021D65D4 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   data_021D6364 0x021D6364 data a4
 *   data_021D64C4 0x021D64C4 data a4
 *   data_021D64A4 0x021D64A4 data a4
 *   data_021D6484 0x021D6484 data a4
 *   d_021D6464 0x021D6464 data a4
 *   d_021D6444 0x021D6444 data a4
 *   d_021D6424 0x021D6424 data a4
 *   d_021D6524 0x021D6524 data a4
 *   d_021D63E4 0x021D63E4 data a4
 *   d_021D63C4 0x021D63C4 data a4
 *   d_021D63A4 0x021D63A4 data a4
 *   d_021D6384 0x021D6384 data a4
 *   d_021D6404 0x021D6404 data a4
 *   d_021D6344 0x021D6344 data a4
 *   d_021D64E4 0x021D64E4 data a4
 *   d_021D6504 0x021D6504 data a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   PALANM_BlendColors 0x02021F64 thumb
 *   DC_FlushRange 0x020862F0 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   FX_MakeSineTable 0x02024230 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WIFILOGIN_MSG_Create 0x021D5984 thumb ov115
 *   WIFILOGIN_MSG_Run 0x021D5A88 thumb ov115
 *   WIFILOGIN_MSG_Delete 0x021D5A9C thumb ov115
 *   WIFILOGIN_MSG_Draw 0x021D5B50 thumb ov115
 *   WIFILOGIN_MSG_SetMessage 0x021D5C24 thumb ov115
 *   WIFILOGIN_MSG_IsPrintDone 0x021D5C70 thumb ov115
 *   WIFILOGIN_MSG_RedrawWindow 0x021D5C94 thumb ov115
 *   WIFILOGIN_MSG_ShowMessage 0x021D5CCC thumb ov115
 *   WIFILOGIN_MSG_CloseMessage 0x021D5D3C thumb ov115
 *   WIFILOGIN_MSG_OpenTask 0x021D5D5C thumb ov115
 *   WIFILOGIN_MSG_CloseTask 0x021D5E34 thumb ov115
 *   WIFILOGIN_MSG_UpdateTask 0x021D5E48 thumb ov115
 *   WIFILOGIN_MSG_IsTaskFinish 0x021D5E6C thumb ov115
 *   WIFILOGIN_MSG_GetTaskCursor 0x021D5EA8 thumb ov115
 *   WIFILOGIN_MSG_PrintMessage 0x021D5ED8 thumb ov115
 *   WIFILOGIN_MSG_RedrawBorder 0x021D5F7C thumb ov115
 */
#include "../version.h"
#include "ov115_types.h"
#include "../sdk_ioreg.h"

struct BigObj;

struct Sub020097BCObj;

struct Sub020097BCFriend;

struct Req;

struct Big;

struct Rec160;

struct Reg2;

struct DWCstAccUserData;

struct DispConfig;

struct DispVram;

struct Node;

struct Bank;

#ifdef __MWERKS__
#define BG_SYS_PushTile BG_SYS_PushTile_hdr
#define BG_SYS_SetTileEntry BG_SYS_SetTileEntry_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_PushTile
#undef BG_SYS_SetTileEntry
void BG_SYS_PushTile(u8);
void BG_SYS_SetTileEntry(u8, int, int, int, u8, u8, u8);
#endif

struct WifiloginDispRect { short x,y; u16 z; u8 kind,mode; };
struct GameData;
struct FieldState;

#include "../arm9/game_data.h"
struct WifiList;

#include "../arm9/wifilist.h"


#include "../arm9/wipe.h"

#include "wifilogin_common.h"


#include "../arm9/net_state.h"

#ifdef __MWERKS__
#define APP_ENV_IsWirelessAvailable APP_ENV_IsWirelessAvailable_hdr
#endif
#include "../arm9/app_env.h"
#ifdef __MWERKS__
#undef APP_ENV_IsWirelessAvailable
int APP_ENV_IsWirelessAvailable(u8 *);
#endif

#include "../ov009/dwc_rap.h"
struct GameData;


struct MyStatus;


#include "../arm9/mystatus.h"


#include "../arm9/os_emulator.h"

#include "../arm9/net.h"


#include "../arm9/net_err.h"


struct RegulationCard;

#include "../arm9/regulation.h"
struct SaveControl;
struct BattleCompetitionSave;


struct BattleBoxSave;

#include "../arm9/battle_box.h"


#include "../arm9/dwc_account.h"


#include "../arm9/gfl_use.h"

#include "../ov009/dwc_nasfunc.h"


#include "../arm9/gf_panic.h"

#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"


#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gx.h"


struct TcbTask;

#include "../arm9/tcb_list.h"


#include "../arm9/arc_tool.h"


#include "../arm9/arc_util.h"


#ifdef __MWERKS__
#define PALANM_BlendColors PALANM_BlendColors_hdr
#endif
#include "../arm9/palanm.h"
#ifdef __MWERKS__
#undef PALANM_BlendColors
void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
#endif

#include "../arm9/os_cache.h"
#include "../arm9/nns_g2d_res_types.h"


#include "../arm9/g2.h"


#include "../arm9/gx_load2d.h"


#include "../arm9/clact.h"


struct ClactActor;


#include "../arm9/pmsi_param.h"
struct DispVramCfg;
struct SysInit;


void *WIFILOGIN_DISP_GetWifiUserData(u8 *p);

void *WIFILOGIN_DISP_GetDwcFriendDataSlot0(u8 *p);

void WIFILOGIN_DISP_CopyProfileSlot(int a,int b,u8 *p);

void WIFILOGIN_DISP_StepCancelOnReady(u8 *p);

void WIFILOGIN_DISP_StepCancel(u8 *p);

void WIFILOGIN_DISP_StepWaitLogin(u8 *p);

void WIFILOGIN_DISP_StepSaveResult(u8 *p);

void WIFILOGIN_DISP_StepStartSave(u8 *p);

void WIFILOGIN_DISP_StepCheckSave(u8 *p);

void WIFILOGIN_DISP_StartSession(u8 *p);

void WIFILOGIN_DISP_StepConfirmProfileResult(u8 *p);

void WIFILOGIN_DISP_StepConfirmConsoleResult(u8 *p);

void WIFILOGIN_DISP_StepConfirmProfile(u8 *p);

void WIFILOGIN_DISP_StepConfirmConsole(u8 *p);

int WIFILOGIN_DISP_HandleNetError(u8 *p);

void WIFILOGIN_DISP_StepMenuAfterProfileError(u8 *p);

void WIFILOGIN_DISP_StepCardMenu(u8 *p);

void WIFILOGIN_DISP_StepOpenCardMenu(u8 *p);

void WIFILOGIN_DISP_StepCardSelect(u8 *p);

void WIFILOGIN_DISP_StepOpenCardMenu2(u8 *p);

void WIFILOGIN_DISP_StepCardMenu2(u8 *p);

void WIFILOGIN_DISP_StepOpenCardMenu3(u8 *p);

void WIFILOGIN_DISP_StepCancelWait(u8 *p);

void WIFILOGIN_DISP_StepCheckAccount(u8 *p);

void WIFILOGIN_DISP_StepFinish(u8 *p);

void WIFILOGIN_DISP_StepCallSync(unsigned char *a);

void WIFILOGIN_DISP_StepStartWipe(u8 *p);

void WIFILOGIN_DISP_StepGetToken(u8 *p);

void WIFILOGIN_DISP_StepBeginToken(u8 *p);

void WIFILOGIN_DISP_StepPollToken(u8 *p);

int WIFILOGIN_DISP_Create(void *ctx,int unused,u8 *q);

int WIFILOGIN_DISP_Update(int a,int b,int c,u8 *p);

int WIFILOGIN_DISP_Delete(struct Proc *a,int b,int c,u8 *p);

u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int reconnect);

void WIFILOGIN_DISP_Draw(u8 *p);

void WIFILOGIN_DISP_DeleteDisplay(u8 *p);

void WIFILOGIN_DISP_InitBgLayersA(u32 unused,unsigned long base);

void WIFILOGIN_DISP_InitBgLayersB(void *unused, unsigned long base);

void WIFILOGIN_DISP_InitBgLayersC(void *unused, unsigned long base);

void WIFILOGIN_DISP_InitBgLayersD(void *unused, unsigned long base);

void WIFILOGIN_DISP_LoadPalette(char *p);

void WIFILOGIN_DISP_UpdatePalette(void *unused, struct WifiloginPalTask *p);

void WIFILOGIN_DISP_CreateActors(u8 *p);

void WIFILOGIN_DISP_CreateUnit(u8 *p);

void WIFILOGIN_DISP_DrawActors(u8 *p);

void WIFILOGIN_DISP_DeleteActors(u8 *p);

void WIFILOGIN_DISP_ScanlineEffect(struct TcbTask *unused, void *p);

void WIFILOGIN_DISP_VBlank(struct TcbTask *task, void *arg);

void WIFILOGIN_DISP_SetPaletteFlag(u8 *p);

void WIFILOGIN_DISP_SetupScreen(u8 *p);

#include "wifilogin_message.h"


#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021D64B4[];
extern const char str_ja_021D64C8[];
#endif

extern u8 d_021D6560[];

extern u8 d_021D65C0[];

extern u8 gWifiloginDialogId[];

extern char d_021D65D0[];

extern u8 d_021D6614[];

extern u32 d_021D65E4[];

extern u32 d_021D65D4[];

extern const struct BgTemplate data_021D6364,data_021D64C4,data_021D64A4,data_021D6484;

extern const struct BgTemplate d_021D6464, d_021D6444, d_021D6424, d_021D6524;

extern const struct BgTemplate d_021D63E4, d_021D63C4, d_021D63A4, d_021D6384;

extern const struct BgTemplate d_021D6404, d_021D6344, d_021D64E4, d_021D6504;

extern u8 gClActorInitParam[];


/*
 * volatile: hardware reads/writes 021D4D66, 021D4D70, 021D4D74.
 */
u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int reconnect) {
    u8 *p;
    p=GFL_HEAP_Alloc(heap,sizeof(struct WifiloginDisp),1,(const char *)d_021D6614,146);
    ((struct WifiloginDisp *)p)->heapId=heap;
    ((struct WifiloginDisp *)p)->mode=mode;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)REG_BLDCNT_ADDR=0;
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)REG_DB_DISPCNT_ADDR |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct WifiloginDisp *)p)->heapId);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021D65E4);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021D65D4);
    switch (((struct WifiloginDisp *)p)->mode) {
    case 1:
        WIFILOGIN_DISP_InitBgLayersB(p,0);
        WIFILOGIN_DISP_InitBgLayersD(p,4);
        WIFILOGIN_DISP_CreateUnit(p);
        WIFILOGIN_DISP_CreateActors(p);
        break;
    case 0:
        WIFILOGIN_DISP_InitBgLayersA((uptr)p,0);
        WIFILOGIN_DISP_InitBgLayersC(p,4);
        WIFILOGIN_DISP_LoadPalette((char *)p);
        break;
    }
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return p;
}

/*
 * trailing: two-byte alignment padding, no follower.
 */
void WIFILOGIN_DISP_Draw(u8 *p) { if(((struct WifiloginDisp *)p)->mode==1) WIFILOGIN_DISP_DrawActors(p); }

void WIFILOGIN_DISP_DeleteDisplay(u8 *p) {
    if (((struct WifiloginDisp *)p)->mode == 1) WIFILOGIN_DISP_DeleteActors(p);
    else if (((struct WifiloginDisp *)p)->pal.frameTask) {
        TCB_DeleteTask(((struct WifiloginDisp *)p)->pal.frameTask);
        ((struct WifiloginDisp *)p)->pal.frameTask = 0;
        ((struct WifiloginDisp *)p)->pal.ready = 0;
    }
    BG_SYS_FreeTiles(5, 1, 0);
    BG_SYS_FreeTiles(6, 1, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_Delete();
    GFL_HEAP_Free(p);
}

/*
 * lever: initialized wrapping base+1 temporary before the first commit, then layer assignments before the following template copies, preserves the four table/call sequences and the original register webs.
 * ABI: first argument unused; full32 base is incremented with wrapping arithmetic and passed untruncated to40C14, while template/toggle/commit/rectangle calls explicitly truncate8 in the original.
 */
void WIFILOGIN_DISP_InitBgLayersA(u32 unused,unsigned long base)
{
    struct BgTemplate a,b,c,d;
    unsigned long layer1,layer2,layer3;
    u32 tmp;
    a=data_021D6364;
    BG_SYS_InitBgLayer((u8)base,&a,0);
    BG_SYS_SetPlaneVisible(base,1);
    tmp=(u32)base+1;
    BG_SYS_PushTile(base);
    layer1=tmp;
    b=data_021D64C4;
    BG_SYS_InitBgLayer((u8)layer1,&b,0);
    BG_SYS_SetPlaneVisible(layer1,1);
    BG_SYS_Init(layer1,0,1,0);
    BG_SYS_SetTileEntry(layer1,0,0,0,32,32,17);
    BG_SYS_PushTile(layer1);
    layer2=(u32)base+2;
    c=data_021D64A4;
    BG_SYS_InitBgLayer((u8)layer2,&c,0);
    BG_SYS_SetPlaneVisible(layer2,1);
    BG_SYS_SetTileEntry(layer2,0,0,0,32,32,17);
    BG_SYS_PushTile(layer2);
    layer3=(u32)base+3;
    d=data_021D6484;
    BG_SYS_InitBgLayer((u8)layer3,&d,0);
    BG_SYS_SetPlaneVisible(layer3,1);
    BG_SYS_Init(layer3,0,1,0);
    BG_SYS_SetTileEntry(layer3,0,0,0,32,32,17);
    BG_SYS_PushTile(layer3);
}

/*
 * ABI: base and unsigned-long indices are full 32-bit wrapping values;
 *   only BG calls with original lsls/lsrs pairs take u8.  Template copies
 *   follow index assignment; four distinct 32-byte locals preserve layout.
 */
void WIFILOGIN_DISP_InitBgLayersB(void *unused, unsigned long base)
{
    struct BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6464;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    BG_SYS_SetPlaneVisible(base, 1);
    BG_SYS_PushTile(base);
    id1 = base + 1;
    t1 = d_021D6444;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    BG_SYS_SetPlaneVisible(id1, 1);
    BG_SYS_PushTile(id1);
    id2 = base + 2;
    t2 = d_021D6424;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    BG_SYS_SetPlaneVisible(id2, 1);
    BG_SYS_PushTile(id2);
    id3 = base + 3;
    t3 = d_021D6524;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    BG_SYS_SetPlaneVisible(id3, 1);
    BG_SYS_Init(id3, 0, 1, 0);
    BG_SYS_SetTileEntry(id3, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id3);
}

void WIFILOGIN_DISP_InitBgLayersC(void *unused, unsigned long base)
{
    struct BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D63E4;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    BG_SYS_SetPlaneVisible(base, 1);
    BG_SYS_PushTile(base);
    id1 = base + 1;
    t1 = d_021D63C4;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    BG_SYS_SetPlaneVisible(id1, 1);
    BG_SYS_Init(id1, 0, 1, 0);
    BG_SYS_SetTileEntry(id1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id1);
    id2 = base + 2;
    t2 = d_021D63A4;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    BG_SYS_SetPlaneVisible(id2, 1);
    BG_SYS_Init(id2, 0, 1, 0);
    BG_SYS_SetTileEntry(id2, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id2);
    id3 = base + 3;
    t3 = d_021D6384;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    BG_SYS_SetPlaneVisible(id3, 1);
    BG_SYS_Init(id3, 0, 1, 0);
    BG_SYS_SetTileEntry(id3, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id3);
}

void WIFILOGIN_DISP_InitBgLayersD(void *unused, unsigned long base)
{
    struct BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6404;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    BG_SYS_SetPlaneVisible(base, 1);
    BG_SYS_PushTile(base);
    id1 = base + 1;
    t1 = d_021D6344;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    BG_SYS_SetPlaneVisible(id1, 1);
    BG_SYS_Init(id1, 0, 1, 0);
    BG_SYS_SetTileEntry(id1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id1);
    id2 = base + 2;
    t2 = d_021D64E4;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    BG_SYS_SetPlaneVisible(id2, 1);
    BG_SYS_PushTile(id2);
    id3 = base + 3;
    t3 = d_021D6504;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    BG_SYS_SetPlaneVisible(id3, 1);
    BG_SYS_PushTile(id3);
}

/*
 * note 2026-10-05 (wD9r lane S5): twin of ov123 PDWACC_DISP_LoadResources (same callees, same loop); offsets differ only.
 */
void WIFILOGIN_DISP_LoadPalette(char *p)
{
    NNSG2dPaletteData *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = ARC_TOOL_CreateHandle(0x91, ((struct WifiloginDisp *)p)->heapId);
    j = 0;
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 4, 0, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(h, 4, 4, 0, j, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 6, 4, 0, j, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 0, 0, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(h, 4, 0, 0, j, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 5, 0, 0, j, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(h, 4, 3, 0, j, j, ((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 7, 3, 0, j, j, ((struct WifiloginDisp *)p)->heapId);
    heap = ((struct WifiloginDisp *)p)->heapId;
    MI_CpuFill8(&((struct WifiloginDisp *)p)->pal, 0, sizeof(((struct WifiloginDisp *)p)->pal));
    allocated = ARC_UTIL_LoadPaletteBlockFromHandle((void *)h, 2, &record, heap);
    MI_CpuCopy8(record->pRawData, ((struct WifiloginDisp *)p)->pal.table, 0x1e0);
    MI_CpuCopy8(record->pRawData, ((struct WifiloginDisp *)p)->pal.frames, 0x1e0);
    GFL_HEAP_Free(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)((struct WifiloginDisp *)p)->pal.frames;
        base0 = (u16 *)((struct WifiloginDisp *)p)->pal.table;
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = ((struct WifiloginDisp *)p)->pal.table[t] - 12;
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 12]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    DC_FlushRange(((struct WifiloginDisp *)p)->pal.frames, sizeof(((struct WifiloginDisp *)p)->pal.frames));
    ((struct WifiloginDisp *)p)->pal.ready = 1;
    ((struct WifiloginDisp *)p)->pal.frameTask = GFL_USE_AddMainTask((void *)WIFILOGIN_DISP_UpdatePalette, &((struct WifiloginDisp *)p)->pal, 0x14);
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 1, 8, 8, 0x10);
    ((struct WifiloginDisp *)p)->pal.layer = 0;
    ARC_TOOL_DeleteHandle(h);
}

void WIFILOGIN_DISP_UpdatePalette(void *unused, struct WifiloginPalTask *p) {
    if (p->ready == 0) return;
    p->toggle ^= 1;
    if (p->toggle & 1) return;
    GX_LoadBGPltt(&p->frames[p->index][4], 40, 14);
    GXS_LoadBGPltt(&p->frames[p->index][4], 40, 14);
    ++p->index;
    if (p->index >= 60) p->index = 0;
    BG_SYS_ChangeScrollImmediate(p->layer, 2, 7);
}

/*
 * lever: an enum zero assigned after archive allocation and passed only in full-width outgoing zero slots preserves the independent literal register zeros.
 * checks: fixed one EXACT with all 26 relocations resolved; earlier typed permuter consumed and not repeated.
 * ABI: 49990 fifth argument is explicitly truncated16; B294 result
 *   is consumed by stores and setters despite its legacy void spelling.
 */
void WIFILOGIN_DISP_CreateActors(u8 *p)
{
    enum { Zero=0 } zero;
    void *res;
    struct WifiloginDispRect a,b;
    res = ARC_TOOL_CreateHandle((uptr)((void *)143), ((struct WifiloginDisp *)p)->heapId);
    zero=Zero;
    ARC_UTIL_UploadPaletteFromHandleWhole(res,0,4,zero,0,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->charBank0 = ARC_UTIL_RegisterObjCharFromHandle(res,7,4,zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(res,18,4,0,(u16)(((struct WifiloginDisp *)p)->charBank0),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(res,19,6,0,(u16)(((struct WifiloginDisp *)p)->charBank0),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(res,20,7,0,(u16)(((struct WifiloginDisp *)p)->charBank0),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(res,0,0,zero,0,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->charBank1 = ARC_UTIL_RegisterObjCharFromHandle(res,6,0,zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(res,15,0,0,(u16)(((struct WifiloginDisp *)p)->charBank1),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(res,16,1,0,(u16)(((struct WifiloginDisp *)p)->charBank1),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(res,17,2,0,(u16)(((struct WifiloginDisp *)p)->charBank1),zero,0,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->charHandle = CLACT_RegisterCharacter(res,9,0,1,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->paletteHandle = CLACT_RegisterPaletteEx(res,3,1,0,0,3,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->cellAnimHandle = CLACT_RegisterCellAnim(res,12,25,((struct WifiloginDisp *)p)->heapId);
    ARC_TOOL_DeleteHandle((void *)res);
    a.x=128; a.y=96; a.z=10; a.kind=0; a.mode=2;
    *(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[0] = CLACT_CreateActor((void *)((struct WifiloginDisp *)p)->unit,((struct WifiloginDisp *)p)->charHandle,((struct WifiloginDisp *)p)->paletteHandle,((struct WifiloginDisp *)p)->cellAnimHandle,(const struct ActorInitParam *)&a,1,((struct WifiloginDisp *)p)->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[0])),1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[0])),1);
    b.x=128; b.y=96; b.z=11; b.kind=1; b.mode=2;
    *(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[1] = CLACT_CreateActor((void *)((struct WifiloginDisp *)p)->unit,((struct WifiloginDisp *)p)->charHandle,((struct WifiloginDisp *)p)->paletteHandle,((struct WifiloginDisp *)p)->cellAnimHandle,(const struct ActorInitParam *)&b,1,((struct WifiloginDisp *)p)->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[1])),1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[1])),1);
    G2x_SetBlendAlpha_((unsigned int *)((void *)REG_BLDCNT_ADDR),4,3,6,16);
    G2x_SetBlendAlpha_((unsigned int *)((void *)REG_DB_BLDCNT_ADDR),8,21,6,16);
    ((struct WifiloginDisp *)p)->hblankTask = GFL_USE_AddHBlankTask(WIFILOGIN_DISP_ScanlineEffect,(void *)p,0);
    FX_MakeSineTable(((struct WifiloginDisp *)p)->sineTable,192,1456,6144);
    ((struct WifiloginDisp *)p)->frameTimer = 10;
}

void WIFILOGIN_DISP_CreateUnit(u8 *p) { CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam,(const struct DispVramCfg *)d_021D65E4,((struct WifiloginDisp *)p)->heapId); ((struct WifiloginDisp *)p)->unit=CLACT_CreateUnit(40,0,((struct WifiloginDisp *)p)->heapId); ((struct WifiloginDisp *)p)->vblankTask=GFL_USE_AddMainTask(WIFILOGIN_DISP_VBlank,(void *)p,0); }

void WIFILOGIN_DISP_DrawActors(u8 *p) {
    ++((struct WifiloginDisp *)p)->scanline;
    if (((struct WifiloginDisp *)p)->scanline >= 192) ((struct WifiloginDisp *)p)->scanline = 0;
    if (((struct WifiloginDisp *)p)->frameTimer) {
        ++((struct WifiloginDisp *)p)->frameTimer;
        if (((struct WifiloginDisp *)p)->frameTimer >= 257) ((struct WifiloginDisp *)p)->frameTimer = 1;
    }
    CLACT_DrawSystem();
}

void WIFILOGIN_DISP_DeleteActors(u8 *p) {
    int i;
    for (i = 0; i < 5; ++i) {
        if (((struct WifiloginDisp *)p)->actors[i]) {
            CLACT_DeleteActor((struct ClactActor *)((struct ClactActor *)(((struct WifiloginDisp *)p)->actors[i])));
            ((struct WifiloginDisp *)p)->actors[i] = 0;
        }
    }
    CLACT_ReleasePalette(((struct WifiloginDisp *)p)->paletteHandle);
    CLACT_ReleaseCharacter(((struct WifiloginDisp *)p)->charHandle);
    CLACT_ReleaseCellAnim(((struct WifiloginDisp *)p)->cellAnimHandle);
    if (((struct WifiloginDisp *)p)->hblankTask) TCB_DeleteTask((struct TcbTask *)(((struct WifiloginDisp *)p)->hblankTask));
    TCB_DeleteTask((struct TcbTask *)(((struct WifiloginDisp *)p)->vblankTask));
    CLACT_DeleteUnit((struct Unit *)((struct Bank *)(((struct WifiloginDisp *)p)->unit)));
    CLACT_ExitSystem();
}

/*
 * lever: bind the hardware scanline before adding the signed counter;
 *        the nested expression moves the first four loads/adds.
 * volatile: hardware reads at 021D58BE, 021D58CC and writes 021D58E2, 021D58EA.
 */
void WIFILOGIN_DISP_ScanlineEffect(struct TcbTask *unused, void *p) {
    int i;
    i = *(volatile u16 *)REG_VCOUNT_ADDR;
    i = (i + (((struct WifiloginDisp *)p)->scanline + 1)) % 192;
    if (*(volatile u16 *)REG_DISPSTAT_ADDR & 2) {
        *(volatile u32 *)REG_BG1OFS_ADDR = *(s16 *)((u8 *)p + 0x9ca + i * 2) & 511;
        *(volatile u32 *)REG_DB_BG2OFS_ADDR = *(s16 *)((u8 *)p + 0x9ca + i * 2) & 511;
    }
}

void WIFILOGIN_DISP_VBlank(struct TcbTask *task, void *arg) { u8 *p = arg; if(((struct WifiloginDisp *)p)->frameTimer>0) { BG_SYS_ChangeScrollImmediate(7,0,((struct WifiloginDisp *)p)->frameTimer-1); BG_SYS_ChangeScrollImmediate(2,0,((struct WifiloginDisp *)p)->frameTimer-1); } CLACT_VBlankSystem(); }

void WIFILOGIN_DISP_SetPaletteFlag(u8 *p) { ((struct WifiloginDisp *)p)->palFlag = 1; }

void WIFILOGIN_DISP_SetupScreen(u8 *p) {
    switch (((struct WifiloginDisp *)p)->mode) {
    case 1:
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 4, 3, 6, 16);
        G2x_SetBlendAlpha_((void *)REG_DB_BLDCNT_ADDR, 8, 21, 6, 16);
        break;
    case 0:
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 1, 8, 8, 16);
        break;
    }
}
