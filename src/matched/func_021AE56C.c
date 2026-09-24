/*
 * function: func_021AE56C
 * address:  0x021AE56C
 * packet:   pkt_021AE56C
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
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188CD0(u32, u32, u32, u32);
extern u32 func_021BB528(u32, u32, u32, u32);

int func_021AE56C(u32 a, u32 b, u32 c, u32 d)
{
*(u32 *)((u8 *)(a) + 44) = func_021BB528(func_02188CD0(*(u32 *)((u8 *)(a) + 48), b, c, d), *(u32 *)((u8 *)(a) + 8), 0, 0);
*(u32 *)((u8 *)(a)) = 6;
return 0;
}

