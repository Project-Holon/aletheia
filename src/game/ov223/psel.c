/*
 * file:     psel.c
 * unit:     yes
 * function: PSEL_SetAnimFrame, PSEL_CreateRecords, PSEL_DeleteRecords, PSEL_Init, PSEL_Exit, PSEL_Main, PSEL_Task, PSEL_DrawObjects, PSEL_CreateG3dUtil, PSEL_DeleteG3dUtil, PSEL_SetupListAnime, PSEL_DeleteListAnime, PSEL_UpdateListAnime, PSEL_SetupSelectAnime, PSEL_DeleteSelectAnime, PSEL_UpdateSelectAnime, PSEL_SetAnimTarget, PSEL_IsAnimTargetReached, PSEL_StepAnim, PSEL_SetAnimTargetIndex, PSEL_StepAnimIndex, PSEL_SelectUnit, PSEL_UpdateUnitAnime, PSEL_CreateUnits, PSEL_DeleteUnits, PSEL_InterpolateCurve, PSEL_UpdateUnitPositions, PSEL_SetUnitVisible, PSEL_UpdateFadeUnit, PSEL_IsUnitAnimDone, PSEL_UpdateUnitAnime2, PSEL_CreateUnits2, PSEL_DeleteActors, PSEL_SetActorPosition, PSEL_UpdateActorPosition, PSEL_CreateBmpWindows, PSEL_NopBgWindows, PSEL_InitBgLayers, PSEL_ClearBgLayer2, PSEL_DeleteBgLayers, PSEL_NopBgDelete, PSEL_SetBgSys, PSEL_ClearBgLayerEx, PSEL_UploadBgPalette, PSEL_NopBgUpdate, PSEL_CreateWin, PSEL_DeleteWin, PSEL_UpdateTcbl, PSEL_UpdateWindows, PSEL_SetMode, PSEL_IsModeDone, PSEL_UpdateSubWindow, PSEL_PrintSubWindow, PSEL_ClearWin, PSEL_ClearWin2, PSEL_ClearWin3, PSEL_CreateTaskRes, PSEL_DeleteTaskResData, PSEL_ShowTaskRes, PSEL_DeleteTaskRes, PSEL_UpdateTaskResWin, PSEL_SetTaskResActive, PSEL_IsTaskResFinished
 * address:  0x021B95A0
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ICA_ANIME_SetFrame  0x020115EC  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   sPselSite 0x021BCB00 data a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   FADE_SetSpeed 0x0204E6F4 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   sPselCallbacks 0x021BC84C data a4
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PSEL_GRAPHIC_Draw 0x021BC4F4 thumb ov223
 *   PSEL_GRAPHIC_ApplyLight 0x021BC508 thumb ov223
 *   PSEL_GRAPHIC_DrawEnd 0x021BC514 thumb ov223
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_UTIL_GetUnitObjIdx 0x020489F4 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   PSEL_GRAPHIC_GetCamera 0x021BC52C thumb ov223
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 *   d_021BC7AC 0x021BC7AC data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   ICA_ANIME_IncFrameLoop 0x02011590 thumb
 *   sPselSetup 0x021BC7BC data a4
 *   sPselPositions 0x021BC7CC data a4
 *   sPselTable 0x021BC78C data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021BC790 0x021BC790 data a2
 *   d_021BC792 0x021BC792 data a2
 *   G3D_SYSTEM_DisableObjectAnime 0x020477D4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   sPselIds 0x021BC710 data a2
 *   sPselBanks 0x021BC6FC data a1
 *   sPselMotion 0x021BC7F0 data a1
 *   sPselFiles 0x021BC73C data a1
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PSEL_GRAPHIC_GetClactBank 0x021BC520 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _fmul 0x0209C77C arm
 *   _fdiv 0x0209CE10 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   d_021BC7F0 0x021BC7F0 data
 *   d_021BC8C0 0x021BC8C0 data ov223
 *   PSEL_GRAPHIC_SetRecordState 0x021BB974 thumb
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021BC716 0x021BC716 data a2
 *   sPselFile 0x021BCB00 data
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_FillRect 0x02043AF4 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   BMP_Delete 0x020437AC arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   sPselEntryTable 0x021BC770 data a1
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_CountLines 0x0201D42C thumb
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotSpeciesName 0x0201EE60 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   d_021BC730 0x021BC730 data a4
 *   d_021BC710 0x021BC710 data a2
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 */

#include "psel_types.h"
#include "../sdk_ioreg.h"

#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
struct Proc;
struct Proc;
struct PrintSys;
struct Arg;
struct G3dUtil;
struct G3dSys;
struct PselRecord;
struct Ctx;
struct IcaAnime;
struct G3dUtil;
struct G3dUtilSetup;
struct AnmCtl;
struct Owner;
struct ClactActor;
struct Pair;
struct Actor;
struct Node;
struct PtS;
struct Bmp;
struct Bmp;
struct MsgBank;
struct Tcbl;
struct Descriptor;
struct CharBuf;
struct Rec3;
struct U16Vec;
struct S02031140;
struct Cfg;
struct StrObj;
struct WordSet;
struct TaskMenuRes;
struct TaskMenuState;
typedef struct {int x,y,z;} PselVec;

struct PselRecord { u16 id,pad; PselVec translation,scale; u32 matrix[9],flag; };

struct TableRow { u16 h[5]; };

struct Request {u16 x,y,z;u8 a,b;};

struct PselDesc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};

typedef struct {u8 b[14];} Motion;

typedef struct {u8 b[5];} Files;

#include "../types.h"
#include "../version.h"

/* Position and width of the task result window; the German labels are wider. */
#if LANGUAGE == LANGUAGE_GERMAN
#define PSEL_TASKRES_WIN_X 5
#define PSEL_TASKRES_WIN_WIDTH 22
#else
#define PSEL_TASKRES_WIN_X 9
#define PSEL_TASKRES_WIN_WIDTH 14
#endif

typedef struct PselVec2 { s16 x, y; } PselVec2;

typedef struct FxPair { int x, y; } FxPair;

typedef struct BytePair {u8 x,y;} BytePair;

typedef struct {u8 a,b,c,d,e,f,g,h,i;} PselTableEntry;

struct PselItem { void *text; u16 color; unsigned value; };

#include "../arm9/ica_anime.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/fx_mtx33.h"
#include "../arm9/fade.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/ui.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/g3d_system.h"
#include "../arm9/g3d_util.h"
#include "psel_graphic.h"
#include "../arm9/bg_sys.h"
struct G3dUtil;
struct G3dObjectStatus;
struct G3dObject;
                               
