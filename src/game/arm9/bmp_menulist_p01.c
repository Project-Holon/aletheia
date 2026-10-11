/*
 * file:     bmp_menulist_p01.c
 * unit:     yes
 * function: func_0201FF30, func_020200CC, func_0202020C, func_02020234, func_02020268, func_02020298, func_020202EC, func_020202FC, func_02020314, func_02020324, func_02020344, func_02020350, func_02020408, func_0202055C, func_020206C0, func_0202071C, func_02020780, func_020208B8, func_02020970, func_02020A34, func_02020A58, func_02020B5C
 * address:  0x0201FF30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A7390     0x020A7390  data  a1
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045738  0x02045738  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020437DC  0x020437DC  arm
 *   func_02020CA0  0x02020CA0  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437E4  0x020437E4  arm
 */
#include "../../matched/include/Obj11266.h"
#include "../../matched/include/Obj08775.h"
#include "../../matched/include/Obj08776.h"

#define COLOR(l, s, b) ((u16)((((l) & 0x1f) << 10) | (((s) & 0x1f) << 5) | ((b) & 0x1f)))
struct CharBuf;
struct Descriptor;
struct Menu;
struct D;
struct Menu;
struct Bmp;
struct Desc;
struct Handle;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Src {
    u32 w[13];
};

typedef signed int     s32;
typedef signed short s16;
typedef signed char s8;

struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};

struct Target {
    u32 win;
    u8  dirty;
};

struct Item {
    void *text;
    u32   value;
};

struct Menu;
typedef void (*Hook)(struct Menu *obj, u32 value, u8 y);
typedef void (*Notify)(struct Menu *obj, u32 value, void *arg);

/* The three bitfield layouts of the halfword at +0x1A. */
struct Flags1A_a {
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
};

struct Flags1A_b {
    u16 f1Alo : 7;
    u16 f1Amid : 2;
    u16 f1Atop : 7;
};

struct Flags1A_c {
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Amid2 : 8;
    u16 f1Atop : 1;
};

union Flags1A {
    struct Flags1A_a a;
    struct Flags1A_b b;
    struct Flags1A_c c;
};

struct Menu {
    struct Item *arr;
    Notify callback;
    Hook hook;
    void *unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    union Flags1A u;
    u32 f1C;
    u16 f20;
    u16 f22;
    u8 pad24[0x28 - 0x24];
    void *f28;
    void *f2C;
    void *f30;
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36 : 6;
    u8 f36top : 2;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
    u8 pad39[0x3C - 0x39];
    void *f3C;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
    u8 f46;
    u8 f47;
    u16 f48;
    u8 f4A;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02020D18(u32 heap);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020061E4(u32 id);
extern void func_02020D3C(struct D *p);
extern u32 func_020307B0(void *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);
extern void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);
extern void func_02045334(struct Descriptor *win);
extern void *func_020437D4(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
struct Menu *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
s32 func_020200CC(struct Menu *o);
void func_0202020C(struct Menu *o, u16 *a, u16 *b);
void func_02020234(u8 *p);
void func_02020268(struct Menu *obj, u8 a, u8 b, u8 c);
void func_02020298(struct Menu *obj, u8 a, u8 b, u8 c);
void func_020202EC(struct Menu *obj, u16 *out);
void func_020202FC(struct Menu *obj, u16 *a, u16 *b);
u16 func_02020314(struct Menu *obj);
u16 func_02020324(struct Menu *obj, u32 n);
u32 func_02020344(struct Menu *obj, u32 n);
u32 func_02020350(struct Menu *obj, u32 what);
void func_02020408(struct Menu *obj, const void *text, u32 x, u32 y, u32 sel);
void func_0202055C(struct Menu *obj, u16 row, u16 col, u16 n, u32 flag);
void func_020206C0(struct Menu *obj);
void func_0202071C(struct Menu *obj, u32 n);
u8 func_02020780(struct Menu *obj, u8 dir);
void func_020208B8(struct Menu *obj, u16 n, u32 flag);
u32 func_02020970(struct Menu *obj, u8 notify, u8 count, u8 dir);
void func_02020A34(struct Menu *obj, void *arg1);
void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size);
extern char g_020A7390[];





struct Menu *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap)
{
    struct Menu *obj;
    int i;
    u32 *d;
    u32 *s;

