/*
 * function: GURU2_MAIN_StateSendSelectedSlot
 * address: 0x021DECCC
 * packet: pkt_ov137_021DECCC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj10620.h"
typedef unsigned short u16;
extern int GURU2_COMM_Send(void *,int,void *,int);
int GURU2_MAIN_StateSendSelectedSlot(char *p) {if(GURU2_COMM_Send(((struct Obj10620 *)p)->fDC,0x280B,*(char * *)&((struct Obj10620 *)p)->fD8+4,4))((struct Obj10620 *)p)->f0=13;return 0;}
