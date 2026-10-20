/*
 * file:     oekaki.c
 * unit:     yes
 * function: OEKAKI_RegisterNetCommands, OEKAKI_RecvCanvasChunk, OEKAKI_RecvStroke, OEKAKI_RecvStrokes, OEKAKI_RecvReset, OEKAKI_RecvSyncMessage, OEKAKI_RecvAck, OEKAKI_RecvMemberJoined, OEKAKI_RecvCanvasDone, OEKAKI_SendCanvasChunk, OEKAKI_GetRecvChunk, OEKAKI_OpenGroup, OEKAKI_Init, OEKAKI_Main, OEKAKI_Exit, OEKAKI_VBlankTask, OEKAKI_OnMemberJoined, OEKAKI_OnMemberLeft, OEKAKI_SetVramBanks, OEKAKI_SetupBgs, OEKAKI_InitWork, OEKAKI_FreeWork, OEKAKI_ResetDisplay, OEKAKI_LoadBgGraphics, OEKAKI_LoadSpriteResources, OEKAKI_CreateActors, OEKAKI_CreateWindows, OEKAKI_DeleteWindows, OEKAKI_SetCursorPosition, OEKAKI_MakeEmptyStroke, OEKAKI_HandleTouch, OEKAKI_SelectColorButton, OEKAKI_SetQuitButtonPressed, OEKAKI_StepDraw, OEKAKI_ApplyRemoteStrokes, OEKAKI_StepStart, OEKAKI_StepHideCursors, OEKAKI_StepEnterDraw, OEKAKI_StepOpenQuitMenu, OEKAKI_StepQuitMenuResult, OEKAKI_StepSendQuitRequest, OEKAKI_StepResetWaitTimer, OEKAKI_StepWaitQuitReply, OEKAKI_StepSendQuitConfirm, OEKAKI_StepCancelQuit, OEKAKI_StepShowQuitMessage, OEKAKI_StepWaitQuitMessage, OEKAKI_StepWaitThenFadeOut, OEKAKI_StepOpenFinishMenu, OEKAKI_StepFinishMenuResult, OEKAKI_RegisterPlayerName, OEKAKI_StepSendFinishRequest, OEKAKI_StepShowFinishMessage, OEKAKI_StepWaitFinishMessage, OEKAKI_StepCheckMembers, OEKAKI_StepKeepState, OEKAKI_StepShowWaitMessage, OEKAKI_StepWaitMessage, OEKAKI_StepShowSyncMessage, OEKAKI_StepWaitSyncAck, OEKAKI_StepWaitSyncTimer, OEKAKI_HandleEvent, OEKAKI_BlitBrush, OEKAKI_DrawLine, OEKAKI_StoreLastPoints, OEKAKI_DrawStrokes, OEKAKI_UpdateRemoteCursors, OEKAKI_AnimatePalette, OEKAKI_CountMembers, OEKAKI_RefreshNamePlates, OEKAKI_SendStrokes, OEKAKI_GetMemberCount, OEKAKI_UpdateMemberSlots, OEKAKI_PrintMessage, OEKAKI_IsMessageDone, OEKAKI_ClearMessageWindow, OEKAKI_HostOpenGroupLimited, OEKAKI_UpdateMembers, OEKAKI_SetNextScene, OEKAKI_ApplySceneChange, OEKAKI_CloseMenuIfOpen, OEKAKI_IsQuitTouched, OEKAKI_MakeStroke, OEKAKI_GetJoinedCount, OEKAKI_GetJoinedBits, OEKAKI_EnableDisplays, OEKAKI_OpenYesNoMenu, OEKAKI_PollYesNoMenu, OEKAKI_CloseYesNoMenu, OEKAKI_RegisterMetPlayers, OEKAKI_UpdatePrintJobs, OEKAKI_SendPendingCommand, OEKAKI_QueueCommand, OEKAKI_GetPrevQueueIndex, OEKAKI_AdvanceQueueTailIfUsed, OEKAKI_AdvanceQueueTail, OEKAKI_ClearStrokeGroup, OEKAKI_PopStrokeGroup, OEKAKI_StoreStroke, OEKAKI_PeekStroke, OEKAKI_FillSendGroup
 * address:  0x021841E0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gOekakiCommandTable 0x02186A6C data ov023 a4
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   OEKAKI_QueueCommand  0x02186860  thumb  ov023
 *   OEKAKI_StoreStroke 0x02186988 thumb ov023
 *   OEKAKI_HandleEvent  0x02185AB0  thumb  ov023
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   UNION_APP_GetMemberCount  0x021841A4  thumb  ov022
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *   MATH_CountPopulation  0x02080D24  arm
 *   UNION_APP_Open  0x02184134  thumb  ov022
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_COMMAND_SetSendSlot  0x0203AA94  arm
 *   UNION_APP_OpenLimited  0x02184148  thumb
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   OEKAKI_CreateActors  0x02184D30  thumb  ov023
 *   OEKAKI_CreateWindows  0x02184ECC  thumb  ov023
 *   OEKAKI_EnableDisplays  0x02186564  thumb  ov023
 *   OEKAKI_RegisterMetPlayers  0x021866C4  thumb  ov023
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_ApplySceneChange  0x0218644C  thumb  ov023
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   UNION_APP_SetCallbacks  0x021840FC  thumb  ov022
 *   OEKAKI_RefreshNamePlates  0x02185F74  thumb  ov023
 *   OEKAKI_UpdateMembers  0x02186324  thumb  ov023
 *   OEKAKI_AnimatePalette  0x02185F10  thumb  ov023
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   UNION_APP_RequestReset  0x02184174  thumb  ov022
 *   UNION_APP_IsResetDone  0x0218417C  thumb  ov022
 *   OEKAKI_SendPendingCommand  0x021867C4  thumb  ov023
 *   CLACT_DrawSystem  0x0204A600  arm
 *   TCBL_Main  0x020310C4  arm
 *   OEKAKI_UpdatePrintJobs  0x02186708  thumb  ov023
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   gOekakiSceneTable     0x02186E80  data   a4
 *   TCB_DeleteTask  0x02030EAC  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   OEKAKI_CloseYesNoMenu  0x02186694  thumb  ov023
 *   OEKAKI_DeleteWindows  0x02185004  thumb  ov023
 *   MSGDATA_Delete  0x02045C04  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   gOekakiVramBanks     0x02186ACC  data  ov023  a4
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   gOekakiDispConfig     0x02186B3C  data  ov023  a4
 *   gOekakiBgTemplate0     0x02186BCC  data  ov023  a4
 *   gOekakiBgTemplate1     0x02186B6C  data  ov023  a4
 *   gOekakiBgTemplate2     0x02186B8C  data  ov023  a4
 *   gOekakiBgTemplate4     0x02186BAC  data  ov023  a4
 *   gOekakiBgTemplate5     0x02186B4C  data  ov023  a4
 *   STRBUF_Create  0x020457B0  arm
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gOekakiFileName     0x02186F58  data  ov023  a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   OEKAKI_StepKeepState  0x02185930  thumb  ov023
 *   gOekakiButtonLayout     0x02186BEC  data  ov023  a2
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_Clear  0x02043B5C  arm
 *   TCBL_Create  0x0203101C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   TCBL_DeleteAllTasks  0x0203115C  arm
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   gOekakiButtonHitTable     0x02186AFC  data  ov023  a4
 *   gOekakiCanvasHitTable     0x02186AB4  data  ov023  a4
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   APP_TASKMENU_TransWinAfterPrint  0x020278F4  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   OEKAKI_OpenGroup  0x02184560  thumb  ov023
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   UNION_APP_Close  0x02184114  thumb  ov022
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   BMP_CreateFromBuffer  0x020436FC  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_Delete  0x020437AC  arm
 *   gOekakiBrushPixels     0x02186C34  data  ov023  a4
 *   GF_STANDARD_SinFromDegreesWrapped  0x0203F684  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   GFL_NET_ResetSendQueue  0x0203D56C  arm
 *   OEKAKI_FillSendGroup  0x02186A04  thumb  ov023
 *   gOekakiQuitHitTable  0x02186AAC  data
 *   gOekakiMenuItemInit  0x02186ABC  data
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb  arm9
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 *   BG_SYS_SetPlaneVisible  0x02040588  arm  arm9
 *   MSGDATA_AllocString  0x02045EC0  arm  arm9
 *   MYSTATUS_GetId  0x02008530  thumb  arm9
 */
#include "../types.h"
#include "../sdk_ioreg.h"
/* The DS code passes the net handle to GFL_NET_ResetSendQueue (docs/ORIGINAL_BUGS.tsv). */
#ifdef __MWERKS__
#define GFL_NET_ResetSendQueue GFL_NET_ResetSendQueue_header
#endif
struct Tcbl;

#include "../ov022/union_app_types.h"
struct TcbTask;
typedef struct Strbuf StrBuf;
typedef struct ClactActor ClActor;
struct Tcbl;
typedef struct TaskMenuRes TaskMenuRes;
typedef struct TaskMenuWork TaskMenu;
typedef struct GFLNetHandle NetHandle;
typedef struct MetTrainersSave MetList;
struct BmpWin;
struct WordSet;
struct MsgBank;
#include "oekaki_types.h"

#define OEKAKI_HEAP_ID          0x28
#define REG_MASTER_BRIGHT_A     REG_MASTER_BRIGHT_ADDR
#define REG_MASTER_BRIGHT_B     REG_DB_MASTER_BRIGHT_ADDR

