/*
 * file:     fld_trade_p05.c
 * unit:     yes
 * function: func_021CCBE0, func_021CCC50, func_021CCCC4, func_021CCCE4, func_021CCDF8, func_021CCE48, func_021CCEB8, func_021CCEE4, func_021CCEFC, func_021CCF48, func_021CCF54, func_021CCF60
 * address:  0x021CCBE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02027694  0x02027694  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027698  0x02027698  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   d_021DB40C  0x021DB40C  data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190938  0x02190938  thumb  ov021
 *   func_021CCF7C  0x021CCF7C  thumb  ov021
 *   d_021DB414     0x021DB414  data  a4
 *   d_021DB42C     0x021DB42C  data  ov021  a4
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021CD184  0x021CD184  thumb  ov021
 *   func_021CD1AC  0x021CD1AC  thumb  ov021
 */
#include "../../matched/include/Obj04293.h"
#include "../../matched/include/Obj09732.h"
#include "../../matched/include/Obj07588.h"
#include "../../matched/include/Obj18357.h"
#include "../../matched/include/Obj18358.h"

struct Obj;
struct WordSet;
struct Rec;
struct Handle;
struct Pair;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u16 x;
    u16 y;
    u16 alt;
    u16 h6;
} IconPos;

typedef struct {
    u8 pad0[4];
    void *party[2];     /* 0x04 */
    u16 hC;             /* 0x0C */
    u8 padE[0x18 - 0xe];
    void *sys;          /* 0x18 */
    u8 pad1C[0x4c - 0x1c];
    void *icon[2][6];   /* 0x4C */
    u8 pad7C[0x98 - 0x7c];
    u16 h98;
    u16 h9A;
    u16 h9C;
} Work_021CCCE4;

typedef struct {
    void *f0;
    u8 pad4[8];
    u16 hC;
    u8 padE[0xa0 - 0xe];
    void *fA0;
    void *fA4;
    void *fA8;
} Work_021CCEB8;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027694(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027698(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);
extern void func_0204A8D4(u32 i);
extern u32 func_0204ADA4(u32);
extern void func_0204AFD8(u32 i);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern u32 func_0202136C(u16 v);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_021904C8(struct Rec *a0);
extern u32 func_02190A28(const struct Pair *arr, int n, u32 c, u16 d);
extern struct Handle *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i);
extern void func_021CCF7C(void *p, int k);
extern int func_021909BC(void *a);
extern int func_021909E4(struct Handle *h);
extern u32 func_02020D0C(u8 *p);
extern void func_021CD184(void *p, u32 sel);
extern void func_021CD1AC(void *p);
void func_021CCBE0(u8 *s, int flag);
void func_021CCC50(u8 *p);
int func_021CCCC4(u32 a);
void func_021CCCE4(Work_021CCCE4 *w);
void func_021CCDF8(u8 *p);
void func_021CCE48(u8 *s, int flag);
void func_021CCEB8(Work_021CCEB8 *w);
int func_021CCEE4(u32 a);
void func_021CCEFC(u8 *p);
void func_021CCF48(u8 *p);
u32 func_021CCF54(u8 *p);
void func_021CCF60(void *a, u32 sel);
extern const IconPos d_021DB40C;
extern u8 d_021DB414[];
extern u8 d_021DB42C[];


void func_021CCBE0(u8 *s, int flag)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x1c) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x1c), 0);
        if (*(void **)(s + i * 4 + 0x34) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x34), 0);
    }
    if (flag == 0) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x1c) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x1c), 1);
        }
    } else if (flag == 1) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x34) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x34), 1);
        }
    }
}


