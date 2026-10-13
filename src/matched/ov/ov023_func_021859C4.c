/*
 * function: OEKAKI_StepWaitSyncAck
 * address:  0x021859C4
 * packet:   pkt_ov023_021859C4
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_GetJoinedCount  0x0218654C  thumb  ov023
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_IsMessageDone  0x021862B0  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 */
#include "../include/Obj06119.h"

extern int  OEKAKI_GetJoinedCount(char *p);
extern int  OEKAKI_GetJoinedBits(char *p);
extern int  OEKAKI_IsMessageDone(char *p);
typedef unsigned int   u32;
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_ApplyRemoteStrokes(char *p);

int OEKAKI_StepWaitSyncAck(char *p, int a1)
{
    if (!((((struct Obj06119 *)p)->f927C == 0 || ((struct Obj06119 *)p)->f927C == OEKAKI_GetJoinedCount(p))
          && (OEKAKI_GetJoinedBits(p) & ((struct Obj06119 *)p)->f9280)))
        ((struct Obj06119 *)p)->f927C = 0;
    if (OEKAKI_IsMessageDone(p)) {
        OEKAKI_SetNextScene(p, 0x1a);
        ((struct Obj06119 *)p)->f1A4 = 0;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
