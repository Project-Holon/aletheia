/*
 * file:     musical_program.c
 * unit:     yes
 * function: MUSICAL_PROGRAM_Create, MUSICAL_PROGRAM_Delete, MUSICAL_PROGRAM_SplitBonus, MUSICAL_PROGRAM_GetCategoryBonus, MUSICAL_PROGRAM_PackBonus, MUSICAL_PROGRAM_UnpackBonus, MUSICAL_PROGRAM_PackPicks, MUSICAL_PROGRAM_UnpackPicks, MUSICAL_PROGRAM_GetBestCategory, MUSICAL_PROGRAM_CreateNpcPerformer, MUSICAL_PROGRAM_GetBaseProgramId, MUSICAL_PROGRAM_GetPropRow, MUSICAL_PROGRAM_GetNpcPortraitClass, MUSICAL_PROGRAM_GetNpcNameId, MUSICAL_PROGRAM_GetCategoryShare, IRC_BATTLE_TASK_Main, IRC_BATTLE_TASK_Create, IRC_BATTLE_TASK_SetFormationOnce, IRC_BATTLE_TASK_Empty0, IRC_BATTLE_TASK_Empty1, IRC_BATTLE_TASK_Empty2, IRC_BATTLE_TASK_Empty3
 * address:  0x02157028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_dressup_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_SetupCommMulti  0x020137F0  thumb
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_REC_SAVE_Start  0x021550A0  thumb  ov008
 *   ov008_id       0x00000008  data
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MUSICAL_MCSS_LoadActorData  0x021F4F14  thumb  ov112
 *   MUSICAL_MCSS_GetElemA  0x021F5140  thumb  ov112
 *   MUSICAL_MCSS_FreeActorData  0x021F4F40  thumb  ov112
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   _s32_div_f  0x0209C0A4  arm
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   sMusicalProgramFileName  0x02172768  data
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   SAVEDATA_PanicFail  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 *   MUSICAL_STAGE_SYS_CreateNpcPerformer 0x02156FD0 thumb ov010
 *   MUSICAL_STAGE_SYS_SetPerformerProp 0x0215700C thumb ov010
 */
#include "../arm9/btl_setup_types.h"
#include "event_ircbattle_shared_types.h"
#include "musical_event_shared_types.h"

typedef unsigned long long u64;

/* Slot description handed to the battle recorder (0x50 bytes). */
typedef struct IrcBattleSlotInfo {
    u8 data[0x48];
    int formation;                      /* 0x48 */
    int flag;                           /* 0x4C */
} IrcBattleSlotInfo;

typedef struct IrcBattleRequest {
    void *party;                        /* 0x00 */
    u8 pad04[0xC];
    u16 bgmBattle;                      /* 0x10 */
    u8 multiTeam;                       /* 0x12 */
    u8 pad13;
    void *regulation;                   /* 0x14 */
    IrcBattleSlotInfo slot;             /* 0x18 */
} IrcBattleRequest;

/* Work of the IR battle task (0xFC bytes). */
typedef struct IrcBattleTaskWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    struct BattleSetupParam setup;      /* 0x08 */
    IrcBattleSlotInfo *slot;            /* 0xF8 */
} IrcBattleTaskWork;

extern void GAME_EVENT_CallEvent(void *parentEvent, void *childEvent);

extern void *GAMESYSTEM_GetGameData(void *gameSys);

extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);

extern void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u8 team, u16 heapId);

extern void BTL_SETUP_SetParty(struct BattleSetupParam *setup, void *party, int index);

extern void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *setup, u32 flag);

extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(void *gameSys, u32 overlayId, void *proc, void *procArg);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);

extern u32 GFL_HEAP_Free(void *ptr);

extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSys);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSys, void *fieldMap, int sel, int d, int e, u8 f, u8 g);

extern void *EVENT_BATTLE_REC_SAVE_Start(void *a, const int *p);

extern struct GameEvent *GAME_EVENT_Create(void *gameSys, void *a, void *proc, u32 size);

extern void *func_020124E8(struct GameEvent *event);

extern void *MUSICAL_MCSS_LoadActorData(int heapId);

extern unsigned char MUSICAL_MCSS_GetElemA(void *table, int propId);

