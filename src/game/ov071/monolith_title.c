/*
 * file:     monolith_title.c
 * unit:     yes
 * function: drawText, MONOLITH_TOOL_TITLE_Init, MONOLITH_TOOL_TITLE_Main, MONOLITH_TOOL_TITLE_Exit, MONOLITH_TOOL_TITLE_InitBackgrounds, MONOLITH_TOOL_TITLE_FreeBackgrounds, MONOLITH_TOOL_TITLE_LoadGraphics, MONOLITH_TOOL_TITLE_CreateSlotIcons, MONOLITH_TOOL_TITLE_FreeSlotIcons, MONOLITH_TOOL_TITLE_UpdateSlotIcons, MONOLITH_TOOL_MENU_Create, MONOLITH_TOOL_MENU_Update, MONOLITH_TOOL_MENU_Destroy, MONOLITH_TOOL_MENU_CreateButtons, MONOLITH_TOOL_MENU_FreeButtons, MONOLITH_TOOL_MENU_UpdateButtons, MONOLITH_TOOL_MENU_CreateCursor, MONOLITH_TOOL_MENU_FreeCursor, MONOLITH_TOOL_MENU_UpdateCursor, MONOLITH_TOOL_MENU_InitBackgrounds, MONOLITH_TOOL_MENU_FreeBackgrounds, MONOLITH_TOOL_MENU_CreateWindow, MONOLITH_TOOL_MENU_FreeWindow, MONOLITH_TOOL_MENU_ShowMessage, MONOLITH_TOOL_MENU_IsMessageDone, MONOLITH_TOOL_MENU_HideMessage, MONOLITH_TOOL_SUMMARY_Create, MONOLITH_TOOL_SUMMARY_Update, MONOLITH_TOOL_SUMMARY_Destroy, MONOLITH_TOOL_SUMMARY_InitBackgrounds, MONOLITH_TOOL_SUMMARY_FreeBackgrounds, MONOLITH_TOOL_SUMMARY_LoadGraphics, MONOLITH_TOOL_SUMMARY_CreateWindows, MONOLITH_TOOL_SUMMARY_DeleteWindows, MONOLITH_TOOL_SUMMARY_CreateLabel, MONOLITH_TOOL_SUMMARY_FreeLabel, MONOLITH_TOOL_SUMMARY_Draw, MONOLITH_TOOL_STATS_Create, MONOLITH_TOOL_STATS_Update, MONOLITH_TOOL_STATS_Destroy, MONOLITH_TOOL_STATS_InitBackgrounds, MONOLITH_TOOL_STATS_FreeBackgrounds, MONOLITH_TOOL_STATS_LoadGraphics, MONOLITH_TOOL_STATS_CreateWindows, MONOLITH_TOOL_STATS_DeleteWindows, MONOLITH_TOOL_STATS_Draw, MONOLITH_TOOL_STATS_CreateCursor, MONOLITH_TOOL_STATS_FreeCursor, MONOLITH_TOOL_STATS_UpdateCursor
 * address:  0x021B7C3C
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
 *   MONOLITH_TOOL_IsButtonUploaded  0x021B6B70  thumb  ov071
 *   MONOLITH_TOOL_HighlightButtonPulse  0x021B6B98  thumb  ov071
 *   MONOLITH_TOOL_HighlightButtonFlash  0x021B6BEC  thumb  ov071
 *   MONOLITH_TOOL_ResetHighlights  0x021B6C54  thumb  ov071
 *   MONOLITH_TOOL_GetHighlightMode  0x021B6C74  thumb  ov071
 *   MONOLITH_TOOL_UpdateHighlight  0x021B6C7C  thumb  ov071
 *   MONOLITH_TOOL_CreateLabel  0x021B6E1C  thumb  ov071
 *   MONOLITH_TOOL_FreeLabel  0x021B6EEC  thumb  ov071
 *   MONOLITH_TOOL_UpdateLabel  0x021B6F04  thumb  ov071
 *   MONOLITH_TOOL_GetTitleSpecies  0x021B6F2C  thumb  ov071
 *   MONOLITH_TOOL_GetSlotIconStates  0x021B6F40  thumb  ov071
 *   MONOLITH_TOOL_CreateSlotIcon  0x021B6F54  thumb  ov071
 *   MONOLITH_TOOL_DeleteSlotIcon  0x021B6FD8  thumb  ov071
 *   MONOLITH_TOOL_UpdateSlotIconState  0x021B6FE0  thumb  ov071
 *   MONOLITH_TOOL_CreateBlink  0x021B7070  thumb  ov071
 *   MONOLITH_TOOL_DeleteBlink  0x021B70B8  thumb  ov071
 *   MONOLITH_TOOL_UpdateBlink  0x021B70C4  thumb  ov071
 *   MONOLITH_TOOL_StartBlink  0x021B7108  thumb  ov071
 *   MONOLITH_TOOL_IsBlinkActive  0x021B7114  thumb  ov071
 *   MONOLITH_TOOL_DrawSlotCounts  0x021B7234  thumb  ov071
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


int MONOLITH_TOOL_TITLE_Init(void *ctx, int *state, MonolithToolProcArgs *args)
{
    MonolithToolTitle *screen;
    void *monsterName;
    void *name;
    struct MyStatus *species;
    switch (*state) {
    case 0:
        screen = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolTitle), 0x61);
        MI_CpuFill8(screen, 0, sizeof(MonolithToolTitle));
        MONOLITH_TOOL_TITLE_InitBackgrounds();
        MONOLITH_TOOL_TITLE_LoadGraphics(args, args->work);
        species = MONOLITH_TOOL_GetTitleSpecies(args);
        name = STRBUF_Create(8, 0x61);
        STRBUF_SetStringN(name, MYSTATUS_GetName((const void *)species), 8);
        WORDSET_SetSlotTag((struct WordSet *)args->work->wordSet, 0, name, MYSTATUS_GetSex(species), 1, PM_LANG_ID);
        STRBUF_Delete(name);
        MONOLITH_TOOL_CreateLabel(args->work, &screen->nameLabel, 0, 0x80, 0xc, 0x1e, 2, 0, (void *)args->work->wordSet);
        MONOLITH_TOOL_TITLE_CreateSlotIcons(screen, args);
        *state = *state + 1;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(2, 1);
        BG_SYS_SetMainPlaneVisible(0x10, 1);
        return 1;
    }
    return 0;
}

int MONOLITH_TOOL_TITLE_Main(int unused,int *state,MonolithToolProcArgs *args,MonolithToolTitle *screen) { if(args->topProcDone==1) return 1; MONOLITH_TOOL_UpdateLabel(args->work,&screen->nameLabel); MONOLITH_TOOL_TITLE_UpdateSlotIcons(screen,args); switch(*state) { case 0:return 0; default:return 0; } }

int MONOLITH_TOOL_TITLE_Exit(void *proc,int unused,MonolithToolProcArgs *args,MonolithToolTitle *screen) { if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys)==0) return 0; BG_SYS_SetMainVisiblePlanes(8); MONOLITH_TOOL_TITLE_FreeSlotIcons(screen); MONOLITH_TOOL_FreeLabel(&screen->nameLabel); MONOLITH_TOOL_TITLE_FreeBackgrounds(); PROCSYS_FreeProcWork(proc); return 1; }

void MONOLITH_TOOL_TITLE_InitBackgrounds(void) { BG_SYS_InitBgLayer(2,(const struct BgTemplate *)d_021BA928,0); BG_SYS_SetTileEntry(2,0,0,0,0x20,0x20,0x11); }

void MONOLITH_TOOL_TITLE_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(2, 0); BG_SYS_FreeLayerBuf(2); }

void MONOLITH_TOOL_TITLE_LoadGraphics(MonolithToolProcArgs *args,MonolithToolWork *work) { ARC_UTIL_UploadBgPaletteFromHandle(work->archive,11,2,0,0,1,0x61); MONOLITH_TOOL_DrawSlotCounts(args,0,2); BG_SYS_PushTile(2); }

void MONOLITH_TOOL_TITLE_CreateSlotIcons(MonolithToolTitle *screen, MonolithToolProcArgs *args)
{
    int i;
    MonolithCounts *counts = MONOLITH_TOOL_GetSlotIconStates(args);
    for (i = 0; i < 6; i++) {
        sptr icon;
        unsigned recordIndex = d_021BAA4C[i];
        icon = MONOLITH_TOOL_CreateSlotIcon(args->work, counts, i, (const int *)(d_021BA948 + recordIndex * 8), 0);
        screen->slotIcon[i] = (void *)icon;
    }
}

void MONOLITH_TOOL_TITLE_FreeSlotIcons(MonolithToolTitle *screen) { int i; for(i=0;i<6;i++) MONOLITH_TOOL_DeleteSlotIcon(screen->slotIcon[i]); }

void MONOLITH_TOOL_TITLE_UpdateSlotIcons(MonolithToolTitle *screen,MonolithToolProcArgs *args) { int i; MonolithCounts *counts; counts=MONOLITH_TOOL_GetSlotIconStates(args); for(i=0;i<6;i++) MONOLITH_TOOL_UpdateSlotIconState(screen->slotIcon[i],counts,i); }

int MONOLITH_TOOL_MENU_Create(struct Proc *ctx, int unused, MonolithToolProcArgs *args)
{
    void *gameData = GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx);
    MonolithToolMenu *screen = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolMenu), 0x61);

    MI_CpuFill8(screen, 0, sizeof(MonolithToolMenu));
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(gameData), 0x980) == 0) {
        screen->kind = 2;
    } else if (args->setup->useSlotRecords == 1) {
        screen->kind = 1;
    } else {
        screen->kind = 0;
    }
    MONOLITH_TOOL_MENU_InitBackgrounds();
    MONOLITH_TOOL_MENU_CreateWindow(screen, args->work);
    MONOLITH_TOOL_MENU_CreateButtons(args, screen);
    MONOLITH_TOOL_MENU_CreateCursor(args, screen);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    return 1;
}

int MONOLITH_TOOL_MENU_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    u8 *saveData;
    int touchResult;
    u32 keys;
    int touch;

    saveData = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((struct GameSystem *)args->setup->gameCtx));
    MONOLITH_TOOL_MENU_UpdateButtons(args, screen);
    MONOLITH_TOOL_MENU_UpdateCursor(screen);
    if (args->abortRequested == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        touchResult = TOUCHPANEL_HitTrg((const TouchHitTable *)&d_021BA9F8[screen->kind]);
        if (touchResult != -1) {
            screen->selected = touchResult;
            screen->result = d_021BA9C8[screen->kind][touchResult];
            UI_SetInputMode(1);
            screen->touchArmed = 0;
            (*state)++;
            break;
        }
        keys = KEY_GetRepeat();
        touch = KEY_GetTrg();
        if (touch > 0 && screen->touchArmed == 1) {
            UI_SetInputMode(0);
            screen->touchArmed = 0;
            MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x548);
            break;
        }
        if (touch & 1) {
            screen->result = d_021BA9C8[screen->kind][screen->selected];
            (*state)++;
        } else if (touch & 2) {
            screen->result = 3;
            (*state)++;
        } else if (keys & 0x80) {
            screen->selected++;
            if (screen->selected >= d_021BA978[screen->kind]) {
                screen->selected = 0;
            }
            MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if (keys & 0x40) {
            screen->selected--;
            if (screen->selected < 0) {
                screen->selected = d_021BA978[screen->kind] - 1;
            }
            MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
        break;
    case 1:
        if (screen->result == 0) {
            if (args->setup->useSlotRecords == 0) {
                (*state)--;
                break;
            }
            if (saveData != 0 && INTRUDE_COMM_IsSessionActive((struct IntrudeSession *)(saveData + 0x1ac)) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                MONOLITH_TOOL_MENU_ShowMessage(screen, args->work, 4);
                *state = 3;
                break;
            }
        }
        if (screen->result != 3) {
            MONOLITH_TOOL_HighlightButtonFlash(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x54c);
        } else {
            MONOLITH_TOOL_StartBlink(&screen->cursorBlink);
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
        (*state)++;
        break;
    case 2:
        if (screen->result != 3) {
            if (MONOLITH_TOOL_GetHighlightMode(args, 3) != 2) {
                args->requestedScreen = screen->result + 1;
                return 1;
            }
        } else {
            if (MONOLITH_TOOL_IsBlinkActive(&screen->cursorBlink) == 0) {
                args->requestedScreen = screen->result + 1;
                return 1;
            }
        }
        break;
    case 3:
        if (MONOLITH_TOOL_MENU_IsMessageDone(args->work, screen) == 1) {
            if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 3) != 0) {
                MONOLITH_TOOL_MENU_HideMessage(screen);
                GFL_USE_PlaySeDefaultVolume(0x547);
                *state = 0;
            }
        }
        break;
    }
    return 0;
}

int MONOLITH_TOOL_MENU_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolMenu *screen)
{

    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys) == 0) {
        return 0;
    }
    BG_SYS_SetSubVisiblePlanes(8);
    if (screen->messageBox != 0) {
        PRINTSYS_PrintStreamDelete(screen->messageBox);
    }
    if (screen->messageText != 0) {
        STRBUF_Delete(screen->messageText);
    }
    MONOLITH_TOOL_MENU_FreeButtons(screen);
    MONOLITH_TOOL_MENU_FreeCursor(screen);
    MONOLITH_TOOL_MENU_FreeWindow(screen);
    MONOLITH_TOOL_MENU_FreeBackgrounds();
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_MENU_CreateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    unsigned i;
    unsigned kind;

    MONOLITH_TOOL_ResetHighlights(args);
    for (i = 0; i < d_021BA978[screen->kind]; i++) {
        kind = screen->kind;
        if (kind == 1) {
            MONOLITH_TOOL_CreateButton(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i + 1, 0);
        } else if (kind == 0) {
            MONOLITH_TOOL_CreateButton(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i + 2, 0);
        } else if (kind == 2) {
            MONOLITH_TOOL_CreateButton(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i == 0 ? 1 : 3, 0);
        }
    }
    if (UI_GetInputMode() == 0) {
        MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], 0, 3);
        screen->touchArmed = 0;
    } else {
        screen->touchArmed = 1;
    }
}

void MONOLITH_TOOL_MENU_FreeButtons(MonolithToolMenu *screen) { unsigned i; for(i=0;i<d_021BA978[screen->kind];i++) MONOLITH_TOOL_FreeButton(&screen->button[i]); }

void MONOLITH_TOOL_MENU_UpdateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    unsigned i;

    MONOLITH_TOOL_UpdateHighlight(args, 3);
    for (i = 0; i < d_021BA978[screen->kind]; i++) {
        MONOLITH_TOOL_IsButtonUploaded(args->work, &screen->button[i]);
    }
}

/*
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x34).
 */
