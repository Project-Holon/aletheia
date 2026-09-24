/*
 * function: func_02194960
 * address:  0x02194960
 * packet:   pkt_02194960
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

int func_02194960(u32 a, u32 b, u32 c)
{
if (*(u16 *)((u8 *)((a + (b * 100))) + 24) == 0) {
    return 1;
}
return 0;
}

