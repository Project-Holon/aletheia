/*
 * file:     iss_city_sys.c
 * unit:     yes
 * function: func_0202A994, func_0202A9F4, ISS_CITY_SYS_Create, ISS_CITY_SYS_Delete, ISS_CITY_SYS_Update, ISS_CITY_SYS_Start, ISS_CITY_SYS_Stop, ISS_CITY_SYS_NotifyZoneChange, ISS_CITY_SYS_InitState, ISS_CITY_SYS_InitUnits, ISS_CITY_SYS_ReleaseUnits, ISS_CITY_SYS_LoadUnits, ISS_CITY_SYS_FreeUnits, ISS_CITY_SYS_GetMode, ISS_CITY_SYS_SetMode, ISS_CITY_SYS_Enable, ISS_CITY_SYS_Disable, ISS_CITY_SYS_HandleZoneChange, ISS_CITY_SYS_GetPlayerZoneId, ISS_CITY_SYS_IsEnabled, ISS_CITY_SYS_UpdateByMode, ISS_CITY_SYS_UpdateSteady, ISS_CITY_SYS_UpdateFadeIn, ISS_CITY_SYS_UpdateFadeOut, ISS_CITY_SYS_GetCurrentUnit, ISS_CITY_SYS_GetCurrentUnitIndex, ISS_CITY_SYS_HasCurrentUnit, ISS_CITY_SYS_HasUnitForZone, ISS_CITY_SYS_SelectUnitForZone, ISS_CITY_SYS_FindUnitIndex, ISS_CITY_SYS_GetFadeLevel, ISS_CITY_SYS_StepFadeIn, ISS_CITY_SYS_StepFadeOut, ISS_CITY_SYS_SetFadeLevel, ISS_CITY_SYS_GetVolume, ISS_CITY_SYS_RefreshVolume, ISS_CITY_SYS_CalcUnitVolume, ISS_CITY_SYS_SetVolume, ISS_CITY_SYS_ApplyVolume, ISS_CITY_SYS_CalcOutputVolume, ISS_CITY_UNIT_Create, ISS_CITY_UNIT_Delete, ISS_CITY_UNIT_GetZoneId, ISS_CITY_UNIT_CalcVolume, ISS_CITY_UNIT_Copy, ISS_CITY_UNIT_CalcVolumeFromAxes, ISS_CITY_UNIT_CalcVolumeX, ISS_CITY_UNIT_CalcVolumeY, ISS_CITY_UNIT_CalcVolumeZ, ISS_CITY_UNIT_FindStepX, ISS_CITY_UNIT_FindStepY, ISS_CITY_UNIT_FindStepZ, ISS_CITY_UNIT_GetCenterX, ISS_CITY_UNIT_GetCenterY, ISS_CITY_UNIT_GetCenterZ, ISS_CITY_UNIT_Interpolate
 * address:  0x0202A994
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetNature  0x020185B0  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   func_02019C90  0x02019C90  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   ISS_CITY_SYS_sSourceFileName     0x020A76E8  data
 *   ISS_CITY_UNIT_sSourceFileName     0x020A76F8  data
 *   func_020307B0  0x020307B0  arm
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AC04   0x0209AC04  arm
 *   _d2s            0x0209C508  arm
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   ARC_TOOL_LoadMemberRange  0x02048F88  arm
 */
struct Personal;
struct PlayerWork;
struct PlayerPosition;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

/* ISS (interactive sound system) city ambience: the fade state machine modes. */
#define ISS_CITY_MODE_STEADY   0
#define ISS_CITY_MODE_FADE_IN  1
#define ISS_CITY_MODE_FADE_OUT 2
#define ISS_CITY_UNIT_NONE     0xff   /* currentUnit when no unit is selected */
#define ISS_CITY_LEVEL_MAX     0x7f   /* fade level and volume range 0..127 */
#define ISS_CITY_FADE_STEP     2

