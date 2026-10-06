/*
 * function: func_0219EA10
 * address:  0x0219EA10
 * packet:   pkt_0219EA10
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
 *   func_0219E9F8  0x0219E9F8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020056EC(u32);
extern int func_0219E9F8(u32 *arr, u32 v);

int func_0219EA10(u32 *a, int b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(func_0219E9F8((u32 *)a, b)) << 2)));
}

