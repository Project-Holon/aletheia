/*
 * function: func_021C6574
 * address:  0x021C6574
 * packet:   pkt_021C6574
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
 *   func_021C6538  0x021C6538  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021C6538(u32, u32, u32, u32);

int func_021C6574(u32 a, u32 b, u32 c)
{
    return func_021C6538(a, b, c, *(u32 *)((u8 *)(a) + 16));
}

