/*
 * function: func_021A00E0
 * address:  0x021A00E0
 * packet:   pkt_ov021_021A00E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0219D680  0x0219D680  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 *func_0216D6F0(u32);
extern void func_0219D680(u32, u16);

void func_021A00E0(u32 a)
{
    func_0219D680(a, *func_0216D6F0(a));
}
