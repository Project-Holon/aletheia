/*
 * file:     event_game_manual.c
 * unit:     yes
 * function: func_021D30B8, func_021D310C, func_021D3164
 * address:  0x021D30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_palace_sys.c at 0x021D30B8 (__FILE__ anchor event_game_manual.c at 0x021D30B8 (first anchored function)).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201210C  0x0201210C  thumb
 *   d_021DE698     0x021DE698  data  ov021  a4
 *   func_020146F8  0x020146F8  thumb
 *   abs_id_e1      0x000000E1  data
 *   d_021BBDE4    0x021BBDE4  data  ov225  a4
 */
struct GameSystem;
struct GameData;
struct GameEvent;
typedef unsigned short u16;
typedef unsigned int u32;

/* Handed to the game manual application (ov225); it writes the result. */
typedef struct GameManualParam {
    struct GameData *gameData;      /* 0x00 */
    u32 result;                     /* 0x04: 0 when the manual returns nothing */
} GameManualParam;

typedef struct EventGameManualWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    void *fieldMap;                 /* 0x04 */
    GameManualParam *param;         /* 0x08 */
    u16 *resultOut;                 /* 0x0C */
} EventGameManualWork;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern void func_02012374(struct GameEvent *event, struct GameEvent *next);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020146F8(struct GameSystem *gameSystem, void *fieldMap, int overlayId, const void *procData, void *param);
struct GameEvent *func_021D30B8(struct GameSystem *gameSystem, u16 *resultOut);
u32 func_021D310C(struct GameEvent *event, u32 *seq, EventGameManualWork *work);
void func_021D3164(EventGameManualWork *work);
extern char d_021DE698[];        /* "event_game_manual.c" */
extern unsigned char abs_id_e1[]; /* FS_OVERLAY_ID(ov225) */
extern char d_021BBDE4[];        /* ov225 proc table */

struct GameEvent *func_021D30B8(struct GameSystem *gameSystem, u16 *resultOut)
{
    struct GameData *gameData;
    void *fieldMap;
    struct GameEvent *event;
    EventGameManualWork *work;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    event = func_020122C0(gameSystem, 0, func_021D310C, sizeof(EventGameManualWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->resultOut = resultOut;
    work->param = func_02030734(4, sizeof(GameManualParam), 0, d_021DE698, 0x4a);
    work->param->gameData = gameData;
    return event;
}

/*
 * abs_id_e1 is FS_OVERLAY_ID(ov225) (overlay_id).  d_021BBDE4 is ov225's
 * proc table (Thumb entries 0x021B95A1, 0x021B96BD, 0x021B9661), handed
 * to the proc loader with ov225's id; it resolves as sole-ref/data in
 * ov225 through the loaded-overlay exception to the own-window rule
 * (attest_xwin_loaded(), 2026-10-02).  No overlay listing labels
 * 0x021BBDE4 as a function; ov114 has ARM code there.
 */
u32 func_021D310C(struct GameEvent *event, u32 *seq, EventGameManualWork *work)
{
    switch (seq[0]) {
    case 0:
        func_02012374(event, func_020146F8(work->gameSystem, work->fieldMap, (int)abs_id_e1, d_021BBDE4, work->param));
        seq[0]++;
        break;
    case 1:
        func_021D3164(work);
        func_020307B0(work->param);
        return 1;
    }
    return 0;
}

void func_021D3164(EventGameManualWork *work)
{
    if (work->param->result == 0) {
        *work->resultOut = 0;
    } else {
        *work->resultOut = 1;
    }
}
