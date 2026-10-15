/*
 * file:     wifibattlematch_util.c
 * unit:     yes
 * function: func_021E8568, func_021E8628, func_021E867C, func_021E8738, func_021E8754, func_021E8844, func_021E8848, func_021E8870, func_021E888C, func_021E88B0, func_021E89D0, func_021E8A00, func_021E8A3C, func_021E8A78, func_021E8A80, func_021E8A90, func_021E8AA0, func_021E8AA8, func_021E8AB4, func_021E8AB8, func_021E8AC0
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
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_020409B4 0x020409B4 arm
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
 *   func_02028484 0x02028484 thumb
 *   TCBL_Main 0x020310C4 arm
 *   func_02045CAC  0x02045CAC  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   func_02034714  0x02034714  arm
 *   func_02028470  0x02028470  thumb
 *   func_02028590  0x02028590  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   d_021E8DEC     0x021E8DEC  data
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_02020D10 0x02020D10 thumb
 *   d_021E8D68 0x021E8D68 data a4
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   BMP_MENULIST_Main  0x020200CC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DF0  0x02008DF0  thumb
 */
#include "../../matched/include/Obj01960.h"
#include "../../matched/include/Obj00842.h"
#include "../../matched/include/Obj24449.h"
#include "../../matched/include/Obj24452.h"
#include "../../matched/include/Obj24454.h"
#include "../../matched/include/Obj08290.h"
#include "wifibattlematch_graphic_shared_types.h"
#include "wifibattlematch_view_shared_types.h"

struct Tcbl;

struct Rec3;

struct S02031140;

struct Ctx;

struct Blk;

struct Big;

struct Sub02008C20Obj;

typedef struct {
    char           pad0[4];
    int            f4;
    char           pad1[4];
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad2[3];
    int            f28;
    int            f2c;
} S_021E7CD0;

typedef struct {
    int            f0;
    int            f4;
    int            f8;
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad0[3];
    int            f28;
    int            f2c;
    int            f30;
    int            f34;
    char           f38[1];
} S_021E8754;

typedef struct {
    char pad0[0x10];
    int  f10;
    int  f14;
    char pad1[0x18];
    int  f30;
} S_021E8848;

typedef struct {
    char           pad0[0x14];
    int            f14;
    char           pad1[4];
    unsigned short f1c;
} S_021E8870;

typedef struct {u32 word[13];} Config;

typedef struct {void *win;u32 mgr;void *win2;u8 flag,pad[3];void *menu;void *entries;u32 counter;} MenuWork;

typedef struct {u32 x0,x1,x2;u32 items[4];u32 count;u16 a,b,c,d;int enabled;u16 kind,pad;} Desc;

typedef struct {
    int f0;
    char pad0[0xc];
    int f10;
    int f14;
} S_021E89D0;

typedef struct {
    char          pad0[4];
    int           f4;
    int           f8;
    unsigned char fc;
    char          pad1[3];
    int           f10;
    int           f14;
    int           f18;
} S_021E8A00;

typedef struct {
    void (*fn)(void *, int *, int);
    int a;
    int b;
} CB;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *, u8, u32);

extern u32 func_020307B0(void *p);

extern struct U16Vec *STRBUF_Create(u32 capacity, u16 heapId);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void func_020409B4(u32);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern u32 PRINTSYS_QUE_Create(void *p);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void TIME_ICON_Delete(unsigned char *p);

extern int APP_KEYCURSOR_Delete(int p);

extern void TCBL_Destroy(struct S02031140 *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

extern s32 func_02028484(struct Blk *blk, void *h);

extern void TCBL_Main(struct Tcbl *p);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern u32 func_020056BC(void);

extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void func_02028470(u8 *p, u32 v);

extern int  func_02028590(int, int, int, int);

extern signed char MSG_SPEED_GetWait(void);

extern int  PRINTSYS_PrintStream(int, int, int, int, int, int, int, int, int, int);

extern void *BMP_MENUWORK_Create(u32,u16);

extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

extern void *BMP_MENULIST_Create(Config *,u16,u16,u16);

extern void func_02020CF8(struct Obj *p, int heap);

extern void func_02020D10(u8 *p, u32 v);

extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);

extern u32 BMP_MENUWORK_Delete(void *p);

extern s32 BMP_MENULIST_Main(struct Obj *o);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern struct Sub02008C20Obj *func_02008C58(void *sys);

extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

S_021E7CD0 *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap);

