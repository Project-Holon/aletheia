/*
 * function: BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage
 * address: 0x021DDFDC
 * packet: pkt_ov093_021DDFDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_HANDLER_ITEM_MicleBerryCheckHp 0x021DE024 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_HANDLER_ITEM_MicleBerryCheckHp(int, void *, int, int);

void BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage(int a, void *b, int c, int d)
{
    if (c == BTL_EVENT_GetVar(2)) BTL_HANDLER_ITEM_MicleBerryCheckHp(a, b, c, d);
}
