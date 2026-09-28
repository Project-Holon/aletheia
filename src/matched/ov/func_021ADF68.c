/*
 * function: func_021ADF68
 * address:  0x021ADF68
 * packet:   pkt_021ADF68
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
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02046EFC(u32);
extern u32 func_020470D0(u32);
extern u32 func_02047504(u32);
extern u32 func_0204762C(u32);
extern u32 func_02047738(u32, u32, u32, u32);

int func_021ADF68(u32 a, u32 b, u32 c, u32 d)
{
func_02047738(*(u32 *)((u8 *)(a) + 12), b, c, d);
func_0204762C(*(u32 *)((u8 *)(a) + 16));
func_02047504(*(u32 *)((u8 *)(a) + 20));
func_02046EFC(*(u32 *)((u8 *)(a) + 8));
func_020470D0(*(u32 *)((u8 *)(a) + 4));
return func_02046EFC(*(u32 *)((u8 *)(a) + 4));
}

