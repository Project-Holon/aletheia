/*
 * file:     bmp_menulist_p02.c
 * unit:     yes
 * function: func_0202020C, func_02020234, func_02020268, func_02020298, func_020202EC, func_020202FC, func_02020314, func_02020324, func_02020344, func_02020350, func_02020408
 * address:  0x0202020C
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
 *   func_02020324  0x02020324  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 */
#include "../../matched/include/Obj08775.h"
#include "../../matched/include/Obj08776.h"

struct Obj;
struct D;
struct Descriptor;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef signed char s8;

struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};

struct Elem {
    u32 unk00;
    u32 unk04;
};

struct Obj_02020268 {
    struct Elem *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
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
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    u32 f1C;
    u16 f20;
    u16 f22;
    u8 pad24[0x34 - 0x24];
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36 : 6;
    u8 f36top : 2;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
    u8 pad39[0x40 - 0x39];
    u16 f40;
    u16 f42;
};

struct Target {
    u32 win;
    u8  dirty;
};

struct Obj_02020408 {
    void *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
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
    u8 pad1A[0x28 - 0x1A];
    struct Target *f28;
    u32 f2C;
    u32 f30;
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
};

extern void func_02020D3C(struct D *p);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202055C(struct Obj *obj, u16 row, u16 col, u16 n, u32 flag);
extern void func_020206C0(struct Obj *obj);
void func_02020234(u8 *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);



void func_0202020C(struct Obj *o, u16 *a, u16 *b)
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
    func_0202055C((struct Obj *)p, ((struct Obj08776 *)p)->f40, 0, ((struct Obj08776 *)p)->f12, 1);
    func_020206C0((struct Obj *)p);
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void func_02020268(struct Obj_02020268 *obj, u8 a, u8 b, u8 c)
{
    obj->f17hi = a;
    obj->f18lo = b;
    obj->f18hi = c;
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void func_02020298(struct Obj_02020268 *obj, u8 a, u8 b, u8 c)
{
    obj->f34lo = a;
    obj->f34hi = b;
    obj->f35lo = c;
    obj->f38top = 1;
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void func_020202EC(struct Obj_02020268 *obj, u16 *out)
{
    *out = obj->f40 + obj->f42;
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void func_020202FC(struct Obj_02020268 *obj, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = obj->f40;
    }
    if (b != 0) {
        *b = obj->f42;
    }
}

u16 func_02020324(struct Obj_02020268 *obj, u32 n);



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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
u16 func_02020314(struct Obj_02020268 *obj)
{
    return func_02020324(obj, obj->f42);
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
u16 func_02020324(struct Obj_02020268 *obj, u32 n)
{
    return (u16)(obj->f17lo + n * (u8)(obj->f22 + obj->f1Amid));
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
u32 func_02020344(struct Obj_02020268 *obj, u32 n)
{
    return obj->arr[n].unk04;
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
 *   func_02020344  arr[n].unk04, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
u32 func_02020350(struct Obj_02020268 *obj, u32 what)
{
    switch (what) {
    case 0:  return obj->unk04;
    case 1:  return obj->unk08;
    case 2:  return obj->count;
    case 3:  return obj->rows;
    case 5:  return obj->f14;
    case 6:  return obj->f15;
    case 7:  return obj->f16;
    case 8:  return obj->f17lo;
    case 9:  return obj->f22 + obj->f1Amid;
    case 10: return obj->f17hi;
    case 11: return obj->f18lo;
    case 12: return obj->f18hi;
    case 13: return obj->f1Alo;
    case 14: return obj->f1Amid;
    case 15: return obj->f1Apad;
    case 16: return obj->f1Amid2;
    case 17: return obj->f1Atop;
    case 18: return obj->unk0C;
    case 19: return obj->f1C;
    }
    return -1;
}


#define COLOR(l, s, b) ((u16)((((l) & 0x1f) << 10) | (((s) & 0x1f) << 5) | ((b) & 0x1f)))


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
void func_02020408(struct Obj_02020408 *obj, const void *text, u32 x, u32 y, u32 sel)
{
    if (text == 0)
        return;
    if (obj->f38top) {
        if (sel) {
            u32 a = obj->f2C;
            struct Target *t = obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)obj->f28->win), x, y, text, obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    } else {
        if (sel) {
            u32 a = obj->f2C;
            struct Target *t = obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, obj->f30,
                          COLOR(obj->f17hi, obj->f18hi, obj->f18lo));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)obj->f28->win), x, y, text, obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    }
}