void MONOLITH_TOOL_MENU_CreateCursor(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    MONOLITH_TOOL_CreateBlink(args->work, &screen->cursorBlink);
}

void MONOLITH_TOOL_MENU_FreeCursor(MonolithToolMenu *screen)
{
    MONOLITH_TOOL_DeleteBlink(&screen->cursorBlink);
}

void MONOLITH_TOOL_MENU_UpdateCursor(MonolithToolMenu *screen)
{
    MONOLITH_TOOL_UpdateBlink(&screen->cursorBlink);
}

void MONOLITH_TOOL_MENU_InitBackgrounds(void) { BG_SYS_InitBgLayer(5,(const struct BgTemplate *)d_021BA984,0); BG_SYS_SetTileEntry(5,0,0,0,0x20,0x20,0x11); BG_SYS_SetPlaneVisible(5,0); }

void MONOLITH_TOOL_MENU_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(5, 0); BG_SYS_FreeLayerBuf(5); }

void MONOLITH_TOOL_MENU_CreateWindow(MonolithToolMenu *screen, MonolithToolWork *work)
{

    BMP_MENUWORK_LoadChar(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    screen->window = (void *)BMP_WIN_Create(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)screen->window)), 0xff);
    BMP_WIN_MakeScreen(screen->window);
    BMP_MENUWORK_DrawWindow(screen->window, 0, 1, 0xb);
}

