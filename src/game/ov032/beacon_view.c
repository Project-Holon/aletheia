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
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
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
 *   BEACON_IncrementThanksCount  0x0200C1E0  thumb
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
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   GAME_BEACON_ACCESSOR_RegisterRecordWords 0x02165FCC thumb ov010
 *   GAME_BEACON_SEARCH_SetPresetEvent 0x02165374 thumb ov010
 *   BEACON_IncrementGreetCount 0x0200C1C8 thumb
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
 *   BG_SYS_SetFlagField06 0x02041B6C arm
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
 *   CALENDER_CreateTask 0x02164B38 thumb ov010
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
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   BEACON_GetFromSave  0x0200C0E8  thumb
 *   BEACON_GetThanksCount  0x0200C1DC  thumb
 *   SYSTEM_DATA_GetMyStatus  0x02008730  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   MYSTATUS_GetOutfit  0x02008554  thumb
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
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
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
#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)
struct Queue;
struct BeaconRecord;
struct Ctx;
struct WordSet;
struct Blk34;
struct Chan02021FD8;
struct PrintSys;
struct Actor;
struct Obj;
struct MsgBank;
struct CharBuf;
struct Descriptor;
struct Vec2;
struct TcblNode;
struct U16Vec;
struct PalAnmSlot;
struct BeaconTrainerInfo;
struct Sub0204A9D0;
struct Strbuf;
struct Grid;
struct Rec02010FA0;
struct Cfg;
struct Tcbl;
struct Desc;
struct S0201235C;
struct S02021D50;
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
struct Bank;
struct Param;
struct Sys;
struct Bmp;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;


typedef struct { u32 x, y; } BeaconPair;

typedef struct { int x, y; } Vec2;

typedef struct { short x,y; } BeaconDelta;

typedef struct BeaconTrainerInfo BeaconTrainerInfo;

typedef signed char s8;

typedef struct BeaconRecord BeaconRecord;

typedef signed int     s32;

#include "beacon_view_types.h"

typedef struct {
    u32 powerId;
    u32 powerFlag;
} Args;

/* Event descriptor handle created by GAME_EVENT_Create; only its pointer is used. */
typedef struct Desc Desc;

/* Work of the event task created by BEACON_VIEW_CreateTaskProc. The event framework also
   reaches it as an int array (state, fieldSystem, sessionInfo, owner, ...). */
typedef struct { int state; void *fieldSystem; unsigned sessionInfo; void *owner; unsigned eventDesc; unsigned mode; unsigned taskMenu; } BeaconTaskWork;

typedef struct {
    u16 count;
    u16 base;
} ResSpec;

typedef struct {
    ResSpec s[3];
} ResSpec3;

typedef struct { int w[4]; } T16;

typedef struct {
    short x;
    short y;
    unsigned short w;
    unsigned char z;
    unsigned char h;
} Rect;

typedef struct {
    short x;
    short y;
} Pt;


/* Sprite template passed to BMP_OAM_Create; same layout as struct Param used
   by the other sprite users in the tree. */
struct Param {
    void *bmp;
    short x;
    short y;
    u32 animResId;
    u32 palette;
    u8 drawPriority;
    u8 bgPriority;
    u16 space;
    u32 engine;
};

