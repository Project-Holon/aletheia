/*
 * file:     ctvt_call.c
 * unit:     yes
 * function: CTVT_CALL_Create, CTVT_CALL_Free, CTVT_CALL_Init, CTVT_CALL_Exit, CTVT_CALL_Update, CTVT_CALL_HandleTouch, CTVT_CALL_RefreshPeers, CTVT_CALL_UpdateRows, CTVT_CALL_DrawRow, CTVT_CALL_PlaceCursor, CTVT_CALL_UpdatePrompt, CTVT_CALL_UpdateTimeWindow, CTVT_CALL_CheckJoinRequest, CTVT_CALL_PrintMessage, CTVT_CALL_PrintTimeMessage, CTVT_CALL_WorkInit, CTVT_CALL_WorkDelete, CTVT_CALL_WorkMain, CTVT_CALL_VBlank, CTVT_CALL_InitDisplay, CTVT_CALL_ExitDisplay, CTVT_CALL_InitBgLayer, CTVT_CALL_InitGraphics, CTVT_CALL_ReleaseGraphics, CTVT_CALL_InitText, CTVT_CALL_DeleteText, CTVT_CALL_SwitchScreen, CTVT_CALL_UpdateMemberWindows, CTVT_CALL_DrawMemberName
 * address:  0x021BBA6C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   G2_GetBG3ScrPtr 0x0207E100 arm
 *   APP_ENV_HasParentalControlBits 0x0202EB14 thumb
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   CTVT_COMM_IsSlotActive 0x021B8BA4 thumb ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   COMM_TVT_SYS_GetLaunchParams 0x021BE004 thumb ov172
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   COMM_TVT_SYS_GetResId 0x021BE018 thumb ov172
 *   COMM_TVT_SYS_GetClactUnit 0x021BE024 thumb ov172
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   COMM_TVT_SYS_GetReturnedFromChild 0x021BE02C thumb ov172
 *   COMM_TVT_SYS_SetReturnedFromChild 0x021BE030 thumb ov172
 *   COMM_TVT_SYS_GetPrintQue 0x021BE044 thumb ov172
 *   COMM_TVT_SYS_CreateTimeIcon 0x021BE318 thumb ov172
 *   COMM_TVT_SYS_DeleteTimeIcon 0x021BE34C thumb ov172
 *   CTVT_CAMVIEW_IsShutterIdle 0x021B7590 thumb ov172
 *   CTVT_CAMVIEW_StopCapture 0x021B7578 thumb ov172
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   COMM_TVT_SYS_GetFont 0x021BE034 thumb ov172
 *   COMM_TVT_SYS_GetMsgData 0x021BE03C thumb ov172
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   CTVT_CAMVIEW_RequestShutterSound1  0x021B7B80  thumb  ov172
 *   CTVT_COMM_StopSession  0x021B8084  thumb  ov172
 *   FX_SinCosTable_     0x020A1B38  data a2
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   g_021C7234    0x021C7234  data  ov172
 *   d_021C7234     0x021C7234  data
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   CTVT_CAMVIEW_RequestShutterSound0  0x021B7B64  thumb  ov172
 *   CTVT_COMM_SetRequestedMode  0x021B80DC  thumb  ov172
 *   CTVT_COMM_SetConnectMac  0x021B80EC  thumb  ov172
 *   CTVT_COMM_GetMyStatusPtr  0x021B8B7C  thumb  ov172
 *   CTVT_COMM_ResetSlotTimer  0x021B8C14  thumb  ov172
 *   CTVT_COMM_IsSlotTimerDone  0x021B8C20  thumb  ov172
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   d_021C7040     0x021C7040  data
 *   CTVT_COMM_IsNetReady  0x021B8108  thumb  ov172
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   NET_WHPIPE_GetEntryBeaconKind  0x02177B80  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   CTVT_COMM_FindPeerName  0x021B85D0  thumb  ov172
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   COMM_PLAYER_SUPPORT_GetRecordField  0x0202E938  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIFILIST_FindFriendByStatusAndOutfit  0x02009D50  thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   CTVT_CAMVIEW_Create 0x021B6EE0 thumb ov172
 *   CTVT_COMM_Create 0x021B7BA8 thumb ov172
 *   CTVT_TALK_Create 0x021B8C3C thumb ov172
 *   DRAW_SYSTEM_CreateCanvas 0x021B6BE0 thumb ov172
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_StopRingtone 0x02028A70 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   DRAW_SYSTEM_DeleteCanvas 0x021B6C34 thumb ov172
 *   CTVT_TALK_Delete 0x021B8CB0 thumb ov172
 *   CTVT_COMM_Delete 0x021B7DCC thumb ov172
 *   CTVT_CAMVIEW_Delete 0x021B70A8 thumb ov172
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   CTVT_COMM_Main  0x021B7E34  thumb  ov172
 *   CTVT_TALK_Main  0x021B9044  thumb  ov172
 *   CTVT_COMM_IsSessionEnded  0x021B80CC  thumb
 *   DRAW_SYSTEM_Nop  0x021B6C48  thumb  ov172
 *   CTVT_CAMVIEW_Update  0x021B712C  thumb  ov172
 *   CTVT_CAMVIEW_UploadWindows  0x021B71B8  thumb  ov172
 *   DRAW_SYSTEM_FlushStrokes  0x021B6C4C  thumb  ov172
 *   CTVT_TALK_SetMicMode  0x021B9574  thumb  ov172
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021C7050     0x021C7050  data  a4
 *   d_021C7060     0x021C7060  data  a4
 *   d_021C7080     0x021C7080  data  a4
 *   d_021C70A0     0x021C70A0  data  a4
 *   d_021C70C0     0x021C70C0  data  a4
 *   d_021C70E0     0x021C70E0  data  a4
 *   d_021C7100     0x021C7100  data  a4
 *   d_021C7120     0x021C7120  data  a4
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   TCBL_Create 0x0203101C arm
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   CTVT_TALK_Exit 0x021B8FB8 thumb ov172
 *   CTVT_TALK_Init 0x021B8CC8 thumb ov172
 *   CTVT_CAMVIEW_IsWindowMoving 0x021B7B30 thumb ov172
 *   CTVT_COMM_GetSlotParam 0x021B8B94 thumb ov172
 *   CTVT_COMM_GetMarkerSlot 0x021B8B68 thumb ov172
 *   MYSTATUS_CreateNameStrbuf 0x02008510 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 *   TCBL_Main  0x020310C4  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   CTVT_DRAW_Create 0x021BA280 thumb ov172
 *   CTVT_DRAW_Free 0x021BA2B8 thumb ov172
 *   CTVT_DRAW_Init 0x021BA2C4 thumb ov172
 *   CTVT_DRAW_Exit 0x021BA8C4 thumb ov172
 *   CTVT_DRAW_Main 0x021BA9EC thumb ov172
 *   COMM_TVT_SYS_GetTaskMenu 0x021BE04C thumb ov172
 *   COMM_TVT_SYS_GetHostBusy 0x021BE0EC thumb ov172
 *   COMM_TVT_SYS_ClearHostBusy 0x021BE0F0 thumb ov172
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm  arm9
 *   BG_SYS_FreeSlot  0x020414AC  arm  arm9
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm  arm9
 *   GFL_USE_GetRandomBelow  0x02005728  thumb  arm9
 *   _fdiv                        0x0209CE10  arm
 *   _ffixu                       0x0209C4C8  arm
 *   _fflt                        0x0209BDBC  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../version.h"
#include "ctvt_types.h"
#include "../sdk_ioreg.h"

#include "../arm9/gx_bgcnt.h"

#include "ctvt_comm.h"
struct GameData;
struct MyStatus;

                            


typedef short s16_p07;
#include "../arm9/bmp.h"

#include "../arm9/bmp_win.h"



#include "../arm9/clact.h"

#include "ctvt_camera.h"


#include "../arm9/touchpanel.h"

struct PrintQueue;
/* The DS code was built against a prototype with a halfword x and a word y; the host build uses the header. */
#ifdef __MWERKS__
#define PRINTSYS_PrintQueColor PRINTSYS_PrintQueColor_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintQueColor
extern void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, s16 x, u32 y, struct Strbuf *str, struct GfFont *font, u16 color);
#endif

struct Strbuf;
/* The DS code passes the capacity and heap id as long words (the original prototype); the header has u32 parameters. The host build uses the header. */
#ifdef __MWERKS__
#define STRBUF_Create STRBUF_Create_header
#endif
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
#undef STRBUF_Create
extern struct Strbuf *STRBUF_Create(unsigned long capacity, unsigned long heapId);
#endif

#include "../arm9/bmp_menuwork.h"

#define MK(c, p, a1, a2, a3, sp) CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(c), COMM_TVT_SYS_GetResId(c, a1), COMM_TVT_SYS_GetResId(c, a2), COMM_TVT_SYS_GetResId(c, a3), &d, sp, v)

#define WININ (*(volatile u16 *)REG_WININ_ADDR)

#define WINOUT (*(volatile u16 *)REG_WINOUT_ADDR)

struct WordSet;

struct Strbuf;

struct GameData;

struct WifiList;

struct TaskMenuRes;

struct FieldSoundSystem;

struct TcbTask;

struct TaskMenuRes;

struct TcblSystem;

struct Unit;

struct DispConfig;

struct BgTemplate;

struct DispVram;

struct GfFont;

struct CtvtCallRec;

struct TcblSystem;

struct CtvtCallRec {
    u8 pad0[4];
    unsigned long trainerId;
    u8 pad8[3];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    unsigned long fC_0 : 17;
    unsigned long fC_17 : 10;
    unsigned long fC_27 : 5;
    u8 pad10[8];
    u16 value;
    u8 pad1A[6];
    u8 memberCount;      /* +0x20: member count of the peer session (copy of its CtvtComm.prevMemberCount) */
    u8 f21_0 : 1;
    u8 f21_1 : 1;
    u8 f21_2 : 6;
};

struct Bits2 {
    u8 b0 : 1;
    u8 b1 : 5;
    u8 b6 : 2;
};

struct CtvtCallSlot {
    unsigned long active;
    unsigned long unseen;
    unsigned long selected;
    u8 padC[8];
    u8 *buf;
    u8 kind;
    u8 mac[6];
    u8 pad1f;
    u8 row;
    u8 pad21[3];
};

struct List {
    u8 pad[0x1e4];
    struct CtvtCallSlot slots[15];
};

struct FlagsA {
    u8 pad[0x21];
    u8 on : 1;
    u8 rest : 7;
};

