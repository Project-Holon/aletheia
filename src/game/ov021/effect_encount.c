/*
 * file:     effect_encount.c
 * unit:     yes
 * function: EFFECT_ENCOUNT_Create, EFFECT_ENCOUNT_Delete, EFFECT_ENCOUNT_Init, EFFECT_ENCOUNT_Exit, EFFECT_ENCOUNT_LoadSetting, EFFECT_ENCOUNT_OnPlayerStep, EFFECT_ENCOUNT_Reset, EFFECT_ENCOUNT_UpdateOccupiedSpot, EFFECT_ENCOUNT_IsSpotAt, EFFECT_ENCOUNT_TriggerSpot, EFFECT_ENCOUNT_GetSpotDistance, EFFECT_ENCOUNT_ConsumeSpot, EFFECT_ENCOUNT_SetEffectPaused, EFFECT_ENCOUNT_SetEffectFlag, EFFECT_ENCOUNT_GetItemId, EFFECT_ENCOUNT_MarkSpotForRestore, EFFECT_ENCOUNT_RestoreSpot, EFFECT_ENCOUNT_CountStep, EFFECT_ENCOUNT_ResetStepCount, EFFECT_ENCOUNT_MakeSearchArea, EFFECT_ENCOUNT_CollectCandidates, EFFECT_ENCOUNT_PickSpot, EFFECT_ENCOUNT_IsTileOccupied, EFFECT_ENCOUNT_ClearSpotIfOccupied, EFFECT_ENCOUNT_ClearSpot, EFFECT_ENCOUNT_CreateEffectObj, EFFECT_ENCOUNT_DeleteEffectObj, EFFECT_ENCOUNT_PickItemKind4, EFFECT_ENCOUNT_PickItemKind7, EFFECT_ENCOUNT_StartItemEvent
 * address:  0x021AA77C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AA77C: __FILE__ effect_encount.c on 0x021AA77C (its work
 * allocation, first function); 0x021AA69C..0x021AA778 are called only by field_encount functions.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   sEffectEncountFileName  0x021DDFB4  data  a4
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   sEffectEncountSettings  0x021D8E70  data  a4
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   MAP_MATRIX_IsInRangeByPos  0x02159C48  thumb  ov010
 *   MAP_MATRIX_GetZoneIdByPos  0x02159BD4  thumb  ov010
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_GetBadge  0x0200C234  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   FIELD_PLAYER_IsGridHopping  0x021A3624  thumb  ov021
 *   FIELD_PLAYER_FinishGridHop  0x021A3644  thumb  ov021
 *   FLDEFF_ENCOUNT_SetPaused  0x021ADB4C  thumb
 *   FLDEFF_ENCOUNT_SetDrawHidden  0x021ADB5C  thumb
 *   sSearchAreaOffsets     0x021D8E76  data  a1
 *   FIELD_G3D_MAPPER_GetFocusSlot  0x0218D168  thumb  ov021
 *   FIELD_G3D_MAPPER_CheckSlotReady  0x0218DBD4  thumb  ov021
 *   _fflt  0x0209BDBC  arm
 *   _fadd  0x0209C95C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   FIELD_G3D_MAPPER_QuerySlotPlane  0x0218DBAC  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDEFF_ENCOUNT_Start  0x021ADAAC  thumb
 *   sRareItemIds     0x021D8E8A  data  a2
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb  ov021
 *   MAP_ATTR_GetEncounterEffectKind  0x021AB504  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "effect_encount_types.h"
#include "../ov010/field_g3d_map_types.h"

#include "../types.h"

struct Mmdl;
struct MmdlSys;
struct FieldPlayer;
struct FieldG3dMapper;
struct GameData;
struct GameSystem;
struct MiscSave;

/* Tile position of a model (three tile coordinates). */
typedef struct GridPos {
    s16 x;
    s16 y;
    s16 z;
} GridPos;

/* Steps needed and spawn chance of one effect kind (EncountData.effectKind). */
typedef struct EffectEncountSetting {
    u8 stepsNeeded;
    u8 spawnPercent;
} EffectEncountSetting;

