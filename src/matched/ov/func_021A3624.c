/*
 * function: func_021A3624
 * address:  0x021A3624
 * packet:   pkt_021A3624
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
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A54A0  0x021A54A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188CFC(u32, u32, u32, u32);
extern u32 func_021A54A0(u32);

int func_021A3624(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188CFC(*(u32 *)((u8 *)(a)), b, c, d) == 0) {
    if (func_021A54A0(*(u32 *)((u8 *)(a) + 8)) == 1) {
        return 1;
    }
}
return 0;
}

