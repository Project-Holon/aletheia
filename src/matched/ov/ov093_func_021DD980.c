/*
 * function: HAND_ITEM_GetRaiseRandomStatHandlers
 * address: 0x021DD980
 * packet: pkt_ov093_021DD980
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DD87C.c and filed here.
 *
 * symbols:
 *   gBtlItemRaiseRandomStatHandlers 0x021F1DBC data ov093 a4
 */

int *HAND_ITEM_GetRaiseRandomStatHandlers(int *p);
extern int gBtlItemRaiseRandomStatHandlers[];

/*
 * extent: two bytes of zero alignment padding after the return.
 */
int *HAND_ITEM_GetRaiseRandomStatHandlers(int *p)
{
    *p = 5;
    return gBtlItemRaiseRandomStatHandlers;
}
