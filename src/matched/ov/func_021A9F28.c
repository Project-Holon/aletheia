/*
 * function: func_021A9F28
 * address:  0x021A9F28
 * packet:   pkt_021A9F28
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
 *   func_021AA7CC  0x021AA7CC  thumb  ov021
 *   func_021AA794  0x021AA794  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_021AA794(u32);
extern int func_021AA7CC(u32 a, u32 b, u32 c, u32 d);

int func_021A9F28(u32 a, u32 b, u32 c, u32 d)
{
func_021AA7CC(a, *(u32 *)((u8 *)(a) + 16), c, d);
func_021AA794(*(u32 *)((u8 *)(a) + 16));
return func_020307B0(a);
}

