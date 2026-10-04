/*
 * function: func_021A5708
 * address:  0x021A5708
 * packet:   pkt_021A5708
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
 *   func_021A53A4  0x021A53A4  thumb  ov021
 *   func_021A5378  0x021A5378  thumb  ov021
 *   func_021A3998  0x021A3998  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A3998(u32);
extern void func_021A5378(u32 *p, int on);
extern void func_021A53A4(u32 *p, int on);

int func_021A5708(u32 a)
{
*(u16 *)((u8 *)(a) + 20) = 0;
*(u8 *)((u8 *)(a) + 22) = 0;
func_021A53A4((u32 *)a, 0);
func_021A5378((u32 *)a, 0);
return func_021A3998(*(u32 *)((u8 *)(a) + 12));
}