extern void PALANM_SetAutoTransfer(struct PalAnmSlot *o, int v);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct BeaconRecord *out, u16 *tag, int delta);
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int GAME_BEACON_ACCESSOR_IsDistributionAction(u8 *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int INTRUDE_COMM_GetVisitProgress(int);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern u32 WIH_DWC_PollStatus(void *key);
extern void *BEACON_STATUS_GetViewFlags(char *p);
extern int BEACON_STATUS_GetMessage(void *p);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern u8 GPOWER_GetActiveIdOfSameType(int,u8 *);
extern int GAME_BEACON_ACCESSOR_TablePop(struct Queue *q, struct BeaconRecord *out, u16 *tag);
extern int GAME_BEACON_ACCESSOR_IsInfoInvalid(struct BeaconRecord *r);
extern int GAME_BEACON_ACCESSOR_TableRingAdd(struct Queue *q, struct BeaconRecord *rec, u16 tag, int *flag);
extern u32 BEACON_IncrementThanksCount(struct Blk34 *p);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void FLD_VREQ_SetSubBlendAlpha(u32 p, u32 a, u32 b, u32 c, u32 d);
extern void PRINTSYS_QUE_SetLimitTick(struct PrintSys *p, u32 lo, u32 hi);
extern void GAME_BEACON_SEARCH_SetThanks(void *a, u16 b);
extern u32 CLACT_IsActorAnimActive(struct Actor *);
extern u8 GAME_BEACON_ACCESSOR_GetSex(struct BeaconRecord *r);
extern u32 GAME_BEACON_ACCESSOR_GetPmVersion(u32 rec);
extern u32 GAME_BEACON_ACCESSOR_GetLanguage(u32 x);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 BG_SYS_CheckPixelColor(u32 layer, u16 x, u16 y, u16 *flags);
extern u32 *APP_TASKMENU_WIN_CreateEx(u32 res, u32 item, u32 charPosX, u32 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter,
                          u16 heapId);
extern u32 APP_TASKMENU_WIN_IsUpdateTrans(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 APP_TASKMENU_WIN_IsTouch(void **p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern int GAME_BEACON_ACCESSOR_GetActionNo(int a0);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int a);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BMP_OAM_SetEnabled(unsigned char *,unsigned);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void TCBL_DeleteTask(struct TcblNode *n);
extern u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(struct BeaconTrainerInfo *p);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(int a0, int a1);
extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
extern u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 v);
extern u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(int a);
extern u16 GAME_BEACON_ACCESSOR_GetTrainerId(u8 *r);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(struct BeaconRecord *r, void *buf);
extern void GAME_BEACON_ACCESSOR_GetGreeting(struct BeaconRecord *r, struct Strbuf *buf);
extern int GAME_BEACON_ACCESSOR_GetThanksName(int a0, int a1);
extern int GAME_BEACON_ACCESSOR_GetFreeText(int a0, int a1);
extern void BMP_OAM_SetPos(struct Grid *g, short x, short y);
extern void BEACON_STATUS_SetViewTop(char *p, int v);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 priority);
extern void *TCBL_GetWork(struct Tcbl *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern u32 FX_Div(u32 a, u32 b);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void GAME_BEACON_ACCESSOR_RegisterRecordWords(int a, int b, u16 c);
extern void GAME_BEACON_SEARCH_SetPresetEvent(unsigned a0);
extern u32 BEACON_IncrementGreetCount(struct Blk34 *p);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern u16 GAME_BEACON_ACCESSOR_GetDistributionSerial(struct BeaconRecord *r);
extern u8 GAME_BEACON_ACCESSOR_GetInfoVersion(struct BeaconRecord *r);
extern void TCBL_SetTaskFunc(int *p, int v);
extern void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v);
extern unsigned int GPOWER_GetPowerCost(struct Rec02010FA0 *p, int idx);
extern u32 MYITEM_SAVEDATA_GetItemQuantity(u8 *base, u16 id, u16 d);
extern int GPOWER_GetSelectedMinutesLeft(void);
extern u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 type);
extern void PRINTSYS_PrintColor(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BG_SYS_SetFlagField06(u32 bit);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetVReq(u8 *p);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 GFL_HEAP_Free(void *p);
extern void TCBL_Main(struct Tcbl *p);
extern int GAME_BEACON_ACCESSOR_TableAddNewLogs(int a0);
extern void INTRUDE_COMM_SetCompleted(void *p);
extern void *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(void *a, u32 b, u32 c);
extern void *CALENDER_CreateTask(void *a, void *b, u8 c);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *gameSystem, u32 overlayId, u32 (*fn)(void *, u32), u32 arg);
extern u32 EVENT_NAMEIN_Create(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *GPOWER_EVENT_CreateActivateEvent(void *a0, int *a1);
extern void *GPOWER_EVENT_CreateListEvent(void *p, void *q);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
extern void *GAME_EVENT_GetWork(struct Obj *p);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void PALANM_TransferPalettes(struct S02021D50 *);
extern u32 GAME_DATA_GetItemUseWork(const struct BigObj *p);
extern u32 BEACON_STATUS_GetLog(u32 a);
extern u8 GAME_BEACON_ACCESSOR_TableGetCount(u8 *q);
extern u8 BEACON_STATUS_GetViewTop(u8 *p);
extern signed char MSG_SPEED_GetWait(void);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *sys);
extern u8 INTRUDE_GetMonolithLevel(struct Rec1B0 *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *BEACON_GetFromSave(void *sys);
extern u32 BEACON_GetThanksCount(struct Blk34 *p);
extern struct Sub0200852CObj *SYSTEM_DATA_GetMyStatus(void *sys);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetOutfit(const struct Sub0200852CObj *obj);
extern u8 *GAME_BEACON_ACCESSOR_AllocTable(u32 heap);
extern u8 *GAME_BEACON_ACCESSOR_AllocInfo(u32 heap);
extern void *GPOWER_LoadPowerTable(u32 heap);
extern void GAME_BEACON_ACCESSOR_TableMarkLogsNew(unsigned char *p);
extern void GPOWER_FreePowerTable(void *);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *GFL_USE_AddMainTask(void *fn, void *ctx, u32 a);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void PRINTSYS_QUE_SetForceQueue(struct PrintSys *p, u32 v);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
extern void GF_FONT_SetDefaultTextColor(void);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(void *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *ctx);
extern void TCB_DeleteTask(struct Node *n);
extern void TCBL_Destroy(struct Tcbl *p);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void MIi_CpuClear32(u32 fill, void *dst, u32 size);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void G2x_SetBlendAlpha_(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern unsigned APP_KEYCURSOR_CreateDefault(int, int, int, unsigned);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, u32 font, u32 printQue, u16 heap);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern int APP_KEYCURSOR_Delete(int cursor);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
extern s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);
extern void DC_FlushAll(void);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *inits, u32 count, u32 heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void *BMP_OAM_CreateSys(unsigned int heapId, void *clact);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern void BEACON_VIEW_DeleteEntry(char *, int);
extern void BMP_OAM_Delete(void *window);
extern void BMP_Delete(void *bitmap);
extern void BMP_OAM_DeleteSys(void *p);
extern void CLACT_DeleteRenderer(int);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void *BMP_WIN_Create(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
void BEACON_VIEW_InitList(BeaconViewWork *work);
int BEACON_VIEW_UpdateListTouch(BeaconViewWork *work);
int BEACON_VIEW_GetContTouchedRow(BeaconViewWork *work);
int BEACON_VIEW_CheckLeaveRequest(BeaconViewWork *work);
int BEACON_VIEW_ShowViewFlagMessage(BeaconViewWork *work);
int BEACON_VIEW_ShowNextHistoryPower(BeaconViewWork *work);
int BEACON_VIEW_LoadNextRecord(BeaconViewWork *work);
void BEACON_VIEW_SetFadeState(BeaconViewWork *work, int flag);
void BEACON_VIEW_ApplySlideTarget(BeaconViewWork *work);
void BEACON_VIEW_SetPrintQueueLimit(BeaconViewWork *work, int flag);
int BEACON_VIEW_UpdateRecordArrival(BeaconViewWork *work);
int BEACON_VIEW_UpdatePowerAnimStart(BeaconViewWork *work);
int BEACON_VIEW_UpdateSelect(BeaconViewWork *work);
int BEACON_VIEW_UpdateSelectTouch(BeaconViewWork *work);
void BEACON_VIEW_SetArrowAnim(BeaconViewWork *work, int a, u32 b);
int BEACON_VIEW_IsArrowAnimActive(BeaconViewWork *work, int i);
void BEACON_VIEW_RefreshActorAnims(BeaconViewWork *work);
void BEACON_VIEW_CountDifferingRecords(BeaconViewWork *work, u8 *a, u8 *b);
void BEACON_VIEW_UpdateAchievements(BeaconViewWork *work, u32 x, int y);
void BEACON_VIEW_AddHistoryId(BeaconViewWork *work, int v);
u32 BEACON_VIEW_PopHistoryId(BeaconViewWork *work);
int BEACON_VIEW_HasRepeatedDigits(u32 x);
int BEACON_VIEW_Cross2D(int *a, int *b);
void BEACON_VIEW_Sub2D(int *a, int *b, int *c);
int BEACON_VIEW_PointInTriangle(Vec2 *pt, Vec2 *tri);
int BEACON_VIEW_HitTestRow(BeaconViewWork *work, void *pt);
int BEACON_VIEW_HitTestIcon(BeaconViewWork *work, void *pt);
int BEACON_VIEW_HitTestActorTouch(BeaconViewWork *work, u32 *v);
void BEACON_VIEW_SetupMessageText(BeaconViewWork *work, unsigned a);
void BEACON_VIEW_ShowRecordCount(BeaconViewWork *work);
void BEACON_VIEW_ShowPlayTime(BeaconViewWork *work, int a, int b);
void BEACON_VIEW_ClearWindow(BeaconViewWork *work);
void BEACON_VIEW_ShowWindowText(BeaconViewWork *work, void *t, unsigned a);
int BEACON_VIEW_CheckWindowTouch(u8 *p);
void BEACON_VIEW_CreateTaskMenuButtons(BeaconViewWork *work, int flag);
int BEACON_VIEW_UpdateTaskMenuButtons(BeaconViewWork *work, int flag);
int BEACON_VIEW_FinishTaskMenuButtons(BeaconViewWork *work, int i);
void BEACON_VIEW_DeleteTaskMenuButtons(BeaconViewWork *work);
int BEACON_VIEW_FinishTaskMenuButtonsAlt(BeaconViewWork *work, int i);
void BEACON_VIEW_DeleteTaskMenuButtonsAlt(BeaconViewWork *work);
int BEACON_VIEW_GetActionVariant(void *p);
void BEACON_VIEW_PlaySe(unsigned int a);
void BEACON_VIEW_MoveActorSurface(void *p, short x, short y);
void BEACON_VIEW_SetActorAnim(void *p, unsigned short v);
void BEACON_VIEW_SetActorVisible(BeaconViewWork *work, unsigned a);
void BEACON_VIEW_UpdateActorAnims(BeaconViewWork *work);
void BEACON_VIEW_UpdateCountActorAnims(BeaconViewWork *work);
void BEACON_VIEW_SetEntryVisible(BeaconViewEntry *icon, unsigned a);
void BEACON_VIEW_SetEntryStatusVisible(BeaconViewEntry *icon, int a);
void BEACON_VIEW_ResetEntry(BeaconViewEntry *icon);
void BEACON_VIEW_SetEntrySlot(BeaconViewEntry *icon, int a, int b);
BeaconViewEntry *BEACON_VIEW_GetEntry(BeaconViewWork *work, int a);
void BEACON_VIEW_LoadEntryPanel(BeaconViewWork *work, BeaconViewEntry *icon, void *r);
void BEACON_VIEW_LoadEntryStatus(BeaconViewWork *work, BeaconViewEntry *icon, int r);
int BEACON_VIEW_GetPmVersion(BeaconTrainerInfo *p);
void BEACON_VIEW_LoadEntryPanelColor(BeaconViewWork *work, BeaconViewEntry *icon, int r);
void BEACON_VIEW_PrintEntryName(BeaconViewWork *work, BeaconViewEntry *icon, void *text, int busyCounter);
void BEACON_VIEW_PrintEntryFrames(BeaconViewWork *work, BeaconViewEntry *icon, int r, int t);
void BEACON_VIEW_PrintEntryRank(BeaconViewWork *work, BeaconViewEntry *icon, int a);
void BEACON_VIEW_SetupEntry(BeaconViewWork *work, BeaconViewEntry *icon, void *r, int mode, int skip, int t);
void BEACON_VIEW_SetEntryPosition(BeaconViewEntry *icon, short x, short y);
void BEACON_VIEW_RefreshTopEntry(BeaconViewWork *work);
void BEACON_VIEW_ScrollList(BeaconViewWork *work, int dir);
void BEACON_VIEW_StartSlide(BeaconViewWork *work, int a, u8 b);
void BEACON_VIEW_StartEntryMove(BeaconViewWork *work, int a, int b, int c, int s);
void BEACON_VIEW_IconMoveTask(void *h, BeaconViewIconMoveTask *task);
void BEACON_VIEW_MoveEntryToSlot(BeaconViewWork *work, int a, BeaconViewEntry *icon, BeaconViewEntry *otherIcon, void *s);
void BEACON_VIEW_MoveEntryToPeer(BeaconViewWork *work, BeaconViewEntry *icon, void *s);
void BEACON_VIEW_StartEntrySlide(BeaconViewWork *work, BeaconViewEntry *icon, int mode, u8 delay, int *r);
void BEACON_VIEW_IconSlideTask(void *h, BeaconViewIconSlideTask *task);
void BEACON_VIEW_StartScrollStep(BeaconViewWork *work, u8 a, int *p);
void BEACON_VIEW_ScrollStepTask(void *task, BeaconViewScrollStepTask *taskData);
int BEACON_VIEW_HandleRecordAction(BeaconViewWork *work, int x, int flag);
void BEACON_VIEW_ShowRecordMessage(BeaconViewWork *work, BeaconRecord *r);
void BEACON_VIEW_ShowFormatMessage(BeaconViewWork *work, int b);
void BEACON_VIEW_StartFadeTask(BeaconViewWork *work, u32 a, int *c);
void BEACON_VIEW_FadeTask(void *task, BeaconViewFadeTask *taskData);
int BEACON_VIEW_HandlePowerRecord(BeaconViewWork *work, void *x, int flag);
void BEACON_VIEW_ShowActivePower(BeaconViewWork *work);
void BEACON_VIEW_ShowPowerAnim(BeaconViewWork *work, int b);
void BEACON_VIEW_StartPowerAnim(BeaconViewWork *work, int b, u8 c, int *r);
void BEACON_VIEW_PowerAnimTaskA(void *h, BeaconViewPowerAnimTask *task);
void BEACON_VIEW_PowerAnimTaskB(void *h, BeaconViewPowerAnimTask *task);
void BEACON_VIEW_StartIconWait(BeaconViewWork *work, BeaconViewEntry *icon, void *x, int flag);
void BEACON_VIEW_IconWaitTask(void *task, BeaconViewIconWaitTask *taskData);
void BEACON_VIEW_ShowTouchedRow(BeaconViewWork *work, int a);
void BEACON_VIEW_StartWindowATask(BeaconViewWork *work, BeaconViewEntry *icon, int *r);
void BEACON_VIEW_WindowATask(void *task, BeaconViewWindowATask *taskData);
void BEACON_VIEW_DrawWindowText(BeaconViewWork *work, BeaconViewWindow *window, void *text, u16 x, u8 y, u8 fillColor, u16 col, u32 busyCounter);
void BEACON_VIEW_StartWindowBTask(BeaconViewWork *work, BeaconViewWindow *window, int *r);
void BEACON_VIEW_WindowBTask(void *task, BeaconViewWindowBTask *taskData);
void BEACON_VIEW_DrawEntryText(BeaconViewWork *work, BeaconViewEntry *icon, void *text, u16 col, u32 busyCounter);
void BEACON_VIEW_StartWindowCTask(BeaconViewWork *work, BeaconViewEntry *icon, int *r);
void BEACON_VIEW_WindowCTask(void *task, BeaconViewWindowCTask *taskData);
BeaconViewWork *BEACON_VIEW_Create(u32 fieldSystem, u32 initArg);
void BEACON_VIEW_Delete(BeaconViewWork *work);
void BEACON_VIEW_Update(BeaconViewWork *work, int request);
u32 BEACON_VIEW_MainPrintQueue(BeaconViewWork *work);
void *BEACON_VIEW_CreateLeaveEvent(BeaconViewWork *work, int go);
void BEACON_VIEW_SetEndRequest(BeaconViewWork *work, int v);
void BEACON_VIEW_ClearEndRequest(BeaconViewWork *work);
Desc *BEACON_VIEW_CreateTaskProc(BeaconViewWork *work, unsigned a, unsigned b, unsigned c);
int BEACON_VIEW_TaskProc(int event, int seq, int *st);
int BEACON_VIEW_TaskStateArrowAnim(BeaconViewWork *work, int *st);
int BEACON_VIEW_TaskStateTasks(BeaconViewWork *work, int *unused);
int BEACON_VIEW_TaskStateTaskMenu(int work, int *st);
void BEACON_VIEW_TransferPalettes(int a, BeaconViewWork *work);
int BEACON_VIEW_UpdateList(BeaconViewWork *work);
int BEACON_VIEW_RunRecordArrival(BeaconViewWork *work);
int BEACON_VIEW_UpdateFadeWait(BeaconViewWork *work);
int BEACON_VIEW_UpdateSlide(BeaconViewWork *work);
int BEACON_VIEW_RunPowerAnimStart(BeaconViewWork *work);
int BEACON_VIEW_RunSelect(BeaconViewWork *work);
void BEACON_VIEW_InitWorkFromSave(BeaconViewWork *work);
void BEACON_VIEW_FreeWorkResources(BeaconViewWork *work);
void BEACON_VIEW_CreateSubSystems(BeaconViewWork *work);
void BEACON_VIEW_DestroySubSystems(BeaconViewWork *work);
void BEACON_VIEW_InitBackgrounds(BeaconViewWork *work, void *h);
void BEACON_VIEW_FreeBackgrounds(BeaconViewWork *work);
void BEACON_VIEW_CreateTaskMenuRes(BeaconViewWork *work);
void BEACON_VIEW_DeleteTaskMenuRes(BeaconViewWork *work);
void BEACON_VIEW_LoadGraphics(BeaconViewWork *work, void *h);
void BEACON_VIEW_FreeGraphics(BeaconViewWork *work);
void BEACON_VIEW_CreateActors(BeaconViewWork *work, void *a);
void BEACON_VIEW_DeleteActors(BeaconViewWork *work);
void BEACON_VIEW_CreateWindow(BeaconViewWindow *window, unsigned a, unsigned b, unsigned c, unsigned char d, unsigned char e, unsigned char f);
void BEACON_VIEW_CreateWindows(BeaconViewWork *work);
void BEACON_VIEW_DeleteWindows(BeaconViewWork *work);
void BEACON_VIEW_LoadResList(BeaconViewWork *work, BeaconViewResList *out, const ResSpec *spec, void *arc);
void BEACON_VIEW_FreeResSet(BeaconViewWork *work, BeaconViewResSet *set);
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

    PALANM_SetAutoTransfer((struct PalAnmSlot *)(work->paletteAnim), 1);
    BEACON_VIEW_ShowRecordCount(work);
    BEACON_VIEW_ShowPlayTime(work, 1, 0);
    for (i = 0; i < work->visibleRows; i++) {
        q = (u8 *)&work->tagBuffer;
        t = work->scrollTop;
        GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)(work->recordLog), (struct BeaconRecord *)(work->recordBuffer), (u16 *)q, t + i);
        s = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(work->recordLog), t + i);
        icon = BEACON_VIEW_GetEntry(work, 0xFF);
        BEACON_VIEW_SetEntrySlot(icon, (u8)s, (u8)(i + 1));
        BEACON_VIEW_SetupEntry(work, icon, (void *)(work->recordBuffer), 2, 0, 0);
        BEACON_VIEW_SetEntryVisible(icon, (int)1);
    }
    BEACON_VIEW_UpdateActorAnims(work);
    BEACON_VIEW_UpdateCountActorAnims(work);
    if (work->powerId == 0x30)
        BEACON_VIEW_SetActorAnim((void *)(*(int *)&work->actors[0]), 3);
    GFL_NET_RestartWithDefaultTimeout(0, work->uiHeapId);
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
        GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)(work->recordLog), (struct BeaconRecord *)(work->recordBuffer), (u16 *)((u8 *)&work->tagBuffer), work->scrollTop + r);
        if (GAME_BEACON_ACCESSOR_IsDistributionAction((u8 *)(work->recordBuffer)) != 0)
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
    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)((unsigned int)work->fieldSystem)) != 0) {
        BEACON_VIEW_SetEndRequest(work, 1);
        return 1;
    }
    if (r == 2) {
        BEACON_VIEW_SetEndRequest(work, 2);
        return 1;
    }
    if (WIH_DWC_PollStatus((void *)(work->optionData)) & 8) {
        BEACON_VIEW_SetEndRequest(work, 3);
        return 1;
    }
    return 0;
}














