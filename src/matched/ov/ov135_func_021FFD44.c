/*
 * function: WORLDTRADE_SUBLCD_SetSlotActorPositions
 * address: 0x021FFD44
 * packet: pkt_ov135_021FFD44
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 */
#include "../include/Obj10591.h"
extern void WORLDTRADE_SetActorSurfacePos(void *,int,int);
void WORLDTRADE_SUBLCD_SetSlotActorPositions(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=((struct Obj10591 *)a)->fD0C;if(v) WORLDTRADE_SetActorSurfacePos(v,((struct Obj10591 *)a)->fEC4,((struct Obj10591 *)a)->fEC6);}}
