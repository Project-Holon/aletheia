/*
 * function: func_021A006C
 * address:  0x021A006C
 * packet:   pkt_ov021_021A006C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219D634  0x0219D634  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u8 *func_0216D6D8(u32, u32);
extern u32 func_0219D634(u32 a);

void func_021A006C(u32 a)
{
    u16 *q = (u16 *)func_0216D6D8(a, 2);
    *q = func_0219D634(a);
}
