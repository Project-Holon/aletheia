/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, EVENT_WIFIBATTLEMATCH_Create
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
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120F4  0x020120F4  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov199_id       0x000000C7  data   a1
 *   d_02213C4C     0x02213C4C  data   ov199  a4
 *   d_02154460     0x02154460  data   ov002  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_02026400  0x02026400  thumb
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

extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern u32 func_02026454(void *gameComm);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void func_02012374(struct GameEvent *event, struct GameEvent **newEvent);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 func_020307B0(void *p);
extern int func_021BE8D4(void *gameSystem, int fieldMap, int sel, int d);
extern int func_021BE92C(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);
void *func_020122C0(void *gameSystem, void *a, void *callback, u32 workSize);
void func_02026400(struct GameComm *gameComm);
void *func_020124E8(struct GameEvent *event);
u32 func_021542C0(struct GameEvent *event, u32 *seq, WifiBattleMatchEventWork *work);
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, int fieldMap, int entryMode, int ratedFlag, int matchKind);
extern char ov199_id[];
extern char d_02213C4C[];
extern char d_02154460[];


u32 func_021542C0(struct GameEvent *event, u32 *seq, WifiBattleMatchEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    WifiBattleMatchParam *param;

    switch (*seq) {
    case 0:
        if (func_02026454(func_02012138(gameSystem)) == 0) {
            work->savedBgmNo = GFL_USE_GetBgmNo();
            GFL_USE_FadeOutBgm(6);
            (*seq)++;
        }
        break;
    case 1:
        if (work->hideFieldObjects)
            func_02012374(event, (struct GameEvent **)func_021BE8D4(gameSystem, work->fieldMap, 0, 0));
        (*seq)++;
        break;
    case 2:
        func_02012374(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, work->fieldMap));
        (*seq)++;
        break;
    case 3:
        param = func_02030734(4, 0x14, 1, d_02154460, 0x86);
        work->param = param;
        param->entryMode = work->entryMode;
        param->gameData = func_020120F4(gameSystem);
        param->matchKind = work->matchKind;
        param->ratedFlag = work->ratedFlag;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov199_id, d_02213C4C, work->param);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            func_020307B0(work->param);
            (*seq)++;
        }
        break;
    case 5:
        (*seq)++;
        break;
    case 6:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        (*seq)++;
        break;
    case 7:
        if (work->hideFieldObjects)
            func_02012374(event, (struct GameEvent **)func_021BE92C(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
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
    void *event = func_020122C0(gameSystem, 0, func_021542C0, 0x20);
    WifiBattleMatchEventWork *work;

    if (func_02026454(func_02012138(gameSystem)))
        func_02026400(func_02012138(gameSystem));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->entryMode = (u16)entryMode;
    work->ratedFlag = ratedFlag;
    work->matchKind = matchKind;
    work->hideFieldObjects = 0;
    return event;
}
