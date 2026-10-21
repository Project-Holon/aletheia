/*
 * file:     wifi_bsubway_graphic.c
 * unit:     yes
 * function: WIFI_BSUBWAY_GRAPHIC_SetupTextParam, WIFI_BSUBWAY_GRAPHIC_DeleteTextParam, WIFI_BSUBWAY_GRAPHIC_ParseCodeIn, WIFI_BSUBWAY_GRAPHIC_StartSaveProc, WIFI_BSUBWAY_GRAPHIC_Noop, WIFI_BSUBWAY_GRAPHIC_GetSaveState, WIFI_BSUBWAY_GRAPHIC_StartRetryProc, WIFI_BSUBWAY_GRAPHIC_NoopRetry, WIFI_BSUBWAY_GRAPHIC_DispatchTable, WIFI_BSUBWAY_GRAPHIC_Step, WIFI_BSUBWAY_GRAPHIC_StepWithInput, WIFI_BSUBWAY_GRAPHIC_StepRetry, WIFI_BSUBWAY_GRAPHIC_InitBt, WIFI_BSUBWAY_GRAPHIC_PollBt, WIFI_BSUBWAY_GRAPHIC_CancelBt, WIFI_BSUBWAY_GRAPHIC_EndBt, WIFI_BSUBWAY_GRAPHIC_CheckNetError, WIFI_BSUBWAY_GRAPHIC_IsPrintDone, WIFI_BSUBWAY_GRAPHIC_CreateWindow, WIFI_BSUBWAY_GRAPHIC_DeleteWindow, WIFI_BSUBWAY_GRAPHIC_UpdateText, WIFI_BSUBWAY_GRAPHIC_SetupBgAnim, WIFI_BSUBWAY_GRAPHIC_StepBgAnim, WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim, WIFI_BSUBWAY_GRAPHIC_PrintMessage, WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream, WIFI_BSUBWAY_GRAPHIC_SetWord, WIFI_BSUBWAY_GRAPHIC_CreateYesNo, WIFI_BSUBWAY_GRAPHIC_ProcessYesNo, WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon, WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon, WIFI_BSUBWAY_GRAPHIC_StartSave, WIFI_BSUBWAY_GRAPHIC_UpdateSave, WIFI_BSUBWAY_GRAPHIC_Create, WIFI_BSUBWAY_GRAPHIC_Delete, WIFI_BSUBWAY_GRAPHIC_OnRedraw, WIFI_BSUBWAY_GRAPHIC_SetupBg, WIFI_BSUBWAY_GRAPHIC_TeardownBg, WIFI_BSUBWAY_GRAPHIC_Draw
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
 *   CODEIN_PARAM_Delete 0x0202E54C thumb
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
 *   WIFILIST_GetWork 0x02009860 thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   MYSTATUS_SetProfileIdOnce 0x02008540 thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   DPW_BT_Init 0x021C8F2C arm ov114
 *   DPW_BT_GetServerStateAsync 0x021C96CC arm ov114
 *   WIFI_BSUBWAY_AsyncReset 0x021D70E4 thumb ov116
 *   WIFI_BSUBWAY_PollAsync 0x021D70EC thumb ov116
 *   DPW_BT_IsAsyncEnd 0x021C93D0 arm ov114
 *   DPW_BT_CancelAsync 0x021C9634 arm ov114
 *   DPW_BT_End 0x021C93BC arm ov114
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
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
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   TCBL_Main 0x020310C4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   DC_FlushRange 0x020862F0 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BG_SYS_CreateRun 0x0203FA08 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   PALANM_BlendColors 0x02021F64 thumb
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   MSGDATA_ReadString 0x02045CAC arm
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
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
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
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021D83B0 0x021D83B0 data a4
 *   d_021D83F0 0x021D83F0 data a4
 *   g_021D83F0  0x021D83F0  data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ov129_id 0x81 data
 *   ov115_id 0x73 data
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   BSUBWAY_SCOREDATA_AccessFlag  0x0200DBA0  thumb  arm9
 *   BSUBWAY_SCOREDATA_GetLevel  0x0200DC08  thumb  arm9
 *   BSUBWAY_WIFIDATA_GetTrainerBit  0x0200DDD0  thumb  arm9
 */
#include "ov116_types.h"
#include "../sdk_ioreg.h"

struct IcaAnime;
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
#include "../types.h"

typedef struct { int (*f[3])(int **, int); } Tbl;

struct Arc { int f0; int f4; int f8; u8 *fC; };
struct CodeinParam;

