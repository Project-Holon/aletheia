/*
 * file:     event_battle.c
 * unit:     yes
 * function: EVENT_BATTLE_CallAndInvert, EVENT_BATTLE_ProcScriptedBattle, EVENT_BATTLE_CreateScriptedBattle, EVENT_BATTLE_CreateEncounterTask, EVENT_BATTLE_CreateResultOnlyTask, EVENT_BATTLE_CreateForcedWinTask, EVENT_BATTLE_CreateCatchTutorial, EVENT_BATTLE_CreateEncounterTaskWithMon, EVENT_BATTLE_ProcBattleTask, EVENT_BATTLE_GetBattleKindClass, EVENT_BATTLE_DispatchBattleKindNotify, EVENT_BATTLE_NotifyLeadSpecies, EVENT_BATTLE_NotifyBattleEnd, EVENT_BATTLE_SetResultSound, EVENT_BATTLE_IsResultSilent, EVENT_BATTLE_GetKindFlag, EVENT_BATTLE_IsTaskResultSilent, EVENT_BATTLE_FinishBattleTask, EVENT_BATTLE_InitTaskWork, EVENT_BATTLE_FreeBtlSetup, EVENT_BATTLE_IntegrityProbeA, EVENT_BATTLE_IntegrityProbeB, EVENT_BATTLE_IntegrityProbeC
 * address:  0x0216E680
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_SelectEffectAndBgm  0x021CF5D8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   COMM_PLAYER_SUPPORT_Init  0x0202E79C  thumb
 *   GAME_DATA_GetFieldMode  0x02012A44  thumb
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   COMM_PLAYER_SUPPORT_HasSavedMode  0x0202E818  thumb
 *   EVENT_COMM_COMMON_CreateSupportMsgEvent  0x02181D8C  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupTrainerBattle  0x021AA5CC  thumb  ov021
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
 *   ENCEFF_SelectEffectAndBgmForTrainer  0x021CF748  thumb  ov021
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   POKE_TOOL_SetupPartyParam  0x0201756C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb  ov021
 *   BTL_SETUP_SetupDemo  0x020135C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02172B54     0x02172B54  data
 *   GAME_DATA_GetSaveBlock43  0x02012FD8  thumb
 *   sub_0200E740   0x0200E740  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   sub_0200E788   0x0200E788  thumb
 *   sub_0200E74C   0x0200E74C  thumb
 *   sub_0200E7B4   0x0200E7B4  thumb
 *   sub_0200E7A4   0x0200E7A4  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   sub_0200E76C   0x0200E76C  thumb
 *   sub_0200E780   0x0200E780  thumb
 *   sub_0200E7AC   0x0200E7AC  thumb
 *   POKE_TOOL_ChangeSpecies  0x020178D8  thumb
 *   POKE_TOOL_SetDefaultMoves  0x02017FA8  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   FIELD_STATUS_SwapSeasonDispFlag  0x0201447C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask  0x02029B28  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   COMM_PLAYER_SUPPORT_StashMode  0x0202E80C  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020056A0  0x020056A0  thumb
 *   GAMESYSTEM_ReadTimerTwice  0x02011D34  thumb
 *   FLD_BTL_INST_TOOL_AddBattleTally  0x02168D30  thumb  ov010
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   func_021882DC  0x021882DC  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   ov093_id       0x0000005D  data
 *   ov092_id       0x0000005C  data
 *   ov230_id       0x000000E6  data
 *   d_021EFDAC     0x021EFDAC  data  ov093
 *   d_021B9D94     0x021B9D94  data  ov092
 *   g_0214624C     0x0214624C  data
 *   func_0202A230   0x0202A230  thumb
 *   func_0202A3FC   0x0202A3FC  thumb
 *   d_021725C0     0x021725C0  data
 *   GAME_BEACON_SEARCH_SetBattlePokeStart  0x0216505C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetBattlePokeWin  0x02165078  thumb  ov010
 *   GAME_BEACON_SEARCH_SetPokeEvent  0x021653F4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_BEACON_SEARCH_SetEventBattleNameC  0x021654AC  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameA  0x02165424  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameB  0x02165468  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameD  0x021654F0  thumb  ov010
 *   STRBUF_Delete  0x02045808  arm
 *   d_021725D8  0x021725D8  data  ov010  a1
 *   d_021725B8     0x021725B8  data
 *   GAME_DATA_SetFieldMode 0x02012A4C thumb
 *   MOVE_POKEMON_HandleBattleResult 0x0215E5B0 thumb ov010
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   func_0202C83C 0x0202C83C thumb
 *   func_02082A7C 0x02082A7C arm
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 */

struct BtlSetup;
struct GameSystem;
struct GameEvent;
struct GameEvent;
struct GameEvent;
struct GameEvent;
struct BtlSetup;
struct RecordBlock;
struct PokeParty;
struct PokemonParam;
struct BtlSetup;
struct TallyRecord;
struct Result;
struct FieldStatus;
struct Strbuf;
struct PlayerWork;
struct SaveData;
struct BattleEndCtx;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef int s32;

