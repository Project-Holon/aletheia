/*
 * file:     scrcmd_fld_battle.c
 * unit:     yes
 * function: func_021B5700, func_021B574C, func_021B57CC, func_021B5824, func_021B58B0, func_021B59B0
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201A354  0x0201A354  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_02030734  0x02030734  arm
 *   g_021DE248     0x021DE248  data  a1
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   func_0201A090  0x0201A090  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021CC720  0x021CC720  thumb  ov021
 *   func_021CC810  0x021CC810  thumb  ov021
 *   func_021CC7B4  0x021CC7B4  thumb  ov021
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

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5DC(void *a0);
extern void *func_0201A354(int a, int b);
extern u32 func_020307B0(void *p);
extern void func_0215897C(void *vm, void *task);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CED4(struct ZukanSave *p, u16 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct GameSystem *p);
extern void *func_0201210C(const struct GameSystem *p);
extern void *func_02012934(const struct GameData *p);
extern void *func_02012EBC(struct GameData *p);
extern int func_02019ED4(void *rules, void *party);
extern int func_0201A090(void *rules, void *party, u32 *mask);
extern void *func_0200BAC8(void *);
extern u32 func_0200BBA8(void *a);
extern void *func_0200BAF4(int a0, int a1);
extern struct FieldTask *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct FieldTask *p);
extern struct PartySelectList *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int func_021CC810(struct PartySelectList *p);
extern u32 func_021CC7B4(struct PartySelectList *p, u32 *out);
int func_021B5700(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B574C(struct ScriptVm *vm, struct ScrcmdWork *work);
u16 func_021B57CC(void *gameData, void *wordSet, u32 regulationNo, int heapId);
u16 *func_021B5824(u8 *regulation, void *gameData, u16 *count, int heapId);
void *func_021B58B0(void *gameSystem, int isSubwayRules, void *rules, u16 *result, u16 heapId);
int func_021B59B0(struct FieldTask *fieldTask, int *state, PartyCheckTaskWork *taskWork);
extern const char g_021DE248[];



/*
 * Script command: register the names of the species the regulation allows
 * and the player has seen in the word set; the count goes to the result
 * variable.
 */
int func_021B5700(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *wordSet = func_0215A5F4(work);
    void *gameData = func_0215A5E4(work);
    unsigned int regulationNo;
    u16 *countOut;

    wordSet = func_02158F74(wordSet);
    regulationNo = func_02159B10(vm, work);
    countOut = func_02159AE8(vm, work);
    *countOut = func_021B57CC(gameData, wordSet, regulationNo, func_0215A5CC(work));
    return 0;
}



/*
 * func_0201A354 is filed as src/matched/arm9/func_0201A354.c (witness).
 *
 * Script command: check the player party and the party in the battle record
 * against a regulation; starts the party select task when the check needs
 * the player to look at the result. Returns 1 while that task runs.
 */
int func_021B574C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork = func_0215A5F4(work);
    void *gameSystem = func_0215A5DC(work);
    int regulationNo = func_02159B10(vm, work);
    u16 *resultOut = func_02159AE8(vm, work);
    u16 heapId = func_0215A5CC(work);
    void *rules = func_0201A354(regulationNo, heapId);
    int isSubwayRules = 1;
    u16 subwayIndex = regulationNo + 0xffec;
    void *task;

    if (subwayIndex > 2) {
        isSubwayRules = 0;
    }
    task = func_021B58B0(gameSystem, isSubwayRules, rules, resultOut, heapId);
    func_020307B0(rules);
    if (task == 0) {
        return 0;
    }
    func_0215897C(scriptWork, task);
    return 1;
}



u16 func_021B57CC(void *gameData, void *wordSet, u32 regulationNo, int heapId)
{
    u16 count = 0;
    u16 i = 0;
    void *regulation;
    u16 *speciesList;

    regulation = func_0201A354(regulationNo, heapId);
    speciesList = func_021B5824(regulation, gameData, &count, heapId);
    for (i = 0; i < count; i++) {
        func_0201EE60(wordSet, i, speciesList[i]);
    }
    func_020307B0(speciesList);
    func_020307B0(regulation);
    return count;
}



/*
 * Lists the species that the regulation bitmap (at +0x0A) allows and the
 * player has in the Pokedex, at most 0x20. The result is a heap block of 0x40
 * bytes owned by the caller.
 */
u16 *func_021B5824(u8 *regulation, void *gameData, u16 *count, int heapId)
{
    int species = 0;
    void *zukan;
    u16 *speciesList;

    *count = 0;
    zukan = func_0200CA1C(gameData);
    speciesList = func_02030734((u16)((heapId & 0x7fff) | 0x8000), 0x40, 1, g_021DE248, 0xac);
    for (species = 0; species < 0x28b; species++) {
        if (regulation[0xa + species / 8] & (1 << (species % 8))) {
            if (func_0200CED4(zukan, (u16)species)) {
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
void *func_021B58B0(void *gameSystem, int isSubwayRules, void *rules, u16 *result, u16 heapId)
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

    gameData = func_020120F4(gameSystem);
    mask = 0;
    playerParty = func_02012934(gameData);
    if (isSubwayRules) {
        playerPartyInvalid = func_02019ED4(rules, playerParty);
    } else {
        playerPartyInvalid = func_0201A090(rules, playerParty, &mask);
    }
    battleRec = func_0200BAC8(func_02012EBC(gameData));
    if (func_0200BBA8(battleRec) == 1) {
        mask = 0;
        recordParty = func_0200BAF4((int)battleRec, heapId);
        if (isSubwayRules) {
            recordPartyInvalid = func_02019ED4(rules, recordParty);
        } else {
            tmp = func_0201A090(rules, recordParty, &mask);
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
            func_020307B0(recordParty);
        }
        *result = 3;
        return 0;
    }
    task = func_020122C0(gameSystem, 0, (void *)func_021B59B0, 0x1c);
    playerFlag = 0;
    taskWork = func_020124E8(task);
    taskWork->gameSystem = gameSystem;
    taskWork->fieldMap = func_0201210C(gameSystem);
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
int func_021B59B0(struct FieldTask *fieldTask, int *state, PartyCheckTaskWork *taskWork)
{
    int cancelled;

    switch (*state) {
    case 0:
        taskWork->partySelect = func_021CC720((u32)taskWork->fieldMap, (u32)taskWork->playerParty,
                                              (u32)taskWork->recordParty, taskWork->playerPartyInvalid,
                                              taskWork->recordPartyInvalid, taskWork->heapId);
        (*state)++;
        break;
    case 1:
        if (func_021CC810(taskWork->partySelect)) {
            *taskWork->result = func_021CC7B4(taskWork->partySelect, (u32 *)(&cancelled));
            if (cancelled == 1) {
                *taskWork->result = 3;
            }
            func_020307B0(taskWork->recordParty);
            return 1;
        }
        break;
    }
    return 0;
}