/* Search window around the player, inside the 32x32 tile block the player stands in. */
typedef struct EffectEncountArea {
    s16 tileX;
    s16 tileZ;
    s16 blockOffsetX;
    s16 blockOffsetZ;
    s16 blockX;
    s16 blockZ;
    u16 originX;
    u16 originZ;
    s16 minX;
    s16 minZ;
    s16 maxX;
    s16 maxZ;
} EffectEncountArea;


/* Size of a model in tiles, in the object code parameter. */
typedef struct MmdlObjSize {
    u8 pad00[0x0B];
    u8 gridWidth;
    u8 gridDepth;
} MmdlObjSize;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_use.h"
#include "fieldmap.h"
extern EncountGimmickWork *GAME_DATA_GetFieldGimmick(const struct GameData *gameData);
#include "field_player.h"
extern short FLDMMDL_GetGridNowX(struct Mmdl *mmdl);
extern short FLDMMDL_GetGridNowZ(struct Mmdl *mmdl);
struct FieldEffectCont;
extern u32 GAME_DATA_GetFieldWork(const struct GameData *gameData);
struct VecFx32;
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct VecFx32 *out);
struct MapMatrix;
#include "../ov010/map_matrix.h"
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
#include "../arm9/beacon.h"
struct MmdlGridVec;
extern void FLDMMDL_GetGridNowPos(struct Mmdl *mmdl, struct MmdlGridVec *out);
#include "field_g3d_mapper.h"
extern int FLDMMDL_SysSearchUseMmdl(struct MmdlSys *sys, struct Mmdl **out, u32 *iter);
extern int FLDMMDL_CheckEndAcmd(struct Mmdl *mmdl);
extern MmdlObjSize *FLDMMDL_GetObjCodeParam(struct Mmdl *mmdl);
struct EncountSys;
struct FieldEffectObj;
#include "fldeff_encount.h"
struct GameEvent;
extern struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, s32 reserved);
#include "field_encount.h"
#include "map_attr.h"
#include "field_effect.h"

