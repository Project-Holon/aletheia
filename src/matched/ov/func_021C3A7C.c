/*
 * function: func_021C3A7C
 * address:  0x021C3A7C
 * packet:   pkt_021C3A7C
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
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02082BCC(u32, u32, u32, u32);

int func_021C3A7C(u32 a, u32 b, u32 c, u32 d)
{
func_02082BCC(a, 0, 140, d);
*(u32 *)((u8 *)(a) + 8) = 1;
return 1;
}

