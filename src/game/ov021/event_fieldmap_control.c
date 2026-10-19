/*
 * file:     event_fieldmap_control.c
 * unit:     yes
 * function: EVENT_FIELDMAP_CONTROL_GetExitEffect, EVENT_FIELDMAP_CONTROL_GetEntranceEffect, EVENT_FIELDMAP_CONTROL_StartFadeOut, EVENT_FIELDMAP_CONTROL_StartFadeIn, EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback, EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore, EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent, EVENT_FIELDMAP_CONTROL_GetFadeKind, EVENT_FIELDMAP_CONTROL_LookupExitEffect, EVENT_FIELDMAP_CONTROL_LookupEntranceEffect, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect, EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault, EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault, EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5, EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6, EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7, EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7, EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8, EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8, EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing, EVENT_FIELDMAP_CONTROL_StartFadeInByFacing, EVENT_FIELDMAP_CONTROL_RunFadeOut, EVENT_FIELDMAP_CONTROL_RunFadeIn, EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut, EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn, EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn, EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect4, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect5, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect6, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect7, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect8, EVENT_FIELDMAP_CONTROL_RunWipeInEffect5, EVENT_FIELDMAP_CONTROL_RunWipeInEffect6, EVENT_FIELDMAP_CONTROL_RunWipeInEffect7, EVENT_FIELDMAP_CONTROL_RunWipeInEffect8, EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore, EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes, EVENT_FIELDMAP_CONTROL_ResetBgAffine
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
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   GX_SetBankForBG  0x0207FDCC  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   SYMBOL_MAP_StartBg2Scale  0x02166B0C  thumb  ov010
 *   sCaptureDispConfig     0x021D9F50  data  ov021  a4
 *   FIELDMAP_SetUpdateStopped  0x02189A58  thumb  ov021
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   GX_DisableBankForLCDC  0x02080B98  arm
 *   SYMBOL_MAP_StopBg2Scale  0x02166B2C  thumb  ov010
 *   FIELDMAP_ResetBgAffineHideMsg  0x02188DF0  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_IsSetupDone  0x021903CC  thumb  ov021
 *   FIELD_MSGBG_LoadWindowGraphicsStep  0x021902AC  thumb  ov021
 *   EL_SCOREBOARD_StartOnField  0x0218774C  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EL_SCOREBOARD_StartOnFieldWithCallback  0x021877A8  thumb  ov020
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback 0x021BE9A0 thumb ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   ZONEDATA_GetExpObjSetId  0x02013FD8  thumb
 *   EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback  0x021BF0E4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore  0x021BF518  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunFadeOut  0x021BEE74  thumb  ov021
 *   gExitEffectTable  0x021D9F60  data
 *   gEntranceEffectTable     0x021D9FF0  data
 *   EVENT_FIELDMAP_CONTROL_RunFadeIn  0x021BEEB4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut  0x021BEF08  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn  0x021BEF8C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn  0x021BF0A4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeOutEffect4  0x021BF130  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeOutEffect5  0x021BF19C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect5  0x021BF348  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeOutEffect6  0x021BF208  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect6  0x021BF3BC  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeOutEffect7  0x021BF274  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect7  0x021BF430  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeOutEffect8  0x021BF2E0  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect8  0x021BF4A4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
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

extern void FADE_Start(u32 fadeKind, s32 startLevel, s32 endLevel, s32 speed);
extern int FADE_IsActive(void);
extern void GX_SetBankForLCDC(u32 vramBanks);
extern void OS_WaitVBlankIntr(void);
extern void BG_SYS_SetGraphicsMode(const DispConfig *config);
extern void GX_SetBankForBG(u32 vramBanks);
extern void BG_SYS_SetVisibleLayer(int index, unsigned short value);
extern void BG_SYS_SetPlaneVisible(unsigned char plane, unsigned char enable);
extern void SYMBOL_MAP_StartBg2Scale(void);
extern void FIELDMAP_SetUpdateStopped(FieldMap *fieldMap, int stopped);
extern void G2x_SetBlendAlpha_(u32 addr, int plane1, int plane2, int ev1, int ev2);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void GX_DisableBankForLCDC(void);
extern void SYMBOL_MAP_StopBg2Scale(void);
extern void FIELDMAP_ResetBgAffineHideMsg(FieldMap *fieldMap);
extern struct FieldMsgBg *FIELDMAP_GetMsgBg(FieldMap *fieldMap);
extern int FIELD_MSGBG_IsSetupDone(struct FieldMsgBg *msgBg);
extern void FIELD_MSGBG_LoadWindowGraphicsStep(struct FieldMsgBg *msgBg, int step);
extern GameEvent *EL_SCOREBOARD_StartOnField(GameSystem *gameSystem, FieldMap *fieldMap, u8 seasonShown, u8 seasonTarget);
extern GameEvent *EL_SCOREBOARD_StartOnFieldWithCallback(GameSystem *gameSystem, FieldMap *fieldMap, u8 seasonShown, u8 seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg);
extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern void WIPE_SYS_Start(u32 type, u32 mainPattern, u32 subPattern, u16 color, u32 frames, u32 wait, u32 heapId);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern u32 BG_SYS_GetSubVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 visiblePlanes);
extern void BG_SYS_SetSubVisiblePlanes(u32 visiblePlanes);
extern void FIELDMAP_ResetBgAffineShowMsg(FieldMap *fieldMap);
extern u8 ZONEDATA_GetExpObjSetId(u32 zoneId);
extern GameEvent *GAME_EVENT_Create(GameSystem *gameSystem, GameEvent *parent, FieldFadeFunc handler, u32 workSize);
extern void *GAME_EVENT_GetWork(GameEvent *event);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *fieldPlayer);

extern const DispConfig sCaptureDispConfig;
extern const EffectTable gExitEffectTable;
extern const EffectTable gEntranceEffectTable;

int EVENT_FIELDMAP_CONTROL_GetExitEffect(int fromZoneId, u32 toZoneId);
int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int fromZoneId, int toZoneId);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg, u8 seasonShown, u8 seasonTarget);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int fadeSpeed);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
int EVENT_FIELDMAP_CONTROL_GetFadeKind(int effect);
u32 EVENT_FIELDMAP_CONTROL_LookupExitEffect(int fromGroup, int toGroup);
u32 EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(int fromGroup, int toGroup);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(GameSystem *gameSystem, FieldMap *fieldMap);
void EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(GameSystem *gameSystem, FieldMap *fieldMap);

int EVENT_FIELDMAP_CONTROL_RunFadeOut(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunFadeIn(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect4(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect5(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect6(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect7(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect8(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect5(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect6(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect7(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect8(GameEvent *event, int *seq, FieldFadeWork *work);
int EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore(GameEvent *event, int *seq, FieldFadeWork *work);
void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
void EVENT_FIELDMAP_CONTROL_ResetBgAffine(FieldMap *fieldMap);

/*
 * Effect id when leaving a zone, from the zone groups of both zones.
 */
