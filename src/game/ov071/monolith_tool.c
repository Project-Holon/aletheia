/*
 * file:     monolith_tool.c
 * unit:     yes
 * function: MONOLITH_TOOL_Init, MONOLITH_TOOL_Main, MONOLITH_TOOL_Exit, MONOLITH_TOOL_InitDisplay, MONOLITH_TOOL_DeleteBg, MONOLITH_TOOL_InitBmpWin, MONOLITH_TOOL_ExitBmpWin, MONOLITH_TOOL_InitPalAnm, MONOLITH_TOOL_FreePalAnm, MONOLITH_TOOL_InitBackgrounds, MONOLITH_TOOL_FreeBackgrounds, MONOLITH_TOOL_LoadGraphics, MONOLITH_TOOL_FreeSubBgChar, MONOLITH_TOOL_InitText, MONOLITH_TOOL_FreeText, MONOLITH_TOOL_InitActors, MONOLITH_TOOL_FreeActors, MONOLITH_TOOL_LoadActorResources, MONOLITH_TOOL_FreeActorResources, MONOLITH_TOOL_VBlankTask, MONOLITH_TOOL_LoadSlotRecords, MONOLITH_TOOL_CreateButton, MONOLITH_TOOL_FreeButton, MONOLITH_TOOL_SetButtonVisible, MONOLITH_TOOL_IsButtonUploaded, MONOLITH_TOOL_HighlightButtonPulse, MONOLITH_TOOL_HighlightButtonFlash, MONOLITH_TOOL_SetButtonPulse, MONOLITH_TOOL_SetButtonFlash, MONOLITH_TOOL_ResetHighlights, MONOLITH_TOOL_GetHighlightMode, MONOLITH_TOOL_UpdateHighlight, MONOLITH_TOOL_SetHighlightMode, MONOLITH_TOOL_GetHighlightColorA, MONOLITH_TOOL_GetHighlightColorB, MONOLITH_TOOL_GetHighlightColorCount, MONOLITH_TOOL_CreateLabel, MONOLITH_TOOL_FreeLabel, MONOLITH_TOOL_UpdateLabel, MONOLITH_TOOL_GetTitleSpecies, MONOLITH_TOOL_GetSlotIconStates, MONOLITH_TOOL_CreateSlotIcon, MONOLITH_TOOL_DeleteSlotIcon, MONOLITH_TOOL_UpdateSlotIconState, MONOLITH_TOOL_CreateCursor, MONOLITH_TOOL_DeleteCursor, MONOLITH_TOOL_CreateBlink, MONOLITH_TOOL_DeleteBlink, MONOLITH_TOOL_UpdateBlink, MONOLITH_TOOL_StartBlink, MONOLITH_TOOL_IsBlinkActive, MONOLITH_TOOL_CreateActorAt, MONOLITH_TOOL_DeleteActorAt, MONOLITH_TOOL_Noop, MONOLITH_TOOL_CreateTaskMenuRes, MONOLITH_TOOL_DeleteTaskMenuRes, MONOLITH_TOOL_OpenTaskMenu, MONOLITH_TOOL_CloseTaskMenu, MONOLITH_TOOL_UpdateTaskMenu, MONOLITH_TOOL_DrawSlotCounts
 * address:  0x021B6100
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

int MONOLITH_TOOL_Init(struct Proc *ctx, int unused, MonolithToolSetup *setup)
{
    MonolithToolWork *work;

    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_ADDR, -16);
    GXx_SetMasterBrightness_((volatile u16 *)REG_DB_MASTER_BRIGHT_ADDR, -16);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u32 *)REG_DISPCNT_ADDR &= 0xFFFFE0FF;
    *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xFFFFE0FF;
    *(volatile u32 *)REG_DISPCNT_ADDR &= 0xFFFF1FFF;
    *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xFFFF1FFF;
    G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 4, 8, 0xF, 0xF);
    G2x_SetBlendAlpha_((unsigned int *)REG_DB_BLDCNT_ADDR, 4, 8, 0xF, 0xF);
    BG_SYS_SetLcdSwap(1);
    GFL_HEAP_CreateChildHeap(1, 0x61, 0x70000);
    work = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolWork), 0x61);
    MI_CpuFill8(work, 0, sizeof(MonolithToolWork));
    work->selection.selected = MONOLITH_ENTRY_NONE;
    MONOLITH_TOOL_LoadSlotRecords(work, setup);
    work->archive = ARC_TOOL_CreateHandle(0x27, 0x61);
    MONOLITH_TOOL_InitDisplay();
    MONOLITH_TOOL_InitBmpWin();
    MONOLITH_TOOL_InitPalAnm(work);
    MONOLITH_TOOL_InitBackgrounds();
    MONOLITH_TOOL_LoadGraphics(work, work);
    MONOLITH_TOOL_InitText(work);
    MONOLITH_TOOL_InitActors(work);
    MONOLITH_TOOL_LoadActorResources(work);
    work->entryTable = (struct MonolithEntry *)GPOWER_LoadPowerTable(0x61);
    work->topProcSys = PROCSYS_Create(0x61);
    work->subProcSys = PROCSYS_Create(0x61);
    PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)work->scratchList, 6);
    work->vblankTask = GFL_USE_AddMainTask(MONOLITH_TOOL_VBlankTask, (void *)work, (unsigned int)0xA);
    GFL_NET_RefreshWmIconAtTopRight(0, 0x61);
    work->procArgs.setup = setup;
    work->procArgs.work = work;
    work->procArgs.param = &work->selection;
    return 1;
}

int MONOLITH_TOOL_Main(int a, int *seq, void **pwk, MonolithToolWork *work)
{
    void *h;
    u8 *r;
    int s1;
    int s2;
    u8 k;

    h = (void *)GAMESYSTEM_GetGameComm(*pwk);
    r = (u8 *)INTRUDE_COMM_GetWorkIfRunning(h);
    switch (*seq) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 1:
        if (r == 0 || GFL_NET_ERR_GetErrorLevel() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyBegin() == 1)
            (*seq)++;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1)
            (*seq)++;
        break;
    case 3:
        if (GFL_NET_ERR_GetErrorLevel() != 0 || (r == 0 && GAME_COMM_GetCounter(h) != 0) || (r == 0 && GAME_COMM_GetKind(h) == 2))
            work->procArgs.abortRequested = 1;
        if (work->procArgs.abortRequested == 0) {
            if (work->topProcStarted == 0) {
                PROCSYS_Push(work->topProcSys, -1, d_021BA774[work->currentScreen].topProc, (void *)&work->procArgs);
                work->topProcStarted = 1;
            }
            if (work->subProcStarted == 0) {
                GF_FONT_SetTextColor(0xF, 2, 0);
                PROCSYS_Push(work->subProcSys, -1, d_021BA774[work->currentScreen].subProc, (void *)&work->procArgs);
                work->subProcStarted = 1;
            }
        }
        s2 = PROCSYS_Main((void *)work->subProcSys);
        k = work->procArgs.requestedScreen;
        if (k == 4 || (s2 != 1 && work->procArgs.abortRequested == 1)) {
            work->procArgs.topProcDone = 1;
        } else if (work->currentScreen != k && d_021BA774[work->currentScreen].topProc != d_021BA774[k].topProc) {
            work->procArgs.topProcDone = 1;
        }
        s1 = PROCSYS_Main((void *)work->topProcSys);
        if (s1 == 1 && s2 == 1)
            break;
        if (work->procArgs.abortRequested == 1 || work->procArgs.requestedScreen == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            work->currentScreen = work->procArgs.requestedScreen;
            if (s1 != 1) {
                work->topProcStarted = 0;
                work->procArgs.topProcDone = 0;
            }
            if (s2 != 1)
                work->subProcStarted = 0;
        }
        break;
    case 4:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || GFL_NET_ERR_GetErrorLevel() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyEnd() == 1)
            (*seq)++;
        break;
    case 6:
        if (WIPE_SYS_EndCheck() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    TCBL_Main((struct TcblSystem *)work->taskList);
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printSys);
    CLACT_DrawSystem();
    return 0;
}

/*
 * Byte-correct. Blocker: GPOWER_FreePowerTable (arm9 unlabelled tail-call stub,
 * the integrator's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: GFL_HEAP_Free 0x020307B0 arm):
 *   void GPOWER_FreePowerTable(void *p) { void GFL_HEAP_Free(void *); GFL_HEAP_Free(p); }
 */
