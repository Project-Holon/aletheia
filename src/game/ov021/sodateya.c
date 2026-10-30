/*
 * file:     sodateya.c
 * unit:     yes
 * function: SODATEYA_Create, SODATEYA_Delete, SODATEYA_DepositPokemon, SODATEYA_PrepareDeposit, SODATEYA_RevertShaymin, SODATEYA_WithdrawPokemon, SODATEYA_RegisterCaughtIfNew, SODATEYA_ReceiveEgg, SODATEYA_DeclineEgg, SODATEYA_AddStep, SODATEYA_SetEggFlag, SODATEYA_ClearEggFlag, SODATEYA_HasEgg, SODATEYA_GetPokemonCount, SODATEYA_GetCurrentLevel, SODATEYA_GetLevelsGained, SODATEYA_GetWithdrawCost, SODATEYA_GetCompatibility, SODATEYA_GetPokemon, SODATEYA_AddExpSaturated, SODATEYA_GrantExp, SODATEYA_LearnMove, SODATEYA_MonKnowsMove, SODATEYA_CompactSlots, SODATEYA_CalcCompatibility, SODATEYA_CalcCompatibilityScore, SODATEYA_UpdateStepCounter, SODATEYA_CreateEggMon, SODATEYA_SyncPartyAfterDeposit, SODATEYA_BuildEgg, SODATEYA_SortParentsByGender, SODATEYA_PutDittoSecond, SODATEYA_SwapParents, SODATEYA_InitEgg, SODATEYA_SetBaseSpecies, SODATEYA_RollNidoranSpecies, SODATEYA_RollVolbeatSpecies, SODATEYA_ApplyPhioneRule, SODATEYA_ApplyIncenseBabyRule, SODATEYA_GetSpeciesParent, SODATEYA_ResetEggForm, SODATEYA_InheritFormShellos, SODATEYA_InheritFormBurmy, SODATEYA_InheritFormBasculin, SODATEYA_GetFormParent, SODATEYA_RollNature, SODATEYA_ApplyEverstoneRule, SODATEYA_RollAbilitySlot, SODATEYA_RollDittoAbilitySlot, SODATEYA_SetAbilityFromSlot, SODATEYA_SetBaseFriendship, SODATEYA_ApplyPowerItemRule, SODATEYA_RollRandomIvInheritance, SODATEYA_CopyInheritedIvs, SODATEYA_SetOtId, SODATEYA_RollPersonalRnd, SODATEYA_ApplyMasudaMethod, SODATEYA_RollRandomU32, SODATEYA_AddLevelUpMoves, SODATEYA_AddEggMoves, SODATEYA_AddSharedMoves, SODATEYA_AddTmMoves, SODATEYA_AddVoltTackle, SODATEYA_AddMove, SODATEYA_SetupEggMon, SODATEYA_CanLearnTm, SODATEYA_GetBaseSpecies, SODATEYA_GetAbilitySlot
 * address:  0x021C31D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the day care work functions 021C31D4..021C360C from fld3d_ci.c (lane FXC2: __FILE__ sodateya.c on 021C31D4; the functions before it use Fld3dCi and the fld3d_ci.c string and data pool).
 * Split from fldeff_ripple.c at 0x021C3670 (lane FXC, CL128: day care breeding code; __FILE__ sodateya.c on 0x021C31D4).
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   sSodateyaHasMoveSlotIds     0x021DA8D8  data  ov021  a4
 *   DAYCARE_IsSlotInUse  0x0200BCA8  thumb
 *   DAYCARE_SwapSlots  0x0200BCEC  thumb
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   DAYCARE_GetInUseCount  0x0200BCB8  thumb
 *   SODATEYA_GetCompatibility  0x021C34C4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   DAYCARE_GetSlotMon  0x0200BC2C  thumb
 *   GAME_DATA_GetPerapVoiceSave  0x02012F98  thumb
 *   PERAPVOICE_ClearIfNoChatot  0x02007C34  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   sSodateyaIncenseBabyTable     0x021DA960  data  ov021  a4
 *   GFL_USE_GetRandomBelow  0x02005728  thumb  ov021
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   sSodateyaPowerItemIds     0x021DA930  data  ov021  a4
 *   sSodateyaParentIvIds     0x021DA918  data  ov021  a4
 *   MYSTATUS_GetId  0x02008530  thumb
 *   POKE_TOOL_IsShinyOtIdPersonality  0x02017ED8  thumb
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sSodateyaEggMoveSlotIds     0x021DA908  data  ov021  a4
 *   sSodateyaSharedMoveSlotIds     0x021DA8F8  data  ov021  a4
 *   FILE_UTIL_GetMachineMove  0x020212B0  thumb
 *   sSodateyaTmMoveSlotIds     0x021DA8E8  data  ov021  a4
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   MYSTATUS_CreateNameStrbuf  0x02008510  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   POKE_TOOL_RecoverAllPP  0x02018198  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *   gSpeciesNameBank     0x020A7370  data
 *   sSodateyaEggIvIds     0x021DA948  data  ov021  a4
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   d_021DE458     0x021DE458  data  ov021
 *   DAYCARE_SetSlotMon  0x0200BC4C  thumb
 *   POKEPARTY_RemoveMember  0x0201A9C8  thumb
 *   SODATEYA_SyncPartyAfterDeposit  0x021C38DC  thumb  ov021
 *   DAYCARE_GetSlotSteps  0x0200BCD8  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   DAYCARE_ClearSlot  0x0200BC88  thumb
 *   SODATEYA_CompactSlots  0x021C36B0  thumb  ov021
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   DAYCARE_GetEggReady  0x0200BCA0  thumb
 *   GAME_BEACON_SEARCH_SetSymbolMapEnter  0x0216556C  thumb  ov010
 *   SODATEYA_CreateEggMon  0x021C3898  thumb  ov021
 *   DAYCARE_ClearEggReady  0x0200BC20  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FORMCHANGE_UpdateSeasonForms  0x0216AAE4  thumb  ov010
 *   DAYCARE_AddSteps  0x0200BD48  thumb
 *   SODATEYA_UpdateStepCounter  0x021C385C  thumb  ov021
 *   DAYCARE_SetEggReady  0x0200BC10  thumb
 *   POKE_TOOL_CalcLevelFromExp  0x0201850C  thumb
 *   SODATEYA_CalcCompatibility  0x021C36EC  thumb  ov021
 *   POKE_TOOL_GetExpForLevel  0x02018584  thumb
 *   SODATEYA_MonKnowsMove  0x021C3670  thumb  ov021
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   d_021DA8C8     0x021DA8C8  data  ov021  a4
 *   POKE_TOOL_ChangeForm  0x02017988  thumb  arm9
 *   ARC_TOOL_ReadMemberRange  0x02048F74  arm  arm9
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb  arm9
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb  arm9
 *   ZUKAN_SAVE_IsCaught  0x0200CED4  thumb  arm9
 *   GAME_DATA_GetEventWork  0x0201296C  thumb  arm9
 */
#include "../arm9/billboard_act_types.h"

/*
 * breeding code (sodateya.c); 0x021C457C..0x021C4788 are script and event
 * glue; the water ripple field effect proper starts at 0x021C47B4.
 */

struct PokemonParam;
struct PersonalData;
struct MyStatus;
struct FieldMap;
struct MsgBank;
struct StrBuf;

/* Mon data ids read and written through the Pokemon data accessors. */
enum {
    MON_DATA_SPECIES = 5,
    MON_DATA_HELD_ITEM = 6,
    MON_DATA_OT_ID = 7,
    MON_DATA_FRIENDSHIP = 9,
    MON_DATA_ABILITY = 0xA,
    MON_DATA_LANGUAGE = 0xC,
    MON_DATA_MOVE1 = 0x36,
    MON_DATA_MOVE2 = 0x37,
    MON_DATA_MOVE3 = 0x38,
    MON_DATA_MOVE4 = 0x39,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_GENDER = 0x6E,
    MON_DATA_FORM = 0x6F,
    MON_DATA_NATURE = 0x70,
    MON_DATA_NICKNAME = 0x73,
    MON_DATA_OT_NAME = 0x8D,
    MON_DATA_ABILITY_SET = 0xB2
};

