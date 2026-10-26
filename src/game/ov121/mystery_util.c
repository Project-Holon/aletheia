/*
 * file:     mystery_util.c
 * unit:     yes
 * function: MYSTERY_UTIL_CreateWindow, MYSTERY_UTIL_DeleteWindow, MYSTERY_UTIL_ClearWindow, MYSTERY_UTIL_ShowMessage, MYSTERY_UTIL_ShowString, MYSTERY_UTIL_SetColor, MYSTERY_UTIL_SetPosition, MYSTERY_UTIL_IsMessageDone, MYSTERY_UTIL_TransferWindowChars, MYSTERY_UTIL_ComputeTextPosition, MYSTERY_UTIL_AlignText, MYSTERY_UTIL_CreateMenuWindow, MYSTERY_UTIL_CreateMenuWindow2, MYSTERY_UTIL_DeleteMenuWindow, MYSTERY_UTIL_UpdateMenuWindow, MYSTERY_UTIL_SetMenuMessage, MYSTERY_UTIL_SetMenuMode, MYSTERY_UTIL_GetMenuState, MYSTERY_UTIL_DrawMenuWindow, MYSTERY_UTIL_ResetMenuWindow, MYSTERY_UTIL_CreateMenu, MYSTERY_UTIL_DeleteMenu, MYSTERY_UTIL_UpdateMenu, MYSTERY_UTIL_CreateWindowList, MYSTERY_UTIL_DeleteWindowList, MYSTERY_UTIL_ClearWindowList, MYSTERY_UTIL_IsWindowListDone, MYSTERY_UTIL_ClearListWindow, MYSTERY_UTIL_TransferWindowList, MYSTERY_UTIL_CreateBmpList, MYSTERY_UTIL_DeleteBmpList, MYSTERY_UTIL_DrawBmpList, MYSTERY_UTIL_CopyBmpList, MYSTERY_UTIL_CreateDetailWindow, MYSTERY_UTIL_DeleteDetailWindow, MYSTERY_UTIL_SetVoice, MYSTERY_UTIL_Update, MYSTERY_UTIL_SetListValue, MYSTERY_UTIL_CreateTask, MYSTERY_UTIL_DeleteTask, MYSTERY_UTIL_DispatchTask, MYSTERY_UTIL_IsTaskDone, MYSTERY_UTIL_SetTaskHandler, MYSTERY_UTIL_MarkTaskDone, MYSTERY_UTIL_SetTaskArg, MYSTERY_UTIL_GetTaskArg, MYSTERY_UTIL_CreateTaskEx, MYSTERY_UTIL_DeleteActorPair, MYSTERY_UTIL_UpdateActorPair, MYSTERY_UTIL_SetActorPairText, MYSTERY_UTIL_SetActorPairColor, MYSTERY_UTIL_SetVec, MYSTERY_UTIL_IsMenuFinished, MYSTERY_UTIL_BuildPaletteRow, MYSTERY_UTIL_BlendPalette, MYSTERY_UTIL_BlendPaletteRange
 * address:  0x021D99A4
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_util.c, mystery_album.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   BMP_WIN_Delete  0x020452E8  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Copy 0x02045838 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_CTRL_Init 0x02028470 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   TCBL_Main 0x020310C4 arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   d_021DF78C 0x021DF78C data a4
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_GetTileBytes 0x02043994 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Delete 0x020437AC arm
 *   BMP_CopyPixels 0x02043814 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021DF7C0 0x021DF7C0 data a4
 *   d_021DF76C 0x021DF76C data a4
 *   d_021DF770 0x021DF770 data a4
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   FX_SinCosTable_ 0x020A1B38 data a4
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   BMP_OAM_Create  0x020255A0  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   PRINTSYS_CTRL_Update  0x02028484  thumb  arm9
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb  arm9
 *   MYSTERY_UTIL_DeleteBmpList 0x021DA3C0 thumb ov121
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 *   MYSTERY_UTIL_CopyBmpList 0x021DA4A8 thumb ov121
 *   MYSTERY_UTIL_TransferWindowList 0x021DA318 thumb ov121
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb  arm9
 *   PRINTSYS_CountLines  0x0201D42C  thumb  arm9
 *   BMP_MENULIST_ResetCursorTile  0x02020CF8  thumb  arm9
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb  arm9
 *   BMP_MENULIST_GetAttr  0x02020350  thumb  arm9
 *   BMP_MENULIST_SetCancelDisabled  0x02020D10  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "mystery_net_types.h"
#include "../sdk_ioreg.h"
#include "mystery_util_shared_types.h"

/*
 * Text window drawn through the BMP_WIN subsystem (mystery_util.c). Allocated
 * 0x28 bytes by MYSTERY_UTIL_Create; shown and hidden through MYSTERY_UTIL_ShowMessage.
 */
typedef struct MysteryUtilWindow {
    void *bmpWin;           /* 0x00 BMP_WIN handle */
    unsigned char visible;  /* 0x04 set once the text has been queued */
    struct PrintQueue *printOwner;       /* 0x08 owner passed to PRINTSYS_PrintQueColor */
    void *bmpWin2;          /* 0x0C second BMP_WIN handle (same as bmpWin) */
    void *textBuf;          /* 0x10 STRBUF text buffer */
    unsigned short textParam; /* 0x14 */
    unsigned short color;   /* 0x16 palette slot / colour word */
    int posX;               /* 0x18 */
    int posY;               /* 0x1C */
    int mode;               /* 0x20 layout mode for MYSTERY_UTIL_AlignText */
    unsigned int variant;   /* 0x24 window variant */
} MysteryUtilWindow;

/*
 * Scrollable text window with a TCBL renderer and a PRINTSYS print stream
 * (mystery_util.c). Allocated 0x40 bytes by MYSTERY_UTIL_CreateMenuWindow.
 */
typedef struct MysteryUtilMenuWindow {
    void *handler;          /* 0x00 handler/vtable slot (guess) */
    struct GfFont *printArg;    /* 0x04 */
    void *printStream;      /* 0x08 PRINTSYS_PrintStream handle */
    void *tcbl;             /* 0x0C TCBL text renderer */
    void *bmpWin;           /* 0x10 BMP_WIN handle */
    void *textBuf;          /* 0x14 STRBUF */
    unsigned short height;  /* 0x18 */
    unsigned short heapTag; /* 0x1A */
    void *bmpWin2;          /* 0x1C BMP_WIN handle used by PRINTSYS_PrintQue */
    unsigned char visible;  /* 0x20 */
    struct PrintQueue *elementSlot;   /* 0x24 PRINTSYS queue */
    unsigned int state;     /* 0x28 */
    unsigned int result;   /* 0x2C */
    void *keyCursor;        /* 0x30 APP_KEYCURSOR handle */
    unsigned char ctrl[8];  /* 0x34 PRINTSYS_CTRL block */
    void *timeIcon;         /* 0x3C TIME_ICON handle */
} MysteryUtilMenuWindow;

/*
 * Table of text windows (mystery_util.c). Built by MYSTERY_UTIL_CreateWindowList; the
 * descriptor table is an array of MysteryUtilMenuEntry, 24 bytes each.
 */
typedef struct MysteryUtilWindowList {
    const char *desc;       /* 0x00 descriptor table */
    unsigned int count;     /* 0x04 number of windows */
    struct GfFont *font;             /* 0x08 */
    struct MsgBank *msgBank;             /* 0x0C */
    void *items[1];         /* 0x10 text windows */
} MysteryUtilWindowList;

/*
 * Table of BMP buffers copied from a MysteryUtilWindowList (mystery_util.c).
 * Built by MYSTERY_UTIL_CreateBmpList, 0x08 bytes of header then one BMP per window.
 */
typedef struct MysteryUtilBmpList {
    unsigned short heapId;  /* 0x00 */
    void *srcList;          /* 0x04 MysteryUtilWindowList */
    void *bmps[1];          /* 0x08 BMP buffers */
} MysteryUtilBmpList;

