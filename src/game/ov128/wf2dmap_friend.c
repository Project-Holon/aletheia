/*
 * file:     wf2dmap_friend.c
 * unit:     yes
 * function: Wf2dmapFriend_Create, Wf2dmapFriend_Main, Wf2dmapFriend_Delete, Wf2dmapFriend_Proc, Wf2dmapFriend_Setup, Wf2dmapFriend_Teardown, Wf2dmapFriend_CreateWindow, Wf2dmapFriend_InitText, Wf2dmapFriend_DeleteText, Wf2dmapFriend_SetState, Wf2dmapFriend_CopyText, Wf2dmapFriend_SubmitFriendKey, Wf2dmapFriend_SetNameEntry, Wf2dmapFriend_SetIndex, Wf2dmapFriend_BuildEntryList, Wf2dmapFriend_InitGfx, Wf2dmapFriend_Draw, Wf2dmapFriend_VBlank, Wf2dmapFriend_DeleteGfx, Wf2dmapFriend_SetVramBanks, Wf2dmapFriend_InitBg, Wf2dmapFriend_DeleteBg, Wf2dmapFriend_InitActors, Wf2dmapFriend_DeleteActors, Wf2dmapFriend_InitFont, Wf2dmapFriend_DeleteFont, Wf2dmapFriend_InitWindows, Wf2dmapFriend_DeleteWindows, Wf2dmapFriend_LoadBmps, Wf2dmapFriend_DeleteBmps, Wf2dmapFriend_DrawText, Wf2dmapFriend_ClearWindow, Wf2dmapFriend_SetFriendCode, Wf2dmapFriend_PrintMyStatus, Wf2dmapFriend_PrintTrainerStats, Wf2dmapFriend_SetWordSlot, Wf2dmapFriend_CreateListActors, Wf2dmapFriend_DeleteListActors, Wf2dmapFriend_SetActorDrawEnable, Wf2dmapFriend_SetActorAutoAnim, Wf2dmapFriend_RestartActorAnim, Wf2dmapFriend_OpenMenu, Wf2dmapFriend_UpdateMenu, Wf2dmapFriend_InitTopBar, Wf2dmapFriend_TopBarMain, Wf2dmapFriend_Exit, Wf2dmapFriend_InitListScreen, Wf2dmapFriend_DeleteListScreen, Wf2dmapFriend_DrawListBg, Wf2dmapFriend_ListKeyInput, Wf2dmapFriend_ListTouchInput, Wf2dmapFriend_ListInput, Wf2dmapFriend_SetListState, Wf2dmapFriend_ClearListScreen, Wf2dmapFriend_PrintMessage, Wf2dmapFriend_UpdatePrintStream, Wf2dmapFriend_CheckPrintStream, Wf2dmapFriend_ResetListWindow, Wf2dmapFriend_HasFreeFriendSlot, Wf2dmapFriend_InitItemScreen, Wf2dmapFriend_ItemScreenMain, Wf2dmapFriend_DeleteItemScreen, Wf2dmapFriend_InitItemWidgets, Wf2dmapFriend_DeleteItemWidgets, Wf2dmapFriend_SetupItemScreen, Wf2dmapFriend_ClearItemScreens, Wf2dmapFriend_ItemSelect, Wf2dmapFriend_ItemKeyInput, Wf2dmapFriend_ItemTouchInput, Wf2dmapFriend_ItemInput, Wf2dmapFriend_StartItemOpen, Wf2dmapFriend_StepItemOpen, Wf2dmapFriend_WaitItemOpen, Wf2dmapFriend_GetEntryFriendKey, Wf2dmapFriend_PrintEntryInfo, Wf2dmapFriend_OpenEntryMenu, Wf2dmapFriend_UpdateEntryMenu, Wf2dmapFriend_ShowEntryFriendCode, Wf2dmapFriend_PrintEntryName, Wf2dmapFriend_OpenConfirmMenu, Wf2dmapFriend_DrawEntry, Wf2dmapFriend_DrawEntryOpen, Wf2dmapFriend_NoopA, Wf2dmapFriend_NoopB, Wf2dmapFriend_SetEntryAnim, Wf2dmapFriend_PrintEntryMessage, Wf2dmapFriend_CheckEntryPrintStream, Wf2dmapFriend_ShowEntryDetail, Wf2dmapFriend_ClearEntryWindow, Wf2dmapFriend_GetEntryIndex, Wf2dmapFriend_ShowEntryActor, Wf2dmapFriend_StepEntryActor, Wf2dmapFriend_HideEntryActor, Wf2dmapFriend_CopyPos, Wf2dmapFriend_NoopC, Wf2dmapFriend_DrawEntryBg, Wf2dmapFriend_DrawEntryPage, Wf2dmapFriend_DrawEntryPageTransfer, Wf2dmapFriend_ClearEntryPage, Wf2dmapFriend_DeleteEntryActors, Wf2dmapFriend_DrawEntrySlot, Wf2dmapFriend_CreateEntryActor, Wf2dmapFriend_NameEntryMain
 * address:  0x021C6180
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gWf2dmapOverlayId 0x0000007F data
 *   gWf2dmapTouchbarOverlayId 0x00000043 data
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   WF2DMAP_TOUCH_FriendKeyScreen 0x021C8E2C thumb ov128
 *   WF2DMAP_TOUCH_FriendEditScreen 0x021C9244 thumb ov128
 *   TCB_DeleteTask 0x02030EAC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   gWf2dmapTouchbarOverlayIdRef 0x00000043 data
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   WF2DMAP_TOUCH_AddSlot 0x021CA458 thumb ov128
 *   STRBUF_Create 0x020457B0 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Copy 0x02045838 arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIFILIST_GetWork 0x02009860 thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   WIFILIST_IsFriendDataValid 0x02009A1C thumb
 *   WF2DMAP_TOUCH_ParseKey 0x021CA014 thumb ov128
 *   DWC_CheckFriendKey 0x02059354 arm
 *   WIFILIST_FindFriendByKey 0x0200F43C thumb
 *   WIFILIST_GetDwcFriendData 0x020099C8 thumb
 *   DWC_CreateFriendKeyToken 0x02059980 arm
 *   WIFILIST_StoreFriendNameFromStrbuf 0x02009A00 thumb
 *   WIFILIST_SetFriendInfoField 0x02009918 thumb
 *   WIFILIST_GetFriendInfoField 0x02009864 thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   WF2DMAP_TOUCH_CreatePalAnims 0x021CA0BC thumb ov128
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   WF2DMAP_TOUCH_UpdateSlots 0x021CA478 thumb ov128
 *   TCBL_Main 0x020310C4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WF2DMAP_TOUCH_DeletePalAnims 0x021CA10C thumb ov128
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   gWf2dmapVramBanks     0x021CA5CC  data
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_ClearLayer 0x0204152C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   gWf2dmapDispConfig 0x021CA664 data a4
 *   gWf2dmapBgTemplates 0x021CA718 data a4
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   gClActorInitParam 0x020A1448 data a4
 *   gWf2dmapRendererParam 0x021CA7D0 data a4
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   gWf2dmapBmpFileIds 0x021CA4F5 data a1
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   WF2DMAP_TOUCH_TransferScreen 0x021CA4B4 thumb ov128
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   MYSTATUS_Create 0x0200846C thumb
 *   WIFILIST_GetFriendInfo 0x020099D4 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   MYSTATUS_NameFromStrbuf 0x020084E4 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   gWf2dmapListActorPos 0x021CA800 data a2
 *   gWf2dmapConfirmActorPos 0x021CA810 data a2
 *   gWf2dmapCancelActorPos 0x021CA818 data a2
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   WF2DMAP_TOUCH_PlayActorAnimA 0x021CA3A0 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimB 0x021CA3C4 thumb ov128
 *   WF2DMAP_TOUCH_StepTopBarBlink 0x021CA1E0 thumb ov128
 *   WF2DMAP_TOUCH_GetConfirmInput 0x021CA084 thumb ov128
 *   WF2DMAP_TOUCH_UpdateTopBar 0x021CA19C thumb ov128
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   gWf2dmapFriendKeyErrorMsgIds 0x021CA4F9 data a1
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   WF2DMAP_TOUCH_ClearSlotArray 0x021CA444 thumb ov128
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   WF2DMAP_TOUCH_SetTopHighlight3 0x021CA16C thumb ov128
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 *   WF2DMAP_TOUCH_SetTopHighlight1 0x021CA154 thumb ov128
 *   WF2DMAP_TOUCH_SetTopHighlight 0x021CA184 thumb ov128
 *   gWf2dmapListHitRects 0x021CA58A data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gWf2dmapListStateTable 0x021CA51C data a4
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   WF2DMAP_TOUCH_SetScreenBrightness 0x021CA3E8 thumb ov128
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetCont 0x0203630C arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WF2DMAP_TOUCH_SetActorAnimSeq 0x021CA40C thumb ov128
 *   WF2DMAP_TOUCH_StepItemBarBlink 0x021CA320 thumb ov128
 *   WIFILIST_RemoveFriendSlot 0x02009A74 thumb
 *   WIFI_2DCHAR_Create 0x021C3EE0 thumb ov127
 *   WIFI_2DCHAR_SetupCells 0x021C4044 thumb ov127
 *   gWf2dmapEntryPositions 0x021CA564 data a4
 *   gWf2dmapItemMsgIds 0x021CA688 data a4
 *   gWf2dmapEntryActorRectA 0x021CA650 data a4
 *   gWf2dmapEntryActorRectB 0x021CA638 data a4
 *   WIFI_2DCHAR_ReleaseBmpCells 0x021C4080 thumb ov127
 *   WIFI_2DCHAR_Delete 0x021C3F80 thumb ov127
 *   WF2DMAP_TOUCH_SetItemHighlight 0x021CA2C4 thumb ov128
 *   WF2DMAP_TOUCH_SetItemHighlight1 0x021CA294 thumb ov128
 *   gWf2dmapItemHitRects 0x021CA5FC data a1
 *   CLACT_SetSurfacePos 0x0204B09C arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   gWf2dmapOpenAnimConfig 0x021CA7C0 data a4
 *   gWf2dmapOpenAnimCallbacks 0x021CA7C0 data a4
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   DWC_GetFriendKey 0x020598C4 arm
 *   gWf2dmapEntryMenuResultTable 0x021CA68C data a4
 *   WF2DMAP_TOUCH_UpdateItemBar 0x021CA2DC thumb ov128
 *   WF2DMAP_TOUCH_MakeScreen 0x021CA42C thumb ov128
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   gWf2dmapEntrySlotPos 0x021CA6C8 data a2
 *   CLACT_GetActorAnimFrame 0x0204B8F4 arm
 *   WIFI_2DCHAR_DeleteActor 0x021C41BC thumb ov127
 *   WIFI_2DCHAR_SpawnActor 0x021C40BC thumb ov127
 *   WIFI_2DCHAR_SetActorAnim 0x021C42A8 thumb ov127
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_Push 0x02031348 arm
 *   WF2DMAP_TOUCH_CreateNameEntry 0x021C8DA0 thumb ov128
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   gWf2dmapNameEntryOverlayId 0x000000C2 data
 *   gWf2dmapNameInOverlayId 0x00000081 data
 *   gNameInProcData 0x021F5580 data ov194 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   CODEIN_PARAM_Create  0x0202E4EC  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   CODEIN_PARAM_Delete  0x0202E54C  thumb  arm9
 */
#include "wf2dmap_ui_types.h"
#include "wf2dmap_touch.h"

struct Proc;
struct Node;
struct Proc;
struct Descriptor;
struct CharBuf;
struct U16Vec;
struct BigObj;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub020097BCFriend;
struct PrintSys;
struct Tcbl;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct Rec3;
struct S02031140;
struct Sub020097BCEnt;
struct Strbuf;
struct Actor;
struct TaskMenu;
struct TaskMenuTmpl;
struct Row;
struct TaskMenuRes;
struct StrObj;
struct TaskMenuState;
struct CodeIn;
struct Vec2;
struct obj;
struct CodeinParam;
struct Param;
struct S020314B8;
#include "../types.h"
#include "../ov067/touchbar.h"

#include "../arm9/bg_sys.h"



typedef struct {int heap;u8 count;u8 pad[3];void *entries;int mode;u8 x,y,a,b;} Wf2dmapMenuConfig;


typedef struct { s16 x, y, z; } Wf2dmapFriendV3;

typedef struct { u32 a, b; } W2;


typedef void (*Callback)(u8 *, u8 *, int, int);

typedef struct { Callback cb[4]; struct ClactVec2 pos; } Wf2dmapAnimConfig;

typedef struct Wf2dmapEntryMenuConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} Wf2dmapEntryMenuConfig;


typedef struct Wf2dmapEntryPos {s16 x,y; s16 rest[3];} Wf2dmapEntryPos;

typedef struct { s16 x, y, rest[3]; } Wf2dmapActorPos;


