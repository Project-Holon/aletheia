/*
 * function: func_0218ED40
 * address:  0x0218ED40
 * packet:   pkt_0218EC2C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the halfword at byte +0x7a of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0218ED40(u8 *p)
{
    return *(u16 *)(p + 0x7a);
}