#include "../arm9/codein_param.h"
struct GameSystem;
#include "../arm9/gamesystem.h"
#include "../arm9/strbuf.h"
struct Strbuf;
#include "wifi_bsubway.h"
struct BsubwayScoreData;
#include "../arm9/gds_profile.h"
#include "../arm9/fade.h"
#include "../ov009/dwc_nasfunc.h"
struct BsubwayWifiData;
struct WifiList;
#include "../arm9/wifilist.h"
struct MyStatus;
#include "../arm9/mystatus.h"
#include "../arm9/dwc_account.h"
#include "../ov114/dpw_bt.h"
#include "../ov009/dwc_rapcommon.h"
#include "../arm9/net_err.h"
#include "../arm9/net_state.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
#ifdef __MWERKS__
#define BMP_MENUWORK_LoadFrameGfx BMP_MENUWORK_LoadFrameGfx_hdr
#endif
#include "../arm9/bmp_menuwork.h"
#ifdef __MWERKS__
#undef BMP_MENUWORK_LoadFrameGfx
void * BMP_MENUWORK_LoadFrameGfx(u32, unsigned int, unsigned int, unsigned int);
#endif
typedef short s16_p07;
#include "../arm9/bmp.h"
struct BmpWin;
#ifdef __MWERKS__
#define BG_SYS_Create BG_SYS_Create_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_Create
void BG_SYS_Create(unsigned);
#endif
#include "../arm9/msgdata.h"
#ifdef __MWERKS__
#define WORDSET_CreateDefault WORDSET_CreateDefault_hdr
#endif
#include "../arm9/gf_font.h"
#ifdef __MWERKS__
#undef WORDSET_CreateDefault
struct WordSet * WORDSET_CreateDefault(u32);
#endif
#ifdef __MWERKS__
#define TCBL_Create TCBL_Create_hdr
#endif
#include "../arm9/tcbl.h"
#ifdef __MWERKS__
#undef TCBL_Create
struct TcblSystem * TCBL_Create(u32, u32, u32, u32);
#endif
#include "../arm9/net.h"
struct TextPrinter;
#include "../arm9/printsys.h"
struct TcblSystem;
#include "../arm9/wordset.h"
#include "../arm9/bmp_menu.h"
#include "../arm9/mi_memory.h"
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#define ARC_UTIL_UploadPaletteFromHandleWhole ARC_UTIL_UploadPaletteFromHandleWhole_hdr
#define ARC_UTIL_UploadBgPaletteAddFromHandle ARC_UTIL_UploadBgPaletteAddFromHandle_hdr
#define ARC_UTIL_RegisterObjCharFromHandle ARC_UTIL_RegisterObjCharFromHandle_hdr
#define ARC_UTIL_UploadPaletteFromArchiveWhole ARC_UTIL_UploadPaletteFromArchiveWhole_hdr
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_UploadPaletteFromHandleWhole
#undef ARC_UTIL_UploadBgPaletteAddFromHandle
#undef ARC_UTIL_RegisterObjCharFromHandle
#undef ARC_UTIL_UploadPaletteFromArchiveWhole
void ARC_UTIL_UploadPaletteFromHandleWhole(void *, int, int, int, int, unsigned int);
u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *, int, int, int, u16, int, int, unsigned int);
unsigned int ARC_UTIL_RegisterObjCharFromHandle(void *, int, int, int, int, unsigned int);
void ARC_UTIL_UploadPaletteFromArchiveWhole(int, int, int, int, int, unsigned int);
#endif
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_use.h"
#include "../arm9/os_cache.h"
#include "../arm9/g2.h"
#ifdef __MWERKS__
#define PALANM_BlendColors PALANM_BlendColors_hdr
#endif
#include "../arm9/palanm.h"
#ifdef __MWERKS__
#undef PALANM_BlendColors
void PALANM_BlendColors(u16 *, u16 *, u16, u8, u16);
#endif
#include "../arm9/gx_load2d.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/msg_speed.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
struct TcbList;
struct TimeIcon;
#include "../arm9/time_icon.h"
struct GameData;
#include "../arm9/game_data.h"
extern void WIFI_BSUBWAY_GRAPHIC_Draw(void *);
void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(struct WifiBsubwayWork *p, u32 heap);
void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(struct WifiBsubwayWork *p);
u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_Noop(void *work);
int WIFI_BSUBWAY_GRAPHIC_GetSaveState(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_StartRetryProc(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *work);
int WIFI_BSUBWAY_GRAPHIC_DispatchTable(int **p, int x);
int WIFI_BSUBWAY_GRAPHIC_Step(struct WifiBsubwayWork *p,int b);
int WIFI_BSUBWAY_GRAPHIC_StepWithInput(struct WifiBsubwayWork *p,short heap);
int WIFI_BSUBWAY_GRAPHIC_StepRetry(struct WifiBsubwayWork *p,short heap);
void WIFI_BSUBWAY_GRAPHIC_InitBt(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_PollBt(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_CancelBt(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_EndBt(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_CheckNetError(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_CreateWindow(struct WifiBsubwayGraphic *p, short heap);
void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_UpdateText(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(struct WifiBsubwayGraphic *p, short heap);
void WIFI_BSUBWAY_GRAPHIC_StepBgAnim(void *unused,struct WifiBsubwayAnim *p);
void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_PrintMessage(struct WifiBsubwayGraphic *p,unsigned int a);
int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_SetWord(struct WifiBsubwayGraphic *p, unsigned int i, unsigned int a, unsigned int b);
void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(struct WifiBsubwayGraphic *p);
unsigned int WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_StartSave(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_UpdateSave(struct WifiBsubwayWork *p);
void *WIFI_BSUBWAY_GRAPHIC_Create(int a,unsigned heap);
void WIFI_BSUBWAY_GRAPHIC_Delete(struct WifiBsubwayBg *p);
void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *a,void *b);
void WIFI_BSUBWAY_GRAPHIC_SetupBg(struct WifiBsubwayBg *p,unsigned heap);
void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *work);
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

void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(struct WifiBsubwayWork *p, u32 heap)
{
    void *obj;
    obj = CODEIN_PARAM_Create(heap, 2, 10, 2, d_021D8574);
    p->codeInParam = obj;
    GAMESYSTEM_CallProc(p->parent->proc, (uptr)ov129_id, d_021DA62C, obj);
}

void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(struct WifiBsubwayWork *p)
{
    if (p->codeInParam) {
        CODEIN_PARAM_Delete(p->codeInParam);
        p->codeInParam = 0;
    }
}

u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(struct WifiBsubwayWork *p) {
    u16 end=STRBUF_GetEosChar();
    u16 *s=STRBUF_GetChars(((struct WifiBsubwayCodeInParam *)p->codeInParam)->strbuf);
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

void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(struct WifiBsubwayWork *p) {
    p->saveControl0=(uptr)p->saveControl;
    p->saveValue0=0;
    p->saveFlag=1;
    p->saveValue1=1;
    p->saveSize=44;
    p->saveBuffer=p->saveData;
    GAMESYSTEM_CallProc(p->parent->proc,(uptr)ov115_id,gNetSaveMainProc,&p->saveControl0);
}

/*
 * extent: two-byte zero alignment padding, then already matched getter WIFI_BSUBWAY_GRAPHIC_GetSaveState.c.
 */
void WIFI_BSUBWAY_GRAPHIC_Noop(void *work) { }

int WIFI_BSUBWAY_GRAPHIC_GetSaveState(struct WifiBsubwayWork *p) { return p->saveState; }

void WIFI_BSUBWAY_GRAPHIC_StartRetryProc(struct WifiBsubwayWork *p) {
    p->retryControl0=(uptr)p->saveControl;
    p->retryValue0=0;
    p->retryValue1=1;
    p->retryValue2=1;
    GAMESYSTEM_CallProc(p->parent->proc,(uptr)ov115_id,gNetSaveRetryProc,&p->retryControl0);
}

void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *work) { }

int WIFI_BSUBWAY_GRAPHIC_DispatchTable(int **p, int x)
{
    Tbl t = d_021D8580;
    return t.f[**p](p, x);
}

/*
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 */
int WIFI_BSUBWAY_GRAPHIC_Step(struct WifiBsubwayWork *p,int b)
{
    int v;
    switch (p->state) {
    case 0: WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,7); ++p->state; break;
    case 1: WIFI_BSUBWAY_StartHttpRequest((u8 *)&p->status,(u8 *)&p->async,(p->saveData),b); ++p->state; break;
    case 2:
        v=WIFI_BSUBWAY_PollHttpRequest((u8 *)&p->status,(u8 *)&p->async,0);
        if(v==1) p->state=5;
        else if(v==2) p->state=3;
        break;
    case 3: WIFI_BSUBWAY_StartHttpRequest((u8 *)&p->status,(u8 *)&p->async,(p->saveData),b); ++p->state; break;
    case 4:
        if(WIFI_BSUBWAY_PollHttpRequest((u8 *)&p->status,(u8 *)&p->async,1)==1) p->state=5;
        break;
    case 5: WIFI_BSUBWAY_StartUploadPlayer((u8 *)&p->status,(u8 *)&p->async); ++p->state; break;
    case 6:
        if(WIFI_BSUBWAY_IsUploadDone((u8 *)&p->status,(u8 *)&p->async)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state;
        break;
    case 7: BSUBWAY_SCOREDATA_AccessFlag(p->saveBlock3A,1,2); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++p->state; break;
    case 8:
        if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,8); ++p->state; }
        break;
    case 9: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 10: return 1;
    }
    return 0;
}

int WIFI_BSUBWAY_GRAPHIC_StepWithInput(struct WifiBsubwayWork *p,short heap)
{
    int v,box;
    u32 n;
    u8 extra[12];
    u8 record[16];
    switch(p->state) {
    case 0: WIFI_BSUBWAY_StartRoomRequest((u8 *)&p->trainers,(u8 *)&p->async,(u32)BSUBWAY_SCOREDATA_GetLevel(p->saveBlock3A)); ++p->state; break;
    case 1: if(WIFI_BSUBWAY_FinishRoomRequest((u8 *)&p->trainers,(u8 *)&p->async)!=0) ++p->state; break;
    case 2:
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic); v=WIFI_BSUBWAY_GetDownloadResult((u8 *)&p->trainers);
        WIFI_BSUBWAY_GRAPHIC_SetWord(&p->graphic,0,v,(u32)WIFI_BSUBWAY_GetTransferState((u8 *)&p->trainers)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,0); ++p->state; break;
    case 3: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 4: FADE_Start((int)3,0,16,1); ++p->state; break;
    case 5: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(&p->graphic); ++p->state; } break;
    case 6: WIFI_BSUBWAY_OpenCodeIn((u8 *)p,heap); ++p->state; break;
    case 7: p->codeInValue=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(&p->graphic,heap); FADE_Start((int)3,16,0,1); ++p->state; break;
    case 8:
        if(FADE_IsActive()==0) {
            box=WIFI_BSUBWAY_GetRoomNumber((u8 *)&p->trainers); n=p->codeInValue; v=WIFI_BSUBWAY_GetDownloadResult((u8 *)&p->trainers);
            DWC_GetDateTime(record,extra);
            if(n<1 || n>(u32)v) { p->state=16; break; }
            if(BSUBWAY_WIFIDATA_GetTrainerBit(p->saveBlock3B,box,n,(struct Stamp *)record)!=0) { p->state=14; break; }
            WIFI_BSUBWAY_StartPlayerDownload((u8 *)&p->trainers,(u8 *)&p->async,p->codeInValue);
            v=WIFI_BSUBWAY_GetPlayerIndex((u8 *)&p->trainers); WIFI_BSUBWAY_GRAPHIC_SetWord(&p->graphic,0,v,(u32)WIFI_BSUBWAY_GetTransferState((u8 *)&p->trainers));
            WIFI_BSUBWAY_GRAPHIC_SetWord(&p->graphic,1,WIFI_BSUBWAY_GetRoomNumber((u8 *)&p->trainers),(uptr)((void *)2)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,1); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(&p->graphic); ++p->state;
        } break;
    case 9: if(WIFI_BSUBWAY_FinishPlayerDownload((u8 *)&p->trainers,(u8 *)&p->async)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 10: WIFI_BSUBWAY_NormalizeTrainers((u8 *)&p->trainers); WIFI_BSUBWAY_SaveTrainers((u8 *)&p->trainers,p->saveBlock3B); WIFI_BSUBWAY_SaveHistory((u8 *)&p->trainers,p->saveBlock3B); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++p->state; break;
    case 11: if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,3); ++p->state; } break;
    case 12: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 13: return 1;
    case 14: WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,2); ++p->state; break;
    case 15: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) p->state=2; break;
    case 16: WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,4); ++p->state; break;
    case 17: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 18: WIFI_BSUBWAY_GRAPHIC_CreateYesNo(&p->graphic); ++p->state; break;
    case 19: v=(int)WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(&p->graphic); if(v==0) return 2; if(v==-2) p->state=2; break;
    }
    return 0;
}

