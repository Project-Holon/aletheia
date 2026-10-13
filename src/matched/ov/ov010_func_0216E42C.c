/*
 * function: FLDMMDL_CheckEventFlagBit
 * address:  0x0216E42C
 * packet:   pkt_ov010_0216E42C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tail call thunk: forwards its arguments unchanged to 0x020142E8.
 *
 * symbols:
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 */

extern unsigned int ZONEDATA_CheckEventFlag(void *bitmap, int id);

unsigned int FLDMMDL_CheckEventFlagBit(void *bitmap, int id)
{
    return ZONEDATA_CheckEventFlag(bitmap, id);
}
