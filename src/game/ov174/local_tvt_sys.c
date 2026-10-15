/*
 * file:     local_tvt_sys.c
 * unit:     yes
 * function: LOCAL_TVT_SYS_Create, LOCAL_TVT_SYS_Delete, LOCAL_TVT_SYS_Main, LOCAL_TVT_SYS_VBlankHandler, LOCAL_TVT_SYS_SetupDisplay, LOCAL_TVT_SYS_ExitSystem, LOCAL_TVT_SYS_SetupBgLayer, LOCAL_TVT_SYS_LoadMenuData, LOCAL_TVT_SYS_CreateGraphics, LOCAL_TVT_SYS_PositionActor, LOCAL_TVT_SYS_HideActor, LOCAL_TVT_SYS_CreateTextResources, LOCAL_TVT_SYS_DeleteTextResources, LOCAL_TVT_SYS_UpdateText, LOCAL_TVT_SYS_IsPrintIdle, LOCAL_TVT_SYS_CreateTextWindow, LOCAL_TVT_SYS_DeleteTextWindow, LOCAL_TVT_SYS_PrintMessage, LOCAL_TVT_SYS_RunStep, LOCAL_TVT_SYS_ApplyStep, LOCAL_TVT_SYS_OnSelect, LOCAL_TVT_SYS_ResetTimer, LOCAL_TVT_SYS_TickTimer, LOCAL_TVT_SYS_ProcInit, LOCAL_TVT_SYS_ProcExit, LOCAL_TVT_SYS_ProcMain
 * address:  0x021B6100
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from local_tvt_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_020056A0 0x020056A0 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   VM_GetTimeZoneLight 0x02011400 thumb
 *   GF_STANDARD_SetField00 0x0203F4CC arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_02005728 0x02005728 thumb
 *   func_02040618 0x02040618 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   func_02082A7C 0x02082A7C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B7450 0x021B7450 data a4
 *   d_021B7388 0x021B7388 data a4
 *   d_021B73D0 0x021B73D0 data a4
 *   d_021B73B0 0x021B73B0 data a4
 *   d_021B7410 0x021B7410 data a4
 *   d_021B7430 0x021B7430 data a4
 *   d_021B73F0 0x021B73F0 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02012944 0x02012944 thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   func_02049B40  0x02049B40  arm
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   TCBL_Create  0x0203101C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   func_02028484 0x02028484 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02028470 0x02028470 thumb
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   g_021B7398  0x021B7398  data  a4
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   d_021B74AC 0x021B74AC data
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   LOCAL_TVT_CHARA_Create 0x021B6C70 thumb ov174
 *   LOCAL_TVT_CHARA_Delete 0x021B6D00 thumb ov174
 *   LOCAL_TVT_CHARA_Update 0x021B6D3C thumb ov174
 *   LOCAL_TVT_CHARA_SetActive 0x021B6F24 thumb ov174
 *   LOCAL_TVT_CHARA_IsDone 0x021B6F2C thumb ov174
 *   LOCAL_TVT_CHARA_ShowWindow 0x021B7350 thumb ov174
 *   LOCAL_TVT_CHARA_GetState 0x021B7360 thumb ov174
 *   LOCAL_TVT_CHARA_SetState 0x021B7364 thumb ov174
 *   LOCAL_TVT_CHARA_ClearState 0x021B7378 thumb ov174
 */
#include "../../matched/include/Obj01167.h"
#include "../../matched/include/Obj24197.h"
#include "../../matched/include/Obj00681.h"
#include "../../matched/include/Obj00152.h"
#include "../../matched/include/Obj03859.h"
#include "../../matched/include/Obj00545.h"
#include "../../matched/include/Obj24199.h"
#include "../../matched/include/Obj24200.h"
#include "../../matched/include/Obj00918.h"
#include "../../matched/include/Obj24201.h"
#include "../../matched/include/Obj02507.h"
#include "../../matched/include/Obj02218.h"
#include "../../matched/include/Obj00919.h"
#include "../../matched/include/Obj08268.h"
#include "../../matched/include/Obj24202.h"
#include "../../matched/include/Obj24203.h"
#include "../../matched/include/Obj10673.h"
#include "../../matched/include/Obj24204.h"
#include "local_tvt_sys_shared_types.h"

struct BigObj;

struct Bank;

struct Node;

struct DispConfig;

struct DispVram;

struct BgTemplate;

struct Vec2;

struct GfFont;

struct Tcbl;

struct Rec;

struct Rec3;

struct S02031140;

struct Blk;

struct Ctx;

struct Obj0203159C;

struct S020315D4;

struct RtcTime{unsigned hour,minute,second;};

typedef unsigned int   u32_021B6100;

typedef unsigned u32_021B622C;

