/*
 * function: FIELD_PLAYER_NOGRID_ClearForcedMove
 * address:  0x021A6714
 * packet:   pkt_021A6708
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
 *   FIELD_PLAYER_NOGRID_ClearFlags  0x021A66EC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_ClearFlags(u32 *p, u32 v);

void FIELD_PLAYER_NOGRID_ClearForcedMove(void *a)
{
    FIELD_PLAYER_NOGRID_ClearFlags(a, 1);
}