void func_021E8628(char *p);

void func_021E867C(char *p);

void func_021E8738(int *p, int a, int b, int c);

void func_021E8754(S_021E8754 *p, int mode);

int func_021E8844(const int *p);

void func_021E8848(S_021E8848 *p);

void func_021E8870(S_021E8870 *p);

void func_021E888C(const Desc *p, u16 a);

MenuWork *func_021E88B0(const Desc *p,u8 x,u8 y,u8 width,int height,u16 heap);

void func_021E89D0(S_021E89D0 *p);

int func_021E8A00(S_021E8A00 *p);

int *func_021E8A3C(int a, int b, int c);

void func_021E8A78(void *p);

void func_021E8A80(CB *p);

int func_021E8A90(int **p);

void func_021E8AA0(int *p, int v);

void func_021E8AA8(int a);

void func_021E8AB4(u32 sys, u32 v);

void func_021E8AB8(u32 sys);

void func_021E8AC0(int a, int b);

extern const char d_021E8DD4[];

extern unsigned char d_021E8DEC[];

extern const Config d_021E8D68;

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
 *   house callee prototypes (func_02030734 u32 heap, u16 tag; STRBUF_Create u32, u32; TCBL_Create u32 heap,
 *   u16 tag, so heap goes to both), and d is a u16 parameter passed to the u16 third parameter of
 *   BMP_MENUWORK_DrawWindow. The u16 heap keeps the word ldr and moves it below the c home store (8 -> 6), and the u16 d
 *   moves its home store to the front (6 -> 0). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 */
S_021E7CD0 *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap)
{
    S_021E7CD0 *w;
    int h;

    w = func_02030734(heap, 0x40, 0, d_021E8DD4, 0x5e);
    MI_CpuFill8(w, 0, 0x40);
    w->f1c = 0xf;
    w->f4 = f;
    w->f28 = PRINTSYS_QUE_Create((void *)heap);
    w->f2c = 3;
    w->f1e = heap;
    w->f18 = (int)STRBUF_Create(0x300, heap);
    w->f14 = BMP_WIN_Create((unsigned char)a, 1, 0x13, 0x1e, 4, (unsigned char)b, 1);
    w->f20 = w->f14;
    w->f24 = 0;
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)w->f14), (unsigned char)w->f1c);
    h = w->f14;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    w->fc = (int)TCBL_Create(heap, heap, 1, 0x20);
    BMP_MENUWORK_DrawWindow((void *)w->f14, 0, d, (unsigned char)c);
    return w;
}

void func_021E8628(char *p)
{
    if (((struct Obj01960 *)p)->f8 != 0) {
        PRINTSYS_PrintStreamDelete(((struct Obj01960 *)p)->f8);
        ((struct Obj01960 *)p)->f8 = 0;
    }
    if (*(unsigned char * *)&((struct Obj01960 *)p)->f10 != 0) {
        TIME_ICON_Delete(*(unsigned char * *)&((struct Obj01960 *)p)->f10);
        ((struct Obj01960 *)p)->f10 = 0;
    }
    if (((struct Obj01960 *)p)->f34 != 0)
        APP_KEYCURSOR_Delete(((struct Obj01960 *)p)->f34);
    TCBL_Destroy(((struct Obj01960 *)p)->fC);
    BMP_MENUWORK_DrawWindowBorder(((struct Obj01960 *)p)->f14, 0);
    BMP_WIN_Delete(((struct Obj01960 *)p)->f14);
    STRBUF_Delete(((struct Obj01960 *)p)->f18);
    PRINTSYS_QUE_Delete(((struct Obj01960 *)p)->f28);
    func_020307B0(p);
}

