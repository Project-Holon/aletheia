/*
 * function: func_021D2524
 * address:  0x021D2524
 * packet:   pkt_ov021_021D2524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021D25A4  0x021D25A4  thumb  ov021
 *   func_021D25F4  0x021D25F4  thumb  ov021
 *   func_021D26D0  0x021D26D0  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern u32 func_02159B10(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_020122C0(void *a, u32 b, void *c, u32 d);
extern void *func_020124E8(void *task);
extern void func_021D25A4(void *p);
extern void func_021D26D0(void);
extern void func_021D25F4(void *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0215897C(void *vm, void *task);

int func_021D2524(u32 a, u32 b)
{
    u32 r5, s1, s2, s3;
    void *r4;
    void *r6;
    void *r7;

    r6 = func_0215A5DC((void *)b);
    func_0201210C(r6);
    s1 = func_02159B10(a, b);
    s2 = func_02159B10(a, b);
    s3 = func_02159B10(a, b);
    r5 = func_02159B10(a, b);
    r7 = func_0215A5F4((void *)b);
    r4 = func_020122C0(r6, 0, func_021D26D0, 0x18);
    r6 = func_020124E8(r4);
    func_021D25A4(r6);
    func_021D25F4(r6, s1, s2, s3, r5, 0);
    func_0215897C(r7, r4);
    return 1;
}