struct BmpWin;
struct Bmp;
struct MsgBank;
struct WordSet;
struct Proc;
struct DispVram;
#include "../arm9/bg_sys.h"
#include "../arm9/net.h"
#include "../arm9/net_system.h"
#include "../arm9/net_handle.h"
#include "../arm9/net_command.h"
#include "../arm9/mi_memory.h"
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *window);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct BmpWin *window);
extern void BMP_WIN_MakeScreen(struct BmpWin *window);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *window);
#include "../ov022/union_app.h"
#include "../arm9/math.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/gf_font.h"
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
#include "../arm9/wipe.h"
#include "../arm9/arc_tool.h"
#include "../arm9/net_err.h"
#include "../arm9/tcb_list.h"
#include "../arm9/tcbl.h"
#include "../arm9/bmp_win.h"
#include "../arm9/bmp.h"
#include "../arm9/printsys.h"
#include "../arm9/touchpanel.h"
#include "../arm9/wordset.h"
#include "../arm9/gfl_use.h"
extern u32 MSGDATA_Delete(struct MsgBank *msgBank);
extern u32 WORDSET_Delete(struct WordSet *wordSet);
#include "../arm9/gfl_heap_wrap.h"
void CLACT_VBlankSystem(void);
extern StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, StrBuf *dest);
extern void STRBUF_Delete(StrBuf *vec);
#include "../arm9/gx.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/app_icon.h"
void OEKAKI_RegisterNetCommands(OekakiWork *work);
void OEKAKI_RecvCanvasChunk(int netId, int size, CanvasChunk *chunk, OekakiWork *work, int netHandle);
void OEKAKI_RecvStroke(int netId, int size, const StrokeRec *stroke, OekakiWork *work);
void OEKAKI_RecvStrokes(int netId, int size, const u8 *strokes, OekakiWork *work);
void OEKAKI_RecvReset(int netId, int size, int unused, OekakiWork *work);
void OEKAKI_RecvSyncMessage(int netId, int size, const OekakiSyncMsg *msg, OekakiWork *work);
void OEKAKI_RecvAck(int netId, int size, int unused, OekakiWork *work);
void OEKAKI_RecvMemberJoined(int netId, int size, u8 *data, OekakiWork *work, int netHandle);
void OEKAKI_RecvCanvasDone(int netId, int size, int unused, OekakiWork *work);
u32 OEKAKI_SendCanvasChunk(OekakiWork *work, int chunkIndex, int unused);
CanvasChunk *OEKAKI_GetRecvChunk(int netId, OekakiWork *work);
void OEKAKI_OpenGroup(OekakiWork *work, int maxCount);
int OEKAKI_Init(void *task, int *state, OekakiParam *param);
int OEKAKI_Main(void *task, int *state, int unused, OekakiWork *work);
int OEKAKI_Exit(struct Proc *task, int *seq, void *unused, OekakiWork *work);
void OEKAKI_VBlankTask(struct TcbTask *task, void *work);
void OEKAKI_OnMemberJoined(int netId, UnionAppEntry *entry, void *work);
void OEKAKI_OnMemberLeft(int netId, UnionAppEntry *entry, void *work);
void OEKAKI_SetVramBanks(void);
void OEKAKI_SetupBgs(void);
void OEKAKI_InitWork(OekakiWork *work);
void OEKAKI_FreeWork(OekakiWork *work);
void OEKAKI_ResetDisplay(void);
void OEKAKI_LoadBgGraphics(OekakiWork *work, void *archive);
void OEKAKI_LoadSpriteResources(OekakiWork *work, void *archive);
extern NetCommandEntry gOekakiCommandTable[];
extern OekakiSceneStep gOekakiSceneTable[];
extern const struct DispVram gOekakiVramBanks;
extern const struct DispConfig gOekakiDispConfig;
extern const struct BgTemplate gOekakiBgTemplate0;
extern const struct BgTemplate gOekakiBgTemplate1;
extern const struct BgTemplate gOekakiBgTemplate2;
extern const struct BgTemplate gOekakiBgTemplate4;
extern const struct BgTemplate gOekakiBgTemplate5;
extern char gOekakiFileName[];
extern const struct ClactSysInit gClActorInitParam;

/* A stroke record copied bytewise (the copy order of the original differs from the member copy). */
typedef struct StrokeBytes {
    u8 b[4];
    u8 lo : 3, mid : 3, hi : 2;
    u8 extra;
} StrokeBytes;

typedef struct StrokeBytesGroup {
    StrokeBytes r[5];
} StrokeBytesGroup;

#include "../arm9/clact.h"
typedef struct ActorInitParam ClActorPos;

/* Screen position and animation of one touch button. */
typedef struct ButtonLayout {
    u16 x;
    u16 y;
    u16 anim;
} ButtonLayout;

typedef struct Point16 {
    u16 x;
    u16 y;
} Point16;

/* Message and result of one item of the yes/no menu. */
typedef struct MenuItemInit {
    u32 msgId;
    u32 result;
} MenuItemInit;

extern void BMP_WIN_Init(u16 heapId);
extern void BMP_Clear(struct Bmp *bmp, u8 color);
extern u32 BMP_WIN_Delete(struct BmpWin *d);
extern void BMP_WIN_Exit(void);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int  TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
#include "../arm9/g2.h"
#include "../arm9/app_taskmenu.h"
extern void BMP_Delete(struct Bmp *p);
#include "../arm9/gf_standard.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/mystatus.h"
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, StrBuf *dst, StrBuf *src);
extern signed char MSG_SPEED_GetWait(void);
#include "../arm9/key.h"
extern StrBuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

#include "../arm9/game_data.h"
#include "../arm9/met_trainers_savedata.h"
extern const ButtonLayout gOekakiButtonLayout[];
extern char gOekakiButtonHitTable[];
extern char gOekakiCanvasHitTable[];
extern const u8 gOekakiBrushPixels[];
extern int d_02186E84[][2];
extern char gOekakiQuitHitTable[];
extern const MenuItemInit gOekakiMenuItemInit[];

void OEKAKI_CreateActors(OekakiWork *p);
void OEKAKI_CreateWindows(OekakiWork *p, void *task);
void OEKAKI_DeleteWindows(OekakiWork *p);
void OEKAKI_SetCursorPosition(ClActor *actor, int x, int y);
void OEKAKI_MakeEmptyStroke(StrokeRec *stroke, int color, int size);
void OEKAKI_HandleTouch(OekakiWork *p);
void OEKAKI_SelectColorButton(ClActor **buttons, int selected);
void OEKAKI_SetQuitButtonPressed(ClActor *button, int pressed);
int OEKAKI_StepDraw(OekakiWork *p, int procState);
void OEKAKI_ApplyRemoteStrokes(OekakiWork *p);
int OEKAKI_StepStart(OekakiWork *p, int procState);
int OEKAKI_StepHideCursors(OekakiWork *p, int procState);
int OEKAKI_StepEnterDraw(OekakiWork *p, int procState);
int OEKAKI_StepOpenQuitMenu(OekakiWork *p, int procState);
int OEKAKI_StepQuitMenuResult(OekakiWork *p, int procState);
int OEKAKI_StepSendQuitRequest(OekakiWork *p, int procState);
int OEKAKI_StepResetWaitTimer(OekakiWork *p, int procState);
int OEKAKI_StepWaitQuitReply(OekakiWork *p, int procState);
int OEKAKI_StepSendQuitConfirm(OekakiWork *p, int procState);
int OEKAKI_StepCancelQuit(OekakiWork *p, int procState);
int OEKAKI_StepShowQuitMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitQuitMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitThenFadeOut(OekakiWork *p, int procState);
int OEKAKI_StepOpenFinishMenu(OekakiWork *p, int procState);
int OEKAKI_StepFinishMenuResult(OekakiWork *p, int procState);
void OEKAKI_RegisterPlayerName(OekakiWork *p, int wordIndex, int netId);
int OEKAKI_StepSendFinishRequest(OekakiWork *p, int procState);
int OEKAKI_StepShowFinishMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitFinishMessage(OekakiWork *p, int procState);
int OEKAKI_StepCheckMembers(OekakiWork *p, int procState);
int OEKAKI_StepKeepState(int unused, int procState);
int OEKAKI_StepShowWaitMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitMessage(OekakiWork *p, int procState);
int OEKAKI_StepShowSyncMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitSyncAck(OekakiWork *p, int procState);
int OEKAKI_StepWaitSyncTimer(OekakiWork *p, int procState);
void OEKAKI_HandleEvent(OekakiWork *p, int event, int netId);
void OEKAKI_BlitBrush(struct BmpWin *canvas, const u8 *brushPixels, int x, int y, int width, int height, int srcX, int srcY, int maxCutX, int maxCutY);
void OEKAKI_DrawLine(struct BmpWin *canvas, const u8 *brushPixels, int x1, int y1, int *px, int *py, int newStroke, int prevCount);
void OEKAKI_StoreLastPoints(StrokeRec *strokes, LastPoint *last);
void OEKAKI_DrawStrokes(struct BmpWin *canvas, StrokeRec *strokes, LastPoint *last, int redraw);
void OEKAKI_UpdateRemoteCursors(OekakiWork *p);
void OEKAKI_AnimatePalette(u16 *angle);
int OEKAKI_CountMembers(OekakiWork *p);
void OEKAKI_RefreshNamePlates(struct BmpWin **windows, u16 color, OekakiWork *p);
void OEKAKI_SendStrokes(OekakiWork *p);
int OEKAKI_GetMemberCount(OekakiWork *p);
int OEKAKI_UpdateMemberSlots(OekakiWork *p);
void OEKAKI_PrintMessage(OekakiWork *p, u32 msgId, int mode);
int OEKAKI_IsMessageDone(OekakiWork *p);
void OEKAKI_ClearMessageWindow(OekakiWork *p);
void OEKAKI_HostOpenGroupLimited(OekakiWork *p, int flag);
int OEKAKI_UpdateMembers(OekakiWork *p);
void OEKAKI_SetNextScene(OekakiWork *p, u32 nextScene);
void OEKAKI_ApplySceneChange(OekakiWork *p, int mode);
void OEKAKI_CloseMenuIfOpen(OekakiWork *p);
int OEKAKI_IsQuitTouched(OekakiWork *p);
void OEKAKI_MakeStroke(StrokeRec *stroke, TouchPoint *path, int color, int size);
int OEKAKI_GetJoinedCount(OekakiWork *p);
int OEKAKI_GetJoinedBits(OekakiWork *p);
void OEKAKI_EnableDisplays(void);
TaskMenu *OEKAKI_OpenYesNoMenu(OekakiWork *p);
int OEKAKI_PollYesNoMenu(OekakiWork *p);
void OEKAKI_CloseYesNoMenu(OekakiWork *p);
void OEKAKI_RegisterMetPlayers(OekakiWork *p);
void OEKAKI_UpdatePrintJobs(OekakiWork *p);
void OEKAKI_SendPendingCommand(OekakiWork *p);
void OEKAKI_QueueCommand(OekakiWork *p, int commandId, int arg);
int OEKAKI_GetPrevQueueIndex(StrokeQueue *queue);
void OEKAKI_AdvanceQueueTailIfUsed(StrokeQueue *queue);
void OEKAKI_AdvanceQueueTail(StrokeQueue *queue);
void OEKAKI_ClearStrokeGroup(StrokeRec *rec);
void OEKAKI_PopStrokeGroup(StrokeQueue *queue);
void OEKAKI_StoreStroke(StrokeBytes *stroke, StrokeQueue *queue, int index);
void OEKAKI_PeekStroke(StrokeRec *dst, StrokeQueue *queue);
void OEKAKI_FillSendGroup(StrokeGroup *sendGroup, StrokeQueue *queue);

/*
 * Registers the net commands 0x2900..0x2907 of the application.
 */
void OEKAKI_RegisterNetCommands(OekakiWork *work)
{
    GFL_NET_COMMAND_AddCommandTable(OEKAKI_CMD_CANVAS_CHUNK, gOekakiCommandTable, 8, work);
}

/*
 * Net command 0x2900: a chunk of the canvas arrives.
 */
void OEKAKI_RecvCanvasChunk(int netId, int size, CanvasChunk *chunk, OekakiWork *work, int netHandle)
{
    int sent;
    int offset;
    struct BmpWin *window;

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        offset = chunk->index * 0x3e8;
        if (offset > 0x3840) {
            MIi_CpuCopyFast(chunk, work->canvas + offset, 0x190);
        } else {
            MIi_CpuCopyFast(chunk, work->canvas + offset, 0x3e8);
        }
        MIi_CpuCopyFast(work->canvas,
                      BMP_GetPixels(BMP_WIN_GetBmp(work->canvasWindow)),
                      OEKAKI_CANVAS_BYTES);
        window = work->canvasWindow;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    } else {
        sent = work->nextChunk;
        if (sent * 1000 < 0x3840) {
            work->nextChunk += 1;
            OEKAKI_SendCanvasChunk(work, work->nextChunk, netHandle);
        } else {
            OEKAKI_QueueCommand(work, OEKAKI_CMD_CANVAS_DONE, 0);
        }
    }
}

