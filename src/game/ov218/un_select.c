/*
 * file:     un_select.c
 * unit:     yes
 * function: UN_SELECT_SceneCreate, UN_SELECT_SceneDelete, UN_SELECT_SceneUpdate, UN_SELECT_LoadBg, UN_SELECT_CreateTouchBar, UN_SELECT_Delete, UN_SELECT_UpdateTouchBar, UN_SELECT_OpenTaskMenu, UN_SELECT_CloseTaskMenu, UN_SELECT_UpdateTaskMenu, UN_SELECT_InitRecord, UN_SELECT_RequestBrightness, UN_SELECT_Create, UN_SELECT_DeleteRecord, UN_SELECT_Main, UN_SELECT_DrawFrameListRow, UN_SELECT_DrawMessage, UN_SELECT_UpdateMessage, UN_SELECT_DrawWindowBorder, UN_SELECT_GetMsgData, UN_SELECT_GetPrintQue, UN_SELECT_GetFont, UN_SELECT_UpdateFrameList, UN_SELECT_ScrollFrameList, UN_SELECT_ScrollFrameListDelta, UN_SELECT_CreateFrameList, UN_SELECT_DeleteFrameList, UN_SELECT_CreateSceneWork, UN_SELECT_SetMode, UN_SELECT_IsListDone, UN_SELECT_SceneStepList, UN_SELECT_IsMessageDone, UN_SELECT_SceneStepMessage, UN_SELECT_SceneStepMenu, UN_SELECT_IsFadeDone, UN_SELECT_SceneStepFade, UN_SELECT_SceneStepMessageIdle, UN_SELECT_SceneStepMenuOut, UN_SELECT_Callback, UN_SELECT_LoadActors, UN_SELECT_ReleaseActors, UN_SELECT_SetupActors, UN_SELECT_DeleteActor, UN_SELECT_CreateActor, UN_SELECT_SetActorVisible, UN_SELECT_ScrollActorsBy, UN_SELECT_InitActorPositions, UN_SELECT_SetActorX, UN_SELECT_SetActorY, UN_SELECT_SetActorPos, UN_SELECT_SetActorPosEx, UN_SELECT_ContainsItem, UN_SELECT_FindTableIndex, UN_SELECT_SetupDisplay
 * address:  0x021B95A0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   UN_SELECT_GRAPHIC_Delete 0x021BA8F0 thumb ov218
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov067_id 0x00000043 data a1
 *   UI_SCENE_Step 0x021B6144 thumb ov067
 *   UN_SELECT_GRAPHIC_Update 0x021BA94C thumb ov218
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetAllButtonsBgPriority 0x021B64F8 thumb ov067
 *   TOUCHBAR_SetButtonSound 0x021B6568 thumb ov067
 *   d_021BAC20 0x021BAC20 data a4
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BRIGHTNESS_ChangeReset 0x02023F98 thumb
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 *   d_021BB088 0x021BB088 data ov218 a4
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   PRINTSYS_CountLine 0x0201D2C8 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   UN_SELECT_DrawFrameListRow 0x021B9AE4 thumb ov218
 *   FRAME_LIST_GetScrollBarTop 0x021B8AB8 thumb ov067
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   d_021BB060 0x021BB060 data ov218 a4
 *   template_021BB060 0x021BB060 data ov218 a4
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   UN_SELECT_GRAPHIC_Create 0x021BA848 thumb ov218
 *   d_021BAB20 0x021BAB20 data a4
 *   UI_SCENE_Create 0x021B6100 thumb ov067
 *   UN_SELECT_GRAPHIC_GetActor 0x021BA960 thumb ov218
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   UN_SELECT_DrawMessage 0x021B9B78 thumb ov218
 *   UN_SELECT_UpdateMessage 0x021B9C00 thumb ov218
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_021BABC8 0x021BABC8 data ov218 a4
 *   d_021BAB68 0x021BAB68 data a4
 *   d_021BAB98 0x021BAB98 data ov218 a4
 *   d_021BABB0 0x021BABB0 data ov218 a4
 *   d_021BAB80 0x021BAB80 data ov218 a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BAED8 0x021BAED8 data a2
 */
#include "../arm9/printsys.h"
#include "../sdk_ioreg.h"
#include "../arm9/nns_g2d_res_types.h"
struct UnSelectPageState {
    unsigned char pad_0[0x18];
    unsigned char page;
    unsigned char pad19;
    unsigned short start;
    unsigned char pad_1C[0x8];
    void *owner;
};
struct UnSelectActorDesc {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned short f;
    unsigned short g;
};

struct Node;
struct TaskMenuState;
struct Proc;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
struct WordSet;
struct Rec3;
struct Rec;
struct PrintSys;
struct S02031140;
struct StrObj;
struct Tmpl;
struct FrameList;
struct UiScene;
struct Proc;
struct Obj;
struct Actor;
struct UnSelectPtS;
#include "../types.h"

typedef struct { u8 *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } UnSelectTouchBarParams;

typedef struct { u32 words[24]; } UnSelectTable;

struct UnSelectItem { void *text; u16 color; u16 padding; u32 value; };

struct UnSelectTaskMenuTmpl { u32 heapId; u8 count; u8 pad05[3]; const void *unk08; u32 unk0c; u8 pad10[2]; u8 unk12, unk13; };

typedef struct Obj Obj;

typedef struct UnSelectPageState UnSelectPageState;

typedef struct UnSelectActorDesc UnSelectActorDesc;

typedef struct UnSelectPtS{s16 x,y;} UnSelectPtS;

typedef enum { FogMode0 = 0 } FogMode;

typedef enum { FogSlope0 = 0 } FogSlope;

/*
 * Scene work object.  UN_SELECT_CreateSceneWork allocates it as 0x330 bytes
 * with PROCSYS_AllocProcWork and zeroes it, then fills the head; every
 * UN_SELECT_Scene* step and actor helper receives it as its context.
 * Replaces the address-named stand-in views this file used for the object.
 */
struct UnSelectWork {
    u16 heapId;              /* +0x000 heap the work was allocated from */
    u8 pad_02[2];
    void *graphic;           /* +0x004 UN_SELECT_GRAPHIC context */
    void *touchBar;          /* +0x008 touch bar from UN_SELECT_CreateTouchBar */
    u8 pad_0C[12];
    void *taskMenuState;     /* +0x018 APP_TASKMENU_RES_Create state */
    void *taskMenu;          /* +0x01C task menu from UN_SELECT_OpenTaskMenu */
    u8 *input;               /* +0x020 raw input block */
    void *uiScene;           /* +0x024 UI_SCENE_Create scene */
    void *record;            /* +0x028 UN_SELECT_Create record */
    void *frameList;         /* +0x02C FRAME_LIST_Create list */
    int selectedIndex;       /* +0x030 row selected in the list */
    u32 itemEnabled[130];    /* +0x034 1 when the row's item is present */
    void *taskProc;          /* +0x23C proc created around UN_SELECT_Callback */
    void *mainActor;         /* +0x240 actor for the top row */
    void *rowActors[20];     /* +0x244 actors for the 20 rows */
    void *hiddenActors[7];   /* +0x294 actors hidden until the list scrolls */
    void *mode1Actors[7];    /* +0x2B0 actors whose object mode is set to 1 */
    void *selectorActor;     /* +0x2CC actor that frames the selection */
    s32 characterId;         /* +0x2D0 CLACT character id, -1 when unset */
    s32 paletteId;           /* +0x2D4 CLACT palette id, -1 when unset */
    s32 cellAnimId;          /* +0x2D8 CLACT cell anim id, -1 when unset */
    int rowIds[20];          /* +0x2DC table index per row, -1 when unset */
    int scrollKey;           /* +0x32C set when a scroll key is pressed */
};

