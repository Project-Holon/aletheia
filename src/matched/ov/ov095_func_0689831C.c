/*
 * function: HAND_POS_GetHandlersWish
 * address: 0x0689831C
 * packet: pkt_ov095_0689831C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Unlabelled follower after the 0689830C veneer; ends before existing 06898328.
 * symbols:
 *   gHandPosWishHandlers 0x0689D698 data ov095 a4
 */
extern unsigned int gHandPosWishHandlers;
unsigned int *HAND_POS_GetHandlersWish(unsigned int *p)
{
    *p = 1;
    return &gHandPosWishHandlers;
}
