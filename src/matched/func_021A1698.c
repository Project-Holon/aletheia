/*
 * function: func_021A1698
 * address:  0x021A1698
 * packet:   pkt_021A1698
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
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1750  0x021A1750  thumb  ov021
 *   func_021A16EC  0x021A16EC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A16EC(u32, u32, u32, u32);
extern u32 func_021A1750(u32);
extern u32 func_021A1780(u32, u32, u32, u32);

int func_021A1698(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A1780((a + 32), b, c, d) != 0) {
    func_021A1750((a + 32));
}
func_021A16EC((a + 32), b, c, d);
*(u8 *)((u8 *)(a) + 31) = *(u8 *)((u8 *)(c) + 8);
*(u32 *)((u8 *)(a) + 20) = (1 << 12);
*(u32 *)((u8 *)(a) + 24) = (1 << 12);
*(u16 *)((u8 *)(a) + 28) = 0;
return 0;
}