typedef char UnSelectWork_SizeCheck[(sizeof(void *) != 4 || (sizeof(struct UnSelectWork) == 0x330)) ? 1 : -1];

/*
 * UN_SELECT record.  UN_SELECT_Create allocates it as 0x234 bytes with
 * GFL_HEAP_Alloc and fills the head; UN_SELECT_DeleteRecord tears it down.
 * UN_SELECT_CreateFrameList fills itemText with one message buffer per row.
 * Replaces the address-named stand-in views this file used for the record.
 */
struct UnSelectRecord {
    u16 heapId;              /* +0x000 heap the record was allocated from */
    u8 pad_02[2];
    struct TcblSystem *tcbl;  /* +0x004 TCBL_Create handle */
    struct MsgBank *msgBank;          /* +0x008 MSGDATA_CreateFromArchive message bank */
    struct GfFont *font;             /* +0x00C GF_FONT_Create font */
    struct PrintQueue *printQue;          /* +0x010 PRINTSYS_QUE_Create queue */
    void *wordSet;           /* +0x014 WORDSET_CreateDefault */
    void *text;              /* +0x018 STRBUF_Create text buffer */
    void *taggedText;        /* +0x01C STRBUF_Create tagged text buffer */
    struct TextPrinter *printStream;      /* +0x020 PRINTSYS_PrintStream handle */
    void *window;            /* +0x024 BMP_WIN_Create window */
    void *windowAlt;         /* +0x028 BMP_WIN_Create second window */
    void *itemText[130];     /* +0x02C message text buffer per row */
};

typedef char UnSelectRecord_SizeCheck[(sizeof(void *) != 4 || (sizeof(struct UnSelectRecord) == 0x234)) ? 1 : -1];

