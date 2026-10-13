/*
 * unit: yes
 * function: HAND_POS_GetHandlersHealingWish
 * address: 0x068987A8
 * packet: pkt_ov095_068987A8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 12-byte store-and-return follower after non-C veneer 06898798.
 * symbols:
 *   gHandPosHealingWishHandlers 0x0689D6A8 data a4
 */
extern unsigned char gHandPosHealingWishHandlers[];
void *HAND_POS_GetHandlersHealingWish(unsigned int *state)
{
    *state = 2;
    return gHandPosHealingWishHandlers;
}
