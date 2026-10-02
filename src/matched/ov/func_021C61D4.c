/*
 * function: func_021C61D4
 * address:  0x021C61D4
 * packet:   pkt_021C61D4
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
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188C6C(u32);
extern u32 func_021A1BF4(u32);

int func_021C61D4(u32 a)
{
if (func_021A1BF4(func_02188C6C(*(u32 *)((u8 *)(a) + 12))) == 0) {
    return 1;
}
return 0;
}

