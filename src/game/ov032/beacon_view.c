/*
 * file:     beacon_view.c
 * unit:     yes
 * function: BEACON_VIEW_InitList, BEACON_VIEW_UpdateListTouch, BEACON_VIEW_GetContTouchedRow, BEACON_VIEW_CheckLeaveRequest, BEACON_VIEW_ShowViewFlagMessage, BEACON_VIEW_ShowNextHistoryPower, BEACON_VIEW_LoadNextRecord, BEACON_VIEW_SetFadeState, BEACON_VIEW_ApplySlideTarget, BEACON_VIEW_SetPrintQueueLimit, BEACON_VIEW_UpdateRecordArrival, BEACON_VIEW_UpdatePowerAnimStart, BEACON_VIEW_UpdateSelect, BEACON_VIEW_UpdateSelectTouch, BEACON_VIEW_SetArrowAnim, BEACON_VIEW_IsArrowAnimActive, BEACON_VIEW_RefreshActorAnims, BEACON_VIEW_CountDifferingRecords, BEACON_VIEW_UpdateAchievements, BEACON_VIEW_AddHistoryId, BEACON_VIEW_PopHistoryId, BEACON_VIEW_HasRepeatedDigits, BEACON_VIEW_Cross2D, BEACON_VIEW_Sub2D, BEACON_VIEW_PointInTriangle, BEACON_VIEW_HitTestRow, BEACON_VIEW_HitTestIcon, BEACON_VIEW_HitTestActorTouch, BEACON_VIEW_SetupMessageText, BEACON_VIEW_ShowRecordCount, BEACON_VIEW_ShowPlayTime, BEACON_VIEW_ClearWindow, BEACON_VIEW_ShowWindowText, BEACON_VIEW_CheckWindowTouch, BEACON_VIEW_CreateTaskMenuButtons, BEACON_VIEW_UpdateTaskMenuButtons, BEACON_VIEW_FinishTaskMenuButtons, BEACON_VIEW_DeleteTaskMenuButtons, BEACON_VIEW_FinishTaskMenuButtonsAlt, BEACON_VIEW_DeleteTaskMenuButtonsAlt, BEACON_VIEW_GetActionVariant, BEACON_VIEW_PlaySe, BEACON_VIEW_MoveActorSurface, BEACON_VIEW_SetActorAnim, BEACON_VIEW_SetActorVisible, BEACON_VIEW_UpdateActorAnims, BEACON_VIEW_UpdateCountActorAnims, BEACON_VIEW_SetEntryVisible, BEACON_VIEW_SetEntryStatusVisible, BEACON_VIEW_ResetEntry, BEACON_VIEW_SetEntrySlot, BEACON_VIEW_GetEntry, BEACON_VIEW_LoadEntryPanel, BEACON_VIEW_LoadEntryStatus, BEACON_VIEW_GetPmVersion, BEACON_VIEW_LoadEntryPanelColor, BEACON_VIEW_PrintEntryName, BEACON_VIEW_PrintEntryFrames, BEACON_VIEW_PrintEntryRank, BEACON_VIEW_SetupEntry, BEACON_VIEW_SetEntryPosition, BEACON_VIEW_RefreshTopEntry, BEACON_VIEW_ScrollList, BEACON_VIEW_StartSlide, BEACON_VIEW_StartEntryMove, BEACON_VIEW_IconMoveTask, BEACON_VIEW_MoveEntryToSlot, BEACON_VIEW_MoveEntryToPeer, BEACON_VIEW_StartEntrySlide, BEACON_VIEW_IconSlideTask, BEACON_VIEW_StartScrollStep, BEACON_VIEW_ScrollStepTask, BEACON_VIEW_HandleRecordAction, BEACON_VIEW_ShowRecordMessage, BEACON_VIEW_ShowFormatMessage, BEACON_VIEW_StartFadeTask, BEACON_VIEW_FadeTask, BEACON_VIEW_HandlePowerRecord, BEACON_VIEW_ShowActivePower, BEACON_VIEW_ShowPowerAnim, BEACON_VIEW_StartPowerAnim, BEACON_VIEW_PowerAnimTaskA, BEACON_VIEW_PowerAnimTaskB, BEACON_VIEW_StartIconWait, BEACON_VIEW_IconWaitTask, BEACON_VIEW_ShowTouchedRow, BEACON_VIEW_StartWindowATask, BEACON_VIEW_WindowATask, BEACON_VIEW_DrawWindowText, BEACON_VIEW_StartWindowBTask, BEACON_VIEW_WindowBTask, BEACON_VIEW_DrawEntryText, BEACON_VIEW_StartWindowCTask, BEACON_VIEW_WindowCTask, BEACON_VIEW_Create, BEACON_VIEW_Delete, BEACON_VIEW_Update, BEACON_VIEW_MainPrintQueue, BEACON_VIEW_CreateLeaveEvent, BEACON_VIEW_SetEndRequest, BEACON_VIEW_ClearEndRequest, BEACON_VIEW_CreateTaskProc, BEACON_VIEW_TaskProc, BEACON_VIEW_TaskStateArrowAnim, BEACON_VIEW_TaskStateTasks, BEACON_VIEW_TaskStateTaskMenu, BEACON_VIEW_TransferPalettes, BEACON_VIEW_UpdateList, BEACON_VIEW_RunRecordArrival, BEACON_VIEW_UpdateFadeWait, BEACON_VIEW_UpdateSlide, BEACON_VIEW_RunPowerAnimStart, BEACON_VIEW_RunSelect, BEACON_VIEW_InitWorkFromSave, BEACON_VIEW_FreeWorkResources, BEACON_VIEW_CreateSubSystems, BEACON_VIEW_DestroySubSystems, BEACON_VIEW_InitBackgrounds, BEACON_VIEW_FreeBackgrounds, BEACON_VIEW_CreateTaskMenuRes, BEACON_VIEW_DeleteTaskMenuRes, BEACON_VIEW_LoadGraphics, BEACON_VIEW_FreeGraphics, BEACON_VIEW_CreateActors, BEACON_VIEW_DeleteActors, BEACON_VIEW_CreateWindow, BEACON_VIEW_CreateWindows, BEACON_VIEW_DeleteWindows, BEACON_VIEW_LoadResList, BEACON_VIEW_FreeResSet, BEACON_VIEW_CreateIconActor, BEACON_VIEW_CreatePanelActors, BEACON_VIEW_DeletePanelActors, BEACON_VIEW_CreateIcon, BEACON_VIEW_DeleteEntry
 * address:  0x021EFEC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   GAME_BEACON_ACCESSOR_TableRingGet  0x02165AC4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex  0x021659F0  thumb  ov010
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   GAME_BEACON_ACCESSOR_IsDistributionAction  0x02165C10  thumb  ov010
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   INTRUDE_COMM_GetVisitProgress  0x021585E0  thumb  ov010
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   BEACON_STATUS_GetViewFlags  0x020275D0  thumb
 *   BEACON_STATUS_GetMessage  0x020275C4  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   GPOWER_GetActiveIdOfSameType 0x02010EA0 thumb
 *   GAME_BEACON_ACCESSOR_TablePop  0x021658D4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_IsInfoInvalid  0x02165B5C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_TableRingAdd  0x02165A10  thumb  ov010
 *   MISC_IncrementThanksCount  0x0200C1E0  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   FLD_VREQ_SetSubBlendAlpha  0x021D3294  thumb  ov021
 *   PRINTSYS_QUE_SetLimitTick 0x0201C4DC thumb
 *   GAME_BEACON_SEARCH_SetThanks  0x021657E8  thumb  ov010
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPmVersion  0x02165C48  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetLanguage  0x02165C50  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   d_021F3554    0x021F3554  data  a4
 *   d_021F356C     0x021F356C  data  a4
 *   d_021F3538     0x021F3538  data  a1
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   TOUCHPANEL_HitPoint  0x02035D40  arm
 *   d_021F3530     0x021F3530  data  a2
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_CheckPixelColor  0x02041FF4  arm
 *   APP_TASKMENU_WIN_CreateEx  0x0202800C  thumb
 *   APP_TASKMENU_WIN_IsUpdateTrans  0x0202846C  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   GAME_BEACON_ACCESSOR_GetActionNo 0x02165E24 thumb ov010
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   STRBUF_Clear  0x0204581C  arm
 *   TCBL_DeleteTask  0x02031194  arm
 *   GAME_BEACON_ACCESSOR_GetTrainerAppearance  0x02165CE8  thumb  ov010
 *   CLACT_TransferCharacter  0x0204A9D0  arm
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_021F3541     0x021F3541  data  ov032  a1
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorRgb  0x02165CC0  thumb  ov010
 *   PALANM_BlendColors  0x02021F64  thumb
 *   GAME_BEACON_GetReceivedFramesByTrainerId  0x02026D48  thumb
 *   GAME_BEACON_ACCESSOR_GetResearchTeamRank 0x02165CB4 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetTrainerId  0x02165CE4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetGreeting  0x02165D50  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetThanksName  0x02165D6C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetFreeText  0x02165D8C  thumb  ov010
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BEACON_STATUS_SetViewTop 0x020275B8 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   FX_Div 0x0207C768 arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   GAME_BEACON_ACCESSOR_RegisterRecordWords 0x02165FCC thumb ov010
 *   GAME_BEACON_SEARCH_SetPresetEvent 0x02165374 thumb ov010
 *   MISC_IncrementGreetCount 0x0200C1C8 thumb
 *   STRBUF_Copy 0x02045838 arm
 *   GAME_BEACON_ACCESSOR_GetDistributionSerial 0x02165EBC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetInfoVersion 0x02165D20 thumb ov010
 *   TCBL_SetTaskFunc 0x02031288 arm
 *   WORDSET_SetSlotFromMsgA0 0x0201F184 thumb
 *   GPOWER_GetPowerCost 0x02010FA0 thumb
 *   MYITEM_SAVEDATA_GetItemQuantity 0x02007FB8 thumb
 *   GPOWER_GetSelectedMinutesLeft 0x02010EEC thumb
 *   d_021F352C 0x021F352C data ov032 a1
 *   GAME_BEACON_ACCESSOR_GetActionViewVariant 0x02165FC0 thumb ov010
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F36A0 0x021F36A0 data ov032 a1
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetVReq 0x02188E30 thumb ov021
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   TCBL_Main 0x020310C4 arm
 *   GAME_BEACON_ACCESSOR_TableAddNewLogs 0x02165888 thumb ov010
 *   INTRUDE_COMM_SetCompleted 0x02158614 thumb ov010
 *   FIELD_COMM_ACTOR_CreateSubscreenChangeEvent 0x021945A4 thumb ov021
 *   BEACON_VIEW_EVENT_Create 0x02164B38 thumb ov010
 *   GAME_EVENT_CreateOverlayEvent 0x020124AC thumb
 *   EVENT_NAMEIN_Create 0x021CD2A4 thumb ov021
 *   GPOWER_EVENT_CreateActivateEvent 0x021F5260 thumb ov083
 *   GPOWER_EVENT_CreateListEvent 0x021F5368 thumb ov083
 *   ov083_id 0x00000053 data
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAME_EVENT_ChangeEvent 0x0201235C thumb
 *   APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   GAME_DATA_GetItemUseWork  0x02012A54  thumb
 *   BEACON_STATUS_GetLog  0x020275A8  thumb
 *   GAME_BEACON_ACCESSOR_TableGetCount  0x02165B04  thumb  ov010
 *   BEACON_STATUS_GetViewTop  0x020275AC  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   INTRUDE_GetMonolithLevel  0x0200BF10  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   MISC_GetFromSave  0x0200C0E8  thumb
 *   MISC_GetThanksCount  0x0200C1DC  thumb
 *   SYSTEM_DATA_GetMyStatus  0x02008730  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   GAME_BEACON_ACCESSOR_AllocTable  0x02165B2C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_AllocInfo  0x02165B10  thumb  ov010
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   GAME_BEACON_ACCESSOR_TableMarkLogsNew 0x02165940 thumb ov010
 *   GPOWER_FreePowerTable 0x02010F8C thumb
 *   TCBL_Create  0x0203101C  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   PRINTSYS_QUE_SetForceQueue  0x0201C4C8  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCBL_Destroy 0x02031140 arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   PALANM_LoadHandlePaletteToSlot  0x020216B4  thumb
 *   PALANM_LoadArcPaletteToSlot  0x02021640  thumb
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021F3608     0x021F3608  data  ov032  a4
 *   d_021F3628     0x021F3628  data  ov032  a4
 *   d_021F3648     0x021F3648  data  ov032  a4
 *   d_021F3668     0x021F3668  data  ov032  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   NNS_G2dGetUnpackedCharacterData  0x02062A00  arm
 *   DC_FlushAll    0x02086284  arm
 *   d_021F35BC     0x021F35BC  data  ov032  a2
 *   d_021F35C8     0x021F35C8  data  ov032  a2
 *   d_021F35D4     0x021F35D4  data  ov032  a2
 *   d_021F35E0 0x021F35E0 data ov032 a4
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BEACON_VIEW_DeleteEntry 0x021F34C8 thumb ov032
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   d_021F35F0 0x021F35F0 data ov032 a2
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   BMP_Delete  0x020437AC  arm
 */

#define FX32_CONST(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
#define REG_DB_DISPCNT_SUB (*(volatile u32 *)REG_DB_DISPCNT_ADDR)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)REG_DB_BLDCNT_ADDR)
struct Queue;
struct BeaconRecord;
struct Ctx;
struct WordSet;
struct Blk34;
struct PaletteFadeWork;
struct PrintSys;
struct ClactActor;
struct Obj;
struct MsgBank;
struct CharBuf;
struct Descriptor;
struct ClactVec2;
struct TcblNode;
struct U16Vec;
struct BeaconTrainerInfo;
struct NNSG2dCharacterData;
struct Strbuf;
struct Grid;
struct Rec02010FA0;
struct Cfg;
struct Tcbl;
struct Desc;
struct S0201235C;
struct PaletteFade;
struct Big;
struct BigObj;
struct Rec1B0;
struct Sub0200852CObj;
struct Node;
struct BgTemplate;
struct TaskMenuRes;
struct TaskMenuState;
struct ArcFile;
struct NitroFileHeader;
struct Unit;
struct BmpOamParam;
struct Sys;
struct Bmp;
#include "../types.h"
#include "../sdk_ioreg.h"
#include "../arm9/ica_anime_shared_types.h"

typedef struct { u32 x, y; } BeaconPair;

typedef struct { int x, y; } Vec2;

typedef struct { short x,y; } BeaconDelta;

typedef struct BeaconTrainerInfo BeaconTrainerInfo;

typedef struct BeaconRecord BeaconRecord;

#include "../version.h"
#include "beacon_view_types.h"

