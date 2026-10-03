/*
 * function: func_021AE58C
 * address:  0x021AE58C
 * packet:   pkt_021AE58C
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
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021AC154(u32);
extern int func_021BB5C8(u32 a, u32 b, u32 c, u32 d);

int func_021AE58C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021BB5C8(*(u32 *)((u8 *)(a) + 44), b, c, d) == 1) {
    func_021AC154(*(u32 *)((u8 *)(a) + 44));
    *(u32 *)((u8 *)(a)) = 9;
}
return 0;
}