extern void MUSICAL_MCSS_FreeActorData(void **table);

extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *gameSys);

extern u32 GF_STANDARD_Rand(void);

extern int _s32_div_f(int dividend, int divisor);

extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *gameSys, u32 b);

extern void BTL_SETUP_FreeSlots(struct BattleSetupParam *setup);

extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *gameSys);

extern void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *setup, void *regulation, u32 heapId);

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);

/* Overlay ids (absolute linker symbols) and data of other overlays. */
extern u8 ov008_id[];

extern const char sMusicalProgramFileName[];

extern u8 d_0217277C[];

void MUSICAL_STAGE_SYS_CreateNpcPerformer(MusicalStage *stage, u8 slot, u16 monsNo, u8 form, u32 personality, u16 appealBase, u16 heapId);

void MUSICAL_STAGE_SYS_SetPerformerProp(MusicalStage *stage, u8 slot, u8 bodySlot, u16 propId, s16 offset, u8 order);

MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel);

int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program);

void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage);

u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index);

u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program);

void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed);

u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program);

void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed);

u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program);

void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId);

u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program);

int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program);

u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex);

u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex);

u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category);

int IRC_BATTLE_TASK_Main(void *event, u32 *state, IrcBattleTaskWork *work);

struct GameEvent *IRC_BATTLE_TASK_Create(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request);

void IRC_BATTLE_TASK_SetFormationOnce(int *formation, int value);

void IRC_BATTLE_TASK_Empty0(void);

void IRC_BATTLE_TASK_Empty1(void);

void IRC_BATTLE_TASK_Empty2(void);

void IRC_BATTLE_TASK_Empty3(void);

static inline u32 RandBelow(u32 n)
{
    u32 r = GF_STANDARD_Rand();

    if (n != 0)
        r = ((u64)r * n) >> 32;
    return r;
}

/*
 * Creates the show program: copies the base program's category bonuses,
 * deals the extra bonus (bonusTotal / 5 steps of 5 points) to random
 * categories and picks three of the six NPC templates the musical level
 * allows. The candidate buffer is `u8 buf[6] = {0, ...}` in a nested block
 * (see docs/idioms/an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six explicit zero stores rematerialise sp+8 for the fill loop, and a plain
 * block-scope array hoists catalog out of it. RandBelow is the inline
 * `(u64)rand * n >> 32` helper; its n != 0 test folds away for constant n.
 */
MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel)
{
    MusicalShowProgram *program;
    u8 i;
    u8 remaining;
    u8 chunk;
    u8 count;
    u8 first;
    u8 second;
    u8 round;

    program = GFL_HEAP_Alloc(heapId, 0x10, 0, sMusicalProgramFileName, 100);
    program->catalog.programs = musicalSystem->programs;
    for (i = 0; i < 4; i++) {
        program->categoryBonus[i] = 0;
        program->sharePerProp[i] = 0;
    }
    for (i = 0; i < 4; i++)
        program->categoryBonus[i] = program->catalog.programs->bonus[i];
    remaining = program->catalog.programs->bonusTotal / 5;
    while (remaining != 0) {
        chunk = RandBelow(3) + 1;
        if (chunk > remaining)
            chunk = remaining;
        program->categoryBonus[RandBelow(4)] += (u8)(chunk * 5);
        remaining -= chunk;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};

        count = 0;
        for (i = 0; i < 6; i++) {
            if (program->catalog.programs[i].levelRequired <= maxLevel) {
                buf[count] = i;
                count++;
            }
        }
        if (count < 3) {
            buf[0] = 0;
            buf[1] = 1;
            buf[2] = 2;
            count = 3;
        }
        for (round = 0; round < 30; round++) {
            first = RandBelow(count);
            second = RandBelow(count);
            chunk = buf[first];
            buf[first] = buf[second];
            buf[second] = chunk;
        }
        for (i = 0; i < 3; i++)
            program->picks[i] = buf[i];
    }
    return program;
}

/*
 * Frees the show program (tail call through a pool word and `bx r3`:
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 */
int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program){

    GFL_HEAP_Free(program);
}

