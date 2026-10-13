/*
 * file:     pleasure_boat.c
 * unit:     yes
 * function: PLEASURE_BOAT_GetPassengerParam, PLEASURE_BOAT_GetPassengerType, PLEASURE_BOAT_GetPassengerExtra, PLEASURE_BOAT_GetPassengerOccupied, PLEASURE_BOAT_SetPassengerOccupied, PLEASURE_BOAT_GetTimeEvent, PLEASURE_BOAT_Lock, PLEASURE_BOAT_ScrCmdCreate, PLEASURE_BOAT_ScrCmdDelete, PLEASURE_BOAT_ScrCmdGetStat, PLEASURE_BOAT_ScrCmdAddTime, PLEASURE_BOAT_ScrCmdSetPassengerInfo, PLEASURE_BOAT_ScrCmdLock
 * address:  0x021C87A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C87A0: pleasure_boat.c tail; calls PLEASURE_BOAT_Create (pleasure_boat.c __FILE__ anchor, in field_flash.c), PLEASURE_BOAT_AdvanceTime, PLEASURE_BOAT_GetStat.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   PLEASURE_BOAT_Create  0x021C8608  thumb  ov021
 *   SYMBOL_MAP_DeleteLinkRecord  0x021666A4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   PLEASURE_BOAT_GetStat  0x021C8738  thumb  ov021
 *   PLEASURE_BOAT_AdvanceTime  0x021C86E8  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct ScriptVm ScriptVm;
typedef struct ScrCmdWork ScrCmdWork;
typedef struct GameSystem GameSystem;
typedef struct FieldMap FieldMap;
typedef struct GameData GameData;

#include "pleasure_boat_types.h"

extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrCmdWork *scrCmdWork);
extern FieldMap *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);
extern GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);
extern PleasureBoatHolder *GAME_DATA_GetEventState(GameData *gameData);
extern PleasureBoatWork *PLEASURE_BOAT_Create(void);
extern void SYMBOL_MAP_DeleteLinkRecord(PleasureBoatHolder *holder);
extern void *SCRCMD_WORK_GetScriptWork(ScrCmdWork *scrCmdWork);
extern u16 VM_GetU16(ScriptVm *vm);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrCmdWork *scrCmdWork);
extern int PLEASURE_BOAT_GetStat(PleasureBoatWork *work, int kind);
extern void PLEASURE_BOAT_AdvanceTime(PleasureBoatWork *work, u32 seconds, u32 clamp);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrCmdWork *scrCmdWork);

u32 PLEASURE_BOAT_GetPassengerParam(PleasureBoatWork *work, u32 index);
u32 PLEASURE_BOAT_GetPassengerType(PleasureBoatWork *work, u32 index);
u32 PLEASURE_BOAT_GetPassengerExtra(PleasureBoatWork *work, u32 index, u32 wordIndex);
u32 PLEASURE_BOAT_GetPassengerOccupied(PleasureBoatWork *work, u32 index);
void PLEASURE_BOAT_SetPassengerOccupied(PleasureBoatWork *work, int index, int occupied);
int PLEASURE_BOAT_GetTimeEvent(PleasureBoatWork *work);
PleasureBoatWork *PLEASURE_BOAT_Lock(PleasureBoatWork *work);
int PLEASURE_BOAT_ScrCmdCreate(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdDelete(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdGetStat(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdAddTime(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdSetPassengerInfo(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdLock(ScriptVm *vm, ScrCmdWork *scrCmdWork);

/* Script queries 5, 6, 7 and 8 read these passenger fields (see symbol_map.c, SYMBOL_MAP_ScrCmdGetEventStateValue). */
u32 PLEASURE_BOAT_GetPassengerParam(PleasureBoatWork *work, u32 index)
{
    return work->passengers[index].param;
}

u32 PLEASURE_BOAT_GetPassengerType(PleasureBoatWork *work, u32 index)
{
    return work->passengers[index].type;
}

/*
 * lever: the passenger record pointer as its own local; the flat
 *   `p + i*0x1C + j*4 + 0x1C` spelling is DIFF4 (adds order).
 */
u32 PLEASURE_BOAT_GetPassengerExtra(PleasureBoatWork *work, u32 index, u32 wordIndex)
{
    BoatPassenger *passenger = &work->passengers[index];
    return passenger->extra[wordIndex];
}

u32 PLEASURE_BOAT_GetPassengerOccupied(PleasureBoatWork *work, u32 index)
{
    return work->passengers[index].occupied;
}

void PLEASURE_BOAT_SetPassengerOccupied(PleasureBoatWork *work, int index, int occupied)
{
    work->passengers[index].occupied = occupied;
}

/* Returns 2 when the trip is over (period 4, tick 5400), 1 at each period boundary, else 0. */
int PLEASURE_BOAT_GetTimeEvent(PleasureBoatWork *work)
{
    if (work->timeTicks >= 5400 && work->periodCount >= 4)
        return 2;
    return work->timeTicks % 1350 == 0;
}

PleasureBoatWork *PLEASURE_BOAT_Lock(PleasureBoatWork *work)
{
    work->locked = 1;
    return work;
}

/* Script command: creates the boat work in the event state unless it exists. */
int PLEASURE_BOAT_ScrCmdCreate(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PleasureBoatHolder *holder = GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scrCmdWork)))));
    if (holder->boat == 0)
        holder->boat = PLEASURE_BOAT_Create();
    return 0;
}

/* Script command: frees the boat work. */
int PLEASURE_BOAT_ScrCmdDelete(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    SYMBOL_MAP_DeleteLinkRecord(GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scrCmdWork))))));
    return 0;
}

/* Script command: reads the statistic selected by the next operand into the output variable. */
int PLEASURE_BOAT_ScrCmdGetStat(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PleasureBoatHolder *holder;
    int kind;
    u16 *out;

    SCRCMD_WORK_GetScriptWork(scrCmdWork);
    holder = GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scrCmdWork)))));
    kind = VM_GetU16(vm);
    out = SCRIPT_WORK_ReadWorkPointer(vm, scrCmdWork);
    *out = PLEASURE_BOAT_GetStat(holder->boat, kind);
    return 0;
}

/* Script command: advances the boat clock by the seconds operand; the second operand is the clamp flag. */
int PLEASURE_BOAT_ScrCmdAddTime(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    SCRCMD_WORK_GetScriptWork(scrCmdWork);
    PLEASURE_BOAT_AdvanceTime(GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scrCmdWork)))))->boat, VM_GetU16(vm), VM_GetU16(vm));
    return 0;
}

/* Script command: sets a passenger field; only sub-command 8 (occupied flag) writes anything. */
int PLEASURE_BOAT_ScrCmdSetPassengerInfo(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PleasureBoatHolder *holder;
    int index;
    int subCommand;
    int value;

    SCRCMD_WORK_GetScriptWork(scrCmdWork);
    holder = GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(scrCmdWork)));
    index = SCRIPT_WORK_ReadWorkValue(vm, scrCmdWork);
    subCommand = VM_GetU16(vm);
    VM_GetU16(vm);
    value = SCRIPT_WORK_ReadWorkValue(vm, scrCmdWork);
    switch (subCommand) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        PLEASURE_BOAT_SetPassengerOccupied(holder->boat, index, value == 1);
        break;
    }
    return 0;
}

/* Script command: locks the boat clock and arrivals. */
int PLEASURE_BOAT_ScrCmdLock(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PLEASURE_BOAT_Lock(GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scrCmdWork)))))->boat);
    return 0;
}