typedef struct {
    u32 powerId;
    u32 powerFlag;
} Args;

/* Event descriptor handle created by GAME_EVENT_Create; only its pointer is used. */
typedef struct Desc Desc;


typedef struct {
    u16 count;
    u16 base;
} ResSpec;

typedef struct {
    ResSpec s[3];
} ResSpec3;

typedef struct { int w[4]; } T16;

#include "../arm9/clact.h"

typedef struct {
    short x;
    short y;
} Pt;

#include "../arm9/bmp_oam.h"

#include "../arm9/palanm.h"
#include "../arm9/nns_g2d_res_types.h"
struct GameBeaconInfo;
struct GameBeaconInfoTable;
#include "../ov010/game_beacon_accessor.h"
#include "../arm9/net.h"
#include "../arm9/touchpanel.h"
struct GameComm;
#include "../ov010/intrude_comm_query.h"
struct GameSystem;
#include "../arm9/gamesystem.h"
#include "../arm9/wih_dwc.h"
struct BeaconStatus;
#include "../arm9/beacon_status.h"
struct Strbuf;
#include "../arm9/wordset.h"
struct GPowerData;
#include "../arm9/gpower.h"
struct MiscSave;
#include "../arm9/beacon.h"
struct FldVReq;
#include "../ov021/fld_vreq.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct GameData;
#include "../ov010/game_beacon_set.h"
#include "../arm9/clact.h"
#include "../arm9/mi_memory.h"
#include "../arm9/msgdata.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/bmp_win.h"
struct BmpWin;
#include "../arm9/bmp.h"
#include "../arm9/bmp_win.h"
#include "../arm9/bg_sys.h"
struct TaskMenuItem;
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/gfl_use.h"
struct BmpOam;
#include "../arm9/bmp_oam.h"
#include "../arm9/strbuf.h"
struct TcblTask;
#include "../arm9/tcbl.h"
#include "../arm9/palanm.h"
#include "../arm9/game_beacon.h"
#include "../arm9/fx_cp.h"
struct MyItem;
#include "../arm9/myitem_savedata.h"
struct GfFont;
#include "../arm9/gfl_heap_wrap.h"
struct GameSystem;
struct FieldMap;
#include "../ov021/fieldmap.h"
#include "../arm9/arc_tool.h"
struct TcblSystem;
struct GameComm;
struct GameEvent;
#include "../ov021/field_comm_actor.h"
#include "../ov010/beacon_view_event.h"
#include "../arm9/game_event.h"
#include "../ov021/event_namein.h"
struct GPowerActivateParam;
#include "../ov083/gpower_event.h"
#include "../arm9/game_data.h"
#include "../arm9/msg_speed.h"
struct SaveControl;
struct IntrudeSave;
#include "../arm9/intrude.h"
struct FieldState;
struct MyStatus;
#include "../arm9/system_data.h"
#include "../arm9/mystatus.h"
struct FieldMsgBg;
struct GfFont;
#include "../ov021/field_msgbg.h"
#include "../arm9/gf_font.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/arc_util.h"
#include "../arm9/g2.h"
struct KeyCursor;
#include "../arm9/app_keycursor.h"
struct GFont;
struct ArcHandle;
#include "../arm9/nns_g2d_anim_bank.h"
#include "../arm9/os_cache.h"
struct SurfaceInit;
struct Renderer;
struct BmpOamSys;
#include "beacon_view.h"
int BEACON_VIEW_PointInTriangle(Vec2 *pt, Vec2 *tri);
void BEACON_VIEW_ShowRecordMessage(BeaconViewWork *work, struct GameBeaconInfo *r);
void BEACON_VIEW_LoadResList(BeaconViewWork *work, BeaconViewResList *out, const ResSpec *spec, void *arc);

typedef struct {
    short x;
    short y;
    unsigned short w;
    unsigned char z;
    unsigned char h;
} BeaconActorRect;

void *BEACON_VIEW_CreateIconActor(BeaconViewWork *work, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z);
void BEACON_VIEW_CreatePanelActors(BeaconViewWork *work);
void BEACON_VIEW_DeletePanelActors(BeaconViewWork *work);
void BEACON_VIEW_CreateIcon(BeaconViewWork *work, u8 idx);
extern u32 d_021F3554[];
extern Vec2 d_021F356C[2][5];
extern u8 d_021F3538[][3];
extern u16 d_021F3530[];
extern u8 d_021F3541[];
extern u8 d_021F352C[];
extern char d_021F36A0[];
extern u8 ov083_id[];
extern const u8 d_021F3608[];
extern const u8 d_021F3628[];
extern const u8 d_021F3648[];
extern const u8 d_021F3668[];
extern const ResSpec3 d_021F35BC;
extern const ResSpec3 d_021F35C8;
extern const ResSpec3 d_021F35D4;
extern T16 d_021F35E0;
extern Pt d_021F35F0[];

void BEACON_VIEW_InitList(BeaconViewWork *work)
{
    int i;
    u8 *q;
    BeaconViewEntry *icon;
    int s;
    int t;

    PALANM_SetAutoTransfer(work->paletteAnim, 1);
    BEACON_VIEW_ShowRecordCount(work);
    BEACON_VIEW_ShowPlayTime(work, 1, 0);
    for (i = 0; i < work->visibleRows; i++) {
        q = (u8 *)&work->tagBuffer;
        t = work->scrollTop;
        GAME_BEACON_ACCESSOR_TableRingGet(work->recordLog, work->recordBuffer, (u16 *)q, t + i);
        s = GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, t + i);
        icon = BEACON_VIEW_GetEntry(work, 0xFF);
        BEACON_VIEW_SetEntrySlot(icon, (u8)s, (u8)(i + 1));
        BEACON_VIEW_SetupEntry(work, icon, work->recordBuffer, 2, 0, 0);
        BEACON_VIEW_SetEntryVisible(icon, (int)1);
    }
    BEACON_VIEW_UpdateActorAnims(work);
    BEACON_VIEW_UpdateCountActorAnims(work);
    if (work->powerId == 0x30)
        BEACON_VIEW_SetActorAnim(work->actors[0], 3);
    GFL_NET_RefreshWmIconAtTopRight(0, work->uiHeapId);
}

int BEACON_VIEW_UpdateListTouch(BeaconViewWork *work)
{
    BeaconPair v;
    int r;
    int s;

    if (TOUCHPANEL_GetPointTrg(&v.x, &v.y) == 0)
        return 0;
    r = BEACON_VIEW_HitTestActorTouch(work, (u32 *)(&v));
    if (r != -1) {
        switch (r) {
        case 0:
            return 4;
        case 1:
            BEACON_VIEW_SetEndRequest(work, 8);
            break;
        case 2:
            return 5;
        case 3:
            BEACON_VIEW_SetEndRequest(work, 1);
            break;
        }
        return 0;
    }
    r = BEACON_VIEW_HitTestRow(work, &v);
    if (r != -1) {
        GAME_BEACON_ACCESSOR_TableRingGet(work->recordLog, work->recordBuffer, (u16 *)((u8 *)&work->tagBuffer), work->scrollTop + r);
        if (GAME_BEACON_ACCESSOR_IsDistributionAction(work->recordBuffer) != 0)
            return 0;
        work->touchedRow = r;
        BEACON_VIEW_ShowTouchedRow(work, (u8)r);
        BEACON_VIEW_SetEndRequest(work, 4);
        return 0;
    }
    s = BEACON_VIEW_HitTestIcon(work, &v);
    if (s != -1) {
        BEACON_VIEW_StartSlide(work, s, (int)0);
        return 3;
    }
    return 0;
}

int BEACON_VIEW_GetContTouchedRow(BeaconViewWork *work) { u32 pt[2]; if(TOUCHPANEL_GetPointCont(pt,pt+1)) return BEACON_VIEW_HitTestIcon(work,pt); return -1; }

int BEACON_VIEW_CheckLeaveRequest(BeaconViewWork *work)
{
    int r;

    r = INTRUDE_COMM_GetVisitProgress(work->playerProfile);
    if (GAMESYSTEM_IsNetOffBySleep(work->fieldSystem) != 0) {
        BEACON_VIEW_SetEndRequest(work, 1);
        return 1;
    }
    if (r == 2) {
        BEACON_VIEW_SetEndRequest(work, 2);
        return 1;
    }
    if (WIH_DWC_PollStatus(work->optionData) & 8) {
        BEACON_VIEW_SetEndRequest(work, 3);
        return 1;
    }
    return 0;
}

int BEACON_VIEW_ShowViewFlagMessage(BeaconViewWork *work)
{
    u16 *f;

    f = BEACON_STATUS_GetViewFlags(work->beaconStatus);
    if (*f == 0)
        return 0;
    *f = 0;
    WORDSET_SetSlotTag(work->wordSet, 0, (void *)BEACON_STATUS_GetMessage(work->beaconStatus),
                  work->gender, 1, 2);
    BEACON_VIEW_ShowFormatMessage(work, 0xB);
    return 1;
}

int BEACON_VIEW_ShowNextHistoryPower(BeaconViewWork *work) { unsigned n; n=BEACON_VIEW_PopHistoryId(work); if(n==0x30) return 0; if(n==GPOWER_GetActiveIdOfSameType(n,work->powerRecord)) return 0; BEACON_VIEW_ShowPowerAnim(work,n); return 1; }

int BEACON_VIEW_LoadNextRecord(BeaconViewWork *work)
{
    u8 t;

    if (GAME_BEACON_ACCESSOR_TablePop(work->receiveQueue, work->currentRecord, (u16 *)((u8 *)&work->currentTag)) == 0) {
        BEACON_VIEW_RefreshTopEntry(work);
        return 0;
    }
    if (GAME_BEACON_ACCESSOR_IsInfoInvalid(work->currentRecord) != 0)
        return 0;
    work->currentIndex = GAME_BEACON_ACCESSOR_TableRingAdd(work->recordLog, work->currentRecord, work->currentTag, (int *)&work->addedCount);
    work->currentId = GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, work->currentIndex);
    if (work->addedCount == 0) {
        work->currentEntry = BEACON_VIEW_GetEntry(work, work->currentId);
    } else {
        work->currentEntry = 0;
        work->playTime = MISC_IncrementThanksCount(work->playerBlock);
    }
    if (work->currentEntry != 0 && work->currentEntry->busy != 0)
        work->step = 0;
    else
        work->step = 1;
    t = work->recordCount;
    work->previousCount = t;
    if (t < 0x1E) {
        work->recordCount += (u8)work->addedCount;
        if (work->recordCount <= 4)
            work->visibleRows = work->recordCount;
    }
    return 1;
}

void BEACON_VIEW_SetFadeState(BeaconViewWork *work, int flag)
{
    if (flag) {
        PALANM_BlendChannel(work->paletteAnim, 1, 0, 0xe0, 6, 0);
        PALANM_BlendChannel(work->paletteAnim, 3, 0, 0xe0, 6, 0);
        FLD_VREQ_SetSubBlendAlpha(work->bgConfig, 5, 0x1e, 0xa, 6);
    } else {
        PALANM_BlendChannel(work->paletteAnim, 1, 0, 0xe0, 0, 0);
        PALANM_BlendChannel(work->paletteAnim, 3, 0, 0xe0, 0, 0);
        FLD_VREQ_SetSubBlendAlpha(work->bgConfig, 4, 0x1e, 0xd, 3);
    }
}

void BEACON_VIEW_ApplySlideTarget(BeaconViewWork *work) { BEACON_VIEW_ScrollList(work, work->slideTarget); }

void BEACON_VIEW_SetPrintQueueLimit(BeaconViewWork *work,int flag) { if(flag) PRINTSYS_QUE_SetLimitTick(work->printQueue,2000,0); else PRINTSYS_QUE_SetLimitTick(work->printQueue,500,0); }

int BEACON_VIEW_UpdateRecordArrival(BeaconViewWork *work)
{
    int r;

    switch (work->step) {
    case 0:
        if (work->currentEntry->busy != 0)
            break;
        (work->step)++;
        break;
    case 1:
        r = BEACON_VIEW_HandleRecordAction(work, work->currentRecord, work->addedCount);
        if (work->addedCount == 0) {
            if (r != 0) {
                BEACON_VIEW_SetArrowAnim(work, 4, 2);
                BEACON_VIEW_PlaySe(0x549);
            }
            if (work->currentEntry != 0) {
                BEACON_VIEW_SetupEntry(work, work->currentEntry, work->currentRecord, 0, r == 0, 0);
                BEACON_VIEW_SetEntryVisible(work->currentEntry, 1);
            }
            return 1;
        }
        BEACON_VIEW_SetArrowAnim(work, 4, 2);
        (work->step)++;
        break;
    case 2:
        BEACON_VIEW_ShowRecordCount(work);
        BEACON_VIEW_ShowPlayTime(work, 1, &work->busyCount);
        BEACON_VIEW_UpdateAchievements(work, work->currentRecord, work->previousCount);
        (work->step)++;
        break;
    case 3:
        if (work->scrollTop != 0) {
            work->currentIndex = work->scrollTop;
            GAME_BEACON_ACCESSOR_TableRingGet(work->recordLog, work->currentRecord, (u16 *)((u8 *)&work->currentTag), work->currentIndex);
            work->currentId = GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, work->currentIndex);
        }
        BEACON_VIEW_StartEntryMove(work, work->currentRecord, work->currentId, 1, (work->scrollTop != 0 ? 1 : 0) + 1);
        work->scrollTop = work->currentIndex;
        BEACON_VIEW_PlaySe(0x64A);
        return 1;
    }
    return 0;
}

