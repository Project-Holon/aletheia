/*
 * function: HAND_SIDE_GetHandlersSwamp
 * address: 0x06899A90
 * packet: pkt_ov095_06899A90
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHandSideSwampHandlers 0x0689D720 data a4
 */
extern unsigned int gHandSideSwampHandlers;
void *HAND_SIDE_GetHandlersSwamp(unsigned int *p)
{
    *p = 1;
    return &gHandSideSwampHandlers;
}
