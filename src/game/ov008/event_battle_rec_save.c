/*
 * file:     event_battle_rec_save.c
 * unit:     yes
 * function: EVENT_BATTLE_REC_SAVE_ProcInit, EVENT_BATTLE_REC_SAVE_ProcExit, EVENT_BATTLE_REC_SAVE_ProcMain, EVENT_BATTLE_REC_SAVE_Start, EVENT_BATTLE_REC_SAVE_CreateEvent, EVENT_BATTLE_REC_SAVE_EventMain
 * address:  0x02154CA0
 * region:   ov008
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * checks: 1 ARM9 unit020120F0 own pointer returns/const args and 020120B4 four-arg forwarder reread; 2 ov001/ov004 sibling interfaces and ov008 neighbours unchanged, no new twin; 3 full-word enum state and Bool return retain11, top-level const pointers retain11; 4 register-tie/front-end and typed-pointer idioms read; 5 fresh idiom directory/neighbours, no stack-object residue. Prior permuter300 consumed, not repeated.
 * wave75: 4 runs; swapped-signature inline wrapper, st=st, unsigned state, proper pointer-return prototypes and const table all retain DIFF11/96B. Both scheduling levers consumed.
 * wave76: 4 runs; parameter reuse worsens74, enum state11, Bool result11; stopped after three nonshrinking iterations; const-pointer check11. Retained previous best C.
 * near miss: DIFF 11 bytes: only the r5/r6 swap (original r6=state ptr, r5=object; ours r5=state, r6=object); switch/if forms, statement order, struct forms tried.
 * lane R1 (2026-09-28), 20 more runs, all still the same 11-byte swap: local copies of either or both
 *   params in every declaration order (coalesced away), `u32 m = *mode` read before args[0], u32/void*
 *   types as in the matched ov001/ov004 siblings, Args/Req struct form, `register` on either param,
 *   K&R parameter declarations in swapped order, `*q = ...` for args[4], `default:` first, inverted
 *   case-1 test; permuter --budget 300 found nothing below 11. A `ret` variable or hoisting q above the
 *   switch makes it worse (80 / 25 bytes). The allocator seems to order the two params by parameter
 *   position regardless of source; untried: a wrapper/inline caller shape.
 * recoup 2026-10-05 (wave P19, lane P19L1): real extent 0x021550DC..0x02155138 (92 B + pool); still DIFF 11 B,
 *   only the r5/r6 swap (original st=r6, o=r5; build st=r5, o=r6). Callee types re-checked against matched
 *   definitions (F4 returns void *, F0 returns u32, B4 void; all already as declared). Tried, no change:
 *   all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments,
 *   scheduling, peephole): 11 B each; *st += 1 and *st = *st + 1: 11; first param as void *: 11; st as
 *   one-field struct pointer: 11; o as 16-word struct with o = ob->w: 11; local s = *st: 11; q declared
 *   before h: 11; dead first parameter reused as h: 11. Worse: returns in each arm 37; if/if chain 62;
 *   case 1 before case 0 78; Ctx struct fields with &o->out 74; h read in each arm 14.
 *   Twin search: grep GAMESYSTEM_GetGameData/GAMESYSTEM_CallProc/GAMESYSTEM_GetProcStatus in src/matched/ov (ov010 0215A370, ov000
 *   021542C0 use the same callees; 0215A370 reads s = *st then p0 = c->f0, no shape that changes this).
 *   Idioms read in full: two-long-lived-values-in-each-others-registers (no missing arg, no join local),
 *   a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off (pragma: no effect here),
 *   a-base-pointer-and-its-mask-scratch-swap-as-an-allocator-tie, a-dead-parameter-reused-as-the-index-
 *   rotates-the-loop-registers (u reused: 11), a-compound-assignment-on-a-field-flips-the-guards-register-pair (+=: 11).
 *   Human-source note: st is longer lived than o (reloaded after the call) yet the original gives o the lower
 *   register; no source form tried reverses the colouring order. Unresolved.
 * final push 2026-10-05 G3L10 (34 compiles, 3 rounds; still DIFF 11/96, only the r5/r6 swap):
 *   Mechanism found: mwcc pushes nodes by ascending vreg once degree < K; in ours st has one more
 *   st-only temp neighbour than o (loaded o[3] value, -1 constant, the reload) so o is pushed first and
 *   gets the higher register. Extending o's live range past the 020120B4 call (probe: `o[1] = 0;` after
 *   `(*st)++`, not a valid form) flips the colouring to the original (o=r5, st=r6), so the original has o
 *   live later or one fewer st-only temp. Per-arm loads of o[0] (no hoisted h; inline Setup(o) or o[0]
 *   read in each arm) also give the original colours but move the ldr r7 below the dispatch (14 B).
 *   Tried, all 11 B: const-free forms with st[0]/*st, u32 st, void **o, struct o (typed fields), copies of
 *   o and st declared inside case 0 in all orders, local obj for o[2], q declared in-block, callee types
 *   from the matched twin ov010 0216C978 (const struct Ctx *, struct IcaAnime *, u32 id, ~0), static inline
 *   Setup(o, h) and Step(st), o[0] re-read in F4/F0 calls. Worse: q[5]=o[3] moved earlier 28-36 B,
 *   o[0] re-read at the B4 call 73 B, one-struct &o->out form 74 B, per-arm h without hoist 14 B.
 *   Matched-asm search for the exact prologue/arg sequence (adds r4,rN,#0; adds r0,r7,#0; adds r4,#imm):
 *   only ov010 0216C978 (matched, st=r5 o=r6 natural, smaller body). Same prologue (r6=r1, r5=r2) in
 *   matched ov010 021619B8, ov071 021B730C: o there is used in case 1 or has far more uses. Unresolved.
 * pass 2 2026-10-06 P2L23: EXACT in --lang c99 and --lang c. The fix is the source order of the two
 *   copied fields: q[1] = o[1] before q[2] = o[2] (field order) instead of q[2] first. The final schedule
 *   is the same (ldr o[2] still first), but the IR order changes the colouring so st takes r6 and o r5.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   PROCSYS_Delete  0x0203133C  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   BATTLE_REC_FreeWork  0x0200B424  thumb
 *   BATTLE_REC_AllocWork  0x0200B400  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   BATTLE_REC_LoadToolOverlay  0x0200BA58  thumb
 *   BATTLE_REC_UnloadToolOverlay  0x0200BA68  thumb
 *   BATTLE_REC_IsVersionSupported  0x0200BA38  thumb
 *   BATTLE_REC_TOOL_PackSetup  0x021EEE78  thumb  ov188
 *   ov093_id       0x0000005D  data   a1
 *   ov097_id       0x00000061  data   a1
 *   ov213_id       0x000000D5  data   a1
 *   ov214_id       0x000000D6  data   a1
 *   d_021BB0B0     0x021BB0B0  data   ov213  a4
 *   d_021F75EC     0x021F75EC  data   ov097  a4
 *   d_021F03C4     0x021F03C4  data   ov093  a4
 *   d_021EFDAC     0x021EFDAC  data   ov093  a4
 *   d_021BB474     0x021BB474  data   ov214  a4
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   d_0215513C     0x0215513C  data  ov008  a4
 */