int BEACON_VIEW_UpdatePowerAnimStart(BeaconViewWork *work)
{
    int s = work->step;

    switch (s) {
    case 0:
        BEACON_VIEW_SetArrowAnim(work, 0, 1);
        BEACON_VIEW_SetPrintQueueLimit(work, 1);
        BEACON_VIEW_ShowActivePower(work);
        work->step = work->step + 1;
        break;
    case 1:
        if (work->busyCount == 0) {
            BEACON_VIEW_SetPrintQueueLimit(work, 0);
            work->step = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int BEACON_VIEW_UpdateSelect(BeaconViewWork *work)
{
    BeaconViewEntry *icon;
    u8 s;

    if (work->busyCount != 0)
        return 5;
    switch (work->step) {
    case 0:
        BEACON_VIEW_SetArrowAnim(work, 2, 1);
        BEACON_VIEW_ShowPlayTime(work, 2, &work->busyCount);
        (work->step)++;
        break;
    case 1:
        if (BEACON_VIEW_IsArrowAnimActive(work, 2) != 0)
            break;
        BEACON_VIEW_SetArrowAnim(work, 0, 2);
        BEACON_VIEW_SetArrowAnim(work, 1, 2);
        BEACON_VIEW_SetArrowAnim(work, 3, 2);
        (work->step)++;
        break;
    case 2:
        work->step = BEACON_VIEW_UpdateSelectTouch(work);
        if (work->step == 3)
            return 3;
        break;
    case 4:
        s = GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, work->touchedRow + work->scrollTop);
        icon = BEACON_VIEW_GetEntry(work, s);
        WORDSET_SetSlotTag(work->wordSet, 0, icon->messageString, icon->gender, 1, 2);
        BEACON_VIEW_SetPrintQueueLimit(work, 1);
        BEACON_VIEW_ShowFormatMessage(work, 3);
        GAME_BEACON_SEARCH_SetThanks(work->saveInfo, icon->trainerId);
        work->step = 5;
        break;
    case 5:
        BEACON_VIEW_SetPrintQueueLimit(work, 0);
        work->step = 6;
        break;
    case 3:
        BEACON_VIEW_SetArrowAnim(work, 2, 0);
        work->step = 2;
        break;
    case 6:
        BEACON_VIEW_SetArrowAnim(work, 4, 0);
        BEACON_VIEW_ShowPlayTime(work, 1, &work->busyCount);
        work->step = 7;
        break;
    case 7:
        work->step = 0;
        return 0;
    }
    return 5;
}

int BEACON_VIEW_UpdateSelectTouch(BeaconViewWork *work)
{
    BeaconPair v;
    int r;
    int s;

    if (GAMESYSTEM_IsNetOffBySleep(work->fieldSystem) != 0) {
        BEACON_VIEW_SetEndRequest(work, 1);
        return 6;
    }
    if (TOUCHPANEL_GetPointTrg(&v.x, &v.y) == 0)
        return 2;
    if (BEACON_VIEW_HitTestActorTouch(work, (u32 *)(&v)) == 2)
        return 6;
    r = BEACON_VIEW_HitTestRow(work, &v);
    if (r != -1) {
        work->touchedRow = r;
        BEACON_VIEW_ShowTouchedRow(work, (u8)r);
        return 4;
    }
    s = BEACON_VIEW_HitTestIcon(work, &v);
    if (s != -1) {
        BEACON_VIEW_StartSlide(work, s, (int)5);
        return 3;
    }
    return 2;
}

void BEACON_VIEW_SetArrowAnim(BeaconViewWork *work, int arrowIndex, u32 animOffset)
{
    u8 m;

    if (arrowIndex == 4)
        m = 0xf;
    else
        m = 1 << arrowIndex;
    if ((1 & m) && work->powerId != 0x30)
        BEACON_VIEW_SetActorAnim(work->actors[0], (u8)(animOffset + 1));
    if (2 & m)
        BEACON_VIEW_SetActorAnim(work->actors[1], (u8)(animOffset + 4));
    if ((4 & m) && work->recordCount != 0)
        BEACON_VIEW_SetActorAnim(work->actors[2], (u8)(animOffset + 7));
    if (8 & m)
        BEACON_VIEW_SetActorAnim(work->actors[3], (u8)(animOffset + 10));
}

int BEACON_VIEW_IsArrowAnimActive(BeaconViewWork *work, int i) { return CLACT_IsActorAnimActive(*(struct ClactActor * *)&work->actors[i]); }

void BEACON_VIEW_RefreshActorAnims(BeaconViewWork *work)
{
    BEACON_VIEW_UpdateActorAnims(work);
}

void BEACON_VIEW_CountDifferingRecords(BeaconViewWork *work, u8 *outGenderMismatch, u8 *outVersionMismatch)
{
    int i = 0;
    u16 tag;

    *outGenderMismatch = 0;
    *outVersionMismatch = 0;
    for (; i < work->recordCount; i++) {
        GAME_BEACON_ACCESSOR_TableRingGet(work->recordLog, work->ownRecord, &tag, i);
        if (work->gender != GAME_BEACON_ACCESSOR_GetSex(work->ownRecord))
            (*outGenderMismatch)++;
        if (work->styleId != GAME_BEACON_ACCESSOR_GetPmVersion(work->ownRecord))
            (*outVersionMismatch)++;
    }
}

void BEACON_VIEW_UpdateAchievements(BeaconViewWork *work, struct GameBeaconInfo *record, int count)
{
    u8 v[2];

    v[1] = 0;
    v[0] = 0;
    BEACON_VIEW_CountDifferingRecords(work, &v[0], &v[1]);
    if (GAME_BEACON_ACCESSOR_GetLanguage(record) != 2)
        BEACON_VIEW_AddHistoryId(work, 1);
    if (work->previousIdB != v[1] && v[1] == 0x14)
        BEACON_VIEW_AddHistoryId(work, 2);
    if (work->playTime % 100 == 0)
        BEACON_VIEW_AddHistoryId(work, 3);
    if (count == 0x1d && work->recordCount == 0x1e)
        BEACON_VIEW_AddHistoryId(work, 4);
    if (work->previousIdA != v[0] && v[0] == 0x14)
        BEACON_VIEW_AddHistoryId(work, 5);
    if (BEACON_VIEW_HasRepeatedDigits(work->playTime) != 0)
        BEACON_VIEW_AddHistoryId(work, 6);
    work->previousIdA = v[0];
    work->previousIdB = v[1];
}

/*
 * volatile: count byte at +0x8c re-read at 021F07A2 and 021F07BE.
 */
void BEACON_VIEW_AddHistoryId(BeaconViewWork *work,int powerId) { int n,i; n=*(volatile u8 *)&work->historyCount; for(i=0;i<n;i++) if(powerId==work->historyIds[i]) return; *(volatile u8 *)&work->historyCount=*(volatile u8 *)&work->historyCount+1; work->historyIds[n]=powerId; }

u32 BEACON_VIEW_PopHistoryId(BeaconViewWork *work)
{
    u32 n = work->historyIds[0];

    if (n == 0)
        return 0x30;
    work->historyCount = work->historyCount - 1;
    MI_CpuCopy8((u8 *)&work->historyIds[1], (u8 *)&work->historyIds[0], work->historyCount);
    work->historyIds[work->historyCount] = 0;
    return d_021F3554[n - 1];
}

int BEACON_VIEW_HasRepeatedDigits(u32 x)
{
    u32 d;

    if (x / 100 == 0)
        return 0;
    d = x % 10;
    x = x / 10;
    do {
        if ((u8)(x % 10) != d)
            return 0;
        x = x / 10;
    } while (x != 0);
    return 1;
}

int BEACON_VIEW_Cross2D(int *lhs, int *rhs) { return lhs[0]*rhs[1] - lhs[1]*rhs[0]; }

void BEACON_VIEW_Sub2D(int *lhs, int *rhs, int *out) { out[0]=lhs[0]-rhs[0]; out[1]=lhs[1]-rhs[1]; }

int BEACON_VIEW_PointInTriangle(Vec2 *pt, Vec2 *tri)
{
    int i;
    Vec2 a;
    Vec2 b;

    for (i = 0; i < 3; i++) {
        BEACON_VIEW_Sub2D((int *)pt, (int *)(&tri[i]), (int *)(&a));
        BEACON_VIEW_Sub2D((int *)(&tri[(i + 1) % 3]), (int *)(&tri[i]), (int *)(&b));
        if (BEACON_VIEW_Cross2D((int *)(&a), (int *)(&b)) < 0)
            return 0;
    }
    return 1;
}

int BEACON_VIEW_HitTestRow(BeaconViewWork *work, void *pt)
{
    int i;
    int x;
    int y;
    int t[6];

    for (i = 0; i < work->visibleRows; i++) {
        x = i * 13;
        y = i * 40;
        t[0] = x;
        t[1] = y + 5;
        t[2] = x + 0xc;
        t[3] = y + 0x2b;
        t[4] = x + 0xd2;
        t[5] = y + 0x2b;
        if (BEACON_VIEW_PointInTriangle((Vec2 *)pt, (Vec2 *)t))
            return i;
        t[0] = x;
        t[1] = y + 5;
        t[2] = x + 0xd2;
        t[3] = y + 0x2b;
        t[4] = x + 0xc6;
        t[5] = y + 5;
        if (BEACON_VIEW_PointInTriangle((Vec2 *)pt, (Vec2 *)t))
            return i;
    }
    return -1;
}

/*
 * Tries the point against the triangles of two fixed 5-vertex fans (byte
 * index triples in d_021F3538); returns 1 - j for the fan that hits, else -1.
 * Copying the vertices as Vec2 structs gives the x-then-y load order; the
 * `k = 0` ahead of the fan pointer keeps `movs r4, #0` first.
 */
int BEACON_VIEW_HitTestIcon(BeaconViewWork *work, void *pt)
{
    int flags;
    int j;
    int k;
    Vec2 t[3];

    flags = 0;
    if (work->scrollTop != 0)
        flags |= 1;
    if (work->scrollTop + work->visibleRows < work->recordCount)
        flags |= 2;
    for (j = 0; j < 2; j++) {
        if (flags & (j + 1)) {
            Vec2 *v;
            k = 0;
            v = d_021F356C[j];
            for (; k < 3; k++) {
                t[0] = v[d_021F3538[k][0]];
                t[1] = v[d_021F3538[k][1]];
                t[2] = v[d_021F3538[k][2]];
                if (BEACON_VIEW_PointInTriangle((Vec2 *)pt, (Vec2 *)((int *)t)))
                    return 1 - j;
            }
        }
    }
    return -1;
}

int BEACON_VIEW_HitTestActorTouch(BeaconViewWork *work, u32 *touchPos)
{
    u8 b[5];
    int i;

    b[4] = 0xff;
    for (i = 0; i < 4; i++) {
        u32 a = CLACT_GetActorAnimSeq(work->actors[i]);
        if ((u8)(a - (i * 3 + 1)) % 3 < 2) {
            b[0] = 0xac;
            b[1] = b[0] + 0x18;
            b[2] = i * 32 + 0x84;
            b[3] = b[2] + 0x18;
            if (TOUCHPANEL_HitPoint((const void *)b, touchPos[0], touchPos[1]) != -1) {
                BEACON_VIEW_PlaySe(d_021F3530[i]);
                return i;
            }
        }
    }
    return -1;
}

void BEACON_VIEW_SetupMessageText(BeaconViewWork *work,unsigned messageId) { MSGDATA_ReadString(work->messageBank,messageId,work->messageBuffer); WORDSET_CopyTaggedText(work->wordSet,work->formatBuffer,work->messageBuffer); }

void BEACON_VIEW_ShowRecordCount(BeaconViewWork *work)
{
    WORDSET_SetSlotNumber(work->wordSet, 0, work->recordCount, 2, 1, 1);
    BEACON_VIEW_SetupMessageText(work, 0);
    BEACON_VIEW_DrawWindowText(work, &work->windows[2], work->formatBuffer, 4, 0, 1, 0x3DC1, 0);
}

void BEACON_VIEW_ShowPlayTime(BeaconViewWork *work, int messageId, int *busyCounter)
{
    WORDSET_SetSlotNumber(work->wordSet, 0, *(int *)&work->playTime, 5, 0, 1);
    BEACON_VIEW_SetupMessageText(work, messageId);
    BEACON_VIEW_DrawWindowText(work, &work->windows[1], work->formatBuffer, 0, 4, 0, 0x3C40, busyCounter);
}

void BEACON_VIEW_ClearWindow(BeaconViewWork *work) { BMP_Clear(work->windows[1].bitmap,0x40); BMP_WIN_TransferChars(work->windows[1].handle); }

void BEACON_VIEW_ShowWindowText(BeaconViewWork *work,void *text,int *busyCounter) { BEACON_VIEW_DrawWindowText(work,&work->windows[0],text,0,0,9,0x449,busyCounter); }

int BEACON_VIEW_CheckWindowTouch(u8 *touchCounter)
{
    u32 x;
    u32 y;
    u16 v = 0xFFFE;
    u8 c = touchCounter[0];

    touchCounter[0] = c - 1;
    if (c == 0) {
        touchCounter[0] = 0;
        return 1;
    }
    if (TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
        if (BG_SYS_CheckPixelColor(6, x, y + 0x40, &v) != 0) {
            touchCounter[0] = 0;
            return 1;
        }
    }
    return 0;
}

void BEACON_VIEW_CreateTaskMenuButtons(BeaconViewWork *work, int flag)
{
    int i;
    int n;
    int base;
    BeaconViewSlot *slotList;

    if (flag == 0) {
        slotList = &work->slots[0];
        n = 3;
        base = 8;
    } else {
        slotList = &work->slots[3];
        n = 2;
        base = 0x10;
    }
    for (i = 0; i < n; i++) {
        slotList[i].taskMenu = APP_TASKMENU_WIN_CreateEx(work->taskMenuState, (struct TaskMenuItem *)((char *)&slotList[i].label),
                                      (u8)(base + i * 8), 0x15, 8, 3, 1, 0,
                                      work->mainHeapId);
    }
}

int BEACON_VIEW_UpdateTaskMenuButtons(BeaconViewWork *work, int flag)
{
    int s;
    BeaconViewSlot *slotList;
    int n;
    int i;

    s = -1;
    if (flag == 0) {
        slotList = &work->slots[0];
        n = 3;
    } else {
        slotList = &work->slots[3];
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (APP_TASKMENU_WIN_IsUpdateTrans(slotList[i].taskMenu) == 1) {
            APP_TASKMENU_WIN_Update(slotList[i].taskMenu);
            return -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (APP_TASKMENU_WIN_IsTouch((struct TaskMenuWin *)(*(u32 * *)&slotList[i].taskMenu)) != 0) {
            if (i < n - 1) {
                BEACON_VIEW_PlaySe(0x54c);
                s = i;
            } else {
                APP_TASKMENU_WIN_SetDecide(slotList[i].taskMenu, 1);
                BEACON_VIEW_PlaySe(0x54c);
                s = i;
            }
        }
        APP_TASKMENU_WIN_Update(slotList[i].taskMenu);
    }
    return s;
}

int BEACON_VIEW_FinishTaskMenuButtons(BeaconViewWork *work, int i)
{
    BeaconViewSlot *slotList;
    int j;

    slotList = &work->slots[0];
    APP_TASKMENU_WIN_Update(slotList[i].taskMenu);
    if (APP_TASKMENU_WIN_IsFinish(slotList[i].taskMenu) != 0) {
        for (j = 0; j < 3; j++) {
            APP_TASKMENU_WIN_Delete(work->slots[j].taskMenu);
            work->slots[j].taskMenu = 0;
        }
        return 1;
    }
    return 0;
}

void BEACON_VIEW_DeleteTaskMenuButtons(BeaconViewWork *work) { int i; for(i=0;i<3;i++) { APP_TASKMENU_WIN_Delete(work->slots[i].taskMenu); work->slots[i].taskMenu=0; } }

int BEACON_VIEW_FinishTaskMenuButtonsAlt(BeaconViewWork *work, int i)
{
    BeaconViewSlot *slotList;
    int j;

    slotList = &work->slots[3];
    APP_TASKMENU_WIN_Update(slotList[i].taskMenu);
    if (APP_TASKMENU_WIN_IsFinish(slotList[i].taskMenu) != 0) {
        for (j = 0; j < 2; j++) {
            APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)((&work->slots[3])[j].taskMenu));
            (&work->slots[3])[j].taskMenu = 0;
        }
        return 1;
    }
    return 0;
}

void BEACON_VIEW_DeleteTaskMenuButtonsAlt(BeaconViewWork *work) { int i; for(i=0;i<2;i++) { APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)(*(unsigned char * *)&(&work->slots[3])[i].taskMenu)); (&work->slots[3])[i].taskMenu=0; } }

