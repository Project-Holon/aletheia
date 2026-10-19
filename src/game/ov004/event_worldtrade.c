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
typedef struct Pair {
    int fieldMap;
    int unused;
} Pair;

typedef unsigned int   u32;

/* Parameter block read by the world trade overlay (ov135): save data handles gathered when the event starts. */
typedef struct WorldTradeParam {
    void *worldTradeData;
    void *consoleStamp;
    void *party;
    struct BoxManager *boxManager;
    struct WorldTradeSave *zukanSave;
    u32 wifiList;
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
    int fieldMap;
    WorldTradeParam param;
    struct SaveControl *saveControl;
    struct GameSystem *paramGameSystem;
    u32 hideFieldObjects;
} WorldTradeEventWork;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef char WorldTradeEventWork_SizeCheck[sizeof(WorldTradeEventWork) == 0x54 ? 1 : -1];

struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
void *GAME_EVENT_Create(void *gameSystem, void *a, void *callback, u32 workSize);
struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
u32 GAME_COMM_GetKind(struct GameComm *comm);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *GAME_EVENT_GetWork(struct GameEvent *event);
void MI_CpuFill8(void *dst, int value, int size);
struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
struct WorldTradeData;
struct WorldTradeData *WORLDTRADE_GetFromSave(struct SaveControl *save);
struct ConsoleStamp;
struct ConsoleStamp *CONSOLE_STAMP_GetFromSave(struct SaveControl *control);
struct Party;
struct Party *POKEPARTY_GetSaveData(struct SaveControl *save);
u32 GAME_DATA_GetBoxManager(const struct GameData *gameData);
void *ZUKAN_SAVE_GetFromGameData(void *gameData);
struct FieldState;
struct FieldState *GAME_DATA_GetWifiList(const struct GameData *gameData);
struct WifiHistory;
struct WifiHistory *WIFI_HISTORY_GetBlock(struct SaveControl *saveControl);
struct MyStatus *SYSTEM_DATA_GetMyStatus(void *saveControl);
struct Config *SYSTEM_DATA_GetConfig(void *saveControl);
void *RECORD_GetFromSave(void *saveControl);
void *GAME_DATA_GetMyItem(const struct GameData *gameData);
struct ZukanSave;
u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *pZukan);
struct WifiList;
int WIFILIST_GetGsProfileId(struct WifiList *list);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 frames);
struct FieldMap;
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int skipWait);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int skipWait, int restoreBg, unsigned char seasonShown, unsigned char seasonTarget);
int EVENT_WORLDTRADE_Entry(int gameSystem, Pair *request);
int EVENT_WORLDTRADE_Create(int gameSystem, int fieldMap, int unused);
u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork *work);
extern char ov135_id[];
extern char d_02202BAC[];



/* Overlay entry point: unpacks the request and creates the event. */
int EVENT_WORLDTRADE_Entry(int gameSystem, Pair *request)
{
    return EVENT_WORLDTRADE_Create(gameSystem, request->fieldMap, request->unused);
}



int EVENT_WORLDTRADE_Create(int gameSystem, int fieldMap, int unused)
{
    int gameData;
    int event;
    WorldTradeEventWork *work;

    gameData = (int)GAMESYSTEM_GetGameData((const struct GameSystem *)gameSystem);
    event = (int)GAME_EVENT_Create((void *)gameSystem, 0, EVENT_WORLDTRADE_Main, 0x54);
    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm((const struct GameSystem *)gameSystem)))
        GAME_COMM_RequestExitNoCallback(GAMESYSTEM_GetGameComm((const struct GameSystem *)gameSystem));
    work = GAME_EVENT_GetWork((struct GameEvent *)event);
    MI_CpuFill8(work, 0, 0x54);
    work->gameSystem = (struct GameSystem *)gameSystem;
    work->fieldMap = fieldMap;
    work->saveControl = GAME_DATA_GetSaveControl((struct GameData *)gameData);
    work->param.worldTradeData = WORLDTRADE_GetFromSave(work->saveControl);
    work->param.consoleStamp = CONSOLE_STAMP_GetFromSave(work->saveControl);
    work->param.party = POKEPARTY_GetSaveData(work->saveControl);
    work->param.boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager((const struct GameData *)gameData);
    work->param.zukanSave = ZUKAN_SAVE_GetFromGameData((void *)gameData);
    work->param.wifiList = (u32)GAME_DATA_GetWifiList((const struct GameData *)gameData);
    work->param.wifiHistory = WIFI_HISTORY_GetBlock(work->saveControl);
    work->param.myStatus = SYSTEM_DATA_GetMyStatus(work->saveControl);
    work->param.config = SYSTEM_DATA_GetConfig(work->saveControl);
    work->param.record = RECORD_GetFromSave(work->saveControl);
    work->param.myItem = GAME_DATA_GetMyItem((const struct GameData *)gameData);
    work->paramGameSystem = (struct GameSystem *)gameSystem;
    work->param.nationalDexEnabled = ZUKAN_SAVE_IsNationalDexEnabled((struct ZukanSave *)work->param.zukanSave);
    work->param.gsProfileId = WIFILIST_GetGsProfileId((void *)work->param.wifiList);
    work->param.reserved = 0;
    work->param.reserved2 = 0;
    return event;
}


u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork *work)
{
    switch (*seq) {
    case 0:
        if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(work->gameSystem)) == 0)
            *seq = 1;
        break;
    case 1:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(work->gameSystem, (struct FieldMap *)work->fieldMap, 0, 0));
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        *seq = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)work->gameSystem, (struct FieldMap *)work->fieldMap));
        *seq = 3;
        break;
    case 3:
        GAMESYSTEM_CallProc(work->gameSystem, (u32)ov135_id, d_02202BAC, &work->param);
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
            GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, (struct FieldMap *)work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}
