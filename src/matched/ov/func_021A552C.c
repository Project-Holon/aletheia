/*
 * function: FIELD_PLAYER_GRID_RunNoForcedMove
 * address:  0x021A552C
 * packet:   pkt_021A552C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls FIELD_PLAYER_GRID_ReleaseForcedMove() and returns 0x0.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_ReleaseForcedMove  0x021A550C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FIELD_PLAYER_GRID_ReleaseForcedMove(u32 *p);

u32 FIELD_PLAYER_GRID_RunNoForcedMove(u32 *p)
{
    FIELD_PLAYER_GRID_ReleaseForcedMove(p);

    return 0x0;
}

