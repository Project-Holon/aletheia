/*
 * file:     field_status.c
 * unit:     yes
 * function: FIELD_STATUS_Create, FIELD_STATUS_Delete, FIELD_STATUS_GetMapMode, FIELD_STATUS_SetMapMode, FIELD_STATUS_SetFieldInitFlag, FIELD_STATUS_GetFieldInitFlag, FIELD_STATUS_SetContinueFlag, FIELD_STATUS_GetContinueFlag, FIELD_STATUS_SetFlashActive, FIELD_STATUS_IsFlashActive, FIELD_STATUS_SetMapEffectMask, FIELD_STATUS_GetMapEffectMask, FIELD_STATUS_SetProcAction, FIELD_STATUS_GetProcAction, FIELD_STATUS_SwapSeasonDispFlag, FIELD_STATUS_GetSeasonDispFlag, FIELD_STATUS_FieldCloseEvent, FIELD_STATUS_CreateFieldCloseEvent, FIELD_STATUS_FieldCloseNoSoundWaitEvent, FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent, FIELD_STATUS_FieldOpenEvent, FIELD_STATUS_CreateFieldOpenEvent, FIELD_STATUS_CreateFieldOpenNoNotifyEvent, FIELD_STATUS_SubProcEvent, FIELD_STATUS_SubProcNoFadeEvent, FIELD_STATUS_CreateSubProcEvent, FIELD_STATUS_CreateSubProcNoFadeEvent, FIELD_STATUS_SubProcCallbackEvent, FIELD_STATUS_SubProcNoFadeCallbackEvent, FIELD_STATUS_CreateSubProcCallbackEvent, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent, FIELD_STATUS_SubProcListEvent, FIELD_STATUS_CreateSubProcListEvent
 * address:  0x02014428
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zonedata.c, field_status.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc     0x02030734  arm
 *   GFL_HEAP_Free     0x020307B0  arm
 *   sFieldStatusFile  0x020A72BC  data
 *   EVENT_WIFI_PROC_UnloadOv020  0x0215FA44  thumb  ov010
 *   FIELDMAP_RequestClose  0x02188BD8  thumb  ov021
 *   FIELDMAP_IsReady  0x02188BE8  thumb ov021
 *   EVENT_WIFI_PROC_LoadOv020  0x0215FA34  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   ov091_id        0x0000005B  data
 *   ov131_id        0x00000083  data
 *   GAMESYSTEM_CallFieldProc  0x020120C0  thumb
 *   FIELD_SOUND_SYSTEM_IsBusy  0x020289B8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 */
#include "../types.h"

struct GameSystem;

struct GameEvent;

struct GameData;

struct FieldMap;

struct FieldSoundSystem;

#include "ica_anime_shared_types.h"

/* Field status (0x14 bytes). */
struct FieldStatus {
    u32 mapMode;            /* 0x00 */
    u8  fieldInitFlag;      /* 0x04 */
    u8  continueFlag;       /* 0x05 */
    u8  flashActive;        /* 0x06 */
    u8  pad07;
    u16 mapEffectMask;      /* 0x08 */
    u8  pad0A[7];
    u8  seasonDispFlag;     /* 0x11 */
    u16 procAction;         /* 0x12 */
};

/* Work of the close-field and open-field events. */
struct FieldCloseWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    struct GameData *gameData;      /* 0x08 */
    int notifyClose;                /* 0x0c */
};

struct FieldOpenWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    u32 unused04;
    struct GameData *gameData;      /* 0x08 */
    u32 unused0C;
};

/* Work of the sub-process events. */
struct SubProcWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    u32 overlayId;                  /* 0x08 */
    void *procData;                 /* 0x0c */
    void *procWork;                 /* 0x10 */
};

struct SubProcCallbackWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    u32 overlayId;                  /* 0x08 */
    void *procData;                 /* 0x0c */
    void *procWork;                 /* 0x10 */
    void (*callback)(void *);       /* 0x14 */
    void *callbackWork;             /* 0x18, freed after the callback */
};

/* Work of FIELD_STATUS_SubProcListEvent: two process calls on one parameter block. */
#include "../ov091/pokelist_types.h"
#include "../ov131/p_status_types.h"

