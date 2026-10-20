/*
 * file:     wifilogin_disp.c
 * unit:     yes
 * function: WIFILOGIN_DISP_OpenProfileCard, WIFILOGIN_DISP_GetProfileSlot0, WIFILOGIN_DISP_CopyProfileSlot, WIFILOGIN_DISP_StepCancelOnReady, WIFILOGIN_DISP_StepCancel, WIFILOGIN_DISP_StepWaitLogin, WIFILOGIN_DISP_StepSaveResult, WIFILOGIN_DISP_StepStartSave, WIFILOGIN_DISP_StepCheckSave, WIFILOGIN_DISP_StartSession, WIFILOGIN_DISP_StepConfirmProfileResult, WIFILOGIN_DISP_StepConfirmConsoleResult, WIFILOGIN_DISP_StepConfirmProfile, WIFILOGIN_DISP_StepConfirmConsole, WIFILOGIN_DISP_HandleNetError, WIFILOGIN_DISP_StepMenuAfterProfileError, WIFILOGIN_DISP_StepCardMenu, WIFILOGIN_DISP_StepOpenCardMenu, WIFILOGIN_DISP_StepCardSelect, WIFILOGIN_DISP_StepOpenCardMenu2, WIFILOGIN_DISP_StepCardMenu2, WIFILOGIN_DISP_StepOpenCardMenu3, WIFILOGIN_DISP_StepCancelWait, WIFILOGIN_DISP_StepCheckAccount, WIFILOGIN_DISP_StepFinish, WIFILOGIN_DISP_StepCallSync, WIFILOGIN_DISP_StepStartWipe, WIFILOGIN_DISP_StepGetToken, WIFILOGIN_DISP_StepBeginToken, WIFILOGIN_DISP_StepPollToken, WIFILOGIN_DISP_Create, WIFILOGIN_DISP_Update, WIFILOGIN_DISP_Delete, WIFILOGIN_DISP_CreateDisplay, WIFILOGIN_DISP_Draw, WIFILOGIN_DISP_DeleteDisplay, WIFILOGIN_DISP_InitBgLayersA, WIFILOGIN_DISP_InitBgLayersB, WIFILOGIN_DISP_InitBgLayersC, WIFILOGIN_DISP_InitBgLayersD, WIFILOGIN_DISP_LoadPalette, WIFILOGIN_DISP_UpdatePalette, WIFILOGIN_DISP_CreateActors, WIFILOGIN_DISP_CreateUnit, WIFILOGIN_DISP_DrawActors, WIFILOGIN_DISP_DeleteActors, WIFILOGIN_DISP_ScanlineEffect, WIFILOGIN_DISP_VBlank, WIFILOGIN_DISP_SetPaletteFlag, WIFILOGIN_DISP_SetupScreen
 * address:  0x021D42A8
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
#include "ov115_types.h"

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


#ifdef __MWERKS__
#define ARC_UTIL_UploadPaletteFromHandleWhole ARC_UTIL_UploadPaletteFromHandleWhole_hdr
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_UploadPaletteFromHandleWhole
void ARC_UTIL_UploadPaletteFromHandleWhole(void *, u32, u32, u32, u32, u16);
#endif




#ifdef __MWERKS__
#define PALANM_BlendColors PALANM_BlendColors_hdr
#endif
#include "../arm9/palanm.h"
#ifdef __MWERKS__
#undef PALANM_BlendColors
void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
#endif

#include "../arm9/os_cache.h"


#include "../arm9/g2.h"


#include "../arm9/gx_load2d.h"







#include "../arm9/clact.h"




struct ClactActor;




#include "../arm9/pmsi_param.h"
struct DispVramCfg;
struct SysInit;











void WIFILOGIN_DISP_OpenProfileCard(u8 *p);

void WIFILOGIN_DISP_GetProfileSlot0(u8 *p);

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

int WIFILOGIN_DISP_Delete(u32 a,int b,int c,u8 *p);

u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int reconnect);

void WIFILOGIN_DISP_Draw(u8 *p);

void WIFILOGIN_DISP_DeleteDisplay(u8 *p);

void WIFILOGIN_DISP_InitBgLayersA(u32 unused,unsigned long base);

void WIFILOGIN_DISP_InitBgLayersB(void *unused, unsigned long base);

void WIFILOGIN_DISP_InitBgLayersC(void *unused, unsigned long base);

void WIFILOGIN_DISP_InitBgLayersD(void *unused, unsigned long base);

void WIFILOGIN_DISP_LoadPalette(char *p);

void WIFILOGIN_DISP_UpdatePalette(void *unused, u8 *p);

void WIFILOGIN_DISP_CreateActors(u8 *p);

void WIFILOGIN_DISP_CreateUnit(u8 *p);

void WIFILOGIN_DISP_DrawActors(u8 *p);

void WIFILOGIN_DISP_DeleteActors(u8 *p);

void WIFILOGIN_DISP_ScanlineEffect(void *unused, u8 *p);

void WIFILOGIN_DISP_VBlank(void *task,u8 *p);

void WIFILOGIN_DISP_SetPaletteFlag(u8 *p);

void WIFILOGIN_DISP_SetupScreen(u8 *p);

#include "wifilogin_message.h"
















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

void WIFILOGIN_DISP_OpenProfileCard(u8 *p) { WIFILIST_GetWork((struct WifiList *)GAME_DATA_GetWifiList(((struct WifiloginWork *)p)->userdata)); }

void WIFILOGIN_DISP_GetProfileSlot0(u8 *p) { WIFILIST_GetDwcFriendData((void *)GAME_DATA_GetWifiList(((struct WifiloginWork *)p)->userdata),0); }

/*
 * extent: Two zero bytes of alignment padding follow the return.
 */
