/*
 * function: SCRCMD_PROC_CallPlayerProfile
 * address:  0x0215C95C
 * packet:   pkt_ov010_0215C95C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: opens the ov071 process on a 0x40-byte work. When the
 * current link record is usable (another player's slot, flagged, and
 * marked at +0x922) the work takes that player's name and profile;
 * otherwise it is filled from the local player. The chosen slot index
 * (0 for the local player) is stored at +0x3C.
 *
 * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local
 * set in both arms, which is what keeps the r6 zero). Three wildcards:
 * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`),
 * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process
 * template) only reach an overlay loader through SCRCMD_PROC_StartOverlayProc, so no
 * class attests them.
 *
 * 2026-10-05 (wave D9): gPlayerProfileProcData now resolves with the ov099 token on its symbols line (`data  ov099  a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches SCRCMD_PROC_StartOverlayProc, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to GAMESYSTEM_CallProc r1); a data token on the id line does not help. Needs the consumer entry (tools), not C.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   INTRUDE_COMM_GetMemberNameNetId  0x02175FB4  thumb  ov011
 *   INTRUDE_COMM_GetMemberEntry  0x0215840C  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   INTRUDE_COMM_BuildLocalProfile  0x02175648  thumb  ov011
 *   SCRCMD_PROC_StartOverlayProc  0x0215C63C  thumb  ov010
 *   sAllocSiteScrcmdProc     0x021728F0  data  a1
 *   gPlayerProfileProcData     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Name20 {
    u16 s[20];
} Name20;

typedef struct Profile16 {
    u32 w[4];
} Profile16;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct LinkState {
    u8 pad00[0x86];
    u16 self : 3;       /* 0x086 */
    u16 rest : 13;
    u8 pad88[0x1AC - 0x88];
    Rec28 recs[1];      /* 0x1AC */
} LinkState;

typedef struct ProfileWork {
    void *sys;          /* 0x00 */
    Name20 name;        /* 0x04 */
    Profile16 profile;  /* 0x2C */
    u8 slot;            /* 0x3C */
    u8 remote;          /* 0x3D */
    u8 pad3E[2];
} ProfileWork;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
struct Big;
struct BigObj;
struct Ctx;
struct Out;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern u8 GAME_DATA_GetIntrudeIdByte(void *p);
extern int INTRUDE_COMM_GetMemberNameNetId(u8 *p);
extern Name20 *INTRUDE_COMM_GetMemberEntry(LinkState *s, int idx);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void INTRUDE_COMM_BuildLocalProfile(void *sv, struct Out *o);
extern void SCRCMD_PROC_StartOverlayProc(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char sAllocSiteScrcmdProc[];
extern const u8 gPlayerProfileProcData[];
extern u8 ov071_id[];

int SCRCMD_PROC_CallPlayerProfile(void *c, void *vm)
{
    void *sys;
    void *p;
    void *q;
    ProfileWork *w;
    LinkState *st;
    u8 idx;

    sys = SCRCMD_WORK_GetGameSystem(vm);
    p = (void *)GAMESYSTEM_GetGameComm(sys);
    q = GAMESYSTEM_GetGameData(sys);
    SCRCMD_WORK_GetScriptWork(vm);
    st = (LinkState *)INTRUDE_COMM_GetWorkIfRunning((int)p);
    w = func_02030734(4, sizeof(ProfileWork), 1, sAllocSiteScrcmdProc, 0x1BC);
    if (st != 0 && st->self != GAME_DATA_GetExitMode(q)
        && INTRUDE_COMM_GetMemberNameNetId((u8 *)(&st->recs[GAME_DATA_GetIntrudeIdByte(q)])) == 1
        && ((u8 *)st)[0x922] == 1) {
        idx = GAME_DATA_GetIntrudeIdByte(q);
        w->name = *INTRUDE_COMM_GetMemberEntry(st, idx);
        w->profile = *(Profile16 *)((u8 *)st + 0x914);
        w->remote = 1;
    } else {
        func_0200BE48(GAME_DATA_GetSaveControl(q));
        INTRUDE_COMM_BuildLocalProfile(q, (struct Out *)(&w->profile));
        idx = 0;
        w->remote = 0;
    }
    w->sys = sys;
    w->slot = idx;
    SCRCMD_PROC_StartOverlayProc(c, vm, (u32)ov071_id, gPlayerProfileProcData, w, 0, 0);
    return 1;
}