void func_021E867C(char *p)
{
 void *q;
 PRINTSYS_QUE_Main(((struct Obj00842 *)p)->f28);
 switch(((struct Obj00842 *)p)->f2C) {
 case 2:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && PRINTSYS_QUE_IsExistTarget(q,(void *)((unsigned)BMP_WIN_GetBmp(((struct Obj00842 *)p)->f20)))==0) {
 BMP_WIN_TransferChars(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 break;
 case 0:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && PRINTSYS_QUE_IsExistTarget(q,(void *)((unsigned)BMP_WIN_GetBmp(((struct Obj00842 *)p)->f20)))==0) {
 BMP_WIN_TransferChars(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 ((struct Obj00842 *)p)->f30=((struct Obj00842 *)p)->f24==0;
 break;
 case 1:
 if(((struct Obj00842 *)p)->f8!=0) {
 if(((struct Obj00842 *)p)->f34!=0)APP_KEYCURSOR_Update(((struct Obj00842 *)p)->f34,((struct Obj00842 *)p)->f8,((struct Obj00842 *)p)->f14);
 if(func_02028484((struct Blk *)(p+0x38),((struct Obj00842 *)p)->f8)!=0)((struct Obj00842 *)p)->f30=1;
 }
 break;
 case 3:break;
 }
 TCBL_Main(((struct Obj00842 *)p)->fC);
}

void func_021E8738(int *p, int a, int b, int c)
{
    func_02045CAC((struct MsgBank *)a, b, (void *)(((struct Obj24449 *)p)->f18));
    func_021E8754((S_021E8754 *)p, c);
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
void func_021E8754(S_021E8754 *p, int mode)
{
    int q;

    PRINTSYS_QUE_Clear((struct PrintSys *)p->f28);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)p->f14), (unsigned char)p->f1c);
    if (p->f8 != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)p->f8);
        p->f8 = 0;
    }
    if (p->f34 != 0) {
        APP_KEYCURSOR_Delete(p->f34);
        p->f34 = 0;
    }
    func_021E8848((S_021E8848 *)((S_021E8754 *)p));
    switch (mode) {
    case 2:
        p->f10 = (int)TIME_ICON_Create((void *)func_020056BC(), (void *)p->f14, (unsigned char)p->f1c, 0x10, p->f1e);
        q = p->f28;
        PRINTSYS_PrintQue((struct PrintSys *)q, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 0:
        q = p->f28;
        PRINTSYS_PrintQue((struct PrintSys *)q, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 1:
        if (p->f34 != 0) {
            func_02034714((const char *)d_021E8DEC, 0, (const char *)d_021E8DEC);
        }
        func_02028470((u8 *)p->f38, 2);
        p->f34 = func_02028590(p->f1c, 1, 0, p->f1e);
        p->f8 = PRINTSYS_PrintStream(p->f14, 0, 0, p->f18, p->f4, MSG_SPEED_GetWait(), p->fc, 0, p->f1e, p->f1c);
        p->f2c = 1;
        break;
    }
    p->f30 = 0;
}

int func_021E8844(const int *p)
{
    return p[0x30 / 4];
}

void func_021E8848(S_021E8848 *p)
{
    p->f30 = 1;
    if (p->f10 != 0) {
        TIME_ICON_Delete((u8 *)p->f10);
        p->f10 = 0;
        BMP_WIN_MakeScreen((struct Cfg *)p->f14);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)p->f14));
    }
}

void func_021E8870(S_021E8870 *p)
{
    int r = (int)BMP_WIN_GetBmp((struct Descriptor *)p->f14);

    BMP_Clear((struct CharBuf *)r, (unsigned char)p->f1c);
    BMP_WIN_TransferChars((struct Descriptor *)p->f14);
}

void func_021E888C(const Desc *p, u16 a)
{
    int v = (p->count & 0x7f) << 1;

    func_021E88B0(p, 0x13, 0x11 - v, 0xc, v, a);
}

/*
 * note 2026-10-05 (wP8 W6): EXACT. Twin shape from ov121 021DA038. Lever: heap parameter u16 with u16 heap parameters on 02030734, 0201F81C, 0201F878 (5th), 0201FF30 (4th) and 02020CF8; x/y/width/height u8 with u8 450F0 prototype; if/else for the 02020D10 flag.
 */
MenuWork *func_021E88B0(const Desc *p,u8 x,u8 y,u8 width,int height,u16 heap)
{
    MenuWork *out;
    void *q;
    u32 i;
    Config cfg;
    out=func_02030734((u16)heap,28,0,d_021E8DD4,0x1a2);
    MI_CpuFill8(out,0,28);
    out->mgr=p->x2;
    out->counter=p->kind;
    /* stand-in: *(u8 *)&height reads the low byte of the stack argument (ldrb); (u8)height and a u8 parameter both compile to lsls/lsrs */
    out->win=(void *)BMP_WIN_Create((u8)p->a,(u8)x,(u8)y,(u8)width,*(u8 *)&height,p->b,1);
    BMP_MENUWORK_DrawWindow(out->win,2,p->d,(u8)p->c);
    q=out->win;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
    out->win2=out->win;
    out->flag=0;
    out->entries=BMP_MENUWORK_Create(p->count,heap);
    for(i=0;i<p->count;i++)
        BMP_MENUWORK_AddMsgItem(out->entries,p->x0,p->items[i],i,(u16)heap);
    cfg=d_021E8D68;
    cfg.word[0]=(u32)out->entries;
    *(u16 *)((u8 *)&cfg+0x10)=p->count;
    *(u16 *)((u8 *)&cfg+0x12)=p->count;
    cfg.word[3]=(u32)out->win;
    cfg.word[9]=p->x0;
    cfg.word[10]=(u32)&out->win2;
    cfg.word[11]=p->x2;
    cfg.word[12]=p->x1;
    out->menu=BMP_MENULIST_Create(&cfg,0,p->pad,heap);
    func_02020CF8(out->menu,(u16)heap);
    if(p->enabled)
        func_02020D10(out->menu,0);
    else
        func_02020D10(out->menu,1);
    return out;
}

