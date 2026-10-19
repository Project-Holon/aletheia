/*
 * file:     scrcmd_fld_battle.c
 * unit:     yes
 * function: SCRCMD_FLD_BATTLE_RegisterAllowedSpecies, SCRCMD_FLD_BATTLE_CheckPartyRegulation, SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames, SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList, SCRCMD_FLD_BATTLE_CreatePartyCheckTask, SCRCMD_FLD_BATTLE_PartyCheckTaskMain
 * address:  0x021B5700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsCaught  0x0200CED4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   sScrcmdFldBattleFileName     0x021DE248  data  a1
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKE_REGULATION_CheckPartyUsable  0x02019ED4  thumb
 *   POKE_REGULATION_CheckParty  0x0201A090  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_HasMon  0x0200BBA8  thumb
 *   BATTLE_BOX_CreateParty  0x0200BAF4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   PARTY_SELECT_LIST_Create  0x021CC720  thumb  ov021
 *   PARTY_SELECT_LIST_Main  0x021CC810  thumb  ov021
 *   PARTY_SELECT_LIST_Delete  0x021CC7B4  thumb  ov021
 */

#include "../arm9/script_vm_types.h"

struct ScrcmdWork;
struct WordSet;
struct ZukanSave;
struct GameData;
struct GameSystem;
struct FieldMap;
struct FieldTask;
struct PartySelectList;

/*
 * Work of the party check task (0x1C bytes, allocated by the field task
 * function). The task shows the party select list for the player party and
 * the party stored in the battle record, and marks the ones that break the
 * regulation.
 */
typedef struct PartyCheckTaskWork {
    void *gameSystem;                    /* 0x00 */
    void *fieldMap;                      /* 0x04 */
    struct PartySelectList *partySelect; /* 0x08 */
    void *playerParty;                   /* 0x0C */
    void *recordParty;                   /* 0x10: heap copy, freed when the task ends */
    u8 playerPartyInvalid;               /* 0x14 */
    u8 recordPartyInvalid;               /* 0x15 */
    u16 heapId;                          /* 0x16 */
    u16 *result;                         /* 0x18 */
} PartyCheckTaskWork;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *work);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *vm, void *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *vm, void *cmdWork);
extern u16 SCRCMD_WORK_GetHeapId(void *work);
extern void *SCRCMD_WORK_GetGameSystem(void *work);
extern void *POKE_REGULATION_Load(int a, int b);
extern u32 GFL_HEAP_Free(void *p);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void WORDSET_SetSlotSpeciesName(struct WordSet *p, u32 i, u16 v);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u32 ZUKAN_SAVE_IsCaught(struct ZukanSave *p, u16 id);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *p);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *p);
extern void *GAME_DATA_GetMyParty(const struct GameData *p);
extern void *GAME_DATA_GetSaveControl(struct GameData *p);
extern int POKE_REGULATION_CheckPartyUsable(void *rules, void *party);
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern void *BATTLE_BOX_GetFromSave(void *);
extern u32 BATTLE_BOX_HasMon(void *a);
extern void *BATTLE_BOX_CreateParty(int box, int heap);
extern struct FieldTask *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
extern void *GAME_EVENT_GetWork(struct FieldTask *p);
extern struct PartySelectList *PARTY_SELECT_LIST_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int PARTY_SELECT_LIST_Main(struct PartySelectList *p);
extern u32 PARTY_SELECT_LIST_Delete(struct PartySelectList *p, u32 *out);
int SCRCMD_FLD_BATTLE_RegisterAllowedSpecies(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_FLD_BATTLE_CheckPartyRegulation(struct ScriptVm *vm, struct ScrcmdWork *work);
u16 SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(void *gameData, void *wordSet, u32 regulationNo, int heapId);
u16 *SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(u8 *regulation, void *gameData, u16 *count, int heapId);
void *SCRCMD_FLD_BATTLE_CreatePartyCheckTask(void *gameSystem, int isSubwayRules, void *rules, u16 *result, u16 heapId);
int SCRCMD_FLD_BATTLE_PartyCheckTaskMain(struct FieldTask *fieldTask, int *state, PartyCheckTaskWork *taskWork);
extern const char sScrcmdFldBattleFileName[];



/*
 * Script command: register the names of the species the regulation allows
 * and the player has seen in the word set; the count goes to the result
 * variable.
 */
int SCRCMD_FLD_BATTLE_RegisterAllowedSpecies(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *wordSet = SCRCMD_WORK_GetScriptWork(work);
    void *gameData = SCRCMD_WORK_GetGameData(work);
    unsigned int regulationNo;
    u16 *countOut;

    wordSet = SCRIPT_WORK_GetWordSet(wordSet);
    regulationNo = SCRIPT_WORK_ReadWorkValue(vm, work);
    countOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *countOut = SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(gameData, wordSet, regulationNo, SCRCMD_WORK_GetHeapId(work));
    return 0;
}



/*
 * POKE_REGULATION_Load is filed as src/matched/arm9/POKE_REGULATION_Load.c (witness).
 *
 * Script command: check the player party and the party in the battle record
 * against a regulation; starts the party select task when the check needs
 * the player to look at the result. Returns 1 while that task runs.
 */
int SCRCMD_FLD_BATTLE_CheckPartyRegulation(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    int regulationNo = SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    u16 heapId = SCRCMD_WORK_GetHeapId(work);
    void *rules = POKE_REGULATION_Load(regulationNo, heapId);
    int isSubwayRules = 1;
    u16 subwayIndex = regulationNo + 0xffec;
    void *task;

    if (subwayIndex > 2) {
        isSubwayRules = 0;
    }
    task = SCRCMD_FLD_BATTLE_CreatePartyCheckTask(gameSystem, isSubwayRules, rules, resultOut, heapId);
    GFL_HEAP_Free(rules);
    if (task == 0) {
        return 0;
    }
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}



u16 SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(void *gameData, void *wordSet, u32 regulationNo, int heapId)
{
    u16 count = 0;
    u16 i = 0;
    void *regulation;
    u16 *speciesList;

    regulation = POKE_REGULATION_Load(regulationNo, heapId);
    speciesList = SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(regulation, gameData, &count, heapId);
    for (i = 0; i < count; i++) {
        WORDSET_SetSlotSpeciesName(wordSet, i, speciesList[i]);
    }
    GFL_HEAP_Free(speciesList);
    GFL_HEAP_Free(regulation);
    return count;
}



/*
 * Lists the species that the regulation bitmap (at +0x0A) allows and the
 * player has in the Pokedex, at most 0x20. The result is a heap block of 0x40
 * bytes owned by the caller.
 */
u16 *SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(u8 *regulation, void *gameData, u16 *count, int heapId)
{
    int species = 0;
    void *zukan;
    u16 *speciesList;

    *count = 0;
    zukan = ZUKAN_SAVE_GetFromGameData(gameData);
    speciesList = GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), 0x40, 1, sScrcmdFldBattleFileName, 0xac);
    for (species = 0; species < 0x28b; species++) {
        if (regulation[0xa + species / 8] & (1 << (species % 8))) {
            if (ZUKAN_SAVE_IsCaught(zukan, (u16)species)) {
                if (*count >= 0x20) {
                    break;
                }
                speciesList[(*count)++] = species;
            }
        }
    }
    return speciesList;
}



