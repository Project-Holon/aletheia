/*
 * function: func_0219F8C8
 * address:  0x0219F8C8
 * packet:   pkt_ov021_0219F8C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219C814  0x0219C814  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u8 *func_0216D6D8(u32, u32);
extern int func_0219C814(u32 a, u16 *b);

void func_0219F8C8(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    q[2] = 9;
    func_0219C814(a, (u16 *)q);
}