int MONOLITH_TOOL_Exit(struct Proc *a, int b, int c, MonolithToolWork *work)
{

    PROCSYS_Delete(work->topProcSys);
    PROCSYS_Delete(work->subProcSys);
    TCB_DeleteTask(work->vblankTask);
    GPOWER_FreePowerTable((struct GPowerData *)work->entryTable);
    MONOLITH_TOOL_FreeActorResources(work);
    MONOLITH_TOOL_FreeActors(work);
    MONOLITH_TOOL_FreeText(work);
    MONOLITH_TOOL_FreeSubBgChar(work);
    MONOLITH_TOOL_FreeBackgrounds();
    MONOLITH_TOOL_FreePalAnm(work);
    MONOLITH_TOOL_ExitBmpWin();
    MONOLITH_TOOL_DeleteBg();
    ARC_TOOL_DeleteHandle(work->archive);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    PROCSYS_FreeProcWork((struct Proc *)a);
    GFL_HEAP_DeleteChecked(0x61);
    return 1;
}

void MONOLITH_TOOL_InitDisplay(void)
{

    BG_SYS_SetVramBanks((const struct DispVram *)(&d_021BA7D4));
    BG_SYS_Create(0x61);
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d_021BA764));
    MIi_CpuClear32(0, (void *)(HW_BG_VRAM), 0x80000);
    MIi_CpuClear32(0, (void *)(HW_DB_BG_VRAM), 0x20000);
    MIi_CpuClear32(0, (void *)(HW_OBJ_VRAM), 0x40000);
    MIi_CpuClear32(0, (void *)(HW_DB_OBJ_VRAM), 0x20000);
}

