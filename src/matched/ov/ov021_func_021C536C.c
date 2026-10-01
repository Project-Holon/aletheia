/*
 * function: func_021C536C
 * address:  0x021C536C
 * packet:   pkt_ov021_021C536C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Advances the sequence from state 3 to 4 (EXACT*: pad).
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021C536C(u8 *p)
{
    if (*(u16 *)(p + 0x70) == 3)
        *(u16 *)(p + 0x70) = 4;
}
