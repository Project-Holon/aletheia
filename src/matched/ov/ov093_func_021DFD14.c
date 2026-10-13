/*
 * function: HAND_ITEM_GetAbsorbBulbHandlers
 * address: 0x021DFD14
 * packet: pkt_ov093_021DFD14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   gHandItemAbsorbBulbHandlers 0x021F173C data a4
 */

int *HAND_ITEM_GetAbsorbBulbHandlers(int *p);
extern int gHandItemAbsorbBulbHandlers[];

int *HAND_ITEM_GetAbsorbBulbHandlers(int *p)
{
    *p = 2;
    return gHandItemAbsorbBulbHandlers;
}
