/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B95E8, func_021B9614, func_021B9A14, func_021B9AA0, func_021B9BD8, func_021B9C34, func_021B9C80, func_021B9CA4
 * address:  0x021B95A0
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_020457B0  0x020457B0  arm
 *   PROCSYS_Create  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_02045808 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_02012934 0x02012934 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0201293C 0x0201293C thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   POKERUS_TryInfectParty 0x0201B038 thumb
 *   POKERUS_SpreadParty 0x0201B170 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02008500 0x02008500 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007698 0x02007698 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0202F190 0x0202F190 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   PROCSYS_Push 0x02031348 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0216C0A4 0x0216C0A4 thumb ov010
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_021B9D04 0x021B9D04 thumb ov092
 *   func_0201A98C 0x0201A98C thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_020074D8 0x020074D8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   data_0220BAB0 0x0220BAB0 data a4 ov207
 *   data_021F5580 0x021F5580 data a4 ov194
 *   data_02208C40 0x02208C40 data a4 ov195
 *   ov207_id 0x000000CF data a1
 *   ov194_id 0x000000C2 data a1
 *   ov195_id 0x000000C3 data a1
 *   data_021B9DC0 0x021B9DC0 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B9D44 0x021B9D44 data a1
 *   d_021B9D6E 0x021B9D6E data ov092 a2
 *   d_021B9D58 0x021B9D58 data ov092 a2
 *   d_021B9D4D 0x021B9D4D data ov092 a1
 *   POKE_TOOL_SetStatusCondition  0x02017F9C  thumb
 *   func_0216E62C  0x0216E62C  thumb  ov010
 *   func_02048F60 0x02048F60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

/* Heap created for the whole after-battle processing; freed in the exit step. */
#define EVENT_BATTLE_RETURN_HEAP_ID 0x52

/* Parameter ids of the get/set party-value accessors. */
#define MON_PARAM_SPECIES 5
#define MON_PARAM_HELD_ITEM 6
#define MON_PARAM_ABILITY 0xa
#define MON_PARAM_NICKNAME 115
#define MON_PARAM_ORIGINAL_TRAINER_NAME 141
#define MON_PARAM_LEVEL 0x9e
#define MON_PARAM_SPECIES_OR_EGG 0xab

#define SPECIES_EGG 0x28a
#define SPECIES_SHAYMIN 0x1ec
#define ABILITY_NATURAL_CURE 0x1e
#define ABILITY_PICKUP 0x35
#define ABILITY_HONEY_GATHER 0x76
#define ITEM_HONEY 0x5e
#define EVENT_FLAG_BOX_NOTICE_SEEN 0x96d
#define RECORD_NICKNAMED_COUNT 30
#define MAX_NICKNAME_LENGTH 10
#define BGM_FADE_FRAMES 30
#define BURMY_FORM_ARCHIVE 0x98
#define LINE_OF_HEAP_ALLOC 0x1ca

/* Overlay ids of the sub-screens this step machine starts. */
extern const u8 ov207_id[], ov194_id[], ov195_id[];

/* Values of BattleReturnParam.outcome that matter here. */
enum {
    BATTLE_OUTCOME_WIN = 1,
    BATTLE_OUTCOME_DRAW = 3,
    BATTLE_OUTCOME_CAUGHT = 5
};

/* Values of BattleReturnParam.competitor: 0 and 1 are wild and trainer fights. */
#define COMPETITOR_LAST_NORMAL 1

struct ProcObj;
struct ProcSys;
struct SubProcTable;
struct NameInArgs;
struct GameData;
struct PokeParty;
struct PokemonParam;
struct BoxPokemon;
struct BoxManager;
struct MyStatus;
struct MiscSave;
struct SaveControl;
struct ZukanSave;
struct EventWork;
struct PlayerWork;
struct RecordBlock;
struct Strbuf;
struct MsgBank;
struct EvolutionRequest;