typedef enum { SZ0=0,SZ1=1,SZ2=2,SZ3=3 } GXBGScrSize256x16Pltt;

typedef enum { OVER0=0,OVER1=1 } GXBGAreaOver;

typedef enum { SB0=0,SB31=31 } GXBGScrBase;

typedef enum { CB0=0,CB15=15 } GXBGCharBase;

typedef unsigned u32_021B63DC;

typedef struct { u32_021B63DC w[7]; } Config;

typedef unsigned int   u32_021B655C;

typedef struct { u16 x,y,z; u8 a,b; } Spec;

typedef unsigned int   u32_021B6704;

typedef unsigned int u32_021B6760;

typedef unsigned int   u32_021B6824;

typedef unsigned int   u32_021B687C;

typedef struct Ent {
    void (*init)(Obj *);
    int (*update)(Obj *);
} Ent;

struct E { u8 a, b; u16 c; };

struct P { u8 pad0[0x40]; struct E *tbl; u8 pad1[0x89 - 0x44]; u8 idx; };

extern void *func_020490F4(u32_021B6100 id, u32_021B6100 heap);

extern void *func_020056A0(unsigned,unsigned,unsigned);

extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

extern u8 VM_GetTimeZoneLight(int row, int col);

extern void GF_STANDARD_SetField00(struct RtcTime *),GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);

extern void func_02030EAC(struct Node *n);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_ReleasePalette(u32_021B61C4 i);

extern void CLACT_ReleaseCharacter(u32_021B61C4 i);

extern void CLACT_ReleaseCellAnim(u32_021B61C4 i);

extern u32_021B61C4 CLACT_DeleteUnit(struct Bank *bank);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32_021B61C4 func_020307B0(void *p);

extern void WIPE_SYS_Start(void *,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C);

extern u32_021B622C WIPE_SYS_EndCheck(void);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

extern int func_02005728(int);

extern void func_02040618(unsigned,unsigned,unsigned);

extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);

extern void WIPE_SetBrightnessFadeOut(u32_021B63DC a, u32_021B63DC color);

extern u32_021B63DC WIPE_ResetWndMask(void *win);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void func_02082A7C(int,int,u32_021B63DC);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32_021B63DC arg, u32_021B63DC heapId);

extern void BG_SYS_SetMainPlaneVisible(u32_021B63DC mask, u32_021B63DC enable);

extern void BG_SYS_SetSubPlaneVisible(u32_021B63DC mask, u32_021B63DC enable);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32_021B63DC heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void func_0207D63C(void *,int,int,int,int);

extern void CLACT_ExitSystem(void),func_020403F4(unsigned),BMP_WIN_Exit(void),BG_SYS_Delete(void);

extern void BG_SYS_InitBgLayer(unsigned,const struct BgTemplate *,unsigned);

extern void func_02040588(unsigned,unsigned),BG_SYS_FreeSlot(unsigned),func_020409B4(unsigned);

extern void *ARC_UTIL_LoadHandleMember(void *a0, u32_021B655C a1, u32_021B655C a2, u32_021B655C a3);

extern void func_020498F4(void *,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u16);

extern u8 *func_02012944(void *p);

extern int CLACT_RegisterPaletteCompressed(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);

extern int CLACT_RegisterCharacter(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);

extern s32 CLACT_RegisterCellAnim(void *owner, u32_021B6594 first, u32_021B6594 second, u32_021B6594 mode);

extern u8 func_02008550(const struct Sub0200852CObj *obj);

extern void func_02049B68(void *,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u16);

extern u32_021B6594 func_02049658(void *a, u32_021B6594 b, u32_021B6594 c, u32_021B6594 d, u32_021B6594 e, u32_021B6594 f, u16 g);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct Obj *p, u32_021B6594 v);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32_021B6594 v);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32_021B6704 which);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32_021B6760 heapId);

extern struct MsgBank *func_02045B38(u32_021B6760 resident, u32_021B6760 arcId, u32_021B6760 fileId, u32_021B6760 heapId);

extern void BMP_MENUWORK_LoadCharAndPltt(u32_021B6760 a, u32_021B6760 b, u32_021B6760 c, u32_021B6760 d, u16 e);

extern u8 BMP_MENUWORK_GetPlttFileId(int i);

extern void ARC_UTIL_UploadPaletteFromArchive(u32_021B6760 a0, u32_021B6760 a1, u32_021B6760 a2, u32_021B6760 a3, u32_021B6760 a4, u32_021B6760 a5, u16 a6);

extern void func_02049B40(u32_021B6760 a, u32_021B6760 b, u32_021B6760 c, u32_021B6760 d, u32_021B6760 e, u16 f);

extern void GF_FONT_SetDefaultTextColor(void);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32_021B6760 count, u32_021B6760 workSize);

