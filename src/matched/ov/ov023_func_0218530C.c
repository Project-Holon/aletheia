/*
 * function: OEKAKI_StepDraw
 * address:  0x0218530C
 * packet:   pkt_ov023_0218530C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_HandleTouch  0x021850A0  thumb  ov023
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_CountMembers  0x02185F50  thumb  ov023
 *   OEKAKI_SendStrokes  0x021860D0  thumb  ov023
 *   OEKAKI_UpdateRemoteCursors  0x02185EA0  thumb  ov023
 *   OEKAKI_DrawStrokes  0x02185DE8  thumb  ov023
 */
#include "../include/Obj01221.h"

typedef unsigned int u32;

extern void OEKAKI_HandleTouch(char *p);
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int OEKAKI_CountMembers(char *p);
extern void OEKAKI_SendStrokes(char *p);
struct P;
extern void OEKAKI_UpdateRemoteCursors(struct P *p);
struct e6;
struct o4;
extern void OEKAKI_DrawStrokes(char *p, struct e6 *e, struct o4 *o, int flag);

int OEKAKI_StepDraw(char *p, int x)
{
    OEKAKI_HandleTouch(p);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (OEKAKI_CountMembers(p) == 1) {
        } else {
            OEKAKI_SendStrokes(p);
        }
    } else {
        OEKAKI_SendStrokes(p);
    }
    OEKAKI_UpdateRemoteCursors((struct P *)p);
    OEKAKI_DrawStrokes((char *)(((struct Obj01221 *)p)->f118), (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 1);
    return x;
}
