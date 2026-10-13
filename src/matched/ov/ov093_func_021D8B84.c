/*
 * unit: yes
 * function: BTL_CALC_SniperBoostCritical, BTL_CALC_GetSniperHandlers
 * address: 0x021D8B84
 * packet: pkt_ov093_021D8B84
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gSniperHandlers 0x021F07B8 data a4
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int, int);
extern unsigned int gSniperHandlers;
void BTL_CALC_SniperBoostCritical(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x45)) BTL_EVENT_MultiplyVar(0x35, 3 << 11);
}
void *BTL_CALC_GetSniperHandlers(int *p) { *p = 1; return &gSniperHandlers; }
