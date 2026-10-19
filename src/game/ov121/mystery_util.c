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
#include "mystery_util_shared_types.h"

/*
 * Text window drawn through the BMP_WIN subsystem (mystery_util.c). Allocated
 * 0x28 bytes by MYSTERY_UTIL_Create; shown and hidden through MYSTERY_UTIL_ShowMessage.
 */
typedef struct MysteryUtilWindow {
    void *bmpWin;           /* 0x00 BMP_WIN handle */
    unsigned char visible;  /* 0x04 set once the text has been queued */
    void *printOwner;       /* 0x08 owner passed to PRINTSYS_PrintQueColor */
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
    unsigned int printArg;    /* 0x04 */
    void *printStream;      /* 0x08 PRINTSYS_PrintStream handle */
    void *tcbl;             /* 0x0C TCBL text renderer */
    void *bmpWin;           /* 0x10 BMP_WIN handle */
    void *textBuf;          /* 0x14 STRBUF */
    unsigned short height;  /* 0x18 */
    unsigned short heapTag; /* 0x1A */
    void *bmpWin2;          /* 0x1C BMP_WIN handle used by PRINTSYS_PrintQue */
    unsigned char visible;  /* 0x20 */
    unsigned int elementSlot;   /* 0x24 */
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
    int printOwner;             /* 0x08 */
    int msgBank;             /* 0x0C */
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
    unsigned int printOwner;    /* 0x04 print owner */
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
    void (*handler)(char *, char *, unsigned int); /* 0x00 called with (task, task+8, arg) */
    unsigned int done;   /* 0x04 dispatch is skipped while nonzero */
    unsigned int state;  /* 0x08 */
    union { void *ptr; unsigned int value; } arg; /* 0x0C third argument passed to the handler */
    unsigned int value;  /* 0x10 */
} MysteryUtilTask;

/*
 * Sprite pair that owns a BMP, a STRBUF text buffer, a BMP_OAM grid and a
 * PRINTSYS queue. Allocated 0x24 bytes by MYSTERY_UTIL_CreateTaskEx and drawn
 * through MYSTERY_UTIL_SetActorPairText / MYSTERY_UTIL_IsMenuFinished.
 */
typedef struct MysteryUtilActorPair {
    void *bmp;              /* 0x00 BMP_Create handle */
    unsigned short color;   /* 0x04 palette slot, masked with 0x1F */
    unsigned char pad06[2];
    int done;               /* 0x08 set once text is queued */
    int posX;               /* 0x0C text x offset */
    int posY;               /* 0x10 text y offset */
    int mode;               /* 0x14 layout mode for MYSTERY_UTIL_AlignText */
    void *textBuf;          /* 0x18 STRBUF text */
    void *oam;              /* 0x1C BMP_OAM grid */
    void *printQueue;       /* 0x20 PRINTSYS queue */
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
 * Sound test selector driven by MYSTERY_UTIL_SetVoice. It owns a CLACT actor,
 * a selected index and count, and four current/target palette fade pairs at
 * 0x3C and 0x4C. The value at 0x3C doubles as the fade phase source.
 */
typedef struct MysteryUtilVoiceSelect {
    unsigned char pad00[4];
    void *actor;                /* 0x04 CLACT actor */
    unsigned int index;         /* 0x08 selected entry */
    unsigned int count;         /* 0x0C number of entries */
    unsigned char pad10[0x12];
    unsigned short blendColor;  /* 0x22 colour passed to MYSTERY_UTIL_BlendPalette */
    unsigned short phase;       /* 0x24 fade phase, advanced by 0x400 */
    unsigned char pad26[6];
    unsigned short paletteBank; /* 0x2C palette bank */
    signed short rowOffset;     /* 0x2E row offset in tiles */
    unsigned short animSeq;     /* 0x30 actor animation sequence */
    unsigned char pad32[2];
    void (*callback)(unsigned int); /* 0x34 optional change callback */
    unsigned int callbackArg;   /* 0x38 callback argument */
    unsigned int current[4];    /* 0x3C applied palette fade values */
    unsigned int target[4];     /* 0x4C requested palette fade values */
    unsigned int pad5C;         /* 0x5C */
    unsigned int *outIndex;     /* 0x60 written back on a selection change */
} MysteryUtilVoiceSelect;

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
    u32 menuWork;       /* 0x00 BMP_MENUWORK handle */
    u32 pad04[2];       /* 0x04 */
    u32 bmpWin;         /* 0x0C BMP_WIN handle */
    u16 itemCount;      /* 0x10 item count */
    u16 itemCountAlt;   /* 0x12 second item count word, set to the same value */
    u32 pad14[4];       /* 0x14 */
    u32 menuTable;      /* 0x24 item table passed to BMP_MENUWORK_AddMsgItem */
    u32 slotPointer;    /* 0x28 element slot pointer (menu object + 8) */
    u32 printOwner;     /* 0x2C */
    u32 messageTable;   /* 0x30 */
} MysteryUtilMenuListSrc;