int BEACON_VIEW_GetActionVariant(void *record) { int a; a=GAME_BEACON_ACCESSOR_GetActionNo((struct GameBeaconInfo *)record); if(a==0 || a>=0x33) return 0x12; return a+0x11; }

void BEACON_VIEW_PlaySe(unsigned int seId)
{
    GFL_USE_PlaySeDefaultVolume(seId);
}

void BEACON_VIEW_MoveActorSurface(void *actor, short x, short y) { BeaconDelta d; d.x=x; d.y=y; CLACT_AddActorSurfacePos(actor,(const struct ClactVec2 *)(&d),0); }

void BEACON_VIEW_SetActorAnim(void *actor, unsigned short animSeq) { CLACT_SetActorAnimSeq(actor,animSeq); CLACT_RestartActorAnim(actor); }

void BEACON_VIEW_SetActorVisible(BeaconViewWork *work, unsigned visible) { int i; for(i=0;i<=3;i++) CLACT_SetActorDrawEnable(work->actors[i],visible); }

void BEACON_VIEW_UpdateActorAnims(BeaconViewWork *work)
{
    if (work->scrollTop == 0) {
        CLACT_SetActorAnimSeq(work->actors[4], 0x10);
    } else {
        CLACT_SetActorAnimSeq(work->actors[4], 0xd);
    }
    if (work->scrollTop + work->visibleRows < work->recordCount) {
        CLACT_SetActorAnimSeq(work->actors[5], 0x11);
        return;
    }
    CLACT_SetActorAnimSeq(work->actors[5], 0x14);
}

void BEACON_VIEW_UpdateCountActorAnims(BeaconViewWork *work) { if(work->recordCount==0) CLACT_SetActorAnimSeq(work->actors[2],9); else CLACT_SetActorAnimSeq(work->actors[2],7); }

void BEACON_VIEW_SetEntryVisible(BeaconViewEntry *icon,unsigned visible) { BMP_OAM_SetEnabled((struct BmpOam *)(*(unsigned char * *)&icon->textWindow),visible); CLACT_SetActorDrawEnable(icon->iconActor,visible); CLACT_SetActorDrawEnable(icon->panelActor,visible); if(visible==0) BEACON_VIEW_SetEntryStatusVisible(icon,visible); }

void BEACON_VIEW_SetEntryStatusVisible(BeaconViewEntry *icon, int visible)
{
    CLACT_SetActorDrawEnable(icon->statusActor, visible);
}

void BEACON_VIEW_ResetEntry(BeaconViewEntry *icon)
{
    int z = 0;

    BEACON_VIEW_SetEntryVisible(icon, 0);
    BEACON_VIEW_SetEntryStatusVisible(icon, 0);
    BMP_Clear((struct Bmp *)((sptr)icon->textBitmap), 0);
    BMP_OAM_UploadChars(icon->textWindow);
    STRBUF_Clear(icon->messageString);
    STRBUF_Clear(icon->nameString);
    icon->peerSlot = 0xff;
    icon->state = z;
    icon->flags = z;
    if (icon->busy != 0) {
        TCBL_DeleteTask(icon->busy);
        icon->busy = 0;
    }
    if (icon->activeTask != 0) {
        TCBL_DeleteTask(icon->activeTask);
        icon->activeTask = 0;
    }
}

void BEACON_VIEW_SetEntrySlot(BeaconViewEntry *icon, int peerSlot, int state) { BEACON_VIEW_ResetEntry(icon); *(char *)&icon->peerSlot=peerSlot; *(char *)&icon->state=state; }

BeaconViewEntry *BEACON_VIEW_GetEntry(BeaconViewWork *work, int peerSlot)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (peerSlot == work->icons[i].peerSlot)
            return &work->icons[i];
    }
    return 0;
}

void BEACON_VIEW_LoadEntryPanel(BeaconViewWork *work, BeaconViewEntry *icon, struct GameBeaconInfo *trainerInfo)
{
    int x;

    x = GAME_BEACON_ACCESSOR_GetTrainerAppearance(trainerInfo);
    CLACT_TransferCharacter(work->iconLists.images.items[icon->index], work->iconRes[x].data);
    PALANM_CopyToSlot(work->paletteAnim,
                  (const u8 *)work->iconPalette.data + ((d_021F3541[x] & 0xf) << 5), 3,
                  (u16)((icon->index + 9) << 4), 0x20);
}

void BEACON_VIEW_LoadEntryStatus(BeaconViewWork *work, BeaconViewEntry *icon, int statusIndex)
{
    CLACT_TransferCharacter(work->statusLists.images.items[icon->index], work->statusRes[statusIndex].data);
}

int BEACON_VIEW_GetPmVersion(struct GameBeaconInfo *trainerInfo)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion(trainerInfo)) {
    case 21: return 0;
    case 20: return 1;
    default: return 2;
    }
}

void BEACON_VIEW_LoadEntryPanelColor(BeaconViewWork *work, BeaconViewEntry *icon, struct GameBeaconInfo *trainerInfo)
{
    u16 a[5];
    int x;
    int b;
    u16 *t;

    x = BEACON_VIEW_GetPmVersion(trainerInfo);
    b = x * 16;
    t = work->panelPalette.data;
    a[0] = t[b];
    a[1] = t[b + 1];
    a[2] = t[b + 2];
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((u16 *)(&a[3]), trainerInfo);
    PALANM_BlendColors(&a[3], &a[4], 1, 3, 0);
    PALANM_CopyToSlot(work->paletteAnim, a, 3, (u16)((icon->index + 4) * 16 + 1), 10);
}

void BEACON_VIEW_PrintEntryName(BeaconViewWork *work, BeaconViewEntry *icon, void *text, int *busyCounter)
{
    BEACON_VIEW_DrawEntryText(work, icon, text, 0x3c60, busyCounter);
}

void BEACON_VIEW_PrintEntryFrames(BeaconViewWork *work, BeaconViewEntry *icon, int force, int *busyCounter)
{
    u8 c;

    c = (GAME_BEACON_GetReceivedFramesByTrainerId(icon->trainerId) >= 0x2a30) ? 1 : 0;
    if (c == icon->frequent && force == 0) {
        return;
    }
    icon->frequent = c;
    if (c != 0) {
        BEACON_VIEW_DrawEntryText(work, icon, icon->messageString, 0xca0, busyCounter);
    } else {
        BEACON_VIEW_DrawEntryText(work, icon, icon->messageString, 0x3c60, busyCounter);
    }
}

void BEACON_VIEW_PrintEntryRank(BeaconViewWork *work, BeaconViewEntry *icon, struct GameBeaconInfo *record)
{
    u8 v;
    int k;

    icon->flags = GAME_BEACON_ACCESSOR_GetResearchTeamRank(record);
    v = icon->flags;
    if (v == 0) {
        k = 0x30;
        v = 5;
    } else {
        k = 0x35;
    }
    PALANM_CopyToSlot(work->paletteAnim, work->panelPalette.data + 0x30, (int)3, (u16)((icon->index + 4) * 16 + 8), 10);
    PALANM_CopyToSlot(work->paletteAnim, work->panelPalette.data + k, (int)3, (u16)((icon->index + 4) * 16 + 8), v * 2);
}

void BEACON_VIEW_SetupEntry(BeaconViewWork *work, BeaconViewEntry *icon, struct GameBeaconInfo *record, int mode, int skip, int *busyCounter)
{
    icon->trainerId = GAME_BEACON_ACCESSOR_GetTrainerId(record);
    icon->gender = GAME_BEACON_ACCESSOR_GetSex(record);
    GAME_BEACON_ACCESSOR_GetPlayerName(record, icon->messageString);
    STRBUF_Clear(icon->nameString);
    GAME_BEACON_ACCESSOR_GetGreeting(record, icon->nameString);
    BEACON_VIEW_PrintEntryRank(work, icon, record);
    BEACON_VIEW_LoadEntryPanel(work, icon, record);
    BEACON_VIEW_LoadEntryPanelColor(work, icon, record);
    if (skip != 0)
        return;
    switch (mode) {
    case 0:
        switch (GAME_BEACON_ACCESSOR_GetActionNo((struct GameBeaconInfo *)record)) {
        case 0x18:
            GAME_BEACON_ACCESSOR_GetThanksName(record, (work->messageBuffer));
            BEACON_VIEW_PrintEntryName(work, icon, work->messageBuffer, busyCounter);
            break;
        case 0x31:
            GAME_BEACON_ACCESSOR_GetFreeText(record, (work->messageBuffer));
            BEACON_VIEW_PrintEntryName(work, icon, work->messageBuffer, busyCounter);
            break;
        }
        BEACON_VIEW_StartIconWait(work, icon, record, 0);
        break;
    case 1:
        BEACON_VIEW_PrintEntryName(work, icon, icon->nameString, busyCounter);
        BEACON_VIEW_StartIconWait(work, icon, record, 1);
        break;
    case 2:
        BEACON_VIEW_PrintEntryFrames(work, icon, 1, busyCounter);
        break;
    }
}

void BEACON_VIEW_SetEntryPosition(BeaconViewEntry *icon, short x, short y)
{
    icon->x = x;
    icon->y = y;
    BEACON_VIEW_MoveActorSurface(icon->panelActor, x, y);
    BEACON_VIEW_MoveActorSurface(icon->iconActor, x + 0x20, y + 0x18);
    BEACON_VIEW_MoveActorSurface(icon->statusActor, x + 0x3c, y + 0x18);
    BMP_OAM_SetPos(icon->textWindow, x + 0x48, y + 0x10);
}

void BEACON_VIEW_RefreshTopEntry(BeaconViewWork *work)
{
    int i;
    BeaconViewEntry *icon;

    for (i = 0; i < work->visibleRows; i++) {
        icon = (BeaconViewEntry *)BEACON_VIEW_GetEntry(work, (u8)GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, work->scrollTop + i));
        if (icon->activeTask == 0 || icon->busy != 0)
            BEACON_VIEW_PrintEntryFrames(work, icon, 0, 0);
    }
}

