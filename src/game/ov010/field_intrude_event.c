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
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SendValueNow  0x02176850  thumb  ov011
 *   INTRUDE_COMM_IsRecordReceived  0x02176870  thumb  ov011
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   ICA_ANIME_GetField20  0x0201210C  thumb
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

extern void *ICA_ANIME_GetField1C(const struct GameSystem *gameSystem);

extern struct GameEvent *GAME_EVENT_Create(void *owner, void *parent, void *proc, u32 workSize);

extern void *func_020124E8(struct GameEvent *event);

extern void MI_CpuFill8(void *dest, int value, int size);

extern void *GAME_EVENT_GetGameSystem(struct GameEvent *event);

extern void *ICA_ANIME_GetField24(const struct GameSystem *gameSystem);

extern u8 *INTRUDE_COMM_GetWorkIfRunning(void *gameComm);

extern int INTRUDE_COMM_SendValueNow(u8 *intrudeComm, u8 requestType);

extern u32 INTRUDE_COMM_IsRecordReceived(u8 *intrudeComm);

extern u8 INTRUDE_COMM_GetPartnerSlot(void *gameComm, void *gameData);

extern void *ICA_ANIME_GetField20(const struct GameSystem *gameSystem);

extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);

extern void *FIELD_PLAYER_GetMmdl(void *player);

extern void *FLDMMDL_GetPosPtr(void *player);

extern void *FIELDMAP_GetMmdlSys(void *fieldMap);

extern void FLDMMDL_SysPauseMove(void *mmdlSys);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, void *fieldMap, u32 a, u32 b);

extern int SYMBOL_MAP_GetSelectedCellTile(int gameSystem, int cellId);

extern void GAME_DATA_SetSymbolMapFlag(void *gameData, unsigned char cellId);

extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *gameSystem, void *fieldMap, u32 tileId, void *position, u32 edge);

extern int FLDMMDL_BLACT_IsReservePending(void *mmdlSys);

extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, void *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e);

extern u32 *FLDMMDL_SysResumeMove(void *mmdlSys);

int FIELD_INTRUDE_EVENT_IntrudeRequestEventMain(struct GameEvent *event, int *state, IntrudeRequestWork *work);

void FIELD_INTRUDE_EVENT_GetEdgePosition(FxVec3 *src, int edge, FxVec3 *dst);

struct GameEvent *FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId);

int FIELD_INTRUDE_EVENT_SymbolEntryEventMain(struct GameEvent *event, u32 *state, SymbolEntryWork *work);

/* Starts the intrude request event: sends requestType and reports 0 or 1 into *result. */
struct GameEvent *FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent(struct GameSystem *gameSystem, u16 *result, int requestType)
{
    struct GameEvent *event;
    IntrudeRequestWork *work;
    ICA_ANIME_GetField1C(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_INTRUDE_EVENT_IntrudeRequestEventMain, 8);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 8);
    work->result = result;
    work->requestType = requestType;
    return event;
}

int FIELD_INTRUDE_EVENT_IntrudeRequestEventMain(struct GameEvent *event, int *state, IntrudeRequestWork *work)
{
    u8 *intrudeComm;
    u16 *result;

    intrudeComm = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    if (intrudeComm == 0) {
        result = work->result;
        if (result != 0)
            *result = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (INTRUDE_COMM_SendValueNow(intrudeComm, work->requestType) == 1)
            (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_IsRecordReceived(intrudeComm) == 1)
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

    gameData = ICA_ANIME_GetField1C(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_INTRUDE_EVENT_SymbolEntryEventMain, 0x24);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 0x24);
    work->position = *position;
    work->edge = edge;
    work->result = 0;
    work->cellId = cellId;
    work->playSe = playSe;
    if (INTRUDE_COMM_GetPartnerSlot(ICA_ANIME_GetField24(gameSystem), gameData) == 4)
        work->solo = 1;
    return event;
}

struct GameEvent *FIELD_INTRUDE_EVENT_StartSymbolEntry(struct GameSystem *gameSystem, int edge, int cellId)
{
    FxVec3 position;
    void *fieldMap;

    fieldMap = ICA_ANIME_GetField20(gameSystem);
    ICA_ANIME_GetField1C(gameSystem);
    FIELD_INTRUDE_EVENT_GetEdgePosition(FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap))), edge, &position);
    return FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(gameSystem, edge != 9, &position, edge, cellId);
}

/*
 * Seven-state proc of the symbol entry: ask the intrude partner (unless
 * playing solo), fade out, show the symbol cell's tile, fade back in, and
 * write 0 or 1 to the caller's result word.
 */
int FIELD_INTRUDE_EVENT_SymbolEntryEventMain(struct GameEvent *event, u32 *state, SymbolEntryWork *work)
{
    void *gameSystem = GAME_EVENT_GetGameSystem(event);
    void *gameData;
    void *fieldMap;

    ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
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
        work->tileId = SYMBOL_MAP_GetSelectedCellTile((int)gameSystem, work->cellId);
        GAME_DATA_SetSymbolMapFlag(gameData, work->cellId);
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(gameSystem, fieldMap, work->tileId, &work->position, work->edge));
        (*state)++;
        break;
    case 4:
        if (FLDMMDL_BLACT_IsReservePending(FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(gameSystem))) == 1)
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