/* Species and items the breeding rules test for. */
#define SPECIES_DITTO 0x84
#define SPECIES_NIDORAN_F 0x1D
#define SPECIES_VOLBEAT 0x139
#define SPECIES_ILLUMISE 0x13A
#define SPECIES_PHIONE 0x1E9
#define SPECIES_MANAPHY 0x1EA
#define SPECIES_PICHU 0xAC
#define SPECIES_BASCULIN 0x226
#define ITEM_EVERSTONE 0xE5
#define ITEM_LIGHT_BALL 0xEC
#define MOVE_VOLT_TACKLE 0x158

#define GENDER_MALE 0
#define GENDER_FEMALE 1
#define GENDER_NONE 2

/* Egg group 15 is "undiscovered": those Pokemon never breed. */
#define EGG_GROUP_UNDISCOVERED 0xF
#define PERSONAL_EGG_GROUP_1 0x18
#define PERSONAL_EGG_GROUP_2 0x19

/* Breeding compatibility scores. */
#define BREED_SCORE_LOW 0x14
#define BREED_SCORE_MID 0x32
#define BREED_SCORE_HIGH 0x46

#include "../types.h"
#include "../version.h"

#define DAYCARE_SLOT_COUNT 2
#define STEPS_PER_EGG_CHECK 0x10
#define SODATEYA_EGG_MET_PLACE 0xEA62
#define TM_ITEM_FIRST 0x148
#define TM_ITEM_LAST 0x272

/* Day care work (0x10 bytes, allocated by SODATEYA_Create). */
typedef struct SodateyaWork {
    u16 heapId;                           /* 0x00 */
    u16 pad02;
    struct FieldMap *fieldMap;            /* 0x04 */
    void *dayCare;                        /* 0x08 */
    u16 stepCount;                        /* 0x0C steps walked since the last egg check */
} SodateyaWork;

/* The offspring being rolled from two parents (0x8C bytes). */
typedef struct DayCareEgg {
    u32 species;                          /* 0x00 */
    u32 form;                             /* 0x04 */
    u32 level;                            /* 0x08 */
    u32 nature;                           /* 0x0C */
    u32 ability;                          /* 0x10 */
    u32 baseFriendship;                   /* 0x14 */
    u32 ivs[6];                           /* 0x18 */
    u32 otId;                             /* 0x30 */
    u32 personalRnd;                      /* 0x34 */
    u32 moveCount;                        /* 0x38 */
    u32 moves[4];                         /* 0x3C */
    u32 abilitySlot;                      /* 0x4C 0 or 1: the two normal abilities, 2: hidden */
    u32 natureFromFather;                 /* 0x50 */
    u32 natureFromMother;                 /* 0x54 */
    u32 fatherIvFlags[6];                 /* 0x58 IVs taken from the father */
    u32 motherIvFlags[6];                 /* 0x70 IVs taken from the mother */
    u32 inheritedIvCount;                 /* 0x88 */
} DayCareEgg;

/* The four move slots of a Pokemon, as mon data ids. */
typedef struct MoveSlotIdTable { u32 ids[4]; } MoveSlotIdTable;

/* The six IVs or the six power items, in HP, Atk, Def, SpAtk, SpDef, Speed order. */
typedef struct StatTable { u32 ids[6]; } StatTable;

/* A baby species, the incense that lets it hatch, and the species hatched without it. */
typedef struct IncenseBabyEntry {
    u32 babySpecies;
    u32 incenseItem;
    u32 adultSpecies;
} IncenseBabyEntry;

typedef struct IncenseBabyTable { IncenseBabyEntry entries[12]; } IncenseBabyTable;

/* Learnset entry; the pair 0xFFFF, 0xFFFF ends the list. */
typedef struct LearnsetEntry {
    u16 move;
    u16 level;
} LearnsetEntry;
struct PokemonParam;

#include "../arm9/poke_tool.h"
struct DaycareSave;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define DAYCARE_GetInUseCount DAYCARE_GetInUseCount_header
#endif
#include "../arm9/daycare.h"
#ifdef __MWERKS__
#undef DAYCARE_GetInUseCount
extern int DAYCARE_GetInUseCount(struct DaycareSave *);
#endif
#include "../arm9/gfl_use.h"
#include "../arm9/game_data.h"
#include "fieldmap.h"
#include "../arm9/gamesystem.h"
struct GameData;
struct PokemonParam;
#include "../arm9/perapvoice.h"
#include "../arm9/mi_memory.h"
struct PersonalData;
#include "../arm9/poke_personal.h"
#include "../arm9/mystatus.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define ARC_TOOL_LoadMember ARC_TOOL_LoadMember_header
#endif
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#undef ARC_TOOL_LoadMember
extern void * ARC_TOOL_LoadMember(u32, u32, u32);
#endif
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/file_util.h"
struct BoxPokemon;
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/msgdata.h"
#include "../arm9/save_event.h"
#include "../arm9/poke_tool_ext.h"
extern void *gSpeciesNameBank;

