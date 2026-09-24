/*
 * function: func_021C1C24
 * address:  0x021C1C24
 * packet:   pkt_021C1C24
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
 *   func_02047E88  0x02047E88  arm
 *   func_0207ADC4  0x0207ADC4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02047E88(u32, u32, u32, u32);
extern u32 func_0207ADC4(u32);

int func_021C1C24(u32 a, u32 b, u32 c, u32 d)
{
*(u32 *)((u8 *)(a) + 24) = func_02047E88(*(u32 *)((u8 *)(a) + 20), b, c, d);
*(u32 *)((u8 *)(a) + 40) = (1 << 12);
*(u32 *)((u8 *)(a) + 44) = (1 << 12);
*(u32 *)((u8 *)(a) + 48) = (1 << 12);
func_0207ADC4((a + 52));
*(u32 *)((u8 *)(a) + 28) = 0;
*(u32 *)((u8 *)(a) + 32) = 0;
*(u32 *)((u8 *)(a) + 36) = 0;
return 0;
}

