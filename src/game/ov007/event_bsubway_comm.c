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

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
struct GameEvent *GAME_EVENT_Create(void *gameSystem, void *eventFileName, void *eventMain, u32 workSize);
u32 GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
u32 GAME_COMM_GetKind(void *gameComm);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *GAME_EVENT_GetWork(struct GameEvent *event);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void GAME_EVENT_CallEvent(struct GameEvent *event, struct GameEvent **callee);
extern void GAMESYSTEM_CallProc(struct ProcHandle *gameSystem, u32 overlayId, void *procData, void *procArgs);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, int fieldMap, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);
int EVENT_BSUBWAY_COMM_Start(int gameSystem, BsubwayProcArgs *args);
void *EVENT_BSUBWAY_COMM_CreateEvent(void *gameSystem, int value, int resultPtr);
u32 EVENT_BSUBWAY_COMM_EventMain(void *event, u32 *stage, u32 *work);
extern char ov116_id[];
extern char d_021D83A4[];



int EVENT_BSUBWAY_COMM_Start(int gameSystem, BsubwayProcArgs *args)
{
    return (int)EVENT_BSUBWAY_COMM_CreateEvent((void *)gameSystem, args->value, (int)args->resultPtr);
}



void *EVENT_BSUBWAY_COMM_CreateEvent(void *gameSystem, int value, int resultPtr)
{
    void *event;
    int *work;

    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_BSUBWAY_COMM_EventMain, 0x10);
    work = GAME_EVENT_GetWork(event);
    work[0] = value;
    work[1] = (int)gameSystem;
    work[3] = resultPtr;
    if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback((struct GameComm *)GAMESYSTEM_GetGameComm(gameSystem));
    return event;
}


u32 EVENT_BSUBWAY_COMM_EventMain(void *event, u32 *stage, u32 *work)
{
    u32 gameSystem = work[1];
    void *fieldMap = GAMESYSTEM_GetFieldMap((void *)gameSystem);

    switch (*stage) {
    case 0:
        if (GAME_COMM_GetKind((void *)((int)GAMESYSTEM_GetGameComm((const struct GameSystem *)gameSystem))) == 0)
            (*stage)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)gameSystem, (int)fieldMap, 0, 0));
        (*stage)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent(gameSystem, (int)fieldMap));
        (*stage)++;
        break;
    case 3:
        GAMESYSTEM_CallProc((struct ProcHandle *)gameSystem, (u32)ov116_id, d_021D83A4, work);
        (*stage)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus((const struct GameSystem *)gameSystem) == 0) {
            if (work[2] == 0)
                *(u16 *)work[3] = 1;
            else
                *(u16 *)work[3] = 0;
            (*stage)++;
        }
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent((void *)gameSystem));
        (*stage)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)gameSystem, (int)fieldMap, 0, 0, 1, 0, 0));
        (*stage)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}
