/*
 * function: GURU2_MAIN_StateWaitCancelMessage
 * address: 0x021DEC64
 * packet: pkt_ov137_021DEC64
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_CountReadyMembers 0x021E170C thumb ov137
 *   GURU2_MAIN_IsMemberFlagSet 0x021E16C4 thumb ov137
 */
#include "../include/Obj01753.h"
typedef unsigned short u16;
extern int GURU2_MAIN_CountReadyMembers(char *);
extern int GURU2_MAIN_IsMemberFlagSet(char *,int);
int GURU2_MAIN_StateWaitCancelMessage(char *p) {if(GURU2_MAIN_IsMemberFlagSet(p,8)==1){((struct Obj01753 *)p)->f30=GURU2_MAIN_CountReadyMembers(p)+1;((struct Obj01753 *)p)->f0=10;}return 0;}
