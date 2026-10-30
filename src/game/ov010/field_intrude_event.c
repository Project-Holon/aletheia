/*
 * file:     field_intrude_event.c
 * unit:     yes
 * function: FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent, FIELD_INTRUDE_EVENT_IntrudeRequestEventMain, FIELD_INTRUDE_EVENT_GetEdgePosition, FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent, FIELD_INTRUDE_EVENT_StartSymbolEntry, FIELD_INTRUDE_EVENT_SymbolEntryEventMain
 * address:  0x0216B24C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_0216B24C.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_RequestPartnerSymbolPage  0x02176850  thumb  ov011
 *   INTRUDE_COMM_IsPartnerSymbolPageReceived  0x02176870  thumb  ov011
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   SYMBOL_MAP_GetSelectedCellTile  0x021665D0  thumb  ov010
 *   GAME_DATA_SetSymbolMapFlag  0x02012FA4  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */
#include "field_intrude_event_shared_types.h"

struct GameEvent;

/* Work of the intrude request event: the word to report into and the request. */
typedef struct {
    u16 *result;        /* 0x00 */
    u8 requestType;     /* 0x04 */
    u8 padding[3];
} IntrudeRequestWork;

/* Work of the symbol entry event (0x24 bytes). */
typedef struct {
    u16 *result;        /* 0x00 */
    u16 tileId;         /* 0x04 */
    u8 padding06[2];
    FxVec3 position;    /* 0x08 */
    u16 edge;           /* 0x14 */
    u8 cellId;          /* 0x16 */
    u8 padding17;
    u16 accepted;       /* 0x18 */
    u8 padding1A[2];
    u32 playSe;         /* 0x1C */
    u32 solo;           /* 0x20 */
} SymbolEntryWork;

#include "../arm9/gamesystem.h"



#include "../arm9/mi_memory.h"

struct GameComm;

struct IntrudeCommSys;
struct FieldMap;
struct FieldPlayer;

                               

                                  




#include "../ov021/fieldmap.h"
struct Mmdl;

#include "../ov021/field_player.h"
struct VecFx32;

#include "fldmmdl.h"
struct FieldMap;
struct MmdlSys;

struct MmdlSys;



#include "../arm9/gfl_use.h"

#include "../ov021/event_fieldmap_control.h"

#include "symbol_map.h"
struct GameData;
struct VecFx32;

                              

#include "../ov020/event_mapchange.h"

#include "../ov021/fldmmdl_blact.h"
#include "../arm9/game_event.h"
#include "intrude_comm_query.h"
#include "../ov011/intrude_comm.h"
#include "../ov011/intrude_battle.h"
#ifndef __MWERKS__
#include "../arm9/game_data.h"
#endif



int FIELD_INTRUDE_EVENT_IntrudeRequestEventMain(struct GameEvent *event, int *state, void *work);

void FIELD_INTRUDE_EVENT_GetEdgePosition(FxVec3 *src, int edge, FxVec3 *dst);

struct GameEvent *FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId);

int FIELD_INTRUDE_EVENT_SymbolEntryEventMain(struct GameEvent *event, int *state, void *work);

/* Starts the intrude request event: sends requestType and reports 0 or 1 into *result. */
struct GameEvent *FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent(struct GameSystem *gameSystem, u16 *result, int requestType)
{
    struct GameEvent *event;
    IntrudeRequestWork *work;
    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_INTRUDE_EVENT_IntrudeRequestEventMain, sizeof(IntrudeRequestWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(*work));
    work->result = result;
    work->requestType = requestType;
    return event;
}

