/*
 * file:     event_fieldmap_control.c
 * unit:     yes
 * function: func_021BE89C, func_021BE8B8, func_021BE8D4, func_021BE92C, func_021BE9A0, func_021BE9F0, func_021BEA30, func_021BEA6C, func_021BEA9C, func_021BEACC, func_021BEAFC, func_021BEB38, func_021BEB78, func_021BEBA8, func_021BEBD8, func_021BEC24, func_021BEC54, func_021BEC84, func_021BECB4, func_021BECE4, func_021BED14, func_021BED44, func_021BED74, func_021BEDA4, func_021BEDD4, func_021BEE24, func_021BEE74, func_021BEEB4, func_021BEF08, func_021BEF8C, func_021BF0A4, func_021BF0E4, func_021BF130, func_021BF19C, func_021BF208, func_021BF274, func_021BF2E0, func_021BF348, func_021BF3BC, func_021BF430, func_021BF4A4, func_021BF518, func_021BF564, func_021BF584
 * address:  0x021BE89C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes 021BE89C..021BEE24 (the fade event creators) from fld_exp_obj.c (lane FXC, CL124).
 * Split from field_player_grid_event.c at 0x021BEE74 (lane CL118, name guess, no __FILE__ anchor: fade and field close/open event handlers whose creators (021BE89C..) sit in fld_exp_obj.c; the fade-in creator 021BE92C takes (gsys, fieldmap, type, wait, bgInit, season, season)).
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_0208068C  0x0208068C  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_02166B0C  0x02166B0C  thumb  ov010
 *   d_021D9F50     0x021D9F50  data  ov021  a4
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02166B2C  0x02166B2C  thumb  ov010
 *   func_02188DF0  0x02188DF0  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021903CC  0x021903CC  thumb  ov021
 *   func_021902AC  0x021902AC  thumb  ov021
 *   func_0218774C  0x0218774C  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_021877A8  0x021877A8  thumb  ov020
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02043658  0x02043658  arm
 *   func_02043668  0x02043668  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_02188DB0  0x02188DB0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021BE9A0 0x021BE9A0 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02013FD8  0x02013FD8  thumb
 *   func_021BF0E4  0x021BF0E4  thumb  ov021
 *   func_021BF518  0x021BF518  thumb  ov021
 *   func_021BEE74  0x021BEE74  thumb  ov021
 *   d_021D9F60  0x021D9F60  data
 *   d_021D9FF0     0x021D9FF0  data
 *   func_021BEEB4  0x021BEEB4  thumb  ov021
 *   func_021BEF08  0x021BEF08  thumb  ov021
 *   func_021BEF8C  0x021BEF8C  thumb  ov021
 *   func_021BF0A4  0x021BF0A4  thumb  ov021
 *   func_021BF130  0x021BF130  thumb  ov021
 *   func_021BF19C  0x021BF19C  thumb  ov021
 *   func_021BF348  0x021BF348  thumb  ov021
 *   func_021BF208  0x021BF208  thumb  ov021
 *   func_021BF3BC  0x021BF3BC  thumb  ov021
 *   func_021BF274  0x021BF274  thumb  ov021
 *   func_021BF430  0x021BF430  thumb  ov021
 *   func_021BF2E0  0x021BF2E0  thumb  ov021
 *   func_021BF4A4  0x021BF4A4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 */
#include "fieldmap_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
struct FieldPlayer;
struct FieldMsgBg;

/* Values an event function returns to the event runner. */
enum {
    EVENT_FIELDMAP_CONTROL_CONTINUE,
    EVENT_FIELDMAP_CONTROL_FINISHED
};

/* Fade levels. */
#define FADE_LEVEL_MAX 16
#define FADE_SPEED_DEFAULT (-1)

/* Hardware registers the default fade events write. */
#define REG_BLDCNT_ADDR 0x04000050
#define REG_BG2CNT (*(volatile u16 *)0x0400000C)
#define REG_BLDALPHA (*(volatile u16 *)0x04000052)
#define REG_DISPCAPCNT (*(volatile u32 *)0x04000064)

