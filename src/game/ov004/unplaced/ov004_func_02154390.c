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
 * Stage machine on *mode, same family as ov003 EVENT_WORLDTRADE_Entry.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0x87 (135): a linker overlay id for
 * ov135, and the third, 0x02202BAC, lies in ov135's window.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
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

extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
extern u32 GAME_COMM_GetKind(void *gameComm);
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

extern char ov135_id[];
extern char d_02202BAC[];

u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork *work)
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
