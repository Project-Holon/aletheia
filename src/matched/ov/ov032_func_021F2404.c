/*
 * function: BEACON_VIEW_CreateLeaveEvent
 * address:  0x021F2404
 * packet:   pkt_ov032_021F2404
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the only wildcards are the bls to two unlabelled arm9
 * leaves, the integrator's (blocker: no witness outside the range). Verified leaf C
 * (both EXACT, thumb, `one --thumb` with no --region):
 *   0x020275B8 (12 bytes incl. pool word 0x0B0E):
 *     typedef unsigned char u8;
 *     void BEACON_STATUS_SetViewTop(char *p, u8 v) { p[0xb0e] = v; }
 *   0x020275D0 (12 bytes incl. pool word 0x0B0C):
 *     void *BEACON_STATUS_GetViewFlags(char *p) { return p + 0xb0c; }
 * 0x53 is ov083's id (GPOWER_EVENT_CreateActivateEvent/GPOWER_EVENT_CreateListEvent are ov083 children).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 *
 * symbols:
 *   BEACON_VIEW_CreateLeaveEvent 0x021F2404 thumb
 *   INTRUDE_COMM_SetCompleted 0x02158614 thumb ov010
 *   BEACON_STATUS_SetViewTop 0x020275B8 thumb
 *   BEACON_STATUS_GetViewFlags 0x020275D0 thumb
 *   FIELD_COMM_ACTOR_CreateSubscreenChangeEvent 0x021945A4 thumb ov021
 *   BEACON_VIEW_CreateTaskProc 0x021F254C thumb ov032
 *   BEACON_VIEW_ClearEndRequest 0x021F2544 thumb ov032
 *   BEACON_VIEW_EVENT_Create 0x02164B38 thumb ov010
 *   GAME_EVENT_CreateOverlayEvent 0x020124AC thumb
 *   EVENT_NAMEIN_Create 0x021CD2A4 thumb ov021
 *   GPOWER_EVENT_CreateActivateEvent 0x021F5260 thumb ov083
 *   GPOWER_EVENT_CreateListEvent 0x021F5368 thumb ov083
 *   ov083_id 0x00000053 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} Args;

extern u8 ov083_id[];
struct Desc;
extern void INTRUDE_COMM_SetCompleted(void *p);
extern void BEACON_STATUS_SetViewTop(char *p, int v);
extern void *BEACON_STATUS_GetViewFlags(char *p);
extern void *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(void *a, u32 b, u32 c);
extern void *BEACON_VIEW_CreateTaskProc(char *p, void *task, int a, u32 b);
extern void BEACON_VIEW_ClearEndRequest(char *p);
extern void *BEACON_VIEW_EVENT_Create(void *a, void *b, u8 c);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern u32 EVENT_NAMEIN_Create(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *GPOWER_EVENT_CreateActivateEvent(void *a0, int *a1);
extern void *GPOWER_EVENT_CreateListEvent(void *p, void *q);

void *BEACON_VIEW_CreateLeaveEvent(char *p, int go)
{
    void *r;
    Args args;

    if (go == 0)
        return 0;
    switch (*(u16 *)(p + 0x70)) {
    case 2:
        INTRUDE_COMM_SetCompleted((void *)(*(int *)(p + 0x1c)));
    case 1:
    case 3:
        BEACON_STATUS_SetViewTop(*(void **)(p + 0x34), 0);
        r = BEACON_VIEW_CreateTaskProc(p, FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(*(void **)p, (u32)(*(void **)(p + 8)), 0), 0, 3);
        break;
    case 4:
        r = BEACON_VIEW_CreateTaskProc(p, BEACON_VIEW_EVENT_Create(*(void **)p, *(void **)(p + 8), *(u8 *)(p + 0x7e) + *(u8 *)(p + 0x7c)), 1, 0);
        break;
    case 5:
        args.a = *(u8 *)(p + 0x7f);
        args.b = *(u8 *)(p + 0x80);
        r = BEACON_VIEW_CreateTaskProc(p, GAME_EVENT_CreateOverlayEvent(*(void **)p, (u32)ov083_id, (void *)GPOWER_EVENT_CreateActivateEvent, (u32)(&args)), 2, *(u32 *)(p + 0xd0));
        p[0x7f] = 0x30;
        break;
    case 6:
        r = BEACON_VIEW_CreateTaskProc(p, GAME_EVENT_CreateOverlayEvent(*(void **)p, (u32)ov083_id, (void *)GPOWER_EVENT_CreateListEvent, (u32)(*(void **)(p + 8))), 2, *(u32 *)(p + 0xc0));
        break;
    case 7:
        r = BEACON_VIEW_CreateTaskProc(p, GAME_EVENT_CreateOverlayEvent(*(void **)p, (u32)ov083_id, (void *)GPOWER_EVENT_CreateListEvent, (u32)(*(void **)(p + 8))), 2, *(u32 *)(p + 0xf0));
        p[0x79] = 0;
        break;
    case 8:
        r = BEACON_VIEW_CreateTaskProc(p, (void *)EVENT_NAMEIN_Create((u32)(*(void **)p), (u32)(*(void **)(p + 8)), 0, 7, (u32)BEACON_STATUS_GetViewFlags((char *)(*(int *)(p + 0x34)))), 0, 1);
        break;
    default:
        return 0;
    }
    BEACON_VIEW_ClearEndRequest(p);
    return r;
}