/*
 * Tail call to BMP_WIN_Delete on the pointer loaded from offset 0x3c.
 */
void MONOLITH_TOOL_MENU_FreeWindow(MonolithToolMenu *screen)
{
    BMP_WIN_Delete(screen->window);
}

void MONOLITH_TOOL_MENU_ShowMessage(MonolithToolMenu *screen, MonolithToolWork *work, unsigned msgId)
{
    if (screen->messageBox != 0) {
        GF_PANIC_Fail(PM_LANG_JA(d_021BABF8, str_ja_021BAB1C), PM_SRC_LINE(0, 0x296), PM_LANG_JA(d_021BABF8, str_ja_021BAB30));
    }
    GF_FONT_SetTextColor(1, 2, 0xf);
    screen->messageText = MSGDATA_AllocString(work->msgBank[3], msgId);
    screen->messageBox = PRINTSYS_PrintStream(screen->window, 0, 0, (void *)screen->messageText, work->font, MSG_SPEED_GetWait(),
                           (void *)work->taskList, 10, 0x61, 0xf);
    BG_SYS_SetPlaneVisible(5, 1);
}

int MONOLITH_TOOL_MENU_IsMessageDone(MonolithToolWork *work, MonolithToolMenu *screen)
{
    return PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)work->scratchList, screen->messageBox);
}

