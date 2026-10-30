/*
 * file:     monolith_power.c
 * unit:     yes
 * function: PrintText, MONOLITH_TOOL_LIST_Init, MONOLITH_TOOL_LIST_Main, MONOLITH_TOOL_LIST_Exit, MONOLITH_TOOL_LIST_InitBackgrounds, MONOLITH_TOOL_LIST_FreeBackgrounds, MONOLITH_TOOL_LIST_LoadGraphics, MONOLITH_TOOL_LIST_FreeBgChar, MONOLITH_TOOL_LIST_InitWindows, MONOLITH_TOOL_LIST_FreeWindows, MONOLITH_TOOL_LIST_DrawTitle, MONOLITH_TOOL_LIST_ShowMessage, MONOLITH_TOOL_LIST_ShowFormattedMessage, MONOLITH_TOOL_LIST_IsMessageDone, MONOLITH_TOOL_LIST_HideMessage, MONOLITH_TOOL_LIST_FitBackground, MONOLITH_TOOL_LIST_BuildEntryList, MONOLITH_TOOL_LIST_FreeEntryBitmaps, MONOLITH_TOOL_LIST_DrawEntryNames, MONOLITH_TOOL_CreateRowGrids, MONOLITH_TOOL_DeleteRowGrids, MONOLITH_TOOL_CreateBackButton, MONOLITH_TOOL_LIST_FreeBackButton, MONOLITH_TOOL_LIST_UpdateBackButton, MONOLITH_TOOL_CreateMarker, MONOLITH_TOOL_DeleteMarker, MONOLITH_TOOL_UpdateMarker, MONOLITH_TOOL_CreateScrollArrows, MONOLITH_TOOL_DeleteScrollArrows, MONOLITH_TOOL_UpdateScrollArrows, MONOLITH_TOOL_ProcessListInput, MONOLITH_TOOL_SetCursor, MONOLITH_TOOL_SetRowHighlight, MONOLITH_TOOL_SetRowHighlightSelected, MONOLITH_TOOL_SetRowHighlightNormal, MONOLITH_TOOL_ClearPrevHighlight, MONOLITH_TOOL_ApplyCursorChange, MONOLITH_TOOL_ScrollBy, MONOLITH_TOOL_UpdateBgScroll, MONOLITH_TOOL_UpdateRows, MONOLITH_TOOL_TaskUploadRows, MONOLITH_TOOL_GetRowAtY, MONOLITH_TOOL_InitInfoScreen, MONOLITH_TOOL_MainInfoScreen, MONOLITH_TOOL_ExitInfoScreen, MONOLITH_TOOL_SetupInfoBgs, MONOLITH_TOOL_HideInfoBgs, MONOLITH_TOOL_LoadInfoPalette, MONOLITH_TOOL_CreateInfoWindows, MONOLITH_TOOL_DeleteInfoWindows, MONOLITH_TOOL_DrawInfoHeader, MONOLITH_TOOL_DrawActiveEntry, MONOLITH_TOOL_DrawSelectedEntry
 * address:  0x021B8EE8
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   PROCSYS_Create  0x02031324  arm
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   INTRUDE_COMM_SendBusyBegin  0x0217440C  thumb  ov011
 *   INTRUDE_COMM_SendBusyEnd  0x0217446C  thumb  ov011
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   d_021BA774     0x021BA774  data  a4
 *   PROCSYS_Delete  0x0203133C  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   d_021BA7D4     0x021BA7D4  data  ov071  a4
 *   d_021BA764     0x021BA764  data  a4
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021BA794     0x021BA794  data  a4
 *   d_021BA7B4     0x021BA7B4  data  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   PALANM_LoadHandlePaletteToSlotAt  0x02021660  thumb
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   PALANM_LoadHandlePaletteToSlot  0x020216B4  thumb
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   APP_ICON_LoadTouchBar  0x02027634  thumb
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   ACTOR_TOOL_Create  0x02025318  thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ACTOR_TOOL_Delete 0x02025358 thumb
 *   ACTOR_TOOL_LoadCharPalAnm  0x02025470  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ACTOR_TOOL_LoadCharSimplePalAnm  0x020254BC  thumb
 *   ACTOR_TOOL_FreeChar 0x02025518 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_Create  0x02043678  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   d_021BA80C     0x021BA80C  data  a2
 *   d_021BA814     0x021BA814  data  a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   PALANM_GetColor  0x02021F3C  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   d_021BABE0     0x021BABE0  data  a1
 *   d_021BA82C     0x021BA82C  data  a4
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatusByNetId 0x021583EC thumb ov010
 *   GAME_DATA_GetBattleRecSlotByNetId 0x021583CC thumb ov010
 *   d_021BA844     0x021BA844  data  a2
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   d_021BA854     0x021BA854  data  a4
 *   d_021BA84C     0x021BA84C  data  a4
 *   d_021BA804     0x021BA804  data  a4
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   BG_SYS_DrawTile  0x02041090  arm
 *   d_021BABE4     0x021BABE4  data  a1
 *   d_021BA8A0     0x021BA8A0  data  a4
 *   INTRUDE_COMM_HasUnlockFlags 0x02158590 thumb ov010
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 *   INTRUDE_COMM_AcceptSession 0x02175B4C thumb ov011
 *   INTRUDE_COMM_TakeJoinReply 0x021761EC thumb ov011
 *   INTRUDE_CMD_SendJoinRequest 0x02173E2C thumb ov011
 *   d_021BA87C 0x021BA87C data a4
 *   d_021BA85C 0x021BA85C data a1
 *   d_021BA862 0x021BA862 data a1
 *   d_021BAA4C 0x021BAA4C data a4
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   d_021BA8DC     0x021BA8DC  data  a4
 *   d_021BA8FC     0x021BA8FC  data  a4
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   d_021BABF4     0x021BABF4  data  a1
 *   PRINTSYS_CTRL_Update  0x02028484  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   UI_GetInputMode  0x020355C4  arm
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   d_021BA928 0x021BA928 data a4
 *   d_021BA948     0x021BA948  data  a4
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9F8     0x021BA9F8  data  a4
 *   d_021BA9C8     0x021BA9C8  data  a4
 *   d_021BA9A4     0x021BA9A4  data  a4
 *   d_021BA984 0x021BA984 data a4
 *   d_021BABF8     0x021BABF8  data  a1
 *   d_021BAA64     0x021BAA64  data  a4
 *   d_021BAA84     0x021BAA84  data  a4
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   d_021BAAA4     0x021BAAA4  data  a4
 *   d_021BAAB8     0x021BAAB8  data  ov071  a4
 *   d_021BAAD8     0x021BAAD8  data  ov071  a4
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   _ll_sdiv       0x0209BE5C  arm
 *   TOWN_MAP_SPOT_CountVisited  0x0216FEAC  thumb  ov010
 *   WORDSET_SetSlotFromMsgA0 0x0201F184 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   INTRUDE_GetFromSave 0x0200BE48 thumb
 *   INTRUDE_SetMonolithLevel 0x0200BF08 thumb
 *   GAME_DATA_GetOwnNetId 0x02012B58 thumb
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 *   INTRUDE_COMM_SendPairMessage 0x02174660 thumb ov011
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   KEY_GetCont 0x0203630C arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 *   d_021BAB28     0x021BAB28  data  ov071  a4
 *   d_021BAB48     0x021BAB48  data  ov071  a4
 *   d_021BAB68     0x021BAB68  data  a4
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   TOWN_MAP_SPOT_Classify  0x0216FE2C  thumb  ov010
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   d_021BAAF8     0x021BAAF8  data  a2
 *   gMonolithRowGridParam     0x021BAB10  data  a4
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BMP_OAM_SetPos  0x0202590C  thumb
 *   BMP_CopyPixels  0x02043814  arm
 *   gMonolithInfoBgTemplate0     0x021BAB94  data  a4
 *   gMonolithInfoBgTemplate2     0x021BABB4  data  a4
 *   INTRUDE_GetMonolithLevel  0x0200BF10  thumb
 *   MONOLITH_TOOL_CreateButton  0x021B6A0C  thumb  ov071
 *   MONOLITH_TOOL_FreeButton  0x021B6B38  thumb  ov071
 *   MONOLITH_TOOL_SetButtonVisible  0x021B6B58  thumb  ov071
 *   MONOLITH_TOOL_IsButtonUploaded  0x021B6B70  thumb  ov071
 *   MONOLITH_TOOL_HighlightButtonPulse  0x021B6B98  thumb  ov071
 *   MONOLITH_TOOL_HighlightButtonFlash  0x021B6BEC  thumb  ov071
 *   MONOLITH_TOOL_SetButtonPulse  0x021B6C30  thumb  ov071
 *   MONOLITH_TOOL_SetButtonFlash  0x021B6C48  thumb  ov071
 *   MONOLITH_TOOL_ResetHighlights  0x021B6C54  thumb  ov071
 *   MONOLITH_TOOL_GetHighlightMode  0x021B6C74  thumb  ov071
 *   MONOLITH_TOOL_UpdateHighlight  0x021B6C7C  thumb  ov071
 *   MONOLITH_TOOL_GetSlotIconStates  0x021B6F40  thumb  ov071
 *   MONOLITH_TOOL_CreateBlink  0x021B7070  thumb  ov071
 *   MONOLITH_TOOL_DeleteBlink  0x021B70B8  thumb  ov071
 *   MONOLITH_TOOL_UpdateBlink  0x021B70C4  thumb  ov071
 *   MONOLITH_TOOL_StartBlink  0x021B7108  thumb  ov071
 *   MONOLITH_TOOL_IsBlinkActive  0x021B7114  thumb  ov071
 *   MONOLITH_TOOL_CreateActorAt  0x021B7118  thumb  ov071
 *   MONOLITH_TOOL_DeleteActorAt  0x021B7168  thumb  ov071
 *   MONOLITH_TOOL_Noop  0x021B7170  thumb  ov071
 *   MONOLITH_TOOL_CreateTaskMenuRes  0x021B7174  thumb  ov071
 *   MONOLITH_TOOL_DeleteTaskMenuRes  0x021B718C  thumb  ov071
 *   MONOLITH_TOOL_OpenTaskMenu  0x021B7194  thumb  ov071
 *   MONOLITH_TOOL_CloseTaskMenu  0x021B71FC  thumb  ov071
 *   MONOLITH_TOOL_UpdateTaskMenu  0x021B7204  thumb  ov071
 */

