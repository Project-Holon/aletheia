/*
 * function: FIELD_INTRUDE_EVENT_IntrudeRequestEventMain
 * address:  0x0216B280
 * packet:   pkt_ov010_0216B280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SendValueNow  0x02176850  thumb  ov011
 *   INTRUDE_COMM_IsRecordReceived  0x02176870  thumb  ov011
 */
#include "../include/Obj09327.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_COMM_SendValueNow(u8 *p, u8 value);
extern u32 INTRUDE_COMM_IsRecordReceived(u8 *p);

int FIELD_INTRUDE_EVENT_IntrudeRequestEventMain(int a0, int *state, u8 **work)
{
    int r;
    u16 *p;

    r = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)GAME_EVENT_GetGameSystem((struct Obj *)a0)));
    if (r == 0) {
        p = *(u16 * *)&((struct Obj09327 *)work)->f0;
        if (p != 0)
            *p = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (INTRUDE_COMM_SendValueNow((u8 *)r, ((u8 *)work)[4]) == 1)
            (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_IsRecordReceived((u8 *)r) == 1)
            (*state)++;
        break;
    case 2:
        p = *(u16 * *)&((struct Obj09327 *)work)->f0;
        if (p != 0)
            *p = 1;
        return 1;
    }
    return 0;
}
