/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov040_021F36C0
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F36C0  0x021F36C0  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   d_021F38D4     0x021F38D4  data  a4
 *   d_021F38EC     0x021F38EC  data  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern V3 d_021F38D4;
extern char d_021F38EC[];

extern u32 func_02188D2C(void);
extern u32 func_02188C84(u32 a);
extern void func_02189764(u32 a, int b, u32 c, int d);
extern void *func_021897BC(u32 a, int b);
extern void func_021BE310(u32 a, void *b, int c);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern u8 *func_0200B3A4(u32 a, u32 b);
extern V3 *func_021BE480(u32 a, int b, int c);
extern u8 *func_021BE674(u32 a, int b, int c, int d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE700(u32 a, int b, int c, int d, int e);
extern int func_021BE748(u8 *p);
extern void func_021BE6CC(u32 a, int b, int c, int d, int e);

void func_021F36C0(u32 a)
{
    u32 s;
    u8 *q;
    u8 *e;
    V3 v;

    s = func_02188D2C();
    func_02189764(a, 1, func_02188C84(a), 4);
    func_021897BC(a, 1);
    func_021BE310(s, d_021F38EC, 0);
    q = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(a))), 3);
    v.a = d_021F38D4.a;
    v.b = 0;
    v.c = d_021F38D4.b;
    *func_021BE480(s, 0, 0) = v;
    e = func_021BE674(s, 0, 0, 0);
    func_021BE6B0(e, 1);
    func_021BE6B8(e, 0);
    if (q[4] != 0) {
        func_021BE700(s, 0, 0, 0, 1);
        func_021BE6CC(s, 0, 0, 0, func_021BE748(e));
    }
}
