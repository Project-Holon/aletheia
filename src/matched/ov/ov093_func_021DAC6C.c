/*
 * unit: yes
 * function: BTL_ABILITY_LevitateClearFlag, BTL_ABILITY_GetLevitateHandlers
 * address: 0x021DAC6C
 * packet: pkt_ov093_021DAC6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gLevitateHandlerTable 0x021F0A10 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 */
extern const unsigned int gLevitateHandlerTable[];
extern int BTL_EVENT_GetVar(int);
void BTL_ABILITY_LevitateClearFlag(int a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(2)) *d = 0; }
const unsigned int *BTL_ABILITY_GetLevitateHandlers(int *n) { *n = 3; return gLevitateHandlerTable; }
