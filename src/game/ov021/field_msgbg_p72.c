/*
 * file:     field_msgbg_p72.c
 * unit:     yes
 * function: func_021915EC, func_0219160C, func_0219161C, func_02191648, func_02191674, func_021916A8, func_021916E0
 * address:  0x021915EC
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
 *   func_020409B4  0x020409B4  arm  arm9
 *   func_02043B5C  0x02043B5C  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   func_02194A34  0x02194A34  thumb  ov021
 *   func_021904EC  0x021904EC  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02190550  0x02190550  thumb  ov021
 *   func_02190590  0x02190590  thumb  ov021
 *   func_02190604  0x02190604  thumb  ov021
 *   func_02190D2C  0x02190D2C  thumb  ov021
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02190D5C  0x02190D5C  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb
 *   func_02040618  0x02040618  arm
 *   func_021927F8  0x021927F8  thumb  ov021
 *   func_021927FC  0x021927FC  thumb  ov021
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_02045334  0x02045334  arm
 */
#include "../../matched/include/Obj00005.h"

struct Descriptor;
struct CharBuf;
struct Slot;
struct Cur;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021915EC;

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

typedef short          s16_0219161C;

typedef short          s16_02191648;

typedef short          s16_02191674;

typedef short          s16_021916A8;

typedef signed short   s16_021916E0;

extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020409B4(u32 a);
extern int func_02194A34(u32 a, u32 b);
extern void func_02190538(struct Slot *s);
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern void func_02190550(struct Slot *s, int x, int y, u32 z);
extern void func_02190590(struct Slot *s, int x, int y, u32 z);
extern void func_02190604(struct Slot *s, int x, int y, u32 z, u16 w);
extern int func_02190D48(void *a);
extern u32 func_02193210(u8 *p);
extern u32 *func_02190D2C(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_02190D5C(u32 *p);
extern u32 func_0201CE30(void *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u8 func_021927F8(u8 *p);
extern void func_021927FC(struct Cur *c, u32 win, u32 col);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern u8 func_0219320C(u8 *p);
extern void func_02045334(struct Descriptor *);
void func_021915EC(R *r);
void func_0219160C(int *p);
void func_0219161C(R *r, int b, int c, u32 d);
void func_02191648(R *r, int b, int c, u32 d);
void func_02191674(R *r, int b, int c, u32 d, u16 e);
void func_021916A8(R *r, u32 b, u16 c, u32 d);
u32 func_021916E0(u32 *a);


/*
 * Addresses are Black-image addresses.
 */
void func_021915EC(R *r)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)r->f18)), 0xFF);
    func_020409B4((u8)r->f0c->f02);
}


void func_0219160C(int *p)
{
    func_02194A34(p[4], p[6]);
}


void func_0219161C(R *r, int b, int c, u32 d)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC((u32 *)r->f0c, r->f14, r->f18);
    func_02190550(r->f20, b, c, d);
}


void func_02191648(R *r, int b, int c, u32 d)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC((u32 *)r->f0c, 0, r->f18);
    func_02190590(r->f20, b, c, d);
}


void func_02191674(R *r, int b, int c, u32 d, u16 e)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC((u32 *)r->f0c, 0, r->f18);
    func_02190604(r->f20, b, c, d, e);
}


void func_021916A8(R *r, u32 b, u16 c, u32 d)
{
    if (r->f1c != 0)
        func_02190D48((void *)r->f1c);
    r->f1c = (u32)func_02190D2C((u32 *)r->f0c, d, r->f18, b, c, func_02193210((u8 *)r->f0c + 0x160));
}


u32 func_021916E0(u32 *a)
{
    u32 r;
    func_020362DC();
    func_0203630C();
    r = func_02190D5C((u32 *)a[7]);
    a[9] = func_0201CE30((void *)(*(u32 *)(a[7] + 4)));
    func_02040618(1, 3, ((struct Obj00005 *)a)->f28);
    if (((struct Obj00005 *)a)->f28 < 0) {
        ((struct Obj00005 *)a)->f28 += 2;
        if (((struct Obj00005 *)a)->f28 > 0) {
            ((struct Obj00005 *)a)->f28 = 0;
        }
    }
    ((struct Obj00005 *)a)->f28 = -((struct Obj00005 *)a)->f28;
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)a) == 1) {
            func_021927FC((struct Cur *)a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            func_02045334((struct Descriptor *)a[6]);
        }
        break;
    case 1:
        if (func_0219320C((u8 *)(a[3] + 0x160)) == 0) {
            func_021928C0((struct Cur *)a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            func_02045334((struct Descriptor *)a[6]);
        }
        break;
    case 2:
        if (((struct Obj00005 *)a)->f28 != 0) {
            ((struct Obj00005 *)a)->f28 = 0;
            func_02040618(1, 3, ((struct Obj00005 *)a)->f28);
        }
        return 1;
    }
    return 0;
}
