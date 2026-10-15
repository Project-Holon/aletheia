/*
 * function: MUSICAL_MCSS_SetFieldA
 * address: 0x021F622C
 * packet: pkt_ov112_021F622C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: blocker leaf of MUSICAL_MCSS_SetRenderFieldA; following 021F6230 is already matched.
 */
#include "../include/Obj22543.h"
void MUSICAL_MCSS_SetFieldA(char *p,int b) { ((struct Obj22543 *)p)->fC=b; }
