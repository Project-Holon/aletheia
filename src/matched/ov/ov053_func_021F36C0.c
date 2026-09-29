/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov053_021F36C0
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021F3828  0x021F3828  thumb  ov053
 *   func_021F3A04  0x021F3A04  thumb  ov053
 *   func_0202B914  0x0202B914  thumb
 *   d_021F3D60     0x021F3D60  data  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern char d_021F3D60[];

extern u32 func_02188C84(u32 a);
extern u32 func_02188D2C(u32 a);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE700(u32 a, int b, int c, int d, int e);
extern u8 *func_021BE674(u32 a, int b, int c, int d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern int *func_02189764(u32 a, int b, u32 c, int d);
extern void func_021F3828(int *p, u32 a);
extern void func_021F3A04(int *p, u32 a);
extern void func_0202B914(int a, int b);

void func_021F36C0(u32 a)
{
    u32 r6;
    u32 r5;
    u8 *e;
    int *p;

    r6 = func_02188C84(a);
    r5 = func_02188D2C(a);
    func_021BE760(r5, d_021F3D60, 0);
    func_021BE700(r5, 0, 4, 0, 1);
    e = func_021BE674(r5, 0, 4, 0);
    func_021BE6B0(e, 0);
    func_021BE6B8(e, 1);
    p = func_02189764(a, 0, r6, 0xf8);
    func_021F3828(p, a);
    func_021F3A04(p, a);
    func_0202B914(p[1], 0x7f);
}