void MONOLITH_TOOL_MENU_HideMessage(MonolithToolMenu *screen)
{
    struct Bmp *r = BMP_WIN_GetBmp(screen->window);

    if (screen->messageBox == 0) {
        GF_PANIC_Fail(PM_LANG_JA(d_021BABF8, str_ja_021BAB1C), PM_SRC_LINE(0, 0x2BC), PM_LANG_JA(d_021BABF8, str_ja_021BAB4C));
    }
    PRINTSYS_PrintStreamDelete(screen->messageBox);
    screen->messageBox = 0;
    STRBUF_Delete(screen->messageText);
    screen->messageText = 0;
    BG_SYS_SetPlaneVisible(5, 0);
    BMP_Clear((struct Bmp *)r, 0xff);
    BMP_WIN_TransferChars(screen->window);
    GF_FONT_SetTextColor(0xf, 2, 0);
}

int MONOLITH_TOOL_SUMMARY_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    MonolithToolSummary *created;
    int busy;
    int i;

    switch (*state) {
    case 0:
        created = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolSummary), 0x61);
        MI_CpuFill8(created, 0, sizeof(MonolithToolSummary));
        MONOLITH_TOOL_SUMMARY_InitBackgrounds();
        MONOLITH_TOOL_SUMMARY_LoadGraphics(args->work);
        MONOLITH_TOOL_SUMMARY_CreateWindows((sptr)args->work, created);
        MONOLITH_TOOL_SUMMARY_CreateLabel(args->work, created);
        created->shownSlot = 0xff;
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *printSys = args->work->printSys;
            if (screen->text[i].on != 0) {
                if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)(BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                    BMP_WIN_TransferChars(screen->text[i].window);
                    screen->text[i].on = 0;
                }
            }
            if ((!screen->text[i].on) == 0) {
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

/*
 * Both tail returns are 0; the load of *p survives only through a
 * `switch` with a `default`, and `(!s[0xc]) == 1` keeps the boolean.
 */
int MONOLITH_TOOL_SUMMARY_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    void *saveData;
    int idleCount;
    int i;

    saveData = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((struct GameSystem *)args->setup->gameCtx));
    idleCount = 0;
    if (args->topProcDone == 1) {
        return 1;
    }
    MONOLITH_TOOL_UpdateLabel(args->work, &screen->nameLabel);
    for (i = 0; i < 2; i++) {
        void *printSys = args->work->printSys;
        if (screen->text[i].on != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)(BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                BMP_WIN_TransferChars(screen->text[i].window);
                screen->text[i].on = 0;
            }
        }
        if ((!screen->text[i].on) == 1) {
            idleCount++;
        }
    }
    if (idleCount == 2) {
        unsigned slot = args->param->slot;
        if (screen->shownSlot != slot) {
            MONOLITH_TOOL_SUMMARY_Draw(args, args->work, screen, (u8 *)saveData, slot);
            screen->shownSlot = args->param->slot;
        }
    }
    switch (*state) {
    case 0:
        return 0;
    default:
        return 0;
    }
}