#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/gfl_heap_wrap.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/strbuf.h"
#include "../arm9/ui.h"
#include "../arm9/msg_speed.h"
struct GameData;
struct FieldState;
#include "../arm9/game_data.h"
#include "../arm9/wifilist.h"
#include "../ov010/namein_args.h"
#include "../arm9/dwc_account.h"
#include "../arm9/wifi_friend.h"
#include "../arm9/gx.h"
#include "../arm9/arc_tool.h"
#include "../arm9/net.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/clact.h"
#include "../arm9/arc_util.h"
struct DispVramCfg;
struct SysInit;
struct SurfaceInit;
struct Renderer;
#include "../arm9/app_icon.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
struct TextPrinter;
#include "../arm9/wordset.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/mystatus.h"
struct WifiFriendInfo;
struct TaskMenuInitWork;
struct TaskMenuWork;
#include "../arm9/app_taskmenu.h"
#include "../arm9/wipe.h"
struct BlinkPalAnm;
#include "../arm9/blink_palanm.h"
struct MyStatus;
struct GFont;
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
struct Wifi2dcharContext;
#include "../ov127/wifi_2dchar.h"
struct Wifi2dcharActor;
#include "../arm9/codein_param.h"
struct NameInArgs;
#include "../ov010/namein_setup.h"
int Wf2dmapFriend_Create(void *p,int unused,void *q);
int Wf2dmapFriend_Main(int result,int *stage,int unused,char *p);
int Wf2dmapFriend_Delete(void *p,int a,int b,char *q);
void Wf2dmapFriend_Proc(void *p,char *q);
void Wf2dmapFriend_Setup(char *p,u16 heap);
void Wf2dmapFriend_Teardown(u8 *p);
void Wf2dmapFriend_CreateWindow(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g);
void Wf2dmapFriend_InitText(u8 *p, const u32 *q, int heap);
void Wf2dmapFriend_DeleteText(u8 *p, void *unused);
void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b);
void Wf2dmapFriend_CopyText(u8 *p,void *a,void *b);
int Wf2dmapFriend_SubmitFriendKey(char *p,void *q,u32 arg);
void Wf2dmapFriend_SetNameEntry(char *p,int x);
void Wf2dmapFriend_SetIndex(char *p,int x);
void Wf2dmapFriend_BuildEntryList(char *p);
void Wf2dmapFriend_InitGfx(char *p,void *q,u16 heap);
void Wf2dmapFriend_Draw(u8 *p);
void Wf2dmapFriend_VBlank(void *p);
void Wf2dmapFriend_DeleteGfx(u8 *p);
void Wf2dmapFriend_SetVramBanks(void *unused);
void Wf2dmapFriend_InitBg(char *p,u16 heap);
void Wf2dmapFriend_DeleteBg(u8 *unused);
void Wf2dmapFriend_InitActors(char *p,u16 heap);
void Wf2dmapFriend_DeleteActors(char *p);
void Wf2dmapFriend_InitFont(u8 *p, u16 heap);
void Wf2dmapFriend_DeleteFont(u8 *p);
void Wf2dmapFriend_InitWindows(u8 *p,const u8 *q,u16 heap);
void Wf2dmapFriend_DeleteWindows(u8 *p);
void Wf2dmapFriend_LoadBmps(u8 *p,u16 heap);
void Wf2dmapFriend_DeleteBmps(u8 *p);
void Wf2dmapFriend_DrawText(u8 *p,u8 *q,unsigned v);
void Wf2dmapFriend_ClearWindow(u8 *p);
void Wf2dmapFriend_SetFriendCode(void **p,u64 value);
void Wf2dmapFriend_PrintMyStatus(u8 *p,u8 *q,int idx,unsigned heap);
int Wf2dmapFriend_PrintTrainerStats(u8 *p,u8 *q,int idx);
void Wf2dmapFriend_SetWordSlot(char **p, int a);
void Wf2dmapFriend_CreateListActors(char *p,u16 heap);
void Wf2dmapFriend_DeleteListActors(u8 *p);
void Wf2dmapFriend_SetActorDrawEnable(u8 *p,u32 a);
void Wf2dmapFriend_SetActorAutoAnim(u8 *p,u32 a);
void Wf2dmapFriend_RestartActorAnim(u8 *p,int i,u16 a);
void *Wf2dmapFriend_OpenMenu(void *p,void **q,int a,int heap);
int Wf2dmapFriend_UpdateMenu(u8 *p);
void Wf2dmapFriend_InitTopBar(u8 *p,u8 *q,u8 *r,u16 heap);
int Wf2dmapFriend_TopBarMain(u8 *p, u8 *q, u8 *ctx, int heap);
void Wf2dmapFriend_Exit(u8 *p,u8 *q,u8 *ctx);
void Wf2dmapFriend_InitListScreen(Wf2dmapFriendListScreen *p, u8 *a, u8 *ctx, u16 heap);
void Wf2dmapFriend_DeleteListScreen(u8 *p, u8 *unused, u8 *q);
void Wf2dmapFriend_DrawListBg(u8 *p,int *q,u8 *ctx);
int Wf2dmapFriend_ListKeyInput(u32 *p, int *q, u8 *ctx);
int Wf2dmapFriend_ListTouchInput(int *p,int *q,u8 *ctx);
int Wf2dmapFriend_ListInput(int *p,int *q,u8 *r);
void Wf2dmapFriend_SetListState(u32 *p,u8 *q);
void Wf2dmapFriend_ClearListScreen(u8 *p,u8 *q);
void Wf2dmapFriend_PrintMessage(u8 *p,u8 *ctx,unsigned v,unsigned heap);
int Wf2dmapFriend_UpdatePrintStream(void *p, int *q);
int Wf2dmapFriend_CheckPrintStream(void *p,int *q,u8 *r);
void Wf2dmapFriend_ResetListWindow(u8 *p, void *ctx);
int Wf2dmapFriend_HasFreeFriendSlot(int *p,u8 *q);
void Wf2dmapFriend_InitItemScreen(u8 *p,u8 *q,u8 *ctx,u16 value);
int Wf2dmapFriend_ItemScreenMain(u8 *p,u8 *q,u8 *ctx,u16 heap);
void Wf2dmapFriend_DeleteItemScreen(u8 *p,u8 *q,u8 *ctx);
void Wf2dmapFriend_InitItemWidgets(u8 *p, void *unused, u8 *ctx, u16 heap);
void Wf2dmapFriend_DeleteItemWidgets(u8 *p, void *unused, u8 *a);
void Wf2dmapFriend_SetupItemScreen(u8 *p,u8 *q,u8 *r,u16 heap);
void Wf2dmapFriend_ClearItemScreens(u8 *p,void *q,u8 *r);
int Wf2dmapFriend_ItemSelect(s16 *p, u8 *a, void *b, int n);
int Wf2dmapFriend_ItemKeyInput(s16 *p, u8 *a, u8 *ctx);
int Wf2dmapFriend_ItemTouchInput(s16 *p, void *a, void *b, int *changed);
int Wf2dmapFriend_ItemInput(s16 *p,u8 *q,u8 *r);
void Wf2dmapFriend_StartItemOpen(u8 *p, void *a, u8 *b, u16 c);
int Wf2dmapFriend_StepItemOpen(u8 *p, u8 *a, u8 *b, u16 h);
int Wf2dmapFriend_WaitItemOpen(u8 *p,u8 *q);
unsigned long long Wf2dmapFriend_GetEntryFriendKey(s16 *p,u8 *q);
void Wf2dmapFriend_PrintEntryInfo(s16 *p,u8 *q,u8 *r,u16 heap);
void Wf2dmapFriend_OpenEntryMenu(u8 *p, u8 *a, void *unused, int heap);
int Wf2dmapFriend_UpdateEntryMenu(u8 *p, int *a, void *b);
int Wf2dmapFriend_ShowEntryFriendCode(u8 *p, u8 *a, u8 *b, int c);
void Wf2dmapFriend_PrintEntryName(s16 *p,u8 *q,u8 *r,u16 heap);
int Wf2dmapFriend_OpenConfirmMenu(u8 *p,int *q,u8 *r,int heap);
void Wf2dmapFriend_DrawEntry(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c);
void Wf2dmapFriend_DrawEntryOpen(u8 *p, u8 *a, u8 *b, int x, int y, u16 c);
void Wf2dmapFriend_NoopA(void);
void Wf2dmapFriend_NoopB(void);
void Wf2dmapFriend_SetEntryAnim(u8 *p, u8 *a, int n);
void Wf2dmapFriend_PrintEntryMessage(u8 *p, u8 *a, int n, int heap);
int Wf2dmapFriend_CheckEntryPrintStream(void *p,int *state,u8 *q);
void Wf2dmapFriend_ShowEntryDetail(char *p,char *q);
void Wf2dmapFriend_ClearEntryWindow(char *p);
int Wf2dmapFriend_GetEntryIndex(s16 *p);
void Wf2dmapFriend_ShowEntryActor(u8 *p, u8 *unused);
int Wf2dmapFriend_StepEntryActor(u8 *p, u8 *unused);
void Wf2dmapFriend_HideEntryActor(u8 *p, u8 *unused);
void Wf2dmapFriend_CopyPos(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap);
void Wf2dmapFriend_NoopC(void *unused0, void *unused1);
void Wf2dmapFriend_DrawEntryBg(s16 *p, void *unused, u8 *q);
void Wf2dmapFriend_DrawEntryPage(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void Wf2dmapFriend_DrawEntryPageTransfer(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void Wf2dmapFriend_ClearEntryPage(char *p, void *q, void *unused);
void Wf2dmapFriend_DeleteEntryActors(char *p,int unused);
void Wf2dmapFriend_DrawEntrySlot(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap);
void Wf2dmapFriend_CreateEntryActor(char *p,char *q,int unused,int i,u16 h);
int Wf2dmapFriend_NameEntryMain(void **p, u8 *a, u8 *b, void *unused, u16 heap);
extern char gWf2dmapOverlayId[];
extern char gWf2dmapTouchbarOverlayId[];
extern char gWf2dmapTouchbarOverlayIdRef[];
extern char gWf2dmapVramBanks[];
extern const struct DispConfig gWf2dmapDispConfig;
extern const u8 gWf2dmapBgTemplates[][32];
extern const struct ClactSysInit gClActorInitParam;
extern u8 gWf2dmapRendererParam[];
extern const u8 gWf2dmapBmpFileIds[];
extern const struct ActorInitParam gWf2dmapListActorPos[];
extern const struct ActorInitParam gWf2dmapConfirmActorPos;
extern const struct ActorInitParam gWf2dmapCancelActorPos;
extern const u8 gWf2dmapFriendKeyErrorMsgIds[];
extern const char gWf2dmapListHitRects[];
extern const u8 gWf2dmapListStateTable[];
extern const Wf2dmapFriendV3 gWf2dmapEntryPositions[];
extern const W2 gWf2dmapItemMsgIds[];
extern const struct ActorInitParam gWf2dmapEntryActorRectA;
extern const struct ActorInitParam gWf2dmapEntryActorRectB;
extern const unsigned char gWf2dmapItemHitRects[];
extern Wf2dmapAnimConfig gWf2dmapOpenAnimConfig;
extern Callback gWf2dmapOpenAnimCallbacks[];
extern const int gWf2dmapEntryMenuResultTable[][8];
extern const Wf2dmapEntryPos gWf2dmapEntrySlotPos[];
extern char gWf2dmapNameEntryOverlayId[];
extern char gWf2dmapNameInOverlayId[];
extern char gNameInProcData[];
extern char d_021DA62C[];

int Wf2dmapFriend_Create(void *p,int unused,void *q)
{
    char *v;
    GF_OVERLAY_Load((u32)gWf2dmapOverlayId); GF_OVERLAY_Load((u32)gWf2dmapTouchbarOverlayId);
    GFL_HEAP_CreateChildHeap(1,52,0xc0000);
    v=PROCSYS_AllocProcWork(p,0x5b0,52);
    MI_CpuFill8(v,0,0x5b0);
    ((Wf2dmapFriendRoot *)v)->saveData=q; ((Wf2dmapFriendRoot *)v)->procHandle=0;
    Wf2dmapFriend_InitText((u8 *)(v+0x190),((Wf2dmapFriendRoot *)v)->saveData,52);
    Wf2dmapFriend_InitGfx(v+4,v+0x190,52);
    if(((Wf2dmapFriendRoot *)v)->procHandle==0) ((Wf2dmapFriendRoot *)v)->procHandle=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))Wf2dmapFriend_Proc,(void *)v,16);
    return 1;
}

int Wf2dmapFriend_Main(int result,int *stage,int unused,char *p)
{
    switch(*stage) {
    case 0:
        switch(((Wf2dmapFriendRoot *)p)->screenMode) {
        case 0: result=Wf2dmapFriend_TopBarMain((u8 *)(p+0x1fc),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 1: result=Wf2dmapFriend_ItemScreenMain((u8 *)(p+0x24c),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 2: result=Wf2dmapFriend_NameEntryMain((void **)(p+0x3f8),(u8 *)p,(u8 *)(p+0x190),p+4,52); break;
        case 3: result=WF2DMAP_TOUCH_FriendKeyScreen(p+0x404,(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 4: result=WF2DMAP_TOUCH_FriendEditScreen((u8 *)(p+0x420),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 5: ((Wf2dmapSaveControl *)(*(char * *)&((Wf2dmapFriendRoot *)p)->saveData))->mode=0; return 1;
        case 6: ((Wf2dmapSaveControl *)(*(char * *)&((Wf2dmapFriendRoot *)p)->saveData))->mode=1; return 1;
        }
        if(result==1) {
            *(int *)&((Wf2dmapFriendRoot *)p)->screenMode=((Wf2dmapFriendRoot *)p)->friendData.stateArgA;
            ((Wf2dmapFriendRoot *)p)->friendData.state=((Wf2dmapFriendRoot *)p)->friendData.stateArgB;
            ((Wf2dmapFriendRoot *)p)->counter=4;
            *stage=1;
        }
        break;
    case 1:
        if(--((Wf2dmapFriendRoot *)p)->counter<=0) *stage=0;
        break;
    }
    Wf2dmapFriend_Draw((u8 *)(p+4));
    return 0;
}

int Wf2dmapFriend_Delete(void *p,int a,int b,char *q)
{
    TCB_DeleteTask(((Wf2dmapFriendRoot *)q)->procHandle); ((Wf2dmapFriendRoot *)q)->procHandle=0;
    Wf2dmapFriend_DeleteGfx((u8 *)(q+4));
    Wf2dmapFriend_DeleteText((u8 *)(q+0x190),((Wf2dmapFriendRoot *)q)->saveData);
    PROCSYS_FreeProcWork(p); GFL_HEAP_DeleteChecked(52);
    GF_OVERLAY_Unload((u32)gWf2dmapTouchbarOverlayIdRef); GF_OVERLAY_Unload((u32)gWf2dmapOverlayId);
    return 1;
}

void Wf2dmapFriend_Proc(void *p,char *q) { Wf2dmapFriend_VBlank(q+4); }

void Wf2dmapFriend_Setup(char *p,u16 heap) {Wf2dmapFriend_InitGfx(p+4,p+0x190,heap); if(!((Wf2dmapFriendRoot *)p)->procHandle) ((Wf2dmapFriendRoot *)p)->procHandle=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))Wf2dmapFriend_Proc,(void *)p,16);}

/*
 * Addresses are Black-image addresses.
 */
void Wf2dmapFriend_Teardown(u8 *p)
{
    TCB_DeleteTask(((Wf2dmapFriendRoot *)p)->procHandle);
    *(u32 *)&((Wf2dmapFriendRoot *)p)->procHandle = 0;
    Wf2dmapFriend_DeleteGfx(p + 4);
}

void Wf2dmapFriend_CreateWindow(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g)
{
    *out=(unsigned int)BMP_WIN_Create((unsigned int)a,(unsigned int)b,(unsigned int)c,d,e,f,1);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)*out),g);
    BMP_WIN_TransferChars((struct BmpWin *)*out);
    WF2DMAP_TOUCH_AddSlot(p,out);
}