int FIELD_INTRUDE_EVENT_IntrudeRequestEventMain(struct GameEvent *event, int *state, void *workPtr)
{
    IntrudeRequestWork *work = workPtr;
    u8 *intrudeComm;
    u16 *result;

    intrudeComm = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
    if (intrudeComm == 0) {
        result = work->result;
        if (result != 0)
            *result = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (INTRUDE_COMM_RequestPartnerSymbolPage((struct IntrudeCommSys *)intrudeComm, work->requestType) == 1)
            (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_IsPartnerSymbolPageReceived((struct IntrudeCommSys *)intrudeComm) == 1)
            (*state)++;
        break;
    case 2:
        result = work->result;
        if (result != 0)
            *result = 1;
        return 1;
    }
    return 0;
}

/*
 * Copies a 12-byte position, then moves one component to the map border
 * named by edge 0-3 (edges 4-9 keep it as copied).
 */
void FIELD_INTRUDE_EVENT_GetEdgePosition(FxVec3 *src, int edge, FxVec3 *dst)
{
    *dst = *src;
    switch (edge) {
    case 0:
        dst->z = 0x62 << 14;
        break;
    case 1:
        dst->z = 0x26 << 14;
        break;
    case 2:
        dst->x = 0x6A << 14;
        break;
    case 3:
        dst->x = 0x16 << 14;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

struct GameEvent *FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId)
{
    void *gameData;
    struct GameEvent *event;
    SymbolEntryWork *work;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_INTRUDE_EVENT_SymbolEntryEventMain, sizeof(SymbolEntryWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(*work));
    work->position = *position;
    work->edge = edge;
    work->result = 0;
    work->cellId = cellId;
    work->playSe = playSe;
    if (INTRUDE_COMM_GetPartnerSlot(GAMESYSTEM_GetGameComm(gameSystem), gameData) == 4)
        work->solo = 1;
    return event;
}

struct GameEvent *FIELD_INTRUDE_EVENT_StartSymbolEntry(struct GameSystem *gameSystem, int edge, int cellId)
{
    FxVec3 position;
    void *fieldMap;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAMESYSTEM_GetGameData(gameSystem);
    FIELD_INTRUDE_EVENT_GetEdgePosition((void *)FLDMMDL_GetPosPtr((void *)FIELD_PLAYER_GetMmdl((void *)FIELDMAP_GetFieldPlayer(fieldMap))), edge, &position);
    return FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(gameSystem, edge != 9, &position, edge, cellId);
}

/*
 * Seven-state proc of the symbol entry: ask the intrude partner (unless
 * playing solo), fade out, show the symbol cell's tile, fade back in, and
 * write 0 or 1 to the caller's result word.
 */
int FIELD_INTRUDE_EVENT_SymbolEntryEventMain(struct GameEvent *event, int *state, void *workPtr)
{
    SymbolEntryWork *work = workPtr;
    void *gameSystem = GAME_EVENT_GetGameSystem(event);
    void *gameData;
    void *fieldMap;

    GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        if (work->solo == 1) {
            *state = 2;
        } else {
            GAME_EVENT_CallEvent(event, FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent(gameSystem, &work->accepted, work->cellId));
            (*state)++;
        }
        break;
    case 1:
        if (work->accepted == 0) {
            if (work->result != 0)
                *work->result = 0;
            *state = 6;
        } else {
            (*state)++;
        }
        break;
    case 2:
        if (work->playSe != 0)
            GFL_USE_PlaySeDefaultVolume(1369);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 9, 0));
        (*state)++;
        break;
    case 3:
        work->tileId = SYMBOL_MAP_GetSelectedCellTile(gameSystem, work->cellId);
        GAME_DATA_SetSymbolMapFlag(gameData, work->cellId);
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(gameSystem, fieldMap, work->tileId, (struct VecFx32 *)(&work->position), work->edge));
        (*state)++;
        break;
    case 4:
        if (FLDMMDL_BLACT_IsReservePending(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(gameSystem))) == 1)
            break;
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 9, 0, 0, 0, 0));
        (*state)++;
        break;
    case 5:
        if (work->result != 0)
            *work->result = 1;
        *state = 6;
        break;
    case 6:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        return 1;
    }
    return 0;
}
