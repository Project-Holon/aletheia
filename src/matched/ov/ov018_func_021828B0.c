/*
 * function: EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent
 * address: 0x021828B0
 * packet: pkt_ov018_021828B0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov018/intrude_subdisp.c and filed here.
 *
 * symbols:
 *   EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent 0x021825F8 thumb ov018
 */

void EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent(void *a, void *b);
void EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent(void *a, void *b);

#pragma opt_propagation off
#pragma opt_propagation reset

void EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent(void *a, void *b)
{
    EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent(a, b);
}
