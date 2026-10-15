/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_HideWindow
 * address: 0x0217B924
 * packet: pkt_ov176_0217B924
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu 0x021E89D0 thumb ov177
 */
extern void WIFIBATTLEMATCH_UTIL_DeleteMenu(int);
void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(int *p) {WIFIBATTLEMATCH_UTIL_DeleteMenu(p[1]);}
