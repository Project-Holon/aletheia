/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: EVENT_BSUBWAY_COMM_Start, EVENT_BSUBWAY_COMM_CreateEvent
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
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_BSUBWAY_COMM_EventMain  0x02154310  thumb  ov007
 */
struct GameSystem;
struct GameComm;
struct GameEvent;
struct GameEventWork;
typedef struct BsubwayProcArgs {
    int value;
    int *resultPtr;
} BsubwayProcArgs;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
struct GameEvent *func_020122C0(void *gameSystem, void *eventFileName, void *eventMain, u32 workSize);
u32 GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
u32 GAME_COMM_GetKind(void *gameComm);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *func_020124E8(struct GameEvent *event);
u32 EVENT_BSUBWAY_COMM_EventMain(void *event, u32 *stage, u32 *work);
int EVENT_BSUBWAY_COMM_Start(int gameSystem, BsubwayProcArgs *args);
void *EVENT_BSUBWAY_COMM_CreateEvent(void *gameSystem, int value, int resultPtr);


int EVENT_BSUBWAY_COMM_Start(int gameSystem, BsubwayProcArgs *args)
{
    return (int)EVENT_BSUBWAY_COMM_CreateEvent((void *)gameSystem, args->value, (int)args->resultPtr);
}


void *EVENT_BSUBWAY_COMM_CreateEvent(void *gameSystem, int value, int resultPtr)
{
    void *event;
    int *work;

    GAMESYSTEM_GetGameData(gameSystem);
    event = func_020122C0(gameSystem, 0, EVENT_BSUBWAY_COMM_EventMain, 0x10);
    work = func_020124E8(event);
    work[0] = value;
    work[1] = (int)gameSystem;
    work[3] = resultPtr;
    if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback((struct GameComm *)GAMESYSTEM_GetGameComm(gameSystem));
    return event;
}