struct MysteryUtilDetailDef {
    void *bank;
    u32 font;
    u32 printQueue;
    u32 *actor;
    u32 ids[4];
    u32 count;
    u16 bgLayer;
    u16 windowPalette;
    u16 windowPalette2;
    u16 paletteBank;
    s16 rowOffset;
    s16 colOffset;
    u16 animSeq;
    u16 pad32;
    u32 callback;
    u32 callbackArg;
    u32 *outIndex;
};

struct MysteryUtilDetailWindow {
    void *windowList;
    u32 actor;
    u32 index;
    u32 count;
    u16 pad10;
    u16 pal[5];
    u16 pad1c[3];
    u16 blendColor;
    u16 phase;
    u16 windowPalette;
    u16 bgLayer;
    u16 windowPalette2;
    u16 paletteBank;
    u16 rowOffset;
    u16 animSeq;
    u16 pad32;
    u32 callback;
    u32 callbackArg;
    u8 pad3c[0x24];
    u32 *outIndex;
};

struct MysteryUtilDetailEntry {
    u8 a;
    u8 b;
    u8 pad[6];
    void *h;
    u8 rest[12];
};

struct MysteryUtilDetailTable { struct MysteryUtilDetailEntry r[4]; };

struct Pt { s16 x; s16 y; };

/* BMP_OAM create parameter (MYSTERY_UTIL_CreateTaskEx). */
typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } MysteryUtilOamParam;

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, char *site, unsigned short tag);

extern void MI_CpuFill8(void *, int, u32);

extern u32 GFL_HEAP_Free(void *p);

extern void *STRBUF_Create(u32, u16);
struct BmpWin;

extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
struct Bmp;

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_Clear(struct Bmp *bmp, u8 value);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern void BG_SYS_PushTile(u32);

extern u32 BMP_WIN_Delete(struct BmpWin *win);
struct Strbuf;

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern void BMP_WIN_ClearScreen(struct BmpWin *win);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
struct GfFont;
struct PrintQueue;

extern void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

extern void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);

extern void BG_SYS_MarkTileDirty(unsigned);

extern u16 BMP_GetWidth(struct Bmp *bmp);

extern u16 BMP_GetHeight(struct Bmp *bmp);

extern u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing);

extern u32 PRINTSYS_CountLines(struct Strbuf *text, struct GfFont *font);
struct TcblSystem;

extern struct TcblSystem *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void PRINTSYS_CTRL_Init(void *p, u32 v);
struct TextPrinter;

extern void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer);
struct TimeIcon;

extern void TIME_ICON_Delete(struct TimeIcon *icon);
struct KeyCursor;

extern void APP_KEYCURSOR_Delete(struct KeyCursor *cursor);

extern void TCBL_Destroy(struct TcblSystem *tcbl);

extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, u32 commitMode);

extern void APP_KEYCURSOR_Update(struct KeyCursor *cursor, struct TextPrinter *printStream, void *win);
struct PrintStreamCtrl;

extern s32 PRINTSYS_CTRL_Update(struct PrintStreamCtrl *ctrl, struct TextPrinter *stream);

extern void TCBL_Main(struct TcblSystem *tcbl);
struct TcbList;

extern struct TcbList *GFL_USE_GetMainTaskList(void);

extern struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);

extern void PRINTSYS_PrintQue(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font);

extern void *APP_KEYCURSOR_CreateDefault(u32,u32,u32,u32);

extern signed char MSG_SPEED_GetWait(void);

extern void *PRINTSYS_PrintStream(void *,u32,u32,u32,u32,int, void *,u32,u16,u16);

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);

extern void *BMP_MENUWORK_Create(u32,u32);

extern void BMP_MENUWORK_AddMsgItem(void *table, u32 a, u32 b, u32 tag, u32 heap);
struct MenuTemplate;
struct BmpMenuList;

extern struct BmpMenuList *BMP_MENULIST_Create(struct MenuTemplate *menuTemplate, u16 scroll, u16 row, u32 heap);

extern void BMP_MENULIST_ResetCursorTile(struct BmpMenuList *menu, s32 heap);

extern void BMP_MENULIST_SetCancelDisabled(struct BmpMenuList *menu, u32 disabled);

extern void BMP_MENULIST_Delete(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow);

extern u32 BMP_MENUWORK_Delete(void *p);

extern s32 BMP_MENULIST_Main(struct BmpMenuList *menu);

extern u32 BMP_MENULIST_GetAttr(struct BmpMenuList *menu, u32 attr);

extern u8 BMP_GetTileBytes(struct Bmp *bmp);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_Delete(struct Bmp *bmp);

extern void BMP_CopyPixels(struct Bmp *src, struct Bmp *dst);

extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern struct Strbuf *STRBUF_Clone(struct Strbuf *src, u32 heapId);

extern void CLACT_AddActorSurfacePos(void *p, const void *delta, u32 which);
struct Actor;

extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);

extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 value);

extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);

extern u32 KEY_GetTrg(void);

extern u32 KEY_GetRepeat(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);


extern struct Grid *BMP_OAM_Create(void *sys, const void *param);
struct BmpOam;

extern void BMP_OAM_Delete(struct BmpOam *bmpOam);

extern void BMP_OAM_UploadChars(struct BmpOam *bmpOam);

extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap);

