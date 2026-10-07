/*
 * file:     field_msgbg_p69.c
 * unit:     yes
 * function: func_02191164, func_02191184, func_021911B4
 * address:  0x02191164
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
 *   func_021904EC  0x021904EC  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02190590  0x02190590  thumb  ov021
 */
#include "../../matched/include/Obj17934.h"

struct Descriptor;
struct CharBuf;
struct Slot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

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

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020409B4(u32 a);
extern void func_02190538(struct Slot *s);
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern void func_02190590(struct Slot *s, int x, int y, u32 z);
void func_02191164(P *p);
void func_02191184(Q *q, u32 b, int c, u32 d);
u32 func_021911B4(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_02191164(P *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->f00)), 0xFF);
    func_020409B4((u8)p->f14->f02);
}


void func_02191184(Q *q, u32 b, int c, u32 d)
{
    if (q->f08 != 0)
        func_02190538(q->f08);
    q->f08 = func_021904EC(q->f14, 0, q->f00);
    func_02190590(q->f08, (u16)(b + 8), c, d);
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021911B4(u8 *p)
{
    return ((struct Obj17934 *)p)->f0;
}
