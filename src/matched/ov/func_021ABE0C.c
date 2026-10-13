/*
 * function: FIELD_EFFECT_Draw
 * address:  0x021ABE0C
 * packet:   pkt_021ABE04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_EFFECT_DrawObjects with no argument change.
 *
 * symbols:
 *   FIELD_EFFECT_DrawObjects  0x021ABFEC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_EFFECT_DrawObjects();

void FIELD_EFFECT_Draw(u32 a)
{
    FIELD_EFFECT_DrawObjects();
}