int MONOLITH_TOOL_SUMMARY_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys) == 0) return 0;
    BG_SYS_SetMainVisiblePlanes(8);
    MONOLITH_TOOL_SUMMARY_DeleteWindows(screen);
    MONOLITH_TOOL_SUMMARY_FreeBackgrounds();
    MONOLITH_TOOL_SUMMARY_FreeLabel(screen);
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_SUMMARY_InitBackgrounds(void)
{

    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)d_021BAA64, 0);
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)d_021BAA84, 0);
    BG_SYS_SetTileEntry(0, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
}

void MONOLITH_TOOL_SUMMARY_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(0,0); BG_SYS_SetPlaneVisible(2,0); BG_SYS_FreeLayerBuf(0); BG_SYS_FreeLayerBuf(2); }

void MONOLITH_TOOL_SUMMARY_LoadGraphics(MonolithToolWork *work) { ARC_UTIL_UploadBgPaletteFromHandle(work->archive,12,2,0,0,1,0x61); BG_SYS_PushTile(0); BG_SYS_PushTile(2); }

void MONOLITH_TOOL_SUMMARY_CreateWindows(int unused, MonolithToolSummary *screen)
{
    int i;

    screen->window[0] = (void *)BMP_WIN_Create(0, 2, 0, 0x1c, 3, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[0]);
    BMP_WIN_MakeScreen(screen->window[0]);
    screen->window[1] = (void *)BMP_WIN_Create(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[1]);
    BMP_WIN_MakeScreen(screen->window[1]);
    for (i = 0; i < 2; i++) {
        screen->text[i].window = screen->window[i];
        screen->text[i].on = 0;
    }
    BG_SYS_PushTile(0);
}

