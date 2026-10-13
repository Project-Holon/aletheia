/*
 * function: SCRCMD_PROC_CallMoveRelearn
 * address: 0x0215C89C
 * packet: pkt_ov010_0215C89C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum one assigned immediately before the f19 store in the inline
 * record initializer separates it from the constant return and selects r0.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WAZA_OSHIE_CreateMoveList 0x0216F948 thumb ov010
 *   WAZA_OSHIE_Create 0x0216F918 thumb ov010
 *   func_02030734 0x02030734 arm
 *   FIELD_STATUS_CreateSubProcCallbackEvent 0x02014808 thumb
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 *   SCRCMD_PROC_OnMoveRelearnDone 0x0215C870 thumb ov010
 *   sAllocSiteScrcmdProc 0x021728F0 data a1
 *   ov173_id 0x000000AD data
 *   gMoveRelearnProcData 0x021B81D0 data ov173 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Relearn {
    void *mon;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *sys;          /* 0x0C */
    void *moves;        /* 0x10 */
    u8 pad14[5];
    u8 f19;             /* 0x19 */
} Relearn;

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *list, u32 i);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u16 *WAZA_OSHIE_CreateMoveList(void *mon, u32 heap);
extern void *WAZA_OSHIE_Create(u32 heap);
extern void *func_02030734(u32 heap, u32 size, int flags, const char *file, u16 line);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void SCRIPT_SYS_CallEvent(void *p, void *v);
extern int SCRCMD_PROC_OnMoveRelearnDone(int a0, int a1);
extern const char sAllocSiteScrcmdProc[];
extern const u8 gMoveRelearnProcData[];
extern u8 ov173_id[];

static inline void init_record(Relearn *r, void *mon, void *sess, void *sys, void *moves)
{
    enum One { ONE = 1 } one;
    r->mon = mon;
    r->sess = sess;
    r->f08 = 0;
    r->sys = sys;
    r->moves = moves;
    one = ONE;
    r->f19 = one;
}
int SCRCMD_PROC_CallMoveRelearn(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 a;
    u32 idx;
    void *mon;
    void *sess;
    void *moves;
    Relearn *r;
    u32 *h;

    slot = SCRCMD_WORK_GetScriptWork(vm);
    sys = SCRCMD_WORK_GetGameSystem(vm);
    w = GAMESYSTEM_GetGameData(sys);
    x = GAMESYSTEM_GetFieldMap(sys);
    a = (u32)SCRIPT_WORK_ReadWorkPointer(c, vm);
    idx = SCRIPT_WORK_ReadWorkValue(c, vm);
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(w), idx);
    sess = GAME_DATA_GetMyStatus(w);
    moves = WAZA_OSHIE_CreateMoveList(mon, 4);
    r = WAZA_OSHIE_Create(4);
    init_record(r, mon, sess, sys, moves);
    h = func_02030734(4, 8, 0, sAllocSiteScrcmdProc, 0x19B);
    h[0] = (u32)r;
    h[1] = a;
    SCRIPT_SYS_CallEvent(slot, FIELD_STATUS_CreateSubProcCallbackEvent(sys, (int)x, (u32)ov173_id, (int)gMoveRelearnProcData, (int)r, (int)((void *)SCRCMD_PROC_OnMoveRelearnDone), (int)h));
    return 1;
}
