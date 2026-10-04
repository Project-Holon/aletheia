/*
 * function: func_021A1750
 * address:  0x021A1750
 * packet:   pkt_021A1750
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
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Tagged;
extern void func_02046EFC(struct Tagged *p);
extern u32 func_020470D0(u32, u32, u32, u32);

int func_021A1750(u32 a, u32 b, u32 c, u32 d)
{
func_020470D0(*(u32 *)((u8 *)(a) + 8), b, c, d);
func_02046EFC((struct Tagged *)(*(u32 *)((u8 *)(a) + 8)));
*(u32 *)((u8 *)(a) + 8) = 0;
*(u8 *)((u8 *)(a) + 6) = 0;
return 0;
}