int WIFI_BSUBWAY_GRAPHIC_StepRetry(struct WifiBsubwayWork *p,short heap)
{
    int v;
    u32 n;
    switch(p->state) {
    case 0: WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,5); ++p->state; break;
    case 1: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 2: FADE_Start(3,0,16,1); ++p->state; break;
    case 3: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(&p->graphic); ++p->state; } break;
    case 4: WIFI_BSUBWAY_GRAPHIC_SetupTextParam(p,heap); ++p->state; break;
    case 5: p->codeInValue=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(&p->graphic,heap); FADE_Start(3,16,0,1); ++p->state; break;
    case 6:
        if(FADE_IsActive()==0) {
            n=p->codeInValue;
            if(n>=1 && n<=10) {
                WIFI_BSUBWAY_StartRoomRequest((u8 *)&p->trainers,(u8 *)&p->async,n); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,26); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(&p->graphic); ++p->state;
            } else p->state=19;
        } break;
    case 7:
        if(WIFI_BSUBWAY_FinishRoomRequest((u8 *)&p->trainers,(u8 *)&p->async)!=0) {
            WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic); v=WIFI_BSUBWAY_GetDownloadResult((u8 *)&p->trainers); WIFI_BSUBWAY_GRAPHIC_SetWord(&p->graphic,0,v,(u32)WIFI_BSUBWAY_GetTransferState((u8 *)&p->trainers)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,6); ++p->state;
        } break;
    case 8: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 9: FADE_Start(3,0,16,1); ++p->state; break;
    case 10: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(&p->graphic); ++p->state; } break;
    case 11: WIFI_BSUBWAY_OpenCodeIn((u8 *)p,heap); ++p->state; break;
    case 12: p->codeInValue=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(&p->graphic,heap); FADE_Start(3,16,0,1); ++p->state; break;
    case 13:
        if(FADE_IsActive()==0) {
            v=WIFI_BSUBWAY_GetDownloadResult((u8 *)&p->trainers); n=p->codeInValue;
            if(n<1 || n>(u32)v) { p->state=19; break; }
            WIFI_BSUBWAY_StartPlayerDownload((u8 *)&p->trainers,(u8 *)&p->async,n);
            v=WIFI_BSUBWAY_GetPlayerIndex((u8 *)&p->trainers); WIFI_BSUBWAY_GRAPHIC_SetWord(&p->graphic,0,v,(u32)WIFI_BSUBWAY_GetTransferState((u8 *)&p->trainers));
            WIFI_BSUBWAY_GRAPHIC_SetWord(&p->graphic,1,WIFI_BSUBWAY_GetRoomNumber((u8 *)&p->trainers),(uptr)((void *)2)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,1); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(&p->graphic); ++p->state;
        } break;
    case 14: if(WIFI_BSUBWAY_FinishPlayerDownload((u8 *)&p->trainers,(u8 *)&p->async)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 15: WIFI_BSUBWAY_NormalizeTrainers((u8 *)&p->trainers); WIFI_BSUBWAY_SaveHistory((u8 *)&p->trainers,p->saveBlock3B); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++p->state; break;
    case 16: if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic); WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,3); ++p->state; } break;
    case 17: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 18: return 1;
    case 19: WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,9); ++p->state; break;
    case 20: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic)!=0) ++p->state; break;
    case 21: WIFI_BSUBWAY_GRAPHIC_CreateYesNo(&p->graphic); ++p->state; break;
    case 22: v=WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(&p->graphic); if(v==0) return 2; if(v==-2) { WIFI_BSUBWAY_ClearTrainers((u8 *)&p->trainers); p->state=0; } break;
    }
    return 0;
}