void WIFILOGIN_DISP_CopyProfileSlot(int a,int b,u8 *p) { WIFILIST_MergeFriendRecord((void *)GAME_DATA_GetWifiList(((struct WifiloginWork *)p)->userdata),a,b); }

void WIFILOGIN_DISP_StepCancelOnReady(u8 *p) { if(WIPE_SYS_EndCheck() && WIFILOGIN_MSG_IsPrintDone((u8 *)(((struct WifiloginWork *)p)->message)) && WIFILOGIN_COMMON_IsCancelInput(p)) WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); }

void WIFILOGIN_DISP_StepCancel(u8 *p)
{
    if (WIFILOGIN_COMMON_IsCancelInput(p)) {
        WIFILOGIN_MSG_RedrawBorder((u8 *)(((struct WifiloginWork *)p)->message));
        if (((struct WifiloginWork *)p)->state->mode == 0)
            WIFILOGIN_MSG_ShowMessage((u8 *)(((struct WifiloginWork *)p)->message), 0x23);
        if (((struct WifiloginWork *)p)->state->waiting != 0)
            WIFILOGIN_COMMON_SetStateHandler(p, (u32)WIFILOGIN_DISP_StepBeginToken);
        else
            WIFILOGIN_COMMON_SetStateHandler(p, (u32)WIFILOGIN_DISP_StepCallSync);
    } else {
        WIFILOGIN_DISP_HandleNetError(p);
    }
}

void WIFILOGIN_DISP_StepWaitLogin(u8 *p) {
 if(GFL_NET_STATE_IsWifiLoginState()) { if(((struct WifiloginWork *)p)->accountError) { WIFILOGIN_MSG_CloseMessage((u8 *)((struct WifiloginWork *)p)->message); WIFILOGIN_MSG_RedrawWindow((u8 *)((struct WifiloginWork *)p)->message); if(APP_ENV_IsRunOnTwl()) WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message,44); else WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message,19); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancel); } else if(((struct WifiloginWork *)p)->state->waiting) { WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepBeginToken); } else { WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); } } else WIFILOGIN_DISP_HandleNetError(p);
}

void WIFILOGIN_DISP_StepSaveResult(u8 *p) { int r; if(DWC_RAP_IsUserDataChanged()) { r=GAME_DATA_SaveMain((struct GameData *)(*(u8 * *)&((struct WifiloginWork *)p)->userdata)); switch(r) { case 0: case 1: return; default: DWC_RAP_ClearUserDataChanged(r); break; } } WIFILOGIN_DISP_StepWaitLogin(p); }

void WIFILOGIN_DISP_StepStartSave(u8 *p) { void *a; if(WIFILOGIN_MSG_IsPrintDone((u8 *)(((struct WifiloginWork *)p)->message))) { a=GAME_DATA_GetMyStatus((struct GameData *)(((struct WifiloginWork *)p)->userdata)); MYSTATUS_SetProfileIdOnce(a,WIFILIST_GetGsProfileId(((struct WifiloginWork *)p)->profile)); GAME_DATA_SaveStart((struct GameData *)(*(u8 * *)&((struct WifiloginWork *)p)->userdata)); ((struct WifiloginWork *)p)->saveStarted=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepSaveResult); } }

void WIFILOGIN_DISP_StepCheckSave(u8 *p) {
 if(WIFILOGIN_MSG_IsPrintDone((u8 *)((int)((u8 *)((struct WifiloginWork *)p)->message)))) { if(DWC_RAP_IsUserDataChanged() && !((struct WifiloginWork *)p)->saveStarted && ((struct WifiloginWork *)p)->state->netMode!=2) { WIFILOGIN_MSG_SetMessage((void *)((struct WifiloginWork *)p)->message,30); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepStartSave); } else { WIFILOGIN_DISP_StepWaitLogin(p); } }
}

