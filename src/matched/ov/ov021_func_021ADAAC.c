/*
 * function: func_021ADAAC
 * address:  0x021ADAAC
 * packet:   pkt_ov021_021ADAAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9238     0x021D9238  data  a1
 *   d_021D9240     0x021D9240  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct L {
    int f0;
    int f4;
    int f8;
    int fc;
    u16 h10;
    u16 h12;
    int f14;
    u8 b18;
    u8 pad19[3];
    int f1c;
    int f20;
    int f24;
} L;

extern u8 d_021D9238[];
extern int d_021D9240[];

extern int func_021ABE14(int a);
extern unsigned int func_02188CFC(u8 *p);
extern int func_021ABEA0(int a, int b);
extern void *func_02082BCC(void *p, u8 v, unsigned n);
extern void *func_02188C7C(unsigned char *p);
extern u8 func_021ABFA8(int a, void *b, int c, int d, void *e, int f);

u8 func_021ADAAC(int a, int b, int c, int d, int e, int f)
{
    int t;
    int k;
    int r;
    L l;

    t = func_021ABE14(b);
    if (func_02188CFC((u8 *)t) != 0) {
        return 0;
    }
    k = d_021D9238[f];
    r = func_021ABEA0(b, k + 0x12);
    if (r == 0) {
        return 0;
    }
    func_02082BCC(&l, 0, 0x28);
    l.f0 = a;
    l.f4 = r;
    l.f8 = func_02188C7C((void *)t);
    l.h10 = c;
    l.h12 = d;
    l.f14 = k;
    if (k == 0) {
        l.b18 = f;
    } else {
        l.b18 = 0;
    }
    l.f1c = (c << 16) + 0x8000;
    l.f24 = (d << 16) + 0x8000;
    l.f20 = e;
    return func_021ABFA8(b, d_021D9240, 0, 1, &l, 0);
}
