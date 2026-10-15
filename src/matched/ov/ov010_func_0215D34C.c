/*
 * function: SCRCMD_MUSICAL_StartMusical
 * address:  0x0215D34C
 * packet:   pkt_ov010_0215D34C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 * checks: 1 own 02159B10 and 0215901C prove full-width fallback return; corrected extern u32 and arg u32 produce27/284, old17 invalid; other own/caller arities reviewed; 2 D468 no closing twin; 3 typed context copy27/284, u16 mode with narrow arg228/288; 4 width/homing idioms read; 5 refreshed idioms/neighbours, no local aggregate.
 * renewed-pass: vm reused as mode and u32 vm both unchanged; no repeated permuter (old seed 9604 already consumed).
 *
 * Script command: start the ov010 link sequence (MUSICAL_EVENT_Create) for mode
 * 0/1, or push the ov112 proc through FIELD_STATUS_CreateSubProcCallbackEvent otherwise.
 * Size-exact, 27 bytes out with corrected full-width return: the image keeps vm in r4 and c in r5 (the
 * mode byte, the task work and the box then reuse r4); this C swaps them.
 * Old 17-byte score used an unjustified u16 return extern and is superseded.
 * Cursor idiom applied; historical declaration orders and seed9604 remain spent.
 * ov112_id now resolves as overlay_id at FIELD_STATUS_CreateSubProcCallbackEvent; the pooled
 * callback 0x0215DF6C still lacks a witness. No leaf filed while DIFF.
 *
 * wave76: Five compiles: widened arg27/284; u16 mode plus corrected u32 extern228/288; u32 extern/arg with u8 mode27/284; byte context parameter copied to typed local27/284; observed u8 call parameter instead of inline cast27/284. Final authorized retry exhausted; seed9604 permuter remains spent.
 * evidence76: scratchpad/overlay-newpass-20261003-w76/R2/; each log awaited to terminal exit.
 *
 * recoup 2026-10-05 (lane X1, wave P9): MATCH, 284/284 bytes, only the pooled callback
 * 0x0215DF6C lacks a witness (12-byte Thumb tail stub before 0215DF78, looks like a veneer into
 * arm9 020307B0; not filed). Same bytes at --lang c99 and --lang c.
 * Two changes versus the DIFF draft: (1) `d = (mode == 0) ? 0 : 1;` instead of `d = 1; if (mode == 0) d = 0;`
 * removed the vm/c register swap (27 B to 10 B); (2) SCRIPT_WORK_ReadWorkValue declared `u16` and `arg` held in a
 * u16 local moved the outgoing `str r7,[sp]` ahead of the reloads (10 B to 0), per
 * docs/idioms/a-u16-accessor-result-held-in-a-u16-local-moves-the-stack-argument-stores.md.
 * The matched definition of SCRIPT_WORK_ReadWorkValue returns u32 (tail value of SCRIPT_WORK_GetWorkValue); the u16
 * prototype is the one six matched files already use, so the callee is declared as its callers see it.
 * Tried and inert: pragmas (six, all 27 B), `*c->pc++` (31 B), pc pointer local (27 B), reversed
 * declaration order (40 B), `u8 d` (165 B), `u32 link` (10 B).
 * Callee arity: SCRIPT_WORK_ResetFieldParam returns a+0x18 (result ignored); GAME_DATA_GetSaveBlock2A is void in its matched
 * file but its result (sv) is used here, so the caller treats it as returning a pointer.
 * No void-return problem found on the other callees.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MUSICAL_EVENT_Create  0x02155A98  thumb  ov010
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   func_02011290  0x02011290  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   func_02030734  0x02030734  arm
 *   MUSICAL_SAVE_NoOp  0x0200A640  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_MUSICAL_TaskStartMusical  0x0215DE58  thumb  ov010
 *   SCRCMD_MUSICAL_FreeProcArgs  0x0215DF6C  thumb  ov010
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data
 *   d_021F8360     0x021F8360  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

typedef struct Starter {
    void *seq;          /* 0x00 */
    void *link;         /* 0x04 */
    u32 mode;           /* 0x08 */
} Starter;

typedef struct Args {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    void *f08;          /* 0x08 */
} Args;

typedef struct Box {
    Args *args;         /* 0x00 */
} Box;

typedef u32 (*TaskFn)(void *task, u32 *state, void *work);

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
struct BigObj;
struct Desc;
struct Obj;
struct ScriptVm;
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 SCRIPT_WORK_ReadWorkValue(Ctx *c, void *vm);
extern int GAME_DATA_GetExternalWork(char *base);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct Link;
extern void *MUSICAL_EVENT_Create(void *a, void *b, u8 c, u32 d, struct Link *link);
extern void SCRIPT_SYS_SetNextEventFromWork(void *a, void *task);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void *GAME_DATA_GetSaveBlock2A(void *sys);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void *MUSICAL_SAVE_NoOp(void *sv);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void SCRIPT_SYS_CallEvent(void *a, void *task);
extern u32 SCRCMD_MUSICAL_TaskStartMusical(void *task, u32 *state, void *work);
extern void SCRCMD_MUSICAL_FreeProcArgs(void **p);
extern u8 ov112_id[];
extern const char d_02172914[];
extern u8 d_021F8360[];

int SCRCMD_MUSICAL_StartMusical(Ctx *c, void *vm)
{
    void *a;
    void *evt;
    void *sys;
    void *proc;
    u16 arg;
    u8 mode;

    a = SCRCMD_WORK_GetScriptWork(vm);
    evt = SCRCMD_WORK_GetGameSystem(vm);
    sys = SCRCMD_WORK_GetGameData(vm);
    proc = ICA_ANIME_GetField20(evt);
    SCRIPT_WORK_ResetFieldParam((int)a);
    arg = SCRIPT_WORK_ReadWorkValue(c, vm);
    mode = *c->pc;
    c->pc++;
    if (mode <= 1) {
        void *link = (void *)GAME_DATA_GetExternalWork(sys);
        u32 d;
        void *task;
        Starter *s;

        d = (mode == 0) ? 0 : 1;
        task = func_020122C0(evt, 0, SCRCMD_MUSICAL_TaskStartMusical, sizeof(Starter));
        s = func_020124E8(task);
        MI_CpuFill8(s, 0, sizeof(Starter));
        s->seq = MUSICAL_EVENT_Create(evt, sys, arg, d, link);
        s->link = link;
        s->mode = d;
        SCRIPT_SYS_SetNextEventFromWork(a, task);
        GAME_DATA_GetBgmInfo(sys);
        func_02011290((struct ScriptVm *)c);
        return 1;
    } else {
        void *sv = GAME_DATA_GetSaveBlock2A(sys);
        Box *box;

        box = func_02030734(4, sizeof(Box), 1, d_02172914, 0xA9);
        box->args = func_02030734(4, 0x14, 1, d_02172914, 0xAA);
        box->args->f00 = 0;
        box->args->f08 = MUSICAL_SAVE_NoOp(sv);
        box->args->f04 = 1;
        SCRIPT_SYS_CallEvent(a, FIELD_STATUS_CreateSubProcCallbackEvent(evt, (int)proc, (u32)ov112_id, (int)d_021F8360, (int)box->args, (int)SCRCMD_MUSICAL_FreeProcArgs, (int)box));
        return 1;
    }
}