/*
 * One entry of a MysteryUtilWindowList. MYSTERY_UTIL_CreateWindowList walks the
 * list with a slot base of out + i*4, so the window pointer of entry i sits at
 * slot + 0x10. Writing this as ((MysteryUtilWindowList *)out)->items[i] changes
 * the register allocation of the 196-byte function (verified DIFF), so the slot
 * view is kept.
 */
typedef struct MysteryUtilWindowSlot {
    unsigned char pad00[0x10];
    void *window;           /* 0x10 */
} MysteryUtilWindowSlot;

/*
 * Menu window with a BMP_MENULIST and a BMP_MENUWORK (mystery_util.c).
 * Allocated 0x18 bytes by MYSTERY_UTIL_CreateMenu.
 */
typedef struct MysteryUtilMenu {
    void *bmpWin;           /* 0x00 BMP_WIN handle */
    struct PrintQueue *printOwner;    /* 0x04 print owner */
    void *bmpWin2;          /* 0x08 BMP_WIN handle */
    unsigned char winFlag;   /* 0x0C */
    void *menuList;         /* 0x10 BMP_MENULIST handle */
    void *menuWork;         /* 0x14 BMP_MENUWORK handle */
} MysteryUtilMenu;

/*
 * Task node created by MYSTERY_UTIL_CreateTask and driven through the handler at
 * 0x00 by MYSTERY_UTIL_DispatchTask. 0x14 bytes.
 */
typedef struct MysteryUtilTask {
    void (*handler)(void *, int *, void *); /* 0x00 called with (task, &state, arg) */
    unsigned int done;   /* 0x04 dispatch is skipped while nonzero */
    int state;           /* 0x08 */
    union { void *ptr; unsigned int value; } arg; /* 0x0C third argument passed to the handler */
    unsigned int value;  /* 0x10 */
} MysteryUtilTask;

/*
 * Sprite pair that owns a BMP, a STRBUF text buffer, a BMP_OAM grid and a
 * PRINTSYS queue. Allocated 0x24 bytes by MYSTERY_UTIL_CreateTaskEx and drawn
 * through MYSTERY_UTIL_SetActorPairText / MYSTERY_UTIL_IsMenuFinished.
 */
typedef struct MysteryUtilActorPair {
    struct Bmp *bmp;        /* 0x00 BMP_Create handle */
    unsigned short color;   /* 0x04 palette slot, masked with 0x1F */
    unsigned char pad06[2];
    int done;               /* 0x08 set once text is queued */
    int posX;               /* 0x0C text x offset */
    int posY;               /* 0x10 text y offset */
    int mode;               /* 0x14 layout mode for MYSTERY_UTIL_AlignText */
    struct Strbuf *textBuf; /* 0x18 STRBUF text */
    struct BmpOam *oam;     /* 0x1C BMP_OAM grid */
    struct PrintQueue *printQueue; /* 0x20 PRINTSYS queue */
} MysteryUtilActorPair;

/* Read-only input record for MYSTERY_UTIL_CreateTaskEx (8 bytes). */
typedef struct MysteryUtilActorPairDef {
    signed short x;         /* 0x00 */
    signed short y;         /* 0x02 */
    unsigned char pad04[2];
    unsigned char a;        /* 0x06 */
    unsigned char b;        /* 0x07 */
} MysteryUtilActorPairDef;

/*
 * Detail selector: a window list plus a CLACT cursor actor, a selected index and
 * count, and four current/target palette fade pairs. Created by
 * MYSTERY_UTIL_CreateDetailWindow from a MysteryUtilDetailDef and stepped by
 * MYSTERY_UTIL_SetVoice. The phase advances by 0x400 per step.
 */
typedef struct MysteryUtilDetailWindow {
    void *windowList;           /* 0x00 MYSTERY_UTIL_CreateWindowList table */
    struct ClactActor *actor;   /* 0x04 CLACT actor */
    unsigned int index;         /* 0x08 selected entry */
    unsigned int count;         /* 0x0C number of entries */
    unsigned short pad10;       /* 0x10 */
    unsigned short pal[4];      /* 0x12 palette entries read from the BG palette */
    unsigned short palWork[4];  /* 0x1A faded copies, passed to MYSTERY_UTIL_BlendPalette */
    unsigned short blendColor;  /* 0x22 colour passed to MYSTERY_UTIL_BlendPalette */
    unsigned short phase;       /* 0x24 fade phase, advanced by 0x400 */
    unsigned short windowPalette;  /* 0x26 */
    unsigned short bgLayer;     /* 0x28 */
    unsigned short windowPalette2; /* 0x2A */
    unsigned short paletteBank; /* 0x2C palette bank */
    signed short rowOffset;     /* 0x2E row offset in tiles */
    unsigned short animSeq;     /* 0x30 actor animation sequence */
    unsigned short pad32;       /* 0x32 */
    void (*callback)(void *);   /* 0x34 optional change callback */
    void *callbackArg;          /* 0x38 callback argument */
    unsigned int current[4];    /* 0x3C applied palette fade values */
    unsigned int target[4];     /* 0x4C requested palette fade values */
    unsigned int pad5C;         /* 0x5C */
    unsigned int *outIndex;     /* 0x60 written back on a selection change */
} MysteryUtilDetailWindow;

struct CharBuf;

struct Descriptor;

struct U16Vec;

struct MsgBank;

struct PrintSys;

struct Tcbl;

struct Blk;

struct Src;

struct Grid;

struct Param;

typedef struct { int x; int y; } MysteryUtilTextPos;

/*
 * BMP_MENULIST create source (d_021DF78C). MYSTERY_UTIL_CreateMenu fills the
 * menu work, the window, the item table and the two count words before calling
 * BMP_MENULIST_Create.
 */
typedef struct MysteryUtilMenuListSrc {
    void *menuWork;       /* 0x00 BMP_MENUWORK handle */
    u32 pad04[2];       /* 0x04 */
    struct BmpWin *bmpWin;         /* 0x0C BMP_WIN handle */
    u16 itemCount;      /* 0x10 item count */
    u16 itemCountAlt;   /* 0x12 second item count word, set to the same value */
    u32 pad14[4];       /* 0x14 */
    struct MsgBank *menuTable;      /* 0x24 item table passed to BMP_MENUWORK_AddMsgItem */
    void *slotPointer;    /* 0x28 element slot pointer (menu object + 8) */
    struct PrintQueue *printOwner;     /* 0x2C */
    struct GfFont *messageTable;   /* 0x30 */
} MysteryUtilMenuListSrc;

struct MysteryUtilDetailEntry {
    u8 a;
    u8 b;
    u8 pad[6];
    void *h;
    u8 rest[12];
};

struct MysteryUtilDetailTable { struct MysteryUtilDetailEntry r[4]; };

struct MysteryUtilPt { s16 x; s16 y; };

/* BMP_OAM create parameter (MYSTERY_UTIL_CreateTaskEx). */
typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } MysteryUtilOamParam;

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"


#ifdef __MWERKS__
#define STRBUF_Create STRBUF_Create_hdr
#endif
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
#undef STRBUF_Create
struct Strbuf * STRBUF_Create(u32, u16);
#endif
struct BmpWin;

#include "../arm9/bmp_win.h"
struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"




#include "../arm9/bg_sys.h"

struct Strbuf;



#include "../arm9/msgdata.h"
struct GfFont;
struct PrintQueue;

#include "../arm9/printsys.h"







struct TcblSystem;

#include "../arm9/tcbl.h"

#include "../arm9/app_keycursor.h"
struct TextPrinter;

struct TimeIcon;

#include "../arm9/time_icon.h"
struct KeyCursor;



#ifdef __MWERKS__
#define BMP_MENUWORK_DrawWindow BMP_MENUWORK_DrawWindow_hdr
#endif
#include "../arm9/bmp_menuwork.h"
#ifdef __MWERKS__
#undef BMP_MENUWORK_DrawWindow
void BMP_MENUWORK_DrawWindow(struct BmpWin *, int, int, int);
#endif

struct PrintStreamCtrl;


struct TcbList;

#include "../arm9/gfl_use.h"