int BEACON_VIEW_ShowViewFlagMessage(BeaconViewWork *work)
{
    u16 *f;

    f = BEACON_STATUS_GetViewFlags((char *)(work->beaconStatus));
    if (*f == 0)
        return 0;
    *f = 0;
    WORDSET_SetSlotTag(*(void * *)&work->wordSet, 0, (void *)BEACON_STATUS_GetMessage((void *)(work->beaconStatus)),
                  work->gender, 1, 2);
    BEACON_VIEW_ShowFormatMessage(work, 0xB);
    return 1;
}













int BEACON_VIEW_ShowNextHistoryPower(BeaconViewWork *work) { unsigned n; n=BEACON_VIEW_PopHistoryId(work); if(n==0x30) return 0; if(n==GPOWER_GetActiveIdOfSameType(n,*(u8 * *)&work->powerRecord)) return 0; BEACON_VIEW_ShowPowerAnim(work,n); return 1; }














int BEACON_VIEW_LoadNextRecord(BeaconViewWork *work)
{
    u8 t;

    if (GAME_BEACON_ACCESSOR_TablePop((struct Queue *)(work->receiveQueue), (struct BeaconRecord *)(work->currentRecord), (u16 *)((u8 *)&work->currentTag)) == 0) {
        BEACON_VIEW_RefreshTopEntry(work);
        return 0;
    }
    if (GAME_BEACON_ACCESSOR_IsInfoInvalid((struct BeaconRecord *)(work->currentRecord)) != 0)
        return 0;
    work->currentIndex = GAME_BEACON_ACCESSOR_TableRingAdd((struct Queue *)(work->recordLog), (struct BeaconRecord *)(work->currentRecord), work->currentTag, (int *)((u8 *)&work->addedCount));
    work->currentId = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(work->recordLog), work->currentIndex);
    if (work->addedCount == 0) {
        work->currentEntry = BEACON_VIEW_GetEntry(work, work->currentId);
    } else {
        work->currentEntry = 0;
        work->playTime = BEACON_IncrementThanksCount((struct Blk34 *)(work->playerBlock));
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
        PALANM_BlendChannel((struct Chan02021FD8 *)((unsigned int)work->paletteAnim), 1, 0, 0xe0, 6, 0);
        PALANM_BlendChannel((struct Chan02021FD8 *)((unsigned int)work->paletteAnim), 3, 0, 0xe0, 6, 0);
        FLD_VREQ_SetSubBlendAlpha(work->bgConfig, 5, 0x1e, 0xa, 6);
    } else {
        PALANM_BlendChannel((struct Chan02021FD8 *)((unsigned int)work->paletteAnim), 1, 0, 0xe0, 0, 0);
        PALANM_BlendChannel((struct Chan02021FD8 *)((unsigned int)work->paletteAnim), 3, 0, 0xe0, 0, 0);
        FLD_VREQ_SetSubBlendAlpha(work->bgConfig, 4, 0x1e, 0xd, 3);
    }
}













void BEACON_VIEW_ApplySlideTarget(BeaconViewWork *work) { BEACON_VIEW_ScrollList(work, work->slideTarget); }













void BEACON_VIEW_SetPrintQueueLimit(BeaconViewWork *work,int flag) { if(flag) PRINTSYS_QUE_SetLimitTick((struct PrintSys *)(work->printQueue),2000,0); else PRINTSYS_QUE_SetLimitTick((struct PrintSys *)(work->printQueue),500,0); }














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
                BEACON_VIEW_SetupEntry(work, work->currentEntry, (void *)(work->currentRecord), 0, r == 0, 0);
                BEACON_VIEW_SetEntryVisible(work->currentEntry, 1);
            }
            return 1;
        }
        BEACON_VIEW_SetArrowAnim(work, 4, 2);
        (work->step)++;
        break;
    case 2:
        BEACON_VIEW_ShowRecordCount(work);
        BEACON_VIEW_ShowPlayTime(work, 1, (int)((u8 *)&work->busyCount));
        BEACON_VIEW_UpdateAchievements(work, work->currentRecord, work->previousCount);
        (work->step)++;
        break;
    case 3:
        if (work->scrollTop != 0) {
            work->currentIndex = work->scrollTop;
            GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)(work->recordLog), (struct BeaconRecord *)(work->currentRecord), (u16 *)((u8 *)&work->currentTag), work->currentIndex);
            work->currentId = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(work->recordLog), work->currentIndex);
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
        BEACON_VIEW_ShowPlayTime(work, 2, (int)((u8 *)&work->busyCount));
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
        s = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(work->recordLog), work->touchedRow + work->scrollTop);
        icon = BEACON_VIEW_GetEntry(work, s);
        WORDSET_SetSlotTag((void *)work->wordSet, 0, icon->messageString, icon->gender, 1, 2);
        BEACON_VIEW_SetPrintQueueLimit(work, 1);
        BEACON_VIEW_ShowFormatMessage(work, 3);
        GAME_BEACON_SEARCH_SetThanks((void *)(*(int *)&work->saveInfo), icon->trainerId);
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
        BEACON_VIEW_ShowPlayTime(work, 1, (int)((u8 *)&work->busyCount));
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

    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)((unsigned int)work->fieldSystem)) != 0) {
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
        BEACON_VIEW_SetActorAnim((void *)(*(u32 *)&work->actors[0]), (u8)(animOffset + 1));
    if (2 & m)
        BEACON_VIEW_SetActorAnim((void *)((unsigned int)work->actors[1]), (u8)(animOffset + 4));
    if ((4 & m) && work->recordCount != 0)
        BEACON_VIEW_SetActorAnim((void *)(*(u32 *)&work->actors[2]), (u8)(animOffset + 7));
    if (8 & m)
        BEACON_VIEW_SetActorAnim((void *)((unsigned int)work->actors[3]), (u8)(animOffset + 10));
}













int BEACON_VIEW_IsArrowAnimActive(BeaconViewWork *work, int i) { return CLACT_IsActorAnimActive(*(struct Actor * *)&work->actors[i]); }














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
        GAME_BEACON_ACCESSOR_TableRingGet((struct Queue *)((unsigned int)work->recordLog), (struct BeaconRecord *)(work->ownRecord), &tag, i);
        if (work->gender != GAME_BEACON_ACCESSOR_GetSex((struct BeaconRecord *)(work->ownRecord)))
            (*outGenderMismatch)++;
        if (work->styleId != GAME_BEACON_ACCESSOR_GetPmVersion(work->ownRecord))
            (*outVersionMismatch)++;
    }
}














