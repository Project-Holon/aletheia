/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm
 * address: 0x0217B468
 * packet: pkt_ov176_0217B468
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_SetOption 0x0217B93C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone 0x0217B964 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuMain 0x0217B3C0 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *,int);
extern int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *p);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int p, unsigned *state, int *q);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *,int);
void BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm(int *p,int *state,u8 *q) {switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetOption((int *)q,1);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)q)==1) WIFIBATTLEMATCH_UTIL_SetCallback(p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain);break;}}
