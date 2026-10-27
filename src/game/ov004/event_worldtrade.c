/*
 * file:     event_worldtrade.c
 * unit:     yes
 * function: EVENT_WORLDTRADE_Entry, EVENT_WORLDTRADE_Create, EVENT_WORLDTRADE_Main
 * address:  0x021542C0
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Stage machine on *mode, same family as ov003 EVENT_WORLDTRADE_Entry.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0x87 (135): a linker overlay id for
 * ov135, and the third, 0x02202BAC, lies in ov135's window.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   WORLDTRADE_GetFromSave  0x0200AD6C  thumb
 *   CONSOLE_STAMP_GetFromSave  0x02008B08  thumb
 *   POKEPARTY_GetSaveData  0x0201AD0C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   SYSTEM_DATA_GetMyStatus  0x02008730  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   RECORD_GetFromSave  0x02008C58  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov135_id       0x00000087  data   a1
 *   d_02202BAC     0x02202BAC  data   ov135  a4
 */
struct GameData;
struct GameSystem;
struct GameEvent;
struct GameComm;
struct SaveControl;
struct BoxManager;
struct MyItem;
struct Config;
struct MyStatus;
struct WorldTradeSave;
struct FieldMap;
typedef struct Pair {
    struct FieldMap *fieldMap;
    int unused;
} Pair;

#include "../types.h"
#include "../arm9/ica_anime_shared_types.h"

/* Parameter block read by the world trade overlay (ov135): save data handles gathered when the event starts. */
typedef struct WorldTradeParam {
    void *worldTradeData;
    void *consoleStamp;
    void *party;
    struct BoxManager *boxManager;
    struct WorldTradeSave *zukanSave;
    struct WifiList *wifiList;
    void *wifiHistory;
    void *myStatus;
    struct Config *config;
    void *record;
    struct MyItem *myItem;
    u32 nationalDexEnabled;
    int gsProfileId;
    int reserved;
    int reserved2;
} WorldTradeParam;

/* Work of the world trade event (0x54 bytes). */
typedef struct WorldTradeEventWork {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    WorldTradeParam param;
    struct SaveControl *saveControl;
    struct GameSystem *paramGameSystem;
    u32 hideFieldObjects;
} WorldTradeEventWork;

typedef char WorldTradeEventWork_SizeCheck[(sizeof(void *) != 4 || (sizeof(WorldTradeEventWork) == 0x54)) ? 1 : -1];

#include "../arm9/gamesystem.h"
#include "../arm9/game_event.h"
#include "../arm9/game_comm.h"
#include "../arm9/mi_memory.h"
#include "../arm9/game_data.h"
struct WorldTradeData;
#include "../arm9/worldtrade.h"
struct ConsoleStamp;
#include "../arm9/console_stamp.h"
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/zukan_save.h"
struct FieldState;
struct WifiHistory;
#include "../arm9/wifi_history.h"
#include "../arm9/system_data.h"
#include "../arm9/record.h"
struct ZukanSave;
struct WifiList;
#include "../arm9/wifilist.h"
#include "../arm9/gfl_use.h"
struct FieldMap;
#include "../arm9/field_status.h"
#include "../ov021/event_fieldmap_control.h"
#include "../arm9/procsys.h"
struct GameEvent *EVENT_WORLDTRADE_Entry(struct GameSystem *gameSystem, Pair *request);
struct GameEvent *EVENT_WORLDTRADE_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int unused);
int EVENT_WORLDTRADE_Main(struct GameEvent *event, int *seq, void *work);
extern char ov135_id[];
extern const ProcData d_02202BAC;

/* Overlay entry point: unpacks the request and creates the event. */
struct GameEvent *EVENT_WORLDTRADE_Entry(struct GameSystem *gameSystem, Pair *request)
{
    return EVENT_WORLDTRADE_Create(gameSystem, request->fieldMap, request->unused);
}

struct GameEvent *EVENT_WORLDTRADE_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int unused)
{
    struct GameData *gameData;
    struct GameEvent *event;
    WorldTradeEventWork *work;

    gameData = GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_WORLDTRADE_Main, sizeof(WorldTradeEventWork));
    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm((const struct GameSystem *)gameSystem)))
        GAME_COMM_RequestExitNoCallback(GAMESYSTEM_GetGameComm((const struct GameSystem *)gameSystem));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(WorldTradeEventWork));
    work->gameSystem = (struct GameSystem *)gameSystem;
    work->fieldMap = fieldMap;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->param.worldTradeData = WORLDTRADE_GetFromSave(work->saveControl);
    work->param.consoleStamp = CONSOLE_STAMP_GetFromSave(work->saveControl);
    work->param.party = POKEPARTY_GetSaveData(work->saveControl);
    work->param.boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager(gameData);
    work->param.zukanSave = ZUKAN_SAVE_GetFromGameData(gameData);
    work->param.wifiList = GAME_DATA_GetWifiList(gameData);
    work->param.wifiHistory = WIFI_HISTORY_GetBlock(work->saveControl);
    work->param.myStatus = SYSTEM_DATA_GetMyStatus(work->saveControl);
    work->param.config = SYSTEM_DATA_GetConfig(work->saveControl);
    work->param.record = RECORD_GetFromSave(work->saveControl);
    work->param.myItem = GAME_DATA_GetMyItem(gameData);
    work->paramGameSystem = (struct GameSystem *)gameSystem;
    work->param.nationalDexEnabled = ZUKAN_SAVE_IsNationalDexEnabled((struct ZukanSave *)work->param.zukanSave);
    work->param.gsProfileId = WIFILIST_GetGsProfileId(work->param.wifiList);
    work->param.reserved = 0;
    work->param.reserved2 = 0;
    return event;
}

int EVENT_WORLDTRADE_Main(struct GameEvent *event, int *seq, void *workPtr)
{
    WorldTradeEventWork *work = workPtr;
    switch (*seq) {
    case 0:
        if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(work->gameSystem)) == 0)
            *seq = 1;
        break;
    case 1:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(work->gameSystem, work->fieldMap, 0, 0));
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        *seq = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)work->gameSystem, work->fieldMap));
        *seq = 3;
        break;
    case 3:
        GAMESYSTEM_CallProc(work->gameSystem, (uptr)ov135_id, &d_02202BAC, &work->param);
        *seq = 4;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(work->gameSystem) == 0) {
            GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
            GFL_USE_FadeInBgmFull(0x3C);
            GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(work->gameSystem));
            *seq = 5;
        }
        break;
    case 5:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}