void BEACON_VIEW_UpdateAchievements(BeaconViewWork *work, u32 x, int y)
{
    u8 v[2];

    v[1] = 0;
    v[0] = 0;
    BEACON_VIEW_CountDifferingRecords(work, &v[0], &v[1]);
    if (GAME_BEACON_ACCESSOR_GetLanguage(x) != 2)
        BEACON_VIEW_AddHistoryId(work, 1);
    if (work->previousIdB != v[1] && v[1] == 0x14)
        BEACON_VIEW_AddHistoryId(work, 2);
    if (work->playTime % 100 == 0)
        BEACON_VIEW_AddHistoryId(work, 3);
    if (y == 0x1d && work->recordCount == 0x1e)
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
        u32 a = CLACT_GetActorAnimSeq((struct Obj *)(*(u32 *)((u8 *)&work->actors[0] + i * 4)));
        if ((u8)(a - (i * 3 + 1)) % 3 < 2) {
            b[0] = 0xac;
            b[1] = b[0] + 0x18;
            b[2] = i * 32 + 0x84;
            b[3] = b[2] + 0x18;
            if (TOUCHPANEL_HitPoint((struct Ctx *)b, touchPos[0], touchPos[1]) != -1) {
                BEACON_VIEW_PlaySe(d_021F3530[i]);
                return i;
            }
        }
    }
    return -1;
}









void BEACON_VIEW_SetupMessageText(BeaconViewWork *work,unsigned messageId) { MSGDATA_ReadString(work->messageBank,messageId,work->messageBuffer); WORDSET_CopyTaggedText((void *)work->wordSet,(void *)work->formatBuffer,work->messageBuffer); }










void BEACON_VIEW_ShowRecordCount(BeaconViewWork *work)
{
    WORDSET_SetSlotNumber((struct WordSet *)(*(int *)&work->wordSet), 0, work->recordCount, 2, 1, 1);
    BEACON_VIEW_SetupMessageText(work, 0);
    BEACON_VIEW_DrawWindowText(work, &work->windows[2], (void *)(*(int *)&work->formatBuffer), 4, 0, 1, 0x3DC1, 0);
}










void BEACON_VIEW_ShowPlayTime(BeaconViewWork *work, int messageId, int busyCounter)
{
    WORDSET_SetSlotNumber((struct WordSet *)(*(int *)&work->wordSet), 0, *(int *)&work->playTime, 5, 0, 1);
    BEACON_VIEW_SetupMessageText(work, messageId);
    BEACON_VIEW_DrawWindowText(work, &work->windows[1], (void *)(*(int *)&work->formatBuffer), 0, 4, 0, 0x3C40, busyCounter);
}









void BEACON_VIEW_ClearWindow(BeaconViewWork *work) { BMP_Clear(work->windows[1].bitmap,0x40); BMP_WIN_TransferChars(work->windows[1].handle); }









void BEACON_VIEW_ShowWindowText(BeaconViewWork *work,void *text,unsigned busyCounter) { BEACON_VIEW_DrawWindowText(work,&work->windows[0],text,0,0,9,0x449,busyCounter); }









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
        slotList[i].taskMenu = (u32)APP_TASKMENU_WIN_CreateEx(work->taskMenuState, (u32)((char *)&slotList[i].label),
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
        if (APP_TASKMENU_WIN_IsUpdateTrans(*(u8 * *)&slotList[i].taskMenu) == 1) {
            APP_TASKMENU_WIN_Update((u8 *)(slotList[i].taskMenu));
            return -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (APP_TASKMENU_WIN_IsTouch((void **)(*(u32 * *)&slotList[i].taskMenu)) != 0) {
            if (i < n - 1) {
                BEACON_VIEW_PlaySe(0x54c);
                s = i;
            } else {
                APP_TASKMENU_WIN_SetDecide(*(char * *)&slotList[i].taskMenu, 1);
                BEACON_VIEW_PlaySe(0x54c);
                s = i;
            }
        }
        APP_TASKMENU_WIN_Update((u8 *)(slotList[i].taskMenu));
    }
    return s;
}









int BEACON_VIEW_FinishTaskMenuButtons(BeaconViewWork *work, int i)
{
    BeaconViewSlot *slotList;
    int j;

    slotList = &work->slots[0];
    APP_TASKMENU_WIN_Update((u8 *)(slotList[i].taskMenu));
    if (APP_TASKMENU_WIN_IsFinish(*(u8 * *)&slotList[i].taskMenu) != 0) {
        for (j = 0; j < 3; j++) {
            APP_TASKMENU_WIN_Delete((u8 *)(work->slots[j].taskMenu));
            work->slots[j].taskMenu = 0;
        }
        return 1;
    }
    return 0;
}








void BEACON_VIEW_DeleteTaskMenuButtons(BeaconViewWork *work) { int i; for(i=0;i<3;i++) { APP_TASKMENU_WIN_Delete(*(unsigned char * *)&work->slots[i].taskMenu); work->slots[i].taskMenu=0; } }









int BEACON_VIEW_FinishTaskMenuButtonsAlt(BeaconViewWork *work, int i)
{
    BeaconViewSlot *slotList;
    int j;

    slotList = &work->slots[3];
    APP_TASKMENU_WIN_Update((u8 *)(slotList[i].taskMenu));
    if (APP_TASKMENU_WIN_IsFinish(*(u8 * *)&slotList[i].taskMenu) != 0) {
        for (j = 0; j < 2; j++) {
            APP_TASKMENU_WIN_Delete((u8 *)((&work->slots[3])[j].taskMenu));
            (&work->slots[3])[j].taskMenu = 0;
        }
        return 1;
    }
    return 0;
}








void BEACON_VIEW_DeleteTaskMenuButtonsAlt(BeaconViewWork *work) { int i; for(i=0;i<2;i++) { APP_TASKMENU_WIN_Delete(*(unsigned char * *)&(&work->slots[3])[i].taskMenu); (&work->slots[3])[i].taskMenu=0; } }








int BEACON_VIEW_GetActionVariant(void *record) { int a; a=GAME_BEACON_ACCESSOR_GetActionNo((int)record); if(a==0 || a>=0x33) return 0x12; return a+0x11; }









void BEACON_VIEW_PlaySe(unsigned int seId)
{
    GFL_USE_PlaySeDefaultVolume(seId);
}








void BEACON_VIEW_MoveActorSurface(void *actor, short x, short y) { BeaconDelta d; d.x=x; d.y=y; CLACT_AddActorSurfacePos(actor,(const struct Vec2 *)(&d),0); }








void BEACON_VIEW_SetActorAnim(void *actor, unsigned short animSeq) { CLACT_SetActorAnimSeq(actor,animSeq); CLACT_RestartActorAnim(actor); }








void BEACON_VIEW_SetActorVisible(BeaconViewWork *work, unsigned visible) { int i; for(i=0;i<=3;i++) CLACT_SetActorDrawEnable(work->actors[i],visible); }









void BEACON_VIEW_UpdateActorAnims(BeaconViewWork *work)
{
    if (work->scrollTop == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)((int)work->actors[4]), 0x10);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)((int)work->actors[4]), 0xd);
    }
    if (work->scrollTop + work->visibleRows < work->recordCount) {
        CLACT_SetActorAnimSeq((struct Obj *)((int)work->actors[5]), 0x11);
        return;
    }
    CLACT_SetActorAnimSeq((struct Obj *)((int)work->actors[5]), 0x14);
}








void BEACON_VIEW_UpdateCountActorAnims(BeaconViewWork *work) { if(work->recordCount==0) CLACT_SetActorAnimSeq(work->actors[2],9); else CLACT_SetActorAnimSeq(work->actors[2],7); }








void BEACON_VIEW_SetEntryVisible(BeaconViewEntry *icon,unsigned visible) { BMP_OAM_SetEnabled(*(unsigned char * *)&icon->textWindow,visible); CLACT_SetActorDrawEnable(icon->iconActor,visible); CLACT_SetActorDrawEnable(icon->panelActor,visible); if(visible==0) BEACON_VIEW_SetEntryStatusVisible(icon,visible); }









void BEACON_VIEW_SetEntryStatusVisible(BeaconViewEntry *icon, int visible)
{
    CLACT_SetActorDrawEnable(icon->statusActor, visible);
}








void BEACON_VIEW_ResetEntry(BeaconViewEntry *icon)
{
    int z = 0;

    BEACON_VIEW_SetEntryVisible(icon, 0);
    BEACON_VIEW_SetEntryStatusVisible(icon, 0);
    BMP_Clear((struct CharBuf *)((int)icon->textBitmap), 0);
    BMP_OAM_UploadChars((struct Obj *)(*(int *)&icon->textWindow));
    STRBUF_Clear((struct U16Vec *)(*(int *)&icon->messageString));
    STRBUF_Clear((struct U16Vec *)(*(int *)&icon->nameString));
    icon->peerSlot = 0xff;
    icon->state = z;
    icon->flags = z;
    if (icon->busy != 0) {
        TCBL_DeleteTask((struct TcblNode *)(icon->busy));
        icon->busy = z;
    }
    if (icon->activeTask != 0) {
        TCBL_DeleteTask((struct TcblNode *)(icon->activeTask));
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








void BEACON_VIEW_LoadEntryPanel(BeaconViewWork *work, BeaconViewEntry *icon, void *trainerInfo)
{
    int x;

    x = GAME_BEACON_ACCESSOR_GetTrainerAppearance((struct BeaconTrainerInfo *)trainerInfo);
    CLACT_TransferCharacter(*(int *)((int)work->iconLists.images.items + icon->index * 4), (struct Sub0204A9D0 *)(*(int *)&work->iconRes[x].data));
    PALANM_CopyToSlot((struct PalAnmSlot *)(work->paletteAnim),
                  (const void *)(*(int *)&work->iconPalette.data + ((d_021F3541[x] & 0xf) << 5)), 3,
                  (u16)((icon->index + 9) << 4), 0x20);
}






void BEACON_VIEW_LoadEntryStatus(BeaconViewWork *work, BeaconViewEntry *icon, int statusIndex)
{
    CLACT_TransferCharacter((*(int * *)&work->statusLists.images.items)[icon->index], (struct Sub0204A9D0 *)(*(int *)&work->statusRes[statusIndex].data));
}






int BEACON_VIEW_GetPmVersion(BeaconTrainerInfo *trainerInfo)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion((u32)trainerInfo)) {
    case 21: return 0;
    case 20: return 1;
    default: return 2;
    }
}






