/*
 * function: func_021A13C0
 * address:  0x021A13C0
 * packet:   pkt_ov021_021A13C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_021F00D4  0x021F00D4  thumb  ov031
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 func_02188C80(u32);
extern int func_0217394C(u32);
extern void func_021F00D4(u32, u32);

void func_021A13C0(u32 *p, u32 a)
{
    u32 h = func_02188C80(p[5]);
    if (a == 1 && func_0217394C(h) == 0)
        a = 0;
    func_021F00D4(p[8], a);
}
