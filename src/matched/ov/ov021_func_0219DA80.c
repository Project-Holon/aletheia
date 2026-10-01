/*
 * function: func_0219DA80
 * address:  0x0219DA80
 * packet:   pkt_ov021_0219DA80
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

extern u32 func_021AB0F8(u32);
extern u32 func_0219DC08(u32);
extern void func_021AC760(u32, u32, u32, u32);

void func_0219DA80(u32 a, u32 b)
{
    if (func_021AB0F8(b) & 0x20)
        func_021AC760(func_0219DC08(a), a, 0, 0);
}
