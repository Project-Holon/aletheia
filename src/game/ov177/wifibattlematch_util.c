/*
 * file:     wifibattlematch_util.c
 * unit:     yes
 * function: WIFIBATTLEMATCH_UTIL_Create, WIFIBATTLEMATCH_UTIL_Delete, WIFIBATTLEMATCH_UTIL_Main, WIFIBATTLEMATCH_UTIL_PrintMessage, WIFIBATTLEMATCH_UTIL_SetMode, WIFIBATTLEMATCH_UTIL_GetBusy, WIFIBATTLEMATCH_UTIL_StopTimeIcon, WIFIBATTLEMATCH_UTIL_ClearBmp, WIFIBATTLEMATCH_UTIL_ShowMenu, WIFIBATTLEMATCH_UTIL_CreateMenu, WIFIBATTLEMATCH_UTIL_DeleteMenu, WIFIBATTLEMATCH_UTIL_UpdateMenu, WIFIBATTLEMATCH_UTIL_CreateCallback, WIFIBATTLEMATCH_UTIL_DeleteCallback, WIFIBATTLEMATCH_UTIL_InvokeCallback, WIFIBATTLEMATCH_UTIL_IsCallbackNull, WIFIBATTLEMATCH_UTIL_SetCallback, WIFIBATTLEMATCH_UTIL_ClearCallback, WIFIBATTLEMATCH_UTIL_SetRequest, WIFIBATTLEMATCH_UTIL_CommitRequest, WIFIBATTLEMATCH_UTIL_SetSaveState
 * address:  0x021E8568
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifibattlematch_view.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   TCBL_Create  0x0203101C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   d_021E8DD4     0x021E8DD4  data
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   TCBL_Main 0x020310C4 arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   d_021E8DEC     0x021E8DEC  data
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   BMP_MENULIST_ResetCursorTile 0x02020CF8 thumb
 *   BMP_MENULIST_SetCancelDisabled 0x02020D10 thumb
 *   d_021E8D68 0x021E8D68 data a4
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   BMP_MENULIST_Main  0x020200CC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   RECORD_GetFromSave  0x02008C58  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 */
#include "wifibattlematch_graphic_shared_types.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define BMP_MENUWORK_Create BMP_MENUWORK_Create_header
#endif
#include "../arm9/bmp_menuwork.h"
#ifdef __MWERKS__
#undef BMP_MENUWORK_Create
extern BmpMenuWork * BMP_MENUWORK_Create(u32, u16);
#endif
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define BMP_MENULIST_Create BMP_MENULIST_Create_header
#endif
#include "../arm9/bmp_menulist.h"
#ifdef __MWERKS__
#undef BMP_MENULIST_Create
extern struct BmpMenuList * BMP_MENULIST_Create(struct BmpMenuListTemplate *, u16, u16, u16);
#endif
#include "wifibattlematch_view_shared_types.h"

struct Tcbl;

struct Rec3;

struct S02031140;

struct Ctx;

struct Blk;

struct Big;

struct RecordBlock;

struct PrintSys;

struct Descriptor;

struct CharBuf;

struct MsgBank;

struct Obj;

struct U16Vec;

struct Cfg;

struct WifibattlematchViewSlot;

/*
 * Work object for one wifibattlematch message window.  WIFIBATTLEMATCH_UTIL_Create allocates
 * it as GFL_HEAP_Alloc(heap, 0x40, 0, ...) and clears 0x40 bytes.
 */
typedef struct WifibattlematchUtilWork {
    int              pad00;           /* 0x00 never read */
    int              printArg;        /* 0x04 last argument to PRINTSYS_PrintQue */
    void            *printStream;     /* 0x08 PRINTSYS_PrintStream handle */
    void            *tcbl;            /* 0x0C TCBL handle */
    void            *timeIcon;        /* 0x10 TIME_ICON handle */
    int              win;             /* 0x14 BMP_WIN handle */
    struct U16Vec   *strbuf;          /* 0x18 STRBUF handle */
    u16              bgSlot;          /* 0x1C background slot (0xF) */
    u16              heapId;          /* 0x1E heap id */
    int              winBmp;          /* 0x20 BMP_WIN handle the text prints into */
    u8               shown;           /* 0x24 pending BMP transfer flag */
    u8               pad25[3];
    struct PrintSys *printQue;        /* 0x28 PRINTSYS_QUE handle */
    int              state;           /* 0x2C window state (0..3) */
    int              busy;            /* 0x30 set while waiting for input */
    int              keyCursor;       /* 0x34 APP_KEYCURSOR handle */
    u8               ctrlKeyReleased; /* 0x38 PRINTSYS_CTRL: key released once */
    u8               pad39[3];
    u32              ctrlInputType;   /* 0x3C PRINTSYS_CTRL: accepted input types */
} WifibattlematchUtilWork;

