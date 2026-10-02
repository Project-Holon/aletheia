/*
 * function: func_02190728
 * address:  0x02190728
 * packet:   pkt_02190728
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
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02190538(u32);
extern u32 func_02193130(u32);

int func_02190728(u32 a)
{
func_02193130(*(u32 *)((u8 *)(a)));
func_02190538(*(u32 *)((u8 *)(a) + 4));
return func_020307B0(a);
}

