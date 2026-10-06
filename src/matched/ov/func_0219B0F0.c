/*
 * function: func_0219B0F0
 * address:  0x0219B0F0
 * packet:   pkt_0219B0F0
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
 *   func_0219B0D8  0x0219B0D8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020056EC(u32);
extern int func_0219B0D8(u32 *t, u32 v);

int func_0219B0F0(u32 a, u32 b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(func_0219B0D8((u32 *)a, b)) << 2)));
}