extern void PSEL_DeleteRecords(void *),ICA_ANIME_Delete(struct IcaAnime *);
/* B908 reads only r0, forwarding its live r1 to D478; legacy r2/r3 unused. */
#include "../arm9/clact.h"
#include "../arm9/pokegra.h"
#include "../arm9/arc_tool.h"
struct Pair32;
#include "../arm9/g2.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/arc_util.h"
#include "../arm9/msgdata.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/gf_font.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct TextPrinter;
struct Strbuf;
#include "../arm9/strbuf.h"
struct GfFont;
struct GfFont;
#include "../arm9/msg_speed.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
#include "../arm9/wordset.h"
struct GFont;
#include "../arm9/app_taskmenu.h"
struct TaskMenuItem;
struct TaskMenuWin;
void PSEL_SetAnimFrame(struct IcaAnime *anime, int frame);
struct PselRecord *PSEL_CreateRecords(u32 heap,u32 count);
void PSEL_DeleteRecords(void *p);
int PSEL_Init(void *a,int unused,void *c);
int PSEL_Exit(void *a, int unused1, int unused2, u8 *ctx);
int PSEL_Main(void *a,int *state,void *b,char *p);
void PSEL_Task(void *unused,char *p);
void PSEL_DrawObjects(char *p);
void PSEL_CreateG3dUtil(char *p);
void PSEL_DeleteG3dUtil(int *p);
void PSEL_SetupListAnime(u8 *p);
void PSEL_DeleteListAnime(char *p);
void PSEL_UpdateListAnime(char *p);
void PSEL_SetupSelectAnime(char *p);
void PSEL_DeleteSelectAnime(char *p);
void PSEL_UpdateSelectAnime(char *p);
void PSEL_SetAnimTarget(char *p,int type,int flag);
int PSEL_IsAnimTargetReached(char *p);
void PSEL_StepAnim(char *p);
void PSEL_SetAnimTargetIndex(char *p,unsigned index);
void PSEL_StepAnimIndex(char *p);
void PSEL_SelectUnit(char *p,unsigned next);
void PSEL_UpdateUnitAnime(char *p);
void PSEL_CreateUnits(char *p);
void PSEL_DeleteUnits(char *p);
int PSEL_InterpolateCurve(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time);
void PSEL_UpdateUnitPositions(struct PselWork *p);
void PSEL_SetUnitVisible(char *p,unsigned selected);
void PSEL_UpdateFadeUnit(char *p);
int PSEL_IsUnitAnimDone(char *p);
void PSEL_UpdateUnitAnime2(char *p);
void PSEL_CreateUnits2(char *p);
void PSEL_DeleteActors(char *p);
void PSEL_SetActorPosition(char *p,int flag);
void PSEL_UpdateActorPosition(char *p);
void PSEL_CreateBmpWindows(u16 *p);
void PSEL_NopBgWindows(int *unused);
void PSEL_InitBgLayers(u16 *p);
void PSEL_ClearBgLayer2(unsigned char *work);
void PSEL_DeleteBgLayers(u16 *p);
void PSEL_NopBgDelete(unsigned char *work);
void PSEL_SetBgSys(const u16 *p);
void PSEL_ClearBgLayerEx(char *unused);
void PSEL_UploadBgPalette(u16 *p);
void PSEL_NopBgUpdate(char *unused);
void PSEL_CreateWin(char *p);
void PSEL_DeleteWin(char *p);
void PSEL_UpdateTcbl(int *p);
int PSEL_UpdateWindows(char *p);
void PSEL_SetMode(char *p, int idx);
int PSEL_IsModeDone(char *a);
void PSEL_UpdateSubWindow(char *p);
void PSEL_PrintSubWindow(char *p, int idx);
void PSEL_ClearWin(char *p);
void PSEL_ClearWin2(char *p);
void PSEL_ClearWin3(char *p);
void PSEL_CreateTaskRes(char *p);
void PSEL_DeleteTaskResData(int *p);
void PSEL_ShowTaskRes(char *p);
void PSEL_DeleteTaskRes(char *p);
void PSEL_UpdateTaskResWin(char *p);
void PSEL_SetTaskResActive(char *p);
u32 PSEL_IsTaskResFinished(char *p);
extern const char sPselSite[];
extern const u8 d_021BC7AC[];
extern const struct G3dUtilSetup sPselSetup;
extern const PselVec sPselPositions[];
extern u16 sPselTable[][5];
extern const struct TableRow d_021BC790[];
extern const u16 d_021BC792[];
extern const u16 sPselIds[];
extern const u8 sPselBanks[];
extern const Motion sPselMotion[];
extern const Files sPselFiles[];
extern const u8 d_021BC7F0[3][14];
extern const u8 d_021BC8C0[3];
extern const BytePair d_021BC716[];
extern const char sPselFile[];
extern const PselTableEntry sPselEntryTable[];
extern const u32 d_021BC730[];
extern const u16 d_021BC710[];

void PSEL_SetAnimFrame(struct IcaAnime *anime, int frame)
{
    ICA_ANIME_SetFrame(anime, frame / 2);
}

struct PselRecord *PSEL_CreateRecords(u32 heap,u32 count)
{
    struct PselRecord *p;
    u16 i;
    p=GFL_HEAP_Alloc(heap,count*sizeof(struct PselRecord),1,sPselSite,654);
    for(i=0;i<count;i++) {
        p[i].translation.x=0;
        p[i].translation.y=0;
        p[i].translation.z=0;
        p[i].scale.x=4096;
        p[i].scale.y=4096;
        p[i].scale.z=4096;
        MTX_Identity33_((MtxFx33 *)p[i].matrix);
    }
    return p;
}

void PSEL_DeleteRecords(void *p) { GFL_HEAP_Free(p); }

int PSEL_Init(void *a,int unused,void *c)
{
    char *p;
    FADE_Start(3,16,16,0);
    GFL_HEAP_CreateChildHeap(1,135,1<<20);
    p=PROCSYS_AllocProcWork(a,sizeof(struct PselWork),135);
    MI_CpuFill8(p,0,sizeof(struct PselWork));
    ((struct PselWork *)p)->heapId=135;
    ((struct PselWork *)p)->config=c;
    ((struct PselWork *)p)->savedFadeSpeed=FADE_GetSpeed();
    FADE_SetSpeed(1);
    ((struct PselWork *)p)->fadeSpeed=UI_GetInputMode();
    ((struct PselWork *)p)->menuSelected=4;
    ((struct PselWork *)p)->currentIndex=4;
    ((struct PselWork *)p)->voicePending=0;
    ((struct PselWork *)p)->subState=0;
    return 1;
}

int PSEL_Exit(void *a, int unused1, int unused2, u8 *ctx)
{
    u16 v;
    FADE_Start(0xC, 0x10, 0x10, 0);
    UI_SetInputMode(((struct PselWork *)ctx)->fadeSpeed);
    FADE_SetSpeed(((struct PselWork *)ctx)->savedFadeSpeed);
    switch (((struct PselWork *)ctx)->menuSelected) {
    case 0:
        **(u16 **)((struct PselWork *)ctx)->config = 0;
        break;
    case 1:
        v = 1;
    st:
        **(u16 **)((struct PselWork *)ctx)->config = v;
        break;
    case 2:
        v = 2;
        goto st;
    default:
        **(u16 **)((struct PselWork *)ctx)->config = 0;
        break;
    }
    ((u32 *)((struct PselWork *)ctx)->config)[1] = ((struct PselWork *)ctx)->menuSelected;
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x87);
    return 1;
}

extern int (*sPselCallbacks[])(char *,int *);

int PSEL_Main(void *a,int *state,void *b,char *p)
{
    int old=*state;
    *state=sPselCallbacks[*state](p,(int *)(&((struct PselWork *)p)->subState));
    if(*state!=13) {
        if(*state!=old) ((struct PselWork *)p)->subState=0;
    } else return 1;
    if(*state>=2&&*state<=11) {
        PRINTSYS_QUE_Main(((struct PselWork *)p)->printQue);
        PSEL_UpdateTcbl((int *)p);
        PSEL_GRAPHIC_Draw(((struct PselWork *)p)->graphicSys);
        PSEL_GRAPHIC_ApplyLight(((struct PselWork *)p)->graphicSys);
        PSEL_DrawObjects(p);
        PSEL_GRAPHIC_DrawEnd(((struct PselWork *)p)->graphicSys);
    }
    return 0;
}

