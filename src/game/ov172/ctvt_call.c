/*
 * file:     ctvt_call.c
 * unit:     yes
 * function: func_021BBA6C, func_021BBA88, func_021BBA94, func_021BBE5C, func_021BBF2C, func_021BC5E8, func_021BC7FC, func_021BCB88, func_021BCC40, func_021BCE2C, func_021BCEF8, func_021BD038, func_021BD0A4, func_021BD0C4, func_021BD134, func_021BD1AC, func_021BD3B8, func_021BD43C, func_021BD5AC, func_021BD5D8, func_021BD7D0, func_021BD820, func_021BD844, func_021BDB5C, func_021BDBC4, func_021BDC70, func_021BDCB8, func_021BDD6C, func_021BDEF0
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
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   G2_GetBG3ScrPtr 0x0207E100 arm
 *   func_0202EB14 0x0202EB14 thumb
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   CTVT_COMM_IsSlotActive 0x021B8BA4 thumb ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   COMM_TVT_SYS_GetLaunchParams 0x021BE004 thumb ov172
 *   func_02012944 0x02012944 thumb
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
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
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   CTVT_CAMVIEW_RequestShutterSound1  0x021B7B80  thumb  ov172
 *   CTVT_COMM_StopSession  0x021B8084  thumb  ov172
 *   FX_SinCosTable_     0x020A1B38  data a2
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
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
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   CTVT_COMM_FindPeerName  0x021B85D0  thumb  ov172
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   COMM_PLAYER_SUPPORT_GetRecordField  0x0202E938  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   func_02009D50  0x02009D50  thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   CTVT_CAMVIEW_Create 0x021B6EE0 thumb ov172
 *   CTVT_COMM_Create 0x021B7BA8 thumb ov172
 *   CTVT_TALK_Create 0x021B8C3C thumb ov172
 *   DRAW_SYSTEM_CreateCanvas 0x021B6BE0 thumb ov172
 *   func_020056A0 0x020056A0 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   func_02028A70 0x02028A70 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02030EAC 0x02030EAC arm
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
 *   func_0203FC28  0x0203FC28  arm
 *   func_02040588  0x02040588  arm
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
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049F78 0x02049F78 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F5BC 0x0201F5BC thumb
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
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
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
 */
#include "../../matched/include/Obj03316.h"
#include "../../matched/include/Obj08261.h"
#include "../../matched/include/Obj00330.h"
#include "../../matched/include/Obj01950.h"
#include "../../matched/include/Obj01951.h"
#include "../../matched/include/Obj01166.h"
#include "../../matched/include/Obj02882.h"
#include "../../matched/include/Obj24102.h"
#include "../../matched/include/Obj01560.h"
#include "../../matched/include/Obj24103.h"
#include "../../matched/include/Obj00543.h"
#include "../../matched/include/Obj01266.h"
#include "../../matched/include/Obj03855.h"
#include "../../matched/include/Obj10666.h"
#include "../../matched/include/Obj24105.h"
#include "../../matched/include/Obj14310.h"
#include "../../matched/include/Obj01758.h"
#include "../../matched/include/Obj02215.h"
#include "../../matched/include/Obj02216.h"
#include "draw_system_shared_types.h"
#include "ctvt_talk_shared_types.h"
#include "ctvt_draw_shared_types.h"
#include "ctvt_call_shared_types.h"

extern void *G2_GetBG2ScrPtr(void);

extern u32 CTVT_COMM_GetSlotConnected(int unused, char *base, int i);

extern int func_0202EB14(void);

extern u8 *func_02012944(void *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void CLACT_DeleteActor(struct Obj *p);

extern int CTVT_CAMVIEW_IsShutterIdle(int x, char *p);

extern void CTVT_CAMVIEW_StopCapture(int x, char *p);

extern int TOUCHPANEL_GetTrg(void);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void func_0201F73C(void *a0, int a1, int a2, int a3);

#define MK(c, p, a1, a2, a3, sp) CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(c), COMM_TVT_SYS_GetResId(c, a1), COMM_TVT_SYS_GetResId(c, a2), COMM_TVT_SYS_GetResId(c, a3), &d, sp, v)

#define OBJ (*(struct Obj **)(p + 0x400))

#define F(o) (*(u32_021BD43C *)(ctx + (o)))

#define WININ (*(volatile u16 *)0x04000048)

#define WINOUT (*(volatile u16 *)0x0400004a)

#define BG (*(void **)(p + 0x17c))

#define HEAP (*(u16 *)p)

struct WordSet;

struct Strbuf;

struct BigObj;

struct Sub020097BCObj;

struct R;

struct SoundSys;

struct Node;

struct TaskMenuState;

struct Tcbl;

struct S;

struct Bank;

struct DispConfig;

struct BgTemplate;

struct DispVram;

struct GfFont;

struct Rec;

struct S02031140;

typedef unsigned int   u32_021BBA6C;

typedef unsigned int   u32_021BBA94;

typedef unsigned int   u32_021BBE5C;

typedef unsigned int   u32_021BBF2C;

typedef unsigned long u32_021BC5E8;

struct Rec {
    u8 pad0[4];
    u32_021BC7FC f4;
    u8 pad8[3];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32_021BC7FC fC_0 : 17;
    u32_021BC7FC fC_17 : 10;
    u32_021BC7FC fC_27 : 5;
    u8 pad10[0x10];
    u8 f20;
    u8 f21_0 : 1;
    u8 f21_1 : 1;
    u8 f21_2 : 6;
};

struct Bits2 {
    u8 b0 : 1;
    u8 b1 : 5;
    u8 b6 : 2;
};

struct Slot {
    u32_021BC7FC active;
    u32_021BC7FC unseen;
    u32_021BC7FC f8;
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
    struct Slot slots[15];
};

typedef unsigned long u32_021BCB88;

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

typedef unsigned long u32_021BCE2C;

typedef unsigned long u32_021BCEF8;

struct Prompt {
    u32_021BCEF8 str;
    u16 color;
    u16 pad;
    u32_021BCEF8 flags;
};

typedef unsigned long u32_021BD038;

typedef unsigned long u32_021BD0A4;

typedef unsigned int u32_021BD0C4;

typedef unsigned long u32_021BD134;

typedef unsigned int u32_021BD1AC;

typedef unsigned int u32_021BD3B8;

typedef unsigned int   u32_021BD43C;

typedef struct { u32 w[7]; } Cfg7;

struct PltData { u32 fmt; u32 ext; u32 size; u8 *raw; };

struct CellCfg { u16 a; u16 b; u16 c; u8 d; u8 e; };

extern void MI_CpuFill8(void *p, int v, int n);

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);

extern u32_021BA2B8 func_020307B0(void *p);

extern void func_020498F4(void *a, u32_021BA2C4 b, u32_021BA2C4 c, u32_021BA2C4 d, u32_021BA2C4 e, u32_021BA2C4 f, u16 g);

extern void func_020409B4(u32_021BA2C4 a);

extern void func_02040588(u32 which, unsigned char enable);

extern u32_021BA2C4  func_020275E4(void);

extern u32_021BA2C4  func_0202762C(void);

extern void *func_020490F4(u32_021BA2C4 id, u32_021BA2C4 heap);

extern void BG_SYS_ClearSlot(u32_021BA2C4 a);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void ARC_TOOL_DeleteHandle(void *a);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32_021BA2C4 v);

extern void CLACT_SetActorDrawEnable(struct Obj *o, unsigned int k);

extern u32_021BA2C4 BMP_WIN_Create(u32_021BA2C4 layer, u32_021BA2C4 a, u32_021BA2C4 b, u32_021BA2C4 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *w);

extern void *func_02045EC0(struct MsgBank *bank, u32_021BCC40 index);

extern void PRINTSYS_PrintQueColor(void *owner, void *b, short x, u32 y, void *text, u32 font, u32 flags);

extern void GFL_NET_RestartWithDefaultTimeout(u32_021BA2C4 a, u32_021BA2C4 b);

extern void func_0201F7A8(void *desc, u32_021BA8C4 kind);

extern u32_021BA8C4 BMP_WIN_Delete(struct Descriptor *d);

extern void CTVT_CAMVIEW_RequestShutterSound1(int x, char *p);

extern void CTVT_COMM_StopSession(void *a, char *q);

extern void WIPE_SYS_Start(void *p1, u32_021BA9EC p2, u32_021BA9EC p3, u32_021BA9EC p4, u32_021BA9EC p5, u32_021BA9EC p6, u32_021BA9EC p7);

extern u32_021BA9EC  WIPE_SYS_EndCheck(void);

extern u32_021BA9EC  KEY_GetTrg(void);

extern u32_021BA9EC PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void func_02041B6C(u32_021BA9EC a);

extern void GFL_USE_PlaySeDefaultVolume(u32_021BA9EC id);

extern u32_021BAE58 CLACT_IsActorAnimActive(struct Actor *);

extern void CLACT_SetActorAnimSeq(struct Obj *, u16);

extern int TOUCHPANEL_HitTrg(const void *p);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32_021BAEE0 which);

extern u32_021BB288 TOUCHPANEL_GetPointTrg(u32_021BB288 *outA, u32_021BB288 *outB);

extern u32_021BB288 G2_GetBG3ScrPtr(void);

extern u32_021BB288 TOUCHPANEL_GetPointCont(u32_021BB288 *outA, u32_021BB288 *outB);

extern void BG_SYS_ResetSlot(u32_021BB4D0, u32_021BB4D0, u32_021BB4D0);

extern u32_021BBA94 func_02049658(void *a, u32_021BBA94 b, u32_021BBA94 c, u32_021BBA94 d, u32_021BBA94 e, u32_021BBA94 f, u16 g);

extern void APP_TASKMENU_WIN_Delete(u8 *p);

extern void CTVT_CAMVIEW_RequestShutterSound0(int x, char *p);

extern void CTVT_COMM_SetRequestedMode(int unused, char *p, u32_021BBF2C v);

