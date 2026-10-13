/*
 * function: SCRCMD_MUSICAL_LinkControl
 * address:  0x0215DB38
 * packet:   pkt_ov010_0215DB38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result slot, then opens or closes the link work (0, 1), starts the
 * ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the slot (19..21).
 *
 * Byte-correct (first draft plus ov100_id for the pooled 0x64). Evidence
 * gaps, not C: 0x021FDA6C (ov132) has no func_ label; ov100_id is passed to
 * FIELD_STATUS_CreateSubProcCallbackEvent (r2), which is not in the overlay_id consumer list;
 * d_021BB6A4 is another overlay's proc data (same gap as func_02155478).
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 *
 * 2026-10-05 (wave D9): EXACT. d_021BB6A4 (ov100 process data) resolves with the ov100 token on its symbols line.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_IsAborted  0x02156BCC  thumb  ov010
 *   SCRCMD_MUSICAL_CreateLinkWork  0x0215DDC8  thumb  ov010
 *   SCRCMD_MUSICAL_DeleteLinkWork  0x0215DE0C  thumb  ov010
 *   SCRCMD_MUSICAL_BeginCommSession  0x0215DE38  thumb  ov010
 *   SCRCMD_MUSICAL_CloseCommSession  0x0215DE44  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_MUSICAL_LinkProcCallback  0x0215DF78  thumb  ov010
 *   SCRCMD_MUSICAL_WaitEntryMenuParent  0x0215DFB4  thumb  ov010
 *   SCRCMD_MUSICAL_WaitEntryMenuChild  0x0215E010  thumb  ov010
 *   SCRCMD_MUSICAL_WaitSetMemberCount  0x0215E068  thumb  ov010
 *   SCRCMD_MUSICAL_WaitSessionReady  0x0215E0B0  thumb  ov010
 *   SCRCMD_MUSICAL_WaitCommAttach  0x0215E0EC  thumb  ov010
 *   SCRCMD_MUSICAL_WaitCommIdle  0x0215E130  thumb  ov010
 *   SCRCMD_MUSICAL_WaitSessionFinish  0x0215E184  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02030734  0x02030734  arm
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   func_021FCDEC  0x021FCDEC  thumb  ov132
 *   func_021FDA6C  0x021FDA6C  thumb  ov132
 *   d_02172914     0x02172914  data  a1
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   ov100_id       0x00000064  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Link {
    void *f00;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
    u16 *f30;           /* 0x30 */
    u16 f34;            /* 0x34 */
} Link;

typedef struct Wait {
    void *vm;
    Link *link;
} Wait;

