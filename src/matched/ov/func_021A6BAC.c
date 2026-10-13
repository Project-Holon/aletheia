/*
 * function: FIELD_PLAYER_NOGRID_ResetInputHold
 * address:  0x021A6BAC
 * packet:   pkt_021A6BAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_PLAYER_NOGRID_InitInputHold with no argument change.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_InitInputHold  0x021A6B88  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_NOGRID_InitInputHold(void *a);

int FIELD_PLAYER_NOGRID_ResetInputHold(void *a)
{
    return FIELD_PLAYER_NOGRID_InitInputHold(a);
}
