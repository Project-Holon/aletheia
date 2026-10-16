/*
 * file:     iss_city_sys.c
 * unit:     yes
 * function: ISS_CITY_SYS_Create, ISS_CITY_SYS_Delete, ISS_CITY_SYS_Update, ISS_CITY_SYS_Start, ISS_CITY_SYS_Stop, ISS_CITY_SYS_NotifyZoneChange, ISS_CITY_SYS_InitState, ISS_CITY_SYS_InitUnits, ISS_CITY_SYS_ReleaseUnits, ISS_CITY_SYS_LoadUnits, ISS_CITY_SYS_FreeUnits, ISS_CITY_SYS_GetMode, ISS_CITY_SYS_SetMode, ISS_CITY_SYS_Enable, ISS_CITY_SYS_Disable, ISS_CITY_SYS_HandleZoneChange, ISS_CITY_SYS_GetPlayerZoneId, ISS_CITY_SYS_IsEnabled, ISS_CITY_SYS_UpdateByMode, ISS_CITY_SYS_UpdateSteady, ISS_CITY_SYS_UpdateFadeIn, ISS_CITY_SYS_UpdateFadeOut, ISS_CITY_SYS_GetCurrentUnit, ISS_CITY_SYS_GetCurrentUnitIndex, ISS_CITY_SYS_HasCurrentUnit, ISS_CITY_SYS_HasUnitForZone, ISS_CITY_SYS_SelectUnitForZone, ISS_CITY_SYS_FindUnitIndex, ISS_CITY_SYS_GetFadeLevel, ISS_CITY_SYS_StepFadeIn, ISS_CITY_SYS_StepFadeOut, ISS_CITY_SYS_SetFadeLevel, ISS_CITY_SYS_GetVolume, ISS_CITY_SYS_RefreshVolume, ISS_CITY_SYS_CalcUnitVolume, ISS_CITY_SYS_SetVolume, ISS_CITY_SYS_ApplyVolume, ISS_CITY_SYS_CalcOutputVolume
 * address:  0x0202AAF4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_city_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ISS_CITY_SYS_sSourceFileName     0x020A76E8  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   ISS_CITY_UNIT_Create 0x0202AEEC thumb arm9
 *   ISS_CITY_UNIT_Delete 0x0202AF28 thumb arm9
 *   ISS_CITY_UNIT_GetZoneId 0x0202AF30 thumb arm9
 *   ISS_CITY_UNIT_CalcVolume 0x0202AF34 thumb arm9
 */
#include "iss_city_sys_shared_types.h"

struct PlayerWork;

struct PlayerPosition;

/* ISS (interactive sound system) city ambience: the fade state machine modes. */
#define ISS_CITY_MODE_STEADY   0

#define ISS_CITY_MODE_FADE_IN  1

#define ISS_CITY_MODE_FADE_OUT 2

#define ISS_CITY_UNIT_NONE     0xff   /* currentUnit when no unit is selected */

#define ISS_CITY_LEVEL_MAX     0x7f   /* fade level and volume range 0..127 */

#define ISS_CITY_FADE_STEP     2

struct IssCitySys {
    struct PlayerWork *player;
    u32 enabled;
    u32 mode;               /* ISS_CITY_MODE_* */
    u32 volume;             /* target volume from the unit and player position */
    u32 fadeLevel;          /* 0..ISS_CITY_LEVEL_MAX, scales volume */
    struct IssCityUnit **units;
    u8 unitCount;
    u8 currentUnit;         /* index into units, or ISS_CITY_UNIT_NONE */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *sourceFile, u16 sourceLine);

extern u32 ARC_TOOL_GetArchiveFileCount(u32 archiveId);

extern u32 GFL_HEAP_Free(void *block);

extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);

extern struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);

extern void GFL_USE_SetBgmTrackVolume(u32 soundTarget, u32 volume);

