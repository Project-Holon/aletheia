/*
 * function: func_021F4AA8
 * address: 0x021F4AA8
 * packet: pkt_ov194_021F4AA8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 *   func_021F4634 0x021F4634 thumb ov194
 */
#include "../include/Obj14510.h"
#include "../include/Obj24924.h"
#include "../include/Obj24925.h"
extern void SAVE_CONTROL_INTR_Pause(unsigned char *);extern int SAVE_CONTROL_INTR_IsPausedOrFinished(unsigned char *);extern void func_021F4634(unsigned char *);
void func_021F4AA8(unsigned char *p,int *state,unsigned char *q){switch(*state){case 0:SAVE_CONTROL_INTR_Pause(*(unsigned char * *)&((struct Obj24924 *)(*(unsigned char * *)&((struct Obj14510 *)q)->f2C4))->f24);*state=1;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(*(unsigned char * *)&((struct Obj24925 *)(*(unsigned char * *)&((struct Obj14510 *)q)->f2C4))->f24)==1)func_021F4634(p);break;}}