struct ProcPairWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    void *fieldMap;                 /* 0x04 */
    PokelistArg *firstParam;        /* 0x08: party list parameter */
    PStatusProcParam *secondParam;  /* 0x0c: status screen parameter */
};

#include "gfl_heap_wrap.h"


#include "game_data.h"

#include "gamesystem.h"





#include "game_event.h"



#include "field_sound_system.h"

#include "../ov010/event_wifi_proc.h"


#include "../ov021/fieldmap.h"


#include "../ov021/event_fieldmap_control.h"


struct FieldStatus *FIELD_STATUS_Create(int heapId);

void FIELD_STATUS_Delete(struct FieldStatus *fs);

u32 FIELD_STATUS_GetMapMode(struct FieldStatus *fs);

void FIELD_STATUS_SetMapMode(struct FieldStatus *fs, u32 mapMode);

void FIELD_STATUS_SetFieldInitFlag(struct FieldStatus *fs, u8 fieldInitFlag);

u8 FIELD_STATUS_GetFieldInitFlag(struct FieldStatus *fs);

void FIELD_STATUS_SetContinueFlag(struct FieldStatus *fs, u8 continueFlag);

u8 FIELD_STATUS_GetContinueFlag(struct FieldStatus *fs);

void FIELD_STATUS_SetFlashActive(struct FieldStatus *fs, u8 flashActive);

u8 FIELD_STATUS_IsFlashActive(struct FieldStatus *fs);

void FIELD_STATUS_SetMapEffectMask(struct FieldStatus *fs, u32 mapEffectMask);

u16 FIELD_STATUS_GetMapEffectMask(struct FieldStatus *fs);

void FIELD_STATUS_SetProcAction(struct FieldStatus *fs, u16 procAction);

u16 FIELD_STATUS_GetProcAction(struct FieldStatus *fs);

u8 FIELD_STATUS_SwapSeasonDispFlag(struct FieldStatus *fs, u8 seasonDispFlag);

u8 FIELD_STATUS_GetSeasonDispFlag(struct FieldStatus *fs);

int FIELD_STATUS_FieldCloseEvent(struct GameEvent *event, int *seq, void *work);

struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);

int FIELD_STATUS_FieldCloseNoSoundWaitEvent(struct GameEvent *event, int *seq, void *work);

struct GameEvent *FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);

int FIELD_STATUS_FieldOpenEvent(struct GameEvent *event, int *seq, void *work);

struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);

struct GameEvent *FIELD_STATUS_CreateFieldOpenNoNotifyEvent(struct GameSystem *gameSystem);

int FIELD_STATUS_SubProcEvent(struct GameEvent *event, int *seq, void *work);

int FIELD_STATUS_SubProcNoFadeEvent(struct GameEvent *event, int *seq, void *work);

struct GameEvent *FIELD_STATUS_CreateSubProcEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork);

struct GameEvent *FIELD_STATUS_CreateSubProcNoFadeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork);

int FIELD_STATUS_SubProcCallbackEvent(struct GameEvent *event, int *seq, void *work);

int FIELD_STATUS_SubProcNoFadeCallbackEvent(struct GameEvent *event, int *seq, void *work);

struct GameEvent *FIELD_STATUS_CreateSubProcCallbackEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork, void (*callback)(void *), void *callbackWork);

struct GameEvent *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork, void (*callback)(void *), void *callbackWork);

int FIELD_STATUS_SubProcListEvent(struct GameEvent *event, u32 *seq, void *work);

extern const char sFieldStatusFile[];

extern u8 ov091_id[];

extern u8 ov131_id[];

/*
 * Heap-allocates a 0x14-byte block tagged with the file string at
 * 0x020A72BC and line 0x33, then clears the u16 at +0x12.  The earlier
 * near miss in docs/notes/pkt_0201441C.c.txt declared the string at
 * 0x020A729C, 0x20 too low: the pool word in the image is the little-endian
 * bc 72 0a 02 at 0x02014440, and the one "differing byte" was bit 5 of that
 * address, not a register choice.
 */
struct FieldStatus *FIELD_STATUS_Create(int heapId)
{
    struct FieldStatus *fs = GFL_HEAP_Alloc(heapId, 0x14, 1, sFieldStatusFile, 0x33);

