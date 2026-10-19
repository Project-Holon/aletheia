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
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   TIMEZONE_GetLight 0x02011400 thumb
 *   GF_STANDARD_GetCachedTime 0x0203F4CC arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   d_021B7450 0x021B7450 data a4
 *   d_021B7388 0x021B7388 data a4
 *   d_021B73D0 0x021B73D0 data a4
 *   d_021B73B0 0x021B73B0 data a4
 *   d_021B7410 0x021B7410 data a4
 *   d_021B7430 0x021B7430 data a4
 *   d_021B73F0 0x021B73F0 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   TCBL_Create  0x0203101C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_CTRL_Init 0x02028470 thumb
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   g_021B7398  0x021B7398  data  a4
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   d_021B74AC 0x021B74AC data
 *   GAME_DATA_Delete 0x02012704 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
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

struct Blk;

struct Ctx;

struct Proc;

struct RtcTime{unsigned hour,minute,second;};


typedef enum { SZ0=0,SZ1=1,SZ2=2,SZ3=3 } GXBGScrSize256x16Pltt;

typedef enum { OVER0=0,OVER1=1 } GXBGAreaOver;

typedef enum { SB0=0,SB31=31 } GXBGScrBase;

typedef enum { CB0=0,CB15=15 } GXBGCharBase;

typedef struct { unsigned int words[7]; } ClactInitConfig;

typedef struct { u16 x,y,z; u8 kind,variant; } ActorSpec;

typedef struct StepHandler {
    void (*init)(struct LocalTvtSys *);
    int (*update)(struct LocalTvtSys *);
} StepHandler;

extern void *ARC_TOOL_CreateHandle(unsigned int archiveID, unsigned short heapID);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);
struct GameData;

extern u8 GAME_DATA_GetSeason(struct GameData *gd);

extern u8 TIMEZONE_GetLight(int row, int col);

extern void GF_STANDARD_GetCachedTime(struct RtcTime *),GFL_NET_RefreshWmIconAtTopRight(unsigned,unsigned);
struct TcbTask;

extern void TCB_DeleteTask(struct TcbTask *task);
struct Actor;

extern void CLACT_DeleteActor(struct Actor *actor);

extern void CLACT_ReleasePalette(unsigned int i);

extern void CLACT_ReleaseCharacter(unsigned int i);

extern void CLACT_ReleaseCellAnim(unsigned int i);

extern unsigned int CLACT_DeleteUnit(struct Bank *bank);

extern void ARC_TOOL_DeleteHandle(void *);

extern unsigned int GFL_HEAP_Free(void *p);

extern void WIPE_SYS_Start(void *divisionMode, unsigned int mainPattern, unsigned int subPattern, unsigned short color, unsigned int frames, unsigned int wait, unsigned int heapId);

extern unsigned WIPE_SYS_EndCheck(void);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

extern unsigned int GFL_USE_GetRandomBelow(unsigned int range);

extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);

extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);

extern void WIPE_SetBrightnessFadeOut(unsigned int a, unsigned int color);

extern void WIPE_ResetWndMask(void *win);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void MIi_CpuClear32(int,int,unsigned int);
struct DispVramCfg;
struct SysInit;

extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, unsigned int heapId);

extern void BG_SYS_SetMainPlaneVisible(unsigned int mask, unsigned int enable);

extern void BG_SYS_SetSubPlaneVisible(unsigned int mask, unsigned int enable);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

extern void CLACT_ExitSystem(void),BG_SYS_FreeLayerBuf(unsigned),BMP_WIN_Exit(void),BG_SYS_Delete(void);

extern void BG_SYS_InitBgLayer(unsigned,const struct BgTemplate *,unsigned);

extern void BG_SYS_SetPlaneVisible(unsigned,unsigned),BG_SYS_FreeSlot(unsigned),BG_SYS_PushTile(unsigned);

extern void *ARC_UTIL_LoadHandleMember(void *narc, unsigned int fileID, unsigned int decompress, unsigned short heapID);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,u16);
struct MyStatus;

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);

extern int CLACT_RegisterPaletteCompressed(void *,unsigned int,unsigned int,unsigned int,u16);

extern int CLACT_RegisterCharacter(void *,unsigned int,unsigned int,unsigned int,u16);

extern s32 CLACT_RegisterCellAnim(void *owner, unsigned int first, unsigned int second, unsigned int mode);

extern u8 MYSTATUS_GetSex(struct MyStatus *mystatus);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,unsigned int,unsigned int,unsigned int,unsigned int,u16);

extern unsigned int ARC_UTIL_UploadBgCharFromHandle(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int value);

