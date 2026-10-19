/*
 * file:     field_map_change.c
 * unit:     yes
 * function: FIELD_MAP_CHANGE_ApplyZoneHeader, FIELD_MAP_CHANGE_SetupZone, FIELD_MAP_CHANGE_ResetGimmickStateCase1, FIELD_MAP_CHANGE_ResetGimmickStateCase3, FIELD_MAP_CHANGE_ResetGimmickStateCase2, FIELD_MAP_CHANGE_ResetGimmickStateCase4, FIELD_MAP_CHANGE_MoveActiveEntries, FIELD_MAP_CHANGE_Empty
 * address:  0x021643AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Map change helpers (guess) and the thunks that follow them.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MOVE_POKEMON_SAVE_GetBlock 0x0200D418 thumb
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   MOVE_POKEMON_SetCommonArea 0x0215E428 thumb ov010
 *   MOVE_POKEMON_MoveActiveEntriesChecked 0x0215E3A0 thumb ov010
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_ResetEventFlag 0x0201433C thumb
 *   FIELD_ENCOUNT_ST_GetEffectEncount 0x0215E33C thumb ov010
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   ZONEDATA_GetFieldSkillMapEffect  0x02013F6C  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   MOVE_POKEMON_MoveActiveEntries  0x0215E364  thumb ov010
 *   HIDDEN_ITEM_Respawn  0x02164728  thumb ov010
 *   ZONEDATA_IsZoneInTableDFB8  0x02013FFC  thumb
 *   PLAYER_LOCATION_GetData  0x02008854  thumb
 *   PLAYER_LOCATION_SetStepMessageCount  0x02008988  thumb
 *   FIELD_ENCOUNT_ST_ResetGimmickState  0x0215E34C  thumb  ov010
 */

struct GameData;
struct SaveControl;
struct Situation;

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"

#include "../types.h"

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl);
struct FieldMap;
extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
struct MovePokemonSave;
extern void MOVE_POKEMON_SetCommonArea(struct MovePokemonSave *block, int value);
extern void MOVE_POKEMON_MoveActiveEntriesChecked(struct GameData *gameData);
extern void *GAME_DATA_GetEventWork(const struct GameData *gameData);
struct EventWork;
extern void ZONEDATA_ResetEventFlag(struct EventWork *ev, int flagId);
extern int FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap);
extern void *GAME_DATA_GetMoveModelSys(const struct GameData *gameData);
extern u32 ZONEDATA_GetFieldSkillMapEffect(u32 id);
struct FieldStatus;
extern void FIELD_STATUS_SetFlashActive(struct FieldStatus *fs, u8 flashActive);
extern void MOVE_POKEMON_MoveActiveEntries(struct GameData *gameData);
struct EventWork;
extern void  HIDDEN_ITEM_Respawn(struct EventWork *eventWork);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
struct PlayerLocationData;
extern struct PlayerLocationData *PLAYER_LOCATION_GetData(void *save);
extern void PLAYER_LOCATION_SetStepMessageCount(struct PlayerLocationData *location_data, u16 value);
struct FieldGimmickWork;
extern struct FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData);
void FIELD_MAP_CHANGE_ApplyZoneHeader(struct GameData *gameData, void *zoneHeader);
void FIELD_MAP_CHANGE_SetupZone(struct GameData *gameData, u32 zoneId);
int FIELD_MAP_CHANGE_ResetGimmickStateCase1(int object, int unused);
int FIELD_MAP_CHANGE_ResetGimmickStateCase3(int object, int unused);
int FIELD_MAP_CHANGE_ResetGimmickStateCase2(int object, int unused);
int FIELD_MAP_CHANGE_ResetGimmickStateCase4(struct GameData *object, int unused);
void FIELD_MAP_CHANGE_MoveActiveEntries(void *object, int unused);
void FIELD_MAP_CHANGE_Empty(struct GameData *system, u16 zoneId);