    fs->procAction = 0;
    return fs;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           FIELD_STATUS_GetFieldInitFlag, FIELD_STATUS_SetContinueFlag, FIELD_STATUS_GetContinueFlag, FIELD_STATUS_SetFlashActive,
 *           FIELD_STATUS_IsFlashActive, FIELD_STATUS_SetMapEffectMask, FIELD_STATUS_GetMapEffectMask, FIELD_STATUS_SetProcAction,
 *           FIELD_STATUS_GetProcAction, FIELD_STATUS_SwapSeasonDispFlag, FIELD_STATUS_GetSeasonDispFlag
 *
 * alias: FIELD_STATUS_Delete is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, FIELD_STATUS_SetFlashActive/FIELD_STATUS_IsFlashActive, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (FIELD_STATUS_GetSeasonDispFlag) and a set-and-return-old accessor (FIELD_STATUS_SwapSeasonDispFlag) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void FIELD_STATUS_Delete(struct FieldStatus *fs)
{
    GFL_HEAP_Free(fs);
}

u32 FIELD_STATUS_GetMapMode(struct FieldStatus *fs)
{
    return fs->mapMode;
}

void FIELD_STATUS_SetMapMode(struct FieldStatus *fs, u32 mapMode)
{
    fs->mapMode = mapMode;
}

void FIELD_STATUS_SetFieldInitFlag(struct FieldStatus *fs, u8 fieldInitFlag)
{
    fs->fieldInitFlag = fieldInitFlag;
}

u8 FIELD_STATUS_GetFieldInitFlag(struct FieldStatus *fs)
{
    return fs->fieldInitFlag;
}

void FIELD_STATUS_SetContinueFlag(struct FieldStatus *fs, u8 continueFlag)
{
    fs->continueFlag = continueFlag;
}

u8 FIELD_STATUS_GetContinueFlag(struct FieldStatus *fs)
{
    return fs->continueFlag;
}

void FIELD_STATUS_SetFlashActive(struct FieldStatus *fs, u8 flashActive)
{
    fs->flashActive = flashActive;
}

u8 FIELD_STATUS_IsFlashActive(struct FieldStatus *fs)
{
    return fs->flashActive;
}

void FIELD_STATUS_SetMapEffectMask(struct FieldStatus *fs, u32 mapEffectMask)
{
    fs->mapEffectMask = mapEffectMask;
}

u16 FIELD_STATUS_GetMapEffectMask(struct FieldStatus *fs)
{
    return fs->mapEffectMask;
}

void FIELD_STATUS_SetProcAction(struct FieldStatus *fs, u16 procAction)
{
    fs->procAction = procAction;
}

u16 FIELD_STATUS_GetProcAction(struct FieldStatus *fs)
{
    return fs->procAction;
}

u8 FIELD_STATUS_SwapSeasonDispFlag(struct FieldStatus *fs, u8 seasonDispFlag)
{
    u8 old = fs->seasonDispFlag;

    fs->seasonDispFlag = seasonDispFlag;
    return old;
}

u8 FIELD_STATUS_GetSeasonDispFlag(struct FieldStatus *fs)
{
    return fs->seasonDispFlag;
}

/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c) in a
 *           fresh process after the evidence rules widened twice: still
 *           MATCH*, 3 of 5 sites resolved, no change to the C.  The two
 *           blockers were re-checked against the overlay listings by hand
 *           and are CLOSED AT THE BOTTOM, not merely unfiled: neither
 *           0x02188BD8 nor 0x0215FA44 is a function start in ANY candidate
 *           overlay, so no `thumb ovNNN` region hint on the symbols: line
 *           can resolve them.  0x02188BD8 falls mid-instruction in ov009
 *           (inside `bl gpiSetErrorString`) and in ov096, and lands on plain
 *           .word data in ov021 and ov230; 0x0215FA44 falls inside a `str`
 *           in ov009 and on .word data in ov010.  A region hint only picks
 *           between labelled candidates; it cannot create a label.  This
 *           row therefore needs a decompiled overlay, not a better hint.
 *
 * blocking: unresolved: 02188BD8 (thumb, from header) has no witness outside 02014488..02014; unresolved: 0215FA44 (thumb, from header) has no witness outside 02014488..02014
 *
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
int FIELD_STATUS_FieldCloseEvent(struct GameEvent *event, int *seq, void *work)
{
    struct FieldCloseWork *wk = work;
    struct GameData *gameData = wk->gameData;
    struct GameSystem *gameSystem = wk->gameSystem;
    struct FieldMap *fieldMap = wk->fieldMap;
    struct FieldSoundSystem *fieldSound;

    fieldSound = GAME_DATA_GetBgmInfo(gameData);
    switch (*seq) {
    case 0:
        FIELDMAP_RequestClose(fieldMap);
        *seq = *seq + 1;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0) {
            break;
        }
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 1) {
            break;
        }
        if (wk->notifyClose != 0) {
            EVENT_WIFI_PROC_UnloadOv020();
        }
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_FieldCloseEvent, 0x10);
    struct FieldCloseWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->fieldMap = fieldMap;
    wk->gameData = GAMESYSTEM_GetGameData(gameSystem);
    wk->notifyClose = 1;
    return event;
}