void PSEL_Task(void *unused,char *p)
{
    if(((struct PselWork *)p)->flags&1) BG_SYS_SetPlaneVisible(3,1);
    if(((struct PselWork *)p)->flags&2) BG_SYS_SetPlaneVisible(3,0);
    if(((struct PselWork *)p)->flags&4) {BG_SYS_SetPlaneVisible(3,1);BG_SYS_SetPlaneVisible(2,1);}
    if(((struct PselWork *)p)->flags&8) {BG_SYS_SetPlaneVisible(3,0);BG_SYS_SetPlaneVisible(2,0);}
    if(((struct PselWork *)p)->flags&16) {BG_SYS_SetPlaneVisible(7,1);BG_SYS_SetPlaneVisible(6,1);BG_SYS_SetPlaneVisible(5,1);}
    if(((struct PselWork *)p)->flags&32) {BG_SYS_SetPlaneVisible(7,0);BG_SYS_SetPlaneVisible(6,0);BG_SYS_SetPlaneVisible(5,0);}
    if(((struct PselWork *)p)->flags&64) BG_SYS_SetPlaneVisible(3,1);
    if(((struct PselWork *)p)->flags&128) BG_SYS_SetPlaneVisible(3,0);
    ((struct PselWork *)p)->flags=0;
}

void PSEL_DrawObjects(char *p) { u16 i;for(i=0;i<((struct PselWork *)p)->recordCount;i++){struct PselRecord *q=(struct PselRecord *)((struct PselWork *)p)->records+(u32)i;if(q->flag)G3D_SYSTEM_DrawObject(G3D_UTIL_GetObject((struct G3dUtil *)(*(u8 * *)&((struct PselWork *)p)->g3dUtil),q->id),(struct G3dObjectStatus *)(&q->translation));} }

void PSEL_CreateG3dUtil(char *p)
{
    ((struct PselWork *)p)->g3dUtil = (void *)G3D_UTIL_Create(5, 4, ((struct PselWork *)p)->heapId);
    ((struct PselWork *)p)->recordCount = 0;
}

void PSEL_DeleteG3dUtil(int *p) { G3D_UTIL_Delete(*(struct G3dUtil * *)&((struct PselWork *)p)->g3dUtil); }

void PSEL_SetupListAnime(u8 *p)
{
    u16 i;
    u32 n;
    u16 j;
    struct PselRecord *rec;
    u32 r;
    void *h;
    ((struct PselWork *)p)->unitId = G3D_UTIL_AddUnit(((struct PselWork *)p)->g3dUtil, (struct G3dUtilSetup *)d_021BC7AC);
    ((struct PselWork *)p)->recordCount = 1;
    ((struct PselWork *)p)->records = PSEL_CreateRecords(*(u16 *)p, ((struct PselWork *)p)->recordCount);
    r = G3D_UTIL_GetUnitObjIdx(((struct PselWork *)p)->g3dUtil, ((struct PselWork *)p)->unitId);
    ((struct PselWork *)p)->recSlots[0] = 0;
    rec = ((struct PselWork *)p)->records;
    rec->id = r;
    rec->flag = 1;
    for (i = 0; i < ((struct PselWork *)p)->recordCount; i++) {
        h = G3D_UTIL_GetObject(((struct PselWork *)p)->g3dUtil, ((struct PselRecord *)((struct PselWork *)p)->records)[i].id);
        n = G3D_SYSTEM_GetObjectAnimeCount(h);
        for (j = 0; j < n; j++) {
            G3D_SYSTEM_EnableObjectAnime(h, j);
        }
    }
    ((struct PselWork *)p)->animStream = ICA_ANIME_CreateStream(*(u16 *)p, 0xCD, 0x21, 0xA);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys), ((struct PselWork *)p)->animStream);
    ((struct PselWork *)p)->animFrame = 0;
}

void PSEL_DeleteListAnime(char *p) { G3D_UTIL_RemoveUnit(*(struct G3dUtil * *)&((struct PselWork *)p)->g3dUtil,((struct PselWork *)p)->unitId);PSEL_DeleteRecords(((struct PselWork *)p)->records);((struct PselWork *)p)->recordCount=0;ICA_ANIME_Delete(*(struct IcaAnime * *)&((struct PselWork *)p)->animStream); }

void PSEL_UpdateListAnime(char *p)
{
    G3dObject *obj;
    u32 n;
    u16 i,j;
    for(i=0;i<((struct PselWork *)p)->recordCount;i++) {
        obj=G3D_UTIL_GetObject((struct G3dUtil *)(*(unsigned char * *)&((struct PselWork *)p)->g3dUtil),((struct PselRecord *)((struct PselWork *)p)->records)[i].id);
        n=G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)obj);
        for(j=0;j<n;j++) G3D_SYSTEM_LoopObjectAnimeFrame((struct G3dObject *)obj,j,2048);
    }
    ICA_ANIME_IncFrameLoop(((struct PselWork *)p)->animStream,2048);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
    (*(u32 *)&((struct PselWork *)p)->animFrame)++;
}

void PSEL_SetupSelectAnime(char *p)
{
    u16 i,n,j;
    u32 base,count;
    G3dObject *obj;
    struct PselRecord *r;
    ((struct PselWork *)p)->unitId2=G3D_UTIL_AddUnit(*(struct G3dUtil * *)&((struct PselWork *)p)->g3dUtil,(struct G3dUtilSetup *)(&sPselSetup));
    ((struct PselWork *)p)->recordCount=4;
    *(struct PselRecord * *)&((struct PselWork *)p)->records=PSEL_CreateRecords(((struct PselWork *)p)->heapId,((struct PselWork *)p)->recordCount);
    n=0;
    base=G3D_UTIL_GetUnitObjIdx((struct G3dUtil *)(*(u8 * *)&((struct PselWork *)p)->g3dUtil),((struct PselWork *)p)->unitId2);
    for(i=0;i<4;i++) {
        ((struct PselWork *)p)->recSlots[1+i]=n;
        r=*(struct PselRecord * *)&((struct PselWork *)p)->records+n;
        r->id=base+i;
        r->flag=1;
        if(i+1>=2&&i+1<=4)r->translation=*(sPselPositions+i-1);
        n++;
    }
    obj=G3D_UTIL_GetObject((struct G3dUtil *)(*(u8 * *)&((struct PselWork *)p)->g3dUtil),((struct PselRecord *)((struct PselWork *)p)->records)[((struct PselWork *)p)->recSlots[1]].id);
    count=G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)obj);
    for(j=0;j<count;j++)G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)obj,j);
    ((struct PselWork *)p)->animStream=ICA_ANIME_CreateStream(((struct PselWork *)p)->heapId,205,36,10);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
    ((struct PselWork *)p)->animFrame=0;
}

void PSEL_DeleteSelectAnime(char *p) {G3D_UTIL_RemoveUnit(*(struct G3dUtil * *)&((struct PselWork *)p)->g3dUtil,((struct PselWork *)p)->unitId2);PSEL_DeleteRecords(((struct PselWork *)p)->records);((struct PselWork *)p)->recordCount=0;ICA_ANIME_Delete(*(struct IcaAnime * *)&((struct PselWork *)p)->animStream);}

void PSEL_UpdateSelectAnime(char *p)
{
    G3dObject *obj;
    u32 n;
    u16 j;
    obj=G3D_UTIL_GetObject((struct G3dUtil *)(*(unsigned char * *)&((struct PselWork *)p)->g3dUtil),((struct PselRecord *)((struct PselWork *)p)->records)[((struct PselWork *)p)->recSlots[1]].id);
    n=G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)obj);
    for(j=0;j<n;j++) G3D_SYSTEM_LoopObjectAnimeFrame((struct G3dObject *)obj,j,2048);
    ICA_ANIME_IncFrameLoop(((struct PselWork *)p)->animStream,2048);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
    (((struct PselWork *)p)->animFrame)++;
}

void PSEL_SetAnimTarget(char *p,int type,int flag)
{
    u16 v;
    float f;
    v=sPselTable[type][flag?1:0];
    if(v!=0) f=0.5f+(float)(v<<12);
    else f=(float)(v<<12)-0.5f;
    PSEL_SetAnimFrame((struct IcaAnime *)((struct PselWork *)p)->animStream,(int)f);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
    ((struct PselWork *)p)->animTableIndex=type;
    ((struct PselWork *)p)->animReverse=flag;
    ((struct PselWork *)p)->animTarget=v;
}

