/*
 * function: func_02190B08
 * address:  0x02190B08
 * packet:   pkt_02190B08
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
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0)
{
*(u16 *)((u8 *)(a)) = b;
*(u16 *)((u8 *)(a) + 22) = d;
*(u16 *)((u8 *)(a) + 20) = c;
*(u16 *)((u8 *)(a) + 24) = *(u16 *)((u8 *)((u8 *)&e0));
*(u16 *)((u8 *)(a) + 26) = *(u16 *)((u8 *)((u8 *)&e0) + 4);
return a;
}