EffectEncount *EFFECT_ENCOUNT_Create(int heapId);
int EFFECT_ENCOUNT_Delete(EffectEncount *effectEncount);
void EFFECT_ENCOUNT_Init(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_Exit(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_LoadSetting(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_OnPlayerStep(FieldEncount *encount);
void EFFECT_ENCOUNT_Reset(FieldEncount *encount);
void EFFECT_ENCOUNT_UpdateOccupiedSpot(FieldEncount *encount);
int EFFECT_ENCOUNT_IsSpotAt(FieldEncount *encount, short *pos);
int EFFECT_ENCOUNT_TriggerSpot(FieldEncount *encount);
int EFFECT_ENCOUNT_GetSpotDistance(FieldEncount *encount, short *out);
void EFFECT_ENCOUNT_ConsumeSpot(FieldEncount *encount);
void EFFECT_ENCOUNT_SetEffectPaused(FieldEncount *encount, int paused);
void EFFECT_ENCOUNT_SetEffectFlag(FieldEncount *encount, int flag);
u16 EFFECT_ENCOUNT_GetItemId(FieldEncount *encount);
void EFFECT_ENCOUNT_MarkSpotForRestore(FieldEncount *encount);
void EFFECT_ENCOUNT_RestoreSpot(FieldEncount *encount, EffectEncount *effectEncount);
int EFFECT_ENCOUNT_CountStep(EncountGimmickWork *gimmick, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_ResetStepCount(EncountGimmickWork *gimmick);
void EFFECT_ENCOUNT_MakeSearchArea(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountArea *area);
void EFFECT_ENCOUNT_CollectCandidates(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_PickSpot(FieldEncount *encount, EffectEncount *effectEncount);
int EFFECT_ENCOUNT_IsTileOccupied(FieldEncount *encount, s16 gridX, s16 gridHeight, s16 gridZ, int ignorePlayer);
int EFFECT_ENCOUNT_ClearSpotIfOccupied(FieldEncount *encount);
void EFFECT_ENCOUNT_ClearSpot(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_CreateEffectObj(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountSpot *spot);
void EFFECT_ENCOUNT_DeleteEffectObj(EffectEncount *effectEncount);
unsigned short EFFECT_ENCOUNT_PickItemKind4(void);
u16 EFFECT_ENCOUNT_PickItemKind7(void);
int EFFECT_ENCOUNT_StartItemEvent(FieldEncount *encount, u16 itemId);

extern char sEffectEncountFileName[];
extern const EffectEncountSetting sEffectEncountSettings[];
extern const s8 sSearchAreaOffsets[][4];
extern unsigned short sRareItemIds[];

EffectEncount *EFFECT_ENCOUNT_Create(int heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(EffectEncount), 1, sEffectEncountFileName, 0x6e);
}

int EFFECT_ENCOUNT_Delete(EffectEncount *effectEncount)
{
    MI_CpuFill8(effectEncount, 0, sizeof(EffectEncount));
    return GFL_HEAP_Free(effectEncount);
}

void EFFECT_ENCOUNT_Init(FieldEncount *encount, EffectEncount *effectEncount)
{
    effectEncount->fieldEffectSys = (struct FieldEffectSys *)FIELDMAP_GetEffect(encount->fieldMap);
    EFFECT_ENCOUNT_LoadSetting(encount, effectEncount);
    EFFECT_ENCOUNT_RestoreSpot(encount, effectEncount);
}

void EFFECT_ENCOUNT_Exit(FieldEncount *encount, EffectEncount *effectEncount)
{
    EFFECT_ENCOUNT_MarkSpotForRestore(encount);
    EFFECT_ENCOUNT_DeleteEffectObj(effectEncount);
}

void EFFECT_ENCOUNT_LoadSetting(FieldEncount *encount, EffectEncount *effectEncount)
{
    unsigned int effectKind = encount->encountData->effectKind;
    if (effectKind > 2) {
        effectKind = 0;
    }
    effectEncount->stepsNeeded = sEffectEncountSettings[effectKind].stepsNeeded;
    effectEncount->spawnPercent = sEffectEncountSettings[effectKind].spawnPercent;
}

/* Called once per player step: counts the step and, when the roll succeeds, picks a new spot. */
void EFFECT_ENCOUNT_OnPlayerStep(FieldEncount *encount)
{
    EffectEncount *effectEncount = encount->effectEncount;
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);
    void *fieldWork;
    u16 playerZoneId;
    VecFx32 pos;
    int mapZoneId;

    if (encount == 0 || encount->encountData == 0 || !encount->encountData->enabled)
        return;
    fieldWork = (void *)GAME_DATA_GetFieldWork(encount->gameData);
    if (encount->fieldMap == 0 || fieldWork == 0)
        return;
    playerZoneId = FIELDMAP_GetZoneId(encount->fieldMap);
    FLDMMDL_GetPos(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(encount->fieldMap)), (struct VecFx32 *)(&pos));
    if (MAP_MATRIX_IsInRangeByPos(fieldWork, pos.x, pos.z) == 0)
        return;
    mapZoneId = MAP_MATRIX_GetZoneIdByPos(fieldWork, pos.x, pos.z);
    if (playerZoneId == 0xFFFF || mapZoneId == 0xFFFF || playerZoneId != mapZoneId)
        return;
    if (MISC_GetBadge(GAME_DATA_GetMiscSave(encount->gameData), 0) == 0)
        return;
    if (FIELDMAP_GetMoveKind(encount->fieldMap) != 0)
        return;
    if (gimmick->spot.active != 0)
        return;
    if (EFFECT_ENCOUNT_CountStep(gimmick, effectEncount) == 0)
        return;
    if (GFL_USE_GetRandomBelow(1000) >= effectEncount->spawnPercent * 10) {
        EFFECT_ENCOUNT_ResetStepCount(gimmick);
        return;
    }
    EFFECT_ENCOUNT_CollectCandidates(encount, effectEncount);
    if (effectEncount->candidateCount != 0)
        EFFECT_ENCOUNT_PickSpot(encount, effectEncount);
}

/* Removes the active spot and its effect object. */
void EFFECT_ENCOUNT_Reset(FieldEncount *encount)
{
    EFFECT_ENCOUNT_ClearSpot(encount, encount->effectEncount);
}

/* Tail-call thunk: removes the active spot when a model stands on it. */
void EFFECT_ENCOUNT_UpdateOccupiedSpot(FieldEncount *encount)
{
    EFFECT_ENCOUNT_ClearSpotIfOccupied(encount);
}

/* True when the active spot lies on the tile pos[0] (x), pos[1] (height), pos[2] (z). */
int EFFECT_ENCOUNT_IsSpotAt(FieldEncount *encount, short *pos)
{
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);

    if (gimmick->spot.active == 0)
        return 0;
    if (gimmick->spot.gridX != pos[0] || gimmick->spot.gridZ != pos[2] || gimmick->spot.gridHeight != pos[1])
        return 0;
    return 1;
}

static inline int isSpotAt(EffectEncountSpot *spot, GridPos *pos)
{
    if (spot->gridX != pos->x || spot->gridZ != pos->z || spot->gridHeight != pos->y)
        return 0;
    return 1;
}

/*
 * The player stepped: when the active spot lies under the player, runs its
 * result. Kind 7 gives a wild encounter on 20% of the rolls, kind 4 on 40%;
 * the other rolls start an item event. Returns the result of the start.
 */
int EFFECT_ENCOUNT_TriggerSpot(FieldEncount *encount)
{
    EffectEncount *effectEncount = encount->effectEncount;
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);
    EffectEncountSpot *spot = &gimmick->spot;
    int isItemEvent = 0;
    GridPos playerPos;
    u16 roll;
    int started;
    struct FieldPlayer *player;

    if (gimmick->spot.active == 0)
        return isItemEvent;
    FLDMMDL_GetGridNowPos(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(encount->fieldMap)), (struct MmdlGridVec *)(&playerPos));
    if (!isSpotAt(spot, &playerPos))
        return 0;
    roll = GFL_USE_GetRandomBelow(1000);
    if (spot->kind == 7) {
        if (roll < 200) {
            started = FIELD_ENCOUNT_CheckWildEncount(encount, 1);
        } else {
            started = EFFECT_ENCOUNT_StartItemEvent(encount, EFFECT_ENCOUNT_PickItemKind7());
            isItemEvent = 1;
        }
    } else if (spot->kind == 4) {
        if (roll < 400) {
            started = FIELD_ENCOUNT_CheckWildEncount(encount, 1);
        } else {
            started = EFFECT_ENCOUNT_StartItemEvent(encount, EFFECT_ENCOUNT_PickItemKind4());
            isItemEvent = 1;
        }
    } else {
        started = FIELD_ENCOUNT_CheckWildEncount(encount, 1);
    }
    if (started == 0) {
        EFFECT_ENCOUNT_ClearSpot(encount, effectEncount);
        return 0;
    }
    if (isItemEvent) {
        EFFECT_ENCOUNT_ClearSpot(encount, effectEncount);
    } else {
        if (spot->kind == 5 || spot->kind == 6)
            EFFECT_ENCOUNT_SetEffectFlag(encount, 1);
        spot->consumed = 1;
        player = FIELDMAP_GetFieldPlayer(encount->fieldMap);
        if (FIELD_PLAYER_IsGridHopping(player))
            FIELD_PLAYER_FinishGridHop(player);
    }
    return started;
}