/*
 * Net command 0x2901: one stroke of the member netId arrives (parent only).
 */
void OEKAKI_RecvStroke(int netId, int size, const StrokeRec *stroke, OekakiWork *work)
{
    if (netId != 0)
        OEKAKI_StoreStroke((StrokeBytes *)stroke, &work->strokeQueue, netId);
}

/*
 * Net command 0x2902: the strokes of all members of one frame arrive (children).
 *
 * stand-in: the six bytes of each record are stored at dst[0x4212 + k] with
 * dst = work + i * 6. Typed fields (work->remoteStroke[i], with or without
 * a struct copy) hoist the address of the array and compile differently.
 */
void OEKAKI_RecvStrokes(int netId, int size, const u8 *strokes, OekakiWork *work)
{
    int i;
    u8 *dst;
    const u8 *src;

    if (work != 0 && netId == 0) {
        for (i = 0; i < OEKAKI_MEMBER_MAX; i++) {
            dst = (u8 *)work + i * 6;
            src = strokes + i * 6;
            dst[0x4212] = src[0];
            dst[0x4213] = src[1];
            dst[0x4214] = src[2];
            dst[0x4215] = src[3];
            dst[0x4216] = src[4];
            dst[0x4217] = src[5];
        }
    }
}

/*
 * The canvas is cleared and the member list is read again from the
 * union application.
 */
void OEKAKI_RecvReset(int netId, int size, int unused, OekakiWork *work)
{
    OEKAKI_HandleEvent(work, 3, 0);
    MIi_CpuClearFast(0, work->canvas, OEKAKI_CANVAS_BYTES);
    work->baseMemberCount = UNION_APP_GetMemberCount(work->param->app);
    work->baseJoinedBits = UNION_APP_GetJoinedBits(work->param->app);
    work->syncMode = 1;
}

/*
 * The message is copied field by field through a const pointer: that is
 * what lets the four loads pair up ahead of the stores and keeps msg->kind in
 * r0 for the switch (a struct copy, or a non-const msg, reloads it).
 *
 * Addresses are Black-image addresses.
 */
void OEKAKI_RecvSyncMessage(int netId, int size, const OekakiSyncMsg *msg, OekakiWork *work)
{
    int sender;

    if (netId != 0) {
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            return;
        }
        work->stateMsg.netId = msg->netId;
        work->stateMsg.memberCount = msg->memberCount;
        work->stateMsg.kind = msg->kind;
        work->stateMsg.accepted = msg->accepted;
        work->stateMsg.netId = netId;
        work->stateMsg.memberCount = work->baseMemberCount;
        switch (msg->kind) {
        case OEKAKI_SYNC_CHECK:
            if (work->baseMemberCount != UNION_APP_GetMemberCount(work->param->app)
                || work->baseMemberCount != MATH_CountPopulation(UNION_APP_GetJoinedBits(work->param->app))) {
                work->stateMsg.accepted = 0;
            } else {
                work->stateMsg.accepted = 1;
                UNION_APP_Open(work->param->app);
            }
            break;
        case OEKAKI_SYNC_STATUS:
            break;
        }
        OEKAKI_QueueCommand(work, OEKAKI_CMD_SYNC_MESSAGE, 0);
        return;
    }
    switch (msg->kind) {
    case OEKAKI_SYNC_CHECK:
        sender = msg->netId;
        if (sender != GFL_NET_SYSTEM_GetCurrentAid()) {
            return;
        }
        if (msg->accepted == 0) {
            OEKAKI_HandleEvent(work, 0xb, sender);
            return;
        }
        work->agreedMemberCount = msg->memberCount;
        OEKAKI_HandleEvent(work, 9, msg->netId);
        work->quitting = 1;
        return;
    case OEKAKI_SYNC_STATUS:
        if (work->quitting == 0) {
            OEKAKI_HandleEvent(work, 0x18, msg->netId);
        }
        return;
    }
}

/*
 * Net command 0x2907: a child answers; its bit is set in ackBits (parent only).
 */
void OEKAKI_RecvAck(int netId, int size, int unused, OekakiWork *work)
{
    if (GFL_NET_SYSTEM_GetCurrentAid())
        return;
    work->waitMemberBits |= 1 << netId;
}

/*
 * Net command 0x2903: a member joined. The parent then starts to send the
 * canvas, chunk by chunk.
 */
void OEKAKI_RecvMemberJoined(int netId, int size, u8 *data, OekakiWork *work, int netHandle)
{
    if (work->canvasReceived == 0) {
        OEKAKI_HandleEvent(work, 1, *data);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && work->state == 1) {
            work->nextChunk = 0;
            OEKAKI_SendCanvasChunk(work, 0, netHandle);
        }
    }
}

/*
 * Net command 0x2904: the whole canvas was sent.
 */
void OEKAKI_RecvCanvasDone(int netId, int size, int unused, OekakiWork *work)
{
    work->canvasReceived = 1;
    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        OEKAKI_HandleEvent(work, 0x12, 0);
}

/*
 * Sends chunk chunkIndex of the canvas to all members. The extent runs
 * long: 0x0218454C is an unlabelled leaf,
 * CanvasChunk *f(int netId, OekakiWork *work) { return &work->recvChunk[netId]; }
 */
u32 OEKAKI_SendCanvasChunk(OekakiWork *work, int chunkIndex, int unused)
{
    int i;
    u32 *words;
    u8 *pixels;
    u32 sum;
    u8 joinedBits;

    pixels = BMP_GetPixels(BMP_WIN_GetBmp(work->canvasWindow));
    MIi_CpuCopyFast(pixels + chunkIndex * 1000, work->sendChunk.data, 1000);
    words = (u32 *)work->sendChunk.data;
    sum = 0;
    for (i = 0; i < 250; i++)
        sum ^= words[i];
    work->sendChunk.checksum = sum;
    work->sendChunk.index = chunkIndex;
    joinedBits = (u32)UNION_APP_GetJoinedBits(work->param->app);
    return GFL_NET_COMMAND_SetSendSlot(GFL_NET_HANDLE_GetNetHandle(0xff), joinedBits, OEKAKI_CMD_CANVAS_CHUNK, 0x3f0, &work->sendChunk);
}

CanvasChunk *OEKAKI_GetRecvChunk(int netId, OekakiWork *work)
{
    return &work->recvChunk[netId];
}

/*
 * Opens the group to maxCount members (the parent decides how many join).
 */
void OEKAKI_OpenGroup(OekakiWork *work, int maxCount)
{
    UNION_APP_OpenLimited(work->param->app, maxCount);
}

/*
 * Step function: builds the application (screens, graphics, resources, net
 * commands) and starts the main step.
 *
 * Addresses are Black-image addresses.
 */
int OEKAKI_Init(void *task, int *state, OekakiParam *param)
{
    OekakiWork *work;
    void *archive;

    switch (*state) {
    case 0:
        BG_SYS_ClearMainPlanes();
        BG_SYS_ClearSubPlanes();
        GFL_HEAP_CreateChildHeap(1, OEKAKI_HEAP_ID, 0x50000);
        work = PROCSYS_AllocProcWork(task, OEKAKI_WORK_SIZE, OEKAKI_HEAP_ID);
        MI_CpuFill8(work, 0, OEKAKI_WORK_SIZE);
        BG_SYS_Create(OEKAKI_HEAP_ID);
        work->wordSet = WORDSET_CreateDefault(OEKAKI_HEAP_ID);
        work->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x53, OEKAKI_HEAP_ID);
        work->font = GF_FONT_Create(0x17, 0, 0, 0, OEKAKI_HEAP_ID);
        OEKAKI_SetVramBanks();
        OEKAKI_SetupBgs();
        WIPE_SYS_Start(0, 9, 9, 0, 0x10, 1, OEKAKI_HEAP_ID);
        work->param = param;
        archive = ARC_TOOL_CreateHandle(0xbf, OEKAKI_HEAP_ID);
        OEKAKI_LoadBgGraphics(work, archive);
        work->vblankTask = GFL_USE_AddMainTask(OEKAKI_VBlankTask, work, 0);
        OEKAKI_InitWork(work);
        OEKAKI_LoadSpriteResources(work, archive);
        OEKAKI_CreateActors(work);
        OEKAKI_CreateWindows(work, task);
        OEKAKI_EnableDisplays();
        OEKAKI_RegisterNetCommands(work);
        OEKAKI_RegisterMetPlayers(work);
        GFL_NET_RefreshWmIconAtTopRight(1, OEKAKI_HEAP_ID);
        ARC_TOOL_DeleteHandle(archive);
        (*state)++;
        break;
    case 1:
        *state = 0;
        return 1;
    }
    return 0;
}

/*
 * Main step. The mode handlers take (work, *state): the switch value,
 * reused as their second argument, is what keeps it live in r1 through the
 * dispatch (a one-argument callback puts the whole dispatch in r0).
 * OEKAKI_ApplySceneChange is void but leaves r0 = work; no hidden argument here.
 *
 * Addresses are Black-image addresses.
 */
int OEKAKI_Main(void *task, int *state, int unused, OekakiWork *work)
{
    int (*handler)(OekakiWork *work, int state);
    int next;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && work->waitMemberBits != 0) {
        work->waitMemberBits = OEKAKI_GetJoinedBits(work) & work->waitMemberBits;
    }
    work->state = *state;
    OEKAKI_ApplySceneChange(work, *state);
    switch (*state) {
    case 0:
        if (WIPE_SYS_EndCheck() != 0) {
            UNION_APP_SetCallbacks(work->param->app, OEKAKI_OnMemberJoined, OEKAKI_OnMemberLeft, work);
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                OEKAKI_OpenGroup(work, 1);
            }
            *state = 1;
        }
        break;
    case 1:
        handler = gOekakiSceneTable[work->scene].handler;
        if (handler != 0) {
            *state = handler(work, *state);
        }
        OEKAKI_RefreshNamePlates(work->nameWindow, 0x44f, work);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            next = OEKAKI_UpdateMembers(work);
            if (*state == 1) {
                *state = next;
            }
        }
        OEKAKI_AnimatePalette(&work->paletteAngle);
        break;
    case 2:
        handler = gOekakiSceneTable[work->scene].handler;
        if (handler != 0 && gOekakiSceneTable[work->scene].runsInWait != 0) {
            *state = handler(work, *state);
        }
        break;
    case 3:
        if (WIPE_SYS_EndCheck() != 0) {
            GFL_NET_COMMAND_DeleteCommandTable(OEKAKI_CMD_CANVAS_CHUNK);
            UNION_APP_RequestReset(work->param->app);
            *state = 4;
        }
        break;
    case 4:
        if (UNION_APP_IsResetDone(work->param->app) != 0) {
            return 1;
        }
        break;
    }
    OEKAKI_SendPendingCommand(work);
    CLACT_DrawSystem();
    TCBL_Main(work->taskList);
    OEKAKI_UpdatePrintJobs(work);
    if (WIPE_SYS_EndCheck() != 0 && GFL_NET_ERR_GetErrorLevel() != 0) {
        return 1;
    }
    return 0;
}