extern u32_021B6760 PRINTSYS_QUE_Create(void *p);

extern u32_021B6760 func_02028590(int a, int b, int c, u32_021B6760 d);

extern void GF_FONT_SetTextColor(u32_021B6760 r, u32_021B6760 g, u32_021B6760 b);

extern int APP_KEYCURSOR_Delete(int a0);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void STRBUF_Delete(struct U16Vec *vec);

extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern unsigned int BMP_WIN_Delete(struct Descriptor *d);

extern u32_021B6824 GF_FONT_Delete(void *ptr);

extern void TCBL_Destroy(struct S02031140 *p);

extern void TCBL_Main(struct Tcbl *p);

extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

extern unsigned PRINTSYS_PrintStreamGetState(void *);

extern s32 func_02028484(struct Blk *blk, void *h);

extern u32_021B687C PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32_021B68F8 kind);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern void func_02041B6C(unsigned);

extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void func_02028470(u8 *p, u32_021B68F8 v);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern u32_021B68F8 BMP_WIN_Create(u32_021B68F8 layer, u32_021B68F8 a, u32_021B68F8 b, u32_021B68F8 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void *func_02045EC0(struct MsgBank *bank, u32_021B6A04 index);

extern struct U16Vec *STRBUF_Create(u32_021B6A04 capacity, u32_021B6A04 heapId);

extern signed char MSG_SPEED_GetWait(void);

extern unsigned PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *GAME_DATA_Create(u16);

extern unsigned int KEY_GetCont(void);

extern void LOCAL_TVT_SYS_Delete(unsigned char *),GAME_DATA_Delete(unsigned char *),func_020315D4(struct S020315D4 *),GFL_HEAP_DeleteChecked(unsigned int);

void LOCAL_TVT_SYS_Create(u8 *p);

void LOCAL_TVT_SYS_Delete(u8 *p);

int LOCAL_TVT_SYS_Main(u8 *p);

void LOCAL_TVT_SYS_VBlankHandler(void);

void LOCAL_TVT_SYS_SetupDisplay(u8 *p);

void LOCAL_TVT_SYS_ExitSystem(unsigned char *p);

void LOCAL_TVT_SYS_SetupBgLayer(const struct BgTemplate *p, int i, int type);

void LOCAL_TVT_SYS_LoadMenuData(char *p);

void LOCAL_TVT_SYS_CreateGraphics(u8 *p);

void LOCAL_TVT_SYS_PositionActor(u8 *p, int index);

void LOCAL_TVT_SYS_HideActor(char *p);

void LOCAL_TVT_SYS_CreateTextResources(u8 *p);

void LOCAL_TVT_SYS_DeleteTextResources(u8 *p);

void LOCAL_TVT_SYS_UpdateText(u8 *p);

int LOCAL_TVT_SYS_IsPrintIdle(char *p);

void LOCAL_TVT_SYS_CreateTextWindow(u8 *p,int mode);

void LOCAL_TVT_SYS_DeleteTextWindow(u8 *p);

void LOCAL_TVT_SYS_PrintMessage(u8 *p, int message);

void LOCAL_TVT_SYS_RunStep(Obj *o);

void LOCAL_TVT_SYS_ApplyStep(u8 *p);

int LOCAL_TVT_SYS_OnSelect(char *p);

void LOCAL_TVT_SYS_ResetTimer(char *p);

int LOCAL_TVT_SYS_TickTimer(char *p);

int LOCAL_TVT_SYS_ProcInit(void *ctx,int unused,char *arg);

int LOCAL_TVT_SYS_ProcExit(struct S020315D4 *a,unsigned unused,int own,unsigned char *p);

int LOCAL_TVT_SYS_ProcMain(int a, int b, int c, int d);

char *LOCAL_TVT_CHARA_Create(char *p,int index);

void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p);

void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q);

void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2);

int LOCAL_TVT_CHARA_IsDone(int unused, char *p);

void LOCAL_TVT_CHARA_ShowWindow(int a, int *p);

unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p);

void LOCAL_TVT_CHARA_SetState(char *p, int v);

void LOCAL_TVT_CHARA_ClearState(char *p);

extern const u32_021B63DC d_021B7450[],d_021B7388[],d_021B73D0[],d_021B73B0[],d_021B7410[],d_021B7430[],d_021B73F0[];

extern const Config gClActorInitParam;

extern const Pair_021B6100 d_021B7380[];

extern const Ent g_021B7398[];

extern char d_021B74AC[];

