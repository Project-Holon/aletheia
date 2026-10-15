/*
 * file:     wifi_bsubway_graphic.c
 * unit:     yes
 * function: WIFI_BSUBWAY_GRAPHIC_SetupTextParam, WIFI_BSUBWAY_GRAPHIC_DeleteTextParam, WIFI_BSUBWAY_GRAPHIC_ParseCodeIn, WIFI_BSUBWAY_GRAPHIC_StartSaveProc, WIFI_BSUBWAY_GRAPHIC_Noop, WIFI_BSUBWAY_GRAPHIC_GetSaveState, WIFI_BSUBWAY_GRAPHIC_StartRetryProc, WIFI_BSUBWAY_GRAPHIC_NoopRetry, WIFI_BSUBWAY_GRAPHIC_DispatchTable, WIFI_BSUBWAY_GRAPHIC_Step, WIFI_BSUBWAY_GRAPHIC_StepWithInput, WIFI_BSUBWAY_GRAPHIC_StepRetry, WIFI_BSUBWAY_GRAPHIC_InitBt, WIFI_BSUBWAY_GRAPHIC_PollBt, WIFI_BSUBWAY_GRAPHIC_CancelBt, WIFI_BSUBWAY_GRAPHIC_EndBt, WIFI_BSUBWAY_GRAPHIC_CheckNetError, WIFI_BSUBWAY_GRAPHIC_CreateWindow, WIFI_BSUBWAY_GRAPHIC_DeleteWindow, WIFI_BSUBWAY_GRAPHIC_UpdateText, WIFI_BSUBWAY_GRAPHIC_SetupBgAnim, WIFI_BSUBWAY_GRAPHIC_StepBgAnim, WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim, WIFI_BSUBWAY_GRAPHIC_PrintMessage, WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream, WIFI_BSUBWAY_GRAPHIC_SetWord, WIFI_BSUBWAY_GRAPHIC_CreateYesNo, WIFI_BSUBWAY_GRAPHIC_ProcessYesNo, WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon, WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon, WIFI_BSUBWAY_GRAPHIC_StartSave, WIFI_BSUBWAY_GRAPHIC_UpdateSave, WIFI_BSUBWAY_GRAPHIC_Create, WIFI_BSUBWAY_GRAPHIC_Delete, WIFI_BSUBWAY_GRAPHIC_OnRedraw, WIFI_BSUBWAY_GRAPHIC_SetupBg, WIFI_BSUBWAY_GRAPHIC_TeardownBg, WIFI_BSUBWAY_GRAPHIC_Draw
 * address:  0x021D72D0
 * region:   ov116
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   d_021D8574 0x021D8574 data a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   func_0202E54C 0x0202E54C thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   gNetSaveRetryProc 0x021D654C data ov115 a4
 *   d_021D8580 0x021D8580 data a4
 *   WIFI_BSUBWAY_PollHttpRequest 0x021D6EC4 thumb ov116
 *   WIFI_BSUBWAY_StartHttpRequest 0x021D6E50 thumb ov116
 *   WIFI_BSUBWAY_StartUploadPlayer 0x021D7060 thumb ov116
 *   WIFI_BSUBWAY_IsUploadDone 0x021D70B0 thumb ov116
 *   WIFI_BSUBWAY_StartRoomRequest 0x021D69A8 thumb ov116
 *   WIFI_BSUBWAY_FinishRoomRequest 0x021D69C0 thumb ov116
 *   WIFI_BSUBWAY_StartPlayerDownload 0x021D69EC thumb ov116
 *   WIFI_BSUBWAY_FinishPlayerDownload 0x021D6A10 thumb ov116
 *   WIFI_BSUBWAY_GetRoomNumber 0x021D6A40 thumb ov116
 *   WIFI_BSUBWAY_GetPlayerIndex 0x021D6A44 thumb ov116
 *   WIFI_BSUBWAY_GetDownloadResult 0x021D6A48 thumb ov116
 *   WIFI_BSUBWAY_GetTransferState 0x021D6A4C thumb ov116
 *   WIFI_BSUBWAY_NormalizeTrainers 0x021D6A5C thumb ov116
 *   WIFI_BSUBWAY_SaveTrainers 0x021D6AF0 thumb ov116
 *   WIFI_BSUBWAY_SaveHistory 0x021D6B30 thumb ov116
 *   WIFI_BSUBWAY_OpenCodeIn 0x021D7278 thumb ov116
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   DWC_GetDateTime 0x02167ED8 arm ov009
 *   WIFI_BSUBWAY_ClearTrainers 0x021D6998 thumb ov116
 *   func_02009860 0x02009860 thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   DPW_BT_Init 0x021C8F2C arm ov114
 *   DPW_BT_GetServerStateAsync 0x021C96CC arm ov114
 *   WIFI_BSUBWAY_AsyncReset 0x021D70E4 thumb ov116
 *   WIFI_BSUBWAY_PollAsync 0x021D70EC thumb ov116
 *   DPW_BT_IsAsyncEnd 0x021C93D0 arm ov114
 *   DPW_BT_CancelAsync 0x021C9634 arm ov114
 *   DPW_BT_End 0x021C93BC arm ov114
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   WIFI_BSUBWAY_AsyncHasError 0x021D7158 thumb ov116
 *   WIFI_BSUBWAY_CheckFatalError 0x021D7200 thumb ov116
 *   WIFI_BSUBWAY_GetErrorState 0x021D7184 thumb ov116
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   TCBL_Main 0x020310C4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020056A0 0x020056A0 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_CreateRun 0x0203FA08 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   PALANM_BlendColors 0x02021F64 thumb
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02045CAC 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   gWifiBsubwayCodeInParam 0x021D8560 data a4
 *   d_021D8560_menu 0x021D8560 data a4
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_02030734 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_021D858C 0x021D858C data a1
 *   d_021D83C0 0x021D83C0 data a4
 *   WIFI_BSUBWAY_GRAPHIC_Draw 0x021D839C thumb ov116
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021D83B0 0x021D83B0 data a4
 *   d_021D83F0 0x021D83F0 data a4
 *   g_021D83F0  0x021D83F0  data
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ov129_id 0x81 data
 *   ov115_id 0x73 data
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */
#include "../../matched/include/Obj13867.h"
#include "../../matched/include/Obj22624.h"
#include "../../matched/include/Obj10340.h"
#include "../../matched/include/Obj22625.h"
#include "../../matched/include/Obj22626.h"
#include "../../matched/include/Obj00671.h"
#include "../../matched/include/Obj22627.h"
#include "../../matched/include/Obj22628.h"
#include "../../matched/include/Obj22629.h"
#include "../../matched/include/Obj01926.h"
#include "../../matched/include/Obj00494.h"
#include "../../matched/include/Obj00470.h"
#include "../../matched/include/Obj13868.h"
#include "../../matched/include/Obj10342.h"
#include "../../matched/include/Obj01721.h"
#include "../../matched/include/Obj13869.h"
#include "../../matched/include/Obj03252.h"
#include "../../matched/include/Obj05322.h"
#include "../../matched/include/Obj22630.h"
#include "../../matched/include/Obj06418.h"
#include "../../matched/include/Obj22631.h"
#include "../../matched/include/Obj08048.h"
#include "../../matched/include/Obj10343.h"
#include "../../matched/include/Obj10344.h"
#include "../../matched/include/Obj10345.h"
#include "../../matched/include/Obj13870.h"
#include "../../matched/include/Obj10346.h"
#include "../../matched/include/Obj22632.h"
#include "../../matched/include/Obj22633.h"
#include "../../matched/include/Obj10347.h"

