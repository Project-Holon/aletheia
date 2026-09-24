/*
 * function: func_021C7844
 * address:  0x021C7844
 * packet:   pkt_021C7844
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0204E720(u32, u32, u32, u32);

int func_021C7844(u32 a, u32 b, u32 c)
{
func_0204E720(*(u32 *)((u8 *)(a) + 4), *(u32 *)((u8 *)(a) + 8), *(u32 *)((u8 *)(a) + 12), *(u32 *)((u8 *)(a) + 16));
return 1;
}