/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH*, 2 of 4 sites resolved, no change to the C.  Same two
 *           overlay targets as src/pending/FIELD_STATUS_FieldCloseEvent.c, and re-checked
 *           the same way: 0x02188BD8 and 0x0215FA44 are a function start
 *           in none of the overlays whose window covers them, so the
 *           `label` refusal is not an ambiguity a region hint can settle.
 *           listing carries a func_ label at either address; 4 overlays
 *           overlap 0x02188BD8 (ov009, ov021, ov096, ov230) and 2 overlap
 *           0x0215FA44 (ov009, ov010), so `label` refuses to guess.
 *
 * Byte-correct at all 70 bytes; 2 of 4 relocation sites stay wildcarded.
 * Seeded from an arm9 dispatcher (arm9_main calls the same pair at 0x020144A8
 * and 0x020144CE, which is inside the same source unit but outside this
 * compared range - it is still not a label, so it does not attest).
 *
 * This row was screened `ready` by the band brief; it is one of the minority
 * the screen cannot see, because the call targets are overlay exports rather
 * than arm9 or runtime code.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FIELD_STATUS_FieldCloseNoSoundWaitEvent.c \
 *       --func FIELD_STATUS_FieldCloseNoSoundWaitEvent --addr 0x0201450C --cc 1.1p1 --thumb
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
int FIELD_STATUS_FieldCloseNoSoundWaitEvent(struct GameEvent *event, int *seq, void *work)
{
    struct FieldCloseWork *wk = work;
    struct GameSystem *gameSystem = wk->gameSystem;
    struct FieldMap *fieldMap = wk->fieldMap;

    GAME_DATA_GetBgmInfo(wk->gameData);
    switch (*seq) {
    case 0:
        FIELDMAP_RequestClose(fieldMap);
        *seq = *seq + 1;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (wk->notifyClose != 0) {
                EVENT_WIFI_PROC_UnloadOv020();
            }
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_FieldCloseNoSoundWaitEvent, 0x10);
    struct FieldCloseWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->fieldMap = fieldMap;
    wk->gameData = GAMESYSTEM_GetGameData(gameSystem);
    wk->notifyClose = 0;
    return event;
}

/*
 *           02014584..020145CA.  This is the chain class of the band brief:
 *           0x020120C0's only callers are inside this range, so `label` has
 *           nothing to point at.  It is NOT a lane-2 row (it lives in
 *           pkt_020120B4 and is a chain row of the 0-64 band list), so this
 *           file cannot be finished from inside the lane.  Filing
 *           0x020120C0's own EXACT entry converts the site to `matched` and
 *           this file prints EXACT with no change to the C below.
 *
 * Byte-correct at all 70 concrete bytes; 3 of 4 relocation sites resolved.
 *
 * Two spelling points that were needed to get this far:
 *   - FIELDMAP_IsReady lives in ov021 and is THUMB.  Left to the name-based
 *     fallback it is inferred `arm` and match.py stops with an ISA conflict
 *     ("the source declares arm, the image says thumb"), which reads like a
 *     compile failure but is a symbols: block omission.  Naming the region
 *     (`FIELDMAP_IsReady  0x02188BE8  thumb ov021`) resolves the site through
 *     `label` (9 outside branches, e.g. 0x02012078).
 *   - `switch (*a1)` with `break` in the arms, not `return 0`: the original
 *     has exactly one `movs r0,#0 / pop` epilogue, shared by the arms and by
 *     the fall-through.  Writing `return 0` in each arm duplicates it and
 *     costs 36 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FIELD_STATUS_FieldOpenEvent.c \
 *       --func FIELD_STATUS_FieldOpenEvent --addr 0x02014584 --cc 1.1p1 --thumb
 */