struct FlagsB {
    u8 pad[2];
    u8 low : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct Prompt {
    struct Strbuf *str;
    u16 color;
    u16 pad;
    unsigned long flags;
};

typedef struct { u32 w[7]; } Cfg7;

struct PltData { u32 fmt; u32 ext; u32 size; u8 *raw; };

struct CellCfg { u16 a; u16 b; u16 c; u8 d; u8 e; };

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"



#include "../arm9/bg_sys.h"


#include "../arm9/app_icon.h"


#include "../arm9/arc_tool.h"











#include "../arm9/net.h"





#include "../arm9/wipe.h"


#include "../arm9/key.h"




#include "../arm9/gfl_use.h"




struct ClactVec2;






#include "../arm9/app_taskmenu.h"
















#include "../ov014/net_whpipe.h"

#include "../arm9/mystatus.h"

struct MyStatus;




#include "../arm9/zonedata.h"



/* The DS code passes the heap id as a word (the original prototype); the header takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define WORDSET_CreateDefault WORDSET_CreateDefault_header
#endif
#include "../arm9/gf_font.h"
#ifdef __MWERKS__
#undef WORDSET_CreateDefault
extern struct WordSet *WORDSET_CreateDefault(unsigned long heapId);
#endif





#include "../arm9/wordset.h"





#include "../arm9/wifilist.h"








#include "../arm9/field_sound_system.h"


#include "../arm9/tcb_list.h"













#include "../arm9/tcbl.h"



#include "../arm9/nns_gfd_vram_transfer.h"

#include "../arm9/arc_util.h"
#include "../arm9/comm_player_support.h"
#include "../arm9/game_data.h"
#include "../arm9/msgdata.h"
#include "../arm9/os_ownerinfo.h"
#include "../ov172/ctvt_talk.h"
#include "../arm9/time_icon.h"
#include "../arm9/app_env.h"
#include "../ov172/ctvt_draw.h"
#include "../ov172/draw_system.h"


































































void *CTVT_CALL_Create(void *unused, u32 heapId);

void CTVT_CALL_Free(void *unused, void *v);

void CTVT_CALL_Init(void *ctx, u8 *p);

void CTVT_CALL_Exit(void *ctx, char *st);

int CTVT_CALL_Update(void *ctx, char *p);

void CTVT_CALL_HandleTouch(void *ctx, u8 *list);

void CTVT_CALL_RefreshPeers(void *ctx, u8 *list);

void CTVT_CALL_UpdateRows(void *ctx, char *list);

void CTVT_CALL_DrawRow(void *ctx, char *list, char *row, int idx);

void CTVT_CALL_PlaceCursor(void *ctx, char *list, char *cur, u8 idx);

void CTVT_CALL_UpdatePrompt(void *ctx, u8 *st);

void CTVT_CALL_UpdateTimeWindow(void *ctx, char *st);

int CTVT_CALL_CheckJoinRequest(void *ctx, void *unused, const void *a, unsigned long b, unsigned long c);

void CTVT_CALL_PrintMessage(void *ctx, char *st, int msgId);

void CTVT_CALL_PrintTimeMessage(void *ctx, char *st, unsigned long msgId);

void CTVT_CALL_WorkInit(char *self);

void CTVT_CALL_WorkDelete(u8 *p);

int CTVT_CALL_WorkMain(char *ctx);

void CTVT_CALL_VBlank(struct TcbTask *unused, void *ctx);

void CTVT_CALL_InitDisplay(u8 *p);

void CTVT_CALL_ExitDisplay(void *work);

void CTVT_CALL_InitBgLayer(const struct BgTemplate *tmpl, u8 bgId, u32 type);

void CTVT_CALL_InitGraphics(u8 *p);

void CTVT_CALL_ReleaseGraphics(u8 *p);

void CTVT_CALL_InitText(u8 *p);

void CTVT_CALL_DeleteText(CtvtWork *work);

void CTVT_CALL_SwitchScreen(u8 *p);

void CTVT_CALL_UpdateMemberWindows(u8 *p);

void CTVT_CALL_DrawMemberName(u8 *p, char *a, struct CtvtDescriptor *b);


extern s16 FX_SinCosTable_[];

extern unsigned int g_021C7234[];

extern u8 d_021C7234[];

extern const u8 d_021C7040[];

extern s16 FX_SinCosTable_[];

extern const Cfg7 gClActorInitParam;

extern u8 d_021C7050[];

extern u8 d_021C7060[];

extern u8 d_021C7080[];

extern u8 d_021C70A0[];

extern u8 d_021C70C0[];

extern u8 d_021C70E0[];

extern u8 d_021C7100[];

extern u8 d_021C7120[];

void *CTVT_CALL_Create(void *unused, u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(CtvtCall), 1, (const char *)g_021C7234, 0xd8);
}

/*
 * Tail call to GFL_HEAP_Free, second argument forwarded.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_CALL_Free(void *unused, void *v)
{
    GFL_HEAP_Free(v);
}

/*
 * Scene setup: fifteen rows of three sprite objects (stride 0x1c), the objects at +0x400 and
 * +0x404, fifteen 0x24-byte entries with text buffers, fifteen windows, then state clears.
 * note 2026-10-05 (wD7 lane03): EXACT. Closing levers: the d.z choice as an if/else (the ternary
 * gave the inverted branch layout and changed the whole colouring), the missing `d.a = 0x10` in
 * the third object of each row (logic error in the draft), row computed after the descriptor
 * stores, and separate pointer locals for loop 2 and loop 3 (spill slots 0x10 and 0xc).
 */
void CTVT_CALL_Init(void *ctx, u8 *p)
{
    struct ActorInitParam d;
    u16 v;
    CtvtLaunchParams *o;
    u8 i;
    u8 j;
    u8 k;
    u8 z;
    CtvtCall *row;
    CtvtCall *ent;
    CtvtCall *slot;
    void *owner;
    int o1, o2, o3, o4, o5, o6, o7;

    v = COMM_TVT_SYS_GetHeapId(ctx);
    owner = COMM_TVT_SYS_GetArc(ctx);
    o = COMM_TVT_SYS_GetLaunchParams(ctx);
    if (o->mode != 2 && o->mode != 3 && COMM_TVT_SYS_GetHostBusy(ctx) == 0) {
        ARC_UTIL_UploadBgCharFromHandle(owner, 0xb, 4, 0, 0xa << 10, 0, v);
        ARC_UTIL_UploadBgPaletteFromHandle(owner, 0x12, 4, 0, 0, 0, v);
        BG_SYS_PushTile(4);
    }
    d.bg_priority = 3;
    for (i = 0; i < 15; i++) {
        d.x = 0x80;
        d.y = i * 32 + 0x10;
        d.anim_seq = 8;
        d.draw_priority = 0x20;
        row = (CtvtCall *)((CtvtCallRow *)p + i);
        row->rows[0].actorA = (void *)MK(ctx, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)row->rows[0].actorA, 0);
        CLACT_SetActorAutoAnim((struct ClactActor *)row->rows[0].actorA, 1);
        d.x = 0x12;
        d.anim_seq = 9;
        d.draw_priority = 0x10;
        row->rows[0].actorB = (void *)MK(ctx, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)row->rows[0].actorB, 0);
        d.x = 0xc8;
        d.anim_seq = 0x12;
        d.draw_priority = 0x10;
        row->rows[0].actorC = (void *)MK(ctx, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)row->rows[0].actorC, 0);
    }
    d.x = 0xe0;
    d.y = 0xa8;
    if (COMM_TVT_SYS_GetHostBusy(ctx) == 0)
        d.anim_seq = 1;
    else
        d.anim_seq = 0xf;
    j = 0;
    d.draw_priority = j;
    d.bg_priority = j;
    ((CtvtCall *)p)->actorBack = (void *)MK(ctx, p, 6, 2, 10, 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCall *)p)->actorBack, 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)((CtvtCall *)p)->actorBack, 1);
    d.x = 0xf8;
    d.y = 0x18;
    d.anim_seq = 0xc;
    ((CtvtCall *)p)->actorSlider = (void *)MK(ctx, p, 5, 1, 9, 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCall *)p)->actorSlider, 0);
    o1 = 0x14A;
    o1 += 0x9a;
    o2 = 0x14A;
    o2 += 0x9e;
    o3 = 0x14A;
    o3 += 0xa2;
    o4 = 0x14A;
    o4 += 0xaa;
    o5 = 0x14A;
    o5 += 0xba;
    o6 = 0x14A;
    o6 += 0xae;
    o7 = 0x14A;
    o7 += 0xb9;
    for (j = 0; j < 15; j++) {
        ent = (CtvtCall *)((CtvtCallEntry *)p + j);
        ent->entries[0].active = 0;
        ent->entries[0].unseen = 0;
        ent->entries[0].selected = 0;
        ent->entries[0].dirty = 0;
        ent->entries[0].row = 0xff;
        ent->entries[0].peer = (u8 *)GFL_HEAP_Alloc(v, 0x64, 1, (const char *)d_021C7234, 0xff + 0x4b);
        ent->entries[0].level = 0;
    }
    for (k = 0; k < 15; k++) {
        slot = (CtvtCall *)((CtvtCallRow *)p + k);
        slot->rows[0].active = 0;
        slot->rows[0].pending = 0;
        slot->rows[0].slot = 0xff;
        slot->rows[0].win = (void *)BMP_WIN_Create(6, 3, (u8)(k * 4 + 1), 0x19, 2, 0xa, 1);
    }
    ((CtvtCall *)p)->msgWin = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
    ((CtvtCall *)p)->timeWin = BMP_WIN_Create(4, 2, 9, 0x1c, 2, 0xa, 1);
    z = 0;
    ((CtvtCall *)p)->timePending = z;
    ((CtvtCall *)p)->timerB = z;
    for (z = 0; z < 3; z++) {
        ((CtvtCall *)p)->slotSel[z] = 0xff;
    }
    ((CtvtCall *)p)->selEntry = 0xff;
    ((CtvtCall *)p)->scroll = 0;
    ((CtvtCall *)p)->scrollPos = 0;
    ((CtvtCall *)p)->rowCount = 0;
    ((CtvtCall *)p)->prevRowCount = 0xff;
    ((CtvtCall *)p)->substate = 0xff;
    ((CtvtCall *)p)->refresh = 0;
    ((CtvtCall *)p)->sliderDrag = 0;
    ((CtvtCall *)p)->msgDirty = 0;
    ((CtvtCall *)p)->timeDirty = 0;
    ((CtvtCall *)p)->soundPlayed = 0;
    ((CtvtCall *)p)->menuWin = 0;
    ((CtvtCall *)p)->state = 0;
    ((CtvtCall *)p)->timerA = 0;
    BG_SYS_ChangeScroll(6, 3, 0);
    if ((unsigned int)(o->mode - 2) <= 1 && COMM_TVT_SYS_GetHostBusy(ctx) == 0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)((CtvtCall *)p)->actorBack, 0xf);
        CTVT_CALL_PrintTimeMessage(ctx, (char *)p, 0x18);
        ((CtvtCall *)p)->timePending = 1;
        ((CtvtCall *)p)->substate = 3;
    }
}

void CTVT_CALL_Exit(void *ctx, char *st)
{
    struct BmpWin *p;
    u8 i, j;

    if (((CtvtCall *)st)->menuWin != 0) {
        APP_TASKMENU_WIN_Delete(((CtvtCall *)st)->menuWin);
        ((CtvtCall *)st)->menuWin = 0;
    }

    p = ((CtvtCall *)st)->msgWin;
    BMP_WIN_ClearScreen((struct BmpWin *)((struct CtvtDescriptor *)p));
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)((struct CtvtDescriptor *)p)));
    BMP_WIN_Delete((struct BmpWin *)((struct CtvtDescriptor *)(((CtvtCall *)st)->msgWin)));

    p = ((CtvtCall *)st)->timeWin;
    BMP_WIN_ClearScreen((struct BmpWin *)((struct CtvtDescriptor *)p));
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)((struct CtvtDescriptor *)p)));
    BMP_WIN_Delete((struct BmpWin *)((struct CtvtDescriptor *)(((CtvtCall *)st)->timeWin)));

    CLACT_DeleteActor((struct ClactActor *)(((CtvtCall *)st)->actorSlider));
    CLACT_DeleteActor((struct ClactActor *)(((CtvtCall *)st)->actorBack));

    for (i = 0; i < 0xf; i++) {
        CtvtCall *q = (CtvtCall *)((CtvtCallRow *)st + i);

        BMP_WIN_Delete((struct BmpWin *)((struct CtvtDescriptor *)(q->rows[0].win)));
        CLACT_DeleteActor((struct ClactActor *)(q->rows[0].actorC));
        CLACT_DeleteActor((struct ClactActor *)(q->rows[0].actorB));
        CLACT_DeleteActor((struct ClactActor *)(q->rows[0].actorA));
    }

    for (j = 0; j < 0xf; j++)
        GFL_HEAP_Free((void *)(((CtvtCall *)st)->entries[j].peer));

    BG_SYS_ClearSlot(6);
    BG_SYS_PushTile(6);
    BG_SYS_ChangeScroll(6, 3, 0);
    BG_SYS_ClearSlot(4);
    BG_SYS_PushTile(4);
    BG_SYS_ChangeScroll(4, 3, 0);
}

