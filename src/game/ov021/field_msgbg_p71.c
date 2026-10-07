/*
 * file:     field_msgbg_p71.c
 * unit:     yes
 * function: func_0219131C, func_02191348, func_02191388, func_021914CC, func_02191504, func_02191558, func_021915B4
 * address:  0x0219131C
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
 *   func_02045808  0x02045808  arm
 *   func_0219492C  0x0219492C  thumb  ov021
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_02194990  0x02194990  thumb  ov021
 *   func_0219499C  0x0219499C  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02194974  0x02194974  thumb  ov021
 *   func_02194984  0x02194984  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb
 *   func_02040618  0x02040618  arm
 *   func_021927F8  0x021927F8  thumb  ov021
 *   func_021927FC  0x021927FC  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02193228  0x02193228  thumb  ov021
 *   func_021932A0  0x021932A0  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_0201CE34  0x0201CE34  thumb
 *   func_02193260  0x02193260  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_02193170  0x02193170  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02194A00  0x02194A00  thumb  ov021
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02030734  0x02030734  arm  arm9
 *   func_020457B0  0x020457B0  arm  arm9
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02194A48  0x02194A48  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj00126.h"

struct U16Vec;
struct CharBuf;
struct Descriptor;
struct Cur;
struct Fx;
struct G;
struct Slot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_0219131C;

typedef signed char    s8;

typedef signed short   s16_02191388;

typedef short          s16_021914CC;

typedef struct S {
    u8  f00;
    u8  f01;
    u8  pad02[6];
    u32 f08;
    u32 sub[2];
    u8 *f14;
} S;

typedef short          s16_02191558;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

typedef signed short   s16_021915B4;

extern void func_02045808(struct U16Vec *vec);
extern u32 func_02082BCC(u32, u32, u32);
extern void func_021927E8(u32 *p);
extern void func_0219492C(u8 *p, int i);
extern u32 func_02194990(u32, u32);
extern void func_0219499C(u8 *p, int i, u32 b, u32 c);
extern u32 func_02193210(u8 *p);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_020409B4(u32);
extern int func_02194974(u8 *p, int i);
extern u32 func_02194984(u32, u32);
extern u32 func_0201CE30(void *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u8 func_021927F8(u8 *p);
extern void func_021927FC(struct Cur *c, u32 win, u32 col);
extern void func_02045334(struct Descriptor *);
extern int func_02193228(u8 *p);
extern void func_021932A0(u32 a, int f);
extern u8 func_0219320C(u8 *p);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern u32 func_0201CE34(void *p);
extern int func_02193260(u8 *p, u32 q);
extern void func_020061E4(u32);
extern void func_0201CE38(void *p);
extern void func_02193170(u32);
extern void func_02193044(u32);
extern u32 func_02194A00(u32, u8, u8, u8, u8, u32);
extern void func_021927C0(struct G *g, struct Fx *a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020307B0(void *p);
extern void func_02190538(struct Slot *s);
extern int func_02190D48(void *a);
extern u32 func_02194A48(u32 a, struct Descriptor *b);
int func_0219131C(u32 a);
u32 func_02191348(u32 *a, u32 b);
u32 func_02191388(u32 *a);
void func_021914CC(S *s);
void func_02191504(u16 *a, u32 *b, u32 c, u32 d, u16 e, u16 f, u32 g);
R *func_02191558(Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
int func_021915B4(void *a);
extern char d_021DDA50[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219131C(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
func_0219492C((u8 *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8), *(u8 *)((u8 *)(a) + 1));
func_021927E8((u32 *)(a + 12));
return func_02082BCC(a, 0, 52);
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_02191348(u32 *a, u32 b)
{
    u32 x = func_02194990(a[2], *((u8 *)a + 1));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)x)), 255);
    func_0219499C((u8 *)a[2], *((u8 *)a + 1), b, func_02193210((u8 *)(a[5] + 0x160)));
    return func_020409B4(func_02045730((struct Descriptor *)x));
}


u32 func_02191388(u32 *a)
{
    u32 h;
    u32 r;
    u32 w;
    u32 c;

    if (func_02194974((u8 *)a[2], *((u8 *)a + 1)) == 0) {
        return 0;
    }
    h = func_02194984(a[2], *((u8 *)a + 1));
    r = func_0201CE30((void *)h);
    func_02040618(1, 3, *(s16_02191388 *)((u8 *)a + 2));
    if (*(s16_02191388 *)((u8 *)a + 2) < 0) {
        *(s16_02191388 *)((u8 *)a + 2) += 2;
        if (*(s16_02191388 *)((u8 *)a + 2) > 0) {
            *(s16_02191388 *)((u8 *)a + 2) = 0;
        }
    }
    *(s16_02191388 *)((u8 *)a + 2) = -*(s16_02191388 *)((u8 *)a + 2);
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)(a + 3)) == 1) {
            w = func_02194990(a[2], *((u8 *)a + 1));
            func_021927FC((struct Cur *)(a + 3), (u32)func_02045770((struct Descriptor *)w), 15);
            func_02045334((struct Descriptor *)w);
        }
        if (func_02193228((u8 *)(a[5] + 0x160)) != 0) {
            func_021932A0(h, 1);
        } else {
            func_021932A0(h, 0);
        }
        break;
    case 1:
        w = func_02194990(a[2], *((u8 *)a + 1));
        c = (u32)func_02045770((struct Descriptor *)w);
        if (func_0219320C((u8 *)(a[5] + 0x160)) == 0) {
            func_021928C0((struct Cur *)(a + 3), c, 15);
        }
        if (func_02193260((u8 *)(a[5] + 0x160), func_0201CE34((void *)h)) != 0) {
            if (func_0219320C((u8 *)(a[5] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)h);
            func_021927FC((struct Cur *)(a + 3), c, 15);
            func_021932A0(h, 0);
        }
        func_02045334((struct Descriptor *)w);
        break;
    case 2:
        if (*(s16_02191388 *)((u8 *)a + 2) != 0) {
            *(s16_02191388 *)((u8 *)a + 2) = 0;
            func_02040618(1, 3, *(s16_02191388 *)((u8 *)a + 2));
        }
        return 1;
    }
    return 0;
}


void func_021914CC(S *s)
{
    u32 x;

    if (func_0219320C(s->f14 + 0x160) == 0) {
        x = func_02194990(s->f08, s->f01);
        func_021928C0((struct Cur *)s->sub, (u32)func_02045770((struct Descriptor *)x), 0xF);
        func_02045334((struct Descriptor *)x);
    }
}


void func_02191504(u16 *a, u32 *b, u32 c, u32 d, u16 e, u16 f, u32 g)
{
    a[3] = 11;
    b[4] = ((struct Obj00126 *)a)->f15C;
    func_02193170(a[0]);
    func_02193044(0);
    b[6] = func_02194A00(b[4], c, d, e, f, g);
    func_021927C0((struct G *)b, (struct Fx *)a);
}


R *func_02191558(Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g)
{
    R *r;

    r = func_02030734(a->f00, 0x2C, 1, d_021DDA50, 0xCA7);
    r->f0c = a;
    r->f14 = b;
    r->f08 = (u32)func_020457B0(0xA0, a->f00);
    func_02191504((u16 *)a, (u32 *)r, d, e, f, g, c);
    if (c == 1)
        r->f28 = 8;
    return r;
}


int func_021915B4(void *a)
{
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C != 0) {
    func_02190D48((void *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20 != 0) {
    func_02190538((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    func_02045808((struct U16Vec *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
func_02194A48(((struct Obj00005 *)((u8 *)(a)))->f10, (struct Descriptor *)(((struct Obj00005 *)((u8 *)(a)))->f18));
func_021927E8((u32 *)a);
return func_020307B0(a);
}