/*
 * The battle parameter object (BattleSetupParam, btl_setup_types.h) seen from
 * the result side. Its header names are inferred for offsets past 0x84; the
 * names here come from how this file reads the battle results, so the header
 * should take these (moneyDelta, outcome, capturedIndex, participated).
 */
struct BattleField {
    s32 bgType;
    s32 bgAttr;
    u8 weather;
    u8 season;
    u16 zoneId;
    u8 hour;
    u8 minute;
    u8 pad0e[2];
};

struct BattleReturnParam {
    u32 competitor;
    u8 pad04[4];
    struct BattleField field;
    u8 pad18[0xc];
    struct PokeParty *playerParty;
    struct PokeParty *opponentParty;
    u8 pad2c[0x5c];
    s32 moneyDelta;
    u32 outcome;
    u8 capturedIndex;
    u8 pad91[0x31];
    u8 participated[6];
};

/* Arguments of the event: the game data and the finished battle's parameters. */
struct EventBattleReturnArgs {
    struct GameData *gameData;
    struct BattleReturnParam *battleParam;
};

/* Arguments of the catch registration screen (overlay 207). */
struct CatchRegistrationArgs {
    u32 wasAlreadyCaught;
    struct PokemonParam *mon;
    u32 dexMode;
    struct Strbuf *boxFullMsg;
    struct BoxManager *boxManager;
    u32 boxNo;
    struct GameData *gameData;
    u32 wantsNickname;
};

/* Work of the step machine, allocated with the proc (0x4c bytes). */
struct EventBattleReturnWork {
    struct NameInArgs *nameInArgs;
    struct Strbuf *nameBuf;
    struct PokemonParam *caughtMon;
    struct CatchRegistrationArgs catchArgs;
    struct Strbuf *boxFullMsg;
    u32 boxNo;
    struct EvolutionRequest *evolutionRequest;
    u16 scanIndex;
    u16 levelUpMask;
    u16 heapId;
    u8 pad3e[2];
    struct ProcSys *procSys;
    u32 bgmSettled;
    u32 bgmFadeStarted;
};

/* Parameter block of the evolution screen (overlay 195), same layout as the one in the trade code. */
struct EvolutionRequest {
    struct GameData *gameData;
    struct PokeParty *party;
    u16 targetSpecies;
    u8 partySlot;
    u8 evolveCondition;
    u32 fromTrade;
    u32 fromField;
};

/* One 0x24-byte record per battle background of the Burmy form table. */
struct BurmyFormRecord {
    u8 header[0x13];
    u8 formByAttr[0x11];
};