extern void CTVT_COMM_SetConnectMac(int unused, char *p, const u8 *src);

extern u8 *CTVT_COMM_GetMyStatusPtr(void *c, u8 *x);

extern void CTVT_COMM_ResetSlotTimer(void *c, u8 *x);

extern u32_021BBF2C CTVT_COMM_IsSlotTimerDone(void *c, u8 *x);

extern u32_021BBF2C APP_TASKMENU_WIN_IsFinish(u8 *p);

extern void APP_TASKMENU_WIN_Update(u8 *p);

extern void GFL_USE_StopAllSe(void);

extern void GFL_USE_PlaySeInSlot(void *arg, int i);

extern u32_021BC5E8 APP_TASKMENU_WIN_IsTouch(void **p);

extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);

extern int CTVT_COMM_IsNetReady(void *unused, void *p);

extern u32_021BC7FC GFL_NET_GetScanResult(u32_021BC7FC a);

extern void *GFL_NET_GetScanResultMac(u32_021BC7FC a);

extern u8 NET_WHPIPE_GetEntryBeaconKind(int i);

extern const void *func_020084F4(const void *p);

extern u8 func_02008550(const struct Sub0200852CObj *obj);

extern u32_021BC7FC func_02008530(const struct Sub0200852CObj *obj);

extern void OS_GetMacAddress(void *p);

extern int CTVT_COMM_FindPeerName(unsigned char *p, unsigned char *q);

extern u32_021BC7FC ZONEDATA_IsZone117(u32_021BC7FC id);

extern u32_021BC7FC ZONEDATA_IsZoneGroup118To120(u32_021BC7FC id);

extern void MI_CpuCopy8(const void *src, void *dst, u32_021BC7FC n);

extern struct WordSet *GF_FONT_Create_EC64(u32_021BCC40 heap);

extern struct U16Vec *STRBUF_Create(u32_021BCC40 capacity, u32_021BCC40 heapId);

extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *p);

extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, unsigned int len);

extern u16 COMM_PLAYER_SUPPORT_GetRecordField(void *p);

extern void func_0201EFA4(struct WordSet *p, u32_021BCC40 i, u32_021BCC40 a, u32_021BCC40 b, u32_021BCC40 c, u32_021BCC40 d);

extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

extern u32_021BCC40 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32_021BCEF8 APP_TASKMENU_WIN_Create(u32_021BCEF8 a0, u32_021BCEF8 a1, u32_021BCEF8 a2, u32_021BCEF8 a3, u8 a4, u16 a5);

extern u32_021BD0A4 GAME_DATA_GetField1A0(const struct BigObj *p);

extern int func_02009D50(struct Sub020097BCObj *obj, const void *unused, u32_021BD0A4 id, u32_021BD0A4 kind, u32_021BD0A4 *out);

extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32_021BD1AC a2, u32_021BD1AC a3, u16 heap);

extern char *CTVT_CAMVIEW_Create(void *a, u16 b);

extern char *CTVT_COMM_Create(void *p, u16 heap);

extern char *CTVT_TALK_Create(char *unused, u16 heap);

extern u32_021BD1AC DRAW_SYSTEM_CreateCanvas(Params *);

extern u32_021BD1AC func_020056A0(void (*)(int, char *), char *, int);

extern u32_021BD1AC GAME_DATA_GetBgmInfo(const struct BigObj *p);

extern void func_02028A70(struct SoundSys *sys);

extern void GFL_USE_CancelChangeAndPlayBgm(u32_021BD1AC, u32_021BD1AC);

extern void func_02030EAC(struct Node *n);

extern void DRAW_SYSTEM_DeleteCanvas(char *);

extern void CTVT_TALK_Delete(void *, char *);

extern void CTVT_COMM_Delete(void *p, char *q);

extern void CTVT_CAMVIEW_Delete(int unused, char *q);

extern u32_021BD3B8 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void CTVT_COMM_Main(void *p, char *q);

extern u32_021BD43C CTVT_TALK_Main(void *p, struct S *s);

extern u32_021BD43C CTVT_COMM_IsSessionEnded(int unused, char *p);

extern void DRAW_SYSTEM_Nop(u32_021BD43C a);

extern void CTVT_CAMVIEW_Update(int unused, char *q);

extern void CLACT_DrawSystem(void);

extern u32_021BD43C PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void TCBL_Main(struct Tcbl *p);

extern u32_021BD43C  func_02005728(u32_021BD43C v);

extern void sub_02040618(u32_021BD43C layer, u32_021BD43C a, u32_021BD43C b);

extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32_021BD43C a, u32_021BD43C b, s32 size);

extern void CTVT_CAMVIEW_UploadWindows(void *p, struct Q *q);

extern void CLACT_VBlankSystem(void);

extern void DRAW_SYSTEM_FlushStrokes(char *p);

extern void CTVT_TALK_SetMicMode(int unused, char *p);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void WIPE_SetBrightnessFadeOut(u32 a, u32 b);

extern u32 WIPE_ResetWndMask(void *win);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_Create(u16 heap);

extern void BMP_WIN_Init(u16 heap);

extern void func_0203FC28(struct DispConfig *cfg);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern void BG_SYS_SetMainPlaneVisible(u32 a, u32 b);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(u32 p);

extern void func_020403F4(u32 i);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_020414AC(u32 which);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern u32 func_02027624(void);

extern u32 func_02027628(void);

extern u32 func_02027614(void);

extern u32 func_02027618(void);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32 func_0202761C(u32 a);

extern u32 func_02027620(u32 a);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

extern void CLACT_ReleasePalette(u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleaseCellAnim(u32);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_0201DD68(void);

extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void TIME_ICON_Delete(u8 *p);

extern void TCBL_Destroy(struct S02031140 *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void CTVT_TALK_Exit(void *,char *);

extern void CTVT_TALK_Init(void *,char *);

extern u32 CTVT_COMM_IsSlotActive(int unused, char *base, int i);

extern u32 CTVT_CAMVIEW_IsWindowMoving(int unused, char *base, int i);

extern char *CTVT_COMM_GetSlotParam(int unused, char *base, int i);

extern u8 CTVT_COMM_GetMarkerSlot(int unused, char *p);

extern void *func_02008510(void *a, int tag);

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

char *CTVT_DRAW_Create(void *a, u16 b);

void CTVT_DRAW_Free(int unused, int v);

void CTVT_DRAW_Init(void *a0, u8 *p);

void CTVT_DRAW_Exit(u16 *a0, char *p);

int CTVT_DRAW_Main(void *a0, char *p);

void *func_021BBA6C(int unused, void *p);

void func_021BBA88(int unused, int v);

void func_021BBA94(void *a0, u8 *p);

void func_021BBE5C(void *a0, char *a1);

int func_021BBF2C(void *a0, char *p);

void func_021BC5E8(void *ctx, u8 *list);

void func_021BC7FC(void *ctx, u8 *list);

void func_021BCB88(void *ctx, char *list);

void func_021BCC40(void *ctx, char *list, char *row, int idx);

void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx);

void func_021BCEF8(void *ctx, u8 *st);

void func_021BD038(void *ctx, char *st);

int func_021BD0A4(void *ctx, u32_021BD0A4 unused, u32_021BD0A4 a, u32_021BD0A4 b, u32_021BD0A4 c);

void func_021BD0C4(void *a0, char *a1, int a2);

void func_021BD134(void *ctx, char *st, u32_021BD134 msgId);

void func_021BD1AC(char *self);

void func_021BD3B8(u8 *p);

int func_021BD43C(char *ctx);

void func_021BD5AC(int unused, char *ctx);

void func_021BD5D8(u8 *p);

void func_021BD7D0(void *a0);

void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type);

void func_021BD844(u8 *p);

void func_021BDB5C(u8 *p);

void func_021BDBC4(u8 *p);

void func_021BDC70(u32 *a0);

void func_021BDCB8(u8 *p);

void func_021BDD6C(u8 *p);

void func_021BDEF0(u8 *p, char *a, u32 b);

u32 COMM_TVT_SYS_GetCamView(void *p);

u32 COMM_TVT_SYS_GetComm(void *p);

u32 COMM_TVT_SYS_GetLaunchParams(void *p);

u16 COMM_TVT_SYS_GetHeapId(u16 *p);

u32 COMM_TVT_SYS_GetArc(void *p);

u32 COMM_TVT_SYS_GetResId(void *p, int i);

u32 COMM_TVT_SYS_GetClactUnit(void *p);

u32 COMM_TVT_SYS_GetReturnedFromChild(void *p);

void COMM_TVT_SYS_SetReturnedFromChild(void *p, u32 v);

u32_021BCC40 COMM_TVT_SYS_GetFont(void *p);

u32_021BCC40 COMM_TVT_SYS_GetMsgData(void *p);

u32_021BCC40 COMM_TVT_SYS_GetPrintQue(void *p);

u32 COMM_TVT_SYS_GetTaskMenu(void *p);

u8 COMM_TVT_SYS_GetMemberCount(void *p);

int COMM_TVT_SYS_GetLayoutMode(void *p);

u32_021BE0D0 COMM_TVT_SYS_GetEndRequested(void *p);

u32_021BE0EC COMM_TVT_SYS_GetHostBusy(void *p);

void COMM_TVT_SYS_ClearHostBusy(u8 *c);

void COMM_TVT_SYS_PlaceSlotMarker(char *a, u8 idx);

void COMM_TVT_SYS_CreateTimeIcon(char *a0, void *a1);

void COMM_TVT_SYS_DeleteTimeIcon(void *p);

extern s16 FX_SinCosTable_[];

extern u32_021BBA6C g_021C7234[];

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

#define W(o) (*(u32_021BBF2C *)(p + (o)))

#define B(o) (*(u8 *)(p + (o)))

#define H(o) (*(u16 *)(p + (o)))

void *func_021BBA6C(int unused, void *p)
{
    return func_02030734((u32_021BBA6C)p, 0x408, 1, (const char *)g_021C7234, 0xd8);
}

