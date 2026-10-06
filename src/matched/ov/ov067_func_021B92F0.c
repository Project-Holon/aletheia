/*
 * function: func_021B92F0
 * address:  0x021B92F0
 * packet:   pkt_ov067_021B92F0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9280  0x021B9280  thumb
 *   func_020355C4  0x020355C4  arm
 *   func_0202EB04  0x0202EB04  thumb
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct H {
    u16 v;
};

struct Pair {
    u32 a;
    u32 b;
};

struct S {
    u8 _0[0x11];
    u8 f11;
    u8 _12[0x28 - 0x12];
    struct Pair *f28;
    u8 _2c[0x30 - 0x2c];
    void *f30;
    u8 _34[0x40 - 0x34];
    struct H **f40;
    u8 _44[0x5e - 0x44];
    u16 f5e;
    u8 _60[0x62 - 0x60];
    s16 f62;
};

extern void func_021B9280(u8 *p, int a, u32 b);
struct CodeIn;
extern u8 func_020355C4(void);
extern void func_0202EB04(struct CodeIn *p);

void func_021B92F0(struct S *p, u32 a1, u32 a2)
{
    if (a2 < p->f5e)
        func_021B9280((u8 *)p, a2, (u16)(p->f40[p->f28[p->f62 + a2].a]->v >> 12));
    if (a1 < p->f5e && func_020355C4() == 0) {
        func_0202EB04(p->f30);
        func_021B9280((u8 *)p, a1, p->f11);
    }
}