int SODATEYA_MonKnowsMove(void *mon, u32 move);
void SODATEYA_CompactSlots(void *dayCare);
int SODATEYA_CalcCompatibility(struct PokemonParam *monA, struct PokemonParam *monB);
int SODATEYA_CalcCompatibilityScore(struct PokemonParam *monA, struct PokemonParam *monB);
int SODATEYA_UpdateStepCounter(SodateyaWork *work);
void SODATEYA_CreateEggMon(SodateyaWork *work, struct PokemonParam *eggMon);
void SODATEYA_SyncPartyAfterDeposit(struct FieldMap *fieldMap, void *party);
void SODATEYA_BuildEgg(u16 heapId, struct MyStatus *myStatus, u32 metPlace, struct PokemonParam *father, struct PokemonParam *mother, struct PokemonParam *eggMon);
void SODATEYA_SortParentsByGender(struct PokemonParam **parents);
void SODATEYA_PutDittoSecond(struct PokemonParam **parents);
void SODATEYA_SwapParents(struct PokemonParam **parents);
int SODATEYA_InitEgg(DayCareEgg *egg);
void SODATEYA_SetBaseSpecies(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollNidoranSpecies(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollVolbeatSpecies(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyPhioneRule(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyIncenseBabyRule(struct PokemonParam **parents, DayCareEgg *egg);
struct PokemonParam *SODATEYA_GetSpeciesParent(struct PokemonParam **parents);
int SODATEYA_ResetEggForm(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_InheritFormShellos(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_InheritFormBurmy(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_InheritFormBasculin(struct PokemonParam **parents, DayCareEgg *egg);
struct PokemonParam *SODATEYA_GetFormParent(struct PokemonParam **parents);
void SODATEYA_RollNature(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyEverstoneRule(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollAbilitySlot(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_RollDittoAbilitySlot(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_SetAbilityFromSlot(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_SetBaseFriendship(DayCareEgg *egg, u32 heapId);
void SODATEYA_ApplyPowerItemRule(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollRandomIvInheritance(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_CopyInheritedIvs(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_SetOtId(struct MyStatus *myStatus, DayCareEgg *egg);
void SODATEYA_RollPersonalRnd(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyMasudaMethod(struct PokemonParam **parents, DayCareEgg *egg);
u32 SODATEYA_RollRandomU32(void);
void SODATEYA_AddLevelUpMoves(DayCareEgg *egg);
void SODATEYA_AddEggMoves(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_AddSharedMoves(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_AddTmMoves(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_AddVoltTackle(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_AddMove(DayCareEgg *egg, u32 move);
void SODATEYA_SetupEggMon(struct PokemonParam *mon, const DayCareEgg *egg, struct MyStatus *myStatus, u32 metPlace, u16 heapId);
int SODATEYA_CanLearnTm(u32 heapId, u32 species, u32 form, u32 tmItem);
u16 SODATEYA_GetBaseSpecies(u16 species);
u8 SODATEYA_GetAbilitySlot(u32 species, u32 form, u32 ability, u32 heapId);
extern const MoveSlotIdTable sSodateyaHasMoveSlotIds;
extern IncenseBabyTable sSodateyaIncenseBabyTable;
extern const StatTable sSodateyaPowerItemIds;
extern StatTable sSodateyaParentIvIds;
extern MoveSlotIdTable sSodateyaEggMoveSlotIds;
extern const MoveSlotIdTable sSodateyaSharedMoveSlotIds;
extern MoveSlotIdTable sSodateyaTmMoveSlotIds;
extern const StatTable sSodateyaEggIvIds;
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/zukan_save.h"
struct ZukanSave;
#include "../ov010/game_beacon_set.h"
#include "../ov010/formchange_season.h"
struct DaycareSlot;
struct EventWork;
#include "../arm9/zonedata.h"
SodateyaWork *SODATEYA_Create(u32 heapId, void *fieldMap, void *dayCare);
void SODATEYA_Delete(void *work);
void SODATEYA_DepositPokemon(SodateyaWork *work, void *party, u32 partyPos);
void SODATEYA_PrepareDeposit(void *mon);
void SODATEYA_RevertShaymin(void *mon);
void SODATEYA_WithdrawPokemon(SodateyaWork *work, u32 slot, void *party);
void SODATEYA_RegisterCaughtIfNew(SodateyaWork *work, void *mon);
void SODATEYA_ReceiveEgg(SodateyaWork *work, void *party);
void SODATEYA_DeclineEgg(SodateyaWork *work);
int SODATEYA_AddStep(SodateyaWork *work);
void SODATEYA_SetEggFlag(void *fieldMap);
void SODATEYA_ClearEggFlag(void *fieldMap);
int SODATEYA_HasEgg(void *work);
int SODATEYA_GetPokemonCount(SodateyaWork *work);
int SODATEYA_GetCurrentLevel(SodateyaWork *work, u32 slot);
int SODATEYA_GetLevelsGained(SodateyaWork *work, int slot);
int SODATEYA_GetWithdrawCost(SodateyaWork *work, int slot);
u8 SODATEYA_GetCompatibility(SodateyaWork *work);
void *SODATEYA_GetPokemon(SodateyaWork *work, u32 slot);
u32 SODATEYA_AddExpSaturated(u32 exp, u32 gain);
void SODATEYA_GrantExp(void *mon, u32 gain);
void SODATEYA_LearnMove(void *mon, u32 move);
extern char d_021DE458[];
extern const MoveSlotIdTable d_021DA8C8;

/* Source line the assertion text of the heap allocation names. */
/*
 * Allocates and initialises the 0x10-byte day care work.
 */
SodateyaWork *SODATEYA_Create(u32 heapId, void *fieldMap, void *dayCare)
{
    SodateyaWork *work = GFL_HEAP_Alloc(heapId, sizeof(*work), 0, d_021DE458, PM_SRC_LINE(0x6A, 0x66));
    work->heapId = heapId;
    work->fieldMap = fieldMap;
    work->dayCare = dayCare;
    work->stepCount = 0;
    return work;
}

/*
 * Tail-call thunk: forwards to GFL_HEAP_Free with no argument change.
 */
void SODATEYA_Delete(void *work)
{
    GFL_HEAP_Free(work);
}

/* Deposits the party member at partyPos in the day care when there is room. */
void SODATEYA_DepositPokemon(SodateyaWork *work, void *party, u32 partyPos)
{
    int count = DAYCARE_GetInUseCount(work->dayCare);
    struct PokemonParam *mon = POKEPARTY_GetMember(party, partyPos);
    if (count < 2) {
        SODATEYA_PrepareDeposit(mon);
        SODATEYA_RevertShaymin(mon);
        DAYCARE_SetSlotMon(work->dayCare, count, (const struct PokeParam *)mon);
        POKEPARTY_RemoveMember(party, partyPos);
        SODATEYA_SyncPartyAfterDeposit(work->fieldMap, party);
    }
}

/*
 * Tail-call thunk: forwards to POKE_TOOL_HealFull with no argument change.
 */
void SODATEYA_PrepareDeposit(void *mon)
{
    POKE_TOOL_HealFull(mon);
}

/* Reverts a Shaymin (species 0x1EC) to its first form. */
void SODATEYA_RevertShaymin(void *mon)
{
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x1EC)
        POKE_TOOL_ChangeForm(mon, 0);
}

/* Takes the pokemon of day care slot out into the party, with the experience it gained. */
void SODATEYA_WithdrawPokemon(SodateyaWork *work, u32 slot, void *party)
{
    struct PokemonParam *mon;
    if (DAYCARE_IsSlotInUse(work->dayCare, slot) == 1) {
        mon = (struct PokemonParam *)DAYCARE_GetSlotMon(work->dayCare, slot);
        SODATEYA_GrantExp(mon, DAYCARE_GetSlotSteps(work->dayCare, slot));
        SODATEYA_RegisterCaughtIfNew(work, mon);
        POKEPARTY_Add(party, mon);
        DAYCARE_ClearSlot(work->dayCare, slot);
        SODATEYA_CompactSlots(work->dayCare);
    }
}

/*
 * Returns the Pokemon's held item to the bag when it fits.
 */
void SODATEYA_RegisterCaughtIfNew(SodateyaWork *work, void *mon)
{
    void *bag = ZUKAN_SAVE_GetFromGameData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap)));
    if (ZUKAN_SAVE_IsCaught(bag, POKE_TOOL_GetPartyValue(mon, 5, 0)) == 0)
        ZUKAN_SAVE_RegisterCaught(bag, mon);
}

/* Takes the egg out of the day care into the party. */
void SODATEYA_ReceiveEgg(SodateyaWork *work, void *party)
{
    struct PokemonParam *egg = POKE_TOOL_Create(1, 1, 1, work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
    struct GameData *gameData;
#endif
    if (DAYCARE_GetEggReady(work->dayCare) == 1) {
        GAME_BEACON_SEARCH_SetSymbolMapEnter();
        SODATEYA_ClearEggFlag(work->fieldMap);
        SODATEYA_CreateEggMon(work, egg);
        POKEPARTY_Add(party, egg);
        DAYCARE_ClearEggReady(work->dayCare);
        GFL_HEAP_Free(egg);
#if LANGUAGE != LANGUAGE_JAPANESE
        /* The Japanese cartridge does not refresh the season forms of a new egg. */
        gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap));
        FORMCHANGE_UpdateSeasonForms((void *)gameData, party, GAME_DATA_GetSeason((void *)gameData));
#endif
    }
}

/*
 * Declines the egg: clears it from the day care and the egg flag.
 */
void SODATEYA_DeclineEgg(SodateyaWork *work)
{
    if (DAYCARE_GetEggReady(work->dayCare) == 1) {
        DAYCARE_ClearEggReady(work->dayCare);
        SODATEYA_ClearEggFlag(work->fieldMap);
    }
}

/* Advances the step counter by one; 1 when an egg was produced. */
int SODATEYA_AddStep(SodateyaWork *work)
{
    DAYCARE_AddSteps(work->dayCare, 1);
    if (SODATEYA_UpdateStepCounter(work) == 1) {
        DAYCARE_SetEggReady(work->dayCare);
        SODATEYA_SetEggFlag(work->fieldMap);
        return 1;
    }
    return 0;
}

/*
 * Sets event flag 0x4139 when the party is not full.
 */
void SODATEYA_SetEggFlag(void *fieldMap)
{
    void *gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    void *eventWork = (void *)GAME_DATA_GetEventWork(gameData);
    void *party = GAME_DATA_GetMyParty(gameData);
    if ((int)POKEPARTY_GetCount(party) < (int)POKEPARTY_GetCapacity(party))
        *((u16 *)ZONEDATA_GetEventWorkAddress((struct EventWork *)eventWork, 0x4139)) = 1;
}

/*
 * Clears event flag 0x4139 (EXACT*: unlabelled follower).
 */
void SODATEYA_ClearEggFlag(void *fieldMap)
{
    *((u16 *)ZONEDATA_GetEventWorkAddress(GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 0x4139)) = 0;
}

/*
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's SCRCMD_PROC_GetDaycareState reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 */
int SODATEYA_HasEgg(void *work)
{
    return DAYCARE_GetEggReady(((SodateyaWork *)work)->dayCare);
}

/* Number of pokemon in the day care. */
int SODATEYA_GetPokemonCount(SodateyaWork *work)
{
    return (u8)DAYCARE_GetInUseCount(work->dayCare);
}

/* Level the pokemon of slot has reached from the experience it gained. */
int SODATEYA_GetCurrentLevel(SodateyaWork *work, u32 slot)
{
    struct PokemonParam *mon;
    u32 form;
    u32 exp;
    u32 species;
    if (DAYCARE_IsSlotInUse(work->dayCare, slot) != 1)
        return 1;
    mon = (struct PokemonParam *)DAYCARE_GetSlotMon(work->dayCare, slot);
    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    exp = POKE_TOOL_GetPartyValue(mon, 8, 0);
    POKE_TOOL_GetPartyValue(mon, 0x9E, 0);
    return POKE_TOOL_CalcLevelFromExp(species, form, SODATEYA_AddExpSaturated(exp, DAYCARE_GetSlotSteps(work->dayCare, slot)));
}

/*
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 */
int SODATEYA_GetLevelsGained(SodateyaWork *work, int slot)
{
    int level = POKE_TOOL_GetPartyValue((struct PokemonParam *)DAYCARE_GetSlotMon(work->dayCare, slot), 0x9E, 0);
    return SODATEYA_GetCurrentLevel(work, slot) - level;
}

/* Price to take the pokemon of slot back: 100 per level gained, plus one. */
int SODATEYA_GetWithdrawCost(SodateyaWork *work, int slot)
{
    return ((SODATEYA_GetLevelsGained(work, slot) + 1) * 100);
}

/*
 * Compatibility of the two deposited Pokemon, 0 when fewer than two (EXACT*: pad).
 */
u8 SODATEYA_GetCompatibility(SodateyaWork *work)
{
    void *first;
    if (DAYCARE_GetInUseCount(work->dayCare) < 2)
        return 0;
    first = DAYCARE_GetSlotMon(work->dayCare, 0);
    return SODATEYA_CalcCompatibility(first, (struct PokemonParam *)DAYCARE_GetSlotMon(work->dayCare, 1));
}

/* Pokemon in day care slot. */
void *SODATEYA_GetPokemon(SodateyaWork *work, u32 slot)
{
    DAYCARE_IsSlotInUse(work->dayCare, slot);
    return DAYCARE_GetSlotMon(work->dayCare, slot);
}

/*
 * Saturating 32-bit add (EXACT*: pad).
 */
u32 SODATEYA_AddExpSaturated(u32 exp, u32 gain)
{
    u64 sum = (u64)exp + gain;
    if (sum > 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return sum;
}

/*
 * Gives the pokemon the gained experience and teaches the moves of the levels
 * crossed. Learnset walk as in SODATEYA_AddLevelUpMoves. Load-bearing: level is read from
 * the first entry copy right after it is made (the value stays in the
 * register), move from the second copy, and move is u32/int (u16 sinks its
 * load to the call).
 */
void SODATEYA_GrantExp(void *mon, u32 gain)
{
    LearnsetEntry learnset[26];
    LearnsetEntry entryE, entryD, entryC, entryA;
    u32 species;
    u32 form;
    u32 maxExp;
    int oldLevel;
    int newLevel;
    u32 exp;
    int i;
    int atEnd;
    int level;
    u32 move;
    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
    maxExp = POKE_TOOL_GetExpForLevel(species, form, 100);
    oldLevel = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
    exp = SODATEYA_AddExpSaturated(POKE_TOOL_GetPartyValue(mon, 8, 0), gain);
    if (maxExp < exp)
        exp = maxExp;
    POKE_TOOL_SetPartyValue(mon, 8, exp);
    POKE_TOOL_RecalcParam(mon);
    i = 0;
    newLevel = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
    POKE_PERSONAL_LoadDataDirect((u16)species, (u16)form, learnset);
    goto test;
body:
    entryE = entryA;
    level = entryE.level;
    entryD = entryA;
    move = entryD.move;
    if (newLevel < level)
        return;
    if (oldLevel < level)
        SODATEYA_LearnMove(mon, move);
    i++;
test:
    entryA = learnset[i];
    entryC = entryA;
    atEnd = 0;
    if (entryC.move == 0xffff && entryC.level == 0xffff)
        atEnd = 1;
    if (!atEnd)
        goto body;
}

/*
 * Teaches a move: into the first empty move slot, else asks to replace one.
 */
void SODATEYA_LearnMove(void *mon, u32 move)
{
    MoveSlotIdTable slotIds = d_021DA8C8;
    int i;
    if (move != 0 && SODATEYA_MonKnowsMove(mon, move) == 0) {
        for (i = 0; i < 4; i++) {
            if (POKE_TOOL_GetPartyValue(mon, slotIds.ids[i], 0) == 0) {
                POKE_TOOL_SetMoveSlot(mon, move, (u8)i);
                return;
            }
        }
        POKE_TOOL_PushMove(mon, (u16)move);
    }
}

/*
 * Addresses are Black-image addresses.
 */

/* Returns 1 when the Pokemon knows the move. */
int SODATEYA_MonKnowsMove(void *mon, u32 move)
{
    MoveSlotIdTable slotIds = sSodateyaHasMoveSlotIds;
    int i;

    for (i = 0; i < 4; i++) {
        if (move == POKE_TOOL_GetPartyValue(mon, slotIds.ids[i], 0))
            return 1;
    }
    return 0;
}

/*
 * Compacts the two day-care slots so occupied ones come first.
 */
void SODATEYA_CompactSlots(void *dayCare)
{
    int i, j;

    for (i = 0; i < DAYCARE_SLOT_COUNT; i++) {
        if (DAYCARE_IsSlotInUse(dayCare, i) == 1)
            continue;
        for (j = i + 1; j < DAYCARE_SLOT_COUNT; j++) {
            if (DAYCARE_IsSlotInUse(dayCare, j) == 1)
                DAYCARE_SwapSlots(dayCare, j, j - 1);
        }
    }
}

/*
 * Breeding compatibility of two party Pokemon: 0 when they cannot breed,
 * else the score from SODATEYA_CalcCompatibilityScore. The last test is spelled as the negated
 * conjunction returning 0, so the fall-through is the call.
 */
int SODATEYA_CalcCompatibility(struct PokemonParam *monA, struct PokemonParam *monB)
{
    u32 species[2];
    u32 form[2];
    u32 gender[2];
    u32 eggGroup1[2];
    u32 eggGroup2[2];
    struct PokemonParam *mons[2];
    int i;

    mons[0] = monA;
    mons[1] = monB;
    for (i = 0; i < 2; i++) {
        species[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mons[i], MON_DATA_SPECIES, 0);
        POKE_TOOL_GetPartyValue((struct PokemonParam *)mons[i], MON_DATA_OT_ID, 0);
        form[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mons[i], MON_DATA_FORM, 0);
        gender[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mons[i], MON_DATA_GENDER, 0);
        eggGroup1[i] = POKE_TOOL_GetPersonalParam(species[i], form[i], PERSONAL_EGG_GROUP_1);
        eggGroup2[i] = POKE_TOOL_GetPersonalParam(species[i], form[i], PERSONAL_EGG_GROUP_2);
    }
    if (eggGroup1[0] == EGG_GROUP_UNDISCOVERED || eggGroup1[1] == EGG_GROUP_UNDISCOVERED
        || eggGroup2[0] == EGG_GROUP_UNDISCOVERED || eggGroup2[1] == EGG_GROUP_UNDISCOVERED)
        return 0;
    if (species[0] == SPECIES_DITTO && species[1] == SPECIES_DITTO)
        return 0;
    if (species[0] == SPECIES_DITTO || species[1] == SPECIES_DITTO)
        return SODATEYA_CalcCompatibilityScore(monA, monB);
    if (gender[0] == gender[1])
        return 0;
    if (gender[0] == GENDER_NONE || gender[1] == GENDER_NONE)
        return 0;
    if (eggGroup1[0] != eggGroup1[1] && eggGroup1[0] != eggGroup2[1]
        && eggGroup2[0] != eggGroup1[1] && eggGroup2[0] != eggGroup2[1])
        return 0;
    return SODATEYA_CalcCompatibilityScore(monA, monB);
}

/*
 * Breeding score: 70 for the same species and the same trainer, 20 for
 * different species and the same trainer, 50 otherwise.
 */
int SODATEYA_CalcCompatibilityScore(struct PokemonParam *monA, struct PokemonParam *monB)
{
    u32 species[2];
    u32 otId[2];
    struct PokemonParam *mons[2];
    int i;

    mons[0] = monA;
    mons[1] = monB;
    for (i = 0; i < 2; i++) {
        species[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mons[i], MON_DATA_SPECIES, 0);
        otId[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mons[i], MON_DATA_OT_ID, 0);
    }
    if (species[0] != species[1]) {
        if (otId[0] == otId[1])
            return BREED_SCORE_LOW;
        return BREED_SCORE_MID;
    }
    if (otId[0] == otId[1])
        return BREED_SCORE_MID;
    return BREED_SCORE_HIGH;
}

/*
 * Step counter: every 16 steps rolls for an egg against compatibility.
 */
int SODATEYA_UpdateStepCounter(SodateyaWork *work)
{
    u16 oldCount = work->stepCount;

    work->stepCount = oldCount + STEPS_PER_EGG_CHECK;
    if (oldCount > 0xFF) {
        work->stepCount = 0;
        if (DAYCARE_GetInUseCount(work->dayCare) >= 2) {
            u32 roll = GFL_USE_GetRandomBelow(0x640);
            if (roll < SODATEYA_GetCompatibility(work))
                return 1;
        }
    }
    return 0;
}

/* Builds the egg Pokemon from the two Pokemon in the day care. */
void SODATEYA_CreateEggMon(SodateyaWork *work, struct PokemonParam *eggMon)
{
    struct MyStatus *myStatus = GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap)));
    struct PokemonParam *father = (struct PokemonParam *)DAYCARE_GetSlotMon(work->dayCare, 0);
    struct PokemonParam *mother = (struct PokemonParam *)DAYCARE_GetSlotMon(work->dayCare, 1);

    SODATEYA_BuildEgg(work->heapId, myStatus, SODATEYA_EGG_MET_PLACE, father, mother, eggMon);
}

/*
 * Runs a field-map accessor chain on the party after a Pokemon was left in the day care.
 */
void SODATEYA_SyncPartyAfterDeposit(struct FieldMap *fieldMap, void *party)
{
    PERAPVOICE_ClearIfNoChatot(GAME_DATA_GetPerapVoiceSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), party);
}

/*
 * Day-care offspring builder: runs every step of the 0x8C-byte egg record
 * over the parent pair and hands the result to SODATEYA_SetupEggMon.
 */
void SODATEYA_BuildEgg(u16 heapId, struct MyStatus *myStatus, u32 metPlace, struct PokemonParam *father, struct PokemonParam *mother, struct PokemonParam *eggMon)
{
    DayCareEgg egg;
    struct PokemonParam *parents[2];

    parents[0] = father;
    parents[1] = mother;
    SODATEYA_SortParentsByGender(parents);
    SODATEYA_PutDittoSecond(parents);
    SODATEYA_InitEgg(&egg);
    SODATEYA_SetBaseSpecies(parents, &egg);
    SODATEYA_RollNidoranSpecies(parents, &egg);
    SODATEYA_RollVolbeatSpecies(parents, &egg);
    SODATEYA_ApplyPhioneRule(parents, &egg);
    SODATEYA_ApplyIncenseBabyRule(parents, &egg);
    SODATEYA_ResetEggForm(parents, &egg);
    SODATEYA_InheritFormShellos(parents, &egg);
    SODATEYA_InheritFormBurmy(parents, &egg);
    SODATEYA_InheritFormBasculin(parents, &egg);
    SODATEYA_RollNature(parents, &egg);
    SODATEYA_ApplyEverstoneRule(parents, &egg);
    SODATEYA_RollAbilitySlot(parents, &egg, heapId);
    SODATEYA_RollDittoAbilitySlot(parents, &egg);
    SODATEYA_SetAbilityFromSlot(parents, &egg, heapId);
    SODATEYA_SetBaseFriendship(&egg, heapId);
    SODATEYA_ApplyPowerItemRule(parents, &egg);
    SODATEYA_RollRandomIvInheritance(parents, &egg);
    SODATEYA_CopyInheritedIvs(parents, &egg);
    SODATEYA_SetOtId(myStatus, &egg);
    SODATEYA_RollPersonalRnd(parents, &egg);
    SODATEYA_ApplyMasudaMethod(parents, &egg);
    SODATEYA_AddLevelUpMoves(&egg);
    SODATEYA_AddEggMoves(parents, &egg, heapId);
    SODATEYA_AddSharedMoves(parents, &egg);
    SODATEYA_AddTmMoves(parents, &egg, heapId);
    SODATEYA_AddVoltTackle(parents, &egg);
    SODATEYA_SetupEggMon(eggMon, &egg, myStatus, metPlace, heapId);
}

/*
 * Puts the father first: parents[0] ends up male (or the non-Ditto),
 * parents[1] female. The result of the second gender read of each pair is unused.
 */
void SODATEYA_SortParentsByGender(struct PokemonParam **parents)
{
    u32 gender = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_GENDER, 0);

    POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_GENDER, 0);
    if (gender == GENDER_FEMALE)
        SODATEYA_SwapParents(parents);
    POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_GENDER, 0);
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_GENDER, 0) == GENDER_MALE)
        SODATEYA_SwapParents(parents);
}

/*
 * Swaps the parents when parents[0] is a Ditto and parents[1] is genderless,
 * so the Ditto ends up second.
 */
void SODATEYA_PutDittoSecond(struct PokemonParam **parents)
{
    u32 species = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_SPECIES, 0);
    u32 gender = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_GENDER, 0);

    if (species == SPECIES_DITTO && gender == GENDER_NONE)
        SODATEYA_SwapParents(parents);
}

void SODATEYA_SwapParents(struct PokemonParam **parents)
{
    struct PokemonParam *tmp = parents[0];

    parents[0] = parents[1];
    parents[1] = tmp;
}

/* Clears the egg record and sets its level to 1. */
int SODATEYA_InitEgg(DayCareEgg *egg)
{
    MI_CpuFill8(egg, 0, sizeof(DayCareEgg));
    egg->level = 1;
    return 1;
}

/*
 * Stores the base form of the mother's species.
 */
void SODATEYA_SetBaseSpecies(struct PokemonParam **parents, DayCareEgg *egg)
{
    egg->species = SODATEYA_GetBaseSpecies(POKE_TOOL_GetPartyValue((struct PokemonParam *)(SODATEYA_GetSpeciesParent(parents)), MON_DATA_SPECIES, 0));
}

/*
 * Nidoran family: offspring species is a coin flip of 0x1D / 0x20.
 */
void SODATEYA_RollNidoranSpecies(struct PokemonParam **parents, DayCareEgg *egg)
{
    u32 species = POKE_TOOL_GetPartyValue((struct PokemonParam *)(SODATEYA_GetSpeciesParent(parents)), MON_DATA_SPECIES, 0);

    if (species == SPECIES_NIDORAN_F || species - 0x20 <= 2) {
        if (GFL_USE_GetRandomBelow(2) == 0)
            egg->species = SPECIES_NIDORAN_F;
        else
            egg->species = 0x20;
    }
}

/*
 * Volbeat / Illumise: offspring species is a coin flip of the two.
 */
void SODATEYA_RollVolbeatSpecies(struct PokemonParam **parents, DayCareEgg *egg)
{
    u32 species = POKE_TOOL_GetPartyValue((struct PokemonParam *)(SODATEYA_GetSpeciesParent(parents)), MON_DATA_SPECIES, 0);

    if (species == SPECIES_VOLBEAT || species == SPECIES_ILLUMISE) {
        if (GFL_USE_GetRandomBelow(2) == 0)
            egg->species = SPECIES_VOLBEAT;
        else
            egg->species = SPECIES_ILLUMISE;
    }
}

/*
 * Manaphy parents produce Phione.
 */
void SODATEYA_ApplyPhioneRule(struct PokemonParam **parents, DayCareEgg *egg)
{
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)(SODATEYA_GetSpeciesParent(parents)), MON_DATA_SPECIES, 0) == SPECIES_MANAPHY)
        egg->species = SPECIES_PHIONE;
}

/*
 * Incense babies: when the baby species is in the table and neither parent
 * holds its incense, the offspring is the adult species instead.
 */
void SODATEYA_ApplyIncenseBabyRule(struct PokemonParam **parents, DayCareEgg *egg)
{
    IncenseBabyTable table = sSodateyaIncenseBabyTable;
    int i;
    u32 fatherItem, motherItem;
    struct PokemonParam *mon = SODATEYA_GetSpeciesParent(parents);

    i = 0;
    POKE_TOOL_GetPartyValue(mon, MON_DATA_SPECIES, 0);
    POKE_TOOL_GetPartyValue(mon, MON_DATA_HELD_ITEM, 0);
    fatherItem = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_HELD_ITEM, 0);
    motherItem = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_HELD_ITEM, 0);
    for (; i < 12; i++) {
        if (egg->species == table.entries[i].babySpecies
            && fatherItem != table.entries[i].incenseItem
            && motherItem != table.entries[i].incenseItem) {
            egg->species = table.entries[i].adultSpecies;
            return;
        }
    }
}

