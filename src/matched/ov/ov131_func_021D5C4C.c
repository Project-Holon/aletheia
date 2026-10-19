/*
 * function: P_STATUS_LoadPokemonState
 * address: 0x021D5C4C
 * packet: pkt_ov131_021D5C4C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_SetParamDecoded 0x021D60D4 thumb ov131
 *   P_STATUS_HasRibbon 0x021D62F4 thumb ov131
 *   P_STATUS_LoadPokemonState 0x021D5C4C thumb ov131
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */
#include "../include/Obj00112.h"
extern int P_STATUS_GetPokeParaSource(char *p);
typedef unsigned int   u32;
extern void *P_STATUS_GetPokePara(unsigned char *p);
extern void P_STATUS_SetParamDecoded(unsigned char *p, int a);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int P_STATUS_HasRibbon(char *p, void *q);
void P_STATUS_LoadPokemonState(unsigned char *p) {
 void *q=(void *)P_STATUS_GetPokeParaSource((char *)p);
 void *m=P_STATUS_GetPokePara(p);
 int one=1;
 P_STATUS_SetParamDecoded(p,1);
 *(int *)&((struct Obj00112 *)p)->f38=POKE_TOOL_GetPartyValue(q,76,0);
 ((struct Obj00112 *)p)->f3C=POKE_TOOL_GetPartyValue(q,9,0);
 ((struct Obj00112 *)p)->f40=P_STATUS_HasRibbon((char *)p,m);
 P_STATUS_SetParamDecoded(p,0);
 ((struct Obj00112 *)p)->f10=one;
}