void LOCAL_TVT_SYS_Create(u8 *p)
{
 struct RtcTime time; unsigned config,lo,mid,hi; u8 i; void *task; unsigned one;
 LOCAL_TVT_SYS_SetupDisplay(p);
 ((struct Obj01167 *)p)->f18=func_020490F4(131,((struct Obj01167 *)p)->f0);
 LOCAL_TVT_SYS_LoadMenuData((char *)p);LOCAL_TVT_SYS_CreateGraphics(p);LOCAL_TVT_SYS_CreateTextResources(p);
 config=GAME_DATA_GetSeason(((struct Obj24197 *)(*(u8 * *)&((struct Obj01167 *)p)->f30))->f4);
 lo=VM_GetTimeZoneLight(config,0);mid=VM_GetTimeZoneLight(config,2);hi=VM_GetTimeZoneLight(config,3);
 GF_STANDARD_SetField00(&time);
 if(time.hour>=lo && time.hour<mid) ((struct Obj01167 *)p)->f10=0;
 else if(time.hour>=mid && time.hour<hi) ((struct Obj01167 *)p)->f10=1;
 else ((struct Obj01167 *)p)->f10=2;
 for(i=0;i<((struct Obj01167 *)p)->f8;i++) *(void **)(p+28+i*4)=LOCAL_TVT_CHARA_Create((char *)p,i);
 task=func_020056A0((unsigned)LOCAL_TVT_SYS_VBlankHandler,(unsigned)p,8);
 one=1;((struct Obj01167 *)p)->fD=one;((struct Obj01167 *)p)->f34=one;
 ((struct Obj01167 *)p)->f4=task;((struct Obj01167 *)p)->f89=0;
 ((struct Obj01167 *)p)->fE=0;((struct Obj01167 *)p)->f14=0;((struct Obj01167 *)p)->f2C=0;((struct Obj01167 *)p)->fC=0;
 GFL_NET_RestartWithDefaultTimeout(0,((struct Obj01167 *)p)->f0);
}

void LOCAL_TVT_SYS_Delete(u8 *p)
{
    u8 i;
    func_02030EAC(((struct Obj00681 *)p)->f4);
    LOCAL_TVT_SYS_DeleteTextResources(p);
    for(i=0;i<((struct Obj00681 *)p)->f8;i++) if(*(void **)(p+28+i*4)) LOCAL_TVT_CHARA_Delete(p,*(void **)(p+28+i*4));
    CLACT_DeleteActor(((struct Obj00681 *)p)->f54);
    CLACT_ReleasePalette((u32_021B61C4)(((struct Obj00681 *)p)->f44));
    CLACT_ReleaseCharacter((u32_021B61C4)(((struct Obj00681 *)p)->f48));
    CLACT_ReleaseCellAnim((u32_021B61C4)(((struct Obj00681 *)p)->f4C));
    CLACT_DeleteUnit(((struct Obj00681 *)p)->f50);
    ARC_TOOL_DeleteHandle(((struct Obj00681 *)p)->f18);
    LOCAL_TVT_SYS_ExitSystem(p);
    func_020307B0(((struct Obj00681 *)p)->f38);
}

static inline void G2_SetBG2Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000C=(u16)((*(volatile u16 *)0x0400000C &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}

static inline void G2_SetBG3Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000E=(u16)((*(volatile u16 *)0x0400000E &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}

int LOCAL_TVT_SYS_Main(u8 *p)
{
    GXBGCharBase a,b;
    unsigned state;
    u8 i;
    switch(p[12]) {
    case 0:
        WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj00152 *)p)->f0);
        p[12]=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) p[12]=4;
        break;
    case 2:
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj00152 *)p)->f0);
        p[12]=3;
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        LOCAL_TVT_SYS_RunStep((Obj *)p);
        break;
    }
    if(p[14]<20) p[14]++;
    if(*(int *)&((struct Obj00152 *)p)->f2C==0 && ((struct Obj00152 *)p)->f14==4) {
        if(p[13]==0) {a=4;b=10;} else {a=7;b=13;}
        G2_SetBG2Control256x16Affine(SZ1,OVER1,(GXBGScrBase)13,a);
        G2_SetBG3Control256x16Affine(SZ1,OVER1,(GXBGScrBase)14,b);
        p[13]=p[13]==0?1:0;
        ((struct Obj00152 *)p)->f14=0;
        p[14]=0;
    }
    if(*(char * *)&((struct Obj00152 *)p)->f2C!=0 && LOCAL_TVT_CHARA_IsDone((int)p,*(char * *)&((struct Obj00152 *)p)->f2C)==1)
        *(char * *)&((struct Obj00152 *)p)->f2C=0;
    if(*(int *)&((struct Obj00152 *)p)->f2C==0) {
        state=*(unsigned *)&((struct Obj00152 *)p)->f14;
        switch(state) {
        case 0: case 1: case 2: case 3: {
            u32_021B622C index=(u8)state*4;
            u32_021B622C table=(u32_021B622C)p+28;
            if(*(u8 **)(table+index)!=0) {
                LOCAL_TVT_CHARA_SetActive(p,*(u8 **)(table+index),p[13]);
                *(u8 * *)&((struct Obj00152 *)p)->f2C=*(u8 **)(table+index);
                if(((struct Obj00152 *)p)->f8==2 && ((struct Obj00152 *)p)->f14==1) ((struct Obj00152 *)p)->f14=4;
                else (((struct Obj00152 *)p)->f14)++;
            } else ((struct Obj00152 *)p)->f14=state+1;
            break;
        }
        }
    }
    for(i=0;i<((struct Obj00152 *)p)->f8;i++) {
        if(*(u8 **)(p+28+i*4)!=0) LOCAL_TVT_CHARA_Update(p,*(u8 **)(p+28+i*4));
    }
    LOCAL_TVT_SYS_UpdateText(p);
    CLACT_DrawSystem();
    return 0;
}

