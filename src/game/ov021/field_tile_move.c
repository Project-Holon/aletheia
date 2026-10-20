/*
 * file:     field_tile_move.c
 * unit:     yes
 * function: FIELD_TILE_MOVE_FindSpinEntry, FIELD_TILE_MOVE_HasSpinEntry, FIELD_TILE_MOVE_SpinTaskMain, FIELD_TILE_MOVE_StartSpinTask, FIELD_TILE_MOVE_IsSpinTile, FIELD_TILE_MOVE_GetSpinStepAcmd, FIELD_TILE_MOVE_GetSpinStopDir, FIELD_TILE_MOVE_GetSpinInterval, FIELD_TILE_MOVE_GetSpinTileAttr, FIELD_TILE_MOVE_SpinTick, FIELD_TILE_MOVE_SpinStartStep, FIELD_TILE_MOVE_SpinSelectEntry, FIELD_TILE_MOVE_SpinIsBlocked, FIELD_TILE_MOVE_SpinFinish, FIELD_TILE_MOVE_FindSlideEntry, FIELD_TILE_MOVE_HasSlideEntry, FIELD_TILE_MOVE_FindBumpEntry, FIELD_TILE_MOVE_SlideTaskMain, FIELD_TILE_MOVE_StartSlideTask, FIELD_TILE_MOVE_IsSlideTile, FIELD_TILE_MOVE_GetSlideStepAcmd, FIELD_TILE_MOVE_GetBumpAcmd, FIELD_TILE_MOVE_GetSlideTileAttr, FIELD_TILE_MOVE_SlideStartStep, FIELD_TILE_MOVE_SlideFinishBump, FIELD_TILE_MOVE_SlideSelectSlideEntry, FIELD_TILE_MOVE_SlideSelectBumpEntry, FIELD_TILE_MOVE_SlideShowSurfPokemon, FIELD_TILE_MOVE_SlidePlayBumpSe, FIELD_TILE_MOVE_SlidePlayBumpEffectSe, FIELD_TILE_MOVE_SlidePlayLoopSe, FIELD_TILE_MOVE_SlideStopLoopSe
 * address:  0x021C8984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C8984: floor tile tasks started from the attribute check in field_event_check.c (FIELD_EVENT_CHECK_CheckTileMoveTask) (file name guess, no anchor).
 *
 * symbols:
 *   sFieldTileMoveSpinTable  0x021DAB24  data  ov021  a4
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   sFieldTileMoveSlideTable  0x021DAB54  data  a4
 *   sFieldTileMoveBumpTable  0x021DAB44  data  ov021  a4
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetWakeEnabled  0x021ACBC8  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_IsResourceLoaded  0x021ABE8C  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartAtPos  0x021AD598  thumb  ov021
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../ov010/fldmmdl_types.h"

#include "../types.h"

#include "../sdk_fx.h"

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct FieldMap FieldMap;
typedef struct FieldPlayer FieldPlayer;
typedef struct FieldEffectSys FieldEffectCtrl;

/* Update function of a game event: (event, state, work), returns 1 when finished. */

/* Spin tile table entry: the player keeps turning on tiles with this attribute. */
typedef struct TileSpinEntry {
    u16 attr;
    u16 stepAcmd;      /* animation command of one turn step */
    u16 stopDir;       /* direction the player faces when the spin ends */
    u16 interval;      /* frames between turns */
} TileSpinEntry;

/* Slide tile table entry: the player slides over tiles with this attribute. */
typedef struct TileSlideEntry {
    u16 attr;
    u16 stepAcmd;      /* animation command of one slide step */
    u16 reserved;      /* never read */
} TileSlideEntry;

/* Bump tile table entry: the slide ends against tiles with this attribute. */
typedef struct TileBumpEntry {
    u16 attr;
    u16 bumpAcmd;      /* animation command of the bump */
} TileBumpEntry;

/* Work of the spin task (0x1C). */
typedef struct TileSpinWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    FieldPlayer *player;        /* 0x08 */
    Mmdl *mmdl;                 /* 0x0C, the player's field model */
    TileSpinEntry *entry;       /* 0x10, entry of the tile the player stands on */
    u16 dir;                    /* 0x14, display direction while spinning */
    u16 reserved16;             /* 0x16 */
    u32 frameCount;             /* 0x18 */
} TileSpinWork;