/*
 * 2026-10-04 (D3-06): byte-identical (1724 bytes); 4 of 106 relocations wait on
 *   unlabelled ov172 Thumb leaves filed EXACT this wave as src/matched/ov/
 *   CTVT_COMM_GetMyStatusPtr.c, CTVT_COMM_ResetSlotTimer.c, CTVT_COMM_IsSlotTimerDone.c,
 *   COMM_TVT_SYS_ClearHostBusy.c. After the integrator manifest gives them shard
 *   witnesses, this file should verify EXACT and move to src/matched/ov.
 *   Keys: cnt is block-local in the fC==1 block (sets its stack slot);
 *   case 6 jumps into case 10 by tail merge (code written twice).
 */
int CTVT_CALL_Update(void *ctx, char *p)
{
    void *t;
    u16 v;
    unsigned int *st;
    void *t2;
    u8 i, j;
    CtvtCall *r;
    CtvtCallRow *q;
    u8 *ip;
    void *w;
    struct CtvtDescriptor *d;

    v = COMM_TVT_SYS_GetHeapId(ctx);
    st = (unsigned int *)COMM_TVT_SYS_GetLaunchParams(ctx);
    switch (((CtvtCall *)p)->state) {
    case 0:
        if (COMM_TVT_SYS_GetReturnedFromChild(ctx) == 1)
            WIPE_SYS_Start((void *)0, 1, 1, 0, 6, 1, v);
        else
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, v);
        ((CtvtCall *)p)->state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            unsigned int *s = (unsigned int *)COMM_TVT_SYS_GetLaunchParams(ctx);
            if (COMM_TVT_SYS_GetHostBusy(ctx) == 1)
                ((CtvtCall *)p)->state = 11;
            else if (((CtvtLaunchParams *)s)->mode == 2 || ((CtvtLaunchParams *)s)->mode == 3)
                ((CtvtCall *)p)->state = 8;
            else
                ((CtvtCall *)p)->state = 5;
        }
        break;
    case 2:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 6, 1, v);
        COMM_TVT_SYS_SetReturnedFromChild(ctx, 0);
        ((CtvtCall *)p)->state = 4;
        break;
    case 3:
        if (CTVT_CAMVIEW_IsShutterIdle((struct CtvtWork *)ctx, (CtvtCamView *)((char *)COMM_TVT_SYS_GetCamView(ctx))) == 1) {
            WIPE_SYS_Start((void *)0, 0, 0, 0, 6, 1, v);
            COMM_TVT_SYS_SetReturnedFromChild(ctx, 0);
            ((CtvtCall *)p)->state = 4;
        }
        break;
    case 4:
        if (WIPE_SYS_EndCheck() == 1) {
            if (((CtvtCall *)p)->substate == 0 || ((CtvtCall *)p)->substate == 5)
                return 4;
            return 1;
        }
        break;
    case 5:
        CTVT_CALL_HandleTouch(ctx, (u8 *)p);
        CTVT_CALL_UpdateTimeWindow(ctx, p);
        break;
    case 6:
        if (((CtvtCall *)p)->substate == 0 || ((CtvtCall *)p)->substate == 5) {
            if (CLACT_IsActorAnimActive((struct ClactActor *)((CtvtCall *)p)->actorBack) == 0) {
                CTVT_CAMVIEW_StopCapture((struct CtvtWork *)ctx, (CtvtCamView *)((char *)COMM_TVT_SYS_GetCamView(ctx)));
                ((CtvtCall *)p)->substate = 0;
                ((CtvtCall *)p)->state = 3;
            }
            break;
        }
        if (APP_TASKMENU_WIN_IsFinish((void *)((CtvtCall *)p)->menuWin) != 1)
            break;
        if (((CtvtCall *)p)->substate == 2) {
            t = COMM_TVT_SYS_GetComm(ctx);
            CTVT_COMM_SetRequestedMode((char *)(ctx), (char *)t, 4);
            CTVT_COMM_SetConnectMac((char *)(ctx), (char *)t, (const u8 *)&((CtvtCall *)p)->entries[((CtvtCall *)p)->selEntry].mac[0]);
            CTVT_CALL_PrintTimeMessage(ctx, p, 0x18);
            ((CtvtCall *)p)->timePending = 1;
            ((CtvtCall *)p)->state = 7;
            ((CtvtCall *)p)->timerA = 0;
            ((CtvtCall *)p)->timerB = 0;
            APP_TASKMENU_WIN_Delete((void *)((CtvtCall *)p)->menuWin);
            ((CtvtCall *)p)->menuWin = 0;
        } else {
            t2 = COMM_TVT_SYS_GetComm(ctx);
            ((CtvtCall *)p)->state = 9;
            CTVT_CALL_PrintTimeMessage(ctx, p, 0x14);
            ((CtvtCall *)p)->timePending = 1;
            ((CtvtCall *)p)->timerB = 0;
            CTVT_COMM_SetRequestedMode((char *)(ctx), (char *)t2, 3);
            APP_TASKMENU_WIN_Delete((void *)((CtvtCall *)p)->menuWin);
            ((CtvtCall *)p)->menuWin = 0;
            ip = CTVT_COMM_GetMyStatusPtr(ctx, (u8 *)t2);
            for (i = 0; i < 3; i++) {
                if (((CtvtCall *)p)->slotSel[i] == 0xff) {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = 0xff;
                } else {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = ((CtvtCall *)p)->entries[((CtvtCall *)p)->slotSel[i]].mac[j];
                }
            }
            ip[0x21] |= 2;
            CTVT_COMM_ResetSlotTimer(ctx, (u8 *)t2);
        }
        CLACT_SetActorAnimSeq(((CtvtCall *)p)->actorBack, 0xf);
        break;
    case 7:
    case 8:
    case 9:
        COMM_TVT_SYS_GetComm(ctx);
        if (COMM_TVT_SYS_GetMemberCount(ctx) >= 2) {
            if (((CtvtCall *)p)->soundPlayed == 0) {
                t = COMM_TVT_SYS_GetCamView(ctx);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x73e);
                CTVT_CAMVIEW_RequestShutterSound0((sptr)ctx, (CtvtCamView *)((char *)t));
            }
            ((CtvtCall *)p)->state = 2;
        }
        if (((CtvtCall *)p)->state == 9) {
            ((CtvtCall *)p)->timerB++;
            if (((CtvtCall *)p)->timerB >= 0x78) {
                ((CtvtCall *)p)->timerB = 0;
                GFL_USE_PlaySeInSlot(0x73d, 2);
            }
        }
        if (((CtvtCall *)p)->state == 9) {
            if (CTVT_COMM_IsSlotTimerDone((void *)ctx, (u8 *)COMM_TVT_SYS_GetComm(ctx)) == 1) {
                CTVT_COMM_SetRequestedMode((char *)(ctx), (char *)COMM_TVT_SYS_GetComm(ctx), 2);
                CTVT_CALL_PrintTimeMessage(ctx, p, 0x27);
                ((CtvtCall *)p)->state = 10;
            }
        } else if (((CtvtCall *)p)->state == 7 || ((CtvtCall *)p)->state == 8) {
            ((CtvtCall *)p)->timerA++;
            if (((CtvtCall *)p)->timerA >= 0x4b0) {
                CTVT_COMM_SetRequestedMode((char *)(ctx), (char *)COMM_TVT_SYS_GetComm(ctx), 2);
                CTVT_CALL_PrintTimeMessage(ctx, p, 0x28);
                ((CtvtCall *)p)->state = 10;
            }
        }
        break;
    case 10:
        if (TOUCHPANEL_GetTrg() == 1) {
            if (((unsigned int *)COMM_TVT_SYS_GetLaunchParams(ctx))[1] == 2) {
                CTVT_CAMVIEW_StopCapture((struct CtvtWork *)ctx, (CtvtCamView *)((char *)COMM_TVT_SYS_GetCamView(ctx)));
                ((CtvtCall *)p)->substate = 0;
                ((CtvtCall *)p)->state = 3;
            } else {
                for (i = 0; i < 3; i++)
                    ((CtvtCall *)p)->slotSel[i] = 0xff;
                ((CtvtCall *)p)->state = 5;
                ((CtvtCall *)p)->selEntry = 0xff;
                BMP_MENUWORK_DrawWindowBorder((void *)((CtvtCall *)p)->timeWin, 1);
                d = (struct CtvtDescriptor *)((CtvtCall *)p)->timeWin;
                BMP_WIN_ClearScreen((struct BmpWin *)d);
                BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)d));
                COMM_TVT_SYS_DeleteTimeIcon(ctx);
                CLACT_SetActorAnimSeq(((CtvtCall *)p)->actorBack, 1);
                ((CtvtCall *)p)->substate = 4;
            }
        }
        break;
    case 11:
        BMP_WIN_Delete((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)p)->msgWin));
        ((CtvtCall *)p)->msgWin = BMP_WIN_Create(4, 2, 5, 0x1c, 0xe, 0xa, 1);
        CTVT_CALL_PrintMessage(ctx, p, 0x29);
        ((CtvtCall *)p)->state = 12;
        break;
    case 12:
        if (COMM_TVT_SYS_GetMemberCount(ctx) >= 2 && ((CtvtCall *)p)->soundPlayed == 0) {
            GFL_USE_StopAllSe();
            ((CtvtCall *)p)->soundPlayed = 1;
            GFL_USE_PlaySeDefaultVolume(0x73e);
        }
        if (TOUCHPANEL_GetTrg() == 1 || COMM_TVT_SYS_GetEndRequested(ctx) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            BMP_MENUWORK_DrawWindowBorder((void *)((CtvtCall *)p)->msgWin, 1);
            d = (struct CtvtDescriptor *)((CtvtCall *)p)->msgWin;
            BMP_WIN_ClearScreen((struct BmpWin *)d);
            BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)d));
            BMP_WIN_Delete((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)p)->msgWin));
            ((CtvtCall *)p)->msgWin = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
            COMM_TVT_SYS_ClearHostBusy(ctx);
            if (((CtvtLaunchParams *)st)->mode == 2 || ((CtvtLaunchParams *)st)->mode == 3) {
                CLACT_SetActorAnimSeq(((CtvtCall *)p)->actorBack, 0xf);
                if (COMM_TVT_SYS_GetMemberCount(ctx) < 2)
                    CTVT_CALL_PrintTimeMessage(ctx, p, 0x18);
                ((CtvtCall *)p)->timePending = 1;
                ((CtvtCall *)p)->substate = 3;
                ((CtvtCall *)p)->state = 8;
            } else {
                ((CtvtCall *)p)->state = 5;
                ((CtvtCall *)p)->substate = 4;
                CLACT_SetActorAnimSeq(((CtvtCall *)p)->actorBack, 1);
                v = COMM_TVT_SYS_GetHeapId(ctx);
                w = COMM_TVT_SYS_GetArc(ctx);
                ARC_UTIL_UploadBgCharFromHandle(w, 0xb, 4, 0, 0x2800, 0, v);
                ARC_UTIL_UploadBgPaletteFromHandle(w, 0x12, 4, 0, 0, 0, v);
                BG_SYS_PushTile(4);
            }
        }
        break;
    }
    if (((CtvtLaunchParams *)st)->mode != 3 && COMM_TVT_SYS_GetHostBusy(ctx) == 0) {
        CTVT_CALL_RefreshPeers(ctx, (u8 *)p);
        for (i = 0; i < 15; i++) {
            r = (CtvtCall *)((CtvtCallRow *)p + i);
            if (r->rows[0].pending == 1) {
                struct PrintQueue *ps = (struct PrintQueue *)COMM_TVT_SYS_GetPrintQue(ctx);
                if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)ps, (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)r->rows[0].win)))) == 0) {
                    d = (struct CtvtDescriptor *)r->rows[0].win;
                    BMP_WIN_TransferChars((struct BmpWin *)d);
                    BMP_WIN_MakeScreen((struct BmpWin *)((struct Cfg *)d));
                    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
                    r->rows[0].pending = 0;
                }
            }
        }
        if (((CtvtCall *)p)->refresh == 1) {
            u8 cnt = 0;
            for (i = 0; i < 15; i++)
                CTVT_CALL_PlaceCursor(ctx, p, (char *)&((CtvtCall *)p)->rows[i], i);
            BG_SYS_ChangeScroll(6, 3, ((CtvtCall *)p)->scroll);
            for (i = 0; i < 3; i++) {
                if (((CtvtCall *)p)->slotSel[i] != 0xff)
                    cnt++;
            }
            for (j = 0; j < 15; j++) {
                r = (CtvtCall *)((CtvtCallEntry *)p + j);
                if (r->entries[0].active == 1) {
                    q = &((CtvtCall *)p)->rows[r->entries[0].row];
                    if (r->entries[0].selected == 1 && r->entries[0].level < 4 && (((CtvtCall *)p)->selEntry == 0xff || ((CtvtCall *)p)->selEntry == j))
                        CLACT_SetActorAnimSeq((struct ClactActor *)q->actorB, 0xa);
                    else if (cnt == 3 || ((CtvtCall *)p)->selEntry != 0xff || r->entries[0].level == 4)
                        CLACT_SetActorAnimSeq((struct ClactActor *)q->actorB, 0xb);
                    else
                        CLACT_SetActorAnimSeq((struct ClactActor *)q->actorB, 9);
                    if (r->entries[0].dirty == 1) {
                        r->entries[0].dirty = 0;
                        CLACT_SetActorAnimSeq((struct ClactActor *)q->actorA, 0x22);
                    }
                }
            }
            ((CtvtCall *)p)->refresh = 0;
        }
    }
    if (((CtvtCall *)p)->msgDirty == 1) {
        struct PrintQueue *ps = (struct PrintQueue *)COMM_TVT_SYS_GetPrintQue(ctx);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)ps, (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)p)->msgWin)))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)p)->msgWin));
            BMP_WIN_MakeScreen((struct BmpWin *)((struct Cfg *)((CtvtCall *)p)->msgWin));
            BG_SYS_PushTile(4);
            ((CtvtCall *)p)->msgDirty = 0;
        }
    }
    if (((CtvtCall *)p)->timeDirty == 1) {
        struct PrintQueue *ps = (struct PrintQueue *)COMM_TVT_SYS_GetPrintQue(ctx);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)ps, (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)p)->timeWin)))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)p)->timeWin));
            BMP_WIN_MakeScreen((struct BmpWin *)((struct Cfg *)((CtvtCall *)p)->timeWin));
            BG_SYS_PushTile(4);
            ((CtvtCall *)p)->timeDirty = 0;
            if (((CtvtCall *)p)->timePending == 1) {
                ((CtvtCall *)p)->timePending = 0;
                COMM_TVT_SYS_CreateTimeIcon(ctx, (void *)((CtvtCall *)p)->timeWin);
            }
        }
    }
    if (((CtvtCall *)p)->menuWin != 0)
        APP_TASKMENU_WIN_Update((void *)((CtvtCall *)p)->menuWin);
    return 2;
}

