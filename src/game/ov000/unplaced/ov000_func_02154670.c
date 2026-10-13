/*
 * function: EVENT_GSYNC_Create
 * address:  0x02154670
 * packet:   pkt_02154670
 * region:   ov000
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Straight-line constructor wrapper over the ARM9 object/service helpers.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   EVENT_GSYNC_Main  0x021542C0  thumb  ov000
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct GameEvent;
struct GameSystem;
struct GameData;
struct SaveControl;

/* Same layout as GsyncEventWork in unit_021542C0.c: only the fields set here are listed. */
typedef struct GsyncEventWorkInit {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    u8 reserved[0x24C];
    struct GameData *loginGameData;
    u32 loginType;
    u32 loginOption;
    u32 loginMessageId;
} GsyncEventWorkInit;

struct GameEvent *func_020122C0(void *gameSystem, void *a, void *callback, u32 workSize);
void *func_020124E8(struct GameEvent *event);
struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
u32 EVENT_GSYNC_Main(void *event, u32 *seq, char *work);

void *EVENT_GSYNC_Create(void *gameSystem)
{
    struct GameEvent *event;
    GsyncEventWorkInit *work;
    struct GameData *gameData;

    event = func_020122C0(gameSystem, 0, EVENT_GSYNC_Main, 0x2CC);
    work = func_020124E8(event);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->gameData = gameData;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameSystem = gameSystem;
    work->loginGameData = GAMESYSTEM_GetGameData(gameSystem);
    work->loginType = 1;
    work->loginOption = 0;
    work->loginMessageId = 0x31;
    return event;
}
