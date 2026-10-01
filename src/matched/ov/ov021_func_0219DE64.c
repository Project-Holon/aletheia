/*
 * function: func_0219DE64
 * address:  0x0219DE64
 * packet:   pkt_ov021_0219DE64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 *func_0216D6BC(u32, u32);
extern void func_0216D5E0(u32, u16);
extern void func_0216D674(u32, u32);
extern void func_02163F10(u32);
extern void func_0216D7CC(u32);

void func_0219DE64(u32 a, u32 b, u16 c, u16 d)
{
    u16 *q = func_0216D6BC(a, 4);
    q[0] = d;
    q[1] = c;
    func_0216D5E0(a, b);
    func_0216D674(a, d);
    func_02163F10(a);
    func_0216D7CC(a);
}