void CTVT_CALL_HandleTouch(void *ctx, u8 *list)
{
    unsigned long tx;
    unsigned long ty;
    unsigned long dx;
    unsigned long dy;
    struct CtvtSpritePos pos;
    int trg;
    int cont;
    s16 row;
    u8 id;
    CtvtCallEntry *e;
    int done;
    u8 i;
    int s;
    unsigned long range;

    trg = TOUCHPANEL_GetPointTrg((u32 *)&tx, (u32 *)&ty);
    cont = TOUCHPANEL_GetPointCont((u32 *)&dx, (u32 *)&dy);
    COMM_TVT_SYS_GetComm(ctx);
    if (trg == 1) {
        if (tx > 8 && tx < 0xe0) {
            row = (ty + ((CtvtCall *)list)->scroll) >> 5;
            if (row >= 0 && row < 15) {
                id = ((CtvtCall *)list)->rows[row].slot;
                e = &((CtvtCall *)list)->entries[id];
                done = 0;
                if (e->active == 1 && e->level < 4) {
                    if (e->kind == 0x20) {
                        if (e->selected == 0) {
                            ((CtvtCall *)list)->selEntry = id;
                            done = 1;
                            e->selected = 1;
                            e->dirty = 1;
                            ((CtvtCall *)list)->refresh = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73b);
                        } else {
                            ((CtvtCall *)list)->selEntry = 0xff;
                            e->selected = 0;
                            done = 1;
                            e->dirty = 1;
                            ((CtvtCall *)list)->refresh = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    } else if (((CtvtCall *)list)->selEntry == 0xff) {
                        if (e->selected == 0) {
                            for (i = 0; i < 3; i++) {
                                if (((CtvtCall *)list)->slotSel[i] == 0xff) {
                                    ((CtvtCall *)list)->slotSel[i] = id;
                                    break;
                                }
                            }
                            if (i < 3) {
                                done = 1;
                                e->selected = 1;
                                e->dirty = 1;
                                ((CtvtCall *)list)->refresh = 1;
                                GFL_USE_PlaySeDefaultVolume(0x73b);
                            }
                        } else {
                            for (i = 0; i < 3; i++) {
                                if (id == ((CtvtCall *)list)->slotSel[i]) {
                                    ((CtvtCall *)list)->slotSel[i] = 0xff;
                                    break;
                                }
                            }
                            e->selected = 0;
                            done = 1;
                            e->dirty = 1;
                            ((CtvtCall *)list)->refresh = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    }
                }
                if (done == 1)
                    CTVT_CALL_UpdatePrompt(ctx, list);
            }
        } else if (tx >= 0xec && tx <= 0x104 && ty >= ((CtvtCall *)list)->scrollPos + 0xc
                   && ty <= ((CtvtCall *)list)->scrollPos + 0x24 && ((CtvtCall *)list)->rowCount > 5) {
            ((CtvtCall *)list)->sliderDrag = 1;
            CLACT_SetActorAnimSeq((struct ClactActor *)(((CtvtCall *)list)->actorSlider), 0xd);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (cont == 1 && ((CtvtCall *)list)->sliderDrag == 1 && ((CtvtCall *)list)->rowCount > 5) {
        if (dx >= 0xec && dx <= 0x104 && dy >= 0xc && dy <= 0x9c) {
            range = (((CtvtCall *)list)->rowCount - 5) * 32;
            s = dy - 0x18;
            if (s < 0)
                s = 0;
            else if (s > 0x78)
                s = 0x78;
            ((CtvtCall *)list)->scrollPos = s;
            pos.x = 0xf8;
            pos.y = ((CtvtCall *)list)->scrollPos + 0x18;
            CLACT_AddActorSurfacePos((struct ClactActor *)(((CtvtCall *)list)->actorSlider), (const struct ClactVec2 *)(&pos), 1);
            ((CtvtCall *)list)->scroll = ((CtvtCall *)list)->scrollPos * range / 0x78;
            ((CtvtCall *)list)->refresh = 1;
        }
    } else {
        ((CtvtCall *)list)->sliderDrag = 0;
        CLACT_SetActorAnimSeq((struct ClactActor *)(((CtvtCall *)list)->actorSlider), 0xc);
    }
    if (((CtvtCall *)list)->menuWin != 0 && APP_TASKMENU_WIN_IsTouch((TaskMenuWin *)((void **)(((CtvtCall *)list)->menuWin))) == 1) {
        APP_TASKMENU_WIN_SetDecide((TaskMenuWin *)((char *)(((CtvtCall *)list)->menuWin)), 1);
        ((CtvtCall *)list)->state = 6;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (((CtvtCall *)list)->substate == 1)
            GFL_USE_PlaySeInSlot(0x73d, 2);
    }
    if (!TOUCHPANEL_HitTrg((const TouchHitTable *)d_021C7040) || (KEY_GetTrg() & 2)) {
        ((CtvtCall *)list)->state = 6;
        ((CtvtCall *)list)->substate = 5;
        CLACT_SetActorAnimSeq((struct ClactActor *)(((CtvtCall *)list)->actorBack), 9);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
}

/*
 * Peer list refresh: marks every active slot as unseen, scans the 16 wireless
 * peers, matches each peer MAC against the 15 slots (kind 0x20 or 3), adds new
 * peers to a free slot and to the first free row, then drops slots that were
 * not seen, compacts the rows, and refreshes the list.
 *
 * pass 2 2026-10-06 P2L03: EXACT. kind is a u8 local (NET_WHPIPE_GetEntryBeaconKind returns u8) and
 * found = 1 is a plain literal after the unseen store. With a u32 kind the found
 * spill store was scheduled above the unseen store (10 bytes) and the found = match
 * stand-in was needed (2 bytes); the narrow kind closes it.
 */
void CTVT_CALL_RefreshPeers(void *ctx, u8 *list)
{
    int changed;
    int refresh;
    int found;
    int diff;
    struct CtvtCallRec *p;
    u8 kind;
    const u16 *name;
    unsigned long c;
    int match;
    u8 slot;
    int j;
    int i;
    u8 k;
    u8 m;
    u8 r;
    CtvtCall *e;
    CtvtCall *row;
    u8 *mac;
    unsigned long mode;
    int ok;
    unsigned long b;
    u8 buf[8];
    u8 q;

    changed = 0;
    refresh = 0;
    if (!CTVT_COMM_IsNetReady(ctx, (void *)COMM_TVT_SYS_GetComm(ctx)))
        return;
    for (i = 0; i < 15; i++) {
        e = (CtvtCall *)(list + i * sizeof(CtvtCallEntry));
        if (e->entries[0].active == 1)
            e->entries[0].unseen = 1;
    }
    mode = ((CtvtCall *)list)->state;
    if (mode != 7 && mode != 9 && mode != 10 && (int)mode >= 5) {
        for (j = 0; j < 16; j++) {
            found = 0;
            diff = 0;
            p = GFL_NET_GetScanResult(j);
            if (p == 0)
                continue;
            slot = 0xff;
            mac = GFL_NET_GetScanResultMac(j);
            kind = NET_WHPIPE_GetEntryBeaconKind(j);
            if (kind == 3 && ((struct Bits2 *)((u8 *)p + 2))->b1 != 2)
                continue;
            ok = 0;
            if (kind == 0x20) {
                name = MYSTATUS_GetName((const struct MyStatus *)p);
                b = MYSTATUS_GetSex((const struct MyStatus *)p);
                c = MYSTATUS_GetId((const struct MyStatus *)p);
                OS_GetMacAddress(buf);
                if (p->f21_1 == 0 || CTVT_COMM_FindPeerName((u8 *)p, buf) == 1)
                    ok = CTVT_CALL_CheckJoinRequest(ctx, (void *)list, name, c, b);
            } else if (ZONEDATA_IsEntralink((u16)p->fC_17) == 0 && ZONEDATA_IsZoneGroup118To120((u16)p->fC_17) == 0) {
                ok = CTVT_CALL_CheckJoinRequest(ctx, (void *)list, (const void *)((u8 *)p + 0x1a), p->trainerId, p->bB_7);
            }
            if (ok == 0)
                continue;
            for (k = 0; k < 15; k++) {
                e = (CtvtCall *)(list + k * sizeof(CtvtCallEntry));
                if (e->entries[0].active == 1) {
                    match = 1;
                    for (m = 0; m < 6; m++) {
                        if (mac[m] != e->entries[0].mac[m]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        ((CtvtCall *)list)->entries[k].unseen = 0;
                        found = 1;
                        if (kind != ((CtvtCall *)list)->entries[k].kind) {
                            found = 0;
                            diff = 1;
                            slot = k;
                            for (m = 0; m < 3; m++) {
                                if (k == ((CtvtCall *)list)->slotSel[m]) {
                                    ((CtvtCall *)list)->slotSel[m] = 0xff;
                                    refresh = 1;
                                }
                            }
                            if (((CtvtCall *)list)->selEntry == k) {
                                ((CtvtCall *)list)->selEntry = 0xff;
                                refresh = 1;
                            }
                        }
                        if (kind == 0x20 && (e->entries[0].peer)[0x20] != p->memberCount) {
                            found = 0;
                            diff = 1;
                            slot = k;
                        }
                        break;
                    }
                } else if (slot == 0xff) {
                    slot = k;
                }
            }
            if (found != 0 || slot == 0xff)
                continue;
            e = (CtvtCall *)(list + slot * sizeof(CtvtCallEntry));
            e->entries[0].active = 1;
            e->entries[0].unseen = 0;
            e->entries[0].selected = 0;
            for (m = 0; m < 6; m++)
                e->entries[0].mac[m] = mac[m];
            if (kind == 0x20) {
                ((CtvtCall *)list)->entries[slot].kind = 0x20;
                MI_CpuCopy8(p, ((CtvtCall *)list)->entries[slot].peer, 0x34);
            } else {
                ((CtvtCall *)list)->entries[slot].kind = 3;
                MI_CpuCopy8(p, ((CtvtCall *)list)->entries[slot].peer, 0x64);
            }
            if (diff == 0) {
                for (r = 0; r < 15; r++) {
                    row = (CtvtCall *)((CtvtCallRow *)list + r);
                    if (row->rows[0].slot == 0xff) {
                        row->rows[0].slot = slot;
                        e->entries[0].row = r;
                        row->rows[0].active = 1;
                        break;
                    }
                }
            } else {
                ((CtvtCall *)list)->rows[e->entries[0].row].active = 1;
            }
            changed = 1;
        }
    }
    for (i = 0; i < 15; i++) {
        e = (CtvtCall *)(list + i * sizeof(CtvtCallEntry));
        if (e->entries[0].active == 1 && e->entries[0].unseen == 1) {
            q = e->entries[0].row;
            for (; q < 14; q++) {
                row = (CtvtCall *)((CtvtCallRow *)list + q);
                if (row->rows[1].slot == 0xff)
                    break;
                row->rows[0].slot = row->rows[1].slot;
                ((CtvtCall *)list)->entries[row->rows[0].slot].row = q;
                row->rows[0].active = 1;
            }
            row = (CtvtCall *)((CtvtCallRow *)list + q);
            row->rows[0].slot = 0xff;
            row->rows[0].active = 1;
            e->entries[0].row = 0xff;
            e->entries[0].active = 0;
            for (m = 0; m < 3; m++) {
                if (i == ((CtvtCall *)list)->slotSel[m]) {
                    ((CtvtCall *)list)->slotSel[m] = 0xff;
                    refresh = 1;
                }
            }
            if (((CtvtCall *)list)->selEntry == i) {
                ((CtvtCall *)list)->selEntry = 0xff;
                refresh = 1;
            }
            i--;
            changed = 1;
        }
    }
    if (changed == 1) {
        CTVT_CALL_UpdateRows(ctx, (char *)list);
        refresh = 1;
        ((CtvtCall *)list)->refresh = 1;
    }
    if (refresh == 1 && ((CtvtCall *)list)->state == 5)
        CTVT_CALL_UpdatePrompt(ctx, list);
}

void CTVT_CALL_UpdateRows(void *ctx, char *list)
{
    struct CtvtSpritePos pos;
    u8 n = 0;
    u8 i;
    unsigned long range;

    for (i = 0; i < 15; i++)
        CTVT_CALL_DrawRow(ctx, list, (char *)&((CtvtCall *)list)->rows[i], i);
    for (i = 0; i < 15; i++) {
        if (((CtvtCall *)list)->rows[i].slot != 0xff)
            n++;
    }
    if (((CtvtCall *)list)->rowCount == n)
        return;
    if (n > 5) {
        range = (n - 5) * 32;
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCall *)list)->actorSlider, 1);
        if (((CtvtCall *)list)->scroll > range)
            ((CtvtCall *)list)->scroll = range;
        ((CtvtCall *)list)->scrollPos = ((CtvtCall *)list)->scroll * 0x78 / range;
        if (((CtvtCall *)list)->sliderDrag == 0) {
            pos.x = 0xf8;
            pos.y = ((CtvtCall *)list)->scrollPos + 0x18;
            CLACT_AddActorSurfacePos((struct ClactActor *)(((CtvtCall *)list)->actorSlider), (const struct ClactVec2 *)(&pos), 1);
        }
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCall *)list)->actorSlider, 0);
        ((CtvtCall *)list)->scroll = 0;
        ((CtvtCall *)list)->refresh = 1;
    }
    ((CtvtCall *)list)->rowCount = n;
}

