/*
 * function: func_021BC5BC
 * address:  0x021BC5BC
 * packet:   pkt_021BC5BC
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
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 *   func_021BCA80  0x021BCA80  thumb  ov021
 *   func_021BCA6C  0x021BCA6C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BCA6C(u32);
extern void func_021BCA80(u8 *p);
extern u32 func_021BCB9C(u32, u32, u32, u32);

int func_021BC5BC(u32 a, u32 b, u32 c, u32 d)
{
func_021BCB9C(a, 0, c, d);
func_021BCA80((u8 *)a);
return func_021BCA6C(a);
}

