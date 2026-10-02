/*
 * function: func_0218E260
 * address:  0x0218E260
 * packet:   pkt_0218E260
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
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020493D4(u32, u32);
extern u32 func_0204944C(u32, u32, u32, u32, u32);

int func_0218E260(u32 a, u32 b)
{
func_020493D4(*(u32 *)((u8 *)(a) + 4), 0);
return func_0204944C(*(u32 *)((u8 *)(a) + 4), 0, (44 * *(u32 *)((u8 *)(a) + 16)), 44, b);
}

