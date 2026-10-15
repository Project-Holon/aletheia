/*
 * function: STA_ACTING_RequestAction
 * address: 0x021F9730
 * packet: pkt_ov132_021F9730
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STA_ACTING_ApplyAction 0x021F9754 thumb ov132
 */
#include "../include/Obj08153.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void STA_ACTING_ApplyAction(char *p, u32 i, int v);
void STA_ACTING_RequestAction(char *p,int value){if(!**(int * *)&((struct Obj08153 *)p)->f30)STA_ACTING_ApplyAction(p,((struct Obj08153 *)p)->fA,value);else{((struct Obj08153 *)p)->f15C=1;((struct Obj08153 *)p)->f160=value;}}
