/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm
 * address: 0x0217B768
 * packet: pkt_ov176_0217B768
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_SetOption 0x0217B93C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone 0x0217B964 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuExtra 0x0217B6AC thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *,int);
extern int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *p);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int p, unsigned *state, int *q);
extern void func_021E8AA0(int *,int);
void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm(int *p,int *state,u8 *q) {switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetOption((int *)q,15);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)q)==1) func_021E8AA0(p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);break;}}
