/*
 * function: SCRCMD_PROC_CallMenuProc
 * address:  0x0215CCE8
 * packet:   pkt_ov010_0215CCE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   EVENT_MENUPROC_Entry  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 */

typedef unsigned int u32;

typedef struct { u32 a; u32 b; } Arg;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void SCRIPT_SYS_CallEvent(void *, void *);
extern void EVENT_MENUPROC_Entry(void);
extern char ov003_id[];

int SCRCMD_PROC_CallMenuProc(void *a, void *b)
{
    Arg arg;
    void *t = SCRCMD_WORK_GetScriptWork(b);
    void *h = SCRCMD_WORK_GetGameSystem(b);
    u32 k = !SCRIPT_WORK_ReadWorkValue(a, b) ? 1 : 2;
    arg.a = (u32)GAMESYSTEM_GetFieldMap(h);
    arg.b = k;
    SCRIPT_SYS_CallEvent(t, GAME_EVENT_CreateOverlayEvent(h, (u32)ov003_id, (void *)EVENT_MENUPROC_Entry, (u32)(&arg)));
    return 1;
}