/*
 * Three ARM9 thunks that share a literal-pool tail-call shape.
 */
void MONOLITH_TOOL_DeleteBg(void)
{
    BG_SYS_Delete();
}

void MONOLITH_TOOL_InitBmpWin(void)
{
    BMP_WIN_Init(0x61);
}

void MONOLITH_TOOL_ExitBmpWin(void)
{
    BMP_WIN_Exit();
}

unsigned int MONOLITH_TOOL_InitPalAnm(MonolithToolWork *work)
{
    work->palAnm = PALANM_Create(0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 2, 0x1c0, 0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 3, 0x1c0, 0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 0, 0x1c0, 0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 1, 0x1c0, 0x61);
    PALANM_SetAutoTransfer(work->palAnm, 1);
#ifndef __MWERKS__
    return 0; /* the DS code returns whatever r0 holds after the call */
#endif
}

void MONOLITH_TOOL_FreePalAnm(MonolithToolWork *work)
{
    PALANM_FreeSlotBuffers(work->palAnm, 2);
    PALANM_FreeSlotBuffers(work->palAnm, 3);
    PALANM_FreeSlotBuffers(work->palAnm, 0);
    PALANM_FreeSlotBuffers(work->palAnm, 1);
    PALANM_Delete(work->palAnm);
}

void MONOLITH_TOOL_InitBackgrounds(void)
{
    int i;

    BG_SYS_InitBgLayer((int)3, (const struct BgTemplate *)(&d_021BA794), (int)0);
    BG_SYS_InitBgLayer((int)7, (const struct BgTemplate *)(&d_021BA7B4), (int)0);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(7, 0, 0, 0, 0x20, 0x20, 0x11);
    for (i = 0; i <= 7; i++) {
        BG_SYS_SetPlaneVisible((u8)i, (int)0);
    }
    BG_SYS_SetPlaneVisible((u8)3, (int)1);
    BG_SYS_SetPlaneVisible((u8)7, (int)1);
}