/*
 * Exit step: frees the resources and the work in order.
 */
int OEKAKI_Exit(struct Proc *task, int *seq, void *unused, OekakiWork *work)
{
    switch (*seq) {
    case 0:
        TCB_DeleteTask(work->vblankTask);
        CLACT_ReleaseCharacter(work->nameTagRes.charRes);
        CLACT_ReleasePalette(work->nameTagRes.plttRes);
        CLACT_ReleaseCellAnim(work->nameTagRes.cellRes);
        CLACT_ReleaseCharacter(work->buttonRes.charRes);
        CLACT_ReleasePalette(work->buttonRes.plttRes);
        CLACT_ReleaseCellAnim(work->buttonRes.cellRes);
        CLACT_ReleaseCharacter(work->cursorRes.charRes);
        CLACT_ReleasePalette(work->cursorRes.plttRes);
        CLACT_ReleaseCellAnim(work->cursorRes.cellRes);
        CLACT_DeleteUnit(work->clactSys);
        CLACT_ExitSystem();
        if (work->menu != 0) {
            OEKAKI_CloseYesNoMenu(work);
        }
        OEKAKI_DeleteWindows(work);
        OEKAKI_ResetDisplay();
        MSGDATA_Delete(work->msgBank);
        WORDSET_Delete(work->wordSet);
        GF_FONT_Delete(work->font);
        (*seq)++;
        break;
    case 1:
        (*seq)++;
        break;
    case 2:
        if (work->memberLeft != 0) {
            if (OEKAKI_GetJoinedBits(work) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 3:
        OEKAKI_FreeWork(work);
        PROCSYS_FreeProcWork(task);
        GFL_HEAP_DeleteChecked(OEKAKI_HEAP_ID);
        return 1;
    }
    return 0;
}

/*
 * Task that runs every vertical blank.
 */
void OEKAKI_VBlankTask(struct TcbTask *task, void *work)
{
    CLACT_VBlankSystem();
    BG_SYS_Update();
}

/*
 * Member join callback of the union application (the parent announces the
 * new member to the others). Extent follower 0x021848CC is already matched
 * separately.
 */
void OEKAKI_OnMemberJoined(int netId, UnionAppEntry *entry, void *arg)
{
    OekakiWork *work = arg;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
        OEKAKI_QueueCommand(work, OEKAKI_CMD_MEMBER_JOINED, netId);
    OEKAKI_RegisterMetPlayers(work);
}

/*
 * Member leave callback of the union application: nothing to do. An
 * unlabelled empty function (a lone bx lr after OEKAKI_OnMemberJoined's pool);
 * OEKAKI_Main hands its address to ov022 UNION_APP_SetCallbacks. Blocker of
 * ov023 OEKAKI_Main.
 */
void OEKAKI_OnMemberLeft(int netId, UnionAppEntry *entry, void *work)
{
}

/*
 * Tail call: apply the VRAM bank descriptor at 0x02186ACC.
 */
void OEKAKI_SetVramBanks(void)
{
    BG_SYS_SetVramBanks(&gOekakiVramBanks);
}

void OEKAKI_SetupBgs(void)
{
    struct DispConfig dispConfig;
    struct BgTemplate bg0;
    struct BgTemplate bg1;
    struct BgTemplate bg2;
    struct BgTemplate bg4;
    struct BgTemplate bg5;

    dispConfig = gOekakiDispConfig;
    BG_SYS_SetGraphicsMode(&dispConfig);

    bg0 = gOekakiBgTemplate0;
    BG_SYS_InitBgLayer(0, &bg0, 0);
    BG_SYS_ClearSlot(0);

    bg1 = gOekakiBgTemplate1;
    BG_SYS_InitBgLayer(1, &bg1, 0);
    BG_SYS_ClearSlot(1);

    bg2 = gOekakiBgTemplate2;
    BG_SYS_InitBgLayer(2, &bg2, 0);

    bg4 = gOekakiBgTemplate4;
    BG_SYS_InitBgLayer(4, &bg4, 0);
    BG_SYS_ClearSlot(4);

    bg5 = gOekakiBgTemplate5;
    BG_SYS_InitBgLayer(5, &bg5, 0);

    BG_SYS_InitRun(0, 0x20, 0, OEKAKI_HEAP_ID);
    BG_SYS_InitRun(4, 0x20, 0, OEKAKI_HEAP_ID);
    BG_SYS_InitRun(1, 0x20, 0, OEKAKI_HEAP_ID);
    BG_SYS_InitRun(5, 0x20, 0, OEKAKI_HEAP_ID);
}

/*
 * Sets the initial values of the work.
 */
void OEKAKI_InitWork(OekakiWork *work)
{
    int i = 0;
    sptr zero = i;

    for (; i < OEKAKI_MEMBER_MAX; i++) {
        work->playerName[i] = STRBUF_Create(8, OEKAKI_HEAP_ID);
        work->remoteStroke[i].count = 0;
        work->lastPoint[i].count = zero;
        work->memberSlot[i].current = (UnionAppEntry *)zero;
        work->memberSlot[i].previous = (UnionAppEntry *)zero;
    }
    work->labelText = STRBUF_Create(0xA, OEKAKI_HEAP_ID);
    work->messageText = STRBUF_Create(0x50, OEKAKI_HEAP_ID);
    work->penColor = zero;
    work->penSize = 1;
    work->syncMode = 1;
    work->menuOpen = zero;
    work->baseMemberCount = 2;
    work->baseJoinedBits = OEKAKI_GetJoinedBits(work);
    work->leaveRequested = zero;
    work->memberLeft = zero;
    work->scene = zero;
    work->newMemberPending = zero;
    work->newMemberBits = zero;
    work->menu = (TaskMenu *)zero;
    GFL_NET_SYSTEM_GetCurrentAid();
    OEKAKI_SetNextScene(work, 4);
    MSGDATA_ReadString(work->msgBank, 7, work->labelText);
    work->tempBuf = GFL_HEAP_Alloc(OEKAKI_HEAP_ID, 0x3C00, zero, gOekakiFileName, 0x31D);
    work->lastMemberCount = zero;
}

void OEKAKI_FreeWork(OekakiWork *work)
{
    int i;
    GFL_HEAP_Free(work->tempBuf);
    for (i = 0; i < OEKAKI_MEMBER_MAX; i++)
        STRBUF_Delete(work->playerName[i]);
    STRBUF_Delete(work->messageText);
    STRBUF_Delete(work->labelText);
}

void OEKAKI_ResetDisplay(void)
{
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_A, -16);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_B, -16);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}

void OEKAKI_LoadBgGraphics(OekakiWork *work, void *archive)
{
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0, 0, 0, 0x180, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 1, 4, 0, 0x180, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1A0, 0x20, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1A0, 0x20, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadBgCharFromHandle(archive, 2, 2, 0, 0x2000, 0, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 6, 2, 0, 0x600, 0, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadBgCharFromHandle(archive, 4, 5, 0, 0x2000, 0, OEKAKI_HEAP_ID);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 7, 5, 0, 0x600, 0, OEKAKI_HEAP_ID);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 10, 0, OEKAKI_HEAP_ID);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1F, 11, 0, OEKAKI_HEAP_ID);
}

void OEKAKI_LoadSpriteResources(OekakiWork *work, void *archive)
{
    void *uiArchive;
    u32 plttIndex;

    uiArchive = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), OEKAKI_HEAP_ID);
    CLACT_InitSystem(&gClActorInitParam, (const struct DispVramCfg *)&gOekakiVramBanks, OEKAKI_HEAP_ID);
    work->clactSys = CLACT_CreateUnit(0x35, 1, OEKAKI_HEAP_ID);
    work->cursorRes.charRes = CLACT_RegisterCharacter(archive, 3, 0, 0, OEKAKI_HEAP_ID);
    work->cursorRes.plttRes = CLACT_RegisterPalette(archive, 0, 0, 0, OEKAKI_HEAP_ID);
    work->cursorRes.cellRes = CLACT_RegisterCellAnim(archive, 5, 8, OEKAKI_HEAP_ID);
    work->buttonRes.charRes = CLACT_RegisterCharacter(uiArchive, APP_ICON_GetMoveKindAnimFileId(), 0, 0, OEKAKI_HEAP_ID);
    work->buttonRes.plttRes = CLACT_RegisterPaletteEx(uiArchive, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x160, 0, 3, OEKAKI_HEAP_ID);
    plttIndex = APP_ICON_GetStatusCellFileId(0);
    work->buttonRes.cellRes = CLACT_RegisterCellAnim(uiArchive, plttIndex, APP_ICON_GetStatusPaletteFileId(0), OEKAKI_HEAP_ID);
    work->nameTagRes.charRes = CLACT_RegisterCharacter(archive, 3, 0, 1, OEKAKI_HEAP_ID);
    work->nameTagRes.plttRes = CLACT_RegisterPalette(archive, 0, 1, 0, OEKAKI_HEAP_ID);
    work->nameTagRes.cellRes = CLACT_RegisterCellAnim(archive, 5, 8, OEKAKI_HEAP_ID);
    ARC_TOOL_DeleteHandle(uiArchive);
}

void OEKAKI_CreateActors(OekakiWork *p)
{
    ClActorPos pos;
    int i;
    int j;

    pos.x = 0;
    pos.y = 0;
    pos.anim_seq = 0;
    pos.draw_priority = 1;
    pos.bg_priority = 1;
    for (i = 0; i < 5; i++) {
        pos.x = i * 0x28 + 0x18;
        pos.y = 0x40;
        p->cursorActor[i] = CLACT_CreateActor(p->clactSys, p->cursorRes.charRes, p->cursorRes.plttRes, p->cursorRes.cellRes, &pos, 0, 0x28);
        CLACT_SetActorAutoAnim(p->cursorActor[i], 1);
        CLACT_SetActorAnimSeq(p->cursorActor[i], i);
        CLACT_SetActorDrawEnable(p->cursorActor[i], 0);
    }
    for (j = 0; j < 12; j++) {
        pos.x = gOekakiButtonLayout[j].x;
        pos.y = gOekakiButtonLayout[j].y;
        p->colorButton[j] = CLACT_CreateActor(p->clactSys, p->cursorRes.charRes, p->cursorRes.plttRes, p->cursorRes.cellRes, &pos, 0, 0x28);
        CLACT_SetActorAutoAnim(p->colorButton[j], 1);
        CLACT_SetActorAnimSeq(p->colorButton[j], gOekakiButtonLayout[j].anim);
        if (j >= 8) {
            CLACT_SetActorBgPriority(p->colorButton[j], 2);
        }
    }
    CLACT_SetActorAnimSeq(p->colorButton[0], 6);
    for (i = 0; i < 5; i++) {
        pos.x = 0x18;
        pos.y = i * 0x20 + 0x20 + 0x100000u;
        p->nameTagActor[i] = CLACT_CreateActor(p->clactSys, p->nameTagRes.charRes, p->nameTagRes.plttRes, p->nameTagRes.cellRes, &pos, 1, 0x28);
        CLACT_SetActorAutoAnim(p->nameTagActor[i], 1);
        CLACT_SetActorAnimSeq(p->nameTagActor[i], i);
        CLACT_SetActorDrawPriority(p->nameTagActor[i], 1);
        CLACT_SetActorDrawEnable(p->nameTagActor[i], 0);
    }
    pos.x = 0xD4;
    pos.y = 0xA0;
    p->quitButton = CLACT_CreateActor(p->clactSys, p->buttonRes.charRes, p->buttonRes.plttRes, p->buttonRes.cellRes, &pos, 0, 0x28);
    CLACT_SetActorAutoAnim(p->quitButton, 1);
    CLACT_SetActorAnimSeq(p->quitButton, 1);
    CLACT_SetActorDrawEnable(p->quitButton, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/* The task argument is unused; the caller passes it and the compiled code must carry it in r1. */
void OEKAKI_CreateWindows(OekakiWork *p, void *task)
{
    int i;
    struct BmpWin *window;

    BMP_WIN_Init(0x28);
    p->messageWindow = BMP_WIN_Create(0, 2, 1, 0x1b, 4, 0xd, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->messageWindow), 0xf);
    p->printJob[6].window = p->messageWindow;
    p->printJob[6].busy = 0;
    p->canvasWindow = BMP_WIN_Create(1, 1, 2, 0x1e, 0xf, 0, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->canvasWindow), 2);
    p->taskList = TCBL_Create(0x28, 0x28, 0x20, 0x20);
    p->namePrinter = PRINTSYS_QUE_Create(0x28);
    p->messagePrinter = PRINTSYS_QUE_Create(0x28);
    for (i = 0; i < 5; i++) {
        p->nameWindow[i] = BMP_WIN_Create(4, 5, (u8)(i * 4 + 3), 0xa, 2, 0xd, 1);
        BMP_Clear(BMP_WIN_GetBmp(p->nameWindow[i]), 0);
        /* the print job keeps its own copy of the window pointer */
        p->printJob[i].window = p->nameWindow[i];
        p->printJob[i].busy = 0;
        window = p->nameWindow[i];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    }
    OEKAKI_RefreshNamePlates(p->nameWindow, 0x44f, p);
}

