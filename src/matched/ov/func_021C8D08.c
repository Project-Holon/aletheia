/*
 * function: func_021C8D08
 * address:  0x021C8D08
 * packet:   pkt_021C8D08
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
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C8D08(u32 a)
{
if (*(u32 *)((u8 *)(a) + 20) != 0) {
    return *(u16 *)((u8 *)(*(u32 *)((u8 *)(a) + 20)) + 2);
}
return 0;
}