/*
 * Splits each category bonus over the four performers by how many of their
 * nine props fall in that category: sharePerProp = bonus / props in the
 * category, appealScore = share * the performer's props there. recoup: the
 * loop 2 and loop 4 performer pointer and the loop 2 byte counter j are
 * block-local declarations (MusicalPerformer *performer inside each for
 * body, u8 j inside the loop 2 body). Function-scope declarations gave 21
 * bytes of register swaps.
 */
void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage)
{
    void *propTable;
    u8 i;
    u8 j;
    u8 category;
    u8 score;
    u8 propsInCategory[4];
    u8 propsOfPerformer[4][4];

    propTable = MUSICAL_MCSS_LoadActorData(heapId);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            propsOfPerformer[j][i] = 0;
        propsInCategory[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        MusicalPerformer *performer = stage->performers[i];
        u8 j;
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF) {
                category = (u32)MUSICAL_MCSS_GetElemA(propTable, (u16)performer->equips[j].propId);
                propsOfPerformer[i][category]++;
                propsInCategory[category]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        program->sharePerProp[i] = _s32_div_f(program->categoryBonus[i], propsInCategory[i]);
    for (i = 0; i < 4; i++) {
        MusicalPerformer *performer = stage->performers[i];
        for (j = 0; j < 4; j++) {
            score = program->sharePerProp[j] * propsOfPerformer[i][j];
            performer->totalScore += score;
            performer->appealScore[j] = score;
        }
    }
    MUSICAL_MCSS_FreeActorData(propTable);
}

/*
 * Reads the category bonus byte at index.
 */
u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index) { return program->categoryBonus[index]; }

/*
 * Little-endian 32-bit read of the category bonuses (inverse of
 * MUSICAL_PROGRAM_UnpackBonus).
 */
u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program)
{
    return program->categoryBonus[0] + (program->categoryBonus[1] << 8) + (program->categoryBonus[2] << 16) + (program->categoryBonus[3] << 24);
}

/*
 * Stores a packed 32-bit word into the category bonuses.
 */
void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed)
{
    program->categoryBonus[0] = packed;
    program->categoryBonus[1] = (packed & 0xFF00) >> 8;
    program->categoryBonus[2] = (packed & 0xFF0000) >> 16;
    program->categoryBonus[3] = (packed & 0xFF000000) >> 24;
}

/*
 * Little-endian 24-bit read of the three picks (inverse of MUSICAL_PROGRAM_UnpackPicks).
 */
u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program)
{
    return program->picks[0] + (program->picks[1] << 8) + (program->picks[2] << 16);
}

/*
 * Stores a packed 24-bit word into the three picks.
 */
void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed)
{
    program->picks[0] = packed;
    program->picks[1] = (packed & 0xFF00) >> 8;
    program->picks[2] = (packed & 0xFF0000) >> 16;
}

/*
 * Index of the category with the highest bonus (first one on a tie).
 * Declaration order i, best, index is what colours them r2, r3, r4.
 */
u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program)
{
    u8 i;
    u8 best;
    u8 index;

    best = 0;
    index = 0;
    for (i = 0; i < 4; i++) {
        if (best < program->categoryBonus[i]) {
            best = program->categoryBonus[i];
            index = i;
        }
    }
    return index;
}

/*
 * Creates the NPC performer for stage slot `slot` from the template picked
 * as npcIndex, then equips its props. The stage slot is a u8 (as wide as
 * either callee's parameter); a u32 or int is reloaded from its spill one
 * instruction early. The personality u32 is spelled out in the call, not
 * through an inline reader, so the top byte is loaded once and kept in ip
 * for the fourth argument.
 */
void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId)
{
    MusicalRivalEntry *rival;
    u8 j;

    rival = &program->catalog.rivals->entries[program->picks[npcIndex]];
    MUSICAL_STAGE_SYS_CreateNpcPerformer(stage, slot, rival->monsNo, rival->personality[3], rival->personality[0] + (rival->personality[1] << 8) + (rival->personality[2] << 16) + (rival->personality[3] << 24), rival->appealBase, heapId);
    for (j = 0; j < 8; j++) {
        if (rival->props[j].propId != 0x1FE && rival->props[j].propId != 0x1FF)
            MUSICAL_STAGE_SYS_SetPerformerProp(stage, slot, rival->props[j].bodySlot, rival->props[j].propId, 0, j);
    }
}