struct IssCitySys *ISS_CITY_SYS_Create(struct PlayerWork *player, u32 heapId);

void ISS_CITY_SYS_Delete(struct IssCitySys *sys);

void ISS_CITY_SYS_Update(struct IssCitySys *sys);

void ISS_CITY_SYS_Start(struct IssCitySys *sys);

void ISS_CITY_SYS_Stop(struct IssCitySys *sys);

void ISS_CITY_SYS_NotifyZoneChange(struct IssCitySys *sys, u32 zoneId);

void ISS_CITY_SYS_InitState(struct IssCitySys *sys, u32 heapIdUnused, struct PlayerWork *player);

void ISS_CITY_SYS_InitUnits(struct IssCitySys *sys, u32 heapId);

void ISS_CITY_SYS_ReleaseUnits(struct IssCitySys *sys);

void ISS_CITY_SYS_LoadUnits(struct IssCitySys *sys, u32 heapId);

void ISS_CITY_SYS_FreeUnits(struct IssCitySys *sys);

u32 ISS_CITY_SYS_GetMode(struct IssCitySys *sys);

void ISS_CITY_SYS_SetMode(struct IssCitySys *sys, u32 mode);

void ISS_CITY_SYS_Enable(struct IssCitySys *sys);

int ISS_CITY_SYS_Disable(struct IssCitySys *sys);

void ISS_CITY_SYS_HandleZoneChange(struct IssCitySys *sys, u32 zoneId);

u32 ISS_CITY_SYS_GetPlayerZoneId(struct IssCitySys *sys);

u32 ISS_CITY_SYS_IsEnabled(struct IssCitySys *sys);

void ISS_CITY_SYS_UpdateByMode(struct IssCitySys *sys);

void ISS_CITY_SYS_UpdateSteady(struct IssCitySys *sys);

void ISS_CITY_SYS_UpdateFadeIn(struct IssCitySys *sys);

void ISS_CITY_SYS_UpdateFadeOut(struct IssCitySys *sys);

struct IssCityUnit *ISS_CITY_SYS_GetCurrentUnit(struct IssCitySys *sys);

u32 ISS_CITY_SYS_GetCurrentUnitIndex(struct IssCitySys *sys);

int ISS_CITY_SYS_HasCurrentUnit(struct IssCitySys *sys);

int ISS_CITY_SYS_HasUnitForZone(struct IssCitySys *sys, u32 zoneId);

int ISS_CITY_SYS_SelectUnitForZone(struct IssCitySys *sys, u32 zoneId);

u8 ISS_CITY_SYS_FindUnitIndex(struct IssCitySys *sys, u32 zoneId);

u32 ISS_CITY_SYS_GetFadeLevel(struct IssCitySys *sys);

int ISS_CITY_SYS_StepFadeIn(struct IssCitySys *sys);

int ISS_CITY_SYS_StepFadeOut(struct IssCitySys *sys);

void ISS_CITY_SYS_SetFadeLevel(struct IssCitySys *sys, u32 fadeLevel);

u32 ISS_CITY_SYS_GetVolume(struct IssCitySys *sys);

int ISS_CITY_SYS_RefreshVolume(struct IssCitySys *sys);

int ISS_CITY_SYS_CalcUnitVolume(struct IssCitySys *sys);

void ISS_CITY_SYS_SetVolume(struct IssCitySys *sys, u32 volume);

void ISS_CITY_SYS_ApplyVolume(struct IssCitySys *sys);

int ISS_CITY_SYS_CalcOutputVolume(struct IssCitySys *sys);

struct IssCityUnit *ISS_CITY_UNIT_Create(u32 heapId, u32 memberIndex);

void ISS_CITY_UNIT_Delete(struct IssCityUnit *unit);

u32 ISS_CITY_UNIT_GetZoneId(struct IssCityUnit *unit);

u8 ISS_CITY_UNIT_CalcVolume(const struct IssCityUnit *unit, const s32 *playerPos);

