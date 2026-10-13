/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: EVENT_WORLDTRADE_Entry, EVENT_WORLDTRADE_Create
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
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_02009CC0  0x02009CC0  thumb
 *   EVENT_WORLDTRADE_Main  0x02154390  thumb  ov004
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
typedef struct WorldTradeEventWork {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    int fieldMap;
    WorldTradeParam param;
    struct SaveControl *saveControl;
    struct GameSystem *paramGameSystem;
    u32 hideFieldObjects;
} WorldTradeEventWork;

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
struct WorldTradeSave *func_0200CA1C(void *gameData);
u32 func_0201283C(const struct GameData *gameData);
void *func_02009470(void *saveControl);
void *func_02008730(void *saveControl);
struct Config *func_0200873C(void *saveControl);
void *func_02008C58(void *saveControl);
struct MyItem *func_0201292C(const struct GameData *gameData);
u32 func_0200CA38(struct WorldTradeSave *worldTradeSave);
int func_02009CC0(void *battleRecordData);
u32 EVENT_WORLDTRADE_Main(void *event, u32 *seq, WorldTradeEventWork *work);
int EVENT_WORLDTRADE_Entry(int gameSystem, Pair *request);
int EVENT_WORLDTRADE_Create(int gameSystem, int fieldMap, int unused);


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
    work->param.worldTradeSave = func_0200CA1C((void *)gameData);
    work->param.battleRecordData = func_0201283C((const struct GameData *)gameData);
    work->param.wifiFriendData = func_02009470(work->saveControl);
    work->param.myStatus = func_02008730(work->saveControl);
    work->param.config = func_0200873C(work->saveControl);
    work->param.pokedexData = func_02008C58(work->saveControl);
    work->param.myItem = func_0201292C((const struct GameData *)gameData);
    work->paramGameSystem = (struct GameSystem *)gameSystem;
    work->param.worldTradeState = func_0200CA38(work->param.worldTradeSave);
    work->param.battleRecordValue = func_02009CC0((void *)work->param.battleRecordData);
    work->param.reserved = 0;
    work->param.reserved2 = 0;
    return event;
}
