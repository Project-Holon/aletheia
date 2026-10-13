/*
 * function: EVENT_MAPCHANGE_RunIntrudeSessionEvent
 * address:  0x02185D38
 * packet:   pkt_ov020_02185D38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 *   INTRUDE_COMM_GetRequestState  0x02158630  thumb  ov010
 *   FIELD_CheckPlayerPositionFree  0x021D2750  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_ClearCounter  0x02026484  thumb
 *   INTRUDE_COMM_SetSuspended  0x0217574C  thumb  ov011
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   INTRUDE_COMM_AcceptSession  0x02175B4C  thumb  ov011
 *   GAME_DATA_SetIntrudeCount  0x02012B78  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GAME_DATA_SetExitMode  0x02012B64  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeArriveEvent  0x02185C4C  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x1c];
    int f1c;
    int f20;
    int f24;
    int f28;
    u8 b2c;
} Ctx;

struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *a);
struct Comm;
struct Evt;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_FIELD_IsStartRequested(u8 *o);
extern int INTRUDE_COMM_GetRequestState(int h);
typedef unsigned int   u32;
extern int FIELD_CheckPlayerPositionFree(u32 a);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern int INTRUDE_COMM_HasUnlockFlags(void *p);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_COMM_ClearCounter(void *obj);
extern void INTRUDE_COMM_SetSuspended(u8 *o, u32 v);
extern void INTRUDE_COMM_SetIntrudeId(u8 *o, u32 v);
extern void INTRUDE_COMM_AcceptSession(u8 *o, u8 *p);
struct BigObj;
extern struct BigObj *GAME_DATA_SetIntrudeCount(struct BigObj *p, u8 v);
extern int GFL_NET_SYSTEM_GetCurrentAid(int a);
extern void GAME_DATA_SetExitMode(int a, int b);
extern int EVENT_MAPCHANGE_CreateIntrudeArriveEvent(int a, int b, Ctx *c);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_MAPCHANGE_RunIntrudeSessionEvent(int a0, int *state, Ctx *c)
{
    int r;
    int h;
    int flag;
    int id;
    u8 *obj;

    h = GAMESYSTEM_GetGameComm((const struct Ctx *)c->f1c);
    switch (*state) {
    case 0:
        obj = (u8 *)INTRUDE_COMM_GetWorkIfRunning(h);
        flag = 0;
        r = 0;
        if (obj != 0) {
            r = INTRUDE_FIELD_IsStartRequested(obj);
            if (INTRUDE_COMM_GetRequestState(h) == 3)
                flag = 1;
        }
        if (r == 0 && FIELD_CheckPlayerPositionFree(c->f1c) != 0) {
            id = !flag ? 0x279A : 0x279B;
            SCRIPT_SYS_CallScriptEvent((void *)a0, id, 0, 0, FIELDMAP_GetHeapId((u8 *)c->f24));
            if (INTRUDE_COMM_HasUnlockFlags((void *)c->f20) == 0)
                GAME_COMM_RequestExitNoCallback((struct Comm *)h);
            *state = 1;
        } else {
            id = !r ? 0x279C : 0x279D;
            SCRIPT_SYS_CallScriptEvent((void *)a0, id, 0, 0, FIELDMAP_GetHeapId((u8 *)c->f24));
            *state = 3;
        }
        break;
    case 1:
        if (INTRUDE_COMM_HasUnlockFlags((void *)c->f20) == 0) {
            if (GAME_COMM_GetKind((void *)h) != 0)
                break;
            GAME_COMM_ClearCounter((void *)h);
        }
        if (c->f28 == 1 && INTRUDE_COMM_GetRequestState(h) != 3) {
            SCRIPT_SYS_CallScriptEvent((void *)a0, 0x279F, 0, 0, FIELDMAP_GetHeapId((u8 *)c->f24));
            *state = 3;
            break;
        }
        obj = (u8 *)INTRUDE_COMM_GetWorkIfRunning(h);
        if (obj != 0) {
            INTRUDE_COMM_SetSuspended(obj, 1);
            INTRUDE_COMM_SetIntrudeId(obj, c->b2c);
            if (c->f28 == 1)
                INTRUDE_COMM_AcceptSession(obj, obj + 0x1AC);
        }
        GAME_DATA_SetExitMode(c->f20, GFL_NET_SYSTEM_GetCurrentAid((int)GAME_DATA_SetIntrudeCount((struct BigObj *)c->f20, 1)));
        GAME_EVENT_CallEvent((struct Evt *)a0, (struct Evt **)EVENT_MAPCHANGE_CreateIntrudeArriveEvent(c->f1c, c->f24, c));
        *state = 2;
        break;
    case 2:
        obj = (u8 *)INTRUDE_COMM_GetWorkIfRunning(h);
        if (obj != 0)
            INTRUDE_COMM_SetSuspended(obj, 0);
        *state = 3;
        break;
    case 3:
        return 1;
    }
    return 0;
}