#include "../ov067/frame_list.h"
#include "../arm9/fade.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../ov067/ui_scene.h"
struct TaskMenuRes;
#include "../arm9/app_taskmenu.h"
#include "un_select_graphic.h"
#include "../arm9/procsys.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/bg_sys.h"
#include "../arm9/mi_memory.h"
/* The DS code passes the heap id as a word (the original prototype); the header takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define TOUCHBAR_Create TOUCHBAR_Create_header
#endif
#include "../ov067/touchbar.h"
#ifdef __MWERKS__
#undef TOUCHBAR_Create
extern TouchBar *TOUCHBAR_Create(TouchBarParams *params, int heapId);
#endif
struct PrintQueue;
struct Bmp;
struct Strbuf;
struct TextPrinter;
struct ClactActor;
struct Unit;
struct ActorInitParam;
struct ClactVec2;
#include "../arm9/strbuf_types.h"
#include "../ov067/touchbar_types.h"
#include "../ov099/wifi_club_work.h"
struct Strbuf;
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
struct TaskMenuInitWork;
struct TaskMenuWork;
#include "../arm9/brightness.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
struct TcblSystem;
#include "../arm9/tcbl.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct TextPrinter;
#include "../arm9/wordset.h"
#include "../arm9/msg_speed.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
#include "../arm9/gfl_use.h"
#include "../version.h"
/* The other languages print the row number one lower. */
#if LANGUAGE == LANGUAGE_ENGLISH || LANGUAGE == LANGUAGE_JAPANESE
#define UN_SELECT_ROW_NUMBER_BIAS 0
#else
#define UN_SELECT_ROW_NUMBER_BIAS 1
#endif
/* Row index of a frame list item; the enum type makes mwcc copy the stack argument into a local. */
enum UnSelectRowIndex { UN_SELECT_ROW_FIRST };
void UN_SELECT_DrawFrameListRow(u8 *p, u8 *a, void *b, struct GfFont *c, enum UnSelectRowIndex idx);
void UN_SELECT_DrawMessage(char *p, u32 id);
int UN_SELECT_UpdateMessage(char *p);
struct FrameListParams;
#include "../arm9/gfl_heap.h"
#include "../arm9/gx.h"
struct UiSceneEntry;
struct GFont;
#include "../arm9/g2.h"
#include "../arm9/net.h"
/* The DS code was built against other parameter widths for CLACT_GetActorSurfacePos (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void CLACT_GetActorSurfacePos(struct ClactActor *actor, struct ClactVec2 *out, u32 space);
#else
#include "../arm9/clact.h"
#endif
#include "../arm9/g3x.h"
struct G3dLight;
#include "../arm9/g3d_system.h"
int UN_SELECT_SceneCreate(void *owner,int *state,char *input,u8 *p);
int UN_SELECT_SceneDelete(struct Proc *ctx, int *state, void *unused, char *p);
int UN_SELECT_SceneUpdate(void *ctx, int *state, void *unused, char *p);
void UN_SELECT_LoadBg(u8 *p, u16 heap);
TouchBar *UN_SELECT_CreateTouchBar(struct Unit *unit, int heap);
void UN_SELECT_Delete(u8 *p);
void UN_SELECT_UpdateTouchBar(TouchBar *p);
struct TaskMenu *UN_SELECT_OpenTaskMenu(void *arg, struct MsgBank *bank, u32 heap);
void UN_SELECT_CloseTaskMenu(struct TaskMenu *p);
void UN_SELECT_UpdateTaskMenu(Obj *p);
void UN_SELECT_InitRecord(void);
void UN_SELECT_RequestBrightness(void);
void *UN_SELECT_Create(u16 heap);
void UN_SELECT_DeleteRecord(char *p);
void UN_SELECT_Main(char *p);
void UN_SELECT_DrawWindowBorder(u8 *p);
void *UN_SELECT_GetMsgData(u8 *p);
void *UN_SELECT_GetPrintQue(u8 *p);
struct MsgBank *UN_SELECT_GetFont(char *p);
void UN_SELECT_UpdateFrameList(u8 *p, u32 a, u32 b, u8 *c, u32 d);
void UN_SELECT_ScrollFrameList(u8 *p);
void UN_SELECT_ScrollFrameListDelta(u8 *p,int delta);
void UN_SELECT_CreateFrameList(char *p);
void UN_SELECT_DeleteFrameList(char *p);
char *UN_SELECT_CreateSceneWork(void *owner,char *input);
void UN_SELECT_SetMode(u8 *p, int mode);
int UN_SELECT_IsListDone(void);
int UN_SELECT_SceneStepList(unsigned char *task,char *p);
int UN_SELECT_IsMessageDone(void);
u32 UN_SELECT_SceneStepMessage(u8 *a, u8 *b);
int UN_SELECT_SceneStepMenu(unsigned char *task, char *ctx);
int UN_SELECT_IsFadeDone(void);
int UN_SELECT_SceneStepFade(unsigned char *task, char *ctx);
int UN_SELECT_SceneStepMessageIdle(void *unused, char *p);
int UN_SELECT_SceneStepMenuOut(unsigned char *task, char *ctx);
void UN_SELECT_Callback(struct TcbTask *unused0, void *unused1);
void UN_SELECT_LoadActors(char *ctx);
void UN_SELECT_ReleaseActors(char *p);
void UN_SELECT_SetupActors(char *p);
void UN_SELECT_DeleteActor(char *p);
struct Obj *UN_SELECT_CreateActor(struct Unit *owner,char *p);
void UN_SELECT_SetActorVisible(char *ctx);
void UN_SELECT_ScrollActorsBy(const char *p,int delta);
void UN_SELECT_InitActorPositions(char *ctx);
void UN_SELECT_SetActorX(char *p,int v);
void UN_SELECT_SetActorY(char *p,int y);
void UN_SELECT_SetActorPos(char *p, int sel, u32 y);
int UN_SELECT_SetActorPosEx(void **base,u32 i,u32 space,int y);
int UN_SELECT_ContainsItem(char *p, int v);
unsigned int UN_SELECT_FindTableIndex(int v);
void UN_SELECT_SetupDisplay(void);
extern char ov067_id[];
extern const UnSelectTable d_021BAC20;
extern char d_021BB088[];
extern struct UnSelectPageState d_021BB060;
extern struct UnSelectPageState template_021BB060;
extern int tbl_021BAC80[];
extern char d_021BAB20[];
extern struct UnSelectActorDesc d_021BAB68;
extern const UnSelectActorDesc d_021BABC8, d_021BAB98, d_021BABB0, d_021BAB80;
extern const unsigned short d_021BAED8[];

int UN_SELECT_SceneCreate(void *owner,int *state,char *input,u8 *p)
{
    switch(*state){
    case 0:UN_SELECT_CreateSceneWork(owner,input);++*state;break;
    case 1:if(FRAME_LIST_UpdateInit(((struct UnSelectWork *)p)->frameList)==0)return 1;break;
    }
    return 0;
}

int UN_SELECT_SceneDelete(struct Proc *ctx, int *state, void *unused, char *p)
{
    switch (*state) {
    case 0:
        FADE_Start(3, 0, 16, 1);
        ++*state;
        break;
    case 1:
        if (FADE_IsActive() != 1)
            ++*state;
        break;
    case 2: {
        u16 heap;
        TCB_DeleteTask(((struct UnSelectWork *)p)->taskProc);
        *(volatile u16 *)0x04000050 = 0;
        *(volatile u16 *)0x04001050 = 0;
        UN_SELECT_DeleteFrameList(p);
        UI_SCENE_Delete(((struct UnSelectWork *)p)->uiScene);
        UN_SELECT_DeleteRecord(((struct UnSelectWork *)p)->record);
        UN_SELECT_DeleteActor(p);
        UN_SELECT_ReleaseActors(p);
        APP_TASKMENU_RES_Delete(((struct UnSelectWork *)p)->taskMenuState);
        UN_SELECT_Delete(((struct UnSelectWork *)p)->touchBar);
        UN_SELECT_GRAPHIC_Delete(((struct UnSelectWork *)p)->graphic);
        heap = ((struct UnSelectWork *)p)->heapId;
        PROCSYS_FreeProcWork(ctx);
        GFL_HEAP_DeleteChecked(heap);
        GF_OVERLAY_Unload((sptr)ov067_id);
        return 1;
    }
    }
    return 0;
}

int UN_SELECT_SceneUpdate(void *ctx, int *state, void *unused, char *p)
{
    int result = 0;
    switch (*state) {
    case 0:
        FADE_Start(3, 16, 0, 1);
        ++*state;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            ++*state;
        break;
    case 2:
        if (UI_SCENE_Step(((struct UnSelectWork *)p)->uiScene) != 0)
            result = 1;
        break;
    }
    UN_SELECT_Main(((struct UnSelectWork *)p)->record);
    UN_SELECT_GRAPHIC_Update(((struct UnSelectWork *)p)->graphic);
    return result != 0;
}

void UN_SELECT_LoadBg(u8 *p, u16 heap)
{
    void *h;
    void *w2;
    void *w1;
    u8 *o2;
    u8 *o1;
    int a;
    int i;
    h = ARC_TOOL_CreateHandle(0xc1, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 1, 0, 0, 0xe0, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 1, 4, 0, 0xe0, heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 0xc, 4, 0, 0x200, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 6, 7, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0xd, 4, 0, 0, 0, heap);
    w1 = ARC_UTIL_LoadBgCharDataFromHandle((void *)h, 0, 0, ((void **)&o1), heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 5, 3, 0, 0, 0, heap);
    w2 = ARC_UTIL_LoadBgCharDataFromHandle((void *)h, 0, 0, ((void **)&o2), heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 2, 2, 0, 0, 0, heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 2, 6, 0, 0, 0, heap);
    for (i = 0; i < 0x82; i++) {
        u8 *buf;
        a = 0x81 - i;
        buf = (i < 0x32) ? ((NNSG2dCharacterData *)o1)->pRawData : ((NNSG2dCharacterData *)o2)->pRawData;
        if (((struct UnSelectWork *)p)->itemEnabled[i] == 0) {
            u32 col = (u8)((u8)((3 - a % 4) * 2) * 4);
            u32 off = col + (((u8)(a / 4) << 5) + 0x20);
            buf[off] = 0xff;
            buf[off + 1] = 0xff;
            buf[off + 2] = 0xff;
            buf[off + 3] = 0xff;
            buf[off + 4] = 0xff;
            buf[off + 5] = 0xff;
            buf[off + 6] = 0xff;
            buf[off + 7] = 0xff;
        }
    }
    BG_SYS_LoadTileData(7, ((NNSG2dCharacterData *)o1)->pRawData, ((NNSG2dCharacterData *)o1)->szByte, 0);
    GFL_HEAP_Free(w1);
    BG_SYS_LoadTileData(3, ((NNSG2dCharacterData *)o2)->pRawData, ((NNSG2dCharacterData *)o2)->szByte, 0);
    GFL_HEAP_Free(w2);
    ARC_TOOL_DeleteHandle(h);
}

TouchBar *UN_SELECT_CreateTouchBar(struct Unit *unit, int heap)
{
    UnSelectTable table = d_021BAC20;
    TouchBarParams config;
    TouchBar *p;
    MI_CpuFill8(&config, 0, sizeof(config));
    config.defs = (TouchBarButtonDef *)&table;
    config.count = 3;
    config.actorSys = unit;
    config.bgLayer = 1;
    config.bgPlttSlot = 13;
    config.actorPlttSlot = 0;
    config.iconSet = 0;
    p = TOUCHBAR_Create(&config, heap);
    TOUCHBAR_SetAllButtonsBgPriority((TouchBar *)p, 1);
    TOUCHBAR_SetButtonSound((TouchBar *)p, 4, 0);
    TOUCHBAR_SetButtonSound((TouchBar *)p, 5, 0);
    return p;
}

void UN_SELECT_Delete(u8 *p)
{
    TOUCHBAR_Delete((TouchBar *)p);
}

void UN_SELECT_UpdateTouchBar(TouchBar *p)
{
    TOUCHBAR_Update((TouchBar *)p);
}

struct TaskMenu *UN_SELECT_OpenTaskMenu(void *arg, struct MsgBank *bank, u32 heap)
{
    struct UnSelectTaskMenuTmpl config;
    struct UnSelectItem items[2];
    struct TaskMenu *menu;
    u32 i;
    for (i = 0; i < 2; i++) {
        items[i].text = MSGDATA_AllocString(bank, i + 235);
        items[i].color = 0x39e3;
        items[i].value = 0;
    }
    config.heapId = heap;
    config.count = 2;
    config.unk08 = items;
    config.unk0c = 1;
    config.pad10[0] = 32;
    config.pad10[1] = 18;
    config.unk12 = 13;
    config.unk13 = 3;
    menu = (struct TaskMenu *)APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&config), arg);
    for (i = 0; i < 2; i++)
        STRBUF_Delete((struct Strbuf *)items[i].text);
    return menu;
}

void UN_SELECT_CloseTaskMenu(struct TaskMenu *p)
{
    APP_TASKMENU_CloseMenu((struct TaskMenuWork *)p);
}

void UN_SELECT_UpdateTaskMenu(Obj *p)
{
    APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)p);
}

/*
 * Initialises one record: enable flag 1 through 0x02023F98, then issue the
 * five-argument setup 0x02023EF4(8, -8, 0, 0x3c, 1) and return its result.
 * Blocker target of UN_SELECT_SceneStepMessage.
 *
 * Addresses are Black-image addresses.
 */
