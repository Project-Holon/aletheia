/*
 * function: func_021CF480
 * address:  0x021CF480
 * packet:   pkt_021CF480
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
 *   func_021CF54C  0x021CF54C  thumb  ov021
 *   func_021CF5AC  0x021CF5AC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_021CF54C(u32, u32, u32, u32);
extern u32 func_021CF5AC(u32);

int func_021CF480(u32 a, u32 b, u32 c, u32 d)
{
func_021CF54C(a, b, c, d);
func_021CF5AC(a);
return func_020307B0(a);
}