extern void func_0203064C(u32 parentHeapId, u32 heapId, u32 size);
extern void *func_0203159C(struct ProcObj *proc, u32 size, u32 heapId);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern struct ProcSys *PROCSYS_Create(int heapId);
extern void func_0203133C(struct ProcSys *procSys);
extern void func_02045808(struct Strbuf *strbuf);
extern void func_020315D4(struct ProcObj *proc);
extern void func_020306F0(unsigned int heapId);
extern u32 PROCSYS_Main(struct ProcSys *procSys);
extern struct PokeParty *func_02012934(const struct GameData *gameData);
extern struct MyStatus *func_02012944(const struct GameData *gameData);
extern struct ZukanSave *func_0200CA1C(const struct GameData *gameData);
extern struct BoxManager *func_0201293C(const struct GameData *gameData);
extern void func_0201AC2C(const struct PokeParty *src, struct PokeParty *dst);
extern void POKERUS_TryInfectParty(struct PokeParty *party);
extern void POKERUS_SpreadParty(struct PokeParty *party);
extern struct MiscSave *func_02012F08(const struct GameData *gameData);
extern u32 func_0200C278(struct MiscSave *misc, u32 amount);
extern u32 func_0200C29C(struct MiscSave *misc, u32 amount);
extern struct PokemonParam *func_0201AB28(struct PokeParty *party, u32 index);
extern void func_02008500(struct MyStatus *status, struct Strbuf *name);
extern void func_02017E40(struct PokemonParam *mon, u32 paramId, u32 value);
extern u32 func_0201AA18(struct PokeParty *party);
extern u32 func_0201AA14(struct PokeParty *party);
extern u32 func_02007698(struct BoxManager *boxManager);
extern int func_020076D0(struct BoxManager *boxManager, int *box, int *slot);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct MsgBank *bank);
extern struct PlayerWork *func_020127A4(const struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *player);
extern u32 func_02013E4C(u32 zoneId);
extern void func_0202F190(struct PokemonParam *mon, u32 mode, const struct MyStatus *trainer, u32 placeNameId, u16 heapId);
extern u32 func_0200CA38(struct ZukanSave *zukan);
extern u32 func_02017E1C(struct PokemonParam *mon, u32 paramId, u32 unused);
extern u32 func_0200CED4(struct ZukanSave *zukan, u16 species);
extern void func_0200CFA0(struct ZukanSave *zukan, struct PokemonParam *mon);
extern void func_0200CDE0(struct ZukanSave *zukan, struct PokemonParam *mon);
extern void PROCSYS_Push(struct ProcSys *procSys, u32 overlayId, const struct SubProcTable *procTable, void *args);
extern struct SaveControl *func_02012EBC(const struct GameData *gameData);
extern struct MiscSave *func_0200C0F0(struct SaveControl *saveControl);
extern struct NameInArgs *func_0216C0A4(unsigned short heapId, struct PokemonParam *mon, int maxLength, int mode, struct Strbuf *boxFullMsg, struct BoxManager *boxManager, int boxNo, struct MiscSave *misc);
extern int func_0216C0E4(struct NameInArgs *args);
extern void func_0216C0D4(struct NameInArgs *args, struct Strbuf *dst);
extern struct RecordBlock *func_02012F2C(const struct GameData *gameData);
extern u32 func_02008DF0(struct RecordBlock *record, int index);
extern int func_0216C0C0(struct NameInArgs *args);
extern void func_021B9D04(struct PokemonParam *mon);
extern u32 func_0201A98C(struct PokeParty *party, const struct PokemonParam *mon);
extern struct BoxPokemon *func_020185F0(struct PokemonParam *mon);
extern int func_020074D8(struct BoxManager *boxManager, const struct BoxPokemon *mon);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u8 func_02012984(const struct GameData *gameData);
extern u16 func_0201B2B0(struct PokeParty *party, struct PokemonParam *mon, u32 mode, u32 zoneId, u8 season, u32 *method, u16 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *memory);
extern u32 func_020056EC(u32 range);
extern void POKE_TOOL_SetStatusCondition(struct PokemonParam *mon, u32 status);
extern void func_0216E62C(struct GameData *gameData, struct PokemonParam *mon, int burmyForm);
extern void *func_02048F60(u32 archiveId, u32 member, u32 heapId);

int func_021B95A0(struct ProcObj *proc);
int func_021B95E8(struct ProcObj *proc, u32 seq, u32 pwk, struct EventBattleReturnWork *work);
int func_021B9614(struct ProcObj *proc, u32 *seq, struct EventBattleReturnArgs *args, struct EventBattleReturnWork *work);
void func_021B9A14(struct EventBattleReturnWork *work, struct EventBattleReturnArgs *args);
void func_021B9AA0(struct PokeParty *party);
void func_021B9BD8(struct PokeParty *party);
void func_021B9C34(struct EventBattleReturnArgs *args, struct PokeParty *party, int burmyForm);
u32 func_021B9C80(const struct BattleField *field, u32 heapId);
void func_021B9CA4(struct EventBattleReturnArgs *args, struct PokeParty *party);

extern const struct SubProcTable data_0220BAB0, data_021F5580, data_02208C40;
extern const u8 data_021B9DC0[];
extern const u8 d_021B9D44[];
extern const u16 d_021B9D6E[];
extern const u16 d_021B9D58[];
extern const u8 d_021B9D4D[];

