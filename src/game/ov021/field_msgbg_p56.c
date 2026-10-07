/*
 * file:     field_msgbg_p56.c
 * unit:     yes
 * function: func_02190680, func_02190708, func_02190728, func_02190740
 * address:  0x02190680
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
 *   func_02030734  0x02030734  arm  arm9
 *   func_021904EC  0x021904EC  thumb  ov021
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_021930C0  0x021930C0  thumb  ov021
 *   func_02193144  0x02193144  thumb  ov021
 *   func_02193170  0x02193170  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02190550  0x02190550  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../../matched/include/Obj12065.h"
#include "../../matched/include/Obj12066.h"

struct W;
struct Slot;
struct Obj;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02190680;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct Obj {
    u32 id;
    u32 slot;
    Fx *owner;
} Obj;

typedef short          s16_02190708;

typedef signed short   s16_02190728;

typedef signed char    s8;

typedef signed short   s16_02190740;

extern void func_02192F74(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern void func_02193170(u32 heap);
extern u32 func_020307B0(void *p);
extern void func_02190538(struct Slot *s);
extern int func_02193130(struct Descriptor *a);
extern u32 func_020409B4(u32);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02190550(struct Slot *s, int x, int y, u32 z);
Obj *func_02190680(Fx *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g);
void *func_02190708(Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
int func_02190728(void *a);
int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern char d_021DDA50[];


/*
 * Addresses are Black-image addresses.
 */
Obj *func_02190680(Fx *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g)
{
    u8 k;
    Obj *r;

    k = a->f02;
    func_02192F74((struct W *)a);
    if (g == 0xe) {
        k = a->f04;
    }
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x483);
    r->owner = a;
    r->id = func_021930C0(k, a->f00, c, d, e, f, g);
    r->slot = (u32)func_021904EC((u32 *)a, b, r->id);
    if (g == 0xe) {
        func_02193144(a->f00);
        func_02193044(1);
    } else {
        func_02193170(a->f00);
    }
    return r;
}


void *func_02190708(Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e)
{
    p->f06 = 0xE;
    return func_02190680(p, a, b, c, d, e, p->f06);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02190728(void *a)
{
func_02193130((struct Descriptor *)(((struct Obj12065 *)((u8 *)(a)))->f0));
func_02190538((struct Slot *)(((struct Obj12065 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}


int func_02190740(u32 a, u32 b, u32 c, u32 d)
{
func_02190550((struct Slot *)(((struct Obj12066 *)((u8 *)(a)))->f4), b, c, d);
return func_020409B4(func_02045730((struct Descriptor *)(((struct Obj12066 *)((u8 *)(a)))->f0)));
}
