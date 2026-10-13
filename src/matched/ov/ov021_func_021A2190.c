/*
 * function: WEATHER_TASK_SetBillboardParam0C
 * address:  0x021A2190
 * packet:   pkt_ov021_021A2190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   WEATHER_TASK_SetBillboardParam0C 0x021A2190 thumb ov021
 *   FIELD_3DBG_SetBillboardTexOffsetX 0x021A16DC thumb ov021
 */

extern void FIELD_3DBG_SetBillboardTexOffsetX(unsigned char *p, unsigned int v);

void WEATHER_TASK_SetBillboardParam0C(unsigned char *o, unsigned int v, int i)
{
    FIELD_3DBG_SetBillboardTexOffsetX((*(unsigned char ***)(o + 0x18))[i], v);
}