extern const char ISS_CITY_SYS_sSourceFileName[];

/*
 * closed:   blocker ISS_CITY_SYS_InitUnits.c is now a manifest entry (matched class)
 *
 * Allocates a 0x1c-byte node with the allocator entry point and runs the
 * two initialisers ISS_CITY_SYS_InitState and ISS_CITY_SYS_InitUnits over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_Create.c \
 *       --func ISS_CITY_SYS_Create --addr 0x0202AAF4 --thumb --cc 1.1p1
 */
struct IssCitySys *ISS_CITY_SYS_Create(struct PlayerWork *player, u32 heapId)
{
    struct IssCitySys *sys = GFL_HEAP_Alloc(heapId, sizeof(struct IssCitySys), 0,
                                           ISS_CITY_SYS_sSourceFileName, 0x92);

    ISS_CITY_SYS_InitState(sys, heapId, player);
    ISS_CITY_SYS_InitUnits(sys, heapId);
    return sys;
}

void ISS_CITY_SYS_Delete(struct IssCitySys *sys)
{
    ISS_CITY_SYS_ReleaseUnits(sys);
    GFL_HEAP_Free(sys);
}

/*
 * closed:   blocker ISS_CITY_SYS_InitUnits.c is now a manifest entry (matched class)
 *
 * When ISS_CITY_SYS_IsEnabled reports non-zero, runs ISS_CITY_SYS_UpdateByMode.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_Update.c \
 *       --func ISS_CITY_SYS_Update --addr 0x0202AB38 --thumb --cc 1.1p1
 */
void ISS_CITY_SYS_Update(struct IssCitySys *sys)
{
    if (ISS_CITY_SYS_IsEnabled(sys) != 0) {
        ISS_CITY_SYS_UpdateByMode(sys);
    }
}

void ISS_CITY_SYS_Start(struct IssCitySys *sys)
{
    ISS_CITY_SYS_Enable(sys);
}

void ISS_CITY_SYS_Stop(struct IssCitySys *sys)
{
    ISS_CITY_SYS_Disable(sys);
}

/*
 * iss_city_sys.c: an unlabelled forwarding leaf, a pool-word tail call to
 * ISS_CITY_SYS_HandleZoneChange with the caller's arguments passed through untouched.
 */
void ISS_CITY_SYS_NotifyZoneChange(struct IssCitySys *sys, u32 zoneId)
{
    ISS_CITY_SYS_HandleZoneChange(sys, zoneId);
}

/* The second argument is never read; the compiler reuses its register as the zero source. */
void ISS_CITY_SYS_InitState(struct IssCitySys *sys, u32 heapIdUnused, struct PlayerWork *player)
{
    sys->enabled = 0;
    sys->mode = 0;
    sys->volume = 0;
    sys->fadeLevel = 0;
    sys->units = 0;
    sys->unitCount = 0;
    sys->player = player;
    sys->currentUnit = 0xff;
}

/*
 * closed:   blocker ISS_CITY_SYS_InitUnits.c is now a manifest entry (matched class)
 *
 * A bare tail-call thunk to ISS_CITY_SYS_LoadUnits.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_InitUnits.c \
 *       --func ISS_CITY_SYS_InitUnits --addr 0x0202AB7C --thumb --cc 1.1p1
 */
void ISS_CITY_SYS_InitUnits(struct IssCitySys *sys, u32 heapId)
{
    ISS_CITY_SYS_LoadUnits(sys, heapId);
}

void ISS_CITY_SYS_ReleaseUnits(struct IssCitySys *sys)
{
    ISS_CITY_SYS_FreeUnits(sys);
}