void MONOLITH_TOOL_FreeBackgrounds(void)
{
    BG_SYS_SetPlaneVisible(3, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(7);
}

void MONOLITH_TOOL_LoadGraphics(MonolithToolWork *work, MonolithToolWork *work2)
{
    void *h;

    PALANM_LoadHandlePaletteToSlotAt(work2->palAnm, work2->archive, 0x10, 0x61, 0, 0x1c0, 0, 0);
    PALANM_LoadHandlePaletteToSlotAt(work2->palAnm, work2->archive, 0x11, 0x61, 1, 0x1c0, 0, 0);
    ARC_UTIL_UploadBgCharFromHandle(work2->archive, 0xf, 3, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgPaletteFromHandle(work2->archive, 0xa, 3, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgCharFromHandle(work2->archive, 0xe, 7, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgPaletteFromHandle(work2->archive, 4, 7, 0, 0, 1, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work2->palAnm, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    PALANM_LoadArcPaletteToSlotAt(work2->palAnm, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = ARC_TOOL_CreateHandle(0x53, 0x61);
    work->subBgCharOffset = BG_SYS_CreateRun(7, 0x80, 1);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x1c, 7, work->subBgCharOffset, 0x80, 0, 0x61);
    APP_ICON_LoadTouchBar(h, 7, 0x61, work->subBgCharOffset, 0xc);
    PALANM_LoadHandlePaletteToSlot(work2->palAnm, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(7);
    BG_SYS_PushTile(3);
    BG_SYS_PushTile(7);
}

void MONOLITH_TOOL_FreeSubBgChar(MonolithToolWork *work)
{
    BG_SYS_FreeTileRun(7, work->subBgCharOffset, 0x80);
}

void MONOLITH_TOOL_InitText(MonolithToolWork *work)
{
    GF_FONT_SetTextColor(0xf, 2, 0);
    work->taskList = (struct Tcbl *)TCBL_Create(0x61, 0x61, 4, 0x20);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x61);
    work->printSys = (struct PrintSys *)PRINTSYS_QUE_Create((unsigned int)0x61);
    work->wordSet = WORDSET_CreateDefault(0x61);
    work->msgBank[0] = MSGDATA_CreateFromArchive(0, 2, 0x43, 0x61);
    work->msgBank[1] = MSGDATA_CreateFromArchive(0, 2, 0xa0, 0x61);
    work->msgBank[2] = MSGDATA_CreateFromArchive(0, 2, 0xa1, 0x61);
    work->msgBank[3] = MSGDATA_CreateFromArchive(0, 2, 0x45, 0x61);
}

void MONOLITH_TOOL_FreeText(MonolithToolWork *work)
{
    MSGDATA_Delete(work->msgBank[0]);
    MSGDATA_Delete(work->msgBank[1]);
    MSGDATA_Delete(work->msgBank[2]);
    MSGDATA_Delete(work->msgBank[3]);
    WORDSET_Delete(work->wordSet);
    PRINTSYS_QUE_Clear((struct PrintQueue *)work->printSys);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printSys);
    GF_FONT_Delete(work->font);
    TCBL_Destroy((struct TcblSystem *)work->taskList);
}

void MONOLITH_TOOL_InitActors(MonolithToolWork *work)
{
    struct SysInit s;

    s = gClActorInitParam;
    s.oam_main_base = 4;
    s.oam_main_count = 0x7c;
    s.oam_sub_base = 4;
    s.oam_sub_count = 0x7c;
    s.n_chars = 0x60;
    s.n_cells = 0x40;
    CLACT_InitSystem((struct ClactSysInit *)(&s), (struct DispVramCfg *)((&d_021BA7D4)), 0x61);
    work->unitBank = (struct Bank *)CLACT_CreateUnit(0x60, 0, 0x61);
    CLACT_SetUnitDefaultRenderer((struct Unit *)work->unitBank);
    work->actorTool = (unsigned char *)ACTOR_TOOL_Create(0x61, 0x10, 0x10);
    work->actorToolUnit = BMP_OAM_CreateSys(0x61, work->unitBank);
}

/*
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 */
void MONOLITH_TOOL_FreeActors(MonolithToolWork *work)
{
    BG_SYS_SetMainPlaneVisible(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    BMP_OAM_DeleteSys(work->actorToolUnit);
    CLACT_DeleteUnit((struct Unit *)work->unitBank);
    CLACT_ExitSystem();
    ACTOR_TOOL_Delete((struct ActorTool *)work->actorTool);
}

void MONOLITH_TOOL_LoadActorResources(MonolithToolWork *work)
{
    void *tmp;
    int i;
    int flag;

    tmp = ARC_TOOL_CreateHandle(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        work->actorRes[i].charPalAnm = ACTOR_TOOL_LoadCharPalAnm((void *)work->palAnm, (struct ActorTool *)work->actorTool, work->archive, 3, flag, 3, 0x61);
        work->actorRes[i].cellRes = CLACT_RegisterCharacter(work->archive, 0, 1, flag, 0x61);
        work->actorRes[i].animRes = CLACT_RegisterCellAnim(work->archive, 1, 2, 0x61);
        work->actorRes[i].simplePalAnm = ACTOR_TOOL_LoadCharSimplePalAnm((void *)work->palAnm, (struct ActorTool *)work->actorTool, tmp, 5, flag, 1, 0x61);
    }
    ARC_TOOL_DeleteHandle(tmp);
}

/*
 * extent: two-byte alignment padding at 0x021B699A.
 * Enum counter preserves the first iteration's cmp/branch.
 */
void MONOLITH_TOOL_FreeActorResources(MonolithToolWork *work)
{
    MonolithToolSlot i;
    int flag;

    i = SLOT_FIRST;
    do {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        ACTOR_TOOL_FreeChar((struct ActorTool *)work->actorTool, work->actorRes[i].charPalAnm, flag);
        CLACT_ReleaseCharacter(work->actorRes[i].cellRes);
        CLACT_ReleaseCellAnim(work->actorRes[i].animRes);
        ACTOR_TOOL_FreeChar((struct ActorTool *)work->actorTool, work->actorRes[i].simplePalAnm, flag);
        i++;
    } while (i < SLOT_COUNT);
}

void MONOLITH_TOOL_VBlankTask(struct TcbTask *unused, void *workArg)
{
    MonolithToolWork *work = workArg;
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(work->palAnm);
}

void MONOLITH_TOOL_LoadSlotRecords(MonolithToolWork *work, MonolithToolSetup *setup)
{
    MonolithToolSlotRecord *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (setup->useSlotRecords != 0) {
        tbl = ARC_TOOL_LoadMember(0x25, 0, 0x61);
        n = ARC_TOOL_GetMemberSize(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = setup->slotIndex[i];
            if (idx >= n) {
                idx = 0;
            }
            work->slotRecord[i] = tbl[idx];
        }
        GFL_HEAP_Free(tbl);
    }
}

/*
 * The 0/1 flag keeps its bne-to-one polarity only as an enum ternary
 * (a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md);
 * `case 2:` shares its arm with `default:` (the dead `cmp r6, #2; b`).
 */
void MONOLITH_TOOL_CreateButton(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet)
{
    struct MonolithToolActorPos pos = d_021BA80C;
    struct MonolithToolGridParam param = d_021BA814;
    u32 widthTiles;
    void *bitmap;
    void *text;
    void *expanded;
    int onSubScreen;

    switch (sizeClass) {
    case 0:
        widthTiles = 0x16;
        pos.animSeq = 0;
        param.x = x - 0x58;
        break;
    case 1:
        widthTiles = 0x12;
        pos.animSeq = 1;
        param.x = x - 0x48;
        break;
    case 2:
    default:
        widthTiles = 0xc;
        pos.animSeq = 8;
        param.x = x - 0x30;
        break;
    }
    bitmap = BMP_Create(widthTiles, 2, 0x20, 0x61);
    button->bitmap = bitmap;
    pos.x = x;
    pos.y = y;
    param.y = y - 8;
    param.bitmap = bitmap;
    param.palette = work->actorRes[resIndex].simplePalAnm;
    onSubScreen = resIndex == 0 ? B_FALSE : B_TRUE;
    param.subScreenB = onSubScreen;
    param.subScreenA = onSubScreen;
    button->actor = CLACT_CreateActor((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, (struct ActorInitParam *)(&pos), onSubScreen, 0x61);
    button->grid = BMP_OAM_Create(work->actorToolUnit, (struct BmpOamParam *)(&param));
    text = MSGDATA_AllocString(work->msgBank[3], msgId);
    if (wordSet) {
        expanded = STRBUF_Create(0x80, 0x61);
        WORDSET_CopyTaggedText(wordSet, expanded, text);
        PRINTSYS_PrintQue((struct PrintQueue *)work->printSys, button->bitmap, 0, 0, expanded, work->font);
        STRBUF_Delete(expanded);
    } else {
        PRINTSYS_PrintQue((struct PrintQueue *)work->printSys, button->bitmap, 0, 0, text, work->font);
    }
    STRBUF_Delete(text);
    button->on = 1;
}

void MONOLITH_TOOL_FreeButton(MonolithToolButton *button)
{
    CLACT_DeleteActor(button->actor);
    BMP_OAM_Delete(button->grid);
    BMP_Delete(button->bitmap);
    button->actor = 0;
    button->grid = 0;
    button->bitmap = 0;
}

/*
 * extent: two-byte alignment padding at 0x021B6B6E.
 */
void MONOLITH_TOOL_SetButtonVisible(MonolithToolButton *button, int visible)
{
    CLACT_SetActorDrawEnable(button->actor, visible);
    BMP_OAM_SetEnabled(button->grid, visible);
}

int MONOLITH_TOOL_IsButtonUploaded(MonolithToolWork *work, MonolithToolButton *button)
{
    if (button->on == 1) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, button->bitmap) == 0) {
            BMP_OAM_UploadChars(button->grid);
            button->on = 0;
            return 1;
        }
    }
    return 0;
}

void MONOLITH_TOOL_HighlightButtonPulse(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == selected) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)button[i].actor, 1, 1);
            MONOLITH_TOOL_SetHighlightMode(args, 1, slot);
        } else {
            CLACT_SetActorPaletteOffset((struct ClactActor *)button[i].actor, 0, 1);
        }
    }
    if (selected == 0xff) {
        MONOLITH_TOOL_SetHighlightMode(args, 0, slot);
    }
}