void MYSTERY_UTIL_DeleteWindow(u8 *p);

void MYSTERY_UTIL_ClearWindow(u8 *p);

void MYSTERY_UTIL_ShowMessage(u8 *p, struct MsgBank *a, int b, int c);

void MYSTERY_UTIL_ShowString(u8 *p, int a, int b);

void MYSTERY_UTIL_SetColor(u8 *p,unsigned v);

void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);

int MYSTERY_UTIL_IsMessageDone(u8 *p);

void MYSTERY_UTIL_TransferWindowChars(u8 *p);

void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,int a,MysteryUtilTextPos *out);

void MYSTERY_UTIL_AlignText(u32 mode, const MysteryUtilTextPos *in, const void *bitmap, void *obj, int a, MysteryUtilTextPos *out);

void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap);

void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, void *c, void *d, u16 heap);

void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);

void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);

void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);

void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode);

unsigned MYSTERY_UTIL_GetMenuState(u8 *p);

void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);

void MYSTERY_UTIL_ResetMenuWindow(u8 *p);

void *MYSTERY_UTIL_CreateMenu(const u8 *p,u16 heap);

void MYSTERY_UTIL_DeleteMenu(u8 *p);

int MYSTERY_UTIL_UpdateMenu(char *p);

void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,struct MsgBank *e,int f,u16 heap);

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

void MYSTERY_UTIL_DeleteDetailWindow(u8 *p);

int MYSTERY_UTIL_SetVoice(u8 *p);

int MYSTERY_UTIL_Update(void **p);

void MYSTERY_UTIL_SetListValue(u8 *p,u32 i,u32 value);

void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap);

void MYSTERY_UTIL_DeleteTask(void *p);

void MYSTERY_UTIL_DispatchTask(char *p);

int MYSTERY_UTIL_IsTaskDone(u32 *p);

void MYSTERY_UTIL_SetTaskHandler(u32 *p,u32 a);

void MYSTERY_UTIL_MarkTaskDone(u32 *p);

void MYSTERY_UTIL_SetTaskArg(u32 *p,u32 a);

void MYSTERY_UTIL_GetTaskArg(u32 *p);

void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);

void MYSTERY_UTIL_DeleteActorPair(u8 *p);

void MYSTERY_UTIL_UpdateActorPair(char *p);

void MYSTERY_UTIL_SetActorPairText(char *p,int a,int b,int c);

void MYSTERY_UTIL_SetActorPairColor(u8 *p,int a);

void MYSTERY_UTIL_SetVec(u32 *p,u32 a,u32 b,u32 c);

int MYSTERY_UTIL_IsMenuFinished(u8 *p);

void MYSTERY_UTIL_BuildPaletteRow(char *p,int a,int *out);

s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);

void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);

extern const char d_021DFBA0[];

extern const MysteryUtilMenuListSrc d_021DF78C;

extern const struct MysteryUtilDetailTable d_021DF7C0;

extern const MysteryUtilTextPos d_021DF76C[];

extern const MysteryUtilTextPos d_021DF770[];

extern const s16 FX_SinCosTable_[];

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap)
{
    u8 *p;
    void *q;
    p = GFL_HEAP_Alloc(heap, 0x28, 0, (char *)d_021DFBA0, 0x55);
    MI_CpuFill8(p, 0, 0x28);
    ((MysteryUtilWindow *)p)->printOwner = (void *)h;
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
void MYSTERY_UTIL_ShowMessage(u8 *p, struct MsgBank *a, int b, int c)
{
    MysteryUtilTextPos xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2), ((MysteryUtilWindow *)p)->color & 31);
    MSGDATA_ReadString(a, b, ((MysteryUtilWindow *)p)->textBuf);
    MYSTERY_UTIL_ComputeTextPosition(p, c, &xy);
    q = ((MysteryUtilWindow *)p)->printOwner;
    PRINTSYS_PrintQueColor(q, (struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin), (s16)xy.x, (s16)xy.y,
                 (struct Strbuf *)(((MysteryUtilWindow *)p)->textBuf), (struct GfFont *)c, ((MysteryUtilWindow *)p)->color);
    p[4] = 1;
}

/*
 * extent: two zero padding bytes at 0x021D9B26.
 */
void MYSTERY_UTIL_ShowString(u8 *p, int a, int b)
{
    MysteryUtilTextPos xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2), ((MysteryUtilWindow *)p)->color & 31);
    STRBUF_Copy((struct Strbuf *)(((MysteryUtilWindow *)p)->textBuf), (struct Strbuf *)a);
    MYSTERY_UTIL_ComputeTextPosition(p, b, &xy);
    q = ((MysteryUtilWindow *)p)->printOwner;
    PRINTSYS_PrintQueColor(q, (struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin), (s16)xy.x, (s16)xy.y,
                 (struct Strbuf *)(((MysteryUtilWindow *)p)->textBuf), (struct GfFont *)b, ((MysteryUtilWindow *)p)->color);
    p[4] = 1;
}

void MYSTERY_UTIL_SetColor(u8 *p,unsigned v) { ((MysteryUtilWindow *)p)->color=v; }