/* Step machine init: heap, work, name buffer and sub-proc system. */
int func_021B95A0(struct ProcObj *proc)
{
    struct EventBattleReturnWork *work;

    func_0203064C(1, EVENT_BATTLE_RETURN_HEAP_ID, 0x1000);
    work = func_0203159C(proc, 0x4c, EVENT_BATTLE_RETURN_HEAP_ID);
    work->nameBuf = func_020457B0(0x20, EVENT_BATTLE_RETURN_HEAP_ID);
    work->nameInArgs = 0;
    work->caughtMon = 0;
    work->boxFullMsg = 0;
    work->boxNo = 0;
    work->evolutionRequest = 0;
    work->heapId = EVENT_BATTLE_RETURN_HEAP_ID;
    work->procSys = PROCSYS_Create(work->heapId);
    work->bgmSettled = 0;
    work->bgmFadeStarted = 0;
    return 1;
}

/* Step machine exit: frees the sub-proc system, both strings, the work and the heap. */
int func_021B95E8(struct ProcObj *proc, u32 seq, u32 pwk, struct EventBattleReturnWork *work)
{
    func_0203133C(work->procSys);
    if (work->boxFullMsg) func_02045808(work->boxFullMsg);
    func_02045808(work->nameBuf);
    func_020315D4(proc);
    func_020306F0(EVENT_BATTLE_RETURN_HEAP_ID);
    return 1;
}

/*
 * Step machine main. Steps: 0 applies the battle results to the party and, for
 * a caught Pokemon, starts the catch registration screen; 1 starts the
 * nickname screen if the player wants one; 2 stores the nickname; 3 puts the
 * caught Pokemon into the party or a box; 4 scans the members that gained a
 * level for an evolution; 5 waits for the evolution screen; 6 ends.
 *
 * note: 2026-10-05 matched. Loader order (context, id, descriptor, argument). Closing forms: case 1, 2 and 5 are
 *   `if (busy != 1) { body; break; } return 0;` (return block after the body); `ok = 0; if (f == 1) ok = 1;`;
 *   `if (flag) x = 0; else x = 1;`; `case 6: default: return 1;`; the case 4 tail `r68 = 1; break;` written in
 *   the guarded arm and again after it (cross-jumped copy leaves the b stub); species and slot as u16 locals,
 *   box/bslot declared first; the source record pointer s is not const. Case 4 mask and slot use a two-field view.
 */