/* Writes the larger of the x and z tile distance between the player and the active spot; 0 when there is no spot. */
int EFFECT_ENCOUNT_GetSpotDistance(FieldEncount *encount, short *out)
{
    EffectEncountSpot *spot = &GAME_DATA_GetFieldGimmick(encount->gameData)->spot;
    GridPos playerPos;
    int distX, distZ;

    if (spot->active == 0) {
        *out = 0;
        return 0;
    }
    FLDMMDL_GetGridNowPos(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(encount->fieldMap)), (struct MmdlGridVec *)(&playerPos));
    distX = (short)(spot->gridX - playerPos.x);
    if (distX < 0)
        distX = distX * 0xffffffff; /* stand-in: -distX and 0 - distX change the bytes */
    distZ = (short)(spot->gridZ - playerPos.z);
    if (distZ < 0)
        distZ = distZ * 0xffffffff;
    if (distX > distZ)
        *out = distX;
    else
        *out = distZ;
    return 1;
}

/* Marks the active spot as used and tells its effect object. */
void EFFECT_ENCOUNT_ConsumeSpot(FieldEncount *encount)
{
    EffectEncountSpot *spot = &GAME_DATA_GetFieldGimmick(encount->gameData)->spot;
    if (spot->active) {
        spot->consumed = 1;
        if (encount->effectEncount->effectObj != 0) {
            FLDEFF_ENCOUNT_SetPaused(encount->effectEncount->effectObj, 1);
        }
    }
}

