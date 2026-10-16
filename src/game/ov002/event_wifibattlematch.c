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
 *   func_020124E8  0x020124E8  thumb
 */
struct GameSystem;
struct GameEvent;
struct GameData;
struct GameComm;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

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
    int fieldMap;
    WifiBattleMatchParam *param;
    u32 entryMode;
    u32 ratedFlag;
    u32 matchKind;
    u32 hideFieldObjects;
} WifiBattleMatchEventWork;

typedef int s32;

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
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, int fieldMap, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);
void *GAME_EVENT_Create(void *gameSystem, void *a, void *callback, u32 workSize);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *func_020124E8(struct GameEvent *event);
u32 EVENT_WIFIBATTLEMATCH_Main(struct GameEvent *event, u32 *seq, WifiBattleMatchEventWork *work);
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, int fieldMap, int entryMode, int ratedFlag, int matchKind);
void EVENT_WIFIBATTLEMATCH_Entry(s32 gameSystem, s32 *request);
extern char ov199_id[];
extern char d_02213C4C[];
extern char d_02154460[];



u32 EVENT_WIFIBATTLEMATCH_Main(struct GameEvent *event, u32 *seq, WifiBattleMatchEventWork *work)
{
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
            GAME_EVENT_CallEvent(event, (struct GameEvent **)EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, work->fieldMap));
        (*seq)++;
        break;
    case 3:
        param = GFL_HEAP_Alloc(4, 0x14, 1, d_02154460, 0x86);
        work->param = param;
        param->entryMode = work->entryMode;
        param->gameData = GAMESYSTEM_GetGameData(gameSystem);
        param->matchKind = work->matchKind;
        param->ratedFlag = work->ratedFlag;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov199_id, d_02213C4C, work->param);
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
            GAME_EVENT_CallEvent(event, (struct GameEvent **)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
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
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, int fieldMap, int entryMode, int ratedFlag, int matchKind)
{
    void *event = GAME_EVENT_Create(gameSystem, 0, EVENT_WIFIBATTLEMATCH_Main, 0x20);
    WifiBattleMatchEventWork *work;

    if (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(gameSystem)))
        GAME_COMM_RequestExitNoCallback(GAMESYSTEM_GetGameComm(gameSystem));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->entryMode = (u16)entryMode;
    work->ratedFlag = ratedFlag;
    work->matchKind = matchKind;
    work->hideFieldObjects = 0;
    return event;
}


/* Overlay entry point: unpacks the four-word request and creates the event. */
void EVENT_WIFIBATTLEMATCH_Entry(s32 gameSystem, s32 *request)
{
    EVENT_WIFIBATTLEMATCH_Create((void *)gameSystem, request[0], request[1], request[2], request[3]);
}