/*
 * Two spellings carry the block layout: the else arm's result goes through
 * a temporary (tmp), which keeps the inner if/else ahead of the outer else
 * rather than sunk before the rest; and the not-1 path is an if/else of two
 * stores, not a ternary (which compiles branch-free).  `playerFlag = 0`
 * after the task call is what puts its zero in r1.
 *
 * Addresses are Black-image addresses.
 */
void *SCRCMD_FLD_BATTLE_CreatePartyCheckTask(void *gameSystem, int isSubwayRules, void *rules, u16 *result, u16 heapId)
{
    u32 mask = 0;
    void *gameData;
    void *playerParty;
    int playerPartyInvalid;
    void *battleRec;
    void *recordParty;
    int recordPartyInvalid;
    struct FieldTask *task;
    PartyCheckTaskWork *taskWork;
    u32 playerFlag;
    int tmp;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    mask = 0;
    playerParty = GAME_DATA_GetMyParty(gameData);
    if (isSubwayRules) {
        playerPartyInvalid = POKE_REGULATION_CheckPartyUsable(rules, playerParty);
    } else {
        playerPartyInvalid = POKE_REGULATION_CheckParty(rules, playerParty, &mask);
    }
    battleRec = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    if (BATTLE_BOX_HasMon(battleRec) == 1) {
        mask = 0;
        recordParty = BATTLE_BOX_CreateParty((int)battleRec, heapId);
        if (isSubwayRules) {
            recordPartyInvalid = POKE_REGULATION_CheckPartyUsable(rules, recordParty);
        } else {
            tmp = POKE_REGULATION_CheckParty(rules, recordParty, &mask);
            recordPartyInvalid = tmp;
        }
    } else {
        if (playerPartyInvalid) {
            *result = 3;
        } else {
            *result = 0;
        }
        return 0;
    }
    if (playerPartyInvalid && recordPartyInvalid) {
        if (recordParty) {
            GFL_HEAP_Free(recordParty);
        }
        *result = 3;
        return 0;
    }
    task = GAME_EVENT_Create(gameSystem, 0, (void *)SCRCMD_FLD_BATTLE_PartyCheckTaskMain, 0x1c);
    playerFlag = 0;
    taskWork = GAME_EVENT_GetWork(task);
    taskWork->gameSystem = gameSystem;
    taskWork->fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    taskWork->result = result;
    taskWork->heapId = heapId;
    taskWork->playerParty = playerParty;
    taskWork->recordParty = recordParty;
    if (playerPartyInvalid) {
        playerFlag = 1;
    }
    taskWork->playerPartyInvalid = playerFlag;
    taskWork->recordPartyInvalid = recordPartyInvalid ? 1 : 0;
    return task;
}



/* Field task function: opens the party select list, then stores its result. */
int SCRCMD_FLD_BATTLE_PartyCheckTaskMain(struct FieldTask *fieldTask, int *state, PartyCheckTaskWork *taskWork)
{
    int cancelled;

    switch (*state) {
    case 0:
        taskWork->partySelect = PARTY_SELECT_LIST_Create((u32)taskWork->fieldMap, (u32)taskWork->playerParty,
                                              (u32)taskWork->recordParty, taskWork->playerPartyInvalid,
                                              taskWork->recordPartyInvalid, taskWork->heapId);
        (*state)++;
        break;
    case 1:
        if (PARTY_SELECT_LIST_Main(taskWork->partySelect)) {
            *taskWork->result = PARTY_SELECT_LIST_Delete(taskWork->partySelect, (u32 *)(&cancelled));
            if (cancelled == 1) {
                *taskWork->result = 3;
            }
            GFL_HEAP_Free(taskWork->recordParty);
            return 1;
        }
        break;
    }
    return 0;
}