/* Work of the slide task (0x28). */
typedef struct TileSlideWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    FieldPlayer *player;        /* 0x08 */
    Mmdl *mmdl;                 /* 0x0C, the player's field model */
    TileSlideEntry *slideEntry; /* 0x10, slide entry of the tile under the player */
    TileBumpEntry *bumpEntry;   /* 0x14, bump entry of the tile under the player */
    u32 bumpStarted;            /* 0x18, set once the bump animation runs */
    int bumpSeSlot;             /* 0x1C, SE slot of 0x55E (bump) */
    int bumpEffectSeSlot;       /* 0x20, SE slot of 0x6E2 (bump effect) */
    int slideSeSlot;            /* 0x24, SE slot of 0x769 (slide loop) */
} TileSlideWork;

#include "../ov010/fldmmdl.h"
#include "../arm9/gfl_use.h"
#include "../arm9/game_event.h"
#include "fieldmap.h"
extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);
extern void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *outPos);
struct FieldG3dMapper;
#include "map_attr.h"
#include "../ov010/fldmmdl_move.h"
extern u32 FIELD_PLAYER_GetRideEffect(FieldPlayer *player);
extern u32 FLDEFF_NAMIPOKE_SetWakeEnabled(u32 namipoke, int visible);
struct FieldEffectCont;
struct FieldEffectSys;
#include "field_effect.h"
extern void FLDEFF_NAMIPOKE_SPLASH_StartAtPos(struct FieldEffectSys *fieldEffect, s32 type, VecFx32 *pos);

