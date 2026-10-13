/*
 * function: EVENT_BSUBWAY_COMM_EventMain
 * address:  0x02154310
 * packet:   pkt_ov007_02154310
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov004 EVENT_WORLDTRADE_Main; the task
 * callback EVENT_BSUBWAY_COMM_CreateEvent installs.  Second argument to GAMESYSTEM_CallProc is
 * pooled 0x74 (116), a linker overlay id; the third lies in ov116.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
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

typedef unsigned int u32;
typedef unsigned short u16;

struct GameSystem;
struct GameEvent;
struct ProcHandle;
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern u32   GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
typedef unsigned char  u8;
extern u32 GAME_COMM_GetKind(void *gameComm);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void GAME_EVENT_CallEvent(struct GameEvent *event, struct GameEvent **callee);
extern void GAMESYSTEM_CallProc(struct ProcHandle *gameSystem, u32 overlayId, void *procData, void *procArgs);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, int fieldMap, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);

extern char ov116_id[];
extern char d_021D83A4[];

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