#define P(k) (*(void **)(p + (k)))
#define I(k) (*(u32_021D8010 *)((char *)p+(k)))
struct IcaAnime;
struct Param;
struct Obj0202E54C;
struct U16Vec;
struct Blk1AC;
struct BlkB90;
struct Stamp;
struct Sub020097BCObj;
struct Sub0200852CObj;
struct DWCstAccUserData;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct Rec3;
struct S02031140;
struct Tcbl;
struct Node;
struct WinDat;
struct BmpMenu;
struct DispVram;
struct BgTemplate;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef int s32_021D7420;

typedef struct { void (*f[3])(int **, int); } Tbl;

typedef signed int     s32_021D7450;

typedef signed int     s32_021D7550;

typedef signed int     s32_021D77D0;

typedef unsigned long long u64;

typedef unsigned int   u32_021D7C58;

typedef unsigned int u32_021D7CF4;

typedef unsigned int u32_021D7D0C;

struct Arc { int f0; int f4; int f8; u8 *fC; };

typedef unsigned int   u32_021D7F54;

typedef unsigned int u32_021D7FC4;

typedef unsigned u32_021D8010;

typedef unsigned int u32_021D80CC;

typedef unsigned int u32_021D8118;

typedef unsigned int u32_021D8134;

typedef unsigned int u32_021D8168;

typedef unsigned int u32_021D8190;

typedef unsigned int u32_021D81B4;

typedef unsigned int u32_021D81D0;

typedef unsigned int u32_021D81EC;

typedef unsigned int   u32_021D821C;

typedef unsigned int   u32_021D82AC;

typedef unsigned int   u32_021D8304;

typedef unsigned int u32_021D8364;

extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern void func_0202E54C(struct Obj0202E54C *p);
extern u16 STRBUF_GetEosChar(void);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern int WIFI_BSUBWAY_PollHttpRequest(u8 *,u8 *,int);
extern void WIFI_BSUBWAY_StartHttpRequest(u8 *,u8 *,int,int);
extern void WIFI_BSUBWAY_StartUploadPlayer(u8 *,u8 *);
extern int WIFI_BSUBWAY_IsUploadDone(void *unused, u8 *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32_021D7450 i, u32 op);
extern u8 func_0200DC08(struct Blk1AC *p);
extern void WIFI_BSUBWAY_StartRoomRequest(u8 *,u8 *,u16);
extern void WIFI_BSUBWAY_StartPlayerDownload(u8 *,u8 *,u16);
extern int WIFI_BSUBWAY_FinishRoomRequest(u8 *,u8 *);
extern int WIFI_BSUBWAY_FinishPlayerDownload(u8 *,u8 *);
extern u16 WIFI_BSUBWAY_GetRoomNumber(u8 *);
extern u16 WIFI_BSUBWAY_GetPlayerIndex(u8 *);
extern u16 WIFI_BSUBWAY_GetDownloadResult(u8 *);
extern int WIFI_BSUBWAY_GetTransferState(unsigned char *p);
extern void WIFI_BSUBWAY_NormalizeTrainers(u8 *);
extern void WIFI_BSUBWAY_SaveTrainers(u8 *,void *);
extern void WIFI_BSUBWAY_SaveHistory(u8 *,void *);
extern void WIFI_BSUBWAY_OpenCodeIn(u8 *,int);
extern int FADE_IsActive(void);
extern void FADE_Start(u32 a, s32_021D7550 b, s32_021D7550 c, s32_021D7550 d);
extern int DWC_GetDateTime(void *date, void *time);
extern int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q);
extern void WIFI_BSUBWAY_ClearTrainers(void *a);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int WIFILIST_GetGsProfileId(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
extern void DPW_BT_Init(unsigned a, unsigned b, unsigned c, unsigned mode);
extern void DPW_BT_GetServerStateAsync(void);
extern void WIFI_BSUBWAY_AsyncReset(u8 *p);
extern int WIFI_BSUBWAY_PollAsync(u8 *, int *);
extern int DPW_BT_IsAsyncEnd(void);
extern void DPW_BT_CancelAsync(void);
extern void DPW_BT_End(void);
extern int DWC_RAPCOMMON_HandleNetError(int,int);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_STATE_GetError(void);
extern int WIFI_BSUBWAY_AsyncHasError(u8 *p);
extern int WIFI_BSUBWAY_CheckFatalError(int *p);
extern int WIFI_BSUBWAY_GetErrorState(int *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *TCBL_Create(u32, u32, u32, u32);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32_021D7C58 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern u32_021D7C58 BMP_WIN_Delete(struct Descriptor *d);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,int,int);
extern void TCBL_Main(struct Tcbl *p);
extern void *func_020490F4(u32_021D7D0C, u32_021D7D0C);
extern void func_02049B68(void *, int, int, int, int, u32_021D7D0C);
extern u32_021D7D0C func_02049740(void *, int, int, int, int, u32_021D7D0C);
extern void func_02049990(void *, int, int, int, u16, int, int, u32_021D7D0C);
extern void *func_02049F78(void *a0, u32_021D7D0C a1, u32_021D7D0C a2, u32_021D7D0C a3);
extern void ARC_TOOL_DeleteHandle(void *);
extern int func_02049B40(int, int, int, int, int, u32_021D7D0C);
extern void MI_CpuCopy8(const void *, void *, u32_021D7D0C);
extern u32_021D7D0C func_020307B0(void *p);
extern void *func_020056A0(void *, void *, int);
extern void DWCi_ScreenDC_FlushRange(void *, u32_021D7D0C);
extern void func_0207D63C(void *, int, int, int, int);
extern u32_021D7D0C BG_SYS_CreateRun(u32_021D7D0C layer, u32_021D7D0C size, u32_021D7D0C top);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32_021D7D0C a1, u32_021D7D0C a2, u32_021D7D0C a3);
extern void PALANM_BlendColors(void *, void *, u16, u8, u16);
extern void GX_LoadBGPltt(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_02040618(u32_021D7F54 layer, u32_021D7F54 a, u32_021D7F54 b);
extern void BG_SYS_DeleteHalf(u32_021D7FC4 layer, u32_021D7FC4 offset, u32_021D7FC4 size);
extern void func_02030EAC(struct Node *n);
extern void func_02045CAC(struct MsgBank *bank, u32_021D8010 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void GF_FONT_SetTextColor(u32_021D8010 r, u32_021D8010 g, u32_021D8010 b);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(u32_021D8010,int,int,u32_021D8010,u32_021D8010,u32_021D8010,u32_021D8010,int,u16,int);
extern u32_021D80CC PRINTSYS_PrintStreamGetState(void *p);
extern u32_021D80CC KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b, u32_021D8118 c, u32_021D8118 d);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *,u16,u8,u8,u16);
extern u32_021D8168 BMP_MENU_ProcessYesNo(u8 *);
extern u32_021D8190 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void TIME_ICON_Delete(u8 *);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern void *func_02030734(u32_021D821C heapId, u32_021D821C size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(u32_021D821C swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void WIFI_BSUBWAY_GRAPHIC_Draw(void *);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32_021D8304 bgId, const struct BgTemplate *tmpl, u32_021D8304 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
void func_020403F4(u32_021D8364 i);
void BMP_WIN_Exit(void);
void BG_SYS_Delete(void);
void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(u8 *p, u32 heap);
void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(u8 *p);
u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_Noop(void *a0);
int WIFI_BSUBWAY_GRAPHIC_GetSaveState(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_StartRetryProc(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *a0);
void WIFI_BSUBWAY_GRAPHIC_DispatchTable(int **p, int x);
int WIFI_BSUBWAY_GRAPHIC_Step(u8 *p,int b);
int WIFI_BSUBWAY_GRAPHIC_StepWithInput(u8 *p,short heap);
int WIFI_BSUBWAY_GRAPHIC_StepRetry(u8 *p,short heap);
void WIFI_BSUBWAY_GRAPHIC_InitBt(u8 *p);
int WIFI_BSUBWAY_GRAPHIC_PollBt(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_CancelBt(u8 *p);
int WIFI_BSUBWAY_GRAPHIC_EndBt(u8 *p);
int WIFI_BSUBWAY_GRAPHIC_CheckNetError(u8 *p);
int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_CreateWindow(u8 *p, short heap);
void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_UpdateText(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(u8 *p, short heap);
void WIFI_BSUBWAY_GRAPHIC_StepBgAnim(void *unused,u8 *p);
void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *p,u32_021D8010 a);
int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *p);
void WIFI_BSUBWAY_GRAPHIC_SetWord(u8 *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b);
void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(u8 *p);
u32_021D8168 WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p);
void WIFI_BSUBWAY_GRAPHIC_StartSave(u8 *p);
int WIFI_BSUBWAY_GRAPHIC_UpdateSave(u8 *p);
void *WIFI_BSUBWAY_GRAPHIC_Create(int a,unsigned heap);
void WIFI_BSUBWAY_GRAPHIC_Delete(void *p);
void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *a,void *b);
void WIFI_BSUBWAY_GRAPHIC_SetupBg(void *p,unsigned heap);
void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *a0);
extern u32 d_021D8574[];
extern u32 d_021DA62C[];
extern u8 ov129_id[];
extern u32 gNetSaveMainProc[];
extern u8 ov115_id[];
extern u32 gNetSaveRetryProc[];
extern const Tbl d_021D8580;
extern u8 gWifiBsubwayCodeInParam[];
extern u8 d_021D8560_menu[];
extern char d_021D858C[];
extern char d_021D83C0[];
extern char d_021D83B0[];
extern char d_021D83F0[];
extern u8 g_021D83F0[];


