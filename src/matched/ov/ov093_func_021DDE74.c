/*
 * function: BTL_HANDLER_ITEM_IsHpLowForTrigger
 * address: 0x021DDE74
 * packet: pkt_ov093_021DDE74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(void *, int, unsigned int);
extern int BTL_EVENT_GetVar(int);

int BTL_HANDLER_ITEM_IsHpLowForTrigger(int a, void *b, int c, unsigned int d)
{
    if (c == BTL_EVENT_GetVar(2) && (unsigned char)BTL_EVENT_GetVar(46) <= 1) return BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(b, c, d);
    return 0;
}