void UN_SELECT_InitRecord(void)
{
    BRIGHTNESS_ChangeReset(1);
    BRIGHTNESS_ChangeRequest(8, -8, 0, 0x3c, 1);
}

void UN_SELECT_RequestBrightness(void)
{
    BRIGHTNESS_ChangeReset(1);
    BRIGHTNESS_ChangeRequest((sptr)((void *)8), 0, -8, 60, 1);
}

void *UN_SELECT_Create(u16 heap)
{
    char *p;
    void *window;
    p=GFL_HEAP_Alloc(heap,sizeof(struct UnSelectRecord),1,d_021BB088,PM_SRC_LINE(0x3cc, 0x3ca));
    ((struct UnSelectRecord *)p)->heapId=heap;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,0x1c0,32,heap);
    BMP_MENUWORK_LoadCharAndPltt(0,1,15,0,heap);
    ((struct UnSelectRecord *)p)->wordSet=WORDSET_CreateDefault(heap);
    ((struct UnSelectRecord *)p)->msgBank=MSGDATA_CreateFromArchive(0,2,229,heap);
    ((struct UnSelectRecord *)p)->printQue=PRINTSYS_QUE_Create((unsigned int)heap);
    ((struct UnSelectRecord *)p)->font=GF_FONT_Create(23,0,0,0,heap);
    ((struct UnSelectRecord *)p)->text=STRBUF_Create(1600,heap);
    ((struct UnSelectRecord *)p)->taggedText=STRBUF_Create(1600,heap);
    ((struct UnSelectRecord *)p)->tcbl=TCBL_Create(heap,heap,1,0);
    ((struct UnSelectRecord *)p)->window=(void *)BMP_WIN_Create(0,1,19,30,4,14,1);
    window=((struct UnSelectRecord *)p)->windowAlt=(void *)BMP_WIN_Create(4,1,1,30,2,6,1);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    GF_FONT_SetTextColor(1,2,15);
    MSGDATA_ReadString(((struct UnSelectRecord *)p)->msgBank,233,((struct UnSelectRecord *)p)->text);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),4,0,((struct UnSelectRecord *)p)->text,((struct UnSelectRecord *)p)->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
    return p;
}

void UN_SELECT_DeleteRecord(char *p)
{
    if (((struct UnSelectRecord *)p)->printStream != 0) {
        PRINTSYS_PrintStreamDelete(((struct UnSelectRecord *)p)->printStream);
        ((struct UnSelectRecord *)p)->printStream = 0;
    }
    BMP_WIN_Delete(((struct UnSelectRecord *)p)->windowAlt);
    BMP_WIN_Delete(((struct UnSelectRecord *)p)->window);
    STRBUF_Delete(((struct UnSelectRecord *)p)->text);
    STRBUF_Delete(((struct UnSelectRecord *)p)->taggedText);
    MSGDATA_Delete(((struct UnSelectRecord *)p)->msgBank);
    PRINTSYS_QUE_Delete(((struct UnSelectRecord *)p)->printQue);
    GF_FONT_Delete(((struct UnSelectRecord *)p)->font);
    TCBL_Destroy(((struct UnSelectRecord *)p)->tcbl);
    WORDSET_Delete(((struct UnSelectRecord *)p)->wordSet);
    GFL_HEAP_Free(p);
}

void UN_SELECT_Main(char *p)
{
    PRINTSYS_QUE_Main(((struct UnSelectRecord *)p)->printQue);
    TCBL_Main(((struct UnSelectRecord *)p)->tcbl);
}

void UN_SELECT_DrawFrameListRow(u8 *p, u8 *a, void *b, struct GfFont *c, enum UnSelectRowIndex idx)
{
    struct Strbuf **items;
    u32 r = 12;
#if LANGUAGE == LANGUAGE_JAPANESE
    u32 t = 0x83 - idx;
#else
    u32 d = idx;
    u32 t = 0x83 - d;
#endif
    MSGDATA_ReadString(((struct UnSelectRecord *)p)->msgBank, PM_LANG_JA((t == 2) ? 0xF0 : 0xED, 0xED), ((struct UnSelectRecord *)p)->text);
    WORDSET_SetSlotNumber(((struct UnSelectRecord *)p)->wordSet, 2, t - UN_SELECT_ROW_NUMBER_BIAS, 3, 0, 1);
    WORDSET_CopyTaggedText(((struct UnSelectRecord *)p)->wordSet, ((struct UnSelectRecord *)p)->taggedText, ((struct UnSelectRecord *)p)->text);
    TOUCHBAR_PrintAligned((TouchBarWindow *)a, b, 0, 12, ((struct UnSelectRecord *)p)->taggedText, c, 0x39E0, 0);
    items = (struct Strbuf **)((struct UnSelectRecord *)p)->itemText;
#if LANGUAGE == LANGUAGE_JAPANESE
    if (STRBUF_GetLength(items[idx]) > 10) r = 4;
    TOUCHBAR_PrintAligned((TouchBarWindow *)a, b, 0x1E, r, items[idx], c, 0x39E0, 0);
#else
    if (PRINTSYS_CountLine(items[d]) > 1) r = 4;
    TOUCHBAR_PrintAligned((TouchBarWindow *)a, b, 0x1E, r, items[d], c, 0x39E0, 0);
#endif
}