#include "wifibattlematch_menu_types.h"

/*
 * Menu work object created by WIFIBATTLEMATCH_UTIL_CreateMenu (0x1C bytes).
 */
typedef struct WifibattlematchMenu {
    void            *win;      /* 0x00 BMP_WIN handle */
    u32              printQue; /* 0x04 PRINTSYS_QUE handle */
    void            *win2;     /* 0x08 BMP_WIN handle the list draws into */
    u8               flag;     /* 0x0C pending BMP transfer flag */
    u8               pad0d[3];
    void            *menu;     /* 0x10 BMP_MENULIST handle */
    void            *entries;  /* 0x14 BMP_MENUWORK handle */
    u32              counter;  /* 0x18 */
} WifibattlematchMenu;

/*
 * Task callback record created by WIFIBATTLEMATCH_UTIL_CreateCallback (0x10 bytes).
 */
typedef struct WifibattlematchCallback {
    void (*fn)(void *self, int *state, int arg); /* 0x00 next task */
    int   state;                                 /* 0x04 */
    int   owner;                                 /* 0x08 */
    int   request;                               /* 0x0C */
} WifibattlematchCallback;

/* BMP_MENULIST_Create config; only a few words and two halfwords are set. */
typedef struct { u32 word[13]; } WifibattlematchMenuConfig;

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"

struct Strbuf;

#include "../arm9/strbuf.h"
struct BmpWin;
struct Bmp;

#include "../arm9/bmp_win.h"
struct GfFont;
struct PrintQueue;



#include "../arm9/bg_sys.h"

typedef short s16_p07;
#include "../arm9/bmp.h"





#include "../arm9/msgdata.h"




struct TcblSystem;

#include "../arm9/tcbl.h"

extern void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int commitMode, unsigned short tileBase, unsigned int palette);
struct TextPrinter;

struct TimeIcon;

#include "../arm9/time_icon.h"
struct KeyCursor;



extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, unsigned int commitMode);



struct PrintStreamCtrl;



struct TcbList;

#include "../arm9/gfl_use.h"


#include "../arm9/gf_panic.h"
#include "../arm9/game_data.h"



#include "../arm9/msg_speed.h"


struct BmpMenuWork;

extern void BMP_MENUWORK_AddMsgItem(struct BmpMenuWork *items, struct MsgBank *bank, u32 msgId, u32 param, u32 heapId);

struct BmpMenuList;

extern void BMP_MENULIST_ResetCursorTile(struct BmpMenuList *menu, int heap);

extern void BMP_MENULIST_SetCancelDisabled(struct BmpMenuList *menu, unsigned int disabled);

extern void BMP_MENULIST_Delete(struct BmpMenuList *menu, unsigned short *outScroll, unsigned short *outRow);

extern u32 BMP_MENUWORK_Delete(void *p);

extern s32 BMP_MENULIST_Main(struct BmpMenuList *menu);
struct GameData;
struct SaveControl;
struct RecordBlock;

                              

#include "../arm9/record.h"


#include "../arm9/printsys.h"
#include "../arm9/app_keycursor.h"
WifibattlematchUtilWork *WIFIBATTLEMATCH_UTIL_Create(int layer, int winType, unsigned short winWidth, unsigned short winHeight, int unused, int printArg, unsigned short heap);

void WIFIBATTLEMATCH_UTIL_Delete(WifibattlematchUtilWork *p);

void WIFIBATTLEMATCH_UTIL_Main(WifibattlematchUtilWork *p);

void WIFIBATTLEMATCH_UTIL_PrintMessage(WifibattlematchUtilWork *p, void *a, int b, int c);