/*
 * One 0x28-byte city sound unit, filled from archive 0x84 (one member per
 * unit).  The unit covers one zone.  It stores a center on a 3D grid and, per
 * axis, six distance thresholds (radius >> 4) with a volume step for each:
 * the closer the player is, the higher the step.
 */
struct IssCityUnit {
    u16 zoneId;
    u16 pad02;
    u32 centerGridX;        /* center = 8.0 * (centerGridX << 4) */
    u32 centerGridY;
    u32 centerGridZ;
    u8 volumeSteps[6];      /* volume (0..127) of each distance step */
    u8 radiusX[6];          /* distance thresholds, radius >> 4 */
    u8 radiusY[6];
    u8 radiusZ[6];
};

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

extern void *func_0201ADE4(u32 species, int form, u32 heapId);
extern u32 func_0201AE1C(const struct Personal *personal, u32 field);
extern void func_0201AE14(void *personal);
extern u32  POKE_TOOL_GetPartyValue(void *mon, u32 field, u32 index);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 field, u32 value);
extern void POKE_TOOL_SetNature(void *mon, u32 nature);
extern void POKE_TOOL_SetAbility(void *mon, u32 species, u32 form);
extern u32  func_02019C90(u32 species, u16 form, u32 personalField);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *sourceFile, u16 sourceLine);
extern void *ARC_TOOL_LoadMemberRange(u32 archiveId, u32 memberIndex, u32 heapId, u32 mode, u32 size);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 archiveId);
extern u32 func_020307B0(void *block);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);
extern struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);
extern void GFL_USE_SetBgmTrackVolume(u32 soundTarget, u32 volume);
extern double _s32_to_double(s32 v);
extern double func_0209AC04(double lhs, double rhs);
extern s32 _d2s(double d);
void func_0202A994(u32 species, u32 form, int adjustFlags, u32 *personalityLow, u16 heapId);
void func_0202A9F4(u32 trainerId, void *mon, u32 form, u32 abilityFlags);
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
void ISS_CITY_UNIT_Copy(const struct IssCityUnit *src, struct IssCityUnit *dst);
u8 ISS_CITY_UNIT_CalcVolumeFromAxes(const struct IssCityUnit *unit, const s32 *playerPos);
u8 ISS_CITY_UNIT_CalcVolumeX(const struct IssCityUnit *unit, const s32 *playerPos);
u8 ISS_CITY_UNIT_CalcVolumeY(const struct IssCityUnit *unit, const s32 *playerPos);
u8 ISS_CITY_UNIT_CalcVolumeZ(const struct IssCityUnit *unit, const s32 *playerPos);
u32 ISS_CITY_UNIT_FindStepX(const struct IssCityUnit *unit, const s32 *playerPos);
u32 ISS_CITY_UNIT_FindStepY(const struct IssCityUnit *unit, const s32 *playerPos);
u32 ISS_CITY_UNIT_FindStepZ(const struct IssCityUnit *unit, const s32 *playerPos);
s32 ISS_CITY_UNIT_GetCenterX(const struct IssCityUnit *unit);
s32 ISS_CITY_UNIT_GetCenterY(const struct IssCityUnit *unit);
s32 ISS_CITY_UNIT_GetCenterZ(const struct IssCityUnit *unit);
s32 ISS_CITY_UNIT_Interpolate(s32 distA, s32 volumeA, s32 distB, s32 volumeB, s32 dist);
extern const char ISS_CITY_SYS_sSourceFileName[];
extern const char ISS_CITY_UNIT_sSourceFileName[];





void func_0202A994(u32 species, u32 form, int adjustFlags, u32 *personalityLow, u16 heapId)
{
    u32 genderAdjust = adjustFlags & 0xf;
    u32 abilityAdjust = (adjustFlags & 0xf0) >> 4;
    u32 personal;

    if (adjustFlags == 0)
        return;

    personal = (u32)func_0201ADE4((u16)species, (u16)form, heapId);

    if (genderAdjust != 0) {
        *personalityLow = func_0201AE1C((const struct Personal *)personal, 0x14);
        if (genderAdjust == 1)
            *personalityLow = *personalityLow + 2;
        else
            *personalityLow = *personalityLow - 2;
    }

    if (abilityAdjust == 1)
        *personalityLow &= ~(u32)1;
    else if (abilityAdjust == 2)
        *personalityLow |= (u32)1;

    func_0201AE14((void *)personal);
}