typedef struct BattleKindHead {
    u32 unused00;
    u32 battleKind;     /* 0x04 */
} BattleKindHead;

typedef struct ScriptedBattleArgs {
    void *gameSystem;           /* 0x00 */
    BattleKindHead *btlSetup;   /* 0x04 */
    u32 returnImmediately;      /* 0x08 */
    u32 effectId;               /* 0x0C */
} ScriptedBattleArgs;

typedef unsigned long long u64;

typedef struct BattleLocation {
    u32 terrain;        /* 0x00 */
    u32 battleBg;       /* 0x04 */
    u8 pad08[8];
} BattleLocation;

typedef struct BtlSetup {
    u32 mode;           /* 0x00 */
    u8 pad04[0x14];
    u16 bgmId;          /* 0x18 */
    u8 pad1A[0x32];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BtlSetup;

typedef struct BattleTask {
    void *gameSystem;       /* 0x00 */
    void *gameData;         /* 0x04 */
    BtlSetup *btlSetup;     /* 0x08 */
    void *procGameData;     /* 0x0C */
    BtlSetup *procBtlSetup; /* 0x10 */
    u32 isScripted;         /* 0x14 */
    u32 skipResultCheck;    /* 0x18 */
    u32 addTallies;         /* 0x1C */
    u32 keepBtlSetup;       /* 0x20 */
    u32 encounterEffect;    /* 0x24 */
} BattleTask;

typedef void (*BattleKindHandler)(u16 id);

typedef struct BattleEndCtx {
    u32 unused00;
    void *btlSetupObj;      /* 0x04 */
    BtlSetup *btlSetup;     /* 0x08 */
} BattleEndCtx;

extern unsigned int POKE_TOOL_GetPartyValue(void *a, unsigned int b, unsigned int c);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *p);
extern struct GameEvent *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct GameEvent *p);
extern void *BTL_SETUP_GetParty(void *p, int i);
extern void *POKEPARTY_GetMember(void *party, u32 i);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *p);
extern void ENCEFF_SelectEffectAndBgm(u32 species, u32 a, u32 b, void *c, u32 *d, void *e);
extern void GAME_EVENT_CallEvent(struct GameEvent *evt, struct GameEvent **out);
extern int GAME_DATA_GetPmsWork(int p0);
extern void COMM_PLAYER_SUPPORT_Init(u8 *p);
extern u32 GAME_DATA_GetFieldMode(const struct BtlSetup *p);
extern void *SCRCMD_NETWORK_CreateCommProcEvent(void *sys);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *o, u32 *out);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern int COMM_PLAYER_SUPPORT_HasSavedMode(int *p);
extern void *EVENT_COMM_COMMON_CreateSupportMsgEvent(void *sys, u32 v);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct RecordBlock *obj, int i);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void EFFECT_ENCOUNT_ConsumeSpot(int s);
extern void *BTL_SETUP_Create(u32 heap);
extern void FIELD_ENCOUNT_SetupTrainerBattle(struct GameSystem *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
extern void BTL_SETUP_SetStatusFlag(char *p, int v);
extern void ENCEFF_SelectEffectAndBgmForTrainer(u32 a, u32 x, int *out, u16 *out2);
extern void *POKEPARTY_Create(u16 heap);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void POKE_TOOL_SetupPartyParam(void *mon, u16 species, u16 level, u64 id);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_Add(struct PokeParty *p, const struct PokemonParam *src);
extern void FIELD_ENCOUNT_SetFieldSituation(struct BtlSetup *out, void *a1, void *a2);
extern void BTL_SETUP_SetupDemo(void *bs, void *ctx, void *p1, void *p2, BattleLocation *loc, u32 heap);
extern u32 func_020307B0(void *p);
extern void *GAME_DATA_GetSaveBlock43(void **p);
extern u32   sub_0200E740(const void *obj, u32 idx);
extern void *GAME_EVENT_GetWork(struct GameEvent *p);
extern u32   sub_0200E788(const void *obj, u32 a, u32 b);
extern u32   sub_0200E74C(const void *obj, u32 idx);
extern u32   sub_0200E7B4(const void *obj, u32 idx);
extern u32   sub_0200E7A4(const void *obj, u32 idx);
extern void  POKE_TOOL_SetupPartyParamEx(void *p, u16 species, u32 level, u64 id, u32 pow, u64 rnd);
extern u32   sub_0200E76C(const void *obj, u32 idx);
extern u8    sub_0200E780(const void *obj, u32 idx);
extern void *sub_0200E7AC(void *obj, u32 idx);
extern void POKE_TOOL_ChangeSpecies(void *p, u32 a);
extern u32   POKE_TOOL_SetDefaultMoves(void *p);
extern void GAME_EVENT_CallProc(struct GameEvent *obj, u32 a1, u32 a2, u32 a3);
extern void *GAME_DATA_GetMoveModelSys(const struct BtlSetup *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern u8 FIELD_STATUS_SwapSeasonDispFlag(struct FieldStatus *o, u8 v);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *sys);
extern void *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(void *a, u16 b);
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *a);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);
extern void COMM_PLAYER_SUPPORT_StashMode(u32 *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void *func_020056A0(void (*callback)(void *, void *), void *work, u32 key);
extern void GAMESYSTEM_ReadTimerTwice(void);
extern void FLD_BTL_INST_TOOL_AddBattleTally(struct TallyRecord *r, struct Result *s);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 func_021882DC(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188390(void (*a)(void), void (*b)(void), u32 c);
extern void ENCEFF_Start(struct GameSystem *c, u32 x, int idx);
extern u32 func_0202A230(void *a, u32 idx);
extern u8 func_0202A3FC(u32 key);
extern int GAME_BEACON_SEARCH_SetBattlePokeStart(int a0);
extern int GAME_BEACON_SEARCH_SetBattlePokeWin(int a0);
extern void GAME_BEACON_SEARCH_SetPokeEvent(u16 species);
extern void *GAME_DATA_GetMyParty(const struct BtlSetup *p);
extern u32 POKEPARTY_FindFirstNonEgg(void *p);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void GAME_BEACON_SEARCH_SetEventBattleNameC(void *name);
extern void GAME_BEACON_SEARCH_SetEventBattleNameA(void *name);
extern void GAME_BEACON_SEARCH_SetEventBattleNameB(void *name);
extern void GAME_BEACON_SEARCH_SetEventBattleNameD(void *name);
extern void STRBUF_Delete(struct Strbuf *vec);
extern void GAME_DATA_SetFieldMode(struct BtlSetup *p, u32 v);
extern void MOVE_POKEMON_HandleBattleResult(void *a0, struct BtlSetup *w);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveData *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *p);
extern int func_0202C83C(int,int);
extern void func_02082A7C(int,void *,int);
extern int BTL_SETUP_Delete(int a0);
extern u32 func_0203F0A8(void);
int EVENT_BATTLE_CallAndInvert(void (*fn)(void));
int EVENT_BATTLE_ProcScriptedBattle(void *evt, u32 *state, ScriptedBattleArgs *args);
int EVENT_BATTLE_CreateScriptedBattle(int gameSystem, int battleSrc, int btlSetup, int returnImmediately, int effectId);
int EVENT_BATTLE_CreateEncounterTask(int gameSystem, int battleSrc, int battleMode, int battleFlags, int battleKind, int fieldEffect, int options);
int EVENT_BATTLE_CreateResultOnlyTask(int gameSystem, int battleSrc, int btlSetup);
int EVENT_BATTLE_CreateForcedWinTask(void *gameSystem, void *battleSrc, void *btlSetup);
void *EVENT_BATTLE_CreateCatchTutorial(void *gameSystem, u32 fieldMap, u32 heapId);
void *EVENT_BATTLE_CreateEncounterTaskWithMon(void *gameSystem, u32 battleSrc, u32 battleMode, u32 battleFlags, u32 battleKind, u32 fieldEffect, u32 options, u32 entryIndex);
int EVENT_BATTLE_ProcBattleTask(void *evt, u32 *state, BattleTask *work);
int EVENT_BATTLE_GetBattleKindClass(void *battleKind);
void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col);
void EVENT_BATTLE_NotifyLeadSpecies(void *btlSetup, int which);
void EVENT_BATTLE_NotifyBattleEnd(BattleEndCtx *ctx);
int EVENT_BATTLE_SetResultSound(BattleTask *task);
int EVENT_BATTLE_IsResultSilent(int outcome, int mode);
u8 EVENT_BATTLE_GetKindFlag(int kindId);
int EVENT_BATTLE_IsTaskResultSilent(BattleTask *task);
void EVENT_BATTLE_FinishBattleTask(BattleTask *task, void *gameSystem);
void EVENT_BATTLE_InitTaskWork(BattleTask *task, void *gameSystem, void *btlSetup);
int EVENT_BATTLE_FreeBtlSetup(BattleTask *task);
int EVENT_BATTLE_IntegrityProbeA(int unused);
int EVENT_BATTLE_IntegrityProbeB(int unused);
int EVENT_BATTLE_IntegrityProbeC(int unused);
extern const char d_02172B54[];
extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;
extern const BattleKindHandler d_021725C0[][2];
extern u8 d_021725D8[][5];
extern u8 d_021725B8[];