/*
 * Tail call to func_020307B0, second argument forwarded.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBA88(int unused, int v)
{
    func_020307B0((void *)v);
}

/*
 * Scene setup: fifteen rows of three sprite objects (stride 0x1c), the objects at +0x400 and
 * +0x404, fifteen 0x24-byte entries with text buffers, fifteen windows, then state clears.
 * note 2026-10-05 (wD7 lane03): EXACT. Closing levers: the d.z choice as an if/else (the ternary
 * gave the inverted branch layout and changed the whole colouring), the missing `d.a = 0x10` in
 * the third object of each row (logic error in the draft), row computed after the descriptor
 * stores, and separate pointer locals for loop 2 and loop 3 (spill slots 0x10 and 0xc).
 */
void func_021BBA94(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u32_021BBA94 o;
    u8 i;
    u8 j;
    u8 k;
    u8 z;
    u8 *row;
    u8 *ent;
    u8 *slot;
    u32_021BBA94 owner;
    int o1, o2, o3, o4, o5, o6, o7;

    v = COMM_TVT_SYS_GetHeapId(a0);
    owner = COMM_TVT_SYS_GetArc(a0);
    o = COMM_TVT_SYS_GetLaunchParams(a0);
    if (*(u32_021BBA94 *)(o + 4) != 2 && *(u32_021BBA94 *)(o + 4) != 3 && COMM_TVT_SYS_GetHostBusy(a0) == 0) {
        func_02049658((void *)owner, 0xb, 4, 0, 0xa << 10, 0, v);
        func_020498F4((void *)owner, 0x12, 4, 0, 0, 0, v);
        func_020409B4(4);
    }
    d.b = 3;
    for (i = 0; i < 15; i++) {
        d.x = 0x80;
        d.y = i * 32 + 0x10;
        d.z = 8;
        d.a = 0x20;
        row = p + i * 0x1c;
        *(u32_021BBA94 *)(row + 0x48) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(row + 0x48), 0);
        CLACT_SetActorAutoAnim((struct Obj *)*(u32_021BBA94 *)(row + 0x48), 1);
        d.x = 0x12;
        d.z = 9;
        d.a = 0x10;
        *(u32_021BBA94 *)(row + 0x4c) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(row + 0x4c), 0);
        d.x = 0xc8;
        d.z = 0x12;
        d.a = 0x10;
        *(u32_021BBA94 *)(row + 0x50) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(row + 0x50), 0);
    }
    d.x = 0xe0;
    d.y = 0xa8;
    if (COMM_TVT_SYS_GetHostBusy(a0) == 0)
        d.z = 1;
    else
        d.z = 0xf;
    j = 0;
    d.a = j;
    d.b = j;
    *(u32_021BBA94 *)(p + 0x400) = (u32_021BBA94)MK(a0, p, 6, 2, 10, 1);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 1);
    CLACT_SetActorAutoAnim((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 1);
    d.x = 0xf8;
    d.y = 0x18;
    d.z = 0xc;
    *(u32_021BBA94 *)(p + 0x404) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(p + 0x404), 0);
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
        ent = p + j * 0x24;
        *(u32_021BBA94 *)(ent + o1) = 0;
        *(u32_021BBA94 *)(ent + o2) = 0;
        *(u32_021BBA94 *)(ent + o3) = 0;
        *(u32_021BBA94 *)(ent + o4) = 0;
        *(u8 *)(ent + o5) = 0xff;
        *(u32_021BBA94 *)(ent + o6) = (u32_021BBA94)func_02030734(v, 0x64, 1, (const char *)d_021C7234, 0xff + 0x4b);
        *(u8 *)(ent + o7) = 0;
    }
    for (k = 0; k < 15; k++) {
        slot = p + k * 0x1c;
        *(u32_021BBA94 *)(slot + 0x40) = 0;
        *(u32_021BBA94 *)(slot + 0x44) = 0;
        *(u8 *)(slot + 0x58) = 0xff;
        *(u32_021BBA94 *)(slot + 0x54) = BMP_WIN_Create(6, 3, (u8)(k * 4 + 1), 0x19, 2, 0xa, 1);
    }
    *(u32_021BBA94 *)(p + 0x2c) = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
    *(u32_021BBA94 *)(p + 0x30) = BMP_WIN_Create(4, 2, 9, 0x1c, 2, 0xa, 1);
    z = 0;
    *(u32_021BBA94 *)(p + 0x38) = z;
    *(u16 *)(p + 0x36) = z;
    for (z = 0; z < 3; z++) {
        p[z] = 0xff;
    }
    p[3] = 0xff;
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 6) = 0;
    p[0x14] = 0;
    p[0x15] = 0xff;
    *(u32_021BBA94 *)(p + 0x18) = 0xff;
    *(u32_021BBA94 *)(p + 0xc) = 0;
    *(u32_021BBA94 *)(p + 0x10) = 0;
    *(u32_021BBA94 *)(p + 0x20) = 0;
    *(u32_021BBA94 *)(p + 0x24) = 0;
    *(u32_021BBA94 *)(p + 0x28) = 0;
    *(u32_021BBA94 *)(p + 0x1c) = 0;
    *(u32_021BBA94 *)(p + 8) = 0;
    *(u16 *)(p + 0x34) = 0;
    BG_SYS_ResetSlot(6, 3, 0);
    if ((u32_021BBA94)(*(u32_021BBA94 *)(o + 4) - 2) <= 1 && COMM_TVT_SYS_GetHostBusy(a0) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 0xf);
        func_021BD134(a0, (char *)p, 0x18);
        *(u32_021BBA94 *)(p + 0x38) = 1;
        *(u32_021BBA94 *)(p + 0x18) = 3;
    }
}

void func_021BBE5C(void *a0, char *a1)
{
    u32_021BBE5C p;
    u8 i, j;

    if (((struct Obj03316 *)a1)->f1C != 0) {
        APP_TASKMENU_WIN_Delete((u8 *)(*(u32_021BBE5C *)&((struct Obj03316 *)a1)->f1C));
        *(u32_021BBE5C *)&((struct Obj03316 *)a1)->f1C = 0;
    }

    p = ((struct Obj03316 *)a1)->f2C;
    BMP_WIN_ClearScreen((struct Descriptor *)p);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03316 *)a1)->f2C));

    p = ((struct Obj03316 *)a1)->f30;
    BMP_WIN_ClearScreen((struct Descriptor *)p);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03316 *)a1)->f30));

    CLACT_DeleteActor((struct Obj *)(((struct Obj03316 *)a1)->f404));
    CLACT_DeleteActor((struct Obj *)(((struct Obj03316 *)a1)->f400));

    for (i = 0; i < 0xf; i++) {
        char *q = a1 + i * 0x1c;

        BMP_WIN_Delete((struct Descriptor *)(((struct Obj08261 *)q)->f54));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f50));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f4C));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f48));
    }

    for (j = 0; j < 0xf; j++)
        func_020307B0((void *)(*(u32_021BBE5C *)(a1 + j * 0x24 + 0x1f8)));

    BG_SYS_ClearSlot(6);
    func_020409B4(6);
    BG_SYS_ResetSlot(6, 3, 0);
    BG_SYS_ClearSlot(4);
    func_020409B4(4);
    BG_SYS_ResetSlot(4, 3, 0);
}

/*
 * 2026-10-04 (D3-06): byte-identical (1724 bytes); 4 of 106 relocations wait on
 *   unlabelled ov172 Thumb leaves filed EXACT this wave as src/matched/ov/
 *   ov172_func_021B8B7C.c, ov172_func_021B8C14.c, ov172_func_021B8C20.c,
 *   ov172_func_021BE0F0.c. After the integrator manifest gives them shard
 *   witnesses, this file should verify EXACT and move to src/matched/ov.
 *   Keys: cnt is block-local in the fC==1 block (sets its stack slot);
 *   case 6 jumps into case 10 by tail merge (code written twice).
 */