/*
 * tr_tool.c: finish one trainer party member.  Field 9 (friendship) is
 * 0xFF unless one of the four moves (fields 0x36..0x39) is 0xDA, then 0;
 * field 0x6F takes form; the 0xF0 nibble of abilityFlags selects the ability
 * path (0x30: POKE_TOOL_SetAbility, otherwise func_02019C90 with field 0x1A or
 * 0x1B); two trainer/species pairs force a fixed nature, the rest take
 * (personality >> 8) % 25.
 *
 * What closed the old 248-byte near miss (docs/notes/func_0202A9F4.c.txt):
 * the register the note read as a copy of the loop counter (`adds r6, r4,
 * #0` before the loop) is the constant 0, kept in r6 for the call's third
 * argument and for `found = 0`.  That zero occupies the fourth callee-saved
 * register across the loop, which is what spills species to sp+0xC.  The
 * tail is the remainder of _s32_div_f (r1), so `% 25`, not `/ 25`.
 */
void func_0202A9F4(u32 trainerId, void *mon, u32 form, u32 abilityFlags)
{
    s32 moveSlot;
    u32 friendship = 0xff;
    u32 species;
    u32 abilityField;
    u32 abilityField2;
    u32 abilityMode;
    u32 trainerIdBase;

    species = (u16)POKE_TOOL_GetPartyValue(mon, 5, 0);
    for (moveSlot = 0; moveSlot < 4; moveSlot++) {
        if (POKE_TOOL_GetPartyValue(mon, 0x36 + moveSlot, 0) == 0xda) {
            friendship = 0;
        }
    }
    POKE_TOOL_SetPartyValue(mon, 9, friendship);
    POKE_TOOL_SetPartyValue(mon, 0x6f, form);

    abilityMode = abilityFlags & 0xf0;
    if (abilityMode == 0x30) {
        POKE_TOOL_SetAbility(mon, species, form);
    } else if (abilityMode != 0) {
        abilityField = 0x1a;
        abilityField2 = 0x1b;
        if (func_02019C90(species, (u16)form, 0x1b) != 0 && abilityMode == 0x20) {
            abilityField = abilityField2;
        }
        POKE_TOOL_SetPartyValue(mon, 0xa, func_02019C90(species, (u16)form, abilityField));
    }

    trainerIdBase = 0x24a;
    if (trainerId == trainerIdBase && species == trainerIdBase + 0x39) {
        POKE_TOOL_SetNature(mon, 0xd);
        return;
    }
    trainerIdBase = 0x24b;
    if (trainerId == trainerIdBase && species == trainerIdBase + 0x39) {
        POKE_TOOL_SetNature(mon, 0xa);
        return;
    }
    POKE_TOOL_SetNature(mon, (u8)(((s32)POKE_TOOL_GetPartyValue(mon, 0, 0) >> 8) % 0x19));
}





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
    struct IssCitySys *sys = func_02030734(heapId, sizeof(struct IssCitySys), 0,
                                           ISS_CITY_SYS_sSourceFileName, 0x92);

    ISS_CITY_SYS_InitState(sys, heapId, player);
    ISS_CITY_SYS_InitUnits(sys, heapId);
    return sys;
}




