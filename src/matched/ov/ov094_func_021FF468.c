/*
 * function: BTLV_MCSS_GetSlotScale
 * address:  0x021FF468
 * packet:   pkt_021FF468
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_CalcSlotScale  0x02201934  thumb  ov094
 */

int BTLV_MCSS_CalcSlotScale(void *u, int i, int mode);

int BTLV_MCSS_GetSlotScale(void *u, int i, int mode)
{
    return BTLV_MCSS_CalcSlotScale(u, i, mode);
}