void OEKAKI_DeleteWindows(OekakiWork *p)
{
    int i;

    TCBL_DeleteAllTasks(p->taskList);
    TCBL_Destroy(p->taskList);
    PRINTSYS_QUE_Clear(p->messagePrinter);
    PRINTSYS_QUE_Delete(p->messagePrinter);
    PRINTSYS_QUE_Clear(p->namePrinter);
    PRINTSYS_QUE_Delete(p->namePrinter);
    for (i = 0; i < 5; i++)
        BMP_WIN_Delete(p->nameWindow[i]);
    BMP_WIN_Delete(p->canvasWindow);
    BMP_WIN_Delete(p->messageWindow);
    BMP_WIN_Exit();
}

void OEKAKI_SetCursorPosition(ClActor *actor, int x, int y)
{
    Point16 pt;

    pt.x = x;
    pt.y = y - 8;
    CLACT_SetActorPos(actor, (const struct Pt16 *)&pt);
}

void OEKAKI_MakeEmptyStroke(StrokeRec *stroke, int color, int size)
{
    TouchPath path;

    path.pt[0].count = 0;
    path.pt[0].x = 0;
    path.pt[0].y = 0;
    OEKAKI_MakeStroke(stroke, path.pt, color, size);
}

/* Shared tail of the quit button press: message, state change, button animation, sound. */
static inline u8 pressQuit(OekakiWork *p, int value)
{
    OEKAKI_PrintMessage(p, value, value);
    OEKAKI_SetNextScene(p, 5);
    OEKAKI_SetQuitButtonPressed(p->quitButton, 1);
    GFL_USE_PlaySeDefaultVolume(0x551);
    return value;
}

/*
 * Lever: the activation tail is an inline returning its flag value;
 * assigning the returned u8 to pressed recolours the merged flag store to r1.
 * The pointer-out helper and inline assignment stayed DIFF by two bytes.
 */
void OEKAKI_HandleTouch(OekakiWork *p)
{
    TouchPath path;
    int touchX;
    int touchY;
    StrokeRec stroke;
    int x;
    int y;
    u8 pressed;
    int hit;
    int i;

    pressed = 0;
    hit = TOUCHPANEL_HitTrg((const void *)gOekakiButtonHitTable);
    if (hit != -1) {
        switch (hit) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (p->penColor != hit) {
                p->penColor = hit;
                OEKAKI_SelectColorButton(p->colorButton, hit);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
            break;
        case 8:
            if (p->scene != 4)
                break;
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                if (p->baseJoinedBits != OEKAKI_GetJoinedBits(p)) {
                    GFL_USE_PlaySeDefaultVolume(0x54b);
                } else {
                    p->syncMode = 2;
                    pressed = pressQuit(p, 1);
                }
            } else {
                if (p->remoteStroke[0].syncMode == 2) {
                    GFL_USE_PlaySeDefaultVolume(0x54b);
                } else {
                    pressed = pressQuit(p, 1);
                }
            }
            break;
        case 9:
        case 10:
        case 11:
            for (i = 0; i < 3; i++) {
                if (hit - 9 == i)
                    CLACT_SetActorAnimSeq(p->sizeButton[i], i * 2 + 0x1e);
                else
                    CLACT_SetActorAnimSeq(p->sizeButton[i], i * 2 + 0x1d);
            }
            if (p->penSize != hit - 9) {
                p->penSize = hit - 9;
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
            break;
        }
    }
    hit = TOUCHPANEL_HitCont((const void *)gOekakiCanvasHitTable);
    CLACT_SetActorDrawEnable(p->cursorActor[GFL_NET_SYSTEM_GetCurrentAid()], 0);
    if (hit != -1) {
        TOUCHPANEL_GetPointCont((u32 *)&touchX, (u32 *)&touchY);
        OEKAKI_SetCursorPosition(p->cursorActor[GFL_NET_SYSTEM_GetCurrentAid()], touchX, touchY);
        CLACT_SetActorDrawEnable(p->cursorActor[GFL_NET_SYSTEM_GetCurrentAid()], 1);
    }
    x = 0;
    y = 0;
    if (TOUCHPANEL_GetCont() == 1) {
        TOUCHPANEL_GetPointCont((u32 *)&x, (u32 *)&y);
        path.pt[0].count = 2;
        path.pt[0].x = p->touchPath.pt[1].x;
        path.pt[0].y = p->touchPath.pt[1].y;
        path.pt[1].x = x;
        path.pt[1].y = y;
        OEKAKI_MakeStroke(&stroke, path.pt, p->penColor, p->penSize);
        if (pressed == 1)
            stroke.count = 0;
    } else {
        path.pt[1].x = 0;
        path.pt[1].y = 0;
        OEKAKI_MakeEmptyStroke(&stroke, p->penColor, p->penSize);
    }
    OEKAKI_StoreStroke((StrokeBytes *)&stroke, &p->strokeQueue, 0);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
        OEKAKI_AdvanceQueueTail(&p->strokeQueue);
    else
        OEKAKI_AdvanceQueueTailIfUsed(&p->strokeQueue);
    p->touchPath = path;
}

void OEKAKI_SelectColorButton(ClActor **buttons, int selected)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (i == selected)
            CLACT_SetActorAnimSeq(buttons[i], (u16)(gOekakiButtonLayout[i].anim + 1));
        else
            CLACT_SetActorAnimSeq(buttons[i], gOekakiButtonLayout[i].anim);
    }
}

void OEKAKI_SetQuitButtonPressed(ClActor *button, int pressed)
{
    if (pressed == 1)
        CLACT_SetActorAnimSeq(button, 9);
    else
        CLACT_SetActorAnimSeq(button, 1);
}

int OEKAKI_StepDraw(OekakiWork *p, int procState)
{
    OEKAKI_HandleTouch(p);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (OEKAKI_CountMembers(p) == 1) {
        } else {
            OEKAKI_SendStrokes(p);
        }
    } else {
        OEKAKI_SendStrokes(p);
    }
    OEKAKI_UpdateRemoteCursors(p);
    OEKAKI_DrawStrokes(p->canvasWindow, p->remoteStroke, p->lastPoint, 1);
    return procState;
}

void OEKAKI_ApplyRemoteStrokes(OekakiWork *p)
{
    OEKAKI_UpdateRemoteCursors(p);
    OEKAKI_DrawStrokes(p->canvasWindow, p->remoteStroke, p->lastPoint, 0);
}

int OEKAKI_StepStart(OekakiWork *p, int procState)
{
    if (p->painterNetId == GFL_NET_SYSTEM_GetCurrentAid())
        OEKAKI_PrintMessage(p, 0xd, 0);
    else
        OEKAKI_PrintMessage(p, 0, 0);
    OEKAKI_SetNextScene(p, 2);
    OEKAKI_CloseMenuIfOpen(p);
    GFL_USE_PlaySeDefaultVolume(0x54c);
    G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 14, -6);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepHideCursors(OekakiWork *p, int procState)
{
    int i;

    for (i = 0; i < 5; i++)
        CLACT_SetActorDrawEnable(p->cursorActor[i], 0);
    return procState;
}

/*
 * volatile: hardware halfword store at 0x021853F8 to 0x04000050.
 */
int OEKAKI_StepEnterDraw(OekakiWork *p, int procState)
{
    *(volatile u16 *)0x04000050 = 0;
    OEKAKI_HostOpenGroupLimited(p, 1);
    OEKAKI_SetNextScene(p, 4);
    OEKAKI_ApplyRemoteStrokes(p);
    p->newMemberPending = 0;
    return procState;
}

