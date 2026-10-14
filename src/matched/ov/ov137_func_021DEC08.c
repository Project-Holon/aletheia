/*
 * function: GURU2_MAIN_StateSendAbort
 * address: 0x021DEC08
 * packet: pkt_ov137_021DEC08
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj14221.h"
typedef unsigned short u16;
extern int GURU2_COMM_Send(void *,int,void *,int);
int GURU2_MAIN_StateSendAbort(char *p) {u16 v=8;if(GURU2_COMM_Send(((struct Obj14221 *)p)->fDC,0x2805,&v,2)==1)((struct Obj14221 *)p)->f0=10;return 0;}