void func_021CCC50(u8 *p)
{
    void *h;
    u32 a;
    u32 b;

    h = func_020490F4(0x53, ((struct Obj04293 *)p)->fC);
    ((struct Obj04293 *)p)->f98 = func_0204AC18(h, func_02027694(), 0, 0xc0, 0, 1, ((struct Obj04293 *)p)->fC);
    a = func_0202769C(1);
    b = func_020276A0(1);
    ((struct Obj04293 *)p)->f9A = func_0204AF28(h, a, b, ((struct Obj04293 *)p)->fC);
    ((struct Obj04293 *)p)->f9C = func_0204A6C8(h, func_02027698(), 0, 0, ((struct Obj04293 *)p)->fC);
    func_02049238(h);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CCCC4(u32 a)
{
func_0204A8D4(*(u16 *)((u8 *)((a + 156))));
func_0204AFD8(*(u16 *)((u8 *)((a + 154))));
return func_0204ADA4(*(u16 *)((u8 *)((a + 152))));
}


/*
 * Creates the party icon sprites for both sides: one per non-empty slot, at x = 0x20 + 0x28 * slot, flagged for the alternate form, into the +0x4C and +0x64 handle arrays.
 *
 * The alternate-form flag is an if/else storing 1 or 0 into pos.alt, not a
 * ternary: the ternary version (114 bytes out) left the second party count in
 * a register and rematerialised &pos; the if/else spills both counts and
 * keeps &pos hoisted in each loop, as the original does.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCCE4(Work_021CCCE4 *w)
{
    IconPos pos = d_021DB40C;
    int n0;
    int n1;
    int i;
    u32 species;

    n0 = func_0201AA18(w->party[0]);
    for (i = 0; i < n0; i++) {
        species = func_02017E1C(func_0201AB28(w->party[0], i), 6, 0);
        if (species != 0) {
            if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
            pos.x = i * 0x28 + 0x20;
            w->icon[0][i] = func_0204B294(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
            func_0204B3DC(w->icon[0][i], 0);
        }
    }
    if (w->party[1] != 0) {
        n1 = func_0201AA18(w->party[1]);
        for (i = 0; i < n1; i++) {
            species = func_02017E1C(func_0201AB28(w->party[1], i), 6, 0);
            if (species != 0) {
                if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
                pos.x = i * 0x28 + 0x20;
                w->icon[1][i] = func_0204B294(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
                func_0204B3DC(w->icon[1][i], 0);
            }
        }
    }
}


void func_021CCDF8(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(((struct Obj09732 *)p)->f4);
    for (i = 0; i < n; i++) {
        if (*(void **)(p + i * 4 + 0x4c))
            func_0204B3B4(*(void **)(p + i * 4 + 0x4c));
    }
    if (((struct Obj09732 *)p)->f8) {
        n = func_0201AA18(((struct Obj09732 *)p)->f8);
        for (i = 0; i < n; i++) {
            if (*(void **)(p + i * 4 + 0x64))
                func_0204B3B4(*(void **)(p + i * 4 + 0x64));
        }
    }
}


void func_021CCE48(u8 *s, int flag)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x4c) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x4c), 0);
        if (*(void **)(s + i * 4 + 0x64) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x64), 0);
    }
    if (flag == 0) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x4c) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x4c), 1);
        }
    } else if (flag == 1) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x64) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x64), 1);
        }
    }
}


/*
 * Fetches three handles for the work block: an ov021 object, a 0x54 sub-entry of it, and the record for the work's id.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCEB8(Work_021CCEB8 *w)
{
    void *o = (void *)func_02188C54(w->f0);
    w->fA8 = (void *)func_021904B0((u32)o, 0x54);
    w->fA4 = o;
    w->fA0 = func_0201EC64(w->hC);
}


int func_021CCEE4(u32 a)
{
func_0201ED04((struct WordSet *)(*(u32 *)((u8 *)((a + 160)))));
return func_021904C8((struct Rec *)(*(u32 *)((u8 *)((a + 168)))));
}


void func_021CCEFC(u8 *p)
{
    void *r;

    r = (void *)func_02190A28((const struct Pair *)d_021DB414, 3, ((struct Obj07588 *)p)->fA8, ((struct Obj07588 *)p)->fC);
    ((struct Obj07588 *)p)->fAC = func_02190938((u16 *)(((struct Obj07588 *)p)->fA4), d_021DB42C, (u32)r, 0, 0,
        (u32)func_021CCF60, (u32)func_021CCF7C, (u32)p);
}


/*
 * Tail call on the word at +0xac.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCF48(u8 *p)
{
    func_021909BC((void *)(((struct Obj18357 *)p)->fAC));
}


u32 func_021CCF54(u8 *p)
{
    return func_021909E4((struct Handle *)(((struct Obj18358 *)p)->fAC));
}


/*
 * Dispatches on a selector below two to func_021CD184, otherwise to func_021CD1AC, on the object from func_02020D0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCF60(void *a, u32 sel)
{
    void *p = (void *)func_02020D0C(a);
    if (sel < 2)
        func_021CD184(p, sel);
    else
        func_021CD1AC(p);
}
