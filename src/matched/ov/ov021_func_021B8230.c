/*
 * function: FIELD_RAIL_GetLine
 * address:  0x021B8230
 * packet:   pkt_021B8224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk on the object 0x20 bytes in.
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetLine  0x021B87FC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *FIELD_RAIL_SETTING_GetLine(u8 *p, u32 idx);

void FIELD_RAIL_GetLine(u8 *p, u32 a1)
{
    FIELD_RAIL_SETTING_GetLine(p + 0x20, a1);
}
