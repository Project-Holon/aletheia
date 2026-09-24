/*
 * function: func_021C8054
 * address:  0x021C8054
 * packet:   pkt_021C8054
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
 *   func_02047788  0x02047788  arm
 *   func_02047504  0x02047504  arm
 *   func_02047738  0x02047738  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02046EFC(u32);
extern u32 func_02047504(u32);
extern u32 func_02047738(u32);
extern u32 func_02047788(u32, u32, u32, u32);

int func_021C8054(u32 a, u32 b, u32 c, u32 d)
{
func_02047504(func_02047788(*(u32 *)((u8 *)(a) + 4), b, c, d));
func_02047738(*(u32 *)((u8 *)(a) + 4));
func_02046EFC(*(u32 *)((u8 *)(a)));
return func_020307B0(a);
}