/* Sets the pause state of the effect object of the active spot. */
void EFFECT_ENCOUNT_SetEffectPaused(FieldEncount *encount, int paused)
{
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);
    EffectEncount *effectEncount = encount->effectEncount;
    if (gimmick->spot.active && effectEncount->effectObj != 0) {
        FLDEFF_ENCOUNT_SetPaused(effectEncount->effectObj, paused);
    }
}

/* Sets the trigger flag of the effect object of the active spot. */
void EFFECT_ENCOUNT_SetEffectFlag(FieldEncount *encount, int flag)
{
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);
    EffectEncount *effectEncount = encount->effectEncount;
    if (gimmick->spot.active && effectEncount->effectObj != 0) {
        FLDEFF_ENCOUNT_SetDrawHidden(effectEncount->effectObj, flag);
    }
}

u16 EFFECT_ENCOUNT_GetItemId(FieldEncount *encount)
{
    return encount->effectEncount->itemId;
}

/* Map exit: flags the active spot so that the next map entry recreates its effect object. */
void EFFECT_ENCOUNT_MarkSpotForRestore(FieldEncount *encount)
{
    EffectEncountSpot *spot = &GAME_DATA_GetFieldGimmick(encount->gameData)->spot;
    if (spot->active) {
        spot->needsRestore = 1;
    }
}

/* Map entry: recreates the effect object of a saved spot, or drops the spot when it no longer fits. */
void EFFECT_ENCOUNT_RestoreSpot(FieldEncount *encount, EffectEncount *effectEncount)
{
    EffectEncountSpot *spot = &GAME_DATA_GetFieldGimmick(encount->gameData)->spot;
    unsigned short zoneId;

    if (spot->active == 0 || spot->needsRestore == 0)
        return;
    spot->needsRestore = 0;
    zoneId = FIELDMAP_GetZoneId(encount->fieldMap);
    if (zoneId != spot->zoneId || spot->consumed != 0)
        MI_CpuFill8(spot, 0, 0x10);
    else
        EFFECT_ENCOUNT_CreateEffectObj(encount, effectEncount, spot);
}

/* Counts one step; true once the count reaches the steps needed for a roll. */
int EFFECT_ENCOUNT_CountStep(EncountGimmickWork *gimmick, EffectEncount *effectEncount)
{
    u32 *stepCount = &gimmick->effectStepCount;
    if (*stepCount < 0xffffffff) {
        (*stepCount)++;
    }
    if (*stepCount >= effectEncount->stepsNeeded) {
        return 1;
    }
    return 0;
}

void EFFECT_ENCOUNT_ResetStepCount(EncountGimmickWork *gimmick)
{
    gimmick->effectStepCount = 0;
}

/* Fills the search window around the player; the window shape depends on the effect kind. */
void EFFECT_ENCOUNT_MakeSearchArea(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountArea *area)
{
    struct Mmdl *player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(encount->fieldMap));
    const s8 *offsets;
    s16 minX;
    s16 maxX;
    s16 minZ;
    s16 maxZ;

    area->tileX = FLDMMDL_GetGridNowX(player);
    area->tileZ = FLDMMDL_GetGridNowZ(player);
    area->blockOffsetX = area->tileX % 32;
    area->blockOffsetZ = area->tileZ % 32;
    area->blockX = area->tileX / 32;
    area->blockZ = area->tileZ / 32;
    area->originX = area->tileX - area->blockOffsetX;
    area->originZ = area->tileZ - area->blockOffsetZ;
    if (encount->encountData->effectKind != 2)
        offsets = sSearchAreaOffsets[GFL_USE_GetRandomBelow(4) + 1];
    else
        offsets = sSearchAreaOffsets[0];
    minX = area->blockOffsetX + offsets[0];
    if (minX < 0)
        minX = 0;
    maxX = area->blockOffsetX + offsets[1];
    if (maxX >= 32)
        maxX = 31;
    minZ = area->blockOffsetZ + offsets[2];
    if (minZ < 0)
        minZ = 0;
    maxZ = area->blockOffsetZ + offsets[3];
    if (maxZ >= 32)
        maxZ = 31;
    area->minX = minX + area->originX;
    area->maxX = maxX + area->originX;
    area->minZ = minZ + area->originZ;
    area->maxZ = maxZ + area->originZ;
}

