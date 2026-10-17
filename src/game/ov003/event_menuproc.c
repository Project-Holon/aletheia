/*
 * file:     event_menuproc.c
 * unit:     yes
 * function: EVENT_MENUPROC_Main, EVENT_MENUPROC_Create, EVENT_MENUPROC_Entry
 * address:  0x021542C0
 * region:   ov003
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Unlabelled leaf callback (tail call through a pool word), sole blocker of
 * ov010 SCRCMD_PROC_CallMenuProc's MATCH.
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
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 */
struct GameSystem;
struct GameEvent;
struct GameData;
struct GameComm;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

/* Parameter block read by the arm9 menu proc this event launches. */
typedef struct MenuProcParam {
    struct GameData *gameData;
    u32 procKind;
} MenuProcParam;

/* Work of the menu proc launch event (0x1C bytes). */
typedef struct MenuProcEventWork {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    int fieldMap;
    MenuProcParam param;
    u32 procKind;
} MenuProcEventWork;

typedef struct { unsigned fieldMap; unsigned procKind; } LaunchRequest;

extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
extern u32 GAME_COMM_GetKind(void *gameComm);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void GAME_EVENT_CallEvent(struct GameEvent *event, struct GameEvent **newEvent);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
void *GAME_EVENT_Create(void *gameSystem, void *a, void *callback, u32 workSize);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *GAME_EVENT_GetWork(struct GameEvent *event);
u32 EVENT_MENUPROC_Main(struct GameEvent *event, u32 *seq, MenuProcEventWork *work);
void *EVENT_MENUPROC_Create(void *gameSystem, int fieldMap, int procKind);
void *EVENT_MENUPROC_Entry(void *gameSystem, LaunchRequest *request);



u32 EVENT_MENUPROC_Main(struct GameEvent *event, u32 *seq, MenuProcEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;

    switch (*seq) {
    case 0:
        if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)) == 0) {
            work->savedBgmNo = GFL_USE_GetBgmNo();
            GFL_USE_FadeOutBgm(6);
            (*seq)++;
        }
        break;
    case 1:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, work->fieldMap));
        *seq = 2;
        break;
    case 2:
        work->param.gameData = GAMESYSTEM_GetGameData(gameSystem);
        work->param.procKind = work->procKind;
        GAMESYSTEM_CallProc(gameSystem, (u32)-1, (void *)0x0209DEFC, &work->param);
        (*seq)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            (*seq)++;
        break;
    case 4:
        (*seq)++;
        break;
    case 5:
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}



/*
 * Allocator + guard + three-field link setup.
 */
void *EVENT_MENUPROC_Create(void *gameSystem, int fieldMap, int procKind)
{
    void *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MENUPROC_Main, 0x1C);
    MenuProcEventWork *work;

    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback(GAMESYSTEM_GetGameComm(gameSystem));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->procKind = procKind;
    return event;
}


/* Overlay entry point: unpacks the request and creates the event. */
void *EVENT_MENUPROC_Entry(void *gameSystem, LaunchRequest *request)
{
    return EVENT_MENUPROC_Create(gameSystem, request->fieldMap, request->procKind);
}