/*
 * Byte-correct; the only wildcard is the bl to BEACON_STATUS_SetViewTop (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, the integrator's). Verified
 * leaf C (EXACT, arm9 0x020275B8, thumb, 12 bytes incl. pool word 0x0B0E):
 *   typedef unsigned char u8;
 *   void BEACON_STATUS_SetViewTop(char *p, u8 v) { p[0xb0e] = v; }
 * The this+0x7c/0x7d reads are volatile: the original re-reads them.
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void BEACON_VIEW_ScrollList(BeaconViewWork *work, int dir)
{
    u8 t;
    int n;
    u8 idx;

    BEACON_VIEW_PlaySe(0x54b);
    if (dir == 0) {
        t = *(volatile u8 *)&work->scrollTop + *(volatile u8 *)&work->visibleRows;
        n = *(volatile u8 *)&work->scrollTop + 1;
    } else {
        t = *(volatile u8 *)&work->scrollTop - 1;
        n = *(volatile u8 *)&work->scrollTop - 1;
    }
    *(volatile u8 *)&work->scrollTop = n;
    BEACON_STATUS_SetViewTop(work->beaconStatus, *(volatile u8 *)&work->scrollTop);
    GAME_BEACON_ACCESSOR_TableRingGet(work->recordLog, work->recordBuffer, (u16 *)((u8 *)&work->tagBuffer), t);
    idx = GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, t);
    BEACON_VIEW_StartEntryMove(work, work->recordBuffer, idx, (u8)dir, 2);
}

void BEACON_VIEW_StartSlide(BeaconViewWork *work, int target, u8 result)
{
    work->animActive = 1;
    *(char *)&work->fadeStarted = 0;
    work->slideTarget = target;
    *(char *)&work->fadeResult = result;
    work->slideTimer = 0;
    BEACON_VIEW_SetPrintQueueLimit(work, 1);
    if (work->slideTarget == 0)
        BEACON_VIEW_SetActorAnim(work->actors[5], 0x13);
    else
        BEACON_VIEW_SetActorAnim(work->actors[4], 0xf);
    BEACON_VIEW_SetArrowAnim(work, 4, 2);
    BEACON_VIEW_ScrollList(work, target);
}

void BEACON_VIEW_StartEntryMove(BeaconViewWork *work, struct GameBeaconInfo *record, int slot, int destSlot, int mode)
{
    BeaconViewEntry *icon;
    BeaconViewIconMoveTask *task;

    icon = (BeaconViewEntry *)BEACON_VIEW_GetEntry(work, 0xff);
    if (icon != 0) {
        task = TCBL_GetWork(TCBL_AddTask(work->taskList, BEACON_VIEW_IconMoveTask, sizeof(BeaconViewIconMoveTask), 0));
        MI_CpuFill8(task, 0, sizeof(BeaconViewIconMoveTask));
        task->work = work;
        task->slot = destSlot;
        task->entry = icon;
        task->mode = mode;
        task->busyCounter = &work->busyCount;
        work->busyCount = work->busyCount + 1;
        BEACON_VIEW_SetEntrySlot(icon, slot, 0);
        BEACON_VIEW_SetupEntry(work, icon, (void *)record, mode, 0, (int *)&task->timer);
    }
}

void BEACON_VIEW_IconMoveTask(struct TcblTask *tcb, void *taskArg)
{
    BeaconViewIconMoveTask *task = taskArg;
    void *this;

    this = (void *)task->work;
    if (task->timer > 0)
        return;
    if (task->phase == 0) {
        BEACON_VIEW_SetEntryVisible(task->entry, 1);
        if (task->mode == 1) {
            BEACON_VIEW_MoveEntryToPeer(this, task->entry, (int *)&task->timer);
            BEACON_VIEW_SetEntryStatusVisible(task->entry, 1);
        } else {
            BEACON_VIEW_MoveEntryToSlot(this, task->slot, task->entry, 0, (int *)&task->timer);
        }
        task->phase = task->phase + 1;
        return;
    }
    if (task->busyCounter != 0)
        *(task->busyCounter) = *(task->busyCounter) - 1;
    TCBL_DeleteTask(tcb);
}

void BEACON_VIEW_MoveEntryToSlot(BeaconViewWork *work, int mode, BeaconViewEntry *icon, BeaconViewEntry *otherIcon, int *busyCounter)
{
    int i;
    BeaconViewEntry *newIcon;

    if (icon != 0) {
        if (mode == 0)
            icon->state = 5;
        else
            icon->state = 0;
        BEACON_VIEW_SetEntryPosition(icon, -13 * (1 - icon->state), -40 * (1 - icon->state));
        BEACON_VIEW_SetEntryVisible(icon, 1);
    }
    for (i = 0; i < 5; i++) {
        newIcon = &work->icons[i];
        if (newIcon->peerSlot != 0xff) {
            if (otherIcon == 0 || newIcon->index != otherIcon->index)
                BEACON_VIEW_StartEntrySlide(work, newIcon, mode, 0, busyCounter);
        }
    }
}

void BEACON_VIEW_MoveEntryToPeer(BeaconViewWork *work, BeaconViewEntry *icon, int *busyCounter)
{
    int k;

    icon->state = 1;
    BEACON_VIEW_SetEntryPosition(icon, -208, 0);
    BEACON_VIEW_SetEntryVisible(icon, 1);
    k = 0;
    if (work->recordCount != 0)
        k = 8;
    BEACON_VIEW_StartEntrySlide(work, icon, 2, (u8)k, busyCounter);
    BEACON_VIEW_MoveEntryToSlot(work, 1, 0, icon, busyCounter);
}

void BEACON_VIEW_StartEntrySlide(BeaconViewWork *work, BeaconViewEntry *icon, int mode, u8 delay, int *busyCounter)
{
    BeaconViewIconSlideTask *task;

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, BEACON_VIEW_IconSlideTask, sizeof(BeaconViewIconSlideTask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewIconSlideTask));
    task->mode = mode;
    if (task->mode == 0) {
        icon->state = icon->state - 1;
    } else if (task->mode == 1) {
        icon->state = icon->state + 1;
    }
    task->work = work;
    task->entry = icon;
    task->targetX = (1 - icon->state) * -13;
    task->targetY = (1 - icon->state) * -40;
    task->x = FX32_CONST(icon->x);
    task->y = FX32_CONST(icon->y);
    task->steps = 8;
    task->delay = delay;
    task->deltaX = FX_Div(FX32_CONST(task->targetX - icon->x), FX32_CONST(task->steps));
    task->deltaY = FX_Div(FX32_CONST(task->targetY - icon->y), FX32_CONST(task->steps));
    task->busyCounter = busyCounter;
    (*busyCounter)++;
}

void BEACON_VIEW_IconSlideTask(struct TcblTask *tcb, void *taskArg)
{
    BeaconViewIconSlideTask *task = taskArg;
    BeaconViewEntry *icon;

    switch (task->phase) {
    case 0:
        if (task->delay != 0) {
            task->delay = task->delay - 1;
            return;
        }
        task->step = task->step + 1;
        if (task->step < task->steps) {
            int x = task->x + task->deltaX;
            int y = task->y + task->deltaY;
            task->x = x;
            task->y = y;
            BEACON_VIEW_SetEntryPosition(task->entry, (short)(x >> 12), (short)(y >> 12));
            return;
        }
        BEACON_VIEW_SetEntryPosition(task->entry, task->targetX, task->targetY);
        icon = task->entry;
        if (icon->state == 0 || icon->state == 5) {
            task->phase = task->phase + 1;
            return;
        }
        break;
    case 1:
    default:
        icon = task->entry;
        if (icon->busy != 0)
            return;
        BEACON_VIEW_ResetEntry(icon);
        break;
    }
    *task->busyCounter = *task->busyCounter - 1;
    TCBL_DeleteTask(tcb);
}

void BEACON_VIEW_StartScrollStep(BeaconViewWork *work, u8 phase, int *busyCounter)
{
    BeaconViewScrollStepTask *task;
    int v;

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, BEACON_VIEW_ScrollStepTask, 0xc, 0));
    MI_CpuFill8(task, 0, 0xc);
    task->phase = phase;
    if (task->phase == 0) {
        task->position = 0;
        v = 0x10;
    } else {
        v = 0x40;
        task->position = v;
        v -= 0x50;
    }
    task->delta = v;
    task->steps = 4;
    task->busyCounter = busyCounter;
    *busyCounter = *busyCounter + 1;
}

void BEACON_VIEW_ScrollStepTask(struct TcblTask *task, void *taskDataArg)
{
    BeaconViewScrollStepTask *taskData = taskDataArg;
    u32 old;
    int x;
    old = taskData->step;
    taskData->step = old + 1;
    if (old < taskData->steps) {
        x = *(signed char *)&taskData->position;
        taskData->position = x + *(signed char *)&taskData->delta;
        BG_SYS_ChangeScrollImmediate(6, 3, *(signed char *)&taskData->position);
        return;
    }
    (*taskData->busyCounter)--;
    TCBL_DeleteTask(task);
}

int BEACON_VIEW_HandleRecordAction(BeaconViewWork *work, struct GameBeaconInfo *record, int flag)
{
    int k;

    k = GAME_BEACON_ACCESSOR_GetActionNo(record);
    if (flag != 0) {
        GAME_BEACON_ACCESSOR_RegisterRecordWords(record, work->wordSet, work->uiHeapId);
        BEACON_VIEW_ShowFormatMessage(work, 0x12);
        return 1;
    }
    switch (k) {
    case 1:
        return 0;
    case 0x12:
        return BEACON_VIEW_HandlePowerRecord(work, record, 0);
    case 0x32:
        return BEACON_VIEW_HandlePowerRecord(work, record, 1);
    case 0x18:
        GAME_BEACON_SEARCH_SetPresetEvent(MISC_IncrementGreetCount(work->playerBlock));
        break;
    }
    BEACON_VIEW_ShowRecordMessage(work, record);
    return 1;
}

void BEACON_VIEW_ShowRecordMessage(BeaconViewWork *work, struct GameBeaconInfo *record)
{
    GAME_BEACON_ACCESSOR_RegisterRecordWords((struct GameBeaconInfo *)record, work->wordSet, work->uiHeapId);
    BEACON_VIEW_SetupMessageText(work, (u8)BEACON_VIEW_GetActionVariant(record));
    BEACON_VIEW_StartFadeTask(work, work->formatBuffer, &work->busyCount);
}

void BEACON_VIEW_ShowFormatMessage(BeaconViewWork *work, int messageId)
{
    BEACON_VIEW_SetupMessageText(work, messageId);
    BEACON_VIEW_StartFadeTask(work, work->formatBuffer, &work->busyCount);
}

void BEACON_VIEW_StartFadeTask(BeaconViewWork *work, struct Strbuf *text, int *busyCounter)
{
    BeaconViewFadeTask *task;

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, BEACON_VIEW_FadeTask, sizeof(BeaconViewFadeTask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewFadeTask));
    STRBUF_Copy(work->stringList, (struct Strbuf *)text);
    task->work = work;
    task->duration = 0x5a;
    BEACON_VIEW_SetArrowAnim(work, 4, 2);
    task->busyCounter = busyCounter;
    (*busyCounter)++;
}

void BEACON_VIEW_FadeTask(struct TcblTask *task, void *taskDataArg)
{
    BeaconViewFadeTask *taskData = taskDataArg;
    if (taskData->frames != 0)
        return;
    switch (taskData->phase) {
    case 0:
        BEACON_VIEW_ShowWindowText(taskData->work, taskData->work->stringList, (int *)&taskData->frames);
        taskData->phase++;
        return;
    case 1:
        BEACON_VIEW_StartScrollStep(taskData->work, 0, (int *)&taskData->frames);
        taskData->phase++;
        return;
    case 2:
        if (BEACON_VIEW_CheckWindowTouch((u8 *)&taskData->duration) != 0) {
            BEACON_VIEW_StartScrollStep(taskData->work, 1, (int *)&taskData->frames);
            taskData->phase++;
        }
        return;
    default:
        (*taskData->busyCounter)--;
        TCBL_DeleteTask(task);
        return;
    }
}

int BEACON_VIEW_HandlePowerRecord(BeaconViewWork *work, struct GameBeaconInfo *x, int flag)
{
    int r;

    if (flag)
        r = GAME_BEACON_ACCESSOR_GetDistributionSerial(x);
    else
        r = GAME_BEACON_ACCESSOR_GetInfoVersion(x);
    if (r == 0x30 || r > 0x2d)
        return 0;
    if (r == GPOWER_GetActiveIdOfSameType(r, work->powerRecord))
        return 0;
    GAME_BEACON_ACCESSOR_RegisterRecordWords(x, work->wordSet, work->uiHeapId);
    WORDSET_CopyTaggedText(work->wordSet, work->formatBuffer, work->messageBuffer);
    BEACON_VIEW_StartPowerAnim(work, r, 1, &work->busyCount);
    return 1;
}

void BEACON_VIEW_ShowActivePower(BeaconViewWork *work)
{
    BEACON_VIEW_StartPowerAnim(work, work->powerId, 0, &work->busyCount);
}

void BEACON_VIEW_ShowPowerAnim(BeaconViewWork *work, int powerId)
{
    BEACON_VIEW_StartPowerAnim(work, powerId, 2, &work->busyCount);
}

/*
 * Byte-correct; the only wildcard is the bl to GPOWER_GetPowerCost (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, the integrator's; it sits
 * in the word run after GPOWER_GetActiveIdOfSameType/GPOWER_GetSelectedMinutesLeft). Verified leaf C
 * (EXACT, arm9 0x02010FA0, thumb, `one --thumb` with no --region):
 *   typedef unsigned short u16;
 *   u16 GPOWER_GetPowerCost(unsigned char *rec, int slot)
 *   { return *(u16 *)(rec + slot * 0xc + 2); }
 * `u8 c` and `int flag` with `flag = 0` after the p[0x7f] store are what
 * put the flag's zero store after the argument copies.
 */
void BEACON_VIEW_StartPowerAnim(BeaconViewWork *work, int powerId, u8 mode, int *busyCounter)
{
    void *h;
    int flag;
    BeaconViewPowerAnimTask *task;

    h = TCBL_AddTask(work->taskList, BEACON_VIEW_PowerAnimTaskA, sizeof(BeaconViewPowerAnimTask), 0);
    task = TCBL_GetWork(h);
    MI_CpuFill8(task, 0, sizeof(BeaconViewPowerAnimTask));
    work->powerIdArg = 0x30;
    flag = 0;
    if (mode == 0)
        flag = 1;
    work->powerFlagArg = flag;
    task->work = work;
    task->duration = 0x5a;
    task->powerId = powerId;
    task->mode = mode;
    WORDSET_SetSlotFromMsgA0(work->wordSet, 1, powerId);
    if (task->mode == 0) {
        task->cost = GPOWER_GetPowerCost(work->powerRecord, powerId);
        task->nameStringId = MYITEM_SAVEDATA_GetItemQuantity(work->myItem, 0x23f, work->uiHeapId);
        WORDSET_SetSlotNumber(work->wordSet, 2, task->cost, 3, 0, 1);
        WORDSET_SetSlotNumber(work->wordSet, 3, task->nameStringId, 3, 0, 1);
        if (powerId == GPOWER_GetActiveIdOfSameType(powerId, work->powerRecord)) {
            task->minutesLeft = GPOWER_GetSelectedMinutesLeft();
            if (task->minutesLeft != 0) {
                task->hours = task->minutesLeft / 60;
                task->minutes = task->minutesLeft % 60;
                WORDSET_SetSlotNumber(work->wordSet, 4, task->hours, 3, 0, 1);
                WORDSET_SetSlotNumber(work->wordSet, 5, task->minutes, 2, 0, 1);
            }
        }
    }
    if (task->mode != 0)
        BEACON_VIEW_SetArrowAnim(work, 0, 2);
    BEACON_VIEW_SetArrowAnim(work, 1, 2);
    BEACON_VIEW_SetArrowAnim(work, 2, 2);
    BEACON_VIEW_SetArrowAnim(work, 3, 2);
    if (task->minutesLeft != 0 || task->nameStringId < task->cost)
        TCBL_SetTaskFunc(h, BEACON_VIEW_PowerAnimTaskB);
    task->busyCounter = busyCounter;
    (*busyCounter)++;
}

void BEACON_VIEW_PowerAnimTaskA(struct TcblTask *tcb, void *taskArg)
{
    BeaconViewPowerAnimTask *task = taskArg;
    BeaconViewWork *work;
    int r;

    work = task->work;
    if (task->timer > 0)
        return;
    switch (task->phase) {
    case 0:
        BEACON_VIEW_SetupMessageText(work, d_021F352C[task->mode]);
        BEACON_VIEW_ShowWindowText(work, work->formatBuffer, (int *)&task->timer);
        task->phase++;
        break;
    case 1:
        BEACON_VIEW_StartScrollStep(work, 0, (int *)&task->timer);
        task->phase++;
        break;
    case 2:
        BEACON_VIEW_SetPrintQueueLimit(work, 1);
        BEACON_VIEW_CreateTaskMenuButtons(work, 0);
        BEACON_VIEW_ClearWindow(work);
        BEACON_VIEW_SetActorVisible(work, 0);
        task->phase++;
        break;
    case 3:
        r = BEACON_VIEW_UpdateTaskMenuButtons(work, 0);
        if (r < 0)
            break;
        task->result = r;
        switch (task->result) {
        case 0:
            BEACON_VIEW_SetEndRequest(work, 6);
            task->phase = 3;
            break;
        case 1:
            work->powerIdArg = task->powerId;
            BEACON_VIEW_SetEndRequest(work, 5);
            task->phase = 4;
            break;
        case 2:
            task->phase = 5;
            break;
        }
        break;
    case 4:
        if (*(u8 *)&work->powerIdArg != 0x30) {
            work->powerIdArg = 0x30;
            task->phase = 3;
            break;
        }
        BEACON_VIEW_DeleteTaskMenuButtons(work);
        task->phase = 6;
        break;
    case 5:
        if (BEACON_VIEW_FinishTaskMenuButtons(work, task->result) == 0)
            break;
        task->phase++;
        break;
    case 6:
        BEACON_VIEW_ShowPlayTime(work, 1, (int *)&task->timer);
        BEACON_VIEW_SetActorVisible(work, 1);
        BEACON_VIEW_StartScrollStep(work, 1, (int *)&task->timer);
        task->phase++;
        break;
    default:
        BEACON_VIEW_SetArrowAnim(work, 4, 0);
        BEACON_VIEW_SetPrintQueueLimit(work, 0);
        (*task->busyCounter)--;
        TCBL_DeleteTask(tcb);
        break;
    }
}

