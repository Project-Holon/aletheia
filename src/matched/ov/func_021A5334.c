/*
 * function: FIELD_PLAYER_GRID_ClearForcedMoveFlag
 * address:  0x021A5334
 * packet:   pkt_021A5328
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the second argument to 1.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_ClearFlag  0x021A530C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_GRID_ClearFlag(u32 a, u32 b);

void FIELD_PLAYER_GRID_ClearForcedMoveFlag(u32 a)
{
    FIELD_PLAYER_GRID_ClearFlag(a, 1);
}