struct Proc;
struct Proc;
struct S020314B8;
struct Entry;
struct Desc;
struct Obj;
struct GameSystem;
struct ProcHandle;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    int trainerId;
    char pad4[0xA - 4];
    u8 name[6];
} BattlePlayerSlot;

typedef struct {
    BattlePlayerSlot slot[4];
    int formatId;
    int modeId;
} BattleSlotTable;

typedef struct {
    char pad0[0x21];
    u8 playerIndex;
    u8 isMulti;
    char pad23[0x8C - 0x23];
    int battleType;
    char pad90[0x91 - 0x90];
    u8 recordVersion;
    char pad92[0x94 - 0x92];
    int hasRecord;
    char pad98[0xC8 - 0x98];
    u8 names[4][6];
} BattleInfo;

typedef struct {
    int gameSystem;
    BattleInfo *info;
    BattleSlotTable *slots;
    int flag;
    int extraFlag;
    int pad14;
    int resultGameSystem;
    int recordSupported;
    int isCommBattle;
    int saveEnabled;
    int resultFlag;
    int resultExtraFlag;
} BattleRecordWork;

typedef struct {
    int procsys;
    int playerIdFirst;
    int playerIdSecond;
    int swapped;
    int overlayLoaded;
    int cmdTableAdded;
    int recordWorkAllocated;
} BattleRecordCtx;

