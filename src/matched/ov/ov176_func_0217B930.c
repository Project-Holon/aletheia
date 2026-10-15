/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult
 * address: 0x0217B930
 * packet: pkt_ov176_0217B930
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu 0x021E8A00 thumb ov177
 */
extern int WIFIBATTLEMATCH_UTIL_UpdateMenu(int);
unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(int *p) {return WIFIBATTLEMATCH_UTIL_UpdateMenu(p[1]);}
