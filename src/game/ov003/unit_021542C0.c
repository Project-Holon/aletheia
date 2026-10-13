/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, EVENT_MENUPROC_Create
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
 *   func_020122C0  0x020122C0  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
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
void *func_020122C0(void *gameSystem, void *a, void *callback, u32 workSize);
void func_02026400(struct GameComm *gameComm);
void *func_020124E8(struct GameEvent *event);
u32 func_021542C0(struct GameEvent *event, u32 *seq, MenuProcEventWork *work);
void *EVENT_MENUPROC_Create(void *gameSystem, int fieldMap, int procKind);


u32 func_021542C0(struct GameEvent *event, u32 *seq, MenuProcEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;

    switch (*seq) {
    case 0:
        if (func_02026454(func_02012138(gameSystem)) == 0) {
            work->savedBgmNo = GFL_USE_GetBgmNo();
            GFL_USE_FadeOutBgm(6);
            (*seq)++;
        }
        break;
    case 1:
        func_02012374(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, work->fieldMap));
        *seq = 2;
        break;
    case 2:
        work->param.gameData = func_020120F4(gameSystem);
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
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
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
    void *event = func_020122C0(gameSystem, 0, func_021542C0, 0x1C);
    MenuProcEventWork *work;

    if (func_02026454(func_02012138(gameSystem)))
        func_02026400(func_02012138(gameSystem));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->procKind = procKind;
    return event;
}