int PSEL_IsAnimTargetReached(char *p)
{
    int select=0;
    if(((struct PselWork *)p)->animReverse==0) select=1;
    if(((struct PselWork *)p)->animTarget==sPselTable[((struct PselWork *)p)->animTableIndex][select]) return 1;
    return 0;
}

void PSEL_StepAnim(char *p)
{
    unsigned i=0;
    if(((struct PselWork *)p)->animReverse==0) i=1;
    i=sPselTable[((struct PselWork *)p)->animTableIndex][i];
    if(((struct PselWork *)p)->animTarget!=i) {
        int step;
        if(((struct PselWork *)p)->animReverse!=0) step=-2048; else step=2048;
        ICA_ANIME_IncFrameLoop(((struct PselWork *)p)->animStream,step);
        ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
        if(((struct PselWork *)p)->animReverse!=0) --((struct PselWork *)p)->animTarget; else ++((struct PselWork *)p)->animTarget;
    if(((struct PselWork *)p)->animTarget==i && ((struct PselWork *)p)->animReverse!=0) {
        PSEL_SetAnimFrame((struct IcaAnime *)(((struct PselWork *)p)->animStream),0x4E000);
        ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
    }
    }
}

void PSEL_SetAnimTargetIndex(char *p,unsigned index)
{
    u16 value;
    int coordinate;
    value=d_021BC790[index].h[0];
    if(value!=0) coordinate=(int)((float)(value<<12)+0.5f);
    else coordinate=(int)((float)(value<<12)-0.5f);
    PSEL_SetAnimFrame((struct IcaAnime *)((struct PselWork *)p)->animStream,coordinate);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);
    ((struct PselWork *)p)->animTableIndex=index;
    ((struct PselWork *)p)->animReverse=0;
    ((struct PselWork *)p)->animTarget=value;
}

void PSEL_StepAnimIndex(char *p) {if(((struct PselWork *)p)->animTarget!=*(const u16 *)((const u8 *)d_021BC792+((struct PselWork *)p)->animTableIndex*10)) {ICA_ANIME_IncFrameLoop(*(struct IcaAnime * *)&((struct PselWork *)p)->animStream,2048);ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->animStream);(((struct PselWork *)p)->animTarget)++;}}

void PSEL_SelectUnit(char *p,unsigned next)
{
    void *object;
    unsigned count;
    u16 i;
    int frame;
    if(((struct PselWork *)p)->currentIndex!=4 && ((struct PselWork *)p)->currentIndex!=next) {
        object=G3D_UTIL_GetObject(((struct PselWork *)p)->g3dUtil,((struct PselRecord *)((struct PselWork *)p)->records)[((struct PselWork *)p)->recSlots[((struct PselWork *)p)->currentIndex+2]].id);
        count=G3D_SYSTEM_GetObjectAnimeCount(object);
        for(i=0;i<count;i++) G3D_SYSTEM_DisableObjectAnime(object,i);
    }
    if(next!=4 && ((struct PselWork *)p)->currentIndex!=next) {
        object=G3D_UTIL_GetObject(((struct PselWork *)p)->g3dUtil,((struct PselRecord *)((struct PselWork *)p)->records)[((struct PselWork *)p)->recSlots[next+2]].id);
        count=G3D_SYSTEM_GetObjectAnimeCount(object);
        frame=0;
        for(i=0;i<count;i++) {
            G3D_SYSTEM_EnableObjectAnime(object,i);
            G3D_SYSTEM_SetObjectAnimeFrame(object,i,&frame);
        }
        CLACT_SetActorAnimIndex((struct ClactActor *)((((struct PselWork *)p)->actor)),0);
    }
    ((struct PselWork *)p)->currentIndex=next;
}

void PSEL_UpdateUnitAnime(char *p)
{
    void *object;
    unsigned count;
    u16 i;
    if(((struct PselWork *)p)->currentIndex!=4) {
        object=G3D_UTIL_GetObject(((struct PselWork *)p)->g3dUtil,((struct PselRecord *)((struct PselWork *)p)->records)[((struct PselWork *)p)->recSlots[((struct PselWork *)p)->currentIndex+2]].id);
        count=G3D_SYSTEM_GetObjectAnimeCount(object);
        for(i=0;i<count;i++) G3D_SYSTEM_LoopObjectAnimeFrame(object,i,2048);
    }
}

/*
 * lever: bind the file table record before the sprite record to reproduce their address scheduling.
 */
void PSEL_CreateUnits(char *p)
{
    struct PselDesc desc;
    struct Request request;
    void *arc; uptr other; u32 id;
    char *r;
    const Files *f;
    u8 i,j;
    arc=POKEGRA_OpenHandle(((struct PselWork *)p)->heapId);
    for(i=0;i<3;i++) {
        id=sPselIds[i];r=p+i*sizeof(struct PselUnit);
        ((struct PselWork *)r)->units[0].cgr=POKEGRA_RegisterCgr(arc,id,0,0,0,0,0,0,1,((struct PselWork *)p)->heapId);
        ((struct PselWork *)r)->units[0].palette=POKEGRA_RegisterPalette(arc,id,0,0,0,0,0,1,(u16)(sPselBanks[i]<<5),((struct PselWork *)p)->heapId);
        ((struct PselWork *)r)->units[0].cellAnim=POKEGRA_RegisterCellAnim(id,0,0,0,0,0,0,1,((struct PselWork *)p)->heapId);
    }
    ARC_TOOL_DeleteHandle(arc);
    for(j=0;j<3;j++) {
        MI_CpuFill8(&request,0,8);
        request.x=sPselMotion[j].b[0];request.y=sPselMotion[j].b[1];request.z=0;request.a=2;request.b=3;
        r=p+j*sizeof(struct PselUnit);
        ((struct PselWork *)r)->units[0].actor=CLACT_CreateActor((struct Unit *)((void *)PSEL_GRAPHIC_GetClactBank(((struct PselWork *)p)->graphicSys)),((struct PselWork *)r)->units[0].cgr,((struct PselWork *)r)->units[0].palette,((struct PselWork *)r)->units[0].cellAnim,(const struct ActorInitParam *)&request,1,((struct PselWork *)p)->heapId);
        CLACT_SetActorDrawEnable((struct ClactActor *)(((struct PselWork *)r)->units[0].actor),0);
    }
    other=(uptr)ARC_TOOL_CreateHandle(205,((struct PselWork *)p)->heapId);
    for(i=0;i<3;i++) {
        f=sPselFiles+i;
        r=p+i*sizeof(struct PselUnit);
        ((struct PselWork *)r)->units[0].charHandle=CLACT_RegisterCharacter((void *)other,f->b[0],0,1,((struct PselWork *)p)->heapId);
        ((struct PselWork *)r)->units[0].affineCellAnim=CLACT_RegisterCellAnim((void *)other,f->b[2],f->b[3],((struct PselWork *)p)->heapId);
    }
    ARC_TOOL_DeleteHandle((void *)other);
    for(j=0;j<3;j++) {
        MI_CpuFill8(&desc,0,24);
        desc.x=sPselMotion[j].b[0];desc.y=sPselMotion[j].b[1];desc.z=0;desc.a=2;desc.b=3;desc.c=0;desc.d=0;
        desc.sx=FIX((float)sPselMotion[j].b[6]/16.0f);desc.sy=FIX((float)sPselMotion[j].b[6]/16.0f);
        desc.e=0;desc.f=1;
        r=p+j*sizeof(struct PselUnit);
        ((struct PselWork *)r)->units[0].affineActor=CLACT_CreateAffineActor((struct Unit *)(PSEL_GRAPHIC_GetClactBank(((struct PselWork *)p)->graphicSys)),((struct PselWork *)r)->units[0].charHandle,((struct PselWork *)r)->units[0].palette,((struct PselWork *)r)->units[0].affineCellAnim,(const struct ActorInit *)( &desc),1,((struct PselWork *)p)->heapId);
        CLACT_SetActorDrawEnable((struct ClactActor *)(((struct PselWork *)r)->units[0].affineActor),0);
    }
    for(i=0;i<3;i++) {
        ((struct PselWork *)p)->units[i].frame=0;
        ((struct PselWork *)p)->units[i].phase=0;
        ((struct PselWork *)p)->units[i].direction=0;
        ((struct PselWork *)p)->units[i].animHold=0;
    }
    ((struct PselWork *)p)->fadeAlpha=0;((struct PselWork *)p)->fadeState=0;
}

