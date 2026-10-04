/*
 * function: func_0219FFD4
 * address:  0x0219FFD4
 * packet:   pkt_ov021_0219FFD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219D738  0x0219D738  thumb  ov021
 *   func_021642D4  0x021642D4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D538(u8 *p);
extern u16 func_0216D5F8(void *p);
extern int func_0216D55C(int a0, int a1);
extern u32 func_0219D738(u32 a, int b);
extern u8 func_021642D4(int i, int v);

void func_0219FFD4(u32 a)
{
    u32 x = func_0216D538(func_0216D67C((void *)a));
    u32 y = func_0216D5F8((void *)a);
    if (func_0216D55C(a, 0x2000))
        func_0219D738(a, x);
    else
        func_021642D4(y, x);
}
