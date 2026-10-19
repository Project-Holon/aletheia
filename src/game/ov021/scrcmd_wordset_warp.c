/*
 * file:     scrcmd_wordset_warp.c
 * unit:     yes
 * function: SCRCMD_BufferPlayerName, SCRCMD_BufferEntryCommon, SCRCMD_BufferItemName, SCRCMD_BufferItemNameAlt, SCRCMD_BufferItemNameWithCount, SCRCMD_BufferConvertedEntryName, SCRCMD_BufferGroupEntryName, SCRCMD_BufferCategoryEntryName, SCRCMD_BufferSpeciesNameCommon, SCRCMD_BufferSpeciesName, SCRCMD_BufferSpeciesEntryName, SCRCMD_BufferShortEntryName, SCRCMD_BufferPartyMonSpeciesName, SCRCMD_BufferPartyMonNickname, SCRCMD_BufferDaycareMonSpeciesName, SCRCMD_BufferDaycareMonNickname, SCRCMD_BufferNumber, SCRCMD_BufferPlaceName, SCRCMD_BufferEasyChatWord, SCRCMD_BufferGroupedEntryName, SCRCMD_BufferByteEntryNameA, SCRCMD_BufferByteEntryNameB, SCRCMD_BufferSignedEntryName, SCRCMD_BufferByteEntryCommon, SCRCMD_BufferMapEntryNameA, SCRCMD_BufferMapEntryNameB, SCRCMD_BufferBeaconThanksCount, SCRCMD_BufferBeaconGreetCount, SCRCMD_WarpToPosition, SCRCMD_WarpToPositionPlain, SCRCMD_WarpToPositionEvent, SCRCMD_WarpToPositionFixedExit, SCRCMD_WarpToFixedZone, SCRCMD_WarpToPosition3D, SCRCMD_WarpToRailLocation, SCRCMD_WarpToRailLocationWithTransition
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
 *   VM_ReadU16  0x02011330  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb
 *   WORDSET_SetSlotFromMsg117  0x0201EF4C  thumb
 *   WORDSET_SetSlotFromMsg118  0x0201EF5C  thumb
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb
 *   WORDSET_SetSlotFromMsg119  0x0201EEC4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb  ov021
 *   SODATEYA_GetPokemon  0x021C34F8  thumb  ov021
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotFromMsgBF  0x0201F0F8  thumb
 *   WORDSET_SetSlotFromMsg11B  0x0201F124  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   MISC_GetThanksCount  0x0200C1DC  thumb
 *   MISC_GetGreetCount  0x0200C1C4  thumb
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
 *   FILE_UTIL_GetMachineMove  0x020212B0  thumb  arm9
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb  arm9
 *   WORDSET_SetSlotPmsWord  0x0201EFC8  thumb  arm9
 *   WORDSET_SetSlotFromMsgC7  0x0201F020  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_SetSlotFromMsg37  0x0201F14C  thumb  arm9
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb  arm9
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb  arm9
 *   WORDSET_SetSlotFromMsg2B  0x0201F198  thumb  arm9
 *   WORDSET_SetSlotFromMsg00  0x0201F1B0  thumb  arm9
 */
#include "../arm9/script_vm_types.h"
#include "../ov010/script_work_types.h"
#include "../ov010/fldmmdl_types.h"
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

#include "../types.h"

typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct GameEvent GameEvent;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct WordSet WordSet;
typedef struct SaveControl SaveControl;
typedef struct MiscSave MiscSave;
typedef struct MyStatus MyStatus;
typedef struct Party Party;
typedef struct PokemonParam PokemonParam;
typedef struct Sodateya Sodateya;
typedef struct EventDataSystem EventDataSystem;
typedef struct EventRec EventRec;
typedef struct FieldPlayer FieldPlayer;
typedef struct FieldEffectCont FieldEffectCont;
typedef struct FieldNogridMapper FieldNogridMapper;

typedef void (*WordSetRegisterFn)(WordSet *wordSet, u32 slot, u32 value);

extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *fieldPlayer);
extern GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);
extern void *GAME_DATA_GetEventWork(GameData *gameData);
extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *scriptWork);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);
extern GameSystem *SCRIPT_WORK_GetGameSystem(ScriptWork *scriptWork);
extern GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);
extern FieldMap *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);
extern u16 VM_ReadU16(ScriptVm *vm);
extern WordSet *SCRIPT_WORK_GetWordSet(ScriptWork *scriptWork);
extern MyStatus *GAME_DATA_GetMyStatus(GameData *gameData);
extern void WORDSET_SetSlotMyStatus(WordSet *wordSet, u32 slot, MyStatus *myStatus);
extern void WORDSET_SetSlotFromMsg36(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsg117(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsg118(WordSet *wordSet, u32 slot, u32 entryIndex);
extern u32 FILE_UTIL_GetMachineMove(u32 value);
extern void WORDSET_SetSlotFromMsgCB(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsgC7(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotSpeciesName(WordSet *wordSet, u32 slot, u16 speciesId);
extern void WORDSET_SetSlotFromMsg119(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsg37(WordSet *wordSet, u32 slot, u32 entryIndex);
extern Party *GAME_DATA_GetMyParty(GameData *gameData);
extern PokemonParam *POKEPARTY_GetMember(Party *party, u32 pos);
extern void WORDSET_SetSlotMonSpeciesName(WordSet *wordSet, u32 slot, PokemonParam *mon);
extern void WORDSET_SetSlotMonNickname(WordSet *wordSet, u32 slot, PokemonParam *mon);
extern Sodateya *FIELDMAP_GetSodateya(FieldMap *fieldMap);
extern PokemonParam *SODATEYA_GetPokemon(Sodateya *sodateya, u32 index);
extern void WORDSET_SetSlotNumber(WordSet *wordSet, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);
extern u32 ZONEDATA_GetPlaceNameId(u32 zoneId);
extern void WORDSET_SetSlotFromMsg59(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotPmsWord(WordSet *wordSet, u32 slot, u32 pmsWord);
extern void WORDSET_SetSlotFromMsgE7(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsg2B(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsg00(WordSet *wordSet, u32 slot, u8 entryIndex);
extern void WORDSET_SetSlotFromMsgA0(WordSet *wordSet, u32 slot, s32 entryIndex);
extern void WORDSET_SetSlotFromMsgBF(WordSet *wordSet, u32 slot, u32 entryIndex);
extern void WORDSET_SetSlotFromMsg11B(WordSet *wordSet, u32 slot, u32 entryIndex);
extern SaveControl *GAME_DATA_GetSaveControl(GameData *gameData);
extern MiscSave *MISC_GetBlock(SaveControl *saveControl);
extern u32 MISC_GetThanksCount(MiscSave *beacon);
extern u32 MISC_GetGreetCount(MiscSave *beacon);
extern GameEvent *GAMESYSTEM_GetEvent(GameSystem *gameSystem);
extern void GAME_EVENT_CallEvent(GameEvent *parentEvent, GameEvent *childEvent);
extern GameEvent *EVENT_MAPCHANGE_CreateWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed);
extern GameEvent *EVENT_MAPCHANGE_CreateWarpEventPlain(GameSystem *gameSystem, FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir);
extern EventDataSystem *GAME_DATA_GetEventData(GameData *gameData);
extern FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern FieldEffectCont *FIELDMAP_GetEffect(FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(FieldPlayer *fieldPlayer, VecFx32 *outPos);
extern EventRec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(EventDataSystem *eventData, void *eventWork, VecFx32 *pos, int mode);
extern void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(const EventRec *event, VecFx32 *outPos);
extern GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos, u16 zoneId, const VecFx32 *pos);
extern void FLDEFF_GYOE_StartHeld(FieldEffectCont *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay);
extern GameEvent *EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir);
extern GameEvent *EVENT_MAPCHANGE_CreateFixedZoneEvent(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, u16 dir);
extern FieldNogridMapper *FIELDMAP_GetNogridMapper(FieldMap *fieldMap);
extern void FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FieldNogridMapper *nogridMapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId);
extern GameEvent *EVENT_MAPCHANGE_CreateRailWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
extern GameEvent *EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(GameSystem *gameSystem, FieldMap *fieldMap, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);

int SCRCMD_BufferPlayerName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferEntryCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferItemName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferItemNameAlt(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_BufferItemNameWithCount(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferConvertedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferGroupEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferCategoryEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferSpeciesNameCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferSpeciesEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferShortEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferPartyMonSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferPartyMonNickname(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferDaycareMonSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferDaycareMonNickname(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferNumber(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferPlaceName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferEasyChatWord(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferGroupedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryNameA(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryNameB(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferSignedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferMapEntryNameA(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferMapEntryNameB(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferBeaconThanksCount(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferBeaconGreetCount(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPosition(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionPlain(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionFixedExit(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToFixedZone(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPosition3D(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToRailLocationWithTransition(ScriptVm *vm, ScrcmdWork *cmdWork);

static inline u8 ScriptVm_ReadU8(ScriptVm *vm)
{
    u8 value = *vm->pc;

    vm->pc++;
    return value;
}

/* Script command: put the player name into a word set slot (slot byte). */
int SCRCMD_BufferPlayerName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    MyStatus *myStatus;
    WordSet *wordSet;

    SCRIPT_WORK_ResetFieldParam(scriptWork);
    myStatus = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(cmdWork));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    WORDSET_SetSlotMyStatus(wordSet, ScriptVm_ReadU8(vm), myStatus);
    return 0;
}

/*
 * Shared body of the word set commands that take a slot byte and one script
 * value: reads the slot and the value and registers the value with registerFn.
 */
int SCRCMD_BufferEntryCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);

    registerFn(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferItemName(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_BufferEntryCommon(vm, cmdWork, WORDSET_SetSlotFromMsg36); }
int SCRCMD_BufferItemNameAlt(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_BufferEntryCommon(vm, cmdWork, WORDSET_SetSlotFromMsg117); }

/*
 * Script command: register an entry (slot byte, entry value, count value,
 * flag byte). A count above 1 selects the plural entry list; otherwise the
 * flag selects between the two singular lists.
 */
void SCRCMD_BufferItemNameWithCount(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 entry;
    u32 count;
    u32 useAltList;

    entry = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    count = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    useAltList = ScriptVm_ReadU8(vm);
    if (count > 1) {
        WORDSET_SetSlotFromMsg118(wordSet, slot, entry);
    } else if (useAltList != 0) {
        WORDSET_SetSlotFromMsg117(wordSet, slot, entry);
    } else {
        WORDSET_SetSlotFromMsg36(wordSet, slot, entry);
    }
}

/* Script command: register the item name with the converted item value (slot byte, value). */
int SCRCMD_BufferConvertedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsgCB(wordSet, slot, FILE_UTIL_GetMachineMove(SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 0;
}

int SCRCMD_BufferGroupEntryName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsgCB(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferCategoryEntryName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsgC7(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Shared body of the species name commands: slot byte, then one script value. */
int SCRCMD_BufferSpeciesNameCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);

    registerFn(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_BufferSpeciesNameCommon(vm, cmdWork, (WordSetRegisterFn)WORDSET_SetSlotSpeciesName); }
int SCRCMD_BufferSpeciesEntryName(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_BufferSpeciesNameCommon(vm, cmdWork, WORDSET_SetSlotFromMsg119); }

int SCRCMD_BufferShortEntryName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsg37(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Script command: register the species name of a party member (slot byte, party index value). */
int SCRCMD_BufferPartyMonSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    u32 slot = ScriptVm_ReadU8(vm);
    u32 partyIndex;

    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WORDSET_SetSlotMonSpeciesName(wordSet, slot, POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex));
    return 0;
}

/* Script command: register the nickname of a party member (slot byte, party index value). */
int SCRCMD_BufferPartyMonNickname(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    u32 slot = ScriptVm_ReadU8(vm);
    u32 partyIndex;

    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WORDSET_SetSlotMonNickname(wordSet, slot, POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex));
    return 0;
}

/* Script command: register the species name of a daycare Pokemon (slot byte, daycare index value). */
int SCRCMD_BufferDaycareMonSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 daycareIndex;

    daycareIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WORDSET_SetSlotMonSpeciesName(wordSet, slot, SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareIndex));
    return 0;
}

/* Script command: register the nickname of a daycare Pokemon (slot byte, daycare index value). */
int SCRCMD_BufferDaycareMonNickname(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 daycareIndex;

    daycareIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WORDSET_SetSlotMonNickname(wordSet, slot, SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), daycareIndex));
    return 0;
}

/* Script command: register a number (slot byte, number value, digit count value). */
int SCRCMD_BufferNumber(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 number;
    u32 digitCount;

    number = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    digitCount = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WORDSET_SetSlotNumber(wordSet, slot, number, digitCount, 0, 1);
    return 0;
}

/* Script command: register the place name of a zone (slot byte, zone value). */
int SCRCMD_BufferPlaceName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsg59(wordSet, slot, ZONEDATA_GetPlaceNameId(SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 0;
}

int SCRCMD_BufferEasyChatWord(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotPmsWord(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferGroupedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsgE7(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferByteEntryNameA(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsg2B(wordSet, slot, (u8)SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRCMD_BufferByteEntryNameB(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    WordSet *wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    WORDSET_SetSlotFromMsg00(wordSet, slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* The slot byte comes first, then the value; the word set is looked up last. */
int SCRCMD_BufferSignedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u8 slot = ScriptVm_ReadU8(vm);
    u32 entryIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    WORDSET_SetSlotFromMsgA0(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork)), slot, entryIndex);
    return 0;
}

/* Shared body of the byte-valued word set commands (slot byte, one script value truncated to a byte). */
int SCRCMD_BufferByteEntryCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    int slot = ScriptVm_ReadU8(vm);
    int entryIndex;

    entryIndex = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    registerFn(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork)), slot, (u8)entryIndex);
    return 0;
}

int SCRCMD_BufferMapEntryNameA(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_BufferByteEntryCommon(vm, cmdWork, WORDSET_SetSlotFromMsgBF); }
int SCRCMD_BufferMapEntryNameB(ScriptVm *vm, ScrcmdWork *cmdWork) { return SCRCMD_BufferByteEntryCommon(vm, cmdWork, WORDSET_SetSlotFromMsg11B); }

/* Script command: register the beacon save thanks count as a 9-digit number (slot byte). */
int SCRCMD_BufferBeaconThanksCount(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    MiscSave *beacon;
    WordSet *wordSet;
    int slot;

    beacon = MISC_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    slot = ScriptVm_ReadU8(vm);
    WORDSET_SetSlotNumber(wordSet, slot, MISC_GetThanksCount(beacon), 9, 1, 1);
    return 0;
}

/* Same as SCRCMD_BufferBeaconThanksCount with the greet count. */
int SCRCMD_BufferBeaconGreetCount(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    MiscSave *beacon;
    WordSet *wordSet;
    int slot;

    beacon = MISC_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    slot = ScriptVm_ReadU8(vm);
    WORDSET_SetSlotNumber(wordSet, slot, MISC_GetGreetCount(beacon), 9, 1, 1);
    return 0;
}

/*
 * Script command: warp to a map position (zone, x, z, direction values; the
 * height is 0). Positions are in 16.16 fixed point.
 */
int SCRCMD_WarpToPosition(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    GameEvent *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    x = VM_ReadU16(vm);
    z = VM_ReadU16(vm);
    dir = VM_ReadU16(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, zoneId, &pos, dir, 0));
    return 1;
}

/* Same arguments as SCRCMD_WarpToPosition, plain warp event. */
int SCRCMD_WarpToPositionPlain(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    GameEvent *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    x = VM_ReadU16(vm);
    z = VM_ReadU16(vm);
    dir = VM_ReadU16(vm);
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
int SCRCMD_WarpToPositionEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    GameData *gameData;
    EventDataSystem *eventData;
    void *eventWork;
    GameEvent *event;
    Mmdl *mmdl;
    EventRec *posEvent;
    VecFx32 targetPos;
    VecFx32 pos;
    VecFx32 playerPos;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    x = VM_ReadU16(vm);
    z = VM_ReadU16(vm);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    eventData = GAME_DATA_GetEventData(gameData);
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
int SCRCMD_WarpToPositionFixedExit(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    GameEvent *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    x = VM_ReadU16(vm);
    z = VM_ReadU16(vm);
    dir = VM_ReadU16(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = GAMESYSTEM_GetEvent(gameSystem);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/* Script command: start the fixed zone warp event (no script arguments). */
int SCRCMD_WarpToFixedZone(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GameEvent *event = GAMESYSTEM_GetEvent(gameSystem);

    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateFixedZoneEvent(gameSystem, fieldMap));
    return 1;
}

/*
 * Script command: warp to a map position with the default transition (zone,
 * x, y, z, direction values, all positions in 16.16 fixed point).
 */
int SCRCMD_WarpToPosition3D(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 y;
    u16 z;
    u16 dir;
    VecFx32 pos;
    GameEvent *event;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    x = VM_ReadU16(vm);
    y = VM_ReadU16(vm);
    z = VM_ReadU16(vm);
    dir = VM_ReadU16(vm);
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
int SCRCMD_WarpToRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 railIndex;
    u16 lineGrid;
    u16 widthGrid;
    u16 dir;
    GameEvent *event;
    RailLocation rail;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    railIndex = VM_ReadU16(vm);
    lineGrid = VM_ReadU16(vm);
    widthGrid = VM_ReadU16(vm);
    dir = VM_ReadU16(vm);
    event = GAMESYSTEM_GetEvent(gameSystem);
    FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FIELDMAP_GetNogridMapper(fieldMap), zoneId, railIndex, lineGrid, widthGrid, &rail, 0x15);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateRailWarpEvent(gameSystem, fieldMap, zoneId, &rail, dir, 0));
    return 1;
}

/* Same arguments as SCRCMD_WarpToRailLocation, rail warp event with the transition. */
int SCRCMD_WarpToRailLocationWithTransition(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    u16 zoneId;
    u16 railIndex;
    u16 lineGrid;
    u16 widthGrid;
    u16 dir;
    GameEvent *event;
    RailLocation rail;

    gameSystem = SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork(cmdWork));
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    zoneId = VM_ReadU16(vm);
    railIndex = VM_ReadU16(vm);
    lineGrid = VM_ReadU16(vm);
    widthGrid = VM_ReadU16(vm);
    dir = VM_ReadU16(vm);
    event = GAMESYSTEM_GetEvent(gameSystem);
    FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FIELDMAP_GetNogridMapper(fieldMap), zoneId, railIndex, lineGrid, widthGrid, &rail, 0x15);
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(gameSystem, fieldMap, zoneId, &rail, dir, 0));
    return 1;
}
