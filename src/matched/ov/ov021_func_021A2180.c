/*
 * function: WEATHER_TASK_SetBillboardParam18
 * address:  0x021A2180
 * packet:   pkt_ov021_021A2180
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
 *   WEATHER_TASK_SetBillboardParam18 0x021A2180 thumb ov021
 *   FIELD_3DBG_SetBillboardScaleY 0x021A16E8 thumb ov021
 */

extern void FIELD_3DBG_SetBillboardScaleY(unsigned char *p, unsigned int v);

void WEATHER_TASK_SetBillboardParam18(unsigned char *o, unsigned int v, int i)
{
    FIELD_3DBG_SetBillboardScaleY((*(unsigned char ***)(o + 0x18))[i], v);
}