extern const char d_02172914[];
extern u8 d_021BB6A4[];
extern u8 ov100_id[];

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
extern u16 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern void MUSICAL_EVENT_CheckNetError(void *p);
extern u32 MUSICAL_EVENT_IsAborted(void *p);
extern void SCRCMD_MUSICAL_CreateLinkWork(void *evt, void *h);
struct Ctx;
extern void SCRCMD_MUSICAL_DeleteLinkWork(void *w, void *h);
extern void SCRCMD_MUSICAL_BeginCommSession(int a, void *b, void *c, int d);
extern void SCRCMD_MUSICAL_CloseCommSession(int a0);
extern void SCRIPT_SYS_CallEvent(void *evt, void *task);
extern void SCRCMD_MUSICAL_LinkProcCallback(int a0, int a1, int a2);
extern int SCRCMD_MUSICAL_WaitEntryMenuParent(int a0, int a1);
extern int SCRCMD_MUSICAL_WaitEntryMenuChild(void *a, void *b);
extern int SCRCMD_MUSICAL_WaitSetMemberCount(int a0, int a1);
extern int SCRCMD_MUSICAL_WaitSessionReady(int a0, int a1);
extern int SCRCMD_MUSICAL_WaitCommAttach(int a0, int a1);
extern int SCRCMD_MUSICAL_WaitCommIdle(void *a, void *b);
extern int SCRCMD_MUSICAL_WaitSessionFinish(int a0, int a1);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Ctx;
extern void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int GAME_DATA_GetExternalWork(char *base);
extern void VM_SetWait(char *p, int val);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32 func_0200FB24(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 COMM_ENTRY_MENU_Create(void *a, void *sys, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021FCDEC(int a, int b);
extern unsigned char *func_021FDA6C(void *h);

int SCRCMD_MUSICAL_LinkControl(void *c, void *vm)
{
    void *evt;
    void *proc;
    void *h;
    void *sys;
    u16 cmd;
    u16 arg;
    u16 *dst;
    int busy;
    Link *l;

    evt = SCRCMD_WORK_GetScriptWork(vm);
    proc = SCRCMD_WORK_GetGameSystem(vm);
    h = SCRCMD_WORK_GetGameData(vm);
    sys = GAMESYSTEM_GetFieldMap(proc);
    cmd = SCRIPT_WORK_ReadWorkValue(c, vm);
    arg = SCRIPT_WORK_ReadWorkValue(c, vm);
    SCRIPT_WORK_ReadWorkValue(c, vm);
    dst = SCRIPT_WORK_ReadWorkPointer(c, vm);
    busy = 0;
    l = 0;
    if (cmd != 0 && cmd != 0x15) {
        l = (Link *)GAME_DATA_GetExternalWork(h);
        if (l->f00 != 0) {
            MUSICAL_EVENT_CheckNetError(l->f00);
            if (MUSICAL_EVENT_IsAborted(l->f00) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        SCRCMD_MUSICAL_CreateLinkWork(evt, h);
        break;
    case 1:
        SCRCMD_MUSICAL_DeleteLinkWork(l, h);
        break;
    case 10:
        SCRCMD_MUSICAL_BeginCommSession((int)l, proc, (void *)GAMESYSTEM_GetGameComm(proc), arg);
        break;
    case 11:
        SCRCMD_MUSICAL_CloseCommSession((int)l);
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitCommIdle);
        return 1;
    case 12:
        l->f30 = dst;
        l->f08 = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(h), sys, 2, 4, 4, 0, 1, 0);
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitEntryMenuParent);
        return 1;
    case 13:
        l->f30 = dst;
        l->f08 = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(h), sys, 2, 4, 4, 1, 1, 0);
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitEntryMenuChild);
        return 1;
    case 14:
        if (l->sess == 0 || busy != 0)
            break;
        l->f34 = arg;
        func_021FCDEC((int)l->sess, (u8)l->f34);
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitSetMemberCount);
        return 1;
    case 15:
        if (l->sess == 0 || busy != 0)
            break;
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitSessionReady);
        return 1;
    case 16:
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitCommAttach);
        return 1;
    case 17:
        if (l->sess == 0 || busy != 0)
            break;
        VM_SetWait(c, (int)SCRCMD_MUSICAL_WaitSessionFinish);
        return 1;
    case 18: {
        Wait *w = func_02030734(0x8004, 8, (u32)1, d_02172914, (u32)0x3C8);

        w->vm = vm;
        w->link = l;
        l->f30 = dst;
        l->f0c = h;
        l->f2c = (u32)func_021FDA6C(h);
        l->f28 = arg == 0 ? 9 : 10;
        SCRIPT_SYS_CallEvent(evt, FIELD_STATUS_CreateSubProcCallbackEvent(proc, (int)sys, (u32)ov100_id, (int)d_021BB6A4, (int)(&l->f0c), (int)SCRCMD_MUSICAL_LinkProcCallback, (int)w));
        return 1;
    }
    case 19:
        if (l->sess != 0 && busy == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 20:
        if (l->sess != 0)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 21:
        if (func_0200FB24() != 0) {
            GAMESYSTEM_SetFieldMapState(proc, 1);
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}