void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(u8 *p, u32 heap)
{
    void *obj;
    obj = CODEIN_PARAM_Create(heap, 2, 10, 2, d_021D8574);
    ((struct Obj13867 *)p)->f1840 = obj;
    GAMESYSTEM_CallProc(((struct Obj22624 *)(*(u8 * *)&((struct Obj13867 *)p)->f0))->f4, (u32)ov129_id, d_021DA62C, obj);
}


void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(u8 *p)
{
    if (((struct Obj10340 *)p)->f1840) {
        func_0202E54C(((struct Obj10340 *)p)->f1840);
        ((struct Obj10340 *)p)->f1840 = 0;
    }
}


u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(u8 *p) {
    u16 end=STRBUF_GetEosChar();
    u16 *s=STRBUF_GetChars(((struct Obj22626 *)(*(u8 * *)&((struct Obj22625 *)p)->f1840))->f20);
    u32 value=0;
    u16 i=0;
    while(s[i]!=end) {
        u16 d=(u16)(s[i]-48);
        if(d>=10) d=(u16)(s[i]-0xff10);
        value *= 10;
        value += d;
        i++;
    }
    return value;
}


void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(u8 *p) {
    ((struct Obj00671 *)p)->f9B0=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9B4=0;
    ((struct Obj00671 *)p)->f9C8=1;
    ((struct Obj00671 *)p)->f9B8=1;
    ((struct Obj00671 *)p)->f9BC=44;
    ((struct Obj00671 *)p)->f9C0=p+0x9f4;
    GAMESYSTEM_CallProc(((struct Obj22627 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,gNetSaveMainProc,p+0x9b0);
}


/*
 * extent: two-byte zero alignment padding, then already matched getter ov116_func_021D73D4.c.
 */
void WIFI_BSUBWAY_GRAPHIC_Noop(void *a0) { }


int WIFI_BSUBWAY_GRAPHIC_GetSaveState(u8 *p) { return ((struct Obj22628 *)p)->f9CC; }


void WIFI_BSUBWAY_GRAPHIC_StartRetryProc(u8 *p) {
    ((struct Obj00671 *)p)->f9D8=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9DC=0;
    ((struct Obj00671 *)p)->f9E0=1;
    ((struct Obj00671 *)p)->f9E4=1;
    GAMESYSTEM_CallProc(((struct Obj22629 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,gNetSaveRetryProc,p+0x9d8);
}



void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *a0) { }


void WIFI_BSUBWAY_GRAPHIC_DispatchTable(int **p, int x)
{
    Tbl t = d_021D8580;
    t.f[**p](p, x);
}


/*
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 */
int WIFI_BSUBWAY_GRAPHIC_Step(u8 *p,int b)
{
    int v;
    switch (((struct Obj01926 *)p)->fB6C) {
    case 0: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,7); ++((struct Obj01926 *)p)->fB6C; break;
    case 1: WIFI_BSUBWAY_StartHttpRequest(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 2:
        v=WIFI_BSUBWAY_PollHttpRequest(p+0x1610,p+0x182c,0);
        if(v==1) ((struct Obj01926 *)p)->fB6C=5;
        else if(v==2) ((struct Obj01926 *)p)->fB6C=3;
        break;
    case 3: WIFI_BSUBWAY_StartHttpRequest(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 4:
        if(WIFI_BSUBWAY_PollHttpRequest(p+0x1610,p+0x182c,1)==1) ((struct Obj01926 *)p)->fB6C=5;
        break;
    case 5: WIFI_BSUBWAY_StartUploadPlayer(p+0x1610,p+0x182c); ++((struct Obj01926 *)p)->fB6C; break;
    case 6:
        if(WIFI_BSUBWAY_IsUploadDone(p+0x1610,p+0x182c)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj01926 *)p)->fB6C;
        break;
    case 7: func_0200DBA0(((struct Obj01926 *)p)->f1858,1,2); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++((struct Obj01926 *)p)->fB6C; break;
    case 8:
        if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,8); ++((struct Obj01926 *)p)->fB6C; }
        break;
    case 9: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj01926 *)p)->fB6C; break;
    case 10: return 1;
    }
    return 0;
}


