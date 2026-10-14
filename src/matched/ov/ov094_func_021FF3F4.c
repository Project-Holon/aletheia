/*
 * function: BTLV_MCSS_GetSlotPosition
 * address:  0x021FF3F4
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_CalcSlotPosition  0x022018A8  thumb  ov094
 */
extern void BTLV_MCSS_CalcSlotPosition(void *obj, void *out, int idx);

void BTLV_MCSS_GetSlotPosition(void *obj, void *out, int idx)
{
    BTLV_MCSS_CalcSlotPosition(obj, out, idx);
}
