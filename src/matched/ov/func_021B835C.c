/*
 * function: func_021B835C
 * address:  0x021B835C
 * packet:   pkt_021B835C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with two object fields.
 *
 * symbols:
 *   func_021B8848  0x021B8848  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B8848(u32 a, u32 b);

void func_021B835C(u8 *p)
{
    func_021B8848(*(u32 *)(p + 0x24), *(u32 *)(*(u32 *)(p + 4) + 0xc));
}