void WIFI_BSUBWAY_GRAPHIC_InitBt(struct WifiBsubwayWork *p) {
    void *a=WIFILIST_GetWork(p->wifiList);
    void *b;
    u64 value;
    MYSTATUS_SetProfileIdOnce(p->myStatus,(u32)WIFILIST_GetGsProfileId(p->wifiList));
    b=(void *)MYSTATUS_GetProfileId(p->myStatus);
    value=DWC_CreateFriendKey(a);
    DPW_BT_Init((uptr)b,(u32)value,(u32)(value>>32),0);
    DPW_BT_GetServerStateAsync();
    WIFI_BSUBWAY_AsyncReset((u8 *)&p->async);
    p->dpwActive=1;
}

int WIFI_BSUBWAY_GRAPHIC_PollBt(struct WifiBsubwayWork *p)
{
    int result;
    return WIFI_BSUBWAY_PollAsync((u8 *)&p->async, &result);
}

/*
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 (pengy overlay, no witness).
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: DPW_BT_IsAsyncEnd (ov114 ARM, SDK-side
 *   libext code, no witness). Nothing source-side to change.
 */
void WIFI_BSUBWAY_GRAPHIC_CancelBt(struct WifiBsubwayWork *p)
{
    if (DPW_BT_IsAsyncEnd() == 0) {
        DPW_BT_CancelAsync();
        WIFI_BSUBWAY_AsyncReset((u8 *)&p->async);
    }
}