void WIFIBATTLEMATCH_UTIL_SetMode(WifibattlematchUtilWork *p, int mode);

int WIFIBATTLEMATCH_UTIL_GetBusy(const WifibattlematchUtilWork *p);

void WIFIBATTLEMATCH_UTIL_StopTimeIcon(WifibattlematchUtilWork *p);

void WIFIBATTLEMATCH_UTIL_ClearBmp(WifibattlematchUtilWork *p);

WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_ShowMenu(const WifibattlematchMenuDesc *p, u16 a);

WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_CreateMenu(const WifibattlematchMenuDesc *p,u8 x,u8 y,u8 width,int height,u16 heap);

void WIFIBATTLEMATCH_UTIL_DeleteMenu(WifibattlematchMenu *p);

int WIFIBATTLEMATCH_UTIL_UpdateMenu(WifibattlematchMenu *p);

WifibattlematchCallback *WIFIBATTLEMATCH_UTIL_CreateCallback(int a, int b, int c);

void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p);

void WIFIBATTLEMATCH_UTIL_InvokeCallback(WifibattlematchCallback *p);

int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p);

void WIFIBATTLEMATCH_UTIL_SetCallback(WifibattlematchCallback *p, int v);

void WIFIBATTLEMATCH_UTIL_ClearCallback(void *a);

void WIFIBATTLEMATCH_UTIL_SetRequest(s32 *sys, u32 v);

void WIFIBATTLEMATCH_UTIL_CommitRequest(u32 sys);

void WIFIBATTLEMATCH_UTIL_SetSaveState(int a, int b);

extern const char d_021E8DD4[];

extern unsigned char d_021E8DEC[];

extern const WifibattlematchMenuConfig d_021E8D68;

/*
 * note 2026-10-02: only prologue scheduling (orig spills r2,r3 before ldr r5 heap, mine
 *   after) and tail ldr r3/str order differ (10 lines). Tried u8 param, local copies,
 *   decl order, init-at-decl, heap types.
 *
 * note 2026-10-05: re-checked the listing: c and d are spilled (str r2,[sp,#0xc]; str r3,[sp,#0x10]) BEFORE
 * the heap load (ldr r5,[sp,#0x30]); ours spills r3 then r2 after the heap load, and loads r3 for the last call
 * above the w->fc store (orig after). Both are scheduler order only, 20 bytes. No source form tried this
 * round changed it (arguments are used in place, no stand-in casts). Still DIFF.
 *
 * note 2026-10-05 (wD9 lane15): 20 -> 8 bytes. `unsigned short c` (docs/idioms/a-narrow-spilled-parameter-keeps-
 *   its-reload-below-a-store.md) fixes the tail: the reload of c now stays below the w->fc store. Left: the
 *   prologue, original `str r2; str r3; ldr r5,[sp,#0x30]; adds r6`, ours `ldr r5; adds r6; str r2; str r3`.
 *   Tried: a struct-by-value (c, d) pair (pushes r0-r3, worse), K&R definition (same 20), d as u16/u8/s16/s8
 *   (10, d's store then drifts below adds r6), a and b as u16 (no change), heap u8/u16 (186, original loads it
 *   as a word), the callee third parameter u16 as in other matched callers (worse). c as u8 is 33 (the original
 *   truncates c at the call).
 *
 * note 2026-10-05 (wD9r lane17, pengy draft): still 8 bytes, prologue only. Hypothesis: c and d are address-taken
 *   so their stores block the heap load. `*&c`/`*&d` at the call: folded, 8. `*(int *)&c` with int c: 38 (homes
 *   r0-r3 in the caller area, push {r0-r3}), so the original does not take their address. Also tried: a local
 *   copy of heap (8), local copies of c and d at the top (8), heap as unsigned int (145).
 * note 2026-10-05 (wD9r lane31): still 8 bytes, prologue only. New tries: c and d as one 64-bit parameter
 *   (20), e/f/heap as a struct passed by value on the stack (8), c and d copied into an `int lc[2]` array local
 *   (8, scalarised), a or b as u8 (113/119), e as u16/u8 (8), f as u16 (158), c as short/signed char (8),
 *   d unsigned int (8), callee 4th parameter u8 with plain c (8; with d u16: 10/12), a..d all u16 (10),
 *   c,d,e u16 (10). With c and d both u16 the c store goes to the front (str r2 matches) but d's store and the
 *   heap load drift down (str r2; adds r6; str r3; movs; adds r7; ldr r5). Left DIFF.
 * note 2026-10-05 (wD9r lane39): still 8 bytes, prologue only. New tries: d as void * / u16 * with the callee
 *   third parameter a pointer (8), an extra unused 8th stack parameter (8), void * return type (8), const heap
 *   (145, heap is reloaded from the stack at each use). Left DIFF.
 * note 2026-10-05 (wD9r lane58): still 8 bytes, prologue only. New tries: the allocation and clear in a
 *   static inline Alloc(heap) helper (8, the inlined copy of heap is propagated), the last call in a static
 *   inline Frame(w, d, c) helper (27). Checked for a matched twin (callers of BMP_MENUWORK_DrawWindow and BMP_WIN_Create
 *   in src/matched): none has this shape. Left DIFF.
 * note 2026-10-05 (wD9r lane68): EXACT. Fix: heap is a u16 parameter (it is stored with strh to f1e) with the
 *   house callee prototypes (GFL_HEAP_Alloc u32 heap, u16 tag; STRBUF_Create u32, u32; TCBL_Create u32 heap,
 *   u16 tag, so heap goes to both), and d is a u16 parameter passed to the u16 third parameter of
 *   BMP_MENUWORK_DrawWindow. The u16 heap keeps the word ldr and moves it below the c home store (8 -> 6), and the u16 d
 *   moves its home store to the front (6 -> 0). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 */