static inline u8 ctvtCallShowRowWindow(struct CtvtDescriptor *win)
{
    BMP_WIN_ClearScreen((struct BmpWin *)(win));
    return BMP_WIN_GetBgLayer((struct BmpWin *)(win));
}

void CTVT_CALL_DrawRow(void *ctx, char *list, char *row, int idx)
{
    struct Strbuf *buf2;
    struct Strbuf *fmt2;
    struct MsgBank *msgs;
    void *sys;
    struct Strbuf *str;
    struct Strbuf *buf;
    u8 *p;
    unsigned long heap;
    struct Strbuf *fmt;
    struct GfFont *font;
    CtvtCallEntry *e;
    struct WordSet *ws;

    if (((CtvtCallRow *)row)->active != 1)
        return;
    if (((CtvtCallRow *)row)->slot != 0xff) {
        heap = COMM_TVT_SYS_GetHeapId(ctx);
        font = COMM_TVT_SYS_GetFont(ctx);
        msgs = COMM_TVT_SYS_GetMsgData(ctx);
        sys = COMM_TVT_SYS_GetPrintQue((CtvtWork *)ctx);
        e = &((CtvtCall *)list)->entries[((CtvtCallRow *)row)->slot];
        ws = WORDSET_CreateDefault(heap);
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCallRow *)row)->win))), 0);
        str = STRBUF_Create(0x20, heap);
        if (e->kind == 0x20)
            STRBUF_SetStringN(str, (const u16 *)(COMM_PLAYER_SUPPORT_GetRecordFieldPtr((const struct MyStatus *)(e->peer))), 8);
        else
            STRBUF_SetStringN(str, (const u16 *)(*(char * *)&e->peer + 0x1a), 8);
        PRINTSYS_PrintQueColor((struct PrintQueue *)(sys), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCallRow *)row)->win))), 6, 0, (struct Strbuf *)((void *)str), (struct GfFont *)font, 0x3c40);
        STRBUF_Delete(str);
        fmt = MSGDATA_AllocString(msgs, 0xe);
        buf = STRBUF_Create(0x20, heap);
        if (e->kind == 0x20)
            WORDSET_SetSlotNumber(ws, 0, COMM_PLAYER_SUPPORT_GetRecordField((const struct MyStatus *)(e->peer)), 5, 2, PM_LANG_HALF_WIDTH_DIGITS);
        else
            WORDSET_SetSlotNumber(ws, 0, ((struct CtvtCallRec *)*(char * *)&e->peer)->value, 5, 2, PM_LANG_HALF_WIDTH_DIGITS);
        WORDSET_CopyTaggedText(ws, (struct Strbuf *)((void *)buf), (struct Strbuf *)((void *)fmt));
        STRBUF_Delete(fmt);
        PRINTSYS_PrintQueColor((struct PrintQueue *)(sys), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCallRow *)row)->win))), 0x50, 0, (struct Strbuf *)((void *)buf), (struct GfFont *)font, 0x3c40);
        STRBUF_Delete(buf);
        if (e->kind == 0x20) {
            p = *(u8 * *)&e->peer;
            e->level = p[0x20];
            fmt2 = MSGDATA_AllocString(msgs, 0x10);
            buf2 = STRBUF_Create(0x20, heap);
            p += 0x20;
            WORDSET_SetSlotNumber(ws, 0, *p, 1, 0, PM_LANG_HALF_WIDTH_DIGITS);
            WORDSET_CopyTaggedText(ws, (struct Strbuf *)((void *)buf2), (struct Strbuf *)((void *)fmt2));
            STRBUF_Delete(fmt2);
            PRINTSYS_PrintQueColor((struct PrintQueue *)(sys), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCallRow *)row)->win))), 0x90, 0, (struct Strbuf *)((void *)buf2), (struct GfFont *)font, 0x3c40);
            STRBUF_Delete(buf2);
        } else {
            e->level = 0;
        }
        if (e->kind == 0x20) {
            if ((*(struct FlagsA * *)&e->peer)->on == 1)
                e->available = 1;
            else
                e->available = 0;
        } else if ((*(struct FlagsB * *)&e->peer)->b7 == 1 && (*(struct FlagsB * *)&e->peer)->b6 == 0) {
            e->available = 1;
        } else {
            e->available = 0;
        }
        WORDSET_Delete(ws);
        ((CtvtCallRow *)row)->pending = 1;
    } else {
        BG_SYS_MarkTileDirty(ctvtCallShowRowWindow((struct CtvtDescriptor *)(((CtvtCallRow *)row)->win)));
    }
    ((CtvtCallRow *)row)->active = 0;
}

/*
 * Places the three cursor sprites (+0x8, +0xc, +0x10) on list row idx relative to the scroll offset at +4: hidden when no row is selected (+0x18 == 0xff) or the row is off screen; the third sprite shows only when the selected entry's flag at +0x1f0 is set, animated from the row's cell at +0x50.
 */