void BEACON_VIEW_PowerAnimTaskB(struct TcblTask *tcb, void *taskArg)
{
    BeaconViewPowerAnimTask *task = taskArg;
    BeaconViewWork *work;
    int r;

    work = task->work;
    if (task->timer > 0)
        return;
    switch (task->phase) {
    case 0:
        if (task->minutesLeft != 0)
            BEACON_VIEW_SetupMessageText(work, (u8)((task->hours != 0 ? 1 : 0) + 9));
        else if (task->nameStringId < task->cost)
            BEACON_VIEW_SetupMessageText(work, (u8)8);
        BEACON_VIEW_ShowWindowText(work, work->formatBuffer, (int *)&task->timer);
        task->phase++;
        break;
    case 1:
        BEACON_VIEW_StartScrollStep(work, 0, (int *)&task->timer);
        task->phase++;
        break;
    case 2:
        BEACON_VIEW_SetActorVisible(work, 0);
        task->phase++;
        break;
    case 3:
        BEACON_VIEW_CreateTaskMenuButtons(work, 1);
        BEACON_VIEW_ClearWindow(work);
        task->phase++;
        break;
    case 4:
        r = BEACON_VIEW_UpdateTaskMenuButtons(work, 1);
        if (r < 0)
            break;
        task->result = r;
        if (task->result == 0) {
            BEACON_VIEW_SetEndRequest(work, 7);
            work->resetFlag = 1;
            task->phase = 5;
        } else {
            task->phase = 6;
        }
        break;
    case 5:
        if (*(unsigned char *)&work->resetFlag != 0) {
            task->phase = 4;
            break;
        }
        BEACON_VIEW_DeleteTaskMenuButtonsAlt(work);
        task->phase = 7;
        break;
    case 6:
        if (BEACON_VIEW_FinishTaskMenuButtonsAlt(work, task->result) == 0)
            break;
        task->phase++;
        break;
    case 7:
        BEACON_VIEW_ShowPlayTime(work, 1, (int *)&task->timer);
        BEACON_VIEW_SetActorVisible(work, 1);
        BEACON_VIEW_StartScrollStep(work, 1, (int *)&task->timer);
        task->phase++;
        break;
    default:
        BEACON_VIEW_SetArrowAnim(work, 4, (int)0);
        (*task->busyCounter)--;
        TCBL_DeleteTask(tcb);
        break;
    }
}

void BEACON_VIEW_StartIconWait(BeaconViewWork *work, BeaconViewEntry *icon, void *x, int flag)
{
    void *t;
    BeaconViewIconWaitTask *task;

    t = TCBL_AddTask(work->taskList, BEACON_VIEW_IconWaitTask, 0x18, 0);
    task = TCBL_GetWork(t);
    MI_CpuFill8(task, 0, 0x18);
    task->work = work;
    task->entry = icon;
    task->delay = 0x5a;
    icon->activeTask = t;
    if (flag)
        task->timer = 1;
    else
        task->timer = GAME_BEACON_ACCESSOR_GetActionNo((struct GameBeaconInfo *)x);
    BEACON_VIEW_LoadEntryStatus(work, icon, GAME_BEACON_ACCESSOR_GetActionViewVariant(task->timer));
    BEACON_VIEW_SetEntryStatusVisible(icon, flag ? 0 : 1);
}

void BEACON_VIEW_IconWaitTask(struct TcblTask *task, void *taskDataArg)
{
    BeaconViewIconWaitTask *taskData = taskDataArg;
    if (taskData->phase == 0) {
        u8 c = taskData->delay;
        taskData->delay = c - 1;
        if (c != 0)
            return;
        if (taskData->timer == 1 || taskData->timer == 0x18 || taskData->timer == 0x31) {
            BEACON_VIEW_PrintEntryFrames(taskData->work, taskData->entry, 1, 0);
            taskData->phase++;
            return;
        }
    } else {
        if (taskData->entry->busy != 0)
            return;
    }
    taskData->entry->activeTask = 0;
    BEACON_VIEW_SetEntryStatusVisible(taskData->entry, 0);
    TCBL_DeleteTask(task);
}

void BEACON_VIEW_ShowTouchedRow(BeaconViewWork *work, int row)
{
    BeaconViewEntry *icon;
    u8 index;
    index = GAME_BEACON_ACCESSOR_TableGetRingIndex(work->recordLog, row + work->scrollTop);
    icon = BEACON_VIEW_GetEntry(work, index);
    BEACON_VIEW_StartWindowATask(work, icon, &work->busyCount);
    BEACON_VIEW_PlaySe(0x54c);
}

void BEACON_VIEW_StartWindowATask(BeaconViewWork *work, BeaconViewEntry *icon, int *busyCounter)
{
    BeaconViewWindowATask *task;

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, BEACON_VIEW_WindowATask, sizeof(BeaconViewWindowATask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewWindowATask));
    task->work = work;
    task->entry = icon;
    task->interval = 2;
    task->paletteOffset = (icon->index + 4) << 4;
    PALANM_BlendChannel(task->work->paletteAnim, 3, task->paletteOffset, 0x10, 4, 0x7fff);
    if (busyCounter != 0) {
        task->busyCounter = busyCounter;
        (*busyCounter)++;
    }
}

void BEACON_VIEW_WindowATask(struct TcblTask *task, void *taskDataArg)
{
    BeaconViewWindowATask *taskData = taskDataArg;
    u8 c = taskData->phase;

    if (c < 2) {
        if (taskData->counter++ >= taskData->interval) {
            PALANM_BlendChannel(taskData->work->paletteAnim, 3, taskData->paletteOffset, 0x10, (c % 2) << 2, 0x7fff);
            taskData->phase++;
            taskData->counter = 0;
        }
    } else {
        int *r;

        PALANM_BlendChannel(taskData->work->paletteAnim, 3, taskData->paletteOffset, 0x10, 0, 0x7fff);
        r = taskData->busyCounter;
        if (r != 0)
            (*r)--;
        TCBL_DeleteTask(task);
    }
}

void BEACON_VIEW_DrawWindowText(BeaconViewWork *work, BeaconViewWindow *window, void *text, u16 x, u8 y, u8 fillColor, u16 col, int *busyCounter)
{
    struct BmpWin *w;
    struct PrintQueue *v;

    BMP_Clear(window->bitmap, fillColor);
    if (work->windowShown != 0) {
        PRINTSYS_PrintColor(window->bitmap, x, y, text, work->font, col);
        w = window->handle;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
        return;
    }
    v = work->printQueue;
    PRINTSYS_PrintQueColor(v, BMP_WIN_GetBmp(window->layout), x, y, text,
                  work->font, col);
    window->drawn = 1;
    BEACON_VIEW_StartWindowBTask(work, window, busyCounter);
}

void BEACON_VIEW_StartWindowBTask(BeaconViewWork *work, BeaconViewWindow *window, int *busyCounter)
{
    BeaconViewWindowBTask *task;
    task = TCBL_GetWork(TCBL_AddTask(work->taskList, BEACON_VIEW_WindowBTask, sizeof(BeaconViewWindowBTask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewWindowBTask));
    task->work = work;
    task->window = window;
    if (busyCounter != 0) {
        task->busyCounter = busyCounter;
        (*busyCounter)++;
    }
}

void BEACON_VIEW_WindowBTask(struct TcblTask *task, void *taskDataArg)
{
    BeaconViewWindowBTask *taskData = taskDataArg;
    u8 *drawn;
    uptr v;
    int *r;

    v = (uptr)taskData->work->printQueue;
    drawn = (u8 *)taskData->window + 8;
    if (drawn[4] != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)v, (void *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor **)drawn)))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)(*(struct Descriptor **)drawn));
            drawn[4] = 0;
        }
    }
    if (drawn[4] == 0) {
        BMP_WIN_MakeScreen((struct BmpWin *)taskData->window->handle);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)taskData->window->handle));
        r = taskData->busyCounter;
        if (r != 0)
            (*r)--;
        TCBL_DeleteTask(task);
    }
}

void BEACON_VIEW_DrawEntryText(BeaconViewWork *work, BeaconViewEntry *icon, void *text, u16 col, int *busyCounter)
{
    void **t;

    t = (void **)&icon->textWindow;
    BMP_Clear((struct Bmp *)t[1], 0);
    if (work->windowShown != 0) {
        PRINTSYS_PrintColor((struct Bmp *)t[1], 0, 0, text, work->font, col);
        BMP_OAM_UploadChars((struct BmpOam *)t[0]);
        return;
    }
    PRINTSYS_PrintQueColor(work->printQueue, (struct Bmp *)t[1], 0, 0, text, work->font, col);
    BEACON_VIEW_StartWindowCTask(work, icon, busyCounter);
}

void BEACON_VIEW_StartWindowCTask(BeaconViewWork *work, BeaconViewEntry *icon, int *busyCounter)
{
    void *t;
    BeaconViewWindowCTask *task;

    t = TCBL_AddTask(work->taskList, BEACON_VIEW_WindowCTask, sizeof(BeaconViewWindowCTask), 0);
    task = TCBL_GetWork(t);
    MI_CpuFill8(task, 0, sizeof(BeaconViewWindowCTask));
    task->work = work;
    task->entry = icon;
    task->windowRef = (void **)&icon->textWindow;
    icon->busy = t;
    if (busyCounter != 0) {
        task->busyCounter = busyCounter;
        (*busyCounter)++;
    }
}

void BEACON_VIEW_WindowCTask(struct TcblTask *task, void *taskDataArg)
{
    BeaconViewWindowCTask *taskData = taskDataArg;
    int *r;
    if (PRINTSYS_QUE_IsExistTarget(taskData->work->printQueue, taskData->windowRef[1]) == 0) {
        BMP_OAM_UploadChars((struct BmpOam *)taskData->windowRef[0]);
        r = taskData->busyCounter;
        if (r != 0)
            (*r)--;
        taskData->entry->busy = 0;
        TCBL_DeleteTask(task);
    }
}

BeaconViewWork *BEACON_VIEW_Create(struct GameSystem *fieldSystem, void *initArg)
{
    BeaconViewWork *work;
    struct FieldMap *v;

    work = GFL_HEAP_Alloc(0x70, 0x3d0, 1, d_021F36A0, 0x8d);
    work->fieldSystem = fieldSystem;
    work->saveInfo = GAMESYSTEM_GetGameData(fieldSystem);
    work->sessionInfo = v = GAMESYSTEM_GetFieldMap(fieldSystem);
    work->bgConfig = FIELDMAP_GetVReq(v);
    work->initArg = initArg;
    work->mainHeapId = 0x70;
    work->tempHeapId = 0x15;
    work->uiHeapId = 0x8070;
    work->bgResource = ARC_TOOL_CreateHandle(0xad, work->mainHeapId);
    BEACON_VIEW_InitWorkFromSave(work);
    BEACON_VIEW_CreateSubSystems(work);
    BEACON_VIEW_InitBackgrounds(work, work->bgResource);
    BEACON_VIEW_CreateTaskMenuRes(work);
    BEACON_VIEW_LoadGraphics(work, work->bgResource);
    BEACON_VIEW_CreateActors(work, work->bgResource);
    BEACON_VIEW_CreateWindows(work);
    work->windowShown = 1;
    BEACON_VIEW_InitList(work);
    work->windowShown = 0;
    *(u32 *)&work->lastRequest = 0;
    BEACON_VIEW_SetFadeState(work, 1);
    return work;
}

void BEACON_VIEW_Delete(BeaconViewWork *work)
{
    TCBL_DeleteAllTasks((struct TcblSystem *)(work->taskList));
    BEACON_VIEW_DeleteWindows(work);
    BEACON_VIEW_DeleteActors(work);
    BEACON_VIEW_FreeGraphics(work);
    BEACON_VIEW_DeleteTaskMenuRes(work);
    BEACON_VIEW_FreeBackgrounds(work);
    BEACON_VIEW_DestroySubSystems(work);
    BEACON_VIEW_FreeWorkResources(work);
    ARC_TOOL_DeleteHandle((void *)(uptr)work->bgResource);
    GFL_HEAP_Free(work);
}

void BEACON_VIEW_Update(BeaconViewWork *work, int request)
{
    int f;

    if (work->lastRequest != request) {
        int c;

        if (work->endRequest != 0 && request == 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            f = 1;
            work->lastRequest = request;
            if (request != 0) {
                f = 0;
            }
            BEACON_VIEW_SetFadeState(work, f);
        }
    }
    if (work->eventFlags != 0) {
        if (request == 0) {
            BEACON_VIEW_ClearEndRequest(work);
            return;
        }
        return;
    }
    if (request != 0) {
        TCBL_Main(work->taskList);
        switch (work->mode) {
        case 0:
            work->mode = BEACON_VIEW_UpdateList(work);
            break;
        case 1:
            work->mode = BEACON_VIEW_RunRecordArrival(work);
            break;
        case 2:
            work->mode = BEACON_VIEW_UpdateFadeWait(work);
            break;
        case 3:
            work->mode = BEACON_VIEW_UpdateSlide(work);
            break;
        case 4:
            work->mode = BEACON_VIEW_RunPowerAnimStart(work);
            break;
        case 5:
            work->mode = BEACON_VIEW_RunSelect(work);
            break;
        case 6:
        case 7:
            break;
        }
        GAME_BEACON_ACCESSOR_TableAddNewLogs(work->receiveQueue);
    }
}

