/*
 * function: PLIST_MENU_HasMonParam
 * address: 0x021BCC2C
 * packet: pkt_ov091_021BCC2C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
extern unsigned int POKE_TOOL_GetPartyValue(void *, unsigned int, unsigned int);
int PLIST_MENU_HasMonParam(void *p, int i, int a2) { int r = 0; if (POKE_TOOL_GetPartyValue(p,i,0)) r=1; return r; }