void LOCAL_TVT_SYS_VBlankHandler(void) {CLACT_VBlankSystem();func_02040618(1,0,func_02005728(256));func_02040618(1,3,func_02005728(256));}

/*
 *   one --arm, no region: MATCH, 16 bytes, blocker434CC.log; concrete bytes agree,
 *   unresolved 020434B4 is also omitted from that owner unit's function header.
 *   Scratch copy of owner unit also verifies TU EXACT: blocker434unit.log.
 *   extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 *   void BG_SYS_ClearMainPlanes(void) {BG_SYS_ClearMainBgPlanes();BG_SYS_ClearMainObjPlane();}
 *   one --arm, no region: EXACT, 16 bytes, blocker43588.log.
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) {BG_SYS_ClearSubBgPlanes();BG_SYS_ClearSubObjPlane();}
 *   retained without an overlay token, ROM pool +0128 names 020A1448.
 * volatile: DISPCNT reads/writes 021B63EE..021B63FE; blend writes 021B6420/6424; POWCNT1 read/write 021B6426..642E.
 */
void LOCAL_TVT_SYS_SetupDisplay(u8 *p)
{
    Config c;
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32_021B63DC *)0x04000000 &= ~0x1F00;
    *(volatile u32_021B63DC *)0x04001000 &= ~0x1F00;
    WIPE_SetBrightnessFadeOut(0,0);
    WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u16 *)0x04000304 |=0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B7450);
    BG_SYS_Create(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((void *)d_021B7388);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73D0,0,0);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73B0,1,0);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B7410,2,2);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B7430,3,2);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73F0,7,0);
    func_02082A7C(0,0x06000000,0x40000);
    c=gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&c),(u32_021B63DC)d_021B7450,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    *(void **)(p+80)=CLACT_CreateUnit(16,0,*(u16 *)p);
    CLACT_SetUnitDefaultRenderer(*(void **)(p+80));
    func_0207D63C((void *)0x04000050,1,30,16,4);
}

void LOCAL_TVT_SYS_ExitSystem(unsigned char *p) {CLACT_ExitSystem();func_020403F4(7);func_020403F4(3);func_020403F4(2);func_020403F4(1);func_020403F4(0);BMP_WIN_Exit();BG_SYS_Delete();}

void LOCAL_TVT_SYS_SetupBgLayer(const struct BgTemplate *p, int i, int type) {BG_SYS_InitBgLayer(i,p,type);func_02040588(i,1);BG_SYS_FreeSlot(i);func_020409B4(i);}

void LOCAL_TVT_SYS_LoadMenuData(char *p) {unsigned char *q=ARC_UTIL_LoadHandleMember(((struct Obj03859 *)p)->f18,**(unsigned short * *)&((struct Obj03859 *)p)->f30+62,0,((struct Obj03859 *)p)->f0);((struct Obj03859 *)p)->f38=q;((struct Obj03859 *)p)->f3C=q;((struct Obj03859 *)p)->f40=q+8;if(q[2]==255 && q[3]==255) ((struct Obj03859 *)p)->f8=2;else ((struct Obj03859 *)p)->f8=4;}