TileSpinEntry *FIELD_TILE_MOVE_FindSpinEntry(u16 attr);
int FIELD_TILE_MOVE_HasSpinEntry(u16 attr);
int FIELD_TILE_MOVE_SpinTaskMain(GameEvent *event, int *state, TileSpinWork *work);
GameEvent *FIELD_TILE_MOVE_StartSpinTask(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int FIELD_TILE_MOVE_IsSpinTile(u16 attr);
u16 FIELD_TILE_MOVE_GetSpinStepAcmd(TileSpinWork *work);
u16 FIELD_TILE_MOVE_GetSpinStopDir(TileSpinWork *work);
int FIELD_TILE_MOVE_GetSpinInterval(TileSpinWork *work);
u16 FIELD_TILE_MOVE_GetSpinTileAttr(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinTick(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinStartStep(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinSelectEntry(TileSpinWork *work);
int FIELD_TILE_MOVE_SpinIsBlocked(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinFinish(TileSpinWork *work);
const TileSlideEntry *FIELD_TILE_MOVE_FindSlideEntry(u16 attr);
int FIELD_TILE_MOVE_HasSlideEntry(u16 attr);
TileBumpEntry *FIELD_TILE_MOVE_FindBumpEntry(u16 attr);
int FIELD_TILE_MOVE_SlideTaskMain(GameEvent *event, int *state, TileSlideWork *work);
GameEvent *FIELD_TILE_MOVE_StartSlideTask(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int FIELD_TILE_MOVE_IsSlideTile(u16 attr);
u16 FIELD_TILE_MOVE_GetSlideStepAcmd(TileSlideWork *work);
u16 FIELD_TILE_MOVE_GetBumpAcmd(TileSlideWork *work);
u16 FIELD_TILE_MOVE_GetSlideTileAttr(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideStartStep(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideFinishBump(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideSelectSlideEntry(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideSelectBumpEntry(TileSlideWork *work);
int FIELD_TILE_MOVE_SlideShowSurfPokemon(TileSlideWork *work);
void FIELD_TILE_MOVE_SlidePlayBumpSe(TileSlideWork *work);
void FIELD_TILE_MOVE_SlidePlayBumpEffectSe(TileSlideWork *work);
void FIELD_TILE_MOVE_SlidePlayLoopSe(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideStopLoopSe(TileSlideWork *work);
extern TileSpinEntry sFieldTileMoveSpinTable[4];
extern const TileSlideEntry sFieldTileMoveSlideTable[4];
extern TileBumpEntry sFieldTileMoveBumpTable[4];

/* Finds the spin table entry for a tile attribute. */
TileSpinEntry *FIELD_TILE_MOVE_FindSpinEntry(u16 attr)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (attr == sFieldTileMoveSpinTable[i].attr)
            return &sFieldTileMoveSpinTable[i];
    }
    return 0;
}

int FIELD_TILE_MOVE_HasSpinEntry(u16 attr)
{
    if (FIELD_TILE_MOVE_FindSpinEntry(attr) != 0) {
        return 1;
    }
    return 0;
}

/* Spin task: 0 checks the tile, 1 turns the player every interval until blocked, 2 ends. */
int FIELD_TILE_MOVE_SpinTaskMain(GameEvent *event, int *state, TileSpinWork *work)
{
    switch (*state) {
    case 0:
        if (FIELD_TILE_MOVE_HasSpinEntry(FIELD_TILE_MOVE_GetSpinTileAttr(work)) == 0) {
            *state = 2;
        } else {
            *state = 1;
        }
        break;
    case 1:
        FIELD_TILE_MOVE_SpinTick(work);
        if (FLDMMDL_CheckEndAcmd(work->mmdl)) {
            FIELD_TILE_MOVE_SpinSelectEntry(work);
            if (FIELD_TILE_MOVE_SpinIsBlocked(work)) {
                GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(0x694));
                *state = 2;
            } else {
                FIELD_TILE_MOVE_SpinStartStep(work);
            }
        }
        break;
    case 2:
        FIELD_TILE_MOVE_SpinFinish(work);
        return 1;
    }
    return 0;
}

/* Creates the spin task with a 0x1C byte work area and fills it from the field map. */
GameEvent *FIELD_TILE_MOVE_StartSpinTask(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, (GameEventFunc)FIELD_TILE_MOVE_SpinTaskMain, 0x1C);
    TileSpinWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->player = FIELDMAP_GetFieldPlayer(fieldMap);
    work->mmdl = FIELD_PLAYER_GetMmdl(work->player);
    work->entry = 0;
    work->dir = FLDMMDL_GetDirDisp(work->mmdl);
    work->frameCount = 0;
    return event;
}

/* Tail-call thunk: forwards to FIELD_TILE_MOVE_HasSpinEntry with no argument change. */
int FIELD_TILE_MOVE_IsSpinTile(u16 attr)
{
    return FIELD_TILE_MOVE_HasSpinEntry(attr);
}

u16 FIELD_TILE_MOVE_GetSpinStepAcmd(TileSpinWork *work)
{
    if (work->entry != 0) {
        return work->entry->stepAcmd;
    }
    return 0;
}

u16 FIELD_TILE_MOVE_GetSpinStopDir(TileSpinWork *work)
{
    if (work->entry != 0) {
        return work->entry->stopDir;
    }
    return 0;
}

int FIELD_TILE_MOVE_GetSpinInterval(TileSpinWork *work)
{
    if (work->entry != 0) {
        return work->entry->interval;
    }
    return 0;
}

/* Attribute of the tile under the player. */
u16 FIELD_TILE_MOVE_GetSpinTileAttr(TileSpinWork *work)
{
    VecFx32 pos;
    FIELD_PLAYER_GetPos(work->player, &pos);
    return MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt(FIELDMAP_GetG3dMapper(work->fieldMap), &pos));
}

/* Counts frames; every interval turns the player's display direction a quarter. */
void FIELD_TILE_MOVE_SpinTick(TileSpinWork *work)
{
    int interval = FIELD_TILE_MOVE_GetSpinInterval(work);

    work->frameCount = work->frameCount + 1;
    if (work->frameCount % interval == 0) {
        work->dir = (work->dir + 1) % 4;
        FLDMMDL_ClearStatusBit(work->mmdl, MMDL_STABIT_PAUSE_DIR);
        FLDMMDL_SetDirDispCheckPause(work->mmdl, work->dir);
        FLDMMDL_SetStatusBit(work->mmdl, MMDL_STABIT_PAUSE_DIR);
    }
}

/* Starts one spin step: animation command, direction pause, looping SE. */
void FIELD_TILE_MOVE_SpinStartStep(TileSpinWork *work)
{
    FLDMMDL_SetAcmd(work->mmdl, FIELD_TILE_MOVE_GetSpinStepAcmd(work));
    FLDMMDL_SetStatusBit(work->mmdl, MMDL_STABIT_PAUSE_DIR);
    if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x694)) == 0)
        GFL_USE_PlaySeDefaultVolume(0x694);
}

void FIELD_TILE_MOVE_SpinSelectEntry(TileSpinWork *work)
{
    TileSpinEntry *entry = FIELD_TILE_MOVE_FindSpinEntry(FIELD_TILE_MOVE_GetSpinTileAttr(work));
    if (entry != 0)
        work->entry = entry;
}

/* Nonzero when the tile in the stop direction blocks the player. */
int FIELD_TILE_MOVE_SpinIsBlocked(TileSpinWork *work)
{
    if (FLDMMDL_MOVE_HitCheckMoveDir(work->mmdl, FIELD_TILE_MOVE_GetSpinStopDir(work)) != 0) {
        return 1;
    }
    return 0;
}

void FIELD_TILE_MOVE_SpinFinish(TileSpinWork *work)
{
    FLDMMDL_ClearStatusBit(work->mmdl, MMDL_STABIT_PAUSE_DIR);
    if (work->entry != 0)
        FLDMMDL_SetDirDispCheckPause(work->mmdl, FIELD_TILE_MOVE_GetSpinStopDir(work));
}

/*
 * 2026-10-02: the base/offset register swap of the earlier DIFF closed by
 * declaring the table const (the const element type recolours the hoisted
 * table base into r3).
 */
const TileSlideEntry *FIELD_TILE_MOVE_FindSlideEntry(u16 attr)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (sFieldTileMoveSlideTable[i].attr == attr)
            return &sFieldTileMoveSlideTable[i];
    }
    return 0;
}

int FIELD_TILE_MOVE_HasSlideEntry(u16 attr)
{
    if (FIELD_TILE_MOVE_FindSlideEntry(attr) != 0) {
        return 1;
    }
    return 0;
}

TileBumpEntry *FIELD_TILE_MOVE_FindBumpEntry(u16 attr)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (attr == sFieldTileMoveBumpTable[i].attr)
            return &sFieldTileMoveBumpTable[i];
    }
    return 0;
}