int WIFI_BSUBWAY_GRAPHIC_StepWithInput(u8 *p,short heap)
{
    int v,box;
    u32 n;
    u8 extra[12];
    u8 record[16];
    switch(((struct Obj00494 *)p)->fB6C) {
    case 0: WIFI_BSUBWAY_StartRoomRequest(p+0xb74,p+0x182c,(u32)func_0200DC08(((struct Obj00494 *)p)->f1858)); ++((struct Obj00494 *)p)->fB6C; break;
    case 1: if(WIFI_BSUBWAY_FinishRoomRequest(p+0xb74,p+0x182c)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 2:
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); v=WIFI_BSUBWAY_GetDownloadResult(p+0xb74);
        WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,0); ++((struct Obj00494 *)p)->fB6C; break;
    case 3: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 4: FADE_Start((int)3,0,16,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 5: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++((struct Obj00494 *)p)->fB6C; } break;
    case 6: WIFI_BSUBWAY_OpenCodeIn(p,heap); ++((struct Obj00494 *)p)->fB6C; break;
    case 7: ((struct Obj00494 *)p)->fB70=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,heap); FADE_Start((int)3,16,0,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 8:
        if(FADE_IsActive()==0) {
            box=WIFI_BSUBWAY_GetRoomNumber(p+0xb74); n=((struct Obj00494 *)p)->fB70; v=WIFI_BSUBWAY_GetDownloadResult(p+0xb74);
            DWC_GetDateTime(record,extra);
            if(n<1 || n>(u32)v) { ((struct Obj00494 *)p)->fB6C=16; break; }
            if(func_0200DDD0(((struct Obj00494 *)p)->f1854,box,n,(const struct Stamp *)record)!=0) { ((struct Obj00494 *)p)->fB6C=14; break; }
            WIFI_BSUBWAY_StartPlayerDownload(p+0xb74,p+0x182c,((struct Obj00494 *)p)->fB70);
            v=WIFI_BSUBWAY_GetPlayerIndex(p+0xb74); WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74));
            WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,1,WIFI_BSUBWAY_GetRoomNumber(p+0xb74),(u32)((void *)2)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,1); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++((struct Obj00494 *)p)->fB6C;
        } break;
    case 9: if(WIFI_BSUBWAY_FinishPlayerDownload(p+0xb74,p+0x182c)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 10: WIFI_BSUBWAY_NormalizeTrainers(p+0xb74); WIFI_BSUBWAY_SaveTrainers(p+0xb74,((struct Obj00494 *)p)->f1854); WIFI_BSUBWAY_SaveHistory(p+0xb74,((struct Obj00494 *)p)->f1854); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++((struct Obj00494 *)p)->fB6C; break;
    case 11: if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,3); ++((struct Obj00494 *)p)->fB6C; } break;
    case 12: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 13: return 1;
    case 14: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,2); ++((struct Obj00494 *)p)->fB6C; break;
    case 15: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ((struct Obj00494 *)p)->fB6C=2; break;
    case 16: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,4); ++((struct Obj00494 *)p)->fB6C; break;
    case 17: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 18: WIFI_BSUBWAY_GRAPHIC_CreateYesNo(p+4); ++((struct Obj00494 *)p)->fB6C; break;
    case 19: v=(int)WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(p+4); if(v==0) return 2; if(v==-2) ((struct Obj00494 *)p)->fB6C=2; break;
    }
    return 0;
}


int WIFI_BSUBWAY_GRAPHIC_StepRetry(u8 *p,short heap)
{
    int v;
    u32 n;
    switch(((struct Obj00470 *)p)->fB6C) {
    case 0: WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,5); ++((struct Obj00470 *)p)->fB6C; break;
    case 1: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 2: FADE_Start(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 3: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 4: WIFI_BSUBWAY_GRAPHIC_SetupTextParam(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 5: ((struct Obj00470 *)p)->fB70=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,heap); FADE_Start(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 6:
        if(FADE_IsActive()==0) {
            n=((struct Obj00470 *)p)->fB70;
            if(n>=1 && n<=10) {
                WIFI_BSUBWAY_StartRoomRequest(p+0xb74,p+0x182c,n); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,26); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++((struct Obj00470 *)p)->fB6C;
            } else ((struct Obj00470 *)p)->fB6C=19;
        } break;
    case 7:
        if(WIFI_BSUBWAY_FinishRoomRequest(p+0xb74,p+0x182c)!=0) {
            WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); v=WIFI_BSUBWAY_GetDownloadResult(p+0xb74); WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,6); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 8: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 9: FADE_Start(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 10: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 11: WIFI_BSUBWAY_OpenCodeIn(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 12: ((struct Obj00470 *)p)->fB70=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,heap); FADE_Start(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 13:
        if(FADE_IsActive()==0) {
            v=WIFI_BSUBWAY_GetDownloadResult(p+0xb74); n=((struct Obj00470 *)p)->fB70;
            if(n<1 || n>(u32)v) { ((struct Obj00470 *)p)->fB6C=19; break; }
            WIFI_BSUBWAY_StartPlayerDownload(p+0xb74,p+0x182c,n);
            v=WIFI_BSUBWAY_GetPlayerIndex(p+0xb74); WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74));
            WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,1,WIFI_BSUBWAY_GetRoomNumber(p+0xb74),(u32)((void *)2)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,1); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 14: if(WIFI_BSUBWAY_FinishPlayerDownload(p+0xb74,p+0x182c)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 15: WIFI_BSUBWAY_NormalizeTrainers(p+0xb74); WIFI_BSUBWAY_SaveHistory(p+0xb74,((struct Obj00470 *)p)->f1854); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++((struct Obj00470 *)p)->fB6C; break;
    case 16: if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,3); ++((struct Obj00470 *)p)->fB6C; } break;
    case 17: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 18: return 1;
    case 19: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,9); ++((struct Obj00470 *)p)->fB6C; break;
    case 20: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 21: WIFI_BSUBWAY_GRAPHIC_CreateYesNo(p+4); ++((struct Obj00470 *)p)->fB6C; break;
    case 22: v=WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(p+4); if(v==0) return 2; if(v==-2) { WIFI_BSUBWAY_ClearTrainers(p+0xb74); ((struct Obj00470 *)p)->fB6C=0; } break;
    }
    return 0;
}