void PSEL_DeleteUnits(char *p)
{
    u8 i,j;
    char *row,*entry;
    for(i=0;i<3;i++) {
        row=p+i*sizeof(struct PselUnit);
        for(j=0;j<2;j++) {
            CLACT_DeleteActor((&((struct PselWork *)row)->units[0].actor)[j]);
            entry=row+j*12;
            CLACT_ReleaseCellAnim(((struct PselWork *)entry)->units[0].cellAnim);
            CLACT_ReleaseCharacter(((struct PselWork *)entry)->units[0].cgr);
            if(j!=1) CLACT_ReleasePalette(((struct PselWork *)entry)->units[0].palette);
        }
    }
}

int PSEL_InterpolateCurve(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time)
{
    float x,y,arc,scale;
    s16 px,py,result;
    int fixed;
    x=(float)a+(float)time*((float)c-(float)a)/(float)duration;
    y=(float)b+(float)time*((float)d-(float)b)/(float)duration;
    arc=4.0f*((0.0f-(float)amplitude)*((float)time-(float)duration/2.0f)*((float)time-(float)duration/2.0f))/(float)duration/(float)duration+(float)amplitude;
    scale=(float)e+(float)time*((float)f-(float)e)/(float)duration;
    px=(s16)x;
    py=(s16)(y-arc);
    fixed=FIX(scale/16.0f);
    pos[0]=px;pos[1]=py;
    size[0]=size[1]=fixed;
    result=(s16)y;
    return result;
}

void PSEL_UpdateUnitPositions(struct PselWork *p)
{
    int flags[3] = {0, 0, 0};
    s16 res[3];
    u8 i;
    for (i = 0; i < 3; i++) {
        struct PselUnit *e = &p->units[i];
        const u8 *t = d_021BC7F0[i];
        int d = 0;
        if (e->direction == 0)
            continue;
        switch (e->direction) {
        case 0: break;
        case 1: d = 1; break;
        case 2: d = -1; break;
        }
        if (d < 0) {
            e->frame = 0;
            e->phase = 1;
        }
        switch (e->phase) {
        case 0:
            if (d > 0) {
                CLACT_SetActorDrawEnable((struct ClactActor *)e->actor, 0);
                CLACT_SetActorDrawEnable((struct ClactActor *)e->affineActor, 1);
                e->frame = 0;
                e->phase = 1;
                e->animHold = 0;
            } else {
                if (e->direction == 2)
                    e->direction = 0;
                break;
            }
        case 1:
            if (e->frame == 0) {
                PselVec2 startPos;
                FxPair s1;
                u8 n1;
                startPos.x = t[0];
                startPos.y = t[1];
                n1 = t[6];
                s1.x = s1.y = FIX((float)n1 / 16.0f);
                CLACT_AddActorSurfacePos((struct ClactActor *)e->affineActor, (const struct ClactVec2 *)&startPos, 1);
                CLACT_SetActorScale((struct ClactActor *)e->affineActor, (struct Pair32 *)(&s1));
            } else {
                PselVec2 tweenPos;
                FxPair b1;
                res[i] = PSEL_InterpolateCurve((s16 *)(&tweenPos), (int *)(&b1), t[0], t[1], t[2], t[3], t[6], t[7], t[10], t[12], e->frame);
                flags[i] = 1;
                CLACT_AddActorSurfacePos((struct ClactActor *)e->affineActor, (const struct ClactVec2 *)&tweenPos, 1);
                CLACT_SetActorScale((struct ClactActor *)e->affineActor, (struct Pair32 *)(&b1));
            }
            if (e->frame == 0 && d < 0) {
                CLACT_SetActorDrawEnable((struct ClactActor *)e->actor, 1);
                CLACT_SetActorDrawEnable((struct ClactActor *)e->affineActor, 0);
                e->frame = 0;
                e->phase = 0;
                e->animHold = 0;
                break;
            }
            e->frame = e->frame + d;
            e->animHold = 0;
            if (e->frame == t[10]) {
                e->frame = 0;
                e->phase = 2;
            }
            break;
        case 2: {
            PselVec2 midPos;
            FxPair s2;
            u8 n2;
            midPos.x = t[2];
            midPos.y = t[3];
            n2 = t[7];
            s2.x = s2.y = FIX((float)n2 / 16.0f);
            CLACT_AddActorSurfacePos((struct ClactActor *)e->affineActor, (const struct ClactVec2 *)&midPos, 1);
            CLACT_SetActorScale((struct ClactActor *)e->affineActor, (struct Pair32 *)(&s2));
            if (e->frame == 0 && d < 0) {
                e->frame = t[10] - 1;
                e->phase = 1;
                e->animHold = 0;
                break;
            }
            e->frame = e->frame + d;
            e->animHold = 0;
            if (e->frame == t[9]) {
                e->frame = 0;
                e->phase = 3;
            }
            break;
        }
        case 3:
            if (e->frame == 0) {
                PselVec2 midPos;
                FxPair s3;
                u8 n3;
                midPos.x = t[2];
                midPos.y = t[3];
                n3 = t[7];
                s3.x = s3.y = FIX((float)n3 / 16.0f);
                CLACT_AddActorSurfacePos((struct ClactActor *)e->affineActor, (const struct ClactVec2 *)&midPos, 1);
                CLACT_SetActorScale((struct ClactActor *)e->affineActor, (struct Pair32 *)(&s3));
            } else {
                PselVec2 tweenPos;
                FxPair b3;
                res[i] = PSEL_InterpolateCurve((s16 *)(&tweenPos), (int *)(&b3), t[2], t[3], t[4], t[5], t[7], t[8], t[11], t[13], e->frame);
                flags[i] = 1;
                CLACT_AddActorSurfacePos((struct ClactActor *)e->affineActor, (const struct ClactVec2 *)&tweenPos, 1);
                CLACT_SetActorScale((struct ClactActor *)e->affineActor, (struct Pair32 *)(&b3));
            }
            if (e->frame == 0 && d < 0) {
                e->frame = t[9] - 1;
                e->phase = 2;
                e->animHold = 0;
                break;
            }
            e->frame = e->frame + d;
            e->animHold = 0;
            if (e->frame == t[11]) {
                e->frame = 0;
                e->phase = 4;
            }
            break;
        case 4: {
            PselVec2 endPos;
            FxPair s4;
            u8 n4;
            endPos.x = t[4];
            endPos.y = t[5];
            n4 = t[8];
            s4.x = s4.y = FIX((float)n4 / 16.0f);
            CLACT_AddActorSurfacePos((struct ClactActor *)e->affineActor, (const struct ClactVec2 *)&endPos, 1);
            CLACT_SetActorScale((struct ClactActor *)e->affineActor, (struct Pair32 *)(&s4));
            if (d < 0) {
                CLACT_SetActorBgPriority((struct ClactActor *)e->affineActor, 3);
                e->frame = t[11] - 1;
                e->phase = 3;
                e->animHold = 0;
                break;
            }
            if (e->direction == 1) {
                CLACT_SetActorBgPriority((struct ClactActor *)e->affineActor, 2);
                e->direction = 0;
                if (e->animHold == 0)
                    p->voicePending = 1;
            }
            break;
        }
        }
    }
    {
    u8 order[3];
    s16 z[3];
    PselVec2 pos;
    u8 j;
    order[0] = d_021BC8C0[0];
    order[1] = d_021BC8C0[1];
    order[2] = d_021BC8C0[2];
    for (i = 0; i < 3; i++) {
        if (flags[i]) {
            z[i] = res[i];
        } else {
            CLACT_GetActorSurfacePos((struct ClactActor *)p->units[i].affineActor, (struct ClactVec2 *)((struct PtS *)(&pos)), 1);
            z[i] = pos.y;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 2; j > i; j--) {
            u8 a = order[j - 1];
            u8 b = order[j];
            if (z[b] > z[a]) {
                order[j - 1] = b;
                order[j] = a;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        u8 pr;
        if (order[0] == i)
            pr = 0;
        else {
            pr = 1;
            if (order[1] != i)
                pr = 2;
        }
        CLACT_SetActorDrawPriority((struct ClactActor *)p->units[i].affineActor, pr);
    }
    }
}

void PSEL_SetUnitVisible(char *p,unsigned selected)
{
    u8 i;
    for(i=0;i<3;i++) {
        if(i==selected) PSEL_GRAPHIC_SetRecordState((unsigned char *)p,i,0); else PSEL_GRAPHIC_SetRecordState((unsigned char *)p,i,2);
        if(i==selected) {
            ((struct PselWork *)p)->units[i].direction=1;
            ((struct PselWork *)p)->units[i].animHold=1;
        } else {
            ((struct PselWork *)p)->units[i].direction=2;
            ((struct PselWork *)p)->units[i].animHold=1;
        }
    }
}

void PSEL_UpdateFadeUnit(char *p)
{
    u8 i;
    int alpha;
    for(i=0;i<3;i++) CLACT_SetActorObjMode(((struct PselWork *)p)->units[i].actor,1);
    ((struct PselWork *)p)->fadeAlpha=0;
    ((struct PselWork *)p)->fadeState=1;
    alpha=((struct PselWork *)p)->fadeAlpha;
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR,0,63,alpha,16-alpha);
}

int PSEL_IsUnitAnimDone(char *p)
{
    if(((struct PselWork *)p)->fadeState==0) return 1;
    return 0;
}

void PSEL_UpdateUnitAnime2(char *p)
{
    u8 i;
    switch(((struct PselWork *)p)->fadeState) {
    case 1:
        for(i=0;i<3;i++) CLACT_SetActorDrawEnable(((struct PselWork *)p)->units[i].actor,1);
        ((struct PselWork *)p)->fadeState=2;
        break;
    case 2:
        if(((struct PselWork *)p)->fadeAlpha<16) {
            ++((struct PselWork *)p)->fadeAlpha;
            if(((struct PselWork *)p)->fadeAlpha==16) {
                for(i=0;i<3;i++) CLACT_SetActorObjMode(((struct PselWork *)p)->units[i].actor,0);
                ((struct PselWork *)p)->fadeState=3;
            }
            G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR,0,63,((struct PselWork *)p)->fadeAlpha,16-((struct PselWork *)p)->fadeAlpha);
        } else ((struct PselWork *)p)->fadeState=3;
        break;
    case 3:
        G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR,4,63,8,8);
        ((struct PselWork *)p)->fadeState=0;
        break;
    }
}

