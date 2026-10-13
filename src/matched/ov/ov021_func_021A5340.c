/*
 * function: FIELD_PLAYER_GRID_IsForcedMoveFlagSet
 * address:  0x021A5340
 * packet:   pkt_ov021_021A5340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_HasFlag  0x021A5318  thumb  ov021
 */

typedef unsigned int u32;

int FIELD_PLAYER_GRID_HasFlag(u32 *p, u32 m);

int FIELD_PLAYER_GRID_IsForcedMoveFlagSet(u32 *p)
{
    int r = 1;

    if (FIELD_PLAYER_GRID_HasFlag(p, 1) == 0)
        r = 0;
    return r;
}