void WIFI_BSUBWAY_GRAPHIC_InitBt(u8 *p) {
    void *a=func_02009860(((struct Obj00671 *)p)->f184C);
    void *b;
    u64 value;
    func_02008540(((struct Obj00671 *)p)->f1850,(u32)WIFILIST_GetGsProfileId(((struct Obj00671 *)p)->f184C));
    b=(void *)func_0200853C(((struct Obj00671 *)p)->f1850);
    value=DWC_CreateFriendKey(a);
    DPW_BT_Init((unsigned int)b,(u32)value,(u32)(value>>32),0);
    DPW_BT_GetServerStateAsync();
    WIFI_BSUBWAY_AsyncReset(p+0x182c);
    ((struct Obj00671 *)p)->fB68=1;
}


int WIFI_BSUBWAY_GRAPHIC_PollBt(u8 *p)
{
    int result;
    return WIFI_BSUBWAY_PollAsync(p + 0x182c, &result);
}


/*
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 (pengy overlay, no witness).
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: DPW_BT_IsAsyncEnd (ov114 ARM, SDK-side
 *   libext code, no witness). Nothing source-side to change.
 */
void WIFI_BSUBWAY_GRAPHIC_CancelBt(u8 *p)
{
    if (DPW_BT_IsAsyncEnd() == 0) {
        DPW_BT_CancelAsync();
        WIFI_BSUBWAY_AsyncReset(p + 0x182c);
    }
}


int WIFI_BSUBWAY_GRAPHIC_EndBt(u8 *p)
{
    int result;
    if (((struct Obj13868 *)p)->fB68 == 0) return 1;
    if (WIFI_BSUBWAY_PollAsync(p + 0x182c, &result)) {
        DPW_BT_End();
        ((struct Obj13868 *)p)->fB68 = 0;
        return 1;
    }
    return 0;
}


int WIFI_BSUBWAY_GRAPHIC_CheckNetError(u8 *p) {
    int yes=1;
    int no=0;
    if(DWC_RAPCOMMON_HandleNetError(1,0)!=0) return no;
    if(func_0200FB24()!=0) {
        GFL_NET_STATE_GetError();
        return no;
    }
    if(WIFI_BSUBWAY_AsyncHasError(p+0x182c)!=0) {
        int v;
        if(WIFI_BSUBWAY_CheckFatalError((int *)(p+0x182c))!=0) return no;
        v=WIFI_BSUBWAY_GetErrorState((int *)(p+0x182c));
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4);
        WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,v);
        return yes;
    }
    return no;
}


int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(u8 *p) { return WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4); }


/*
 * evidence: incoming heap in r1 is forwarded unchanged to 021D821C.
 * evidence: 0203101C's second parameter is wide here: original 021D7C26
 * copies full r6 to r1 with no truncation; its definition stores the low halfword.
 */
void WIFI_BSUBWAY_GRAPHIC_CreateWindow(u8 *p, short heap)
{
    P(8) = WIFI_BSUBWAY_GRAPHIC_Create(1, heap);
    ((struct Obj10342 *)p)->f4 = heap;
    WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(p, heap);
    P(0x97c) = (void *)BMP_WIN_Create(1, 1, 19, 30, 4, 12, 1);
    BMP_MENUWORK_DrawWindow(P(0x97c), 1, (u16)(((struct Obj10342 *)p)->f984), 13);
    BMP_Clear(BMP_WIN_GetBmp(P(0x97c)), 15);
    BMP_WIN_MakeScreen(P(0x97c));
    BMP_WIN_TransferChars(P(0x97c));
    func_02041B6C(1);
    P(0x990) = func_02045B38(0, 2, 206, heap);
    P(0x994) = GF_FONT_Create_EC64(heap);
    P(0x998) = GF_FONT_Create(23, 0, 0, 0, heap);
    P(0x99c) = STRBUF_Create(128, heap);
    P(0x9a0) = STRBUF_Create(128, heap);
    P(0x9a8) = TCBL_Create(heap, heap, 1, 0);
    ((struct Obj10342 *)p)->f0 = 1;
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout(1, heap);
}


void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *p) {
    if(((struct Obj01721 *)p)->f0!=0) {
        if(((struct Obj01721 *)p)->f9A4) PRINTSYS_PrintStreamDelete(((struct Obj01721 *)p)->f9A4);
        TCBL_Destroy(((struct Obj01721 *)p)->f9A8);
        MSGDATA_Delete(((struct Obj01721 *)p)->f990);
        WORDSET_DeleteStrbufED04(((struct Obj01721 *)p)->f994);
        GF_FONT_Delete(((struct Obj01721 *)p)->f998);
        STRBUF_Delete(((struct Obj01721 *)p)->f99C);
        STRBUF_Delete(((struct Obj01721 *)p)->f9A0);
        WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(p);
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p);
        if(((struct Obj01721 *)p)->f980) {
            BMP_MENU_DeleteYesNo(((struct Obj01721 *)p)->f980);
            ((struct Obj01721 *)p)->f980=0;
        }
        BMP_WIN_Delete(((struct Obj01721 *)p)->f97C);
        WIFI_BSUBWAY_GRAPHIC_Delete(((struct Obj01721 *)p)->f8);
        GF_FONT_SetDefaultTextColor();
        MI_CpuFill8(p,0,0x9ac);
    }
}


