/*
 * function: func_021CBEFC
 * address:  0x021CBEFC
 * packet:   pkt_ov021_021CBEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps a value to a bracket 3..31 in steps of 20.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021CBEFC(u32 v)
{
    if (v < 100)
        return 3;
    if (v < 120)
        return 6;
    if (v < 140)
        return 9;
    if (v < 160)
        return 12;
    if (v < 180)
        return 15;
    if (v < 200)
        return 18;
    if (v < 220)
        return 21;
    return 31;
}