/*
 * interface: FIELDMAP_GetZoneId reads the u16 field at +0xD8;
 * MOVE_POKEMON_SetCommonArea forwards its second argument to MOVE_POKEMON_SAVE_SetCommonArea,
 * whose matched ARM9 body takes u16 and stores only that halfword.
 * The legacy FIELD_MAP_CHANGE_SetupZone declaration uses a pointer for this ID.
 */
void FIELD_MAP_CHANGE_ApplyZoneHeader(struct GameData *gameData, void *zoneHeader) { void *saveWork=MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData)); MOVE_POKEMON_SetCommonArea(saveWork,FIELDMAP_GetZoneId((struct FieldMap *)zoneHeader)); MOVE_POKEMON_MoveActiveEntriesChecked(gameData); ZONEDATA_ResetEventFlag((struct EventWork *)GAME_DATA_GetEventWork(gameData),0x964); FIELD_ENCOUNT_ST_GetEffectEncount(zoneHeader); }

/*
 * Per-object setup: registers the object with the frame list, applies
 * the flag word and seeds the 177-entry table pass.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_MAP_CHANGE_SetupZone(struct GameData *gameData, u32 zoneId)
{
    MmdlSys *mmdlSys = GAME_DATA_GetMoveModelSys(gameData);
    void *eventWork;
    if ((ZONEDATA_GetFieldSkillMapEffect(zoneId) & 3) == 0) {
        FIELD_STATUS_SetFlashActive((struct FieldStatus *)mmdlSys, 0);
    }
    MOVE_POKEMON_SetCommonArea(MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData)), (int)zoneId);
    MOVE_POKEMON_MoveActiveEntries(gameData);
    eventWork = GAME_DATA_GetEventWork(gameData);
    ZONEDATA_ResetEventFlag(eventWork, 0x964);
    HIDDEN_ITEM_Respawn(eventWork);
    if (ZONEDATA_IsZoneInTableDFB8(zoneId) == 0) {
        PLAYER_LOCATION_SetStepMessageCount(PLAYER_LOCATION_GetData(GAME_DATA_GetSaveControl(gameData)), 0);
    }
}

/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to FIELD_ENCOUNT_ST_ResetGimmickState at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 EVENT_MAPCHANGE_ChangeFieldEvent (case 1 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int FIELD_MAP_CHANGE_ResetGimmickStateCase1(int object, int unused)
{
    return (int)FIELD_ENCOUNT_ST_ResetGimmickState((struct GameData *)object);
}

/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to FIELD_ENCOUNT_ST_ResetGimmickState at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 EVENT_MAPCHANGE_ChangeFieldEvent (case 3 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int FIELD_MAP_CHANGE_ResetGimmickStateCase3(int object, int unused)
{
    return (int)FIELD_ENCOUNT_ST_ResetGimmickState((struct GameData *)object);
}

/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to FIELD_ENCOUNT_ST_ResetGimmickState at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 EVENT_MAPCHANGE_ChangeFieldEvent (case 2 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int FIELD_MAP_CHANGE_ResetGimmickStateCase2(int object, int unused)
{
    return (int)FIELD_ENCOUNT_ST_ResetGimmickState((struct GameData *)object);
}

/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 EVENT_MAPCHANGE_InitFieldFromSituationWarp.
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 EVENT_MAPCHANGE_InitFieldFromSituationWarp.
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int FIELD_MAP_CHANGE_ResetGimmickStateCase4(struct GameData *object, int unused)
{
    return (int)FIELD_ENCOUNT_ST_ResetGimmickState((struct GameData *)object);
}

/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 EVENT_MAPCHANGE_ContinueEvent.
 */
void FIELD_MAP_CHANGE_MoveActiveEntries(void *object, int unused)
{
    MOVE_POKEMON_MoveActiveEntries(object);
}

/*
 * Empty function after the veneer run; the only Thumb code at this address
 * in any overlay window, called from ov021 FIELDMAP_SeqCreateSubsystems.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_MAP_CHANGE_Empty(struct GameData *system, u16 zoneId)
{
}