/* Slide task: 0 checks the tile, 1 slides step by step until no slide or bump tile is left, 2 ends. */
int FIELD_TILE_MOVE_SlideTaskMain(GameEvent *event, int *state, TileSlideWork *work)
{
    switch (*state) {
    case 0:
        if (FIELD_TILE_MOVE_HasSlideEntry(FIELD_TILE_MOVE_GetSlideTileAttr(work)) == 0) {
            *state = 2;
        } else {
            FLDEFF_NAMIPOKE_SetWakeEnabled(FIELD_PLAYER_GetRideEffect(work->player), 0);
            FIELD_TILE_MOVE_SlidePlayLoopSe(work);
            *state = 1;
        }
        break;
    case 1:
        FIELD_TILE_MOVE_SlidePlayLoopSe(work);
        if (FLDMMDL_CheckEndAcmd(work->mmdl)) {
            FIELD_TILE_MOVE_SlideFinishBump(work);
            FIELD_TILE_MOVE_SlideSelectSlideEntry(work);
            FIELD_TILE_MOVE_SlideSelectBumpEntry(work);
            if (work->slideEntry == 0 && work->bumpEntry == 0) {
                FIELD_TILE_MOVE_SlideStopLoopSe(work);
                *state = 2;
            } else {
                FIELD_TILE_MOVE_SlideStartStep(work);
            }
        }
        break;
    case 2:
        FIELD_TILE_MOVE_SlideShowSurfPokemon(work);
        return 1;
    }
    return 0;
}

/* Creates the slide task with a 0x28 byte work area; loads the three SE slots (0x55E, 0x6E2, 0x769). */
GameEvent *FIELD_TILE_MOVE_StartSlideTask(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    FieldPlayer *player = FIELDMAP_GetFieldPlayer(fieldMap);
    GameEvent *event = GAME_EVENT_Create(gameSystem, parent, (GameEventFunc)FIELD_TILE_MOVE_SlideTaskMain, 0x28);
    TileSlideWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->player = player;
    work->mmdl = FIELD_PLAYER_GetMmdl(work->player);
    work->slideEntry = 0;
    work->bumpEntry = 0;
    work->bumpStarted = 0;
    work->bumpSeSlot = GFL_USE_GetSeSlot(0x55E);
    work->bumpEffectSeSlot = GFL_USE_GetSeSlot(0x6E2);
    work->slideSeSlot = GFL_USE_GetSeSlot(0x769);
    return event;
}

/* Tail-call thunk: forwards to FIELD_TILE_MOVE_HasSlideEntry with no argument change. */
int FIELD_TILE_MOVE_IsSlideTile(u16 attr)
{
    return FIELD_TILE_MOVE_HasSlideEntry(attr);
}

u16 FIELD_TILE_MOVE_GetSlideStepAcmd(TileSlideWork *work)
{
    if (work->slideEntry != 0) {
        return work->slideEntry->stepAcmd;
    }
    return 0;
}