void CTVT_CALL_PlaceCursor(void *ctx, char *list, char *cur, u8 idx)
{
    struct CtvtSpritePos pos;
    s16 y;

    if (((CtvtCallRow *)cur)->slot == 0xff) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorA, 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorB, 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorC, 0);
        return;
    }
    y = idx * 32 - ((CtvtCall *)list)->scroll;
    if (y >= -32 && y <= 0xa0) {
        pos.x = 0x80;
        pos.y = y + 0x10;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((CtvtCallRow *)cur)->actorA), (const struct ClactVec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorA, 1);
        pos.x = 0x12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((CtvtCallRow *)cur)->actorB), (const struct ClactVec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorB, 1);
        pos.x = 0xc8;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((CtvtCallRow *)cur)->actorC), (const struct ClactVec2 *)(&pos), 1);
        if (((CtvtCall *)list)->entries[((CtvtCallRow *)cur)->slot].available == 1) {
            CLACT_SetActorAnimSeq((struct ClactActor *)(((CtvtCall *)list)->rows[idx].actorC), 0x12);
            CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorC, 1);
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorC, 0);
        }
        return;
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorA, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorB, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)((CtvtCallRow *)cur)->actorC, 0);
}

static inline u8 ctvtCallShowPromptWindow(struct BmpWin *win)
{
    BMP_WIN_ClearScreen((struct BmpWin *)((struct CtvtDescriptor *)win));
    return BMP_WIN_GetBgLayer((struct BmpWin *)((struct CtvtDescriptor *)win));
}

/*
 * Keeps the button prompt (+0x1c, kind at +0x18) in step with the selection: a fourth selected slot shows prompt 0x13 (kind 2), any selected slot shows prompt 0x12 (kind 1), none removes the prompt (kind 0) and reprints message 0x11 when the mode byte at +0x14 is set.
 */
void CTVT_CALL_UpdatePrompt(void *ctx, u8 *st)
{
    u8 n = 0;
    u8 i;
    u16 heap = COMM_TVT_SYS_GetHeapId(ctx);
    struct MsgBank *msgs = COMM_TVT_SYS_GetMsgData(ctx);
    void *sys = COMM_TVT_SYS_GetTaskMenu(ctx);

    for (i = 0; i < 3; i++) {
        if (((CtvtCall *)st)->slotSel[i] != 0xff)
            n++;
    }
    if (((CtvtCall *)st)->selEntry != 0xff) {
        if (((CtvtCall *)st)->substate != 2) {
            struct Prompt p = {0};

            BG_SYS_MarkTileDirty(ctvtCallShowPromptWindow(((CtvtCall *)st)->msgWin));
            BMP_MENUWORK_DrawWindowBorder((void *)(((CtvtCall *)st)->msgWin), 1);
            if (((CtvtCall *)st)->menuWin != 0) {
                APP_TASKMENU_WIN_Delete((TaskMenuWin *)((u8 *)(((CtvtCall *)st)->menuWin)));
                ((CtvtCall *)st)->menuWin = 0;
            }
            p.str = MSGDATA_AllocString(msgs, 0x13);
            p.color = 0x39e3;
            p.flags = 0;
            ((CtvtCall *)st)->menuWin = APP_TASKMENU_WIN_Create((TaskMenuRes *)sys, (const TaskMenuItem *)((&p)), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct Strbuf *)p.str);
            ((CtvtCall *)st)->substate = 2;
        }
    } else if (n != 0) {
        if (((CtvtCall *)st)->substate != 1) {
            struct Prompt p = {0};

            BG_SYS_MarkTileDirty(ctvtCallShowPromptWindow(((CtvtCall *)st)->msgWin));
            BMP_MENUWORK_DrawWindowBorder((void *)(((CtvtCall *)st)->msgWin), 1);
            if (((CtvtCall *)st)->menuWin != 0) {
                APP_TASKMENU_WIN_Delete((TaskMenuWin *)((u8 *)(((CtvtCall *)st)->menuWin)));
                ((CtvtCall *)st)->menuWin = 0;
            }
            p.str = MSGDATA_AllocString(msgs, 0x12);
            p.color = 0x39e3;
            p.flags = 0;
            ((CtvtCall *)st)->menuWin = APP_TASKMENU_WIN_Create((TaskMenuRes *)sys, (const TaskMenuItem *)((&p)), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct Strbuf *)p.str);
            ((CtvtCall *)st)->substate = 1;
        }
    } else if (((CtvtCall *)st)->substate != 0) {
        if (((CtvtCall *)st)->menuWin != 0) {
            APP_TASKMENU_WIN_Delete((TaskMenuWin *)((u8 *)(((CtvtCall *)st)->menuWin)));
            ((CtvtCall *)st)->menuWin = 0;
        }
        if (((CtvtCall *)st)->rowCount != 0)
            CTVT_CALL_PrintMessage(ctx, (char *)st, 0x11);
        ((CtvtCall *)st)->substate = 0;
    }
}

static inline u8 ctvtCallShowTimeWindow(struct BmpWin *win)
{
    BMP_WIN_ClearScreen((struct BmpWin *)((struct CtvtDescriptor *)win));
    return BMP_WIN_GetBgLayer((struct BmpWin *)((struct CtvtDescriptor *)win));
}

void CTVT_CALL_UpdateTimeWindow(void *ctx, char *st)
{
    if (((CtvtCall *)st)->rowCount == ((CtvtCall *)st)->prevRowCount)
        return;
    if (((CtvtCall *)st)->rowCount == 0) {
        CTVT_CALL_PrintTimeMessage(ctx, st, 0x1c);
        ((CtvtCall *)st)->timePending = 1;
        BG_SYS_MarkTileDirty(ctvtCallShowTimeWindow(((CtvtCall *)st)->msgWin));
        BMP_MENUWORK_DrawWindowBorder((void *)(((CtvtCall *)st)->msgWin), 1);
    } else if (((CtvtCall *)st)->prevRowCount == 0 && ((CtvtCall *)st)->rowCount != 0) {
        CTVT_CALL_PrintMessage(ctx, st, 0x11);
        COMM_TVT_SYS_DeleteTimeIcon(ctx);
        BMP_MENUWORK_DrawWindowBorder((void *)(((CtvtCall *)st)->timeWin), 1);
        BG_SYS_PushTile(ctvtCallShowTimeWindow(((CtvtCall *)st)->timeWin));
    }
    ((CtvtCall *)st)->prevRowCount = ((CtvtCall *)st)->rowCount;
}

int CTVT_CALL_CheckJoinRequest(void *ctx, void *unused, const void *name, unsigned long trainerId, unsigned long outfitVariant)
{
    return WIFILIST_FindFriendByStatusAndOutfit((struct WifiList *)GAME_DATA_GetWifiList((const struct GameData *)(COMM_TVT_SYS_GetLaunchParams(ctx)->gameData)), (const void *)name, trainerId, outfitVariant, 0);
}

void CTVT_CALL_PrintMessage(void *ctx, char *st, int msgId)
{
    struct GfFont *x = COMM_TVT_SYS_GetFont(ctx);
    struct MsgBank *y = COMM_TVT_SYS_GetMsgData(ctx);
    void *z = COMM_TVT_SYS_GetPrintQue(ctx);
    struct Strbuf *w;

    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)st)->msgWin))), 0xf);
    w = MSGDATA_AllocString(y, msgId);
    PRINTSYS_PrintQueColor((struct PrintQueue *)(z), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)st)->msgWin))), 0, 0, (struct Strbuf *)((void *)w), (struct GfFont *)x, 0x440);
    STRBUF_Delete(w);
    BMP_MENUWORK_DrawWindow((void *)(((CtvtCall *)st)->msgWin), 2, 0x140, 9);
    ((CtvtCall *)st)->msgDirty = 1;
}

void CTVT_CALL_PrintTimeMessage(void *ctx, char *st, unsigned long msgId)
{
    struct GfFont *font = COMM_TVT_SYS_GetFont(ctx);
    struct MsgBank *msgs = COMM_TVT_SYS_GetMsgData(ctx);
    void *sys = COMM_TVT_SYS_GetPrintQue(ctx);
    struct Strbuf *str;

    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)st)->timeWin))), 0xf);
    str = MSGDATA_AllocString(msgs, msgId);
    PRINTSYS_PrintQueColor((struct PrintQueue *)(sys), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtCall *)st)->timeWin))), 0, 0, (struct Strbuf *)((void *)str), (struct GfFont *)font, 0x440);
    STRBUF_Delete(str);
    BMP_MENUWORK_DrawWindow((void *)(((CtvtCall *)st)->timeWin), 2, 0x140, 9);
    ((CtvtCall *)st)->timeDirty = 1;
    ((CtvtCall *)st)->timePending = 0;
    COMM_TVT_SYS_DeleteTimeIcon(ctx);
}

/*
 * note 2026-10-05 wD5 lane12: the loop argument and the two byte stores are the literal 0 (the
 *   original copies r5=0 into r6 before the loop label; it is not the last index).
 */
void CTVT_CALL_WorkInit(char *self)
{
    int z = 0;
    int one = 1;
    u8 i;
    unsigned int h2;
    CtvtParams st;
    ((CtvtWork *)self)->memberCount = one;
    ((CtvtWork *)self)->selfSlot = z;
    ((CtvtWork *)self)->halfRes = z;
    CTVT_CALL_InitDisplay((u8 *)self);
    CTVT_CALL_InitGraphics((u8 *)self);
    CTVT_CALL_InitText((u8 *)self);
    ((CtvtWork *)self)->taskMenu = APP_TASKMENU_RES_Create(4, 7, (struct GFont *)(((CtvtWork *)self)->font), (struct PrintQueue *)(((CtvtWork *)self)->printQue), ((CtvtWork *)self)->heapId);
    ((CtvtWork *)self)->camView = CTVT_CAMVIEW_Create(self, ((CtvtWork *)self)->heapId);
    ((CtvtWork *)self)->comm = CTVT_COMM_Create(self, ((CtvtWork *)self)->heapId);
    ((CtvtWork *)self)->talk = CTVT_TALK_Create(self, ((CtvtWork *)self)->heapId);
    ((CtvtWork *)self)->draw = CTVT_DRAW_Create((struct CtvtWork *)self, ((CtvtWork *)self)->heapId);
    ((CtvtWork *)self)->call = CTVT_CALL_Create((void *)self, (u32)((CtvtWork *)self)->heapId);
    st.heap = ((CtvtWork *)self)->heapId;
    st.kind = 2;
    st.count = 0x64;
    st.a = z;
    st.b = 0x100;
    st.c = z;
    st.d = 0xc0;
    ((CtvtWork *)self)->sprites = DRAW_SYSTEM_CreateCanvas((struct DrawCanvasParams *)&st);
    ((CtvtWork *)self)->vblankTask = GFL_USE_AddMainTask(CTVT_CALL_VBlank, self, 8);
    ((CtvtWork *)self)->screen = z;
    ((CtvtWork *)self)->fadePhase = z;
    ((CtvtWork *)self)->fadeIndex = z;
    ((CtvtWork *)self)->returnedFromChild = one;
    ((CtvtWork *)self)->messageActive = z;
    ((CtvtWork *)self)->viewSwapped = z;
    ((CtvtWork *)self)->inputLocked = z;
    ((CtvtWork *)self)->endRequested = z;
    ((CtvtWork *)self)->hostBusy = z;
    ((CtvtWork *)self)->cameraBusy = z;
    if (APP_ENV_HasParentalControlBits() == 1) ((CtvtWork *)self)->hostBusy = one;
    GFL_NET_RefreshWmIconAtTopRight(0, ((CtvtWork *)self)->heapId);
    switch (((CtvtLaunchParams *)((CtvtWork *)self)->launch)->mode) {
    case 0:
        CTVT_COMM_SetRequestedMode((char *)(self), (char *)((CtvtWork *)self)->comm, 3);
        ((CtvtWork *)self)->nextScreen = 1;
        break;
    case 1:
        CTVT_COMM_SetRequestedMode((char *)(self), (char *)((CtvtWork *)self)->comm, 2);
        ((CtvtWork *)self)->nextScreen = 2;
        break;
    case 2:
        CTVT_COMM_SetRequestedMode((char *)(self), (char *)((CtvtWork *)self)->comm, 4);
        CTVT_COMM_SetConnectMac((char *)(self), (char *)((CtvtWork *)self)->comm, ((CtvtWork *)self)->launch->peerParam);
        ((CtvtWork *)self)->nextScreen = 2;
        FIELD_SOUND_SYSTEM_StopRingtone(GAME_DATA_GetBgmInfo((const struct GameData *)((CtvtWork *)self)->launch->gameData));
        break;
    case 3:
        CTVT_COMM_SetRequestedMode((char *)(self), (char *)((CtvtWork *)self)->comm, 5);
        ((CtvtWork *)self)->nextScreen = 2;
        break;
    }
    ((CtvtWork *)self)->bmpWin[0] = BMP_WIN_Create(0, 2, 10, 12, 2, 10, 1);
    ((CtvtWork *)self)->bmpWin[1] = BMP_WIN_Create(0, 0x12, 10, 12, 2, 10, 1);
    ((CtvtWork *)self)->bmpWin[2] = BMP_WIN_Create(0, 2, 0x16, 12, 2, 10, 1);
    ((CtvtWork *)self)->bmpWin[3] = BMP_WIN_Create(0, 0x12, 0x16, 12, 2, 10, 1);
    for (i = 0; i < 4; i++) {
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)(((CtvtWork *)self)->bmpWin[i])))), 0);
    }
    ((CtvtWork *)self)->slotFlagA = 0;
    ((CtvtWork *)self)->slotFlagB = 0;
    GFL_USE_CancelChangeAndPlayBgm(0x3e9, 0xffff);
}

