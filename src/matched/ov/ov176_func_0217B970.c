/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_FinishMenu
 * address: 0x0217B970
 * packet: pkt_ov176_0217B970
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_EndMenu 0x0217B3B8 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 */
extern void BATTLE_CHAMPIONSHIP_FLOW_EndMenu(int p);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(int *p,int a) {p[4]=a;WIFIBATTLEMATCH_UTIL_SetCallback((int *)p[0],(int)BATTLE_CHAMPIONSHIP_FLOW_EndMenu);}