void UN_SELECT_DrawMessage(char *p, u32 id)
{
    int value = MSG_SPEED_GetWait();
    struct Descriptor *obj = ((struct UnSelectRecord *)p)->window;
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)obj), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    MSGDATA_ReadString(((struct UnSelectRecord *)p)->msgBank, id, ((struct UnSelectRecord *)p)->text);
    WORDSET_CopyTaggedText(((struct UnSelectRecord *)p)->wordSet, ((struct UnSelectRecord *)p)->taggedText, ((struct UnSelectRecord *)p)->text);
    ((struct UnSelectRecord *)p)->printStream = PRINTSYS_PrintStream((struct BmpWin *)obj, 4, 0, ((struct UnSelectRecord *)p)->taggedText, ((struct UnSelectRecord *)p)->font, value, (struct Tcbl *)((struct UnSelectRecord *)p)->tcbl, (u32)65535, ((struct UnSelectRecord *)p)->heapId, 15);
    BMP_MENUWORK_DrawWindow(((struct UnSelectRecord *)p)->window, 2, 1, 15);
    BMP_WIN_TransferChars((struct BmpWin *)obj);
    BMP_WIN_MakeScreen((struct BmpWin *)obj);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)obj));
}

int UN_SELECT_UpdateMessage(char *p)
{
    if (((struct UnSelectRecord *)p)->printStream != 0) {
        switch (PRINTSYS_PrintStreamGetState(((struct UnSelectRecord *)p)->printStream)) {
        case 2:
            PRINTSYS_PrintStreamDelete(((struct UnSelectRecord *)p)->printStream);
            ((struct UnSelectRecord *)p)->printStream = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2 || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause(((struct UnSelectRecord *)p)->printStream);
                GFL_USE_PlaySeDefaultVolume(1356);
            }
            break;
        case 0:
            if (((unsigned int)KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait(((struct UnSelectRecord *)p)->printStream, 0);
            break;
        }
        return 0;
    }
    return 0;
}

void UN_SELECT_DrawWindowBorder(u8 *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct UnSelectRecord *)p)->window,1);
}

void *UN_SELECT_GetMsgData(u8 *p)
{
    return ((struct UnSelectRecord *)p)->font;
}

void *UN_SELECT_GetPrintQue(u8 *p)
{
    return ((struct UnSelectRecord *)p)->printQue;
}

/*
 * Unlabelled leaf in ov218, printed as a .word run right before the next
 * function at 0x021B9C8C; four-byte word getter.  Blocker target of
 * UN_SELECT_SceneStepMessage (pkt_021BA0B0), whose ov218 hint then covers it.
 */
struct MsgBank *UN_SELECT_GetFont(char *p)
{
    return ((struct UnSelectRecord *)p)->msgBank;
}

void UN_SELECT_UpdateFrameList(u8 *p, u32 a, u32 b, u8 *c, u32 d)
{
    u32 t;
    UN_SELECT_SetActorVisible((char *)p);
    FRAME_LIST_GetItemValue((struct FrameList *)((struct UnSelectWork *)p)->frameList, a);
    t = (uptr)FRAME_LIST_GetPrinter((struct FrameList *)((struct UnSelectWork *)p)->frameList);
    UN_SELECT_DrawFrameListRow((u8 *)((struct UnSelectWork *)p)->record, (u8 *)(uptr)b, (void *)(uptr)t, (struct GfFont *)UN_SELECT_GetMsgData((u8 *)((struct UnSelectWork *)p)->record), a);
    if (UN_SELECT_ContainsItem((char *)p, a)) {
        UN_SELECT_SetActorPos((char *)p, d, (uptr)(c + 0x14));
    }
}

void UN_SELECT_ScrollFrameList(u8 *p)
{
    int selected;
    s16 y;
    y=FRAME_LIST_GetScrollBarTop(((struct UnSelectWork *)p)->frameList);
    UN_SELECT_SetActorX((char *)p,y);
    selected=FRAME_LIST_GetSelectedIndex(((struct UnSelectWork *)p)->frameList);
    UN_SELECT_SetActorY((char *)p,(int)(((u32)selected-(u32)FRAME_LIST_GetCursor(((struct UnSelectWork *)p)->frameList))*2+92));
}

void UN_SELECT_ScrollFrameListDelta(u8 *p,int delta)
{
    int selected;
    s16 y;
    UN_SELECT_ScrollActorsBy((const char *)p,(int)(0u-(u32)delta));
    y=FRAME_LIST_GetScrollBarTop(((struct UnSelectWork *)p)->frameList);
    UN_SELECT_SetActorX((char *)p,y);
    selected=FRAME_LIST_GetSelectedIndex(((struct UnSelectWork *)p)->frameList);
    UN_SELECT_SetActorY((char *)p,(int)(((u32)selected-(u32)FRAME_LIST_GetCursor(((struct UnSelectWork *)p)->frameList))*2+92));
}

void UN_SELECT_CreateFrameList(char *p)
{
    int i,value;
    u32 offset;
    int disabled;
    void *archive,*bank;
    d_021BB060.owner=p;
    value=*((struct UnSelectWork *)p)->input;
    if(value<=1)value=2;
    for(i=0;i<130;i++) {
        if(131-i==value) {
            if(i>126) {
                d_021BB060.page=i-126;
                d_021BB060.start=i-d_021BB060.page;
            } else d_021BB060.start=i;
        }
    }
    ((struct UnSelectWork *)p)->frameList=FRAME_LIST_Create((struct FrameListParams *)(&template_021BB060),((struct UnSelectWork *)p)->heapId);
    archive=ARC_TOOL_CreateHandle(193,((struct UnSelectWork *)p)->heapId);
    FRAME_LIST_CopyMapToBuffer(((struct UnSelectWork *)p)->frameList,archive,3,0,0);
    FRAME_LIST_CopyMapToBuffer(((struct UnSelectWork *)p)->frameList,archive,4,0,1);
    FRAME_LIST_LoadPalettes(((struct UnSelectWork *)p)->frameList,archive,1,2,3);
    ARC_TOOL_DeleteHandle(archive);
    bank=MSGDATA_CreateFromArchive(0,2,229,((struct UnSelectWork *)p)->heapId);
    for(i=0;i<130;i++) {
        offset=i*4;
        disabled=1;
        if(((struct UnSelectWork *)p)->itemEnabled[i]==1)disabled=0;
        FRAME_LIST_AddItem(((struct UnSelectWork *)p)->frameList,disabled,i);
        if(disabled==0)
            ((struct UnSelectRecord *)((struct UnSelectWork *)p)->record)->itemText[i]=MSGDATA_AllocString(bank,*(int *)((char *)tbl_021BAC80+offset));
        else
            ((struct UnSelectRecord *)((struct UnSelectWork *)p)->record)->itemText[i]=MSGDATA_AllocString(bank,238);
    }
    MSGDATA_Delete(bank);
}

void UN_SELECT_DeleteFrameList(char *p){int i;for(i=0;i<130;i++)STRBUF_Delete(((struct UnSelectRecord *)((struct UnSelectWork *)p)->record)->itemText[i]);FRAME_LIST_Delete(((struct UnSelectWork *)p)->frameList);}