void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c)
{
    *(u32 *)(p + 0x18) = a;
    *(u32 *)(p + 0x1c) = b;
    *(u32 *)(p + 0x20) = c;
}

int MYSTERY_UTIL_IsMessageDone(u8 *p)
{
    u32 q;
    if (((MysteryUtilWindow *)p)->variant == 0) {
        q = (u32)((MysteryUtilWindow *)p)->printOwner;
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)q, (void *)((u32)BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilWindow *)p)->bmpWin))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilWindow *)p)->bmpWin);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(((MysteryUtilWindow *)p)->printOwner), (void *)((u32)BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilWindow *)p)->bmpWin))) == 0)
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
void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,int a,MysteryUtilTextPos *out) {
    void *bitmap=BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2);
    MYSTERY_UTIL_AlignText(((MysteryUtilWindow *)p)->mode,(const MysteryUtilTextPos *)(p+0x18),bitmap,((MysteryUtilWindow *)p)->textBuf,a,out);
}

/*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a MysteryUtilTextPos assignment.
 */
void MYSTERY_UTIL_AlignText(u32 mode, const MysteryUtilTextPos *in, const void *bitmap, void *obj, int a, MysteryUtilTextPos *out)
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
        x -= PRINTSYS_MeasureWidestLine(obj, (struct GfFont *)a, 0) / 2;
        y -= PRINTSYS_CountLines(obj, (void *)a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)BMP_GetHeight((struct Bmp *)bitmap) / 2;
        y -= PRINTSYS_CountLines(obj, (void *)a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = BMP_GetWidth((struct Bmp *)bitmap);
        x -= PRINTSYS_MeasureWidestLine(obj, (struct GfFont *)a, 0);
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
void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    MI_CpuFill8(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = STRBUF_Create(0x300, heap);
    q = (void *)BMP_WIN_Create((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    *(void **)(p + 0xc) = TCBL_Create(heap, heap, 1, 32);
    return p;
}

/*
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (GFL_HEAP_Alloc first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 MYSTERY_UTIL_CreateMenuWindow.
 */
void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = GFL_HEAP_Alloc(heap, 0x40, 0, (char *)d_021DFBA0, 0x1ae);
    MI_CpuFill8(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    PRINTSYS_CTRL_Init(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = STRBUF_Create(0x200, heap);
    q = (struct Descriptor *)BMP_WIN_Create((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor **)(p + 0x10))), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    BMP_WIN_TransferChars((struct BmpWin *)q);
    BMP_WIN_MakeScreen((struct BmpWin *)q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)q));
    *(struct Tcbl **)(p + 0xc) = (struct Tcbl *)TCBL_Create(heap, heap, 1, 32);
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
    u32 q;
    switch (((MysteryUtilMenuWindow *)p)->state) {
    case 2:
        q = ((MysteryUtilMenuWindow *)p)->elementSlot;
        if (p[0x20]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)q, (void *)((u32)BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2);
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = ((MysteryUtilMenuWindow *)p)->elementSlot;
        if (p[0x20]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)q, (void *)((u32)BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)((MysteryUtilMenuWindow *)p)->bmpWin2);
                p[0x20] = 0;
            }
        }
        ((MysteryUtilMenuWindow *)p)->result = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (((MysteryUtilMenuWindow *)p)->printStream) {
            if (((MysteryUtilMenuWindow *)p)->keyCursor)
                APP_KEYCURSOR_Update((struct KeyCursor *)(((MysteryUtilMenuWindow *)p)->keyCursor), (void *)(((MysteryUtilMenuWindow *)p)->printStream), (void *)(((MysteryUtilMenuWindow *)p)->bmpWin));
            if (PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)(p + 0x34), (void *)(((MysteryUtilMenuWindow *)p)->printStream)))
                ((MysteryUtilMenuWindow *)p)->result = 1;
        }
        break;
    case 3:
        break;
    }
    TCBL_Main((struct TcblSystem *)(((MysteryUtilMenuWindow *)p)->tcbl));
}

void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d)
{
    MSGDATA_ReadString((struct MsgBank *)b, c, ((MysteryUtilMenuWindow *)a)->textBuf);
    MYSTERY_UTIL_SetMenuMode(a, d);
}

void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode)
{
    u32 q;
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
        PRINTSYS_PrintQue((struct PrintQueue *)q,(struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin2),0,0,((MysteryUtilMenuWindow *)p)->textBuf,(struct GfFont *)(((MysteryUtilMenuWindow *)p)->printArg));
        p[0x20]=1;
        ((MysteryUtilMenuWindow *)p)->state=0;
        break;
    case 0:
        q=((MysteryUtilMenuWindow *)p)->elementSlot;
        PRINTSYS_PrintQue((struct PrintQueue *)q,(struct Bmp *)BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin2),0,0,((MysteryUtilMenuWindow *)p)->textBuf,(struct GfFont *)(((MysteryUtilMenuWindow *)p)->printArg));
        p[0x20]=1;
        ((MysteryUtilMenuWindow *)p)->state=0;
        break;
    case 1:
        PRINTSYS_CTRL_Init(p+0x34,2);
        ((MysteryUtilMenuWindow *)p)->keyCursor=APP_KEYCURSOR_CreateDefault(((MysteryUtilMenuWindow *)p)->height,1,0,((MysteryUtilMenuWindow *)p)->heapTag);
        ((MysteryUtilMenuWindow *)p)->printStream=PRINTSYS_PrintStream(((MysteryUtilMenuWindow *)p)->bmpWin,0,0,*(u32 *)&((MysteryUtilMenuWindow *)p)->textBuf,((MysteryUtilMenuWindow *)p)->printArg,MSG_SPEED_GetWait(),((MysteryUtilMenuWindow *)p)->tcbl,0,((MysteryUtilMenuWindow *)p)->heapTag,((MysteryUtilMenuWindow *)p)->height);
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

