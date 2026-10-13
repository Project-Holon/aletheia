/*
 * function: EVENT_BATTLE_ProcScriptedBattle
 * address:  0x0216E68C
 * packet:   pkt_ov010_0216E68C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state proc that pushes the tutorial capture task (EVENT_BATTLE_ProcBattleTask)
 * for the opponent's first Pokemon and then the result screens.
 * Byte-correct first draft (func_021CF5D8's species is a u32 here: no
 * truncation at the call).
 * Blocker (MATCH): two arm9 Thumb callees have no func_ label and no
 * matched file: 0x0201313C (`return bs->party[side]`, 8 bytes) and
 * 0x0202E818 (16 bytes). Seeds for the arm9 lane.
 *
 * 2026-10-05: byte-identical; the two wildcards resolve once shards exist for arm9 BTL_SETUP_GetParty (matched file exists, no shard) and COMM_PLAYER_SUPPORT_HasSavedMode (new matched/arm9 file, EXACT, this lane).
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_BATTLE_InitTaskWork  0x0216F02C  thumb  ov010
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_021CF5D8  0x021CF5D8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   COMM_PLAYER_SUPPORT_Init  0x0202E79C  thumb
 *   GAME_DATA_GetFieldMode  0x02012A44  thumb
 *   EVENT_BATTLE_IsResultSilent  0x0216EFA8  thumb  ov010
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   COMM_PLAYER_SUPPORT_HasSavedMode  0x0202E818  thumb
 *   EVENT_COMM_COMMON_CreateSupportMsgEvent  0x02181D8C  thumb
 *   EVENT_BATTLE_ProcBattleTask  0x0216EB98  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Battle {
    u32 f00;
    u32 f04;            /* 0x04 */
} Battle;

typedef struct Holder {
    u8 pad00[0x18];
    u8 f18[4];          /* 0x18 */
} Holder;

typedef struct Task {
    u8 pad00[8];
    Holder *f08;        /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 f24;            /* 0x24 */
} Task;

typedef struct Work {
    void *sys;          /* 0x00 */
    Battle *bs;         /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
} Work;

typedef u32 (*TaskFn)(void *task, u32 *state, Task *work);

struct BigObj;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void EVENT_BATTLE_InitTaskWork(void **p, void *a, void *b);
extern void *BTL_SETUP_GetParty(void *p, int i);
extern void *POKEPARTY_GetMember(void *party, u32 i);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void func_021CF5D8(u32 species, u32 a, u32 b, void *c, u32 *d, void *e);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int GAME_DATA_GetPmsWork(int p0);
extern void COMM_PLAYER_SUPPORT_Init(u8 *p);
extern u32 GAME_DATA_GetFieldMode(const struct BigObj *p);
extern int EVENT_BATTLE_IsResultSilent(int a, int b);
extern void *SCRCMD_NETWORK_CreateCommProcEvent(void *sys);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern int COMM_PLAYER_SUPPORT_HasSavedMode(int *p);
extern void *EVENT_COMM_COMMON_CreateSupportMsgEvent(void *sys, u32 v);
extern int EVENT_BATTLE_ProcBattleTask(void *evt, u32 *state, struct Work *w);

int EVENT_BATTLE_ProcScriptedBattle(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *ctx = GAMESYSTEM_GetGameData(sys);
    void *task;
    Task *t;
    u32 species;
    u32 flag;

    switch (*state) {
    case 0:
        task = func_020122C0(sys, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
        t = func_020124E8(task);
        EVENT_BATTLE_InitTaskWork((void **)t, sys, w->bs);
        flag = 1;
        t->f14 = 1;
        species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(BTL_SETUP_GetParty(w->bs, 1), 0), 5, 0);
        {
            void *proc = GAMESYSTEM_GetFieldMap(sys);

            if (w->bs->f04 != 1)
                flag = 0;
            func_021CF5D8(species, w->f0c, flag, proc, &t->f24, t->f08->f18);
        }
        GAME_EVENT_CallEvent(evt, task);
        (*state)++;
        break;
    case 1:
        if (w->f08 == 1) {
            COMM_PLAYER_SUPPORT_Init((void *)GAME_DATA_GetPmsWork((int)ctx));
            return 1;
        }
        if (EVENT_BATTLE_IsResultSilent(GAME_DATA_GetFieldMode(ctx), 0) == 1) {
            COMM_PLAYER_SUPPORT_Init((void *)GAME_DATA_GetPmsWork((int)ctx));
            GAME_EVENT_ChangeEvent(evt, SCRCMD_NETWORK_CreateCommProcEvent(sys));
        } else {
            GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeIn(sys, GAMESYSTEM_GetFieldMap(sys), 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 2:
        if (COMM_PLAYER_SUPPORT_HasSavedMode((void *)GAME_DATA_GetPmsWork((int)ctx)) == 1)
            GAME_EVENT_CallEvent(evt, EVENT_COMM_COMMON_CreateSupportMsgEvent(sys, 4));
        (*state)++;
        break;
    case 3:
        COMM_PLAYER_SUPPORT_Init((void *)GAME_DATA_GetPmsWork((int)ctx));
        return 1;
    }
    return 0;
}