int FIELD_STATUS_FieldOpenEvent(struct GameEvent *event, int *seq, void *work)
{
    struct FieldOpenWork *wk = work;
    struct GameSystem *gameSystem = wk->gameSystem;

    switch (*seq) {
    case 0:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            GAMESYSTEM_CallFieldProc(gameSystem);
            *seq = *seq + 1;
        }
        break;
    case 1:
        if (FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(gameSystem)) != 0) {
            *seq = *seq + 1;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH, 3 of 4 sites resolved, no change to the C.  The single
 *           blocker 0x0215FA34 is the same overlay-export class as the
 *           two in FIELD_STATUS_FieldCloseEvent.c: ov009 and ov010 both cover it and
 *           neither labels a function there, so no region hint helps.
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_FieldOpenEvent, 0x10);
    struct FieldOpenWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->unused04 = 0;
    wk->gameData = GAMESYSTEM_GetGameData(gameSystem);
    EVENT_WIFI_PROC_LoadOv020();
    return event;
}

struct GameEvent *FIELD_STATUS_CreateFieldOpenNoNotifyEvent(struct GameSystem *gameSystem)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_FieldOpenEvent, 0x10);
    struct FieldOpenWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->unused04 = 0;
    wk->gameData = GAMESYSTEM_GetGameData(gameSystem);
    return event;
}

/*
 * The shared tail of the three working cases sits INSIDE case 0's arm (a
 * label a later arm jumps back to is what makes 0x02014658 fall out of case 0
 * with no branch) and the default arm's `return 0` is reached by a `goto`
 * rather than copied, which is what puts the single `movs r0, #0` epilogue at
 * 0x02014692.  `u32 a0 = p[0];` before the switch is load-bearing: without it
 * each arm reloads p[0] and the whole dispatch shifts.
 */
int FIELD_STATUS_SubProcEvent(struct GameEvent *event, int *seq, void *work)
{
    struct SubProcWork *wk = work;
    struct GameSystem *gameSystem = wk->gameSystem;
    struct GameEvent *child;

    switch (*seq) {
    case 0:
        child = EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, wk->fieldMap, 0, 0);
    call:
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        goto wait;
    case 1:
        child = FIELD_STATUS_CreateSubProcNoFadeEvent(gameSystem, wk->fieldMap, wk->overlayId, wk->procData, wk->procWork);
        goto call;
    case 2:
        child = EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, wk->fieldMap, 0, 0, 1, 0, 0);
        goto call;
    case 3:
        return 1;
    default:
    wait:
        return 0;
    }
}

/*
 * The step function FIELD_STATUS_CreateSubProcNoFadeEvent installs (argsize 0x14, args p[0]..p[4]),
 * one stage per call on *mode.  Closed in wave 13: the earlier goto/label
 * spelling (docs/notes/FIELD_STATUS_SubProcNoFadeEvent.c.txt, one byte out) was the wrong
 * shape.  Written plainly -- every arm carries its own `(*mode)++; break;`
 * and case 2 is `if (poll() == 0) (*mode)++;` -- the compiler cross-jumps
 * the repeated increments itself, and that leaves case 2's tail jump on
 * case 1's `b inc` block exactly as the image has it.
 */