void WIFILOGIN_DISP_StartSession(u8 *p) {
 int z; if(OS_IsRunOnTwl()) *(u32 *)(d_021D6560+0x48)=0x79000; else *(u32 *)(d_021D6560+0x48)=0x5e400; if(((struct WifiloginWork *)p)->state->dialogId==44) *(u32 *)(d_021D6560+0x48)=0x50000; else if(((struct WifiloginWork *)p)->state->dialogId==36) *(u32 *)(d_021D6560+0x48)=0x6e000; if(((struct WifiloginWork *)p)->state->dialogId!=10) *(u32 *)(d_021D6560+0x40)=0; z=0; d_021D65C0[7]=((struct WifiloginWork *)p)->state->dialogId; *(u32 *)gWifiloginDialogId=((struct WifiloginWork *)p)->state->dialogId; GFL_NET_StartSession((GFLNetInitializeStruct *)d_021D6560,z,(u32)p); GFL_NET_STATE_WifiStartMatch(); if(!((struct WifiloginWork *)p)->state->reconnect) GFL_NET_RefreshWmIconAtTopRight(z,((struct WifiloginWork *)p)->heapId); else GFL_NET_RefreshWmIconAtTopRight(1,((struct WifiloginWork *)p)->heapId); WIFILOGIN_MSG_SetMessage((void *)((struct WifiloginWork *)p)->message,23); WIFILOGIN_DISP_SetPaletteFlag(((struct WifiloginWork *)p)->disp); WIFILOGIN_COMMON_SetStateHandler((u8 *)p,(u32)WIFILOGIN_DISP_StepCheckSave);
}

void WIFILOGIN_DISP_StepConfirmProfileResult(u8 *p) {
 if(WIFILOGIN_MSG_IsTaskFinish((u8 *)((struct WifiloginWork *)p)->task)) { if(!WIFILOGIN_MSG_GetTaskCursor((u8 *)((struct WifiloginWork *)p)->task)) { ((struct WifiloginWork *)p)->state->aidMismatch=0; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StartSession); } else { ((struct WifiloginWork *)p)->state->aidMismatch=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); } WIFILOGIN_MSG_RedrawBorder((u8 *)((struct WifiloginWork *)p)->message); if(!((struct WifiloginWork *)p)->state->mode) WIFILOGIN_MSG_ShowMessage((u8 *)((struct WifiloginWork *)p)->message,35); WIFILOGIN_MSG_CloseTask((u8 *)((struct WifiloginWork *)p)->task); ((struct WifiloginWork *)p)->task=0; }
}

void WIFILOGIN_DISP_StepConfirmConsoleResult(u8 *p) {
 if(WIFILOGIN_MSG_IsTaskFinish((u8 *)((struct WifiloginWork *)p)->task)) { if(!WIFILOGIN_MSG_GetTaskCursor((u8 *)((struct WifiloginWork *)p)->task)) { ((struct WifiloginWork *)p)->state->aidMismatch=0; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StartSession); } else { ((struct WifiloginWork *)p)->state->aidMismatch=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); } WIFILOGIN_MSG_RedrawBorder((u8 *)((struct WifiloginWork *)p)->message); WIFILOGIN_MSG_RedrawWindow((u8 *)((struct WifiloginWork *)p)->message); WIFILOGIN_MSG_CloseTask((u8 *)((struct WifiloginWork *)p)->task); ((struct WifiloginWork *)p)->task=0; if(!((struct WifiloginWork *)p)->state->mode) WIFILOGIN_MSG_ShowMessage((u8 *)((struct WifiloginWork *)p)->message,35); }
}

void WIFILOGIN_DISP_StepConfirmProfile(u8 *p) { if(WIPE_SYS_EndCheck() && WIFILOGIN_MSG_IsPrintDone((u8 *)(*(int *)&((struct WifiloginWork *)p)->message))) { ((struct WifiloginWork *)p)->task=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct WifiloginWork *)p)->message,1,!((struct WifiloginWork *)p)->state->mode,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmProfileResult); } }

void WIFILOGIN_DISP_StepConfirmConsole(u8 *p) { if(WIPE_SYS_EndCheck()) { WIFILOGIN_MSG_CloseMessage((u8 *)(*(int *)&((struct WifiloginWork *)p)->message)); ((struct WifiloginWork *)p)->task=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct WifiloginWork *)p)->message,1,!((struct WifiloginWork *)p)->state->mode,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmConsoleResult); } }

