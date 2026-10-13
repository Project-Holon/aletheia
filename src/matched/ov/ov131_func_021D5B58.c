/*
 * function: P_STATUS_ChangePokemon
 * address: 0x021D5B58
 * packet: pkt_ov131_021D5B58
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_SearchPokemon 0x021D5BAC thumb ov131
 *   P_STATUS_LoadPokemonState 0x021D5C4C thumb ov131
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb  arm9
 */
#include "../include/Obj00039.h"
typedef unsigned int   u32;
struct Mon;
struct Sav;
extern int P_STATUS_SearchPokemon(unsigned char *p, int direction, unsigned short *out);
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern u32 func_020307B0(void *p);
extern void *P_STATUS_GetPokePara(unsigned char *p);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void P_STATUS_LoadPokemonState(unsigned char *p);
int P_STATUS_ChangePokemon(unsigned char *p,int a) {
 unsigned short n;
 int r=P_STATUS_SearchPokemon(p,a,&n);
 if(r==1) {
 ((struct Obj00039 *)p)->f18=n;
 if((*(unsigned char **)(p+8))[12]==2) {
 if(((struct Obj00039 *)p)->f258) {POKE_TOOL_ClearPartyParam(((struct Obj00039 *)p)->f258);func_020307B0(((struct Obj00039 *)p)->f258);}
 ((struct Obj00039 *)p)->f258=func_0201747C(P_STATUS_GetPokePara(p),((struct Obj00039 *)p)->f0);
 }
 P_STATUS_LoadPokemonState(p);
 }
 return r;
}
