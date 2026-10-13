/*
 * function: FIELD_RAIL_WORK_GetCamera
 * address:  0x021B830C
 * packet:   pkt_021B8224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_RAIL_WORK_GetSpotCamera with no argument change.
 *
 * symbols:
 *   FIELD_RAIL_WORK_GetSpotCamera  0x021B91C8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_WORK_GetSpotCamera();

void FIELD_RAIL_WORK_GetCamera(void)
{
    FIELD_RAIL_WORK_GetSpotCamera();
}
