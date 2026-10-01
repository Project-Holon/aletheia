/*
 * function: func_0219DE98
 * address:  0x0219DE98
 * packet:   pkt_ov021_0219DE98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern s16 *func_0216D6D4(u32);
extern void func_0216D568(u32, u32);
extern void func_0216D674(u32, u32);
extern void func_0216D7CC(u32);

int func_0219DE98(u32 a)
{
    s16 *q = func_0216D6D4(a);
    q[1]--;
    if (q[1] > 0)
        return 0;
    func_0216D568(a, 0x400);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    return 1;
}
