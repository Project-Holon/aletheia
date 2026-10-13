/*
 * function: HAND_SIDE_GetHandlersSpikes
 * address: 0x068995A4
 * packet: pkt_ov095_068995A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: C follower after the fixed linker veneer at 0x06899594.
 * symbols:
 *   gHandSideSpikesHandlers 0x0689D740 data a4
 */
typedef unsigned int u32;
extern unsigned char gHandSideSpikesHandlers[];
void *HAND_SIDE_GetHandlersSpikes(u32 *p)
{
    *p = 1;
    return gHandSideSpikesHandlers;
}