void Wf2dmapFriend_InitText(u8 *p, const u32 *q, int heap) {((Wf2dmapTouchFriendData *)p)->saveWord=*q;((Wf2dmapTouchFriendData *)p)->textBufA=STRBUF_Create(128,heap);((Wf2dmapTouchFriendData *)p)->textBufB=STRBUF_Create(128,heap);((Wf2dmapTouchFriendData *)p)->textSpeed=UI_GetInputMode();p[12]=MSG_SPEED_GetWait();p[13]=0;p[14]=1;}

void Wf2dmapFriend_DeleteText(u8 *p, void *unused) { UI_SetInputMode(((Wf2dmapTouchFriendData *)p)->textSpeed); STRBUF_Delete(((Wf2dmapTouchFriendData *)p)->textBufA); STRBUF_Delete(((Wf2dmapTouchFriendData *)p)->textBufB); }

/*
 * extent: Six code bytes followed by two zero alignment bytes.
 */
void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b)
{
    p[9] = a;
    p[10] = b;
}

void Wf2dmapFriend_CopyText(u8 *p,void *a,void *b) { if(a) STRBUF_Copy(((Wf2dmapTouchFriendData *)p)->textBufA,a); if(b) STRBUF_Copy(((Wf2dmapTouchFriendData *)p)->textBufB,b); }

int Wf2dmapFriend_SubmitFriendKey(char *p,void *q,u32 arg)
{
    int i;
    void *v;
    u64 old,id;
    int valid,result;
    v=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)p)->saveData);
    old=DWC_CreateFriendKey((struct DWCstAccUserData *)WIFILIST_GetWork(v));
    for(i=0;i<32;i++) {
        if(WIFILIST_IsFriendDataValid(v,i)==0) {
            id=WF2DMAP_TOUCH_ParseKey(q,&valid);
            if(valid==1 && id!=old) {
            if(DWC_CheckFriendKey((struct DWCstAccUserData *)WIFILIST_GetWork(v),id)==0) return 1;
            if(WIFILIST_FindFriendByKey(v,id,&result)==0) return 2;
            DWC_CreateFriendKeyToken(WIFILIST_GetDwcFriendData(v,i),id);
            WIFILIST_StoreFriendNameFromStrbuf(v,i,(void *)arg);
            WIFILIST_SetFriendInfoField(v,i,9,2);
            return 0;
            }
            return 1;
        }
    }
    return 0;
}

void Wf2dmapFriend_SetNameEntry(char *p,int x) { ((Wf2dmapTouchFriendData *)p)->nameTextInt=x; ((Wf2dmapTouchFriendData *)p)->nameFlag=1; }

void Wf2dmapFriend_SetIndex(char *p,int x) { p[11]=x; }

/*
 * lever: direct assignment from postincrement preserves the old count load;
 *   the two-byte tail at 021C658A is zero padding.
 */
void Wf2dmapFriend_BuildEntryList(char *p)
{
    int i;
    void *v;
    MI_CpuFill8(p+16,0,72);
    v=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)p)->saveData);
    ((Wf2dmapTouchFriendData *)p)->count=0;
    for(i=0;i<32;i++) {
        if(WIFILIST_IsFriendDataValid(v,i)==1) {
            *(u8 *)(p+((Wf2dmapTouchFriendData *)p)->count+24)=i;
            if(WIFILIST_GetFriendInfoField(v,i,9)==2) *(u8 *)(p+((Wf2dmapTouchFriendData *)p)->count+56)=255;
            else *(u8 *)(p+((Wf2dmapTouchFriendData *)p)->count+56)=(((Wf2dmapTouchFriendData *)p)->nextColor)++;
            ((Wf2dmapTouchFriendData *)p)->count=((Wf2dmapTouchFriendData *)p)->count+1;
        }
    }
}

/*
 * calls: 021C6698 receives live r0=0x180 although its own body ignores it;
 *   021CA0BC heap is widened because this caller has no truncation.
 * volatile: hardware register stores at 021C65A6 and 021C65A8
 */
void Wf2dmapFriend_InitGfx(char *p,void *q,u16 heap)
{
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0; *(volatile u16 *)0x04001050=0;
    GXx_SetMasterBrightness_((void *)0x0400006c,-16); GXx_SetMasterBrightness_((void *)0x0400106c,-16);
    BG_SYS_SetLcdSwap(0);
    ((Wf2dmapTouchGfx *)p)->archive=ARC_TOOL_CreateHandle(63,heap); ((Wf2dmapTouchGfx *)p)->heapId=heap;
    Wf2dmapFriend_SetVramBanks((void *)0x180);
    Wf2dmapFriend_InitBg(p,heap); Wf2dmapFriend_InitActors(p,heap); Wf2dmapFriend_InitFont((u8 *)p,heap);
    Wf2dmapFriend_InitWindows((u8 *)p,q,heap); Wf2dmapFriend_CreateListActors(p,heap); Wf2dmapFriend_LoadBmps((u8 *)p,heap); WF2DMAP_TOUCH_CreatePalAnims((u8 *)p,heap);
    GFL_NET_RefreshWmIconAtTopRight(1,52); BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
}

void Wf2dmapFriend_Draw(u8 *p) { if(((Wf2dmapTouchGfx *)p)->printWin) { PRINTSYS_QUE_Main(((Wf2dmapTouchGfx *)p)->printWin);WF2DMAP_TOUCH_UpdateSlots((char *)p); } if(((Wf2dmapTouchGfx *)p)->tcbl) TCBL_Main(((Wf2dmapTouchGfx *)p)->tcbl);CLACT_DrawSystem(); }

/*
 * calls: preserves incoming r0 at the tail call; callers load its argument
 *   even though CLACT_VBlankSystem's own body ignores that register.
 */
void Wf2dmapFriend_VBlank(void *p) { CLACT_VBlankSystem(); }

void Wf2dmapFriend_DeleteGfx(u8 *p) {WF2DMAP_TOUCH_DeletePalAnims(p);Wf2dmapFriend_DeleteListActors(p);Wf2dmapFriend_DeleteBmps(p);Wf2dmapFriend_DeleteWindows(p);Wf2dmapFriend_DeleteFont(p);Wf2dmapFriend_DeleteActors((char *)p);Wf2dmapFriend_DeleteBg(p);ARC_TOOL_DeleteHandle(((Wf2dmapTouchGfx *)p)->archive);}

void Wf2dmapFriend_SetVramBanks(void *unused)
{
    BG_SYS_SetVramBanks((const struct DispVram *)gWf2dmapVramBanks);
}

void Wf2dmapFriend_InitBg(char *p,u16 heap)
{
    struct DispConfig config;
    int i;
    BG_SYS_Create(heap); /* likely original mismatch: the original prototype took a wide heap id */
    config=gWf2dmapDispConfig;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&config));
    for(i=0;i<5;i++) {
        BG_SYS_InitBgLayer((u8)i,(const struct BgTemplate *)gWf2dmapBgTemplates[i],0);
        BG_SYS_InitRun(i,32,0,heap);
        BG_SYS_ClearLayer((u8)i,0);
        BG_SYS_SetPlaneVisible(i,1);
    }
    ARC_UTIL_UploadPaletteFromHandleWhole(((Wf2dmapTouchGfx *)p)->archive,0,0,0,192,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(((Wf2dmapTouchGfx *)p)->archive,0,4,0,192,heap);
    ARC_UTIL_UploadBgCharFromHandle(((Wf2dmapTouchGfx *)p)->archive,3,0,0,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(((Wf2dmapTouchGfx *)p)->archive,3,2,0,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(((Wf2dmapTouchGfx *)p)->archive,3,4,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(((Wf2dmapTouchGfx *)p)->archive,5,0,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(((Wf2dmapTouchGfx *)p)->archive,14,4,0,0,0,heap);
}

void Wf2dmapFriend_DeleteBg(u8 *unused)
{
    int i;
    for (i = 0; i < 5; i++)
        BG_SYS_FreeLayerBuf((u8)i);
    BG_SYS_Delete();
}

void Wf2dmapFriend_InitActors(char *p,u16 heap)
{
    struct ClactSysInit config=gClActorInitParam;
    void *bank,*archive;
    u32 first,second;
    config.oam_main_base=16;
    config.oam_main_count=112;
    CLACT_InitSystem(&config,(struct DispVramCfg *)gWf2dmapVramBanks,heap);
    bank=CLACT_CreateUnit(32,0,heap);
    ((Wf2dmapTouchGfx *)p)->actorBank=bank;
    CLACT_SetUnitDefaultRenderer(bank);
    ((Wf2dmapTouchGfx *)p)->renderer=CLACT_CreateRenderer((struct SurfaceInit *)gWf2dmapRendererParam,1,heap);
    bank=CLACT_CreateUnit(18,1,heap);
    ((Wf2dmapTouchGfx *)p)->actorBank2=bank;
    CLACT_SetUnitRenderer(bank,((Wf2dmapTouchGfx *)p)->renderer);
    ((Wf2dmapTouchGfx *)p)->character[0]=CLACT_RegisterCharacter(((Wf2dmapTouchGfx *)p)->archive,4,0,0,heap);
    ((Wf2dmapTouchGfx *)p)->palette[0]=CLACT_RegisterPalette(((Wf2dmapTouchGfx *)p)->archive,1,0,0,heap);
    ((Wf2dmapTouchGfx *)p)->cellAnim[0]=CLACT_RegisterCellAnim(((Wf2dmapTouchGfx *)p)->archive,15,16,heap);
    archive=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),heap);
    ((Wf2dmapTouchGfx *)p)->character[1]=CLACT_RegisterCharacter(archive,APP_ICON_GetMoveKindAnimFileId(),0,0,heap);
    ((Wf2dmapTouchGfx *)p)->palette[1]=CLACT_RegisterPalette(archive,APP_ICON_GetMoveKindPaletteFileId(),0,96,heap);
    first=APP_ICON_GetStatusCellFileId(2);
    second=APP_ICON_GetStatusPaletteFileId(2);
    ((Wf2dmapTouchGfx *)p)->cellAnim[1]=CLACT_RegisterCellAnim(archive,first,second,heap);
    ARC_TOOL_DeleteHandle(archive);
}

void Wf2dmapFriend_DeleteActors(char *p)
{
    unsigned i;
    for(i=0;i<2;i++) CLACT_ReleaseCharacter(*(u32 *)(p+i*4+0x144));
    for(i=0;i<2;i++) CLACT_ReleasePalette(*(u32 *)(p+i*4+0x14c));
    for(i=0;i<2;i++) CLACT_ReleaseCellAnim(*(u32 *)(p+i*4+0x154));
    CLACT_DeleteUnit(((Wf2dmapTouchGfx *)p)->actorBank2);
    CLACT_DeleteRenderer(((Wf2dmapTouchGfx *)p)->renderer);
    CLACT_DeleteUnit(((Wf2dmapTouchGfx *)p)->actorBank);
    CLACT_ExitSystem();
}

void Wf2dmapFriend_InitFont(u8 *p, u16 heap)
{
    GF_FONT_SetDefaultTextColor();
    ((Wf2dmapTouchGfx *)p)->wordSet=WORDSET_CreateDefault(heap);
    ((Wf2dmapTouchGfx *)p)->msgBank=MSGDATA_CreateFromArchive(0,2,211,heap);
    ((Wf2dmapTouchGfx *)p)->palWin=GF_FONT_Create(23,0,0,0,heap);
    ((Wf2dmapTouchGfx *)p)->tcbl=TCBL_Create(heap,heap,3,256);
    ((Wf2dmapTouchGfx *)p)->printStream=0;
    ((Wf2dmapTouchGfx *)p)->printWin=(void *)PRINTSYS_QUE_Create((unsigned int)heap);
}

void Wf2dmapFriend_DeleteFont(u8 *p)
{
    PRINTSYS_QUE_Clear(((Wf2dmapTouchGfx *)p)->printWin);
    PRINTSYS_QUE_Delete(((Wf2dmapTouchGfx *)p)->printWin);
    ((Wf2dmapTouchGfx *)p)->printWin=0;
    if (((Wf2dmapTouchGfx *)p)->printStream) {
        PRINTSYS_PrintStreamDelete(((Wf2dmapTouchGfx *)p)->printStream);
        ((Wf2dmapTouchGfx *)p)->printStream=0;
    }
    TCBL_Destroy(((Wf2dmapTouchGfx *)p)->tcbl);
    ((Wf2dmapTouchGfx *)p)->tcbl=0;
    GF_FONT_Delete(((Wf2dmapTouchGfx *)p)->palWin);
    MSGDATA_Delete(((Wf2dmapTouchGfx *)p)->msgBank);
    WORDSET_Delete(((Wf2dmapTouchGfx *)p)->wordSet);
}

void Wf2dmapFriend_InitWindows(u8 *p,const u8 *q,u16 heap)
{
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,320,32,heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,heap);
    BMP_MENUWORK_LoadCharAndPltt(1,70,11,q[13],heap);
    BMP_WIN_Init(heap);
    Wf2dmapFriend_CreateWindow(p,(u32 *)(p+12),1,1,0,24,3,10,100,0);
    ((Wf2dmapTouchGfx *)p)->textBufA=STRBUF_Create(128,heap);
    ((Wf2dmapTouchGfx *)p)->textBufB=STRBUF_Create(128,heap);
    ((Wf2dmapTouchGfx *)p)->textHandleStrbuf=STRBUF_Create(128,heap);
    ((Wf2dmapTouchGfx *)p)->formatArg=STRBUF_Create(128,heap);
}

void Wf2dmapFriend_DeleteWindows(u8 *p) { STRBUF_Delete(((Wf2dmapTouchGfx *)p)->textHandleStrbuf);STRBUF_Delete(((Wf2dmapTouchGfx *)p)->formatArg);STRBUF_Delete(((Wf2dmapTouchGfx *)p)->textBufA);STRBUF_Delete(((Wf2dmapTouchGfx *)p)->textBufB);BMP_WIN_Delete(((Wf2dmapTouchGfx *)p)->window);BMP_WIN_Exit(); }

void Wf2dmapFriend_LoadBmps(u8 *p,u16 heap) {int i;for(i=0;i<2;i++) *(void **)(p+0x16c+i*4)=ARC_UTIL_LoadPaletteDataFromHandle(((Wf2dmapTouchGfx *)p)->archive,gWf2dmapBmpFileIds[i],0,(void **)(p+0x174+i*4),heap);}

void Wf2dmapFriend_DeleteBmps(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        GFL_HEAP_Free(*(void **)(p + 0x16c + i * 4));
}

void Wf2dmapFriend_DrawText(u8 *p,u8 *q,unsigned v)
{
    BMP_Clear(BMP_WIN_GetBmp(((Wf2dmapTouchSlot *)q)->window),0);
    BMP_WIN_TransferChars(((Wf2dmapTouchSlot *)q)->window);
    MSGDATA_ReadString(((Wf2dmapTouchGfx *)p)->msgBank,v,((Wf2dmapTouchGfx *)p)->textBufB);
    WORDSET_CopyTaggedText(((Wf2dmapTouchGfx *)p)->wordSet,((Wf2dmapTouchGfx *)p)->textBufA,((Wf2dmapTouchGfx *)p)->textBufB);
    TOUCHBAR_PrintAligned((TouchBarWindow *)q,(void *)(((Wf2dmapTouchGfx *)p)->printWin),0,4,(u32)(((Wf2dmapTouchGfx *)p)->textBufA),(u32)(((Wf2dmapTouchGfx *)p)->palWin),0x3c40,0);
    WF2DMAP_TOUCH_TransferScreen(((Wf2dmapTouchSlot *)q)->window);
}

void Wf2dmapFriend_ClearWindow(u8 *p)
{
    void *q = ((Wf2dmapTouchGfx *)p)->window;
    BMP_WIN_ClearScreen(q);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(q));
}

