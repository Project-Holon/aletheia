/*
 * file:     monolith_mission_select.c
 * unit:     yes
 * function: MONOLITH_TOOL_SLOT_SELECT_Init, MONOLITH_TOOL_SLOT_SELECT_Main, MONOLITH_TOOL_SLOT_SELECT_Exit, MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds, MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds, MONOLITH_TOOL_SLOT_SELECT_LoadGraphics, MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow, MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow, MONOLITH_TOOL_SLOT_SELECT_ShowMessage, MONOLITH_TOOL_SLOT_SELECT_IsMessageDone, MONOLITH_TOOL_SLOT_SELECT_HideMessage, MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons, MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons, MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons, MONOLITH_TOOL_SLOT_SELECT_MoveCursor, MONOLITH_TOOL_SLOT_SELECT_CreateButtons, MONOLITH_TOOL_SLOT_SELECT_FreeButtons, MONOLITH_TOOL_SLOT_SELECT_UpdateButtons, MONOLITH_TOOL_SLOT_SELECT_CreateCursor, MONOLITH_TOOL_SLOT_SELECT_FreeCursor, MONOLITH_TOOL_SLOT_SELECT_UpdateCursor, MONOLITH_TOOL_SLOT_SELECT_SetMode
 * address:  0x021B730C
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
 *   MONOLITH_TOOL_ResetHighlights  0x021B6C54  thumb  ov071
 *   MONOLITH_TOOL_GetHighlightMode  0x021B6C74  thumb  ov071
 *   MONOLITH_TOOL_UpdateHighlight  0x021B6C7C  thumb  ov071
 *   MONOLITH_TOOL_GetSlotIconStates  0x021B6F40  thumb  ov071
 *   MONOLITH_TOOL_CreateSlotIcon  0x021B6F54  thumb  ov071
 *   MONOLITH_TOOL_DeleteSlotIcon  0x021B6FD8  thumb  ov071
 *   MONOLITH_TOOL_UpdateSlotIconState  0x021B6FE0  thumb  ov071
 *   MONOLITH_TOOL_CreateCursor  0x021B7014  thumb  ov071
 *   MONOLITH_TOOL_DeleteCursor  0x021B7068  thumb  ov071
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


int MONOLITH_TOOL_SLOT_SELECT_Init(void *ctx, int *state, MonolithToolProcArgs *args)
{
    MonolithToolSlotSelect *screen;

    switch (state[0]) {
    case 0:
        screen = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolSlotSelect), 0x61);
        MI_CpuFill8(screen, 0, sizeof(MonolithToolSlotSelect));
        screen->backMode = 0;
        MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds();
        MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(args, args->work);
        MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(screen, args->work);
        MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(screen, args);
        MONOLITH_TOOL_SLOT_SELECT_CreateButtons(args, screen);
        MONOLITH_TOOL_SLOT_SELECT_CreateCursor(args, screen);
        screen->cursorActor = (void *)MONOLITH_TOOL_CreateCursor(args->work, (const int *)&d_021BA8A0[args->param->slot], 1);
        state[0]++;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetSubPlaneVisible(0x10, 1);
        return 1;
    }
    return 0;
}

#pragma opt_lifetimes off

#pragma opt_common_subs off

int MONOLITH_TOOL_SLOT_SELECT_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
 u16 *nameDst;
 u16 *nameSrc;
 u8 *intrude;
 int keyState,touchResult,result;
 u32 slot;
 u8 nextSlot;
 const u8 *neighbors;
 intrude=(u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((struct GameSystem *)args->setup->gameCtx));
 MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(screen,args); MONOLITH_TOOL_SLOT_SELECT_MoveCursor(screen,args->param->slot);MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(args,screen);MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(screen);
 if(args->abortRequested==1 && *state==3) return 1;
 switch(*state) {
 case 0:
  if(intrude!=0 && INTRUDE_COMM_IsSessionActive((struct IntrudeSession *)(intrude+0x1ac))==1) MONOLITH_TOOL_SLOT_SELECT_SetMode(args,screen,1);
  *state=1;break;
 case 1:
  if(INTRUDE_COMM_HasUnlockFlags(GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx))==0) MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x16);
  else MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x12);
  ++*state;break;
 case 2:
  if(MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(args->work,screen)!=1) break;
  if(TOUCHPANEL_GetTrg()==0 && (KEY_GetTrg()&3)==0) break;
  MONOLITH_TOOL_SLOT_SELECT_HideMessage(screen);GFL_USE_PlaySeDefaultVolume(0x547);
  if(TOUCHPANEL_GetTrg()!=0) {screen->buttonHighlight=1;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0xff,3);}
  else {screen->buttonHighlight=0;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0,3);}
  if(screen->backMode==0) *state=3;else *state=4;
  break;
 case 3:
  keyState=KEY_GetTrg();touchResult=TOUCHPANEL_HitTrg((const TouchHitTable *)d_021BA87C);
  if(intrude!=0 && INTRUDE_COMM_IsSessionActive((struct IntrudeSession *)(intrude+0x1ac))==1) {MONOLITH_TOOL_SLOT_SELECT_SetMode(args,screen,1);screen->linkLost=1;*state=4;break;}
  if(keyState>0 && screen->buttonHighlight==1) {screen->buttonHighlight=0;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0,3);GFL_USE_PlaySeDefaultVolume(0x548);break;}
  if(keyState&0xf0) {
   nextSlot=0xff;
   for(slot=0;(slot<6)?1:0;slot++) if(d_021BA85C[slot]==args->param->slot) break;
   slot=args->param->slot;
   if(keyState&0x40) {neighbors=d_021BA862[slot];nextSlot=neighbors[0];}
   else if(keyState&0x80) {neighbors=d_021BA862[slot];nextSlot=neighbors[1];}
   else if(keyState&0x20) {neighbors=d_021BA862[slot];nextSlot=neighbors[2];}
   else if(keyState&0x10) {neighbors=d_021BA862[slot];nextSlot=neighbors[3];}
   if(nextSlot!=0xff) slot=nextSlot;
   args->param->slot=slot;GFL_USE_PlaySeDefaultVolume(0x548);
  }
  if(touchResult>=0 && touchResult<6) {args->param->slot=touchResult;screen->buttonHighlight=1;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0xff,3);GFL_USE_PlaySeDefaultVolume(0x548);break;}
  if(touchResult==6 || (keyState&1)) {
   UI_SetInputMode(touchResult==6);
   if(INTRUDE_COMM_HasUnlockFlags(GAMESYSTEM_GetGameData((const struct GameSystem *)args->setup->gameCtx))==0) {
    result=d_021BAA4C[args->param->slot];
    if(result!=2 && result!=1) {*state=9;break;}
   }
   MONOLITH_TOOL_HighlightButtonFlash(args,&screen->button[0],1,0,3);GFL_USE_PlaySeDefaultVolume(0x736);*state=5;
  } else if(touchResult==7 || (keyState&2)) {
   MONOLITH_TOOL_StartBlink(&screen->cursorBlink);UI_SetInputMode(touchResult==7);GFL_USE_PlaySeDefaultVolume(0x551);*state=11;
  }
  break;
 case 4: {
  int keyState4,touchResult4;
  keyState4=KEY_GetTrg();touchResult4=TOUCHPANEL_HitTrg((const TouchHitTable *)d_021BA87C);
  if(touchResult4==7 || (keyState4&2)) {if(touchResult4==7) UI_SetInputMode(1); else UI_SetInputMode(0);GFL_USE_PlaySeDefaultVolume(0x551);*state=11;}
  break;}

 case 5:
  screen->joinRecord=args->work->slotRecord[d_021BAA4C[args->param->slot]];
  screen->playerGender=args->setup->playerGender;
  nameDst=screen->playerName;
  nameSrc=args->setup->playerName;
  for(slot=10;slot!=0;slot--) {*nameDst=*nameSrc;nameDst++;nameSrc++;}
  if(intrude!=0 && INTRUDE_CMD_SendJoinRequest((struct IntrudeCommSys *)intrude,&screen->joinRecord)!=1) break;
  *state=6;break;
 case 6:
  if(intrude==0) {*state=3;break;}
  result=INTRUDE_COMM_TakeJoinReply((struct IntrudeSession *)(intrude+0x1ac));
  if(result==1) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x10);*state=7;}
  else if(result==2) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x11);*state=8;}
  else if(result==3) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x15);*state=8;}
  else if(result==4) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x14);*state=8;}
  break;
 case 7:case 8:
  if(MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(args->work,screen)!=1) break;
  if(*state==7) {
  } else if(*state==8) {
   if(TOUCHPANEL_GetTrg()==0 && !(KEY_GetTrg()&3)) break;
  } else break;
  if(*state==7 && intrude!=0 && INTRUDE_COMM_IsSessionActive((struct IntrudeSession *)(intrude+0x1ac))==0) break;
  MONOLITH_TOOL_SLOT_SELECT_HideMessage(screen);GFL_USE_PlaySeDefaultVolume(0x547);
  if(*state==7) {if(intrude!=0) INTRUDE_COMM_AcceptSession((struct IntrudeCommSys *)intrude,(struct IntrudeSession *)(intrude+0x1ac));screen->joined=1;*state=11;}
  else *state=11;
  break;
 case 9:MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x17);++*state;break;
 case 10:
  if(MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(args->work,screen)==1 && (TOUCHPANEL_GetTrg()!=0 || (KEY_GetTrg()&3)!=0)) {MONOLITH_TOOL_SLOT_SELECT_HideMessage(screen);*state=3;}
  break;
 case 11:
  if(MONOLITH_TOOL_GetHighlightMode(args,3)==2) break;
  if(MONOLITH_TOOL_IsBlinkActive(&screen->cursorBlink)!=0) break;
  if(screen->joined==1) args->requestedScreen=4;else args->requestedScreen=0;
  return 1;
 }
 return 0;
}

#pragma opt_lifetimes reset

#pragma opt_common_subs reset

int MONOLITH_TOOL_SLOT_SELECT_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)args->work->printSys) == 0)
        return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    if (screen->msgPrinter != 0)
        PRINTSYS_PrintStreamDelete(screen->msgPrinter);
    if (screen->msgString != 0)
        STRBUF_Delete(screen->msgString);
    MONOLITH_TOOL_DeleteCursor(screen->cursorActor);
    MONOLITH_TOOL_SLOT_SELECT_FreeCursor(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeButtons(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds();
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BA8DC, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)d_021BA8FC, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetPlaneVisible(5, 0);
}

void MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(5,0); BG_SYS_SetPlaneVisible(6,0); BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(6); }

void MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(MonolithToolProcArgs *args, MonolithToolWork *work) {ARC_UTIL_UploadBgPaletteFromHandle(work->archive,6,6,0,0,1,0x61);MONOLITH_TOOL_DrawSlotCounts(args,1,6);BG_SYS_PushTile(6);}

void MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(MonolithToolSlotSelect *screen, MonolithToolWork *work)
{
    BMP_MENUWORK_LoadChar(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    screen->msgWindow = (void *)BMP_WIN_Create(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear(BMP_WIN_GetBmp(screen->msgWindow), 0xff);
    BMP_WIN_MakeScreen(screen->msgWindow);
    BMP_MENUWORK_DrawWindow(screen->msgWindow, 0, 1, 0xb);
}

void MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(MonolithToolSlotSelect *screen)
{
    BMP_WIN_Delete(screen->msgWindow);
}

void MONOLITH_TOOL_SLOT_SELECT_ShowMessage(MonolithToolSlotSelect *screen, MonolithToolWork *work, int msgId)
{
    if (screen->msgPrinter != 0)
        GF_PANIC_Fail(PM_LANG_JA(d_021BABF4, str_ja_021BAAC8), PM_SRC_LINE(0, 0x2D8), PM_LANG_JA(d_021BABF4, str_ja_021BAAE4));
    GF_FONT_SetTextColor(1, 2, 15);
    screen->msgString = MSGDATA_AllocString((void *)work->msgBank[3], msgId);
    screen->msgPrinter = PRINTSYS_PrintStream(screen->msgWindow, 0, 0, screen->msgString, work->font, MSG_SPEED_GetWait(), (void *)work->taskList, 10, 0x61, 15);
    BG_SYS_SetPlaneVisible(5, 1);
}

int MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(MonolithToolWork *work, MonolithToolSlotSelect *screen) { return PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)work->scratchList, screen->msgPrinter); }

void MONOLITH_TOOL_SLOT_SELECT_HideMessage(MonolithToolSlotSelect *screen)
{
    void *window;
    window = BMP_WIN_GetBmp(screen->msgWindow);
    if (screen->msgPrinter == 0)
        GF_PANIC_Fail(PM_LANG_JA(d_021BABF4, str_ja_021BAAC8), PM_SRC_LINE(0, 0x2FE), PM_LANG_JA(d_021BABF4, str_ja_021BAB00));
    PRINTSYS_PrintStreamDelete(screen->msgPrinter);
    screen->msgPrinter = 0;
    STRBUF_Delete(screen->msgString);
    screen->msgString = 0;
    BG_SYS_SetPlaneVisible(5, 0);
    BMP_Clear(window, 0xff);
    BMP_WIN_TransferChars(screen->msgWindow);
    GF_FONT_SetTextColor(15, 2, 0);
}

void MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args)
{
    int i;
    MonolithCounts *counts = MONOLITH_TOOL_GetSlotIconStates(args);
    for (i = 0; i < 6; i++) {
        sptr icon;
        unsigned recordIndex = d_021BAA4C[i];
        icon = MONOLITH_TOOL_CreateSlotIcon(args->work, counts, i, (const int *)&d_021BA8A0[recordIndex], 1);
        screen->slotIcon[i] = (void *)icon;
    }
}

void MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(MonolithToolSlotSelect *screen) { int i; for(i=0;i<6;i++) MONOLITH_TOOL_DeleteSlotIcon(screen->slotIcon[i]); }

void MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args) { MonolithCounts *counts;int i;counts=MONOLITH_TOOL_GetSlotIconStates(args);for(i=0;i<6;i++)MONOLITH_TOOL_UpdateSlotIconState(screen->slotIcon[i],counts,i);}

void MONOLITH_TOOL_SLOT_SELECT_MoveCursor(MonolithToolSlotSelect *screen,int slot) { u16 pos[2];pos[0]=d_021BA8A0[slot].x;pos[1]=d_021BA8A0[slot].y;CLACT_AddActorSurfacePos(screen->cursorActor,(const struct ClactVec2 *)pos,1);}

void MONOLITH_TOOL_SLOT_SELECT_CreateButtons(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_ResetHighlights(args);
    MONOLITH_TOOL_CreateButton(args->work, &screen->button[0], 1, 1, 0x80, 0x90, 14, 0);
    if (UI_GetInputMode() == 0) {
        MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], 1, 0, 3);
    } else {
        MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], 1, 0xff, 3);
        screen->buttonHighlight = 1;
    }
    MONOLITH_TOOL_CreateButton(args->work, &screen->button[1], 1, 1, 0x80, 0x90, 15, 0);
    MONOLITH_TOOL_SetButtonVisible(&screen->button[1], 0);
}

void MONOLITH_TOOL_SLOT_SELECT_FreeButtons(MonolithToolSlotSelect *screen) { int i; for (i=0;i<2;i++) MONOLITH_TOOL_FreeButton(&screen->button[i]); }

void MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(MonolithToolProcArgs *args,MonolithToolSlotSelect *screen) { int i; MONOLITH_TOOL_UpdateHighlight(args,3); for(i=0;i<2;i++) MONOLITH_TOOL_IsButtonUploaded(args->work,&screen->button[i]); }

/*
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x24).
 */
void MONOLITH_TOOL_SLOT_SELECT_CreateCursor(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_CreateBlink(args->work, &screen->cursorBlink);
}

/*
 * Tail call to MONOLITH_TOOL_DeleteBlink with the pointer advanced by 0x24.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/MONOLITH_TOOL_DeleteBlink.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void MONOLITH_TOOL_SLOT_SELECT_FreeCursor(MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_DeleteBlink(&screen->cursorBlink);
}

/*
 * Tail call to MONOLITH_TOOL_UpdateBlink((char *)p + 0x24).
 */
void MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_UpdateBlink(&screen->cursorBlink);
}

void MONOLITH_TOOL_SLOT_SELECT_SetMode(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen, unsigned char mode)
{
    if (mode == 0) {
        MONOLITH_TOOL_SetButtonVisible(&screen->button[0], 1);
        MONOLITH_TOOL_SetButtonVisible(&screen->button[1], 0);
    } else {
        args->param->slot = 6;
        MONOLITH_TOOL_SetButtonVisible(&screen->button[0], 0);
        MONOLITH_TOOL_SetButtonVisible(&screen->button[1], 1);
    }
    screen->backMode = mode;
}