void ISS_CITY_SYS_Delete(struct IssCitySys *sys)
{
    ISS_CITY_SYS_ReleaseUnits(sys);
    func_020307B0(sys);
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
    sys->units = func_02030734(heapId, memberCount << 2, 0, ISS_CITY_SYS_sSourceFileName, 0x14d);
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
    func_020307B0(sys->units);
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
 * closed:   blocker func_02020F0C.c is now a manifest entry (matched class)
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


/*
 * Allocates a 0x28-byte node with func_02030734, wraps it with ARC_TOOL_LoadMemberRange,
 * runs ISS_CITY_UNIT_Copy over the pair and releases the wrapper.  The pair is
 * passed as (wrapper, node): r0 is left holding the wrapper from the second
 * allocation when ISS_CITY_UNIT_Copy is reached, with the node moved into r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_Create.c \
 *       --func ISS_CITY_UNIT_Create --addr 0x0202AEEC --thumb --cc 1.1p1
 */
struct IssCityUnit *ISS_CITY_UNIT_Create(u32 heapId, u32 memberIndex)
{
    struct IssCityUnit *unit = func_02030734(heapId, sizeof(struct IssCityUnit), 0, ISS_CITY_UNIT_sSourceFileName, 0x6c);
    struct IssCityUnit *rawMember = ARC_TOOL_LoadMemberRange(0x84, memberIndex, heapId, 0, sizeof(struct IssCityUnit));
    ISS_CITY_UNIT_Copy(rawMember, unit);
    func_020307B0(rawMember);
    return unit;
}


void ISS_CITY_UNIT_Delete(struct IssCityUnit *unit)
{
    func_020307B0(unit);
}


u32 ISS_CITY_UNIT_GetZoneId(struct IssCityUnit *unit)
{
    return unit->zoneId;
}


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * A bare tail-call thunk to ISS_CITY_UNIT_CalcVolumeFromAxes (ldr r3, pool; bx r3; .word
 * 0x0202AF75).  Blocked at MATCH on `literal`: the pointer word 0x0202AF75
 * appears in exactly one literal pool image-wide, this thunk's own at
 * 0x0202AF38, so the ABS32 site has no outside witness.  There is no branch
 * to 0x0202AF74 anywhere else in the image either, so the `label` class is
 * empty too.  Closes when ISS_CITY_UNIT_CalcVolumeFromAxes acquires a manifest entry that is
 * not this file's own (a second reader of the thunk, or a matched
 * ISS_CITY_UNIT_CalcVolumeFromAxes elsewhere).
 *
 * THE BODY BELOW IS NEW (third unit pass).  The file carried the note alone
 * because the shape had been reported as a linker veneer with no C spelling:
 * it is not.  A plain tail call reproduces all 8 bytes - 4 of code plus the
 * pool word - byte for byte, and the IRQ-window `ldr r3, [pc, #0]` + `bx r3`
 * is exactly what this front end emits for it.  The one relocation therefore
 * stays a wildcard (its own pool word is inside the compared range), which is
 * the MATCH cap and the only thing that keeps this entry out of the manifest.
 *
 * It is the last link of this lane's 0x0202AE68 chain: src/pending/
 * ISS_CITY_SYS_CalcUnitVolume.c is capped on this address's `label`, which is empty while
 * this file cannot be an EXACT entry.  The whole chain needs ISS_CITY_UNIT_CalcVolumeFromAxes
 * (50 bytes, in another packet) filed.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_CITY_UNIT_CalcVolume.c \
 *       --func ISS_CITY_UNIT_CalcVolume --addr 0x0202AF34 --cc 1.1p1 --thumb
 */
u8 ISS_CITY_UNIT_CalcVolume(const struct IssCityUnit *unit, const s32 *playerPos)
{
    return ISS_CITY_UNIT_CalcVolumeFromAxes(unit, playerPos);
}


void ISS_CITY_UNIT_Copy(const struct IssCityUnit *src, struct IssCityUnit *dst)
{
    int i;
    dst->zoneId = src->zoneId;
    dst->centerGridX = src->centerGridX;
    dst->centerGridY = src->centerGridY;
    dst->centerGridZ = src->centerGridZ;
    for (i = 0; i < 6; i++) {
        dst->volumeSteps[i] = src->volumeSteps[i];
        dst->radiusX[i] = src->radiusX[i];
        dst->radiusY[i] = src->radiusY[i];
        dst->radiusZ[i] = src->radiusZ[i];
    }
}