/*
 * Id of the base program (first catalog entry).
 */
u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program)
{
    return program->catalog.programs->id;
}

/*
 * Prop row of the base program (selects the row of the reward prop table).
 */
int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program)
{
    return program->catalog.programs->propRow;
}

/*
 * Portrait class byte of the picked NPC template npcIndex.
 */
u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex)
{
    return program->catalog.npcInfo[program->picks[npcIndex]].portraitClass;
}

/*
 * Name id byte of the picked NPC template npcIndex.
 */
u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex)
{
    return program->catalog.npcInfo[program->picks[npcIndex]].nameId;
}

/*
 * Share of the bonus per prop for a category.
 */
u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category)
{
    return program->sharePerProp[category];
}

/*
 * Task callback of the IR battle task: a 10-state sequence that closes the
 * field, runs the battle (the ov008 runner gets the setup, the slot record
 * and a zero word) and returns 1 when done.
 */
int IRC_BATTLE_TASK_Main(void *event, u32 *state, IrcBattleTaskWork *work)
{
    void *gameSys = work->gameSys;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSys, work->setup.bgmBattle));
        (*state)++;
        break;
    case 4: {
        BattleRecSaveArgs args;

        args.setup = &work->setup;
        args.slotData = work->slot;
        args.flag = 0;
        GAME_EVENT_CallEvent(event, GAME_EVENT_CreateOverlayEvent(gameSys, (u32)ov008_id, EVENT_BATTLE_REC_SAVE_Start, &args));
        (*state)++;
        break;
    }
    case 5:
        BTL_SETUP_FreeSlots(&work->setup);
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSys));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSys));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSys, work->gameData, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSys));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}

/*
 * Creates the IR battle task: allocates it with IRC_BATTLE_TASK_Main as its
 * callback, picks the formation slot for battle kinds 4..23 (four kinds per
 * rule, the first matching case wins through IRC_BATTLE_TASK_SetFormationOnce), runs the
 * matching setup builder and returns the event.
 */
struct GameEvent *IRC_BATTLE_TASK_Create(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request)
{
    int formation = 0x29;
    struct GameEvent *event = GAME_EVENT_Create(gameSys, 0, IRC_BATTLE_TASK_Main, 0xFC);
    IrcBattleTaskWork *work = func_020124E8(event);
    struct BattleSetupParam *setup;
    void *sysData;

    work->gameSys = gameSys;
    work->gameData = gameData;
    work->slot = &request->slot;
    setup = &work->setup;
    switch (kind) {
    case 5:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 0);
    case 4:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 2);
    case 7:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 1);
    case 6:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 3);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommSingle(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 9:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 4);
    case 8:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 6);
    case 11:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 5);
    case 10:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 7);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommDouble(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 13:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 8);
    case 12:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 10);
    case 15:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 9);
    case 14:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 11);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommTriple(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 17:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 12);
    case 16:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 14);
    case 19:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 13);
    case 18:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 15);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommRotation(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 21:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 16);
    case 20:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 18);
    case 23:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 17);
    case 22:
        IRC_BATTLE_TASK_SetFormationOnce(&formation, 19);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommMulti(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, request->multiTeam, 4);
        break;
    default:
        SAVEDATA_PanicFail((const char *)d_0217277C, 0, (const char *)d_0217277C);
        return 0;
    }
    BTL_SETUP_SetParty(setup, request->party, 0);
    BTL_SETUP_ApplyRegulation(setup, request->regulation, 4);
    setup->bgmBattle = request->bgmBattle;
    work->slot->formation = formation;
    work->slot->flag = 0;
    BTL_SETUP_AllocRecordBuffer(setup, 1);
    return event;
}

/*
 * Stores value into *formation only while it still holds the unset
 * sentinel 0x29, so the first call wins.
 */
void IRC_BATTLE_TASK_SetFormationOnce(int *formation, int value)
{
    if (*formation == 0x29)
        *formation = value;
}

/* Four empty leaves (unused callback slots). */
void IRC_BATTLE_TASK_Empty0(void)
{
}

void IRC_BATTLE_TASK_Empty1(void)
{
}

void IRC_BATTLE_TASK_Empty2(void)
{
}

void IRC_BATTLE_TASK_Empty3(void)
{
}
