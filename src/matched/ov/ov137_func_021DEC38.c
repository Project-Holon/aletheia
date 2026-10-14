/*
 * function: GURU2_MAIN_StateSendCancel
 * address: 0x021DEC38
 * packet: pkt_ov137_021DEC38
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj10618.h"
typedef unsigned short u16;
extern int GURU2_COMM_Send(void *,int,void *,int);
int GURU2_MAIN_StateSendCancel(char *p) {if(GURU2_COMM_Send(((struct Obj10618 *)p)->fDC,0x2806,0,0)==1){((struct Obj10618 *)p)->f0=9;((struct Obj10618 *)p)->f10=0;return 0;}return 0;}
