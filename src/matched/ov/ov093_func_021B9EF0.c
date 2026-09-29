/*
 * function: func_021B9EF0
 * address:  0x021B9EF0
 * packet:   pkt_ov093_021B9EF0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045A00  0x02045A00  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02024570  0x02024570  thumb
 *   func_0202428C  0x0202428C  thumb
 */

typedef unsigned short u16;

struct H {
    u16 a, b, c, d;
};

struct A {
    int vt;
    int q;
    u16 h8;
    u16 ha;
    int c;
    u16 h[4];
    struct H s18;
    struct H s20;
};

struct B {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
    char pad[0x68 - 0x28];
    int f68;
};

extern int func_020457B0(int, int);
extern void func_02045A00(int, const void *, int);
extern void func_02082D44(const void *, void *, int);
extern void func_02024570(struct H *, const struct H *);
extern void func_0202428C(struct H *);

void func_021B9EF0(struct A *p, const struct B *src)
{
    unsigned int i;
    int t, u;

    p->vt = 0;
    if (src) {
        p->ha = src->f0;
        p->h8 = src->f4;
        t = func_020457B0(0x20, 0x12);
        u = src->f68 + 1;
        p->q = t;
        func_02045A00(t, (char *)src + 0x28, u);
        p->c = src->f8;
        func_02082D44(src->b, p->h, 8);
        func_02024570(&p->s18, &src->s18);
        func_02024570(&p->s20, &src->s20);
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        func_0202428C(&p->s18);
        func_0202428C(&p->s20);
    }
}