int func_021B9614(struct ProcObj *proc, u32 *seq, struct EventBattleReturnArgs *args, struct EventBattleReturnWork *work)
{
    u32 busy;
    struct PokeParty *party;
    int box, boxSlot;
    u32 method;
    struct PokemonParam *mon;
    struct MyStatus *myStatus;
    struct ZukanSave *zukan;
    struct BoxManager *boxManager;
    struct MsgBank *msgBank;
    struct MiscSave *miscSave;
    int moneyDelta, partyCount, msgIndex;
    int isNewSpecies, wantsNickname;
    unsigned long dexMode;
    u16 species;
    u16 slot;
    struct EvolutionRequest *evolutionRequest;
    busy = PROCSYS_Main(work->procSys);
    if (busy == 1) return 0;
    switch (*seq) {
    case 0:
        party = func_02012934(args->gameData);
        myStatus = func_02012944(args->gameData);
        zukan = func_0200CA1C(args->gameData);
        boxManager = func_0201293C(args->gameData);
        work->scanIndex = 0;
        work->levelUpMask = 0;
        if (args->battleParam->competitor <= COMPETITOR_LAST_NORMAL) {
            func_021B9A14(work, args);
            func_0201AC2C(args->battleParam->playerParty, party);
            POKERUS_TryInfectParty(party);
            POKERUS_SpreadParty(party);
            if (args->battleParam->outcome == BATTLE_OUTCOME_WIN) func_021B9AA0(party);
            func_021B9C34(args, party, func_021B9C80(&args->battleParam->field, work->heapId));
            func_021B9CA4(args, party);
            moneyDelta = args->battleParam->moneyDelta;
            if (moneyDelta > 0) func_0200C278(func_02012F08(args->gameData), moneyDelta);
            else if (moneyDelta < 0) func_0200C29C(func_02012F08(args->gameData), -moneyDelta);
        }
        func_021B9BD8(party);
        if (args->battleParam->outcome == BATTLE_OUTCOME_CAUGHT) {
            work->caughtMon = func_0201AB28(args->battleParam->opponentParty, args->battleParam->capturedIndex);
            func_02008500(myStatus, work->nameBuf);
            func_02017E40(work->caughtMon, MON_PARAM_ORIGINAL_TRAINER_NAME, (u32)work->nameBuf);
            partyCount = (int)func_0201AA18(party);
            if (partyCount >= (int)func_0201AA14(party)) {
                box = func_02007698(boxManager); boxSlot = 0;
                func_020076D0(boxManager, &box, &boxSlot);
                work->boxNo = box;
                msgBank = func_02045B38(0, 2, 234, EVENT_BATTLE_RETURN_HEAP_ID);
                msgIndex = func_020142E8(func_0201296C(args->gameData), EVENT_FLAG_BOX_NOTICE_SEEN) ? 177 : 176;
                work->boxFullMsg = func_02045EC0(msgBank, msgIndex);
                func_02045C04(msgBank);
            }
            func_0202F190(work->caughtMon, 0, myStatus, func_02013E4C(func_02012AC8(func_020127A4(args->gameData))), work->heapId);
            isNewSpecies = 0;
            dexMode = func_0200CA38(zukan);
            if (func_0200CED4(zukan, func_02017E1C(work->caughtMon, MON_PARAM_SPECIES, 0)) == 0) isNewSpecies = 1;
            func_0200CFA0(zukan, work->caughtMon);
            func_0200CDE0(zukan, work->caughtMon);
            work->catchArgs.dexMode = dexMode;
            work->catchArgs.mon = work->caughtMon;
            work->catchArgs.boxFullMsg = work->boxFullMsg;
            work->catchArgs.boxManager = boxManager;
            work->catchArgs.boxNo = work->boxNo;
            work->catchArgs.gameData = args->gameData;
            if (isNewSpecies) work->catchArgs.wasAlreadyCaught = 0; else work->catchArgs.wasAlreadyCaught = 1;
            PROCSYS_Push(work->procSys, (u32)ov207_id, &data_0220BAB0, &work->catchArgs);
            ++*seq;
        } else *seq = 4;
        break;
    case 1:
        if (busy != 1) {
        boxManager = func_0201293C(args->gameData);
        wantsNickname = 0;
        if (work->catchArgs.wantsNickname == 1) wantsNickname = 1;
        if (wantsNickname) {
            miscSave = func_0200C0F0(func_02012EBC(args->gameData));
            work->nameInArgs = func_0216C0A4(work->heapId, work->caughtMon, MAX_NICKNAME_LENGTH, 0, work->boxFullMsg, boxManager, work->boxNo, miscSave);
            PROCSYS_Push(work->procSys, (u32)ov194_id, &data_021F5580, work->nameInArgs);
            ++*seq;
        } else *seq = 3;
        break;
        }
        return 0;
    case 2:
        if (busy != 1) {
        if (!func_0216C0E4(work->nameInArgs)) {
            func_0216C0D4(work->nameInArgs, work->nameBuf);
            func_02017E40(work->caughtMon, MON_PARAM_NICKNAME, (u32)work->nameBuf);
            func_02008DF0(func_02012F2C(args->gameData), RECORD_NICKNAMED_COUNT);
        }
        func_0216C0C0(work->nameInArgs);
        work->nameInArgs = 0;
        ++*seq;
        break;
        }
        return 0;
    case 3:
        party = func_02012934(args->gameData);
        func_021B9D04(work->caughtMon);
        if (!work->boxFullMsg) func_0201A98C(party, work->caughtMon);
        else {
            boxManager = func_0201293C(args->gameData);
            func_020074D8(boxManager, func_020185F0(work->caughtMon));
        }
        ++*seq;
        break;
    case 4: {
        struct PokeParty *scanParty;
        if (!work->bgmSettled) {
            if (args->battleParam->outcome == BATTLE_OUTCOME_CAUGHT && work->levelUpMask) {
                if (!work->bgmFadeStarted) { GFL_USE_FadeOutBgm(BGM_FADE_FRAMES); work->bgmFadeStarted = 1; break; }
                if (GFL_USE_IsBgmFading()) break;
                GFL_USE_CancelChangeAndStopBgm();
                work->bgmSettled = 1;
                break;
            }
            work->bgmSettled = 1;
            break;
        }
        if (work->levelUpMask) {
            species = 0;
            scanParty = func_02012934(args->gameData);
            *seq = 6;
            while (work->levelUpMask) {
                if (work->levelUpMask & 1) {
                    mon = func_0201AB28(scanParty, work->scanIndex);
                    species = func_0201B2B0(scanParty, mon, 0, args->battleParam->field.zoneId, func_02012984(args->gameData), &method, work->heapId);
                    slot = work->scanIndex;
                }
                work->levelUpMask = work->levelUpMask >> 1;
                work->scanIndex++;
                if (species) {
                    evolutionRequest = func_02030734(work->heapId, 20, 0, (const char *)data_021B9DC0, LINE_OF_HEAP_ALLOC);
                    evolutionRequest->gameData = args->gameData; evolutionRequest->party = scanParty; evolutionRequest->targetSpecies = species; evolutionRequest->partySlot = slot; evolutionRequest->evolveCondition = method; evolutionRequest->fromTrade = 0; evolutionRequest->fromField = 1;
                    work->evolutionRequest = evolutionRequest;
                    PROCSYS_Push(work->procSys, (u32)ov195_id, &data_02208C40, evolutionRequest);
                    *seq = 5;
                    break;
                }
            }
        } else *seq = 6;
        break;
    }
    case 5:
        if (busy != 1) {
        func_020307B0(work->evolutionRequest);
        work->evolutionRequest = 0;
        if (work->levelUpMask) *seq = 4;
        else ++*seq;
        break;
        }
        return 0;
    case 6:
    default:
        return 1;
    }
    return 0;
}

