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
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200AD6C  0x0200AD6C  thumb
 *   func_02008B08  0x02008B08  thumb
 *   POKEPARTY_GetSaveData  0x0201AD0C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0201292C  0x0201292C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   func_02009CC0  0x02009CC0  thumb
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
    void *regulationData;
    void *trainerCardData;
    void *mailBoxData;
    struct BoxManager *boxManager;
    struct WorldTradeSave *worldTradeSave;
    u32 battleRecordData;
    void *wifiFriendData;
    void *myStatus;
    struct Config *config;
    void *pokedexData;
    struct MyItem *myItem;
    u32 worldTradeState;
    int battleRecordValue;
    int reserved;
    int reserved2;
} WorldTradeParam;

/* Work of the world trade event (0x54 bytes). */
typedef struct WorldTradeEventWork_021542C0 {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    int fieldMap;
    WorldTradeParam param;
    struct SaveControl *saveControl;
    struct GameSystem *paramGameSystem;
    u32 hideFieldObjects;
} WorldTradeEventWork_021542C0;

typedef unsigned char  u8;

typedef unsigned short u16;

/* Work of the world trade event, see event_worldtrade.c (0x54 bytes): the field view used here. */
typedef struct WorldTradeEventWork_02154390 {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    int fieldMap;
    u8 param[0x3C];
    void *saveControl;
    struct GameSystem *paramGameSystem;
    u32 hideFieldObjects;
} WorldTradeEventWork_02154390;

void *func_020120F4(const struct GameSystem *gameSystem);
void *func_020122C0(void *gameSystem, void *a, void *callback, u32 workSize);
struct GameComm *func_02012138(const struct GameSystem *gameSystem);
u32 GAME_COMM_GetKind(void *gameComm);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *func_020124E8(struct GameEvent *event);
void MI_CpuFill8(void *dst, int value, int size);
struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
void *func_0200AD6C(void *saveControl);
void *func_02008B08(void *saveControl);
void *POKEPARTY_GetSaveData(void *saveControl);
struct BoxManager *func_0201293C(const struct GameData *gameData);
struct WorldTradeSave *ZUKAN_SAVE_GetFromGameData(void *gameData);
u32 func_0201283C(const struct GameData *gameData);
void *func_02009470(void *saveControl);
void *func_02008730(void *saveControl);
struct Config *func_0200873C(void *saveControl);
void *func_02008C58(void *saveControl);
struct MyItem *func_0201292C(const struct GameData *gameData);
u32 ZUKAN_SAVE_IsNationalDexEnabled(struct WorldTradeSave *worldTradeSave);
int func_02009CC0(void *battleRecordData);
extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void GAME_EVENT_CallEvent(struct GameEvent *event, struct GameEvent **newEvent);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, int fieldMap, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);
int EVENT_WORLDTRADE_Entry(int gameSystem, Pair *request);
int EVENT_WORLDTRADE_Create(int gameSystem, int fieldMap, int unused);
u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork_02154390 *work);
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
    WorldTradeEventWork_021542C0 *work;

    gameData = (int)func_020120F4((const struct GameSystem *)gameSystem);
    event = (int)func_020122C0((void *)gameSystem, 0, EVENT_WORLDTRADE_Main, 0x54);
    if (GAME_COMM_GetKind(func_02012138((const struct GameSystem *)gameSystem)))
        GAME_COMM_RequestExitNoCallback(func_02012138((const struct GameSystem *)gameSystem));
    work = func_020124E8((struct GameEvent *)event);
    MI_CpuFill8(work, 0, 0x54);
    work->gameSystem = (struct GameSystem *)gameSystem;
    work->fieldMap = fieldMap;
    work->saveControl = GAME_DATA_GetSaveControl((struct GameData *)gameData);
    work->param.regulationData = func_0200AD6C(work->saveControl);
    work->param.trainerCardData = func_02008B08(work->saveControl);
    work->param.mailBoxData = POKEPARTY_GetSaveData(work->saveControl);
    work->param.boxManager = func_0201293C((const struct GameData *)gameData);
    work->param.worldTradeSave = ZUKAN_SAVE_GetFromGameData((void *)gameData);
    work->param.battleRecordData = func_0201283C((const struct GameData *)gameData);
    work->param.wifiFriendData = func_02009470(work->saveControl);
    work->param.myStatus = func_02008730(work->saveControl);
    work->param.config = func_0200873C(work->saveControl);
    work->param.pokedexData = func_02008C58(work->saveControl);
    work->param.myItem = func_0201292C((const struct GameData *)gameData);
    work->paramGameSystem = (struct GameSystem *)gameSystem;
    work->param.worldTradeState = ZUKAN_SAVE_IsNationalDexEnabled(work->param.worldTradeSave);
    work->param.battleRecordValue = func_02009CC0((void *)work->param.battleRecordData);
    work->param.reserved = 0;
    work->param.reserved2 = 0;
    return event;
}


u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork_02154390 *work)
{
    switch (*seq) {
    case 0:
        if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(work->gameSystem)) == 0)
            *seq = 1;
        break;
    case 1:
        if (work->hideFieldObjects)
            GAME_EVENT_CallEvent(event, (struct GameEvent **)EVENT_FIELDMAP_CONTROL_StartFadeOut(work->gameSystem, work->fieldMap, 0, 0));
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        *seq = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)work->gameSystem, work->fieldMap));
        *seq = 3;
        break;
    case 3:
        GAMESYSTEM_CallProc(work->gameSystem, (u32)ov135_id, d_02202BAC, work->param);
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
            GAME_EVENT_CallEvent(event, (struct GameEvent **)EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}
