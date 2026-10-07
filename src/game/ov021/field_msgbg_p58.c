/*
 * file:     field_msgbg_p58.c
 * unit:     yes
 * function: func_021907C4, func_0219082C, func_02190844
 * address:  0x021907C4
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
 *   func_02192B20  0x02192B20  thumb  ov021
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_02192BC0  0x02192BC0  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02190590  0x02190590  thumb  ov021
 */
#include "../../matched/include/Obj12067.h"

struct W;
struct Slot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021907C4;

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

typedef signed short   s16_0219082C;

typedef signed char    s8;

typedef short          s16_02190844;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

extern void func_02192F74(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e);
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern void func_02193044(u32 v);
extern u32 func_020307B0(void *p);
extern void func_02190538(struct Slot *s);
extern void func_02192BC0(u8 *p);
extern void func_02190590(struct Slot *s, int x, int y, u32 z);
Obj *func_021907C4(Fx *a, u32 b, u32 c, u32 d, u16 e, u16 f);
int func_0219082C(void *a);
void func_02190844(Slot **p, int x, int y, u32 z);
extern char d_021DDA50[];


/*
 * Addresses are Black-image addresses.
 */
Obj *func_021907C4(Fx *a, u32 b, u32 c, u32 d, u16 e, u16 f)
{
    Obj *r;

    a->f06 = 0xe;
    func_02192F74((struct W *)a);
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x560);
    r->owner = a;
    r->id = func_02192B20(c, d, e, f, a->f00);
    r->slot = (u32)func_021904EC((u32 *)a, b, r->id);
    func_02193044(1);
    return r;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219082C(void *a)
{
func_02192BC0((u8 *)(((struct Obj12067 *)((u8 *)(a)))->f0));
func_02190538((struct Slot *)(((struct Obj12067 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}


void func_02190844(Slot **p, int x, int y, u32 z)
{
    func_02190590(p[1], (u16)(x + 8), y, z);
}