/* The parent whose species and form the offspring takes: the mother, or the father when she is a Ditto. */
struct PokemonParam *SODATEYA_GetSpeciesParent(struct PokemonParam **parents)
{
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_SPECIES, 0) == SPECIES_DITTO) {
        return parents[0];
    }
    return parents[1];
}

/* The offspring starts in form 0. */
int SODATEYA_ResetEggForm(struct PokemonParam **parents, DayCareEgg *egg)
{
    egg->form = 0;
    return 0;
}

/*
 * Copies the parent's form for species 0x1A6..0x1A7 (Shellos, Gastrodon).
 */
void SODATEYA_InheritFormShellos(struct PokemonParam **parents, DayCareEgg *egg)
{
    struct PokemonParam *mon = SODATEYA_GetFormParent(parents);
    u32 species = POKE_TOOL_GetPartyValue(mon, MON_DATA_SPECIES, 0);

    if (species - 0x1A6 <= 1)
        egg->form = POKE_TOOL_GetPartyValue(mon, MON_DATA_FORM, 0);
}

/*
 * Copies the parent's form for species 0x19C..0x19D (Burmy, Wormadam).
 */
void SODATEYA_InheritFormBurmy(struct PokemonParam **parents, DayCareEgg *egg)
{
    struct PokemonParam *mon = SODATEYA_GetFormParent(parents);
    u32 species = POKE_TOOL_GetPartyValue(mon, MON_DATA_SPECIES, 0);

    if (species - 0x19C <= 1)
        egg->form = POKE_TOOL_GetPartyValue(mon, MON_DATA_FORM, 0);
}

