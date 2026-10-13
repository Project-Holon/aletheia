/*
 * function: C_GEAR_PanelEventMain
 * address:  0x021F2F60
 * packet:   pkt_ov029_021F2F60
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-04 (wD2 lane 09): bytes are identical; only ABS32 +0124 (EVENT_GSYNC_Entry) is open.
 * 02154668 is a Thumb veneer (ldr r3,[pc]; bx r3) and 3 overlays overlap it (ov000, ov001, ov006).
 * Tried ov000 and ov010 on the symbols line: still no outside witness.
 *
 * Byte-correct; two sites stay wildcarded:
 *   +0130 ABS32 abs_id_124 (0x7C): a pooled overlay id (ov124, whose
 *     0x021D4D40 table is the next argument) passed as FIELD_STATUS_CreateSubProcCallbackEvent's
 *     third argument; FIELD_STATUS_CreateSubProcCallbackEvent is not in OVERLAY_ID_CONSUMERS and no
 *     other pool word holds 0x7C, so no evidence class resolves it.
 *   +0124 ABS32 EVENT_GSYNC_Entry (ov000): an unlabelled tail-call stub
 *     (`ldr r3,[pc,#0]; bx r3` -> EVENT_GSYNC_Create, 00 4b 18 47 at 0x02154668
 *     in ov000.s).  Not filed, since it is not the only blocker: C
 *     `void *EVENT_GSYNC_Entry(void *p) { return EVENT_GSYNC_Create(p); }`.
 *   abs_id_0 resolves through the GAME_EVENT_CreateOverlayEvent overlay-id consumer.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: ABS32 EVENT_GSYNC_Entry, an ov000 Thumb veneer (`ldr r3,[pc]; bx r3`), so no C witness is possible;
 * ov001 and ov006 also overlap that address.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   C_GEAR_StepRipple  0x021F009C  thumb  ov029
 *   C_GEAR_StepFadeIcon  0x021F2C78  thumb  ov029
 *   C_GEAR_StepIconAnim  0x021F2C10  thumb  ov029
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   EVENT_GSYNC_Entry  0x02154668  thumb  ov000
 *   abs_id_0       0x00000000  data
 *   func_021559E4  0x021559E4  thumb  ov010
 *   SCRCMD_NETWORK_CreateWifiProcEvent  0x0215FBF4  thumb  ov010
 *   EVENT_RESEARCH_RADAR_CreateTopTask  0x02167044  thumb  ov010
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   abs_id_124     0x0000007C  data
 *   d_021D4D40     0x021D4D40  data  ov124  a4
 *   FIELD_SUBSCREEN_CreateAnimTask  0x021D297C  thumb  ov021
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_021F3554     0x021F3554  data  a4
 * 2026-10-05 (wD8 lane06): re-run, still MATCH. Only blocker: ABS32 EVENT_GSYNC_Entry, an ov000 Thumb veneer
 * (`ldr r3,[pc]; bx r3`), so no C witness; ov000/ov001/ov006 overlap it. Needs a seeded label in ov000.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    char *p;
    int kind;
} Req;

extern u8 abs_id_0[];
extern u8 abs_id_124[];
extern int d_021D4D40;
extern int d_021F3554;

struct Ctx;
struct Desc;
struct S0201235C;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int C_GEAR_StepRipple(u8 *p);
extern int C_GEAR_StepFadeIcon(char *p);
extern int C_GEAR_StepIconAnim(char *p);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void *EVENT_GSYNC_Entry(void *p);
extern void *func_021559E4(void *a, int b, void *c, int d);
extern struct Desc *SCRCMD_NETWORK_CreateWifiProcEvent(int a0, int a1, struct Desc *a2, int a3);
extern void *EVENT_RESEARCH_RADAR_CreateTopTask(void *a, void *b);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void *FIELD_SUBSCREEN_CreateAnimTask(void *a);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int C_GEAR_PanelEventMain(void *a, int unused, Req *q)
{
    char *p;
    int h;
    int ok;
    void *x;
    int *buf;

    p = q->p;
    ok = 0;
    h = (int)GAMESYSTEM_GetFieldMap((const struct Ctx *)(*(int *)(p + 0x1c)));
    switch (q->kind) {
    case 1:
    case 5:
    case 6:
        ok = C_GEAR_StepRipple((u8 *)q->p);
        break;
    case 7:
    case 11:
        ok = C_GEAR_StepFadeIcon(q->p);
        break;
    case 12:
    case 13:
        ok = C_GEAR_StepIconAnim(q->p);
        break;
    }
    if (ok == 0)
        return 0;

    switch (q->kind) {
    case 6:
        x = GAME_EVENT_CreateOverlayEvent((void *)(*(int *)(p + 0x1c)), (u32)abs_id_0, (void *)EVENT_GSYNC_Entry, h);
        break;
    case 1:
        x = func_021559E4((void *)(*(int *)(p + 0x1c)), h, 0, 1);
        break;
    case 5:
        x = SCRCMD_NETWORK_CreateWifiProcEvent(*(int *)(p + 0x1c), h, 0, 1);
        break;
    case 11:
        x = EVENT_RESEARCH_RADAR_CreateTopTask((void *)(*(int *)(p + 0x1c)), (void *)h);
        break;
    case 7:
        x = func_021945A4((void *)(*(int *)(p + 0x1c)), h, 4);
        break;
    case 12:
        buf = func_02030734(4, 8, 1, (const char *)(&d_021F3554), 0x14B7);
        buf[0] = (int)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData((const struct Ctx *)(*(int *)(p + 0x1c))));
        buf[1] = *(int *)(p + 0x1c);
        x = FIELD_STATUS_CreateSubProcCallbackEvent((char *)(*(int *)(p + 0x1c)), h, (int)abs_id_124, (int)(&d_021D4D40), (int)buf, 0, (int)buf);
        break;
    case 13:
        x = FIELD_SUBSCREEN_CreateAnimTask((void *)(*(int *)(p + 0x1c)));
        break;
    }
    GAME_EVENT_ChangeEvent(a, x);
    return 0;
}