void MYSTERY_UTIL_ResetMenuWindow(u8 *p) { ((MysteryUtilMenuWindow *)p)->result=1; if(*(u8 * *)&((MysteryUtilMenuWindow *)p)->timeIcon) { TIME_ICON_Delete((struct TimeIcon *)(*(u8 * *)&((MysteryUtilMenuWindow *)p)->timeIcon)); *(u32 *)&((MysteryUtilMenuWindow *)p)->timeIcon=0; BMP_WIN_MakeScreen(((MysteryUtilMenuWindow *)p)->bmpWin); BG_SYS_PushTile(BMP_WIN_GetBgLayer(((MysteryUtilMenuWindow *)p)->bmpWin)); } }

/*
 * lever: const source parameter and the original heap stack argument to 0201F878.
 */
void *MYSTERY_UTIL_CreateMenu(const u8 *p,u16 heap)
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
    out[12]=0;
    ((MysteryUtilMenu *)out)->menuWork=BMP_MENUWORK_Create(((MysteryUtilMenuDef *)p)->count,heap);
    for(i=0;i<((MysteryUtilMenuDef *)p)->count;i++)
        BMP_MENUWORK_AddMsgItem(((MysteryUtilMenu *)out)->menuWork,((MysteryUtilMenuDef *)p)->menuTable,((MysteryUtilMenuDef *)p)->menuItems[i],i,(u16)heap);
    cfg=d_021DF78C;
    cfg.menuWork=*(u32 *)&((MysteryUtilMenu *)out)->menuWork;
    cfg.itemCount=((MysteryUtilMenuDef *)p)->count;
    cfg.itemCountAlt=((MysteryUtilMenuDef *)p)->count;
    cfg.bmpWin=*(u32 *)&((MysteryUtilMenu *)out)->bmpWin;
    cfg.menuTable=((MysteryUtilMenuDef *)p)->menuTable;
    cfg.slotPointer=(u32)(out+8);
    cfg.printOwner=((MysteryUtilMenuDef *)p)->printOwner;
    cfg.messageTable=((MysteryUtilMenuDef *)p)->messageTable;
    ((MysteryUtilMenu *)out)->menuList=BMP_MENULIST_Create((struct MenuTemplate *)(&cfg),0,0,heap);
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
    u32 q = ((MysteryUtilMenu *)p)->printOwner;
    int r;
    if (((MysteryUtilMenu *)p)->winFlag) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)q,(void *)((u32)BMP_WIN_GetBmp((struct BmpWin *)((MysteryUtilMenu *)p)->bmpWin2))) == 0) {
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
void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,struct MsgBank *e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=GFL_HEAP_Alloc(heap,size,0,(char *)d_021DFBA0,0x374);
    MI_CpuFill8(out,0,size);
    *(const char * *)&((MysteryUtilWindowList *)out)->desc=desc;
    ((MysteryUtilWindowList *)out)->count=n;
    ((MysteryUtilWindowList *)out)->printOwner=f;
    ((MysteryUtilWindowList *)out)->msgBank=(int)e;
    for(i=0;i<((MysteryUtilWindowList *)out)->count;i++) {
        const char *v=desc+i*24;
        MysteryUtilWindowSlot *slot=(MysteryUtilWindowSlot *)(out+i*4);
        void *q=MYSTERY_UTIL_CreateWindow((u32)a,b,((MysteryUtilMenuEntry *)v)->u0.bytes[0],((MysteryUtilMenuEntry *)v)->u0.bytes[1],((MysteryUtilMenuEntry *)v)->u0.bytes[2],((MysteryUtilMenuEntry *)v)->u0.bytes[3],c,d,heap);
        slot->window=q;
        MYSTERY_UTIL_SetPosition(q,((MysteryUtilMenuEntry *)v)->posX,((MysteryUtilMenuEntry *)v)->posY,((MysteryUtilMenuEntry *)v)->layoutMode);
        MYSTERY_UTIL_SetColor(slot->window,((MysteryUtilMenuEntry *)v)->color);
        if(((MysteryUtilMenuEntry *)v)->str.stringId) MYSTERY_UTIL_ShowString(slot->window,((MysteryUtilMenuEntry *)v)->str.stringId,((MysteryUtilWindowList *)out)->printOwner);
        else MYSTERY_UTIL_ShowMessage(slot->window,e,((MysteryUtilMenuEntry *)v)->messageId,((MysteryUtilWindowList *)out)->printOwner);
    }
    return out;
}