void Wf2dmapFriend_SetFriendCode(void **p,u64 value)
{
    WORDSET_SetSlotNumber(*p,1,(unsigned)(value/100000000ULL),4,2,1);
    WORDSET_SetSlotNumber(*p,2,(unsigned)(value/10000ULL%10000ULL),4,2,1);
    WORDSET_SetSlotNumber(*p,3,(unsigned)(value%10000ULL),4,2,1);
}

void Wf2dmapFriend_PrintMyStatus(u8 *p,u8 *q,int idx,unsigned heap)
{
    void *base;
    void *obj;
    void *str;
    base=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
    obj=MYSTATUS_Create(heap);
    str=STRBUF_Create(10,heap);
    STRBUF_SetString(str,(const u16 *)WIFILIST_GetFriendInfo(base,idx));
    MYSTATUS_NameFromStrbuf(obj,str);
    STRBUF_Delete(str);
    WORDSET_SetSlotMyStatus(((Wf2dmapTouchGfx *)p)->wordSet,0,obj);
    GFL_HEAP_Free(obj);
}

int Wf2dmapFriend_PrintTrainerStats(u8 *p,u8 *q,int idx)
{
    void *base;
    unsigned v;
    int result;
    base=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
    result=1;
    v=WIFILIST_GetFriendInfoField(base,idx,7);
    if(v==0) result=0;
    WORDSET_SetSlotNumber(((Wf2dmapTouchGfx *)p)->wordSet,2,v,2,0,1);
    v=WIFILIST_GetFriendInfoField(base,idx,5);
    WORDSET_SetSlotNumber(((Wf2dmapTouchGfx *)p)->wordSet,0,v,4,1,1);
    v=WIFILIST_GetFriendInfoField(base,idx,6);
    WORDSET_SetSlotNumber(((Wf2dmapTouchGfx *)p)->wordSet,1,v,2,0,1);
    return result;
}

void Wf2dmapFriend_SetWordSlot(char **p, int a)
{
    WORDSET_SetSlotNumber((struct WordSet *)(*p), 0, a, 4, 1, 1);
}

/*
 * calls: 0204B294 returns the handle read in r0; heap is not truncated.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`a=0x138;` before `a=0x148;`; `b=0x138;` before `b=0x150;` and 4 more).
 * Game code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void Wf2dmapFriend_CreateListActors(char *p,u16 heap)
{
    int a,b,c,d,e,f,i;
    char *q;
    void *handle;
    a=0x148;
    b=0x150;
    c=0x158;
    d=0x15c;
    e=0x15c;
    f=0x15c;
    for(i=0;i<2;i++) {
        q=p+i*4;
        *(void **)(q+d)=CLACT_CreateActor(((Wf2dmapTouchGfx *)p)->actorBank,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&gWf2dmapListActorPos[i],0,heap);
        CLACT_SetActorAutoAnim(*(void **)(q+e),1);
        CLACT_SetActorDrawEnable(*(void **)(q+f),0);
    }
    handle=CLACT_CreateActor(((Wf2dmapTouchGfx *)p)->actorBank,((Wf2dmapTouchGfx *)p)->character[1],((Wf2dmapTouchGfx *)p)->palette[1],((Wf2dmapTouchGfx *)p)->cellAnim[1],&gWf2dmapConfirmActorPos,0,heap);
    ((Wf2dmapTouchGfx *)p)->actorA=handle;
    CLACT_SetActorDrawEnable(handle,1);
    handle=CLACT_CreateActor(((Wf2dmapTouchGfx *)p)->actorBank,((Wf2dmapTouchGfx *)p)->character[1],((Wf2dmapTouchGfx *)p)->palette[1],((Wf2dmapTouchGfx *)p)->cellAnim[1],&gWf2dmapCancelActorPos,0,heap);
    ((Wf2dmapTouchGfx *)p)->actorB=handle;
    CLACT_SetActorDrawEnable(handle,1);
}

void Wf2dmapFriend_DeleteListActors(u8 *p) {int i;CLACT_DeleteActor(((Wf2dmapTouchGfx *)p)->actorB);CLACT_DeleteActor(((Wf2dmapTouchGfx *)p)->actorA);for(i=0;i<2;i++) CLACT_DeleteActor(*(void **)((u32)p+i*4+0x15c));}

void Wf2dmapFriend_SetActorDrawEnable(u8 *p,u32 a) {int i; for(i=0;i<2;i++) CLACT_SetActorDrawEnable(*(void **)((u32)p+i*4+0x15c),a);}

void Wf2dmapFriend_SetActorAutoAnim(u8 *p,u32 a) {int i; for(i=0;i<2;i++) CLACT_SetActorAutoAnim(*(void **)((u32)p+i*4+0x15c),a);}

void Wf2dmapFriend_RestartActorAnim(u8 *p,int i,u16 a) {CLACT_SetActorAutoAnim(*(void **)((u32)p+0x15c+i*4),1);CLACT_SetActorAnimSeq(*(void **)((u32)p+0x15c+i*4),a);CLACT_RestartActorAnim(*(void **)((u32)p+0x15c+i*4));}

void *Wf2dmapFriend_OpenMenu(void *p,void **q,int a,int heap) {Wf2dmapMenuConfig c;c.heap=heap;c.count=2;c.entries=p;c.mode=1;c.x=32;if(a==1)c.y=18;else c.y=12;c.a=8;c.b=3;return APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&c),*q);}

int Wf2dmapFriend_UpdateMenu(u8 *p) {int n;APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)p);if(APP_TASKMENU_IsFinish((struct TaskMenuWork *)p)==1) {n=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)p);APP_TASKMENU_CloseMenu((struct TaskMenuWork *)p);return n;}return -1;}

void Wf2dmapFriend_InitTopBar(u8 *p,u8 *q,u8 *r,u16 heap) {((Wf2dmapTouchFriendData *)q)->textSpeed=UI_GetInputMode();Wf2dmapFriend_InitListScreen((Wf2dmapFriendListScreen *)p,q,r,heap);}

/*
 * note: 2026-10-05 lane P24L6. Bytes equal to the original (632 B function, 640 B listing
 * extent includes the 8 B stub Wf2dmapFriend_Exit). Only the two Wf2dmapFriend_Exit relocations
 * lack a witness: the stub is now filed as src/matched/ov/Wf2dmapFriend_Exit.c (EXACT),
 * so this file should become EXACT after the next manifest refresh. Recoup trail: the
 * condition chain on *p (3,4,1) is an if/else-if chain with q[8]=5 repeated in each arm
 * (bne over b); the shared finish block (Wf2dmapFriend_ResetListWindow with ctx as 2nd argument,
 * WF2DMAP_TOUCH_UpdateTopBar, q[8]=3) is written out in each of its three arms (case 10 arm 0, case 10
 * arm 1, case 11) and case 10 is an inner switch on the menu status. A goto finish form
 * and a return-0 form were each 4 to 70 bytes off. Callee problem: matched Wf2dmapFriend_ResetListWindow
 * takes one parameter but this caller passes two (p, ctx).
 */
int Wf2dmapFriend_TopBarMain(u8 *p, u8 *q, u8 *ctx, int heap)
{
    int result;
    void *text;
    u64 number;
    switch(q[8]) {
    case 0:
        Wf2dmapFriend_InitTopBar(p,q,ctx,52);
        Wf2dmapFriend_DrawListBg(p,(int *)q,ctx);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);
        q[8]=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()!=0) q[8]=3;
        break;
    case 2:
        Wf2dmapFriend_InitTopBar(p,q,ctx,52);
        Wf2dmapFriend_DrawListBg(p,(int *)q,ctx);
        q[8]=3;
        break;
    case 3:
        BLINK_PALANM_Update(*(void **)(ctx+0x184));
        result=Wf2dmapFriend_ListInput((int *)p,(int *)q,ctx);
        if(result!=0) {
            if(*(u32 *)p==3) WF2DMAP_TOUCH_PlayActorAnimA((char *)ctx);
            else if(*(u32 *)p==4) WF2DMAP_TOUCH_PlayActorAnimB((char *)ctx);
            else *(u16 *)(p+8)=0;
            q[8]=4;
        }
        break;
    case 4:
        if(*(u32 *)p==3) {
            if(CLACT_IsActorAnimActive(*(void **)(ctx+0x164))==1) break;
        } else if(*(u32 *)p==4) {
            if(CLACT_IsActorAnimActive(*(void **)(ctx+0x168))==1) break;
        } else {
            if(WF2DMAP_TOUCH_StepTopBarBlink((char *)p)==1) break;
        }
        if(Wf2dmapFriend_HasFreeFriendSlot((int *)p,q)==1) {
            Wf2dmapFriend_SetListState((u32 *)p,q);
            if(*(u32 *)p==3) q[8]=5;
            else if(*(u32 *)p==4) q[8]=5;
            else if(*(u32 *)p==1) q[8]=5;
            else {
                Wf2dmapFriend_ClearListScreen(p,ctx);
                Wf2dmapFriend_Exit(p,q,ctx);
                return 1;
            }
        } else {
            Wf2dmapFriend_PrintMessage(p,ctx,58,heap);
            q[8]=11;
        }
        break;
    case 5:
        WIPE_SYS_Start(0,0,0,0,6,1,heap);
        q[8]++;
        break;
    case 6:
        if(WIPE_SYS_EndCheck()==1) {
            Wf2dmapFriend_Exit(p,q,ctx);
            return 1;
        }
        break;
    case 7:
        Wf2dmapFriend_InitTopBar(p,q,ctx,52);
        Wf2dmapFriend_DrawListBg(p,(int *)q,ctx);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);
        q[8]=8;
        break;
    case 8:
        if(WIPE_SYS_EndCheck()!=0) {
            text=MYSTATUS_Create(heap);
            MYSTATUS_NameFromStrbuf(text,*(void **)(q+0x58));
            WORDSET_SetSlotMyStatus(*(void **)ctx,0,text);
            GFL_HEAP_Free(text);
            number=WF2DMAP_TOUCH_ParseKey(*(void **)(q+0x5C),&result);
            if(result!=0) {
                Wf2dmapFriend_SetFriendCode((void **)ctx,number);
                Wf2dmapFriend_PrintMessage(p,ctx,55,heap);
                q[8]=9;
            } else {
                Wf2dmapFriend_PrintMessage(p,ctx,56,heap);
                q[8]=11;
            }
        }
        break;
    case 9:
        if(Wf2dmapFriend_CheckPrintStream(p,(int *)q,ctx)!=0) {
            *(void **)(p+0x4C)=Wf2dmapFriend_OpenMenu(p+0x30,(void **)(p+0x48),1,heap);
            q[8]=10;
        }
        break;
    case 10:
        switch(Wf2dmapFriend_UpdateMenu(*(void **)(p+0x4C))) {
        case 0:
            {
            int submission;
            *(u32 *)q=UI_GetInputMode();
            submission=Wf2dmapFriend_SubmitFriendKey((char *)q,*(void **)(q+0x5C),*(u32 *)(q+0x58));
            if(submission==0) {
                Wf2dmapFriend_ResetListWindow(p,ctx);
                WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
                q[8]=3;
            } else {
                Wf2dmapFriend_PrintMessage(p,ctx,gWf2dmapFriendKeyErrorMsgIds[submission],heap);
                q[8]=11;
            }
            }
            break;
        case 1:
            *(u32 *)q=UI_GetInputMode();
            Wf2dmapFriend_ResetListWindow(p,ctx);
            WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
            q[8]=3;
            break;
        }
        break;
    case 11:
        if(Wf2dmapFriend_CheckPrintStream(p,(int *)q,ctx)!=0 && WF2DMAP_TOUCH_GetConfirmInput((int *)q)==1) {
            Wf2dmapFriend_ResetListWindow(p,ctx);
            WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
            q[8]=3;
        }
        break;
    default:
        break;
    }
    return 0;
}

