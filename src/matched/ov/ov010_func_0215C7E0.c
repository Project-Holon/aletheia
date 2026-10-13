/*
 * function: SCRCMD_PROC_CallGtsNegotiation
 * address:  0x0215C7E0
 * packet:   pkt_ov010_0215C7E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the SCRCMD_PROC_OnGtsNegotiationDone callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. d_021C78A4 resolves once its symbols line carries the ov136 token (the overlay the function loads); SCRCMD_PROC_OnGtsNegotiationDone has its own witness.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_STATUS_CreateSubProcNoFadeCallbackEvent  0x02014840  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_PROC_OnGtsNegotiationDone  0x0215C7C4  thumb  ov010
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 *   ov136_id       0x00000088  data
 *   d_021C78A4     0x021C78A4  data  ov136  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
struct Ctx;
struct Rec;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void SCRIPT_SYS_CallEvent(void *p, void *v);
extern void SCRCMD_PROC_OnGtsNegotiationDone(struct Rec *r);
extern const char sAllocSiteScrcmdProc[];
extern const u8 d_021C78A4[];
extern u8 ov136_id[];

int SCRCMD_PROC_CallGtsNegotiation(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 *a;
    u32 *b;

    slot = SCRCMD_WORK_GetScriptWork(vm);
    sys = SCRCMD_WORK_GetGameSystem(vm);
    w = GAMESYSTEM_GetGameData(sys);
    x = GAMESYSTEM_GetFieldMap(sys);
    a = func_02030734(4, 8, 0, sAllocSiteScrcmdProc, 0x14F);
    b = func_02030734(4, 8, 0, sAllocSiteScrcmdProc, 0x150);
    a[0] = (u32)w;
    b[0] = (u32)a;
    b[1] = (u32)SCRIPT_WORK_ReadWorkPointer(c, vm);
    SCRIPT_SYS_CallEvent(slot, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(sys, (int)x, (u32)ov136_id, (int)d_021C78A4, (int)a, (int)((void *)SCRCMD_PROC_OnGtsNegotiationDone), (int)b));
    return 1;
}
