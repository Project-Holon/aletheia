/*
 * function: BTL_HANDLER_ITEM_HpBerryCheckOnUse
 * address: 0x021DDDFC
 * packet: pkt_ov093_021DDDFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_HANDLER_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *func_021C7CF4(int *p, int i);
extern int BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(void *, int, unsigned int);
extern void BTL_HANDLER_ITEM_PushUseItem(void *, void *, int);
extern int BTL_HANDLER_ITEM_GetParam(int, int);

void BTL_HANDLER_ITEM_HpBerryCheckOnUse(int a, void *b, int c)
{
    func_021C7CF4(b, c);
    if (BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(b, c, BTL_HANDLER_ITEM_GetParam(a, 2)) != 0) BTL_HANDLER_ITEM_PushUseItem((void *)a, b, c);
}