/*
 * Graduated from src/pending/; promoted once its blocker became a manifest entry.
 *
 * Previously blocked at MATCH on `label`: ISS_CITY_UNIT_Create has exactly one branch reference
 * image-wide, this function's own call, so no witness exists outside the
 * compared range and no cut helps.  It closes when ISS_CITY_UNIT_Create (pkt_0202AEEC)
 * acquires a manifest entry or a second caller appears.
 *
 * closed:   blocker 0202AEEC is now a manifest entry (matched class)
 */
void ISS_CITY_SYS_LoadUnits(struct IssCitySys *sys, u32 heapId)
{
    s32 memberCount = ARC_TOOL_GetArchiveFileCount(0x84);
    s32 i;
    sys->unitCount = memberCount;
    sys->units = GFL_HEAP_Alloc(heapId, memberCount << 2, 0, ISS_CITY_SYS_sSourceFileName, 0x14d);
    for (i = 0; i < memberCount; i++) {
        sys->units[i] = ISS_CITY_UNIT_Create(heapId, i);
    }
}

void ISS_CITY_SYS_FreeUnits(struct IssCitySys *sys)
{
    int i;
    int count = sys->unitCount;
    for (i = 0; i < count; i++) {
        ISS_CITY_UNIT_Delete(sys->units[i]);
    }
    GFL_HEAP_Free(sys->units);
    sys->units = 0;
}

u32 ISS_CITY_SYS_GetMode(struct IssCitySys *sys)
{
    return sys->mode;
}

void ISS_CITY_SYS_SetMode(struct IssCitySys *sys, u32 mode)
{
    sys->mode = mode;
}

void ISS_CITY_SYS_Enable(struct IssCitySys *sys)
{
    if (ISS_CITY_SYS_IsEnabled(sys) != 0)
        return;
    sys->enabled = 1;
    ISS_CITY_SYS_SetVolume(sys, 0);
    ISS_CITY_SYS_ApplyVolume(sys);
    ISS_CITY_SYS_SelectUnitForZone(sys, ISS_CITY_SYS_GetPlayerZoneId(sys));
    if (ISS_CITY_SYS_HasCurrentUnit(sys) == 1)
        ISS_CITY_SYS_SetMode(sys, ISS_CITY_MODE_FADE_IN);
    else
        ISS_CITY_SYS_SetMode(sys, ISS_CITY_MODE_STEADY);
}

int ISS_CITY_SYS_Disable(struct IssCitySys *sys)
{
    int wasEnabled = ISS_CITY_SYS_IsEnabled(sys);
    if (wasEnabled != 0) {
        sys->enabled = 0;
        return 0;
    }
    return wasEnabled;
}

void ISS_CITY_SYS_HandleZoneChange(struct IssCitySys *sys, u32 zoneId)
{
    if (ISS_CITY_SYS_IsEnabled(sys) == 0) {
        return;
    }
    if (ISS_CITY_SYS_HasCurrentUnit(sys) == 1) {
        if (ISS_CITY_SYS_HasUnitForZone(sys, zoneId) == 1) {
            ISS_CITY_SYS_Disable(sys);
            return;
        }
    }
    ISS_CITY_SYS_SelectUnitForZone(sys, zoneId);
    if (ISS_CITY_SYS_HasCurrentUnit(sys) == 1) {
        ISS_CITY_SYS_SetFadeLevel(sys, 0);
        ISS_CITY_SYS_SetMode(sys, ISS_CITY_MODE_FADE_IN);
        return;
    }
    ISS_CITY_SYS_SetMode(sys, ISS_CITY_MODE_FADE_OUT);
}

u32 ISS_CITY_SYS_GetPlayerZoneId(struct IssCitySys *sys)
{
    return GAME_DATA_GetPlayerZoneId(sys->player);
}

u32 ISS_CITY_SYS_IsEnabled(struct IssCitySys *sys)
{
    return sys->enabled;
}