void BEACON_VIEW_LoadEntryPanelColor(BeaconViewWork *work, BeaconViewEntry *icon, int trainerInfo)
{
    u16 a[5];
    int x;
    int b;
    u16 *t;

    x = BEACON_VIEW_GetPmVersion((BeaconTrainerInfo *)trainerInfo);
    b = x * 16;
    t = work->panelPalette.data;
    a[0] = t[b];
    a[1] = t[b + 1];
    a[2] = t[b + 2];
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((int)(&a[3]), trainerInfo);
    PALANM_BlendColors(&a[3], &a[4], 1, 3, 0);
    PALANM_CopyToSlot((struct PalAnmSlot *)(work->paletteAnim), a, 3, (u16)((icon->index + 4) * 16 + 1), 10);
}





void BEACON_VIEW_PrintEntryName(BeaconViewWork *work, BeaconViewEntry *icon, void *text, int busyCounter)
{
    BEACON_VIEW_DrawEntryText(work, icon, text, 0x3c60, busyCounter);
}














void BEACON_VIEW_PrintEntryFrames(BeaconViewWork *work, BeaconViewEntry *icon, int force, int busyCounter)
{
    u8 c;

    c = (GAME_BEACON_GetReceivedFramesByTrainerId(icon->trainerId) >= 0x2a30) ? 1 : 0;
    if (c == icon->frequent && force == 0) {
        return;
    }
    icon->frequent = c;
    if (c != 0) {
        BEACON_VIEW_DrawEntryText(work, icon, (void *)(*(int *)&icon->messageString), 0xca0, busyCounter);
    } else {
        BEACON_VIEW_DrawEntryText(work, icon, (void *)(*(int *)&icon->messageString), 0x3c60, busyCounter);
    }
}














void BEACON_VIEW_PrintEntryRank(BeaconViewWork *work, BeaconViewEntry *icon, int record)
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
    PALANM_CopyToSlot((struct PalAnmSlot *)(work->paletteAnim), work->panelPalette.data + 0x30, (int)3, (u16)((icon->index + 4) * 16 + 8), 10);
    PALANM_CopyToSlot((struct PalAnmSlot *)(work->paletteAnim), work->panelPalette.data + k, (int)3, (u16)((icon->index + 4) * 16 + 8), v * 2);
}














void BEACON_VIEW_SetupEntry(BeaconViewWork *work, BeaconViewEntry *icon, void *record, int mode, int skip, int busyCounter)
{
    icon->trainerId = GAME_BEACON_ACCESSOR_GetTrainerId(record);
    icon->gender = GAME_BEACON_ACCESSOR_GetSex(record);
    GAME_BEACON_ACCESSOR_GetPlayerName(record, icon->messageString);
    STRBUF_Clear(icon->nameString);
    GAME_BEACON_ACCESSOR_GetGreeting(record, icon->nameString);
    BEACON_VIEW_PrintEntryRank(work, icon, (int)record);
    BEACON_VIEW_LoadEntryPanel(work, icon, record);
    BEACON_VIEW_LoadEntryPanelColor(work, icon, (int)record);
    if (skip != 0)
        return;
    switch (mode) {
    case 0:
        switch (GAME_BEACON_ACCESSOR_GetActionNo((int)record)) {
        case 0x18:
            GAME_BEACON_ACCESSOR_GetThanksName((int)record, (int)(work->messageBuffer));
            BEACON_VIEW_PrintEntryName(work, icon, work->messageBuffer, busyCounter);
            break;
        case 0x31:
            GAME_BEACON_ACCESSOR_GetFreeText((int)record, (int)(work->messageBuffer));
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
        icon = (BeaconViewEntry *)BEACON_VIEW_GetEntry(work, (u8)GAME_BEACON_ACCESSOR_TableGetRingIndex(*(u8 * *)&work->recordLog, work->scrollTop + i));
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
    BEACON_STATUS_SetViewTop(*(void * *)&work->beaconStatus, *(volatile u8 *)&work->scrollTop);
    GAME_BEACON_ACCESSOR_TableRingGet(*(void * *)&work->recordLog, *(void * *)&work->recordBuffer, (u16 *)((u8 *)&work->tagBuffer), t);
    idx = GAME_BEACON_ACCESSOR_TableGetRingIndex(*(void * *)&work->recordLog, t);
    BEACON_VIEW_StartEntryMove(work, (int)(*(void * *)&work->recordBuffer), idx, (u8)dir, 2);
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
        BEACON_VIEW_SetActorAnim((void *)((int)work->actors[5]), 0x13);
    else
        BEACON_VIEW_SetActorAnim((void *)((int)work->actors[4]), 0xf);
    BEACON_VIEW_SetArrowAnim(work, 4, 2);
    BEACON_VIEW_ScrollList(work, target);
}














void BEACON_VIEW_StartEntryMove(BeaconViewWork *work, int record, int slot, int destSlot, int mode)
{
    BeaconViewEntry *icon;
    BeaconViewIconMoveTask *task;

    icon = (BeaconViewEntry *)BEACON_VIEW_GetEntry(work, 0xff);
    if (icon != 0) {
        task = TCBL_GetWork(TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_IconMoveTask, sizeof(BeaconViewIconMoveTask), 0));
        MI_CpuFill8(task, 0, sizeof(BeaconViewIconMoveTask));
        task->work = work;
        task->slot = destSlot;
        task->entry = icon;
        task->mode = mode;
        task->busyCounter = (int *)((char *)&work->busyCount);
        work->busyCount = work->busyCount + 1;
        BEACON_VIEW_SetEntrySlot(icon, slot, 0);
        BEACON_VIEW_SetupEntry(work, icon, (void *)record, mode, 0, (int)((u8 *)&task->timer));
    }
}














void BEACON_VIEW_IconMoveTask(void *tcb, BeaconViewIconMoveTask *task)
{
    void *this;

    this = (void *)task->work;
    if (task->timer > 0)
        return;
    if (task->phase == 0) {
        BEACON_VIEW_SetEntryVisible(task->entry, 1);
        if (task->mode == 1) {
            BEACON_VIEW_MoveEntryToPeer(this, task->entry, (u8 *)&task->timer);
            BEACON_VIEW_SetEntryStatusVisible(task->entry, 1);
        } else {
            BEACON_VIEW_MoveEntryToSlot(this, task->slot, task->entry, 0, (u8 *)&task->timer);
        }
        task->phase = task->phase + 1;
        return;
    }
    if (task->busyCounter != 0)
        *(task->busyCounter) = *(task->busyCounter) - 1;
    TCBL_DeleteTask(tcb);
}














void BEACON_VIEW_MoveEntryToSlot(BeaconViewWork *work, int mode, BeaconViewEntry *icon, BeaconViewEntry *otherIcon, void *busyCounter)
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














void BEACON_VIEW_MoveEntryToPeer(BeaconViewWork *work, BeaconViewEntry *icon, void *busyCounter)
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

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_IconSlideTask, sizeof(BeaconViewIconSlideTask), 0));
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














void BEACON_VIEW_IconSlideTask(void *tcb, BeaconViewIconSlideTask *task)
{
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

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_ScrollStepTask, 0xc, 0));
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












void BEACON_VIEW_ScrollStepTask(void *task, BeaconViewScrollStepTask *taskData)
{
    u32 old;
    int x;
    old = taskData->step;
    taskData->step = old + 1;
    if (old < taskData->steps) {
        x = *(signed char *)&taskData->position;
        taskData->position = x + *(signed char *)&taskData->delta;
        BG_SYS_FillScrollArea(6, 3, *(signed char *)&taskData->position);
        return;
    }
    (*taskData->busyCounter)--;
    TCBL_DeleteTask(task);
}











int BEACON_VIEW_HandleRecordAction(BeaconViewWork *work, int x, int flag)
{
    int k;

    k = GAME_BEACON_ACCESSOR_GetActionNo(x);
    if (flag != 0) {
        GAME_BEACON_ACCESSOR_RegisterRecordWords(x, *(int *)&work->wordSet, work->uiHeapId);
        BEACON_VIEW_ShowFormatMessage(work, 0x12);
        return 1;
    }
    switch (k) {
    case 1:
        return 0;
    case 0x12:
        return BEACON_VIEW_HandlePowerRecord(work, (void *)x, 0);
    case 0x32:
        return BEACON_VIEW_HandlePowerRecord(work, (void *)x, 1);
    case 0x18:
        GAME_BEACON_SEARCH_SetPresetEvent(BEACON_IncrementGreetCount((struct Blk34 *)(work->playerBlock)));
        break;
    }
    BEACON_VIEW_ShowRecordMessage(work, (BeaconRecord *)x);
    return 1;
}









void BEACON_VIEW_ShowRecordMessage(BeaconViewWork *work, BeaconRecord *record)
{
    GAME_BEACON_ACCESSOR_RegisterRecordWords((int)record, (int)((void *)work->wordSet), work->uiHeapId);
    BEACON_VIEW_SetupMessageText(work, (u8)BEACON_VIEW_GetActionVariant(record));
    BEACON_VIEW_StartFadeTask(work, work->formatBuffer, (int *)((char *)&work->busyCount));
}









void BEACON_VIEW_ShowFormatMessage(BeaconViewWork *work, int messageId)
{
    BEACON_VIEW_SetupMessageText(work, messageId);
    BEACON_VIEW_StartFadeTask(work, work->formatBuffer, (int *)((char *)&work->busyCount));
}










void BEACON_VIEW_StartFadeTask(BeaconViewWork *work, u32 text, int *busyCounter)
{
    BeaconViewFadeTask *task;

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_FadeTask, sizeof(BeaconViewFadeTask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewFadeTask));
    STRBUF_Copy((struct U16Vec *)(work->stringList), (struct U16Vec *)text);
    task->work = work;
    task->duration = 0x5a;
    BEACON_VIEW_SetArrowAnim(work, 4, 2);
    task->busyCounter = busyCounter;
    (*busyCounter)++;
}