/*
 * Copies the parent's form for Basculin.
 */
void SODATEYA_InheritFormBasculin(struct PokemonParam **parents, DayCareEgg *egg)
{
    struct PokemonParam *mon = SODATEYA_GetFormParent(parents);
    u32 species = POKE_TOOL_GetPartyValue(mon, MON_DATA_SPECIES, 0);

    if (species == SPECIES_BASCULIN)
        egg->form = POKE_TOOL_GetPartyValue(mon, MON_DATA_FORM, 0);
}

/* Same choice as SODATEYA_GetSpeciesParent, kept as its own function by the original. */
struct PokemonParam *SODATEYA_GetFormParent(struct PokemonParam **parents)
{
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_SPECIES, 0) == SPECIES_DITTO) {
        return parents[0];
    }
    return parents[1];
}

/*
 * Rolls the offspring nature.
 */
void SODATEYA_RollNature(struct PokemonParam **parents, DayCareEgg *egg)
{
    egg->nature = GFL_USE_GetRandomBelow(0x19);
}

/*
 * Everstone: a parent holding it passes its nature on (half the time when
 * one holds it, a coin flip between the two when both do).
 */
void SODATEYA_ApplyEverstoneRule(struct PokemonParam **parents, DayCareEgg *egg)
{
    int fatherHolds, motherHolds;
    u32 fatherNature, motherNature;

    fatherHolds = 0;
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_HELD_ITEM, 0) == ITEM_EVERSTONE)
        fatherHolds = 1;
    motherHolds = 0;
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_HELD_ITEM, 0) == ITEM_EVERSTONE)
        motherHolds = 1;
    fatherNature = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_NATURE, 0);
    motherNature = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_NATURE, 0);
    if (fatherHolds || motherHolds) {
        if (GFL_USE_GetRandomBelow(2) == 0)
            return;
    }
    if (fatherHolds && motherHolds) {
        if (GFL_USE_GetRandomBelow(2) == 0) {
            egg->nature = fatherNature;
            egg->natureFromFather = 1;
        } else {
            egg->nature = motherNature;
            egg->natureFromMother = 1;
        }
    } else if (fatherHolds) {
        egg->nature = fatherNature;
        egg->natureFromFather = 1;
    } else if (motherHolds) {
        egg->nature = motherNature;
        egg->natureFromMother = 1;
    }
}