    obj = (struct Menu *)func_02030734(heap, 0x50, 1, g_020A7390, 0x69);
    *(struct Src *)obj = *src;
    obj->f3C = func_02020D18(heap);
    obj->f40 = a;
    obj->f42 = b;
    obj->f44 = 0;
    obj->f45 = 0;
    obj->f46 = 0xFF;
    obj->f47 = 0;
    obj->f48 = (u16)heap;
    obj->f34lo = obj->f17hi;
    obj->f34hi = obj->f18lo;
    obj->f35lo = obj->f18hi;
    obj->f36 = (u8)obj->u.a.f1Alo;
    obj->f38 = (u8)obj->u.a.f1Amid2;
    obj->f38top = 0;
    if (obj->count < obj->rows) {
        obj->rows = obj->count;
    }
    while (*(u32 *)((u8 *)obj->arr + (obj->f40 + obj->f42) * 8 + 4) == (u32)-3) {
        obj->f42++;
    }
    {
        u8 *q = (u8 *)obj->f28;
        ((struct Obj11266 *)q)->f0 = (u32)obj->unk0C;
        q[4] = 0;
    }
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
    func_0202055C((struct Menu *)obj, obj->f40, 0, obj->rows, 1);
    func_020206C0((struct Menu *)obj);
    func_02020A34(obj, (void *)1);
    return obj;
}





/*
 * The per-frame key handler of the menu-cursor object built by
 * func_0201FF30: same shape as func_0201FA04 one block down, over the wider
 * struct that unit_020206C0.c already spells out.  Sound ids 0x54C / 0x551 /
 * 0x548 sit in the trailing pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020200CC.c \
 *       --func func_020200CC --addr 0x020200CC --thumb
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/func_020200CC.c.txt,
 * 81 bytes out).  The note read the residue as an allocator choice (`tst`
 * versus a copy and `ands`); it was a misread of the image.  In the
 * f1Amid == 2 arm the masks are derived from the 0x80 still live in r2:
 * `lsls r1, r2, #2` is 0x200 and `adds r2, #0x80` is 0x100, so the arm reads
 * the L and R shoulder buttons (0x200, 0x100), not up/down (0x40, 0x80).
 * With the right constants the 0x40 test becomes a plain `tst` by itself,
 * and the switch closes once case 0 and default share one arm.
 * func_02020970's prototype is the EXACT one (u8 scalar parameters).
 */
s32 func_020200CC(struct Menu *o)
{
    u32 keys = func_020362DC();
    u32 one = 1;
    u32 held = func_0203633C();

    o->f47 = 0;

    if (keys & one) {
        func_020061E4(0x54C);
        return o->arr[o->f40 + o->f42].value;
    }
    if (o->f4A == 0) {
        u32 two = 2;
        if (keys & two) {
            func_020061E4(0x551);
            return two - 4;
        }
    }
    if (held & 0x40) {
        if (func_02020970(o, 1, 1, 0) == 0) {
            func_020061E4(0x548);
            o->f47 = 1;
        }
        return -1;
    }
    if (held & 0x80) {
        if (func_02020970(o, 1, 1, 1) == 0) {
            func_020061E4(0x548);
            o->f47 = 2;
        }
        return -1;
    }
    {
        u16 h, v;
        switch (o->u.b.f1Amid) {
        case 0:
        default:
            h = 0;
            v = 0;
            break;
        case 1:
            h = (u16)(held & 0x20);
            v = (u16)(held & 0x10);
            break;
        case 2:
            h = (u16)(held & 0x200);
            v = (u16)(held & 0x100);
            break;
        }
        if (h != 0) {
            if (func_02020970(o, 1, (u8)o->rows, 0) == 0) {
                func_020061E4(0x548);
                o->f47 = 3;
            }
            return -1;
        }
        if (v != 0) {
            if (func_02020970(o, 1, (u8)o->rows, 1) == 0) {
                func_020061E4(0x548);
                o->f47 = 4;
            }
            return -1;
        }
    }
    return -1;
}






void func_0202020C(struct Menu *o, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = ((struct Obj08775 *)o)->f40;
    }
    if (b != 0) {
        *b = ((struct Obj08775 *)o)->f42;
    }
    func_02020D3C((struct D *)(((struct Obj08775 *)o)->f3C));
    func_020307B0(o);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020234.c \
 *       --func func_02020234 --addr 0x02020234 --cc 1.1p1 --thumb
 */
