/*
 * function: EFFECT_ENCOUNT_Reset
 * address:  0x021AA8EC
 * packet:   pkt_021AA8EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object and the word at +0x10.
 *
 * symbols:
 *   EFFECT_ENCOUNT_ClearSpot  0x021AAFA0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18072.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void EFFECT_ENCOUNT_ClearSpot(u8 *p, u32 v);

void EFFECT_ENCOUNT_Reset(u8 *p)
{
    EFFECT_ENCOUNT_ClearSpot(p, ((struct Obj18072 *)p)->f10);
}