int WIFILOGIN_DISP_HandleNetError(u8 *p) {
 if(GFL_NET_ERR_GetErrorLevel()) { switch(*(u32 *)(GFL_NET_STATE_GetError()+4)) { case 1: case 2: case 3: case 4: case 5: case 6: WIFILOGIN_MSG_RedrawBorder((u8 *)((struct WifiloginWork *)p)->message); WIFILOGIN_MSG_CloseMessage((u8 *)((int)((u8 *)((struct WifiloginWork *)p)->message))); WIFILOGIN_MSG_RedrawWindow((u8 *)((struct WifiloginWork *)p)->message); GFL_NET_ERR_ShowSimpleScreen(); WIFILOGIN_DISP_SetupScreen((u8 *)((struct WifiloginWork *)p)->disp); if(GFL_NET_GetRunState()) GFL_NET_ERR_WaitLinkClosed(); GFL_NET_STATE_SetWifiError(); GFL_NET_ERR_ResetState(); GFL_NET_STATE_ClearErrorMode(); WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message,37); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmConsole); return 1; case 7: GFL_NET_ERR_HaltIfActive(); break; case 0: default: break; } } return 0;
}

void WIFILOGIN_DISP_StepMenuAfterProfileError(u8 *p) { if(WIPE_SYS_EndCheck() && WIFILOGIN_MSG_IsPrintDone((u8 *)(*(int *)&((struct WifiloginWork *)p)->message))) { ((struct WifiloginWork *)p)->task=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct WifiloginWork *)p)->message,0,!((struct WifiloginWork *)p)->state->mode,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmConsoleResult); } }

void WIFILOGIN_DISP_StepCardMenu(u8 *p) {
 void *v; if(WIFILOGIN_MSG_IsTaskFinish((u8 *)((struct WifiloginWork *)p)->task)) { if(!WIFILOGIN_MSG_GetTaskCursor((u8 *)((struct WifiloginWork *)p)->task)) { v=REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((void *)((struct WifiloginWork *)p)->userdata))),0); BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((void *)((struct WifiloginWork *)p)->userdata)),1); REGULATION_Card_SetValue(v,10,5); ((struct WifiloginWork *)p)->state->aidMismatch=0; WIFILIST_Init((void *)((struct WifiloginWork *)p)->profile); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StartSession); } else { ((struct WifiloginWork *)p)->state->aidMismatch=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCheckAccount); } WIFILOGIN_MSG_RedrawBorder((u8 *)((struct WifiloginWork *)p)->message); if(!((struct WifiloginWork *)p)->state->mode) WIFILOGIN_MSG_ShowMessage((u8 *)((struct WifiloginWork *)p)->message,35); WIFILOGIN_MSG_CloseTask((u8 *)((struct WifiloginWork *)p)->task); ((struct WifiloginWork *)p)->task=0; }
}

void WIFILOGIN_DISP_StepOpenCardMenu(u8 *p) { ((struct WifiloginWork *)p)->task=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct WifiloginWork *)p)->message,1,!((struct WifiloginWork *)p)->state->mode,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCardMenu);  }

void WIFILOGIN_DISP_StepCardSelect(u8 *p) {
 int x; void *v; u32 y; if(WIFILOGIN_MSG_IsTaskFinish((u8 *)((struct WifiloginWork *)p)->task)) { x=WIFILOGIN_MSG_GetTaskCursor((u8 *)((struct WifiloginWork *)p)->task); WIFILOGIN_MSG_RedrawBorder((u8 *)((struct WifiloginWork *)p)->message); if(!((struct WifiloginWork *)p)->state->mode) WIFILOGIN_MSG_ShowMessage((u8 *)((struct WifiloginWork *)p)->message,35); WIFILOGIN_MSG_CloseTask((u8 *)((struct WifiloginWork *)p)->task); ((struct WifiloginWork *)p)->task=0; if(!x) { v=REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((void *)((struct WifiloginWork *)p)->userdata))),0); x=REGULATION_Card_GetValue(v,2); y=REGULATION_Card_GetValue(v,10); if(x && y>=1 && y<=4) { WIFILOGIN_MSG_CloseMessage((u8 *)((int)((u8 *)((struct WifiloginWork *)p)->message))); WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message,38); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepOpenCardMenu); } else { ((struct WifiloginWork *)p)->state->aidMismatch=0; WIFILIST_Init((void *)((struct WifiloginWork *)p)->profile); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StartSession); } } else { ((struct WifiloginWork *)p)->state->aidMismatch=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCheckAccount); } }
}

void WIFILOGIN_DISP_StepOpenCardMenu2(u8 *p) { ((struct WifiloginWork *)p)->task=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct WifiloginWork *)p)->message,1,!((struct WifiloginWork *)p)->state->mode,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCardSelect);  }