void BEACON_VIEW_FadeTask(void *task, BeaconViewFadeTask *taskData)
{
    if (taskData->frames != 0)
        return;
    switch (taskData->phase) {
    case 0:
        BEACON_VIEW_ShowWindowText(taskData->work, (void *)(taskData->work->stringList), (unsigned int)((u8 *)&taskData->frames));
        taskData->phase++;
        return;
    case 1:
        BEACON_VIEW_StartScrollStep(taskData->work, 0, (int *)((u8 *)&taskData->frames));
        taskData->phase++;
        return;
    case 2:
        if (BEACON_VIEW_CheckWindowTouch((u8 *)&taskData->duration) != 0) {
            BEACON_VIEW_StartScrollStep(taskData->work, 1, (int *)((u8 *)&taskData->frames));
            taskData->phase++;
        }
        return;
    default:
        (*taskData->busyCounter)--;
        TCBL_DeleteTask(task);
        return;
    }
}










int BEACON_VIEW_HandlePowerRecord(BeaconViewWork *work, void *x, int flag)
{
    int r;

    if (flag)
        r = GAME_BEACON_ACCESSOR_GetDistributionSerial(x);
    else
        r = GAME_BEACON_ACCESSOR_GetInfoVersion(x);
    if (r == 0x30 || r > 0x2d)
        return 0;
    if (r == GPOWER_GetActiveIdOfSameType(r, *(u8 * *)&work->powerRecord))
        return 0;
    GAME_BEACON_ACCESSOR_RegisterRecordWords((int)x, work->wordSet, work->uiHeapId);
    WORDSET_CopyTaggedText((struct WordSet *)(work->wordSet), (void *)(work->formatBuffer), (void *)(*(u32 *)&work->messageBuffer));
    BEACON_VIEW_StartPowerAnim(work, r, 1, (int *)((char *)&work->busyCount));
    return 1;
}









void BEACON_VIEW_ShowActivePower(BeaconViewWork *work)
{
    BEACON_VIEW_StartPowerAnim(work, work->powerId, 0, (int *)((char *)&work->busyCount));
}









void BEACON_VIEW_ShowPowerAnim(BeaconViewWork *work, int powerId)
{
    BEACON_VIEW_StartPowerAnim(work, powerId, 2, (int *)((char *)&work->busyCount));
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

    h = TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_PowerAnimTaskA, sizeof(BeaconViewPowerAnimTask), 0);
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
    WORDSET_SetSlotFromMsgA0((struct WordSet *)(work->wordSet), 1, powerId);
    if (task->mode == 0) {
        task->cost = GPOWER_GetPowerCost((struct Rec02010FA0 *)(work->powerRecord), powerId);
        task->nameStringId = MYITEM_SAVEDATA_GetItemQuantity((u8 *)(work->messageArchive), 0x23f, work->uiHeapId);
        WORDSET_SetSlotNumber((struct WordSet *)(work->wordSet), 2, task->cost, 3, 0, 1);
        WORDSET_SetSlotNumber((struct WordSet *)(work->wordSet), 3, task->nameStringId, 3, 0, 1);
        if (powerId == GPOWER_GetActiveIdOfSameType(powerId, (u8 *)(work->powerRecord))) {
            task->minutesLeft = GPOWER_GetSelectedMinutesLeft();
            if (task->minutesLeft != 0) {
                task->hours = task->minutesLeft / 60;
                task->minutes = task->minutesLeft % 60;
                WORDSET_SetSlotNumber((struct WordSet *)(work->wordSet), 4, task->hours, 3, 0, 1);
                WORDSET_SetSlotNumber((struct WordSet *)(work->wordSet), 5, task->minutes, 2, 0, 1);
            }
        }
    }
    if (task->mode != 0)
        BEACON_VIEW_SetArrowAnim(work, 0, 2);
    BEACON_VIEW_SetArrowAnim(work, 1, 2);
    BEACON_VIEW_SetArrowAnim(work, 2, 2);
    BEACON_VIEW_SetArrowAnim(work, 3, 2);
    if (task->minutesLeft != 0 || task->nameStringId < task->cost)
        TCBL_SetTaskFunc(h, (int)((void *)BEACON_VIEW_PowerAnimTaskB));
    task->busyCounter = busyCounter;
    (*busyCounter)++;
}










void BEACON_VIEW_PowerAnimTaskA(void *tcb, BeaconViewPowerAnimTask *task)
{
    BeaconViewWork *work;
    int r;

    work = task->work;
    if (task->timer > 0)
        return;
    switch (task->phase) {
    case 0:
        BEACON_VIEW_SetupMessageText(work, d_021F352C[task->mode]);
        BEACON_VIEW_ShowWindowText(work, (void *)(work->formatBuffer), (unsigned int)((int *)((u8 *)&task->timer)));
        task->phase++;
        break;
    case 1:
        BEACON_VIEW_StartScrollStep(work, 0, (int *)((u8 *)&task->timer));
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
        BEACON_VIEW_ShowPlayTime(work, 1, (int)((int *)((u8 *)&task->timer)));
        BEACON_VIEW_SetActorVisible(work, 1);
        BEACON_VIEW_StartScrollStep(work, 1, (int *)((u8 *)&task->timer));
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









void BEACON_VIEW_PowerAnimTaskB(void *tcb, BeaconViewPowerAnimTask *task)
{
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
        BEACON_VIEW_ShowWindowText(work, (void *)(work->formatBuffer), (unsigned int)((int *)((u8 *)&task->timer)));
        task->phase++;
        break;
    case 1:
        BEACON_VIEW_StartScrollStep(work, 0, (int *)((u8 *)&task->timer));
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
        BEACON_VIEW_ShowPlayTime(work, 1, (int)((int *)((u8 *)&task->timer)));
        BEACON_VIEW_SetActorVisible(work, 1);
        BEACON_VIEW_StartScrollStep(work, 1, (int *)((u8 *)&task->timer));
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

    t = TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_IconWaitTask, 0x18, 0);
    task = TCBL_GetWork(t);
    MI_CpuFill8(task, 0, 0x18);
    task->work = work;
    task->entry = icon;
    task->delay = 0x5a;
    *(void * *)&icon->activeTask = t;
    if (flag)
        task->timer = 1;
    else
        task->timer = GAME_BEACON_ACCESSOR_GetActionNo((int)x);
    BEACON_VIEW_LoadEntryStatus(work, icon, GAME_BEACON_ACCESSOR_GetActionViewVariant(task->timer));
    BEACON_VIEW_SetEntryStatusVisible(icon, flag ? 0 : 1);
}









void BEACON_VIEW_IconWaitTask(void *task, BeaconViewIconWaitTask *taskData)
{
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
        if ((unsigned int)taskData->entry->busy != 0)
            return;
    }
    *(unsigned int *)&taskData->entry->activeTask = 0;
    BEACON_VIEW_SetEntryStatusVisible(taskData->entry, 0);
    TCBL_DeleteTask(task);
}








void BEACON_VIEW_ShowTouchedRow(BeaconViewWork *work, int row)
{
    BeaconViewEntry *icon;
    u8 index;
    index = GAME_BEACON_ACCESSOR_TableGetRingIndex(*(u8 * *)&work->recordLog, row + work->scrollTop);
    icon = BEACON_VIEW_GetEntry(work, index);
    BEACON_VIEW_StartWindowATask(work, icon, (int *)((char *)&work->busyCount));
    BEACON_VIEW_PlaySe(0x54c);
}









void BEACON_VIEW_StartWindowATask(BeaconViewWork *work, BeaconViewEntry *icon, int *busyCounter)
{
    BeaconViewWindowATask *task;

    task = TCBL_GetWork(TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_WindowATask, sizeof(BeaconViewWindowATask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewWindowATask));
    task->work = work;
    task->entry = icon;
    task->interval = 2;
    task->paletteOffset = (icon->index + 4) << 4;
    PALANM_BlendChannel((struct Chan02021FD8 *)(task->work->paletteAnim), 3, task->paletteOffset, 0x10, 4, 0x7fff);
    if (busyCounter != 0) {
        task->busyCounter = busyCounter;
        (*busyCounter)++;
    }
}









void BEACON_VIEW_WindowATask(void *task, BeaconViewWindowATask *taskData)
{
    u8 c = taskData->phase;

    if (c < 2) {
        if (taskData->counter++ >= taskData->interval) {
            PALANM_BlendChannel((struct Chan02021FD8 *)(taskData->work->paletteAnim), 3, taskData->paletteOffset, 0x10, (c % 2) << 2, 0x7fff);
            taskData->phase++;
            taskData->counter = 0;
        }
    } else {
        int *r;

        PALANM_BlendChannel((struct Chan02021FD8 *)(taskData->work->paletteAnim), 3, taskData->paletteOffset, 0x10, 0, 0x7fff);
        r = taskData->busyCounter;
        if (r != 0)
            (*r)--;
        TCBL_DeleteTask(task);
    }
}









void BEACON_VIEW_DrawWindowText(BeaconViewWork *work, BeaconViewWindow *window, void *text, u16 x, u8 y, u8 fillColor, u16 col, u32 busyCounter)
{
    u32 w;
    u32 v;

    BMP_Clear((struct CharBuf *)((unsigned int)window->bitmap), fillColor);
    if (work->windowShown != 0) {
        PRINTSYS_PrintColor((unsigned int)window->bitmap, x, y, text, work->font, col);
        w = (unsigned int)window->handle;
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        return;
    }
    v = work->printQueue;
    PRINTSYS_PrintQueColor((void *)v, (u32)BMP_WIN_GetBmp((struct Descriptor *)(unsigned int)window->layout), x, y, (u32)text,
                  work->font, col);
    window->drawn = 1;
    BEACON_VIEW_StartWindowBTask(work, window, (int *)busyCounter);
}








void BEACON_VIEW_StartWindowBTask(BeaconViewWork *work, BeaconViewWindow *window, int *busyCounter)
{
    BeaconViewWindowBTask *task;
    task = TCBL_GetWork(TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_WindowBTask, sizeof(BeaconViewWindowBTask), 0));
    MI_CpuFill8(task, 0, sizeof(BeaconViewWindowBTask));
    task->work = work;
    task->window = window;
    if (busyCounter != 0) {
        task->busyCounter = busyCounter;
        (*busyCounter)++;
    }
}








