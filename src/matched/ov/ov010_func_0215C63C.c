/*
 * function: SCRCMD_PROC_StartOverlayProc
 * address:  0x0215C63C
 * packet:   pkt_ov010_0215C63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with GAMESYSTEM_CallProc, parks the record in the
 * script's slot and waits on SCRCMD_PROC_WaitOverlayProc.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_PROC_WaitOverlayProc  0x0215C69C  thumb  ov010
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ProcHandoff {
    void *work;         /* 0x00 */
    u32 arg1;           /* 0x04 */
    u32 arg0;           /* 0x08 */
} ProcHandoff;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRIPT_WORK_GetUserWorkPtr(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct IcaAnime;
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_PROC_WaitOverlayProc(int a0, int a1);
extern const char sAllocSiteScrcmdProc[];

void SCRCMD_PROC_StartOverlayProc(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1)
{
    void *sys;
    void **slot;
    ProcHandoff *h;

    sys = SCRCMD_WORK_GetGameSystem(vm);
    slot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(vm));
    h = func_02030734(4, sizeof(ProcHandoff), 1, sAllocSiteScrcmdProc, 0x8B);
    h->work = work;
    h->arg1 = arg1;
    h->arg0 = arg0;
    GAMESYSTEM_CallProc(sys, ovId, (void *)proc, work);
    *slot = h;
    VM_SetWait(c, (int)SCRCMD_PROC_WaitOverlayProc);
}
