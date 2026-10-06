/*
 * function: func_021A15D4
 * address:  0x021A15D4
 * packet:   pkt_021A15D4
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
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1750  0x021A1750  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern int func_021A1750(u32 a);
extern u32 func_021A1780(u8 *p);

int func_021A15D4(u32 a)
{
if (func_021A1780((u8 *)(a + 32)) != 0) {
    func_021A1750((a + 32));
}
return func_020307B0(a);
}