void WIFI_BSUBWAY_GRAPHIC_UpdateText(u8 *p)
{
    if (((struct Obj13869 *)p)->f0 != 0) TCBL_Main(((struct Obj13869 *)p)->f9A8);
}


/*
 * lever: 2026-10-05 (wD9r lane92): the heap parameter is a signed 16-bit value (`short heap`). With u32
 *   heap the last call hoisted the heap reload above `str r6,[sp]` (10 bytes, waves D3 to D9r). The
 *   image truncates heap only for func_02049F78 (u16 cast); the other callees take it unchanged.
 */
void WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(u8 *p, short heap) {
    struct Arc *res;
    u8 *pa;
    u8 *pb;
    void *arc;
    int done;
    int t;
    int j;
    int k;
    u8 *q;
    void *blk;
    int m;
    int n;
    int sh;
    u8 *a;
    u8 *b;
    arc = func_020490F4(0x91, heap);
    j = 0;
    func_02049B68(arc, 3, 4, 0, j, heap);
    func_02049990(arc, 6, 4, 0, (u16)func_02049740(arc, 4, 4, 0, j, heap), j, j, heap);
    func_02049B68(arc, 3, 0, 0, j, heap);
    func_02049990(arc, 5, 0, 0, (u16)func_02049740(arc, 4, 0, 0, j, heap), j, j, heap);
    func_02049990(arc, 7, 3, 0, (u16)func_02049740(arc, 4, 3, 0, j, heap), j, j, heap);
    MI_CpuFill8(p + 0xc, 0, 0x970);
    blk = func_02049F78(arc, 2, (u32_021D7D0C)(&res), (u16)heap);
    MI_CpuCopy8(res->fC, p + 0x14, 0x1e0);
    MI_CpuCopy8(res->fC, p + 0x1f4, 0x1e0);
    func_020307B0(blk);
    k = 0;
    pa = p + 0x1f4;
    pb = p;
    pb += 0x14;
    for (; k < 15; k++) {
        n = k + 1;
        if (n >= 15) n -= 15;
        t = 0;
        done = 0;
        q = p + n * 32;
        for (;;) {
            a = pb + k * 32;
            sh = t >> 8;
            b = pa + j * 32;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors(a + m * 2, b + m * 2, 1, (u8)sh, *(u16 *)(q + 0x14 + m * 2));
            }
            j++;
            if (done == 1) break;
            t += 0x600;
            if (t >= 0x1000) { t = 0x1000; done = 1; }
        }
    }
    DWCi_ScreenDC_FlushRange(p + 0x1f4, 0x780);
    *(u32_021D7D0C *)(p + 0x10) = 1;
    *(void **)(p + 0xc) = func_020056A0((void *)WIFI_BSUBWAY_GRAPHIC_StepBgAnim, p + 0xc, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    p[0x978] = 0;
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_CreateRun(1, 0x20, 0);
    BG_SYS_CreateRun(2, 0x20, 0);
    *(void **)(p + 0x984) = BMP_MENUWORK_LoadFrameGfx((void *)1, 0xd, 0, heap);
    *(void **)(p + 0x988) = BMP_MENUWORK_LoadFrameGfx((void *)2, 0xd, 0, heap);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, heap);
}


void WIFI_BSUBWAY_GRAPHIC_StepBgAnim(void *unused,u8 *p) {
    if(((struct Obj03252 *)p)->f4!=0) {
        p[0x96b]^=1;
        if((p[0x96b]&1)==0) {
            GX_LoadBGPltt(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            func_0207E468(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            (((struct Obj03252 *)p)->f968)++;
            if(((struct Obj03252 *)p)->f968>=60) ((struct Obj03252 *)p)->f968=0;
            func_02040618(p[0x96c],2,7);
        }
    }
}


void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(u8 *p) {
    u32_021D7FC4 x=((struct Obj05322 *)p)->f984;
    BG_SYS_DeleteHalf(1,(u16)x,(u16)(x>>16));
    x=((struct Obj05322 *)p)->f988;
    BG_SYS_DeleteHalf(2,(u16)x,(u16)(x>>16));
    if(((struct Obj05322 *)p)->fC) {
        func_02030EAC(((struct Obj05322 *)p)->fC);
        *(u32_021D7FC4 *)&((struct Obj05322 *)p)->fC=0;
        ((struct Obj05322 *)p)->f10=0;
    }
    *(u16 *)0x04000050=0;
}


void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *p,u32_021D8010 a) {
 if(I(0x9a4)!=0) {PRINTSYS_PrintStreamDelete((void *)I(0x9a4)); I(0x9a4)=0;}
 func_02045CAC((struct MsgBank *)I(0x990),a,(void *)I(0x99c));
 WORDSET_CopyTaggedText((struct WordSet *)I(0x994),(void *)I(0x9a0),(void *)I(0x99c));
 BMP_Clear((struct CharBuf *)((u32_021D8010)BMP_WIN_GetBmp((struct Descriptor *)I(0x97c))),15);
 GF_FONT_SetTextColor(1,2,15);
 I(0x9a4)=(u32_021D8010)PRINTSYS_PrintStream(I(0x97c),0,0,I(0x9a0),I(0x998),MSG_SPEED_GetWait(),I(0x9a8),2,((struct Obj22630 *)p)->f4,15);
 BMP_MENUWORK_DrawWindow((void *)I(0x97c),1,(u16)I(0x984),13);
 BMP_WIN_TransferChars((struct Descriptor *)I(0x97c));
}


int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *p) {
 int v;
 if(((struct Obj06418 *)p)->f9A4==0) return 1;
 v=PRINTSYS_PrintStreamGetState(((struct Obj06418 *)p)->f9A4);
 if(v==2) { PRINTSYS_PrintStreamDelete(((struct Obj06418 *)p)->f9A4); ((struct Obj06418 *)p)->f9A4=0; return 1; }
 if(v==1) { if(KEY_GetTrg()==1 || TOUCHPANEL_GetTrg()!=0) PRINTSYS_PrintStreamReleasePause(((struct Obj06418 *)p)->f9A4); }
 return 0;
}


