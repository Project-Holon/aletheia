/*
 * function: func_0204B864
 * address:  0x0204B864
 * packet:   pkt_0204B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 func_0204B864(u8 *a0)
{
    return (u8)((*(u32 *)(a0 + 0x60) << 14) >> 30);
}