WifibattlematchUtilWork *WIFIBATTLEMATCH_UTIL_Create(int layer, int winType, unsigned short winWidth, unsigned short winHeight, int unused, int printArg, unsigned short heap)
{
    WifibattlematchUtilWork *w;
    int h;

    w = GFL_HEAP_Alloc(heap, 0x40, 0, d_021E8DD4, 0x5e);
    MI_CpuFill8(w, 0, 0x40);
    w->bgSlot = 0xf;
    w->printArg = printArg;
    w->printQue = (struct PrintSys *)PRINTSYS_QUE_Create((unsigned int)heap);
    w->state = 3;
    w->heapId = heap;
    w->strbuf = (struct U16Vec *)STRBUF_Create(0x300, heap);
    w->win = (int)BMP_WIN_Create((unsigned char)layer, 1, 0x13, 0x1e, 4, (unsigned char)winType, 1);
    w->winBmp = w->win;
    w->shown = 0;
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)w->win), (unsigned char)w->bgSlot);
    h = w->win;
    BMP_WIN_TransferChars((struct BmpWin *)h);
    BMP_WIN_MakeScreen((struct BmpWin *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    w->tcbl = TCBL_Create(heap, heap, 1, 0x20);
    BMP_MENUWORK_DrawWindow((void *)w->win, 0, winHeight, (unsigned char)winWidth);
    return w;
}

void WIFIBATTLEMATCH_UTIL_Delete(WifibattlematchUtilWork *p)
{
    if (p->printStream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)p->printStream);
        p->printStream = 0;
    }
    if (*(unsigned char * *)&p->timeIcon != 0) {
        TIME_ICON_Delete((struct TimeIcon *)(*(unsigned char * *)&p->timeIcon));
        p->timeIcon = 0;
    }
    if (p->keyCursor != 0)
        APP_KEYCURSOR_Delete((struct KeyCursor *)p->keyCursor);
    TCBL_Destroy((struct TcblSystem *)p->tcbl);
    BMP_MENUWORK_DrawWindowBorder((void *)p->win, 0);
    BMP_WIN_Delete((struct BmpWin *)p->win);
    STRBUF_Delete((struct Strbuf *)p->strbuf);
    PRINTSYS_QUE_Delete((struct PrintQueue *)p->printQue);
    GFL_HEAP_Free(p);
}

