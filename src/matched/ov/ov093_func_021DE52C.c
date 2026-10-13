/*
 * function: HAND_ITEM_GetWideLensHandlers
 * address: 0x021DE52C
 * packet: pkt_ov093_021DE52C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE4A0.c and filed here.
 *
 * symbols:
 *   gWideLensHandlers 0x021F1584 data ov093 a4
 */

int *HAND_ITEM_GetWideLensHandlers(int *p);
extern int gWideLensHandlers[];

int *HAND_ITEM_GetWideLensHandlers(int *p)
{
    *p = 1;
    return gWideLensHandlers;
}
