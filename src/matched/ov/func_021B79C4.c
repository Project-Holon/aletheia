/*
 * function: FIELD_RAIL_SetFocusWork
 * address:  0x021B79C4
 * packet:   pkt_021B79C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: stores v at +0x14 and 1 at +0x18.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_RAIL_SetFocusWork(u32 *p, u32 v)
{
    p[5] = v;
    p[6] = 1;
}
