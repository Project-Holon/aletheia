/*
 * function: func_021BB5C8
 * address:  0x021BB5C8
 * packet:   pkt_021BB5C8
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
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021AC1E0(u32, u32, u32, u32);

int func_021BB5C8(u32 a, u32 b, u32 c, u32 d)
{
if (a != 0) {
    return *(u32 *)((u8 *)(func_021AC1E0(a, b, c, d)) + 36);
}
return 1;
}

