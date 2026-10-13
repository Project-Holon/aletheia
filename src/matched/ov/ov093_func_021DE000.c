/*
 * function: BTL_HANDLER_ITEM_MicleBerryCheckAfterAction
 * address: 0x021DE000
 * packet: pkt_ov093_021DE000
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage 0x021DDFDC thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage(int, void *, int, int);

void BTL_HANDLER_ITEM_MicleBerryCheckAfterAction(int a, void *b, int c, int d)
{
    if (BTL_EVENT_GetVar(12) != 6) BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage(a, b, c, d);
}