void MONOLITH_TOOL_HighlightButtonFlash(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == selected) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)button[i].actor, 1, 1);
            MONOLITH_TOOL_SetHighlightMode(args, 2, slot);
        } else {
            CLACT_SetActorPaletteOffset((struct ClactActor *)button[i].actor, 0, 1);
        }
    }
}

void MONOLITH_TOOL_SetButtonPulse(MonolithToolProcArgs *args, int pulse, int slot)
{
    if (pulse == 1) {
        MONOLITH_TOOL_SetHighlightMode(args, 1, slot);
    } else {
        MONOLITH_TOOL_SetHighlightMode(args, 0, slot);
    }
}

void MONOLITH_TOOL_SetButtonFlash(MonolithToolProcArgs *args, int slot)
{
    MONOLITH_TOOL_SetHighlightMode(args, 2, slot);
}

void MONOLITH_TOOL_ResetHighlights(MonolithToolProcArgs *args) { int i; for(i=0;i<4;i++) MI_CpuFill8(&args->highlight[i],0,8); }

u8 MONOLITH_TOOL_GetHighlightMode(MonolithToolProcArgs *args, int slot)
{
    return args->highlight[slot].mode;
}

/*
 * sites to PALANM_GetColor stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } MonolithToolSlot;
 *   u16 PALANM_GetColor(MonolithToolSlot *s, int idx, int which, u16 pos)
 *   {
 *       if (which == 1) {
 *           return s[idx].a[pos];
 *       }
 *       if (which == 0) {
 *           return s[idx].b[pos];
 *       }
 *       return 0;
 *   }
 *
 * note 2026-10-05 (D8 lane16): witness PALANM_GetColor filed as src/matched/arm9/PALANM_GetColor.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
 */