void Wf2dmapFriend_Exit(u8 *p,u8 *q,u8 *ctx) { Wf2dmapFriend_DeleteListScreen(p,q,ctx); }

void Wf2dmapFriend_InitListScreen(Wf2dmapFriendListScreen *p, u8 *a, u8 *ctx, u16 heap)
{
    int i;
    void *buf;
    void *text;
    u32 width;
    Wf2dmapFriend_CreateWindow(ctx,(u32 *)((u8 *)p+12),3,4,5,24,20,10,1,0);
    Wf2dmapFriend_CreateWindow(ctx,(u32 *)((u8 *)p+28),1,2,19,27,4,10,172,0);
    p->buf=STRBUF_Create(128,heap);
    buf=STRBUF_Create(128,heap);
    text=STRBUF_Create(128,heap);
    WORDSET_SetSlotMyStatus(((Wf2dmapTouchGfx *)ctx)->wordSet,0,GAME_DATA_GetMyStatus(((Wf2dmapTouchFriendData *)a)->saveData));
    for(i=0;i<3;i++) {
        MSGDATA_ReadString(((Wf2dmapTouchGfx *)ctx)->msgBank,i+1,text);
        WORDSET_CopyTaggedText(((Wf2dmapTouchGfx *)ctx)->wordSet,buf,text);
        width=PRINTSYS_MeasureWidestLine((struct Strbuf *)((u32)buf),(struct GfFont *)(((Wf2dmapTouchGfx *)ctx)->palWinU32),0);
        TOUCHBAR_PrintAligned((TouchBarWindow *)((u8 *)p+12),(void *)(((Wf2dmapTouchGfx *)ctx)->printWin),(192-width)/2,i*40+8,(u32)buf,((Wf2dmapTouchGfx *)ctx)->palWinU32,0x440,0);
    }
    WF2DMAP_TOUCH_TransferScreen(((Wf2dmapFriendListScreen *)p)->windowA);
    STRBUF_Delete(buf);
    STRBUF_Delete(text);
    ((Wf2dmapFriendListScreen *)p)->bitmap=ARC_UTIL_LoadPaletteDataFromHandle(((Wf2dmapTouchGfx *)ctx)->archive,13,0,(void **)((u8 *)p+24),heap);
    p->text1=MSGDATA_AllocString(((Wf2dmapTouchGfx *)ctx)->msgBank,66);
    p->color1=0x39e3;
    p->flag1=0;
    p->text2=MSGDATA_AllocString(((Wf2dmapTouchGfx *)ctx)->msgBank,67);
    p->color2=0x39e3;
    p->flag2=0;
    p->menu=APP_TASKMENU_RES_Create(1,14,(struct GFont *)(((Wf2dmapTouchGfx *)ctx)->palWinU32),(struct PrintQueue *)(((Wf2dmapTouchGfx *)ctx)->printWinU32),heap);
}

void Wf2dmapFriend_DeleteListScreen(u8 *p, u8 *unused, u8 *q)
{
    WF2DMAP_TOUCH_ClearSlotArray((char *)q);
    WF2DMAP_TOUCH_AddSlot((char *)q,q+12);
    APP_TASKMENU_RES_Delete(((Wf2dmapFriendListScreen *)p)->menu);
    STRBUF_Delete(((Wf2dmapFriendListScreen *)p)->text1);
    STRBUF_Delete(((Wf2dmapFriendListScreen *)p)->text2);
    STRBUF_Delete(((Wf2dmapFriendListScreen *)p)->buf);
    BMP_WIN_Delete(((Wf2dmapFriendListScreen *)p)->windowB);
    BMP_WIN_Delete(((Wf2dmapFriendListScreen *)p)->windowA);
    GFL_HEAP_Free(((Wf2dmapFriendListScreen *)p)->bitmap);
}

void Wf2dmapFriend_DrawListBg(u8 *p,int *q,u8 *ctx)
{
    u16 *data;
    Wf2dmapFriend_DrawText(ctx,ctx+12,0);
    data=*(u16 * *)&((Wf2dmapFriendListScreen *)p)->bmpDesc;
    BG_SYS_DrawTile(2,((u8 *)data+12),0,0,data[0]>>3,data[1]>>3);
    BG_SYS_ChangeScrollImmediate(2,0,0);
    BG_SYS_ChangeScrollImmediate(2,3,0);
    if(*q==0) WF2DMAP_TOUCH_SetTopHighlight3(ctx,((Wf2dmapFriendListScreen *)p)->highlight);
    else BG_SYS_MarkTileDirty(2);
}

int Wf2dmapFriend_ListKeyInput(u32 *p, int *q, u8 *ctx)
{
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        WF2DMAP_TOUCH_SetTopHighlight1(ctx, *p);
        UI_SetInputMode(0);
        *q = 0;
        *p = 3;
        return 1;
    }
    if (KEY_GetTrg() & 1024) {
        GFL_USE_PlaySeDefaultVolume(0x556);
        WF2DMAP_TOUCH_SetTopHighlight1(ctx, *p);
        UI_SetInputMode(0);
        *q = 0;
        *p = 4;
        return 1;
    }
    if (*q == 1) {
        if (KEY_GetTrg() & 0xcf3) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetTopHighlight(ctx, *p, *p);
            UI_SetInputMode(0);
            *q = 0;
        }
        return 0;
    }
    if (KEY_GetTrg() & 1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)ctx)->palAnimA);
        return 1;
    }
    if (KEY_GetRepeat() & 64) {
        if (*p != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetTopHighlight(ctx, *p - 1, *p);
            --*p;
            return 0;
        }
    } else if (KEY_GetRepeat() & 128) {
        if (*p < 2) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetTopHighlight(ctx, *p + 1, *p);
            ++*p;
            return 0;
        }
    }
    return 0;
}

int Wf2dmapFriend_ListTouchInput(int *p,int *q,u8 *ctx)
{
    int v;
    v=TOUCHPANEL_HitTrg((const TouchHitTable *)gWf2dmapListHitRects);
    if(v!=-1) {
        if(v==3) {
            GFL_USE_PlaySeDefaultVolume(1361);
            WF2DMAP_TOUCH_SetTopHighlight1(ctx,*p);
        } else if(v==4) {
            GFL_USE_PlaySeDefaultVolume(1366);
            WF2DMAP_TOUCH_SetTopHighlight1(ctx,*p);
        } else {
            GFL_USE_PlaySeDefaultVolume(1356);
            WF2DMAP_TOUCH_SetTopHighlight(ctx,v,*p);
        }
        *p=v;
        UI_SetInputMode(1);
        *q=1;
    }
    return v;
}

int Wf2dmapFriend_ListInput(int *p,int *q,u8 *r) {if(Wf2dmapFriend_ListTouchInput(p,q,r)!=-1) return 1;return Wf2dmapFriend_ListKeyInput((u32 *)p,q,r);}

void Wf2dmapFriend_SetListState(u32 *p,u8 *q) {Wf2dmapFriend_SetState(q,gWf2dmapListStateTable[*p],0);}

void Wf2dmapFriend_ClearListScreen(u8 *p,u8 *q)
{
    void *obj;
    Wf2dmapFriend_ClearWindow(q);
    BG_SYS_SetTileEntry(2,0,0,0,32,24,16);
    BG_SYS_MarkTileDirty(2);
    BG_SYS_SetTileEntry(3,0,0,0,32,24,16);
    BG_SYS_MarkTileDirty(3);
    obj=((Wf2dmapFriendListScreen *)p)->windowA;
    BMP_WIN_ClearScreen(obj);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(obj));
}

void Wf2dmapFriend_PrintMessage(u8 *p,u8 *ctx,unsigned v,unsigned heap)
{
    void *buf;
    void *obj;
    int font;
    if(((Wf2dmapTouchGfx *)ctx)->printStream) {
        PRINTSYS_PrintStreamDelete(((Wf2dmapTouchGfx *)ctx)->printStream);
        ((Wf2dmapTouchGfx *)ctx)->printStream=0;
    }
    buf=STRBUF_Create(128,heap);
    BMP_Clear(BMP_WIN_GetBmp(((Wf2dmapFriendListScreen *)p)->windowB),15);
    MSGDATA_ReadString(((Wf2dmapTouchGfx *)ctx)->msgBank,v,buf);
    WORDSET_CopyTaggedText(((Wf2dmapTouchGfx *)ctx)->wordSet,((Wf2dmapFriendListScreen *)p)->buf,buf);
    font=MSG_SPEED_GetWait();
    ((Wf2dmapTouchGfx *)ctx)->printStream=PRINTSYS_PrintStream(((Wf2dmapFriendListScreen *)p)->windowB,0,0,((Wf2dmapFriendListScreen *)p)->buf,((Wf2dmapTouchGfx *)ctx)->palWin,font,((Wf2dmapTouchGfx *)ctx)->tcbl,10,((Wf2dmapTouchGfx *)ctx)->heapId,0);
    BMP_MENUWORK_DrawWindow(((Wf2dmapFriendListScreen *)p)->windowB,2,70,11);
    obj=((Wf2dmapFriendListScreen *)p)->windowB;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(obj));
    STRBUF_Delete(buf);
    WF2DMAP_TOUCH_SetScreenBrightness(0);
}

int Wf2dmapFriend_UpdatePrintStream(void *p, int *q)
{
    switch (PRINTSYS_PrintStreamGetState(p)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3)) PRINTSYS_PrintStreamShortWait(p, 0);
        *q = 0;
        break;
    case 1:
        if (*q == 0 && (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3))) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause(p);
            *q = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(p);
        *q = 0;
        return 0;
    }
    return 1;
}

int Wf2dmapFriend_CheckPrintStream(void *p,int *q,u8 *r) {if(Wf2dmapFriend_UpdatePrintStream(((Wf2dmapTouchGfx *)r)->printStream,(int *)(r+48))==0) {*q=0;return 1;}return 0;}

void Wf2dmapFriend_ResetListWindow(u8 *p, void *ctx) {void *q;WF2DMAP_TOUCH_SetScreenBrightness(1);BMP_MENUWORK_DrawWindowBorder(((Wf2dmapFriendListScreen *)p)->windowB,0);q=((Wf2dmapFriendListScreen *)p)->windowB;BMP_WIN_ClearScreen(q);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(q));}

int Wf2dmapFriend_HasFreeFriendSlot(int *p,u8 *q) {int i;void *v;if(*p==1) {v=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);for(i=0;i<32;i++) {if(WIFILIST_IsFriendDataValid(v,i)==0) return 1;}}else return 1;return 0;}

/*
 * leaf: sole unresolved overlay blocker of handed 021C76F8.
 */
void Wf2dmapFriend_InitItemScreen(u8 *p,u8 *q,u8 *ctx,u16 value)
{
    Wf2dmapFriend_InitItemWidgets(p,q,ctx,value);
}

/*
 * extent: 021C7AC4 is the eight-byte tail stub to 021C7D48.
 * calls: Wf2dmapEntryPos r0-r3 stay live into argumentless switch-arm calls.
 * Original explicit r1=ctx on 021C87B0/8850/8880 is retained even
 * where the callee reads only r0. All signed indexed reads are modular.
 */
/*
 * extent: 021C7AC4 is the eight-byte tail stub to 021C7D48.
 * calls: Entry r0-r3 stay live into argumentless switch-arm calls.
 * Original explicit r1=ctx on 021C87B0/8850/8880 is retained even
 * where the callee reads only r0. All signed indexed reads are modular.
 */