/* Scans the search window and lists every tile whose attribute allows a spot. */
void EFFECT_ENCOUNT_CollectCandidates(FieldEncount *encount, EffectEncount *effectEncount)
{
    VecFx32 cellPos;
    EffectEncountArea area;
    FieldG3dMapHit cell;
    int blockIndex;
    int startX;
    s16 z;
    s16 x;
    struct FieldG3dMapper *mapper;
    float fixed;
    int kind;

    mapper = FIELDMAP_GetG3dMapper(encount->fieldMap);
    MI_CpuFill8(&effectEncount->candidateCount, 0, 0x5B0);
    cellPos.y = 0;
    blockIndex = FIELD_G3D_MAPPER_GetFocusSlot(mapper);
    if (FIELD_G3D_MAPPER_CheckSlotReady(mapper, blockIndex) == 0)
        return;
    EFFECT_ENCOUNT_MakeSearchArea(encount, effectEncount, &area);
    z = area.minZ;
    if ((z << 4) > 0)
        fixed = 0.5f + (float)(z << 16);
    else
        fixed = (float)(z << 16) - 0.5f;
    cellPos.z = (int)fixed + 0x8000;
    if ((area.minX << 4) > 0)
        fixed = 0.5f + (float)(area.minX << 16);
    else
        fixed = (float)(area.minX << 16) - 0.5f;
    startX = (int)fixed + 0x8000;
    for (; z <= area.maxZ; z++) {
        cellPos.x = startX;
        for (x = area.minX; x <= area.maxX; x++) {
            FIELD_G3D_MAPPER_QuerySlotPlane(mapper, blockIndex, &cellPos, &cell);
            kind = MAP_ATTR_GetEncounterEffectKind(cell.attr);
            if (kind != 8) {
                effectEncount->candidates[effectEncount->candidateCount].kind = kind;
                effectEncount->candidates[effectEncount->candidateCount].gridX = x;
                effectEncount->candidates[effectEncount->candidateCount].gridZ = z;
                effectEncount->candidates[effectEncount->candidateCount++].heightFx = cell.height;
            }
            cellPos.x += 0x10000;
        }
        cellPos.z += 0x10000;
    }
}

/* Picks a random candidate; when no model stands on it, it becomes the active spot with a new effect object. */
void EFFECT_ENCOUNT_PickSpot(FieldEncount *encount, EffectEncount *effectEncount)
{
    u16 index = GFL_USE_GetRandomBelow(effectEncount->candidateCount);
    EffectEncountCandidate *candidate = &effectEncount->candidates[index];
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);
    EffectEncountSpot *spot = &gimmick->spot;
    candidate->gridHeight = (candidate->heightFx >> 4) / 0x1000;
    if (EFFECT_ENCOUNT_IsTileOccupied(encount, candidate->gridX, candidate->gridHeight, candidate->gridZ, 0) == 0) {
        spot->gridX = candidate->gridX;
        spot->gridHeight = candidate->gridHeight;
        spot->gridZ = candidate->gridZ;
        spot->heightFx = candidate->heightFx;
        spot->kind = candidate->kind;
        spot->zoneId = FIELDMAP_GetZoneId(encount->fieldMap);
        spot->active = 1;
        EFFECT_ENCOUNT_ResetStepCount(gimmick);
        EFFECT_ENCOUNT_CreateEffectObj(encount, effectEncount, spot);
    }
}