void CTVT_CALL_WorkDelete(u8 *p)
{
    u8 i;
    for (i=0; i<4; i++) BMP_WIN_Delete((struct BmpWin *)((struct CtvtDescriptor *)(((CtvtWork *)p)->bmpWin[i])));
    TCB_DeleteTask((struct TcbTask *)(((CtvtWork *)p)->vblankTask));
    DRAW_SYSTEM_DeleteCanvas((struct DrawCanvas *)*(char * *)&((CtvtWork *)p)->sprites);
    CTVT_CALL_Free((void *)p, (void *)(((CtvtWork *)p)->call));
    CTVT_DRAW_Free((struct CtvtWork *)p, (struct CtvtDrawScene *)((CtvtWork *)p)->draw);
    CTVT_TALK_Delete(p, *(char * *)&((CtvtWork *)p)->talk);
    CTVT_COMM_Delete((void *)p, (char *)(((CtvtWork *)p)->comm));
    CTVT_CAMVIEW_Delete((u8 *)(p), (CtvtCamView *)((char *)(((CtvtWork *)p)->camView)));
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)(((CtvtWork *)p)->taskMenu));
    CTVT_CALL_DeleteText((CtvtWork *)p);
    CTVT_CALL_ReleaseGraphics(p);
    CTVT_CALL_ExitDisplay(p);
}

int CTVT_CALL_WorkMain(char *ctx)
{
    unsigned int idx;
    s32 v;
    u8 pal;

    CTVT_COMM_Main(ctx, (char *)((CtvtWork *)ctx)->comm);
    switch (((CtvtWork *)ctx)->screen) {
    case 1:
        ((CtvtWork *)ctx)->nextScreen = CTVT_TALK_Main(ctx, (CtvtTalk *)((CtvtWork *)ctx)->talk);
        break;
    case 2:
        ((CtvtWork *)ctx)->nextScreen = CTVT_CALL_Update(ctx, (char *)((CtvtWork *)ctx)->call);
        break;
    case 3:
        ((CtvtWork *)ctx)->nextScreen = CTVT_DRAW_Main((struct CtvtWork *)ctx, (struct CtvtDrawScene *)(char *)((CtvtWork *)ctx)->draw);
        break;
    case 4:
        if (CTVT_COMM_IsSessionEnded((sptr)ctx, (char *)((CtvtWork *)ctx)->comm) == 1 && CTVT_CAMVIEW_IsShutterIdle((struct CtvtWork *)ctx, (CtvtCamView *)((char *)((CtvtWork *)ctx)->camView)) == 1) {
            return 1;
        }
        return 0;
    case 5:
        if (CTVT_COMM_IsSessionEnded((sptr)ctx, (char *)((CtvtWork *)ctx)->comm) == 1 && CTVT_CAMVIEW_IsShutterIdle((struct CtvtWork *)ctx, (CtvtCamView *)((char *)((CtvtWork *)ctx)->camView)) == 1
            && WIPE_SYS_EndCheck() == 1) {
            return 1;
        }
        break;
    }
    if (((CtvtWork *)ctx)->netErrorPending == 1 && WIPE_SYS_EndCheck() == 1) {
        ((CtvtWork *)ctx)->nextScreen = 5;
    }
    if (((CtvtWork *)ctx)->screen != ((CtvtWork *)ctx)->nextScreen) {
        CTVT_CALL_SwitchScreen((u8 *)ctx);
    }
    CTVT_CAMVIEW_Update((char *)(ctx), (CtvtCamView *)((char *)((CtvtWork *)ctx)->camView));
    DRAW_SYSTEM_Nop((u32)(uptr)((CtvtWork *)ctx)->sprites);
    CLACT_DrawSystem();
    PRINTSYS_QUE_Main((struct PrintQueue *)((CtvtWork *)ctx)->printQue);
    CTVT_CALL_UpdateMemberWindows((u8 *)ctx);
    ((CtvtWork *)ctx)->fadePhase += 0x200;
    idx = ((CtvtWork *)ctx)->fadePhase >> 4;
    v = (FX_SinCosTable_[idx * 2] + 0x1000) / 2 * 10;
    pal = (u8)(unsigned int)((float)v / 4096.0f);
    if (pal >= 10) {
        pal = 9;
    }
    if (pal != ((CtvtWork *)ctx)->fadeIndex) {
        ((CtvtWork *)ctx)->fadeIndex = pal;
        NNS_GfdRegisterNewVramTransferTask(0x1f, 0x40, ((CtvtWork *)ctx)->fadePalette[pal], 0x20);
    }
    TCBL_Main((struct TcblSystem *)((CtvtWork *)ctx)->timeIconSrc);
    BG_SYS_ChangeScrollImmediate(1, 0, GFL_USE_GetRandomBelow(0x100));
    BG_SYS_ChangeScrollImmediate(1, 3, GFL_USE_GetRandomBelow(0x100));
    return 0;
}

void CTVT_CALL_VBlank(struct TcbTask *unused, void *ctxArg)
{
    char *ctx = ctxArg;
    CTVT_CAMVIEW_UploadWindows(ctx, (struct CtvtCamView *)(((CtvtWork *)ctx)->camView));
    CLACT_VBlankSystem();
    DRAW_SYSTEM_FlushStrokes((struct DrawCanvas *)(char *)(((CtvtWork *)ctx)->sprites));
    CTVT_TALK_SetMicMode((char *)ctx, (char *)(((CtvtWork *)ctx)->talk));
}

static inline void inside0(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WININ = (u16)tmp;
}

static inline void inside1(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    WININ = (u16)tmp;
}

static inline void outside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WINOUT & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WINOUT = (u16)tmp;
}