u16 FIELD_TILE_MOVE_GetBumpAcmd(TileSlideWork *work)
{
    if (work->bumpEntry != 0) {
        return work->bumpEntry->bumpAcmd;
    }
    return 0;
}

/* Attribute of the tile under the player. */
u16 FIELD_TILE_MOVE_GetSlideTileAttr(TileSlideWork *work)
{
    VecFx32 pos;
    FIELD_PLAYER_GetPos(work->player, &pos);
    return MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt(FIELDMAP_GetG3dMapper(work->fieldMap), &pos));
}

/* Starts the next step: the bump animation if the tile bumps, else the slide step. */
void FIELD_TILE_MOVE_SlideStartStep(TileSlideWork *work)
{
    if (work->bumpEntry != 0) {
        FLDMMDL_SetAcmd(work->mmdl, FIELD_TILE_MOVE_GetBumpAcmd(work));
        FIELD_TILE_MOVE_SlidePlayBumpSe(work);
        work->bumpStarted = 1;
        return;
    }
    if (work->slideEntry != 0)
        FLDMMDL_SetAcmd(work->mmdl, FIELD_TILE_MOVE_GetSlideStepAcmd(work));
}

/* After a bump step: registers effect 9, spawns it at the player and clears the bump state. */
void FIELD_TILE_MOVE_SlideFinishBump(TileSlideWork *work)
{
    VecFx32 pos;
    int effectId;
    FieldEffectCtrl *effectCtrl;

    if (work->bumpEntry != 0) {
        effectCtrl = (struct FieldEffectSys *)FIELDMAP_GetEffect(work->fieldMap);
        effectId = 9;
        if (FIELD_EFFECT_IsResourceLoaded((struct FieldEffectSys *)effectCtrl, effectId) == 0) {
            FIELD_EFFECT_LoadResources((struct FieldEffectSys *)effectCtrl, &effectId, 1);
        }
        FIELD_PLAYER_GetPos(work->player, &pos);
        FLDEFF_NAMIPOKE_SPLASH_StartAtPos(effectCtrl, 0, &pos);
        FIELD_TILE_MOVE_SlidePlayBumpEffectSe(work);
        work->bumpEntry = 0;
        work->bumpStarted = 0;
    }
}

void FIELD_TILE_MOVE_SlideSelectSlideEntry(TileSlideWork *work)
{
    work->slideEntry = (TileSlideEntry *)FIELD_TILE_MOVE_FindSlideEntry(FIELD_TILE_MOVE_GetSlideTileAttr(work));
}

void FIELD_TILE_MOVE_SlideSelectBumpEntry(TileSlideWork *work)
{
    work->bumpEntry = FIELD_TILE_MOVE_FindBumpEntry(FIELD_TILE_MOVE_GetSlideTileAttr(work));
}

/* Shows the player's surf Pokemon again. */
int FIELD_TILE_MOVE_SlideShowSurfPokemon(TileSlideWork *work)
{
    return FLDEFF_NAMIPOKE_SetWakeEnabled(FIELD_PLAYER_GetRideEffect(work->player), 1);
}

/* Stops the slide loop SE and plays the bump SE. */
void FIELD_TILE_MOVE_SlidePlayBumpSe(TileSlideWork *work)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        GFL_USE_StopSeSlot(work->slideSeSlot);
        GFL_USE_PlaySeInSlot(0x55E, work->bumpSeSlot);
    }
}

void FIELD_TILE_MOVE_SlidePlayBumpEffectSe(TileSlideWork *work)
{
    if (GFL_USE_IsLoaderBusy() == 0)
        GFL_USE_PlaySeInSlot(0x6E2, work->bumpEffectSeSlot);
}

/* Keeps the slide loop SE (0x769) playing until a bump starts. */
void FIELD_TILE_MOVE_SlidePlayLoopSe(TileSlideWork *work)
{
    if (GFL_USE_IsLoaderBusy() == 0 && work->bumpStarted == 0 && GFL_USE_IsSeSlotBusy(work->slideSeSlot) == 0)
        GFL_USE_PlaySeInSlot(0x769, work->slideSeSlot);
}

/* Tail-call thunk: stops the slide loop SE. */
void FIELD_TILE_MOVE_SlideStopLoopSe(TileSlideWork *work)
{
    GFL_USE_StopSeSlot(work->slideSeSlot);
}
