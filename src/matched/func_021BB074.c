/*
 * function: func_021BB074
 * address:  0x021BB074
 * packet:   pkt_021BB074
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

u16 func_021BB074(u16 **p)
{
    u16 v = (*p)[2];
    if (v <= 6)
        return 0;
    return (u16)(v - 6);
}