/*
 * Rolls the ability slot of the offspring from the mother's ability slot.
 */
void SODATEYA_RollAbilitySlot(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId)
{
    u32 species = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_SPECIES, 0);
    u32 form = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_FORM, 0);
    u32 ability = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_ABILITY, 0);
    u32 motherSlot = (u32)SODATEYA_GetAbilitySlot((u16)species, (u16)form, (u16)ability, heapId);
    u32 roll = GFL_USE_GetRandomBelow(100);

    switch (motherSlot) {
    default:
    case 0:
        if (roll < 0x50)
            egg->abilitySlot = 0;
        else
            egg->abilitySlot = 1;
        return;
    case 1:
        if (roll < 0x14)
            egg->abilitySlot = 0;
        else
            egg->abilitySlot = 1;
        return;
    case 2:
        if (roll < 0x14)
            egg->abilitySlot = 0;
        else if (roll < 0x28)
            egg->abilitySlot = 1;
        else
            egg->abilitySlot = 2;
        return;
    }
}

/*
 * Sets the ability slot by coin flip when a parent is a Ditto.
 */
void SODATEYA_RollDittoAbilitySlot(struct PokemonParam **parents, DayCareEgg *egg)
{
    u32 fatherSpecies = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_SPECIES, 0);
    u32 motherSpecies = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_SPECIES, 0);

    if (fatherSpecies == SPECIES_DITTO || motherSpecies == SPECIES_DITTO) {
        if (GFL_USE_GetRandomBelow(2) == 0)
            egg->abilitySlot = 0;
        else
            egg->abilitySlot = 1;
    }
}

/*
 * Looks up the ability of the chosen slot in the personal data of the
 * offspring species, falling back to slot 0 when it is empty.
 */