extern void CLACT_SetActorAutoAnim(struct Actor *actor, unsigned int enable);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, unsigned int heapId);

extern struct MsgBank *MSGDATA_CreateFromArchive(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);

extern void BMP_MENUWORK_LoadCharAndPltt(unsigned int a, unsigned int b, unsigned int c, unsigned int d, u16 e);

extern u8 BMP_MENUWORK_GetPlttFileId(int i);

extern void ARC_UTIL_UploadPaletteFromArchive(unsigned int archiveID, unsigned int memberIdx, unsigned int kind, unsigned int offset, unsigned int dest, unsigned int size, u16 flags);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, u16 f);

extern void GF_FONT_SetDefaultTextColor(void);
struct TcblSystem;

extern struct TcblSystem *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
struct PrintQueue;

extern struct PrintQueue *PRINTSYS_QUE_Create(unsigned int heap);
struct KeyCursor;

extern struct KeyCursor *APP_KEYCURSOR_CreateDefault(unsigned int id, unsigned int isLive, unsigned int isFlip, unsigned short heapId);

extern void GF_FONT_SetTextColor(unsigned int r, unsigned int g, unsigned int b);

extern void APP_KEYCURSOR_Delete(struct KeyCursor *cursor);

extern void PRINTSYS_QUE_Delete(struct PrintQueue *queue);
struct TextPrinter;

extern void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer);
struct Strbuf;

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern unsigned int WORDSET_Delete(struct WordSet *p);

extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
struct BmpWin;

extern unsigned int BMP_WIN_Delete(struct BmpWin *win);

extern unsigned int GF_FONT_Delete(struct GfFont *font);

extern void TCBL_Destroy(struct TcblSystem *tcbl);

extern void TCBL_Main(struct TcblSystem *tcbl);

extern void APP_KEYCURSOR_Update(struct KeyCursor *cursor, struct TextPrinter *printStream, void *win);

extern unsigned PRINTSYS_PrintStreamGetState(struct TextPrinter *printer);
struct PrintStreamCtrl;

extern s32 PRINTSYS_CTRL_Update(struct PrintStreamCtrl *ctrl, struct TextPrinter *stream);

extern unsigned int PRINTSYS_QUE_Main(struct PrintQueue *queue);

extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, unsigned int commitMode);

extern void BMP_WIN_ClearScreen(struct BmpWin *win);

extern void BG_SYS_MarkTileDirty(unsigned);

extern void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int commitMode, unsigned short tileBase, unsigned int palette);
struct Bmp;

extern void BMP_Clear(struct Bmp *bmp, unsigned char value);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern void PRINTSYS_CTRL_Init(struct PrintStreamCtrl *ctrl, unsigned int inputType);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern struct BmpWin *BMP_WIN_Create(unsigned int bgLayer, unsigned int posX, unsigned int posY, unsigned char width, unsigned char height, unsigned char palette, unsigned char allocDir);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);

extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, unsigned int index);

extern struct Strbuf *STRBUF_Create(unsigned int capacity, unsigned int heapId);

extern signed char MSG_SPEED_GetWait(void);

extern unsigned PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);

extern struct WordSet *WORDSET_CreateDefault(unsigned short heapId);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);

extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GameData *GAME_DATA_Create(u16);

extern unsigned int KEY_GetCont(void);

extern void LOCAL_TVT_SYS_Delete(unsigned char *),GAME_DATA_Delete(unsigned char *),PROCSYS_FreeProcWork(struct Proc *),GFL_HEAP_DeleteChecked(unsigned int);

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

void LOCAL_TVT_SYS_RunStep(struct LocalTvtSys *o);

void LOCAL_TVT_SYS_ApplyStep(u8 *p);

int LOCAL_TVT_SYS_OnSelect(char *p);

void LOCAL_TVT_SYS_ResetTimer(char *p);

int LOCAL_TVT_SYS_TickTimer(char *p);

int LOCAL_TVT_SYS_ProcInit(void *ctx,int unused,char *arg);

int LOCAL_TVT_SYS_ProcExit(struct Proc *a,unsigned unused,int own,unsigned char *p);

int LOCAL_TVT_SYS_ProcMain(int a, int b, int c, int d);

char *LOCAL_TVT_CHARA_Create(char *p,int index);

void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p);

void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q);

void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2);

int LOCAL_TVT_CHARA_IsDone(u8 *unused, char *p);

void LOCAL_TVT_CHARA_ShowWindow(int a, int *p);

unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p);

void LOCAL_TVT_CHARA_SetState(char *p, int v);