#include "../arm9/msg_speed.h"




struct MenuTemplate;
struct BmpMenuList;

#include "../arm9/bmp_menulist.h"













#include "../arm9/clact.h"
struct ClactActor;




#include "../arm9/key.h"




#include "../arm9/bmp_oam.h"
struct BmpOam;



#include "../arm9/nns_gfd_vram_transfer.h"

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, struct PrintQueue *h, u16 heap);

void MYSTERY_UTIL_DeleteWindow(u8 *p);

void MYSTERY_UTIL_ClearWindow(u8 *p);

void MYSTERY_UTIL_ShowMessage(u8 *p, struct MsgBank *a, int b, struct GfFont *c);

void MYSTERY_UTIL_ShowString(u8 *p, struct Strbuf *a, struct GfFont *b);

void MYSTERY_UTIL_SetColor(u8 *p,unsigned v);

void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);

int MYSTERY_UTIL_IsMessageDone(u8 *p);

void MYSTERY_UTIL_TransferWindowChars(u8 *p);

void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,struct GfFont *a,MysteryUtilTextPos *out);

void MYSTERY_UTIL_AlignText(u32 mode, const MysteryUtilTextPos *in, const void *bitmap, void *obj, struct GfFont *a, MysteryUtilTextPos *out);

void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, struct PrintQueue *c, struct GfFont *d, u16 heap);

void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, struct PrintQueue *c, struct GfFont *d, u16 heap);

void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);

void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);

void MYSTERY_UTIL_SetMenuMessage(u8 *a, struct MsgBank *b, int c, int d);

void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode);

unsigned MYSTERY_UTIL_GetMenuState(u8 *p);

void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);

void MYSTERY_UTIL_ResetMenuWindow(u8 *p);

void *MYSTERY_UTIL_CreateMenu(const MysteryUtilMenuDef *p,u16 heap);

void MYSTERY_UTIL_DeleteMenu(u8 *p);

int MYSTERY_UTIL_UpdateMenu(char *p);

void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,struct PrintQueue *d,struct MsgBank *e,struct GfFont *f,u16 heap);

void MYSTERY_UTIL_DeleteWindowList(u8 *p);

void MYSTERY_UTIL_ClearWindowList(u8 *p);

int MYSTERY_UTIL_IsWindowListDone(u8 *p);

void MYSTERY_UTIL_ClearListWindow(u8 *p,u32 i);

void MYSTERY_UTIL_TransferWindowList(u8 *p);

void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap);

void MYSTERY_UTIL_DeleteBmpList(u8 *p);

void MYSTERY_UTIL_DrawBmpList(char *p,char *desc,void *dst);

void MYSTERY_UTIL_CopyBmpList(u8 *p);

struct MysteryUtilDetailWindow *MYSTERY_UTIL_CreateDetailWindow(const struct MysteryUtilDetailDef *in, u16 heap);

void MYSTERY_UTIL_DeleteDetailWindow(MysteryUtilDetailWindow *p);

int MYSTERY_UTIL_SetVoice(MysteryUtilDetailWindow *p);

int MYSTERY_UTIL_Update(MysteryUtilDetailWindow *p);

void MYSTERY_UTIL_SetListValue(MysteryUtilDetailWindow *p,u32 i,u32 value);

void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap);

void MYSTERY_UTIL_DeleteTask(void *p);

void MYSTERY_UTIL_DispatchTask(char *p);

int MYSTERY_UTIL_IsTaskDone(MysteryUtilTask *p);

void MYSTERY_UTIL_SetTaskHandler(MysteryUtilTask *p, void (*a)(void *, int *, void *));

void MYSTERY_UTIL_MarkTaskDone(MysteryUtilTask *p);

void MYSTERY_UTIL_SetTaskArg(MysteryUtilTask *p,u32 a);

void MYSTERY_UTIL_GetTaskArg(MysteryUtilTask *p);

void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);

void MYSTERY_UTIL_DeleteActorPair(MysteryUtilActorPair *p);

void MYSTERY_UTIL_UpdateActorPair(MysteryUtilActorPair *p);

void MYSTERY_UTIL_SetActorPairText(MysteryUtilActorPair *p,struct MsgBank *a,int b,struct GfFont *c);

void MYSTERY_UTIL_SetActorPairColor(MysteryUtilActorPair *p,int a);

void MYSTERY_UTIL_SetVec(MysteryUtilActorPair *p,u32 a,u32 b,u32 c);

int MYSTERY_UTIL_IsMenuFinished(MysteryUtilActorPair *p);

void MYSTERY_UTIL_BuildPaletteRow(MysteryUtilActorPair *p,struct GfFont *a,int *out);

s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);

void MYSTERY_UTIL_BlendPaletteRange(u32 a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);

extern const char d_021DFBA0[];

extern const MysteryUtilMenuListSrc d_021DF78C;

extern const struct MysteryUtilDetailTable d_021DF7C0;

extern const MysteryUtilTextPos d_021DF76C[];

extern const MysteryUtilTextPos d_021DF770[];

extern const s16 FX_SinCosTable_[];

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, struct PrintQueue *h, u16 heap)
{
    u8 *p;
    void *q;
    p = GFL_HEAP_Alloc(heap, 0x28, 0, (char *)d_021DFBA0, 0x55);
    MI_CpuFill8(p, 0, 0x28);
    ((MysteryUtilWindow *)p)->printOwner = h;
    ((MysteryUtilWindow *)p)->textParam = b;
    ((MysteryUtilWindow *)p)->color = 0x440;
    ((MysteryUtilWindow *)p)->variant = a;
    ((MysteryUtilWindow *)p)->textBuf = STRBUF_Create(0x200, heap);
    q = (void *)BMP_WIN_Create((u8)b, (u16)c, (u16)d, (u8)e, f, g, 1);
    ((MysteryUtilWindow *)p)->bmpWin2 = q;
    ((MysteryUtilWindow *)p)->bmpWin = q;
    p[4] = 0;
    BMP_Clear(BMP_WIN_GetBmp(q), ((MysteryUtilWindow *)p)->color & 31);
    if (((MysteryUtilWindow *)p)->variant == 0) {
        BMP_WIN_TransferChars(((MysteryUtilWindow *)p)->bmpWin2);
        BMP_WIN_MakeScreen(((MysteryUtilWindow *)p)->bmpWin2);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(((MysteryUtilWindow *)p)->bmpWin2));
    }
    return p;
}

void MYSTERY_UTIL_DeleteWindow(u8 *p)
{
    BMP_WIN_Delete(((MysteryUtilWindow *)p)->bmpWin2);
    STRBUF_Delete(((MysteryUtilWindow *)p)->textBuf);
    GFL_HEAP_Free(p);
}

void MYSTERY_UTIL_ClearWindow(u8 *p) { BMP_WIN_ClearScreen(((MysteryUtilWindow *)p)->bmpWin2); }

/*
 * extent: two zero padding bytes at 0x021D9AC6.
 */
void MYSTERY_UTIL_ShowMessage(u8 *p, struct MsgBank *a, int b, struct GfFont *c)
{
    MysteryUtilTextPos xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2), ((MysteryUtilWindow *)p)->color & 31);
    MSGDATA_ReadString(a, b, ((MysteryUtilWindow *)p)->textBuf);
    MYSTERY_UTIL_ComputeTextPosition(p, c, &xy);
    q = ((MysteryUtilWindow *)p)->printOwner;
    PRINTSYS_PrintQueColor(q, (struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin), (s16)xy.x, (s16)xy.y,
                 (struct Strbuf *)(((MysteryUtilWindow *)p)->textBuf), c, ((MysteryUtilWindow *)p)->color);
    ((MysteryUtilWindow *)p)->visible = 1;
}

/*
 * extent: two zero padding bytes at 0x021D9B26.
 */
