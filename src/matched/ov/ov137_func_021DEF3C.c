/*
 * function: GURU2_MAIN_StateSendRoleChild
 * address: 0x021DEF3C
 * packet: pkt_ov137_021DEF3C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj14223.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GURU2_COMM_Send(void *,int,void *,int);
int GURU2_MAIN_StateSendRoleChild(u8 *p) { u16 buf; buf=4; if(GURU2_COMM_Send(((struct Obj14223 *)p)->fDC,0x2805,&buf,2)==1) ((struct Obj14223 *)p)->f0=22; return 0; }
