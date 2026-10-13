/*
 * function: EFFECT_ENCOUNT_UpdateOccupiedSpot
 * address:  0x021AA8F8
 * packet:   pkt_021AA8F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to EFFECT_ENCOUNT_ClearSpotIfOccupied with no argument change.
 *
 * symbols:
 *   EFFECT_ENCOUNT_ClearSpotIfOccupied  0x021AAF54  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Self;
extern int EFFECT_ENCOUNT_ClearSpotIfOccupied(struct Self *self);

void EFFECT_ENCOUNT_UpdateOccupiedSpot(struct Self *a0)
{
    EFFECT_ENCOUNT_ClearSpotIfOccupied(a0);
}