int WIFI_BSUBWAY_GRAPHIC_EndBt(struct WifiBsubwayWork *p)
{
    int result;
    if (p->dpwActive == 0) return 1;
    if (WIFI_BSUBWAY_PollAsync((u8 *)&p->async, &result)) {
        DPW_BT_End();
        p->dpwActive = 0;
        return 1;
    }
    return 0;
}

int WIFI_BSUBWAY_GRAPHIC_CheckNetError(struct WifiBsubwayWork *p) {
    int yes=1;
    int no=0;
    if(DWC_RAPCOMMON_HandleNetError(1,0)!=0) return no;
    if(GFL_NET_ERR_GetErrorLevel()!=0) {
        GFL_NET_STATE_GetError();
        return no;
    }
    if(WIFI_BSUBWAY_AsyncHasError((u8 *)&p->async)!=0) {
        int v;
        if(WIFI_BSUBWAY_CheckFatalError((int *)((u8 *)&p->async))!=0) return no;
        v=WIFI_BSUBWAY_GetErrorState((int *)((u8 *)&p->async));
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(&p->graphic);
        WIFI_BSUBWAY_GRAPHIC_PrintMessage(&p->graphic,v);
        return yes;
    }
    return no;
}

int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(struct WifiBsubwayWork *p) { return WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(&p->graphic); }

