/*
 * function: func_0216E204
 * address:  0x0216E204
 * packet:   pkt_ov010_0216E204
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D594  0x0216D594  thumb  ov010
 *   func_0216E39C  0x0216E39C  thumb  ov010
 *   func_0216DA94  0x0216DA94  thumb  ov010
 *   func_0216E190  0x0216E190  thumb  ov010
 *   func_0216E114  0x0216E114  thumb  ov010
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern void *func_0216D67C(void *a);
extern int func_0216D948(int a0);
extern int func_0216DAA0(void *a);
extern void func_0216D76C(void *a);
extern void func_0216D594(void *a, u16 v);
extern void func_0216E39C(int a0, int a1, int a2);
extern void func_0216DA94(void *a);
extern void func_0216E190(void *a);
extern void func_0216E114(void *a);

void func_0216E204(char *a, u16 v)
{
    void *ctx;
    char *p;

    ctx = func_0216D67C(a);
    if (func_0216D948((int)ctx) == 1 && func_0216DAA0(a) == 1)
        func_0216D76C(a);
    func_0216D594(a, v);
    func_0216E39C((int)ctx, v, (int)a);
    p = a + 0xe4;
    *(u8 *)(a + 0x7c) = *(u8 *)(p + 0xb);
    *(u8 *)(a + 0x7d) = *(u8 *)(p + 0xc);
    *(s8 *)(a + 0x7e) = *(s8 *)(p + 0xd);
    *(s8 *)(a + 0x7f) = *(s8 *)(p + 0xe);
    *(s8 *)(a + 0x80) = *(s8 *)(p + 0xf);
    func_0216DA94(a);
    func_0216E190(a);
    func_0216E114(a);
}