void BEACON_VIEW_WindowBTask(void *task, BeaconViewWindowBTask *taskData)
{
    u8 *drawn;
    u32 v;
    int *r;

    v = taskData->work->printQueue;
    drawn = (u8 *)&taskData->window->layout;
    if (drawn[4] != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)v, (void *)((u32)BMP_WIN_GetBmp(*(struct Descriptor **)drawn))) == 0) {
            BMP_WIN_TransferChars(*(struct Descriptor **)drawn);
            drawn[4] = 0;
        }
    }
    if (drawn[4] == 0) {
        BMP_WIN_MakeScreen((struct Cfg *)taskData->window->handle);
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)taskData->window->handle));
        r = taskData->busyCounter;
        if (r != 0)
            (*r)--;
        TCBL_DeleteTask(task);
    }
}








void BEACON_VIEW_DrawEntryText(BeaconViewWork *work, BeaconViewEntry *icon, void *text, u16 col, u32 busyCounter)
{
    u32 *t;

    t = (u32 *)((char *)&icon->textWindow);
    BMP_Clear((struct CharBuf *)t[1], 0);
    if (work->windowShown != 0) {
        PRINTSYS_PrintColor((u32)((void *)t[1]), 0, 0, text, (u32)((void *)(work->font)), col);
        BMP_OAM_UploadChars((struct Obj *)t[0]);
        return;
    }
    PRINTSYS_PrintQueColor((void *)(work->printQueue), t[1], 0, 0, (u32)text, work->font, col);
    BEACON_VIEW_StartWindowCTask(work, icon, (int *)busyCounter);
}








void BEACON_VIEW_StartWindowCTask(BeaconViewWork *work, BeaconViewEntry *icon, int *busyCounter)
{
    void *t;
    BeaconViewWindowCTask *task;

    t = TCBL_AddTask(work->taskList, (void *)BEACON_VIEW_WindowCTask, sizeof(BeaconViewWindowCTask), 0);
    task = TCBL_GetWork(t);
    MI_CpuFill8(task, 0, sizeof(BeaconViewWindowCTask));
    task->work = work;
    task->entry = icon;
    *(char * *)&task->windowRef = (char *)&icon->textWindow;
    *(void * *)&icon->busy = t;
    if (busyCounter != 0) {
        task->busyCounter = busyCounter;
        (*busyCounter)++;
    }
}







void BEACON_VIEW_WindowCTask(void *task, BeaconViewWindowCTask *taskData)
{
    int *r;
    if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(taskData->work->printQueue), (void *)((taskData->windowRef)[1])) == 0) {
        BMP_OAM_UploadChars((struct Obj *)(*taskData->windowRef));
        r = taskData->busyCounter;
        if (r != 0)
            (*r)--;
        *(unsigned int *)&taskData->entry->busy = 0;
        TCBL_DeleteTask(task);
    }
}







BeaconViewWork *BEACON_VIEW_Create(u32 fieldSystem, u32 initArg)
{
    BeaconViewWork *work;
    void *v;

    work = GFL_HEAP_Alloc(0x70, 0x3d0, 1, d_021F36A0, 0x8d);
    *(unsigned int *)&work->fieldSystem = fieldSystem;
    work->saveInfo = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)fieldSystem);
    work->sessionInfo = v = GAMESYSTEM_GetFieldMap((void *)fieldSystem);
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
    TCBL_DeleteAllTasks((struct Tcbl *)(work->taskList));
    BEACON_VIEW_DeleteWindows(work);
    BEACON_VIEW_DeleteActors(work);
    BEACON_VIEW_FreeGraphics(work);
    BEACON_VIEW_DeleteTaskMenuRes(work);
    BEACON_VIEW_FreeBackgrounds(work);
    BEACON_VIEW_DestroySubSystems(work);
    BEACON_VIEW_FreeWorkResources(work);
    ARC_TOOL_DeleteHandle((void *)(unsigned int)work->bgResource);
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
        TCBL_Main((struct Tcbl *)(*(int *)&work->taskList));
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
    return PRINTSYS_QUE_Main(*(struct PrintSys * *)&work->printQueue);
}


void *BEACON_VIEW_CreateLeaveEvent(BeaconViewWork *work, int go)
{
    void *r;
    Args args;

    if (go == 0)
        return 0;
    switch (work->eventFlags) {
    case 2:
        INTRUDE_COMM_SetCompleted((void *)(work->playerProfile));
    case 1:
    case 3:
        BEACON_STATUS_SetViewTop(*(void * *)&work->beaconStatus, 0);
        r = BEACON_VIEW_CreateTaskProc(work, (unsigned)(FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(work->fieldSystem, (u32)(work->sessionInfo), 0)), 0, 3);
        break;
    case 4:
        r = BEACON_VIEW_CreateTaskProc(work, (unsigned)(CALENDER_CreateTask(work->fieldSystem, work->sessionInfo, work->touchedRow + work->scrollTop)), 1, 0);
        break;
    case 5:
        args.powerId = *(u8 *)&work->powerIdArg;
        args.powerFlag = *(u8 *)&work->powerFlagArg;
        r = BEACON_VIEW_CreateTaskProc(work, (unsigned)(GAME_EVENT_CreateOverlayEvent(work->fieldSystem, (u32)ov083_id, (void *)GPOWER_EVENT_CreateActivateEvent, (u32)(&args))), 2, work->slots[1].taskMenu);
        work->powerIdArg = 0x30;
        break;
    case 6:
        r = BEACON_VIEW_CreateTaskProc(work, (unsigned)(GAME_EVENT_CreateOverlayEvent(work->fieldSystem, (u32)ov083_id, (void *)GPOWER_EVENT_CreateListEvent, (u32)(work->sessionInfo))), 2, work->slots[0].taskMenu);
        break;
    case 7:
        r = BEACON_VIEW_CreateTaskProc(work, (unsigned)(GAME_EVENT_CreateOverlayEvent(work->fieldSystem, (u32)ov083_id, (void *)GPOWER_EVENT_CreateListEvent, (u32)(work->sessionInfo))), 2, work->slots[3].taskMenu);
        work->resetFlag = 0;
        break;
    case 8:
        r = BEACON_VIEW_CreateTaskProc(work, (unsigned)((void *)EVENT_NAMEIN_Create((u32)(work->fieldSystem), (u32)(work->sessionInfo), 0, 7, (u32)BEACON_STATUS_GetViewFlags((char *)(work->beaconStatus)))), 0, 1);
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







Desc *BEACON_VIEW_CreateTaskProc(BeaconViewWork *work, unsigned eventDesc, unsigned mode, unsigned taskMenu)
{
    Desc *d;
    BeaconTaskWork *w;
    d = (Desc *)GAME_EVENT_Create(work->fieldSystem, 0, BEACON_VIEW_TaskProc, 0x1c);
    w = GAME_EVENT_GetWork((struct Obj *)d);
    w->owner = work;
    w->fieldSystem = work->fieldSystem;
    w->sessionInfo = (unsigned int)work->sessionInfo;
    w->eventDesc = eventDesc;
    w->mode = mode;
    w->taskMenu = taskMenu;
    work->endRequest = 1;
    return d;
}








int BEACON_VIEW_TaskProc(int event, int seq, int *eventWork)
{
    int r;
    BeaconViewWork *work;

    r = 0;
    work = (BeaconViewWork *)eventWork[3];
    switch (eventWork[5]) {
    case 0:
        r = BEACON_VIEW_TaskStateArrowAnim(work, eventWork);
        break;
    case 1:
        r = BEACON_VIEW_TaskStateTasks(work, eventWork);
        break;
    case 2:
        r = BEACON_VIEW_TaskStateTaskMenu((int)work, eventWork);
        break;
    }
    if (r) {
        work->endRequest = 0;
        GAME_EVENT_ChangeEvent((struct S0201235C *)event, (u32 *)eventWork[4]);
    }
    return 0;
}







int BEACON_VIEW_TaskStateArrowAnim(BeaconViewWork *work, int *st)
{
    switch (st[0]) {
    case 0:
        BEACON_VIEW_SetArrowAnim(work, st[6], 1);
        st[0]++;
        return 0;
    case 1:
        if (BEACON_VIEW_IsArrowAnimActive(work, st[6]) != 0)
            return 0;
        break;
    }
    return 1;
}







int BEACON_VIEW_TaskStateTasks(BeaconViewWork *work, int *unused)
{
    TCBL_Main(*(struct Tcbl * *)&work->taskList);
    if (work->busyCount == 0)
        return 1;
    return 0;
}








int BEACON_VIEW_TaskStateTaskMenu(int work, int *st)
{
    int h = st[6];

    switch (st[0]) {
    case 0:
        APP_TASKMENU_WIN_SetDecide((char *)h, 1);
        st[0]++;
        break;
    case 1:
        APP_TASKMENU_WIN_Update((u8 *)h);
        if (APP_TASKMENU_WIN_IsFinish((u8 *)h)) {
            APP_TASKMENU_WIN_ResetDecide((struct Obj *)h);
            return 1;
        }
        break;
    }
    return 0;
}







void BEACON_VIEW_TransferPalettes(int tcb, BeaconViewWork *work)
{
    if (*(struct S02021D50 * *)&work->paletteAnim)
        PALANM_TransferPalettes(*(struct S02021D50 * *)&work->paletteAnim);
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
    u32 sv;
    u32 s2;

    *(u32 *)&work->beaconStatus = GAME_DATA_GetItemUseWork((const struct BigObj *)(work->saveInfo));
    *(u32 *)&work->recordLog = BEACON_STATUS_GetLog(*(u32 *)&work->beaconStatus);
    work->recordCount = GAME_BEACON_ACCESSOR_TableGetCount((u8 *)(*(u32 *)&work->recordLog));
    work->scrollTop = BEACON_STATUS_GetViewTop((u8 *)(*(u32 *)&work->beaconStatus));
    if (work->recordCount < 4)
        work->visibleRows = work->recordCount;
    else
        work->visibleRows = 4;
    *(u8 *)&work->powerIdArg = 0x30;
    work->languageCode = MSG_SPEED_GetWait();
    sv = (u32)GAME_DATA_GetSaveControl((struct Big *)(work->saveInfo));
    *(u32 *)&work->powerId = INTRUDE_GetMonolithLevel((struct Rec1B0 *)INTRUDE_GetFromSave((void *)sv));
    *(u32 *)&work->playerProfile = GAMESYSTEM_GetGameComm((const struct Ctx *)(*(u32 *)&work->fieldSystem));
    *(u32 *)&work->optionData = GAME_DATA_GetField1A0((const struct BigObj *)(work->saveInfo));
    work->messageArchive = (u32)GAME_DATA_GetMyItem((const struct BigObj *)(work->saveInfo));
    *(u32 *)&work->playerBlock = (u32)BEACON_GetFromSave((void *)sv);
    work->playTime = BEACON_GetThanksCount((struct Blk34 *)(*(u32 *)&work->playerBlock));
    s2 = (u32)SYSTEM_DATA_GetMyStatus((void *)sv);
    work->profileId = (u16)MYSTATUS_GetId((const struct Sub0200852CObj *)s2);
    work->gender = MYSTATUS_GetOutfitVariant((const struct Sub0200852CObj *)s2);
    work->languageId = MYSTATUS_GetOutfit((const struct Sub0200852CObj *)s2);
    work->styleId = 0x15;
    *(u32 *)&work->receiveQueue = (u32)GAME_BEACON_ACCESSOR_AllocTable(work->mainHeapId);
    *(u32 *)&work->recordBuffer = (u32)GAME_BEACON_ACCESSOR_AllocInfo(work->mainHeapId);
    work->ownRecord = (u32)GAME_BEACON_ACCESSOR_AllocInfo(work->mainHeapId);
    *(u32 *)&work->currentRecord = (u32)GAME_BEACON_ACCESSOR_AllocInfo(work->mainHeapId);
    work->powerRecord = (u32)GPOWER_LoadPowerTable(work->mainHeapId);
    BEACON_VIEW_CountDifferingRecords(work, (u8 *)&work->previousIdA, (u8 *)&work->previousIdB);
}







/*
 * note: two alignment padding bytes at 0x021F2906 follow the body.
 */
void BEACON_VIEW_FreeWorkResources(BeaconViewWork *work)
{
    GAME_BEACON_ACCESSOR_TableMarkLogsNew((void *)work->receiveQueue);
    GPOWER_FreePowerTable((void *)work->powerRecord);
    GFL_HEAP_Free((void *)work->currentRecord);
    GFL_HEAP_Free((void *)work->ownRecord);
    GFL_HEAP_Free((void *)work->recordBuffer);
    GFL_HEAP_Free((void *)work->receiveQueue);
}








void BEACON_VIEW_CreateSubSystems(BeaconViewWork *work)
{
    *(void * *)&work->taskList = TCBL_Create(work->mainHeapId, work->mainHeapId, 0x10, 0x80);
    work->updateTask = GFL_USE_AddMainTask((void *)BEACON_VIEW_TransferPalettes, work, 0);
    work->paletteAnim = (u32)PALANM_Create(work->mainHeapId);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(work->paletteAnim), 1, 0x1c0, work->mainHeapId);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(work->paletteAnim), 3, 0x200, work->mainHeapId);
    work->printQueue = PRINTSYS_QUE_Create((void *)(work->mainHeapId));
    PRINTSYS_QUE_SetForceQueue((struct PrintSys *)(work->printQueue), 1);
    PRINTSYS_QUE_SetLimitTick((struct PrintSys *)(work->printQueue), 0x1f4, 0);
    work->font = FIELD_MSGBG_GetFont((u8 *)FIELDMAP_GetMsgBg((u8 *)(*(u32 *)&work->sessionInfo)));
    GF_FONT_SetDefaultTextColor();
    *(void * *)&work->wordSet = WORDSET_CreateDefault(work->mainHeapId);
    work->messageBank = MSGDATA_CreateFromArchive(1, 2, 8, work->mainHeapId);
    work->messageBuffer = STRBUF_Create(0xd9, work->mainHeapId);
    *(void * *)&work->formatBuffer = STRBUF_Create(0xd9, work->mainHeapId);
    *(void * *)&work->stringList = STRBUF_Create(0xd9, work->mainHeapId);
}