char *UN_SELECT_CreateSceneWork(void *owner,char *input)
{
    char *p;
    int i,value;
    uptr a, b;
    GF_OVERLAY_Load((sptr)ov067_id);
    GFL_HEAP_CreateChildHeap(1,122,0x30000);
    p=PROCSYS_AllocProcWork(owner,sizeof(struct UnSelectWork),122);
    MI_CpuFill8(p,0,sizeof(struct UnSelectWork));
    ((struct UnSelectWork *)p)->heapId=122;
    ((struct UnSelectWork *)p)->input=(u8 *)input;
    for(i=0;i<130;i++) {
        if(*(u8 *)(input+0x2f+tbl_021BAC80[i]))((struct UnSelectWork *)p)->itemEnabled[i]=1;
        else ((struct UnSelectWork *)p)->itemEnabled[i]=0;
    }
    for(i=0;i<20;i++) {
        value=*(u16 *)(input+8+i*2);
        if(value!=0)value=UN_SELECT_FindTableIndex(value);
        else value=65535;
        ((struct UnSelectWork *)p)->rowIds[i]=value;
    }
    GXx_SetMasterBrightness_((u16 *)REG_MASTER_BRIGHT_ADDR,-16);
    GXx_SetMasterBrightness_((u16 *)REG_DB_MASTER_BRIGHT_ADDR,-16);
    ((struct UnSelectWork *)p)->graphic=UN_SELECT_GRAPHIC_Create(0,((struct UnSelectWork *)p)->heapId);
    ((struct UnSelectWork *)p)->uiScene=UI_SCENE_Create(((struct UnSelectWork *)p)->heapId,(struct UiSceneEntry *)d_021BAB20,3,0,p);
    UN_SELECT_LoadBg((u8 *)p,((struct UnSelectWork *)p)->heapId);
    ((struct UnSelectWork *)p)->record=UN_SELECT_Create(((struct UnSelectWork *)p)->heapId);
    ((struct UnSelectWork *)p)->touchBar=UN_SELECT_CreateTouchBar(UN_SELECT_GRAPHIC_GetActor(((struct UnSelectWork *)p)->graphic),((struct UnSelectWork *)p)->heapId);
    a=(uptr)UN_SELECT_GetMsgData(((struct UnSelectWork *)p)->record);
    b=(uptr)UN_SELECT_GetPrintQue(((struct UnSelectWork *)p)->record);
    ((struct UnSelectWork *)p)->taskMenuState=APP_TASKMENU_RES_Create(1,11,(struct GFont *)a,(struct PrintQueue *)b,((struct UnSelectWork *)p)->heapId);
    UN_SELECT_LoadActors(p);
    UN_SELECT_CreateFrameList(p);
    UN_SELECT_SetupActors(p);
    UN_SELECT_InitActorPositions(p);
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR,4,8,6,10);
    ((struct UnSelectWork *)p)->taskProc=GFL_USE_AddHBlankTask(UN_SELECT_Callback,(void *)((uptr)p),0);
    GFL_NET_RefreshWmIconAtTopRight(1,((struct UnSelectWork *)p)->heapId);
    return p;
}

void UN_SELECT_SetMode(u8 *p, int mode)
{
    switch (mode) {
    case 0: {
        int idx = ((struct UnSelectWork *)p)->selectedIndex;
        *(u8 *)(((struct UnSelectWork *)p)->input + 1) = 0x83 - idx;
        *(u16 *)(((struct UnSelectWork *)p)->input + 2) = tbl_021BAC80[idx];
        *(u32 *)(((struct UnSelectWork *)p)->input + 4) = 1;
        break;
    }
    case 1:
        *(u8 *)(((struct UnSelectWork *)p)->input + 1) = 0;
        *(u16 *)(((struct UnSelectWork *)p)->input + 2) = 0;
        *(u32 *)(((struct UnSelectWork *)p)->input + 4) = 0;
        break;
    }
}

int UN_SELECT_IsListDone(void) { return 1; }

int UN_SELECT_SceneStepList(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    ((struct UnSelectWork *)p)->scrollKey=0;
    if(KEY_GetTrg()&0x200)active=1;
    else if(KEY_GetTrg()&0x100)active=1;
    if(active) ((struct UnSelectWork *)p)->scrollKey=1;
    if((u32)FRAME_LIST_Update(((struct UnSelectWork *)p)->frameList)<4){
        selected=FRAME_LIST_GetSelectedIndex(((struct UnSelectWork *)p)->frameList);
        if(((struct UnSelectWork *)p)->itemEnabled[selected]==1){
            ((struct UnSelectWork *)p)->selectedIndex=selected;
            FRAME_LIST_SetRowPalette(((struct UnSelectWork *)p)->frameList,(unsigned short)FRAME_LIST_GetCursor(((struct UnSelectWork *)p)->frameList),3);
            GFL_USE_PlaySeDefaultVolume(1356);
            UI_SCENE_SetNextScene((struct UiScene *)task,*((struct UnSelectWork *)p)->input==131-selected ? 2 : 1);
            return 1;
        }
    }
    UN_SELECT_UpdateTouchBar(((struct UnSelectWork *)p)->touchBar);
    switch(TOUCHBAR_GetPressedButtonIdIfDone(((struct UnSelectWork *)p)->touchBar)){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        UN_SELECT_SetMode((u8 *)p,1);
        UI_SCENE_SetNextScene((struct UiScene *)task,65534);
        return 1;
    }
    return 0;
}

int UN_SELECT_IsMessageDone(void) { return 1; }

u32 UN_SELECT_SceneStepMessage(u8 *a, u8 *b)
{
    switch (UI_SCENE_GetPhaseFrame((struct UiScene *)a)) {
    case 0:
        UN_SELECT_InitRecord();
    tail:
        UI_SCENE_AdvancePhaseFrame((struct UiScene *)a);
        break;
    case 1:
        if (FADE_IsActive() == 1) break;
        if (BRIGHTNESS_IsFinished(1) == 0) break;
        WORDSET_SetSlotFromMsgE7((struct WordSet *)((struct UnSelectRecord *)((struct UnSelectWork *)b)->record)->wordSet, 0, tbl_021BAC80[((struct UnSelectWork *)b)->selectedIndex]);
        UN_SELECT_DrawMessage((char *)((struct UnSelectWork *)b)->record, 0xEA);
        goto tail;
    case 2:
        if (UN_SELECT_UpdateMessage((char *)((struct UnSelectWork *)b)->record) == 0) break;
        goto tail;
    case 3:
        ((struct UnSelectWork *)b)->taskMenu = (void *)UN_SELECT_OpenTaskMenu(((struct UnSelectWork *)b)->taskMenuState, (struct MsgBank *)UN_SELECT_GetFont((char *)((struct UnSelectWork *)b)->record), ((struct UnSelectWork *)b)->heapId);
        return 1;
    }
    return 0;
}