void func_02020234(u8 *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj08776 *)p)->fC)),
                  ((struct Ctl *)p)->lo4);
    func_0202055C((struct Menu *)((struct Menu *)((struct Menu *)p)), ((struct Obj08776 *)p)->f40, 0, ((struct Obj08776 *)p)->f12, 1);
    func_020206C0((struct Menu *)((struct Menu *)((struct Menu *)p)));
}






/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020268.c \
 *       --addr 0x02020268 --thumb
 *
 * The bmp_menulist.c attribute block 0x02020268..0x02020408, eight
 * functions of which only 0x02020268 was ever near a label.  The
 * worklist entry 0x020202CC (a "32-byte open function") is NOT a
 * function start: it is the middle of func_02020298 (the colour-override
 * setter), seeded into layout/function_starts.txt from a pending header
 * that misnamed sub_02022AC4's tail-call target (the pool word there is
 * 0x020222CD; see docs/notes/pkt_02022940.c.txt, wave 11).  The 32 bytes
 * the worklist counted are func_02020298's last eight instructions.
 *
 *   func_02020268  set the three colour nibbles f17hi / f18lo / f18hi
 *   func_02020298  set the override nibbles f34lo / f34hi / f35lo and the
 *                  override flag f38top (func_0201FF30 seeds the same
 *                  three from f17hi / f18lo / f18hi)
 *   func_020202EC  *out = f40 + f42 (list index of the cursor row)
 *   func_020202FC  optional out-pointers for f40 and f42
 *   func_02020314  tail call to func_02020324 with the cursor row f42
 *   func_02020324  pixel y of row n: f17lo + n * (u8)(f22 + f1Amid),
 *                  the expression unit_020206C0 inlines
 *   func_02020344  arr[n].value, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void func_02020268(struct Menu *obj, u8 a, u8 b, u8 c)
{
    obj->f17hi = a;
    obj->f18lo = b;
    obj->f18hi = c;
}




void func_02020298(struct Menu *obj, u8 a, u8 b, u8 c)
{
    obj->f34lo = a;
    obj->f34hi = b;
    obj->f35lo = c;
    obj->f38top = 1;
}




void func_020202EC(struct Menu *obj, u16 *out)
{
    *out = obj->f40 + obj->f42;
}




void func_020202FC(struct Menu *obj, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = obj->f40;
    }
    if (b != 0) {
        *b = obj->f42;
    }
}






u16 func_02020314(struct Menu *obj)
{
    return func_02020324(obj, obj->f42);
}




u16 func_02020324(struct Menu *obj, u32 n)
{
    return (u16)(obj->f17lo + n * (u8)(obj->f22 + obj->u.a.f1Amid));
}




u32 func_02020344(struct Menu *obj, u32 n)
{
    return obj->arr[n].value;
}




