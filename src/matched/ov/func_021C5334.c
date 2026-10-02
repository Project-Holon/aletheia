/*
 * function: func_021C5334
 * address:  0x021C5334
 * packet:   pkt_021C5334
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_021C56F8  0x021C56F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201C4E4(u32);
extern u32 func_021C56F8(u32);

int func_021C5334(u32 a)
{
func_0201C4E4(*(u32 *)((u8 *)(a) + 108));
return func_021C56F8(a);
}

