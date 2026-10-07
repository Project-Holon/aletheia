/*
 * file:     weather_task_p83.c
 * unit:     yes
 * function: func_021A6D9C, func_021A6DA4, func_021A6DC0, func_021A6DC4, func_021A6E30, func_021A6F18, func_021A6F24
 * address:  0x021A6D9C
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
 *   func_020307B0  0x020307B0  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021A3674  0x021A3674  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb
 *   func_021A71E4  0x021A71E4  thumb
 *   func_021A70D0  0x021A70D0  thumb
 *   func_021A7198  0x021A7198  thumb
 *   func_021A712C  0x021A712C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012AC0  0x02012AC0  thumb
 *   func_0219F058  0x0219F058  thumb  ov021
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_021A3664  0x021A3664  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021A7258  0x021A7258  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   d_021DDF64     0x021DDF64  data  a1
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   d_021DDF38  0x021DDF38  data  a4
 */
#include "../../matched/include/Obj18063.h"

struct V;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct Obj00020;
struct H4;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct Holder {
    int mode;
    void *f04;
    void *f08;
} Holder;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_020307B0(void *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_021A3674(u8 *p, u32 b, u32 c);
extern void *func_021A3074(unsigned char *p);
extern u32 func_0216D5F8(void *a);
extern int func_021A71E4(u32 a, u32 *b, u16 *c, u32 d);
extern void func_021A70D0(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern int func_021A7198(u32 a, u32 *b, struct V *c, u32 d);
extern void func_021A712C(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void *func_02188C80(void *o);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02188CAC(u8 *p, u32 v);
extern void *func_02188CB4(struct Obj00020 *p);
extern u8 func_02012AC0(const struct Rec44 *p);
extern void func_0219F058(u32 a, u16 *o1, u16 *o2);
extern void func_021A35E0(u32 *p, u32 heap);
extern void func_021A3664(u32 *p, u32 heap);
extern void func_021A305C(char *p, u32 b);
extern struct H4 *func_02012AB8(struct Rec44 *p);
extern void func_021A7258(void *o, Holder *h, int mode, VecFx32 *pos, u16 e, u16 f, u16 g);
extern void *func_0216D888(void *m);
extern void func_02188D40(u8 *p, u32 v);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188CA4(u8 *p);
void func_021A6D9C(void *a0);
void func_021A6DA4(u32 *a);
u32 func_021A6DC0(u8 *p);
void func_021A6DC4(u32 *b, void *a);
void func_021A6E30(void *o, VecFx32 *pos, u16 e);
int func_021A6F18(u32 a, u32 b, u32 c, u32 d);
void func_021A6F24(u32 a, int *v);
extern char d_021DDF64;


/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6D9C(void *a0)
{
    func_020307B0(a0);
}


void func_021A6DA4(u32 *a)
{
    u32 x = func_020362DC();
    u32 y = func_0203630C();
    func_021A3674((u8 *)(*a), x, y);
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A6DC0(u8 *p)
{
    return ((struct Obj18063 *)p)->f0;
}


void func_021A6DC4(u32 *b, void *a)
{
    u16 out2[6];
    u16 out1[4];
    u32 k = func_0216D5F8(func_021A3074(((unsigned char **)b)[1]));
    if (b[0] == 0) {
        if (func_021A71E4((u32)a, b, out1, k) != 0) {
            func_021A70D0((u32)a, b, k, 0, (u32)out1, 0, 0);
        }
    } else {
        if (func_021A7198((u32)a, b, (struct V *)out2, k) != 0) {
            func_021A712C((u32)a, b, k, 0, (u32)out2, 0, 0);
        }
    }
    b[2] = 0;
}


/*
 * Creates the 12-byte model holder for a field-map object, loads its
 * model, and places it through func_021A7258 in the mode the object's
 * record asks for (0: at pos; else attached to the record's anchor).
 */
void func_021A6E30(void *o, VecFx32 *pos, u16 e)
{
    void *r;
    u16 heap;
    Holder *h;
    int mode;
    void *m;
    VecFx32 *anchor;
    u16 anim[2];

    r = func_020127A4(func_020120F4(func_02188C80(o)));
    heap = func_02188C84(o);
    h = func_02030734(heap, sizeof(Holder), 1, &d_021DDF64, 0xbd);
    func_02188CAC(o, (u32)h);
    h->f04 = func_02188CB4(o);
    mode = func_02012AC0(r);
    h->mode = 2;
    m = func_021A3074(h->f04);
    func_0219F058((u32)m, &anim[0], &anim[1]);
    if (mode == 0) {
        func_021A35E0(h->f04, heap);
        func_021A3664(h->f04, heap);
        func_021A305C(h->f04, e);
        func_021A7258(o, h, mode, pos, e, anim[0], anim[1]);
    } else {
        anchor = (VecFx32 *)func_02012AB8(r);
        func_021A3664(h->f04, heap);
        func_021A35E0(h->f04, heap);
        func_021A305C(h->f04, e);
        func_021A7258(o, h, mode, anchor, e, anim[0], anim[1]);
    }
    func_02188D40(o, (u32)func_0216D888(m));
    func_021A3038(h->f04, pos);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6F18(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0((void *)func_02188CA4((u8 *)a));
}

extern void (*const d_021DDF38[])(u32 a, u32 *p);


void func_021A6F24(u32 a, int *v)
{
    u32 *p = (u32 *)func_02188CA4((u8 *)a);
    d_021DDF38[p[0]](a, p);
    func_021A3038((unsigned char *)p[1], (struct VecFx32 *)v);
}
