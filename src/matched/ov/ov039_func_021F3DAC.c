/*
 * function: FIELD_GIMMICK_CART_LANES_GetDockLane
 * address:  0x021F3DAC
 * packet:   pkt_021F3DAC
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_CART_LANES_GetDockLane 0x021F3DAC thumb
 *   sDockLanes    0x021F4C0C data ov039 a1
 */

extern unsigned char sDockLanes[];

unsigned char FIELD_GIMMICK_CART_LANES_GetDockLane(int i)
{
    return sDockLanes[i];
}
