/*
 * function: func_021B91AC
 * address:  0x021B91AC
 * packet:   pkt_021B91AC
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

int func_021B91AC(u32 a, u32 b)
{
if (*(u16 *)((u8 *)(a)) < 2) {
    if (*(u32 *)((u8 *)(a) + 4) != 0) {
        if (*(u16 *)((u8 *)(a) + 2) != 0) {
            return 1;
        }
    }
}
return 0;
}