/*
 * evidence: incoming heap in r1 is forwarded unchanged to 021D821C.
 * evidence: 0203101C's second parameter is wide here: original 021D7C26
 * copies full r6 to r1 with no truncation; its definition stores the low halfword.
 */
void WIFI_BSUBWAY_GRAPHIC_CreateWindow(struct WifiBsubwayGraphic *p, short heap)
{
    p->bg = WIFI_BSUBWAY_GRAPHIC_Create(1, heap);
    p->heapId = heap;
    WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(p, heap);
    p->window = (void *)BMP_WIN_Create(1, 1, 19, 30, 4, 12, 1);
    BMP_MENUWORK_DrawWindow(p->window, 1, (u16)p->frameGfxA, 13);
    BMP_Clear(BMP_WIN_GetBmp(p->window), 15);
    BMP_WIN_MakeScreen(p->window);
    BMP_WIN_TransferChars(p->window);
    BG_SYS_MarkTileDirty(1);
    p->msgBank = MSGDATA_CreateFromArchive(0, 2, 206, heap);
    p->wordSet = WORDSET_CreateDefault(heap);
    p->font = GF_FONT_Create(23, 0, 0, 0, heap);
    p->strbufA = STRBUF_Create(128, heap);
    p->strbufB = STRBUF_Create(128, heap);
    p->tcbl = TCBL_Create(heap, heap, 1, 0);
    p->active = 1;
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RefreshWmIconAtTopRight(1, heap);
}

void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(struct WifiBsubwayGraphic *p) {
    if(p->active!=0) {
        if(p->printStream) PRINTSYS_PrintStreamDelete(p->printStream);
        TCBL_Destroy(p->tcbl);
        MSGDATA_Delete(p->msgBank);
        WORDSET_Delete(p->wordSet);
        GF_FONT_Delete(p->font);
        STRBUF_Delete(p->strbufA);
        STRBUF_Delete(p->strbufB);
        WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(p);
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p);
        if(p->yesNoMenu) {
            BMP_MENU_DeleteYesNo(p->yesNoMenu);
            p->yesNoMenu=0;
        }
        BMP_WIN_Delete(p->window);
        WIFI_BSUBWAY_GRAPHIC_Delete(p->bg);
        GF_FONT_SetDefaultTextColor();
        MI_CpuFill8(p,0,0x9ac);
    }
}

void WIFI_BSUBWAY_GRAPHIC_UpdateText(struct WifiBsubwayGraphic *p)
{
    if (p->active != 0) TCBL_Main(p->tcbl);
}

/*
 * lever: 2026-10-05 (wD9r lane92): the heap parameter is a signed 16-bit value (`short heap`). With u32
 *   heap the last call hoisted the heap reload above `str r6,[sp]` (10 bytes, waves D3 to D9r). The
 *   image truncates heap only for ARC_UTIL_LoadPaletteBlockFromHandle(u16 cast); the other callees take it unchanged.
 */
void WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(struct WifiBsubwayGraphic *p, short heap) {
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
    arc = ARC_TOOL_CreateHandle(0x91, heap);
    j = 0;
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 3, 4, 0, j, heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arc, 6, 4, 0, (u16)ARC_UTIL_RegisterObjCharFromHandle(arc, 4, 4, 0, j, heap), j, j, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 3, 0, 0, j, heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arc, 5, 0, 0, (u16)ARC_UTIL_RegisterObjCharFromHandle(arc, 4, 0, 0, j, heap), j, j, heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arc, 7, 3, 0, (u16)ARC_UTIL_RegisterObjCharFromHandle(arc, 4, 3, 0, j, heap), j, j, heap);
    MI_CpuFill8(&p->animCallback, 0, 0x970);
    blk = ARC_UTIL_LoadPaletteBlockFromHandle(arc, 2, (void *)(uptr)(&res), (u16)heap);
    MI_CpuCopy8(res->fC, p->pad014, 0x1e0);
    MI_CpuCopy8(res->fC, p->palette, 0x1e0);
    GFL_HEAP_Free(blk);
    k = 0;
    pa = p->palette;
    pb = (u8 *)p;
    pb += 0x14;
    for (; k < 15; k++) {
        n = k + 1;
        if (n >= 15) n -= 15;
        t = 0;
        done = 0;
        q = (u8 *)p + n * 32;
        for (;;) {
            a = pb + k * 32;
            sh = t >> 8;
            b = pa + j * 32;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors((u16 *)(a + m * 2), (u16 *)(b + m * 2), 1, (u8)sh, *(u16 *)(q + 0x14 + m * 2));
            }
            j++;
            if (done == 1) break;
            t += 0x600;
            if (t >= 0x1000) { t = 0x1000; done = 1; }
        }
    }
    DC_FlushRange(p->palette, 0x780);
    p->animEnabled = 1;
    p->animCallback = GFL_USE_AddMainTask((void *)WIFI_BSUBWAY_GRAPHIC_StepBgAnim, &p->animCallback, 0x14);
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 1, 8, 8, 0x10);
    p->animPhase = 0;
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_CreateRun(1, 0x20, 0);
    BG_SYS_CreateRun(2, 0x20, 0);
    p->frameGfxA = (uptr)BMP_MENUWORK_LoadFrameGfx((uptr)(void *)1, 0xd, 0, heap);
    p->frameGfxB = (uptr)BMP_MENUWORK_LoadFrameGfx((uptr)(void *)2, 0xd, 0, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x180, 0x20, heap);
}

void WIFI_BSUBWAY_GRAPHIC_StepBgAnim(void *unused,struct WifiBsubwayAnim *p) {
    if(p->enabled!=0) {
        p->toggle^=1;
        if((p->toggle&1)==0) {
            GX_LoadBGPltt(p->palette+(p->frame<<5),40,14);
            GXS_LoadBGPltt(p->palette+(p->frame<<5),40,14);
            p->frame++;
            if(p->frame>=60) p->frame=0;
            BG_SYS_ChangeScrollImmediate(p->phase,2,7);
        }
    }
}

void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(struct WifiBsubwayGraphic *p) {
    unsigned int x=p->frameGfxA;
    BG_SYS_FreeTileRun(1,(u16)x,(u16)(x>>16));
    x=p->frameGfxB;
    BG_SYS_FreeTileRun(2,(u16)x,(u16)(x>>16));
    if(p->animCallback) {
        TCB_DeleteTask(p->animCallback);
        p->animCallback=0;
        p->animEnabled=0;
    }
    *(u16 *)0x04000050=0;
}

void WIFI_BSUBWAY_GRAPHIC_PrintMessage(struct WifiBsubwayGraphic *p,unsigned int a) {
 if(p->printStream!=0) {PRINTSYS_PrintStreamDelete(p->printStream); p->printStream=0;}
 MSGDATA_ReadString((struct MsgBank *)p->msgBank,a,(struct Strbuf *)p->strbufA);
 WORDSET_CopyTaggedText((struct WordSet *)p->wordSet,(struct Strbuf *)p->strbufB,(struct Strbuf *)p->strbufA);
 BMP_Clear((struct Bmp *)((struct CharBuf *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)(struct Descriptor *)p->window))),15);
 GF_FONT_SetTextColor(1,2,15);
 p->printStream=PRINTSYS_PrintStream((struct BmpWin *)((uptr)p->window),0,0,(struct Strbuf *)((uptr)p->strbufB),(struct GfFont *)((uptr)p->font),MSG_SPEED_GetWait(),(struct Tcbl *)((uptr)p->tcbl),2,p->heapId,15);
 BMP_MENUWORK_DrawWindow((void *)p->window,1,(u16)p->frameGfxA,13);
 BMP_WIN_TransferChars((struct BmpWin *)p->window);
}