void WIFILOGIN_DISP_StepCardMenu2(u8 *p) {
 if(WIFILOGIN_MSG_IsTaskFinish((u8 *)((struct WifiloginWork *)p)->task)) { if(!WIFILOGIN_MSG_GetTaskCursor((u8 *)((struct WifiloginWork *)p)->task)) { ((struct WifiloginWork *)p)->state->aidMismatch=0; WIFILOGIN_MSG_CloseMessage((u8 *)((int)((u8 *)((struct WifiloginWork *)p)->message))); WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message,22); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepOpenCardMenu2); } else { ((struct WifiloginWork *)p)->state->aidMismatch=1; WIFILOGIN_MSG_RedrawBorder((u8 *)((struct WifiloginWork *)p)->message); if(!((struct WifiloginWork *)p)->state->mode) WIFILOGIN_MSG_ShowMessage((u8 *)((struct WifiloginWork *)p)->message,35); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); } WIFILOGIN_MSG_CloseTask((u8 *)((struct WifiloginWork *)p)->task); ((struct WifiloginWork *)p)->task=0; }
}

void WIFILOGIN_DISP_StepOpenCardMenu3(u8 *p) { ((struct WifiloginWork *)p)->task=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct WifiloginWork *)p)->message,1,!((struct WifiloginWork *)p)->state->mode,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCardMenu2);  }

void WIFILOGIN_DISP_StepCancelWait(u8 *p) {
 if (WIPE_SYS_EndCheck() && WIFILOGIN_COMMON_IsCancelInput(p)) { WIFILOGIN_MSG_CloseMessage((u8 *)((int)((u8 *)((struct WifiloginWork *)p)->message))); if (APP_ENV_IsRunOnTwl()) WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message, 0x2e); else WIFILOGIN_MSG_PrintMessage((u8 *)((struct WifiloginWork *)p)->message, 0x15); WIFILOGIN_COMMON_SetStateHandler(p, (u32)WIFILOGIN_DISP_StepOpenCardMenu3); }
}

/*
 * evidence: 0202EB44 leaves r0 live for this caller; entry p is forwarded.
 * 02009860 is bx lr; its unchanged entry pointer feeds both SDK readers.
 * callbacks: both zero-status arms use 42E0; mode2 and final else use 46CC;
 * missing profile uses 45D0, missing console uses 493C, mode1 uses 460C.
 */
void WIFILOGIN_DISP_StepCheckAccount(u8 *p)
{
#ifdef __MWERKS__
    if(APP_ENV_IsWirelessAvailable(p)==0) {
#else
    if(APP_ENV_IsWirelessAvailable()==0) {
#endif
        WIFILOGIN_MSG_CloseMessage((u8 *)((int)(((struct WifiloginWork *)p)->message)));
        WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,39);
        ((struct WifiloginWork *)p)->state->aidMismatch=1;
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancelOnReady);
        return;
    }
    if(APP_ENV_IsEulaAgreed()==0) {
        WIFILOGIN_MSG_CloseMessage((u8 *)((int)(((struct WifiloginWork *)p)->message)));
        WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,34);
        ((struct WifiloginWork *)p)->state->aidMismatch=1;
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancelOnReady);
        return;
    }
    if(((struct WifiloginWork *)p)->state->netMode==2) {
        WIFILOGIN_MSG_Draw(((struct WifiloginWork *)p)->message,17);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepMenuAfterProfileError);
        return;
    }
    if(DWC_CheckHasProfile((struct DWCstAccUserData *)WIFILIST_GetWork((struct WifiList *)((struct WifiloginWork *)p)->profile))==0) {
        ((struct WifiloginWork *)p)->accountError=1;
        WIFILOGIN_MSG_CloseMessage((u8 *)((int)(((struct WifiloginWork *)p)->message)));
        if(APP_ENV_IsRunOnTwl()==0) WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,18);
        else WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,43);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmProfile);
        return;
    }
    if(DWC_CheckValidConsole((struct DWCstAccUserData *)WIFILIST_GetWork((struct WifiList *)((struct WifiloginWork *)p)->profile))==0) {
        ((struct WifiloginWork *)p)->accountError=1;
        WIFILOGIN_MSG_CloseMessage((u8 *)((int)(((struct WifiloginWork *)p)->message)));
        if(APP_ENV_IsRunOnTwl()==0) WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,20);
        else WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,45);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancelWait);
        return;
    }
    if(((struct WifiloginWork *)p)->state->netMode==1) {
        WIFILOGIN_MSG_CloseMessage((u8 *)((int)(((struct WifiloginWork *)p)->message)));
        WIFILOGIN_MSG_PrintMessage(((struct WifiloginWork *)p)->message,37);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmConsole);
    } else {
        WIFILOGIN_MSG_Draw(((struct WifiloginWork *)p)->message,17);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepMenuAfterProfileError);
    }
}

void WIFILOGIN_DISP_StepFinish(u8 *p) { if(WIPE_SYS_EndCheck()) WIFILOGIN_COMMON_SetStateHandler(p,0); }