int func_021BBF2C(void *a0, char *p)
{
    u32_021BBF2C t;
    u16 v;
    u32_021BBF2C *st;
    u32_021BBF2C t2;
    u8 i, j;
    char *r;
    char *q;
    u8 *ip;
    u32_021BBF2C w;
    struct Descriptor *d;

    v = COMM_TVT_SYS_GetHeapId(a0);
    st = (u32_021BBF2C *)COMM_TVT_SYS_GetLaunchParams(a0);
    switch (W(8)) {
    case 0:
        if (COMM_TVT_SYS_GetReturnedFromChild(a0) == 1)
            WIPE_SYS_Start((void *)0, 1, 1, 0, 6, 1, v);
        else
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, v);
        W(8) = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            u32_021BBF2C *s = (u32_021BBF2C *)COMM_TVT_SYS_GetLaunchParams(a0);
            if (COMM_TVT_SYS_GetHostBusy(a0) == 1)
                W(8) = 11;
            else if (s[1] == 2 || s[1] == 3)
                W(8) = 8;
            else
                W(8) = 5;
        }
        break;
    case 2:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 6, 1, v);
        COMM_TVT_SYS_SetReturnedFromChild(a0, 0);
        W(8) = 4;
        break;
    case 3:
        if (CTVT_CAMVIEW_IsShutterIdle((int)a0, (char *)COMM_TVT_SYS_GetCamView(a0)) == 1) {
            WIPE_SYS_Start((void *)0, 0, 0, 0, 6, 1, v);
            COMM_TVT_SYS_SetReturnedFromChild(a0, 0);
            W(8) = 4;
        }
        break;
    case 4:
        if (WIPE_SYS_EndCheck() == 1) {
            if (W(0x18) == 0 || W(0x18) == 5)
                return 4;
            return 1;
        }
        break;
    case 5:
        func_021BC5E8(a0, (u8 *)p);
        func_021BD038(a0, p);
        break;
    case 6:
        if (W(0x18) == 0 || W(0x18) == 5) {
            if (CLACT_IsActorAnimActive((struct Actor *)OBJ) == 0) {
                CTVT_CAMVIEW_StopCapture((int)a0, (char *)COMM_TVT_SYS_GetCamView(a0));
                W(0x18) = 0;
                W(8) = 3;
            }
            break;
        }
        if (APP_TASKMENU_WIN_IsFinish((void *)W(0x1c)) != 1)
            break;
        if (W(0x18) == 2) {
            t = COMM_TVT_SYS_GetComm(a0);
            CTVT_COMM_SetRequestedMode((int)a0, (char *)t, 4);
            CTVT_COMM_SetConnectMac((int)a0, (char *)t, (const u8 *)(p + 0x1fd + B(3) * 0x24));
            func_021BD134(a0, p, 0x18);
            W(0x38) = 1;
            W(8) = 7;
            H(0x34) = 0;
            H(0x36) = 0;
            APP_TASKMENU_WIN_Delete((void *)W(0x1c));
            W(0x1c) = 0;
        } else {
            t2 = COMM_TVT_SYS_GetComm(a0);
            W(8) = 9;
            func_021BD134(a0, p, 0x14);
            W(0x38) = 1;
            H(0x36) = 0;
            CTVT_COMM_SetRequestedMode((int)a0, (char *)t2, 3);
            APP_TASKMENU_WIN_Delete((void *)W(0x1c));
            W(0x1c) = 0;
            ip = CTVT_COMM_GetMyStatusPtr(a0, (u8 *)t2);
            for (i = 0; i < 3; i++) {
                if (B(i) == 0xff) {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = 0xff;
                } else {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = *(u8 *)(p + B(i) * 0x24 + j + 0x1fd);
                }
            }
            ip[0x21] |= 2;
            CTVT_COMM_ResetSlotTimer(a0, (u8 *)t2);
        }
        CLACT_SetActorAnimSeq(OBJ, 0xf);
        break;
    case 7:
    case 8:
    case 9:
        COMM_TVT_SYS_GetComm(a0);
        if (COMM_TVT_SYS_GetMemberCount(a0) >= 2) {
            if (W(0x28) == 0) {
                t = COMM_TVT_SYS_GetCamView(a0);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x73e);
                CTVT_CAMVIEW_RequestShutterSound0((int)a0, (char *)t);
            }
            W(8) = 2;
        }
        if (W(8) == 9) {
            H(0x36)++;
            if (H(0x36) >= 0x78) {
                H(0x36) = 0;
                GFL_USE_PlaySeInSlot((void *)0x73d, 2);
            }
        }
        if (W(8) == 9) {
            if (CTVT_COMM_IsSlotTimerDone(a0, (u8 *)COMM_TVT_SYS_GetComm(a0)) == 1) {
                CTVT_COMM_SetRequestedMode((int)a0, (char *)COMM_TVT_SYS_GetComm(a0), 2);
                func_021BD134(a0, p, 0x27);
                W(8) = 10;
            }
        } else if (W(8) == 7 || W(8) == 8) {
            H(0x34)++;
            if (H(0x34) >= 0x4b0) {
                CTVT_COMM_SetRequestedMode((int)a0, (char *)COMM_TVT_SYS_GetComm(a0), 2);
                func_021BD134(a0, p, 0x28);
                W(8) = 10;
            }
        }
        break;
    case 10:
        if (TOUCHPANEL_GetTrg() == 1) {
            if (((u32_021BBF2C *)COMM_TVT_SYS_GetLaunchParams(a0))[1] == 2) {
                CTVT_CAMVIEW_StopCapture((int)a0, (char *)COMM_TVT_SYS_GetCamView(a0));
                W(0x18) = 0;
                W(8) = 3;
            } else {
                for (i = 0; i < 3; i++)
                    B(i) = 0xff;
                W(8) = 5;
                B(3) = 0xff;
                func_0201F7A8((void *)W(0x30), 1);
                d = (struct Descriptor *)W(0x30);
                BMP_WIN_ClearScreen(d);
                func_020409B4(BMP_WIN_GetBgLayer(d));
                COMM_TVT_SYS_DeleteTimeIcon(a0);
                CLACT_SetActorAnimSeq(OBJ, 1);
                W(0x18) = 4;
            }
        }
        break;
    case 11:
        BMP_WIN_Delete((struct Descriptor *)W(0x2c));
        W(0x2c) = BMP_WIN_Create(4, 2, 5, 0x1c, 0xe, 0xa, 1);
        func_021BD0C4(a0, p, 0x29);
        W(8) = 12;
        break;
    case 12:
        if (COMM_TVT_SYS_GetMemberCount(a0) >= 2 && W(0x28) == 0) {
            GFL_USE_StopAllSe();
            W(0x28) = 1;
            GFL_USE_PlaySeDefaultVolume(0x73e);
        }
        if (TOUCHPANEL_GetTrg() == 1 || COMM_TVT_SYS_GetEndRequested(a0) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_0201F7A8((void *)W(0x2c), 1);
            d = (struct Descriptor *)W(0x2c);
            BMP_WIN_ClearScreen(d);
            func_020409B4(BMP_WIN_GetBgLayer(d));
            BMP_WIN_Delete((struct Descriptor *)W(0x2c));
            W(0x2c) = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
            COMM_TVT_SYS_ClearHostBusy(a0);
            if (st[1] == 2 || st[1] == 3) {
                CLACT_SetActorAnimSeq(OBJ, 0xf);
                if (COMM_TVT_SYS_GetMemberCount(a0) < 2)
                    func_021BD134(a0, p, 0x18);
                W(0x38) = 1;
                W(0x18) = 3;
                W(8) = 8;
            } else {
                W(8) = 5;
                W(0x18) = 4;
                CLACT_SetActorAnimSeq(OBJ, 1);
                v = COMM_TVT_SYS_GetHeapId(a0);
                w = COMM_TVT_SYS_GetArc(a0);
                func_02049658((void *)w, 0xb, 4, 0, 0x2800, 0, v);
                func_020498F4((void *)w, 0x12, 4, 0, 0, 0, v);
                func_020409B4(4);
            }
        }
        break;
    }
    if (st[1] != 3 && COMM_TVT_SYS_GetHostBusy(a0) == 0) {
        func_021BC7FC(a0, (u8 *)p);
        for (i = 0; i < 15; i++) {
            r = p + i * 0x1c;
            if (*(u32_021BBF2C *)(r + 0x44) == 1) {
                struct PrintSys *ps = (struct PrintSys *)COMM_TVT_SYS_GetPrintQue(a0);
                if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp(*(struct Descriptor **)(r + 0x54))) == 0) {
                    d = *(struct Descriptor **)(r + 0x54);
                    BMP_WIN_TransferChars(d);
                    BMP_WIN_MakeScreen((struct Cfg *)d);
                    func_02041B6C(BMP_WIN_GetBgLayer(d));
                    *(u32_021BBF2C *)(r + 0x44) = 0;
                }
            }
        }
        if (W(0xc) == 1) {
            u8 cnt = 0;
            for (i = 0; i < 15; i++)
                func_021BCE2C(a0, p, p + 0x40 + i * 0x1c, i);
            BG_SYS_ResetSlot(6, 3, H(4));
            for (i = 0; i < 3; i++) {
                if (B(i) != 0xff)
                    cnt++;
            }
            for (j = 0; j < 15; j++) {
                r = p + j * 0x24;
                if (*(u32_021BBF2C *)(r + 0x1e4) == 1) {
                    q = p + 0x40 + *(u8 *)(r + 0x204) * 0x1c;
                    if (*(u32_021BBF2C *)(r + 0x1ec) == 1 && *(u8 *)(r + 0x203) < 4 && (B(3) == 0xff || B(3) == j))
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 0xa);
                    else if (cnt == 3 || B(3) != 0xff || *(u8 *)(r + 0x203) == 4)
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 0xb);
                    else
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 9);
                    if (*(u32_021BBF2C *)(r + 0x1f4) == 1) {
                        *(u32_021BBF2C *)(r + 0x1f4) = 0;
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 8), 0x22);
                    }
                }
            }
            W(0xc) = 0;
        }
    }
    if (W(0x20) == 1) {
        struct PrintSys *ps = (struct PrintSys *)COMM_TVT_SYS_GetPrintQue(a0);
        if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp((struct Descriptor *)W(0x2c))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)W(0x2c));
            BMP_WIN_MakeScreen((struct Cfg *)W(0x2c));
            func_020409B4(4);
            W(0x20) = 0;
        }
    }
    if (W(0x24) == 1) {
        struct PrintSys *ps = (struct PrintSys *)COMM_TVT_SYS_GetPrintQue(a0);
        if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp((struct Descriptor *)W(0x30))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)W(0x30));
            BMP_WIN_MakeScreen((struct Cfg *)W(0x30));
            func_020409B4(4);
            W(0x24) = 0;
            if (W(0x38) == 1) {
                W(0x38) = 0;
                COMM_TVT_SYS_CreateTimeIcon(a0, (void *)W(0x30));
            }
        }
    }
    if (W(0x1c) != 0)
        APP_TASKMENU_WIN_Update((void *)W(0x1c));
    return 2;
}

