/*
 * file:     trial_house_p08.c
 * unit:     yes
 * function: func_021CF3FC, func_021CF45C, func_021CF480, func_021CF498, func_021CF51C, func_021CF520, func_021CF52C, func_021CF54C
 * address:  0x021CF3FC
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
 *   func_0203996C  0x0203996C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_021CF128  0x021CF128  thumb  ov021
 *   func_0203D4D0  0x0203D4D0  arm
 *   d_021DE5FC     0x021DE5FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_021CF5AC  0x021CF5AC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0203038C  0x0203038C  arm
 *   func_021CF564  0x021CF564  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 */
#include "../../matched/include/Obj12140.h"
#include "../../matched/include/Obj20270.h"
#include "../../matched/include/Obj03621.h"

struct Entry;
struct Res021CF;
struct Evt;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Ent {
    u32 (*fn)(u32, void *, u32);   /* 0x00 */
    u32 f04;                       /* 0x04 */
    int f08;                       /* 0x08 */
    u32 f0c;                       /* 0x0C */
    u32 f10;                       /* 0x10 */
} Ent;

typedef struct Ctx {
    u32 f00;
    u32 f04;
    void *f08;
} Ctx;

extern struct Entry *func_0203996C(s32 idx);
extern struct Entry *func_020399A8(void);
extern u32 func_021CF128(void);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021CF5AC(struct Res021CF *r);
extern void *func_02188C80(void *p);
extern u32  func_0203038C(u32 a);
extern void func_021CF564(Ctx *c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020124E8(struct Obj *p);
void func_021CF3FC(u32 a, u32 b, int c);
void *func_021CF45C(u32 heap, u32 v);
int func_021CF480(void *a);
void func_021CF498(Ctx *c, u32 x, int idx);
u32 func_021CF51C(u32 *p);
void func_021CF520(u32 a, u32 b, u32 c, u32 d);
void func_021CF52C(u8 *p, u32 size, u32 heap);
void func_021CF54C(u8 *p);
extern char d_021DE5FC[];
extern Ent d_021DB4FC[];


/*
 * Calls func_0203D4D0 with 0x2707 on the handle of func_0203996C(0xff) when c == 1,
 * otherwise on the handle of func_020399A8().
 *
 * Addresses are Black-image addresses.
 */
void func_021CF3FC(u32 a, u32 b, int c)
{
    u32 h;

    if (c == 1) {
        h = (u32)func_0203996C(0xff);
        func_0203D4D0(h, b, 0x2707, func_021CF128(), a, 0, 0, 1);
    } else {
        h = (u32)func_020399A8();
        func_0203D4D0(h, b, 0x2707, func_021CF128(), a, 0, 0, 1);
    }
}


void *func_021CF45C(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x20, 1, d_021DE5FC, 0x6c);

    p[2] = v;
    p[6] = 0;
    return p;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF480(void *a)
{
func_021CF54C((u8 *)a);
func_021CF5AC((struct Res021CF *)a);
return func_020307B0(a);
}


/*
 * Picks a row of the 0x25-entry table at 0x021DB4FC (0x14 bytes each) and calls its
 * builder.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF498(Ctx *c, u32 x, int idx)
{
    u32 r;
    u32 y;
    void *p = c->f08;

    y = (u32)func_02188C80(p);

    if (idx >= 0x25) {
        idx = 0;
    }
    if (func_0203038C(0x15) < d_021DB4FC[idx].f10) {
        idx = 7;
    }
    if (d_021DB4FC[idx].f08 != -1) {
        func_021CF564(c);
    }
    r = d_021DB4FC[idx].fn(y, p, d_021DB4FC[idx].f0c);
    func_02012374((struct Evt *)x, (struct Evt **)r);
    c->f00 = (u32)func_020124E8((struct Obj *)r);
    c->f04 = d_021DB4FC[idx].f04;
}


/*
 * Unlabelled 4-byte accessor (returns the first word of its argument),
 * filed 2026-10-04 (wave D2) because it blocks ov077/ov078 callers.
 */
u32 func_021CF51C(u32 *p) { return *p; }


void func_021CF520(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj12140 *)((u8 *)(a)))->f4 != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(a) + 4))(a, ((struct Obj12140 *)((u8 *)(a)))->f4, c, d);
}
}


void func_021CF52C(u8 *p, u32 size, u32 heap)
{
    ((struct Obj20270 *)p)->f1C = func_02030734(heap, size, 1, d_021DE5FC, 0xe3);
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF54C(u8 *p)
{
    u32 v = ((struct Obj03621 *)p)->f1C;
    if (v != 0) {
        func_020307B0((void *)v);
        ((struct Obj03621 *)p)->f1C = 0;
    }
}
