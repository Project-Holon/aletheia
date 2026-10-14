/*
 * function: GURU2_MAIN_StateSendPlayerCount
 * address: 0x021DEB40
 * packet: pkt_ov137_021DEB40
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GURU2_MAIN_CountReadyMembers 0x021E170C thumb ov137
 */
#include "../include/Obj01753.h"
typedef unsigned short u16;
extern int GURU2_COMM_Send(void *,int,void *,int);
extern int GURU2_MAIN_CountReadyMembers(char *);
int GURU2_MAIN_StateSendPlayerCount(char *p) {((struct Obj01753 *)p)->f30=GURU2_MAIN_CountReadyMembers(p)+1;if(GURU2_COMM_Send(((struct Obj01753 *)p)->fDC,0x280A,p+48,4)==1){((struct Obj01753 *)p)->f14=0;((struct Obj01753 *)p)->f0=6;}return 0;}
