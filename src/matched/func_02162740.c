/*
 * function: func_02162740
 * address:  0x02162740
 * packet:   pkt_02162740
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x20.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 func_02162740(u8 *p)
{
    return *(u32 *)(p + 0x20);
}

