/*
 * function: HAND_ITEM_CustapBerryMoveFirst
 * address: 0x021DDEFC
 * packet: pkt_ov093_021DDEFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   HAND_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   HAND_ITEM_PushUseItem 0x021DD044 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int HAND_ITEM_IsHpAtOrBelowFraction(void *, int, unsigned int);
extern void HAND_ITEM_PushUseItem(void *, void *, int);
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);

void HAND_ITEM_CustapBerryMoveFirst(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && HAND_ITEM_IsHpAtOrBelowFraction(b, c, 4) != 0 && BTL_EVENT_OverwriteVar(17, 2) != 0) HAND_ITEM_PushUseItem((void *)a, b, c);
}