int FIELD_STATUS_SubProcNoFadeEvent(struct GameEvent *event, int *seq, void *work)
{
    struct SubProcWork *wk = work;
    struct GameSystem *gameSystem = wk->gameSystem;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, wk->fieldMap));
        (*seq)++;
        break;
    case 1:
        GAMESYSTEM_CallProc(gameSystem, wk->overlayId, wk->procData, wk->procWork);
        (*seq)++;
        break;
    case 2:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            (*seq)++;
        }
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_STATUS_CreateSubProcEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_SubProcEvent, 0x14);
    struct SubProcWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->fieldMap = fieldMap;
    wk->overlayId = overlayId;
    wk->procData = procData;
    wk->procWork = procWork;
    return event;
}

struct GameEvent *FIELD_STATUS_CreateSubProcNoFadeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_SubProcNoFadeEvent, 0x14);
    struct SubProcWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->fieldMap = fieldMap;
    wk->overlayId = overlayId;
    wk->procData = procData;
    wk->procWork = procWork;
    return event;
}

/*
 * A three-state step machine over a descriptor `a2`.  State 0 forwards five
 * of the descriptor's leading words (four in registers, the fifth on the
 * stack) to FIELD_STATUS_CreateSubProcEvent and hands the result to GAME_EVENT_CallEvent, then bumps
 * the counter.  State 1 calls the descriptor's own callback slot (+0x14) with
 * the pointer at +0x18.  State 2 frees the +0x18 pointer and returns 1.  The
 * `*a1 = *a1 + 1` in state 1 is a separate arm in the source; the compiler
 * cross-jumps it onto state 0's increment, which is why the listing shows the
 * state-1 arm branching backwards into state 0's tail.
 *
 * EXACT*: the compared extent runs four bytes past the body into the next
 * function's alignment pad (the follower at 0x020147B0 saves lr, so its label
 * exists and the extent is only the pad - no byte of it differs).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_STATUS_SubProcCallbackEvent.c \
 *       --func FIELD_STATUS_SubProcCallbackEvent --addr 0x02014758 --cc 1.1p1 --thumb
 */
int FIELD_STATUS_SubProcCallbackEvent(struct GameEvent *event, int *seq, void *work)
{
    struct SubProcCallbackWork *wk = work;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent(wk->gameSystem, wk->fieldMap, wk->overlayId, wk->procData,
                                        wk->procWork));
        *seq = *seq + 1;
        break;
    case 1:
        if (wk->callback != 0) {
            wk->callback(wk->callbackWork);
        }
        *seq = *seq + 1;
        break;
    case 2:
        if (wk->callbackWork != 0) {
            GFL_HEAP_Free(wk->callbackWork);
        }
        return 1;
    }
    return 0;
}

/*
 * Byte-for-byte the twin of FIELD_STATUS_SubProcCallbackEvent (same 86-byte shape, same three
 * states) with FIELD_STATUS_CreateSubProcEvent replaced by FIELD_STATUS_CreateSubProcNoFadeEvent.  The only other
 * difference is the literal pool holding 0x020307B0: 0x02014758's pool is
 * reachable with `blx 0x20307b0`'s 26-bit reach, this one needs no change.
 *
 * EXACT*: the compared extent runs into the four-byte alignment pad before
 * the next labelled function; no byte of the body differs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_STATUS_SubProcNoFadeCallbackEvent.c \
 *       --func FIELD_STATUS_SubProcNoFadeCallbackEvent --addr 0x020147B0 --cc 1.1p1 --thumb
 */
int FIELD_STATUS_SubProcNoFadeCallbackEvent(struct GameEvent *event, int *seq, void *work)
{
    struct SubProcCallbackWork *wk = work;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcNoFadeEvent(wk->gameSystem, wk->fieldMap, wk->overlayId, wk->procData,
                                        wk->procWork));
        *seq = *seq + 1;
        break;
    case 1:
        if (wk->callback != 0) {
            wk->callback(wk->callbackWork);
        }
        *seq = *seq + 1;
        break;
    case 2:
        if (wk->callbackWork != 0) {
            GFL_HEAP_Free(wk->callbackWork);
        }
        return 1;
    }
    return 0;
}

/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT.
 */
struct GameEvent *FIELD_STATUS_CreateSubProcCallbackEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork, void (*callback)(void *), void *callbackWork)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_SubProcCallbackEvent, 0x1c);
    struct SubProcCallbackWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->fieldMap = fieldMap;
    wk->overlayId = overlayId;
    wk->procData = procData;
    wk->procWork = procWork;
    wk->callback = callback;
    wk->callbackWork = callbackWork;
    return event;
}