int EVENT_FIELDMAP_CONTROL_GetExitEffect(int fromZoneId, u32 toZoneId)
{
    return EVENT_FIELDMAP_CONTROL_LookupExitEffect(ZONEDATA_GetExpObjSetId(fromZoneId), ZONEDATA_GetExpObjSetId(toZoneId));
}

/*
 * Effect id when arriving in a zone.
 */
int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int fromZoneId, int toZoneId)
{
    int fromGroup = ZONEDATA_GetExpObjSetId(fromZoneId);

    return EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(fromGroup, ZONEDATA_GetExpObjSetId(toZoneId));
}

/*
 * Starts the fade-out event of a map change effect.
 */
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait)
{
    switch (effect) {
    default:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault(gameSystem, fieldMap);
    case 0:
    case 1:
    case 3:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect(gameSystem, fieldMap, effect, skipWait);
    case 4:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4(gameSystem, fieldMap);
    case 5:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(gameSystem, fieldMap);
    case 6:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(gameSystem, fieldMap);
    case 7:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(gameSystem, fieldMap);
    case 8:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(gameSystem, fieldMap);
    case 9:
        return EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(gameSystem, fieldMap);
    }
}

/*
 * Starts the fade-in event of a map change effect.
 */
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg, u8 seasonShown, u8 seasonTarget)
{
    switch (effect) {
    default:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault(gameSystem, fieldMap);
    case 0:
    case 1:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect(gameSystem, fieldMap, effect, skipWait, restoreBg);
    case 3:
        return EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent(gameSystem, fieldMap, seasonShown, seasonTarget);
    case 5:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(gameSystem, fieldMap);
    case 6:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(gameSystem, fieldMap);
    case 7:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(gameSystem, fieldMap);
    case 8:
        return EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(gameSystem, fieldMap);
    case 9:
        EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(gameSystem, fieldMap);
        break;
    }
}

