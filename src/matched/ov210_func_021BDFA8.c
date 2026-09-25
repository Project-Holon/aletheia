/*
 * function: func_021BDFA8
 * address:  0x021BDFA8
 * packet:   pkt_ov210_021BDFA8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCD3C  0x021BCD3C  thumb  ov210
 *   func_021BF38C  0x021BF38C  thumb  ov210
 *   func_021C0550  0x021C0550  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BCD3C(u8 *);
extern void func_021BF38C(u8 *);
extern void func_021C0550(u8 *);

u32 func_021BDFA8(u8 *p)
{
    func_021BCD3C(p);
    func_021BF38C(p);
    func_021C0550(p);
    return 3;
}
