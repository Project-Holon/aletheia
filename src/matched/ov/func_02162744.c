/*
 * function: func_02162744
 * address:  0x02162744
 * packet:   pkt_02162744
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the halfword field at +0x14.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u16 func_02162744(u8 *p)
{
    return *(u16 *)(p + 0x14);
}

