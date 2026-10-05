/*
 * function: func_021CD1AC
 * address:  0x021CD1AC
 * packet:   pkt_021CD1AC
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
 *   func_021CD038  0x021CD038  thumb  ov021
 *   func_021CCBE0  0x021CCBE0  thumb  ov021
 *   func_021CCE48  0x021CCE48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021CCBE0(u8 *s, int flag);
extern u32 func_021CCE48(u32, u32);
extern u32 func_021CD038(u32, u32, u32, u32);

int func_021CD1AC(u32 a, u32 b, u32 c, u32 d)
{
func_021CD038(a, b, c, d);
func_021CCBE0((u8 *)a, 2);
return func_021CCE48(a, 2);
}