void MONOLITH_TOOL_SUMMARY_DeleteWindows(MonolithToolSummary *screen) { BMP_WIN_Delete(screen->window[0]); BMP_WIN_Delete(screen->window[1]); }

void MONOLITH_TOOL_SUMMARY_CreateLabel(MonolithToolWork *work, MonolithToolSummary *screen) { MONOLITH_TOOL_CreateLabel(work, &screen->nameLabel, 1, 0x80, 0xb4, 0x1c, 2, 0x13, 0); }

/*
 * Tail call to MONOLITH_TOOL_FreeLabel((char *)p + 0x18).
 */
void MONOLITH_TOOL_SUMMARY_FreeLabel(MonolithToolSummary *screen)
{
    MONOLITH_TOOL_FreeLabel(&screen->nameLabel);
}

/*
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 */
void MONOLITH_TOOL_SUMMARY_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolSummary *screen, u8 *saveData, unsigned slot)
{
    void *numberText;
    u8 *src;
    MonolithToolSlotInfo *info;
    u32 detailId;
    void *labelText;
    void *detailText;
    void *printSys;

    numberText = STRBUF_Create(0x100, 0x61);
    BMP_Clear(BMP_WIN_GetBmp(screen->window[0]), 0);
    BMP_Clear(BMP_WIN_GetBmp(screen->window[1]), 0);
    if (slot == 6 && saveData != 0 && INTRUDE_COMM_IsSessionActive((struct IntrudeSession *)(saveData + 0x1AC)) == 1) {
        info = (MonolithToolSlotInfo *)INTRUDE_COMM_GetActiveSessionRequest((struct IntrudeSession *)(saveData + 0x1AC));
        src = (u8 *)info + 0x18;
    } else {
        if (slot > 6) {
            slot = 0;
        }
        info = (MonolithToolSlotInfo *)&work->slotRecord[d_021BAA4C[slot]];
        src = (u8 *)args->setup->playerName;
    }
    detailId = info->detailId;
    labelText = MSGDATA_AllocString(work->msgBank[0], info->labelId);
    detailText = MSGDATA_AllocString(work->msgBank[0], detailId);
    INTRUDE_COMM_SetWordSetRequest((struct IntrudeRequestHead *)info, (struct IntrudeMemberName *)src, work->wordSet, 0x61);
    WORDSET_CopyTaggedText(work->wordSet, numberText, detailText);
    printSys = work->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(screen->text[0].window), 0, 4, labelText, work->font);
    screen->text[0].on = 1;
    printSys = work->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(screen->text[1].window), 0, 0, numberText, work->font);
    screen->text[1].on = 1;
    STRBUF_Delete(labelText);
    STRBUF_Delete(detailText);
    STRBUF_Delete(numberText);
}