int EVENT_BATTLE_CallAndInvert(void (*fn)(void))
{
    if (fn != 0)
        fn();
    return ~(u32)fn;
}




/*
 * Four-state proc that pushes the tutorial capture battleTask (EVENT_BATTLE_ProcBattleTask)
 * for the opponent's first Pokemon and then the result screens.
 * Byte-correct first draft (ENCEFF_SelectEffectAndBgm's species is a u32 here: no
 * truncation at the call).
 * Blocker (MATCH): two arm9 Thumb callees have no func_ label and no
 * matched file: 0x0201313C (`return btlSetup->party[side]`, 8 bytes) and
 * 0x0202E818 (16 bytes). Seeds for the arm9 lane.
 *
 * 2026-10-05: byte-identical; the two wildcards resolve once shards exist for arm9 BTL_SETUP_GetParty (matched file exists, no shard) and COMM_PLAYER_SUPPORT_HasSavedMode (new matched/arm9 file, EXACT, this lane).
 */
int EVENT_BATTLE_ProcScriptedBattle(void *event, u32 *state, ScriptedBattleArgs *args)
{
    void *gameSystem = args->gameSystem;
    void *gameData = GAMESYSTEM_GetGameData(gameSystem);
    void *taskEvent;
    BattleTask *work;
    u32 species;
    u32 hasWildOpponent;

    switch (*state) {
    case 0:
        taskEvent = func_020122C0(gameSystem, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
        work = func_020124E8(taskEvent);
        EVENT_BATTLE_InitTaskWork(work, gameSystem, args->btlSetup);
        hasWildOpponent = 1;
        work->isScripted = 1;
        species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(BTL_SETUP_GetParty(args->btlSetup, 1), 0), 5, 0);
        {
            void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

            if (args->btlSetup->battleKind != 1)
                hasWildOpponent = 0;
            ENCEFF_SelectEffectAndBgm(species, args->effectId, hasWildOpponent, fieldMap, &work->encounterEffect, &work->btlSetup->bgmId);
        }
        GAME_EVENT_CallEvent(event, taskEvent);
        (*state)++;
        break;
    case 1:
        if (args->returnImmediately == 1) {
            COMM_PLAYER_SUPPORT_Init((void *)GAME_DATA_GetPmsWork((int)gameData));
            return 1;
        }
        if (EVENT_BATTLE_IsResultSilent(GAME_DATA_GetFieldMode(gameData), 0) == 1) {
            COMM_PLAYER_SUPPORT_Init((void *)GAME_DATA_GetPmsWork((int)gameData));
            GAME_EVENT_ChangeEvent(event, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
        } else {
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 2:
        if (COMM_PLAYER_SUPPORT_HasSavedMode((void *)GAME_DATA_GetPmsWork((int)gameData)) == 1)
            GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateSupportMsgEvent(gameSystem, 4));
        (*state)++;
        break;
    case 3:
        COMM_PLAYER_SUPPORT_Init((void *)GAME_DATA_GetPmsWork((int)gameData));
        return 1;
    }
    return 0;
}




/*
 * Allocates a 0x10-byte battleTask record (handler EVENT_BATTLE_ProcScriptedBattle) and fills it
 * from the arguments.
 */
int EVENT_BATTLE_CreateScriptedBattle(int gameSystem, int battleSrc, int btlSetup, int returnImmediately, int effectId)
{
    struct GameEvent *taskEvent;
    ScriptedBattleArgs *args;

    taskEvent = func_020122C0((void *)gameSystem, 0, EVENT_BATTLE_ProcScriptedBattle, 0x10);
    args = func_020124E8(taskEvent);
    args->gameSystem = (void *)gameSystem;
    args->btlSetup = (BattleKindHead *)btlSetup;
    args->returnImmediately = returnImmediately;
    args->effectId = effectId;
    EVENT_BATTLE_NotifyLeadSpecies((void *)btlSetup, 0);
    func_02008DF0(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem)), 5);
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)battleSrc));
    return (int)taskEvent;
}




