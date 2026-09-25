/*
 * function: func_021F4BD8
 * address:  0x021F4BD8
 * packet:   pkt_021F4BD8
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D0C  0x021F4D0C  thumb  ov194
 *   func_021F4CA4  0x021F4CA4  thumb  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021F4D0C(u8 *);
extern void func_021F4CA4(u8 *);

void func_021F4BD8(u8 *p)
{
    func_021F4D0C(p + 4);
    func_021F4CA4(p);
}