void func_021BC5E8(void *ctx, u8 *list)
{
    u32_021BC5E8 tx;
    u32_021BC5E8 ty;
    u32_021BC5E8 dx;
    u32_021BC5E8 dy;
    struct SpritePos pos;
    int trg;
    int cont;
    s16 row;
    u8 id;
    u8 *e;
    int done;
    u8 i;
    int s;
    u32_021BC5E8 range;

    trg = TOUCHPANEL_GetPointTrg(&tx, &ty);
    cont = TOUCHPANEL_GetPointCont(&dx, &dy);
    COMM_TVT_SYS_GetComm(ctx);
    if (trg == 1) {
        if (tx > 8 && tx < 0xe0) {
            row = (ty + ((struct Obj00330 *)list)->f4) >> 5;
            if (row >= 0 && row < 15) {
                id = *(list + row * 0x1c + 0x58);
                e = list + 0x1e4 + id * 0x24;
                done = 0;
                if (((struct Obj01950 *)e)->f0 == 1 && e[0x1f] < 4) {
                    if (e[0x18] == 0x20) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            list[3] = id;
                            done = 1;
                            ((struct Obj01950 *)e)->f8 = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73b);
                        } else {
                            list[3] = 0xff;
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    } else if (list[3] == 0xff) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            for (i = 0; i < 3; i++) {
                                if (list[i] == 0xff) {
                                    list[i] = id;
                                    break;
                                }
                            }
                            if (i < 3) {
                                done = 1;
                                ((struct Obj01950 *)e)->f8 = 1;
                                ((struct Obj01950 *)e)->f10 = 1;
                                ((struct Obj00330 *)list)->fC = 1;
                                GFL_USE_PlaySeDefaultVolume(0x73b);
                            }
                        } else {
                            for (i = 0; i < 3; i++) {
                                if (id == list[i]) {
                                    list[i] = 0xff;
                                    break;
                                }
                            }
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    }
                }
                if (done == 1)
                    func_021BCEF8(ctx, list);
            }
        } else if (tx >= 0xec && tx <= 0x104 && ty >= ((struct Obj00330 *)list)->f6 + 0xc
                   && ty <= ((struct Obj00330 *)list)->f6 + 0x24 && list[0x14] > 5) {
            ((struct Obj00330 *)list)->f10 = 1;
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f404), 0xd);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (cont == 1 && ((struct Obj00330 *)list)->f10 == 1 && list[0x14] > 5) {
        if (dx >= 0xec && dx <= 0x104 && dy >= 0xc && dy <= 0x9c) {
            range = (list[0x14] - 5) * 32;
            s = dy - 0x18;
            if (s < 0)
                s = 0;
            else if (s > 0x78)
                s = 0x78;
            ((struct Obj00330 *)list)->f6 = s;
            pos.x = 0xf8;
            pos.y = ((struct Obj00330 *)list)->f6 + 0x18;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00330 *)list)->f404), (const struct Vec2 *)(&pos), 1);
            ((struct Obj00330 *)list)->f4 = ((struct Obj00330 *)list)->f6 * range / 0x78;
            ((struct Obj00330 *)list)->fC = 1;
        }
    } else {
        ((struct Obj00330 *)list)->f10 = 0;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f404), 0xc);
    }
    if (((struct Obj00330 *)list)->f1C != 0 && APP_TASKMENU_WIN_IsTouch((void **)(((struct Obj00330 *)list)->f1C)) == 1) {
        APP_TASKMENU_WIN_SetDecide((char *)(((struct Obj00330 *)list)->f1C), 1);
        ((struct Obj00330 *)list)->f8 = 6;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (((struct Obj00330 *)list)->f18 == 1)
            GFL_USE_PlaySeInSlot((void *)0x73d, 2);
    }
    if (!TOUCHPANEL_HitTrg(d_021C7040) || (KEY_GetTrg() & 2)) {
        ((struct Obj00330 *)list)->f8 = 6;
        ((struct Obj00330 *)list)->f18 = 5;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f400), 9);
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
void func_021BC7FC(void *ctx, u8 *list)
{
    int changed;
    int refresh;
    int found;
    int diff;
    struct Rec *p;
    u8 kind;
    u32_021BC7FC a;
    u32_021BC7FC c;
    int match;
    u8 slot;
    int j;
    int i;
    u8 k;
    u8 m;
    u8 r;
    u8 *e;
    u8 *row;
    u8 *mac;
    u32_021BC7FC mode;
    int ok;
    u32_021BC7FC b;
    u8 buf[8];
    u8 q;

    changed = 0;
    refresh = 0;
    if (!CTVT_COMM_IsNetReady(ctx, (void *)COMM_TVT_SYS_GetComm(ctx)))
        return;
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32_021BC7FC *)(e + 0x1e4) == 1)
            *(u32_021BC7FC *)(e + 0x1e8) = 1;
    }
    mode = *(u32_021BC7FC *)(list + 8);
    if (mode != 7 && mode != 9 && mode != 10 && (int)mode >= 5) {
        for (j = 0; j < 16; j++) {
            found = 0;
            diff = 0;
            p = (struct Rec *)GFL_NET_GetScanResult(j);
            if (p == 0)
                continue;
            slot = 0xff;
            mac = GFL_NET_GetScanResultMac(j);
            kind = NET_WHPIPE_GetEntryBeaconKind(j);
            if (kind == 3 && ((struct Bits2 *)((u8 *)p + 2))->b1 != 2)
                continue;
            ok = 0;
            if (kind == 0x20) {
                a = (u32_021BC7FC)func_020084F4(p);
                b = func_02008550((const struct Sub0200852CObj *)p);
                c = func_02008530((const struct Sub0200852CObj *)p);
                OS_GetMacAddress(buf);
                if (p->f21_1 == 0 || CTVT_COMM_FindPeerName((u8 *)p, buf) == 1)
                    ok = func_021BD0A4(ctx, (u32_021BC7FC)list, a, c, b);
            } else if (ZONEDATA_IsZone117((u16)p->fC_17) == 0 && ZONEDATA_IsZoneGroup118To120((u16)p->fC_17) == 0) {
                ok = func_021BD0A4(ctx, (u32_021BC7FC)list, (u32_021BC7FC)((u8 *)p + 0x1a), p->f4, p->bB_7);
            }
            if (ok == 0)
                continue;
            for (k = 0; k < 15; k++) {
                e = list + k * 0x24;
                if (*(u32_021BC7FC *)(e + 0x1e4) == 1) {
                    match = 1;
                    for (m = 0; m < 6; m++) {
                        if (mac[m] != e[m + 0x1fd]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        ((struct List *)list)->slots[k].unseen = 0;
                        found = 1;
                        if (kind != ((struct List *)list)->slots[k].kind) {
                            found = 0;
                            diff = 1;
                            slot = k;
                            for (m = 0; m < 3; m++) {
                                if (k == list[m]) {
                                    list[m] = 0xff;
                                    refresh = 1;
                                }
                            }
                            if (list[3] == k) {
                                list[3] = 0xff;
                                refresh = 1;
                            }
                        }
                        if (kind == 0x20 && (*(u8 **)(e + 0x1f8))[0x20] != p->f20) {
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
            e = list + slot * 0x24;
            *(u32_021BC7FC *)(e + 0x1e4) = 1;
            *(u32_021BC7FC *)(e + 0x1e8) = 0;
            *(u32_021BC7FC *)(e + 0x1ec) = 0;
            for (m = 0; m < 6; m++)
                e[m + 0x1fd] = mac[m];
            if (kind == 0x20) {
                ((struct List *)list)->slots[slot].kind = 0x20;
                MI_CpuCopy8(p, ((struct List *)list)->slots[slot].buf, 0x34);
            } else {
                ((struct List *)list)->slots[slot].kind = 3;
                MI_CpuCopy8(p, ((struct List *)list)->slots[slot].buf, 0x64);
            }
            if (diff == 0) {
                for (r = 0; r < 15; r++) {
                    row = list + r * 0x1c;
                    if (row[0x58] == 0xff) {
                        row[0x58] = slot;
                        e[0x204] = r;
                        *(u32_021BC7FC *)(row + 0x40) = 1;
                        break;
                    }
                }
            } else {
                *(u32_021BC7FC *)(list + e[0x204] * 0x1c + 0x40) = 1;
            }
            changed = 1;
        }
    }
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32_021BC7FC *)(e + 0x1e4) == 1 && *(u32_021BC7FC *)(e + 0x1e8) == 1) {
            q = e[0x204];
            for (; q < 14; q++) {
                row = list + q * 0x1c;
                if (row[0x74] == 0xff)
                    break;
                row[0x58] = row[0x74];
                list[row[0x58] * 0x24 + 0x204] = q;
                *(u32_021BC7FC *)(row + 0x40) = 1;
            }
            row = list + q * 0x1c;
            row[0x58] = 0xff;
            *(u32_021BC7FC *)(row + 0x40) = 1;
            e[0x204] = 0xff;
            *(u32_021BC7FC *)(e + 0x1e4) = 0;
            for (m = 0; m < 3; m++) {
                if (i == list[m]) {
                    list[m] = 0xff;
                    refresh = 1;
                }
            }
            if (list[3] == i) {
                list[3] = 0xff;
                refresh = 1;
            }
            i--;
            changed = 1;
        }
    }
    if (changed == 1) {
        func_021BCB88(ctx, (char *)list);
        refresh = 1;
        *(u32_021BC7FC *)(list + 0xc) = 1;
    }
    if (refresh == 1 && *(u32_021BC7FC *)(list + 8) == 5)
        func_021BCEF8(ctx, list);
}

void func_021BCB88(void *ctx, char *list)
{
    struct SpritePos pos;
    u8 n = 0;
    u8 i;
    u32_021BCB88 range;

    for (i = 0; i < 15; i++)
        func_021BCC40(ctx, list, list + 0x40 + i * 0x1c, i);
    for (i = 0; i < 15; i++) {
        if (*(u8 *)(list + i * 0x1c + 0x58) != 0xff)
            n++;
    }
    if (((struct Obj01951 *)list)->f14 == n)
        return;
    if (n > 5) {
        range = (n - 5) * 32;
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01951 *)list)->f404, 1);
        if (((struct Obj01951 *)list)->f4 > range)
            ((struct Obj01951 *)list)->f4 = range;
        ((struct Obj01951 *)list)->f6 = ((struct Obj01951 *)list)->f4 * 0x78 / range;
        if (((struct Obj01951 *)list)->f10 == 0) {
            pos.x = 0xf8;
            pos.y = ((struct Obj01951 *)list)->f6 + 0x18;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01951 *)list)->f404), (const struct Vec2 *)(&pos), 1);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01951 *)list)->f404, 0);
        ((struct Obj01951 *)list)->f4 = 0;
        ((struct Obj01951 *)list)->fC = 1;
    }
    ((struct Obj01951 *)list)->f14 = n;
}