void WIFILOGIN_DISP_StepCallSync(unsigned char *a)
{
    int r;

    if (((struct WifiloginWork *)a)->state->stepCallback != 0 &&
        ((struct WifiloginWork *)a)->state->aidMismatch == 0) {
        r = ((int (*)(int, int)) ((struct WifiloginWork *)a)->state->stepCallback)(
            (int)((struct WifiloginWork *)a)->message, (int)((struct WifiloginWork *)a)->state->stepArg);
        if (r == 2)
            return;
        switch (r) {
        case 0:
            ((struct WifiloginWork *)a)->state->aidMismatch = 0;
            WIFILOGIN_COMMON_SetStateHandler(a, (int)WIFILOGIN_DISP_StepStartWipe);
            break;
        case 1:
            ((struct WifiloginWork *)a)->state->aidMismatch = 1;
            WIFILOGIN_MSG_RedrawBorder((unsigned char *)(((struct WifiloginWork *)a)->message));
            WIFILOGIN_MSG_CloseMessage((u8 *)((int)((unsigned char *)(((struct WifiloginWork *)a)->message))));
            WIFILOGIN_MSG_RedrawWindow((unsigned char *)(((struct WifiloginWork *)a)->message));
            if (GFL_NET_GetRunState() != 0)
                GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            WIFILOGIN_MSG_PrintMessage((unsigned char *)(((struct WifiloginWork *)a)->message), 0x25);
            WIFILOGIN_COMMON_SetStateHandler(a, (int)WIFILOGIN_DISP_StepConfirmConsole);
            break;
        }
    } else {
        WIFILOGIN_COMMON_SetStateHandler(a, (int)WIFILOGIN_DISP_StepStartWipe);
    }
}

void WIFILOGIN_DISP_StepStartWipe(u8 *p) {
 WIPE_SYS_Start(0,0,0,0,6,1,((struct WifiloginWork *)p)->heapId); if(!((struct WifiloginWork *)p)->state->mode && !((struct WifiloginWork *)p)->state->cancelBgm) GFL_USE_FadeOutBgm(8); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepFinish);
}

void WIFILOGIN_DISP_StepGetToken(u8 *p) {
 if(!WIFILOGIN_DISP_HandleNetError(p)) { if(DWC_SVLGetTokenAsync(d_021D65D0,(void *)(((struct WifiloginWork *)p)->state->waiting))) WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepPollToken); else WIFILOGIN_DISP_HandleNetError(p); }
}

void WIFILOGIN_DISP_StepBeginToken(u8 *p) { WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepGetToken); }

void WIFILOGIN_DISP_StepPollToken(u8 *p) { int x; if(!WIFILOGIN_DISP_HandleNetError(p)) { x=DWC_SVLProcess(); if(x==3) WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); else if(x==4 || x==0 || x==5) WIFILOGIN_DISP_HandleNetError(p); } }

/*
 * evidence: 0203159C leaves its allocation in r0, read here despite legacy void.
 * 021D4D38 r2 is explicitly loaded here and retained in the extern.
 */
int WIFILOGIN_DISP_Create(void *ctx,int unused,u8 *q)
{
    u8 *p;
    if(((struct WifiloginState *)q)->dialogId==0) GF_PANIC_Fail(d_021D65D0,0,d_021D65D0);
    GFL_HEAP_CreateChildHeap(1,120,0x18000);
    p=PROCSYS_AllocProcWork(ctx,72,120);
    MI_CpuFill8(p,0,72);
    ((struct WifiloginWork *)p)->heapId=120;
    ((struct WifiloginWork *)p)->userdata=((struct WifiloginState *)q)->userdata;
    ((struct WifiloginWork *)p)->disp=WIFILOGIN_DISP_CreateDisplay(((struct WifiloginWork *)p)->heapId,((struct WifiloginState *)q)->mode,((struct WifiloginState *)q)->reconnect);
    ((struct WifiloginWork *)p)->message=WIFILOGIN_MSG_Create(((struct WifiloginWork *)p)->heapId,232,((struct WifiloginState *)q)->reconnect);
    ((struct WifiloginWork *)p)->saveControl=GAME_DATA_GetSaveControl(((struct WifiloginState *)q)->userdata);
    ((struct WifiloginWork *)p)->profile=(void *)GAME_DATA_GetWifiList(((struct WifiloginState *)q)->userdata);
    WIPE_SYS_Start(0,1,1,0,6,1,((struct WifiloginWork *)p)->heapId);
    *(u8 * *)&((struct WifiloginWork *)p)->state=q;
    if(GFL_NET_GetRunState()) {
        GFL_NET_STATE_SetWifiError();
        GFL_NET_STATE_ClearErrorMode();
        GFL_NET_ERR_WaitLinkClosed();
        GFL_NET_ERR_ResetState();
    }
    WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCheckAccount);
    if(((struct WifiloginWork *)p)->state->mode==0) {
        WIFILOGIN_MSG_ShowMessage(*(u8 * *)&((struct WifiloginWork *)p)->message,35);
        if(((struct WifiloginWork *)p)->state->cancelBgm==0) GFL_USE_CancelChangeAndPlayBgm(1153,65535);
    } else {
        if(((struct WifiloginWork *)p)->state->cancelBgm==0) GFL_USE_CancelChangeAndPlayBgm(1155,65535);
    }
    return 1;
}

