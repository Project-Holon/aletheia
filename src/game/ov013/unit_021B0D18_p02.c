/*
 * file:     unit_021B0D18_p02.c
 * unit:     yes
 * function: func_021B111C, func_021B11E8
 * address:  0x021B111C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B1488  0x021B1488  arm  ov013
 *   func_021B1498  0x021B1498  arm  ov013
 *   func_021B14A8  0x021B14A8  arm  ov013
 *   func_021B043C  0x021B043C  arm  ov013
 *   func_021B1634  0x021B1634  arm  ov013
 *   func_021B16B4  0x021B16B4  arm  ov013
 *   func_021B14F8  0x021B14F8  arm  ov013
 *   func_021B1810  0x021B1810  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   d_021B3C84  0x021B3C84  data  ov013  a4
 *   d_021B42C0  0x021B42C0  data  ov013  a4
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B3ADA  0x021B3ADA  data  ov013  a1
 *   func_021B0D18  0x021B0D18  arm  ov013
 *   func_02177044  0x02177044  arm  ov009
 */
#include "../../matched/include/G_Ctx42C0.h"

struct AdpcmState;
struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Voice {
    u32 f0;
    u32 f4;
    u32 f8;
    int fC;
    u8 f10;
    u8 f11;
    u8 pad12[2];
    u32 f14;
    u32 f18;
    u8 buf[0x474 - 0x1c];
    void *f474;
} Voice;

typedef struct {
    u8 pad0[0xc];
    u32 fC;
    u8 pad10[0x8];
    u32 f18;
    u32 f1C;
    u32 f20;
} Ctx3C84;

typedef struct {
    u8 pad0[0x8c0];
    int f8C0;
    u32 f8C4;
    u32 f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef struct {
    u8 pad0[0x10];
    int f10;
} Ctx60D8;

extern Voice *func_021B1488(void);
extern int func_021B1498(unsigned int i);
extern Voice *func_021B14A8(u8 id);
extern void func_021B043C(struct AdpcmState *hdr, void *dst, int n, int mode);
extern void func_021B1634(unsigned char *src, short *dst, unsigned int n);
extern void func_021B16B4(signed char *src, short *dst, unsigned int n, int fmt);
extern u32 func_021B14F8(struct Node *n);
extern int func_021B1810(struct Node *n, u32 idx);
extern void func_021B2FE4(void *p);
extern int func_02087988(void);
extern void func_0208799C(int);
extern u32 func_021B0D18(void);
extern void func_02177044(u8 bit, u32 a, u32 b);
int func_021B111C(void);
int func_021B11E8(void);
extern Ctx3C84 d_021B3C84;
extern struct Ctx42C0 d_021B42C0;
extern Ctx60D8 d_021B60D8;
extern u8 d_021B3ADA[][3];


/*
 * The three sample converters are passed q->fC as a fourth argument: the
 * original keeps the format in r3 across the argument set-up of all three
 * calls, which only a live fourth argument reproduces (a plain local or
 * the bare field lands in r0).
 */
int func_021B111C(void)
{
    Voice *v;
    int i;
    int n;
    u8 id;
    int irq;
    Voice *q;
    int fmt;

    v = func_021B1488();
    if (v == 0)
        return 0;

    irq = func_02087988();
    id = v->f11;
    n = func_021B1498(id);
    for (i = 0; i < n; i++) {
        q = func_021B14A8(id);
        fmt = q->fC;
        if (fmt >= 2)
            func_021B043C(q->f474, q->buf, q->f14, fmt);
        else if (fmt == 1)
            func_021B1634(q->f474, (short int *)q->buf, q->f14);
        else
            func_021B16B4(q->f474, (short int *)q->buf, q->f14, fmt);
        q->f474 = q->buf;
        func_021B14F8((struct Node *)q);
        if (func_021B1810((struct Node *)q, q->f11) < 0)
            func_021B2FE4(q);
    }
    func_0208799C(irq);
    return n;
}


static inline u32 clz32(u32 x)
{
    asm { clz x, x }
    return x;
}


int func_021B11E8(void)
{
    int i;
    int count;
    u32 mask;
    u32 z;

    if (d_021B3C84.f20 == 0)
        return 1;

    if (d_021B42C0.f8C8 == 0) {
        d_021B42C0.f8C8 = func_021B0D18();
        if (d_021B42C0.f8C8 != 0 && d_021B3C84.f18 != 0)
            return 0;
        return 1;
    }

    count = 1;
    if (d_021B60D8.f10 == 2)
        count = d_021B3ADA[d_021B42C0.f8D4][d_021B42C0.f8D0++];

    for (i = 0; i < count; i++) {
        mask = d_021B42C0.f8CC;
        z = clz32(mask);
        if (z == 32)
            break;
        d_021B42C0.f8CC = mask & ~(0x80000000 >> z);
        func_02177044((u8)(31 - z), d_021B42C0.f8C8, d_021B3C84.fC);
        if (d_021B42C0.f8CC == 0) {
            d_021B42C0.f8C0++;
            d_021B42C0.f8C8 = 0;
            d_021B42C0.f8CC = 0;
            break;
        }
    }
    return 1;
}
