/*
 * function: func_021F4BF8
 * address:  0x021F4BF8
 * packet:   pkt_021F4BF8
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F4CA8  0x021F4CA8  thumb  ov194
 *   func_021F4D14  0x021F4D14  thumb  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021F4CA8(u8 *);
extern void func_021F4D14(u8 *);

void func_021F4BF8(u32 a, u8 *b)
{
    func_021F4CA8(b);
    func_021F4D14(b + 4);
}

