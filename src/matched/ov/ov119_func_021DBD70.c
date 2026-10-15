/*
 * function: POKETRADE_PROC_IsTradeTargetValid
 * address: 0x021DBD70
 * packet: pkt_ov119_021DBD70
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_FindOfferIndex 0x021DD34C thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_PROC_IsHostSide(void *);
extern int POKETRADE_NEGO_FindOfferIndex(char *p, int a, int b);
int POKETRADE_PROC_IsTradeTargetValid(char *p,int a,int b) {
 if(POKETRADE_PROC_IsHostSide(p)==0) {
  if(((struct Obj00001 *)p)->fF84==b && ((struct Obj00001 *)p)->fF88==a) return 1;
 } else { if(POKETRADE_NEGO_FindOfferIndex(p,a,b)!=-1) return 1; }
 return 0;
}
