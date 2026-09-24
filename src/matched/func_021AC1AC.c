/*
 * function: func_021AC1AC
 * address:  0x021AC1AC
 * packet:   pkt_021AC1AC
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

int func_021AC1AC(u32 a)
{
if (a != 0) {
    return *(u32 *)((u8 *)(a) + 8);
}
return 0;
}

