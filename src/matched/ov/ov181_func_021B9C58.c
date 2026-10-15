/*
 * function: STAFF_ROLL_PrintRow
 * address: 0x021B9C58
 * packet: pkt_ov181_021B9C58
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STAFF_ROLL_PrintText 0x021BA4AC thumb ov181
 */
#include "../include/Obj14407.h"
extern void STAFF_ROLL_PrintText(char *,unsigned char *,void *,int);
void STAFF_ROLL_PrintRow(char *p,void *s,unsigned i){unsigned char *q=*(unsigned char * *)&((struct Obj14407 *)p)->f2D4+i*16;if(q[9]==0)STAFF_ROLL_PrintText(p,q,s,0);else STAFF_ROLL_PrintText(p,q,s,2);}