void PSEL_CreateUnits2(char *p)
{
    void *object;
    struct Request request;
    object=ARC_TOOL_CreateHandle(205,((struct PselWork *)p)->heapId);
    ((struct PselWork *)p)->palHandle=CLACT_RegisterPaletteEx(object,11,0,0,0,1,((struct PselWork *)p)->heapId);
    ((struct PselWork *)p)->charHandle=CLACT_RegisterCharacter(object,17,0,0,((struct PselWork *)p)->heapId);
    ((struct PselWork *)p)->cellAnimHandle=CLACT_RegisterCellAnim(object,24,28,((struct PselWork *)p)->heapId);
    ARC_TOOL_DeleteHandle((void *)object);
    MI_CpuFill8(&request,0,8);
    request.x=66;request.y=39;request.z=0;request.a=0;request.b=2;
    ((struct PselWork *)p)->actor=CLACT_CreateActor((void *)PSEL_GRAPHIC_GetClactBank(((struct PselWork *)p)->graphicSys),((struct PselWork *)p)->charHandle,((struct PselWork *)p)->palHandle,((struct PselWork *)p)->cellAnimHandle,(const struct ActorInitParam *)&request,0,((struct PselWork *)p)->heapId);
    CLACT_SetActorAutoAnim(((struct PselWork *)p)->actor,1);
    PSEL_SetActorPosition(p,0);
}

void PSEL_DeleteActors(char *p) {CLACT_DeleteActor((struct ClactActor *)((((struct PselWork *)p)->actor)));CLACT_ReleaseCellAnim(((struct PselWork *)p)->cellAnimHandle);CLACT_ReleaseCharacter(((struct PselWork *)p)->charHandle);CLACT_ReleasePalette(((struct PselWork *)p)->palHandle);}

void PSEL_SetActorPosition(char *p,int flag) {PselVec2 pos;if(flag) {PSEL_UpdateActorPosition(p);}else {pos.x=400;pos.y=300;CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct PselWork *)p)->actor),(const struct ClactVec2 *)&pos,0);}}

void PSEL_UpdateActorPosition(char *p) {PselVec2 pos;u32 idx;idx=((struct PselWork *)p)->menuSelected;pos.x=d_021BC716[idx].x;pos.y=d_021BC716[idx].y;CLACT_AddActorSurfacePos((struct ClactActor *)(((struct PselWork *)p)->actor),(const struct ClactVec2 *)&pos,0);}

void PSEL_CreateBmpWindows(u16 *p)
{
    u16 *buffer;
    void *bmp,*data;
    unsigned size;
    buffer=GFL_HEAP_Alloc(*p,32,1,sPselFile,0x92B);
    buffer[0]=0;buffer[1]=0;buffer[2]=0x7FFF;
    BG_SYS_LoadPltt(2,buffer,32,0x1A0);
    BG_SYS_LoadPltt(6,buffer,32,0);
    GFL_HEAP_Free(buffer);
    bmp=BMP_Create(2,1,32,*p);
    BMP_FillRect(bmp,0,0,8,8,0);
    BMP_FillRect(bmp,8,0,8,8,1);
    data=BMP_GetPixels(bmp);size=BMP_GetByteSize(bmp);
    BG_SYS_LoadTileData(2,data,size,0);
    data=BMP_GetPixels(bmp);size=BMP_GetByteSize(bmp);
    BG_SYS_LoadTileData(6,data,size,0);
    BMP_Delete(bmp);
}

void PSEL_NopBgWindows(int *unused) {}

/*
 * lever: cast the whole ternary to u16; declare col,row before index.
 */
void PSEL_InitBgLayers(u16 *p)
{
    u8 col,row;
    u16 *buffer,index;
    buffer=GFL_HEAP_Alloc(*p,1536,1,sPselFile,0x951);
    index=0;
    for(row=0;row<24;row++) {
        for(col=0;col<32;col++) {
            u16 tile;
            tile=(u16)((row>=4 && row<20)?1:0);
            buffer[index]=tile|0xD000;
            index++;
        }
    }
    BG_SYS_DrawTile(2,(void *)buffer,0,0,32,24);
    BG_SYS_MarkTileDirty(2);
    GFL_HEAP_Free(buffer);
}

/*
 * Addresses are Black-image addresses.
 */
void PSEL_ClearBgLayer2(unsigned char *work)
{
    BG_SYS_ClearLayerEx(2, 0xd000);
}