/* Sets bit i of levelUpMask for each member whose level is higher after the battle. */
void func_021B9A14(struct EventBattleReturnWork *work, struct EventBattleReturnArgs *args)
{
    struct BattleReturnParam *battleParam = args->battleParam;
    struct PokeParty *partyBefore;
    int count;
    int i;
    u16 *mask;

    if (battleParam->outcome == BATTLE_OUTCOME_WIN || battleParam->outcome == BATTLE_OUTCOME_DRAW || battleParam->outcome == BATTLE_OUTCOME_CAUGHT) {
        switch (battleParam->competitor) {
        case 0:
        case 1:
            partyBefore = func_02012934(args->gameData);
            count = func_0201AA18(partyBefore);
            i = 0;
            if (count > 0) {
                mask = &work->levelUpMask;
                do {
                    struct PokemonParam *monBefore = func_0201AB28(partyBefore, i);
                    struct PokemonParam *monAfter = func_0201AB28(args->battleParam->playerParty, i);
                    u32 levelBefore = func_02017E1C(monBefore, MON_PARAM_LEVEL, 0);
                    u32 levelAfter = func_02017E1C(monAfter, MON_PARAM_LEVEL, 0);
                    if (levelBefore < levelAfter) {
                        *mask |= (u16)(1 << i);
                    }
                    i++;
                } while (i < count);
            }
            break;
        }
    }
}