void func_021E89D0(S_021E89D0 *p)
{
    BMP_MENULIST_Delete((struct Obj *)p->f10, 0, 0);
    BMP_MENUWORK_Delete((void *)p->f14);
    BMP_MENUWORK_DrawWindowBorder((void *)p->f0, 0);
    BMP_WIN_ClearScreen((struct Descriptor *)p->f0);
    BMP_WIN_Delete((struct Descriptor *)p->f0);
    func_020307B0(p);
}

int func_021E8A00(S_021E8A00 *p)
{
    int r4 = p->f4;
    int r;

    if (p->fc != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)r4, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)p->f8))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)p->f8);
            p->fc = 0;
        }
    }
    r = BMP_MENULIST_Main((struct Obj *)p->f10);
    if (r == -2) {
        r = p->f18;
    }
    return r;
}

/*
 * Allocate and clear a 0x10-byte record, attach a and b, and return it.
 */
int *func_021E8A3C(int a, int b, int c)
{
    int *p;
    p = func_02030734(c, 0x10, 0, d_021E8DD4, 0x246);
    MI_CpuFill8(p, 0, 0x10);
    ((struct Obj24452 *)p)->f8 = a;
    func_021E8AA0(p, b);
    return p;
}

void func_021E8A78(void *p) {func_020307B0(p);}

void func_021E8A80(CB *p)
{
    void (*fn)(void *, int *, int) = p->fn;

    if (fn != 0) {
        fn(p, &p->a, p->b);
    }
}

/*
 * Unlabelled ov177 leaf hidden in a word run (it follows func_021E8A80):
 * loads the word its argument points at and returns 1 when it is zero.
 * Matched to supply the `matched` witness for the four pending callers.
 */
int func_021E8A90(int **p)
{
    return *p == 0;
}

void func_021E8AA0(int *p, int v)
{
    p[0] = v;
    p[1] = 0;
}

/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E8AA0 with
 * its second argument zeroed.  Matched to supply the `matched` witness for the
 * pending ov175 caller WIFIBATTLEMATCH_NET_TaskCleanupB.
 */
void func_021E8AA8(int a)
{
    func_021E8AA0((int *)a, 0);
}

/*
 * Field setter after func_021E8AA8's pool: stores the second argument at
 * +0xc. Called from the ov175 root WIFIBATTLEMATCH_NET_CompStepF (0x021D7EF6, 0x021D8060,
 * 0x021D8550).
 */
void func_021E8AB4(u32 sys, u32 v)
{
    ((struct Obj24454 *)sys)->fC = v;
}

/*
 * Field copy after func_021E8AB4: the word at +0xc is stored to +4.
 * Called from ov175 at 0x021D5550 and from the root WIFIBATTLEMATCH_NET_CompStepF
 * (0x021D8858).
 */
void func_021E8AB8(u32 sys)
{
    ((struct Obj08290 *)sys)->f4 = ((struct Obj08290 *)sys)->fC;
}

void func_021E8AC0(int a, int b)
{
    int x;

    x = (int)func_02008C58(GAME_DATA_GetSaveControl((struct Big *)a));
    switch (b) {
    case 1:
    case 4:
        func_02008DF0((struct Sub02008C20Obj *)x, 0x12);
        break;
    case 0:
    case 3:
        func_02008DF0((struct Sub02008C20Obj *)x, 0x13);
        break;
    case 2:
        func_02008DF0((struct Sub02008C20Obj *)x, 0x14);
        break;
    }
    func_02008DF0((struct Sub02008C20Obj *)x, 0x11);
}