void PSEL_DeleteBgLayers(u16 *p)
{
    void *object;
    object=ARC_TOOL_CreateHandle(205,*p);
    ARC_UTIL_UploadPaletteFromHandle(object,6,4,256,256,256,*p);
    ARC_UTIL_UploadBgCharFromHandle(object,15,4,0,0,0,*p);
    ARC_UTIL_UploadBgPaletteFromHandle(object,18,4,0,0,0,*p);
    ARC_TOOL_DeleteHandle((void *)object);
    BG_SYS_PushTile(4);
}

void PSEL_NopBgDelete(unsigned char *work) {}

void PSEL_SetBgSys(const u16 *p)
{
    u16 *buffer;
    u8 x;
    u16 v;
    u8 y;
    u16 n;
    buffer=GFL_HEAP_Alloc(*p,1536,1,sPselSite,2463);
    n=0;
    for(y=0;y<24;y++)for(x=0;x<32;x++) {
        v=(y>=17&&y<23)?1:0;
        buffer[n]=v|0xd000;
        n++;
    }
    BG_SYS_DrawTile(2,(void *)buffer,0,0,32,24);
    BG_SYS_MarkTileDirty(2);GFL_HEAP_Free(buffer);
    buffer=GFL_HEAP_Alloc(*p,1536,1,sPselSite,2488);
    n=0;
    for(x=0;x<24;x++)for(y=0;y<32;y++) {
        v=(x>=17&&x<23)?1:0;
        buffer[n]=v;
        n++;
    }
    BG_SYS_DrawTile(6,(void *)buffer,0,0,32,24);
    BG_SYS_MarkTileDirty(6);GFL_HEAP_Free(buffer);
}

void PSEL_ClearBgLayerEx(char *unused)
{
    BG_SYS_ClearLayerEx(2, 0xd000);
    BG_SYS_ClearLayerEx(6, 0);
}

/*
 * Trailing ADFA halfword is zero alignment padding.
 */
void PSEL_UploadBgPalette(u16 *p)
{
    void *object;
    object = ARC_TOOL_CreateHandle(205, *p);
    ARC_UTIL_UploadPaletteFromHandle(object, 7, 4, 256, 256, 256, *p);
    ARC_UTIL_UploadBgCharFromHandle(object, 16, 4, 0, 0, 0, *p);
    ARC_UTIL_UploadBgPaletteFromHandle(object, 19, 4, 0, 0, 0, *p);
    ARC_UTIL_UploadBgPaletteFromHandle(object, 20, 5, 0, 0, 0, *p);
    ARC_TOOL_DeleteHandle((void *)object);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(5);
}

void PSEL_NopBgUpdate(char *unused) {}

void PSEL_CreateWin(char *p)
{
    u8 i=0;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,448,32,((struct PselWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,32,32,((struct PselWork *)p)->heapId);
    *(struct MsgBank * *)&((struct PselWork *)p)->msgBank=MSGDATA_CreateFromArchive(0,3,430,((struct PselWork *)p)->heapId);
    *(struct Tcbl * *)&((struct PselWork *)p)->tcbl=(struct Tcbl *)TCBL_Create(((struct PselWork *)p)->heapId,((struct PselWork *)p)->heapId,1,0);
    GF_FONT_SetTextColor(15,2,0);
    for(;i<3;i++) {
        ((struct PselWork *)p)->windows[i]=(void *)BMP_WIN_Create(sPselEntryTable[i].a,sPselEntryTable[i].b,sPselEntryTable[i].c,sPselEntryTable[i].d,sPselEntryTable[i].e,sPselEntryTable[i].f,sPselEntryTable[i].g);
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(((struct PselWork *)p)->windows[i]))),0);
        BMP_WIN_TransferChars((struct BmpWin *)(((struct PselWork *)p)->windows[i]));
        ((struct PselWork *)p)->winFlags[i]=1;
    }
    ((struct PselWork *)p)->printStream=0;((struct PselWork *)p)->strbuf=0;
}

void PSEL_DeleteWin(char *p)
{
    u8 i;
    if (*(struct Rec3 * *)&((struct PselWork *)p)->printStream)
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)(*(struct Rec3 * *)&((struct PselWork *)p)->printStream));
    if (*(struct U16Vec * *)&((struct PselWork *)p)->strbuf)
        STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&((struct PselWork *)p)->strbuf));
    for (i = 0; i < 3; i++)
        BMP_WIN_Delete((struct BmpWin *)(((struct PselWork *)p)->windows[i]));
    TCBL_Destroy((struct TcblSystem *)(*(struct S02031140 * *)&((struct PselWork *)p)->tcbl));
    MSGDATA_Delete((struct MsgBank *)(*(struct G3dUtil * *)&((struct PselWork *)p)->msgBank));
}

void PSEL_UpdateTcbl(int *p)
{
    TCBL_Main(((struct PselWork *)p)->tcbl);
    PSEL_UpdateWindows((char *)p);
}

/*
 * Trailing AFC2 halfword is zero alignment padding. Forming q = p + i*4
 * before fixed field offsets retains the observed invariant constants;
 * computing p + constant + i*4 instead hoists pointer bases and spills p.
 */
int PSEL_UpdateWindows(char *p)
{
    int finished = 1;
    u8 i;
    for (i = 0; i < 3; i++) {
        if (((struct PselWork *)p)->winFlags[i] == 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(*(struct PrintSys * *)&((struct PselWork *)p)->printQue),
                            BMP_WIN_GetBmp((struct BmpWin *)(((struct PselWork *)p)->windows[i]))) != 0) {
                finished = 0;
            } else {
                struct Descriptor *d = (struct Descriptor *)((struct PselWork *)p)->windows[i];
                BMP_WIN_TransferChars((struct BmpWin *)d);
                BMP_WIN_MakeScreen((struct BmpWin *)d);
                BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
                ((struct PselWork *)p)->winFlags[i] = 1;
            }
        }
    }
    return finished;
}

void PSEL_SetMode(char *p, int idx)
{
    struct Descriptor *desc = ((struct PselWork *)p)->windows[1];
    s16 x = 0;
    s16 y = 0;
    unsigned w, h;
    unsigned W, H;
    BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)desc), 0);
    if (((struct PselWork *)p)->printStream != 0)
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)(((struct PselWork *)p)->printStream));
    if (((struct PselWork *)p)->strbuf != 0)
        STRBUF_Delete((struct Strbuf *)(((struct PselWork *)p)->strbuf));
    ((struct PselWork *)p)->strbuf = MSGDATA_AllocString(((struct PselWork *)p)->msgBank, idx);
    w = (u16)PRINTSYS_MeasureWidestLine((struct Strbuf *)(((struct PselWork *)p)->strbuf), ((struct PselWork *)p)->font, 0);
    h = (u16)PRINTSYS_CountLines((struct Strbuf *)(((struct PselWork *)p)->strbuf), ((struct PselWork *)p)->font);
    W = BMP_GetWidth(BMP_WIN_GetBmp((struct BmpWin *)desc));
    H = BMP_GetHeight(BMP_WIN_GetBmp((struct BmpWin *)desc));
    if (W > w)
        x = ((int)(W - w)) / 2;
    if (H > h)
        y = ((int)(H - h)) / 2;
    ((struct PselWork *)p)->printStream = PRINTSYS_PrintStream((struct BmpWin *)(desc), x, y, ((struct PselWork *)p)->strbuf, ((struct PselWork *)p)->font, MSG_SPEED_GetWait(),
                                         (struct Tcbl *)((struct PselWork *)p)->tcbl, (u32)2, *(u16 *)p, 0);
    BMP_WIN_TransferChars((struct BmpWin *)desc);
    BMP_WIN_MakeScreen((struct BmpWin *)desc);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)desc));
}

