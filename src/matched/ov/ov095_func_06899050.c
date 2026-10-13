/*
 * function: HAND_SIDE_GetHandlersMist
 * address: 0x06899050
 * packet: pkt_ov095_06899050
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * follower: store-return leaf after non-C veneer 0x06899040.
 * symbols:
 *   gHandSideMistHandlers 0x0689D758 data a4
 */
extern unsigned int gHandSideMistHandlers;
unsigned int *HAND_SIDE_GetHandlersMist(unsigned int *out)
{
    *out = 2;
    return &gHandSideMistHandlers;
}
