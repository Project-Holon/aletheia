/*
 * function: func_021BD36C
 * address:  0x021BD36C
 * packet:   pkt_021BD36C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCD3C  0x021BCD3C  thumb  ov210
 *   func_021BEDF0  0x021BEDF0  thumb  ov210
 *   func_021BFF18  0x021BFF18  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BCD3C(u8 *);
extern void func_021BEDF0(u8 *, u32, u32);
extern void func_021BFF18(u8 *);

u32 func_021BD36C(u8 *p)
{
    func_021BCD3C(p);
    func_021BEDF0(p, 7, 0);
    func_021BFF18(p);
    return *(u32 *)(p + 0x18);
}