int EVENT_BATTLE_CreateEncounterTask(int gameSystem, int battleSrc, int battleMode, int battleFlags, int battleKind, int fieldEffect, int options)
{
    struct GameEvent *taskEvent;
    BattleTask *task;
    int battleObj;
    int records;
    int btlSetup;

    taskEvent = func_020122C0((void *)gameSystem, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
    task = func_020124E8(taskEvent);
    battleObj = FIELDMAP_GetEncount((u8 *)battleSrc);
    records = (int)GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem));
    btlSetup = (int)BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupTrainerBattle((struct GameSystem *)battleObj, (void *)btlSetup, battleMode, battleFlags, (void *)battleKind, fieldEffect, 4);
    EVENT_BATTLE_DispatchBattleKindNotify(battleKind, 0);
    func_02008DF0((struct RecordBlock *)records, 6);
    func_02008DF0((struct RecordBlock *)records, 0x56);
    EVENT_BATTLE_InitTaskWork(task, (void *)gameSystem, (void *)btlSetup);
    task->isScripted = 1;
    if (options & 1) {
        BTL_SETUP_SetStatusFlag((char *)btlSetup, 0x100);
        task->skipResultCheck = 1;
    }
    ENCEFF_SelectEffectAndBgmForTrainer(battleKind, battleSrc, (int *)&task->encounterEffect, &task->btlSetup->bgmId);
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)battleSrc));
    return (int)taskEvent;
}




int EVENT_BATTLE_CreateResultOnlyTask(int gameSystem, int battleSrc, int btlSetup)
{
    struct GameEvent *taskEvent;
    BattleTask *task;

    taskEvent = func_020122C0((void *)gameSystem, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
    task = func_020124E8(taskEvent);
    EVENT_BATTLE_InitTaskWork(task, (void *)gameSystem, (void *)btlSetup);
    task->isScripted = 0;
    task->skipResultCheck = 1;
    task->keepBtlSetup = 1;
    task->encounterEffect = 9;
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)battleSrc));
    return (int)taskEvent;
}