static inline u8 func_021BCC40_show(u32_021BCC40 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}

void func_021BCC40(void *ctx, char *list, char *row, int idx)
{
    u32_021BCC40 buf2;
    u32_021BCC40 fmt2;
    u32_021BCC40 msgs;
    u32_021BCC40 sys;
    u32_021BCC40 str;
    u32_021BCC40 buf;
    u8 *p;
    u32_021BCC40 heap;
    u32_021BCC40 fmt;
    u32 font;
    char *e;
    u32_021BCC40 ws;

    if (((struct Obj02882 *)row)->f0 != 1)
        return;
    if (((struct Obj02882 *)row)->f18 != 0xff) {
        heap = COMM_TVT_SYS_GetHeapId(ctx);
        font = COMM_TVT_SYS_GetFont(ctx);
        msgs = COMM_TVT_SYS_GetMsgData(ctx);
        sys = COMM_TVT_SYS_GetPrintQue(ctx);
        e = list + 0x1e4 + ((struct Obj02882 *)row)->f18 * 0x24;
        ws = (u32_021BCC40)GF_FONT_Create_EC64(heap);
        BMP_Clear((struct CharBuf *)((u32_021BCC40)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14)), 0);
        str = (u32_021BCC40)STRBUF_Create(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            STRBUF_SetStringN((struct Strbuf *)str, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(((struct Obj01166 *)e)->f14), 8);
        else
            STRBUF_SetStringN((struct Strbuf *)str, (const u16 *)(*(char * *)&((struct Obj01166 *)e)->f14 + 0x1a), 8);
        PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 6, 0, (void *)str, font, 0x3c40);
        STRBUF_Delete((struct U16Vec *)str);
        fmt = (u32_021BCC40)func_02045EC0((struct MsgBank *)msgs, 0xe);
        buf = (u32_021BCC40)STRBUF_Create(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            func_0201EFA4((struct WordSet *)ws, 0, COMM_PLAYER_SUPPORT_GetRecordField(((struct Obj01166 *)e)->f14), 5, 2, 1);
        else
            func_0201EFA4((struct WordSet *)ws, 0, ((struct Obj24102 *)(*(char * *)&((struct Obj01166 *)e)->f14))->f18, 5, 2, 1);
        func_0201F250((struct WordSet *)ws, (void *)buf, (void *)fmt);
        STRBUF_Delete((struct U16Vec *)fmt);
        PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x50, 0, (void *)buf, font, 0x3c40);
        STRBUF_Delete((struct U16Vec *)buf);
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            p = *(u8 * *)&((struct Obj01166 *)e)->f14;
            ((struct Obj01166 *)e)->f1F = p[0x20];
            fmt2 = (u32_021BCC40)func_02045EC0((struct MsgBank *)msgs, 0x10);
            buf2 = (u32_021BCC40)STRBUF_Create(0x20, heap);
            p += 0x20;
            func_0201EFA4((struct WordSet *)ws, 0, *p, 1, 0, 1);
            func_0201F250((struct WordSet *)ws, (void *)buf2, (void *)fmt2);
            STRBUF_Delete((struct U16Vec *)fmt2);
            PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x90, 0, (void *)buf2, font, 0x3c40);
            STRBUF_Delete((struct U16Vec *)buf2);
        } else {
            ((struct Obj01166 *)e)->f1F = 0;
        }
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            if ((*(struct FlagsA * *)&((struct Obj01166 *)e)->f14)->on == 1)
                ((struct Obj01166 *)e)->fC = 1;
            else
                ((struct Obj01166 *)e)->fC = 0;
        } else if ((*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b7 == 1 && (*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b6 == 0) {
            ((struct Obj01166 *)e)->fC = 1;
        } else {
            ((struct Obj01166 *)e)->fC = 0;
        }
        WORDSET_DeleteStrbufED04((struct WordSet *)ws);
        ((struct Obj02882 *)row)->f4 = 1;
    } else {
        func_02041B6C(func_021BCC40_show(((struct Obj02882 *)row)->f14));
    }
    ((struct Obj02882 *)row)->f0 = 0;
}

/*
 * Places the three cursor sprites (+0x8, +0xc, +0x10) on list row idx relative to the scroll offset at +4: hidden when no row is selected (+0x18 == 0xff) or the row is off screen; the third sprite shows only when the selected entry's flag at +0x1f0 is set, animated from the row's cell at +0x50.
 */
void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx)
{
    struct SpritePos pos;
    s16 y;

    if (((struct Obj01560 *)cur)->f18 == 0xff) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        return;
    }
    y = idx * 32 - ((struct Obj24103 *)list)->f4;
    if (y >= -32 && y <= 0xa0) {
        pos.x = 0x80;
        pos.y = y + 0x10;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->f8), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 1);
        pos.x = 0x12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->fC), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 1);
        pos.x = 0xc8;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->f10), (const struct Vec2 *)(&pos), 1);
        if (*(u32_021BCE2C *)(list + ((struct Obj01560 *)cur)->f18 * 0x24 + 0x1f0) == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(*(u32_021BCE2C *)(list + idx * 0x1c + 0x50)), 0x12);
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 1);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        }
        return;
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
}

static inline u8 func_021BCEF8_show(u32_021BCEF8 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}

/*
 * Keeps the button prompt (+0x1c, kind at +0x18) in step with the selection: a fourth selected slot shows prompt 0x13 (kind 2), any selected slot shows prompt 0x12 (kind 1), none removes the prompt (kind 0) and reprints message 0x11 when the mode byte at +0x14 is set.
 */
void func_021BCEF8(void *ctx, u8 *st)
{
    u8 n = 0;
    u8 i;
    u16 heap = COMM_TVT_SYS_GetHeapId(ctx);
    u32_021BCEF8 msgs = COMM_TVT_SYS_GetMsgData(ctx);
    u32_021BCEF8 sys = COMM_TVT_SYS_GetTaskMenu(ctx);

    for (i = 0; i < 3; i++) {
        if (st[i] != 0xff)
            n++;
    }
    if (st[3] != 0xff) {
        if (((struct Obj00543 *)st)->f18 != 2) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            func_0201F7A8((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32_021BCEF8)func_02045EC0((struct MsgBank *)msgs, 0x13);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = APP_TASKMENU_WIN_Create(sys, (u32_021BCEF8)(&p), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 2;
        }
    } else if (n != 0) {
        if (((struct Obj00543 *)st)->f18 != 1) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            func_0201F7A8((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32_021BCEF8)func_02045EC0((struct MsgBank *)msgs, 0x12);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = APP_TASKMENU_WIN_Create(sys, (u32_021BCEF8)(&p), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 1;
        }
    } else if (((struct Obj00543 *)st)->f18 != 0) {
        if (((struct Obj00543 *)st)->f1C != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
            ((struct Obj00543 *)st)->f1C = 0;
        }
        if (st[0x14] != 0)
            func_021BD0C4(ctx, (char *)st, 0x11);
        ((struct Obj00543 *)st)->f18 = 0;
    }
}

static inline u8 func_021BD038_show(u32_021BD038 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}

void func_021BD038(void *ctx, char *st)
{
    if (((struct Obj01266 *)st)->f14 == ((struct Obj01266 *)st)->f15)
        return;
    if (((struct Obj01266 *)st)->f14 == 0) {
        func_021BD134(ctx, st, 0x1c);
        ((struct Obj01266 *)st)->f38 = 1;
        func_02041B6C(func_021BD038_show(((struct Obj01266 *)st)->f2C));
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f2C), 1);
    } else if (((struct Obj01266 *)st)->f15 == 0 && ((struct Obj01266 *)st)->f14 != 0) {
        func_021BD0C4(ctx, st, 0x11);
        COMM_TVT_SYS_DeleteTimeIcon(ctx);
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f30), 1);
        func_020409B4(func_021BD038_show(((struct Obj01266 *)st)->f30));
    }
    ((struct Obj01266 *)st)->f15 = ((struct Obj01266 *)st)->f14;
}

int func_021BD0A4(void *ctx, u32_021BD0A4 unused, u32_021BD0A4 a, u32_021BD0A4 b, u32_021BD0A4 c)
{
    return func_02009D50((struct Sub020097BCObj *)GAME_DATA_GetField1A0((const struct BigObj *)(*((u32_021BD0A4 *)COMM_TVT_SYS_GetLaunchParams(ctx)))), (const void *)a, b, c, 0);
}

#undef W

#undef W

#undef W

#undef W

#define W(o) (*(u32_021BD1AC *)(self + (o)))

#undef B

#undef B

#undef B

#undef B

#define B(o) (*(u8 *)(self + (o)))

void func_021BD0C4(void *a0, char *a1, int a2)
{
    u32_021BD0C4 x = COMM_TVT_SYS_GetFont(a0);
    u32_021BD0C4 y = COMM_TVT_SYS_GetMsgData(a0);
    u32_021BD0C4 z = COMM_TVT_SYS_GetPrintQue(a0);
    u32_021BD0C4 w;

    BMP_Clear((struct CharBuf *)((u32_021BD0C4)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00543 *)a1)->f2C)), 0xf);
    w = (u32_021BD0C4)func_02045EC0((struct MsgBank *)y, a2);
    PRINTSYS_PrintQueColor((void *)z, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00543 *)a1)->f2C), 0, 0, (void *)w, x, 0x440);
    STRBUF_Delete((struct U16Vec *)w);
    func_0201F73C((void *)(((struct Obj00543 *)a1)->f2C), 2, 0x140, 9);
    ((struct Obj00543 *)a1)->f20 = 1;
}