/* The procsys proc work made by EVENT_BATTLE_REC_SAVE_ProcInit (0x1c bytes). */
typedef struct EventBattleRecSaveProc {
    int procsys;        /* 0x00: handle from PROCSYS_Create(0x76) */
    char pad4[0x18];
} EventBattleRecSaveProc;

/* The task work seen by EVENT_BATTLE_REC_SAVE_ProcExit. */
typedef struct EventBattleRecSaveTask {
    char pad0[0x14];
    int commBattleActive;   /* 0x14: nonzero once the comm battle has started */
} EventBattleRecSaveTask;

typedef signed int     s32;

extern void  GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int b, unsigned int c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void *PROCSYS_Create(int heapId);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern void PROCSYS_Delete(struct S020314B8 *p);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern unsigned int PROCSYS_Main(void *p);
extern void PROCSYS_Push(int h, u32 id, void *a, void *b);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void GF_OVERLAY_Unload(s32 handle);
extern int GF_OVERLAY_Load(s32 handle);
extern void BATTLE_REC_FreeWork(void);
extern void BATTLE_REC_AllocWork(u32 heap);
struct GFLNetHandle;
extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_StartTimingSync(struct GFLNetHandle *handle, unsigned short tag);
extern unsigned int GFL_NET_CheckTimingSync(struct GFLNetHandle *handle, unsigned int timingNo);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);
struct BattleSetupParam;
extern void BATTLE_REC_TOOL_PackSetup(struct BattleSetupParam *setup);
extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
struct GameEvent;
extern void *GAME_EVENT_GetWork(struct GameEvent *event);
struct GameData;
struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
int EVENT_BATTLE_REC_SAVE_ProcInit(void *procsysOwner);
int EVENT_BATTLE_REC_SAVE_ProcExit(void *procWork, int unused, char *taskWork, int *procsys);
u32 EVENT_BATTLE_REC_SAVE_ProcMain(void *event, int *stage, BattleRecordWork *work, BattleRecordCtx *ctx);
void *EVENT_BATTLE_REC_SAVE_Start(void *gameSystem, const int *args);
void *EVENT_BATTLE_REC_SAVE_CreateEvent(void *gameSystem, int info, int slots, int flag);
int EVENT_BATTLE_REC_SAVE_EventMain(int unused, int *stage, int *work);
extern char ov093_id[];
extern char ov097_id[];
extern char ov213_id[];
extern char ov214_id[];
extern char d_021BB0B0[];
extern char d_021F75EC[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_021BB474[];
extern char d_0215513C[];



int EVENT_BATTLE_REC_SAVE_ProcInit(void *procsysOwner)
{
    EventBattleRecSaveProc *procWork;

    GFL_HEAP_CreateChildHeap(1, 0x76, 0x4000);
    procWork = PROCSYS_AllocProcWork(procsysOwner, 0x1c, 0x76);
    procWork->procsys = (unsigned int)PROCSYS_Create(0x76);
    return 1;
}



int EVENT_BATTLE_REC_SAVE_ProcExit(void *procWork, int unused, char *taskWork, int *procsys)
{
    if (((EventBattleRecSaveTask *)taskWork)->commBattleActive == 1) {
        if (GFL_NET_ERR_GetErrorLevel() != 0)
            GFL_NET_ERR_RequestScreen();
    }
    PROCSYS_Delete((struct S020314B8 *)*procsys);
    PROCSYS_FreeProcWork(procWork);
    GFL_HEAP_DeleteChecked(0x76);
    return 1;
}



/*
 * 2026-10-05 wave P16 lane E10: stage 15 truth value is built after the call
 * (versionOk = f(recordVersion); nameRow = 1; if (versionOk == 0) nameRow = 0; zero arm for hasRecord == 0 shares the
 * same zero). Closes the 121-byte DIFF; the mid-function pool island follows.
 * BA38 returns u32.
 *
 * 18-stage task on *stage.  PROCSYS_Push's second/third arguments are an
 * overlay id and an address in that overlay (0xD5/ov213, 0x61/ov097,
 * 0xD6/ov214; the -1 one points into ov093, which stage 6 loads by id 0x5D
 * and stage 12 unloads).
 */
u32 EVENT_BATTLE_REC_SAVE_ProcMain(void *event, int *stage, BattleRecordWork *work, BattleRecordCtx *ctx)
{
    int procsysBusy = PROCSYS_Main((void *)ctx->procsys);
    int lastPlayer, firstTeamBase, secondTeamBase, i, j, playerIndexBit, nameRow;
    u32 versionOk;

    if (procsysBusy != 1 && GFL_NET_ERR_GetErrorLevel() != 0 && *stage >= 0 && *stage < 13) {
        if (ctx->cmdTableAdded == 1)
            GFL_NET_COMMAND_DeleteCommandTable(0x100);
        if (ctx->overlayLoaded == 1)
            GF_OVERLAY_Unload((u32)ov093_id);
        if (ctx->recordWorkAllocated == 1)
            BATTLE_REC_FreeWork();
        return 1;
    }

    switch (*stage) {
    case 0:
        if (work->info->isMulti == 0)
            work->slots->modeId = 1;
        else
            work->slots->modeId = 3;
        PROCSYS_Push(ctx->procsys, (u32)ov213_id, d_021BB0B0, work->slots);
        *stage = 1;
        break;
    case 1:
        if (procsysBusy == 1)
            break;
        if (work->info->isMulti == 0)
            *stage = 6;
        else
            *stage = 2;
        break;
    case 2:
        GFL_NET_StartTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), 0xC9);
        *stage = 3;
        break;
    case 3:
        if (GFL_NET_CheckTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), 0xC9) == 0)
            break;
        *stage = 4;
        break;
    case 4:
        if (work->info->playerIndex <= 1) {
            ctx->swapped = 0;
            ctx->playerIdFirst = work->slots->slot[0].trainerId;
            ctx->playerIdSecond = work->slots->slot[1].trainerId;
        } else {
            ctx->swapped = 1;
            ctx->playerIdFirst = work->slots->slot[1].trainerId;
            ctx->playerIdSecond = work->slots->slot[0].trainerId;
        }
        PROCSYS_Push(ctx->procsys, (u32)ov097_id, d_021F75EC, &ctx->playerIdFirst);
        *stage = 5;
        break;
    case 5:
        if (procsysBusy == 1)
            break;
        *stage = 6;
        break;
    case 6:
        ctx->overlayLoaded = 1;
        GF_OVERLAY_Load((u32)ov093_id);
        ctx->cmdTableAdded = 1;
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_StartTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), 0xC8);
        *stage = 7;
        break;
    case 7:
        if (GFL_NET_CheckTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), 0xC8) == 0)
            break;
        *stage = 8;
        break;
    case 8:
        ctx->recordWorkAllocated = 1;
        BATTLE_REC_AllocWork(0x76);
        PROCSYS_Push(ctx->procsys, -1, d_021EFDAC, work->info);
        *stage = 9;
        break;
    case 9:
        if (procsysBusy == 1)
            break;
        *stage = 10;
        break;
    case 10:
        *stage = 11;
        break;
    case 11:
        GFL_NET_StartTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), 0xCA);
        *stage = 12;
        break;
    case 12:
        if (GFL_NET_CheckTimingSync(GFL_NET_HANDLE_GetCurrentHandle(), 0xCA) == 0)
            break;
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        ctx->cmdTableAdded = 0;
        GF_OVERLAY_Unload((u32)ov093_id);
        ctx->overlayLoaded = 0;
        BATTLE_REC_LoadToolOverlay();
        BATTLE_REC_TOOL_PackSetup((struct BattleSetupParam *)work->info);
        BATTLE_REC_UnloadToolOverlay();
        *stage = 13;
        break;
    case 13:
        if (work->info->isMulti == 0)
            work->slots->modeId = 2;
        else
            work->slots->modeId = 4;
        switch (work->info->battleType) {
        case 1:
        case 4:
            work->slots->formatId = 0;
            break;
        case 0:
        case 3:
            work->slots->formatId = 1;
            break;
        case 2:
            work->slots->formatId = 2;
            break;
        case 6:
            break;
        default:
            work->slots->formatId = 2;
            break;
        }
        if (work->info->isMulti == 0) {
            lastPlayer = 1;
            firstTeamBase = 0;
            secondTeamBase = 1;
        } else {
            lastPlayer = 3;
            firstTeamBase = 0;
            secondTeamBase = 2;
        }
        playerIndexBit = work->info->playerIndex;
        for (i = 0; i <= lastPlayer; i++) {
            if ((i & 1) == (playerIndexBit & 1)) {
                if (playerIndexBit & 1)
                    nameRow = (i & 2) + 1;
                else
                    nameRow = i & 2;
                for (j = 0; j < 6; j++)
                    work->slots->slot[firstTeamBase + (i >> 1)].name[j] = work->info->names[nameRow][j];
            } else {
                if (playerIndexBit & 1)
                    nameRow = i & 2;
                else
                    nameRow = (i & 2) + 1;
                for (j = 0; j < 6; j++)
                    work->slots->slot[secondTeamBase + (i >> 1)].name[j] = work->info->names[nameRow][j];
            }
        }
        if (work->info->battleType == 6) {
            *stage = 16;
            break;
        }
        PROCSYS_Push(ctx->procsys, (u32)ov213_id, d_021BB0B0, work->slots);
        *stage = 14;
        break;
    case 14:
        if (procsysBusy == 1)
            break;
        *stage = 15;
        break;
    case 15:
        if (work->info->hasRecord == 0) nameRow = 0; else { versionOk = BATTLE_REC_IsVersionSupported(work->info->recordVersion); nameRow = 1; if (versionOk == 0) nameRow = 0; }
        work->recordSupported = nameRow;
        work->resultGameSystem = work->gameSystem;
        work->isCommBattle = 1;
        work->saveEnabled = 1;
        work->resultFlag = work->flag;
        work->resultExtraFlag = work->extraFlag;
        PROCSYS_Push(ctx->procsys, (u32)ov214_id, d_021BB474, &work->resultGameSystem);
        *stage = 16;
        break;
    case 16:
        if (procsysBusy == 1)
            break;
        BATTLE_REC_FreeWork();
        ctx->recordWorkAllocated = 0;
        *stage = 17;
        break;
    case 17:
        return 1;
    }
    return 0;
}


