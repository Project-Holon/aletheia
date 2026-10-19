/*
 * file:     pleasure_boat.c
 * unit:     yes
 * function: PLEASURE_BOAT_Create, PLEASURE_BOAT_AckEvent, PLEASURE_BOAT_Update, PLEASURE_BOAT_AdvanceTime, PLEASURE_BOAT_GetStat, PLEASURE_BOAT_GetPassengerParam, PLEASURE_BOAT_GetPassengerType, PLEASURE_BOAT_GetPassengerExtra, PLEASURE_BOAT_GetPassengerOccupied, PLEASURE_BOAT_SetPassengerOccupied, PLEASURE_BOAT_GetTimeEvent, PLEASURE_BOAT_Lock, PLEASURE_BOAT_ScrCmdCreate, PLEASURE_BOAT_ScrCmdDelete, PLEASURE_BOAT_ScrCmdGetStat, PLEASURE_BOAT_ScrCmdAddTime, PLEASURE_BOAT_ScrCmdSetPassengerInfo, PLEASURE_BOAT_ScrCmdLock
 * address:  0x021C8608
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_flash.c, pleasure_boat.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   DAILY_LAYOUT_Generate  0x021F36C0  thumb  ov036
 *   gPleasureBoatFileName     0x021DE534  data  a4
 *   ov036_id     0x00000024  data  a4
 *   PLEASURE_BOAT_GetTimeEvent  0x021C87E0  thumb  ov021
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   PLEASURE_BOAT_Create  0x021C8608  thumb  ov021
 *   SYMBOL_MAP_DeleteLinkRecord  0x021666A4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   PLEASURE_BOAT_GetStat  0x021C8738  thumb  ov021
 *   PLEASURE_BOAT_AdvanceTime  0x021C86E8  thumb  ov021
 */
#include "field_flash_shared_types.h"
#include "pleasure_boat_types.h"
#include "fld_wipe_3dobj_shared_types.h"

extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern int GF_OVERLAY_Load(s32 overlayId);

extern void GF_OVERLAY_Unload(int overlayId);

extern void DAILY_LAYOUT_Generate(PleasureBoatWork *work);

extern int PLEASURE_BOAT_GetTimeEvent(PleasureBoatWork *work);

extern GameEvent *SCRIPT_SYS_CreateScriptEventSimple(GameSystem *gameSystem, int a, int b, int scriptId);

extern char gPleasureBoatFileName;

extern char ov036_id[];

PleasureBoatWork *PLEASURE_BOAT_Create(void);

void PLEASURE_BOAT_AckEvent(PleasureBoatWork *work);

GameEvent *PLEASURE_BOAT_Update(GameSystem *gameSystem, PleasureBoatWork *work);

void PLEASURE_BOAT_AdvanceTime(PleasureBoatWork *work, int seconds, int clamp);

int PLEASURE_BOAT_GetStat(PleasureBoatWork *work, int kind);

PleasureBoatWork *PLEASURE_BOAT_Create(void)
{
    PleasureBoatWork *work = GFL_HEAP_Alloc(5, sizeof(PleasureBoatWork), 1, &gPleasureBoatFileName, 0x31);
    work->eventPending = 0;
    work->timeTicks = 0;
    work->periodCount = 0;
    work->groupCount[0] = 0;
    work->groupCount[1] = 0;
    work->groupCount[2] = 0;
    work->groupCount[3] = 0;
    work->locked = 0;
    GF_OVERLAY_Load((int)ov036_id); /* stand-in: overlay id passed as a raw address constant; a plain 0x24 changes the literal pool */
    DAILY_LAYOUT_Generate(work);
    GF_OVERLAY_Unload((int)ov036_id);
    return work;
}

/* Plays the arrival jingle and moves to the next period once the pending flag is set. */
void PLEASURE_BOAT_AckEvent(PleasureBoatWork *work)
{
    if (work != 0 && work->locked == 0 && work->eventPending != 0) {
        GFL_USE_PlaySeDefaultVolume(0x6dd);
        work->periodCount++;
        work->eventPending = 0;
    }
}

/* Advances the boat clock; returns the script event when the boat reaches a milestone. */
GameEvent *PLEASURE_BOAT_Update(GameSystem *gameSystem, PleasureBoatWork *work)
{
    GameEvent *event;
    int hasEvent;
    int milestone;
    if (work == 0) {
        return 0;
    }
    if (work->locked != 0) {
        return 0;
    }
    work->timeTicks = work->timeTicks + 1;
    milestone = PLEASURE_BOAT_GetTimeEvent(work);
    switch (milestone) {
    case 1:
        work->eventPending = 1;
        hasEvent = 0;
        break;
    case 2:
        event = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 1, 0, 0x8015);
        hasEvent = 1;
        break;
    default:
        hasEvent = 0;
        break;
    }
    if (hasEvent == 0) {
        event = 0;
    }
    return event;
}

/*
 * The sum is built in two statements (`r = f4 % 1350; r += b * 30;`) so
 * the multiply lands after the _s32_div_f call; one expression, or a
 * separate `t = b * 30` local, hoists it above the call into r4.
 * Adds `seconds` of boat time (30 ticks per second, 1350 ticks per period).
 * At a period end the clock stops one tick short (clamp) or enters the next period.
 */
void PLEASURE_BOAT_AdvanceTime(PleasureBoatWork *work, int seconds, int clamp)
{
    int ticks;
    ticks = work->timeTicks % 1350;
    ticks += seconds * 30;
    if (ticks >= 1350) {
        if (clamp) {
            work->timeTicks = (work->periodCount + 1) * 1350 - 1;
        } else {
            work->timeTicks = (work->periodCount + 1) * 1350;
            work->periodCount++;
        }
    } else {
        work->timeTicks += seconds * 30;
    }
}

/* Reads one boat statistic: kinds 0-3 are the group counters, 4 the visitor count, 5 the used passenger slots. */
int PLEASURE_BOAT_GetStat(PleasureBoatWork *work, int kind)
{
    int result;
    int i;
    switch (kind) {
    case 0:
        result = work->groupCount[0];
        break;
    case 1:
        result = work->groupCount[1];
        break;
    case 2:
        result = work->groupCount[2];
        break;
    case 3:
        result = work->groupCount[3];
        break;
    case 4:
        result = work->visitorCount;
        break;
    case 5:
        result = 0;
        for (i = 0; i < 15; i++) {
            if (work->passengers[i].occupied != 0) {
                result++;
            }
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

typedef struct GameData GameData;

extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrCmdWork *scrCmdWork);

extern FieldMap *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);

extern GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap);

extern GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);

extern PleasureBoatHolder *GAME_DATA_GetEventState(GameData *gameData);

extern void SYMBOL_MAP_DeleteLinkRecord(PleasureBoatHolder *holder);

extern void *SCRCMD_WORK_GetScriptWork(ScrCmdWork *scrCmdWork);

extern u16 VM_GetU16(ScriptVm *vm);

extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrCmdWork *scrCmdWork);

extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrCmdWork *scrCmdWork);

u32 PLEASURE_BOAT_GetPassengerParam(PleasureBoatWork *work, u32 index);

u32 PLEASURE_BOAT_GetPassengerType(PleasureBoatWork *work, u32 index);

u32 PLEASURE_BOAT_GetPassengerExtra(PleasureBoatWork *work, u32 index, u32 wordIndex);

u32 PLEASURE_BOAT_GetPassengerOccupied(PleasureBoatWork *work, u32 index);

void PLEASURE_BOAT_SetPassengerOccupied(PleasureBoatWork *work, int index, int occupied);

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