void WIFI_BSUBWAY_GRAPHIC_SetWord(u8 *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b)
{
    WORDSET_SetSlotNumber(((struct Obj22631 *)p)->f994, i, a, b, 2, 1);
}


/*
 * The duplicated 021D8560 pool words require separate extern names;
 * see the duplicated-pool-word idiom.
 */
void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(u8 *p) { *(u16 *)(gWifiBsubwayCodeInParam+4)=((struct Obj08048 *)p)->f988; *(struct BmpMenu * *)&((struct Obj08048 *)p)->f980=BMP_MENU_CreateYesNo((const struct WinDat *)d_021D8560_menu,((struct Obj08048 *)p)->f988,13,0,((struct Obj08048 *)p)->f4); }


u32_021D8168 WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(u8 *p) { u32_021D8168 result=-2; if(*(u8 * *)&((struct Obj10343 *)p)->f980!=0) { result=BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj10343 *)p)->f980); if(result!=-1) *(u32_021D8168 *)&((struct Obj10343 *)p)->f980=0; } return result; }


void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(u8 *p) { *(u8 * *)&((struct Obj10344 *)p)->f98C=TIME_ICON_Create((void *)func_020056BC(),((struct Obj10344 *)p)->f97C,15,16,((struct Obj10344 *)p)->f4); }


void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p) { if(*(u8 * *)&((struct Obj10345 *)p)->f98C!=0) { TIME_ICON_Delete(*(u8 * *)&((struct Obj10345 *)p)->f98C); *(u32_021D81B4 *)&((struct Obj10345 *)p)->f98C=0; } }


void WIFI_BSUBWAY_GRAPHIC_StartSave(u8 *p) { GAME_DATA_SaveStart(((struct Obj13870 *)p)->f1844); ((struct Obj13870 *)p)->fB6A=1; }


int WIFI_BSUBWAY_GRAPHIC_UpdateSave(u8 *p) { if(((struct Obj10346 *)p)->fB6A==0) return 1; if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj10346 *)p)->f1844)==2) { ((struct Obj10346 *)p)->fB6A=0; return 1; } return 0; }


/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
void *WIFI_BSUBWAY_GRAPHIC_Create(int a,unsigned heap) {
 void *p;
 p=func_02030734(heap,16,0,d_021D858C,0x1bc);
 MI_CpuFill8(p,0,16);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks((const struct DispVram *)d_021D83C0); BMP_SetDisplaySwap(a);
 BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes(); GF_FONT_InitTextColor();
 WIFI_BSUBWAY_GRAPHIC_SetupBg(p,heap);
 ((struct Obj22632 *)p)->fC=func_020056A0((void *)WIFI_BSUBWAY_GRAPHIC_OnRedraw,p,0);
 return p;
}


void WIFI_BSUBWAY_GRAPHIC_Delete(void *p) {
 func_02030EAC(((struct Obj22633 *)p)->fC); WIFI_BSUBWAY_GRAPHIC_TeardownBg(p); GF_FONT_SetDefaultTextColor();
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 MI_CpuFill8(p,0,16); func_020307B0(p);
}


void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *a,void *b) {WIFI_BSUBWAY_GRAPHIC_Draw(b);}


void WIFI_BSUBWAY_GRAPHIC_SetupBg(void *p,unsigned heap) {
 unsigned i; char *q; unsigned n;
 MI_CpuFill8(p,0,4);
 BG_SYS_Create(heap); BMP_WIN_Init(heap); BG_SYS_SetGraphicsMode((struct DispConfig *)d_021D83B0);
 for(i=0;i<8;i++) {
 q=d_021D83F0+i*44; n=((struct Obj10347 *)q)->f0;
 BG_SYS_InitBgLayer((u8)n,(const struct BgTemplate *)(q+4),(u8)(((struct Obj10347 *)q)->f24));
 BG_SYS_FreeSlot(n); func_02040588(n,((struct Obj10347 *)q)->f28);
 }
}



void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *a0)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        func_020403F4((u8)*(u32_021D8364 *)(g_021D83F0 + i * 0x2c));
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(a0, 0, 4);
}



extern void BG_SYS_Update(void *);
void WIFI_BSUBWAY_GRAPHIC_Draw(void *p) { BG_SYS_Update(p); }
