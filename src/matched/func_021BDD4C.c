/*
 * function: func_021BDD4C
 * address:  0x021BDD4C
 * packet:   pkt_021BDD4C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDF90  0x021BDF90  thumb  ov204
 *   func_021BDE10  0x021BDE10  thumb  ov204
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BDF90(u8 *);
extern void func_021BDE10(u8 *);

void func_021BDD4C(u8 *p)
{
    func_021BDF90(p + 4);
    func_021BDE10(p);
}