int UN_SELECT_SceneStepMenu(unsigned char *task, char *ctx)
{
    UN_SELECT_UpdateTaskMenu(((struct UnSelectWork *)ctx)->taskMenu);
    if (APP_TASKMENU_IsFinish(((struct UnSelectWork *)ctx)->taskMenu) != 0) {
        switch (APP_TASKMENU_GetCursorPos(((struct UnSelectWork *)ctx)->taskMenu)) {
        case 0:
            UN_SELECT_SetMode((u8 *)ctx, 0);
            UN_SELECT_RequestBrightness();
            UN_SELECT_DrawWindowBorder(((struct UnSelectWork *)ctx)->record);
            UN_SELECT_CloseTaskMenu(((struct UnSelectWork *)ctx)->taskMenu);
            UI_SCENE_SetNextScene((struct UiScene *)task, 65534);
            break;
        case 1:
            UN_SELECT_RequestBrightness();
            UN_SELECT_DrawWindowBorder(((struct UnSelectWork *)ctx)->record);
            UN_SELECT_CloseTaskMenu(((struct UnSelectWork *)ctx)->taskMenu);
            UI_SCENE_SetNextScene((struct UiScene *)task, 0);
            break;
        }
        return 1;
    }
    return 0;
}

int UN_SELECT_IsFadeDone(void){if(FADE_IsActive()==1 || BRIGHTNESS_IsFinished(1)==0)return 0;return 1;}

int UN_SELECT_SceneStepFade(unsigned char *task, char *ctx)
{
    switch (UI_SCENE_GetPhaseFrame((struct UiScene *)task)) {
    case 0:
        UN_SELECT_InitRecord();
advance:
        UI_SCENE_AdvancePhaseFrame((struct UiScene *)task);
        break;
    case 1:
        if (FADE_IsActive() == 1)
            break;
        if (BRIGHTNESS_IsFinished(1) == 0)
            break;
        UN_SELECT_DrawMessage(((struct UnSelectWork *)ctx)->record, 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}

int UN_SELECT_SceneStepMessageIdle(void *unused, char *p)
{
    return UN_SELECT_UpdateMessage((char *)((struct UnSelectWork *)p)->record) != 0;
}

int UN_SELECT_SceneStepMenuOut(unsigned char *task, char *ctx)
{
    UN_SELECT_RequestBrightness();
    UN_SELECT_DrawWindowBorder(((struct UnSelectWork *)ctx)->record);
    UI_SCENE_SetNextScene((struct UiScene *)task, 0);
    return 1;
}

void UN_SELECT_Callback(struct TcbTask *unused0, void *unused1)
{
    int count = *(volatile unsigned short *)REG_VCOUNT_ADDR;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}

void UN_SELECT_LoadActors(char *ctx)
{
    unsigned short heap = ((struct UnSelectWork *)ctx)->heapId;
    void *archive;
    ((struct UnSelectWork *)ctx)->characterId = -1;
    ((struct UnSelectWork *)ctx)->paletteId = -1;
    ((struct UnSelectWork *)ctx)->cellAnimId = -1;
    archive = ARC_TOOL_CreateHandle(193, heap);
    ((struct UnSelectWork *)ctx)->characterId = CLACT_RegisterCharacter((void *)(archive), 10, 0, 2, heap);
    ((struct UnSelectWork *)ctx)->paletteId = CLACT_RegisterPalette((void *)archive, 11, 2, 96, heap);
    ((struct UnSelectWork *)ctx)->cellAnimId = CLACT_RegisterCellAnim((void *)(archive), 9, 8, heap);
    ARC_TOOL_DeleteHandle(archive);
}

void UN_SELECT_ReleaseActors(char *p){if(((struct UnSelectWork *)p)->characterId!=-1)CLACT_ReleaseCharacter(((struct UnSelectWork *)p)->characterId);if(((struct UnSelectWork *)p)->paletteId!=-1)CLACT_ReleasePalette(((struct UnSelectWork *)p)->paletteId);if(((struct UnSelectWork *)p)->cellAnimId!=-1)CLACT_ReleaseCellAnim(((struct UnSelectWork *)p)->cellAnimId);}

void UN_SELECT_SetupActors(char *p)
{
    UnSelectActorDesc a,b,c,d,e;
    struct Unit *manager;
    void *item;
    int i,j;
    manager=UN_SELECT_GRAPHIC_GetActor(((struct UnSelectWork *)p)->graphic);
    for(j=0;j<36;j++)(&((struct UnSelectWork *)p)->mainActor)[j]=0;
    a=d_021BABC8;
    a.c=((struct UnSelectWork *)p)->characterId;a.d=((struct UnSelectWork *)p)->paletteId;a.e=((struct UnSelectWork *)p)->cellAnimId;
    ((struct UnSelectWork *)p)->mainActor=UN_SELECT_CreateActor(manager,(char *)(&a));
    b=d_021BAB68;
    b.c=((struct UnSelectWork *)p)->characterId;b.d=((struct UnSelectWork *)p)->paletteId;b.e=((struct UnSelectWork *)p)->cellAnimId;
    for(i=0;i<20;i++)((struct UnSelectWork *)p)->rowActors[i]=UN_SELECT_CreateActor(manager,(char *)(&b));
    c=d_021BAB98;
    c.c=((struct UnSelectWork *)p)->characterId;c.d=((struct UnSelectWork *)p)->paletteId;c.e=((struct UnSelectWork *)p)->cellAnimId;
    for(j=0;j<7;j++) {
        item=UN_SELECT_CreateActor(manager,(char *)(&c));
        CLACT_SetActorDrawEnable(item,0);
        ((struct UnSelectWork *)p)->hiddenActors[j]=item;
    }
    d=d_021BABB0;
    d.c=((struct UnSelectWork *)p)->characterId;d.d=((struct UnSelectWork *)p)->paletteId;d.e=((struct UnSelectWork *)p)->cellAnimId;
    for(i=0;i<7;i++) {
        item=UN_SELECT_CreateActor(manager,(char *)(&d));
        CLACT_SetActorObjMode(item,1);
        CLACT_SetActorDrawEnable(item,0);
        ((struct UnSelectWork *)p)->mode1Actors[i]=item;
    }
    e=d_021BAB80;
    e.c=((struct UnSelectWork *)p)->characterId;e.d=((struct UnSelectWork *)p)->paletteId;e.e=((struct UnSelectWork *)p)->cellAnimId;
    ((struct UnSelectWork *)p)->selectorActor=UN_SELECT_CreateActor(manager,(char *)(&e));
}

void UN_SELECT_DeleteActor(char *p)
{
    int i;
    for (i = 0; i < 0x24; i++)
    {
        void *q = (&((struct UnSelectWork *)p)->mainActor)[i];
        if (q != 0)
        {
            CLACT_DeleteActor(q);
        }
    }
}

struct Obj *UN_SELECT_CreateActor(struct Unit *owner,char *p){struct Obj *r;r=(struct Obj *)CLACT_CreateActor(owner,((struct UnSelectActorDesc *)p)->c,((struct UnSelectActorDesc *)p)->d,((struct UnSelectActorDesc *)p)->e,(const struct ActorInitParam *)(p),((struct UnSelectActorDesc *)p)->g,122);CLACT_SetActorAutoAnim((struct ClactActor *)r,1);return r;}

void UN_SELECT_SetActorVisible(char *ctx)
{
    int i;
    void *item;
    if (((struct UnSelectWork *)ctx)->scrollKey != 0) {
        ((struct UnSelectWork *)ctx)->scrollKey = 0;
        for (i = 0; i < 7; i++) {
            item = ((struct UnSelectWork *)ctx)->hiddenActors[i];
            if (CLACT_GetActorDrawEnable(item) != 0)
                CLACT_SetActorDrawEnable(item, 0);
        }
        for (i = 0; i < 7; i++) {
            item = ((struct UnSelectWork *)ctx)->mode1Actors[i];
            if (CLACT_GetActorDrawEnable(item) != 0)
                CLACT_SetActorDrawEnable(item, 0);
        }
    }
}

static inline void scroll(const char *p,short delta,int space,UnSelectPtS *pos)
{
    void *item;
    long i;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((const struct UnSelectWork *)p)->hiddenActors[i];
        else item=((const struct UnSelectWork *)p)->mode1Actors[i];
        if(CLACT_GetActorDrawEnable(item)){
            CLACT_GetActorSurfacePos(item,(struct ClactVec2 *)pos,space);
            pos->y+=delta;
            value=pos->y;
            CLACT_AddActorSurfacePos((struct ClactActor *)item,(const struct ClactVec2 *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)CLACT_SetActorDrawEnable(item,0);
            }else{
                if(value<=-28 || value>=212)CLACT_SetActorDrawEnable(item,0);
            }
        }
    }
}

static inline void scrollSecond(const char *p,short delta,int space,UnSelectPtS *pos)
{
    long i;
    void *item;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((const struct UnSelectWork *)p)->hiddenActors[i];
        else item=((const struct UnSelectWork *)p)->mode1Actors[i];
        if(CLACT_GetActorDrawEnable(item)){
            CLACT_GetActorSurfacePos(item,(struct ClactVec2 *)pos,space);
            pos->y+=delta;
            value=pos->y;
            CLACT_AddActorSurfacePos((struct ClactActor *)item,(const struct ClactVec2 *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)CLACT_SetActorDrawEnable(item,0);
            }else{
                if(value<=-28 || value>=212)CLACT_SetActorDrawEnable(item,0);
            }
        }
    }
}

