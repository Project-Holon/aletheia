/*
 * file:     field_msgbg_p73.c
 * unit:     yes
 * function: func_02191794, func_021917C0, func_021917C4, func_02191830
 * address:  0x02191794
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
 *   func_02045334  0x02045334  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_02193170  0x02193170  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_021947E8  0x021947E8  thumb  ov021
 *   func_02194940  0x02194940  thumb  ov021
 *   func_0201D304  0x0201D304  thumb  arm9
 *   func_0201D42C  0x0201D42C  thumb  arm9
 */
#include "../../matched/include/Obj03112.h"

struct Descriptor;
struct Cur;
struct StrObj;
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

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

extern u8 func_0219320C(u8 *p);
extern void *func_02045770(struct Descriptor *a);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern void func_02045334(struct Descriptor *a);
extern void func_02193170(u32);
extern void func_02193044(u32);
extern u32 func_02193210(u8 *p);
extern void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n);
extern void func_02194940(u8 *p, int i);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
void func_02191794(R *r);
int func_021917C0(int *p);
void func_021917C4(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i);
void func_02191830(Q *q, u32 a, u8 *w, u8 *h);


/*
 * Addresses are Black-image addresses.
 */
void func_02191794(R *r)
{
    if (func_0219320C((u8 *)r->f0c + 0x160) == 0) {
        func_021928C0((struct Cur *)r, (u32)func_02045770((struct Descriptor *)r->f18), 0xF);
        func_02045334((struct Descriptor *)r->f18);
    }
}

int func_021917C0(int *p)
{
    return p[9];
}


void func_021917C4(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i)
{
    a[3] = 11;
    b[3] = ((struct Obj03112 *)a)->f15C;
    b[2] = d;
    b[1] = i;
    func_02193170(a[0]);
    func_02193044(0);
    func_021947E8((u8 *)b[3], b[2], c, e, f, g, h, 0xFF, 0, func_02193210((u8 *)((u32)a + 0x15C + 4)), 2, 0);
    func_02194940((u8 *)b[3], b[2]);
}


/*
 * The margins are locals (mx = 2, my = 0): the `+ my` add is folded to a
 * move after coalescing, which is the original's `adds r0, r0, #0` at +0x22.
 * A literal `+ 0` folds early and loses it.
 *
 * Addresses are Black-image addresses.
 */
void func_02191830(Q *q, u32 a, u8 *w, u8 *h)
{
    u32 mx = 2, my = 0;
    u32 tw = func_0201D304((struct StrObj *)a, (int)q->f08, 0) + mx;
    u32 th = func_0201D42C((struct StrObj *)a, (void *)((int)q->f08)) + my;
    u32 m = tw;
    tw >>= 3;
    if (m & 7) tw++;
    m = th;
    th >>= 3;
    *w = tw;
    if (m & 7) th++;
    *h = th;
}