void LOCAL_TVT_CHARA_ClearState(char *p);

extern const unsigned int d_021B7450[],d_021B7388[],d_021B73D0[],d_021B73B0[],d_021B7410[],d_021B7430[],d_021B73F0[];

extern const ClactInitConfig gClActorInitParam;

extern const LocalTvtTilePos d_021B7380[];

extern const StepHandler g_021B7398[];

extern char d_021B74AC[];

void LOCAL_TVT_SYS_Create(u8 *p)
{
 struct RtcTime time; unsigned season,earlyHour,midHour,lateHour; u8 i; void *task; unsigned one;
 LOCAL_TVT_SYS_SetupDisplay(p);
 ((struct LocalTvtSys *)p)->arcHandle=ARC_TOOL_CreateHandle(131,((struct LocalTvtSys *)p)->heapId);
 LOCAL_TVT_SYS_LoadMenuData((char *)p);LOCAL_TVT_SYS_CreateGraphics(p);LOCAL_TVT_SYS_CreateTextResources(p);
 season=GAME_DATA_GetSeason(((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->gameData);
 earlyHour=TIMEZONE_GetLight(season,0);midHour=TIMEZONE_GetLight(season,2);lateHour=TIMEZONE_GetLight(season,3);
 GF_STANDARD_GetCachedTime(&time);
 if(time.hour>=earlyHour && time.hour<midHour) ((struct LocalTvtSys *)p)->timeSlot=0;
 else if(time.hour>=midHour && time.hour<lateHour) ((struct LocalTvtSys *)p)->timeSlot=1;
 else ((struct LocalTvtSys *)p)->timeSlot=2;
 for(i=0;i<((struct LocalTvtSys *)p)->charaCount;i++) ((struct LocalTvtSys *)p)->chara[i]=LOCAL_TVT_CHARA_Create((char *)p,i);
 task=GFL_USE_AddMainTask((unsigned)LOCAL_TVT_SYS_VBlankHandler,(unsigned)p,8);
 one=1;((struct LocalTvtSys *)p)->highBase=one;((struct LocalTvtSys *)p)->pending=one;
 ((struct LocalTvtSys *)p)->vblankTask=task;((struct LocalTvtSys *)p)->stepIndex=0;
 ((struct LocalTvtSys *)p)->frameTimer=0;((struct LocalTvtSys *)p)->charaCursor=0;((struct LocalTvtSys *)p)->activeChara.asInt=0;((struct LocalTvtSys *)p)->state=0;
 GFL_NET_RefreshWmIconAtTopRight(0,((struct LocalTvtSys *)p)->heapId);
}

void LOCAL_TVT_SYS_Delete(u8 *p)
{
    u8 i;
    TCB_DeleteTask(((struct LocalTvtSys *)p)->vblankTask);
    LOCAL_TVT_SYS_DeleteTextResources(p);
    for(i=0;i<((struct LocalTvtSys *)p)->charaCount;i++) if(((struct LocalTvtSys *)p)->chara[i]) LOCAL_TVT_CHARA_Delete(p,((struct LocalTvtSys *)p)->chara[i]);
    CLACT_DeleteActor(((struct LocalTvtSys *)p)->actor);
    CLACT_ReleasePalette((unsigned int)(((struct LocalTvtSys *)p)->palette.ptr));
    CLACT_ReleaseCharacter((unsigned int)(((struct LocalTvtSys *)p)->character.ptr));
    CLACT_ReleaseCellAnim((unsigned int)(((struct LocalTvtSys *)p)->cellAnim.ptr));
    CLACT_DeleteUnit(((struct LocalTvtSys *)p)->unit.ptr);
    ARC_TOOL_DeleteHandle(((struct LocalTvtSys *)p)->arcHandle);
    LOCAL_TVT_SYS_ExitSystem(p);
    GFL_HEAP_Free(((struct LocalTvtSys *)p)->menuHandle);
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
    GXBGCharBase charBase2,charBase3;
    unsigned state;
    u8 i;
    switch(((struct LocalTvtSys *)p)->state) {
    case 0:
        WIPE_SYS_Start(0,1,1,0,6,1,((struct LocalTvtSys *)p)->heapId);
        ((struct LocalTvtSys *)p)->state=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) ((struct LocalTvtSys *)p)->state=4;
        break;
    case 2:
        WIPE_SYS_Start(0,0,0,0,6,1,((struct LocalTvtSys *)p)->heapId);
        ((struct LocalTvtSys *)p)->state=3;
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        LOCAL_TVT_SYS_RunStep((struct LocalTvtSys *)p);
        break;
    }
    if(((struct LocalTvtSys *)p)->frameTimer<20) ((struct LocalTvtSys *)p)->frameTimer++;
    if(((struct LocalTvtSys *)p)->activeChara.asInt==0 && ((struct LocalTvtSys *)p)->charaCursor==4) {
        if(((struct LocalTvtSys *)p)->highBase==0) {charBase2=4;charBase3=10;} else {charBase2=7;charBase3=13;}
        G2_SetBG2Control256x16Affine(SZ1,OVER1,(GXBGScrBase)13,charBase2);
        G2_SetBG3Control256x16Affine(SZ1,OVER1,(GXBGScrBase)14,charBase3);
        ((struct LocalTvtSys *)p)->highBase=((struct LocalTvtSys *)p)->highBase==0?1:0;
        ((struct LocalTvtSys *)p)->charaCursor=0;
        ((struct LocalTvtSys *)p)->frameTimer=0;
    }
    if(((struct LocalTvtSys *)p)->activeChara.ptr!=0 && LOCAL_TVT_CHARA_IsDone(p,((struct LocalTvtSys *)p)->activeChara.ptr)==1)
        ((struct LocalTvtSys *)p)->activeChara.ptr=0;
    if(((struct LocalTvtSys *)p)->activeChara.asInt==0) {
        state=((struct LocalTvtSys *)p)->charaCursor;
        switch(state) {
        case 0: case 1: case 2: case 3: {
            if(((void **)&((struct LocalTvtSys *)p)->chara[0])[(u8)state]!=0) {
                LOCAL_TVT_CHARA_SetActive(p,((void **)&((struct LocalTvtSys *)p)->chara[0])[(u8)state],((struct LocalTvtSys *)p)->highBase);
                ((struct LocalTvtSys *)p)->activeChara.ptr=((void **)&((struct LocalTvtSys *)p)->chara[0])[(u8)state];
                if(((struct LocalTvtSys *)p)->charaCount==2 && ((struct LocalTvtSys *)p)->charaCursor==1) ((struct LocalTvtSys *)p)->charaCursor=4;
                else (((struct LocalTvtSys *)p)->charaCursor)++;
            } else ((struct LocalTvtSys *)p)->charaCursor=state+1;
            break;
        }
        }
    }
    for(i=0;i<((struct LocalTvtSys *)p)->charaCount;i++) {
        if(((struct LocalTvtSys *)p)->chara[i]!=0) LOCAL_TVT_CHARA_Update(p,((struct LocalTvtSys *)p)->chara[i]);
    }
    LOCAL_TVT_SYS_UpdateText(p);
    CLACT_DrawSystem();
    return 0;
}

void LOCAL_TVT_SYS_VBlankHandler(void) {CLACT_VBlankSystem();BG_SYS_ChangeScrollImmediate(1,0,GFL_USE_GetRandomBelow(256));BG_SYS_ChangeScrollImmediate(1,3,GFL_USE_GetRandomBelow(256));}

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
    ClactInitConfig c;
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile unsigned int *)0x04000000 &= ~0x1F00;
    *(volatile unsigned int *)0x04001000 &= ~0x1F00;
    WIPE_SetBrightnessFadeOut(0,0);
    WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u16 *)0x04000304 |=0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B7450);
    BG_SYS_Create(((struct LocalTvtSys *)p)->heapId);
    BMP_WIN_Init(((struct LocalTvtSys *)p)->heapId);
    BG_SYS_SetGraphicsMode((void *)d_021B7388);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73D0,0,0);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73B0,1,0);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B7410,2,2);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B7430,3,2);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73F0,7,0);
    MIi_CpuClear32(0,0x06000000,0x40000);
    c=gClActorInitParam;
    CLACT_InitSystem((struct SysInit *)(&c),(struct DispVramCfg *)d_021B7450,((struct LocalTvtSys *)p)->heapId);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    ((struct LocalTvtSys *)p)->unit.ptr=CLACT_CreateUnit(16,0,((struct LocalTvtSys *)p)->heapId);
    CLACT_SetUnitDefaultRenderer(((struct LocalTvtSys *)p)->unit.ptr);
    G2x_SetBlendAlpha_((void *)0x04000050,1,30,16,4);
}