/*
 * Byte-correct; the only wildcards are the bls to two unlabelled arm9
 * leaves, the integrator's (blocker: no witness outside the range). Verified leaf C
 * (both EXACT, thumb, `one --thumb` with no --region):
 *   0x020275B8 (12 bytes incl. pool word 0x0B0E):
 *     typedef unsigned char u8;
 *     void BEACON_STATUS_SetViewTop(char *p, u8 v) { p[0xb0e] = v; }
 *   0x020275D0 (12 bytes incl. pool word 0x0B0C):
 *     void *BEACON_STATUS_GetViewFlags(char *p) { return p + 0xb0c; }
 * 0x53 is ov083's id (GPOWER_EVENT_CreateActivateEvent/GPOWER_EVENT_CreateListEvent are ov083 children).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
u32 BEACON_VIEW_MainPrintQueue(BeaconViewWork *work)
{
    return PRINTSYS_QUE_Main(work->printQueue);
}

void *BEACON_VIEW_CreateLeaveEvent(BeaconViewWork *work, int go)
{
    void *r;
    Args args;

    if (go == 0)
        return 0;
    switch (work->eventFlags) {
    case 2:
        INTRUDE_COMM_SetCompleted(work->playerProfile);
    case 1:
    case 3:
        BEACON_STATUS_SetViewTop(work->beaconStatus, 0);
        r = BEACON_VIEW_CreateTaskProc(work, FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(work->fieldSystem, work->sessionInfo, 0), 0, 3);
        break;
    case 4:
        r = BEACON_VIEW_CreateTaskProc(work, BEACON_VIEW_EVENT_Create(work->fieldSystem, work->sessionInfo, work->touchedRow + work->scrollTop), 1, 0);
        break;
    case 5:
        args.powerId = *(u8 *)&work->powerIdArg;
        args.powerFlag = *(u8 *)&work->powerFlagArg;
        r = BEACON_VIEW_CreateTaskProc(work, GAME_EVENT_CreateOverlayEvent(work->fieldSystem, (uptr)ov083_id, (void *)GPOWER_EVENT_CreateActivateEvent, &args), 2, (uptr)work->slots[1].taskMenu);
        work->powerIdArg = 0x30;
        break;
    case 6:
        r = BEACON_VIEW_CreateTaskProc(work, GAME_EVENT_CreateOverlayEvent(work->fieldSystem, (uptr)ov083_id, (void *)GPOWER_EVENT_CreateListEvent, work->sessionInfo), 2, (uptr)work->slots[0].taskMenu);
        break;
    case 7:
        r = BEACON_VIEW_CreateTaskProc(work, GAME_EVENT_CreateOverlayEvent(work->fieldSystem, (uptr)ov083_id, (void *)GPOWER_EVENT_CreateListEvent, work->sessionInfo), 2, (uptr)work->slots[3].taskMenu);
        work->resetFlag = 0;
        break;
    case 8:
        r = BEACON_VIEW_CreateTaskProc(work, (EVENT_NAMEIN_Create(work->fieldSystem, work->sessionInfo, 0, 7, (u16 *)BEACON_STATUS_GetViewFlags(work->beaconStatus))), 0, 1);
        break;
    default:
        return 0;
    }
    BEACON_VIEW_ClearEndRequest(work);
    return r;
}

void BEACON_VIEW_SetEndRequest(BeaconViewWork *work, int request)
{
    work->eventFlags = request;
}

void BEACON_VIEW_ClearEndRequest(BeaconViewWork *work)
{
    work->eventFlags = 0;
}

Desc *BEACON_VIEW_CreateTaskProc(BeaconViewWork *work, struct GameEvent *eventDesc, unsigned mode, uptr param)
{
    Desc *d;
    BeaconTaskWork *w;
    d = (Desc *)GAME_EVENT_Create(work->fieldSystem, 0, (GameEventFunc)BEACON_VIEW_TaskProc, 0x1c);
    w = GAME_EVENT_GetWork((struct GameEvent *)d);
    w->owner = work;
    w->fieldSystem = work->fieldSystem;
    w->sessionInfo = work->sessionInfo;
    w->eventDesc = eventDesc;
    w->mode = mode;
    w->param = param;
    work->endRequest = 1;
    return d;
}

int BEACON_VIEW_TaskProc(struct GameEvent *event, int seq, BeaconTaskWork *eventWork)
{
    int r;
    BeaconViewWork *work;

    r = 0;
    work = eventWork->owner;
    switch (eventWork->mode) {
    case 0:
        r = BEACON_VIEW_TaskStateArrowAnim(work, eventWork);
        break;
    case 1:
        r = BEACON_VIEW_TaskStateTasks(work, eventWork);
        break;
    case 2:
        r = BEACON_VIEW_TaskStateTaskMenu(work, eventWork);
        break;
    }
    if (r) {
        work->endRequest = 0;
        GAME_EVENT_ChangeEvent(event, eventWork->eventDesc);
    }
    return 0;
}

int BEACON_VIEW_TaskStateArrowAnim(BeaconViewWork *work, BeaconTaskWork *st)
{
    switch (st->state) {
    case 0:
        BEACON_VIEW_SetArrowAnim(work, st->param, 1);
        st->state++;
        return 0;
    case 1:
        if (BEACON_VIEW_IsArrowAnimActive(work, st->param) != 0)
            return 0;
        break;
    }
    return 1;
}

int BEACON_VIEW_TaskStateTasks(BeaconViewWork *work, BeaconTaskWork *unused)
{
    TCBL_Main(work->taskList);
    if (work->busyCount == 0)
        return 1;
    return 0;
}

int BEACON_VIEW_TaskStateTaskMenu(BeaconViewWork *work, BeaconTaskWork *st)
{
    struct TaskMenuWin *h = (struct TaskMenuWin *)st->param;

    switch (st->state) {
    case 0:
        APP_TASKMENU_WIN_SetDecide(h, 1);
        st->state++;
        break;
    case 1:
        APP_TASKMENU_WIN_Update(h);
        if (APP_TASKMENU_WIN_IsFinish(h)) {
            APP_TASKMENU_WIN_ResetDecide(h);
            return 1;
        }
        break;
    }
    return 0;
}

void BEACON_VIEW_TransferPalettes(struct TcbTask *tcb, void *workArg)
{
    BeaconViewWork *work = workArg;
    if (work->paletteAnim)
        PALANM_TransferPalettes(work->paletteAnim);
}

int BEACON_VIEW_UpdateList(BeaconViewWork *work)
{
    int r;

    if (BEACON_VIEW_ShowViewFlagMessage(work)) {
        work->waitFrames = 90;
        return 2;
    }
    if (BEACON_VIEW_CheckLeaveRequest(work)) {
        return 0;
    }
    r = BEACON_VIEW_UpdateListTouch(work);
    if (r == 0) {
        if (work->waitFrames != 0) {
            work->waitFrames = work->waitFrames - 1;
            return 0;
        }
        if (BEACON_VIEW_ShowNextHistoryPower(work) == 1) {
            work->waitFrames = 90;
            return 2;
        }
        if (BEACON_VIEW_LoadNextRecord(work) == 0) {
            return 0;
        }
        work->waitFrames = 90;
        return 1;
    }
    return r;
}

int BEACON_VIEW_RunRecordArrival(BeaconViewWork *work)
{
    if (BEACON_VIEW_UpdateRecordArrival(work) == 0)
        return 1;
    work->step = 0;
    return 2;
}

int BEACON_VIEW_UpdateFadeWait(BeaconViewWork *work)
{
    if (work->busyCount != 0)
        return 2;
    BEACON_VIEW_SetArrowAnim(work, 4, 0);
    BEACON_VIEW_RefreshActorAnims(work);
    return 0;
}

/*
 * note:     BEACON_VIEW_SetArrowAnim takes three arguments (its own matched file); the
 *           cleared zero is shared with its third argument, which is what
 *           puts the zero in r2 for the three stores.
 */
int BEACON_VIEW_UpdateSlide(BeaconViewWork *work)
{
    int r;

    if (work->fadeStarted == 0) {
        r = BEACON_VIEW_GetContTouchedRow(work);
        if (r != work->slideTarget || r == -1) {
            work->fadeStarted = 1;
        }
        work->slideTimer = work->slideTimer + 1;
    }
    if (work->fadeStarted != 0) {
        if (work->busyCount > 0) {
            return 3;
        }
        work->fadeStarted = 0;
        work->slideTimer = 0;
        *(unsigned char *)&work->animActive = 0;
        if (work->fadeResult == 0) {
            BEACON_VIEW_SetArrowAnim(work, 4, 0);
        }
        BEACON_VIEW_RefreshActorAnims(work);
        BEACON_VIEW_SetPrintQueueLimit(work, 0);
        return work->fadeResult;
    }
    if (work->busyCount == 0) {
        BEACON_VIEW_ApplySlideTarget(work);
    }
    return 3;
}

/*
 * note: extent follower 0x021F27CC is already filed separately.
 */
int BEACON_VIEW_RunPowerAnimStart(BeaconViewWork *work)
{
    if (BEACON_VIEW_UpdatePowerAnimStart(work) == 0)
        return 4;
    work->step = 0;
    return 0;
}

int BEACON_VIEW_RunSelect(BeaconViewWork *work)
{
    return BEACON_VIEW_UpdateSelect(work);
}

/*
 *           wildcarded because their targets are unlabelled arm9 leaves with no
 *           caller outside this range (the integrator's, inside arm9). Each was verified
 *           EXACT with `one --thumb` and no --region:
 *             0x020275A8  u32 BEACON_STATUS_GetLog(u32 a) { return a; }
 *             0x020275AC  u8 BEACON_STATUS_GetViewTop(u8 *p) { return p[0xb0e]; }
 *             0x02010F7C  u32 GPOWER_LoadPowerTable(u32 heap)
 *                         { return ARC_TOOL_LoadMember(0x26, 0, heap); }
 *                         (ARC_TOOL_LoadMember 0x02048F60 arm, a tail call)
 *           Once those three are matched in arm9, this file is EXACT as it stands.
 *           The min of p[0x7b] and 4 must be an if/else of two stores: the
 *           ternary inverts the branch (blo for bhs; b).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void BEACON_VIEW_InitWorkFromSave(BeaconViewWork *work)
{
    uptr sv;
    uptr s2;

    work->beaconStatus = (struct BeaconStatus *)GAME_DATA_GetItemUseWork(work->saveInfo);
    work->recordLog = (struct GameBeaconInfoTable *)BEACON_STATUS_GetLog(work->beaconStatus);
    work->recordCount = GAME_BEACON_ACCESSOR_TableGetCount(work->recordLog);
    work->scrollTop = BEACON_STATUS_GetViewTop(work->beaconStatus);
    if (work->recordCount < 4)
        work->visibleRows = work->recordCount;
    else
        work->visibleRows = 4;
    *(u8 *)&work->powerIdArg = 0x30;
    work->languageCode = MSG_SPEED_GetWait();
    sv = (uptr)GAME_DATA_GetSaveControl(work->saveInfo);
    *(u32 *)&work->powerId = INTRUDE_GetMonolithLevel((struct IntrudeSave *)INTRUDE_GetFromSave((void *)sv));
    work->playerProfile = GAMESYSTEM_GetGameComm(work->fieldSystem);
    work->optionData = GAME_DATA_GetWifiList(work->saveInfo);
    work->myItem = GAME_DATA_GetMyItem(work->saveInfo);
    work->playerBlock = MISC_GetFromSave((void *)sv);
    work->playTime = MISC_GetThanksCount(work->playerBlock);
    s2 = (uptr)SYSTEM_DATA_GetMyStatus((void *)sv);
    work->profileId = (u16)MYSTATUS_GetId((struct MyStatus *)s2);
    work->gender = MYSTATUS_GetSex((struct MyStatus *)s2);
    work->languageId = MYSTATUS_GetTrainerView((struct MyStatus *)s2);
    work->styleId = PM_VERSION_ID;
    work->receiveQueue = GAME_BEACON_ACCESSOR_AllocTable(work->mainHeapId);
    work->recordBuffer = GAME_BEACON_ACCESSOR_AllocInfo(work->mainHeapId);
    work->ownRecord = GAME_BEACON_ACCESSOR_AllocInfo(work->mainHeapId);
    work->currentRecord = GAME_BEACON_ACCESSOR_AllocInfo(work->mainHeapId);
    work->powerRecord = GPOWER_LoadPowerTable(work->mainHeapId);
    BEACON_VIEW_CountDifferingRecords(work, (u8 *)&work->previousIdA, (u8 *)&work->previousIdB);
}

/*
 * note: two alignment padding bytes at 0x021F2906 follow the body.
 */
void BEACON_VIEW_FreeWorkResources(BeaconViewWork *work)
{
    GAME_BEACON_ACCESSOR_TableMarkLogsNew(work->receiveQueue);
    GPOWER_FreePowerTable(work->powerRecord);
    GFL_HEAP_Free(work->currentRecord);
    GFL_HEAP_Free(work->ownRecord);
    GFL_HEAP_Free(work->recordBuffer);
    GFL_HEAP_Free(work->receiveQueue);
}

void BEACON_VIEW_CreateSubSystems(BeaconViewWork *work)
{
    work->taskList = TCBL_Create(work->mainHeapId, work->mainHeapId, 0x10, 0x80);
    work->updateTask = GFL_USE_AddMainTask(BEACON_VIEW_TransferPalettes, work, 0);
    work->paletteAnim = PALANM_Create(work->mainHeapId);
    PALANM_AllocSlotBuffers(work->paletteAnim, 1, 0x1c0, work->mainHeapId);
    PALANM_AllocSlotBuffers(work->paletteAnim, 3, 0x200, work->mainHeapId);
    work->printQueue = PRINTSYS_QUE_Create((u32)(work->mainHeapId));
    PRINTSYS_QUE_SetForceQueue(work->printQueue, 1);
    PRINTSYS_QUE_SetLimitTick(work->printQueue, 0x1f4, 0);
    work->font = FIELD_MSGBG_GetFont((struct FieldMsgBg *)FIELDMAP_GetMsgBg(work->sessionInfo));
    GF_FONT_SetDefaultTextColor();
    work->wordSet = WORDSET_CreateDefault(work->mainHeapId);
    work->messageBank = MSGDATA_CreateFromArchive(1, 2, 8, work->mainHeapId);
    work->messageBuffer = STRBUF_Create(0xd9, work->mainHeapId);
    work->formatBuffer = STRBUF_Create(0xd9, work->mainHeapId);
    work->stringList = STRBUF_Create(0xd9, work->mainHeapId);
}

void BEACON_VIEW_DestroySubSystems(BeaconViewWork *work)
{
    STRBUF_Delete(work->stringList);
    STRBUF_Delete(work->formatBuffer);
    STRBUF_Delete(work->messageBuffer);
    MSGDATA_Delete(work->messageBank);
    WORDSET_Delete(work->wordSet);
    PRINTSYS_QUE_Clear(work->printQueue);
    PRINTSYS_QUE_Delete(work->printQueue);
    GF_FONT_SetDefaultTextColor();
    PALANM_FreeSlotBuffers(work->paletteAnim, 3);
    PALANM_FreeSlotBuffers(work->paletteAnim, 1);
    PALANM_Delete((void *)((sptr)work->paletteAnim));
    work->paletteAnim = 0;
    TCB_DeleteTask(work->updateTask);
    TCBL_Destroy(work->taskList);
}

/*
 * volatile: 0x021F2ACE ldr / 0x021F2AD6 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F2ADC strh to 0x04001050 (hardware registers)
 */
void BEACON_VIEW_InitBackgrounds(BeaconViewWork *work, void *archiveHandle)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021F3608, 0);
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021F3628, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)d_021F3648, 0);
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)d_021F3668, 0);
    MIi_CpuClear32(0, (void *)HW_DB_BG_VRAM, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    PALANM_LoadHandlePaletteToSlot(work->paletteAnim, (void *)archiveHandle, 0x13, work->uiHeapId, 1, 0x1a0, 0);
    PALANM_LoadArcPaletteToSlot(work->paletteAnim, 0x17, 5, work->uiHeapId, 1, 0x20, 0xd0);
    ARC_UTIL_UploadBgCharFromHandle((void *)archiveHandle, 0x14, 7, 0, 0, 1, work->uiHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)archiveHandle, 0x15, 5, 0, 0x800, 1, work->uiHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)archiveHandle, 0x16, 6, 0, 0x800, 1, work->uiHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)archiveHandle, 0x17, 7, 0, 0x800, 1, work->uiHeapId);
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 4, 0x1e, 0xd, 3);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(7, 1);
}

