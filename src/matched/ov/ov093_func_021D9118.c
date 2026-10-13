/*
 * unit: yes
 * function: BTL_ABILITY_IronFistBoostPunchPower, BTL_ABILITY_GetIronFistHandlers
 * address: 0x021D9118
 * packet: pkt_ov093_021D9118
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   gIronFistHandlerTable 0x021F0758 data a4
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int, int);
extern unsigned int WAZA_TOOL_GetFlag(unsigned short, unsigned int);
extern unsigned int gIronFistHandlerTable;
void BTL_ABILITY_IronFistBoostPunchPower(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 7)) BTL_EVENT_MultiplyVar(0x31, 0x1333);
}
void *BTL_ABILITY_GetIronFistHandlers(int *p) { *p = 1; return &gIronFistHandlerTable; }
