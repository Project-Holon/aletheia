/*
 * function: func_0218AEAC
 * address:  0x0218AEAC
 * packet:   pkt_ov021_0218AEAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when func_021626E8 reports kind 0, 5 or 6.
 *
 * symbols:
 *   func_021626E8  0x021626E8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u8 func_021626E8(u8 *p);

int func_0218AEAC(u8 *p)
{
    u8 v = func_021626E8(p);
    return v == 0 || v == 5 || v == 6;
}
