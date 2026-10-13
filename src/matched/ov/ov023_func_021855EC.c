/*
 * function: OEKAKI_StepWaitQuitReply
 * address:  0x021855EC
 * packet:   pkt_021855EC
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
 */
#include "../include/Obj09769.h"

extern void OEKAKI_ApplyRemoteStrokes(char *p);
typedef unsigned int   u32;
extern void OEKAKI_SetNextScene(char *p, u32 v);

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

int OEKAKI_StepWaitQuitReply(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj09769 *)p)->f9286 += 1;
    if (((struct Obj09769 *)p)->f9286 > 0x1e) {
        OEKAKI_SetNextScene((char *)p, 0xa);
        ((struct Obj09769 *)p)->f9286 = 0;
    }
    OEKAKI_ApplyRemoteStrokes((char *)p);
    return a1;
}
