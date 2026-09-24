/*
 * function: func_0218DD04
 * address:  0x0218DD04
 * packet:   pkt_0218DC6C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0218DD04(u8 *p)
{
    return *(u32 *)(p + 0x4);
}