/*
 * Fade-in event with the season scoreboard and a finish callback.
 */
GameEvent *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 3;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(work->effect);
    work->finishCallback = finishCallback;
    work->finishCallbackArg = finishCallbackArg;
    return event;
}

/*
 * Fade-in event that restores the BG planes first.
 */
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int fadeSpeed)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(effect);
    work->fadeSpeed = fadeSpeed;
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunFadeOut, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(effect);
    return event;
}

/*
 * FADE_Start type of a map change effect.
 */
int EVENT_FIELDMAP_CONTROL_GetFadeKind(int effect)
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

u32 EVENT_FIELDMAP_CONTROL_LookupExitEffect(int fromGroup, int toGroup)
{
    EffectTable table = gExitEffectTable;

    return table.v[fromGroup][toGroup];
}

u32 EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(int fromGroup, int toGroup)
{
    EffectTable table = gEntranceEffectTable;

    return table.v[fromGroup][toGroup];
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunFadeOut, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(effect);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunFadeIn, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = effect;
    work->skipWait = skipWait;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(effect);
    work->restoreBg = restoreBg;
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 2;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(2);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 2;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(2);
    return event;
}

/*
 * Season scoreboard fade-in without a finish callback.
 */
GameEvent *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 3;
    work->seasonShown = seasonShown;
    work->seasonTarget = seasonTarget;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(work->effect);
    work->finishCallback = 0;
    work->finishCallbackArg = 0;
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect4, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 4;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(4);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect5, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 5;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(5);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect5, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 5;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(5);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect6, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 6;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(6);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect6, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 6;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(6);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect7, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 7;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(7);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect7, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 7;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(7);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeOutEffect8, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 8;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(8);
    return event;
}

GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect8, sizeof(FieldFadeWork));
    FieldFadeWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->effect = 8;
    work->fadeKind = EVENT_FIELDMAP_CONTROL_GetFadeKind(8);
    return event;
}

/*
 * Fade-out for effect 9: picks effect 5 to 8 from the way the player faces.
 */
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(GameSystem *gameSystem, FieldMap *fieldMap)
{
    switch (FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer(fieldMap))) {
    case 2:
    default:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(gameSystem, fieldMap);
    case 3:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(gameSystem, fieldMap);
    case 0:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(gameSystem, fieldMap);
    case 1:
        return EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(gameSystem, fieldMap);
    }
}

/*
 * Fade-in for effect 9, the twin of EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing.
 */
void EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(GameSystem *gameSystem, FieldMap *fieldMap)
{
    switch (FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer(fieldMap))) {
    case 2:
    default:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(gameSystem, fieldMap);
        break;
    case 3:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(gameSystem, fieldMap);
        break;
    case 0:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(gameSystem, fieldMap);
        break;
    case 1:
        EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(gameSystem, fieldMap);
        break;
    }
}


