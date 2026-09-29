/*
 * function: func_021AD96C
 * address:  0x021AD96C
 * packet:   pkt_ov021_021AD96C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_021ABE2C  0x021ABE2C  thumb  ov021
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
    u16 tab[1];
} Desc;

typedef struct P {
    int f0;
    int f4;
    int f8[4];
    int f18[1];
} P;

extern u8 func_021ABE28(int a);
extern u8 func_021ABE2C(int a);
extern void func_021AD82C(void *a, void *b, int c);
extern int func_02046E24(int a, int b);
extern void func_02046FF8(int a);

void func_021AD96C(P *a, Desc *d, int c)
{
    int base;
    int i;
    int j;
    int t;

    base = 0;
    if (d->b6) {
        base = func_021ABE28(a->f0);
    } else if (d->b7) {
        base = func_021ABE2C(a->f0);
    }
    for (i = 0; i < d->lo; i++) {
        t = base + i * d->mid;
        a->f8[i] = func_02046E24(c, d->h4 + t);
        func_02046FF8(a->f8[i]);
        for (j = 0; j < d->n; j++) {
            a->f18[i * d->n + j] = func_02046E24(c, t + d->tab[j]);
        }
        func_021AD82C((char *)a + 0x28 + i * 0x18, a, (u8)i);
    }
}
