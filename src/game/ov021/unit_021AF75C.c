/*
 * file:     unit_021AF75C.c
 * unit:     yes
 * function: SCRCMD_BufferPlayerName, SCRCMD_BufferEntryCommon, SCRCMD_BufferItemName, SCRCMD_BufferItemNameAlt, SCRCMD_BufferItemNameWithCount, SCRCMD_BufferConvertedEntryName, SCRCMD_BufferGroupEntryName, SCRCMD_BufferCategoryEntryName, SCRCMD_BufferSpeciesNameCommon, SCRCMD_BufferSpeciesName, SCRCMD_BufferSpeciesEntryName, SCRCMD_BufferShortEntryName, SCRCMD_BufferPartyMonSpeciesName, SCRCMD_BufferPartyMonNickname, SCRCMD_BufferDaycareMonSpeciesName, SCRCMD_BufferDaycareMonNickname, SCRCMD_BufferNumber, SCRCMD_BufferPlaceName, SCRCMD_BufferEasyChatWord, SCRCMD_BufferGroupedEntryName, SCRCMD_BufferByteEntryNameA, SCRCMD_BufferByteEntryNameB, SCRCMD_BufferSignedEntryName, SCRCMD_BufferByteEntryCommon, SCRCMD_BufferMapEntryNameA, SCRCMD_BufferMapEntryNameB, SCRCMD_BufferSaveCounterA, SCRCMD_BufferSaveCounterB, SCRCMD_WarpToPosition, SCRCMD_WarpToPositionPlain, SCRCMD_WarpToPositionEvent, SCRCMD_WarpToPositionFixedExit, SCRCMD_WarpToFixedZone, SCRCMD_WarpToPosition3D, SCRCMD_WarpToRailLocation, SCRCMD_WarpToRailLocationWithTransition
 * address:  0x021AF75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021AF75C (lane L135, script argument and event data command handlers; original unknown).
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EF5C  0x0201EF5C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_0201EE84  0x0201EE84  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb  ov021
 *   SODATEYA_GetPokemon  0x021C34F8  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F0F8  0x0201F0F8  thumb
 *   func_0201F124  0x0201F124  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 *   EVENT_MAPCHANGE_CreateWarpEventPlain  0x02185534  thumb  ov020
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight  0x0216282C  thumb  ov010
 *   EVENTDATA_SYSTEM_GetPosEventCenterPosThunk  0x02162A6C  thumb  ov010
 *   EVENT_MAPCHANGE_CreateWarpEventWithTargetPos  0x02184E40  thumb  ov020
 *   FLDEFF_GYOE_StartHeld  0x021BB578  thumb  ov021
 *   EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent  0x02185050  thumb  ov020
 *   EVENT_MAPCHANGE_CreateFixedZoneEvent  0x021850A8  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_CalcZoneRailLocation  0x021BB3E8  thumb  ov021
 *   EVENT_MAPCHANGE_CreateRailWarpEvent  0x02184D90  thumb  ov020
 *   EVENT_MAPCHANGE_CreateRailWarpEventWithTransition  0x02184DE8  thumb  ov020
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb  arm9
 */
#include "../arm9/script_vm_types.h"
#include "fldmmdl_rail_types.h"

typedef signed int s32;

struct ScrcmdWork;
struct WordSet;
struct GameSystem;
struct GameData;
struct FieldMap;
struct EventRec;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef void (*WordSetRegisterFn)(struct WordSet *wordSet, u32 slot, u32 value);