/* Display mode block that GX setup takes (4 words, same layout as the bg_sys.c DispConfig). */
typedef struct DispConfig {
    u32 dispMode;       /* 0x00: main display mode */
    u32 bgMode;         /* 0x04: main BG mode */
    u32 subBgMode;      /* 0x08: sub BG mode */
    u32 bg0As;          /* 0x0C: BG0 as 2D or 3D */
} DispConfig;

/*
 * Work of the map change fade events (0x2C bytes, GAME_EVENT work). The
 * creators and handlers are in this file and in event_appear.c / event_disappear.c.
 */
typedef struct FieldFadeWork FieldFadeWork;
typedef void (*FieldFadeCallback)(void *arg);
typedef int (*FieldFadeFunc)(GameEvent *event, int *seq, FieldFadeWork *work);

struct FieldFadeWork {
    GameSystem *gameSystem;         /* 0x00 */
    FieldMap *fieldMap;             /* 0x04 */
    int effect;                     /* 0x08: map change effect id */
    int fadeKind;                   /* 0x0C: FADE_Start type, from FLD_EXP_OBJ effect */
    int fadeSpeed;                  /* 0x10: last FADE_Start argument (fade-in 021BE9F0 only) */
    int skipWait;                   /* 0x14: 1 returns without waiting for the fade to end */
    int restoreBg;                  /* 0x18: nonzero restores the BG planes first */
    int blendStep;                  /* 0x1C: default fade-in, alpha blend level counting down from 16 */
    u8 seasonShown;                 /* 0x20: season scoreboard, shown season */
    u8 seasonTarget;                /* 0x21: season scoreboard, target season */
    u8 padding22[2];
    FieldFadeCallback finishCallback; /* 0x24 */
    void *finishCallbackArg;        /* 0x28 */
};

typedef struct {
    u32 v[6][6];
} EffectTable;

/* Steps of the plain fade events. */
enum {
    FADE_STEP_START,
    FADE_STEP_WAIT
};

/* Steps of the wipe events (fade, wipe, wait for the wipe). */
enum {
    WIPE_STEP_FADE,
    WIPE_STEP_START,
    WIPE_STEP_WAIT,
    WIPE_STEP_END
};

/* Steps of the default fade-in. */
enum {
    DEFAULT_FADE_IN_STEP_START,
    DEFAULT_FADE_IN_STEP_BLEND,
    DEFAULT_FADE_IN_STEP_SAVE_PLANES,
    DEFAULT_FADE_IN_STEP_HIDE_MSG,
    DEFAULT_FADE_IN_STEP_WAIT_MSG_BG,
    DEFAULT_FADE_IN_STEP_LOAD_WINDOW_1,
    DEFAULT_FADE_IN_STEP_LOAD_WINDOW_2,
    DEFAULT_FADE_IN_STEP_FINISH,
    DEFAULT_FADE_IN_STEP_END
};

/* Steps of the season scoreboard fade-ins. */
enum {
    SEASON_FADE_STEP_START,
    SEASON_FADE_STEP_END
};