int Wf2dmapFriend_ItemScreenMain(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    int idx;
    u32 base;
    switch(q[8]) {
    case 0:
        *(u16 *)&((Wf2dmapFriendItemScreen *)p)->page=0; ((Wf2dmapFriendItemScreen *)p)->prevPage=0; *(u16 *)&((Wf2dmapFriendItemScreen *)p)->cursor=0; ((Wf2dmapFriendItemScreen *)p)->prevCursor=0;
    case 1:
        Wf2dmapFriend_InitItemScreen(p,q,ctx,52);
        Wf2dmapFriend_BuildEntryList((char *)q);
        Wf2dmapFriend_SetupItemScreen(p,q,ctx,heap);
        q[8]=2;
        break;
    case 2:
        BLINK_PALANM_Update(((Wf2dmapTouchGfx *)ctx)->palAnimA);
        BLINK_PALANM_Update(((Wf2dmapTouchGfx *)ctx)->palAnimB);
        switch(Wf2dmapFriend_ItemInput((s16 *)p,q,ctx)) {
        case 0: break;
        case 1:
            Wf2dmapFriend_SetEntryAnim(p,q,2);
            WF2DMAP_TOUCH_SetActorAnimSeq((char *)p,((Wf2dmapFriendItemScreen *)p)->page);
            BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)ctx)->palAnimB);
            BLINK_PALANM_Update(((Wf2dmapTouchGfx *)ctx)->palAnimB);
            break;
        case 2:
            Wf2dmapFriend_SetEntryAnim(p,q,3);
            WF2DMAP_TOUCH_SetActorAnimSeq((char *)p,((Wf2dmapFriendItemScreen *)p)->page);
            BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)ctx)->palAnimB);
            BLINK_PALANM_Update(((Wf2dmapTouchGfx *)ctx)->palAnimB);
            break;
        case 3: q[8]=25; break;
        case 4: q[8]=26; break;
        case 5: q[8]=6; break;
        }
        break;
    case 3: Wf2dmapFriend_StartItemOpen(p,q,ctx,heap); q[8]=4; break;
    case 4: if(Wf2dmapFriend_StepItemOpen(p,q,ctx,heap)==1) q[8]=5; break;
    case 5: if(Wf2dmapFriend_WaitItemOpen(p,ctx)==1) q[8]=2; break;
    case 6:
        if(WF2DMAP_TOUCH_StepItemBarBlink((char *)p)!=1) {
            Wf2dmapFriend_SetIndex((char *)q,Wf2dmapFriend_GetEntryIndex((s16 *)p));
            Wf2dmapFriend_PrintEntryInfo((s16 *)p,q,ctx,heap); q[8]=7;
        }
        break;
    case 7:
        if(Wf2dmapFriend_CheckEntryPrintStream(p,(int *)q,ctx)==1) {Wf2dmapFriend_OpenEntryMenu(p,q,ctx,heap);q[8]=8;}
        break;
    case 8: q[8]=Wf2dmapFriend_UpdateEntryMenu(p,(int *)q,ctx); break;
    case 9: ((Wf2dmapFriendItemScreen *)p)->countdown=8; q[8]=10; break;
    case 10:
        (((Wf2dmapFriendItemScreen *)p)->countdown)--;
        if(((Wf2dmapFriendItemScreen *)p)->countdown<=0) {
            Wf2dmapFriend_ClearItemScreens(p,q,ctx);Wf2dmapFriend_SetState(q,4,0);Wf2dmapFriend_DeleteItemScreen(p,q,ctx);return 1;
        }
        break;
    case 11:
        ((Wf2dmapFriendItemScreen *)p)->page=((Wf2dmapTouchFriendData *)q)->index/8;
        ((Wf2dmapFriendItemScreen *)p)->cursor=((Wf2dmapTouchFriendData *)q)->index%8;
        q[8]=1;
        break;
    case 12:
        WIPE_SYS_Start(0,0,0,0,6,1,heap);
        idx=Wf2dmapFriend_GetEntryIndex((s16 *)p);
        base=(u32)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
        Wf2dmapFriend_SetNameEntry((char *)q,(int)WIFILIST_GetFriendInfo((void *)base,*(u8 *)((u32)q+(u32)idx+24)));
        q[8]=13;
        break;
    case 13:
        if(WIPE_SYS_EndCheck()!=0) {
            Wf2dmapFriend_ClearItemScreens(p,q,ctx);Wf2dmapFriend_SetState(q,2,4);Wf2dmapFriend_DeleteItemScreen(p,q,ctx);return 1;
        }
        break;
    case 14:
        idx=Wf2dmapFriend_GetEntryIndex((s16 *)p);
        base=(u32)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
        WIFILIST_StoreFriendNameFromStrbuf((void *)base,*(u8 *)((u32)q+(u32)idx+24),((Wf2dmapTouchFriendData *)q)->textBufA);
    case 15:
        Wf2dmapFriend_InitItemScreen(p,q,ctx,52);Wf2dmapFriend_SetupItemScreen(p,q,ctx,heap);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);q[8]=16;
        break;
    case 16: if(WIPE_SYS_EndCheck()!=0) q[8]=2; break;
    case 17: Wf2dmapFriend_PrintEntryName((s16 *)p,q,ctx,heap);q[8]=18;break;
    case 18: if(Wf2dmapFriend_OpenConfirmMenu(p,(int *)q,ctx,heap)==1) q[8]=19;break;
    case 19:
        switch(Wf2dmapFriend_UpdateMenu(((Wf2dmapFriendItemScreen *)p)->taskMenu)) {
        case 0:
            ((Wf2dmapTouchFriendData *)q)->textSpeed=UI_GetInputMode();Wf2dmapFriend_ShowEntryDetail((char *)p,(char *)ctx);q[8]=20;break;
        case 1:
            ((Wf2dmapTouchFriendData *)q)->textSpeed=UI_GetInputMode();Wf2dmapFriend_ShowEntryDetail((char *)p,(char *)ctx);q[8]=2;break;
        }
        break;
    case 20: Wf2dmapFriend_ShowEntryActor(p,ctx);q[8]=21;break;
    case 21:
        if(Wf2dmapFriend_StepEntryActor(p,ctx)==1) {
            base=(u32)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
            idx=Wf2dmapFriend_GetEntryIndex((s16 *)p);
            WIFILIST_RemoveFriendSlot((void *)base,*(u8 *)((u32)q+(u32)idx+24));
            Wf2dmapFriend_BuildEntryList((char *)q);
            Wf2dmapFriend_DrawEntry(p,q,ctx,((Wf2dmapFriendItemScreen *)p)->page,((Wf2dmapFriendItemScreen *)p)->cursor,0,heap);q[8]=22;
        }
        break;
    case 22: Wf2dmapFriend_HideEntryActor(p,ctx);q[8]=2;break;
    case 23:
        if(Wf2dmapFriend_ShowEntryFriendCode(p,q,ctx,heap)==1) q[8]=24;
        else q[8]=2;
        break;
    case 24:
        if(Wf2dmapFriend_CheckEntryPrintStream(p,(int *)q,ctx)!=0 && WF2DMAP_TOUCH_GetConfirmInput((int *)q)==1) {q[8]=2;Wf2dmapFriend_ShowEntryDetail((char *)p,(char *)ctx);}
        break;
    case 25:
        if(CLACT_IsActorAnimActive(((Wf2dmapTouchGfx *)ctx)->actorA)!=1) {
            Wf2dmapFriend_ClearItemScreens(p,q,ctx);Wf2dmapFriend_SetState(q,0,2);Wf2dmapFriend_DeleteItemScreen(p,q,ctx);return 1;
        }
        break;
    case 26: if(CLACT_IsActorAnimActive(((Wf2dmapTouchGfx *)ctx)->actorB)!=1) q[8]=27;break;
    case 27: WIPE_SYS_Start(0,0,0,0,6,1,heap);q[8]=28;break;
    case 28:
        if(WIPE_SYS_EndCheck()!=0) {Wf2dmapFriend_SetState(q,6,0);Wf2dmapFriend_DeleteItemScreen(p,q,ctx);return 1;}
        break;
    }
    return 0;
}

void Wf2dmapFriend_DeleteItemScreen(u8 *p,u8 *q,u8 *ctx) {Wf2dmapFriend_DeleteItemWidgets(p,q,ctx);}

static inline int iabs(int v)
{
    return v < 0 ? -v : v;
}

void Wf2dmapFriend_InitItemWidgets(u8 *p, void *unused, u8 *ctx, u16 heap)
{
    int i;
    int j;
    struct ActorInitParam r1;
    struct ActorInitParam r2;
    for (i = 0; i < 2; i++) {
        Wf2dmapFriend_CreateWindow(ctx, (u32 *)(p + 0xf0 + i * 8), 3,
            (u8)(iabs(gWf2dmapEntryPositions[i].x) + 4), (u8)(iabs(gWf2dmapEntryPositions[i].y) + 4), 0x1a, 0x11, 0xa, 0, 0);
    }
    for (j = 0; j < 3; j++)
        Wf2dmapFriend_CopyPos((u16 *)(p + 12 + j * 0x4c), (u16 *)ctx, (u16 *)((const void *)&gWf2dmapEntryPositions[j]), 0, heap);
    *(u8 **)(p + 0x14) = p + 0xf0;
    *(u8 **)(p + 0xac) = p + 0xf8;
    *(u8 **)(p + 0x60) = p + 0xf8;
    *(void **)(p + 0x104) = WIFI_2DCHAR_Create(*(void **)(ctx + 0x13c), 0, 0x10, heap);
    WIFI_2DCHAR_SetupCells(*(u8 **)(p + 0x104), 0, 2, 0xe0, heap);
    for (i = 0; i < 4; i++) {
        const W2 *e = &gWf2dmapItemMsgIds[i];
        *(void **)(p + i * 12 + 0x118) = MSGDATA_AllocString(*(struct MsgBank **)(ctx + 4), gWf2dmapItemMsgIds[i].a);
        *(u16 *)(p + i * 12 + 0x11c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x120) = 0;
        *(void **)(p + i * 12 + 0x148) = MSGDATA_AllocString(*(struct MsgBank **)(ctx + 4), e[4].a);
        *(u16 *)(p + i * 12 + 0x14c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x150) = 0;
    }
    *(u32 *)(p + 0x144) = 1;
    *(u32 *)(p + 0x174) = 1;
    *(void **)(p + 0x178) = MSGDATA_AllocString(*(struct MsgBank **)(ctx + 4), 0x42);
    *(u16 *)(p + 0x17c) = 0x39e3;
    *(u32 *)(p + 0x180) = 0;
    *(void **)(p + 0x184) = MSGDATA_AllocString(*(struct MsgBank **)(ctx + 4), 0x43);
    *(u16 *)(p + 0x188) = 0x39e3;
    *(u32 *)(p + 0x18c) = 0;
    *(struct TaskMenuRes **)(p + 0x190) = APP_TASKMENU_RES_Create(1, 14, (struct GFont *)(*(u32 *)(ctx + 0x17c)), (struct PrintQueue *)(*(u32 *)(ctx + 0x34)), heap);
    Wf2dmapFriend_CreateWindow(ctx, (u32 *)(p + 0x108), 1, 2, 1, 0x1b, 4, 0xa, 0, 0xf);
    *(struct U16Vec **)(p + 0x110) = (struct U16Vec *)STRBUF_Create(0x80, heap);
    r1 = gWf2dmapEntryActorRectA;
    ((Wf2dmapFriendItemScreen *)p)->actor = CLACT_CreateActor(((Wf2dmapTouchGfx *)ctx)->actorBank, ((Wf2dmapTouchGfx *)ctx)->character[0], ((Wf2dmapTouchGfx *)ctx)->palette[0], ((Wf2dmapTouchGfx *)ctx)->cellAnim[0], &r1, 0, heap);
    CLACT_SetActorDrawEnable(((Wf2dmapFriendItemScreen *)p)->actor, 0);
    r2 = gWf2dmapEntryActorRectB;
    ((Wf2dmapFriendItemScreen *)p)->actor2 = CLACT_CreateActor(((Wf2dmapTouchGfx *)ctx)->actorBank, ((Wf2dmapTouchGfx *)ctx)->character[0], ((Wf2dmapTouchGfx *)ctx)->palette[0], ((Wf2dmapTouchGfx *)ctx)->cellAnim[0], &r2, 0, heap);
}

void Wf2dmapFriend_DeleteItemWidgets(u8 *p, void *unused, u8 *a)
{
    int i;
    int offset;
    WF2DMAP_TOUCH_ClearSlotArray((char *)a);
    WF2DMAP_TOUCH_AddSlot((char *)a,a + 12);
    CLACT_DeleteActor(((Wf2dmapFriendItemScreen *)p)->actor2);
    CLACT_DeleteActor(((Wf2dmapFriendItemScreen *)p)->actor);
    BMP_WIN_Delete(((Wf2dmapFriendItemScreen *)p)->window);
    STRBUF_Delete(((Wf2dmapFriendItemScreen *)p)->strbuf);
    APP_TASKMENU_RES_Delete(((Wf2dmapFriendItemScreen *)p)->menu);
    STRBUF_Delete(((Wf2dmapFriendItemScreen *)p)->textA);
    STRBUF_Delete(((Wf2dmapFriendItemScreen *)p)->textB);
    offset=0x1a4;
    i=0;
    offset=0x118;
    for (; i < 4; i++) {
        STRBUF_Delete(*(void **)(p + i * 12 + offset));
        STRBUF_Delete(*(void **)(p + i * 12 + 0x148));
    }
    WIFI_2DCHAR_ReleaseBmpCells(((Wf2dmapFriendItemScreen *)p)->wifiActor);
    WIFI_2DCHAR_Delete(*(u8 * *)&((Wf2dmapFriendItemScreen *)p)->wifiActor);
    for(i=0;i<3;i++) Wf2dmapFriend_NoopC(p + 12 + i * 0x4c,a);
    for(i=0;i<2;i++) BMP_WIN_Delete(*(void **)(p + i * 8 + 0xf0));
}

void Wf2dmapFriend_SetupItemScreen(u8 *p,u8 *q,u8 *r,u16 heap) {Wf2dmapFriend_DrawText(r,r+12,5);BG_SYS_MarkTileDirty(0);Wf2dmapFriend_DrawEntry(p,q,r,((Wf2dmapFriendItemScreen *)p)->page,((Wf2dmapFriendItemScreen *)p)->cursor,0,heap);}

void Wf2dmapFriend_ClearItemScreens(u8 *p,void *q,u8 *r) {int i;Wf2dmapFriend_ClearWindow(r);for(i=0;i<3;i++)Wf2dmapFriend_ClearEntryPage((char *)(p+12+i*76),r,r+364);BG_SYS_MarkTileDirty(0);}

int Wf2dmapFriend_ItemSelect(s16 *p, u8 *a, void *b, int n)
{
    if (n == 0) {
        GFL_USE_PlaySeDefaultVolume(0x551); WF2DMAP_TOUCH_PlayActorAnimA(b); return 3;
    }
    if (n == 6) {
        GFL_USE_PlaySeDefaultVolume(0x556); WF2DMAP_TOUCH_PlayActorAnimB(b); return 4;
    }
    if (n == 5) {
        if (p[2] == 8) { GFL_USE_PlaySeDefaultVolume(0x551); WF2DMAP_TOUCH_PlayActorAnimA(b); return 3; }
        if (p[2] == 9) { GFL_USE_PlaySeDefaultVolume(0x556); WF2DMAP_TOUCH_PlayActorAnimB(b); return 4; }
        if (((Wf2dmapTouchFriendData *)a)->count <= (unsigned int)(p[2] + p[0] * 8)) return 0;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        p[4] = 0;
        return 5;
    }
    if (n == 1) return 1;
    return n == 2 ? 2 : 0;
}

