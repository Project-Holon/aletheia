/*
 * function: HAND_ITEM_AddLeppaBerry
 * address: 0x021DD234
 * packet: pkt_ov093_021DD234
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCAE8.c and filed here.
 *
 * symbols:
 *   gLeppaBerryHandlers 0x021F1E6C data ov093 a4
 */

int *HAND_ITEM_AddLeppaBerry(int *p);
extern int gLeppaBerryHandlers[];

int *HAND_ITEM_AddLeppaBerry(int *p)
{
    *p = 7;
    return gLeppaBerryHandlers;
}