void SODATEYA_SetAbilityFromSlot(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId)
{
    u32 abilities[3];
    struct PersonalData *personal = (struct PersonalData *)POKE_PERSONAL_Create((u16)egg->species, (u16)egg->form, heapId);

    abilities[0] = POKE_PERSONAL_GetParam(personal, 0x1a);
    abilities[1] = POKE_PERSONAL_GetParam(personal, 0x1b);
    abilities[2] = POKE_PERSONAL_GetParam(personal, 0x1c);
    POKE_PERSONAL_Delete(personal);
    if (egg->abilitySlot < 2) {
        egg->ability = abilities[egg->abilitySlot];
        if (egg->ability == 0)
            egg->ability = abilities[0];
    }
}

/*
 * Reads personal-data field 0x15 (base friendship) for the species/form pair.
 */
void SODATEYA_SetBaseFriendship(DayCareEgg *egg, u32 heapId)
{
    void *personal = POKE_PERSONAL_Create((u16)egg->species, (u16)egg->form, heapId);
    u32 baseFriendship = POKE_PERSONAL_GetParam(personal, 0x15);

    POKE_PERSONAL_Delete(personal);
    egg->baseFriendship = baseFriendship;
}

/*
 * Power items: a parent holding one passes the matching IV on. The flag
 * array must be a struct member (egg->fatherIvFlags[i]); spelled as a flat
 * index the compiler folds the offset into the index and spills it.
 */
void SODATEYA_ApplyPowerItemRule(struct PokemonParam **parents, DayCareEgg *egg)
{
    StatTable powerItems;
    int fatherHolds;
    int motherHolds;
    int fatherStat;
    int motherStat;
    u32 fatherItem;
    u32 motherItem;
    int i;

    fatherHolds = 0;
    motherHolds = 0;
    fatherItem = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_HELD_ITEM, 0);
    motherItem = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_HELD_ITEM, 0);
    powerItems = sSodateyaPowerItemIds;
    for (i = 0; i < 6; i++) {
        if (fatherItem == powerItems.ids[i]) {
            fatherHolds = 1;
            fatherStat = i;
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        if (motherItem == powerItems.ids[i]) {
            motherHolds = 1;
            motherStat = i;
            break;
        }
    }
    if (fatherHolds && motherHolds) {
        if (GFL_USE_GetRandomBelow(2) == 0) {
            egg->fatherIvFlags[fatherStat] = 1;
            egg->inheritedIvCount++;
        } else {
            egg->motherIvFlags[motherStat] = 1;
            egg->inheritedIvCount++;
        }
    } else if (fatherHolds) {
        egg->fatherIvFlags[fatherStat] = 1;
        egg->inheritedIvCount++;
    } else if (motherHolds) {
        egg->motherIvFlags[motherStat] = 1;
        egg->inheritedIvCount++;
    }
}

/*
 * Picks random IVs from random parents until three are inherited.
 */
void SODATEYA_RollRandomIvInheritance(struct PokemonParam **parents, DayCareEgg *egg)
{
    while (egg->inheritedIvCount < 3) {
        u32 stat = GFL_USE_GetRandomBelow(6);

        if (GFL_USE_GetRandomBelow(2) == 0) {
            if (egg->fatherIvFlags[stat] == 0 && egg->motherIvFlags[stat] == 0) {
                egg->fatherIvFlags[stat] = 1;
                egg->inheritedIvCount++;
            }
        } else {
            if (egg->fatherIvFlags[stat] == 0 && egg->motherIvFlags[stat] == 0) {
                egg->motherIvFlags[stat] = 1;
                egg->inheritedIvCount++;
            }
        }
    }
}

/*
 * Copies the flagged IVs from the parents into the egg.
 */
void SODATEYA_CopyInheritedIvs(struct PokemonParam **parents, DayCareEgg *egg)
{
    StatTable ivIds = sSodateyaParentIvIds;
    u32 *ids = ivIds.ids;
    int i;

    for (i = 0; i < 6; i++) {
        if (egg->fatherIvFlags[i] != 0)
            egg->ivs[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], ids[i], 0);
        if (egg->motherIvFlags[i] != 0)
            egg->ivs[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], ids[i], 0);
    }
}

/* The egg belongs to the player: copies the trainer id. */
void SODATEYA_SetOtId(struct MyStatus *myStatus, DayCareEgg *egg)
{
    egg->otId = MYSTATUS_GetId(myStatus);
}

/* Rolls the personality value of the egg. */
void SODATEYA_RollPersonalRnd(struct PokemonParam **parents, DayCareEgg *egg)
{
    egg->personalRnd = SODATEYA_RollRandomU32();
}

/*
 * Masuda method: parents of different languages get up to five more
 * personality rolls, stopping at the first shiny one.
 */
void SODATEYA_ApplyMasudaMethod(struct PokemonParam **parents, DayCareEgg *egg)
{
    int i = 0;
    u32 fatherLanguage = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_LANGUAGE, 0);

    if (fatherLanguage == POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_LANGUAGE, 0))
        return;
    if (POKE_TOOL_IsShinyOtIdPersonality(egg->otId, egg->personalRnd) != 0)
        return;
    do {
        egg->personalRnd = SODATEYA_RollRandomU32();
        if (POKE_TOOL_IsShinyOtIdPersonality(egg->otId, egg->personalRnd) != 0)
            return;
        i++;
    } while (i < 5);
}

/*
 * Random 32-bit value (tail call with minus one).
 */
u32 SODATEYA_RollRandomU32(void)
{
    return GFL_USE_GetRandomBelow(-1);
}

/*
 * Adds the moves the baby learns by level up at its starting level. The
 * learnset walk is a rotated loop (goto test) with the entry copied three times.
 */
void SODATEYA_AddLevelUpMoves(DayCareEgg *egg)
{
    LearnsetEntry learnset[26];
    LearnsetEntry copyA, copyB, probe, entry;
    int i;
    int isEnd;
    u32 entryLevel, eggLevel, move;

    POKE_PERSONAL_LoadDataDirect((u16)egg->species, (u16)egg->form, learnset);
    i = 0;
    goto test;
body:
    copyA = entry;
    copyB = entry;
    entryLevel = copyA.level;
    eggLevel = egg->level;
    move = copyB.move;
    if (eggLevel < entryLevel)
        return;
    SODATEYA_AddMove(egg, move);
    i++;
test:
    entry = learnset[i];
    probe = entry;
    isEnd = 0;
    if (probe.move == 0xffff && probe.level == 0xffff)
        isEnd = 1;
    if (!isEnd)
        goto body;
}

/*
 * Egg moves: moves the father knows that are in the egg move list of the
 * offspring species. The third parameter must exist and is forwarded as the
 * heap id; with two parameters the table copy takes r3/r2 instead of r4/r3.
 */
void SODATEYA_AddEggMoves(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId)
{
    MoveSlotIdTable slotIds = sSodateyaEggMoveSlotIds;
    u32 *ids = slotIds.ids;
    u16 *eggMoves = ARC_TOOL_LoadMember(0x7b, egg->species, heapId);
    int eggMoveCount = eggMoves[0];
    int i;

    for (i = 0; i < 4; i++) {
        u32 move = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], ids[i], 0);
        int j;

        for (j = 1; j <= eggMoveCount; j++) {
            if (move == eggMoves[j]) {
                SODATEYA_AddMove(egg, move);
                break;
            }
        }
    }
    GFL_HEAP_Free(eggMoves);
}

/*
 * Moves of the offspring's learnset that both parents know. Twin of
 * SODATEYA_AddLevelUpMoves (same goto-rotated learnset walk). The call result must be
 * a named local (v == move gives cmp r0, r5), and isEnd = 0 goes after the
 * entry copies, as in the twin.
 */
