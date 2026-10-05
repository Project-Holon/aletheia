/*
 * function: func_021BDD84
 * address:  0x021BDD84
 * packet:   pkt_021BDD84
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BDE28  0x021BDE28  thumb  ov204
 *   func_021BDF98  0x021BDF98  thumb  ov204
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BDE28(u8 *);
extern void func_021BDF98(u8 *);

void func_021BDD84(u32 a, u8 *b)
{
    func_021BDE28(b);
    func_021BDF98(b + 4);
}

