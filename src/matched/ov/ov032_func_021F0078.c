/*
 * function: BEACON_VIEW_CheckLeaveRequest
 * address:  0x021F0078
 * packet:   pkt_ov032_021F0078
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_CheckLeaveRequest  0x021F0078  thumb
 *   INTRUDE_COMM_GetVisitProgress  0x021585E0  thumb  ov010
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   BEACON_VIEW_RequestTransition  0x021F253C  thumb  ov032
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 */
#include "../include/Obj09794.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int INTRUDE_COMM_GetVisitProgress(int);
struct Ctx;
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void BEACON_VIEW_RequestTransition(char *p, int v);
extern u32 WIH_DWC_PollStatus(void *key);

int BEACON_VIEW_CheckLeaveRequest(char *p)
{
    int r;

    r = INTRUDE_COMM_GetVisitProgress(((struct Obj09794 *)p)->f1C);
    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)(((struct Obj09794 *)p)->f0)) != 0) {
        BEACON_VIEW_RequestTransition(p, 1);
        return 1;
    }
    if (r == 2) {
        BEACON_VIEW_RequestTransition(p, 2);
        return 1;
    }
    if (WIH_DWC_PollStatus((void *)(((struct Obj09794 *)p)->f20)) & 8) {
        BEACON_VIEW_RequestTransition(p, 3);
        return 1;
    }
    return 0;
}
