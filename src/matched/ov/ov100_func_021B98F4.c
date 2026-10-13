/*
 * function: IRCBATTLEMATCH_GetParty
 * address: 0x021B98F4
 * packet: pkt_ov100_021B98F4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj22069.h"
int IRCBATTLEMATCH_GetParty(int a,int b)
{
 if(a>=0 && a<4) return *(int *)(((struct Obj22069 *)b)->f244+a*4+8);
 return 0;
}
