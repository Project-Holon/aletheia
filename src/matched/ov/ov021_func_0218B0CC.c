/*
 * function: func_0218B0CC
 * address:  0x0218B0CC
 * packet:   pkt_ov021_0218B0CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls the unlabelled ov010 leaf func_021626EC (filed as pkt_ov010_021626EC).
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02162598  0x02162598  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_0218AEAC  0x0218AEAC  thumb
 *   func_0218B2A8  0x0218B2A8  thumb
 *   func_0218B2E8  0x0218B2E8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void *func_02188CB4(void *x);
extern void *func_021A3074(void *a);
extern void func_0219E2F4(void *a, int *b);
extern int func_02162598(void *a, int *b);
extern void *func_021625CC(void *a, u16 b);
extern int func_021626EC(void);
extern int func_0218AEAC(void *a);
extern void func_0218B2A8(char *p, int a, int *b);
extern int func_0218B2E8(char *p, void *x, int a, int *b);

int func_0218B0CC(char *p, void *unused, void *x)
{
    int buf[2];
    int r4;
    void *r6;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    r4 = func_02162598(*(void **)(p + 0xC), buf);
    if (r4 == 0xFFFF)
        return 0;
    r6 = func_021625CC(*(void **)(p + 0xC), r4);
    if (func_021626EC() == 1 || func_0218AEAC(r6) == 0)
        return 0;
    func_0218B2A8(p, r4, buf);
    return func_0218B2E8(p, x, r4, buf);
}