int Wf2dmapFriend_ItemKeyInput(s16 *p, u8 *a, u8 *ctx)
{
    u16 old;
    int moved;
    int page;
    int dir;
    if(KEY_GetTrg() & 2) {
        UI_SetInputMode(0);
        ((Wf2dmapTouchFriendData *)a)->textSpeed=0;
        return Wf2dmapFriend_ItemSelect(p,a,ctx,0);
    }
    if(KEY_GetTrg() & 1024) {
        UI_SetInputMode(0);
        ((Wf2dmapTouchFriendData *)a)->textSpeed=0;
        return Wf2dmapFriend_ItemSelect(p,a,ctx,6);
    }
    if(((Wf2dmapTouchFriendData *)a)->textSpeed==1) {
        if(KEY_GetTrg() & 0xcf3) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetItemHighlight(ctx,p[2],p[2]);
            UI_SetInputMode(0);
            ((Wf2dmapTouchFriendData *)a)->textSpeed=0;
        }
        return 0;
    }
    if(KEY_GetTrg() & 1) return Wf2dmapFriend_ItemSelect(p,a,ctx,5);
    old=p[2];
    moved=0;
    page=0;
    if(KEY_GetRepeat() & 64) {
        if(p[2]==0) p[2]=3;
        else if(p[2]==4) p[2]=7;
        else --p[2];
        moved=1;
    } else if(KEY_GetRepeat() & 128) {
        if(p[2]==3) p[2]=0;
        else if(p[2]==7) p[2]=4;
        else ++p[2];
        moved=1;
    } else if(KEY_GetRepeat() & 32) {
        if(p[2]<4) {
            p[2]+=4;
            page=1;
            dir=0;
        } else p[2]-=4;
        moved=1;
    } else if(KEY_GetRepeat() & 16) {
        if(p[2]<4) p[2]+=4;
        else {
            p[2]-=4;
            page=1;
            dir=1;
        }
        moved=1;
    } else if(a[14]) {
        if(a[14] && (KEY_GetRepeat() & 512)) {
            page=1;
            dir=0;
        } else if(a[14] && (KEY_GetRepeat() & 256)) {
            page=1;
            dir=1;
        }
    }
    if(page==1) {
        if(dir) {
            p[1]=p[0];
            p[0]=(p[0]+1)%4;
            return Wf2dmapFriend_ItemSelect(p,a,ctx,2);
        } else {
            p[1]=p[0];
            --p[0];
            if(p[0]<0) p[0]+=4;
            return Wf2dmapFriend_ItemSelect(p,a,ctx,1);
        }
    }
    if(moved==1) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WF2DMAP_TOUCH_SetItemHighlight(ctx,p[2],old);
        p[3]=old;
    }
    return 0;
}

int Wf2dmapFriend_ItemTouchInput(s16 *p, void *a, void *b, int *changed)
{
    u32 v = TOUCHPANEL_HitTrg((const TouchHitTable *)gWf2dmapItemHitRects);
    s8 delta;
    if (v == (u32)-1) return 0;
    if (v <= 7) {
        *changed = 1;
        WF2DMAP_TOUCH_SetItemHighlight1(b, p[2]);
        p[2] = v;
        return Wf2dmapFriend_ItemSelect(p, a, b, 5);
    }
    if (v == 8) {
        *changed = 1;
        p[2] = v;
        return Wf2dmapFriend_ItemSelect(p, a, b, 5);
    }
    if (v == 9) {
        *changed = 1;
        p[2] = v;
        return Wf2dmapFriend_ItemSelect(p, a, b, 5);
    }
    delta = (v - 10) - p[0];
    if (delta != 0) {
        *changed = 1;
        p[1] = p[0];
        p[0] += delta;
        if (delta >= 0) {
            p[0] %= 4;
            return Wf2dmapFriend_ItemSelect(p, a, b, 2);
        } else {
            if (p[0] < 0) p[0] += 4;
            return Wf2dmapFriend_ItemSelect(p, a, b, 1);
        }
    }
    return 0;
}

int Wf2dmapFriend_ItemInput(s16 *p,u8 *q,u8 *r) {int changed=0;int ret=Wf2dmapFriend_ItemTouchInput(p,q,r,&changed);if(changed) {UI_SetInputMode(1);((Wf2dmapTouchFriendData *)q)->textSpeed=1;return ret;}return Wf2dmapFriend_ItemKeyInput(p,q,r);}

void Wf2dmapFriend_StartItemOpen(u8 *p, void *a, u8 *b, u16 c)
{
    int n = ((Wf2dmapFriendItemScreen *)p)->openMode == 2 ? 2 : 1;
    Wf2dmapFriend_DrawEntry(p, a, b, ((Wf2dmapFriendItemScreen *)p)->page, ((Wf2dmapFriendItemScreen *)p)->cursor, n, c);
    WF2DMAP_TOUCH_SetItemHighlight1(b, ((Wf2dmapFriendItemScreen *)p)->cursor);
    GFL_USE_PlaySeDefaultVolume(0x548);
}

/*
 * lever: Two names reproduce the duplicate 0x021CA7C0 pool words; the
 * mutable config declaration preserves sequential halfword loads/stores.
 */
int Wf2dmapFriend_StepItemOpen(u8 *p, u8 *a, u8 *b, u16 h)
{
    struct ClactVec2 pos;
    int delta;
    Callback cb;
    int mode;
    if (PRINTSYS_QUE_IsFinished(((Wf2dmapTouchGfx *)b)->printWin) == 0) return 0;
    if (((Wf2dmapFriendItemScreen *)p)->openCounter > 24) {
        pos.x = gWf2dmapOpenAnimConfig.pos.x;
        pos.y = gWf2dmapOpenAnimConfig.pos.y;
        CLACT_SetSurfacePos(((Wf2dmapTouchGfx *)b)->renderer, 0, &pos);
        mode = ((Wf2dmapFriendItemScreen *)p)->openMode == 2 ? 2 : 1;
        Wf2dmapFriend_DeleteEntryActors((char *)(p + 12 + mode * 76), (int)b);
        Wf2dmapFriend_DrawEntryOpen(p, a, b, ((Wf2dmapFriendItemScreen *)p)->page, ((Wf2dmapFriendItemScreen *)p)->cursor, h);
        return 1;
    }
    delta = (((Wf2dmapFriendItemScreen *)p)->openCounter * 256) / 24;
    if (((Wf2dmapFriendItemScreen *)p)->openMode == 2) delta = -delta;
    BG_SYS_ChangeScroll(2, 0, delta);
    BG_SYS_ChangeScroll(3, 0, delta);
    pos.x = gWf2dmapOpenAnimConfig.pos.x;
    pos.y = gWf2dmapOpenAnimConfig.pos.y;
    pos.x += (s16)delta;
    CLACT_SetSurfacePos(((Wf2dmapTouchGfx *)b)->renderer, 0, &pos);
    mode = ((Wf2dmapFriendItemScreen *)p)->openCounter;
    if (mode % 6 != 0) {
        cb = gWf2dmapOpenAnimCallbacks[mode / 6];
        if (cb != 0) cb(p, b, ((Wf2dmapFriendItemScreen *)p)->page, *(s16 *)&((Wf2dmapFriendItemScreen *)p)->prevPage);
    }
    (((Wf2dmapFriendItemScreen *)p)->openCounter)++;
    return 0;
}

/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int Wf2dmapFriend_WaitItemOpen(u8 *p,u8 *q) {if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(const struct PrintSys * *)&((Wf2dmapTouchGfx *)q)->printWin))==1) {BG_SYS_ChangeScroll(2,0,0);BG_SYS_ChangeScroll(3,0,0);WF2DMAP_TOUCH_TransferScreen(**(char ** *)&((Wf2dmapFriendItemScreen *)p)->pages[0].window);return 1;}return 0;}

unsigned long long Wf2dmapFriend_GetEntryFriendKey(s16 *p,u8 *q) {struct WifiList *base;base=(struct WifiList *)GAME_DATA_GetWifiList((struct GameData *)(*(const struct BigObj * *)&((Wf2dmapTouchFriendData *)q)->saveData));return DWC_GetFriendKey(WIFILIST_GetDwcFriendData(base,*(u8 *)(q+24+Wf2dmapFriend_GetEntryIndex(p))));}

void Wf2dmapFriend_PrintEntryInfo(s16 *p,u8 *q,u8 *r,u16 heap) {Wf2dmapFriend_PrintMyStatus(r,q,*(u8 *)(q+24+Wf2dmapFriend_GetEntryIndex(p)),heap);Wf2dmapFriend_PrintEntryMessage((u8 *)p,r,12,heap);}

void Wf2dmapFriend_OpenEntryMenu(u8 *p, u8 *a, void *unused, int heap)
{
    Wf2dmapEntryMenuConfig config;
    void *q = (void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)a)->saveData);
    int result = WIFILIST_GetFriendInfoField(q, (a + Wf2dmapFriend_GetEntryIndex((s16 *)p))[24], 9);
    config.heap = heap;
    config.count = 4;
    if (result == 2) {
        config.entries = p + (Wf2dmapFriend_GetEntryFriendKey((s16 *)p, a) != 0 ? 0x148 : 0x118);
        ((Wf2dmapFriendItemScreen *)p)->menuFlag = 1;
    } else {
        config.entries = p + 0x118;
        ((Wf2dmapFriendItemScreen *)p)->menuFlag = 0;
    }
    config.mode = 1;
    config.x = 32; config.y = 24; config.a = 17; config.b = 3;
    ((Wf2dmapFriendItemScreen *)p)->taskMenu = APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&config), ((Wf2dmapFriendItemScreen *)p)->menu);
}

int Wf2dmapFriend_UpdateEntryMenu(u8 *p, int *a, void *b)
{
    int n;
    int result;
    APP_TASKMENU_UpdateMenu(((Wf2dmapFriendItemScreen *)p)->taskMenu);
    if (APP_TASKMENU_IsFinish(((Wf2dmapFriendItemScreen *)p)->taskMenu) == 1) {
        n = APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(*(u8 * *)&((Wf2dmapFriendItemScreen *)p)->taskMenu));
        APP_TASKMENU_CloseMenu(((Wf2dmapFriendItemScreen *)p)->taskMenu);
    } else return 8;
    if (n == 3) {
        *a = UI_GetInputMode();
        result = 2;
    } else {
        *a = UI_GetInputMode();
        result = gWf2dmapEntryMenuResultTable[((Wf2dmapFriendItemScreen *)p)->menuFlag][n * 2];
    }
    if (result == 2) Wf2dmapFriend_ShowEntryDetail((char *)p, b);
    else if (result == 9 || result == 12) Wf2dmapFriend_ShowEntryDetail((char *)p, b);
    else Wf2dmapFriend_ClearEntryWindow((char *)p);
    return result;
}

int Wf2dmapFriend_ShowEntryFriendCode(u8 *p, u8 *a, u8 *b, int c)
{
    u64 value = Wf2dmapFriend_GetEntryFriendKey((s16 *)p, a);
    Wf2dmapFriend_PrintMyStatus(b, a, (a + Wf2dmapFriend_GetEntryIndex((s16 *)p))[0x18], c);
    if (value != 0) {
        Wf2dmapFriend_SetFriendCode((void **)b, value);
        Wf2dmapFriend_PrintEntryMessage(p, b, 0x3c, c);
    } else {
        Wf2dmapFriend_PrintEntryMessage(p, b, 0x44, c);
    }
    return 1;
}

void Wf2dmapFriend_PrintEntryName(s16 *p,u8 *q,u8 *r,u16 heap) {Wf2dmapFriend_PrintMyStatus(r,q,*(u8 *)(q+24+Wf2dmapFriend_GetEntryIndex(p)),heap);Wf2dmapFriend_PrintEntryMessage((u8 *)p,r,57,heap);}

int Wf2dmapFriend_OpenConfirmMenu(u8 *p,int *q,u8 *r,int heap) {if(Wf2dmapFriend_CheckEntryPrintStream(p,q,r)==0)return 0;((Wf2dmapFriendItemScreen *)p)->taskMenu=Wf2dmapFriend_OpenMenu(p+376,(void **)(p+400),0,heap);return 1;}

void Wf2dmapFriend_DrawEntry(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c)
{
    int offset;
    u8 *base;
    if (n == 0) {
        ((Wf2dmapFriendItemScreen *)p)->page = x;
        ((Wf2dmapFriendItemScreen *)p)->cursor = y;
        WF2DMAP_TOUCH_SetActorAnimSeq((char *)p, x);
    }
    offset = n * 0x4c;
    base = p + 12;
    Wf2dmapFriend_DrawEntryBg((s16 *)(base + offset), b, b + 0x16c);
    Wf2dmapFriend_DrawEntryPageTransfer((char *)(base + offset), (char *)a, b, ((Wf2dmapFriendItemScreen *)p)->wifiActor, (int)(b + 0x16c), (char *)(a + 16), x, c);
    WF2DMAP_TOUCH_UpdateItemBar((char *)p);
}

void Wf2dmapFriend_DrawEntryOpen(u8 *p, u8 *a, u8 *b, int x, int y, u16 c)
{
    ((Wf2dmapFriendItemScreen *)p)->cursor = y;
    ((Wf2dmapFriendItemScreen *)p)->page = x;
    WF2DMAP_TOUCH_SetActorAnimSeq((char *)p, x);
    Wf2dmapFriend_DrawEntryBg((s16 *)(p + 12), b, b + 0x16c);
    Wf2dmapFriend_DrawEntryPage((char *)(p + 12), (char *)a, b, ((Wf2dmapFriendItemScreen *)p)->wifiActor, (int)(b + 0x16c), (char *)(a + 16), x, c);
    WF2DMAP_TOUCH_UpdateItemBar((char *)p);
}

void Wf2dmapFriend_NoopA(void) {}

void Wf2dmapFriend_NoopB(void) {}

void Wf2dmapFriend_SetEntryAnim(u8 *p, u8 *a, int n)
{
    a[8] = 3;
    ((Wf2dmapFriendItemScreen *)p)->openMode = n;
    ((Wf2dmapFriendItemScreen *)p)->openCounter = 0;
}

void Wf2dmapFriend_PrintEntryMessage(u8 *p, u8 *a, int n, int heap)
{
    void *text;
    void *q;
    if (((Wf2dmapTouchGfx *)a)->printStream) {
        PRINTSYS_PrintStreamDelete(((Wf2dmapTouchGfx *)a)->printStream);
        ((Wf2dmapTouchGfx *)a)->printStream = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((Wf2dmapFriendItemScreen *)p)->window),15);
    text=STRBUF_Create(128,heap);
    MSGDATA_ReadString(((Wf2dmapTouchGfx *)a)->msgBank,n,text);
    WORDSET_CopyTaggedText(((Wf2dmapTouchGfx *)a)->wordSet,((Wf2dmapFriendItemScreen *)p)->strbuf,text);
    ((Wf2dmapTouchGfx *)a)->printStream=PRINTSYS_PrintStream(((Wf2dmapFriendItemScreen *)p)->window,0,0,((Wf2dmapFriendItemScreen *)p)->strbuf,((Wf2dmapTouchGfx *)a)->palWin,MSG_SPEED_GetWait(),((Wf2dmapTouchGfx *)a)->tcbl,10,((Wf2dmapTouchGfx *)a)->heapId,0);
    BMP_MENUWORK_DrawWindow(((Wf2dmapFriendItemScreen *)p)->window,2,70,11);
    q=((Wf2dmapFriendItemScreen *)p)->window;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(q));
    STRBUF_Delete(text);
    WF2DMAP_TOUCH_SetScreenBrightness(0);
}