struct Proc;
struct Ctx;
struct PrintSys;
struct Tcbl;
struct Node;
struct PaletteFade;
struct ProcSys;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Bank;
struct Cfg;
struct Bitmap;
struct BmpOamGrid;
struct Sys;
struct Strbuf;
struct Actor;
struct PaletteFade;
struct TaskMenuRes;
struct TaskMenuState;
struct TaskMenu;
struct MonolithToolTaskMenuTmpl;
struct Rec3;
struct BmpWin;
struct Blk;
struct Vec2;
struct Sub0200852CObj;
struct BigObj;
struct Big;
struct Rec1B0;
#include "../arm9/msgdata.h"
#include "../sdk_ioreg.h"
#include "../types.h"
#include "../version.h"

struct PaletteFadeWork;
#include "../arm9/bmp_oam.h"
#include "../arm9/clact.h"
#include "../arm9/printsys.h"
#include "../arm9/bg_sys.h"

#include "monolith_tool_types.h"

typedef struct {
    const struct ProcData *topProc;
    const struct ProcData *subProc;
} MonolithToolPair;

/* CLACT system init config, same layout as arm9 struct SysInit. */
struct SysInit {
    short surface_pos[4];
    u8 oam_main_base;
    u8 oam_main_count;
    u8 oam_sub_base;
    u8 oam_sub_count;
    u32 n_transfers;
    u16 n_chars;
    u16 n_pltts;
    u16 n_cells;
    u16 n_spare;
    u16 n_main_blocks;
    u16 n_sub_blocks;
};

typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } MonolithToolSlot;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

typedef enum { B_FALSE, B_TRUE } MonolithBool;

struct MonolithToolPair {
    int x, y;
};

struct MonolithToolActorPos {
    s16 x;
    s16 y;
    u16 animSeq;
    u8 reserved6;
    u8 reserved7;
};

struct MonolithToolGridParam {
    void *bitmap;
    s16 x;
    s16 y;
    u32 palette;
    u32 reservedC;
    u8 reserved10;
    u8 reserved11;
    u16 subScreenA;
    u32 subScreenB;
};

typedef struct {
    u16 v;
    u8 state;
    u8 dir;
    u8 timer;
    u8 cnt;
    u8 pad[2];
} Ent;

struct MonolithToolIconPos {
    u16 x, y, animSeq, reserved6;
};

typedef enum { V4 = 4, V5 = 5 } Value;

struct MonolithToolCursorPos {
    u16 x, y, animSeq, reserved6;
};

typedef struct { void *text; u16 color; int flags; } MonolithToolItem;

/* Task menu template, same layout and field names as ov070 struct MonolithToolTaskMenuTmpl. */
struct MonolithToolTaskMenuTmpl {
    int heapId;
    u8 itemNum;
    u8 pad[3];
    void *items;
    int posType;
    u8 charPosX;
    u8 charPosY;
    u8 width;
    u8 height;
};

/* Hit area of one menu entry, passed to TOUCHPANEL_HitTrg. */
typedef struct {
    u8 hitBox[0x14];
} MonolithToolHitBox;

typedef enum { FALSE, TRUE } BoolFlag;

