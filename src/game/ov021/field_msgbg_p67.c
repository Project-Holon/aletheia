/*
 * file:     field_msgbg_p67.c
 * unit:     yes
 * function: func_02190F7C, func_02190F9C, func_02190FA0, func_02191008
 * address:  0x02190F7C
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
 *   func_02030734  0x02030734  arm  arm9
 *   func_020457B0  0x020457B0  arm  arm9
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02192B20  0x02192B20  thumb  ov021
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02193144  0x02193144  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_02192BC0  0x02192BC0  thumb  ov021
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00005.h"

struct Descriptor;
struct CharBuf;
struct G;
struct W;
struct U16Vec;
struct Slot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02190F7C;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    Fx *f14;
} P;

typedef short          s16_02190FA0;

typedef struct Obj2 {
    u32 id;
    u32 f04;
    u32 f08;
    u32 b;
    u32 f10;
    Fx *owner;
    u32 sub[2];
} Obj2;

typedef signed short   s16_02191008;

typedef signed char    s8;

extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020409B4(u32 a);
extern void func_02192F74(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021927C0(struct G *g, struct Fx *a);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e);
extern u32 func_020307B0(u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_02190538(struct Slot *s);
extern int func_02190D48(void *a);
extern void func_021927E8(u32 *p);
extern void func_02192BC0(u8 *p);
void func_02190F7C(P *p);
void *func_02190F9C(void **p);
Obj2 *func_02190FA0(Fx *a, u32 b, u32 c);
int func_02191008(u32 a);
extern char d_021DDA50[];


/*
 * Addresses are Black-image addresses.
 */
void func_02190F7C(P *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->f00)), 0xFF);
    func_020409B4((u8)p->f14->f02);
}

/*
 * Getter: returns the first word of the object.  Unlabelled in the listing,
 * reached from func_021D1C8C.
 *
 * Addresses are Black-image addresses.
 */
void *func_02190F9C(void **p)
{
    return *p;
}


Obj2 *func_02190FA0(Fx *a, u32 b, u32 c)
{
    Obj2 *r;

    a->f06 = 0xe;
    func_02192F74((struct W *)a);
    r = func_02030734(a->f00, 0x20, 1, d_021DDA50, 0x9F4);
    r->owner = a;
    r->b = b;
    r->id = func_02192B20(1, c, 0x1E, 4, a->f00);
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
int func_02191008(u32 a)
{
func_02192BC0((u8 *)(((struct Obj00005 *)((u8 *)(a)))->f0));
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02190D48((void *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    func_02190538((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f10));
func_021927E8((u32 *)(a + 24));
return func_020307B0(a);
}