void MYSTERY_UTIL_ShowString(u8 *p, struct Strbuf *a, struct GfFont *b)
{
    MysteryUtilTextPos xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2), ((MysteryUtilWindow *)p)->color & 31);
    STRBUF_Copy((struct Strbuf *)(((MysteryUtilWindow *)p)->textBuf), a);
    MYSTERY_UTIL_ComputeTextPosition(p, b, &xy);
    q = ((MysteryUtilWindow *)p)->printOwner;
    PRINTSYS_PrintQueColor(q, (struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin), (s16)xy.x, (s16)xy.y,
                 (struct Strbuf *)(((MysteryUtilWindow *)p)->textBuf), b, ((MysteryUtilWindow *)p)->color);
    ((MysteryUtilWindow *)p)->visible = 1;
}

void MYSTERY_UTIL_SetColor(u8 *p,unsigned v) { ((MysteryUtilWindow *)p)->color=v; }

void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c)
{
    ((MysteryUtilWindow *)p)->posX = a;
    ((MysteryUtilWindow *)p)->posY = b;
    ((MysteryUtilWindow *)p)->mode = c;
}

int MYSTERY_UTIL_IsMessageDone(u8 *p)
{
    struct PrintQueue *q;
    if (((MysteryUtilWindow *)p)->variant == 0) {
        q = ((MysteryUtilWindow *)p)->printOwner;
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget(q, (void *)(BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilWindow *)p)->bmpWin))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilWindow *)p)->bmpWin);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(((MysteryUtilWindow *)p)->printOwner), (void *)(BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilWindow *)p)->bmpWin))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}

void MYSTERY_UTIL_TransferWindowChars(u8 *p) {
    BMP_WIN_TransferChars(((MysteryUtilWindow *)p)->bmpWin2);
    if(((MysteryUtilWindow *)p)->variant==1) {
        BMP_WIN_MakeScreen(((MysteryUtilWindow *)p)->bmpWin2);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(((MysteryUtilWindow *)p)->bmpWin2));
    }
}

/*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 */
void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,struct GfFont *a,MysteryUtilTextPos *out) {
    void *bitmap=BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2);
    MYSTERY_UTIL_AlignText(((MysteryUtilWindow *)p)->mode,(const MysteryUtilTextPos *)&((MysteryUtilWindow *)p)->posX,bitmap,((MysteryUtilWindow *)p)->textBuf,a,out);
}

/*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a MysteryUtilTextPos assignment.
 */
void MYSTERY_UTIL_AlignText(u32 mode, const MysteryUtilTextPos *in, const void *bitmap, void *obj, struct GfFont *a, MysteryUtilTextPos *out)
{
    int x;
    int y;
    switch (mode) {
    case 0:
        *out = *in;
        return;
    case 1:
        x = (u32)BMP_GetWidth((struct Bmp *)bitmap) / 2;
        y = (u32)BMP_GetHeight((struct Bmp *)bitmap) / 2;
        x -= PRINTSYS_MeasureWidestLine(obj, a, 0) / 2;
        y -= PRINTSYS_CountLines(obj, a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)BMP_GetHeight((struct Bmp *)bitmap) / 2;
        y -= PRINTSYS_CountLines(obj, a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = BMP_GetWidth((struct Bmp *)bitmap);
        x -= PRINTSYS_MeasureWidestLine(obj, a, 0);
        if (x < 0) x = 0;
        out->x = x + in->x;
        out->y = in->y;
        break;
    }
}

static inline void *allocate(u16 heap, u32 size, const char *site, u16 line)
{
    return GFL_HEAP_Alloc(heap, size, 0, (char *)site, line);
}

/*
 * lever: final push 2026-10-05 G3L5. heap is a u16 parameter and every heap-taking callee
 *   (GFL_HEAP_Alloc first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order
 *   (lsls of the line constant after the heap load). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov177 WIFIBATTLEMATCH_UTIL_Create.
 */
void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, struct PrintQueue *c, struct GfFont *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    MI_CpuFill8(p, 0, 0x40);
    ((MysteryUtilMenuWindow *)p)->height = 15;
    ((MysteryUtilMenuWindow *)p)->printArg = d;
    ((MysteryUtilMenuWindow *)p)->elementSlot = c;
    ((MysteryUtilMenuWindow *)p)->state = 3;
    ((MysteryUtilMenuWindow *)p)->textBuf = STRBUF_Create(0x300, heap);
    q = (void *)BMP_WIN_Create((u8)a, 1, 19, 30, 4, b, 1);
    ((MysteryUtilMenuWindow *)p)->bmpWin = q;
    ((MysteryUtilMenuWindow *)p)->bmpWin2 = q;
    ((MysteryUtilMenuWindow *)p)->visible = 0;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin), ((MysteryUtilMenuWindow *)p)->height);
    q = ((MysteryUtilMenuWindow *)p)->bmpWin;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    ((MysteryUtilMenuWindow *)p)->tcbl = TCBL_Create(heap, heap, 1, 32);
    return p;
}

/*
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (GFL_HEAP_Alloc first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 MYSTERY_UTIL_CreateMenuWindow.
 */
void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, struct PrintQueue *c, struct GfFont *d, u16 heap)
{
    u8 *p;
    void *q;
    p = GFL_HEAP_Alloc(heap, 0x40, 0, (char *)d_021DFBA0, 0x1ae);
    MI_CpuFill8(p, 0, 0x40);
    ((MysteryUtilMenuWindow *)p)->height = 15;
    ((MysteryUtilMenuWindow *)p)->printArg = d;
    ((MysteryUtilMenuWindow *)p)->elementSlot = c;
    ((MysteryUtilMenuWindow *)p)->state = 3;
    PRINTSYS_CTRL_Init((PrintStreamCtrl *)((MysteryUtilMenuWindow *)p)->ctrl, 2);
    ((MysteryUtilMenuWindow *)p)->textBuf = STRBUF_Create(0x200, heap);
    q = (void *)BMP_WIN_Create((u8)a, 1, 21, 30, 2, b, 1);
    ((MysteryUtilMenuWindow *)p)->bmpWin = q;
    ((MysteryUtilMenuWindow *)p)->bmpWin2 = q;
    ((MysteryUtilMenuWindow *)p)->visible = 0;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin), ((MysteryUtilMenuWindow *)p)->height);
    q = ((MysteryUtilMenuWindow *)p)->bmpWin;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    ((MysteryUtilMenuWindow *)p)->tcbl = TCBL_Create(heap, heap, 1, 32);
    return p;
}

void MYSTERY_UTIL_DeleteMenuWindow(u8 *p)
{
    if (((MysteryUtilMenuWindow *)p)->printStream) {
        PRINTSYS_PrintStreamDelete(((MysteryUtilMenuWindow *)p)->printStream);
        ((MysteryUtilMenuWindow *)p)->printStream = 0;
    }
    if (((MysteryUtilMenuWindow *)p)->timeIcon) {
        TIME_ICON_Delete(((MysteryUtilMenuWindow *)p)->timeIcon);
        ((MysteryUtilMenuWindow *)p)->timeIcon = 0;
    }
    if (((MysteryUtilMenuWindow *)p)->keyCursor) APP_KEYCURSOR_Delete((struct KeyCursor *)(((MysteryUtilMenuWindow *)p)->keyCursor));
    TCBL_Destroy(((MysteryUtilMenuWindow *)p)->tcbl);
    BMP_MENUWORK_DrawWindowBorder(((MysteryUtilMenuWindow *)p)->bmpWin, 0);
    BMP_WIN_Delete(((MysteryUtilMenuWindow *)p)->bmpWin);
    STRBUF_Delete(((MysteryUtilMenuWindow *)p)->textBuf);
    GFL_HEAP_Free(p);
}