/* Product of the three axis levels (0..127 each), renormalised by 127 * 127. */
/*
 * The head of the three-axis attenuation family: multiplies the X, Y and
 * Z unit responses (ISS_CITY_UNIT_CalcVolumeX / ISS_CITY_UNIT_CalcVolumeY / ISS_CITY_UNIT_CalcVolumeZ, each a
 * 0..127 fadeLevel) and renormalises by 127*127 == 0x3f01, so the product of
 * three 7-bit levels comes back as one 7-bit fadeLevel.  The result is
 * truncated to u8 by the caller-visible return type.
 *
 * Blocked at MATCH: every concrete byte is right.  The three THM_CALL
 * sites at +0x06, +0x10 and +0x1a have no witness outside
 * 0x0202AF74..0x0202AFAC -- this is the only caller of any of the three
 * axis routines in the whole image, so `label` refuses them and `matched`
 * has nothing to point at while ISS_CITY_UNIT_CalcVolumeX / ISS_CITY_UNIT_CalcVolumeY /
 * ISS_CITY_UNIT_CalcVolumeZ stay unfiled (each is a 6-to-13 byte scheduling near
 * miss, see docs/notes/ISS_CITY_UNIT_CalcVolumeX.c.txt and its two twins).
 * --suggest-split cannot help: the compared range is one function.
 * Blocking evidence class: none available (needs an EXACT manifest entry
 * at 0x0202AFAC / 0x0202AFFC / 0x0202B04C, or a second caller).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeFromAxes.c \
 *       --func ISS_CITY_UNIT_CalcVolumeFromAxes --addr 0x0202AF74 --cc 1.1p1 --thumb
 */
u8 ISS_CITY_UNIT_CalcVolumeFromAxes(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 x;
    s32 y;
    s32 z;
    x = ISS_CITY_UNIT_CalcVolumeX(unit, playerPos);
    y = ISS_CITY_UNIT_CalcVolumeY(unit, playerPos);
    z = ISS_CITY_UNIT_CalcVolumeZ(unit, playerPos);
    return (u8)(z * (x * y) / 0x3f01);
}


/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the first axis: playerPos[0], radius table at +0x16.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/ISS_CITY_UNIT_CalcVolumeX.c.txt: the
 * stacked fifth argument stored to [sp] before the step address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const struct IssCityUnit *unit`, `const s32 *playerPos` and
 * const-pointee callees.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeX.c  *       --func ISS_CITY_UNIT_CalcVolumeX --addr 0x0202AFAC --thumb --cc 1.1p1
 */
u8 ISS_CITY_UNIT_CalcVolumeX(const struct IssCityUnit *unit, const s32 *playerPos)
{
    u32 step;
    u32 prevStep;
    s32 gridPos;
    s32 dist;
    step = ISS_CITY_UNIT_FindStepX(unit, playerPos);
    if (step == 0)
        prevStep = 0;
    else
        prevStep = (u8)(step - 1);
    if (step == prevStep)
        return unit->volumeSteps[step];
    gridPos = playerPos[0] >> 12;
    dist = gridPos - ISS_CITY_UNIT_GetCenterX(unit);
    if (dist < 0)
        dist = -dist;
    return (u8)ISS_CITY_UNIT_Interpolate(unit->radiusX[step] << 4, unit->volumeSteps[step],
                             unit->radiusX[prevStep] << 4, unit->volumeSteps[prevStep], dist);
}


/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the second axis: playerPos[1], radius table at +0x1c.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/ISS_CITY_UNIT_CalcVolumeY.c.txt: the
 * stacked fifth argument stored to [sp] before the step address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const struct IssCityUnit *unit`, `const s32 *playerPos` and
 * const-pointee callees.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeY.c  *       --func ISS_CITY_UNIT_CalcVolumeY --addr 0x0202AFFC --thumb --cc 1.1p1
 */