void MYSTERY_UTIL_DeleteWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_DeleteWindow(*(u8 **)(p+16+i*4)); GFL_HEAP_Free(p); }

void MYSTERY_UTIL_ClearWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_ClearWindow(*(u8 **)(p+16+i*4)); }

int MYSTERY_UTIL_IsWindowListDone(u8 *p) { u32 i; int result=1; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) result &= MYSTERY_UTIL_IsMessageDone(*(u8 **)(p+16+i*4)); return result; }

void MYSTERY_UTIL_ClearListWindow(u8 *p,u32 i) { u8 *d=*(u8 **)(p+16+i*4); BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)d)->bmpWin2),((MysteryUtilWindow *)d)->color&31); BMP_WIN_TransferChars(*(void **)(*(u8 **)(p+16+i*4)+12)); }

void MYSTERY_UTIL_TransferWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_TransferWindowChars(*(u8 **)(p+16+i*4)); }

/*
 * lever: heap is u16 in this function and the two callees receiving it.
 */
void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap)
{
    u32 i;
    int size=((MysteryUtilWindowList *)p)->count*4+8;
    char *out=GFL_HEAP_Alloc(heap,size,0,(char *)d_021DFBA0,0x42e);
    MI_CpuFill8(out,0,size);
    *(char * *)&((MysteryUtilBmpList *)out)->srcList=p;
    ((MysteryUtilBmpList *)out)->heapId=heap;
    for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) {
        void *win=BMP_WIN_GetBmp(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=BMP_GetWidth(win);
        u32 y=BMP_GetHeight(win);
        u32 type=BMP_GetTileBytes(win);
        *(void **)(out+i*4+8)=BMP_Create(x/8,y/8,type,heap);
    }
    return out;
}

void MYSTERY_UTIL_DeleteBmpList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->count;i++) BMP_Delete(*(void **)(p+8+i*4)); GFL_HEAP_Free(p); }

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
            BMP_Clear(*(void **)(p+i*4+8),(u8)(((MysteryUtilMenuEntry *)d)->color&31));
            pos.x=((MysteryUtilMenuEntry *)d)->posX;
            pos.y=((MysteryUtilMenuEntry *)d)->posY;
            MYSTERY_UTIL_AlignText(((MysteryUtilMenuEntry *)d)->layoutMode,&pos,*(void **)(p+i*4+8),text,((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->printOwner,&out);
            if(((MysteryUtilMenuEntry *)d)->str.stringId) STRBUF_Copy((struct Strbuf *)text,(struct Strbuf *)(((MysteryUtilMenuEntry *)d)->str.stringId));
            else MSGDATA_ReadString((struct MsgBank *)(((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->msgBank),((MysteryUtilMenuEntry *)d)->messageId,text);
            PRINTSYS_PrintQueColor(dst,(struct Bmp *)(*(void **)(p+i*4+8)),(s16)out.x,(s16)out.y,(struct Strbuf *)text,(struct GfFont *)(((MysteryUtilWindowList *)((MysteryUtilBmpList *)p)->srcList)->printOwner),((MysteryUtilMenuEntry *)d)->color);
        }
    }
    GFL_HEAP_Free(text);
}

void MYSTERY_UTIL_CopyBmpList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)((u8 *)((MysteryUtilBmpList *)p)->srcList))->count;i++) { void *out=*(void **)(p+8+i*4); BMP_CopyPixels(out,BMP_WIN_GetBmp(*(void **)(*(u8 **)((u8 *)((MysteryUtilBmpList *)p)->srcList+16+i*4)+12))); } }

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
    struct Pt pt;
    u32 i;
    u8 c;
    u16 w;
    struct MysteryUtilDetailWindow *out = GFL_HEAP_Alloc(heap, 0x64, 0, (char *)d_021DFBA0, 0x4e7);
    MI_CpuFill8(out, 0, 0x64);
    out->count = in->count;
    out->actor = (u32)in->actor;
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
        out->pal[i] = *(u16 *)(0x05000000 + in->paletteBank * 32 + (i + 10) * 2);
    out->blendColor = *(u16 *)(0x0500001E + in->paletteBank * 32);
    t = d_021DF7C0;
    for (i = 0; i < out->count; i++) {
        struct MysteryUtilDetailEntry *r = &t.r[i];
        r->b += (u8)in->rowOffset;
        r->a += (u8)in->colOffset;
        if (in->bank) r->h = MSGDATA_AllocString(in->bank, in->ids[i]);
        else r->h = STRBUF_Clone((struct Strbuf *)in->ids[i], (u16)((heap & 0x7FFF) | 0x8000));
    }
    c = in->windowPalette;
    w = in->bgLayer;
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    out->windowList = ((void *(*)())MYSTERY_UTIL_CreateWindowList)(0, (const char *)&t, out->count, w, c, in->printQueue, (u32)in->bank, in->font, heap);
    for (i = 0; i < out->count; i++)
        if (t.r[i].h) STRBUF_Delete(t.r[i].h);
    pt.x = d_021DF76C[out->index].x;
    pt.y = d_021DF770[out->index].x + in->rowOffset * 8;
    CLACT_AddActorSurfacePos((void *)out->actor, (const struct Vec2 *)(&pt), 0);
    CLACT_SetActorDrawEnable((void *)out->actor, 1);
    CLACT_SetActorAnimSeq((void *)out->actor, out->animSeq);
    CLACT_SetActorAutoAnim((void *)out->actor, 1);
    return out;
}