#include "../arm9/gx.h"
#include "../arm9/g2.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/arc_tool.h"
struct GPowerData;
#include "../arm9/gpower.h"
struct PrintStreamCtrl;
#include "../arm9/app_keycursor.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
#include "../arm9/net.h"
struct GameSystem;
struct GameComm;
#include "../arm9/gamesystem.h"
struct IntrudeCommSys;
#include "../ov010/intrude_comm_query.h"
#include "../arm9/wipe.h"
#include "../arm9/net_err.h"
#include "../ov011/intrude_comm.h"
#include "../arm9/game_comm.h"
#include "../arm9/gf_font.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct PrintQueue;
extern void PROCSYS_Delete(struct ProcSys *p);
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/palanm.h"
#include "../arm9/arc_util.h"
struct ArcHandle;
#include "../arm9/app_icon.h"
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
#include "../arm9/wordset.h"
struct BmpOamSys;
struct ActorTool;
#include "../arm9/actor_tool.h"
extern void PALANM_TransferPalettes(struct PaletteFade *);
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/strbuf.h"
struct BmpOam;
#include "../arm9/gf_panic.h"
extern u16 PALANM_GetColor(struct PaletteFadeWork *base, int idx, int which, u16 pos);
struct GameData;
struct MyStatus;
struct BattleRecSlot;
struct GFont;
#include "../arm9/app_taskmenu.h"
struct TaskMenuInitWork;
struct TaskMenuWork;
#include "../arm9/bmp_win.h"
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u16 fileId, u32 heapId);
struct DispVramCfg;
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
#include "../arm9/ui.h"
struct IntrudeSession;
struct TextPrinter;
#include "../arm9/bmp_menuwork.h"
extern signed char MSG_SPEED_GetWait(void);
#include "../arm9/mystatus.h"
#include "../arm9/game_data.h"
struct EventWork;
#include "../arm9/zonedata.h"
struct IntrudeMemberRecord;
struct IntrudeMemberName;
struct IntrudeRequestHead;
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, struct Strbuf *dest);
#include "../ov010/town_map_spot.h"
struct SaveControl;
struct IntrudeSave;
#include "../arm9/intrude.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021BAAA0[];
extern const char str_ja_021BAAB0[];
extern const char str_ja_021BAAC8[];
extern const char str_ja_021BAAE4[];
extern const char str_ja_021BAB00[];
extern const char str_ja_021BAB1C[];
extern const char str_ja_021BAB30[];
extern const char str_ja_021BAB4C[];
extern const char str_ja_021BAB68[];
extern const char str_ja_021BAB7C[];
extern const char str_ja_021BAB98[];
extern const char str_ja_021BABB4[];
#endif
extern const struct MonolithToolGridParam gMonolithRowGridParam;
extern const struct BgTemplate gMonolithInfoBgTemplate0;
extern const struct BgTemplate gMonolithInfoBgTemplate2;
int MONOLITH_TOOL_Init(struct Proc *ctx, int unused, MonolithToolSetup *setup);
int MONOLITH_TOOL_Main(int a, int *seq, void **pwk, MonolithToolWork *work);
int MONOLITH_TOOL_Exit(struct Proc *a, int b, int c, MonolithToolWork *work);
void MONOLITH_TOOL_InitDisplay(void);
void MONOLITH_TOOL_DeleteBg(void);
void MONOLITH_TOOL_InitBmpWin(void);
void MONOLITH_TOOL_ExitBmpWin(void);
unsigned int MONOLITH_TOOL_InitPalAnm(MonolithToolWork *work);
void MONOLITH_TOOL_FreePalAnm(MonolithToolWork *work);
void MONOLITH_TOOL_InitBackgrounds(void);
void MONOLITH_TOOL_FreeBackgrounds(void);
void MONOLITH_TOOL_LoadGraphics(MonolithToolWork *work, MonolithToolWork *work2);
void MONOLITH_TOOL_FreeSubBgChar(MonolithToolWork *work);
void MONOLITH_TOOL_InitText(MonolithToolWork *work);
void MONOLITH_TOOL_FreeText(MonolithToolWork *work);
void MONOLITH_TOOL_InitActors(MonolithToolWork *work);
void MONOLITH_TOOL_FreeActors(MonolithToolWork *work);
void MONOLITH_TOOL_LoadActorResources(MonolithToolWork *work);
void MONOLITH_TOOL_FreeActorResources(MonolithToolWork *work);
void MONOLITH_TOOL_VBlankTask(struct TcbTask *unused, void *workArg);
void MONOLITH_TOOL_LoadSlotRecords(MonolithToolWork *work, MonolithToolSetup *setup);
void MONOLITH_TOOL_CreateButton(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet);
void MONOLITH_TOOL_FreeButton(MonolithToolButton *button);
void MONOLITH_TOOL_SetButtonVisible(MonolithToolButton *button, int visible);
int MONOLITH_TOOL_IsButtonUploaded(MonolithToolWork *work, MonolithToolButton *button);
void MONOLITH_TOOL_HighlightButtonPulse(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void MONOLITH_TOOL_HighlightButtonFlash(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void MONOLITH_TOOL_SetButtonPulse(MonolithToolProcArgs *args, int pulse, int slot);
void MONOLITH_TOOL_SetButtonFlash(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_ResetHighlights(MonolithToolProcArgs *args);
u8 MONOLITH_TOOL_GetHighlightMode(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_UpdateHighlight(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_SetHighlightMode(MonolithToolProcArgs *args, int mode, int slot);
int MONOLITH_TOOL_GetHighlightColorA(unsigned int x);
int MONOLITH_TOOL_GetHighlightColorB(unsigned int x);
int MONOLITH_TOOL_GetHighlightColorCount(int slot);
void MONOLITH_TOOL_CreateLabel(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet);
void MONOLITH_TOOL_FreeLabel(MonolithToolLabel *label);
int MONOLITH_TOOL_UpdateLabel(MonolithToolWork *work, MonolithToolLabel *label);
void *MONOLITH_TOOL_GetTitleSpecies(MonolithToolProcArgs *args);
MonolithCounts *MONOLITH_TOOL_GetSlotIconStates(MonolithToolProcArgs *args);
int MONOLITH_TOOL_CreateSlotIcon(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex);
void MONOLITH_TOOL_DeleteSlotIcon(void *p);
void MONOLITH_TOOL_UpdateSlotIconState(void *p, MonolithCounts *counts, int i);
struct ClactActor *MONOLITH_TOOL_CreateCursor(MonolithToolWork *work, const int *pos, int resIndex);
void MONOLITH_TOOL_DeleteCursor(void *p);
void MONOLITH_TOOL_CreateBlink(MonolithToolWork *work, MonolithToolBlink *blink);
void MONOLITH_TOOL_DeleteBlink(MonolithToolBlink *blink);
void MONOLITH_TOOL_UpdateBlink(MonolithToolBlink *p);
void MONOLITH_TOOL_StartBlink(MonolithToolBlink *blink);
int MONOLITH_TOOL_IsBlinkActive(MonolithToolBlink *blink);
struct Actor *MONOLITH_TOOL_CreateActorAt(MonolithToolWork *work, int x, int y, int animSeq);
void MONOLITH_TOOL_DeleteActorAt(void *p);
void MONOLITH_TOOL_Noop(void *a);
struct TaskMenuRes *MONOLITH_TOOL_CreateTaskMenuRes(MonolithToolWork *p, int a, u16 heap);
void MONOLITH_TOOL_DeleteTaskMenuRes(void *p);
void *MONOLITH_TOOL_OpenTaskMenu(MonolithToolWork *p, void *res, u32 heap);
void MONOLITH_TOOL_CloseTaskMenu(void *p);
int MONOLITH_TOOL_UpdateTaskMenu(MonolithToolWork *work, int unused, void *p, int *q);
void MONOLITH_TOOL_DrawSlotCounts(void *a, int flag, int bg);
int MONOLITH_TOOL_SLOT_SELECT_Init(void *ctx, int *state, MonolithToolProcArgs *args);
int MONOLITH_TOOL_SLOT_SELECT_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
int MONOLITH_TOOL_SLOT_SELECT_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds(void);
void MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds(void);
void MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(MonolithToolProcArgs *args, MonolithToolWork *work);
void MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(MonolithToolSlotSelect *screen, MonolithToolWork *work);
void MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_ShowMessage(MonolithToolSlotSelect *screen, MonolithToolWork *work, int msgId);
int MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(MonolithToolWork *work, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_HideMessage(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args);
void MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args);
void MONOLITH_TOOL_SLOT_SELECT_MoveCursor(MonolithToolSlotSelect *screen,int slot);
void MONOLITH_TOOL_SLOT_SELECT_CreateButtons(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_FreeButtons(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(MonolithToolProcArgs *args,MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_CreateCursor(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_FreeCursor(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_SetMode(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen, unsigned char mode);
int MONOLITH_TOOL_TITLE_Init(void *ctx, int *state, MonolithToolProcArgs *args);
int MONOLITH_TOOL_TITLE_Main(int unused,int *state,MonolithToolProcArgs *args,MonolithToolTitle *screen);
int MONOLITH_TOOL_TITLE_Exit(void *proc,int unused,MonolithToolProcArgs *args,MonolithToolTitle *screen);
void MONOLITH_TOOL_TITLE_InitBackgrounds(void);
void MONOLITH_TOOL_TITLE_FreeBackgrounds(void);
void MONOLITH_TOOL_TITLE_LoadGraphics(MonolithToolProcArgs *args,MonolithToolWork *work);
void MONOLITH_TOOL_TITLE_CreateSlotIcons(MonolithToolTitle *screen, MonolithToolProcArgs *args);
void MONOLITH_TOOL_TITLE_FreeSlotIcons(MonolithToolTitle *screen);
void MONOLITH_TOOL_TITLE_UpdateSlotIcons(MonolithToolTitle *screen,MonolithToolProcArgs *args);
int MONOLITH_TOOL_MENU_Create(struct Proc *ctx, int unused, MonolithToolProcArgs *args);
int MONOLITH_TOOL_MENU_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolMenu *screen);
int MONOLITH_TOOL_MENU_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_CreateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_FreeButtons(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_UpdateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_CreateCursor(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_FreeCursor(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_UpdateCursor(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_InitBackgrounds(void);
void MONOLITH_TOOL_MENU_FreeBackgrounds(void);
void MONOLITH_TOOL_MENU_CreateWindow(MonolithToolMenu *screen, MonolithToolWork *work);
void MONOLITH_TOOL_MENU_FreeWindow(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_ShowMessage(MonolithToolMenu *screen, MonolithToolWork *work, unsigned msgId);
int MONOLITH_TOOL_MENU_IsMessageDone(MonolithToolWork *work, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_HideMessage(MonolithToolMenu *screen);
int MONOLITH_TOOL_SUMMARY_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen);
int MONOLITH_TOOL_SUMMARY_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen);
int MONOLITH_TOOL_SUMMARY_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_InitBackgrounds(void);
void MONOLITH_TOOL_SUMMARY_FreeBackgrounds(void);
void MONOLITH_TOOL_SUMMARY_LoadGraphics(MonolithToolWork *work);
void MONOLITH_TOOL_SUMMARY_CreateWindows(int unused, MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_DeleteWindows(MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_CreateLabel(MonolithToolWork *work, MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_FreeLabel(MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolSummary *screen, u8 *saveData, unsigned slot);
int MONOLITH_TOOL_STATS_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen);
int MONOLITH_TOOL_STATS_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen);
int MONOLITH_TOOL_STATS_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_InitBackgrounds(void);
void MONOLITH_TOOL_STATS_FreeBackgrounds(void);
void MONOLITH_TOOL_STATS_LoadGraphics(MonolithToolWork *work);
void MONOLITH_TOOL_STATS_CreateWindows(int unused, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_DeleteWindows(MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_CreateCursor(MonolithToolProcArgs *args, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_FreeCursor(MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_UpdateCursor(MonolithToolStats *screen);
int MONOLITH_TOOL_LIST_Init(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_LIST_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_LIST_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_InitBackgrounds(void);
void MONOLITH_TOOL_LIST_FreeBackgrounds(void);
void MONOLITH_TOOL_LIST_LoadGraphics(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeBgChar(MonolithListWork *work);
void MONOLITH_TOOL_LIST_InitWindows(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeWindows(MonolithListWork *work);
void MONOLITH_TOOL_LIST_DrawTitle(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_ShowMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
void MONOLITH_TOOL_LIST_ShowFormattedMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
int MONOLITH_TOOL_LIST_IsMessageDone(MonolithToolWork *toolWork, MonolithListWork *work);
void MONOLITH_TOOL_LIST_HideMessage(MonolithListWork *work);
void MONOLITH_TOOL_LIST_FitBackground(MonolithListWork *work);
void MONOLITH_TOOL_LIST_BuildEntryList(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeEntryBitmaps(MonolithListWork *work);
int MONOLITH_TOOL_LIST_DrawEntryNames(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_CreateRowGrids(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_DeleteRowGrids(MonolithListWork *work);
void MONOLITH_TOOL_CreateBackButton(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_FreeBackButton(MonolithListWork *work);
void MONOLITH_TOOL_LIST_UpdateBackButton(MonolithToolWork *toolWork, MonolithListWork *work);
void MONOLITH_TOOL_CreateMarker(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_DeleteMarker(MonolithListWork *work);
void MONOLITH_TOOL_UpdateMarker(MonolithListWork *work);
void MONOLITH_TOOL_CreateScrollArrows(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_DeleteScrollArrows(MonolithListWork *work);
void MONOLITH_TOOL_UpdateScrollArrows(MonolithListWork *work);
int MONOLITH_TOOL_ProcessListInput(MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_SetCursor(MonolithListWork *work, int index, int inputMode);
void MONOLITH_TOOL_SetRowHighlight(MonolithListWork *work, int index, int palette);
void MONOLITH_TOOL_SetRowHighlightSelected(MonolithListWork *work, int index);
void MONOLITH_TOOL_SetRowHighlightNormal(MonolithListWork *work, int index);
void MONOLITH_TOOL_ClearPrevHighlight(MonolithListWork *work);
void MONOLITH_TOOL_ApplyCursorChange(MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_ScrollBy(MonolithListWork *work, int delta);
void MONOLITH_TOOL_UpdateBgScroll(MonolithListWork *work);
void MONOLITH_TOOL_UpdateRows(MonolithListWork *work);
void MONOLITH_TOOL_TaskUploadRows(struct TcbTask *task, void *workArg);
int MONOLITH_TOOL_GetRowAtY(MonolithListWork *work, unsigned y);
int MONOLITH_TOOL_InitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int MONOLITH_TOOL_MainInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int MONOLITH_TOOL_ExitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
void MONOLITH_TOOL_SetupInfoBgs(void);
void MONOLITH_TOOL_HideInfoBgs(void);
void MONOLITH_TOOL_LoadInfoPalette(MonolithToolWork *toolWork);
void MONOLITH_TOOL_CreateInfoWindows(MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DeleteInfoWindows(MonolithInfoWork *work);
void MONOLITH_TOOL_DrawInfoHeader(MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DrawActiveEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DrawSelectedEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
extern MonolithToolPair d_021BA774[];
extern char d_021BA7D4;
extern char d_021BA764;
extern char d_021BA794;
extern char d_021BA7B4;
extern struct SysInit gClActorInitParam;
extern const struct MonolithToolActorPos d_021BA80C;
extern const struct MonolithToolGridParam d_021BA814;
extern char d_021BABE0[];
extern const struct MonolithToolGridParam d_021BA82C;
extern struct MonolithToolIconPos d_021BA844;
extern const struct MonolithToolCursorPos d_021BA854;
extern const struct MonolithToolCursorPos d_021BA84C;
extern const struct MonolithToolCursorPos d_021BA804;
extern const char d_021BABE4[];
extern const struct MonolithToolPair d_021BA8A0[];
extern const u32 d_021BA87C[];
extern const u8 d_021BA85C[],d_021BA862[][4];
extern const u32 d_021BAA4C[];
extern char d_021BA8DC[];
extern char d_021BA8FC[];
extern char d_021BABF4[];
extern const char d_021BA928[];
extern const char d_021BA948[];
extern unsigned d_021BA978[];
extern MonolithToolHitBox d_021BA9F8[];
extern int d_021BA9C8[][4];
extern int d_021BA9A4[][3];
extern const char d_021BA984[];
extern char d_021BABF8[];
extern char d_021BAA64[];
extern char d_021BAA84[];
extern char d_021BAAA4[];
extern char d_021BAAB8[];
extern char d_021BAAD8[];
extern const u32 d_021BAAFC[];
extern char d_021BABFC[];
extern char d_021BAB28[];
extern char d_021BAB48[];
extern struct Config d_021BAB68;
extern u16 d_021BAAF8[];


#pragma opt_lifetimes off

#pragma opt_common_subs off


#pragma opt_lifetimes reset

#pragma opt_common_subs reset


int MONOLITH_TOOL_LIST_Init(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work)
{
    int busy;
    struct PrintSys *printSys;
    MonolithBool finished;

    switch (*state) {
    case 0:
        work = PROCSYS_AllocProcWork(proc, sizeof(MonolithListWork), 0x61);
        MI_CpuFill8(work, 0, sizeof(MonolithListWork));
        work->scrollPos = 0x800;
        work->chosenEntry = MONOLITH_CURSOR_NONE;
        work->prevCursor = MONOLITH_CURSOR_NONE;
        work->lastCursor = MONOLITH_CURSOR_NONE;
        MONOLITH_TOOL_ResetHighlights(args);
        work->entryNameBank = MSGDATA_CreateFromArchive(0, 2, 0xa0, 0x61);
        MONOLITH_TOOL_LIST_InitBackgrounds();
        MONOLITH_TOOL_LIST_LoadGraphics(work, args->work);
        MONOLITH_TOOL_LIST_InitWindows(work, args->work);
        MONOLITH_TOOL_UpdateBgScroll(work);
        MONOLITH_TOOL_CreateMarker(args, work);
        MONOLITH_TOOL_CreateRowGrids(work, args->work);
        MONOLITH_TOOL_CreateBackButton(args, work);
        MONOLITH_TOOL_CreateScrollArrows(args, work);
        MONOLITH_TOOL_LIST_DrawTitle(args, work);
        work->taskMenuUnit = MONOLITH_TOOL_CreateTaskMenuRes(args->work, 4, 0x61);
        args->param->selected = MONOLITH_ENTRY_NONE;
        work->task = GFL_USE_AddMainTask(MONOLITH_TOOL_TaskUploadRows, (void *)work, (unsigned int)3);
        MONOLITH_TOOL_LIST_BuildEntryList(args, work, args->work);
        MONOLITH_TOOL_LIST_FitBackground(work);
        *state = *state + 1;
        break;
    case 1:
        if (MONOLITH_TOOL_LIST_DrawEntryNames(work, args->work) == 1) {
            MONOLITH_TOOL_UpdateRows(work);
            work->uploadPending = 1;
            if (UI_GetInputMode() == 0) {
                MONOLITH_TOOL_SetCursor(work, 1, 0);
            } else {
                MONOLITH_TOOL_SetCursor(work, MONOLITH_CURSOR_NONE, 0);
            }
            *state = *state + 1;
        }
        break;
    case 2:
        busy = 0;
        printSys = args->work->printSys;
        if (work->statusPending != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->statusWindow)) == 0) {
                BMP_WIN_TransferChars(work->statusWindow);
                work->statusPending = 0;
            }
        }
        finished = work->statusPending == 0 ? B_TRUE : B_FALSE;
        if (finished == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(4, 1);
            BG_SYS_SetPlaneVisible(5, 1);
            BG_SYS_SetPlaneVisible(6, 1);
            BG_SYS_SetSubPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * extent: final halfword at 021B94CA is alignment padding.
 * lever: state9 writes its state10 tail twice, one reached by goto, preserving the cross-jump.
 */
int MONOLITH_TOOL_LIST_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work)
{
    u32 initial, mask; uptr save;
    int active, result;
    struct PrintSys *printSys;

    initial = (uptr)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((struct GameSystem *)args->setup->gameCtx));
    MONOLITH_TOOL_UpdateHighlight(args, 1);
    MONOLITH_TOOL_UpdateHighlight(args, 3);
    MONOLITH_TOOL_UpdateMarker(work);
    MONOLITH_TOOL_LIST_UpdateBackButton(args->work, work);
    printSys = args->work->printSys;
    if (work->statusPending != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->statusWindow)) == 0) {
        BMP_WIN_TransferChars(work->statusWindow);
        work->statusPending = 0;
    }
    if (args->abortRequested == 1 && *state == 4) return 1;
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        MONOLITH_TOOL_LIST_ShowMessage(work, args->work, 0x25);
        ++*state;
        break;
    case 2:
        if (MONOLITH_TOOL_LIST_IsMessageDone(args->work, work) == 1 && (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 3))) {
            MONOLITH_TOOL_LIST_HideMessage(work);
            GFL_USE_PlaySeDefaultVolume(0x547);
            if (TOUCHPANEL_GetTrg() == 0) MONOLITH_TOOL_SetCursor(work, 1, 0);
            else MONOLITH_TOOL_SetCursor(work, MONOLITH_CURSOR_NONE, 0);
            ++*state;
        }
        break;
    case 3:
        if (TOUCHPANEL_GetCont() == 0 && !(KEY_GetCont() & 3)) *state = 4;
        break;
    case 4:
        mask = KEY_GetTrg();
        active = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021BAAFC);
        if (active == 0 || (mask & 2)) {
            MONOLITH_TOOL_StartBlink(&work->marker);
            if (active == 0) UI_SetInputMode(TRUE);
            else UI_SetInputMode(FALSE);
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = 17;
            break;
        }
        MONOLITH_TOOL_ProcessListInput(args, work);
        MONOLITH_TOOL_ClearPrevHighlight(work);
        if (MONOLITH_TOOL_ScrollBy(work, work->scrollVelocity + work->scrollRequest) == 1) {
            MONOLITH_TOOL_UpdateBgScroll(work);
            MONOLITH_TOOL_UpdateRows(work);
            work->uploadPending = 1;
        }
        MONOLITH_TOOL_ApplyCursorChange(args, work);
        if (work->cursor == MONOLITH_CURSOR_NONE) {
            args->param->selected = MONOLITH_ENTRY_NONE;
        } else {
            args->param->selected = work->entryIds[work->cursor];
            args->param->mode = work->entryDisabled[work->cursor];
            if (work->entryDisabled[work->cursor] == 0) {
                MONOLITH_TOOL_SetButtonVisible(&work->backButton, 1);
                goto selected;
            }
        }
        MONOLITH_TOOL_SetButtonVisible(&work->backButton, 0);
selected:
        if (work->chosenEntry != MONOLITH_CURSOR_NONE) {
            GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_CONFIRM);
            *state = 5;
        }
        break;
    case 5:
        if (MONOLITH_TOOL_GetHighlightMode(args, 1) != 2 && MONOLITH_TOOL_GetHighlightMode(args, 3) != 2) {
            MONOLITH_TOOL_LIST_ShowMessage(work, args->work, 0x20);
            ++*state;
        }
        break;
    case 6:
        if (MONOLITH_TOOL_LIST_IsMessageDone(args->work, work) == 1) {
            if (work->yesNoMenu != 0) GF_PANIC_Fail(PM_LANG_JA((const char *)d_021BABFC, str_ja_021BAB68), PM_SRC_LINE(0, 0x1F7), PM_LANG_JA((const char *)d_021BABFC, str_ja_021BAB7C));
            work->yesNoMenu = MONOLITH_TOOL_OpenTaskMenu(args->work, work->taskMenuUnit, 0x61);
            ++*state;
        }
        break;
    case 7:
        if (MONOLITH_TOOL_UpdateTaskMenu(args->work, 4, work->yesNoMenu, &result) == 1) {
            MONOLITH_TOOL_CloseTaskMenu(work->yesNoMenu);
            work->yesNoMenu = 0;
            MONOLITH_TOOL_LIST_HideMessage(work);
            if (result == 1) *state = 8;
            else {
                work->chosenEntry = MONOLITH_CURSOR_NONE;
                MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
                MONOLITH_TOOL_HighlightButtonPulse(args, &work->backButton, 1, 0xff, 3);
                *state = 4;
            }
        }
        break;
    case 8:
        if (MONOLITH_TOOL_GetHighlightMode(args, 1) != 2 && MONOLITH_TOOL_GetHighlightMode(args, 3) != 2) {
            WORDSET_SetSlotFromMsgA0(args->work->wordSet, 0, work->entryIds[work->chosenEntry]);
            MONOLITH_TOOL_LIST_ShowFormattedMessage(work, args->work, 0x23);
            *state = 9;
        }
        break;
    case 9:
        if (initial == 0) goto write10;
        if (INTRUDE_COMM_SendPairMessage(args->setup->areaId) == 1) {
            *state = 10;
            break;
        }
        break;
write10:
        *state = 10;
        break;
    case 10:
        if (MONOLITH_TOOL_LIST_IsMessageDone(args->work, work) == 1) {
            GFL_USE_FadeOutBgm(6);
            ++*state;
        }
        break;
    case 11:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPaused((unsigned int)1);
            GFL_USE_PushBgm();
            ++*state;
        }
        break;
    case 12:
        GFL_USE_CancelChangeAndPlayBgm(0x531, 0xffff);
        ++*state;
        break;
    case 13:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPaused(0);
            GFL_USE_FadeInBgmFull(6);
            ++*state;
        }
        break;
    case 14:
        if (GFL_USE_IsBgmFading() == 0) *state = 15;
        break;
    case 15:
        if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 3)) {
            MONOLITH_TOOL_LIST_HideMessage(work);
            INTRUDE_SetMonolithLevel((struct IntrudeSave *)INTRUDE_GetFromSave(GAME_DATA_GetSaveControl((struct GameData *)GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx))), work->entryIds[work->chosenEntry]);
            save = (uptr)GAMESYSTEM_GetGameComm((const struct GameSystem *)args->setup->gameCtx);
            GAME_COMM_PushPairMessage((GameComm *)save, GAME_DATA_GetOwnNetId(GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx)), args->setup->areaId);
            work->chosenEntry = MONOLITH_CURSOR_NONE;
            MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
            MONOLITH_TOOL_HighlightButtonPulse(args, &work->backButton, 1, 0xff, 3);
            if (TOUCHPANEL_GetTrg() != 0) *state = 16;
            else *state = 17;
        }
        break;
    case 16:
        if (TOUCHPANEL_GetCont() == 0) *state = 17;
        break;
    case 17:
        if (MONOLITH_TOOL_GetHighlightMode(args, 1) != 2 && MONOLITH_TOOL_GetHighlightMode(args, 3) != 2 && MONOLITH_TOOL_IsBlinkActive(&work->marker) == 0) {
            args->requestedScreen = 0;
            return 1;
        }
        break;
    }
    MONOLITH_TOOL_UpdateScrollArrows(work);
    return 0;
}

int MONOLITH_TOOL_LIST_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys) == 0)
        return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    TCB_DeleteTask(work->task);
    if (work->messagePrinter != 0)
        PRINTSYS_PrintStreamDelete(work->messagePrinter);
    if (work->messageText != 0)
        STRBUF_Delete(work->messageText);
    MONOLITH_TOOL_LIST_FreeEntryBitmaps(work);
    if (work->yesNoMenu != 0)
        MONOLITH_TOOL_CloseTaskMenu(work->yesNoMenu);
    MONOLITH_TOOL_DeleteTaskMenuRes(work->taskMenuUnit);
    MONOLITH_TOOL_LIST_FreeBackButton(work);
    MONOLITH_TOOL_DeleteRowGrids(work);
    MONOLITH_TOOL_DeleteMarker(work);
    MONOLITH_TOOL_DeleteScrollArrows(work);
    MONOLITH_TOOL_LIST_FreeBgChar(work);
    MONOLITH_TOOL_LIST_FreeWindows(work);
    MONOLITH_TOOL_LIST_FreeBackgrounds();
    MSGDATA_Delete(work->entryNameBank);
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_LIST_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021BAB28, 0);
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BAB48, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)((char *)&d_021BAB68), 0);
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
}

void MONOLITH_TOOL_LIST_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(4,0); BG_SYS_SetPlaneVisible(5,0); BG_SYS_SetPlaneVisible(6,0); BG_SYS_FreeLayerBuf(4); BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(6); }

void MONOLITH_TOOL_LIST_LoadGraphics(MonolithListWork *work, MonolithToolWork *toolWork)
{
    void *res;

    ARC_UTIL_UploadBgPaletteFromHandle(toolWork->archive, 7, 6, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgCharFromHandle(toolWork->archive, 0xe, 5, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgPaletteFromHandle(toolWork->archive, 9, 5, 0, 0, 1, 0x61);
    res = ARC_TOOL_CreateHandle(0x53, 0x61);
    work->bgCharOffset = BG_SYS_CreateRun(5, 0x80, 1);
    ARC_UTIL_UploadBgCharFromHandle(res, 0x1c, 5, work->bgCharOffset, 0x80, 0, 0x61);
    APP_ICON_LoadTouchBar(res, 5, 0x61, work->bgCharOffset, 0xc);
    ARC_TOOL_DeleteHandle(res);
    BG_SYS_PushTile(5);
    BG_SYS_PushTile(6);
}

void MONOLITH_TOOL_LIST_FreeBgChar(MonolithListWork *work) { BG_SYS_FreeTileRun(5, work->bgCharOffset, 0x80); }

void MONOLITH_TOOL_LIST_InitWindows(MonolithListWork *work, MonolithToolWork *toolWork)
{
    BMP_MENUWORK_LoadChar(4, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(toolWork->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    work->messageWindow = BMP_WIN_Create(4, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->messageWindow), 0xff);
    work->titleWindow = BMP_WIN_Create(4, 0, 0, 0x20, 3, 0xd, 1);
    BMP_WIN_MakeScreen(work->titleWindow);
    BG_SYS_PushTile(4);
    work->statusWindow = work->titleWindow;
    work->statusPending = 0;
}

void MONOLITH_TOOL_LIST_FreeWindows(MonolithListWork *work) { int i; for (i=0;i<2;i++) BMP_WIN_Delete((&work->messageWindow)[i]); }

void MONOLITH_TOOL_LIST_DrawTitle(MonolithToolProcArgs *args, MonolithListWork *work)
{
    struct Strbuf *text;
    MonolithToolWork *toolWork;
    struct PrintSys *printSys;

    text = MSGDATA_AllocString(args->work->msgBank[3], 0x22);
    toolWork = args->work;
    printSys = toolWork->printSys;
    PRINTSYS_PrintQue((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->statusWindow), 0x18, 4, text, toolWork->font);
    work->statusPending = 1;
    STRBUF_Delete(text);
}

void MONOLITH_TOOL_LIST_ShowMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId)
{
    if (work->messagePrinter != 0)
        GF_PANIC_Fail(PM_LANG_JA(d_021BABFC, str_ja_021BAB68), PM_SRC_LINE(0, 0x35E), PM_LANG_JA(d_021BABFC, str_ja_021BAB98));
    GF_FONT_SetTextColor(1, 2, 0xf);
    work->messageText = MSGDATA_AllocString(toolWork->msgBank[3], msgId);
    work->messagePrinter = PRINTSYS_PrintStream(work->messageWindow, 0, 0, work->messageText, toolWork->font, MSG_SPEED_GetWait(), toolWork->taskList, 0xa, 0x61, 0xf);
    BMP_WIN_MakeScreen(work->messageWindow);
    BMP_MENUWORK_DrawWindow(work->messageWindow, 1, 1, 0xb);
}

void MONOLITH_TOOL_LIST_ShowFormattedMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId)
{
    struct Strbuf *format;

    if (work->messagePrinter != 0)
        GF_PANIC_Fail(PM_LANG_JA(d_021BABFC, str_ja_021BAB68), PM_SRC_LINE(0, 0x37C), PM_LANG_JA(d_021BABFC, str_ja_021BAB98));
    GF_FONT_SetTextColor(1, 2, 0xf);
    format = MSGDATA_AllocString(toolWork->msgBank[3], msgId);
    work->messageText = STRBUF_Create(0x100, 0x61);
    WORDSET_CopyTaggedText(toolWork->wordSet, work->messageText, format);
    STRBUF_Delete(format);
    work->messagePrinter = PRINTSYS_PrintStream(work->messageWindow, 0, 0, work->messageText, toolWork->font, MSG_SPEED_GetWait(), toolWork->taskList, 0xa, 0x61, 0xf);
    BMP_WIN_MakeScreen(work->messageWindow);
    BMP_MENUWORK_DrawWindow(work->messageWindow, 1, 1, 0xb);
}

/*
 * leaf: unlabelled tail stub called by MONOLITH_TOOL_LIST_Main; parent confirmed unowned.
 */
int MONOLITH_TOOL_LIST_IsMessageDone(MonolithToolWork *toolWork, MonolithListWork *work)
{
    return PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)toolWork->scratchList, work->messagePrinter);
}

void MONOLITH_TOOL_LIST_HideMessage(MonolithListWork *work)
{
    struct Bitmap *bitmap;

    bitmap = (struct Bitmap *)BMP_WIN_GetBmp(work->messageWindow);
    if (work->messagePrinter == 0)
        GF_PANIC_Fail(PM_LANG_JA(d_021BABFC, str_ja_021BAB68), PM_SRC_LINE(0, 0x3A8), PM_LANG_JA(d_021BABFC, str_ja_021BABB4));
    PRINTSYS_PrintStreamDelete(work->messagePrinter);
    work->messagePrinter = 0;
    STRBUF_Delete(work->messageText);
    work->messageText = 0;
    BMP_MENUWORK_DrawWindowBorder(work->messageWindow, 0);
    BMP_Clear((struct Bmp *)bitmap, 0xff);
    BMP_WIN_TransferChars(work->messageWindow);
    GF_FONT_SetTextColor(0xf, 2, 0);
}

void MONOLITH_TOOL_LIST_FitBackground(MonolithListWork *work)
{
    int count;
    int offset;

    count = work->entryCount;
    if (count - 2 < 7) {
        offset = (count - 1) * 32 / 8;
        BG_SYS_SetTileEntry(6, 0, 0, (u8)offset, 0x20, 0x20 - offset, 0x11);
        BG_SYS_PushTile(6);
    }
}

void MONOLITH_TOOL_LIST_BuildEntryList(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork)
{
    Idx i = 0;
    int n;
    int kind;
    MonolithCounts *counts;

    GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx);
    counts = MONOLITH_TOOL_GetSlotIconStates(args);
    work->entryIds[0] = i;
    work->entryDisabled[0] = 1;
    work->entryBitmaps[0] = (struct Bitmap *)BMP_Create(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < MONOLITH_ENTRY_NONE; i++) {
        kind = TOWN_MAP_SPOT_Classify((struct Rec *)toolWork->entryTable, i, (struct Pos *)counts, (u8 *)args->setup->rankData);
        if (kind != 2) {
            work->entryIds[n] = i;
            work->entryDisabled[n] = kind;
            work->entryBitmaps[n] = (struct Bitmap *)BMP_Create(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    work->entryIds[n] = 0;
    work->entryDisabled[n] = 1;
    work->entryBitmaps[n] = (struct Bitmap *)BMP_Create(0x17, 2, 0x20, 0x61);
    work->entryCount = n + 1;
}

void MONOLITH_TOOL_LIST_FreeEntryBitmaps(MonolithListWork *work) { int i; for (i = 0; i < work->entryCount; i++) BMP_Delete((struct Bmp *)work->entryBitmaps[i]); }

int MONOLITH_TOOL_LIST_DrawEntryNames(MonolithListWork *work, MonolithToolWork *toolWork)
{
    int count;
    int i;
    struct Strbuf *text;

    count = 0;
    text = STRBUF_Create(0x20, 0x61);
    i = work->loadedCount;
    if (i < work->entryCount) {
        do {
            if (i >= 1 && i < work->entryCount - 1) {
                MSGDATA_ReadString(work->entryNameBank, work->entryIds[i], text);
                PRINTSYS_PrintColor((struct Bmp *)work->entryBitmaps[i], 0, 0, text, (void *)toolWork->font,
                              d_021BAAF8[work->entryDisabled[i]]);
            }
            count++;
            if (count >= 3)
                break;
            i++;
        } while (i < work->entryCount);
    }
    STRBUF_Delete(text);
    work->loadedCount = i;
    return work->loadedCount >= work->entryCount;
}

void MONOLITH_TOOL_CreateRowGrids(MonolithListWork *work, MonolithToolWork *toolWork)
{
    int i;
    struct MonolithToolGridParam param;

    param = gMonolithRowGridParam;
    param.palette = toolWork->actorRes[1].simplePalAnm;
    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        work->rowBitmaps[i] = (struct Bitmap *)BMP_Create(0x17, 2, 0x20, 0x61);
        param.bitmap = work->rowBitmaps[i];
        work->rowGrids[i] = (struct BmpOamGrid *)BMP_OAM_Create(toolWork->actorToolUnit, (struct BmpOamParam *)(&param));
    }
}

void MONOLITH_TOOL_DeleteRowGrids(MonolithListWork *work)
{
    int i;

    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        BMP_OAM_Delete((struct BmpOam *)work->rowGrids[i]);
        BMP_Delete((struct Bmp *)work->rowBitmaps[i]);
    }
}

void MONOLITH_TOOL_CreateBackButton(MonolithToolProcArgs *args, MonolithListWork *work)
{
    MONOLITH_TOOL_CreateButton(args->work, &work->backButton, 1, 2, 0x40, 0xb4, 0x24, 0);
    if (UI_GetInputMode() == 1)
        MONOLITH_TOOL_SetButtonVisible(&work->backButton, 0);
}

void MONOLITH_TOOL_LIST_FreeBackButton(MonolithListWork *work)
{
    MONOLITH_TOOL_FreeButton(&work->backButton);
}

void MONOLITH_TOOL_LIST_UpdateBackButton(MonolithToolWork *toolWork, MonolithListWork *work)
{
    MONOLITH_TOOL_IsButtonUploaded(toolWork, &work->backButton);
}

void MONOLITH_TOOL_CreateMarker(MonolithToolProcArgs *args, MonolithListWork *work)
{
    MONOLITH_TOOL_CreateBlink(args->work, &work->marker);
}

void MONOLITH_TOOL_DeleteMarker(MonolithListWork *work)
{
    MONOLITH_TOOL_DeleteBlink(&work->marker);
}

void MONOLITH_TOOL_UpdateMarker(MonolithListWork *work)
{
    MONOLITH_TOOL_UpdateBlink(&work->marker);
}

void MONOLITH_TOOL_CreateScrollArrows(MonolithToolProcArgs *args, MonolithListWork *work)
{
    work->scrollUpArrow = MONOLITH_TOOL_CreateActorAt(args->work, 0x80, 0x1c, 9);
    work->scrollDownArrow = MONOLITH_TOOL_CreateActorAt(args->work, 0x80, 0xa4, 10);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->scrollUpArrow, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->scrollDownArrow, 0);
}

void MONOLITH_TOOL_DeleteScrollArrows(MonolithListWork *work)
{
    MONOLITH_TOOL_DeleteActorAt(work->scrollUpArrow);
    MONOLITH_TOOL_DeleteActorAt(work->scrollDownArrow);
}

void MONOLITH_TOOL_UpdateScrollArrows(MonolithListWork *work)
{
    if (work->scrollPos <= 0x800)
        CLACT_SetActorDrawEnable((struct ClactActor *)work->scrollUpArrow, 0);
    else
        CLACT_SetActorDrawEnable((struct ClactActor *)work->scrollUpArrow, 1);
    if ((work->scrollPos >> 8) >= work->entryCount * MONOLITH_ROW_HEIGHT - 200)
        CLACT_SetActorDrawEnable((struct ClactActor *)work->scrollDownArrow, 0);
    else
        CLACT_SetActorDrawEnable((struct ClactActor *)work->scrollDownArrow, 1);
    MONOLITH_TOOL_Noop(work->scrollUpArrow);
    MONOLITH_TOOL_Noop(work->scrollDownArrow);
}

/*
 * `touching = 0` in the key branch is what keeps r7 as the zero stored to
 * scrollVelocity/touchFrames and passed to UI_SetInputMode; `work->scrollRequest
 * = chosen` (not 0) reloads the spilled result as in the image.
 */
int MONOLITH_TOOL_ProcessListInput(MonolithToolProcArgs *args, MonolithListWork *work)
{
    int chosen;
    int selectedRow;
    u32 touchX;
    u32 touchY;
    int touching;
    int contentY;
    int row;
    int rowRemainder;
    int dragDistance;
    int tappedRow;

    chosen = 0;
    selectedRow = MONOLITH_CURSOR_NONE;
    work->scrollRequest = chosen;
    touching = TOUCHPANEL_GetPointCont(&touchX, &touchY);
    if (work->touchFrames == 0) {
        if (touchX < 0x18 || touchX > 0xe0) {
            touching = 0;
        }
    }
    if (KEY_GetCont() & (MONOLITH_KEY_A | MONOLITH_KEY_B | MONOLITH_KEY_UP | MONOLITH_KEY_DOWN)) {
        contentY = (work->scrollPos >> 8) + 0x18;
        row = contentY / MONOLITH_ROW_HEIGHT;
        rowRemainder = contentY % MONOLITH_ROW_HEIGHT;
        touching = 0;
        work->scrollVelocity = touching;
        work->touchFrames = touching;
        if (work->cursor == MONOLITH_CURSOR_NONE) {
            if (rowRemainder != 0) {
                row++;
            }
            if (row < 1) {
                row = 1;
            }
            if (row >= work->entryCount - 2) {
                MONOLITH_TOOL_SetCursor(work, work->entryCount - 2, MONOLITH_INPUT_KEY);
            } else {
                MONOLITH_TOOL_SetCursor(work, row, MONOLITH_INPUT_KEY);
            }
            GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
            return 0;
        }
        if (KEY_GetTrg() & MONOLITH_KEY_A) {
            MONOLITH_TOOL_SetCursor(work, work->cursor, MONOLITH_INPUT_KEY);
            UI_SetInputMode(0);
            if (work->entryDisabled[work->cursor] == 0) {
                GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_CONFIRM);
            }
            return 1;
        }
        if (KEY_GetRepeat() & MONOLITH_KEY_UP) {
            if (rowRemainder != 0) {
                row++;
            }
            if (MONOLITH_TOOL_SetCursor(work, work->cursor - 1, MONOLITH_INPUT_KEY) == 1) {
                GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
            }
            if (work->cursor < row) {
                work->scrollRequest = -0x2000;
            }
            return 0;
        }
        if (KEY_GetRepeat() & MONOLITH_KEY_DOWN) {
            row = ((work->scrollPos >> 8) + 0xa8) / MONOLITH_ROW_HEIGHT;
            if (MONOLITH_TOOL_SetCursor(work, work->cursor + 1, MONOLITH_INPUT_KEY) == 1) {
                GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
            }
            if (work->cursor >= row) {
                work->scrollRequest = 0x2000;
            }
            return 0;
        }
    }
    if (work->touchFrames == 0) {
        if (touching == 1) {
            if (touchY > 0x18 && touchY < 0xa8) {
                work->touchFrames = 1;
                work->touchY = touchY;
                work->touchStartY = touchY;
                MONOLITH_TOOL_SetCursor(work, MONOLITH_CURSOR_NONE, MONOLITH_INPUT_NONE);
            } else if (TOUCHPANEL_GetTrg() == 1 && work->cursor != MONOLITH_CURSOR_NONE
                       && touchX >= 0x10 && touchX <= 0x70 && touchY >= 0xac && touchY <= 0xbc) {
                chosen = 1;
                selectedRow = work->cursor;
                UI_SetInputMode(1);
            }
        } else if (work->scrollVelocity != 0) {
            if (work->scrollVelocity > 0) {
                work->scrollVelocity -= 0xc0;
                if (work->scrollVelocity < 0) {
                    work->scrollVelocity = 0;
                }
            } else {
                work->scrollVelocity += 0xc0;
                if (work->scrollVelocity > 0) {
                    work->scrollVelocity = 0;
                }
            }
        }
    } else if (touching == 0) {
        work->touchFrames = 0;
        if (work->touchStartY != MONOLITH_CURSOR_NONE) {
            dragDistance = work->touchY - work->touchStartY;
            if (dragDistance < 0) {
                dragDistance = -dragDistance;
            }
            if (dragDistance < 4) {
                tappedRow = MONOLITH_TOOL_GetRowAtY(work, work->touchY);
                if (tappedRow != MONOLITH_CURSOR_NONE) {
                    chosen = 1;
                    selectedRow = tappedRow;
                    GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
                }
            }
        }
    } else {
        work->scrollVelocity = (work->touchY - touchY) << 8;
        work->touchY = touchY;
        work->touchFrames++;
        if (work->touchStartY != MONOLITH_CURSOR_NONE) {
            dragDistance = touchY - work->touchStartY;
            if (dragDistance < 0) {
                dragDistance = -dragDistance;
            }
            if (dragDistance > 4) {
                work->touchStartY = MONOLITH_CURSOR_NONE;
            }
        }
    }
    if (chosen == 1) {
        work->scrollVelocity = 0;
        MONOLITH_TOOL_SetCursor(work, selectedRow, MONOLITH_INPUT_TOUCH);
    }
    return chosen;
}

int MONOLITH_TOOL_SetCursor(MonolithListWork *work, int index, int inputMode)
{
    int prev;

    if (index != MONOLITH_CURSOR_NONE) {
        if (index >= work->entryCount - 1 || index < 1) {
            return 0;
        }
    }
    prev = work->cursor;
    work->prevCursor = prev;
    work->lastCursor = prev;
    work->cursor = index;
    work->cursorChanged = 1;
    work->inputMode = inputMode;
    return 1;
}

void MONOLITH_TOOL_SetRowHighlight(MonolithListWork *work, int index, int palette)
{
    int scrollPixels;
    int firstRow;
    int rowOffset;
    int bgOffset;
    int rowOnScreen;

    if (index != MONOLITH_CURSOR_NONE) {
        scrollPixels = work->scrollPos >> 8;
        firstRow = scrollPixels / MONOLITH_ROW_HEIGHT;
        rowOffset = scrollPixels % MONOLITH_ROW_HEIGHT;
        bgOffset = scrollPixels % 64;
        rowOnScreen = index - firstRow;
        if (rowOnScreen >= 0 && rowOnScreen < firstRow + MONOLITH_ROW_GRIDS) {
            BG_SYS_FillTileMap(6, 3, ((rowOnScreen * MONOLITH_ROW_HEIGHT + bgOffset - rowOffset) % 256) / 8, 0x19, 4, palette);
        }
    }
}

/*
 * Two thunks passing a constant third argument.
 */
void MONOLITH_TOOL_SetRowHighlightSelected(MonolithListWork *work, int index)
{
    MONOLITH_TOOL_SetRowHighlight(work, index, 3);
}

void MONOLITH_TOOL_SetRowHighlightNormal(MonolithListWork *work, int index)
{
    MONOLITH_TOOL_SetRowHighlight(work, index, 0);
}

void MONOLITH_TOOL_ClearPrevHighlight(MonolithListWork *work)
{
    if (work->cursorChanged == 1)
        MONOLITH_TOOL_SetRowHighlightNormal(work, work->prevCursor);
}

void MONOLITH_TOOL_ApplyCursorChange(MonolithToolProcArgs *args, MonolithListWork *work)
{
    int cursor;
    int inputMode;

    if (work->cursorChanged == 1) {
        MONOLITH_TOOL_SetRowHighlightSelected(work, work->cursor);
        cursor = work->cursor;
        if (cursor == MONOLITH_CURSOR_NONE) {
            MONOLITH_TOOL_SetButtonPulse(args, 0, 1);
        } else {
            inputMode = work->inputMode;
            if ((inputMode == MONOLITH_INPUT_TOUCH && cursor == work->lastCursor)
                || (inputMode == MONOLITH_INPUT_KEY && cursor == work->prevCursor)) {
                if (work->entryDisabled[cursor] == 0) {
                    work->chosenEntry = cursor;
                    if (work->inputMode == MONOLITH_INPUT_KEY) {
                        MONOLITH_TOOL_SetButtonFlash(args, 1);
                    } else {
                        MONOLITH_TOOL_HighlightButtonFlash(args, &work->backButton, 1, 0, 3);
                    }
                } else if (inputMode == MONOLITH_INPUT_TOUCH) {
                    MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
                }
            } else {
                MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
            }
        }
        BG_SYS_MarkTileDirty(6);
        work->cursorChanged = 0;
    }
}

int MONOLITH_TOOL_ScrollBy(MonolithListWork *work, int delta)
{
    int limit;
    int oldPos;

    oldPos = work->scrollPos;
    limit = work->entryCount * MONOLITH_ROW_HEIGHT - 8;
    if (limit <= 0xc0) {
        return 0;
    }
    work->scrollPos = oldPos + delta;
    if (work->scrollPos < 0x800) {
        work->scrollPos = 0x800;
    } else if (work->scrollPos > (limit - 0xc0) << 8) {
        work->scrollPos = (limit - 0xc0) << 8;
    }
    if ((work->scrollPos >> 8) != (oldPos >> 8)) {
        return 1;
    }
    return 0;
}

void MONOLITH_TOOL_UpdateBgScroll(MonolithListWork *work)
{
    BG_SYS_ChangeScroll(6, 3, (work->scrollPos >> 8) % 64);
}

void MONOLITH_TOOL_UpdateRows(MonolithListWork *work)
{
    int scrollPixels = work->scrollPos >> 8;
    int gridY = 8 - scrollPixels % MONOLITH_ROW_HEIGHT;
    int firstRow = scrollPixels / MONOLITH_ROW_HEIGHT;
    int i;

    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        BMP_OAM_SetPos((struct BmpOam *)work->rowGrids[i], 0x20, gridY + i * MONOLITH_ROW_HEIGHT);
        if (work->entryBitmaps[firstRow + i] != 0) {
            BMP_CopyPixels((struct Bmp *)(work->entryBitmaps[firstRow + i]), (struct Bmp *)work->rowBitmaps[i]);
        }
    }
}

void MONOLITH_TOOL_TaskUploadRows(struct TcbTask *task, void *workArg)
{
    MonolithListWork *work = workArg;
    int i;

    if (work->uploadPending == 1) {
        for (i = 0; i < MONOLITH_ROW_GRIDS; i++)
            BMP_OAM_UploadChars((struct BmpOam *)work->rowGrids[i]);
        work->uploadPending = 0;
    }
}

int MONOLITH_TOOL_GetRowAtY(MonolithListWork *work, unsigned y)
{
    int row = ((work->scrollPos >> 8) + y) >> 5;

    if (row >= work->entryCount)
        row = MONOLITH_CURSOR_NONE;
    return row;
}

int MONOLITH_TOOL_InitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    MonolithInfoWork *newWork;
    int busy;
    int i;
    struct PrintSys *printSys;
    MonolithBool finished;

    switch (*state) {
    case 0:
        newWork = PROCSYS_AllocProcWork(proc, sizeof(MonolithInfoWork), 0x61);
        MI_CpuFill8(newWork, 0, sizeof(MonolithInfoWork));
        newWork->shownEntry = MONOLITH_ENTRY_NONE;
        MONOLITH_TOOL_SetupInfoBgs();
        MONOLITH_TOOL_LoadInfoPalette(args->work);
        MONOLITH_TOOL_CreateInfoWindows(args->work, newWork);
        MONOLITH_TOOL_DrawInfoHeader(args->work, newWork);
        MONOLITH_TOOL_DrawActiveEntry(args, args->work, newWork);
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            printSys = args->work->printSys;
            if (work->slots[i].pending != 0) {
                if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->slots[i].window)) == 0) {
                    BMP_WIN_TransferChars(work->slots[i].window);
                    work->slots[i].pending = 0;
                }
            }
            finished = work->slots[i].pending == 0 ? B_TRUE : B_FALSE;
            if (finished == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(0, 1);
            BG_SYS_SetPlaneVisible(2, 1);
            BG_SYS_SetMainPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

int MONOLITH_TOOL_MainInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    int i;
    u8 idle[3];
    struct PrintSys *printSys;

    if (args->topProcDone == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        printSys = args->work->printSys;
        if (work->slots[i].pending != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->slots[i].window)) == 0) {
                BMP_WIN_TransferChars(work->slots[i].window);
                work->slots[i].pending = 0;
            }
        }
        idle[i] = work->slots[i].pending == 0;
    }
    if (*state == 0) {
        if (args->param->activeDirty == 1 && idle[1] == 1) {
            MONOLITH_TOOL_DrawActiveEntry(args, args->work, work);
            args->param->activeDirty = 0;
        }
        if (args->param->selected != work->shownEntry && idle[2] == 1) {
            MONOLITH_TOOL_DrawSelectedEntry(args, args->work, work);
            work->shownEntry = args->param->selected;
        }
        return 0;
    }
    return 0;
}

int MONOLITH_TOOL_ExitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys) == 0)
        return 0;
    BG_SYS_SetMainVisiblePlanes(8);
    MONOLITH_TOOL_DeleteInfoWindows(work);
    MONOLITH_TOOL_HideInfoBgs();
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_SetupInfoBgs(void)
{
    BG_SYS_InitBgLayer(0, &gMonolithInfoBgTemplate0, 0);
    BG_SYS_InitBgLayer(2, &gMonolithInfoBgTemplate2, 0);
    BG_SYS_SetTileEntry(0, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
}

void MONOLITH_TOOL_HideInfoBgs(void)
{
    BG_SYS_SetPlaneVisible(0, 0);
    BG_SYS_SetPlaneVisible(2, 0);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(2);
}

void MONOLITH_TOOL_LoadInfoPalette(MonolithToolWork *toolWork)
{
    ARC_UTIL_UploadBgPaletteFromHandle(toolWork->archive, 13, 2, 0, 0, 1, 0x61);
    BG_SYS_PushTile(0);
    BG_SYS_PushTile(2);
}

void MONOLITH_TOOL_CreateInfoWindows(MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    int i;

    work->windows[0] = BMP_WIN_Create(0, 2, 0, 0x1c, 3, 0xd, 1);
    BMP_WIN_TransferChars(work->windows[0]);
    BMP_WIN_MakeScreen(work->windows[0]);
    work->windows[1] = BMP_WIN_Create(0, 2, 4, 0x1c, 8, 0xd, 1);
    BMP_WIN_TransferChars(work->windows[1]);
    BMP_WIN_MakeScreen(work->windows[1]);
    work->windows[2] = BMP_WIN_Create(0, 2, 0xf, 0x1c, 9, 0xd, 1);
    BMP_WIN_TransferChars(work->windows[2]);
    BMP_WIN_MakeScreen(work->windows[2]);
    for (i = 0; i < 3; i++) {
        work->slots[i].window = work->windows[i];
        work->slots[i].pending = 0;
    }
    BG_SYS_PushTile(0);
}

void MONOLITH_TOOL_DeleteInfoWindows(MonolithInfoWork *work)
{
    int i;

    for (i = 0; i < 3; i++)
        BMP_WIN_Delete(work->windows[i]);
}

/*
 * note: trailing two-byte alignment padding.
 */
void MONOLITH_TOOL_DrawInfoHeader(MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    struct Strbuf *text;
    struct PrintSys *printSys;

    text = MSGDATA_AllocString(toolWork->msgBank[3], 38);
    printSys = toolWork->printSys;
    PRINTSYS_PrintQue((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->slots[0].window), 0, 4, text, toolWork->font);
    work->slots[0].pending = 1;
    STRBUF_Delete(text);
}

void MONOLITH_TOOL_DrawActiveEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    struct Strbuf *name;
    struct Strbuf *desc;
    u32 activeEntry;
    struct PrintSys *printSys;

    activeEntry = INTRUDE_GetMonolithLevel(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx))));
    BMP_Clear(BMP_WIN_GetBmp(work->windows[1]), 0);
    if (activeEntry == MONOLITH_ENTRY_NONE) {
        name = MSGDATA_AllocString(toolWork->msgBank[3], 0x27);
    } else {
        name = MSGDATA_AllocString(toolWork->msgBank[1], toolWork->entryTable[activeEntry].nameMsgId);
        desc = MSGDATA_AllocString(toolWork->msgBank[2], toolWork->entryTable[activeEntry].descMsgId);
        printSys = toolWork->printSys;
        PRINTSYS_PrintQue((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->slots[1].window), 0, 0x10, desc, toolWork->font);
        work->slots[1].pending = 1;
        STRBUF_Delete(desc);
    }
    printSys = toolWork->printSys;
    PRINTSYS_PrintQue((struct PrintQueue *)printSys, BMP_WIN_GetBmp(work->slots[1].window), 0, 0, name, toolWork->font);
    work->slots[1].pending = 1;
    STRBUF_Delete(name);
}

