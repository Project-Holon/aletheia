/*
 * function: func_021AB780
 * address:  0x021AB780
 * packet:   pkt_021AB780
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

int func_021AB780(u32 a, u32 b, u32 c)
{
if (*(u16 *)((u8 *)(a) + 10) > b) {
    if (*(u32 *)((u8 *)(*(u32 *)((u8 *)(a) + 4)) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}

