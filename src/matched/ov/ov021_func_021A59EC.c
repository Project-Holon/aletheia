/*
 * function: FIELD_PLAYER_NOGRID_IsForcedMove
 * address:  0x021A59EC
 * packet:   pkt_ov021_021A59EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_HasFlags  0x021A66F8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;

extern u32 FIELD_PLAYER_NOGRID_HasFlags(u32 p, u32 f);

u32 FIELD_PLAYER_NOGRID_IsForcedMove(u32 p)
{
    u32 r = 1;
    if (FIELD_PLAYER_NOGRID_HasFlags(p, 1) == 0) {
        r = 0;
    }
    return r;
}