/*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 */
void MYSTERY_UTIL_UpdateMenuWindow(u8 *p)
{
    struct PrintQueue *q;
    switch (((MysteryUtilMenuWindow *)p)->state) {
    case 2:
        q = ((MysteryUtilMenuWindow *)p)->elementSlot;
        if (((MysteryUtilMenuWindow *)p)->visible) {
            if (PRINTSYS_QUE_IsExistTarget(q, (void *)(BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2);
                ((MysteryUtilMenuWindow *)p)->visible = 0;
            }
        }
        break;
    case 0:
        q = ((MysteryUtilMenuWindow *)p)->elementSlot;
        if (((MysteryUtilMenuWindow *)p)->visible) {
            if (PRINTSYS_QUE_IsExistTarget(q, (void *)(BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2);
                ((MysteryUtilMenuWindow *)p)->visible = 0;
            }
        }
        ((MysteryUtilMenuWindow *)p)->result = ((MysteryUtilMenuWindow *)p)->visible == 0 ? 1 : 0;
        break;
    case 1:
        if (((MysteryUtilMenuWindow *)p)->printStream) {
            if (((MysteryUtilMenuWindow *)p)->keyCursor)
                APP_KEYCURSOR_Update((struct KeyCursor *)(((MysteryUtilMenuWindow *)p)->keyCursor), (void *)(((MysteryUtilMenuWindow *)p)->printStream), (void *)(((MysteryUtilMenuWindow *)p)->bmpWin));
            if (PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)((MysteryUtilMenuWindow *)p)->ctrl, (void *)(((MysteryUtilMenuWindow *)p)->printStream)))
                ((MysteryUtilMenuWindow *)p)->result = 1;
        }
        break;
    case 3:
        break;
    }
    TCBL_Main((struct TcblSystem *)(((MysteryUtilMenuWindow *)p)->tcbl));
}

void MYSTERY_UTIL_SetMenuMessage(u8 *a, struct MsgBank *b, int c, int d)
{
    MSGDATA_ReadString(b, c, ((MysteryUtilMenuWindow *)a)->textBuf);
    MYSTERY_UTIL_SetMenuMode(a, d);
}

void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode)
{
    struct PrintQueue *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin),((MysteryUtilMenuWindow *)p)->height);
    if(((MysteryUtilMenuWindow *)p)->printStream) {
        PRINTSYS_PrintStreamDelete(((MysteryUtilMenuWindow *)p)->printStream);
        ((MysteryUtilMenuWindow *)p)->printStream=0;
    }
    if(((MysteryUtilMenuWindow *)p)->keyCursor) {
        APP_KEYCURSOR_Delete((struct KeyCursor *)(((MysteryUtilMenuWindow *)p)->keyCursor));
        ((MysteryUtilMenuWindow *)p)->keyCursor=0;
    }
    MYSTERY_UTIL_ResetMenuWindow(p);
    switch(mode) {
    case 2:
        ((MysteryUtilMenuWindow *)p)->timeIcon=TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(),((MysteryUtilMenuWindow *)p)->bmpWin,((MysteryUtilMenuWindow *)p)->height,16,((MysteryUtilMenuWindow *)p)->heapTag);
        q=((MysteryUtilMenuWindow *)p)->elementSlot;
        PRINTSYS_PrintQue(q,(struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin2),0,0,((MysteryUtilMenuWindow *)p)->textBuf,(struct GfFont *)(((MysteryUtilMenuWindow *)p)->printArg));
        ((MysteryUtilMenuWindow *)p)->visible=1;
        ((MysteryUtilMenuWindow *)p)->state=0;
        break;
    case 0:
        q=((MysteryUtilMenuWindow *)p)->elementSlot;
        PRINTSYS_PrintQue(q,(struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin2),0,0,((MysteryUtilMenuWindow *)p)->textBuf,(struct GfFont *)(((MysteryUtilMenuWindow *)p)->printArg));
        ((MysteryUtilMenuWindow *)p)->visible=1;
        ((MysteryUtilMenuWindow *)p)->state=0;
        break;
    case 1:
        PRINTSYS_CTRL_Init((PrintStreamCtrl *)((MysteryUtilMenuWindow *)p)->ctrl,2);
        ((MysteryUtilMenuWindow *)p)->keyCursor=APP_KEYCURSOR_CreateDefault(((MysteryUtilMenuWindow *)p)->height,1,0,((MysteryUtilMenuWindow *)p)->heapTag);
        ((MysteryUtilMenuWindow *)p)->printStream=PRINTSYS_PrintStream((struct BmpWin *)(((MysteryUtilMenuWindow *)p)->bmpWin),0,0,(struct Strbuf *)(((MysteryUtilMenuWindow *)p)->textBuf),(struct GfFont *)(((MysteryUtilMenuWindow *)p)->printArg),MSG_SPEED_GetWait(),(struct Tcbl *)(((MysteryUtilMenuWindow *)p)->tcbl),0,((MysteryUtilMenuWindow *)p)->heapTag,((MysteryUtilMenuWindow *)p)->height);
        ((MysteryUtilMenuWindow *)p)->state=1;
        break;
    }
    ((MysteryUtilMenuWindow *)p)->result=0;
}

unsigned MYSTERY_UTIL_GetMenuState(u8 *p) { return ((MysteryUtilMenuWindow *)p)->result; }

void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b)
{
    BMP_MENUWORK_DrawWindow(((MysteryUtilMenuWindow *)p)->bmpWin, 0, a, b);
}

void MYSTERY_UTIL_ResetMenuWindow(u8 *p) { ((MysteryUtilMenuWindow *)p)->result=1; if(*(u8 * *)&((MysteryUtilMenuWindow *)p)->timeIcon) { TIME_ICON_Delete((struct TimeIcon *)(*(u8 * *)&((MysteryUtilMenuWindow *)p)->timeIcon)); ((MysteryUtilMenuWindow *)p)->timeIcon=0; BMP_WIN_MakeScreen(((MysteryUtilMenuWindow *)p)->bmpWin); BG_SYS_PushTile(BMP_WIN_GetBgLayer(((MysteryUtilMenuWindow *)p)->bmpWin)); } }

/*
 * lever: const source parameter and the original heap stack argument to 0201F878.
 */
void *MYSTERY_UTIL_CreateMenu(const MysteryUtilMenuDef *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    MysteryUtilMenuListSrc cfg;
    out=GFL_HEAP_Alloc(heap,24,0,(char *)d_021DFBA0,0x2cb);
    MI_CpuFill8(out,0,24);
    ((MysteryUtilMenu *)out)->printOwner=((MysteryUtilMenuDef *)p)->printOwner;
    ((MysteryUtilMenu *)out)->bmpWin=(void *)BMP_WIN_Create((u8)(((MysteryUtilMenuDef *)p)->bgLayer),(u16)19,(u16)((u8)(17-(u8)(((MysteryUtilMenuDef *)p)->count*2))),(u8)12,(u8)(((MysteryUtilMenuDef *)p)->count*2),((MysteryUtilMenuDef *)p)->palette,1);
    BMP_MENUWORK_DrawWindow(((MysteryUtilMenu *)out)->bmpWin,2,((MysteryUtilMenuDef *)p)->windowY,(u8)(((MysteryUtilMenuDef *)p)->windowX));
    q=((MysteryUtilMenu *)out)->bmpWin;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    ((MysteryUtilMenu *)out)->bmpWin2=((MysteryUtilMenu *)out)->bmpWin;
    ((MysteryUtilMenu *)out)->winFlag=0;
    ((MysteryUtilMenu *)out)->menuWork=BMP_MENUWORK_Create(((MysteryUtilMenuDef *)p)->count,heap);
    for(i=0;i<((MysteryUtilMenuDef *)p)->count;i++)
        BMP_MENUWORK_AddMsgItem(((MysteryUtilMenu *)out)->menuWork,(struct MsgBank *)((MysteryUtilMenuDef *)p)->menuTable,((MysteryUtilMenuDef *)p)->menuItems[i],i,(u16)heap);
    cfg=d_021DF78C;
    cfg.menuWork=((MysteryUtilMenu *)out)->menuWork;
    cfg.itemCount=((MysteryUtilMenuDef *)p)->count;
    cfg.itemCountAlt=((MysteryUtilMenuDef *)p)->count;
    cfg.bmpWin=((MysteryUtilMenu *)out)->bmpWin;
    cfg.menuTable=((MysteryUtilMenuDef *)p)->menuTable;
    cfg.slotPointer=(void *)&((MysteryUtilMenu *)out)->bmpWin2;
    cfg.printOwner=((MysteryUtilMenuDef *)p)->printOwner;
    cfg.messageTable=((MysteryUtilMenuDef *)p)->messageTable;
    ((MysteryUtilMenu *)out)->menuList=BMP_MENULIST_Create((struct BmpMenuListTemplate *)((struct MenuTemplate *)(&cfg)),0,0,heap);
    BMP_MENULIST_ResetCursorTile(((MysteryUtilMenu *)out)->menuList,heap);
    BMP_MENULIST_SetCancelDisabled(((MysteryUtilMenu *)out)->menuList,0);
    return out;
}