int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(struct WifiBsubwayGraphic *p) {
 int v;
 if(p->printStream==0) return 1;
 v=PRINTSYS_PrintStreamGetState(p->printStream);
 if(v==2) { PRINTSYS_PrintStreamDelete(p->printStream); p->printStream=0; return 1; }
 if(v==1) { if(KEY_GetTrg()==1 || TOUCHPANEL_GetTrg()!=0) PRINTSYS_PrintStreamReleasePause(p->printStream); }
 return 0;
}

void WIFI_BSUBWAY_GRAPHIC_SetWord(struct WifiBsubwayGraphic *p, unsigned int i, unsigned int a, unsigned int b)
{
    WORDSET_SetSlotNumber(p->wordSet, i, a, b, 2, 1);
}

/*
 * The duplicated 021D8560 pool words require separate extern names;
 * see the duplicated-pool-word idiom.
 */
void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(struct WifiBsubwayGraphic *p) { *(u16 *)(gWifiBsubwayCodeInParam+4)=p->frameGfxB; p->yesNoMenu=BMP_MENU_CreateYesNo((const struct WinDat *)d_021D8560_menu,p->frameGfxB,13,0,p->heapId); }

unsigned int WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(struct WifiBsubwayGraphic *p) { unsigned int result=-2; if(p->yesNoMenu!=0) { result=BMP_MENU_ProcessYesNo(p->yesNoMenu); if(result!=-1) p->yesNoMenu=0; } return result; }

void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(struct WifiBsubwayGraphic *p) { p->timeIcon=TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(),p->window,15,16,p->heapId); }

void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(struct WifiBsubwayGraphic *p) { if(p->timeIcon!=0) { TIME_ICON_Delete(p->timeIcon); p->timeIcon=0; } }

void WIFI_BSUBWAY_GRAPHIC_StartSave(struct WifiBsubwayWork *p) { (struct GameData *)GAME_DATA_SaveStart((struct GameData *)p->saveControl); p->dpwDone=1; }

int WIFI_BSUBWAY_GRAPHIC_UpdateSave(struct WifiBsubwayWork *p) { if(p->dpwDone==0) return 1; if(GAME_DATA_SaveMain((struct GameData *)p->saveControl)==2) { p->dpwDone=0; return 1; } return 0; }

/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
void *WIFI_BSUBWAY_GRAPHIC_Create(int a,unsigned heap) {
 struct WifiBsubwayBg *p;
 p=GFL_HEAP_Alloc(heap,16,0,d_021D858C,0x1bc);
 MI_CpuFill8(p,0,16);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks((const struct DispVram *)d_021D83C0); BG_SYS_SetLcdSwap(a);
 BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes(); GF_FONT_InitTextColor();
 WIFI_BSUBWAY_GRAPHIC_SetupBg(p,heap);
 p->redrawCallback=GFL_USE_AddMainTask((void *)WIFI_BSUBWAY_GRAPHIC_OnRedraw,p,0);
 return p;
}

void WIFI_BSUBWAY_GRAPHIC_Delete(struct WifiBsubwayBg *p) {
 TCB_DeleteTask(p->redrawCallback); WIFI_BSUBWAY_GRAPHIC_TeardownBg(p); GF_FONT_SetDefaultTextColor();
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 MI_CpuFill8(p,0,16); GFL_HEAP_Free(p);
}

void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *a,void *b) {WIFI_BSUBWAY_GRAPHIC_Draw(b);}

void WIFI_BSUBWAY_GRAPHIC_SetupBg(struct WifiBsubwayBg *p,unsigned heap) {
 unsigned i; struct WifiBsubwayBgLayer *q; unsigned n;
 MI_CpuFill8(p,0,4);
 BG_SYS_Create(heap); BMP_WIN_Init(heap); BG_SYS_SetGraphicsMode((struct DispConfig *)d_021D83B0);
 for(i=0;i<8;i++) {
 q=(struct WifiBsubwayBgLayer *)(d_021D83F0+i*44); n=q->layer;
 BG_SYS_InitBgLayer((u8)n,(const struct BgTemplate *)q->templateData,(u8)q->type);
 BG_SYS_FreeSlot(n); BG_SYS_SetPlaneVisible(n,q->slot);
 }
}

void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *work)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        BG_SYS_FreeLayerBuf((u8)*(unsigned int *)(g_021D83F0 + i * 0x2c));
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(work, 0, 4);
}

void WIFI_BSUBWAY_GRAPHIC_Draw(void *p) { BG_SYS_Update(); }
