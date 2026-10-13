/*
 * function: HAND_SIDE_GetHandlersToxicSpikes
 * address: 0x068996C8
 * packet: pkt_ov095_068996C8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled store-and-return follower after the 0x068996B8 veneer.
 * symbols:
 *   gHandSideToxicSpikesHandlers 0x0689D708 data a4
 */
typedef unsigned int u32;
extern unsigned char gHandSideToxicSpikesHandlers[];

void *HAND_SIDE_GetHandlersToxicSpikes(u32 *p)
{
    *p = 1;
    return gHandSideToxicSpikesHandlers;
}