void MONOLITH_TOOL_UpdateHighlight(MonolithToolProcArgs *args, int slot)
{
    MonolithToolHighlight *highlight;
    int firstColor, srcColor, colorCount;
    int i;
    int level;
    highlight = &args->highlight[slot];
    if (slot >= 4) {
        GF_PANIC_Fail(PM_LANG_JA(d_021BABE0, str_ja_021BAAA0), PM_SRC_LINE((int)0, 0x193), PM_LANG_JA(d_021BABE0, str_ja_021BAAB0));
    }
    firstColor = MONOLITH_TOOL_GetHighlightColorA((int)slot);
    srcColor = MONOLITH_TOOL_GetHighlightColorB((int)slot);
    colorCount = MONOLITH_TOOL_GetHighlightColorCount(slot);
    switch (highlight->mode) {
    case 1:
        level = highlight->level;
        if (highlight->fadeDown == 0) {
            level += 0x80;
            if (level >= 0x1100) {
                level = 0x1000;
                highlight->fadeDown ^= 1;
            }
        } else {
            level -= 0x80;
            if (level <= 0) {
                level = 0x100;
                highlight->fadeDown ^= 1;
            }
        }
        highlight->level = level;
        for (i = 0; i < colorCount; i++) {
            PALANM_BlendChannel(args->work->palAnm, (int)slot, (u16)(firstColor + i), (u16)1, level >> 8,
                          PALANM_GetColor((struct PaletteFadeWork *)args->work->palAnm, slot, 1, srcColor + i));
        }
        break;
    case 2:
        if (highlight->timer == 0) {
            highlight->timer = 3;
            if (highlight->level == 0) {
                highlight->level = 0x1000;
            } else {
                highlight->level = 0;
                highlight->flashCount++;
                if (highlight->flashCount > 1) {
                    MONOLITH_TOOL_SetHighlightMode(args, 0, slot);
                }
            }
            for (i = 0; i < colorCount; i++) {
                PALANM_BlendChannel(args->work->palAnm, (int)slot, (u16)(firstColor + i), (u16)1, highlight->level >> 8,
                              PALANM_GetColor((struct PaletteFadeWork *)args->work->palAnm, slot, 1, srcColor + i));
            }
        } else {
            highlight->timer--;
        }
        break;
    }
}

void MONOLITH_TOOL_SetHighlightMode(MonolithToolProcArgs *args, int mode, int slot)
{
    MonolithToolHighlight *highlight;
    highlight = &args->highlight[slot];
    MI_CpuFill8(highlight, 0, 8);
    highlight->mode = mode;
    PALANM_BlendChannel(args->work->palAnm, (int)slot, (u16)MONOLITH_TOOL_GetHighlightColorA(slot), (u16)MONOLITH_TOOL_GetHighlightColorCount(slot), 0, 0);
}

/*
 * Two bounded constant selectors and a constant return.
 */
int MONOLITH_TOOL_GetHighlightColorA(unsigned int x)
{
    return x <= 1 ? 0x32 : 0x12;
}

int MONOLITH_TOOL_GetHighlightColorB(unsigned int x)
{
    return x <= 1 ? 0x42 : 0x22;
}

int MONOLITH_TOOL_GetHighlightColorCount(int slot)
{
    return 3;
}

/*
 * The 0/1 flag is written in each if/else arm (param.f14 and param.f12 stores), so the
 * param address stays in r0 across the diamond and tail merging rebuilds the join. Callee
 * types from matched definitions (02043678 returns Bmp *, 020255A0 Grid *, 02045EC0 void *,
 * 020457B0 U16Vec *). Twin ov071 021B6A0C. final push 2026-10-05 G7L5.
 */
void MONOLITH_TOOL_CreateLabel(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet)
{
    struct MonolithToolGridParam param = d_021BA82C;
    void *bitmap;
    void *text;
    void *expanded;
    bitmap = BMP_Create(widthTiles, heightTiles, 0x20, 0x61);
    label->bitmap = bitmap;
    param.x = x - (widthTiles / 2) * 8;
    param.y = y - (heightTiles / 2) * 8;
    param.bitmap = bitmap;
    param.palette = work->actorRes[resIndex].simplePalAnm;
    if (resIndex == 0) {
        param.subScreenB = 0;
        param.subScreenA = 0;
    } else {
        param.subScreenB = 1;
        param.subScreenA = 1;
    }
    label->grid = BMP_OAM_Create(work->actorToolUnit, (struct BmpOamParam *)(&param));
    text = MSGDATA_AllocString(work->msgBank[3], msgId);
    if (wordSet) {
        expanded = STRBUF_Create(0x80, 0x61);
        WORDSET_CopyTaggedText(wordSet, expanded, text);
        PRINTSYS_PrintQue((struct PrintQueue *)work->printSys, label->bitmap, 0, 0, expanded, work->font);
        STRBUF_Delete(expanded);
    } else {
        PRINTSYS_PrintQue((struct PrintQueue *)work->printSys, label->bitmap, 0, 0, text, work->font);
    }
    STRBUF_Delete(text);
    label->on = 1;
}