void func_021BD134(void *ctx, char *st, u32_021BD134 msgId)
{
    u32_021BD134 font = COMM_TVT_SYS_GetFont(ctx);
    u32_021BD134 msgs = COMM_TVT_SYS_GetMsgData(ctx);
    u32_021BD134 sys = COMM_TVT_SYS_GetPrintQue(ctx);
    u32_021BD134 str;

    BMP_Clear((struct CharBuf *)((u32_021BD134)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01266 *)st)->f30)), 0xf);
    str = (u32_021BD134)func_02045EC0((struct MsgBank *)msgs, msgId);
    PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01266 *)st)->f30), 0, 0, (void *)str, font, 0x440);
    STRBUF_Delete((struct U16Vec *)str);
    func_0201F73C((void *)(((struct Obj01266 *)st)->f30), 2, 0x140, 9);
    ((struct Obj01266 *)st)->f24 = 1;
    ((struct Obj01266 *)st)->f38 = 0;
    COMM_TVT_SYS_DeleteTimeIcon(ctx);
}

#undef H

#undef H

#undef H

#undef H

#define H(o) (*(u16 *)(self + (o)))

/*
 * note 2026-10-05 wD5 lane12: the loop argument and the two byte stores are the literal 0 (the
 *   original copies r5=0 into r6 before the loop label; it is not the last index).
 */
void func_021BD1AC(char *self)
{
    int z = 0;
    int one = 1;
    u8 i;
    u32_021BD1AC h2;
    Params st;
    B(0x18) = one;
    B(0x19) = z;
    W(0x1c) = z;
    func_021BD5D8((u8 *)self);
    func_021BD844((u8 *)self);
    func_021BDBC4((u8 *)self);
    W(0x1d4) = (u32_021BD1AC)APP_TASKMENU_RES_Create(4, 7, W(0x1c8), W(0x1d0), H(0));
    W(0x1e0) = (u32_021BD1AC)CTVT_CAMVIEW_Create(self, H(0));
    W(0x1e4) = (u32_021BD1AC)CTVT_COMM_Create(self, H(0));
    W(0x1e8) = (u32_021BD1AC)CTVT_TALK_Create(self, H(0));
    W(0x1ec) = (u32_021BD1AC)CTVT_DRAW_Create(self, H(0));
    W(0x1f0) = (u32_021BD1AC)func_021BBA6C((int)self, (void *)H(0));
    st.heap = H(0);
    st.kind = 2;
    st.count = 0x64;
    st.a = z;
    st.b = 0x100;
    st.c = z;
    st.d = 0xc0;
    W(0x1f4) = DRAW_SYSTEM_CreateCanvas(&st);
    W(4) = func_020056A0(func_021BD5AC, self, 8);
    W(8) = z;
    H(0x38) = z;
    H(0x3a) = z;
    W(0x10) = one;
    W(0x20) = z;
    W(0x24) = z;
    W(0x28) = z;
    W(0x2c) = z;
    W(0x30) = z;
    W(0x34) = z;
    if (func_0202EB14() == 1) W(0x30) = one;
    GFL_NET_RestartWithDefaultTimeout(0, H(0));
    switch (*(u32_021BD1AC *)(W(0x1f8) + 4)) {
    case 0:
        CTVT_COMM_SetRequestedMode((int)self, (char *)W(0x1e4), 3);
        W(0xc) = 1;
        break;
    case 1:
        CTVT_COMM_SetRequestedMode((int)self, (char *)W(0x1e4), 2);
        W(0xc) = 2;
        break;
    case 2:
        CTVT_COMM_SetRequestedMode((int)self, (char *)W(0x1e4), 4);
        CTVT_COMM_SetConnectMac((int)self, (char *)W(0x1e4), (const u8 *)(W(0x1f8) + 8));
        W(0xc) = 2;
        func_02028A70((struct SoundSys *)GAME_DATA_GetBgmInfo((const struct BigObj *)(*(u32_021BD1AC *)W(0x1f8))));
        break;
    case 3:
        CTVT_COMM_SetRequestedMode((int)self, (char *)W(0x1e4), 5);
        W(0xc) = 2;
        break;
    }
    W(0x1b8) = BMP_WIN_Create(0, 2, 10, 12, 2, 10, 1);
    W(0x1bc) = BMP_WIN_Create(0, 0x12, 10, 12, 2, 10, 1);
    W(0x1c0) = BMP_WIN_Create(0, 2, 0x16, 12, 2, 10, 1);
    W(0x1c4) = BMP_WIN_Create(0, 0x12, 0x16, 12, 2, 10, 1);
    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(u32_021BD1AC *)(self + i * 4 + 0x1b8))), 0);
    }
    B(0x1b4) = 0;
    B(0x1b5) = 0;
    GFL_USE_CancelChangeAndPlayBgm(0x3e9, 0xffff);
}

void func_021BD3B8(u8 *p)
{
    u8 i;
    for (i=0; i<4; i++) BMP_WIN_Delete((struct Descriptor *)(*(u32_021BD3B8 *)(p + i*4 + 0x1b8)));
    func_02030EAC((struct Node *)(((struct Obj03855 *)p)->f4));
    DRAW_SYSTEM_DeleteCanvas(*(char * *)&((struct Obj03855 *)p)->f1F4);
    func_021BBA88((int)p, ((struct Obj03855 *)p)->f1F0);
    CTVT_DRAW_Free((int)p, ((struct Obj03855 *)p)->f1EC);
    CTVT_TALK_Delete(p, *(char * *)&((struct Obj03855 *)p)->f1E8);
    CTVT_COMM_Delete(p, (char *)(((struct Obj03855 *)p)->f1E4));
    CTVT_CAMVIEW_Delete((int)p, (char *)(((struct Obj03855 *)p)->f1E0));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj03855 *)p)->f1D4));
    func_021BDC70((u32_021BD3B8 *)p);
    func_021BDB5C(p);
    func_021BD7D0(p);
}

#undef H

#undef H

#undef H

#undef H

#undef H

#define H(o) (*(u16 *)(ctx + (o)))

int func_021BD43C(char *ctx)
{
    u32_021BD43C idx;
    s32 v;
    u8 pal;

    CTVT_COMM_Main(ctx, (char *)F(0x1e4));
    switch (F(8)) {
    case 1:
        F(0xc) = CTVT_TALK_Main(ctx, (struct S *)F(0x1e8));
        break;
    case 2:
        F(0xc) = func_021BBF2C(ctx, (char *)F(0x1f0));
        break;
    case 3:
        F(0xc) = CTVT_DRAW_Main(ctx, (char *)F(0x1ec));
        break;
    case 4:
        if (CTVT_COMM_IsSessionEnded((int)ctx, (char *)F(0x1e4)) == 1 && CTVT_CAMVIEW_IsShutterIdle((int)ctx, (char *)F(0x1e0)) == 1) {
            return 1;
        }
        return 0;
    case 5:
        if (CTVT_COMM_IsSessionEnded((int)ctx, (char *)F(0x1e4)) == 1 && CTVT_CAMVIEW_IsShutterIdle((int)ctx, (char *)F(0x1e0)) == 1
            && WIPE_SYS_EndCheck() == 1) {
            return 1;
        }
        break;
    }
    if (F(0x14) == 1 && WIPE_SYS_EndCheck() == 1) {
        F(0xc) = 5;
    }
    if (F(8) != F(0xc)) {
        func_021BDCB8((u8 *)ctx);
    }
    CTVT_CAMVIEW_Update((int)ctx, (char *)F(0x1e0));
    DRAW_SYSTEM_Nop(F(0x1f4));
    CLACT_DrawSystem();
    PRINTSYS_QUE_Main((struct PrintSys *)F(0x1d0));
    func_021BDD6C((u8 *)ctx);
    H(0x38) += 0x200;
    idx = H(0x38) >> 4;
    v = (FX_SinCosTable_[idx * 2] + 0x1000) / 2 * 10;
    pal = (u8)(u32_021BD43C)((float)v / 4096.0f);
    if (pal >= 10) {
        pal = 9;
    }
    if (pal != H(0x3a)) {
        H(0x3a) = pal;
        NNS_GfdRegisterNewVramTransferTask((void *)0x1f, 0x40, (u32_021BD43C)(ctx + 0x3c + pal * 32), 0x20);
    }
    TCBL_Main((struct Tcbl *)F(0x1d8));
    sub_02040618(1, 0, func_02005728(0x100));
    sub_02040618(1, 3, func_02005728(0x100));
    return 0;
}

void func_021BD5AC(int unused, char *ctx)
{
    CTVT_CAMVIEW_UploadWindows(ctx, (struct Q *)(((struct Obj10666 *)ctx)->f1E0));
    CLACT_VBlankSystem();
    DRAW_SYSTEM_FlushStrokes((char *)(((struct Obj10666 *)ctx)->f1F4));
    CTVT_TALK_SetMicMode((int)ctx, (char *)(((struct Obj10666 *)ctx)->f1E8));
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

void func_021BD5D8(u8 *p)
{
    u32 size;
    u32 mode;
    struct Bank *bank;
    Cfg7 cfg;

    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C7120);
    BG_SYS_Create(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021C7050);
    func_021BD820((const struct BgTemplate *)d_021C70A0, 0, 0);
    func_021BD820((const struct BgTemplate *)d_021C7100, 1, 0);
    func_021BD820((const struct BgTemplate *)d_021C70C0, 4, 0);
    func_021BD820((const struct BgTemplate *)d_021C70E0, 5, 0);
    func_021BD820((const struct BgTemplate *)d_021C7080, 6, 0);
    func_021BD820((const struct BgTemplate *)d_021C7060, 7, 0);
    *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & 0x43) | 0x4484;
    *(volatile u16 *)0x0400000E = (*(volatile u16 *)0x0400000E & 0x43) | 0x4A84;
    size = 0x18000;
    MI_CpuFill8(G2_GetBG2ScrPtr(), 0, size);
    MI_CpuFill8((void *)G2_GetBG3ScrPtr(), 0, size);
    *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & ~3) | 1;
    *(volatile u16 *)0x0400000E = (*(volatile u16 *)0x0400000E & ~3) | 2;
    func_02040588(2, 1);
    mode = 3;
    func_02040588(mode, 1);
    cfg = gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&cfg), (u32)d_021C7120, *(u16 *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    bank = CLACT_CreateUnit(0x40, 0, *(u16 *)p);
    *(struct Bank **)(p + 0x1AC) = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | (mode << 13);
    inside0(0x1f, 1);
    inside1(0x1f, 1);
    outside(0x13, 1);
    *(volatile u16 *)0x04000040 = 0xff;
    *(volatile u16 *)0x04000044 = 0xc0;
    *(volatile u16 *)0x04000042 = 0x20 << 10;
    *(volatile u16 *)0x04000046 = 0xc0;
}

