/*
 * file:     event_wifibattlematch.c
 * unit:     yes
 * function: EVENT_WIFIBATTLEMATCH_Main, EVENT_WIFIBATTLEMATCH_Create, EVENT_WIFIBATTLEMATCH_Entry
 * address:  0x021542C0
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov199_id       0x000000C7  data   a1
 *   d_02213C4C     0x02213C4C  data   ov199  a4
 *   d_02154460     0x02154460  data   ov002  a4
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 */
struct GameSystem;
struct GameEvent;
struct GameData;
struct GameComm;
#include "../types.h"
#include "../arm9/ica_anime_shared_types.h"

/* Parameter block read by the Wi-Fi battle match overlay (ov199), 0x14 bytes. */
typedef struct WifiBattleMatchParam {
    struct GameData *gameData;
    u32 matchKind;
    u32 entryMode;
    u32 ratedFlag;
    u32 reserved;
} WifiBattleMatchParam;

/* Work of the Wi-Fi battle match event (0x20 bytes). */
typedef struct WifiBattleMatchEventWork {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    WifiBattleMatchParam *param;
    u32 entryMode;
    u32 ratedFlag;
    u32 matchKind;
    u32 hideFieldObjects;
} WifiBattleMatchEventWork;

/* Launch request built by the script command: the field map and three words. */
typedef struct WifiBattleMatchRequest {
    struct FieldMap *fieldMap;
    s32 entryMode;
    s32 ratedFlag;
    s32 matchKind;
} WifiBattleMatchRequest;

#include "../arm9/gamesystem.h"
#include "../arm9/game_comm.h"
#include "../arm9/gfl_use.h"
struct FieldMap;
#include "../arm9/field_status.h"
#include "../arm9/game_event.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../ov021/event_fieldmap_control.h"
#include "../arm9/procsys.h"
int EVENT_WIFIBATTLEMATCH_Main(struct GameEvent *event, int *seq, void *work);
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, struct FieldMap *fieldMap, int entryMode, int ratedFlag, int matchKind);
struct GameEvent *EVENT_WIFIBATTLEMATCH_Entry(struct GameSystem *gameSystem, WifiBattleMatchRequest *request);
extern char ov199_id[];
extern const ProcData d_02213C4C;
extern char d_02154460[];

int EVENT_WIFIBATTLEMATCH_Main(struct GameEvent *event, int *seq, void *workPtr)
{
    WifiBattleMatchEventWork *work = workPtr;
    struct GameSystem *gameSystem = work->gameSystem;
    WifiBattleMatchParam *param;

    switch (*seq) {
    case 0:
        if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)) == 0) {
            work->savedBgmNo = GFL_USE_GetBgmNo();
            GFL_USE_FadeOutBgm(6);
            (*seq)++;
        }
        break;
    case 1:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, work->fieldMap));
        (*seq)++;
        break;
    case 3:
        param = GFL_HEAP_Alloc(4, sizeof(WifiBattleMatchParam), 1, d_02154460, 0x86);
        work->param = param;
        param->entryMode = work->entryMode;
        param->gameData = GAMESYSTEM_GetGameData(gameSystem);
        param->matchKind = work->matchKind;
        param->ratedFlag = work->ratedFlag;
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov199_id, &d_02213C4C, work->param);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            GFL_HEAP_Free(work->param);
            (*seq)++;
        }
        break;
    case 5:
        (*seq)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        (*seq)++;
        break;
    case 7:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}

/*
 * Allocator + guard + link setup, stores five constructor arguments.
 */
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, struct FieldMap *fieldMap, int entryMode, int ratedFlag, int matchKind)
{
    void *event = GAME_EVENT_Create(gameSystem, 0, EVENT_WIFIBATTLEMATCH_Main, sizeof(WifiBattleMatchEventWork));
    WifiBattleMatchEventWork *work;

    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback(GAMESYSTEM_GetGameComm(gameSystem));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->entryMode = (u16)entryMode;
    work->ratedFlag = ratedFlag;
    work->matchKind = matchKind;
    work->hideFieldObjects = 0;
    return event;
}

/* Overlay entry point: unpacks the four-word request and creates the event. */
struct GameEvent *EVENT_WIFIBATTLEMATCH_Entry(struct GameSystem *gameSystem, WifiBattleMatchRequest *request)
{
    return EVENT_WIFIBATTLEMATCH_Create(gameSystem, request->fieldMap, request->entryMode, request->ratedFlag, request->matchKind);
}