/* True when a model stands on the tile (and is not the player, if ignorePlayer is set). */
int EFFECT_ENCOUNT_IsTileOccupied(FieldEncount *encount, s16 gridX, s16 gridHeight, s16 gridZ, int ignorePlayer)
{
    GridPos pos;
    struct Mmdl *mmdl;
    u32 iter = 0;
    struct MmdlSys *mmdlSys;
    struct Mmdl *player;
    MmdlObjSize *size;

    player = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(encount->fieldMap));
    mmdlSys = FIELDMAP_GetMmdlSys(encount->fieldMap);
    for (;;) {
        if (!FLDMMDL_SysSearchUseMmdl(mmdlSys, &mmdl, &iter))
            break;
        if (!FLDMMDL_CheckEndAcmd(mmdl))
            continue;
        if (mmdl == player && ignorePlayer)
            continue;
        size = FLDMMDL_GetObjCodeParam(mmdl);
        FLDMMDL_GetGridNowPos(mmdl, (struct MmdlGridVec *)(&pos));
        if (gridHeight != pos.y)
            continue;
        if (gridX < pos.x || gridX >= pos.x + size->gridWidth)
            continue;
        if (gridZ > pos.z || gridZ <= pos.z - size->gridDepth)
            continue;
        return 1;
    }
    return 0;
}

/* Removes the active spot when a model stands on it; returns 1 if it did. */
int EFFECT_ENCOUNT_ClearSpotIfOccupied(FieldEncount *encount)
{
    EffectEncountSpot *spot = &GAME_DATA_GetFieldGimmick(encount->gameData)->spot;

    if (spot->active == 0)
        return 0;
    if (EFFECT_ENCOUNT_IsTileOccupied(encount, spot->gridX, spot->gridHeight, spot->gridZ, 1)) {
        EFFECT_ENCOUNT_ClearSpot(encount, encount->effectEncount);
        return 1;
    }
    return 0;
}

/* Deletes the effect object and clears the active spot. */
void EFFECT_ENCOUNT_ClearSpot(FieldEncount *encount, EffectEncount *effectEncount)
{
    EncountGimmickWork *gimmick = GAME_DATA_GetFieldGimmick(encount->gameData);
    EFFECT_ENCOUNT_DeleteEffectObj(effectEncount);
    MI_CpuFill8(&gimmick->spot, 0, 0x10);
}

/* Creates the effect object of the spot; clears the spot when the effect cannot start. */
void EFFECT_ENCOUNT_CreateEffectObj(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountSpot *spot)
{
    if (effectEncount->effectObj == 0) {
        /* stand-in: the (u16) casts make the loads ldrh as the original has them; the spot fields are s16 elsewhere */
        effectEncount->effectObj = FLDEFF_ENCOUNT_Start((struct EncountSys *)encount, effectEncount->fieldEffectSys, (u16)spot->gridX, (u16)spot->gridZ, spot->heightFx, spot->kind);
        if (effectEncount->effectObj == 0) {
            MI_CpuFill8(spot, 0, 0x10);
        }
    }
}

void EFFECT_ENCOUNT_DeleteEffectObj(EffectEncount *effectEncount)
{
    if (effectEncount->effectObj != 0) {
        FIELD_EFFECT_DeleteObject(effectEncount->effectObj);
        effectEncount->effectObj = 0;
    }
}

/* Item for a kind 4 spot: 10% from the rare table, 85% from item ids 548..564, 5% item 229. */
unsigned short EFFECT_ENCOUNT_PickItemKind4(void)
{
    unsigned short roll = GFL_USE_GetRandomBelow(1000);

    if (roll < 100)
        return sRareItemIds[(unsigned short)(GFL_USE_GetRandomBelow(1000) / 100)];
    if (roll < 950)
        return (unsigned short)((unsigned short)(GFL_USE_GetRandomBelow(1700) / 100) + 548);
    return 229;
}

/* Item for a kind 7 spot: 90% item ids 565..570, 10% item 571. */
u16 EFFECT_ENCOUNT_PickItemKind7(void)
{
    if ((u16)GFL_USE_GetRandomBelow(1000) < 900) {
        return (u16)(GFL_USE_GetRandomBelow(600) / 100) + 565;
    }
    return 571;
}

/* Remembers the item and starts the item event script. */
int EFFECT_ENCOUNT_StartItemEvent(FieldEncount *encount, u16 itemId)
{
    encount->effectEncount->itemId = itemId;
    return (sptr)SCRIPT_SYS_CreateScriptEventSimple(encount->gameSystem, 0x2795, 0, FIELDMAP_GetHeapId(encount->fieldMap));
}