void LOCAL_TVT_SYS_CreateGraphics(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    Spec s;
    if(((struct Obj00545 *)p)->f8!=2) id=38;
    func_020498F4(((struct Obj00545 *)p)->f18,id,2,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(((struct Obj00545 *)p)->f18,id,3,0,0,0,((struct Obj00545 *)p)->f0);
    save=func_02012944(((struct Obj24199 *)(*(u8 * *)&((struct Obj00545 *)p)->f30))->f4);
    arc=func_020490F4(172,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f44=CLACT_RegisterPaletteCompressed(arc,3,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f48=CLACT_RegisterCharacter(arc,24,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f4C=CLACT_RegisterCellAnim(arc,20,22,((struct Obj00545 *)p)->f0);
    if(func_02008550(save)==0) func_02049B68(arc,7,4,0,0x60,((struct Obj00545 *)p)->f0);
    else func_02049B68(arc,6,4,0,0x60,((struct Obj00545 *)p)->f0);
    func_02049658(arc,11,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,14,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020409B4(7);
    func_02049B68(arc,0,0,0x160,0x20,((struct Obj00545 *)p)->f0);
    func_02049658(arc,8,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,13,1,0,0,0,((struct Obj00545 *)p)->f0);
    BG_SYS_FillTileMap(1,0,0,32,32,11);
    func_020409B4(1);
    ARC_TOOL_DeleteHandle(arc);
    s.a=10; s.b=1; s.x=0;s.y=0;s.z=0;
    ((struct Obj00545 *)p)->f54=CLACT_CreateActor((void *)((struct Obj00545 *)p)->f50,((struct Obj00545 *)p)->f48,((struct Obj00545 *)p)->f44,((struct Obj00545 *)p)->f4C,&s,0,((struct Obj00545 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00545 *)p)->f54,0);
    CLACT_SetActorAutoAnim(((struct Obj00545 *)p)->f54,1);
}

void LOCAL_TVT_SYS_PositionActor(u8 *p, int index)
{
    u16 point[2];
    unsigned width;
    unsigned x;
    unsigned y;
    width = LOCAL_TVT_CHARA_GetState(*((void **) ((p + 28) + (index * 4))));
    width = width / 2;
    x = ((d_021B7380[index].x * 8) + 80) + width;
    point[0] = x;
    y = (d_021B7380[index].y * 8) + 16;
    point[1] = y;
    CLACT_AddActorSurfacePos(*((void **) (p + 84)), (const struct Vec2 *)point, 0);
    CLACT_SetActorDrawEnable(*((void **) (p + 84)), 1);
    CLACT_RestartActorAnim(*((void **) (p + 84)));
}

void LOCAL_TVT_SYS_HideActor(char *p) {CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj24200 *)p)->f54,0);}

void LOCAL_TVT_SYS_CreateTextResources(u8 *p)
{
    ((struct Obj00918 *)p)->f60 = (u32_021B6760)GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f68 = (u32_021B6760)func_02045B38(0, 2, 0xc6, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f6C = (u32_021B6760)func_02045B38(0, 2, (u16)(*(u16 *)(((struct Obj00918 *)p)->f30) + 0xbf), ((struct Obj00918 *)p)->f0);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xd, 0, ((struct Obj00918 *)p)->f0);
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0x20, 0x1a0, 0x20, ((struct Obj00918 *)p)->f0);
    func_02049B40(0x17, 7, 0, 0x180, 0x20, ((struct Obj00918 *)p)->f0);
    GF_FONT_SetDefaultTextColor();
    ((struct Obj00918 *)p)->f58 = (u32_021B6760)TCBL_Create(((struct Obj00918 *)p)->f0, ((struct Obj00918 *)p)->f0, 3, 0x100);
    ((struct Obj00918 *)p)->f64 = 0;
    ((struct Obj00918 *)p)->f5C = 0;
    ((struct Obj00918 *)p)->f70 = 0;
    ((struct Obj00918 *)p)->f74 = 0;
    ((struct Obj00918 *)p)->f78 = PRINTSYS_QUE_Create((void *)(((struct Obj00918 *)p)->f0));
    ((struct Obj00918 *)p)->f7C = func_02028590(0xf, 1, 1, ((struct Obj00918 *)p)->f0);
    GF_FONT_SetTextColor(1, 2, 0xf);
}

/*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 */
void LOCAL_TVT_SYS_DeleteTextResources(u8 *p)
{
    APP_KEYCURSOR_Delete((int)(((struct Obj00681 *)p)->f7C));
    PRINTSYS_QUE_Delete(((struct Obj00681 *)p)->f78);
    if(((struct Obj00681 *)p)->f64) PRINTSYS_PrintStreamDelete(((struct Obj00681 *)p)->f64);
    if(((struct Obj00681 *)p)->f70) STRBUF_Delete(((struct Obj00681 *)p)->f70);
    if(((struct Obj00681 *)p)->f74) WORDSET_DeleteStrbufED04(((struct Obj00681 *)p)->f74);
    MSGDATA_Delete(((struct Obj00681 *)p)->f6C);
    MSGDATA_Delete(((struct Obj00681 *)p)->f68);
    if(((struct Obj00681 *)p)->f5C) BMP_WIN_Delete(((struct Obj00681 *)p)->f5C);
    GF_FONT_Delete(((struct Obj00681 *)p)->f60);
    TCBL_Destroy(((struct Obj00681 *)p)->f58);
    GF_FONT_SetDefaultTextColor();
}

void LOCAL_TVT_SYS_UpdateText(u8 *p)
{
    TCBL_Main(((struct Obj00152 *)p)->f58);
    if(((struct Obj00152 *)p)->f64) {
        APP_KEYCURSOR_Update(((struct Obj00152 *)p)->f7C,((struct Obj00152 *)p)->f64,((struct Obj00152 *)p)->f5C);
        if(PRINTSYS_PrintStreamGetState(((struct Obj00152 *)p)->f64)!=0) LOCAL_TVT_CHARA_SetState(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),0);
        else LOCAL_TVT_CHARA_SetState(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),1);
        if(func_02028484((struct Blk *)(p+128),((struct Obj00152 *)p)->f64)==1) {
            PRINTSYS_PrintStreamDelete(((struct Obj00152 *)p)->f64);
            ((struct Obj00152 *)p)->f64=0;
            STRBUF_Delete(((struct Obj00152 *)p)->f70);
            ((struct Obj00152 *)p)->f70=0;
        }
    }
    PRINTSYS_QUE_Main(((struct Obj00152 *)p)->f78);
}