void BEACON_VIEW_FreeBackgrounds(BeaconViewWork *work)
{
    unsigned short z = 0;

    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    *(volatile unsigned short *)0x04001050 = z;
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}

void BEACON_VIEW_CreateTaskMenuRes(BeaconViewWork *work)
{
    int i;
    int z;

    z = 0;
    work->taskMenuCursor = APP_KEYCURSOR_CreateDefault(9, 0, 1, work->mainHeapId);
    work->taskMenuState = APP_TASKMENU_RES_Create(4, 0xe, (struct GFont *)work->font, work->printQueue, work->mainHeapId);
    i = 0;
    do {
        work->slots[i].label = MSGDATA_AllocString(work->messageBank, i + 0xc);
        work->slots[i].textColor = 0x39e3;
        work->slots[i].labelId = z;
        work->slots[i].taskMenu = 0;
        i++;
    } while (i < 3);
    z = 0;
    i = 0;
    do {
        (&work->slots[3])[i].label = MSGDATA_AllocString(work->messageBank, i + 0xf);
        (&work->slots[3])[i].textColor = 0x39e3;
        (&work->slots[3])[i].labelId = z;
        (&work->slots[3])[i].taskMenu = 0;
        i++;
    } while (i < 2);
}

void BEACON_VIEW_DeleteTaskMenuRes(BeaconViewWork *work)
{
    int i;
    struct TaskMenuWin *menu;

    for (i = 0; i < 2; i++) {
        menu = (&work->slots[3])[i].taskMenu;
        if (menu != 0) {
            APP_TASKMENU_WIN_Delete(menu);
        }
        STRBUF_Delete((&work->slots[3])[i].label);
    }
    for (i = 0; i < 3; i++) {
        menu = work->slots[i].taskMenu;
        if (menu != 0) {
            APP_TASKMENU_WIN_Delete(menu);
        }
        STRBUF_Delete(work->slots[i].label);
    }
    APP_TASKMENU_RES_Delete(work->taskMenuState);
    APP_KEYCURSOR_Delete(work->taskMenuCursor);
}

/*
 * Loads the resource lists, palette files and per-icon files of the view.
 */
void BEACON_VIEW_LoadGraphics(BeaconViewWork *work, void *archiveHandle)
{
    void *h2;
    ResSpec3 a;
    ResSpec3 b;
    ResSpec3 c;
    int i;

    h2 = ARC_TOOL_CreateHandle(0x20, work->uiHeapId);
    a = d_021F35BC;
    BEACON_VIEW_LoadResList(work, &work->panelLists.palettes, a.s, archiveHandle);
    b = d_021F35D4;
    BEACON_VIEW_LoadResList(work, &work->statusLists.palettes, b.s, archiveHandle);
    c = d_021F35C8;
    BEACON_VIEW_LoadResList(work, &work->iconLists.palettes, c.s, h2);
    PALANM_LoadHandlePaletteToSlot(work->paletteAnim, archiveHandle, 0, work->uiHeapId, 3, 0x1c0, 0);
    PALANM_LoadArcPaletteToSlot(work->paletteAnim, 0, 1, work->uiHeapId, 3, 0x20, 0xe0);
    work->panelPalette.res = ARC_TOOL_LoadHandleMember(archiveHandle, 4, work->mainHeapId);
    NNS_G2dGetUnpackedPaletteData(work->panelPalette.res, (void **)(&work->panelPalette.header));
    work->panelPalette.data = ((NNSG2dPaletteData *)work->panelPalette.header)->pRawData;
    work->iconPalette.res = ARC_TOOL_LoadHandleMember(h2, 0, work->mainHeapId);
    NNS_G2dGetUnpackedPaletteData(work->iconPalette.res, (void **)(&work->iconPalette.header));
    work->iconPalette.data = ((NNSG2dPaletteData *)work->iconPalette.header)->pRawData;
    for (i = 0; i < 16; i++) {
        work->iconRes[i].file = ARC_TOOL_LoadHandleMember(h2, i + 0x31, work->mainHeapId);
        NNS_G2dGetUnpackedCharacterData(work->iconRes[i].file, (void **)&work->iconRes[i].data);
    }
    for (i = 0; i < 12; i++) {
        work->statusRes[i].file = ARC_TOOL_LoadHandleMember(archiveHandle, i + 7, work->mainHeapId);
        NNS_G2dGetUnpackedCharacterData(work->statusRes[i].file, (void **)&work->statusRes[i].data);
    }
    DC_FlushAll();
    ARC_TOOL_DeleteHandle(h2);
}

void BEACON_VIEW_FreeGraphics(BeaconViewWork *work)
{
    int i;

    for (i = 0; i < 12; i++) {
        GFL_HEAP_Free(work->statusRes[i].file);
    }
    for (i = 0; i < 16; i++) {
        GFL_HEAP_Free(work->iconRes[i].file);
    }
    GFL_HEAP_Free((void *)((sptr)work->panelPalette.res));
    GFL_HEAP_Free((void *)((sptr)work->iconPalette.res));
    BEACON_VIEW_FreeResSet(work, &work->iconLists);
    BEACON_VIEW_FreeResSet(work, &work->statusLists);
    BEACON_VIEW_FreeResSet(work, &work->panelLists);
}

/*
 * note:     CLACT_SetUnitRenderer takes two arguments (twin C_GEAR_LoadGraphics): the
 *           0x12C result still in r1 at that call is its second argument.
 */
void BEACON_VIEW_CreateActors(BeaconViewWork *work, void *bgResource)
{
    T16 t;
    int i;

    work->actorBank = CLACT_CreateUnit(0x40, 0, work->tempHeapId);
    t = d_021F35E0;
    work->actorResource = CLACT_CreateRenderer((struct SurfaceInit *)(&t), 1, work->mainHeapId);
    CLACT_SetUnitRenderer(work->actorBank, work->actorResource);
    work->actorSystem = BMP_OAM_CreateSys(work->mainHeapId, work->actorBank);
    BEACON_VIEW_CreatePanelActors(work);
    for (i = 0; i < 5; i++) {
        BEACON_VIEW_CreateIcon(work, i);
    }
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void BEACON_VIEW_DeleteActors(BeaconViewWork *work)
{
    int i;

    BG_SYS_SetSubPlaneVisible(0x10, 0);
    for (i = 0; i < 5; i++) {
        BEACON_VIEW_DeleteEntry((char *)work, (unsigned char)i);
    }
    BEACON_VIEW_DeletePanelActors(work);
    BMP_OAM_DeleteSys((void *)((sptr)work->actorSystem));
    CLACT_DeleteRenderer((struct Renderer *)work->actorResource);
    CLACT_DeleteUnit((struct Unit *)((sptr)work->actorBank));
}

void BEACON_VIEW_CreateWindow(BeaconViewWindow *window, unsigned bgFrame, unsigned char palNo, unsigned charPosX, unsigned char charPosY, unsigned char width, unsigned char height)
{
    void *w;
    window->handle = BMP_WIN_Create((u32)bgFrame, charPosX, charPosY, width, height, palNo, 1);
    window->bitmap = BMP_WIN_GetBmp(window->handle);
    w = window->handle;
    window->drawn = 0;
    window->layout = w;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
}

void BEACON_VIEW_CreateWindows(BeaconViewWork *work)
{
    BEACON_VIEW_CreateWindow(&work->windows[0], 6, 1, 2, 0x16, 0x1C, 6);
    BEACON_VIEW_CreateWindow(&work->windows[1], 4, 0xD, 1, 0x15, 0xF, 3);
    BEACON_VIEW_CreateWindow(&work->windows[2], 7, 4, 0, 0x13, 6, 2);
}

void BEACON_VIEW_DeleteWindows(BeaconViewWork *work)
{
    int i;
    for (i = 0; i < 3; i++)
        BMP_WIN_Delete((struct BmpWin *)(*(struct Descriptor * *)&work->windows[i].handle));
}

void BEACON_VIEW_LoadResList(BeaconViewWork *work, BeaconViewResList *out, const ResSpec *spec, void *arc)
{
    int i;

    MI_CpuFill8(out, 0, 0x18);
    for (i = 0; i < 3; i++) {
        out[i].count = spec[i].count;
        if (out[i].count != 0)
            out[i].items = GFL_HEAP_Alloc(work->tempHeapId, out[i].count << 2, 1, d_021F36A0, 0x4C3);
    }
    for (i = 0; i < out[0].count; i++)
        out[0].items[i] = CLACT_RegisterPalette(arc, spec[0].base + i, 1, 0, work->tempHeapId);
    for (i = 0; i < out[1].count; i++)
        out[1].items[i] = CLACT_RegisterCharacter(arc, spec[1].base + i, 0, 1, work->tempHeapId);
    for (i = 0; i < out[2].count; i++)
        out[2].items[i] = CLACT_RegisterCellAnim(arc, spec[2].base + i * 2, spec[2].base + 1 + i * 2, work->tempHeapId);
}

void BEACON_VIEW_FreeResSet(BeaconViewWork *work, BeaconViewResSet *set)
{
    unsigned i;
    int j;
    for (i = 0; i < set->cells.count; i++)
        CLACT_ReleaseCellAnim(set->cells.items[i]);
    for (i = 0; i < set->images.count; i++)
        CLACT_ReleaseCharacter(set->images.items[i]);
    for (i = 0; i < set->palettes.count; i++)
        CLACT_ReleasePalette(set->palettes.items[i]);
    for (j = 0; j < 3; j++) {
        if ((&set->palettes)[j].items != 0)
            GFL_HEAP_Free((&set->palettes)[j].items);
    }
}

void *BEACON_VIEW_CreateIconActor(BeaconViewWork *work, unsigned images, unsigned palettes, unsigned cells, short x, short y, unsigned char width, unsigned char height, unsigned char z)
{
    BeaconActorRect r;
    void *res;
    r.x = x;
    r.y = y;
    r.w = width;
    r.h = height;
    r.z = z;
    res = CLACT_CreateActor((void *)(uptr)work->actorBank, images, palettes, cells, (const struct ActorInitParam *)&r, 0, work->tempHeapId);
    CLACT_SetActorAutoAnim(res, 1);
    CLACT_SetActorVisible(res, 0);
    return res;
}

/*
 * Creates the six decoration actors stored in the actors array of the work.
 */
void BEACON_VIEW_CreatePanelActors(BeaconViewWork *work)
{
    int i;
    for (i = 0; i < 6; i++) {
        work->actors[i] = BEACON_VIEW_CreateIconActor(work, *work->panelLists.images.items, *work->panelLists.palettes.items, *work->panelLists.cells.items, d_021F35F0[i].x, d_021F35F0[i].y, i * 3 + 1, 1, 1);
        CLACT_SetActorDrawEnable(work->actors[i], 1);
    }
}

void BEACON_VIEW_DeletePanelActors(BeaconViewWork *work)
{
    int i;
    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable(work->actors[i], 0);
        CLACT_DeleteActor(work->actors[i]);
    }
}

/*
 * Builds the 0x34-byte record at +0x1B8 that BEACON_VIEW_DeleteEntry tears down.
 */
void BEACON_VIEW_CreateIcon(BeaconViewWork *work, u8 idx)
{
    BeaconViewEntry *icon;
    struct BmpOamParam t;

    icon = &work->icons[idx];
    MI_CpuFill8(icon, 0, 0x34);
    icon->index = idx;
    icon->peerSlot = 0xff;
    icon->state = 0;
    icon->sharedValue = work->printQueue;
    icon->x = idx * 13;
    icon->y = idx * 0x28;
    icon->panelActor = BEACON_VIEW_CreateIconActor(work, *work->panelLists.images.items, *work->panelLists.palettes.items, *work->panelLists.cells.items,
                                     icon->x, icon->y, 0, 3, idx + 0x14);
    CLACT_SetActorPaletteOffset(icon->panelActor, (u8)idx, 0);
    icon->iconActor = BEACON_VIEW_CreateIconActor(work, work->iconLists.images.items[idx], *work->panelLists.palettes.items, *work->iconLists.cells.items,
                                    icon->x + 0x20, icon->y + 0x18, 0, 3, idx + 10);
    CLACT_SetActorPaletteOffset(icon->iconActor, (u8)(idx + 9), 1);
    icon->statusActor = BEACON_VIEW_CreateIconActor(work, work->statusLists.images.items[idx], *work->panelLists.palettes.items, *work->statusLists.cells.items,
                                      icon->x + 0x3c, icon->y + 0x18, 0, 3, idx + 5);
    icon->textBitmap = BMP_Create(0xc, 2, 0x20, work->mainHeapId);
    t.bmp = icon->textBitmap;
    t.x = icon->x + 0x48;
    t.y = icon->y + 0x10;
    t.animResId = *work->panelLists.palettes.items;
    t.palette = 3;
    t.drawPriority = 0;
    t.bgPriority = 3;
    t.space = 0;
    t.engine = 1;
    icon->textWindow = BMP_OAM_Create(work->actorSystem, (const struct BmpOamParam *)(&t));
    icon->nameString = STRBUF_Create(0xb, work->mainHeapId);
    icon->messageString = STRBUF_Create(8, work->mainHeapId);
    BMP_Clear(icon->textBitmap, 0);
    BMP_OAM_UploadChars(icon->textWindow);
    BMP_OAM_SetEnabled(icon->textWindow, 0);
    CLACT_SetActorDrawEnable(icon->panelActor, 0);
    CLACT_SetActorDrawEnable(icon->iconActor, 0);
    CLACT_SetActorDrawEnable(icon->statusActor, 0);
}

/* Frees the strings, window, bitmap and actors of one list slot and clears it. */
void BEACON_VIEW_DeleteEntry(char *work, int index)
{
    BeaconViewEntry *entry = (BeaconViewEntry *)(work + 0x1B8 + index * 0x34);

    STRBUF_Delete(entry->messageString);
    STRBUF_Delete(entry->nameString);
    BMP_OAM_SetEnabled(entry->textWindow, 0);
    BMP_OAM_Delete(entry->textWindow);
    BMP_Delete(entry->textBitmap);
    CLACT_SetActorDrawEnable(entry->statusActor, 0);
    CLACT_DeleteActor(entry->statusActor);
    CLACT_SetActorDrawEnable(entry->iconActor, 0);
    CLACT_DeleteActor(entry->iconActor);
    CLACT_SetActorDrawEnable(entry->panelActor, 0);
    CLACT_DeleteActor(entry->panelActor);
    MI_CpuFill8(entry, 0, sizeof(BeaconViewEntry));
}
