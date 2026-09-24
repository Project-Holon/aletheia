/*
 * function: func_02155A8C
 * address:  0x02155A8C
 * packet:   pkt_02155A8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the word field at +0x50.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


void func_02155A8C(u8 *p, u32 v)
{
    *(u32 *)(p + 0x50) = v;
}