#undef W

#define W(o) (*(u32 *)(p + (o)))

/*
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD7D0(void *a0)
{
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj24105 *)a0)->f1AC)));
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(1);
    func_020403F4(0);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type)
{
    BG_SYS_InitBgLayer(bgId, tmpl, type);
    func_02040588(bgId, 1);
    func_020414AC(bgId);
    func_020409B4(bgId);
}

void func_021BD844(u8 *p)
{
    struct Sub0200852CObj *t;
    void *dev;
    u32 o;
    u32 i0;
    u32 i1;
    u32 i2;
    int z;
    struct CellCfg cfg;
    struct PltData *pal;
    t = (struct Sub0200852CObj *)func_02012944(*(void **)W(0x1f8));
    BG = func_020490F4(0xac, HEAP);
    if (func_02008550(t) == 0) {
        func_02049B68(BG, 7, 4, 0, 0xc0, HEAP);
    } else {
        func_02049B68(BG, 6, 4, 0, 0xc0, HEAP);
    }
    z = 0;
    func_02049658(BG, 0xb, 7, 0, z, z, HEAP);
    func_020498F4(BG, 0xe, 7, 0, z, z, HEAP);
    func_020409B4(7);
    func_02049B68(BG, 0, 0, 0x20, 0x20, HEAP);
    func_02049658(BG, 8, 1, 0, z, z, HEAP);
    func_020498F4(BG, 0xd, 1, 0, z, z, HEAP);
    func_020409B4(1);
    W(0x180) = CLACT_RegisterPaletteCompressed(BG, 3, 0, 0, HEAP);
    W(0x190) = CLACT_RegisterCharacter(BG, 0x18, 0, 0, HEAP);
    W(0x1a0) = CLACT_RegisterCellAnim(BG, 0x14, 0x16, HEAP);
    W(0x184) = CLACT_RegisterPaletteCompressed(BG, 3, 1, 0, HEAP);
    W(0x194) = CLACT_RegisterCharacter(BG, 0x17, 0, 1, HEAP);
    W(0x1a4) = CLACT_RegisterCellAnim(BG, 0x13, 0x15, HEAP);
    dev = func_020490F4(func_020275E4(), HEAP);
    func_02049B68(dev, func_02027624(), 0, 0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 0, 0, z, z, HEAP);
    func_02049B68(dev, func_02027624(), 4, 0xc0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 5, z, z, z, HEAP);
    func_020498F4(dev, func_0202762C(), 5, z, z, z, HEAP);
    func_020413B0(5, z, 0x15, 0x20, 3, 6);
    func_020409B4(5);
    W(0x18c) = CLACT_RegisterPaletteEx(dev, func_02027614(), z, 0xe0, z, 3, HEAP);
    W(0x19c) = CLACT_RegisterCharacter(dev, func_02027618(), z, z, HEAP);
    W(0x188) = CLACT_RegisterPaletteEx(dev, func_02027614(), 1, 0xe0, z, 3, HEAP);
    W(0x198) = CLACT_RegisterCharacter(dev, func_02027618(), z, 1, HEAP);
    W(0x1a8) = CLACT_RegisterCellAnim(dev, func_0202761C(2), func_02027620(2), HEAP);
    ARC_TOOL_DeleteHandle(dev);
    cfg.a = z;
    cfg.b = z;
    cfg.c = z;
    cfg.d = z;
    cfg.e = z;
    o = COMM_TVT_SYS_GetClactUnit(p);
    i0 = COMM_TVT_SYS_GetResId(p, 4);
    i1 = COMM_TVT_SYS_GetResId(p, z);
    i2 = COMM_TVT_SYS_GetResId(p, 8);
    W(0x1b0) = (u32)CLACT_CreateActor((void *)o, i0, i1, i2, &cfg, z, HEAP);
    CLACT_SetActorDrawEnable((void *)W(0x1b0), z);
    CLACT_SetActorAutoAnim((void *)W(0x1b0), 1);
    if (func_02008550(t) == 0) {
        dev = func_02049F78(BG, 7, (u32)(&pal), HEAP);
    } else {
        dev = func_02049F78(BG, 6, (u32)(&pal), HEAP);
    }
    MIi_CpuCopy32(pal->raw + 0xc0, p + 0x3c, 0x140);
    func_020307B0(dev);
}

void func_021BDB5C(u8 *p)
{
    u8 i;
    CLACT_DeleteActor((struct Obj *)(((struct Obj14310 *)p)->f1B0));
    for (i = 0; i < 4; i++) CLACT_ReleasePalette(*(u32 *)(p + i * 4 + 0x180));
    for (i = 4; i < 8; i++) CLACT_ReleaseCharacter(*(u32 *)(p + i * 4 + 0x180));
    for (i = 8; i < 11; i++) CLACT_ReleaseCellAnim(*(u32 *)(p + i * 4 + 0x180));
    ARC_TOOL_DeleteHandle((void *)(((struct Obj14310 *)p)->f17C));
}

/*
 * Extent remainder: zero alignment halfword at 021BDC6E.
 */
void func_021BDBC4(u8 *p)
{
    ((struct Obj01758 *)p)->f1C8=(u32)GF_FONT_Create(23,0,0,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1CC=(u32)func_02045B38(0,2,27,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D0=(u32)PRINTSYS_QUE_CreateEx(0x800,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,0,0x140,32,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,4,0x140,32,((struct Obj01758 *)p)->f0);
    func_0201DD68();
    func_0201F5BC(4,0x140,9,0,((struct Obj01758 *)p)->f0);
    func_0201F5BC(0,0x200,9,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D8=(u32)TCBL_Create(((struct Obj01758 *)p)->f0,((struct Obj01758 *)p)->f0,1,0);
    ((struct Obj01758 *)p)->f1DC=0;
}

void func_021BDC70(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        TIME_ICON_Delete((u8 *)v);
        a0[i] = 0;
    }
    i = 0x76;
    TCBL_Destroy((struct S02031140 *)a0[i]);
    PRINTSYS_QUE_Clear((struct PrintSys *)a0[i - 2]);
    PRINTSYS_QUE_Delete((struct PrintSys *)a0[i - 2]);
    MSGDATA_Delete((struct Rec *)a0[i - 3]);
    GF_FONT_Delete((void *)a0[i - 4]);
}

void func_021BDCB8(u8 *p)
{
    switch (*(u32 *)(p+8)) {
    case 1: CTVT_TALK_Exit(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBE5C(p,*(char **)(p+0x1f0)); break;
    case 3: CTVT_DRAW_Exit((u16 *)p,*(char **)(p+0x1ec)); break;
    }
    *(u32 *)(p+8)=*(u32 *)(p+12);
    switch (*(u32 *)(p+8)) {
    case 0: break;
    case 1: CTVT_TALK_Init(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBA94(p,(u8 *)(*(char **)(p+0x1f0))); break;
    case 3: CTVT_DRAW_Init(p,(u8 *)(*(char **)(p+0x1ec))); break;
    case 5:
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
    case 4:
        CTVT_COMM_StopSession(p,*(char **)(p+0x1e4));
        CTVT_CAMVIEW_StopCapture((int)p,*(char **)(p+0x1e0));
        CTVT_CAMVIEW_RequestShutterSound1((int)p,*(char **)(p+0x1e0));
        break;
    }
}

void func_021BDD6C(u8 *p)
{
    u8 i;
    u32 found;
    u32 r;
    u32 m;
    u32 b;
    u32 w;
    found = 0;
    if (((struct Obj02215 *)p)->f8 == 3) {
        return;
    }
    r = COMM_TVT_SYS_GetLayoutMode(p);
    for (i = found; i < 4; i++) {
        if (CTVT_COMM_IsSlotActive((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (CTVT_COMM_GetSlotConnected((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (CTVT_CAMVIEW_IsWindowMoving((int)p, *(char * *)&((struct Obj02215 *)p)->f1E0, i) != 0) continue;
        m = 1 << i;
        if (m & p[0x1b4]) continue;
        {
            char *k = CTVT_COMM_GetSlotParam((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i);
            if (r == 1) {
                if (i == 0) b = 2; else b = 3;
            } else {
                b = i;
            }
            func_021BDEF0(p, k, *(u32 *)(p + b * 4 + 0x1b8));
        }
        p[0x1b4] += (u8)m;
        p[0x1b5] += (u8)(1 << b);
    }
    for (i = 0; i < 4; i++) {
        m = 1 << i;
        if (!(p[0x1b5] & m)) continue;
        if (PRINTSYS_QUE_IsExistTarget(((struct Obj02215 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))) != 0) continue;
        w = *(u32 *)(p + i * 4 + 0x1b8);
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        p[0x1b5] -= (u8)m;
        found = 1;
    }
    if (found == 1) {
        u8 v = CTVT_COMM_GetMarkerSlot((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4);
        if (v != 0xff) {
            COMM_TVT_SYS_PlaceSlotMarker((char *)p, v);
        }
    }
}

void func_021BDEF0(u8 *p, char *a, u32 b)
{
    void *s;
    int x;
    s = func_02008510(a, ((struct Obj02216 *)p)->f0);
    x = (0x60 - (u8)func_0201D304(s, ((struct Obj02216 *)p)->f1C8, 0)) / 2;
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x + 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x - 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 2, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 0, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 1, s, ((struct Obj02216 *)p)->f1C8, 0x3c00);
    STRBUF_Delete(s);
}
