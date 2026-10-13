/*
 * function: OEKAKI_StepWaitQuitMessage
 * address:  0x021856CC
 * packet:   pkt_021856CC
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_IsMessageDone  0x021862B0  thumb  ov023
 */
#include "../include/Obj20350.h"

extern void OEKAKI_ApplyRemoteStrokes(char *p);
typedef unsigned int   u32;
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern int  OEKAKI_IsMessageDone(char *p);

int OEKAKI_StepWaitQuitMessage(char *p, int a1)
{
    if (OEKAKI_IsMessageDone(p)) {
        ((struct Obj20350 *)p)->f1A4 = 0;
        OEKAKI_SetNextScene(p, 0xe);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