void *EVENT_BATTLE_REC_SAVE_Start(void *gameSystem, const int *args)
{
    return EVENT_BATTLE_REC_SAVE_CreateEvent(gameSystem, args[0], args[1], args[2]);
}



void *EVENT_BATTLE_REC_SAVE_CreateEvent(void *gameSystem, int info, int slots, int flag)
{
    void *event = GAME_EVENT_Create(gameSystem, 0, (void *)((int)EVENT_BATTLE_REC_SAVE_EventMain), 0x40);
    u32 *work = GAME_EVENT_GetWork(event);

    work[0] = (u32)gameSystem;
    work[1] = info;
    work[2] = slots;
    work[3] = flag;
    return event;
}


int EVENT_BATTLE_REC_SAVE_EventMain(int unused, int *stage, int *work)
{
    void *gameSystem = (void *)work[0];
    int *procArgs;

    switch (*stage) {
    case 0:
        procArgs = work + 4;
        work[4] = (int)GAMESYSTEM_GetGameData(gameSystem);
        procArgs[1] = work[1];
        procArgs[2] = work[2];
        procArgs[3] = *(int *)(work[2] + 0x48);
        procArgs[4] = *(int *)(work[2] + 0x4c);
        procArgs[5] = work[3];
        GAMESYSTEM_CallProc(gameSystem, -1, d_0215513C, procArgs);
        (*stage)++;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            return 1;
        break;
    }
    return 0;
}
