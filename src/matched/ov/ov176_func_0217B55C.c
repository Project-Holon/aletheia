/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuClose
 * address: 0x0217B55C
 * packet: pkt_ov176_0217B55C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BATTLE_CHAMPIONSHIP_FLOW_SetOption 0x0217B93C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone 0x0217B964 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse 0x0217B4A0 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 */
extern void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *,int);
typedef unsigned char  u8;
extern int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *p);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int p, unsigned *state, int *q);
extern void func_021E8AA0(int *p, int v);
void BATTLE_CHAMPIONSHIP_FLOW_MenuClose(int p,int *state,int *q)
{
    switch(*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(q,8); *state=1; break;
    case 1: if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)q)==1) func_021E8AA0((int *)p,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse); break;
    }
}