int OEKAKI_StepOpenQuitMenu(OekakiWork *p, int procState)
{
    if (OEKAKI_IsMessageDone(p)) {
        if (p->menu == 0)
            p->menu = OEKAKI_OpenYesNoMenu(p);
        OEKAKI_SetNextScene(p, 6);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepQuitMenuResult(OekakiWork *p, int procState)
{
    struct BmpWin *window;

    p->localStroke.count = 0;
    if (p->remoteStroke[0].syncMode == 2 && GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        OEKAKI_ApplyRemoteStrokes(p);
        APP_TASKMENU_TransWinAfterPrint(p->menu);
        if (OEKAKI_IsQuitTouched(p))
            GFL_USE_PlaySeDefaultVolume(0x54b);
        return procState;
    }
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && p->waitMemberBits != 0) {
        OEKAKI_ApplyRemoteStrokes(p);
        APP_TASKMENU_TransWinAfterPrint(p->menu);
        return procState;
    }
    switch (OEKAKI_PollYesNoMenu(p)) {
    case 0:
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            OEKAKI_SetNextScene(p, 0xf);
            OEKAKI_PrintMessage(p, 4, 1);
        } else {
            OEKAKI_SetNextScene(p, 8);
            BMP_MENUWORK_DrawWindowBorder(p->messageWindow, 2);
        }
        window = p->canvasWindow;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
        break;
    case 1:
        OEKAKI_SetNextScene(p, 4);
        OEKAKI_SetQuitButtonPressed(p->quitButton, 0);
        BMP_MENUWORK_DrawWindowBorder(p->messageWindow, 2);
        window = p->canvasWindow;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            OEKAKI_OpenGroup(p, 1);
            p->syncMode = 1;
        }
        break;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepSendQuitRequest(OekakiWork *p, int procState)
{
    OekakiSyncMsg msg;

    MI_CpuFill8(&msg, 0, 4);
    msg.kind = OEKAKI_SYNC_CHECK;
    msg.netId = GFL_NET_SYSTEM_GetCurrentAid();
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2905, 4, &msg))
        OEKAKI_SetNextScene(p, 7);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepResetWaitTimer(OekakiWork *p, int procState)
{
    p->localStroke.count = 0;
    p->waitFrames = 0;
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepWaitQuitReply(OekakiWork *p, int procState)
{
    p->localStroke.count = 0;
    (*(s16 *)&p->waitFrames) += 1;
    if ((s16)p->waitFrames > 0x1e) {
        OEKAKI_SetNextScene(p, 0xa);
        p->waitFrames = 0;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepSendQuitConfirm(OekakiWork *p, int procState)
{
    OekakiSyncMsg msg;

    MI_CpuFill8(&msg, 0, 4);
    msg.kind = OEKAKI_SYNC_STATUS;
    msg.netId = GFL_NET_SYSTEM_GetCurrentAid();
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2905, 4, &msg))
        OEKAKI_SetNextScene(p, 12);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepCancelQuit(OekakiWork *p, int procState)
{
    p->localStroke.count = 0;
    p->quitting = 0;
    OEKAKI_SetNextScene(p, 4);
    OEKAKI_SetQuitButtonPressed(p->quitButton, 0);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepShowQuitMessage(OekakiWork *p, int procState)
{
    OEKAKI_PrintMessage(p, 6, 1);
    OEKAKI_SetNextScene(p, 0xd);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepWaitQuitMessage(OekakiWork *p, int procState)
{
    if (OEKAKI_IsMessageDone(p)) {
        p->timer = 0;
        OEKAKI_SetNextScene(p, 0xe);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepWaitThenFadeOut(OekakiWork *p, int procState)
{
    if (++p->timer > 60) {
        WIPE_SYS_Start(0, 8, 8, 0, 0x10, 1, 0x28);
        procState = 3;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepOpenFinishMenu(OekakiWork *p, int procState)
{
    if (OEKAKI_IsMessageDone(p)) {
        if (p->menu == 0)
            p->menu = OEKAKI_OpenYesNoMenu(p);
        OEKAKI_SetNextScene(p, 0x10);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepFinishMenuResult(OekakiWork *p, int procState)
{
    int menuResult;

    menuResult = OEKAKI_PollYesNoMenu(p);
    if (p->baseMemberCount != OEKAKI_GetMemberCount(p) || p->waitMemberBits != 0) {
        OEKAKI_ApplyRemoteStrokes(p);
        return procState;
    }
    switch (menuResult) {
    case 0:
        OEKAKI_SetNextScene(p, 0x11);
        UNION_APP_Close(p->param->app);
        break;
    case 1:
        OEKAKI_SetNextScene(p, 4);
        OEKAKI_SetQuitButtonPressed(p->quitButton, 0);
        BMP_MENUWORK_DrawWindowBorder(p->messageWindow, 2);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            OEKAKI_OpenGroup(p, 1);
            p->syncMode = 1;
        }
        break;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

/*
 * Original narrows the lookup index to u8; its extern expresses the observed call-site width.
 */
void OEKAKI_RegisterPlayerName(OekakiWork *p, int wordIndex, int netId)
{
    UnionAppEntry *entry;

    entry = UNION_APP_GetMemberEntry(p->param->app, (u8)netId);
    if (entry != 0)
        WORDSET_SetSlotMyStatus(p->wordSet, wordIndex, entry);
}

int OEKAKI_StepSendFinishRequest(OekakiWork *p, int procState)
{
    int zero;

    zero = 0;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(0xff), 0x2906, 0, 0)) {
        OEKAKI_SetNextScene(p, 0x12);
        OEKAKI_RegisterPlayerName(p, zero, zero);
        procState = 2;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepShowFinishMessage(OekakiWork *p, int procState)
{
    OEKAKI_RegisterPlayerName(p, 0, 0);
    OEKAKI_PrintMessage(p, 3, 1);
    OEKAKI_SetNextScene(p, 0x13);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

/*
 * extent: two zero padding bytes follow the return at 0x021858B4.
 * Original narrows r3 to u16 before GFL_NET_HANDLE_SetUserInfo, retained in the call prototype.
 */
int OEKAKI_StepWaitFinishMessage(OekakiWork *p, int procState)
{
    if (OEKAKI_IsMessageDone(p)) {
        OEKAKI_SetNextScene(p, 0x14);
        GFL_NET_HANDLE_SetUserInfo(GFL_NET_HANDLE_GetCurrentHandle(), 0xc8, 0x29, (u16)p->baseJoinedBits);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepCheckMembers(OekakiWork *p, int procState)
{
    NetHandle *handle;
    int i;
    int connectedBits;

    handle = GFL_NET_HANDLE_GetCurrentHandle();
    connectedBits = 0;
    for (i = 0; i < 5; i++) {
        if (GFL_NET_IsConnectMember((unsigned char)i) == 1)
            connectedBits |= 1 << i;
    }
    if (GFL_NET_HANDLE_IsTimingSyncRange(handle, 0xc8, 0x29) != 0 || OEKAKI_GetJoinedCount(p) == 1
        || connectedBits != p->baseJoinedBits) {
        WIPE_SYS_Start(0, 8, 8, 0, 0x10, 1, 0x28);
        procState = 3;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepKeepState(int unused, int procState)
{
    return procState;
}

int OEKAKI_StepShowWaitMessage(OekakiWork *p, int procState)
{
    OEKAKI_PrintMessage(p, 5, 1);
    OEKAKI_SetNextScene(p, 0x17);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepWaitMessage(OekakiWork *p, int procState)
{
    if (OEKAKI_IsMessageDone(p))
        OEKAKI_SetNextScene(p, 0xe);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepShowSyncMessage(OekakiWork *p, int procState)
{
    OEKAKI_PrintMessage(p, 2, 1);
    OEKAKI_CloseMenuIfOpen(p);
    OEKAKI_SetNextScene(p, 0x19);
    GFL_USE_PlaySeDefaultVolume(0x54c);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
        OEKAKI_HostOpenGroupLimited(p, 0);
    p->waitMemberCount = OEKAKI_GetJoinedCount(p);
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepWaitSyncAck(OekakiWork *p, int procState)
{
    if (!((p->waitMemberCount == 0 || p->waitMemberCount == OEKAKI_GetJoinedCount(p))
          && (OEKAKI_GetJoinedBits(p) & p->waitMemberBits)))
        p->waitMemberCount = 0;
    if (OEKAKI_IsMessageDone(p)) {
        OEKAKI_SetNextScene(p, 0x1a);
        p->timer = 0;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

int OEKAKI_StepWaitSyncTimer(OekakiWork *p, int procState)
{
    if (!((p->waitMemberCount == 0 || p->waitMemberCount == OEKAKI_GetJoinedCount(p))
          && (OEKAKI_GetJoinedBits(p) & p->waitMemberBits)))
        p->waitMemberCount = 0;
    p->timer += 1;
    if (p->timer > 0x3c && p->waitMemberCount == 0) {
        OEKAKI_ClearMessageWindow(p);
        OEKAKI_SetNextScene(p, 4);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            p->syncMode = 1;
            OEKAKI_HostOpenGroupLimited(p, 1);
        }
        p->baseMemberCount = UNION_APP_GetMemberCount(p->param->app);
        p->baseJoinedBits = UNION_APP_GetJoinedBits(p->param->app);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return procState;
}

void OEKAKI_HandleEvent(OekakiWork *p, int event, int netId)
{
    struct BmpWin *window;

    switch (event) {
    case 1:
        if (p->quitting == 1)
            return;
        if (p->scene == 6 || p->scene == 0x10)
            OEKAKI_CloseMenuIfOpen(p);
        OEKAKI_SetQuitButtonPressed(p->quitButton, 0);
        OEKAKI_RegisterPlayerName(p, 0, netId);
        p->painterNetId = netId;
        p->waitMemberBits = 0;
        break;
    case 3:
        OEKAKI_ClearMessageWindow(p);
        break;
    case 0xb:
    case 0x12:
        break;
    case 0x18:
        if (p->quitting == 1)
            return;
        OEKAKI_RegisterPlayerName(p, 0, netId);
        if (netId == GFL_NET_SYSTEM_GetCurrentAid())
            return;
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
            p->waitMemberBits = p->waitMemberBits & (netId ^ 0xFFFF);
        if (p->scene == 6 || p->scene == 0x10) {
            OEKAKI_CloseMenuIfOpen(p);
            window = p->canvasWindow;
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen(window);
            BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
        }
        OEKAKI_SetQuitButtonPressed(p->quitButton, 0);
        break;
    case 9:
        OEKAKI_QueueCommand(p, 0x2907, GFL_NET_SYSTEM_GetCurrentAid());
        break;
    default:
        return;
    }
    OEKAKI_SetNextScene(p, event);
}

/*
 * Clearing dx/dy before the w/h subtraction is what moves a1 into r0 at
 * entry (t in r1, the bound in r2); clearing it last keeps a1 in r1.
 */
void OEKAKI_BlitBrush(struct BmpWin *canvas, const u8 *brushPixels, int x, int y, int width, int height, int srcX, int srcY,
                   int maxCutX, int maxCutY)
{
    struct Bmp *brushBmp;
    int cut;

    if (srcX < 0) {
        cut = -srcX;
        if (cut > maxCutX)
            cut = maxCutX;
        x += cut;
        srcX = 0;
        width -= cut;
    }
    if (srcY < 0) {
        cut = -srcY;
        if (cut > maxCutY)
            cut = maxCutY;
        y += cut;
        srcY = 0;
        height -= cut;
    }
    brushBmp = BMP_CreateFromBuffer((void *)brushPixels, 8, 8, 0x20, 0x28);
    BMP_Blit(brushBmp, BMP_WIN_GetBmp(canvas), x, y, srcX, srcY, width, height, 0);
    BMP_Delete(brushBmp);
}

/* Draws a line of brush stamps from (*px, *py) to (x1, y1) (Bresenham). */
void OEKAKI_DrawLine(struct BmpWin *canvas, const u8 *brushPixels, int x1, int y1, int *px, int *py, int newStroke, int prevCount)
{
    int startX;
    int startY;
    int endX;
    int deltaX;
    int endY;
    int deltaY;
    int error;
    int step;

    startX = *px;
    startY = *py;
    endX = x1;
    endY = y1;
    if (newStroke == 0 && prevCount == 0) {
        *px = x1;
        *py = y1;
        return;
    }
    deltaX = x1 - startX;
    if (deltaX < 0)
        deltaX = -deltaX;
    deltaY = y1 - startY;
    if (deltaY < 0)
        deltaY = -deltaY;
    if (deltaX > deltaY) {
        if (startX > x1) {
            step = (startY > y1) ? 1 : -1;
            endX = startX;
            startX = x1;
            startY = y1;
        } else {
            step = (startY < y1) ? 1 : -1;
        }
        OEKAKI_BlitBrush(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        error = deltaX >> 1;
        for (startX++; startX <= endX; startX++) {
            error -= deltaY;
            if (error < 0) {
                error += deltaX;
                startY += step;
            }
            OEKAKI_BlitBrush(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        }
    } else {
        if (startY > y1) {
            step = (startX > x1) ? 1 : -1;
            endY = startY;
            startY = y1;
            startX = x1;
        } else {
            step = (startX < x1) ? 1 : -1;
        }
        OEKAKI_BlitBrush(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        error = deltaY >> 1;
        for (startY++; startY <= endY; startY++) {
            error -= deltaX;
            if (error < 0) {
                error += deltaY;
                startX += step;
            }
            OEKAKI_BlitBrush(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        }
    }
    *px = x1;
    *py = y1;
}

/* Remembers the last point and the point count of every member's stroke. */
void OEKAKI_StoreLastPoints(StrokeRec *strokes, LastPoint *last)
{
    int i;

    for (i = 0; i < 5; i++) {
        last[i].count = strokes[i].count;
        if (strokes[i].count != 0) {
            last[i].x = *((unsigned char *)&strokes[i] + strokes[i].count - 1);
            last[i].y = *((unsigned char *)&strokes[i] + strokes[i].count + 1);
        }
    }
}

void OEKAKI_DrawStrokes(struct BmpWin *canvas, StrokeRec *strokes, LastPoint *last, int redraw)
{
    int drew;
    int i;
    int x;
    int y;

    drew = 0;
    for (i = 0; i < 5; i++) {
        if (strokes[i].count == 2) {
            x = strokes[i].startX - 9;
            y = strokes[i].startY - 0x11;
            OEKAKI_DrawLine(canvas, gOekakiBrushPixels + strokes[i].size * 0xc0 + strokes[i].color * 0x18,
                          strokes[i].endX - 9, strokes[i].endY - 0x11, &x, &y, 1, last[i].count);
            drew = 1;
        }
    }
    if (drew && redraw) {
        BMP_WIN_TransferChars(canvas);
        BMP_WIN_MakeScreen(canvas);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(canvas));
    }
    OEKAKI_StoreLastPoints(strokes, last);
    for (i = 0; i < 5; i++)
        strokes[i].count = 0;
}

/*
 * The 6-byte records at +0x4212 are reached through a byte cast of a struct
 * pointer at every use (remoteStrokes below): the base is hoisted into r6 and the
 * element address is recomputed (muls) at each use. A local pointer, or a
 * `char *` parameter with the same cast, CSEs the element pointer instead.
 */
#define REMOTE_STROKES(p) ((StrokeRec *)((char *)(p) + ((sptr)&((OekakiWork *)0)->remoteStroke)))
void OEKAKI_UpdateRemoteCursors(OekakiWork *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (i == GFL_NET_SYSTEM_GetCurrentAid())
            continue;
        if (REMOTE_STROKES(p)[i].count != 0 && UNION_APP_GetMemberEntry(p->param->app, (unsigned char)i) != 0) {
            CLACT_SetActorDrawEnable(p->cursorActor[i], 1);
            OEKAKI_SetCursorPosition(p->cursorActor[i], (&REMOTE_STROKES(p)[i].startX)[REMOTE_STROKES(p)[i].count - 1],
                          (&REMOTE_STROKES(p)[i].startX)[REMOTE_STROKES(p)[i].count + 1]);
        } else {
            CLACT_SetActorDrawEnable(p->cursorActor[i], 0);
        }
    }
}

/* Cycles the colour of palette entry 12 of the object palette (the name tag blink). */
void OEKAKI_AnimatePalette(u16 *angle)
{
    u16 color;

    *angle += 20;
    if (*angle > 360)
        *angle = 0;
    color = (u16)((((GF_STANDARD_SinFromDegreesWrapped(*angle) * 10) / 0x1000) + 15) << 5 | 0x1d);
    GX_LoadOBJPltt(&color, 0x18, 2);
}

/*
 * lever: index declared before count places i in r4 and n in r5.
 */
int OEKAKI_CountMembers(OekakiWork *p)
{
    int i;
    int count;

    count = 0;
    for (i = 0; i < 5; i++) {
        if (UNION_APP_GetMemberEntry(p->param->app, (u8)i) != 0)
            count++;
    }
    return count;
}

void OEKAKI_RefreshNamePlates(struct BmpWin **windows, u16 color, OekakiWork *p)
{
    int selfId;
    int i;
    struct BmpWin *window;
    struct PrintQueue *printer;

    selfId = GFL_NET_SYSTEM_GetCurrentAid();
    if (!OEKAKI_UpdateMemberSlots(p))
        return;
    for (i = 0; i < 5; i++) {
        if (p->memberSlot[i].current == 0)
            CLACT_SetActorDrawEnable(p->nameTagActor[i], 0);
        else
            CLACT_SetActorDrawEnable(p->nameTagActor[i], 1);
    }
    PRINTSYS_QUE_Clear(p->namePrinter);
    for (i = 0; i < 5; i++)
        BMP_FillRect(BMP_WIN_GetBmp(windows[i]), 0, 0, 0x50, 0x10, 0);
    for (i = 0; i < 5; i++) {
        if (p->memberSlot[i].current != 0) {
            MYSTATUS_NameToStrbuf((const u16 *)p->memberSlot[i].current, p->playerName[i]);
            if (selfId == i) {
                printer = p->namePrinter;
                PRINTSYS_PrintQueColor(printer, BMP_WIN_GetBmp(p->printJob[i].window), 0, 0, p->playerName[i], p->font, 0xc80);
                p->printJob[i].busy = 1;
            } else {
                printer = p->namePrinter;
                PRINTSYS_PrintQueColor(printer, BMP_WIN_GetBmp(p->printJob[i].window), 0, 0, p->playerName[i], p->font, color);
                p->printJob[i].busy = 1;
            }
        }
        window = windows[i];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    }
}

#ifdef __MWERKS__
#undef GFL_NET_ResetSendQueue
int GFL_NET_ResetSendQueue(struct GFLNetHandle *handle);
#define OEKAKI_ResetSendQueue(handle) GFL_NET_ResetSendQueue(handle)
#else
#define OEKAKI_ResetSendQueue(handle) GFL_NET_ResetSendQueue()
#endif

void OEKAKI_SendStrokes(OekakiWork *p)
{
    NetHandle *handle;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        handle = GFL_NET_HANDLE_GetCurrentHandle();
        if (OEKAKI_ResetSendQueue(handle) == 0)
            return;
        OEKAKI_FillSendGroup(&p->sendPacket, &p->strokeQueue);
        p->sendPacket.rec[0].syncMode = p->syncMode;
        if (GFL_NET_SendToHandle(handle, 0x2902, 0x1e, &p->sendPacket) == 1)
            OEKAKI_PopStrokeGroup(&p->strokeQueue);
    } else {
        handle = GFL_NET_HANDLE_GetCurrentHandle();
        OEKAKI_PeekStroke(&p->localStroke, &p->strokeQueue);
        if (OEKAKI_ResetSendQueue(handle) == 0)
            return;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2901, 6, &p->localStroke) == 1)
            OEKAKI_PopStrokeGroup(&p->strokeQueue);
    }
}

/*
 * Unblocked by matching the leaf at 0x021841A4 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int OEKAKI_GetMemberCount(OekakiWork *p)
{
    return UNION_APP_GetMemberCount(p->param->app);
}

/* Returns 1 when the member list changed since the last call. */
int OEKAKI_UpdateMemberSlots(OekakiWork *p)
{
    int i;
    int changed;

    changed = 0;
    for (i = 0; i < 5; i++) {
        p->memberSlot[i].previous = p->memberSlot[i].current;
        p->memberSlot[i].current = UNION_APP_GetMemberEntry(p->param->app, (unsigned char)i);
    }
    for (i = 0; i < 5; i++) {
        if (p->memberSlot[i].previous != p->memberSlot[i].current)
            changed = 1;
    }
    return changed;
}

/* Prints message msgId in the message window: mode 0 with the printer, otherwise as a stream. */
void OEKAKI_PrintMessage(OekakiWork *p, u32 msgId, int mode)
{
    StrBuf *text;
    struct PrintQueue *printer;
    struct BmpWin *window;

    text = STRBUF_Create(0x50, 0x28);
    MSGDATA_ReadString(p->msgBank, msgId, text);
    WORDSET_CopyTaggedText(p->wordSet, p->messageText, text);
    STRBUF_Delete(text);
    BMP_Clear(BMP_WIN_GetBmp(p->messageWindow), 15);
    BMP_MENUWORK_DrawWindow(p->messageWindow, 0, 1, 10);
    if (p->messageStream != 0) {
        PRINTSYS_PrintStreamDelete(p->messageStream);
        p->messageStream = 0;
    }
    if (mode == 0) {
        printer = p->messagePrinter;
        PRINTSYS_PrintQueColor(printer, BMP_WIN_GetBmp(p->printJob[6].window), 0, 0, p->messageText, p->font, 0x44F);
        p->printJob[6].busy = 1;
    } else {
        p->messageStream = PRINTSYS_PrintStream(p->messageWindow, 0, 0, p->messageText,
                                         p->font, MSG_SPEED_GetWait(),
                                         (struct Tcbl *)p->taskList, 1, 0x28, 0xF0F);
    }
    window = p->messageWindow;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

/* Returns 1 when the message has been shown completely (or none runs). */
int OEKAKI_IsMessageDone(OekakiWork *p)
{
    int state = PRINTSYS_PrintStreamGetState(p->messageStream);

    if (state == 1) {
        if (KEY_GetTrg() & 1) {
            PRINTSYS_PrintStreamReleasePause(p->messageStream);
        }
        return 0;
    }
    if (state == 2) {
        PRINTSYS_PrintStreamDelete(p->messageStream);
        p->messageStream = 0;
        return 1;
    }
    return p->messageStream == 0;
}

void OEKAKI_ClearMessageWindow(OekakiWork *p)
{
    BMP_MENUWORK_DrawWindowBorder(p->messageWindow, 0);
}

/*
 * extent: two zero padding bytes follow the return at 0x02186320.
 * Caller explicitly sets r1 for OEKAKI_OpenGroup, retained despite its legacy one-argument definition.
 */
void OEKAKI_HostOpenGroupLimited(OekakiWork *p, int flag)
{
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        OEKAKI_GetJoinedCount(p);
        OEKAKI_OpenGroup(p, flag);
    }
}

/* Host only: reacts to members joining or leaving. Returns the next procState (1 keep, 2 leave). */
int OEKAKI_UpdateMembers(OekakiWork *p)
{
    int memberCount;
    int joinedBits;

    memberCount = OEKAKI_GetMemberCount(p);
    switch (memberCount) {
    case 0:
        break;
    case 1:
        if (p->scene > 0x10) {
            break;
        }
        if (OEKAKI_GetJoinedBits(p) != 1) {
            p->memberLeft = 1;
        }
        p->nextScene = 0x16;
        if (p->menuOpen != 0) {
            OEKAKI_CloseMenuIfOpen(p);
            CLACT_SetActorAnimSeq(p->clearButton, 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (memberCount < p->lastMemberCount) {
            if (p->syncMode == 2) {
                OEKAKI_HostOpenGroupLimited(p, 0);
            } else if (p->newMemberPending == 0) {
                OEKAKI_HostOpenGroupLimited(p, 1);
            } else {
                OEKAKI_HostOpenGroupLimited(p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (memberCount < p->lastMemberCount) {
        p->baseMemberCount = OEKAKI_GetJoinedCount(p);
        joinedBits = OEKAKI_GetJoinedBits(p);
        p->baseJoinedBits = joinedBits;
        if (p->newMemberPending != 0 && (joinedBits & p->newMemberBits) == 0) {
            OEKAKI_HostOpenGroupLimited(p, 1);
            p->syncMode = 1;
            p->newMemberPending = 0;
            p->newMemberBits = 0;
        }
    }
    p->lastMemberCount = OEKAKI_GetMemberCount(p);
    if (p->baseMemberCount < OEKAKI_GetJoinedCount(p)) {
        p->syncMode = 2;
        p->newMemberPending = 1;
        p->newMemberBits = OEKAKI_GetJoinedBits(p) ^ p->baseJoinedBits;
    }
    return 1;
}

void OEKAKI_SetNextScene(OekakiWork *p, u32 nextScene)
{
    p->nextScene = nextScene;
}

void OEKAKI_ApplySceneChange(OekakiWork *p, int mode)
{
    int next;

    next = p->nextScene;
    if (p->scene != next) {
        if (mode != 2) {
            p->scene = next;
            return;
        }
        if (d_02186E84[next][0] != 0)
            p->scene = next;
    }
}

/* Closes the yes/no menu if it is open. */
void OEKAKI_CloseMenuIfOpen(OekakiWork *p)
{
    if (p->menuOpen != 0) {
        if (p->menu != 0)
            OEKAKI_CloseYesNoMenu(p);
        p->menuOpen = 0;
    }
}

int OEKAKI_IsQuitTouched(OekakiWork *p)
{
    if (TOUCHPANEL_HitTrg((const void *)gOekakiQuitHitTable) != -1)
        return 1;
    return 0;
}

/* Packs the touch path into a stroke record. */
void OEKAKI_MakeStroke(StrokeRec *stroke, TouchPoint *path, int color, int size)
{
    int i;
    TouchPoint *last;

    if (path[0].count != 0) {
        ((u8 *)stroke)[0] = path[0].x;
        ((u8 *)stroke)[2] = path[0].y;
        last = &path[path[0].count - 1];
        ((u8 *)stroke)[1] = last->x;
        ((u8 *)stroke)[3] = last->y;
        for (i = 0; i < 2; i++) {
            if (((u8 *)stroke)[i] + ((u8 *)stroke)[i + 2] == 0) {
                path[0].count = 0;
            }
        }
    }
    if (path[0].count >= 2) {
        stroke->count = 2;
    } else {
        stroke->count = path[0].count;
    }
    stroke->color = color;
    stroke->size = size;
}

int OEKAKI_GetJoinedCount(OekakiWork *p)
{
    return UNION_APP_GetMemberCount(p->param->app);
}

/*
 * Unblocked by matching the leaf at 0x021841A0 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int OEKAKI_GetJoinedBits(OekakiWork *p)
{
    return UNION_APP_GetJoinedBits(p->param->app);
}

void OEKAKI_EnableDisplays(void)
{
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    *(volatile u16 *)0x04000304 = *(volatile u16 *)0x04000304 & 0xFFFF7FFF;
}

TaskMenu *OEKAKI_OpenYesNoMenu(OekakiWork *p)
{
    int i;
    TaskMenu *menu;
    const MenuItemInit *init;
    TaskMenuInitWork tmpl;

    p->menuRes = APP_TASKMENU_RES_Create(0, 2, p->font, p->messagePrinter, 0x28);
    for (i = 0; i < 2; i++) {
        init = &gOekakiMenuItemInit[i];
        p->menuItem[i].str = MSGDATA_AllocString(p->msgBank, gOekakiMenuItemInit[i].msgId);
        p->menuItem[i].msgColor = 0x39E3;
        p->menuItem[i].type = init->result;
    }
    tmpl.heapId = 0x28;
    tmpl.itemNum = 2;
    tmpl.itemWork = p->menuItem;
    tmpl.posType = 0;
    tmpl.charPosX = 0x15;
    tmpl.charPosY = 7;
    tmpl.width = 10;
    tmpl.height = 3;
    menu = APP_TASKMENU_OpenMenu(&tmpl, p->menuRes);
    p->menuOpen = 1;
    return menu;
}

/*
 * extent: trailing two-byte zero alignment padding at 0x02186692.
 * lever: naming the accessor result before clearing result preserves call/store scheduling.
 */
int OEKAKI_PollYesNoMenu(OekakiWork *p)
{
    int result = 2;

    APP_TASKMENU_UpdateMenu(p->menu);
    if (APP_TASKMENU_IsFinish(p->menu) != 0) {
        u8 choice = APP_TASKMENU_GetCursorPos(p->menu);
        result = 0;
        if (choice != 0) result = 1;
        OEKAKI_CloseYesNoMenu(p);
    }
    return result;
}

/*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 */
void OEKAKI_CloseYesNoMenu(OekakiWork *p)
{
    APP_TASKMENU_CloseMenu(p->menu);
    STRBUF_Delete(p->menuItem[1].str);
    STRBUF_Delete(p->menuItem[0].str);
    APP_TASKMENU_RES_Delete(p->menuRes);
    p->menu = 0;
}

void OEKAKI_RegisterMetPlayers(OekakiWork *p)
{
    int i;
    MetList *list;
    UnionAppEntry *entry;

    list = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(p->param->gameData));
    for (i = 0; i < 5; i++) {
        entry = UNION_APP_GetMemberEntry(p->param->app, (u8)i);
        if (entry != 0) {
            if (i != GFL_NET_SYSTEM_GetCurrentAid()) {
                MET_TRAINERS_Insert(list, MYSTATUS_GetId((const struct MyStatus *)entry));
            }
        }
    }
}

void OEKAKI_UpdatePrintJobs(OekakiWork *p)
{
    int i;
    struct PrintQueue *printer;

    PRINTSYS_QUE_Main(p->namePrinter);
    PRINTSYS_QUE_Main(p->messagePrinter);
    for (i = 0; i < 5; i++) {
        printer = p->namePrinter;
        if (p->printJob[i].busy != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printer, BMP_WIN_GetBmp(p->printJob[i].window)) == 0) {
                BMP_WIN_TransferChars(p->printJob[i].window);
                p->printJob[i].busy = 0;
            }
        }
    }
    printer = p->messagePrinter;
    if (p->printJob[6].busy != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printer, BMP_WIN_GetBmp(p->printJob[6].window)) == 0) {
            BMP_WIN_TransferChars(p->printJob[6].window);
            p->printJob[6].busy = 0;
        }
    }
}

/* Sends the queued net command; the command is dropped once the send succeeded. */
void OEKAKI_SendPendingCommand(OekakiWork *p)
{
    switch (p->pendingCommand) {
    case 0x2903:
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(0xFF), 0x2903, 1, &p->pendingArg) != 0) {
            p->pendingCommand = 0;
        }
        break;
    case 0x2904:
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(0xFF), 0x2904, 0, 0) != 0) {
            p->pendingCommand = 0;
        }
        break;
    case 0x2905:
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(0xFF), 0x2905, 4, &p->stateMsg) != 0) {
            p->pendingCommand = 0;
        }
        break;
    case 0x2906:
        break;
    case 0x2907:
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2907, 0, 0) != 0) {
            p->pendingCommand = 0;
        }
        break;
    }
}

void OEKAKI_QueueCommand(OekakiWork *p, int commandId, int arg)
{
    if (p->pendingCommand == 0) {
        p->pendingCommand = commandId;
        p->pendingArg = arg;
    }
}

int OEKAKI_GetPrevQueueIndex(StrokeQueue *queue)
{
    int index = queue->tail - 1;

    if (index < 0) index = 99;
    return index;
}

void OEKAKI_AdvanceQueueTailIfUsed(StrokeQueue *queue)
{
    if (queue->group[queue->tail].rec[0].count != 0
        || queue->group[OEKAKI_GetPrevQueueIndex(queue)].rec[0].count != 0) {
        queue->tail += 1;
        if (queue->tail >= 100) {
            queue->tail = 0;
        }
    }
}

/*
 * The second loop indexes group[idx].rec[j] in full and lets the
 * compiler hoist the group address itself: a named group pointer puts the 30*idx
 * temporary in r1 instead of r2.
 * Byte 6 of a record (syncMode) exists also to make sizeof(StrokeRec) == 6 so `rec[i]` is `muls #6`.
 */
void OEKAKI_AdvanceQueueTail(StrokeQueue *queue)
{
    int i;
    int emptyCount;
    int prevEmptyCount;
    StrokeRec *rec;

    emptyCount = 0;
    prevEmptyCount = 0;
    i = 0;
    rec = queue->group[queue->tail].rec;
    for (; i < 5; i++) {
        if (rec[i].count == 0) {
            emptyCount++;
        }
    }
    if (emptyCount == 5) {
        int prev = OEKAKI_GetPrevQueueIndex(queue);
        int j;
        for (j = 0; j < 5; j++) {
            if (queue->group[prev].rec[j].count == 0) {
                prevEmptyCount++;
            }
        }
    }
    if (prevEmptyCount != 5) {
        queue->tail += 1;
        if (queue->tail >= 100) {
            queue->tail = 0;
        }
    }
}

/*
 * extent: trailing two-byte zero alignment padding at 0x02186956.
 */
void OEKAKI_ClearStrokeGroup(StrokeRec *rec)
{
    int i;

    for (i = 0; i < 5; i++) rec[i].count = 0;
}

void OEKAKI_PopStrokeGroup(StrokeQueue *queue)
{
    if (queue->head != queue->tail) {
        OEKAKI_ClearStrokeGroup(queue->group[queue->head].rec);
        queue->head += 1;
        if (queue->head >= 100) queue->head = 0;
    }
}

/* stand-in: the record is copied as a StrokeBytes (b[4]); a copy of StrokeRec schedules the last two bytes differently */
void OEKAKI_StoreStroke(StrokeBytes *stroke, StrokeQueue *queue, int index)
{
    ((StrokeBytesGroup *)queue)[queue->tail].r[index] = *stroke;
}

void OEKAKI_PeekStroke(StrokeRec *dst, StrokeQueue *queue)
{
    int index = queue->head;

    if (index != queue->tail) {
        *dst = queue->group[index].rec[0];
    } else {
        dst->count = 0;
    }
}

/*
 * Fills the stroke group sent to the members: the group at the queue head,
 * or, when the queue is empty, a group of five empty records.
 */
void OEKAKI_FillSendGroup(StrokeGroup *sendGroup, StrokeQueue *queue)
{
    int i;
    if (queue->head != queue->tail) {
        for (i = 0; i < OEKAKI_MEMBER_MAX; i++) {
            sendGroup->rec[i] = queue->group[queue->head].rec[i];
        }
    } else {
        for (i = 0; i < OEKAKI_MEMBER_MAX; i++) {
            sendGroup->rec[i].count = 0;
        }
    }
}
