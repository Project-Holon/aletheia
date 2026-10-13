/*
 * function: HAND_ITEM_HpBerryCheckAtTurnEnd
 * address: 0x021DDDC4
 * packet: pkt_ov093_021DDDC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   HAND_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_ITEM_GetParam 0x021DCFF8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void HAND_ITEM_HpBerryCheckAndUse(int, int, int, int, int);
extern int BTL_EVENT_GetVar(int);
extern int HAND_ITEM_GetParam(int, int);

void HAND_ITEM_HpBerryCheckAtTurnEnd(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) {
        BTL_SERVER_FLOW_GetPokeParam(b, c);
        HAND_ITEM_HpBerryCheckAndUse(a, (int)b, c, HAND_ITEM_GetParam(a, 2), 0);
    }
}