int LOCAL_TVT_SYS_IsPrintIdle(char *p)
{
    return ((struct Obj24201 *)p)->f64 == 0;
}

/*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 */
void LOCAL_TVT_SYS_CreateTextWindow(u8 *p,int mode)
{
 void *tmp;
 if(((struct Obj02507 *)p)->f5C){
 BMP_MENUWORK_DrawWindowBorder(((struct Obj02507 *)p)->f5C,1);
 tmp=((struct Obj02507 *)p)->f5C;BMP_WIN_ClearScreen(tmp);func_02041B6C(BMP_WIN_GetBgLayer(tmp));
 BMP_WIN_Delete(((struct Obj02507 *)p)->f5C);((struct Obj02507 *)p)->f5C=0;
 }
 if(mode==0) ((struct Obj02507 *)p)->f5C=(void *)BMP_WIN_Create(0,1,1,30,4,12,1);
 else if(mode==1) ((struct Obj02507 *)p)->f5C=(void *)BMP_WIN_Create(0,1,19,30,4,12,1);
 BMP_MENUWORK_DrawWindow(((struct Obj02507 *)p)->f5C,1,1,13);
 BMP_Clear(BMP_WIN_GetBmp(((struct Obj02507 *)p)->f5C),15);
 BMP_WIN_TransferChars(((struct Obj02507 *)p)->f5C);BMP_WIN_MakeScreen(((struct Obj02507 *)p)->f5C);
 func_02041B6C(0);func_02028470(p+128,6);
}

void LOCAL_TVT_SYS_DeleteTextWindow(u8 *p)
{
 void *tmp; u8 i;
 if(((struct Obj02218 *)p)->f5C){
 BMP_MENUWORK_DrawWindowBorder(((struct Obj02218 *)p)->f5C,1);tmp=((struct Obj02218 *)p)->f5C;
 BMP_WIN_ClearScreen(tmp);func_02041B6C(BMP_WIN_GetBgLayer(tmp));
 BMP_WIN_Delete(((struct Obj02218 *)p)->f5C);((struct Obj02218 *)p)->f5C=0;
 }
 if(((struct Obj02218 *)p)->f64){PRINTSYS_PrintStreamDelete(((struct Obj02218 *)p)->f64);((struct Obj02218 *)p)->f64=0;}
 if(((struct Obj02218 *)p)->f70){STRBUF_Delete(((struct Obj02218 *)p)->f70);((struct Obj02218 *)p)->f70=0;}
 for(i=0;i<((struct Obj02218 *)p)->f8;i++) if(*(int **)(p+28+i*4)) LOCAL_TVT_CHARA_ShowWindow((int)p,*(int **)(p+28+i*4));
}

/*
 * extent: 0x021B6A8E..0x021B6A90 is two zero alignment bytes.
 */