/*
 * Fade-out for the black and white effects: starts the fade and waits for it.
 */
int EVENT_FIELDMAP_CONTROL_RunFadeOut(GameEvent *event, int *seq, FieldFadeWork *work)
{
    switch (*seq) {
    case FADE_STEP_START:
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case FADE_STEP_WAIT:
        if (work->skipWait == 1)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        if (FADE_IsActive() == 0)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        break;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Fade-in for the black and white effects: restores the BG planes when the
 * work asks for it, then fades in and waits.
 */
int EVENT_FIELDMAP_CONTROL_RunFadeIn(GameEvent *event, int *seq, FieldFadeWork *work)
{
    switch (*seq) {
    case FADE_STEP_START:
        if (work->restoreBg != 0) {
            EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(work->fieldMap);
            EVENT_FIELDMAP_CONTROL_ResetBgAffine(work->fieldMap);
        }
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case FADE_STEP_WAIT:
        if (work->skipWait == 1)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        if (FADE_IsActive() == 0)
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        break;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Default fade-out: starts the fade, captures the screen into VRAM bank A
 * and switches the main display to the capture BG setup.
 */
int EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut(GameEvent *event, int *seq, FieldFadeWork *work)
{
    DispConfig dispConfig;

    if (*seq == 0) {
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        GX_SetBankForLCDC(8);
        REG_DISPCAPCNT = 0x80330010;
        OS_WaitVBlankIntr();
        OS_WaitVBlankIntr();
        dispConfig = sCaptureDispConfig;
        BG_SYS_SetGraphicsMode(&dispConfig);
        REG_BG2CNT = 0x4084 | (REG_BG2CNT & 0x43);
        GX_SetBankForBG(8);
        BG_SYS_SetVisibleLayer(2, 0);
        BG_SYS_SetPlaneVisible(2, 1);
        SYMBOL_MAP_StartBg2Scale();
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Default fade-in: cross-fades the captured screen into the map with an alpha
 * blend, restores the BG setup and loads the window graphics step by step.
 */
int EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn(GameEvent *event, int *seq, FieldFadeWork *work)
{
    struct FieldMsgBg *msgBg;

    switch (*seq) {
    case DEFAULT_FADE_IN_STEP_START:
        FIELDMAP_SetUpdateStopped(work->fieldMap, 1);
        work->blendStep = FADE_LEVEL_MAX;
        BG_SYS_SetVisibleLayer(2, 0);
        BG_SYS_SetVisibleLayer(0, 1);
        BG_SYS_SetPlaneVisible(0, 1);
        G2x_SetBlendAlpha_(REG_BLDCNT_ADDR, 4, 1, work->blendStep, 0);
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_BLEND:
        if (work->blendStep != 0) {
            work->blendStep = work->blendStep - 1;
            REG_BLDALPHA = ((FADE_LEVEL_MAX - work->blendStep) << 8) | work->blendStep;
            break;
        }
        BG_SYS_SetPlaneVisible(2, 0);
        GX_SetBankForLCDC(8);
        MIi_CpuClearFast(0, (void *)0x06800000, 0x20000);
        GX_DisableBankForLCDC();
        GX_SetBankForBG(8);
        SYMBOL_MAP_StopBg2Scale();
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_SAVE_PLANES:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(work->fieldMap);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_HIDE_MSG:
        FIELDMAP_ResetBgAffineHideMsg(work->fieldMap);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_WAIT_MSG_BG:
        msgBg = FIELDMAP_GetMsgBg(work->fieldMap);
        if (FIELD_MSGBG_IsSetupDone(msgBg) != 0) {
            FIELD_MSGBG_LoadWindowGraphicsStep(msgBg, 0);
            *seq = *seq + 1;
        }
        break;
    case DEFAULT_FADE_IN_STEP_LOAD_WINDOW_1:
        FIELD_MSGBG_LoadWindowGraphicsStep(FIELDMAP_GetMsgBg(work->fieldMap), 1);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_LOAD_WINDOW_2:
        FIELD_MSGBG_LoadWindowGraphicsStep(FIELDMAP_GetMsgBg(work->fieldMap), 2);
        *seq = *seq + 1;
        break;
    case DEFAULT_FADE_IN_STEP_FINISH:
        *seq = *seq + 1;
    case DEFAULT_FADE_IN_STEP_END:
        FIELDMAP_SetUpdateStopped(work->fieldMap, 0);
        return EVENT_FIELDMAP_CONTROL_FINISHED;
    }
    return EVENT_FIELDMAP_CONTROL_CONTINUE;
}

/*
 * Season fade-in without a finish callback: starts the season scoreboard
 * event as a child and ends.
 */
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn(GameEvent *event, int *seq, FieldFadeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case SEASON_FADE_STEP_START: {
        GameEvent *scoreboardEvent = EL_SCOREBOARD_StartOnField(gameSystem, fieldMap, work->seasonShown, work->seasonTarget);
        GAME_EVENT_CallEvent(event, scoreboardEvent);
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
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback(GameEvent *event, int *seq, FieldFadeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case SEASON_FADE_STEP_START: {
        GameEvent *scoreboardEvent = EL_SCOREBOARD_StartOnFieldWithCallback(gameSystem, fieldMap, work->seasonShown, work->seasonTarget, work->finishCallback, work->finishCallbackArg);
        GAME_EVENT_CallEvent(event, scoreboardEvent);
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
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect4(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 8, 8, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect5(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 2, 2, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect6(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 4, 4, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect7(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 10, 10, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect8(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        FADE_Start(work->fadeKind, 0, FADE_LEVEL_MAX, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 6, 6, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect5(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
        EVENT_FIELDMAP_CONTROL_ResetBgAffine(work->fieldMap);
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 3, 3, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect6(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
        EVENT_FIELDMAP_CONTROL_ResetBgAffine(work->fieldMap);
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 5, 5, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect7(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
        EVENT_FIELDMAP_CONTROL_ResetBgAffine(work->fieldMap);
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 7, 7, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect8(GameEvent *event, int *seq, FieldFadeWork *work)
{
    FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case WIPE_STEP_FADE:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
        EVENT_FIELDMAP_CONTROL_ResetBgAffine(work->fieldMap);
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, FADE_SPEED_DEFAULT);
        *seq = *seq + 1;
        break;
    case WIPE_STEP_START:
        WIPE_SYS_Start(3, 11, 11, 0, 6, 1, FIELDMAP_GetHeapId(fieldMap));
        *seq = *seq + 1;
        break;
    case WIPE_STEP_WAIT:
        if (WIPE_SYS_EndCheck() != 0)
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
int EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore(GameEvent *event, int *seq, FieldFadeWork *work)
{
    switch (*seq) {
    case FADE_STEP_START:
        FADE_Start(work->fadeKind, FADE_LEVEL_MAX, 0, work->fadeSpeed);
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(work->fieldMap);
        EVENT_FIELDMAP_CONTROL_ResetBgAffine(work->fieldMap);
        *seq = *seq + 1;
        break;
    case FADE_STEP_WAIT:
        if (work->skipWait == 1) {
            return EVENT_FIELDMAP_CONTROL_FINISHED;
        }
        if (FADE_IsActive() == 0) {
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
void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes()
{
    u32 mainPlanes = BG_SYS_GetMainVisiblePlanes();
    u32 subPlanes = BG_SYS_GetSubVisiblePlanes();

    FIELDMAP_SetBgMode();
    BG_SYS_SetMainVisiblePlanes(mainPlanes);
    BG_SYS_SetSubVisiblePlanes(subPlanes);
}

/*
 * Tail-call thunk: forwards to FIELDMAP_ResetBgAffineShowMsg with no argument change.
 */
void EVENT_FIELDMAP_CONTROL_ResetBgAffine(FieldMap *fieldMap)
{
    FIELDMAP_ResetBgAffineShowMsg(fieldMap);
}
