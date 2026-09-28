/*
 * function: func_021AB504
 * address:  0x021AB504
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain class of a tile attribute word, for the encounter-effect lane.
 * Its one caller, func_021AACD4 in effect_encount.c, drops the tile when
 * the answer is 8 and otherwise stores the class byte in its per-tile
 * candidate list, so 8 is "no effect".  Note the flag-half gate: unless
 * bit 2 of the high half is set, every id falls through to 8, which is why
 * the overwhelmingly common 0x0081 flag half never produces a class.
 *
 * The two half accessors are func_021AB0F0/func_021AB0F8 inlined.
 */

typedef unsigned short u16;
typedef unsigned long u32;

int func_021AB504(u32 attr)
{
    u16 id = (u16)attr;
    u16 flags = (u16)(attr >> 16);

    if (id == 0x20) {
        return 7;
    }

    if (!(flags & 4)) {
        return 8;
    }

    switch (id) {
    case 4:
        return 0;
    case 5:
        return 1;
    case 0x21:
        return 2;
    case 8:
        return 3;
    case 10:
        return 4;
    case 0x3d:
        return 5;
    case 0x3f:
    case 0x43:
        return 6;
    }

    return 8;
}
