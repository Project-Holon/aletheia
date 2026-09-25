/*
 * function: func_021BDFA8
 * address:  0x021BDFA8
 * packet:   pkt_ov203_021BDFA8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE07C  0x021BE07C  thumb  ov203
 *   func_021BE0E8  0x021BE0E8  thumb  ov203
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BE07C(u8 *);
extern void func_021BE0E8(u8 *);

void func_021BDFA8(u32 a, u8 *p)
{
    if (*(u32 *)(p + 0x14) == 0) {
        func_021BE07C(p);
        func_021BE0E8(p + 4);
    }
}