void BEACON_VIEW_DestroySubSystems(BeaconViewWork *work)
{
    STRBUF_Delete((struct U16Vec *)((int)work->stringList));
    STRBUF_Delete((struct U16Vec *)((int)work->formatBuffer));
    STRBUF_Delete((struct U16Vec *)((int)work->messageBuffer));
    MSGDATA_Delete(work->messageBank);
    WORDSET_DeleteStrbufED04((struct WordSet *)((int)work->wordSet));
    PRINTSYS_QUE_Clear((struct PrintSys *)((int)work->printQueue));
    PRINTSYS_QUE_Delete((struct PrintSys *)((int)work->printQueue));
    GF_FONT_SetDefaultTextColor();
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)((int)work->paletteAnim), 3);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)((int)work->paletteAnim), 1);
    PALANM_Delete((void *)((int)work->paletteAnim));
    *(int *)&work->paletteAnim = 0;
    TCB_DeleteTask((struct Node *)((int)work->updateTask));
    TCBL_Destroy((struct Tcbl *)(*(int *)&work->taskList));
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
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    PALANM_LoadHandlePaletteToSlot((struct PalAnmSlot *)(work->paletteAnim), (void *)archiveHandle, 0x13, work->uiHeapId, 1, 0x1a0, 0);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(work->paletteAnim), 0x17, 5, work->uiHeapId, 1, 0x20, 0xd0);
    ARC_UTIL_UploadBgCharFromHandle((void *)archiveHandle, 0x14, 7, 0, 0, 1, work->uiHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)archiveHandle, 0x15, 5, 0, 0x800, 1, work->uiHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)archiveHandle, 0x16, 6, 0, 0x800, 1, work->uiHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)archiveHandle, 0x17, 7, 0, 0x800, 1, work->uiHeapId);
    G2x_SetBlendAlpha_(0x04001050, 4, 0x1e, 0xd, 3);
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
    work->taskMenuState = (unsigned int)APP_TASKMENU_RES_Create(4, 0xe, work->font, work->printQueue, work->mainHeapId);
    i = 0;
    do {
        work->slots[i].label = (unsigned int)MSGDATA_AllocString((struct MsgBank *)(*(unsigned *)&work->messageBank), i + 0xc);
        work->slots[i].textColor = 0x39e3;
        work->slots[i].labelId = z;
        *(int *)&work->slots[i].taskMenu = z;
        i++;
    } while (i < 3);
    z = 0;
    i = 0;
    do {
        (&work->slots[3])[i].label = (unsigned int)MSGDATA_AllocString((struct MsgBank *)(*(unsigned *)&work->messageBank), i + 0xf);
        (&work->slots[3])[i].textColor = 0x39e3;
        (&work->slots[3])[i].labelId = z;
        *(int *)&(&work->slots[3])[i].taskMenu = z;
        i++;
    } while (i < 2);
}








void BEACON_VIEW_DeleteTaskMenuRes(BeaconViewWork *work)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(int *)&(&work->slots[3])[i].taskMenu != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(*(int *)&(&work->slots[3])[i].taskMenu));
        }
        STRBUF_Delete((struct U16Vec *)(*(int *)&(&work->slots[3])[i].label));
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)&work->slots[i].taskMenu != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(*(int *)&work->slots[i].taskMenu));
        }
        STRBUF_Delete((struct U16Vec *)(*(int *)&work->slots[i].label));
    }
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)((int)work->taskMenuState));
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
    PALANM_LoadHandlePaletteToSlot((struct PalAnmSlot *)work->paletteAnim, archiveHandle, 0, work->uiHeapId, 3, 0x1c0, 0);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)work->paletteAnim, 0, 1, work->uiHeapId, 3, 0x20, 0xe0);
    work->panelPalette.res = ARC_TOOL_LoadHandleMember(archiveHandle, 4, work->mainHeapId);
    NNS_G2dGetUnpackedPaletteData(work->panelPalette.res, (void **)(&work->panelPalette.header));
    work->panelPalette.data = (u16 *)((u32 *)work->panelPalette.header)[3];
    work->iconPalette.res = ARC_TOOL_LoadHandleMember(h2, 0, work->mainHeapId);
    NNS_G2dGetUnpackedPaletteData(work->iconPalette.res, (void **)(&work->iconPalette.header));
    work->iconPalette.data = (u16 *)((u32 *)work->iconPalette.header)[3];
    for (i = 0; i < 16; i++) {
        work->iconRes[i].file = ARC_TOOL_LoadHandleMember(h2, i + 0x31, work->mainHeapId);
        NNS_G2dGetUnpackedCharacterData(work->iconRes[i].file, &work->iconRes[i].data);
    }
    for (i = 0; i < 12; i++) {
        work->statusRes[i].file = ARC_TOOL_LoadHandleMember(archiveHandle, i + 7, work->mainHeapId);
        NNS_G2dGetUnpackedCharacterData(work->statusRes[i].file, &work->statusRes[i].data);
    }
    DC_FlushAll();
    ARC_TOOL_DeleteHandle(h2);
}








void BEACON_VIEW_FreeGraphics(BeaconViewWork *work)
{
    int i;

    for (i = 0; i < 12; i++) {
        GFL_HEAP_Free((void *)(*(int *)((char *)&work->statusRes[0].file + i * 8)));
    }
    for (i = 0; i < 16; i++) {
        GFL_HEAP_Free((void *)(*(int *)((char *)&work->iconRes[0].file + i * 8)));
    }
    GFL_HEAP_Free((void *)((int)work->panelPalette.res));
    GFL_HEAP_Free((void *)((int)work->iconPalette.res));
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
    work->actorResource = CLACT_CreateRenderer((u8 *)(&t), 1, work->mainHeapId);
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
    BMP_OAM_DeleteSys((void *)((int)work->actorSystem));
    CLACT_DeleteRenderer((int)work->actorResource);
    CLACT_DeleteUnit((struct Bank *)((int)work->actorBank));
}






void BEACON_VIEW_CreateWindow(BeaconViewWindow *window, unsigned bgFrame, unsigned palNo, unsigned charPosX, unsigned char charPosY, unsigned char width, unsigned char height)
{
    void *w;
    window->handle = BMP_WIN_Create((void *)bgFrame, charPosX, charPosY, width, height, palNo, 1);
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
        BMP_WIN_Delete(*(struct Descriptor * *)&work->windows[i].handle);
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
    Rect r;
    void *res;
    r.x = x;
    r.y = y;
    r.w = width;
    r.h = height;
    r.z = z;
    res = CLACT_CreateActor((void *)(unsigned int)work->actorBank, images, palettes, cells, &r, 0, work->tempHeapId);
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
    struct Param t;

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
    icon->textWindow = BMP_OAM_Create(work->actorSystem, (const struct Param *)(&t));
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