u32 func_02020350(struct Menu *obj, u32 what)
{
    switch (what) {
    case 0:  return (u32)obj->callback;
    case 1:  return (u32)obj->hook;
    case 2:  return obj->count;
    case 3:  return obj->rows;
    case 5:  return obj->f14;
    case 6:  return obj->f15;
    case 7:  return obj->f16;
    case 8:  return obj->f17lo;
    case 9:  return obj->f22 + obj->u.a.f1Amid;
    case 10: return obj->f17hi;
    case 11: return obj->f18lo;
    case 12: return obj->f18hi;
    case 13: return obj->u.a.f1Alo;
    case 14: return obj->u.a.f1Amid;
    case 15: return obj->u.a.f1Apad;
    case 16: return obj->u.a.f1Amid2;
    case 17: return obj->u.a.f1Atop;
    case 18: return (u32)obj->unk0C;
    case 19: return obj->f1C;
    }
    return -1;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020408.c \
 *       --func func_02020408 --addr 0x02020408 --thumb
 *
 * Print one item's text into the menu window.  f38top selects the override
 * colours at +0x34/+0x35 (set by unit_02020268's func_02020298) over the
 * list's own at +0x17/+0x18; sel picks func_0201C724 (which also marks the
 * target dirty) over func_0201C7D0.  Closed in wave 13; the 2026-09-21 note
 * (docs/notes/func_02020408.c.txt) had it at 314 of 338 bytes.
 *
 * The packed colour is a 5:5:5 triple built by a masking macro,
 *     ((l & 0x1f) << 10) | ((s & 0x1f) << 5) | (b & 0x1f)
 * over the 4-bit nibbles: mwcc turns each mask-then-shift into the
 * `<< 27 / >> 17` and `<< 27 / >> 22` pairs and keeps the bare `ands 0x1f`
 * on the unshifted term, which is exactly the "5-bit destination over a
 * 4-bit source" shape the note described.  No 5-bit bitfield struct needed.
 *
 * THE IMAGE'S FOURTH ARM (f38top clear, sel == 0) READS THE OVERRIDE BYTES
 * +0x34/+0x35, not +0x17/+0x18 like the third arm.  That is what the bytes
 * say, and the C reproduces it; it reads like a copy-paste slip in the
 * original.  EXACT* only because the extent includes 2 bytes of padding.
 */
void func_02020408(struct Menu *obj, const void *text, u32 x, u32 y, u32 sel)
{
    if (text == 0)
        return;
    if (obj->f38top) {
        if (sel) {
            u32 a = (u32)obj->f2C;
            struct Target *t = (struct Target *)obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, (u32)obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)((struct Target *)obj->f28)->win), x, y, text, (u32)obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    } else {
        if (sel) {
            u32 a = (u32)obj->f2C;
            struct Target *t = (struct Target *)obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, (u32)obj->f30,
                          COLOR(obj->f17hi, obj->f18hi, obj->f18lo));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)((struct Target *)obj->f28)->win), x, y, text, (u32)obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    }
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202055C.c \
 *       --func func_0202055C --addr 0x0202055C --thumb
 *
 * Redraw n + 1 rows of the menu list from item `row`, starting at window
 * row `col`.  When flag is set and row > 0 the window is first scrolled by
 * one row: the band is cleared with func_02043AF4, the item above is
 * redrawn and func_02020CA0 moves the pixels.  Every item goes through the
 * optional per-item hook at +0x08 (obj, item value, y) and then
 * func_02020408 at x = f15, or f14 for a separator (value -3).
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/func_0202055C.c.txt,
 * 96 out).  That source misread three things, all fixed here from the image:
 * the hook's second argument inside the loop is the item's value word (still
 * live in r1 from the separator test), not 0; func_02020CA0's last argument
 * is (step*2/8) * (func_020437DC(bitmap) / 8), the bitmap's width in tiles,
 * not step >> 3; and the x colour is an int (no truncation after the
 * ternary).  Then the permuter's type:l(step:u8->int) (the value is still
 * (u8)-truncated at its one assignment) swapped the last two stack slots.
 * EXACT* only because the extent includes 2 bytes of padding.
 */
void func_0202055C(struct Menu *obj, u16 row, u16 col, u16 n, u32 flag)
{
    int step;
    int x;
    u8 y;
    int i;
    int lim;

    step = (u8)(obj->f22 + obj->u.a.f1Amid);
    if (row != 0 && flag != 0) {
        u32 bmp;
        u8 w;
        u8 k;
        x = (obj->arr[row - 1].value != (u32)-3) ? obj->f15 : obj->f14;
        bmp = (u32)func_02045770((struct Descriptor *)obj->unk0C);
        w = func_02045738((struct Descriptor *)obj->unk0C);
        func_02043AF4((struct Bmp *)bmp, 0, 0, (u16)(w * 8),
                      (u16)(obj->f17lo + (col + 1) * step * 2), obj->f18lo);
        y = (u8)(obj->f17lo + col * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row - 1].value, y);
        func_02020408((struct Menu *)obj, obj->arr[row - 1].text, x, y, 0);
        k = obj->f18lo;
        func_02020CA0((void *)obj->unk0C, 0, step, (u8)((k << 4) | k),
                      (u16)((step * 2 / 8) * (func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C))) / 8)));
    }
    lim = (u16)(n + 1);
    for (i = 0; i < lim; i++) {
        x = (obj->arr[row].value != (u32)-3) ? obj->f15 : obj->f14;
        y = (u8)(obj->f17lo + (i + col) * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row].value, y);
        func_02020408((struct Menu *)obj, obj->arr[row].text, x, y, 1);
        row++;
        if (row >= obj->count)
            return;
    }
}