void MONOLITH_TOOL_FreeLabel(MonolithToolLabel *label) { BMP_OAM_Delete(label->grid); BMP_Delete(label->bitmap); label->grid = 0; label->bitmap = 0; }

int MONOLITH_TOOL_UpdateLabel(MonolithToolWork *work, MonolithToolLabel *label) { if(label->on==1) { if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printSys, label->bitmap)==0) { BMP_OAM_UploadChars(label->grid); label->on=0; return 1; } } return 0; }

void *MONOLITH_TOOL_GetTitleSpecies(MonolithToolProcArgs *args)
{
    MonolithToolSetup *setup = args->setup;
    return (void *)GAME_DATA_GetMyStatusByNetId(GAMESYSTEM_GetGameData((const struct GameSystem *)setup->gameCtx), setup->areaId);
}

MonolithCounts *MONOLITH_TOOL_GetSlotIconStates(MonolithToolProcArgs *args)
{
    MonolithToolSetup *setup = args->setup;
    return (void *)GAME_DATA_GetBattleRecSlotByNetId(GAMESYSTEM_GetGameData((const struct GameSystem *)setup->gameCtx), setup->areaId);
}

/*
 * The flag is a u16 local assigned from a ternary over enum constants: every
 * int-constant spelling (ternary, if/else, e != 0) is folded to a boolean and
 * comes out with the opposite branch polarity (beq to 0, not bne to 1).
 * const on d lets both d[] loads go ahead of the stores into s.
 */
int MONOLITH_TOOL_CreateSlotIcon(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex)
{
    struct MonolithToolIconPos iconPos;
    sptr actor;
    u16 onSubScreen;
    u8 *states;
    iconPos = d_021BA844;
    onSubScreen = resIndex == 0 ? B_FALSE : B_TRUE;
    iconPos.x = pos[0];
    iconPos.y = pos[1];
    states = counts->slotIconState;
    if (states[slot] == 1) {
        iconPos.animSeq = 5;
    }
    actor = (sptr)CLACT_CreateActor((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, (struct ActorInitParam *)(&iconPos), onSubScreen, 0x61);
    if (states[slot] == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)actor, 0);
    }
    CLACT_SetActorAutoAnim((struct ClactActor *)actor, 1);
    return actor;
}

/*
 * Tail call to CLACT_DeleteActor.
 */
void MONOLITH_TOOL_DeleteSlotIcon(void *p)
{
    CLACT_DeleteActor(p);
}

void MONOLITH_TOOL_UpdateSlotIconState(void *p, MonolithCounts *counts, int i) { Value v; if(counts->slotIconState[i]==1) v=V5; else if(counts->slotIconState[i]==2) v=V4; else {CLACT_SetActorDrawEnable(p,0);return;} CLACT_SetActorDrawEnable(p,1);CLACT_ChangeActorAnimSeq(p,v); }