extern void func_0204E720(u32 fadeKind, s32 startLevel, s32 endLevel, s32 speed);
extern int func_0204E804(void);
extern void func_0208068C(u32 vramBanks);
extern void func_02087AE4(void);
extern void func_0203FC28(const DispConfig *config);
extern void func_0207FDCC(u32 vramBanks);
extern void func_0204047C(int index, unsigned short value);
extern void func_02040588(unsigned char plane, unsigned char enable);
extern void func_02166B0C(void);
extern void func_02189A58(FieldMap *fieldMap, int stopped);
extern void func_0207D63C(u32 addr, int plane1, int plane2, int ev1, int ev2);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern void func_02080B98(void);
extern void func_02166B2C(void);
extern void func_02188DF0(FieldMap *fieldMap);
extern struct FieldMsgBg *func_02188C54(FieldMap *fieldMap);
extern int func_021903CC(struct FieldMsgBg *msgBg);
extern void func_021902AC(struct FieldMsgBg *msgBg, int step);
extern GameEvent *func_0218774C(GameSystem *gameSystem, FieldMap *fieldMap, u8 seasonShown, u8 seasonTarget);
extern GameEvent *func_021877A8(GameSystem *gameSystem, FieldMap *fieldMap, u8 seasonShown, u8 seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg);
extern void func_02012374(GameEvent *parent, GameEvent *child);
extern u16 func_02188C84(FieldMap *fieldMap);
extern void func_0202208C(u32 type, u32 p2, u32 p3, u16 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern u32 func_02043658(void);
extern u32 func_02043668(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 visiblePlanes);
extern void func_020435F4(u32 visiblePlanes);
extern void func_02188DB0(FieldMap *fieldMap);
extern u8 func_02013FD8(u32 zoneId);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, FieldFadeFunc handler, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern u16 func_021A3050(struct FieldPlayer *fieldPlayer);

extern const DispConfig d_021D9F50;
extern const EffectTable d_021D9F60;
extern const EffectTable d_021D9FF0;

int func_021BE89C(int fromZoneId, u32 toZoneId);
int func_021BE8B8(int fromZoneId, int toZoneId);
GameEvent *func_021BE8D4(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
GameEvent *func_021BE92C(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg, u8 seasonShown, u8 seasonTarget);
GameEvent *func_021BE9A0(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg);
GameEvent *func_021BE9F0(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int fadeSpeed);
GameEvent *func_021BEA30(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
int func_021BEA6C(int effect);
u32 func_021BEA9C(int fromGroup, int toGroup);
u32 func_021BEACC(int fromGroup, int toGroup);
GameEvent *func_021BEAFC(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
GameEvent *func_021BEB38(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg);
GameEvent *func_021BEB78(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BEBA8(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BEBD8(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget);
GameEvent *func_021BEC24(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BEC54(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BEC84(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BECB4(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BECE4(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BED14(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BED44(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BED74(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BEDA4(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *func_021BEDD4(GameSystem *gameSystem, FieldMap *fieldMap);
void func_021BEE24(GameSystem *gameSystem, FieldMap *fieldMap);

int func_021BEE74(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BEEB4(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BEF08(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BEF8C(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF0A4(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF0E4(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF130(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF19C(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF208(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF274(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF2E0(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF348(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF3BC(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF430(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF4A4(GameEvent *event, int *seq, FieldFadeWork *work);
int func_021BF518(GameEvent *event, int *seq, FieldFadeWork *work);
void func_021BF564();
void func_021BF584(FieldMap *fieldMap);

/*
 * Effect id when leaving a zone, from the zone groups of both zones.
 */
int func_021BE89C(int fromZoneId, u32 toZoneId)
{
    return func_021BEA9C(func_02013FD8(fromZoneId), func_02013FD8(toZoneId));
}

/*
 * Effect id when arriving in a zone.
 */
int func_021BE8B8(int fromZoneId, int toZoneId)
{
    int fromGroup = func_02013FD8(fromZoneId);

    return func_021BEACC(fromGroup, func_02013FD8(toZoneId));
}

/*
 * Starts the fade-out event of a map change effect.
 */
GameEvent *func_021BE8D4(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait)
{
    switch (effect) {
    default:
        return func_021BEB78(gameSystem, fieldMap);
    case 0:
    case 1:
    case 3:
        return func_021BEAFC(gameSystem, fieldMap, effect, skipWait);
    case 4:
        return func_021BEC24(gameSystem, fieldMap);
    case 5:
        return func_021BEC54(gameSystem, fieldMap);
    case 6:
        return func_021BECB4(gameSystem, fieldMap);
    case 7:
        return func_021BED14(gameSystem, fieldMap);
    case 8:
        return func_021BED74(gameSystem, fieldMap);
    case 9:
        return func_021BEDD4(gameSystem, fieldMap);
    }
}

/*
 * Starts the fade-in event of a map change effect.
 */
GameEvent *func_021BE92C(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg, u8 seasonShown, u8 seasonTarget)
{
    switch (effect) {
    default:
        return func_021BEBA8(gameSystem, fieldMap);
    case 0:
    case 1:
        return func_021BEB38(gameSystem, fieldMap, effect, skipWait, restoreBg);
    case 3:
        return func_021BEBD8(gameSystem, fieldMap, seasonShown, seasonTarget);
    case 5:
        return func_021BEC84(gameSystem, fieldMap);
    case 6:
        return func_021BECE4(gameSystem, fieldMap);
    case 7:
        return func_021BED44(gameSystem, fieldMap);
    case 8:
        return func_021BEDA4(gameSystem, fieldMap);
    case 9:
        func_021BEE24(gameSystem, fieldMap);
        break;
    }
}

/*
 * Fade-in event with the season scoreboard and a finish callback.
 */
GameEvent *func_021BE9A0(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF0E4, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 3;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    work->fadeKind = func_021BEA6C(work->effect);
    work->finishCallback = finishCallback;
    work->finishCallbackArg = finishCallbackArg;
    return event;
}

/*
 * Fade-in event that restores the BG planes first.
 */
GameEvent *func_021BE9F0(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int fadeSpeed)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF518, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = func_021BEA6C(effect);
    work->fadeSpeed = fadeSpeed;
    return event;
}

GameEvent *func_021BEA30(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BEE74, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = func_021BEA6C(effect);
    return event;
}

/*
 * FADE_Start type of a map change effect.
 */
int func_021BEA6C(int effect)
{
    switch (effect) {
    case 0:
    default:
        return 3;
    case 1:
        return 12;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 2;
    }
}

u32 func_021BEA9C(int fromGroup, int toGroup)
{
    EffectTable table = d_021D9F60;

    return table.v[fromGroup][toGroup];
}

u32 func_021BEACC(int fromGroup, int toGroup)
{
    EffectTable table = d_021D9FF0;

    return table.v[fromGroup][toGroup];
}

GameEvent *func_021BEAFC(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BEE74, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = func_021BEA6C(effect);
    return event;
}

GameEvent *func_021BEB38(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BEEB4, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = func_021BEA6C(effect);
    work->restoreBg = restoreBg;
    return event;
}

GameEvent *func_021BEB78(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BEF08, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 2;
    work->fadeKind = func_021BEA6C(2);
    return event;
}

GameEvent *func_021BEBA8(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BEF8C, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 2;
    work->fadeKind = func_021BEA6C(2);
    return event;
}

/*
 * Season scoreboard fade-in without a finish callback.
 */
GameEvent *func_021BEBD8(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF0A4, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 3;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    work->fadeKind = func_021BEA6C(work->effect);
    work->finishCallback = 0;
    work->finishCallbackArg = 0;
    return event;
}

GameEvent *func_021BEC24(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF130, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 4;
    work->fadeKind = func_021BEA6C(4);
    return event;
}

GameEvent *func_021BEC54(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF19C, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 5;
    work->fadeKind = func_021BEA6C(5);
    return event;
}

GameEvent *func_021BEC84(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF348, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 5;
    work->fadeKind = func_021BEA6C(5);
    return event;
}

GameEvent *func_021BECB4(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF208, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 6;
    work->fadeKind = func_021BEA6C(6);
    return event;
}

GameEvent *func_021BECE4(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF3BC, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 6;
    work->fadeKind = func_021BEA6C(6);
    return event;
}

GameEvent *func_021BED14(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF274, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 7;
    work->fadeKind = func_021BEA6C(7);
    return event;
}

GameEvent *func_021BED44(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF430, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 7;
    work->fadeKind = func_021BEA6C(7);
    return event;
}

GameEvent *func_021BED74(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF2E0, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 8;
    work->fadeKind = func_021BEA6C(8);
    return event;
}

GameEvent *func_021BEDA4(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, func_021BF4A4, sizeof(FieldFadeWork));
    FieldFadeWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 8;
    work->fadeKind = func_021BEA6C(8);
    return event;
}

/*
 * Fade-out for effect 9: picks effect 5 to 8 from the way the player faces.
 */
GameEvent *func_021BEDD4(GameSystem *gameSystem, FieldMap *fieldMap)
{
    switch (func_021A3050(func_02188CB4(fieldMap))) {
    case 2:
    default:
        return func_021BED14(gameSystem, fieldMap);
    case 3:
        return func_021BED74(gameSystem, fieldMap);
    case 0:
        return func_021BEC54(gameSystem, fieldMap);
    case 1:
        return func_021BECB4(gameSystem, fieldMap);
    }
}

/*
 * Fade-in for effect 9, the twin of func_021BEDD4.
 */
void func_021BEE24(GameSystem *gameSystem, FieldMap *fieldMap)
{
    switch (func_021A3050(func_02188CB4(fieldMap))) {
    case 2:
    default:
        func_021BED44(gameSystem, fieldMap);
        break;
    case 3:
        func_021BEDA4(gameSystem, fieldMap);
        break;
    case 0:
        func_021BEC84(gameSystem, fieldMap);
        break;
    case 1:
        func_021BECE4(gameSystem, fieldMap);
        break;
    }
}


/*
 * Fade-out for the black and white effects: starts the fade and waits for it.
 */
int func_021BEE74(GameEvent *event, int *seq, FieldFadeWork *work)
{
    switch (*seq) {
    case FADE_STEP_START:
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case FADE_STEP_WAIT:
        if (work->skipWait == 1)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        if (func_0204E804() == 0)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        break;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Fade-in for the black and white effects: restores the BG planes when the
 * work asks for it, then fades in and waits.
 */
int func_021BEEB4(GameEvent *event, int *seq, FieldFadeWork *work)
{
    switch (*seq) {
    case FADE_STEP_START:
        if (work->restoreBg != 0) {
            func_021BF564(work->fieldMap);
            func_021BF584(work->fieldMap);
        }
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case FADE_STEP_WAIT:
        if (work->skipWait == 1)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        if (func_0204E804() == 0)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        break;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Default fade-out: starts the fade, captures the screen into VRAM bank A
 * and switches the main display to the capture BG setup.
 */
int func_021BEF08(GameEvent *event, int *seq, FieldFadeWork *work)
{
    DispConfig dispConfig;

    if (*seq == 0) {
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        func_0208068C(8);
        REG_DISPCAPCNT = 0x80330010;
        func_02087AE4();
        func_02087AE4();
        dispConfig = d_021D9F50;
        func_0203FC28(&dispConfig);
        REG_BG2CNT = 0x4084 | (REG_BG2CNT & 0x43);
        func_0207FDCC(8);
        func_0204047C(2, 0);
        func_02040588(2, 1);
        func_02166B0C();
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Default fade-in: cross-fades the captured screen into the map with an alpha
 * blend, restores the BG setup and loads the window graphics step by step.
 */
int func_021BEF8C(GameEvent *event, int *seq, FieldFadeWork *work)
{
    struct FieldMsgBg *msgBg;

    switch (*seq) {
    case DEFAULT_FADE_IN_STEP_START:
        func_02189A58(work->fieldMap, 1);
        work->blendStep = FADE_LEVEL_MAX;
        func_0204047C(2, 0);
        func_0204047C(0, 1);
        func_02040588(0, 1);
        func_0207D63C(REG_BLDCNT_ADDR, 4, 1, work->blendStep, 0);
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_BLEND:
        if (work->blendStep != 0) {
            work->blendStep = work->blendStep - 1;
            REG_BLDALPHA = ((FADE_LEVEL_MAX - work->blendStep) << 8) | work->blendStep;
            break;
        }
        func_02040588(2, 0);
        func_0208068C(8);
        func_02082AC0(0, (void *)0x06800000, 0x20000);
        func_02080B98();
        func_0207FDCC(8);
        func_02166B2C();
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_SAVE_PLANES:
        func_021BF564(work->fieldMap);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_HIDE_MSG:
        func_02188DF0(work->fieldMap);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_WAIT_MSG_BG:
        msgBg = func_02188C54(work->fieldMap);
        if (func_021903CC(msgBg) != 0) {
            func_021902AC(msgBg, 0);
            *seq = *seq + 1;
        }
        break;
    case DEFAULT_FADE_IN_STEP_LOAD_WINDOW_1:
        func_021902AC(func_02188C54(work->fieldMap), 1);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_LOAD_WINDOW_2:
        func_021902AC(func_02188C54(work->fieldMap), 2);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_FINISH:
        *seq = *seq + 1;
    case DEFAULT_FADE_IN_STEP_END:
        func_02189A58(work->fieldMap, 0);
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Season fade-in without a finish callback: starts the season scoreboard
 * event as a child and ends.
 */
int func_021BF0A4(GameEvent *event, int *seq, FieldFadeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case SEASON_FADE_STEP_START: {
        GameEvent *scoreboardEvent = func_0218774C(gameSystem, fieldMap, work->seasonShown, work->seasonTarget);
        func_02012374(event, scoreboardEvent);
        *seq = *seq + 1;
        break;
    }
    case SEASON_FADE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Season fade-in with a finish callback: same as above, the scoreboard event
 * calls the callback when it ends.
 */
int func_021BF0E4(GameEvent *event, int *seq, FieldFadeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case SEASON_FADE_STEP_START: {
        GameEvent *scoreboardEvent = func_021877A8(gameSystem, fieldMap, work->seasonShown, work->seasonTarget, work->finishCallback, work->finishCallbackArg);
        func_02012374(event, scoreboardEvent);
        *seq = *seq + 1;
        break;
    }
    case SEASON_FADE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 4 fade-out: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF130(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 8, 8, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 5 fade-out: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF19C(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 2, 2, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 6 fade-out: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF208(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 4, 4, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 7 fade-out: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF274(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 10, 10, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 8 fade-out: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF2E0(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_0204E720(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 6, 6, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 5 fade-in: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF348(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_021BF564();
        func_021BF584(work->fieldMap);
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 3, 3, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 6 fade-in: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF3BC(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_021BF564();
        func_021BF584(work->fieldMap);
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 5, 5, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 7 fade-in: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF430(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_021BF564();
        func_021BF584(work->fieldMap);
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 7, 7, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Map change effect 8 fade-in: fade, then a wipe, then wait for the wipe to end.
 */
int func_021BF4A4(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        func_021BF564();
        func_021BF584(work->fieldMap);
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        func_0202208C(3, 11, 11, 0, 6, 1, func_02188C84(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (func_020221A4() != 0)
            *seq = *seq + 1;
        break;
    case WIPE_STEP_END:
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Fade-in with a fade speed from the work: restores the BG planes, fades in
 * and waits.
 */
int func_021BF518(GameEvent *event, int *seq, FieldFadeWork *work)
{
    switch (*seq) {
    case FADE_STEP_START:
        func_0204E720(work->fadeKind, FADE_LEVEL_MAX, 0, work->fadeSpeed);
        func_021BF564(work->fieldMap);
        func_021BF584(work->fieldMap);
        *seq = *seq + 1;
        break;
    case FADE_STEP_WAIT:
        if (work->skipWait == 1) {
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        }
        if (func_0204E804() == 0) {
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        }
        break;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Keeps the visible BG planes of both screens across the BG mode reset.
 *
 * stand-in: the empty parameter list is kept because three callers pass the
 * field map (the argument load is in the matched bytes) and the others pass
 * nothing; the function reads no argument.
 */
void func_021BF564()
{
    u32 mainPlanes = func_02043658();
    u32 subPlanes = func_02043668();

    func_02188DA0();
    func_02043534(mainPlanes);
    func_020435F4(subPlanes);
}

/*
 * Tail-call thunk: forwards to func_02188DB0 with no argument change.
 */
void func_021BF584(FieldMap *fieldMap)
{
    func_02188DB0(fieldMap);
}
