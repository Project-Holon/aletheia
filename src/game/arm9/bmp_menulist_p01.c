/*
 * file:     bmp_menulist_p01.c
 * unit:     yes
 * function: func_0201FF30, func_020200CC
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
 *   func_02020970  0x02020970  thumb
 */
#include "../../matched/include/Obj11266.h"

struct CharBuf;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj_0201FF30 {
    void *arr;
    void *unk04;
    void *unk08;
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
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    u8 pad1C[0x28 - 0x1C];
    void *f28;
    u8 pad2C[0x34 - 0x2C];
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
    u32 f3C;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
    u8 f46;
    u8 f47;
    u16 f48;
};

struct Src {
    u32 w[13];
};

typedef signed int     s32;

struct Elem {
    void *unk00;
    s32   f4;
};

struct Obj_020200CC {
    struct Elem *arr;
    u8  pad_04[0x12 - 0x04];
    u16 f12;
    u8  pad_14[0x1A - 0x14];
    u16 f1Alo : 7;
    u16 f1Amid : 2;
    u16 f1Atop : 7;
    u8  pad_1C[0x40 - 0x1C];
    u16 f40;
    u16 f42;
    u8  pad_44[3];
    u8  f47;
    u8  pad_48[2];
    u8  f4A;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02020D18(u32 heap);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202055C(struct Obj_0201FF30 *obj, u16 row, u16 col, u16 n, u32 flag);
extern void func_020206C0(struct Obj_0201FF30 *o);
extern void func_02020A34(struct Obj_0201FF30 *obj, void *arg1);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020061E4(u32 id);
extern u32  func_02020970(struct Obj_020200CC *o, u8 a, u8 b, u8 c);
extern char g_020A7390[];


struct Obj_0201FF30 *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap)
{
    struct Obj_0201FF30 *obj;
    int i;
    u32 *d;
    u32 *s;

    obj = (struct Obj_0201FF30 *)func_02030734(heap, 0x50, 1, g_020A7390, 0x69);
    *(struct Src *)obj = *src;
    obj->f3C = (u32)func_02020D18(heap);
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
    obj->f36 = (u8)obj->f1Alo;
    obj->f38 = (u8)obj->f1Amid2;
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
    func_0202055C(obj, obj->f40, 0, obj->rows, 1);
    func_020206C0(obj);
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
s32 func_020200CC(struct Obj_020200CC *o)
{
    u32 keys = func_020362DC();
    u32 one = 1;
    u32 held = func_0203633C();

    o->f47 = 0;

    if (keys & one) {
        func_020061E4(0x54C);
        return o->arr[o->f40 + o->f42].f4;
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
        switch (o->f1Amid) {
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
            if (func_02020970(o, 1, (u8)o->f12, 0) == 0) {
                func_020061E4(0x548);
                o->f47 = 3;
            }
            return -1;
        }
        if (v != 0) {
            if (func_02020970(o, 1, (u8)o->f12, 1) == 0) {
                func_020061E4(0x548);
                o->f47 = 4;
            }
            return -1;
        }
    }
    return -1;
}