int PSEL_IsModeDone(char *a)
{
    int r = 0;

    switch (PRINTSYS_PrintStreamGetState(*(void **)&((struct PselWork *)a)->printStream)) {
    case 0:
        if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
            PRINTSYS_PrintStreamShortWait(*(struct TextPrinter **)&((struct PselWork *)a)->printStream, 0);
            if ((KEY_GetCont() & 3) != 0)
                ((struct PselWork *)a)->fadeSpeed = 0;
            else
                ((struct PselWork *)a)->fadeSpeed = 1;
        }
        break;
    case 1:
        if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
            PRINTSYS_PrintStreamReleasePause(*(void **)&((struct PselWork *)a)->printStream);
            if ((KEY_GetTrg() & 3) != 0)
                ((struct PselWork *)a)->fadeSpeed = 0;
            else
                ((struct PselWork *)a)->fadeSpeed = 1;
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

void PSEL_UpdateSubWindow(char *p)
{
    struct Descriptor *d;
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct PselWork *)p)->windows[1]))), 0);
    d = *(struct Descriptor * *)&((struct PselWork *)p)->windows[1];
    BMP_WIN_TransferChars((struct BmpWin *)d);
    BMP_WIN_MakeScreen((struct BmpWin *)d);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
    if (*(struct Rec3 * *)&((struct PselWork *)p)->printStream)
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)(*(struct Rec3 * *)&((struct PselWork *)p)->printStream));
    ((struct PselWork *)p)->printStream = 0;
    if (*(struct U16Vec * *)&((struct PselWork *)p)->strbuf)
        STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&((struct PselWork *)p)->strbuf));
    ((struct PselWork *)p)->strbuf = 0;
}

/*
 * note: 2026-10-05 (wD8 lane03): EXACT. The 0x24C slot is a pointer local `flag = (u32 *)(&((struct PselWork *)p)->winFlags[2])`
 *   set right after the desc load and written at the end (`*flag = 0`). mwcc keeps the 0x240 base from
 *   the desc load in r4, derives 0x24C from it at the top, spills only the offset and uses [r5,r0] at the
 *   store. The k/off locals and the enum type of earlier drafts are gone.
 */
void PSEL_PrintSubWindow(char *p, int idx)
{
    struct Descriptor *desc;
    u16 x;
    void *words;
    void *text;
    u32 *flag;
    struct StrObj *buf;
    u16 height;
    unsigned h;
    desc = ((struct PselWork *)p)->windows[2];
    flag = (u32 *)(&((struct PselWork *)p)->winFlags[2]);
    x = 0;
    words = WORDSET_CreateDefault(*(u16 *)p);
    text = MSGDATA_AllocString(((struct PselWork *)p)->msgBank, d_021BC730[idx]);
    buf = (struct StrObj *)STRBUF_Create(0x40, *(u16 *)p);
    WORDSET_SetSlotSpeciesName(words, 1, d_021BC710[idx]);
    WORDSET_CopyTaggedText(words, (struct Strbuf *)buf, text);
    STRBUF_Delete((struct Strbuf *)text);
    WORDSET_Delete(words);
    BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)desc), 0);
    PRINTSYS_MeasureWidestLine((struct Strbuf *)buf, ((struct PselWork *)p)->font, 0);
    height = PRINTSYS_CountLines((struct Strbuf *)buf, ((struct PselWork *)p)->font);
    BMP_GetWidth(BMP_WIN_GetBmp((struct BmpWin *)desc));
    h = BMP_GetHeight(BMP_WIN_GetBmp((struct BmpWin *)desc));
    if (h > height)
        x = ((int)h - height) / 2;
    PRINTSYS_PrintQueColor(((struct PselWork *)p)->printQue, (struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)desc), 0, (s16)x, (struct Strbuf *)buf, ((struct PselWork *)p)->font, 0x3C40);
    STRBUF_Delete((struct Strbuf *)buf);
    *flag = 0;
    PSEL_UpdateWindows(p);
}

void PSEL_ClearWin(char *p) {struct Descriptor *d;BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(((struct PselWork *)p)->windows[2]))),0);d=((struct PselWork *)p)->windows[2];BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));}

/*
 * Declare width before the zero x initializer: its store shares the
 * upcoming call's zero r2; const p left the six-byte scheduling diff.
 * The bitmap accessors' own sources return u16. This caller uses each
 * result at full width without truncation, so its declarations widen them.
 */
void PSEL_ClearWin2(char *p)
{
    struct StrObj *text = (struct StrObj *)MSGDATA_AllocString(*(struct MsgBank * *)&((struct PselWork *)p)->msgBank, 12);
    u16 width = PRINTSYS_MeasureWidestLine((struct Strbuf *)text, *(struct GfFont **)&((struct PselWork *)p)->font, 0);
    u16 x = 0;
    u16 height = PRINTSYS_CountLines((struct Strbuf *)text, ((struct PselWork *)p)->font);
    unsigned w = BMP_GetWidth(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct PselWork *)p)->windows[0])));
    unsigned h = BMP_GetHeight(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct PselWork *)p)->windows[0])));
    u16 y = 0;
    if (w > width)
        x = ((int)w - width) / 2;
    if (h > height)
        y = ((int)h - height) / 2;
    PRINTSYS_PrintQueColor((void *)((struct PselWork *)p)->printQue, (struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct PselWork *)p)->windows[0])),
                 (s16)x, (s16)y, (struct Strbuf *)text, *(struct GfFont **)&((struct PselWork *)p)->font, 0x3C40);
    STRBUF_Delete((struct Strbuf *)text);
    ((struct PselWork *)p)->winFlags[0] = 0;
    PSEL_UpdateWindows(p);
}

void PSEL_ClearWin3(char *p) {struct Descriptor *d;BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)(((struct PselWork *)p)->windows[0]))),0);d=((struct PselWork *)p)->windows[0];BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));}

void PSEL_CreateTaskRes(char *p) {*(struct TaskMenuRes * *)&((struct PselWork *)p)->taskRes=APP_TASKMENU_RES_Create(3,11,*(struct GFont **)&((struct PselWork *)p)->font,(struct PrintQueue *)(((struct PselWork *)p)->printQue),((struct PselWork *)p)->heapId);}

void PSEL_DeleteTaskResData(int *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)((struct PselWork *)p)->taskRes);
}

/*
 * The lead's EXACT* ends at BB404; two complete 16-byte load/tail-call
 * followers cover the remaining extent. Parent cleared both starts.
 */
void PSEL_ShowTaskRes(char *p)
{
    struct PselItem item;
    item.text = MSGDATA_AllocString(*(struct MsgBank * *)&((struct PselWork *)p)->msgBank, 21);
    item.color = 0x39E3;
    item.value = 0;
    ((struct PselWork *)p)->win = (void *)APP_TASKMENU_WIN_Create(*(struct TaskMenuRes **)&((struct PselWork *)p)->taskRes, (struct TaskMenuItem *)&item, PSEL_TASKRES_WIN_X, 21, PSEL_TASKRES_WIN_WIDTH, ((struct PselWork *)p)->heapId);
    STRBUF_Delete(item.text);
}

void PSEL_DeleteTaskRes(char *p)
{
    APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)(*(u8 * *)&((struct PselWork *)p)->win));
}

void PSEL_UpdateTaskResWin(char *p)
{
    APP_TASKMENU_WIN_Update((struct TaskMenuWin *)(*(u8 * *)&((struct PselWork *)p)->win));
}

void PSEL_SetTaskResActive(char *p) {APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)(((struct PselWork *)p)->win),1);APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)(((struct PselWork *)p)->win),1);}

u32 PSEL_IsTaskResFinished(char *p) {return APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)(*(u8 * *)&((struct PselWork *)p)->win));}