void LOCAL_TVT_SYS_ExitSystem(unsigned char *p) {CLACT_ExitSystem();BG_SYS_FreeLayerBuf(7);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(0);BMP_WIN_Exit();BG_SYS_Delete();}

void LOCAL_TVT_SYS_SetupBgLayer(const struct BgTemplate *p, int i, int type) {BG_SYS_InitBgLayer(i,p,type);BG_SYS_SetPlaneVisible(i,1);BG_SYS_FreeSlot(i);BG_SYS_PushTile(i);}

void LOCAL_TVT_SYS_LoadMenuData(char *p) {unsigned char *q=ARC_UTIL_LoadHandleMember(((struct LocalTvtSys *)p)->arcHandle,((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->mode+62,0,((struct LocalTvtSys *)p)->heapId);((struct LocalTvtSys *)p)->menuHandle=q;((struct LocalTvtSys *)p)->menuCharaTable=q;((struct LocalTvtSys *)p)->stepTable.bytes=q+8;if(q[2]==255 && q[3]==255) ((struct LocalTvtSys *)p)->charaCount=2;else ((struct LocalTvtSys *)p)->charaCount=4;}

void LOCAL_TVT_SYS_CreateGraphics(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    ActorSpec spec;
    if(((struct LocalTvtSys *)p)->charaCount!=2) id=38;
    ARC_UTIL_UploadBgPaletteFromHandle(((struct LocalTvtSys *)p)->arcHandle,id,2,0,0,0,((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(((struct LocalTvtSys *)p)->arcHandle,id,3,0,0,0,((struct LocalTvtSys *)p)->heapId);
    save=GAME_DATA_GetMyStatus(((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->gameData);
    arc=ARC_TOOL_CreateHandle(172,((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtSys *)p)->palette.value=CLACT_RegisterPaletteCompressed(arc,3,0,0,((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtSys *)p)->character.value=CLACT_RegisterCharacter(arc,24,0,0,((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtSys *)p)->cellAnim.value=CLACT_RegisterCellAnim(arc,20,22,((struct LocalTvtSys *)p)->heapId);
    if(MYSTATUS_GetSex(save)==0) ARC_UTIL_UploadPaletteFromHandleWhole(arc,7,4,0,0x60,((struct LocalTvtSys *)p)->heapId);
    else ARC_UTIL_UploadPaletteFromHandleWhole(arc,6,4,0,0x60,((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc,11,7,0,0,0,((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,14,7,0,0,0,((struct LocalTvtSys *)p)->heapId);
    BG_SYS_PushTile(7);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,0,0,0x160,0x20,((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc,8,1,0,0,0,((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,13,1,0,0,0,((struct LocalTvtSys *)p)->heapId);
    BG_SYS_FillTileMap(1,0,0,32,32,11);
    BG_SYS_PushTile(1);
    ARC_TOOL_DeleteHandle(arc);
    spec.kind=10; spec.variant=1; spec.x=0;spec.y=0;spec.z=0;
    ((struct LocalTvtSys *)p)->actor=CLACT_CreateActor(((struct LocalTvtSys *)p)->unit.ptr,((struct LocalTvtSys *)p)->character.value,((struct LocalTvtSys *)p)->palette.value,((struct LocalTvtSys *)p)->cellAnim.value,&spec,0,((struct LocalTvtSys *)p)->heapId);
    CLACT_SetActorDrawEnable(((struct LocalTvtSys *)p)->actor,0);
    CLACT_SetActorAutoAnim(((struct LocalTvtSys *)p)->actor,1);
}

void LOCAL_TVT_SYS_PositionActor(u8 *p, int index)
{
    u16 point[2];
    unsigned width;
    unsigned x;
    unsigned y;
    width = LOCAL_TVT_CHARA_GetState(((struct LocalTvtSys *)p)->chara[index]);
    width = width / 2;
    x = ((d_021B7380[index].x * 8) + 80) + width;
    point[0] = x;
    y = (d_021B7380[index].y * 8) + 16;
    point[1] = y;
    CLACT_AddActorSurfacePos(((struct LocalTvtSys *)p)->actor, (const struct Vec2 *)point, 0);
    CLACT_SetActorDrawEnable(((struct LocalTvtSys *)p)->actor, 1);
    CLACT_RestartActorAnim(((struct LocalTvtSys *)p)->actor);
}

void LOCAL_TVT_SYS_HideActor(char *p) {CLACT_SetActorDrawEnable(((struct LocalTvtSys *)p)->actor,0);}

void LOCAL_TVT_SYS_CreateTextResources(u8 *p)
{
    ((struct LocalTvtSys *)p)->font.ptr = GF_FONT_Create(0x17, 0, 0, 0, ((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtSys *)p)->msgBankA.ptr = MSGDATA_CreateFromArchive(0, 2, 0xc6, ((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtSys *)p)->msgBankB.ptr = MSGDATA_CreateFromArchive(0, 2, (u16)(((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->mode + 0xbf), ((struct LocalTvtSys *)p)->heapId);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xd, 0, ((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0x20, 0x1a0, 0x20, ((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 7, 0, 0x180, 0x20, ((struct LocalTvtSys *)p)->heapId);
    GF_FONT_SetDefaultTextColor();
    ((struct LocalTvtSys *)p)->textCtl.ptr = TCBL_Create(((struct LocalTvtSys *)p)->heapId, ((struct LocalTvtSys *)p)->heapId, 3, 0x100);
    ((struct LocalTvtSys *)p)->printStream.value = 0;
    ((struct LocalTvtSys *)p)->window.value = 0;
    ((struct LocalTvtSys *)p)->textBuf.value = 0;
    ((struct LocalTvtSys *)p)->wordSet.value = 0;
    ((struct LocalTvtSys *)p)->printQueue.value = (unsigned int)PRINTSYS_QUE_Create((unsigned int)(((struct LocalTvtSys *)p)->heapId));
    ((struct LocalTvtSys *)p)->keyCursor.value = (unsigned int)APP_KEYCURSOR_CreateDefault((unsigned int)0xf, (unsigned int)1, (unsigned int)1, ((struct LocalTvtSys *)p)->heapId);
    GF_FONT_SetTextColor(1, 2, 0xf);
}

/*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 */
void LOCAL_TVT_SYS_DeleteTextResources(u8 *p)
{
    APP_KEYCURSOR_Delete((((struct LocalTvtSys *)p)->keyCursor.ptr));
    PRINTSYS_QUE_Delete(((struct LocalTvtSys *)p)->printQueue.ptr);
    if(((struct LocalTvtSys *)p)->printStream.ptr) PRINTSYS_PrintStreamDelete(((struct LocalTvtSys *)p)->printStream.ptr);
    if(((struct LocalTvtSys *)p)->textBuf.ptr) STRBUF_Delete(((struct LocalTvtSys *)p)->textBuf.ptr);
    if(((struct LocalTvtSys *)p)->wordSet.ptr) WORDSET_Delete(((struct LocalTvtSys *)p)->wordSet.ptr);
    MSGDATA_Delete(((struct LocalTvtSys *)p)->msgBankB.ptr);
    MSGDATA_Delete(((struct LocalTvtSys *)p)->msgBankA.ptr);
    if(((struct LocalTvtSys *)p)->window.ptr) BMP_WIN_Delete(((struct LocalTvtSys *)p)->window.ptr);
    GF_FONT_Delete(((struct LocalTvtSys *)p)->font.ptr);
    TCBL_Destroy(((struct LocalTvtSys *)p)->textCtl.ptr);
    GF_FONT_SetDefaultTextColor();
}

void LOCAL_TVT_SYS_UpdateText(u8 *p)
{
    TCBL_Main(((struct LocalTvtSys *)p)->textCtl.ptr);
    if(((struct LocalTvtSys *)p)->printStream.ptr) {
        APP_KEYCURSOR_Update(((struct LocalTvtSys *)p)->keyCursor.ptr,((struct LocalTvtSys *)p)->printStream.ptr,((struct LocalTvtSys *)p)->window.ptr);
        if(PRINTSYS_PrintStreamGetState(((struct LocalTvtSys *)p)->printStream.ptr)!=0) LOCAL_TVT_CHARA_SetState(((struct LocalTvtSys *)p)->chara[((struct LocalTvtSys *)p)->charaIndex],0);
        else LOCAL_TVT_CHARA_SetState(((struct LocalTvtSys *)p)->chara[((struct LocalTvtSys *)p)->charaIndex],1);
        if(PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)(((struct LocalTvtSys *)p)->printCtrl),((struct LocalTvtSys *)p)->printStream.ptr)==1) {
            PRINTSYS_PrintStreamDelete(((struct LocalTvtSys *)p)->printStream.ptr);
            ((struct LocalTvtSys *)p)->printStream.ptr=0;
            STRBUF_Delete(((struct LocalTvtSys *)p)->textBuf.ptr);
            ((struct LocalTvtSys *)p)->textBuf.ptr=0;
        }
    }
    PRINTSYS_QUE_Main(((struct LocalTvtSys *)p)->printQueue.ptr);
}

int LOCAL_TVT_SYS_IsPrintIdle(char *p)
{
    return ((struct LocalTvtSys *)p)->printStream.ptr == 0;
}

/*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 */
void LOCAL_TVT_SYS_CreateTextWindow(u8 *p,int mode)
{
 void *tmp;
 if(((struct LocalTvtSys *)p)->window.ptr){
 BMP_MENUWORK_DrawWindowBorder(((struct LocalTvtSys *)p)->window.ptr,1);
 tmp=((struct LocalTvtSys *)p)->window.ptr;BMP_WIN_ClearScreen(tmp);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(tmp));
 BMP_WIN_Delete(((struct LocalTvtSys *)p)->window.ptr);((struct LocalTvtSys *)p)->window.ptr=0;
 }
 if(mode==0) ((struct LocalTvtSys *)p)->window.ptr=(void *)BMP_WIN_Create(0,1,1,30,4,12,1);
 else if(mode==1) ((struct LocalTvtSys *)p)->window.ptr=(void *)BMP_WIN_Create(0,1,19,30,4,12,1);
 BMP_MENUWORK_DrawWindow(((struct LocalTvtSys *)p)->window.ptr,1,1,13);
 BMP_Clear(BMP_WIN_GetBmp(((struct LocalTvtSys *)p)->window.ptr),15);
 BMP_WIN_TransferChars(((struct LocalTvtSys *)p)->window.ptr);BMP_WIN_MakeScreen(((struct LocalTvtSys *)p)->window.ptr);
 BG_SYS_MarkTileDirty(0);PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)(((struct LocalTvtSys *)p)->printCtrl),6);
}

void LOCAL_TVT_SYS_DeleteTextWindow(u8 *p)
{
 void *tmp; u8 i;
 if(((struct LocalTvtSys *)p)->window.ptr){
 BMP_MENUWORK_DrawWindowBorder(((struct LocalTvtSys *)p)->window.ptr,1);tmp=((struct LocalTvtSys *)p)->window.ptr;
 BMP_WIN_ClearScreen(tmp);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(tmp));
 BMP_WIN_Delete(((struct LocalTvtSys *)p)->window.ptr);((struct LocalTvtSys *)p)->window.ptr=0;
 }
 if(((struct LocalTvtSys *)p)->printStream.ptr){PRINTSYS_PrintStreamDelete(((struct LocalTvtSys *)p)->printStream.ptr);((struct LocalTvtSys *)p)->printStream.ptr=0;}
 if(((struct LocalTvtSys *)p)->textBuf.ptr){STRBUF_Delete(((struct LocalTvtSys *)p)->textBuf.ptr);((struct LocalTvtSys *)p)->textBuf.ptr=0;}
 for(i=0;i<((struct LocalTvtSys *)p)->charaCount;i++) if(((struct LocalTvtSys *)p)->chara[i]) LOCAL_TVT_CHARA_ShowWindow((int)p,((struct LocalTvtSys *)p)->chara[i]);
}

/*
 * extent: 0x021B6A8E..0x021B6A90 is two zero alignment bytes.
 */
void LOCAL_TVT_SYS_PrintMessage(u8 *p, int message)
{
 void *tmp; unsigned speed;
 if(((struct LocalTvtSys *)p)->printStream.ptr){PRINTSYS_PrintStreamDelete(((struct LocalTvtSys *)p)->printStream.ptr);((struct LocalTvtSys *)p)->printStream.ptr=0;}
 if(((struct LocalTvtSys *)p)->textBuf.ptr){STRBUF_Delete(((struct LocalTvtSys *)p)->textBuf.ptr);((struct LocalTvtSys *)p)->textBuf.ptr=0;}
 BMP_Clear(BMP_WIN_GetBmp(((struct LocalTvtSys *)p)->window.ptr),15);
 ((struct LocalTvtSys *)p)->textBuf.ptr=MSGDATA_AllocString(((struct LocalTvtSys *)p)->msgBankB.ptr,message);
 if(((struct LocalTvtSys *)p)->wordSet.ptr){
 tmp=STRBUF_Create(1024,((struct LocalTvtSys *)p)->heapId);
 WORDSET_CopyTaggedText(((struct LocalTvtSys *)p)->wordSet.ptr,tmp,((struct LocalTvtSys *)p)->textBuf.ptr);
 STRBUF_Delete(((struct LocalTvtSys *)p)->textBuf.ptr);((struct LocalTvtSys *)p)->textBuf.ptr=tmp;
 }
 speed=MSG_SPEED_GetWait();
 ((struct LocalTvtSys *)p)->printStream.value=PRINTSYS_PrintStream((unsigned)((struct LocalTvtSys *)p)->window.ptr,0,0,(unsigned)((struct LocalTvtSys *)p)->textBuf.ptr,((struct LocalTvtSys *)p)->font.value,speed,((struct LocalTvtSys *)p)->textCtl.value,2,((struct LocalTvtSys *)p)->heapId,15);
}

void LOCAL_TVT_SYS_RunStep(struct LocalTvtSys *o)
{
    unsigned int cur = o->stepTable.bytes[o->stepIndex * 4];

    if (o->pending == 1) {
        o->pending = 0;
        g_021B7398[cur].init(o);
    }
    if (g_021B7398[cur].update(o) == 1) {
        unsigned int next;
        o->stepIndex++;
        next = o->stepTable.bytes[o->stepIndex * 4];
        if (next != 0) {
            g_021B7398[next].init(o);
            return;
        }
        o->state = 2;
    }
}

/*
 * lever: Write the table element access twice (stepTable.entries[stepIndex].charaIndex and .messageId) with no element pointer local; the index shift then schedules before the table load.
 */
void LOCAL_TVT_SYS_ApplyStep(u8 *p)
{
    u32 charaSel = ((struct LocalTvtSys *)p)->stepTable.entries[((struct LocalTvtSys *)p)->stepIndex].charaIndex;
    u32 messageId = (u8)((struct LocalTvtSys *)p)->stepTable.entries[((struct LocalTvtSys *)p)->stepIndex].messageId;
    ((struct LocalTvtSys *)p)->charaIndex = charaSel;
    LOCAL_TVT_SYS_PositionActor(p, charaSel);
    if (charaSel < 2) {
        LOCAL_TVT_SYS_CreateTextWindow(p, 1);
    } else {
        LOCAL_TVT_SYS_CreateTextWindow(p, 0);
    }
    if (((struct LocalTvtSys *)p)->wordSet.ptr != 0) {
        WORDSET_Delete(((struct LocalTvtSys *)p)->wordSet.ptr);
    }
    ((struct LocalTvtSys *)p)->wordSet.ptr = WORDSET_CreateDefault(((struct LocalTvtSys *)p)->heapId);
    WORDSET_SetSlotMyStatus(((struct LocalTvtSys *)p)->wordSet.ptr, 0, GAME_DATA_GetMyStatus(((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->gameData));
    LOCAL_TVT_SYS_PrintMessage(p, messageId);
}

int LOCAL_TVT_SYS_OnSelect(char *p)
{
    if(LOCAL_TVT_SYS_IsPrintIdle(p)==1) {
        LOCAL_TVT_SYS_HideActor(p);
        LOCAL_TVT_SYS_DeleteTextWindow((u8 *)p);
        LOCAL_TVT_CHARA_ClearState(((struct LocalTvtSys *)p)->chara[((struct LocalTvtSys *)p)->charaIndex]);
        return 1;
    }
    return 0;
}

void LOCAL_TVT_SYS_ResetTimer(char *p)
{
    ((struct LocalTvtSys *)p)->timer=0;
}

int LOCAL_TVT_SYS_TickTimer(char *p)
{
    u8 threshold=((struct LocalTvtSys *)p)->stepTable.entries[((struct LocalTvtSys *)p)->stepIndex].messageId;
    ++((struct LocalTvtSys *)p)->timer;
    if(((struct LocalTvtSys *)p)->timer>threshold) return 1;
    return 0;
}

int LOCAL_TVT_SYS_ProcInit(void *ctx,int unused,char *arg)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,0x55,0x40000);
    p=PROCSYS_AllocProcWork(ctx,0x8c,0x55);
    if(arg==0) {
        arg=GFL_HEAP_Alloc(0x55,8,0,d_021B74AC,0x3b8);
        ((struct LocalTvtSysMode *)arg)->gameData=GAME_DATA_Create(1);
        ((struct LocalTvtSysMode *)arg)->mode=1;
        if(KEY_GetCont() & 0x100) ((struct LocalTvtSysMode *)arg)->mode=5;
    }
    ((struct LocalTvtSys *)p)->heapId=0x55;
    ((struct LocalTvtSys *)p)->modeData=arg;
    LOCAL_TVT_SYS_Create((u8 *)p);
    return 1;
}

int LOCAL_TVT_SYS_ProcExit(struct Proc *a,unsigned unused,int own,unsigned char *p) {LOCAL_TVT_SYS_Delete(p);if(own==0){GAME_DATA_Delete((unsigned char *)((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->gameData);GFL_HEAP_Free(((struct LocalTvtSys *)p)->modeData);}PROCSYS_FreeProcWork(a);GFL_HEAP_DeleteChecked(85);return 1;}

int LOCAL_TVT_SYS_ProcMain(int a, int b, int c, int d)
{
    return LOCAL_TVT_SYS_Main((u8 *)d) == 1;
}
