/*
 * function: func_0219DAA4
 * address:  0x0219DAA4
 * packet:   pkt_ov021_0219DAA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_021AC760  0x021AC760  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 func_021AB0F8(u32 attr);
extern int func_0219DC08(u32 a);
extern void func_021AC760(u32 a, u32 b, u32 c, int d);

void func_0219DAA4(u32 a, u32 b, u32 a2, u32 a3)
{
    if (b != 0xFFFFFFFF && (func_021AB0F8(b) & 0x20))
        func_021AC760(func_0219DC08(a), a, 1, 0);
}