int Wf2dmapFriend_CheckEntryPrintStream(void *p,int *state,u8 *q) {if(Wf2dmapFriend_UpdatePrintStream(((Wf2dmapTouchGfx *)q)->printStream,(int *)(q+48))==0) {*state=0;return 1;}return 0;}

void Wf2dmapFriend_ShowEntryDetail(char *p,char *q) {BMP_MENUWORK_DrawWindowBorder(((Wf2dmapFriendItemScreen *)p)->window,1);WF2DMAP_TOUCH_MakeScreen(q);WF2DMAP_TOUCH_UpdateItemBar(p);WF2DMAP_TOUCH_SetScreenBrightness(1);}

void Wf2dmapFriend_ClearEntryWindow(char *p)
{
    BMP_Clear(BMP_WIN_GetBmp(((Wf2dmapFriendItemScreen *)p)->window), 0xf);
    BMP_WIN_TransferChars(((Wf2dmapFriendItemScreen *)p)->window);
}

int Wf2dmapFriend_GetEntryIndex(s16 *p)
{
    int a = p[0] * 8;

    return a + p[2];
}

static inline void Outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400004A & ~0x3F) | wnd;
    if(effect) tmp |= 0x20;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}

/*
 * volatile: 021C8808, 021C8814 read WINOUT; 021C8828 reads DISPCNT.
 */
void Wf2dmapFriend_ShowEntryActor(u8 *p, u8 *unused)
{
    struct ClactVec2 pos;
    CLACT_SetActorDrawEnable(((Wf2dmapFriendItemScreen *)p)->actor,1);
    CLACT_SetActorAnimSeq(((Wf2dmapFriendItemScreen *)p)->actor,1);
    CLACT_RestartActorAnim(((Wf2dmapFriendItemScreen *)p)->actor);
    *(int *)&((Wf2dmapFriendItemScreen *)p)->animFrame=0;
    CLACT_SetActorAutoAnim(((Wf2dmapFriendItemScreen *)p)->actor,1);
    pos.x=gWf2dmapEntrySlotPos[*(s16 *)(p + 4)].x * 8;
    pos.y=gWf2dmapEntrySlotPos[*(s16 *)(p + 4)].y * 8 - 4;
    CLACT_AddActorSurfacePos(((Wf2dmapFriendItemScreen *)p)->actor,&pos,0);
    *(volatile u16 *)0x0400004A=(u16)((*(volatile u16 *)0x0400004A & ~0x3F00) | 0x700);
    Outside(31,1);
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0xe000) | 0x8000;
    GFL_USE_PlaySeDefaultVolume(0x668);
}

int Wf2dmapFriend_StepEntryActor(u8 *p, u8 *unused) {u32 n;if(CLACT_IsActorAnimActive(((Wf2dmapFriendItemScreen *)p)->actor)==0)return 1;n=CLACT_GetActorAnimFrame(((Wf2dmapFriendItemScreen *)p)->actor);if(n-((Wf2dmapFriendItemScreen *)p)->animFrame>=2) ((Wf2dmapFriendItemScreen *)p)->animFrame=n;return 0;}

/*
 * volatile: display control MMIO 0x04000000 read/write at 021C888A and 021C8892.
 */
void Wf2dmapFriend_HideEntryActor(u8 *p, u8 *unused) {*(volatile u32 *)0x04000000 &= ~0xe000u;CLACT_SetActorDrawEnable(((Wf2dmapFriendItemScreen *)p)->actor,0);CLACT_SetActorAutoAnim(((Wf2dmapFriendItemScreen *)p)->actor,0);}

void Wf2dmapFriend_CopyPos(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void Wf2dmapFriend_NoopC(void *unused0, void *unused1) {}

void Wf2dmapFriend_DrawEntryBg(s16 *p, void *unused, u8 *q)
{
    int y = p[1];
    int x;
    u16 *t;
    if (y < 0) y = -y;
    x = p[0];
    if (x < 0) x = -x;
    t = *(u16 * *)&((Wf2dmapTouchBmp *)q)->desc[0];
    BG_SYS_DrawTile((int)2, ((u8 *)t + 12), (u8)x, (u8)y, (t[0] >> 3) & 255, (t[1] >> 3) & 255);
    BG_SYS_MarkTileDirty(2);
}

void Wf2dmapFriend_DrawEntryPage(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {
 int i;int offset;void *base;int found;char *row;void *v;
 base=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
 v=BMP_WIN_GetBmp(**(void ** *)&((Wf2dmapFriendEntryPage *)p)->window);
 found=0;
 BMP_Clear(v,0);
 Wf2dmapFriend_DeleteEntryActors(p,(int)r);
 offset=page*8;i=0;row=table+offset;
 for(;i<8;i++) {
  if(((Wf2dmapFriendEntryTable *)table)->count > offset+i) {
   Wf2dmapFriend_DrawEntrySlot((u8 *)p,s,r,t,i,base,(u8)row[i+8],heap);found=1;
  } else Wf2dmapFriend_CreateEntryActor(p,r,t,i,heap);
 }
 if(!found)BMP_WIN_TransferChars(**(void ** *)&((Wf2dmapFriendEntryPage *)p)->window);
}

void Wf2dmapFriend_DrawEntryPageTransfer(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {Wf2dmapFriend_DrawEntryPage(p,q,r,s,t,table,page,heap);WF2DMAP_TOUCH_TransferScreen(**(char ** *)&((Wf2dmapFriendEntryPage *)p)->window);}

static inline int ab(int v) {return v<0?-v:v;}

/*
 * extent: trailing two-byte zero padding at 0x021C8A4E; next label 0x021C8A50.
 */
void Wf2dmapFriend_ClearEntryPage(char *p, void *unusedArg, void *unused) {
 void *v;
 Wf2dmapFriend_DeleteEntryActors(p,(int)unusedArg);
 v=**(void ** *)&((Wf2dmapFriendEntryPage *)p)->window;BMP_WIN_ClearScreen(v);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(v));
 BG_SYS_SetTileEntry(2,0,ab(((Wf2dmapFriendEntryPage *)p)->x),ab(((Wf2dmapFriendEntryPage *)p)->y),p[4],p[5],0);
 BG_SYS_MarkTileDirty(2);
 BG_SYS_SetTileEntry(3,0,ab(((Wf2dmapFriendEntryPage *)p)->x),ab(((Wf2dmapFriendEntryPage *)p)->y),p[4],p[5],0);
 BG_SYS_MarkTileDirty(3);
}

void Wf2dmapFriend_DeleteEntryActors(char *p,int unused) {int i;char *q;for(i=0;i<8;i++) {q=p+i*4;if(((Wf2dmapFriendEntryPage *)q)->wifiActor[0]){WIFI_2DCHAR_DeleteActor(((Wf2dmapFriendEntryPage *)q)->wifiActor[0]);*(u32 *)&((Wf2dmapFriendEntryPage *)q)->wifiActor[0]=0;} if(((Wf2dmapFriendEntryPage *)q)->clactActor[0]){CLACT_DeleteActor(((Wf2dmapFriendEntryPage *)q)->clactActor[0]);*(u32 *)&((Wf2dmapFriendEntryPage *)q)->clactActor[0]=0;}}}

/*
 * lever: The colors and four-halfword position descriptor are fields of
 * one stack aggregate, fixing their 0x28 and 0x2E frame positions.
 * bounds: 02009864 field 9 reads the two-bit value at entry+0x2f,
 * so 3 also reads the initialized position halfword at aggregate+6.
 * heap: 021C8644 and 021C89B0 load the incoming heap as a halfword;
 * 021C8904 forwards that value to this eighth argument at 021C896A.
 */
void Wf2dmapFriend_DrawEntrySlot(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap)
{
    struct { u16 colors[3]; s16 pos[4]; } local;
    int result8, result9;
    void *str;
    local.colors[0] = 0x14c0;
    local.colors[1] = 0xc80;
    local.colors[2] = 0x440;
#ifdef __MWERKS__
    /* The original prototype returned int. */
    result8 = ((int (*)(void *, int, int))WIFILIST_GetFriendInfoField)(base, idx, 8);
#else
    result8 = WIFILIST_GetFriendInfoField(base, idx, 8);
#endif
    result9 = WIFILIST_GetFriendInfoField(base, idx, 9);
    if (result9 == 2) {
        Wf2dmapFriend_CreateEntryActor((char *)p, (char *)b, unused, i, heap);
    } else {
        local.pos[0] = (((Wf2dmapFriendEntryPage *)p)->x + gWf2dmapEntrySlotPos[i].x) * 8 + 8;
        local.pos[1] = (((Wf2dmapFriendEntryPage *)p)->y + gWf2dmapEntrySlotPos[i].y) * 8 + 10;
        local.pos[2] = 8;
        local.pos[3] = 1;
        *(void **)(p + 12 + (int)((u32)i * 4u)) = WIFI_2DCHAR_SpawnActor(a, local.pos, result8, heap);
        WIFI_2DCHAR_SetActorAnim(*(void **)(p + 12 + (int)((u32)i * 4u)), 0, 1);
    }
    str = STRBUF_Create(128, heap);
    STRBUF_SetString(str, (const u16 *)WIFILIST_GetFriendInfo(base, idx));
    TOUCHBAR_PrintAligned(*(TouchBarWindow * *)&((Wf2dmapFriendEntryPage *)p)->window, (void *)(((Wf2dmapTouchGfx *)b)->printWin), gWf2dmapEntrySlotPos[i].x * 8,
                 gWf2dmapEntrySlotPos[i].y * 8 - 24, (u32)str, ((Wf2dmapTouchGfx *)b)->palWinU32, *(u16 *)((u8 *)&local + result9 * 2), 0);
    STRBUF_Delete(str);
}

void Wf2dmapFriend_CreateEntryActor(char *p,char *q,int unused,int i,u16 h) {
 struct ActorInitParam pt;
 pt.x=(((Wf2dmapFriendEntryPage *)p)->x+gWf2dmapEntrySlotPos[i].x)*8+16;
 pt.y=(((Wf2dmapFriendEntryPage *)p)->y+gWf2dmapEntrySlotPos[i].y)*8+16;
 pt.anim_seq=0;pt.draw_priority=8;pt.bg_priority=1;
 *(void **)(p+44+i*4)=CLACT_CreateActor(((Wf2dmapTouchGfx *)q)->actorBank2,((Wf2dmapTouchGfx *)q)->character[0],((Wf2dmapTouchGfx *)q)->palette[0],((Wf2dmapTouchGfx *)q)->cellAnim[0],&pt,0,h);
}

/*
 * interface: 02031324 forwards heap to 02031354 and returns its node;
 * 02031348 forwards all four inputs to 020314F4 despite legacy void(void).
 * data: Process setup loads ov194/ov129 and receives their callback tables.
 */
int Wf2dmapFriend_NameEntryMain(void **p, u8 *a, u8 *b, void *unused, u16 heap)
{
    u32 sizes[3];
    switch (b[8]) {
    case 0:
        GF_OVERLAY_Unload((u32)gWf2dmapTouchbarOverlayId);
        p[1] = WF2DMAP_TOUCH_CreateNameEntry(p, (char *)b, 1, heap);
        sizes[0] = 4; sizes[1] = 4; sizes[2] = 4;
        p[2] = CODEIN_PARAM_Create(heap, 0, 0, 12, sizes);
        Wf2dmapFriend_Teardown(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push((ProcSys *)p[0], (u32)gWf2dmapNameEntryOverlayId, (const ProcData *)gNameInProcData, (void *)p[1]);
        b[8] = 1;
        break;
    case 1:
        if (PROCSYS_Main((ProcSys *)p[0]) == 0) {
            if (((NameInArgs *)p[1])->canceled == 0) {
                PROCSYS_Push((ProcSys *)p[0], (u32)gWf2dmapNameInOverlayId, (const ProcData *)d_021DA62C, (void *)p[2]);
                b[8] = 2;
            } else {
                PROCSYS_Delete(p[0]);
                Wf2dmapFriend_SetState(b, 0, 0);
                b[8] = 3;
            }
        }
        break;
    case 2:
        if (PROCSYS_Main(p[0]) == 0) {
            PROCSYS_Delete(p[0]);
            Wf2dmapFriend_CopyText(b, ((NameInArgs *)p[1])->name, ((NameInArgs *)p[2])->name);
            Wf2dmapFriend_SetState(b, 0, 7);
            b[8] = 3;
        }
        break;
    case 3:
        NAMEIN_SETUP_FreeArgs(p[1]);
        CODEIN_PARAM_Delete(p[2]);
        GF_OVERLAY_Load((u32)gWf2dmapTouchbarOverlayId);
        Wf2dmapFriend_Setup((char *)a, heap);
        return 1;
    case 4:
        GF_OVERLAY_Unload((u32)gWf2dmapTouchbarOverlayId);
        p[1] = WF2DMAP_TOUCH_CreateNameEntry(p, (char *)b, 0, heap);
        Wf2dmapFriend_Teardown(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push((ProcSys *)p[0], (u32)gWf2dmapNameEntryOverlayId, (const ProcData *)gNameInProcData, (void *)p[1]);
        b[8] = 5;
        break;
    case 5:
        if (PROCSYS_Main(p[0]) == 0) {
            PROCSYS_Delete(p[0]);
            *(int *)b = UI_GetInputMode();
            if (((NameInArgs *)p[1])->canceled == 0) {
                Wf2dmapFriend_SetState(b, 1, 14);
                Wf2dmapFriend_CopyText(b, ((NameInArgs *)p[1])->name, 0);
                b[8] = 6;
            } else {
                Wf2dmapFriend_SetState(b, 1, 15);
                b[8] = 6;
            }
        }
        break;
    case 6:
        NAMEIN_SETUP_FreeArgs(p[1]);
        GF_OVERLAY_Load((u32)gWf2dmapTouchbarOverlayId);
        Wf2dmapFriend_Setup((char *)a, heap);
        return 1;
    }
    return 0;
}
