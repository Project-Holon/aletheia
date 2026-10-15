/*
 * function: INTRO_CMD_CmdPrintText
 * address: 0x021BE478
 * packet: pkt_ov204_021BE478
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_MSG_PrintText 0x021BF23C thumb ov204
 *   INTRO_MSG_UpdatePrint 0x021BF2F4 thumb ov204
 */
#include "../include/Obj14608.h"
extern void INTRO_MSG_PrintText(char *,void *,int);
extern int INTRO_MSG_UpdatePrint(char *);
int INTRO_CMD_CmdPrintText(char *p,int *state,unsigned *q){switch(*state){case 0:INTRO_MSG_PrintText(*(char * *)&((struct Obj14608 *)p)->f18,(void *)q[0],q[1]);(*state)++;break;case 1:if(INTRO_MSG_UpdatePrint(*(char * *)&((struct Obj14608 *)p)->f18))return 1;break;}return 0;}