void MYSTERY_UTIL_DeleteDetailWindow(u8 *p) { if(((struct MysteryUtilDetailWindow *)p)->outIndex && ((struct MysteryUtilDetailWindow *)p)->index!=3) *((struct MysteryUtilDetailWindow *)p)->outIndex=((struct MysteryUtilDetailWindow *)p)->index; CLACT_SetActorDrawEnable((void *)((struct MysteryUtilDetailWindow *)p)->actor,0); MYSTERY_UTIL_ClearWindowList((u8 *)((struct MysteryUtilDetailWindow *)p)->windowList); MYSTERY_UTIL_DeleteWindowList((u8 *)((struct MysteryUtilDetailWindow *)p)->windowList); BG_SYS_PushTile((u8)((struct MysteryUtilDetailWindow *)p)->bgLayer); GFL_HEAP_Free(p); }

/*
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 */
int MYSTERY_UTIL_SetVoice(u8 *p)
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
        index=((MysteryUtilVoiceSelect *)p)->index==0 ? ((MysteryUtilVoiceSelect *)p)->count-1 : ((MysteryUtilVoiceSelect *)p)->index-1;
        ((MysteryUtilVoiceSelect *)p)->index=index;
        if(((MysteryUtilVoiceSelect *)p)->count!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((MysteryUtilVoiceSelect *)p)->count!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        ((MysteryUtilVoiceSelect *)p)->index+=1;
        ((MysteryUtilVoiceSelect *)p)->index=((MysteryUtilVoiceSelect *)p)->index%((MysteryUtilVoiceSelect *)p)->count;
        changed=1;
    } else if(keys&1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ((MysteryUtilVoiceSelect *)p)->index;
    } else if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        if(((MysteryUtilVoiceSelect *)p)->count==1) return -2;
        if(((MysteryUtilVoiceSelect *)p)->index!=3) *((MysteryUtilVoiceSelect *)p)->outIndex=((MysteryUtilVoiceSelect *)p)->index;
        ((MysteryUtilVoiceSelect *)p)->index=((MysteryUtilVoiceSelect *)p)->count-1;
        return ((MysteryUtilVoiceSelect *)p)->index;
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+((MysteryUtilVoiceSelect *)p)->rowOffset*8;
        CLACT_AddActorSurfacePos(((MysteryUtilVoiceSelect *)p)->actor,(const struct Vec2 *)(&pos),0);
        if(((MysteryUtilVoiceSelect *)p)->index==3) CLACT_SetActorAnimSeq(((MysteryUtilVoiceSelect *)p)->actor,2);
        else CLACT_SetActorAnimSeq(((MysteryUtilVoiceSelect *)p)->actor,((MysteryUtilVoiceSelect *)p)->animSeq);
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(((MysteryUtilVoiceSelect *)p)->callbackArg);
    }
    oldphase=((MysteryUtilVoiceSelect *)p)->phase;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((MysteryUtilVoiceSelect *)p)->phase=oldphase-0xfc00;
    else ((MysteryUtilVoiceSelect *)p)->phase=phase;
    for(i=0;i<4;i++) {
        if(((MysteryUtilVoiceSelect *)p)->target[i]!=((MysteryUtilVoiceSelect *)p)->current[i] && ((MysteryUtilVoiceSelect *)p)->phase>=0x7dff && ((MysteryUtilVoiceSelect *)p)->phase<=0x81ff)
            ((MysteryUtilVoiceSelect *)p)->current[i]=((MysteryUtilVoiceSelect *)p)->target[i];
        if(((MysteryUtilVoiceSelect *)p)->current[i])
            MYSTERY_UTIL_BlendPalette((int)((void *)15),(u16 *)(p+0x1a+i*2),((MysteryUtilVoiceSelect *)p)->phase,(u8)(((MysteryUtilVoiceSelect *)p)->paletteBank),(u8)(i+10),*(u16 *)(p+0x12+i*2),((MysteryUtilVoiceSelect *)p)->blendColor);
    }
    return -1;
}

/*
 * Addresses are Black-image addresses.
 */
int MYSTERY_UTIL_Update(void **p)
{
    return MYSTERY_UTIL_IsWindowListDone(*p);
}

void MYSTERY_UTIL_SetListValue(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}

void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap) { u8 *p; p=GFL_HEAP_Alloc(heap,20,0,(char *)d_021DFBA0,0x61c); MI_CpuFill8(p,0,20); ((MysteryUtilTask *)p)->arg.ptr=a; MYSTERY_UTIL_SetTaskHandler((u32 *)p,(u32)b); return p; }

void MYSTERY_UTIL_DeleteTask(void *p) { GFL_HEAP_Free(p); }

void MYSTERY_UTIL_DispatchTask(char *p)
{
    if (((MysteryUtilTask *)p)->done == 0)
        ((MysteryUtilTask *)p)->handler(p, p + 8, ((MysteryUtilTask *)p)->arg.value);
}