/*
 * The two redraw entry points of the menu-cursor block, func_020206C0 and
 * func_0202071C, folded into one translation unit so 0x020206C0..0x0202077E
 * reproduces end to end.  Both dispatch on the same one-bit field at the top
 * of the u16 at +0x1A through a four-entry PC-relative halfword table whose
 * cases 1..3 are empty arms; the empty arms are what make the table exist
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Both pass the same derived byte, f17lo + <row> * (u8)(f22 + f1Amid), to
 * their callee; in func_020206C0 the row is the cursor's own f42 and the
 * value must be bound to a named local computed BEFORE the switch (as must
 * f16), or the compiler sinks both into the case-0 arm and the function is
 * four bytes short.  In func_0202071C the row is the function's second
 * argument and the same value is an inline argument, scheduled per site
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 */
void func_020206C0(struct Menu *obj)
{
    u8 a = obj->f17lo;
    u8 b = obj->f16;
    u8 v = (u8)(a + obj->f42 * (u8)(obj->f22 + obj->u.c.f1Amid));

    switch (obj->u.c.f1Atop) {
    case 0:
        func_02020D5C(obj->f3C, b, v, obj->f28, obj->f2C, (u32)obj->f30);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}



void func_0202071C(struct Menu *obj, u32 n)
{
    switch (obj->u.c.f1Atop) {
    case 0:
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C)),
                      obj->f16,
                      (s16)(u16)(obj->f17lo + n * (u8)(obj->f22 + obj->u.c.f1Amid)),
                      obj->f20,
                      obj->f22,
                      obj->f18lo);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020780.c \
 *       --func func_02020780 --addr 0x02020780 --thumb
 *
 * One cursor step of the scrolling menu list, dir 0 = up, else down.  The
 * cursor row (f42) moves inside the window, skipping items whose value word
 * is -3 (separators), and answers 1; at the window's middle row the list
 * scrolls instead (f40 -= 1 / += 1, cursor parked on the middle row) and it
 * answers 2; at either end of the list it answers 0.  The middle row is
 * rows - (rows/2 + rows%2) - 1 going up and rows/2 + rows%2 going down, 0
 * for a one-row window.
 *
 * Re-derived in wave 13 (the 2026-09-21 note, docs/notes/func_02020780.c.txt,
 * kept no source).  What pinned the register map obj=r0 row=r4 col=r3
 * rows=r2, which that note could not reach:
 *   - col (f40) is an int local, not u16 (u16 keeps obj out of r0);
 *   - rows is read into its local INSIDE each arm, not before the test
 *     (the image loads +0x12 after `cmp r1, #0`);
 *   - declaration order ncol, col, rows, mid, row (the permuter's
 *     decl-order row<->ncol; row declared first swaps r3/r4).
 * EXACT* only because the listing's extent includes the two bytes of
 * alignment padding after the function.
 */