/* Pickup and Honey Gather: members holding nothing may find an item after the battle. */
void func_021B9AA0(struct PokeParty *party)
{
    int i;
    struct PokemonParam *mon;
    u16 species,item;
    int ability;
    int roll;
    int j;
    u8 levelTier;
    int levelCeil;
    int chanceIndex;
    for (i=0;i<(int)func_0201AA18(party);i++) {
        mon = func_0201AB28(party,i);
        species = func_02017E1C(mon,MON_PARAM_SPECIES_OR_EGG,0);
        item = func_02017E1C(mon,MON_PARAM_HELD_ITEM,0);
        ability = (u8)func_02017E1C(mon,MON_PARAM_ABILITY,0);
        if (ability == ABILITY_PICKUP && species != 0 && species != SPECIES_EGG && item == 0 && func_020056EC(10) == 0) {
            roll = func_020056EC(100);
            levelTier = (func_02017E1C(mon,MON_PARAM_LEVEL,0)-1)/10u;
            if (levelTier >= 10) levelTier=9;
            for (j=0;j<9;j++) {
                if (d_021B9D44[j] > roll) {
                    func_02017E40(mon,MON_PARAM_HELD_ITEM,d_021B9D6E[levelTier+j]);
                    break;
                } else if (roll >= 98 && roll <= 99) {
                    func_02017E40(mon,MON_PARAM_HELD_ITEM,d_021B9D58[levelTier+(99-roll)]);
                    break;
                }
            }
        }
        if (ability == ABILITY_HONEY_GATHER && species != 0 && species != SPECIES_EGG && item == 0) {
            chanceIndex=0;
            levelCeil=10;
            ability=(u8)func_02017E1C(mon,MON_PARAM_LEVEL,0);
            while (levelCeil < ability) {
                levelCeil+=10;
                chanceIndex++;
            }
            if (func_020056EC(100) < d_021B9D4D[chanceIndex]) func_02017E40(mon,MON_PARAM_HELD_ITEM,ITEM_HONEY);
        }
    }
}

/* Natural Cure: clears the status of every member that has the ability. */
void func_021B9BD8(struct PokeParty *party)
{
    int i;
    struct PokemonParam *mon;
    u16 species;
    u8 ability;

    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        species = func_02017E1C(mon, MON_PARAM_SPECIES_OR_EGG, 0);
        ability = func_02017E1C(mon, MON_PARAM_ABILITY, 0);
        if (ability == ABILITY_NATURAL_CURE && species != 0 && species != SPECIES_EGG) {
            POKE_TOOL_SetStatusCondition(mon, 0);
        }
    }
}

/* Applies the Burmy form for the battle background to every member that took part. */
void func_021B9C34(struct EventBattleReturnArgs *args, struct PokeParty *party, int burmyForm)
{
    int i;

    if (args->battleParam->competitor - 2 > 1) {
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (args->battleParam->participated[i] != 0) {
                func_0216E62C(args->gameData, func_0201AB28(party, i), burmyForm);
            }
        }
    }
}

/* Reads the Burmy form of a battle background from its archive table. */
u32 func_021B9C80(const struct BattleField *field, u32 heapId)
{
    struct BurmyFormRecord *table;
    u32 form;
    struct BurmyFormRecord *record;
    table = func_02048F60(BURMY_FORM_ARCHIVE, 0, heapId);
    record = &table[field->bgType];
    form = record->formByAttr[field->bgAttr];
    func_020307B0(table);
    return form;
}

/* Registers the form of each participating Shaymin in the Pokedex. */
void func_021B9CA4(struct EventBattleReturnArgs *args, struct PokeParty *party)
{
    int i;
    struct PokemonParam *mon;
    u32 competitor;

    competitor = args->battleParam->competitor;
    switch (competitor) {
    case 0:
    case 1:
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (args->battleParam->participated[i] != 0) {
                mon = func_0201AB28(party, i);
                if (func_02017E1C(mon, MON_PARAM_SPECIES, 0) == SPECIES_SHAYMIN) {
                    func_0200CFA0(func_0200CA1C(args->gameData), mon);
                }
            }
        }
        break;
    }
}
