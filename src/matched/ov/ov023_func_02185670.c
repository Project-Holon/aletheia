/*
 * function: OEKAKI_StepCancelQuit
 * address:  0x02185670
 * packet:   pkt_02185670
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
 *   OEKAKI_SetQuitButtonPressed  0x021852F4  thumb  ov023
 */
#include "../include/Obj13025.h"

extern void OEKAKI_ApplyRemoteStrokes(char *p);
typedef unsigned int   u32;
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_SetQuitButtonPressed(void *p, int v);

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

int OEKAKI_StepCancelQuit(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj13025 *)p)->f9288 = 0;
    OEKAKI_SetNextScene((char *)p, 4);
    OEKAKI_SetQuitButtonPressed(((struct Obj13025 *)p)->f100, 0);
    OEKAKI_ApplyRemoteStrokes((char *)p);
    return a1;
}