void MYSTERY_UTIL_DeleteMenu(u8 *p) { BMP_MENULIST_Delete(((MysteryUtilMenu *)p)->menuList,0,0); BMP_MENUWORK_Delete(((MysteryUtilMenu *)p)->menuWork); BMP_MENUWORK_DrawWindowBorder(((MysteryUtilMenu *)p)->bmpWin,0); BMP_WIN_ClearScreen(((MysteryUtilMenu *)p)->bmpWin); BMP_WIN_Delete(((MysteryUtilMenu *)p)->bmpWin); GFL_HEAP_Free(p); }

/*
 * extent: two bytes of zero alignment padding follow the return.
 */
int MYSTERY_UTIL_UpdateMenu(char *p)
{
    struct PrintQueue *q = ((MysteryUtilMenu *)p)->printOwner;
    int r;
    if (((MysteryUtilMenu *)p)->winFlag) {
        if (PRINTSYS_QUE_IsExistTarget(q,(void *)(BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilMenu *)p)->bmpWin2))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilMenu *)p)->bmpWin2);
            ((MysteryUtilMenu *)p)->winFlag=0;
        }
    }
    r=BMP_MENULIST_Main(((MysteryUtilMenu *)p)->menuList);
    if (r == -2) r=BMP_MENULIST_GetAttr(((MysteryUtilMenu *)p)->menuList,2)-1;
    return r;
}

/*
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 */
void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,struct PrintQueue *d,struct MsgBank *e,struct GfFont *f,u16 heap)
{
    u32 i;
    int size=n*sizeof(void *)+(sizeof(MysteryUtilWindowList)-sizeof(void *));
    char *out=GFL_HEAP_Alloc(heap,size,0,(char *)d_021DFBA0,0x374);
    MI_CpuFill8(out,0,size);
    *(const char * *)&((MysteryUtilWindowList *)out)->desc=desc;
    ((MysteryUtilWindowList *)out)->count=n;
    ((MysteryUtilWindowList *)out)->font=f;
    ((MysteryUtilWindowList *)out)->msgBank=e;
    for(i=0;i<((MysteryUtilWindowList *)out)->count;i++) {
        const char *v=desc+i*24;
        MysteryUtilWindowSlot *slot=(MysteryUtilWindowSlot *)(out+i*4);
        void *q=MYSTERY_UTIL_CreateWindow((uptr)a,b,((MysteryUtilMenuEntry *)v)->u0.bytes[0],((MysteryUtilMenuEntry *)v)->u0.bytes[1],((MysteryUtilMenuEntry *)v)->u0.bytes[2],((MysteryUtilMenuEntry *)v)->u0.bytes[3],c,d,heap);
        slot->window=q;
        MYSTERY_UTIL_SetPosition(q,((MysteryUtilMenuEntry *)v)->posX,((MysteryUtilMenuEntry *)v)->posY,((MysteryUtilMenuEntry *)v)->layoutMode);
        MYSTERY_UTIL_SetColor(slot->window,((MysteryUtilMenuEntry *)v)->color);
        if(((MysteryUtilMenuEntry *)v)->str.stringPtr) MYSTERY_UTIL_ShowString(slot->window,((MysteryUtilMenuEntry *)v)->str.stringPtr,((MysteryUtilWindowList *)out)->font);
        else MYSTERY_UTIL_ShowMessage(slot->window,e,((MysteryUtilMenuEntry *)v)->messageId,((MysteryUtilWindowList *)out)->font);
    }
    return out;
}

void MYSTERY_UTIL_DeleteWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_DeleteWindow(((MysteryUtilWindowList *)p)->items[i]); GFL_HEAP_Free(p); }

void MYSTERY_UTIL_ClearWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_ClearWindow(((MysteryUtilWindowList *)p)->items[i]); }

int MYSTERY_UTIL_IsWindowListDone(u8 *p) { u32 i; int result=1; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) result &= MYSTERY_UTIL_IsMessageDone(((MysteryUtilWindowList *)p)->items[i]); return result; }

void MYSTERY_UTIL_ClearListWindow(u8 *p,u32 i) { void **items=((MysteryUtilWindowList *)p)->items; u8 *d=items[i]; BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)d)->bmpWin2),((MysteryUtilWindow *)d)->color&31); BMP_WIN_TransferChars(((MysteryUtilWindow *)items[i])->bmpWin2); }

void MYSTERY_UTIL_TransferWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_TransferWindowChars(((MysteryUtilWindowList *)p)->items[i]); }

/*
 * lever: heap is u16 in this function and the two callees receiving it.
 */
void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap)
{
    u32 i;
    int size=((MysteryUtilWindowList *)p)->count*sizeof(void *)+(sizeof(MysteryUtilBmpList)-sizeof(void *));
    char *out=GFL_HEAP_Alloc(heap,size,0,(char *)d_021DFBA0,0x42e);
    MI_CpuFill8(out,0,size);
    *(char * *)&((MysteryUtilBmpList *)out)->srcList=p;
    ((MysteryUtilBmpList *)out)->heapId=heap;
    for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) {
        void *win=BMP_WIN_GetBmp(((MysteryUtilWindow *)((MysteryUtilWindowList *)p)->items[i])->bmpWin2);
        u32 x=BMP_GetWidth(win);
        u32 y=BMP_GetHeight(win);
        u32 type=BMP_GetTileBytes(win);
        ((MysteryUtilBmpList *)out)->bmps[i]=BMP_Create(x/8,y/8,type,heap);
    }
    return out;
}

void MYSTERY_UTIL_DeleteBmpList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->count;i++) BMP_Delete(((MysteryUtilBmpList *)p)->bmps[i]); GFL_HEAP_Free(p); }

/*
 * extent: two bytes of zero alignment padding follow the return.
 */
