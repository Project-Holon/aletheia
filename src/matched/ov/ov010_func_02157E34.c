/*
 * function: DELIVERY_IRC_Start
 * address:  0x02157E34
 * packet:   pkt_ov010_02157E34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DELIVERY_IRC_StartNet  0x02157E08  thumb
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb
 *   DELIVERY_IRC_StepWaitInit  0x02157DB8  thumb
 */
#include "../include/Obj07276.h"

typedef unsigned char u8;

extern int DELIVERY_IRC_StartNet(void *);
extern void DELIVERY_IRC_SetStepAtLine(int a, int b, int c);
extern void DELIVERY_IRC_StepWaitInit(int p);

int DELIVERY_IRC_Start(void *p)
{
    int r = DELIVERY_IRC_StartNet(p);
    *((u8 *)p + 0x675) = 0;
    *((u8 *)p + 0x676) = 0;
    *((u8 *)p + 0x677) = 0;
    ((struct Obj07276 *)p)->f66C = 0;
    DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepWaitInit), 0x231);
    return r;
}
