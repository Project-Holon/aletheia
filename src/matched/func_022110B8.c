/*
 * function: func_022110B8
 * address:  0x022110B8
 * packet:   pkt_022110B8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

u32 func_022110B8(u8 **p, u32 c)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        if (c == *(u8 *)(*p + i + 0x48)) {
            return 1;
        }
    }
    return 0;
}