int EVENT_BATTLE_CreateForcedWinTask(void *gameSystem, void *battleSrc, void *btlSetup)
{
    struct GameEvent *taskEvent;
    BattleTask *task;

    taskEvent = func_020122C0(gameSystem, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
    task = func_020124E8(taskEvent);
    EVENT_BATTLE_InitTaskWork(task, gameSystem, btlSetup);
    task->isScripted = 0;
    task->addTallies = 1;
    task->skipResultCheck = 1;
    task->encounterEffect = 9;
    task->btlSetup->bgmId = 0x46b;
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)battleSrc));
    return (int)taskEvent;
}




/*
 * Set up the scripted catching-tutorial battle (Minccino Lv7 against
 * Patrat Lv2) and push EVENT_BATTLE_ProcBattleTask as its battleTask. First draft.
 */
void *EVENT_BATTLE_CreateCatchTutorial(void *gameSystem, u32 fieldMap, u32 heapId)
{
    BattleLocation location;
    u16 tempHeapId;
    void *gameData;
    void *btlSetup;
    void *playerParty;
    void *opponentParty;
    void *pokemon;
    void *battleTask;
    BattleTask *work;

    tempHeapId = (heapId & 0x7FFF) | 0x8000;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    btlSetup = BTL_SETUP_Create(heapId);
    playerParty = POKEPARTY_Create(tempHeapId);
    opponentParty = POKEPARTY_Create(tempHeapId);
    pokemon = func_02030734(tempHeapId, POKE_TOOL_GetPartyParamSize(), 1, d_02172B54, 0x1DA);
    POKE_TOOL_SetupPartyParam(pokemon, 572, 7, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x36, 1);
    POKE_TOOL_SetPartyValue(pokemon, 0x37, 45);
    POKE_TOOL_SetPartyValue(pokemon, 0x38, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x39, 0);
    POKEPARTY_Add(playerParty, pokemon);
    POKE_TOOL_SetupPartyParam(pokemon, 504, 2, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x36, 33);
    POKE_TOOL_SetPartyValue(pokemon, 0x37, 43);
    POKE_TOOL_SetPartyValue(pokemon, 0x38, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x39, 0);
    POKEPARTY_Add(opponentParty, pokemon);
    FIELD_ENCOUNT_SetFieldSituation((struct BtlSetup *)(&location), gameData, (void *)fieldMap);
    location.battleBg = 5;
    location.terrain = 0;
    BTL_SETUP_SetupDemo(btlSetup, gameData, playerParty, opponentParty, &location, heapId);
    func_020307B0(pokemon);
    func_020307B0(opponentParty);
    func_020307B0(playerParty);
    battleTask = func_020122C0(gameSystem, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
    work = func_020124E8(battleTask);
    EVENT_BATTLE_InitTaskWork(work, gameSystem, btlSetup);
    work->isScripted = 1;
    ENCEFF_SelectEffectAndBgm(504, 5, 0, (void *)fieldMap, &work->encounterEffect, &work->btlSetup->bgmId);
    work->encounterEffect = 0;
    return battleTask;
}




/*
 * Every concrete byte matches; the one wildcard is the bl to 0x02012FD8, an
 * unlabelled 12-byte arm9 Thumb leaf (ldr r0,[r0]; tail call
 * func_020071CC(r0, 0x43)) with no label, no shard and so no witness.
 * as `void *GAME_DATA_GetSaveBlock43(void **p) { return func_020071CC(*p, 0x43); }`
 * (symbols: func_020071CC 0x020071CC thumb), which is outside an overlay
 * lane's write set; once it has a shard this file should verify EXACT.
 *
 * The level argument to POKE_TOOL_SetupPartyParamEx is passed untruncated here, so its
 * extern takes u32 level rather than the u16 other callers declare.
 */
void *EVENT_BATTLE_CreateEncounterTaskWithMon(void *gameSystem, u32 battleSrc, u32 battleMode, u32 battleFlags, u32 battleKind, u32 fieldEffect, u32 options, u32 entryIndex)
{
    void *giftData;
    void *task;
    void *mon;
    u32 oldSpecies;
    u32 species;
    u32 level;
    u32 id;
    u32 rnd;

    giftData = GAME_DATA_GetSaveBlock43(GAMESYSTEM_GetGameData(gameSystem));
    task = (void *)EVENT_BATTLE_CreateEncounterTask((int)gameSystem, battleSrc, battleMode, battleFlags, battleKind, fieldEffect, options);
    if (sub_0200E740(giftData, entryIndex) != 0) {
        mon = POKEPARTY_GetMember(*(void **)(*(u8 **)((u8 *)GAME_EVENT_GetWork(task) + 8) + 0x28), 0);
        oldSpecies = POKE_TOOL_GetPartyValue(mon, 5, 0);
        species = sub_0200E788(giftData, entryIndex, 0x15);
        level = sub_0200E74C(giftData, entryIndex);
        id = sub_0200E7B4(giftData, entryIndex);
        rnd = sub_0200E7A4(giftData, entryIndex);
        POKE_TOOL_SetupPartyParamEx(mon, species, level, id, -1, rnd);
        if (sub_0200E76C(giftData, entryIndex) != 0) {
            POKE_TOOL_SetPartyValue(mon, 10, sub_0200E780(giftData, entryIndex));
        }
        POKE_TOOL_SetPartyValue(mon, 0x74, (u32)sub_0200E7AC(giftData, entryIndex));
        POKE_TOOL_ChangeSpecies(mon, (u16)oldSpecies);
        POKE_TOOL_SetDefaultMoves(mon);
    }
    return task;
}




/*
 * lever:    case 1's argument-less `bl FIELDMAP_GetEncEff` takes proc (the
 *           GAMESYSTEM_GetFieldMap result) as its hidden r0 argument: the matched
 *           ov021 definition is int FIELDMAP_GetEncEff(unsigned char *p). That
 *           keeps proc in r0 through the dispatch, the index in r1 and the
 *           r2 copy of proc for cases 2 and 10 (457 -> 2 bytes). The ov230
 *           probe calls resolve with the `ov230d` token, prototypes copied
 *           from the matched twin src/matched/arm9/GAMESYSTEM_ProcInit.c.
 * residue:  case 7 zeroes its spilled `ok` (sp+0xC) through r2 in the image
 *           (`movs r2,#0; str r2,[sp,#0xc]` at 0x0216ECCC), r0 in the compile.
 *           No change from ok as u32, u8, enum, function-scope, passed as the
 *           seed, or with start/end locals ahead of it; permuter 300 found
 *           nothing (baseline agrees, DIFF 2/612).
 *           unlabelled: `ldr r1,[r0]; str r1,[r0,#8]; movs r1,#0; str
 *           r1,[r0]; bx lr`, verified C not filed: arm9 is the integrator's);
 *           0x0216EFDC (ov010 unlabelled tail-call leaf, not filed while an
 *           arm9 leaf blocks); ov093_id/ov092_id pooled ids passed to
 *           GAME_EVENT_CallProc, which is not in OVERLAY_ID_CONSUMERS;
 *           d_021EFDAC/d_021B9D94 (proc data of ov093/ov092) unwitnessed.
 * prototype conflicts (parked, matched callees not edited):
 *           EVENT_BATTLE_FreeBtlSetup (ov010 0x0216F054, src/matched/ov/EVENT_BATTLE_FreeBtlSetup.c)
 *           is defined int(int a0, int a1) but a1 is overwritten before any
 *           read (`ldr r1,[r0,#0x20]` at 0x0216F054); the three call sites
 *           here set only r0 (`adds r0, r5, #0; bl`). GAME_DATA_GetPmsWork (arm9,
 *           src/matched/arm9/GAME_DATA_GetPmsWork.c) is defined int(int p0..p3) and
 *           reads only p0; both sites here set only r0 (`ldr r0,[sp,#0x10];
 *           bl`). The C below declares both with one parameter.
 * runs:     4 iteration + checks (2 + 2 + 1) + permuter 300; one cleanup run.
 * checks:   1 every callee re-derived from its matched definition: FIELDMAP_GetEncEff takes the live proc in r0 (fixed), F054/2F20 definitions over-declare (conflict above); 2 twin GAMESYSTEM_ProcInit gives the ov230d probe tokens and prototypes (resolved 3 sites), u32 start local no change; 3 ok as u32 / enum no change; 4 u8 flag idiom (a-narrow-flag-local-is-spilled) no change, zero-register idioms read; 5 idioms re-listed, nothing new applies
 * note:     2026-10-05 wave P19 lane 6 recoup: byte-correct (612/612, 0 bytes off).
 *           Lever: case 7 writes ok in both arms (`if (probe == ~f) ok = 1; else ok = 0;`
 *           with `int ok;` uninitialised), which moves the spilled zero to r2 (was r0,
 *           2 bytes). Tried before it: six per-function pragmas (lifetimes 14 B, the rest
 *           2 B), function-scope ok, ok as the probe seed or a separate zero local, probe
 *           result in a local (3 B), ternary sum (258 B). Data words resolve with
 *           `data ov093` / `data ov092` tokens. Leaf witnesses filed:
 *           src/matched/arm9/COMM_PLAYER_SUPPORT_StashMode.c and src/matched/ov/ov010_func_0216EFDC.c (both
 *           EXACT c99 and c); the three unresolved call sites resolve once the integrator
 *           refreshes the manifest. Callee arity conflicts (matched definitions
 *           over-declare, callers pass less): EVENT_BATTLE_FreeBtlSetup and GAME_DATA_GetPmsWork.
 */
int EVENT_BATTLE_ProcBattleTask(void *event, u32 *state, BattleTask *work)
{
    void *gameSystem = work->gameSystem;
    void *gameData = work->gameData;
    void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    u32 integritySum = 0x013A1AB5;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSystem, work->btlSetup->bgmId));
        (*state)++;
        break;
    case 1:
        ENCEFF_Start((void *)FIELDMAP_GetEncEff(fieldMap), (u32)event, (int)work->encounterEffect);
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, (void *)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)fieldMap));
        (*state)++;
        break;
    case 3:
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData), 1);
        COMM_PLAYER_SUPPORT_Init((u8 *)GAME_DATA_GetPmsWork((int)gameData));
        GAME_EVENT_CallProc(event, (u32)ov093_id, (u32)d_021EFDAC, (u32)work->btlSetup);
        (*state)++;
        break;
    case 4:
        work->procBtlSetup = work->btlSetup;
        work->procGameData = gameData;
        GAME_EVENT_CallProc(event, (u32)ov092_id, (u32)d_021B9D94, (u32)&work->procGameData);
        (*state)++;
        break;
    case 5:
        func_02034AC4((s32)ov230_id);
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData), 0);
        COMM_PLAYER_SUPPORT_StashMode((void *)GAME_DATA_GetPmsWork((int)gameData));
        (*state)++;
        break;
    case 6: {
        int probeOk = 0;

        if (func_021882DC((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeA, 0) == ~(u32)EVENT_BATTLE_IntegrityProbeA)
            probeOk = 1;
        integritySum += probeOk ? 0 : 0x3D1;
        EVENT_BATTLE_FinishBattleTask(work, gameData);
        if (work->addTallies != 0)
            FLD_BTL_INST_TOOL_AddBattleTally(*(void **)GAME_DATA_GetListCursor(gameData), (struct Result *)work->btlSetup);
        (*state)++;
        probeOk = 0;
        if (func_02188354((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeB, 0) == ~(u32)EVENT_BATTLE_IntegrityProbeB)
            probeOk = 1;
        integritySum += probeOk ? 0 : 0x5D1;
        break;
    }
    case 7: {
        int probeOk;

        if (func_02188390((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeC, 0) == ~(u32)EVENT_BATTLE_IntegrityProbeC)
            probeOk = 1;
        else
            probeOk = 0;
        integritySum += probeOk * 0x9D;
        if (work->skipResultCheck == 0 && EVENT_BATTLE_IsTaskResultSilent(work) == 1)
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(gameSystem, 0x1E));
        else
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSystem));
        func_02034A5C((s32)ov230_id);
        (*state)++;
        break;
    }
    case 8:
        if (work->skipResultCheck == 0 && EVENT_BATTLE_IsTaskResultSilent(work) == 1) {
            if (work->isScripted == 1) {
                EVENT_BATTLE_FreeBtlSetup(work);
                return 1;
            }
            EVENT_BATTLE_FreeBtlSetup(work);
            GAME_EVENT_ChangeEvent(event, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
            return 0;
        }
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 9:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*state)++;
        break;
    case 10:
        if (work->isScripted == 0)
            GAME_EVENT_CallEvent(event, (void *)(int)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (void *)((int)fieldMap), 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 11:
        EVENT_BATTLE_FreeBtlSetup(work);
        return 1;
    }
    if (integritySum % 0x1933 != 0) {
        func_020056A0((void (*)(void *, void *))GAMESYSTEM_ReadTimerTwice, 0, 0x7F);
        g_0214624C++;
    }
    return 0;
}