void WIFIBATTLEMATCH_UTIL_Main(WifibattlematchUtilWork *p)
{
 void *printQue;
 PRINTSYS_QUE_Main((struct PrintQueue *)p->printQue);
 switch(p->state) {
 case 2:
 printQue=p->printQue;
 if(p->shown!=0 && PRINTSYS_QUE_IsExistTarget(printQue,(void *)((unsigned)BMP_WIN_GetBmp((struct BmpWin *)p->winBmp)))==0) {
 BMP_WIN_TransferChars((struct BmpWin *)p->winBmp);p->shown=0;
 }
 break;
 case 0:
 printQue=p->printQue;
 if(p->shown!=0 && PRINTSYS_QUE_IsExistTarget(printQue,(void *)((unsigned)BMP_WIN_GetBmp((struct BmpWin *)p->winBmp)))==0) {
 BMP_WIN_TransferChars((struct BmpWin *)p->winBmp);p->shown=0;
 }
 p->busy=p->shown==0;
 break;
 case 1:
 if(p->printStream!=0) {
 if(p->keyCursor!=0)APP_KEYCURSOR_Update((struct KeyCursor *)p->keyCursor,p->printStream,(void *)p->win);
 if(PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)&p->ctrlKeyReleased,p->printStream)!=0)p->busy=1;
 }
 break;
 case 3:break;
 }
 TCBL_Main((struct TcblSystem *)p->tcbl);
}

void WIFIBATTLEMATCH_UTIL_PrintMessage(WifibattlematchUtilWork *p, void *msgBank, int msgIndex, int mode)
{
    MSGDATA_ReadString((struct MsgBank *)msgBank, msgIndex, (void *)p->strbuf);
    WIFIBATTLEMATCH_UTIL_SetMode(p, mode);
}

/*
 * note 2026-10-02: all code matches except the case 2 arm: original ends it with an
 *   explicit `b` onto the immediately following case 0 block (+2 bytes, 238 vs 240).
 *   Fallthrough case 2 -> case 0 emits no such branch. Tried default arm, goto, guarded if.
 *
 * note 2026-10-05: orig layout is dispatch (cmp 0 beq A; cmp 1 beq B; cmp 2 bne end), case 2 block,
 * `b .+2` (0xE7FF), case 0 block A, case 1 block B, join store. Tried: if/else chain with `goto L0` into A (240 B
 * but A laid out first, wrong order); switch with case 2 first and `goto L0` before `case 0: L0:` (the
 * goto to the next label is deleted, 236 B); case 0 body under `if (mode == 0 || mode == 2)` (244 B).
 * None emits the branch to the next instruction. Still DIFF (residue is the 2-byte branch plus shifted offsets).
 *
 * note 2026-10-05 (wD9 lane20): EXACT. Case 2 repeats the whole case 0 body and its own break; cross-jumping
 *   then replaces that copy with a branch to the case 0 block, which is laid out next (the `b .+2`).
 */
void WIFIBATTLEMATCH_UTIL_SetMode(WifibattlematchUtilWork *p, int mode)
{
    int printQue;

    PRINTSYS_QUE_Clear((struct PrintQueue *)p->printQue);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)p->win), (unsigned char)p->bgSlot);
    if (p->printStream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)p->printStream);
        p->printStream = 0;
    }
    if (p->keyCursor != 0) {
        APP_KEYCURSOR_Delete((struct KeyCursor *)p->keyCursor);
        p->keyCursor = 0;
    }
    WIFIBATTLEMATCH_UTIL_StopTimeIcon(p);
    switch (mode) {
    case 2:
        p->timeIcon = TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(), (void *)p->win, (unsigned char)p->bgSlot, 0x10, p->heapId);
        printQue = (int)p->printQue;
        PRINTSYS_PrintQue((struct PrintQueue *)printQue, BMP_WIN_GetBmp((struct BmpWin *)p->winBmp), 0, 0, (void *)p->strbuf, (struct GfFont *)p->printArg);
        p->shown = 1;
        p->state = 0;
        break;
    case 0:
        printQue = (int)p->printQue;
        PRINTSYS_PrintQue((struct PrintQueue *)printQue, BMP_WIN_GetBmp((struct BmpWin *)p->winBmp), 0, 0, (void *)p->strbuf, (struct GfFont *)p->printArg);
        p->shown = 1;
        p->state = 0;
        break;
    case 1:
        if (p->keyCursor != 0) {
            GF_PANIC_Fail((const char *)d_021E8DEC, 0, (const char *)d_021E8DEC);
        }
        PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)(u8 *)&p->ctrlKeyReleased, 2);
        p->keyCursor = (int)APP_KEYCURSOR_CreateDefault(p->bgSlot, 1, 0, p->heapId);
        p->printStream = (void *)PRINTSYS_PrintStream((struct BmpWin *)(int)p->win, 0, 0, (struct Strbuf *)(int)p->strbuf, (struct GfFont *)p->printArg, MSG_SPEED_GetWait(), (struct Tcbl *)(int)p->tcbl, 0, p->heapId, p->bgSlot);
        p->state = 1;
        break;
    }
    p->busy = 0;
}

