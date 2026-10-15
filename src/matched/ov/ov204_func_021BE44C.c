/*
 * function: func_021BE44C
 * address: 0x021BE44C
 * packet: pkt_ov204_021BE44C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_MSG_SetMsgBank 0x021BF204 thumb ov204
 */
#include "../include/Obj25350.h"
extern void INTRO_MSG_SetMsgBank(char *,void *,unsigned short);
int func_021BE44C(char *p,int *state,unsigned *q){INTRO_MSG_SetMsgBank(*(char * *)&((struct Obj25350 *)p)->f18,(void *)q[0],q[1]);return 1;}
