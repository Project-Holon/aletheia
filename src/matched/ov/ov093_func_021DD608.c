/*
 * function: HAND_ITEM_GetFlavorHealAttackHandlers
 * address: 0x021DD608
 * packet: pkt_ov093_021DD608
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DD588.c and filed here.
 *
 * symbols:
 *   gBtlItemFlavorHealAttackHandlers 0x021F1C04 data ov093 a4
 */

int *HAND_ITEM_GetFlavorHealAttackHandlers(int *p);
extern int gBtlItemFlavorHealAttackHandlers[];

int *HAND_ITEM_GetFlavorHealAttackHandlers(int *p)
{
    *p = 5;
    return gBtlItemFlavorHealAttackHandlers;
}
