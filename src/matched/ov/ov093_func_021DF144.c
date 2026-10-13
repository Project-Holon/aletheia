/*
 * function: HAND_ITEM_GetStickyBarbHandlers
 * address: 0x021DF144
 * packet: pkt_ov093_021DF144
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gStickyBarbHandlers 0x021F16FC data
 */
extern unsigned char gStickyBarbHandlers[];

void *HAND_ITEM_GetStickyBarbHandlers(int *p)
{
    *p = 2;
    return gStickyBarbHandlers;
}
