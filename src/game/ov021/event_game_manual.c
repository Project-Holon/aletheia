/*
 * file:     event_game_manual.c
 * unit:     yes
 * function: EVENT_GAME_MANUAL_Create, EVENT_GAME_MANUAL_Main, EVENT_GAME_MANUAL_SetResult
 * address:  0x021D30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_palace_sys.c at 0x021D30B8 (__FILE__ anchor event_game_manual.c at 0x021D30B8 (first anchored function)).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   d_021DE698     0x021DE698  data  ov021  a4
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   abs_id_e1      0x000000E1  data
 *   d_021BBDE4    0x021BBDE4  data  ov225  a4
 */
struct GameSystem;
struct GameData;
struct GameEvent;
#include "../types.h"

/* Handed to the game manual application (ov225); it writes the result. */
typedef struct GameManualParam {
    struct GameData *gameData;      /* 0x00 */
    u32 result;                     /* 0x04: 0 when the manual returns nothing */
} GameManualParam;

typedef struct EventGameManualWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    void *fieldMap;                 /* 0x04 */
    GameManualParam *param;         /* 0x08 */
    u16 *resultOut;                 /* 0x0C */
} EventGameManualWork;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_event.h"
struct FieldMap;
#include "../arm9/field_status.h"
struct GameEvent *EVENT_GAME_MANUAL_Create(struct GameSystem *gameSystem, u16 *resultOut);
int EVENT_GAME_MANUAL_Main(struct GameEvent *event, int *seq, void *work);
void EVENT_GAME_MANUAL_SetResult(EventGameManualWork *work);
extern char d_021DE698[];        /* "event_game_manual.c" */
extern unsigned char abs_id_e1[]; /* FS_OVERLAY_ID(ov225) */
extern char d_021BBDE4[];        /* ov225 proc table */

struct GameEvent *EVENT_GAME_MANUAL_Create(struct GameSystem *gameSystem, u16 *resultOut)
{
    struct GameData *gameData;
    void *fieldMap;
    struct GameEvent *event;
    EventGameManualWork *work;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_GAME_MANUAL_Main, sizeof(EventGameManualWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->resultOut = resultOut;
    work->param = GFL_HEAP_Alloc(4, sizeof(GameManualParam), 0, d_021DE698, 0x4a);
    work->param->gameData = gameData;
    return event;
}

/*
 * abs_id_e1 is FS_OVERLAY_ID(ov225) (overlay_id).  d_021BBDE4 is ov225's
 * proc table (Thumb entries 0x021B95A1, 0x021B96BD, 0x021B9661), handed
 * to the proc loader with ov225's id; it resolves as sole-ref/data in
 * ov225 through the loaded-overlay exception to the own-window rule
 * (attest_xwin_loaded(), 2026-10-02).  No overlay listing labels
 * 0x021BBDE4 as a function; ov114 has ARM code there.
 */
int EVENT_GAME_MANUAL_Main(struct GameEvent *event, int *seq, void *workPtr)
{
    EventGameManualWork *work = workPtr;
    switch (seq[0]) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent(work->gameSystem, work->fieldMap, (sptr)abs_id_e1, d_021BBDE4, work->param));
        seq[0]++;
        break;
    case 1:
        EVENT_GAME_MANUAL_SetResult(work);
        GFL_HEAP_Free(work->param);
        return 1;
    }
    return 0;
}

void EVENT_GAME_MANUAL_SetResult(EventGameManualWork *work)
{
    if (work->param->result == 0) {
        *work->resultOut = 0;
    } else {
        *work->resultOut = 1;
    }
}
