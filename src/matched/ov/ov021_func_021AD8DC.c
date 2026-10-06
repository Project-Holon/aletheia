/*
 * function: func_021AD8DC
 * address:  0x021AD8DC
 * packet:   pkt_ov021_021AD8DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_021AD82C  0x021AD82C  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Desc {
    u8 n;
    u8 lo : 3;
    u8 mid : 3;
    u8 b6 : 1;
    u8 b7 : 1;
    u16 pad2;
    u16 h4;
    u16 h6;
} Desc;

typedef struct P {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
} P;

typedef unsigned int   u32;
extern u8 func_021ABE28(u8 *p);
struct A;
struct B;
extern void func_021AD82C(struct A *a, struct B *b, int c);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);

void func_021AD8DC(P *a, Desc *d, int c)
{
    int r7;

    r7 = func_021ABE28((u8 *)a->f0);
    func_02046FF8((int *)(a->f8 = (int)func_02046E24(c, d->h4 + r7)));
    a->f18 = (int)func_02046E24(c, d->h6 + r7);
    func_021AD82C((struct A *)((char *)a + 0x28), (struct B *)a, 0);
    r7 += d->mid;
    func_02046FF8((int *)(a->fc = (int)func_02046E24(c, d->h4 + r7)));
    a->f1c = (int)func_02046E24(c, d->h6 + r7);
    func_021AD82C((struct A *)((char *)a + 0x40), (struct B *)a, 1);
    func_02046FF8((int *)(a->f10 = (int)func_02046E24(c, d->h4)));
    a->f20 = (int)func_02046E24(c, d->h6);
    func_021AD82C((struct A *)((char *)a + 0x58), (struct B *)a, 2);
}
