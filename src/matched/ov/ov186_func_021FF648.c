/*
 * function: BR_NET_IsIdle
 * address: 0x021FF648
 * packet: pkt_ov186_021FF648
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_NET_IsStep 0x021FFB70 thumb ov186
 *   BR_NET_StepIdle 0x021FF8E0 thumb ov186
 */
#include "../include/Obj24855.h"
extern int BR_NET_IsStep(int *,int);
extern void BR_NET_StepIdle(void);
int BR_NET_IsIdle(char *p)
{
    return BR_NET_IsStep(*(int * *)&((struct Obj24855 *)p)->f5AC,(int)BR_NET_StepIdle);
}