extern void *FIELD_PLAYER_GetMmdl(void *fieldPlayer);
extern void *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern void *GAME_DATA_GetEventWork(void *gameData);
extern void *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *cmdWork);
extern int SCRIPT_WORK_ResetFieldParam(void *scriptWork);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *cmdWork);
extern void *SCRIPT_WORK_GetGameSystem(void *scriptWork);
extern void *SCRCMD_WORK_GetGameData(struct ScrcmdWork *cmdWork);
extern void *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern u16 VM_GetU16(ScriptVm *vm);
extern struct WordSet *SCRIPT_WORK_GetWordSet(void *scriptWork);
extern void *GAME_DATA_GetMyStatus(void *gameData);
extern void func_0201F02C(struct WordSet *wordSet, u32 slot, void *myStatus);
extern void func_0201EF40(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EF4C(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EF5C(struct WordSet *wordSet, u32 slot, u32 value);
extern u32 func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F020(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EE60(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EEC4(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F14C(struct WordSet *wordSet, u32 slot, u32 value);
extern void *GAME_DATA_GetMyParty(void *gameData);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern void func_0201EE84(struct WordSet *wordSet, u32 slot, void *mon);
extern void func_0201EEF4(struct WordSet *wordSet, u32 slot, void *mon);
extern void *FIELDMAP_GetSodateya(struct FieldMap *fieldMap);
extern void *SODATEYA_GetPokemon(void *sodateya, u32 index);
extern void func_0201EFA4(struct WordSet *wordSet, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);
extern u32 ZONEDATA_GetPlaceNameId(u32 a);
extern void func_0201F158(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EFC8(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F048(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F198(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F1B0(struct WordSet *wordSet, u32 slot, u8 value);
extern void func_0201F184(struct WordSet *wordSet, u32 slot, s32 value);
extern void func_0201F0F8(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F124(struct WordSet *wordSet, u32 slot, u32 value);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void *func_0200C0F0(void *saveControl);
extern u32 func_0200C1DC(void *block);
extern u32 func_0200C1C4(void *block);
extern void *GAMESYSTEM_GetEvent(struct GameSystem *gameSystem);
extern void GAME_EVENT_CallEvent(void *parentEvent, void *childEvent);
extern void *EVENT_MAPCHANGE_CreateWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed);
extern void *EVENT_MAPCHANGE_CreateWarpEventPlain(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir);
extern u32 GAME_DATA_GetEventData(void *gameData);
extern void *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void *FIELDMAP_GetEffect(struct FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(void *fieldPlayer, VecFx32 *outPos);
extern struct EventRec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(void *eventData, void *eventWork, VecFx32 *pos, int mode);
extern void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(const struct EventRec *event, VecFx32 *outPos);
extern void *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(struct GameSystem *gameSystem, struct FieldMap *fieldMap, const VecFx32 *targetPos, u16 zoneId, const VecFx32 *pos);
extern void FLDEFF_GYOE_StartHeld(void *fieldEffectCtrl, void *mmdl, int type, int sePlay);
extern void *EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir);
extern void *EVENT_MAPCHANGE_CreateFixedZoneEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, u16 dir);
extern void *FIELDMAP_GetNogridMapper(struct FieldMap *fieldMap);
extern void FIELD_NOGRID_MAPPER_CalcZoneRailLocation(void *nogridMapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId);
extern void *EVENT_MAPCHANGE_CreateRailWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
extern void *EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);

int SCRCMD_BufferPlayerName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferEntryCommon(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferItemName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferItemNameAlt(ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_BufferItemNameWithCount(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferConvertedEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferGroupEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferCategoryEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferSpeciesNameCommon(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferSpeciesName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferSpeciesEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferShortEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferPartyMonSpeciesName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferPartyMonNickname(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferDaycareMonSpeciesName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferDaycareMonNickname(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferNumber(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferPlaceName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferEasyChatWord(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferGroupedEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryNameA(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryNameB(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferSignedEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryCommon(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferMapEntryNameA(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferMapEntryNameB(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferSaveCounterA(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_BufferSaveCounterB(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToPosition(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionPlain(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionFixedExit(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToFixedZone(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToPosition3D(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToRailLocation(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_WarpToRailLocationWithTransition(ScriptVm *vm, struct ScrcmdWork *cmdWork);

static inline u8 ScriptVm_ReadU8(ScriptVm *vm)
{
    u8 value = *vm->pc;

    vm->pc++;
    return value;
}

/* Script command: put the player name into a word set slot (slot byte). */
int SCRCMD_BufferPlayerName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *myStatus;
    struct WordSet *wordSet;

    SCRIPT_WORK_ResetFieldParam(scriptWork);
    myStatus = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(cmdWork));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    func_0201F02C(wordSet, ScriptVm_ReadU8(vm), myStatus);
    return 0;
}

/*
 * Shared body of the word set commands that take a slot byte and one script
 * value: reads the slot and the value and registers the value with registerFn.
 */
int SCRCMD_BufferEntryCommon(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);

    registerFn(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferItemName(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return SCRCMD_BufferEntryCommon(vm, cmdWork, func_0201EF40); }
int SCRCMD_BufferItemNameAlt(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return SCRCMD_BufferEntryCommon(vm, cmdWork, func_0201EF4C); }

/*
 * Script command: register an entry (slot byte, entry value, count value,
 * flag byte). A count above 1 selects the plural entry list; otherwise the
 * flag selects between the two singular lists.
 */
void SCRCMD_BufferItemNameWithCount(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 entry;
    u32 count;
    u32 flag;

    entry = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    count = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    flag = ScriptVm_ReadU8(vm);
    if (count > 1) {
        func_0201EF5C(wordSet, slot, entry);
    } else if (flag != 0) {
        func_0201EF4C(wordSet, slot, entry);
    } else {
        func_0201EF40(wordSet, slot, entry);
    }
}

/* Script command: register the item name with the converted item value (slot byte, value). */
int SCRCMD_BufferConvertedEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201EF34(wordSet, slot, func_020212B0(SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 0;
}

int SCRCMD_BufferGroupEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201EF34(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferCategoryEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F020(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Shared body of the species name commands: slot byte, then one script value. */
int SCRCMD_BufferSpeciesNameCommon(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);

    registerFn(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferSpeciesName(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return SCRCMD_BufferSpeciesNameCommon(vm, cmdWork, func_0201EE60); }
int SCRCMD_BufferSpeciesEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return SCRCMD_BufferSpeciesNameCommon(vm, cmdWork, func_0201EEC4); }

int SCRCMD_BufferShortEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F14C(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Script command: register the species name of a party member (slot byte, party index value). */
int SCRCMD_BufferPartyMonSpeciesName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    u32 slot = ScriptVm_ReadU8(vm);
    u32 partyIndex;

    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_0201EE84(wordSet, slot, POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex));
    return 0;
}

/* Script command: register the nickname of a party member (slot byte, party index value). */
int SCRCMD_BufferPartyMonNickname(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    u32 slot = ScriptVm_ReadU8(vm);
    u32 partyIndex;

    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_0201EEF4(wordSet, slot, POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex));
    return 0;
}

/* Script command: register the species name of a daycare Pokemon (slot byte, daycare index value). */
int SCRCMD_BufferDaycareMonSpeciesName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 daycareIndex;

    daycareIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_0201EE84(wordSet, slot, SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareIndex));
    return 0;
}

/* Script command: register the nickname of a daycare Pokemon (slot byte, daycare index value). */
int SCRCMD_BufferDaycareMonNickname(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 daycareIndex;

    daycareIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_0201EEF4(wordSet, slot, SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareIndex));
    return 0;
}

/* Script command: register a number (slot byte, number value, digit count value). */
int SCRCMD_BufferNumber(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 number;
    u32 digitCount;

    number = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    digitCount = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    func_0201EFA4(wordSet, slot, number, digitCount, 0, 1);
    return 0;
}

/* Script command: register the place name of a zone (slot byte, zone value). */
int SCRCMD_BufferPlaceName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F158(wordSet, slot, ZONEDATA_GetPlaceNameId(SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 0;
}

int SCRCMD_BufferEasyChatWord(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201EFC8(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferGroupedEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F048(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferByteEntryNameA(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F198(wordSet, slot, (u8)SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferByteEntryNameB(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F1B0(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* The slot byte comes first, then the value; the word set is looked up last. */
int SCRCMD_BufferSignedEntryName(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u8 slot = ScriptVm_ReadU8(vm);
    u32 value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    func_0201F184(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork)), slot, value);
    return 0;
}

/* Shared body of the byte-valued word set commands (slot byte, one script value truncated to a byte). */
int SCRCMD_BufferByteEntryCommon(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    int slot = ScriptVm_ReadU8(vm);
    int value;

    value = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    registerFn(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork)), slot, (u8)value);
    return 0;
}

int SCRCMD_BufferMapEntryNameA(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return SCRCMD_BufferByteEntryCommon(vm, cmdWork, func_0201F0F8); }
int SCRCMD_BufferMapEntryNameB(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return SCRCMD_BufferByteEntryCommon(vm, cmdWork, func_0201F124); }

/* Script command: register a counter of the save data as a 9-digit number (slot byte). */
int SCRCMD_BufferSaveCounterA(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *counters;
    struct WordSet *wordSet;
    int slot;

    counters = func_0200C0F0(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    slot = ScriptVm_ReadU8(vm);
    func_0201EFA4(wordSet, slot, func_0200C1DC(counters), 9, 1, 1);
    return 0;
}

/* Same as SCRCMD_BufferSaveCounterA with the second counter. */
int SCRCMD_BufferSaveCounterB(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *counters;
    struct WordSet *wordSet;
    int slot;

    counters = func_0200C0F0(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    slot = ScriptVm_ReadU8(vm);
    func_0201EFA4(wordSet, slot, func_0200C1C4(counters), 9, 1, 1);
    return 0;
}

/*
 * Script command: warp to a map position (zone, x, z, direction values; the
 * height is 0). Positions are in 16.16 fixed point.
 */
int SCRCMD_WarpToPosition(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    x = VM_GetU16(vm);
    z = VM_GetU16(vm);
    dir = VM_GetU16(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, zoneId, &pos, dir, 0));
    return 1;
}

/* Same arguments as SCRCMD_WarpToPosition, plain warp event. */
int SCRCMD_WarpToPositionPlain(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    x = VM_GetU16(vm);
    z = VM_GetU16(vm);
    dir = VM_GetU16(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventPlain(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/*
 * Script command: warp to a zone, arriving at the player's position event
 * (zone, x, z values). The position event is found from the player's
 * position; the player model is then handed to the effect controller.
 */
int SCRCMD_WarpToPositionEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    void *gameData;
    void *eventData;
    void *eventWork;
    void *event;
    void *mmdl;
    struct EventRec *posEvent;
    VecFx32 targetPos;
    VecFx32 pos;
    VecFx32 playerPos;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    x = VM_GetU16(vm);
    z = VM_GetU16(vm);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    eventData = (void *)GAME_DATA_GetEventData(gameData);
    eventWork = GAME_DATA_GetEventWork(gameData);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    posEvent = EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(eventData, eventWork, &playerPos, 9);
    if (posEvent != 0)
        EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(posEvent, &targetPos);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(gameSystem, fieldMap, &targetPos, zoneId, &pos));
    mmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    FLDEFF_GYOE_StartHeld(FIELDMAP_GetEffect(fieldMap), mmdl, 0, 1);
    return 1;
}

/* Same arguments as SCRCMD_WarpToPosition, fixed exit type warp event. */
int SCRCMD_WarpToPositionFixedExit(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    x = VM_GetU16(vm);
    z = VM_GetU16(vm);
    dir = VM_GetU16(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/* Script command: start the fixed zone warp event (no script arguments). */
int SCRCMD_WarpToFixedZone(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    void *event = GAMESYSTEM_GetEvent(gameSystem);

    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateFixedZoneEvent(gameSystem, fieldMap));
    return 1;
}

/*
 * Script command: warp to a map position with the default transition (zone,
 * x, y, z, direction values, all positions in 16.16 fixed point).
 */
int SCRCMD_WarpToPosition3D(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 y;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    x = VM_GetU16(vm);
    y = VM_GetU16(vm);
    z = VM_GetU16(vm);
    dir = VM_GetU16(vm);
    FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    pos.x = x << 16;
    pos.y = y << 16;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/*
 * Script command: warp to a rail location (zone, rail index, line grid,
 * width grid, direction values). The zone's rail location is looked up
 * through the no-grid mapper first.
 */
int SCRCMD_WarpToRailLocation(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 railIndex;
    u16 lineGrid;
    u16 widthGrid;
    u16 dir;
    void *event;
    RailLocation rail;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    railIndex = VM_GetU16(vm);
    lineGrid = VM_GetU16(vm);
    widthGrid = VM_GetU16(vm);
    dir = VM_GetU16(vm);
    event = GAMESYSTEM_GetEvent(gameSystem);
    FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FIELDMAP_GetNogridMapper(fieldMap), zoneId, railIndex, lineGrid, widthGrid, &rail, 0x15);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateRailWarpEvent(gameSystem, fieldMap, zoneId, &rail, dir, 0));
    return 1;
}

/* Same arguments as SCRCMD_WarpToRailLocation, rail warp event with the transition. */
int SCRCMD_WarpToRailLocationWithTransition(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 railIndex;
    u16 lineGrid;
    u16 widthGrid;
    u16 dir;
    void *event;
    RailLocation rail;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_GetU16(vm);
    railIndex = VM_GetU16(vm);
    lineGrid = VM_GetU16(vm);
    widthGrid = VM_GetU16(vm);
    dir = VM_GetU16(vm);
    event = GAMESYSTEM_GetEvent(gameSystem);
    FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FIELDMAP_GetNogridMapper(fieldMap), zoneId, railIndex, lineGrid, widthGrid, &rail, 0x15);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(gameSystem, fieldMap, zoneId, &rail, dir, 0));
    return 1;
}