void SODATEYA_AddSharedMoves(struct PokemonParam **parents, DayCareEgg *egg)
{
    LearnsetEntry learnset[26];
    MoveSlotIdTable slotIds = sSodateyaSharedMoveSlotIds;
    LearnsetEntry copy, probe, entry;
    int i;
    int fatherKnows;
    int motherKnows;
    int isEnd;
    int slot;
    u32 move;
    u32 value;

    POKE_PERSONAL_LoadDataDirect((u16)egg->species, (u16)egg->form, learnset);
    i = 0;
    goto test;
body:
    copy = entry;
    move = copy.move;
    fatherKnows = 0;
    motherKnows = 0;
    for (slot = 0; slot < 4; slot++) {
        value = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], slotIds.ids[slot], 0);
        if (value == move) {
            fatherKnows = 1;
            break;
        }
    }
    for (slot = 0; slot < 4; slot++) {
        value = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], slotIds.ids[slot], 0);
        if (value == move) {
            motherKnows = 1;
            break;
        }
    }
    if (fatherKnows && motherKnows)
        SODATEYA_AddMove(egg, move);
    i++;
test:
    entry = learnset[i];
    probe = entry;
    isEnd = 0;
    if (probe.move == 0xffff && probe.level == 0xffff)
        isEnd = 1;
    if (!isEnd)
        goto body;
}

/*
 * TM moves: moves the father knows that match a TM the offspring species can learn.
 */
void SODATEYA_AddTmMoves(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId)
{
    MoveSlotIdTable slotIds = sSodateyaTmMoveSlotIds;
    int i;

    for (i = 0; i < 4; i++) {
        u32 move = POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], slotIds.ids[i], 0);
        int tmItem;

        for (tmItem = TM_ITEM_FIRST; tmItem <= TM_ITEM_LAST; tmItem++) {
            if (move == FILE_UTIL_GetMachineMove(tmItem)) {
                if (SODATEYA_CanLearnTm(heapId, (u16)egg->species, (u16)egg->form, (u16)tmItem)) {
                    SODATEYA_AddMove(egg, move);
                    break;
                }
            }
        }
    }
}

/*
 * Pichu offspring learns Volt Tackle when a parent holds a Light Ball.
 */
void SODATEYA_AddVoltTackle(struct PokemonParam **parents, DayCareEgg *egg)
{
    if (egg->species == SPECIES_PICHU) {
        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[0], MON_DATA_HELD_ITEM, 0) == ITEM_LIGHT_BALL
            || POKE_TOOL_GetPartyValue((struct PokemonParam *)parents[1], MON_DATA_HELD_ITEM, 0) == ITEM_LIGHT_BALL)
            SODATEYA_AddMove(egg, MOVE_VOLT_TACKLE);
    }
}

/*
 * Adds a move to the egg, skipping duplicates; when all four slots are
 * full the oldest move drops out.
 */
void SODATEYA_AddMove(DayCareEgg *egg, u32 move)
{
    int i;
    u32 count;

    if (move == 0)
        return;
    count = egg->moveCount;
    for (i = 0; i < count; i++) {
        if (move == egg->moves[i])
            return;
    }
    if (count < 4) {
        egg->moves[count] = move;
        egg->moveCount = egg->moveCount + 1;
        return;
    }
    for (i = 0; i < 3; i++)
        egg->moves[i] = egg->moves[i + 1];
    egg->moves[i] = move;
}

/*
 * Builds the day-care egg/offspring Pokemon from the 0x8C-byte egg record
 * (the struct SODATEYA_BuildEgg fills on its stack). The bl to the Thumb
 * tail-call stub POKE_TOOL_RecoverAllPP is witnessed by
 * src/matched/arm9/POKE_TOOL_RecoverAllPP.c.
 *
 * Load-bearing: const DayCareEgg *egg (the species/level loads rise above
 * the zero stack-argument stores), and heapId u16 at both callees
 * (MYSTATUS_CreateNameStrbuf, SAVE_EVENT_Write) so it is re-read from its stack slot per call.
 */
void SODATEYA_SetupEggMon(struct PokemonParam *mon, const DayCareEgg *egg, struct MyStatus *myStatus, u32 metPlace, u16 heapId)
{
    StatTable ivIds = sSodateyaEggIvIds;
    int i;
    struct StrBuf *str;

    POKE_TOOL_SetupPartyParamEx(mon, egg->species, egg->level, egg->otId, -1, egg->personalRnd);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_FORM, egg->form);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_NATURE, egg->nature);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_FRIENDSHIP, egg->baseFriendship);
    if (egg->abilitySlot == 2)
        POKE_TOOL_SetAbility((struct BoxPokemon *)mon, egg->species, egg->form);
    else
        POKE_TOOL_SetPartyValue(mon, MON_DATA_ABILITY_SET, egg->ability);
    for (i = 0; i < 6; i++) {
        if (egg->fatherIvFlags[i] != 0 || egg->motherIvFlags[i] != 0)
            POKE_TOOL_SetPartyValue(mon, ivIds.ids[i], egg->ivs[i]);
    }
    POKE_TOOL_SetPartyValue(mon, MON_DATA_MOVE1, egg->moves[0]);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_MOVE2, egg->moves[1]);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_MOVE3, egg->moves[2]);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_MOVE4, egg->moves[3]);
    str = (struct StrBuf *)MYSTATUS_CreateNameStrbuf((u16 *)myStatus, heapId);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_OT_NAME, (uptr)str);
    STRBUF_Delete((struct Strbuf *)str);
    str = (struct StrBuf *)MSGDATA_AllocString(gSpeciesNameBank, 0x28a);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_NICKNAME, (uptr)str);
    STRBUF_Delete((struct Strbuf *)str);
    SAVE_EVENT_Write(mon, 5, myStatus, metPlace, heapId);
    POKE_TOOL_SetPartyValue(mon, MON_DATA_IS_EGG, 1);
    POKE_TOOL_RecoverAllPP(mon);
    POKE_TOOL_RecalcParam(mon);
    POKE_TOOL_HealFull(mon);
}

/*
 * Tests whether a species can learn a TM: reads the TM bit mask in the
 * personal data (four 32-bit words, TM index split across them).
 */
int SODATEYA_CanLearnTm(u32 heapId, u32 species, u32 form, u32 tmItem)
{
    u32 tmIndex; struct PersonalData *personal; u32 mask;

    if (species >= SPECIES_LAST)
        return 0;
    if (FILE_UTIL_IsMachineItem(tmItem) == 0)
        return 0;
    personal = POKE_PERSONAL_Create(species, form, heapId);
    tmIndex = FILE_UTIL_GetId(tmItem);
    if (tmIndex < 0x20) {
        mask = POKE_PERSONAL_GetParam(personal, 0x27);
    } else if (tmIndex < 0x40) {
        mask = POKE_PERSONAL_GetParam(personal, 0x28);
        tmIndex -= 0x20;
    } else if (tmIndex < 0x60) {
        mask = POKE_PERSONAL_GetParam(personal, 0x29);
        tmIndex -= 0x40;
    } else {
        mask = POKE_PERSONAL_GetParam(personal, 0x2a);
        tmIndex -= 0x60;
    }
    POKE_PERSONAL_Delete(personal);
    return mask & (1 << tmIndex);
}

/*
 * Maps a species to its base form via the evolution table (species below
 * 0x289).
 */
u16 SODATEYA_GetBaseSpecies(u16 species)
{
    u16 baseSpecies;

    if (species >= SPECIES_LAST)
        return species;
    ARC_TOOL_ReadMemberRange(&baseSpecies, (u32)0x14, (u32)species, (u32)0, (u32)2);
    return baseSpecies;
}

/*
 * Position of an ability among the three ability slots of a species/form
 * (0 when it matches none).
 */
u8 SODATEYA_GetAbilitySlot(u32 species, u32 form, u32 ability, u32 heapId)
{
    u32 abilities[3];
    struct PersonalData *personal = POKE_PERSONAL_Create(species, form, heapId);
    u32 slot;

    abilities[0] = POKE_PERSONAL_GetParam(personal, 0x1a);
    abilities[1] = POKE_PERSONAL_GetParam(personal, 0x1b);
    abilities[2] = POKE_PERSONAL_GetParam(personal, 0x1c);
    POKE_PERSONAL_Delete(personal);
    for (slot = 0; slot < 3; slot++) {
        if (ability == abilities[slot])
            break;
    }
    if (slot >= 3)
        slot = 0;
    return slot;
}
