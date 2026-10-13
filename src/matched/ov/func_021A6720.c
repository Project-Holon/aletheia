/*
 * function: FIELD_PLAYER_NOGRID_SetForcedMoveEnded
 * address:  0x021A6720
 * packet:   pkt_021A6708
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the second argument to 2.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_SetFlags  0x021A66E4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_SetFlags(u32 *p, u32 v);

void FIELD_PLAYER_NOGRID_SetForcedMoveEnded(void *a)
{
    FIELD_PLAYER_NOGRID_SetFlags(a, 2);
}
