/*
 * function: P_STATUS_SearchPokemon
 * address: 0x021D5BAC
 * packet: pkt_ov131_021D5BAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_HasRibbon 0x021D62F4 thumb ov131
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */
#include "../include/Obj03284.h"
typedef unsigned int   u32;
extern void *P_STATUS_GetPokePara(unsigned char *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern int P_STATUS_HasRibbon(char *p, void *q);
int P_STATUS_SearchPokemon(unsigned char *p,int direction,unsigned short *out) {
 int result=0;
 int old;
 int done;
 void *m;
 done=0;
 old=((struct Obj03284 *)p)->f18;
 do {
 if(direction==1 && ((struct Obj03284 *)p)->f18>=(*(unsigned char **)(p+8))[14]-1) {done=1;continue;}
 if(direction==0 && ((struct Obj03284 *)p)->f18==0) {done=1;continue;}
 if(direction==1) ++((struct Obj03284 *)p)->f18; else --((struct Obj03284 *)p)->f18;
 m=P_STATUS_GetPokePara(p);
 if(POKE_TOOL_GetBoxValue(m,169,0)!=0) {
 if(POKE_TOOL_GetBoxValue(m,76,0)!=1 || ((struct Obj03284 *)p)->f58==0) {
 if(((struct Obj03284 *)p)->f58!=2 || P_STATUS_HasRibbon((char *)p,m)!=0) {done=1;result=1;}
 }
 }
 } while(done==0);
 if(out) *out=((struct Obj03284 *)p)->f18;
 ((struct Obj03284 *)p)->f18=old;
 return result;
}