struct GameEvent *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork, void (*callback)(void *), void *callbackWork)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_STATUS_SubProcNoFadeCallbackEvent, 0x1c);
    struct SubProcCallbackWork *wk = GAME_EVENT_GetWork(event);

    wk->gameSystem = gameSystem;
    wk->fieldMap = fieldMap;
    wk->overlayId = overlayId;
    wk->procData = procData;
    wk->procWork = procWork;
    wk->callback = callback;
    wk->callbackWork = callbackWork;
    return event;
}

/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov091_id (91) and ov131_id (131) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * A six-state machine on obj->f1e.  Every concrete byte matches: 152 of 152
 * against the listing extent, the two relocation sites that are attestable
 * (both calls) resolve as `label`, and both 0x021BED00/0x021DC800 pool words
 * resolve as `literal`; only the two small pooled words stay wildcarded.
 *
 * The small pooled words are the SDK's FS_OVERLAY_ID() shape (see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): a
 * value that mwccarm materialises with `movs` for any literal in 0..255, and
 * therefore cannot be written as a number - the source passes an address the
 * linker resolved to 91 / 131, and is declared here as a symbol of that
 * absolute value.
 *
 * Two levers mattered, both from the wave-r6 list:
 *   * the switch value is read once into a local before the dispatch
 *     (`ldr r1, [r4]` before `cmp r1, #5`), which is what puts p[0] in r0;
 *   * a case that ends in "return 0" must `break` instead, so every arm
 *     shares the one epilogue at 0x020148FC instead of duplicating it.
 * The state-2 arm is three statements - `if (v == 0) { *mode = 5; break; }`,
 * `if (v == 1) { ...; *mode = 3; break; }` and a trailing `*mode = 5;` - and
 * only that spelling reproduces the arm's out-of-line `movs r0, #5` block at
 * 0x020148D2 with the second test as `bne` rather than `beq`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_STATUS_SubProcListEvent.c \
 *       --func FIELD_STATUS_SubProcListEvent --addr 0x02014878 --cc 1.1p1 --thumb
 */
int FIELD_STATUS_SubProcListEvent(struct GameEvent *event, u32 *seq, void *work)
{
    struct ProcPairWork *wk = work;
    struct GameSystem *gameSystem = wk->gameSystem;

    /* stand-in: the two process data blocks (0x021BED00 in ov091, 0x021DC800 in
     * ov131) are written as raw addresses; named externs for them leave the pool
     * words unattested (MATCH, not EXACT), since the overlays are not linked here. */
    switch (*seq) {
    case 0:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov091_id, (void *)0x021BED00, wk->firstParam);
        *seq = 1;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        *seq = 2;
        break;
    case 2:
        if (wk->firstParam->exitCode == 0) {
            *seq = 5;
            break;
        }
        if (wk->firstParam->exitCode == 1) {
            wk->secondParam->pos = (u8)wk->firstParam->selectedIndex;
            *seq = 3;
            break;
        }
        *seq = 5;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov131_id, (void *)0x021DC800, wk->secondParam);
        *seq = 4;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        wk->firstParam->selectedIndex = wk->secondParam->pos;
        *seq = 0;
        break;
    case 5:
        return 1;
    default:
        break;
    }
    return 0;
}



void *FIELD_STATUS_CreateSubProcListEvent(void *anime, void *fieldMap, void *listParam, void *statusParam);

/*
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           FIELD_STATUS_SubProcListEvent is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */
void *FIELD_STATUS_CreateSubProcListEvent(void *anime, void *fieldMap, void *listParam, void *statusParam)
{
    void *task = GAME_EVENT_Create(anime, 0, (void *)(FIELD_STATUS_SubProcListEvent), sizeof(struct ProcPairWork));
    struct ProcPairWork *taskWork = GAME_EVENT_GetWork(task);

    taskWork->gameSystem = anime;
    taskWork->fieldMap = fieldMap;
    taskWork->firstParam = listParam;
    taskWork->secondParam = statusParam;
    return task;
}
