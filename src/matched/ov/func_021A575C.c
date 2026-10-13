/*
 * function: FIELD_PLAYER_GRID_StopForcedMove
 * address:  0x021A575C
 * packet:   pkt_021A572C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_PLAYER_GRID_ReleaseForcedMove with no argument change.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_ReleaseForcedMove  0x021A550C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_GRID_ReleaseForcedMove(u32 *p);

void FIELD_PLAYER_GRID_StopForcedMove(u32 *p)
{
    FIELD_PLAYER_GRID_ReleaseForcedMove(p);
}
