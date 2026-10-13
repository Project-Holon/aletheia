/*
 * function: HAND_SIDE_GetHandlersLuckyChant
 * address: 0x06899204
 * packet: pkt_ov095_06899204
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * follower: store-return leaf after non-C veneer 0x068991F4.
 * symbols:
 *   gHandSideLuckyChantHandlers 0x0689D730 data a4
 */
extern unsigned int gHandSideLuckyChantHandlers;
unsigned int *HAND_SIDE_GetHandlersLuckyChant(unsigned int *out)
{
    *out = 1;
    return &gHandSideLuckyChantHandlers;
}