/*
 * Twin of MONOLITH_TOOL_SUMMARY_Create (six handle slots at +0x18 instead of two at +8).
 */
int MONOLITH_TOOL_STATS_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    MonolithToolStats *created;
    int busy;
    int i;

    switch (*state) {
    case 0:
        created = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolStats), 0x61);
        MI_CpuFill8(created, 0, sizeof(MonolithToolStats));
        MONOLITH_TOOL_STATS_InitBackgrounds();
        MONOLITH_TOOL_STATS_LoadGraphics(args->work);
        MONOLITH_TOOL_STATS_CreateWindows((sptr)args->work, created);
        MONOLITH_TOOL_STATS_CreateCursor(args, created);
        MONOLITH_TOOL_STATS_Draw(args, args->work, created);
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *printSys = args->work->printSys;
            if (screen->text[i].on != 0) {
                if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)(BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                    BMP_WIN_TransferChars(screen->text[i].window);
                    screen->text[i].on = 0;
                }
            }
            if ((!screen->text[i].on) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(4, 1);
            BG_SYS_SetPlaneVisible(6, 1);
            BG_SYS_SetSubPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * `UI_SetInputMode(0)`/`UI_SetInputMode(1)` in the arms of `if (t & 2)`: the
 * two calls tail-merge into one `blx` with the then-arm's `movs r0, #0`
 * falling through; every ternary or `!` spelling of the argument emits
 * `bne` to the 1 instead (same size, polarity flipped).
 */
int MONOLITH_TOOL_STATS_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    int i;
    int touch;

    if (args->abortRequested == 1) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        void *printSys = args->work->printSys;
        if (screen->text[i].on != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)(BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                BMP_WIN_TransferChars(screen->text[i].window);
                screen->text[i].on = 0;
            }
        }
    }
    MONOLITH_TOOL_STATS_UpdateCursor(screen);
    switch (*state) {
    case 0:
        touch = KEY_GetTrg();
        if (TOUCHPANEL_HitTrg((const TouchHitTable *)d_021BAAA4) != -1 || (touch & 2) != 0) {
            MONOLITH_TOOL_StartBlink(&screen->cursorBlink);
            if (touch & 2) {
                UI_SetInputMode(0);
            } else {
                UI_SetInputMode(1);
            }
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = *state + 1;
        }
        break;
    case 1:
        if (MONOLITH_TOOL_IsBlinkActive(&screen->cursorBlink) == 0) {
            args->requestedScreen = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int MONOLITH_TOOL_STATS_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys) == 0) return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    MONOLITH_TOOL_STATS_FreeCursor(screen);
    MONOLITH_TOOL_STATS_DeleteWindows(screen);
    MONOLITH_TOOL_STATS_FreeBackgrounds();
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_STATS_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021BAAB8, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)d_021BAAD8, 0);
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
}

void MONOLITH_TOOL_STATS_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(4,0); BG_SYS_SetPlaneVisible(6,0); BG_SYS_FreeLayerBuf(4); BG_SYS_FreeLayerBuf(6); }

void MONOLITH_TOOL_STATS_LoadGraphics(MonolithToolWork *work) { ARC_UTIL_UploadBgPaletteFromHandle(work->archive,5,6,0,0,1,0x61); BG_SYS_PushTile(6); BG_SYS_PushTile(4); }

/*
 * Six-window twin of MONOLITH_TOOL_SUMMARY_CreateWindows.
 */
