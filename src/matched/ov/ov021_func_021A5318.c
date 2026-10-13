/*
 * function: FIELD_PLAYER_GRID_HasFlag
 * address:  0x021A5318
 * packet:   pkt_ov021_021A5318
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;

int FIELD_PLAYER_GRID_HasFlag(u32 *p, u32 m)
{
    if (p[2] & m)
        return 1;
    return 0;
}
