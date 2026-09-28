/*
 * function: func_021626E8
 * address:  0x021626E8
 * packet:   pkt_021626E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the byte field at +0x5.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u8 func_021626E8(u8 *p)
{
    return *(u8 *)(p + 0x5);
}