void LOCAL_TVT_SYS_PrintMessage(u8 *p, int message)
{
 void *tmp; unsigned speed;
 if(((struct Obj00919 *)p)->f64){PRINTSYS_PrintStreamDelete(((struct Obj00919 *)p)->f64);((struct Obj00919 *)p)->f64=0;}
 if(((struct Obj00919 *)p)->f70){STRBUF_Delete(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=0;}
 BMP_Clear(BMP_WIN_GetBmp(((struct Obj00919 *)p)->f5C),15);
 ((struct Obj00919 *)p)->f70=func_02045EC0(((struct Obj00919 *)p)->f6C,message);
 if(((struct Obj00919 *)p)->f74){
 tmp=STRBUF_Create(1024,((struct Obj00919 *)p)->f0);
 WORDSET_CopyTaggedText(((struct Obj00919 *)p)->f74,tmp,((struct Obj00919 *)p)->f70);
 STRBUF_Delete(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=tmp;
 }
 speed=MSG_SPEED_GetWait();
 *(unsigned *)&((struct Obj00919 *)p)->f64=PRINTSYS_PrintStream(*(unsigned *)&((struct Obj00919 *)p)->f5C,0,0,*(unsigned *)&((struct Obj00919 *)p)->f70,((struct Obj00919 *)p)->f60,speed,((struct Obj00919 *)p)->f58,2,((struct Obj00919 *)p)->f0,15);
}

void LOCAL_TVT_SYS_RunStep(Obj *o)
{
    unsigned int cur = o->steps[o->stepIdx * 4];

    if (o->pending == 1) {
        o->pending = 0;
        g_021B7398[cur].init(o);
    }
    if (g_021B7398[cur].update(o) == 1) {
        unsigned int next;
        o->stepIdx++;
        next = o->steps[o->stepIdx * 4];
        if (next != 0) {
            g_021B7398[next].init(o);
            return;
        }
        o->state = 2;
    }
}

/*
 * lever: Write the table element access twice (tbl[idx].b and tbl[idx].c) with no element pointer local; the index shift then schedules before the table load.
 */
void LOCAL_TVT_SYS_ApplyStep(u8 *p)
{
    u32 a = ((struct P *)p)->tbl[((struct P *)p)->idx].b;
    u32 b = (u8)((struct P *)p)->tbl[((struct P *)p)->idx].c;
    p[0x88] = a;
    LOCAL_TVT_SYS_PositionActor(p, a);
    if (a < 2) {
        LOCAL_TVT_SYS_CreateTextWindow(p, 1);
    } else {
        LOCAL_TVT_SYS_CreateTextWindow(p, 0);
    }
    if (*(void **)(p + 0x74) != 0) {
        WORDSET_DeleteStrbufED04(*(void **)(p + 0x74));
    }
    *(void **)(p + 0x74) = GF_FONT_Create_EC64(*(u16 *)p);
    WORDSET_SetSlotMyStatus(*(void **)(p + 0x74), 0, func_02012944(*(void **)(*(u8 **)(p + 0x30) + 4)));
    LOCAL_TVT_SYS_PrintMessage(p, b);
}

int LOCAL_TVT_SYS_OnSelect(char *p)
{
    if(LOCAL_TVT_SYS_IsPrintIdle(p)==1) {
        LOCAL_TVT_SYS_HideActor(p);
        LOCAL_TVT_SYS_DeleteTextWindow((u8 *)p);
        LOCAL_TVT_CHARA_ClearState(*(char **)(p+0x1c+((struct Obj24202 *)p)->f88*4));
        return 1;
    }
    return 0;
}

void LOCAL_TVT_SYS_ResetTimer(char *p)
{
    ((struct Obj24203 *)p)->f8A=0;
}

int LOCAL_TVT_SYS_TickTimer(char *p)
{
    u8 threshold=*(u16 *)(*(char * *)&((struct Obj08268 *)p)->f40+((struct Obj08268 *)p)->f89*4+2);
    ++*(u16 *)&((struct Obj08268 *)p)->f8A;
    if(*(u16 *)&((struct Obj08268 *)p)->f8A>threshold) return 1;
    return 0;
}

int LOCAL_TVT_SYS_ProcInit(void *ctx,int unused,char *arg)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,0x55,0x40000);
    p=PROCSYS_AllocProcWork(ctx,0x8c,0x55);
    if(arg==0) {
        arg=func_02030734(0x55,8,0,d_021B74AC,0x3b8);
        ((struct Obj10673 *)arg)->f4=GAME_DATA_Create(1);
        ((struct Obj10673 *)arg)->f0=1;
        if(KEY_GetCont() & 0x100) ((struct Obj10673 *)arg)->f0=5;
    }
    ((struct Obj01167 *)p)->f0=0x55;
    *(char * *)&((struct Obj01167 *)p)->f30=arg;
    LOCAL_TVT_SYS_Create((u8 *)p);
    return 1;
}

int LOCAL_TVT_SYS_ProcExit(struct S020315D4 *a,unsigned unused,int own,unsigned char *p) {LOCAL_TVT_SYS_Delete(p);if(own==0){GAME_DATA_Delete(*(unsigned char * *)&((struct Obj24204 *)(*(char * *)&((struct Obj00681 *)p)->f30))->f4);func_020307B0(((struct Obj00681 *)p)->f30);}func_020315D4(a);GFL_HEAP_DeleteChecked(85);return 1;}

int LOCAL_TVT_SYS_ProcMain(int a, int b, int c, int d)
{
    return LOCAL_TVT_SYS_Main((u8 *)d) == 1;
}