void CTVT_CALL_InitDisplay(u8 *p)
{
    u32 size;
    u32 mode;
    struct Unit *bank;
    Cfg7 cfg;

    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)REG_DISPCNT_ADDR &= 0xFFFFE0FF;
    *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xFFFFE0FF;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_POWCNT1_ADDR |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C7120);
    BG_SYS_Create(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021C7050);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C70A0, 0, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C7100, 1, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C70C0, 4, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C70E0, 5, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C7080, 6, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C7060, 7, 0);
    *(volatile u16 *)REG_BG2CNT_ADDR = (*(volatile u16 *)REG_BG2CNT_ADDR & 0x43) | 0x4484;
    *(volatile u16 *)REG_BG3CNT_ADDR = (*(volatile u16 *)REG_BG3CNT_ADDR & 0x43) | 0x4A84;
    size = 0x18000;
    MI_CpuFill8(G2_GetBG2ScrPtr(), 0, size);
    MI_CpuFill8((void *)G2_GetBG3ScrPtr(), 0, size);
    *(volatile u16 *)REG_BG2CNT_ADDR = (*(volatile u16 *)REG_BG2CNT_ADDR & ~3) | 1;
    *(volatile u16 *)REG_BG3CNT_ADDR = (*(volatile u16 *)REG_BG3CNT_ADDR & ~3) | 2;
    BG_SYS_SetPlaneVisible(2, 1);
    mode = 3;
    BG_SYS_SetPlaneVisible(mode, 1);
    cfg = gClActorInitParam;
    CLACT_InitSystem((const struct ClactSysInit *)((const struct Cfg *)(&cfg)), (const struct DispVramCfg *)(d_021C7120), *(u16 *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    bank = CLACT_CreateUnit(0x40, 0, *(u16 *)p);
    ((CtvtWork *)p)->clactUnit = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    *(volatile u32 *)REG_DISPCNT_ADDR = (*(volatile u32 *)REG_DISPCNT_ADDR & 0xFFFF1FFF) | (mode << 13);
    inside0(0x1f, 1);
    inside1(0x1f, 1);
    outside(0x13, 1);
    *(volatile u16 *)REG_WIN0H_ADDR = 0xff;
    *(volatile u16 *)REG_WIN0V_ADDR = 0xc0;
    *(volatile u16 *)REG_WIN1H_ADDR = 0x20 << 10;
    *(volatile u16 *)REG_WIN1V_ADDR = 0xc0;
}

/*
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_CALL_ExitDisplay(void *work)
{
    *(volatile u32 *)REG_DISPCNT_ADDR &= 0xFFFF1FFF;
    CLACT_DeleteUnit((struct Unit *)(((CtvtWork *)work)->clactUnit));
    CLACT_ExitSystem();
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

void CTVT_CALL_InitBgLayer(const struct BgTemplate *tmpl, u8 bgId, u32 type)
{
    BG_SYS_InitBgLayer(bgId, tmpl, type);
    BG_SYS_SetPlaneVisible(bgId, 1);
    BG_SYS_FreeSlot(bgId);
    BG_SYS_PushTile(bgId);
}

void CTVT_CALL_InitGraphics(u8 *p)
{
    struct MyStatus *t;
    void *dev;
    void *o;
    u32 i0;
    u32 i1;
    u32 i2;
    int z;
    struct CellCfg cfg;
    struct PltData *pal;
    t = (struct MyStatus *)GAME_DATA_GetMyStatus(*(void **)((CtvtWork *)p)->launch);
    ((CtvtWork *)p)->arc = ARC_TOOL_CreateHandle(0xac, ((CtvtWork *)p)->heapId);
    if (MYSTATUS_GetSex(t) == 0) {
        ARC_UTIL_UploadPaletteFromHandleWhole(((CtvtWork *)p)->arc, 7, 4, 0, 0xc0, ((CtvtWork *)p)->heapId);
    } else {
        ARC_UTIL_UploadPaletteFromHandleWhole(((CtvtWork *)p)->arc, 6, 4, 0, 0xc0, ((CtvtWork *)p)->heapId);
    }
    z = 0;
    ARC_UTIL_UploadBgCharFromHandle(((CtvtWork *)p)->arc, 0xb, 7, 0, z, z, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(((CtvtWork *)p)->arc, 0xe, 7, 0, z, z, ((CtvtWork *)p)->heapId);
    BG_SYS_PushTile(7);
    ARC_UTIL_UploadPaletteFromHandleWhole(((CtvtWork *)p)->arc, 0, 0, 0x20, 0x20, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(((CtvtWork *)p)->arc, 8, 1, 0, z, z, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(((CtvtWork *)p)->arc, 0xd, 1, 0, z, z, ((CtvtWork *)p)->heapId);
    BG_SYS_PushTile(1);
    ((CtvtWork *)p)->resId[0] = CLACT_RegisterPaletteCompressed(((CtvtWork *)p)->arc, 3, 0, 0, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[4] = CLACT_RegisterCharacter(((CtvtWork *)p)->arc, 0x18, 0, 0, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[8] = CLACT_RegisterCellAnim(((CtvtWork *)p)->arc, 0x14, 0x16, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[1] = CLACT_RegisterPaletteCompressed(((CtvtWork *)p)->arc, 3, 1, 0, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[5] = CLACT_RegisterCharacter(((CtvtWork *)p)->arc, 0x17, 0, 1, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[9] = CLACT_RegisterCellAnim(((CtvtWork *)p)->arc, 0x13, 0x15, ((CtvtWork *)p)->heapId);
    dev = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(dev, APP_ICON_GetStatusAnimFileId(), 0, 0, 0x20, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(dev, APP_ICON_GetStatusFrameFileId(), 0, 0, z, z, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(dev, APP_ICON_GetStatusAnimFileId(), 4, 0xc0, 0x20, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(dev, APP_ICON_GetStatusFrameFileId(), 5, z, z, z, ((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(dev, APP_ICON_GetStatusDataFileId(), 5, z, z, z, ((CtvtWork *)p)->heapId);
    BG_SYS_FillTileMap(5, z, 0x15, 0x20, 3, 6);
    BG_SYS_PushTile(5);
    ((CtvtWork *)p)->resId[3] = CLACT_RegisterPaletteEx(dev, APP_ICON_GetMoveKindPaletteFileId(), z, 0xe0, z, 3, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[7] = CLACT_RegisterCharacter(dev, APP_ICON_GetMoveKindAnimFileId(), z, z, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[2] = CLACT_RegisterPaletteEx(dev, APP_ICON_GetMoveKindPaletteFileId(), 1, 0xe0, z, 3, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[6] = CLACT_RegisterCharacter(dev, APP_ICON_GetMoveKindAnimFileId(), z, 1, ((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->resId[10] = CLACT_RegisterCellAnim(dev, APP_ICON_GetStatusCellFileId(2), APP_ICON_GetStatusPaletteFileId(2), ((CtvtWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(dev);
    cfg.a = z;
    cfg.b = z;
    cfg.c = z;
    cfg.d = z;
    cfg.e = z;
    o = COMM_TVT_SYS_GetClactUnit((CtvtWork *)p);
    i0 = COMM_TVT_SYS_GetResId((CtvtWork *)p, 4);
    i1 = COMM_TVT_SYS_GetResId((CtvtWork *)p, z);
    i2 = COMM_TVT_SYS_GetResId((CtvtWork *)p, 8);
    ((CtvtWork *)p)->marker = CLACT_CreateActor((struct Unit *)(o), i0, i1, i2, (const struct ActorInitParam *)&cfg, z, ((CtvtWork *)p)->heapId);
    CLACT_SetActorDrawEnable((void *)((CtvtWork *)p)->marker, z);
    CLACT_SetActorAutoAnim((void *)((CtvtWork *)p)->marker, 1);
    if (MYSTATUS_GetSex(t) == 0) {
        dev = ARC_UTIL_LoadPaletteBlockFromHandle((void *)((CtvtWork *)p)->arc, 7, (void *)(&pal), ((CtvtWork *)p)->heapId);
    } else {
        dev = ARC_UTIL_LoadPaletteBlockFromHandle((void *)((CtvtWork *)p)->arc, 6, (void *)(&pal), ((CtvtWork *)p)->heapId);
    }
    MIi_CpuCopy32(pal->raw + 0xc0, ((CtvtWork *)p)->fadePalette, 0x140);
    GFL_HEAP_Free(dev);
}

void CTVT_CALL_ReleaseGraphics(u8 *p)
{
    u8 i;
    CLACT_DeleteActor((struct ClactActor *)(((CtvtWork *)p)->marker));
    for (i = 0; i < 4; i++) CLACT_ReleasePalette(((CtvtWork *)p)->resId[i]);
    for (i = 4; i < 8; i++) CLACT_ReleaseCharacter(((CtvtWork *)p)->resId[i]);
    for (i = 8; i < 11; i++) CLACT_ReleaseCellAnim(((CtvtWork *)p)->resId[i]);
    ARC_TOOL_DeleteHandle((void *)(((CtvtWork *)p)->arc));
}

/*
 * Extent remainder: zero alignment halfword at 021BDC6E.
 */
void CTVT_CALL_InitText(u8 *p)
{
    ((CtvtWork *)p)->font=GF_FONT_Create(23,0,0,0,((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->msgData=(struct MsgBank *)MSGDATA_CreateFromArchive(0,2,27,((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->printQue=(struct PrintQueue *)PRINTSYS_QUE_CreateEx(0x800,((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,0x140,32,((CtvtWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x140,32,((CtvtWork *)p)->heapId);
    GF_FONT_SetDefaultTextColor();
    BMP_MENUWORK_LoadCharAndPltt(4,0x140,9,0,((CtvtWork *)p)->heapId);
    BMP_MENUWORK_LoadCharAndPltt(0,0x200,9,0,((CtvtWork *)p)->heapId);
    ((CtvtWork *)p)->timeIconSrc=(void *)TCBL_Create(((CtvtWork *)p)->heapId,((CtvtWork *)p)->heapId,1,0);
    ((CtvtWork *)p)->timeIcon=0;
}

void CTVT_CALL_DeleteText(CtvtWork *work)
{
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    TCBL_Destroy((struct TcblSystem *)work->timeIconSrc);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
}

void CTVT_CALL_SwitchScreen(u8 *p)
{
    switch (((CtvtWork *)p)->screen) {
    case 1: CTVT_TALK_Exit(p,(char *)((CtvtWork *)p)->talk); break;
    case 2: CTVT_CALL_Exit(p,(char *)((CtvtWork *)p)->call); break;
    case 3: CTVT_DRAW_Exit((struct CtvtWork *)(u16 *)p,((CtvtWork *)p)->draw); break;
    }
    ((CtvtWork *)p)->screen=((CtvtWork *)p)->nextScreen;
    switch (((CtvtWork *)p)->screen) {
    case 0: break;
    case 1: CTVT_TALK_Init(p,(char *)((CtvtWork *)p)->talk); break;
    case 2: CTVT_CALL_Init(p,(u8 *)((CtvtWork *)p)->call); break;
    case 3: CTVT_DRAW_Init((struct CtvtWork *)p,((CtvtWork *)p)->draw); break;
    case 5:
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
    case 4:
        CTVT_COMM_StopSession((struct CtvtWork *)p,((CtvtWork *)p)->comm);
        CTVT_CAMVIEW_StopCapture((struct CtvtWork *)p,((CtvtWork *)p)->camView);
        CTVT_CAMVIEW_RequestShutterSound1((struct CtvtWork *)p,((CtvtWork *)p)->camView);
        break;
    }
}

void CTVT_CALL_UpdateMemberWindows(u8 *p)
{
    u8 i;
    u32 found;
    u32 r;
    u32 m;
    u32 b;
    void *w;
    found = 0;
    if (((CtvtWork *)p)->screen == 3) {
        return;
    }
    r = COMM_TVT_SYS_GetLayoutMode((CtvtWork *)p);
    for (i = found; i < 4; i++) {
        if (CTVT_COMM_IsSlotActive((void *)(p), (char *)(*(char * *)&((CtvtWork *)p)->comm), i) != 1) continue;
        if (CTVT_COMM_GetSlotConnected((void *)(p), (char *)(*(char * *)&((CtvtWork *)p)->comm), i) != 1) continue;
        if (CTVT_CAMVIEW_IsWindowMoving((u8 *)(p), (CtvtCamView *)(*(char * *)&((CtvtWork *)p)->camView), i) != 0) continue;
        m = 1 << i;
        if (m & ((CtvtWork *)p)->slotFlagA) continue;
        {
            char *k = CTVT_COMM_GetSlotParam((sptr)p, *(char * *)&((CtvtWork *)p)->comm, i);
            if (r == 1) {
                if (i == 0) b = 2; else b = 3;
            } else {
                b = i;
            }
            CTVT_CALL_DrawMemberName(p, k, (struct CtvtDescriptor *)(((CtvtWork *)p)->bmpWin[b]));
        }
        ((CtvtWork *)p)->slotFlagA += (u8)m;
        ((CtvtWork *)p)->slotFlagB += (u8)(1 << b);
    }
    for (i = 0; i < 4; i++) {
        m = 1 << i;
        if (!(((CtvtWork *)p)->slotFlagB & m)) continue;
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)((CtvtWork *)p)->printQue, (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct CtvtDescriptor *)((CtvtWork *)p)->bmpWin[i])))) != 0) continue;
        w = ((CtvtWork *)p)->bmpWin[i];
        BMP_WIN_TransferChars((struct BmpWin *)((struct CtvtDescriptor *)w));
        BMP_WIN_MakeScreen((struct BmpWin *)((struct Cfg *)w));
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)((struct CtvtDescriptor *)w)));
        ((CtvtWork *)p)->slotFlagB -= (u8)m;
        found = 1;
    }
    if (found == 1) {
        u8 v = CTVT_COMM_GetMarkerSlot((void *)(p), (char *)(*(char * *)&((CtvtWork *)p)->comm));
        if (v != 0xff) {
            COMM_TVT_SYS_PlaceSlotMarker((void *)p, v);
        }
    }
}

void CTVT_CALL_DrawMemberName(u8 *p, char *a, struct CtvtDescriptor *b)
{
    void *s;
    int x;
    s = MYSTATUS_CreateNameStrbuf((const u16 *)a, ((CtvtWork *)p)->heapId);
    x = (0x60 - (u8)PRINTSYS_MeasureWidestLine((struct Strbuf *)s, (struct GfFont *)(((CtvtWork *)p)->font), 0)) / 2;
    PRINTSYS_PrintQueColor((struct PrintQueue *)((void *)((CtvtWork *)p)->printQue), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(b))), x + 1, 1, (struct Strbuf *)s, (struct GfFont *)(((CtvtWork *)p)->font), 0x400);
    PRINTSYS_PrintQueColor((struct PrintQueue *)((void *)((CtvtWork *)p)->printQue), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(b))), x - 1, 1, (struct Strbuf *)s, (struct GfFont *)(((CtvtWork *)p)->font), 0x400);
    PRINTSYS_PrintQueColor((struct PrintQueue *)((void *)((CtvtWork *)p)->printQue), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(b))), x, 2, (struct Strbuf *)s, (struct GfFont *)(((CtvtWork *)p)->font), 0x400);
    PRINTSYS_PrintQueColor((struct PrintQueue *)((void *)((CtvtWork *)p)->printQue), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(b))), x, 0, (struct Strbuf *)s, (struct GfFont *)(((CtvtWork *)p)->font), 0x400);
    PRINTSYS_PrintQueColor((struct PrintQueue *)((void *)((CtvtWork *)p)->printQue), (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(b))), x, 1, (struct Strbuf *)s, (struct GfFont *)(((CtvtWork *)p)->font), 0x3c00);
    STRBUF_Delete(s);
}
