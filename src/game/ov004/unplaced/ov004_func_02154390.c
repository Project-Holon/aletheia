/*
 * function: EVENT_WORLDTRADE_Main
 * address:  0x02154390
 * packet:   pkt_ov004_02154390
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov003 func_021542C0.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0x87 (135): a linker overlay id for
 * ov135, and the third, 0x02202BAC, lies in ov135's window.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov135_id       0x00000087  data   a1
 *   d_02202BAC     0x02202BAC  data   ov135  a4
 */

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct GameSystem;
struct GameEvent;
struct GameComm;
struct GameData;
struct WorldTradeSave;

/* Work of the world trade event, see unit_021542C0.c (0x54 bytes): the field view used here. */
typedef struct WorldTradeEventWork {
    u32 savedBgmNo;
    struct GameSystem *gameSystem;
    int fieldMap;
    u8 param[0x3C];
    void *saveControl;
    struct GameSystem *paramGameSystem;
    u32 hideFieldObjects;
} WorldTradeEventWork;

extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern u32 func_02026454(void *gameComm);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void func_02012374(struct GameEvent *event, struct GameEvent **newEvent);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
extern int func_021BE8D4(void *gameSystem, int fieldMap, int sel, int d);
extern int func_021BE92C(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);

extern char ov135_id[];
extern char d_02202BAC[];

u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork *work)
{
    switch (*seq) {
    case 0:
        if (func_02026454(func_02012138(work->gameSystem)) == 0)
            *seq = 1;
        break;
    case 1:
        if (work->hideFieldObjects)
            func_02012374(event, (struct GameEvent **)func_021BE8D4(work->gameSystem, work->fieldMap, 0, 0));
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        *seq = 2;
        break;
    case 2:
        func_02012374(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)work->gameSystem, work->fieldMap));
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
            func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(work->gameSystem));
            *seq = 5;
        }
        break;
    case 5:
        if (work->hideFieldObjects)
            func_02012374(event, (struct GameEvent **)func_021BE92C(work->gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}
