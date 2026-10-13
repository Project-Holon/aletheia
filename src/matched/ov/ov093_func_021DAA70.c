/*
 * function: BTL_ABILITY_DrySkinBoostFireDamage
 * address: 0x021DAA70
 * packet: pkt_ov093_021DAA70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int, int);

void BTL_ABILITY_DrySkinBoostFireDamage(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x16) == 9)
        BTL_EVENT_MultiplyVar(0x31, 5 << 10);
}