/*
 * checks: 1 actor accessor/unit bodies fix return and three-argument position calls; 2 ov218 A61C confirms UnSelectPtS ABI, no two-loop twin; 3 long index and const p each unchanged; 4 inline short-parameter helper reproduces both raw-parameter recasts, shared UnSelectPtS fixes frame; 5 full idiom listing and A61C/other ov218 callers reread.
 * Two manual scheduling variants used; once-only permuter 300/jobs1/types unchanged, emitted baseline agrees at DIFF 200/200 with 9 concrete bytes.
 * single-lever: separate inline helpers use item-before-index in the first loop and index-before-item in the second; shared helper order swaps one loop's r4/r5 pair (9 bytes out).
 */
void UN_SELECT_ScrollActorsBy(const char *p,int delta)
{
    UnSelectPtS pos;
    scroll(p,delta,0,&pos);
    scrollSecond(p,delta,1,&pos);
}

/*
 * single-lever: row base retains ctx+i*4; fields at 244/2DC reproduce rematerialized id offset instead of hoisting a second array base.
 */
void UN_SELECT_InitActorPositions(char *ctx)
{
    int i;
    void *item;
    UnSelectPtS pos;
    for (i = 0; i < 20; i++) {
        item = ((struct UnSelectWork *)ctx)->rowActors[i];
        if (((struct UnSelectWork *)ctx)->rowIds[i] == 65535) {
            CLACT_SetActorDrawEnable(item, 0);
        } else {
            CLACT_GetActorSurfacePos(item, (struct ClactVec2 *)&pos, 65535);
            pos.y = ((struct UnSelectWork *)ctx)->rowIds[i] * 2 + 92;
            CLACT_AddActorSurfacePos((struct ClactActor *)item, (const struct ClactVec2 *)((const struct UnSelectPtS *)(&pos)), 65535);
        }
    }
}

/*
 * extent: 2 zero alignment bytes at 021BA6BA.
 */
void UN_SELECT_SetActorX(char *p,int v){UnSelectPtS pos;s16 y;void *o;o=((struct UnSelectWork *)p)->selectorActor;y=(s16)v;if(y<16)y=16;else if(y>152)y=152;CLACT_GetActorSurfacePos(o,(struct ClactVec2 *)(&pos),0);pos.y=y;CLACT_AddActorSurfacePos((struct ClactActor *)o,(const struct ClactVec2 *)&pos,0);}

void UN_SELECT_SetActorY(char *p,int y){UnSelectPtS pos;void *o=((struct UnSelectWork *)p)->mainActor;CLACT_GetActorSurfacePos(o,(struct ClactVec2 *)(&pos),65535);pos.y=y;CLACT_AddActorSurfacePos((struct ClactActor *)o,(const struct ClactVec2 *)&pos,65535);}

void UN_SELECT_SetActorPos(char *p, int sel, u32 y)
{
    void **base;
    u32 space;
    int i;
    int n;
    if (sel) {
        space = 0;
        base = ((struct UnSelectWork *)p)->hiddenActors;
        n = 7;
    } else {
        space = 1;
        base = ((struct UnSelectWork *)p)->mode1Actors;
        n = 7;
    }
    for (i = 0; i < n; i++) {
        if (UN_SELECT_SetActorPosEx(base, i, space, y)) break;
    }
}

int UN_SELECT_SetActorPosEx(void **base,u32 i,u32 space,int y){UnSelectPtS pos;int r;void *o;o=base[i];r=0;if(CLACT_GetActorDrawEnable((struct ClactActor *)o)==0){CLACT_SetActorDrawEnable((struct ClactActor *)o,1);r=1;CLACT_GetActorSurfacePos(o,(struct ClactVec2 *)(&pos),space);pos.y=y;CLACT_AddActorSurfacePos((struct ClactActor *)o,(const struct ClactVec2 *)&pos,space);}return r;}

int UN_SELECT_ContainsItem(char *p, int v)
{
    int i;
    for (i = 0; i < 0x14; i++)
    {
        if (v == ((struct UnSelectWork *)p)->rowIds[i])
        {
            return 1;
        }
    }
    return 0;
}

unsigned int UN_SELECT_FindTableIndex(int v)
{
    int i;
    for (i = 0; i < 0x82; i++)
    {
        if (v == tbl_021BAC80[i])
        {
            break;
        }
    }
    if (i >= 0x82)
    {
        return 0xffff;
    }
    return i;
}

void UN_SELECT_SetupDisplay(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~(2 | 0x3000)) | 2;
    *(volatile unsigned short *)0x04000060 &= ~(0x10 | 0x3000);
    *(volatile unsigned short *)0x04000060 &= ~(4 | 0x3000);
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~0x3000) | 8;
    *(volatile unsigned short *)0x04000060 &= ~(0x20 | 0x3000);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((unsigned char)i, (struct G3dLight *)(&d_021BAED8[i * 4]));
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}