/* One switch on the call result puts it straight into r0 for all three compares. */
/*
 * Dispatches on the state word returned by ISS_CITY_SYS_GetMode over a three-way
 * state machine.  One `switch` on the call result is what puts the result
 * straight into r0 for all three `cmp`sys: a named local would have stored it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_UpdateByMode.c \
 *       --func ISS_CITY_SYS_UpdateByMode --addr 0x0202ACCC --thumb --cc 1.1p1
 */
void ISS_CITY_SYS_UpdateByMode(struct IssCitySys *sys)
{
    switch (ISS_CITY_SYS_GetMode(sys)) {
    case ISS_CITY_MODE_STEADY:
        ISS_CITY_SYS_UpdateSteady(sys);
        break;
    case ISS_CITY_MODE_FADE_IN:
        ISS_CITY_SYS_UpdateFadeIn(sys);
        break;
    case ISS_CITY_MODE_FADE_OUT:
        ISS_CITY_SYS_UpdateFadeOut(sys);
        break;
    }
}

void ISS_CITY_SYS_UpdateSteady(struct IssCitySys *sys)
{
    if (ISS_CITY_SYS_RefreshVolume(sys) != 0) {
        ISS_CITY_SYS_ApplyVolume(sys);
    }
}

void ISS_CITY_SYS_UpdateFadeIn(struct IssCitySys *sys)
{
    int levelChanged = ISS_CITY_SYS_StepFadeIn(sys);
    int volumeChanged = ISS_CITY_SYS_RefreshVolume(sys);
    if (levelChanged != 0 || volumeChanged != 0) {
        ISS_CITY_SYS_ApplyVolume(sys);
    }
    if ((int)ISS_CITY_SYS_GetFadeLevel(sys) >= ISS_CITY_LEVEL_MAX) {
        ISS_CITY_SYS_SetMode(sys, ISS_CITY_MODE_STEADY);
    }
}

void ISS_CITY_SYS_UpdateFadeOut(struct IssCitySys *sys)
{
    int levelChanged = ISS_CITY_SYS_StepFadeOut(sys);
    int volumeChanged = ISS_CITY_SYS_RefreshVolume(sys);
    if (levelChanged != 0 || volumeChanged != 0) {
        ISS_CITY_SYS_ApplyVolume(sys);
    }
    if ((int)ISS_CITY_SYS_GetFadeLevel(sys) <= 0) {
        ISS_CITY_SYS_SetMode(sys, ISS_CITY_MODE_STEADY);
    }
}

struct IssCityUnit *ISS_CITY_SYS_GetCurrentUnit(struct IssCitySys *sys)
{
    return sys->units[ISS_CITY_SYS_GetCurrentUnitIndex(sys)];
}

u32 ISS_CITY_SYS_GetCurrentUnitIndex(struct IssCitySys *sys)
{
    return sys->currentUnit;
}

int ISS_CITY_SYS_HasCurrentUnit(struct IssCitySys *sys)
{
    if (ISS_CITY_SYS_GetCurrentUnitIndex(sys) != ISS_CITY_UNIT_NONE) {
        return 1;
    }
    return 0;
}

int ISS_CITY_SYS_HasUnitForZone(struct IssCitySys *sys, u32 zoneId)
{
    if (ISS_CITY_SYS_FindUnitIndex(sys, zoneId) != ISS_CITY_UNIT_NONE) {
        return 1;
    }
    return 0;
}

int ISS_CITY_SYS_SelectUnitForZone(struct IssCitySys *sys, u32 zoneId)
{
    u32 oldUnit = ISS_CITY_SYS_GetCurrentUnitIndex(sys);
    u8 newUnit = ISS_CITY_SYS_FindUnitIndex(sys, zoneId);
    if (oldUnit == newUnit) {
        return 0;
    }
    sys->currentUnit = newUnit;
    return 1;
}