/*
 * Lever: a 12-byte MonolithEntry subscript retains the second-path scale in r0;
 * byte indexing instead adds a copy and shifts the remainder by 2 bytes.
 * Extent after 0x021BA756 is alignment and rodata, not a code follower.
 */
static inline void PrintText(MonolithToolWork *toolWork, struct BmpWin *window, u32 x, s16 y, struct Strbuf *text)
{
    struct PrintSys *queue = toolWork->printSys;
    PRINTSYS_PrintQue((struct PrintQueue *)queue, BMP_WIN_GetBmp(window), x, y, text, toolWork->font);
}

void MONOLITH_TOOL_DrawSelectedEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    u32 selected;
    struct Strbuf *desc, *format, *line;
    MonolithCounts *counts;
    u32 msgId;
    u32 cost;

    selected = args->param->selected;
    BMP_Clear(BMP_WIN_GetBmp(work->windows[2]), 0);
    if (selected != MONOLITH_ENTRY_NONE) {
        if (args->param->mode == 0) {
            WORDSET_SetSlotNumber(toolWork->wordSet, 0, toolWork->entryTable[selected].number, 4, 0, PM_LANG_HALF_WIDTH_DIGITS);
            desc = MSGDATA_AllocString(toolWork->msgBank[2], toolWork->entryTable[selected].descMsgId);
            format = MSGDATA_AllocString(toolWork->msgBank[3], 0x28);
            line = STRBUF_Create(0x40, 0x61);
            WORDSET_CopyTaggedText(toolWork->wordSet, line, format);
            PrintText(toolWork, work->slots[2].window, 0, 4, desc);
            work->slots[2].pending = 1;
            PrintText(toolWork, work->slots[2].window, 0x70, 0x34, line);
            work->slots[2].pending = 1;
            STRBUF_Delete(desc);
            STRBUF_Delete(format);
            STRBUF_Delete(line);
        } else {
            counts = MONOLITH_TOOL_GetSlotIconStates(args);
            cost = toolWork->entryTable[selected].costA;
            if ((int)cost > counts->current) {
                msgId = 0x29;
            } else {
                cost = toolWork->entryTable[selected].costB;
                msgId = 0x2a;
            }
            WORDSET_SetSlotNumber(toolWork->wordSet, 0, cost, 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
            WORDSET_SetSlotNumber(toolWork->wordSet, 1, counts->current, 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
            WORDSET_SetSlotNumber(toolWork->wordSet, 2, counts->limit, 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
            format = MSGDATA_AllocString(toolWork->msgBank[3], msgId);
            line = STRBUF_Create(0x80, 0x61);
            WORDSET_CopyTaggedText(toolWork->wordSet, line, format);
            PrintText(toolWork, work->slots[2].window, 0, 4, line);
            work->slots[2].pending = 1;
            STRBUF_Delete(line);
            STRBUF_Delete(format);
        }
    } else {
        BMP_WIN_TransferChars(work->windows[2]);
    }
}