int WIFILOGIN_DISP_Update(int a,int b,int c,u8 *p) { int r=1; void (*cb)(u8 *); WIFILOGIN_DISP_Draw(((struct WifiloginWork *)p)->disp); WIFILOGIN_MSG_Run((u8 *)(((struct WifiloginWork *)p)->message)); cb=*(void (**)(u8 *))p; if(cb) { cb(p); r=0; } if(((struct WifiloginWork *)p)->task) WIFILOGIN_MSG_UpdateTask((u8 *)(((struct WifiloginWork *)p)->task)); return r; }

int WIFILOGIN_DISP_Delete(u32 a,int b,int c,u8 *p) { BG_SYS_FreeLayerBuf(7); WIFILOGIN_MSG_Delete(*(u8 * *)&((struct WifiloginWork *)p)->message); WIFILOGIN_DISP_DeleteDisplay(*(u8 * *)&((struct WifiloginWork *)p)->disp); PROCSYS_FreeProcWork((struct Proc *)a); GFL_HEAP_DeleteChecked(120); return 1; }

/*
 * volatile: hardware reads/writes 021D4D66, 021D4D70, 021D4D74.
 */
u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int reconnect) {
    u8 *p;
    p=GFL_HEAP_Alloc(heap,0x14bc,1,(const char *)d_021D6614,146);
    ((struct WifiloginDisp *)p)->heapId=heap;
    ((struct WifiloginDisp *)p)->mode=mode;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0;
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
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
        WIFILOGIN_DISP_InitBgLayersA((u32)p,0);
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
    else if (((struct WifiloginDisp *)p)->frameTask) {
        TCB_DeleteTask(((struct WifiloginDisp *)p)->frameTask);
        ((struct WifiloginDisp *)p)->frameTask = 0;
        ((struct WifiloginDisp *)p)->paletteReady = 0;
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
    void *record;
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
    MI_CpuFill8(p + 0x10, 0, 0x970);
    allocated = ARC_UTIL_LoadPaletteBlockFromHandle((void *)h, 2, &record, heap);
    MI_CpuCopy8(*(void **)((u8 *)record + 0xc), p + 0x18, 0x1e0);
    MI_CpuCopy8(*(void **)((u8 *)record + 0xc), p + 0x1f8, 0x1e0);
    GFL_HEAP_Free(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)(p + 0x1f8);
        base0 = (u16 *)(p + 0x18);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
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
    DC_FlushRange(p + 0x1f8, 0x780);
    ((struct WifiloginDisp *)p)->paletteReady = 1;
    ((struct WifiloginDisp *)p)->frameTask = GFL_USE_AddMainTask((void *)WIFILOGIN_DISP_UpdatePalette, p + 0x10, 0x14);
    G2x_SetBlendAlpha_((void *)0x04000050, 1, 8, 8, 0x10);
    ((struct WifiloginDisp *)p)->palDone = 0;
    ARC_TOOL_DeleteHandle(h);
}

void WIFILOGIN_DISP_UpdatePalette(void *unused, u8 *p) {
    if (((struct WifiloginDisp *)p)->charBank1 == 0) return;
    ((struct WifiloginDisp *)p)->palToggle ^= 1;
    if (((struct WifiloginDisp *)p)->palToggle & 1) return;
    GX_LoadBGPltt(p + 0x1f0 + ((struct WifiloginDisp *)p)->palIndex * 32, 40, 14);
    GXS_LoadBGPltt(p + 0x1f0 + ((struct WifiloginDisp *)p)->palIndex * 32, 40, 14);
    ++((struct WifiloginDisp *)p)->palIndex;
    if (((struct WifiloginDisp *)p)->palIndex >= 60) ((struct WifiloginDisp *)p)->palIndex = 0;
    BG_SYS_ChangeScrollImmediate(((struct WifiloginDisp *)p)->palLayer, 2, 7);
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
    u32 res;
    struct WifiloginDispRect a,b;
    res = (u32)ARC_TOOL_CreateHandle((u32)((void *)143), ((struct WifiloginDisp *)p)->heapId);
    zero=Zero;
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)res),0,4,zero,0,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->charBank0 = ARC_UTIL_RegisterObjCharFromHandle((void *)((u32)res),7,4,zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),18,4,0,(u16)(((struct WifiloginDisp *)p)->charBank0),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),19,6,0,(u16)(((struct WifiloginDisp *)p)->charBank0),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),20,7,0,(u16)(((struct WifiloginDisp *)p)->charBank0),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)res),0,0,zero,0,((struct WifiloginDisp *)p)->heapId);
    ((struct WifiloginDisp *)p)->charBank1 = ARC_UTIL_RegisterObjCharFromHandle((void *)((u32)res),6,0,zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),15,0,0,(u16)(((struct WifiloginDisp *)p)->charBank1),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),16,1,0,(u16)(((struct WifiloginDisp *)p)->charBank1),zero,0,((struct WifiloginDisp *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)res),17,2,0,(u16)(((struct WifiloginDisp *)p)->charBank1),zero,0,((struct WifiloginDisp *)p)->heapId);
    *(int *)&((struct WifiloginDisp *)p)->charHandle = CLACT_RegisterCharacter((void *)((u32)res),9,0,1,((struct WifiloginDisp *)p)->heapId);
    *(int *)&((struct WifiloginDisp *)p)->paletteHandle = CLACT_RegisterPaletteEx((void *)((u32)res),3,1,0,0,3,((struct WifiloginDisp *)p)->heapId);
    *(int *)&((struct WifiloginDisp *)p)->cellAnimHandle = CLACT_RegisterCellAnim((void *)((u32)res),12,25,((struct WifiloginDisp *)p)->heapId);
    ARC_TOOL_DeleteHandle((void *)res);
    a.x=128; a.y=96; a.z=10; a.kind=0; a.mode=2;
    *(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[0] = CLACT_CreateActor((void *)((struct WifiloginDisp *)p)->unit,((struct WifiloginDisp *)p)->charHandle,((struct WifiloginDisp *)p)->paletteHandle,((struct WifiloginDisp *)p)->cellAnimHandle,(const struct ActorInitParam *)&a,1,((struct WifiloginDisp *)p)->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[0])),1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[0])),1);
    b.x=128; b.y=96; b.z=11; b.kind=1; b.mode=2;
    *(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[1] = CLACT_CreateActor((void *)((struct WifiloginDisp *)p)->unit,((struct WifiloginDisp *)p)->charHandle,((struct WifiloginDisp *)p)->paletteHandle,((struct WifiloginDisp *)p)->cellAnimHandle,(const struct ActorInitParam *)&b,1,((struct WifiloginDisp *)p)->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[1])),1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)(*(struct ClactActor * *)&((struct WifiloginDisp *)p)->actors[1])),1);
    G2x_SetBlendAlpha_((unsigned int *)((void *)0x04000050),4,3,6,16);
    G2x_SetBlendAlpha_((unsigned int *)((void *)0x04001050),8,21,6,16);
    ((struct WifiloginDisp *)p)->hblankTask = GFL_USE_AddHBlankTask((void (*)(struct TcbTask *, void *))((u32)WIFILOGIN_DISP_ScanlineEffect),(void *)((u32)p),0);
    FX_MakeSineTable(((struct WifiloginDisp *)p)->sineTable,192,1456,6144);
    ((struct WifiloginDisp *)p)->frameTimer = 10;
}

