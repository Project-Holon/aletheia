/*
 * function: OEKAKI_StepOpenFinishMenu
 * address:  0x02185730
 * packet:   pkt_02185730
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_IsMessageDone  0x021862B0  thumb  ov023
 *   OEKAKI_OpenYesNoMenu  0x021865B4  thumb  ov023
 */
#include "../include/Obj02742.h"

extern void OEKAKI_ApplyRemoteStrokes(char *p);
typedef unsigned int   u32;
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern int  OEKAKI_IsMessageDone(char *p);
extern int OEKAKI_OpenYesNoMenu(char *p);

int OEKAKI_StepOpenFinishMenu(char *p, int a1)
{
    if (OEKAKI_IsMessageDone(p)) {
        if (((struct Obj02742 *)p)->f178 == 0)
            ((struct Obj02742 *)p)->f178 = (void *)OEKAKI_OpenYesNoMenu(p);
        OEKAKI_SetNextScene(p, 0x10);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
