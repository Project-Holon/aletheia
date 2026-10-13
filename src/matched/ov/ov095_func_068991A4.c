/*
 * function: HAND_SIDE_GetHandlersTailwind
 * address: 0x068991A4
 * packet: pkt_ov095_068991A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * follower: store-return leaf after non-C veneer 0x06899194.
 * symbols:
 *   gHandSideTailwindHandlers 0x0689D738 data a4
 */
extern unsigned int gHandSideTailwindHandlers;
unsigned int *HAND_SIDE_GetHandlersTailwind(unsigned int *out)
{
    *out = 1;
    return &gHandSideTailwindHandlers;
}
