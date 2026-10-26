/*
 * file:     event_bsubway_comm.c
 * unit:     yes
 * function: EVENT_BSUBWAY_COMM_Start, EVENT_BSUBWAY_COMM_CreateEvent, EVENT_BSUBWAY_COMM_EventMain
 * address:  0x021542C0
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Stage machine on *mode, same family as ov004 EVENT_WORLDTRADE_Main; the task
 * callback EVENT_BSUBWAY_COMM_CreateEvent installs.  Second argument to GAMESYSTEM_CallProc is
 * pooled 0x74 (116), a linker overlay id; the third lies in ov116.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov116_id       0x00000074  data   a1
 *   d_021D83A4     0x021D83A4  data   ov116  a4
 */
struct GameSystem;
struct GameComm;
struct GameEvent;
struct GameEventWork;
struct ProcHandle;
typedef struct BsubwayProcArgs {
    int value;
    int *resultPtr;
} BsubwayProcArgs;

/* Event work (0x10 bytes); the Wi-Fi Battle Subway screen (ov116) reads it as its parameter. */
typedef struct BsubwayCommEventWork {
    int value;
    struct GameSystem *gameSystem;
    int result;
    unsigned short *resultPtr;
} BsubwayCommEventWork;

#include "../types.h"
#include "../arm9/ica_anime_shared_types.h"

struct GameData;

#include "../arm9/gamesystem.h"
#include "../arm9/game_event.h"
#include "../arm9/game_comm.h"
struct FieldMap;
#include "../arm9/field_status.h"
#include "../ov021/event_fieldmap_control.h"
#include "../arm9/procsys.h"
struct GameEvent *EVENT_BSUBWAY_COMM_Start(struct GameSystem *gameSystem, void *arg);
struct GameEvent *EVENT_BSUBWAY_COMM_CreateEvent(struct GameSystem *gameSystem, int value, int *resultPtr);
int EVENT_BSUBWAY_COMM_EventMain(struct GameEvent *event, int *stage, void *work);
extern char ov116_id[];
extern const ProcData d_021D83A4;

struct GameEvent *EVENT_BSUBWAY_COMM_Start(struct GameSystem *gameSystem, void *arg)
{
    BsubwayProcArgs *args = arg;

    return EVENT_BSUBWAY_COMM_CreateEvent(gameSystem, args->value, args->resultPtr);
}

struct GameEvent *EVENT_BSUBWAY_COMM_CreateEvent(struct GameSystem *gameSystem, int value, int *resultPtr)
{
    struct GameEvent *event;
    BsubwayCommEventWork *work;

    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_BSUBWAY_COMM_EventMain, sizeof(BsubwayCommEventWork));
    work = GAME_EVENT_GetWork(event);
    work->value = value;
    work->gameSystem = gameSystem;
    work->resultPtr = (unsigned short *)resultPtr;
    if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback((struct GameComm *)GAMESYSTEM_GetGameComm(gameSystem));
    return event;
}

int EVENT_BSUBWAY_COMM_EventMain(struct GameEvent *event, int *stage, void *workPtr)
{
    BsubwayCommEventWork *work = workPtr;
    struct GameSystem *gameSystem = work->gameSystem;
    void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

    switch (*stage) {
    case 0:
        if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)) == 0)
            (*stage)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*stage)++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent(gameSystem, (struct FieldMap *)fieldMap));
        (*stage)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov116_id, &d_021D83A4, work);
        (*stage)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (work->result == 0)
                *work->resultPtr = 1;
            else
                *work->resultPtr = 0;
            (*stage)++;
        }
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*stage)++;
        break;
    case 6:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*stage)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}
