/*
 * function: func_021AEFD8
 * address:  0x021AEFD8
 * packet:   pkt_ov021_021AEFD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: func_02029DF4 (arm9, unlabelled thumb veneer: ldr r3,[pc]; bx r3;
 * .word 0x02029EB5) has no witness outside the range (evidence class: none;
 * arm9 leaf belongs to Ilias, not filed here).
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02028BDC  0x02028BDC  thumb
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_020120F4(void *a);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012A30(u32 a);
extern u32 func_02012984(u32 a);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02029DF4(u32 a, u32 b, u32 c);
extern u32 func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void func_0215897C(void *a, u32 b);
extern void func_02028BDC(u32 a, u32 b);
extern void func_02159168(int n);

int func_021AEFD8(u32 a, u32 b)
{
    u32 y, m, q, s;
    void *x;
    void *l;
    void *p;

    x = func_0215A5DC((void *)b);
    y = func_020120F4(x);
    l = func_0201210C((void *)x);
    m = func_02012A30(y);
    p = func_0215A5F4((void *)b);
    q = func_02012984(y);
    s = func_02029DF4(y, func_02188C9C(l), q);
    func_0215897C(p, func_020298A0(x, s, 0x5a, 0x3c));
    func_02028BDC(m, 2);
    func_02159168(13);
    return 1;
}