void WIFILOGIN_DISP_CreateUnit(u8 *p) { CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam,(const struct DispVramCfg *)d_021D65E4,((struct WifiloginDisp *)p)->heapId); ((struct WifiloginDisp *)p)->unit=CLACT_CreateUnit(40,0,((struct WifiloginDisp *)p)->heapId); ((struct WifiloginDisp *)p)->vblankTask=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))WIFILOGIN_DISP_VBlank,(void *)p,0); }

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
void WIFILOGIN_DISP_ScanlineEffect(void *unused, u8 *p) {
    int i;
    i = *(volatile u16 *)0x04000006;
    i = (i + (((struct WifiloginDisp *)p)->scanline + 1)) % 192;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x04000014 = *(s16 *)(p + 0x9ca + i * 2) & 511;
        *(volatile u32 *)0x04001018 = *(s16 *)(p + 0x9ca + i * 2) & 511;
    }
}

void WIFILOGIN_DISP_VBlank(void *task,u8 *p) { if(((struct WifiloginDisp *)p)->frameTimer>0) { BG_SYS_ChangeScrollImmediate(7,0,((struct WifiloginDisp *)p)->frameTimer-1); BG_SYS_ChangeScrollImmediate(2,0,((struct WifiloginDisp *)p)->frameTimer-1); } CLACT_VBlankSystem(); }

void WIFILOGIN_DISP_SetPaletteFlag(u8 *p) { ((struct WifiloginDisp *)p)->palFlag = 1; }

void WIFILOGIN_DISP_SetupScreen(u8 *p) {
    switch (((struct WifiloginDisp *)p)->mode) {
    case 1:
        G2x_SetBlendAlpha_((void *)0x04000050, 4, 3, 6, 16);
        G2x_SetBlendAlpha_((void *)0x04001050, 8, 21, 6, 16);
        break;
    case 0:
        G2x_SetBlendAlpha_((void *)0x04000050, 1, 8, 8, 16);
        break;
    }
}