/*
 * Mode word out of the overlay call decides between zero, one and two;
 * two of the modes are refused outright.
 */
int EVENT_BATTLE_GetBattleKindClass(void *battleKind)
{
    int r = 1;
    int v;

    v = func_0202A3FC(func_0202A230(battleKind, 1));

    if (v == 0xC || v == 9)
        return 0;
    if (v != 2)
        r = 2;

    return r;
}




/*
 * Dispatches through the two-column handler table d_021725C0, row chosen
 * by EVENT_BATTLE_GetBattleKindClass's classification of `id`.
 */
void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col)
{
    d_021725C0[EVENT_BATTLE_GetBattleKindClass((void *)id)][col](id);
}




/*
 * Reports the species of the first party member to one of three
 * notifiers.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is arm9
 * 0x0201313C, an unlabelled Thumb leaf (`lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x24]; bx lr`) inside the listing's ARM data run.
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 BTL_SETUP_GetParty (matched file exists, no shard yet); integrator shard resolves it.
 */
void EVENT_BATTLE_NotifyLeadSpecies(void *btlSetup, int which)
{
    u16 species;

    species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(BTL_SETUP_GetParty(btlSetup, 1), 0), 5, 0);
    switch (which) {
    case 0:
        GAME_BEACON_SEARCH_SetBattlePokeStart(species);
        break;
    case 1:
        GAME_BEACON_SEARCH_SetBattlePokeWin(species);
        break;
    case 2:
        GAME_BEACON_SEARCH_SetPokeEvent(species);
        break;
    }
}




