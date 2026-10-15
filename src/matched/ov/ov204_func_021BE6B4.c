/*
 * function: INTRO_CMD_CmdSavePause
 * address: 0x021BE6B4
 * packet: pkt_ov204_021BE6B4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 */
#include "../include/Obj14612.h"
extern void SAVE_CONTROL_INTR_Pause(unsigned char *);
extern int SAVE_CONTROL_INTR_IsPausedOrFinished(unsigned char *);
int INTRO_CMD_CmdSavePause(char *p,int *state,unsigned *q){switch(*state){case 0:SAVE_CONTROL_INTR_Pause(*(unsigned char * *)&((struct Obj14612 *)p)->fA4);(*state)++;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(*(unsigned char * *)&((struct Obj14612 *)p)->fA4)==1)return 1;break;}return 0;}