int MYSTERY_UTIL_IsTaskDone(u32 *p) { return p[1]; }

void MYSTERY_UTIL_SetTaskHandler(u32 *p,u32 a) { p[0]=a; p[2]=0; }

void MYSTERY_UTIL_MarkTaskDone(u32 *p) { p[1]=1; }

void MYSTERY_UTIL_SetTaskArg(u32 *p,u32 a) { p[4]=a; }

void MYSTERY_UTIL_GetTaskArg(u32 *p) { p[2]=p[4]; }

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
    MI_CpuFill8(&desc,0,24);
    desc.win=((MysteryUtilActorPair *)out)->bmp;
    desc.x=((MysteryUtilActorPairDef *)p)->x;
    desc.y=((MysteryUtilActorPairDef *)p)->y;
    desc.z=c;
    desc.a=((MysteryUtilActorPairDef *)p)->a;
    desc.c=e;
    desc.d=e;
    desc.b=((MysteryUtilActorPairDef *)p)->b;
    desc.pal=d;
    ((MysteryUtilActorPair *)out)->oam=BMP_OAM_Create(f,(const struct Param *)(&desc));
    return out;
}

void MYSTERY_UTIL_DeleteActorPair(u8 *p) { BMP_OAM_Delete(((MysteryUtilActorPair *)p)->oam); BMP_Delete(((MysteryUtilActorPair *)p)->bmp); STRBUF_Delete(((MysteryUtilActorPair *)p)->textBuf); GFL_HEAP_Free(p); }

void MYSTERY_UTIL_UpdateActorPair(char *p)
{
    BMP_Clear((struct Bmp *)((MysteryUtilActorPair *)p)->bmp, (unsigned char)(((MysteryUtilActorPair *)p)->color & 0x1f));
    BMP_OAM_UploadChars(((MysteryUtilActorPair *)p)->oam);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_UTIL_SetActorPairText(char *p,int a,int b,int c)
{
    int xy[2];
    BMP_Clear((struct Bmp *)((MysteryUtilActorPair *)p)->bmp,(u8)(((MysteryUtilActorPair *)p)->color&31));
    MSGDATA_ReadString((struct MsgBank *)a,b,((MysteryUtilActorPair *)p)->textBuf);
    MYSTERY_UTIL_BuildPaletteRow(p,c,xy);
    PRINTSYS_PrintQueColor(((MysteryUtilActorPair *)p)->printQueue,(struct Bmp *)((MysteryUtilActorPair *)p)->bmp,(s16)xy[0],(s16)xy[1],(struct Strbuf *)(((MysteryUtilActorPair *)p)->textBuf),(struct GfFont *)c,((MysteryUtilActorPair *)p)->color);
    ((MysteryUtilActorPair *)p)->done=1;
}

void MYSTERY_UTIL_SetActorPairColor(u8 *p,int a) { ((MysteryUtilActorPair *)p)->color=a; }

void MYSTERY_UTIL_SetVec(u32 *p,u32 a,u32 b,u32 c) { p[3]=a; p[4]=b; p[5]=c; }

int MYSTERY_UTIL_IsMenuFinished(u8 *p) { if(((MysteryUtilActorPair *)p)->done) { if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)((MysteryUtilActorPair *)p)->printQueue,(void *)((MysteryUtilActorPair *)p)->bmp)==0) { BMP_OAM_UploadChars(((MysteryUtilActorPair *)p)->oam); ((MysteryUtilActorPair *)p)->done=0; } } if(((MysteryUtilActorPair *)p)->done==0) return 1; return 0; }

/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 */
void MYSTERY_UTIL_BuildPaletteRow(char *p,int a,int *out)
{
    int x,y;
    switch(((MysteryUtilActorPair *)p)->mode) {
    case 0:
        *(MysteryUtilTextPos *)out=*(MysteryUtilTextPos *)(p+12);
        break;
    case 1:
        x=BMP_GetWidth((struct Bmp *)((MysteryUtilActorPair *)p)->bmp)/2;
        y=BMP_GetHeight((struct Bmp *)((MysteryUtilActorPair *)p)->bmp)/2;
        x-=PRINTSYS_MeasureWidestLine(((MysteryUtilActorPair *)p)->textBuf,(struct GfFont *)a,0)/2;
        y-=PRINTSYS_CountLines(((MysteryUtilActorPair *)p)->textBuf,(void *)a)/2;
        out[0]=x+((MysteryUtilActorPair *)p)->posX;
        out[1]=y+((MysteryUtilActorPair *)p)->posY;
        break;
    case 2:
        x=BMP_GetHeight((struct Bmp *)((MysteryUtilActorPair *)p)->bmp)/2;
        x-=PRINTSYS_CountLines(((MysteryUtilActorPair *)p)->textBuf,(void *)a)/2;
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
 return NNS_GfdRegisterNewVramTransferTask((void *)a,bank*32+index*2,(u32)p,2);
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
void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last) {
 int i=0;
 int factor=(FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2;
 for(;i<16;i++) p[i]=blend(first[i],last[i],factor);
 NNS_GfdRegisterNewVramTransferTask(a,bank*32,(u32)p,32);
}