/*
 * After a battle: unless the outcome is 0 or 2, reports the lead party
 * member's state (fainted, at half HP or less, a move out of PP, a status
 * condition) by name, then reports the species depending on the mode and
 * outcome.
 */
void EVENT_BATTLE_NotifyBattleEnd(BattleEndCtx *ctx)
{
    BtlSetup *setup;
    void *playerParty;
    void *leadMon;
    void *nameBuf;
    u16 curHp;
    u16 maxHp;
    int moveIndex;

    setup = ctx->btlSetup;
    playerParty = GAME_DATA_GetMyParty(ctx->btlSetupObj);
    leadMon = POKEPARTY_GetMember(playerParty, POKEPARTY_FindFirstNonEgg(playerParty));
    if (setup->outcome != 0 && setup->outcome != 2) {
        nameBuf = STRBUF_Create(12, 0x8004);
        POKE_TOOL_GetPartyValue(leadMon, 0x73, (u32)nameBuf);
        curHp = POKE_TOOL_GetPartyValue(leadMon, 0xA0, 0);
        maxHp = POKE_TOOL_GetPartyValue(leadMon, 0xA1, 0);
        if (curHp == 0)
            GAME_BEACON_SEARCH_SetEventBattleNameC(nameBuf);
        else if (curHp * 2 <= maxHp)
            GAME_BEACON_SEARCH_SetEventBattleNameA(nameBuf);
        for (moveIndex = 0; moveIndex < 4; moveIndex++) {
            if (POKE_TOOL_GetPartyValue(leadMon, 0x36 + moveIndex, 0) != 0 && POKE_TOOL_GetPartyValue(leadMon, 0x3A + moveIndex, 0) == 0) {
                GAME_BEACON_SEARCH_SetEventBattleNameB(nameBuf);
                break;
            }
        }
        if (POKE_TOOL_GetPartyValue(leadMon, 0x9D, 0) != 0)
            GAME_BEACON_SEARCH_SetEventBattleNameD(nameBuf);
        STRBUF_Delete(nameBuf);
    }
    switch (setup->mode) {
    case 0:
        if (setup->outcome == 3)
            EVENT_BATTLE_NotifyLeadSpecies(setup, 2);
        else if (setup->outcome == 1)
            EVENT_BATTLE_NotifyLeadSpecies(setup, 1);
        break;
    case 1:
        if (setup->outcome == 1)
            EVENT_BATTLE_DispatchBattleKindNotify(*setup->result, 1);
        break;
    }
}