void MYSTERY_UTIL_DrawBmpList(char *p,char *desc,void *dst)
{
    u32 i;
    MysteryUtilTextPos pos,out;
    void *text=STRBUF_Create(512,((MysteryUtilBmpList *)p)->heapId);
    for(i=0;i<((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->count;i++) {
        char *d=desc+i*24;
        if(((MysteryUtilMenuEntry *)d)->u0.flags) {
            BMP_Clear(((MysteryUtilBmpList *)p)->bmps[i],(u8)(((MysteryUtilMenuEntry *)d)->color&31));
            pos.x=((MysteryUtilMenuEntry *)d)->posX;
            pos.y=((MysteryUtilMenuEntry *)d)->posY;
            MYSTERY_UTIL_AlignText(((MysteryUtilMenuEntry *)d)->layoutMode,&pos,((MysteryUtilBmpList *)p)->bmps[i],text,((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->font,&out);
            if(((MysteryUtilMenuEntry *)d)->str.stringPtr) STRBUF_Copy((struct Strbuf *)text,((MysteryUtilMenuEntry *)d)->str.stringPtr);
            else MSGDATA_ReadString((struct MsgBank *)(((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->msgBank),((MysteryUtilMenuEntry *)d)->messageId,text);
            PRINTSYS_PrintQueColor(dst,(struct Bmp *)(((MysteryUtilBmpList *)p)->bmps[i]),(s16)out.x,(s16)out.y,(struct Strbuf *)text,(struct GfFont *)(((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->font),((MysteryUtilMenuEntry *)d)->color);
        }
    }
    GFL_HEAP_Free(text);
}

void MYSTERY_UTIL_CopyBmpList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)((u8 *)((MysteryUtilBmpList *)p)->srcList))->count;i++) { void *out=((MysteryUtilBmpList *)p)->bmps[i]; BMP_CopyPixels(out,BMP_WIN_GetBmp(((MysteryUtilWindow *)((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->items[i])->bmpWin2)); } }

/*
 * note (2026-10-05, lane T7, pengy's share): written bottom-up from the listing.
 *   heap is u16 (callees take it as u16). The input record is const, the
 *   output field f60 is a pointer typed like in->f3c: with a u32 f60 the second
 *   read of in->f3c was merged (4 B short). Struct copy t = d_021DF7C0 (4 records of
 *   24 B). The caller passes a 0x38 B input record and heap.
 */
struct MysteryUtilDetailWindow *MYSTERY_UTIL_CreateDetailWindow(const struct MysteryUtilDetailDef *in, u16 heap)
{
    struct MysteryUtilDetailTable t;
    struct MysteryUtilPt pt;
    u32 i;
    u8 c;
    u16 w;
    struct MysteryUtilDetailWindow *out = GFL_HEAP_Alloc(heap, sizeof(*out), 0, (char *)d_021DFBA0, 0x4e7);
    MI_CpuFill8(out, 0, sizeof(*out));
    out->count = in->count;
    out->actor = in->actor;
    out->windowPalette = in->windowPalette;
    out->windowPalette2 = in->windowPalette2;
    out->paletteBank = in->paletteBank;
    out->bgLayer = in->bgLayer;
    out->callback = in->callback;
    out->callbackArg = in->callbackArg;
    out->rowOffset = in->rowOffset;
    out->animSeq = in->animSeq;
    out->outIndex = in->outIndex;
    if (in->outIndex) {
        u32 v = *in->outIndex;
        out->index = v;
        out->index = (v > out->count - 1) ? out->count - 1 : v;
    }
    for (i = 0; i < out->count; i++)
        out->pal[i] = *(u16 *)(HW_BG_PLTT + in->paletteBank * 32 + (i + 10) * 2);
    out->blendColor = *(u16 *)(HW_BG_PLTT + 0x1E + in->paletteBank * 32);
    t = d_021DF7C0;
    for (i = 0; i < out->count; i++) {
        struct MysteryUtilDetailEntry *r = &t.r[i];
        r->b += (u8)in->rowOffset;
        r->a += (u8)in->colOffset;
        if (in->bank) r->h = MSGDATA_AllocString(in->bank, in->ids[i].id);
        else r->h = STRBUF_Clone(in->ids[i].str, (u16)((heap & 0x7FFF) | 0x8000));
    }
    c = in->windowPalette;
    w = in->bgLayer;
    out->windowList = MYSTERY_UTIL_CreateWindowList(0, (const char *)&t, out->count, w, c, in->printQueue, in->bank, in->font, heap);
    for (i = 0; i < out->count; i++)
        if (t.r[i].h) STRBUF_Delete(t.r[i].h);
    pt.x = d_021DF76C[out->index].x;
    pt.y = d_021DF770[out->index].x + in->rowOffset * 8;
    CLACT_AddActorSurfacePos(out->actor, (const struct ClactVec2 *)((const struct Vec2 *)(&pt)), 0);
    CLACT_SetActorDrawEnable(out->actor, 1);
    CLACT_SetActorAnimSeq(out->actor, out->animSeq);
    CLACT_SetActorAutoAnim(out->actor, 1);
    return out;
}

void MYSTERY_UTIL_DeleteDetailWindow(MysteryUtilDetailWindow *p) { if(((struct MysteryUtilDetailWindow *)p)->outIndex && ((struct MysteryUtilDetailWindow *)p)->index!=3) *((struct MysteryUtilDetailWindow *)p)->outIndex=((struct MysteryUtilDetailWindow *)p)->index; CLACT_SetActorDrawEnable(((struct MysteryUtilDetailWindow *)p)->actor,0); MYSTERY_UTIL_ClearWindowList((u8 *)((struct MysteryUtilDetailWindow *)p)->windowList); MYSTERY_UTIL_DeleteWindowList((u8 *)((struct MysteryUtilDetailWindow *)p)->windowList); BG_SYS_PushTile((u8)((struct MysteryUtilDetailWindow *)p)->bgLayer); GFL_HEAP_Free(p); }

/*
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 */
int MYSTERY_UTIL_SetVoice(MysteryUtilDetailWindow *p)
{
    u32 keys=KEY_GetTrg();
    u32 repeat=KEY_GetRepeat();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    MysteryUtilVec2 pos;
    if(repeat&64) {
        index=((MysteryUtilDetailWindow *)p)->index==0 ? ((MysteryUtilDetailWindow *)p)->count-1 : ((MysteryUtilDetailWindow *)p)->index-1;
        ((MysteryUtilDetailWindow *)p)->index=index;
        if(((MysteryUtilDetailWindow *)p)->count!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((MysteryUtilDetailWindow *)p)->count!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        ((MysteryUtilDetailWindow *)p)->index+=1;
        ((MysteryUtilDetailWindow *)p)->index=((MysteryUtilDetailWindow *)p)->index%((MysteryUtilDetailWindow *)p)->count;
        changed=1;
    } else if(keys&1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ((MysteryUtilDetailWindow *)p)->index;
    } else if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        if(((MysteryUtilDetailWindow *)p)->count==1) return -2;
        if(((MysteryUtilDetailWindow *)p)->index!=3) *((MysteryUtilDetailWindow *)p)->outIndex=((MysteryUtilDetailWindow *)p)->index;
        ((MysteryUtilDetailWindow *)p)->index=((MysteryUtilDetailWindow *)p)->count-1;
        return ((MysteryUtilDetailWindow *)p)->index;
    }
    if(changed) {
        pos.x=d_021DF76C[((MysteryUtilDetailWindow *)p)->index].x;
        pos.y=d_021DF76C[((MysteryUtilDetailWindow *)p)->index].y+((MysteryUtilDetailWindow *)p)->rowOffset*8;
        CLACT_AddActorSurfacePos(((MysteryUtilDetailWindow *)p)->actor,(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),0);
        if(((MysteryUtilDetailWindow *)p)->index==3) CLACT_SetActorAnimSeq(((MysteryUtilDetailWindow *)p)->actor,2);
        else CLACT_SetActorAnimSeq(((MysteryUtilDetailWindow *)p)->actor,((MysteryUtilDetailWindow *)p)->animSeq);
        if(((MysteryUtilDetailWindow *)p)->callback) ((MysteryUtilDetailWindow *)p)->callback(((MysteryUtilDetailWindow *)p)->callbackArg);
    }
    oldphase=((MysteryUtilDetailWindow *)p)->phase;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((MysteryUtilDetailWindow *)p)->phase=oldphase-0xfc00;
    else ((MysteryUtilDetailWindow *)p)->phase=phase;
    for(i=0;i<4;i++) {
        if(((MysteryUtilDetailWindow *)p)->target[i]!=((MysteryUtilDetailWindow *)p)->current[i] && ((MysteryUtilDetailWindow *)p)->phase>=0x7dff && ((MysteryUtilDetailWindow *)p)->phase<=0x81ff)
            ((MysteryUtilDetailWindow *)p)->current[i]=((MysteryUtilDetailWindow *)p)->target[i];
        if(((MysteryUtilDetailWindow *)p)->current[i])
            MYSTERY_UTIL_BlendPalette(15,&((MysteryUtilDetailWindow *)p)->palWork[i],((MysteryUtilDetailWindow *)p)->phase,(u8)(((MysteryUtilDetailWindow *)p)->paletteBank),(u8)(i+10),((MysteryUtilDetailWindow *)p)->pal[i],((MysteryUtilDetailWindow *)p)->blendColor);
    }
    return -1;
}

/*
 * Addresses are Black-image addresses.
 */
int MYSTERY_UTIL_Update(MysteryUtilDetailWindow *p)
{
    return MYSTERY_UTIL_IsWindowListDone(p->windowList);
}

void MYSTERY_UTIL_SetListValue(MysteryUtilDetailWindow *p,u32 i,u32 value)
{
    p->target[i]=value;
}

void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap) { u8 *p; p=GFL_HEAP_Alloc(heap,20,0,(char *)d_021DFBA0,0x61c); MI_CpuFill8(p,0,20); ((MysteryUtilTask *)p)->arg.ptr=a; MYSTERY_UTIL_SetTaskHandler((MysteryUtilTask *)p,b); return p; }

void MYSTERY_UTIL_DeleteTask(void *p) { GFL_HEAP_Free(p); }

void MYSTERY_UTIL_DispatchTask(char *p)
{
    if (((MysteryUtilTask *)p)->done == 0)
        ((MysteryUtilTask *)p)->handler(p, &((MysteryUtilTask *)p)->state, ((MysteryUtilTask *)p)->arg.ptr);
}

int MYSTERY_UTIL_IsTaskDone(MysteryUtilTask *p) { return p->done; }

void MYSTERY_UTIL_SetTaskHandler(MysteryUtilTask *p, void (*a)(void *, int *, void *)) { p->handler=a; p->state=0; }

void MYSTERY_UTIL_MarkTaskDone(MysteryUtilTask *p) { p->done=1; }

void MYSTERY_UTIL_SetTaskArg(MysteryUtilTask *p,u32 a) { p->value=a; }

void MYSTERY_UTIL_GetTaskArg(MysteryUtilTask *p) { p->state=p->value; }

/*
 * lever: a and b are u16; the descriptor input pointer is const.
 */
void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    MysteryUtilOamParam desc;
    char *out=GFL_HEAP_Alloc(heap,36,0,(char *)d_021DFBA0,0x6b1);
    MI_CpuFill8(out,0,36);
    ((MysteryUtilActorPair *)out)->printQueue=g;
    ((MysteryUtilActorPair *)out)->textBuf=STRBUF_Create(128,heap);
    ((MysteryUtilActorPair *)out)->bmp=BMP_Create(a,b,32,heap);
    MI_CpuFill8(&desc,0,sizeof(desc));
    desc.win=((MysteryUtilActorPair *)out)->bmp;
    desc.x=((MysteryUtilActorPairDef *)p)->x;
    desc.y=((MysteryUtilActorPairDef *)p)->y;
    desc.z=c;
    desc.a=((MysteryUtilActorPairDef *)p)->a;
    desc.c=e;
    desc.d=e;
    desc.b=((MysteryUtilActorPairDef *)p)->b;
    desc.pal=d;
    ((MysteryUtilActorPair *)out)->oam=BMP_OAM_Create((struct BmpOamSys *)f,(const struct BmpOamParam *)((const struct Param *)(&desc)));
    return out;
}

void MYSTERY_UTIL_DeleteActorPair(MysteryUtilActorPair *p) { BMP_OAM_Delete(((MysteryUtilActorPair *)p)->oam); BMP_Delete(((MysteryUtilActorPair *)p)->bmp); STRBUF_Delete(((MysteryUtilActorPair *)p)->textBuf); GFL_HEAP_Free(p); }

void MYSTERY_UTIL_UpdateActorPair(MysteryUtilActorPair *p)
{
    BMP_Clear((struct Bmp *)((MysteryUtilActorPair *)p)->bmp, (unsigned char)(((MysteryUtilActorPair *)p)->color & 0x1f));
    BMP_OAM_UploadChars(((MysteryUtilActorPair *)p)->oam);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_UTIL_SetActorPairText(MysteryUtilActorPair *p,struct MsgBank *a,int b,struct GfFont *c)
{
    int xy[2];
    BMP_Clear((struct Bmp *)((MysteryUtilActorPair *)p)->bmp,(u8)(((MysteryUtilActorPair *)p)->color&31));
    MSGDATA_ReadString(a,b,((MysteryUtilActorPair *)p)->textBuf);
    MYSTERY_UTIL_BuildPaletteRow(p,c,xy);
    PRINTSYS_PrintQueColor(((MysteryUtilActorPair *)p)->printQueue,(struct Bmp *)((MysteryUtilActorPair *)p)->bmp,(s16)xy[0],(s16)xy[1],(struct Strbuf *)(((MysteryUtilActorPair *)p)->textBuf),(struct GfFont *)c,((MysteryUtilActorPair *)p)->color);
    ((MysteryUtilActorPair *)p)->done=1;
}

void MYSTERY_UTIL_SetActorPairColor(MysteryUtilActorPair *p,int a) { ((MysteryUtilActorPair *)p)->color=a; }

void MYSTERY_UTIL_SetVec(MysteryUtilActorPair *p,u32 a,u32 b,u32 c) { p->posX=a; p->posY=b; p->mode=c; }

int MYSTERY_UTIL_IsMenuFinished(MysteryUtilActorPair *p) { if(((MysteryUtilActorPair *)p)->done) { if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)((MysteryUtilActorPair *)p)->printQueue,(void *)((MysteryUtilActorPair *)p)->bmp)==0) { BMP_OAM_UploadChars(((MysteryUtilActorPair *)p)->oam); ((MysteryUtilActorPair *)p)->done=0; } } if(((MysteryUtilActorPair *)p)->done==0) return 1; return 0; }

/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 */
void MYSTERY_UTIL_BuildPaletteRow(MysteryUtilActorPair *p,struct GfFont *a,int *out)
{
    int x,y;
    switch(((MysteryUtilActorPair *)p)->mode) {
    case 0:
        *(MysteryUtilTextPos *)out=*(MysteryUtilTextPos *)&((MysteryUtilActorPair *)p)->posX;
        break;
    case 1:
        x=BMP_GetWidth((struct Bmp *)((MysteryUtilActorPair *)p)->bmp)/2;
        y=BMP_GetHeight((struct Bmp *)((MysteryUtilActorPair *)p)->bmp)/2;
        x-=PRINTSYS_MeasureWidestLine(((MysteryUtilActorPair *)p)->textBuf,a,0)/2;
        y-=PRINTSYS_CountLines(((MysteryUtilActorPair *)p)->textBuf,a)/2;
        out[0]=x+((MysteryUtilActorPair *)p)->posX;
        out[1]=y+((MysteryUtilActorPair *)p)->posY;
        break;
    case 2:
        x=BMP_GetHeight((struct Bmp *)((MysteryUtilActorPair *)p)->bmp)/2;
        x-=PRINTSYS_CountLines(((MysteryUtilActorPair *)p)->textBuf,a)/2;
        out[0]=((MysteryUtilActorPair *)p)->posX;
        out[1]=x+((MysteryUtilActorPair *)p)->posY;
        break;
    }
}

static inline u16 blend(u16 c1,u16 c2,s16 factor) {
 u8 g1,r1,b1; int db,dr,dg;
 g1=(c1&0x3e0)>>5;
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}

/*
 * lever: twin ov104 021B89DC blend spelling, first argument passed through to NNS_GfdRegisterNewVramTransferTask.
 */
s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(c1,c2,(s16)((FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2));
 return NNS_GfdRegisterNewVramTransferTask(a,bank*32+index*2,p,2);
}

#pragma opt_loop_invariants off

/*
 * lever: int factor before the loop, narrowed to s16 at the inline blend argument
 * inside the loop, with #pragma opt_loop_invariants off: the IR keeps the
 * conversion in the loop (no div+convert fold to lsls #0xf) and the backend
 * hoists it, giving asrs #1; lsls #0x10; asrs #0x10. Counter initialised at its
 * declaration (int i=0; for(;...)) sets the i/index birth order (r6/r4).
 * note pass 2 2026-10-06 P2L51: closed from 147/200 (h5 pragma form 7/200, i/index swap fixed by i=0 at declaration).
 */
void MYSTERY_UTIL_BlendPaletteRange(u32 a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last) {
 int i=0;
 int factor=(FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2;
 for(;i<16;i++) p[i]=blend(first[i],last[i],factor);
 NNS_GfdRegisterNewVramTransferTask(a,bank*32,p,32);
}
