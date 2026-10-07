/*
 * file:     field_msgbg_p65.c
 * unit:     yes
 * function: func_02190D5C, func_02190DCC, func_02190E40
 * address:  0x02190D5C
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
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE34  0x0201CE34  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_02193228  0x02193228  thumb  ov021
 *   func_02193260  0x02193260  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021932A0  0x021932A0  thumb  ov021
 *   func_02030734  0x02030734  arm  arm9
 *   func_020457B0  0x020457B0  arm  arm9
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_021930C0  0x021930C0  thumb  ov021
 *   func_02193144  0x02193144  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj04888.h"

struct G;
struct W;
struct U16Vec;
struct Slot;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short          s16_02190DCC;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct Obj2 {
    u32 id;
    u32 f04;
    u32 f08;
    u32 b;
    u32 f10;
    Fx *owner;
    u32 sub[2];
} Obj2;

typedef signed short   s16_02190E40;

typedef signed char    s8;

extern u32 func_0201CE30(void *p);
extern u32 func_0201CE34(void *p);
extern void func_0201CE38(void *p);
extern int func_02193228(u8 *p);
extern int func_02193260(u8 *p, u32 q);
extern u8 func_0219320C(u8 *p);
extern void func_020061E4(u32 a);
extern void func_021932A0(u32 a, int f);
extern void func_02192F74(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021927C0(struct G *g, struct Fx *a);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
extern u32 func_020307B0(u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_02190538(struct Slot *s);
extern int func_02190D48(void *a);
extern void func_021927E8(u32 *p);
extern int func_02193130(struct Descriptor *a);
int func_02190D5C(u32 *p);
Obj2 *func_02190DCC(Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f);
int func_02190E40(u32 a);
extern char d_021DDA50[];


/*
 * Addresses are Black-image addresses.
 */
int func_02190D5C(u32 *p)
{
    int r = func_0201CE30((void *)p[1]);

    switch (r) {
    case 0:
        if (func_02193228((u8 *)(p[2] + 0x160)) != 0) {
            func_021932A0(p[1], 1);
        } else {
            func_021932A0(p[1], 0);
        }
        break;
    case 1:
        if (func_02193260((u8 *)(p[2] + 0x160), func_0201CE34((void *)p[1])) != 0) {
            if (func_0219320C((u8 *)(p[2] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)p[1]);
            r = 0;
            func_021932A0(p[1], 0);
        }
        break;
    case 2:
        break;
    }
    return r;
}


Obj2 *func_02190DCC(Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f)
{
    Obj2 *r;

    a->f06 = 0xe;
    func_02192F74((struct W *)a);
    r = func_02030734(a->f00, 0x20, 1, d_021DDA50, 0x8FF);
    r->owner = a;
    r->b = b;
    r->id = func_021930C0(a->f04, a->f00, c, d, e, f, a->f06);
    r->f10 = (u32)func_020457B0(0xA0, a->f00);
    func_021927C0((struct G *)r->sub, a);
    func_02193144(a->f00);
    func_02193044(1);
    return r;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02190E40(u32 a)
{
func_02193130((struct Descriptor *)(((struct Obj04888 *)((u8 *)(a)))->f0));
if (((struct Obj04888 *)((u8 *)(a)))->f4 != 0) {
    func_02190D48((void *)(((struct Obj04888 *)((u8 *)(a)))->f4));
}
if (((struct Obj04888 *)((u8 *)(a)))->f8 != 0) {
    func_02190538((struct Slot *)(((struct Obj04888 *)((u8 *)(a)))->f8));
}
func_02045808((struct U16Vec *)(((struct Obj04888 *)((u8 *)(a)))->f10));
func_021927E8((u32 *)(a + 24));
return func_020307B0(a);
}