int EVENT_BATTLE_SetResultSound(BattleTask *task)
{
    BtlSetup *btlSetup = task->btlSetup;
    void *gameData = GAMESYSTEM_GetGameData(task->gameSystem);
    int records = (int)GAME_DATA_GetTrainerRecord(gameData);

    if (btlSetup->mode == 0 && btlSetup->outcome == 4)
        records = func_02008DF0((struct RecordBlock *)records, 0x4f);
    return records;
}




int EVENT_BATTLE_IsResultSilent(int outcome, int mode)
{
    if (mode == 4)
        return 0;
    if (d_021725D8[outcome][mode] == 0)
        return 1;
    return 0;
}




/*
 * Unlabelled leaf, blocker of ov021 SCRCMD_PROC_FLD_StoreByteValue: byte table lookup, 0xFF maps to 1.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 EVENT_BATTLE_GetKindFlag(int kindId)
{
    u8 flag = d_021725B8[kindId];

    if (flag == 0xff) {
        flag = 1;
    }
    return flag;
}




/*
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled tail-call leaf filed as
 *           the witness for the calls in ov010 EVENT_BATTLE_ProcBattleTask. Reads the info
 *           block at w[2] and tail-calls EVENT_BATTLE_IsResultSilent(info[0x8c / 4], info[0]).
 */
int EVENT_BATTLE_IsTaskResultSilent(BattleTask *task)
{
    BtlSetup *btlSetup = task->btlSetup;
    return EVENT_BATTLE_IsResultSilent(btlSetup->outcome, btlSetup->mode);
}



/*
 * func_0202C83C's body consumes only r0/r1, forwarding those to
 * func_0202C794; original supplies no new r2/r3. Legacy trailing
 * arguments are omitted. GAME_DATA_GetPlayerZoneId consumes the preceding result.
 */
void EVENT_BATTLE_FinishBattleTask(BattleTask *task, void *gameSystem)
{
    GAME_DATA_SetFieldMode(gameSystem, task->btlSetup->outcome);
    MOVE_POKEMON_HandleBattleResult(gameSystem, task->btlSetup);
    EVENT_BATTLE_NotifyBattleEnd((struct BattleEndCtx *)task);
    EVENT_BATTLE_SetResultSound(task);
    func_0202C83C((int)task->gameSystem, GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameSystem)));
}



void EVENT_BATTLE_InitTaskWork(BattleTask *task, void *gameSystem, void *btlSetup)
{
    int zero = 0;

    func_02082A7C(0, task, 40);
    task->gameSystem = gameSystem;
    task->gameData = GAMESYSTEM_GetGameData(gameSystem);
    task->btlSetup = btlSetup;
    task->isScripted = zero;
    task->skipResultCheck = zero;
    task->addTallies = zero;
}




int EVENT_BATTLE_FreeBtlSetup(BattleTask *task)
{
    if (task->keepBtlSetup == 0)
        return BTL_SETUP_Delete((int)task->btlSetup);
    return (int)task;
}




int EVENT_BATTLE_IntegrityProbeA(int unused)
{
    func_0203F0A8();
    return func_0203F0A8();
}




int EVENT_BATTLE_IntegrityProbeB(int unused)
{
    func_0203F0A8();
    return func_0203F0A8();
}




int EVENT_BATTLE_IntegrityProbeC(int unused)
{
    func_0203F0A8();
    return func_0203F0A8();
}
