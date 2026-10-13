/*
 * function: SYMBOL_MAP_ScrCmdStartPmsInput
 * address:  0x02166D30
 * packet:   pkt_ov010_02166D30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a kind and three variable pointers, starts the
 * SYMBOL_MAP_PmsInputTaskMain task over a 0x1C-byte work, and for kinds 0..5 opens the
 * matching window (PMSI_PARAM_Create), optionally filled with a message.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): byte-correct; the one
 * wildcard is the bl to arm9 0x02024108, a Thumb function (`ldrh r2, [r1]`
 * ...) with no witness outside this file (seed for the ARM9 session).
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   PMSI_PARAM_Create  0x02024044  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   PMSI_PARAM_SetSentence  0x02024108  thumb
 *   SYMBOL_MAP_PmsInputTaskMain  0x02166E50  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ChoiceWork {
    u32 kind;           /* 0x00 */
    u16 *var0;          /* 0x04 */
    u16 *var1;          /* 0x08 */
    u16 *result;        /* 0x0C */
    void *win;          /* 0x10 */
    u32 msg;            /* 0x14 */
    u32 hasMsg;         /* 0x18 */
} ChoiceWork;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern u16 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
struct Big;
struct Ctx;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Obj *PMSI_PARAM_Create(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void *func_020120F4(const struct Ctx *p);
struct Rec0200E6FC;
extern void *func_0200E6F0(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void PMSI_PARAM_SetSentence(u16 *dst, const u16 *src);
extern u32 SYMBOL_MAP_PmsInputTaskMain(void *obj, u32 *mode);

int SYMBOL_MAP_ScrCmdStartPmsInput(void *c, void *vm)
{
    u8 buf[8];
    u16 *result;
    u16 *var1;
    u16 *var0;
    void *sys;
    void *heap;
    void *owner;
    ChoiceWork *w;
    void *task;
    u16 kind;
    u32 mode;

    sys = SCRCMD_WORK_GetGameSystem(vm);
    heap = SCRCMD_WORK_GetGameData(vm);
    owner = SCRCMD_WORK_GetScriptWork(vm);
    kind = SCRIPT_WORK_ReadWorkValue(c, vm);
    var0 = SCRIPT_WORK_ReadWorkPointer(c, vm);
    var1 = SCRIPT_WORK_ReadWorkPointer(c, vm);
    result = SCRIPT_WORK_ReadWorkPointer(c, vm);
    mode = 0;
    task = func_020122C0(sys, 0, SYMBOL_MAP_PmsInputTaskMain, sizeof(ChoiceWork));
    w = func_020124E8(task);
    MI_CpuFill8(w, 0, sizeof(ChoiceWork));
    w->kind = kind;
    w->var0 = var0;
    w->var1 = var1;
    w->result = result;
    *result = 0;
    switch (kind) {
    case 0:
        w->msg = 1;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 1:
        w->msg = 2;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 2:
        w->msg = 3;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 3:
        w->msg = 4;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 4:
        w->hasMsg = 0;
        break;
    case 5:
        w->hasMsg = 0;
        mode = 1;
        break;
    default:
        w->win = 0;
        SCRIPT_SYS_CallEvent(owner, task);
        return 1;
    }
    w->win = PMSI_PARAM_Create(mode, 0, 0, 0, GAME_DATA_GetSaveControl(heap), 1);
    if (w->hasMsg) {
        func_0200E6FC(func_0200E6F0((u32)GAME_DATA_GetSaveControl(func_020120F4(sys))), w->msg, (struct Rec0200E6FC *)buf);
        PMSI_PARAM_SetSentence(w->win, (const u16 *)buf);
    }
    SCRIPT_SYS_CallEvent(owner, task);
    return 1;
}
