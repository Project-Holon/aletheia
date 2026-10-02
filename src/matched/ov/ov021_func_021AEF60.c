/*
 * function: func_021AEF60
 * address:  0x021AEF60
 * packet:   pkt_ov021_021AEF60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02028A58  0x02028A58  thumb
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern u32 func_020120F4(u32 a);
extern void *func_0201210C(void *p);
extern u32 func_02012A30(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern void func_02028A58(u32 a, u8 b, u8 c);
extern void func_02159168(u32 a);

int func_021AEF60(u32 a, u32 b)
{
    u32 y;
    void *x;

    x = func_0215A5DC((void *)b);
    y = func_020120F4(x);
    func_0201210C((void *)x);
    y = func_02012A30(y);
    func_02028A58(y, 0x7f, func_02159B10(a, b));
    func_02159168(12);
    return 0;
}