u8 ISS_CITY_UNIT_CalcVolumeY(const struct IssCityUnit *unit, const s32 *playerPos)
{
    u32 step;
    u32 prevStep;
    s32 gridPos;
    s32 dist;
    step = ISS_CITY_UNIT_FindStepY(unit, playerPos);
    if (step == 0)
        prevStep = 0;
    else
        prevStep = (u8)(step - 1);
    if (step == prevStep)
        return unit->volumeSteps[step];
    gridPos = playerPos[1] >> 12;
    dist = gridPos - ISS_CITY_UNIT_GetCenterY(unit);
    if (dist < 0)
        dist = -dist;
    return (u8)ISS_CITY_UNIT_Interpolate(unit->radiusY[step] << 4, unit->volumeSteps[step],
                             unit->radiusY[prevStep] << 4, unit->volumeSteps[prevStep], dist);
}


/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the third axis: playerPos[2], radius table at +0x22
 * (past the ldrb reach, hence one `adds` per load).
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/ISS_CITY_UNIT_CalcVolumeZ.c.txt: the
 * stacked fifth argument stored to [sp] before the step address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const struct IssCityUnit *unit`, `const s32 *playerPos` and
 * const-pointee callees.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeZ.c  *       --func ISS_CITY_UNIT_CalcVolumeZ --addr 0x0202B04C --thumb --cc 1.1p1
 */
u8 ISS_CITY_UNIT_CalcVolumeZ(const struct IssCityUnit *unit, const s32 *playerPos)
{
    u32 step;
    u32 prevStep;
    s32 gridPos;
    s32 dist;
    step = ISS_CITY_UNIT_FindStepZ(unit, playerPos);
    if (step == 0)
        prevStep = 0;
    else
        prevStep = (u8)(step - 1);
    if (step == prevStep)
        return unit->volumeSteps[step];
    gridPos = playerPos[2] >> 12;
    dist = gridPos - ISS_CITY_UNIT_GetCenterZ(unit);
    if (dist < 0)
        dist = -dist;
    return (u8)ISS_CITY_UNIT_Interpolate(unit->radiusZ[step] << 4, unit->volumeSteps[step],
                             unit->radiusZ[prevStep] << 4, unit->volumeSteps[prevStep], dist);
}


u32 ISS_CITY_UNIT_FindStepX(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 step;
    s32 gridPos = playerPos[0] >> 12;
    s32 dist = gridPos - ISS_CITY_UNIT_GetCenterX(unit);
    if (dist < 0) dist = -dist;
    for (step = 0; step < 6; step++) {
        if ((unit->radiusX[step] << 4) <= dist) return (u8)step;
    }
    return 0;
}


u32 ISS_CITY_UNIT_FindStepY(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 step;
    s32 gridPos = playerPos[1] >> 12;
    s32 dist = gridPos - ISS_CITY_UNIT_GetCenterY(unit);
    if (dist < 0) dist = -dist;
    for (step = 0; step < 6; step++) {
        if ((unit->radiusY[step] << 4) <= dist) return (u8)step;
    }
    return 0;
}


u32 ISS_CITY_UNIT_FindStepZ(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 step;
    s32 gridPos = playerPos[2] >> 12;
    s32 dist = gridPos - ISS_CITY_UNIT_GetCenterZ(unit);
    if (dist < 0) dist = -dist;
    for (step = 0; step < 6; step++) {
        if ((unit->radiusZ[step] << 4) <= dist) return (u8)step;
    }
    return 0;
}


s32 ISS_CITY_UNIT_GetCenterX(const struct IssCityUnit *unit)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(unit->centerGridX << 4))));
}


s32 ISS_CITY_UNIT_GetCenterY(const struct IssCityUnit *unit)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(unit->centerGridY << 4))));
}


s32 ISS_CITY_UNIT_GetCenterZ(const struct IssCityUnit *unit)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(unit->centerGridZ << 4))));
}


s32 ISS_CITY_UNIT_Interpolate(s32 distA, s32 volumeA, s32 distB, s32 volumeB, s32 dist)
{
    return volumeA + (volumeB - volumeA) * (dist - distA) / (distB - distA);
}