u8 func_02020780(struct Menu *obj, u8 dir)
{
    int ncol;
    int col;
    u16 rows;
    u16 mid;
    u16 row;

    row = obj->f42;
    col = obj->f40;
    if (dir == 0) {
        rows = obj->rows;
        if (rows == 1) {
            mid = 0;
        } else {
            mid = rows - (rows / 2 + rows % 2) - 1;
        }
        if (col == 0) {
            while (row != 0) {
                row--;
                if (obj->arr[col + row].value != (u32)-3) {
                    obj->f42 = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row > mid) {
            row--;
            if (obj->arr[col + row].value != (u32)-3) {
                obj->f42 = row;
                return 1;
            }
        }
        obj->f42 = mid;
        ncol = col - 1;
    } else {
        rows = obj->rows;
        if (rows == 1) {
            mid = 0;
        } else {
            mid = rows / 2 + rows % 2;
        }
        if (col == obj->count - rows) {
            while ((int)row < rows - 1) {
                row++;
                if (obj->arr[col + row].value != (u32)-3) {
                    obj->f42 = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row < mid) {
            row++;
            if (obj->arr[col + row].value != (u32)-3) {
                obj->f42 = row;
                return 1;
            }
        }
        obj->f42 = mid;
        ncol = col + 1;
    }
    obj->f40 = ncol;
    return 2;
}




void func_020208B8(struct Menu *obj, u16 n, u32 flag)
{
    u8 step;

    if (n >= (int)obj->rows) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
        func_0202055C((struct Menu *)obj, obj->f40, 0, obj->rows, 1);
        return;
    }

    step = (u8)(obj->f22 + obj->u.c.f1Amid);
    if (flag == 0) {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 1, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C((struct Menu *)obj, obj->f40, 0, n, 1);
    } else {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 0, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C((struct Menu *)obj, (u16)(obj->f40 + (obj->rows - n)), (u16)(obj->rows - n), n, 0);
    }
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020970.c \
 *       --func func_02020970 --addr 0x02020970 --thumb
 *
 * Move the menu cursor count steps in direction dir (func_02020780 does one
 * step and answers 0 = no move, 1 = cursor moved inside the window, 2 = the
 * list scrolled), then, if notify, redraw what changed.  Closed in wave 13
 * after the 2026-09-21 note (docs/notes/func_02020970.c.txt) left it at 34
 * bytes out.  What closed it, in order of weight:
 *   - ALL THREE SCALAR PARAMETERS ARE NARROW (u8 here; u16 compiles the
 *     same).  u8 count is what gives the guard its `cmp r0,#0 / bls` with
 *     the reload from the home slot (u32 count gives `cmp #1 / blo` or folds
 *     onto r2); u8/u16 notify and dir are what schedule the three home
 *     stores ahead of the obj copy.
 *   - the guard is `i < count` with i already 0, around a do/while;
 *   - a skipped row (item value -3) re-runs the step WITHOUT advancing i:
 *     a goto to the top of the body, not a continue (continue reaches the
 *     condition);
 *   - `case 0: default: return 1;` written first; without case 0 the switch
 *     becomes a compare chain, with a separate default it duplicates.
 */
u32 func_02020970(struct Menu *obj, u8 notify, u8 count, u8 dir)
{
    u8 acc;
    u8 moved;
    u8 i;
    u8 r;
    u16 saved;

    moved = 0;
    acc = 0;
    saved = obj->f42;
    i = 0;
    if (i < count) {
        do {
        again:
            r = func_02020780((struct Menu *)obj, dir);
            acc |= r;
            if (r == 2) {
                moved++;
                if (obj->arr[obj->f40 + obj->f42].value == (u32)-3)
                    goto again;
            }
            i++;
        } while (i < count);
    }
    if (notify != 0) {
        switch (acc) {
        case 0:
        default:
            return 1;
        case 1:
            func_0202071C((struct Menu *)obj, saved);
            func_020206C0((struct Menu *)obj);
            func_02020A34((struct Menu *)((struct Menu *)obj), 0);
            func_02045334((struct Descriptor *)obj->unk0C);
            break;
        case 2:
        case 3:
            func_0202071C((struct Menu *)obj, saved);
            func_020208B8((struct Menu *)obj, moved, dir);
            func_020206C0((struct Menu *)obj);
            func_02020A34((struct Menu *)((struct Menu *)obj), 0);
            break;
        }
    }
    return 0;
}




void func_02020A34(struct Menu *obj, void *arg1)
{
    if (obj->callback != 0) {
        obj->callback(obj, obj->arr[obj->f40 + obj->f42].value, arg1);
    }
}




void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32  len;
    s32  y;
    s32  src;
    s32  dst;
    u32  t;
    s32  x;
    u8  *buf;

    buf = func_020437D4(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)func_020437DC(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)func_020437E4(bmp) >> 3)) << 5;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                *(u32 *)(buf + dst) =
                    (src < len) ? *(u32 *)(buf + src) : fill;
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 4);
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 *q;
                u32  v;
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    q = (u32 *)(buf - dst);
                } else {
                    q = (u32 *)(buf - dst);
                    v = fill;
                }
                t++;
                *q = v;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}




void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32  len;
    s32  y;
    s32  src;
    s32  dst;
    u32  t;
    s32  x;
    u8  *buf;

    buf = func_020437D4(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)func_020437DC(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)func_020437E4(bmp) >> 3)) << 6;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x40) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 v;
                dst = y + x * 8;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 3);
                if (src < len) {
                    v = *(u32 *)(buf + src);
                    *(u32 *)(buf + dst) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf + dst) = v;
                }
                if (src + 4 < len + 4) {
                    v = *(u32 *)(buf + (src + 4));
                    *(u32 *)(buf + (dst + 4)) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf + (dst + 4)) = v;
                }
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 8);
        for (y = 0; y < len; y += 0x40) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32  v;
                dst = y + x * 8;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 3);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    *(u32 *)(buf - dst) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf - dst) = v;
                }
                if (src - 4 < len - 4) {
                    v = *(u32 *)(buf - (src - 4));
                    dst = dst - 4;
                    *(u32 *)(buf - dst) = v;
                } else {
                    dst = dst - 4;
                    v = fill;
                    *(u32 *)(buf - dst) = v;
                }
                t++;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}
