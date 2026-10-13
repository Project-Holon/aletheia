/*
 * unit: yes
 * function: BTL_ABILITY_TruantClearLoafing, BTL_ABILITY_GetTruantHandlers
 * address: 0x021DADD8
 * packet: pkt_ov093_021DADD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gTruantHandlerTable 0x021F0B94 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 */
extern const unsigned int gTruantHandlerTable[];
extern int BTL_EVENT_GetVar(int);
void BTL_ABILITY_TruantClearLoafing(int a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(12) == 7) *d = 0; }
const unsigned int *BTL_ABILITY_GetTruantHandlers(int *n) { *n = 4; return gTruantHandlerTable; }