int WIFIBATTLEMATCH_UTIL_GetBusy(const WifibattlematchUtilWork *p)
{
    return p->busy;
}

void WIFIBATTLEMATCH_UTIL_StopTimeIcon(WifibattlematchUtilWork *p)
{
    p->busy = 1;
    if (p->timeIcon != 0) {
        TIME_ICON_Delete((struct TimeIcon *)p->timeIcon);
        p->timeIcon = 0;
        BMP_WIN_MakeScreen((struct BmpWin *)p->win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)p->win));
    }
}

void WIFIBATTLEMATCH_UTIL_ClearBmp(WifibattlematchUtilWork *p)
{
    int bmp = (int)BMP_WIN_GetBmp((struct BmpWin *)p->win);

    BMP_Clear((struct Bmp *)bmp, (unsigned char)p->bgSlot);
    BMP_WIN_TransferChars((struct BmpWin *)p->win);
}

WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_ShowMenu(const WifibattlematchMenuDesc *p, u16 heap)
{
    int height = (p->count & 0x7f) << 1;

    return WIFIBATTLEMATCH_UTIL_CreateMenu(p, 0x13, 0x11 - height, 0xc, height, heap);
}

/*
 * note 2026-10-05 (wP8 W6): EXACT. Twin shape from ov121 021DA038. Lever: heap parameter u16 with u16 heap parameters on 02030734, 0201F81C, 0201F878 (5th), 0201FF30 (4th) and 02020CF8; x/y/width/height u8 with u8 450F0 prototype; if/else for the 02020D10 flag.
 */
WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_CreateMenu(const WifibattlematchMenuDesc *p,u8 x,u8 y,u8 width,int height,u16 heap)
{
    WifibattlematchMenu *out;
    void *bmp;
    u32 index;
    WifibattlematchMenuConfig config;
    out=GFL_HEAP_Alloc((u16)heap,28,0,d_021E8DD4,0x1a2);
    MI_CpuFill8(out,0,28);
    out->printQue=p->printQue;
    out->counter=p->kind;
    /* stand-in: *(u8 *)&height reads the low byte of the stack argument (ldrb); (u8)height and a u8 parameter both compile to lsls/lsrs */
    out->win=(void *)BMP_WIN_Create((u8)p->a,(u8)x,(u8)y,(u8)width,*(u8 *)&height,p->b,1);
    BMP_MENUWORK_DrawWindow(out->win,2,p->d,(u8)p->c);
    bmp=out->win;
    BMP_WIN_TransferChars(bmp);
    BMP_WIN_MakeScreen(bmp);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmp));
    out->win2=out->win;
    out->flag=0;
    out->entries=BMP_MENUWORK_Create(p->count,heap);
    for(index=0;index<p->count;index++)
        BMP_MENUWORK_AddMsgItem(out->entries,(struct MsgBank *)p->msgBank,p->items[index],index,(u16)heap);
    config=d_021E8D68;
    config.word[0]=(u32)out->entries;
    *(u16 *)((u8 *)&config+0x10)=p->count;
    *(u16 *)((u8 *)&config+0x12)=p->count;
    config.word[3]=(u32)out->win;
    config.word[9]=p->msgBank;
    config.word[10]=(u32)&out->win2;
    config.word[11]=p->printQue;
    config.word[12]=p->font;
    out->menu=BMP_MENULIST_Create((struct BmpMenuListTemplate *)&config,0,p->row,heap);
    BMP_MENULIST_ResetCursorTile(out->menu,(u16)heap);
    if(p->enabled)
        BMP_MENULIST_SetCancelDisabled(out->menu,0);
    else
        BMP_MENULIST_SetCancelDisabled(out->menu,1);
    return out;
}