void MONOLITH_TOOL_STATS_CreateWindows(int unused, MonolithToolStats *screen)
{
    int i;

    screen->window[0] = (void *)BMP_WIN_Create(4, 2, 0x0, 0x1e, 0x3, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[0]);
    BMP_WIN_MakeScreen(screen->window[0]);
    screen->window[1] = (void *)BMP_WIN_Create(4, 2, 0x5, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[1]);
    BMP_WIN_MakeScreen(screen->window[1]);
    screen->window[2] = (void *)BMP_WIN_Create(4, 2, 0x8, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[2]);
    BMP_WIN_MakeScreen(screen->window[2]);
    screen->window[3] = (void *)BMP_WIN_Create(4, 2, 0xe, 0x1e, 0x4, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[3]);
    BMP_WIN_MakeScreen(screen->window[3]);
    screen->window[4] = (void *)BMP_WIN_Create(4, 2, 0x10, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[4]);
    BMP_WIN_MakeScreen(screen->window[4]);
    screen->window[5] = (void *)BMP_WIN_Create(4, 2, 0x12, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[5]);
    BMP_WIN_MakeScreen(screen->window[5]);
    for (i = 0; i < 6; i++) {
        screen->text[i].window = screen->window[i];
        screen->text[i].on = 0;
    }
    BG_SYS_PushTile(4);
}

void MONOLITH_TOOL_STATS_DeleteWindows(MonolithToolStats *screen) { int i; for (i=0;i<6;i++) BMP_WIN_Delete(screen->window[i]); }

static inline void drawText(MonolithToolWork *work, void *window, u32 x, s16 y, void *text)
{
    void *printSys = work->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(window), x, y, text, work->font);
}

/*
 * Each window draw is a `static inline` (drawText) whose `printSys` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 */
void MONOLITH_TOOL_STATS_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolStats *screen)
{
    MonolithCounts *counts;
    s64 seconds;
    u32 hours;
    u32 minutes;
    void *labelText;
    void *lineText;

    MONOLITH_TOOL_GetTitleSpecies(args);
    counts = MONOLITH_TOOL_GetSlotIconStates(args);
    labelText = STRBUF_Create(0x100, 0x61);
    lineText = STRBUF_Create(0x100, 0x61);
    MSGDATA_ReadString(work->msgBank[3], 0xd, labelText);
    drawText(work, screen->text[0].window, 0, 4, labelText);
    screen->text[0].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 5, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, counts->limit + counts->current, 5, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[1].window, 0, 0, lineText);
    screen->text[1].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 9, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, counts->limit, 4, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[2].window, 0, 0, lineText);
    screen->text[2].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 8, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, counts->current, 4, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[2].window, 0x78, 0, lineText);
    screen->text[2].on = 1;
    seconds = args->setup->playSeconds;
    hours = seconds / 60 / 60;
    if (hours > 999) {
        hours = 999;
        minutes = 59;
    } else {
        seconds -= hours * 3600;
        minutes = seconds / 60;
    }
    MSGDATA_ReadString(work->msgBank[3], 0xb, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, hours, 3, 1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(work->wordSet, 1, minutes, 2, 2, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[3].window, 0, 0, lineText);
    screen->text[3].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 0xc, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, args->setup->recordCount, 5, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[4].window, 0, 0, lineText);
    screen->text[4].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 0xa, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, TOWN_MAP_SPOT_CountVisited(work->entryTable, MONOLITH_TOOL_GetSlotIconStates(args), args->setup->rankData), 4, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[5].window, 0, 0, lineText);
    screen->text[5].on = 1;
    STRBUF_Delete(labelText);
    STRBUF_Delete(lineText);
}

/*
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x48).
 */
void MONOLITH_TOOL_STATS_CreateCursor(MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    MONOLITH_TOOL_CreateBlink(args->work, &screen->cursorBlink);
}

/*
 * Tail call to MONOLITH_TOOL_DeleteBlink with the pointer advanced by 0x48.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/MONOLITH_TOOL_DeleteBlink.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void MONOLITH_TOOL_STATS_FreeCursor(MonolithToolStats *screen)
{
    MONOLITH_TOOL_DeleteBlink(&screen->cursorBlink);
}

/*
 * Tail call to MONOLITH_TOOL_UpdateBlink((char *)p + 0x48).
 */
void MONOLITH_TOOL_STATS_UpdateCursor(MonolithToolStats *screen)
{
    MONOLITH_TOOL_UpdateBlink(&screen->cursorBlink);
}