struct ClactActor *MONOLITH_TOOL_CreateCursor(MonolithToolWork *work, const int *pos, int resIndex)
{
    struct MonolithToolCursorPos cursorPos;
    int onSubScreen;
    cursorPos = d_021BA854;
    onSubScreen = 0;
    if (resIndex != 0)
        onSubScreen = 1;
    cursorPos.x = pos[0];
    cursorPos.y = pos[1];
    return CLACT_CreateActor((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, (const struct ActorInitParam *)&cursorPos, (u16)onSubScreen, 0x61);
}

void MONOLITH_TOOL_DeleteCursor(void *p)
{
    CLACT_DeleteActor(p);
}

void MONOLITH_TOOL_CreateBlink(MonolithToolWork *work, MonolithToolBlink *blink)
{
    struct MonolithToolCursorPos cursorPos;
    struct ClactActor *actor;
    cursorPos = d_021BA84C;
    actor = CLACT_CreateActor((void *)work->unitBank, work->actorRes[1].cellRes, work->actorRes[1].charPalAnm, work->actorRes[1].animRes, (const struct ActorInitParam *)&cursorPos, 1, 0x61);
    CLACT_SetActorAutoAnim((struct ClactActor *)actor, 1);
    blink->actor = actor;
}

/*
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * CLACT_DeleteActor with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 */
void MONOLITH_TOOL_DeleteBlink(MonolithToolBlink *blink)
{
    CLACT_DeleteActor((void *)blink->actor);
}

void MONOLITH_TOOL_UpdateBlink(MonolithToolBlink *p)
{
    if (p->active == 1) {
        if (p->frame % 5 == 0) {
            CLACT_SetActorPaletteOffset(p->actor, p->phase, 1);
            p->phase ^= 1;
            if (p->frame / 5 == 3)
                p->active = 0;
        }
        p->frame++;
    }
}

/*
 * Byte initialiser and its getter.
 */
void MONOLITH_TOOL_StartBlink(MonolithToolBlink *blink)
{
    blink->active = 1;
    blink->frame = 0;
    blink->phase = 1;
}

int MONOLITH_TOOL_IsBlinkActive(MonolithToolBlink *blink)
{
    return blink->active;
}

struct Actor *MONOLITH_TOOL_CreateActorAt(MonolithToolWork *work, int x, int y, int animSeq)
{
    struct MonolithToolCursorPos cursorPos;
    struct Actor *actor;
    cursorPos = d_021BA804;
    cursorPos.x = x;
    cursorPos.y = y;
    cursorPos.animSeq = animSeq;
    actor = (struct Actor *)CLACT_CreateActor((void *)work->unitBank, work->actorRes[1].cellRes, work->actorRes[1].charPalAnm, work->actorRes[1].animRes, (struct ActorInitParam *)(&cursorPos), 1, 0x61);
    CLACT_SetActorAutoAnim((struct ClactActor *)actor, 1);
    return actor;
}

/*
 * ARM9 tail call followed by an empty function.
 */
void MONOLITH_TOOL_DeleteActorAt(void *p)
{
    CLACT_DeleteActor(p);
}

void MONOLITH_TOOL_Noop(void *a)
{
}

struct TaskMenuRes *MONOLITH_TOOL_CreateTaskMenuRes(MonolithToolWork *p, int a, u16 heap)
{
    return APP_TASKMENU_RES_Create((u8)a, 14, (struct GFont *)p->font, (struct PrintQueue *)p->printSys, heap);
}

/*
 * Tail call to APP_TASKMENU_RES_Delete.
 */
void MONOLITH_TOOL_DeleteTaskMenuRes(void *p)
{
    APP_TASKMENU_RES_Delete(p);
}

void *MONOLITH_TOOL_OpenTaskMenu(MonolithToolWork *work, void *res, u32 heap)
{
    MonolithToolItem it[2];
    struct MonolithToolTaskMenuTmpl t;
    void *menu;

    it[0].text = MSGDATA_AllocString(work->msgBank[3], 0x1e);
    it[1].text = MSGDATA_AllocString(work->msgBank[3], 0x1f);
    it[0].color = 0x39E0;
    it[1].color = 0x39E0;
    it[0].flags = 0;
    it[1].flags = 0;
    t.heapId = heap;
    t.itemNum = 2;
    t.items = it;
    t.posType = 0;
    t.charPosX = 0x18;
    t.charPosY = 0xc;
    t.width = 8;
    t.height = 3;
    menu = APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&t), res);
    STRBUF_Delete(it[0].text);
    STRBUF_Delete(it[1].text);
    return menu;
}

/*
 * Tail call to APP_TASKMENU_CloseMenu.
 */
void MONOLITH_TOOL_CloseTaskMenu(void *menu)
{
    APP_TASKMENU_CloseMenu(menu);
}

int MONOLITH_TOOL_UpdateTaskMenu(MonolithToolWork *work, int unused, void *menu, int *outConfirmed) { APP_TASKMENU_UpdateMenu(menu); if(APP_TASKMENU_IsFinish(menu)==1) { *outConfirmed=APP_TASKMENU_GetCursorPos(menu)==0 ? 1 : 0;return 1;} return 0; }

void MONOLITH_TOOL_DrawSlotCounts(void *a, int flag, int bg)
{
    MonolithCounts *c;
    u16 *buf;
    int y;
    int n, m;
    int left, right;
    int i;

    c = MONOLITH_TOOL_GetSlotIconStates((MonolithToolProcArgs *)a);
    y = 0x14;
    if (flag) {
        y = 0xe;
    }
    n = c->current;
    m = c->limit;
    if (n == m) {
        left = 0x78;
        right = 0x78;
    } else {
        left = n * 0xf0 / (n + m);
        if (m > 0) {
            right = 0xf0 - left;
        } else {
            right = 0;
            left = 0xf0;
        }
    }
    if (n > 0 && left == 0) {
        right--;
    } else if (m > 0 && right == 0) {
        right++;
    }
    buf = GFL_HEAP_Alloc(0x61, 0x3c, 1, PM_LANG_JA(d_021BABE4, str_ja_021BAAA0), 0x474);
    for (i = 0; right > 0; i++) {
        if (right >= 8) {
            buf[i] = 1;
            right -= 8;
        } else {
            buf[i] = 9 - right;
            right = 0;
        }
    }
    for (; i < 30; i++) {
        buf[i] = 9;
    }
    for (i = 0; i < 30; i++) {
        buf[i] |= 0x1000;
    }
    BG_SYS_DrawTile((u8)bg, buf, (u8)1, (u8)y, 30, 1);
    GFL_HEAP_Free(buf);
}


#pragma opt_lifetimes off

#pragma opt_common_subs off


#pragma opt_lifetimes reset

#pragma opt_common_subs reset