void WIFIBATTLEMATCH_UTIL_DeleteMenu(WifibattlematchMenu *p)
{
    BMP_MENULIST_Delete((struct BmpMenuList *)p->menu, 0, 0);
    BMP_MENUWORK_Delete(p->entries);
    BMP_MENUWORK_DrawWindowBorder(p->win, 0);
    BMP_WIN_ClearScreen((struct BmpWin *)p->win);
    BMP_WIN_Delete((struct BmpWin *)p->win);
    GFL_HEAP_Free(p);
}

int WIFIBATTLEMATCH_UTIL_UpdateMenu(WifibattlematchMenu *p)
{
    int que = p->printQue;
    int result;

    if (p->flag != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)que, (void *)((int)BMP_WIN_GetBmp((struct BmpWin *)p->win2))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)p->win2);
            p->flag = 0;
        }
    }
    result = BMP_MENULIST_Main((struct BmpMenuList *)p->menu);
    if (result == -2) {
        result = p->counter;
    }
    return result;
}

/*
 * Allocate and clear a 0x10-byte record, attach a and b, and return it.
 */
WifibattlematchCallback *WIFIBATTLEMATCH_UTIL_CreateCallback(int owner, int callback, int heap)
{
    WifibattlematchCallback *record;
    record = GFL_HEAP_Alloc(heap, 0x10, 0, d_021E8DD4, 0x246);
    MI_CpuFill8(record, 0, 0x10);
    record->owner = owner;
    WIFIBATTLEMATCH_UTIL_SetCallback(record, callback);
    return record;
}

void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p) {GFL_HEAP_Free(p);}

void WIFIBATTLEMATCH_UTIL_InvokeCallback(WifibattlematchCallback *p)
{
    void (*fn)(void *, int *, int) = p->fn;

    if (fn != 0) {
        fn(p, &p->state, p->owner);
    }
}

/*
 * Unlabelled ov177 leaf hidden in a word run (it follows WIFIBATTLEMATCH_UTIL_InvokeCallback):
 * loads the word its argument points at and returns 1 when it is zero.
 * Matched to supply the `matched` witness for the four pending callers.
 */
int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p)
{
    return *p == 0;
}

void WIFIBATTLEMATCH_UTIL_SetCallback(WifibattlematchCallback *p, int callback)
{
    p->fn = (void (*)(void *, int *, int))callback;
    p->state = 0;
}

/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls WIFIBATTLEMATCH_UTIL_SetCallback with
 * its second argument zeroed.  Matched to supply the `matched` witness for the
 * pending ov175 caller WIFIBATTLEMATCH_NET_TaskCleanupB.
 */
void WIFIBATTLEMATCH_UTIL_ClearCallback(void *record)
{
    WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)record, 0);
}

/*
 * Field setter after WIFIBATTLEMATCH_UTIL_ClearCallback's pool: stores the second argument at
 * +0xc. Called from the ov175 root WIFIBATTLEMATCH_NET_CompStepF (0x021D7EF6, 0x021D8060,
 * 0x021D8550).
 */
void WIFIBATTLEMATCH_UTIL_SetRequest(s32 *record, u32 request)
{
    ((WifibattlematchCallback *)record)->request = request;
}

/*
 * Field copy after WIFIBATTLEMATCH_UTIL_SetRequest: the word at +0xc is stored to +4.
 * Called from ov175 at 0x021D5550 and from the root WIFIBATTLEMATCH_NET_CompStepF
 * (0x021D8858).
 */
void WIFIBATTLEMATCH_UTIL_CommitRequest(u32 record)
{
    ((WifibattlematchCallback *)record)->state = ((WifibattlematchCallback *)record)->request;
}

void WIFIBATTLEMATCH_UTIL_SetSaveState(int owner, int state)
{
    int save;

    save = (int)RECORD_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl((struct GameData *)owner)));
    switch (state) {
    case 1:
    case 4:
        RECORD_AddOne((struct RecordBlock *)save, 0x12);
        break;
    case 0:
    case 3:
        RECORD_AddOne((struct RecordBlock *)save, 0x13);
        break;
    case 2:
        RECORD_AddOne((struct RecordBlock *)save, 0x14);
        break;
    }
    RECORD_AddOne((struct RecordBlock *)save, 0x11);
}