u8 ISS_CITY_SYS_FindUnitIndex(struct IssCitySys *sys, u32 zoneId)
{
    int i;
    u8 count = sys->unitCount;
    for (i = 0; i < count; i++) {
        if (zoneId == ISS_CITY_UNIT_GetZoneId(sys->units[i])) {
            return (u8)i;
        }
    }
    return ISS_CITY_UNIT_NONE;
}

u32 ISS_CITY_SYS_GetFadeLevel(struct IssCitySys *sys)
{
    return sys->fadeLevel;
}

int ISS_CITY_SYS_StepFadeIn(struct IssCitySys *sys)
{
    s32 newLevel = (s32)ISS_CITY_SYS_GetFadeLevel(sys) + ISS_CITY_FADE_STEP;
    if (newLevel >= ISS_CITY_LEVEL_MAX) {
        newLevel = ISS_CITY_LEVEL_MAX;
    }
    if (newLevel == (s32)ISS_CITY_SYS_GetFadeLevel(sys)) {
        return 0;
    }
    ISS_CITY_SYS_SetFadeLevel(sys, newLevel);
    return 1;
}

int ISS_CITY_SYS_StepFadeOut(struct IssCitySys *sys)
{
    s32 newLevel = (s32)ISS_CITY_SYS_GetFadeLevel(sys) - ISS_CITY_FADE_STEP;
    if (newLevel <= 0) {
        newLevel = 0;
    }
    if (newLevel == (s32)ISS_CITY_SYS_GetFadeLevel(sys)) {
        return 0;
    }
    ISS_CITY_SYS_SetFadeLevel(sys, newLevel);
    return 1;
}

void ISS_CITY_SYS_SetFadeLevel(struct IssCitySys *sys, u32 fadeLevel)
{
    sys->fadeLevel = fadeLevel;
}

/*
 * closed:   blocker FILE_UTIL_GetBankCount.c is now a manifest entry (matched class)
 *
 * Plain field read: the word at 0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_CITY_SYS_GetVolume.c \
 *       --func ISS_CITY_SYS_GetVolume --addr 0x0202AE64 --thumb --cc 1.1p1
 */
u32 ISS_CITY_SYS_GetVolume(struct IssCitySys *sys)
{
    return sys->volume;
}

/*
 * Blocked: 0202AE9C (thumb, from name) has no witness outside 0202AE68..0202AE9A. Every concrete byte reproduces.
 */
int ISS_CITY_SYS_RefreshVolume(struct IssCitySys *sys)
{
    int newVolume;
    if (ISS_CITY_SYS_HasCurrentUnit(sys) == 0) {
        return 0;
    }
    newVolume = ISS_CITY_SYS_CalcUnitVolume(sys);
    if (newVolume == ISS_CITY_SYS_GetVolume(sys)) {
        return 0;
    }
    ISS_CITY_SYS_SetVolume(sys, newVolume);
    return 1;
}

/*
 * Blocked: call target ISS_CITY_UNIT_CalcVolume is unlabelled and unmatched (it lives in
 * another lane's packet, pkt_0202AF34). Every concrete byte reproduces.
 */
int ISS_CITY_SYS_CalcUnitVolume(struct IssCitySys *sys)
{
    return ISS_CITY_UNIT_CalcVolume(ISS_CITY_SYS_GetCurrentUnit(sys), (const s32 *)GAME_DATA_GetPlayerPosition(sys->player));
}

void ISS_CITY_SYS_SetVolume(struct IssCitySys *sys, u32 volume)
{
    sys->volume = volume;
}

void ISS_CITY_SYS_ApplyVolume(struct IssCitySys *sys)
{
    GFL_USE_SetBgmTrackVolume(3 << 8, ISS_CITY_SYS_CalcOutputVolume(sys));
}

int ISS_CITY_SYS_CalcOutputVolume(struct IssCitySys *sys)
{
    return (s32)ISS_CITY_SYS_GetVolume(sys) * (s32)ISS_CITY_SYS_GetFadeLevel(sys) / ISS_CITY_LEVEL_MAX;
}
