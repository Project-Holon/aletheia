/*
 * file:     effect_encount.c
 * unit:     yes
 * function: func_021AA77C, func_021AA794, func_021AA7AC, func_021AA7CC, func_021AA7DC, func_021AA80C, func_021AA8EC, func_021AA8F8, func_021AA900, func_021AA944, func_021AAA4C, func_021AAABC, func_021AAAF0, func_021AAB1C, func_021AAB48, func_021AAB54, func_021AAB74, func_021AABC4, func_021AABEC, func_021AABF4, func_021AACD4, func_021AAE34, func_021AAEC0, func_021AAF54, func_021AAFA0, func_021AAFC0, func_021AAFFC, func_021AB018, func_021AB070, func_021AB0AC
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
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02005728  0x02005728  thumb
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188C98  0x02188C98  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   d_021DDFB4  0x021DDFB4  data  a4
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   d_021D8E70  0x021D8E70  data  a4
 *   func_02012974  0x02012974  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021A3624  0x021A3624  thumb  ov021
 *   func_021A3644  0x021A3644  thumb  ov021
 *   func_021ADB4C  0x021ADB4C  thumb
 *   func_021ADB5C  0x021ADB5C  thumb
 *   d_021D8E76     0x021D8E76  data  a1
 *   func_0218D168  0x0218D168  thumb  ov021
 *   func_0218DBD4  0x0218DBD4  thumb  ov021
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0218DBAC  0x0218DBAC  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_021ADAAC  0x021ADAAC  thumb
 *   d_021D8E8A     0x021D8E8A  data  a2
 *   func_02158768  0x02158768  thumb
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_021AB504  0x021AB504  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 */
#include "effect_encount_types.h"

typedef signed char s8;

struct Mmdl;
struct MmdlSys;
struct FieldPlayer;
struct FieldG3dMapper;
struct GameData;
struct GameSystem;
struct BeaconSave;

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

/* Cell data of the map mapper (attribute and height of one tile). */
typedef struct MapCellInfo {
    u8 pad00[8];
    u32 attribute;
    u32 height;
} MapCellInfo;

/* Size of a model in tiles, in the object code parameter. */
typedef struct MmdlObjSize {
    u8 pad00[0x0B];
    u8 gridWidth;
    u8 gridDepth;
} MmdlObjSize;

extern u32 func_020307B0(void *memory);
extern u32 func_02082BCC(void *dest, int value, int size);
extern u32 func_02005728(u32 range);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int mode, const char *fileName, u16 line);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern EncountGimmickWork *func_02012A38(const struct GameData *gameData);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern struct FieldG3dMapper *func_02188C98(struct FieldMap *fieldMap);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern int func_0216D83C(struct Mmdl *mmdl);
extern int func_0216D86C(struct Mmdl *mmdl);
extern struct FieldEffectSys *func_02188CD0(struct FieldMap *fieldMap);
extern void *func_02012974(const struct GameData *gameData);
extern void func_0216D88C(const struct Mmdl *mmdl, VecFx32 *out);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern struct BeaconSave *func_02012F08(struct GameData *gameData);
extern u32 func_0200C234(struct BeaconSave *beacon, u32 bit);
extern u32 func_02188CFC(struct FieldMap *fieldMap);
extern void func_0216D828(struct Mmdl *mmdl, GridPos *out);
extern int func_021A3624(struct FieldPlayer *player);
extern void func_021A3644(struct FieldPlayer *player);
extern int func_0218D168(struct FieldG3dMapper *mapper);
extern int func_0218DBD4(struct FieldG3dMapper *mapper, int blockIndex);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0218DBAC(struct FieldG3dMapper *mapper, int blockIndex, VecFx32 *pos, MapCellInfo *out);
extern struct MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern int func_0216DD1C(struct MmdlSys *sys, struct Mmdl **out, u32 *iter);
extern int func_0216D454(struct Mmdl *mmdl);
extern MmdlObjSize *func_0216E3C4(struct Mmdl *mmdl);
extern FieldEffectObj *func_021ADAAC(FieldEncount *encount, FieldEffectSys *fieldEffectSys, int gridX, int gridZ, int heightFx, int kind);
extern void func_021ADB4C(FieldEffectObj *effect, int paused);
extern void func_021ADB5C(FieldEffectObj *effect, int flag);
extern int func_02158768(struct GameSystem *gameSystem, u32 scriptId, int a2, u16 heapId);
extern int func_021A9F40(FieldEncount *encount, int triggerMode);
extern int func_021AB504(u32 attribute);
extern void func_021AC154(FieldEffectObj *effect);

EffectEncount *func_021AA77C(int heapId);
int func_021AA794(EffectEncount *effectEncount);
void func_021AA7AC(FieldEncount *encount, EffectEncount *effectEncount);
void func_021AA7CC(FieldEncount *encount, EffectEncount *effectEncount);
void func_021AA7DC(FieldEncount *encount, EffectEncount *effectEncount);
void func_021AA80C(FieldEncount *encount);
void func_021AA8EC(FieldEncount *encount);
void func_021AA8F8(FieldEncount *encount);
int func_021AA900(FieldEncount *encount, short *pos);
int func_021AA944(FieldEncount *encount);
int func_021AAA4C(FieldEncount *encount, short *out);
void func_021AAABC(FieldEncount *encount);
void func_021AAAF0(FieldEncount *encount, int paused);
void func_021AAB1C(FieldEncount *encount, int flag);
u16 func_021AAB48(FieldEncount *encount);
void func_021AAB54(FieldEncount *encount);
void func_021AAB74(FieldEncount *encount, EffectEncount *effectEncount);
int func_021AABC4(EncountGimmickWork *gimmick, EffectEncount *effectEncount);
void func_021AABEC(EncountGimmickWork *gimmick);
void func_021AABF4(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountArea *area);
void func_021AACD4(FieldEncount *encount, EffectEncount *effectEncount);
void func_021AAE34(FieldEncount *encount, EffectEncount *effectEncount);
int func_021AAEC0(FieldEncount *encount, s16 gridX, s16 gridHeight, s16 gridZ, int ignorePlayer);
int func_021AAF54(FieldEncount *encount);
void func_021AAFA0(FieldEncount *encount, EffectEncount *effectEncount);
void func_021AAFC0(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountSpot *spot);
void func_021AAFFC(EffectEncount *effectEncount);
unsigned short func_021AB018(void);
u16 func_021AB070(void);
int func_021AB0AC(FieldEncount *encount, u16 itemId);

extern char d_021DDFB4[];
extern const EffectEncountSetting d_021D8E70[];
extern const s8 d_021D8E76[][4];
extern unsigned short d_021D8E8A[];

EffectEncount *func_021AA77C(int heapId)
{
    return func_02030734(heapId, sizeof(EffectEncount), 1, d_021DDFB4, 0x6e);
}

int func_021AA794(EffectEncount *effectEncount)
{
    func_02082BCC(effectEncount, 0, sizeof(EffectEncount));
    return func_020307B0(effectEncount);
}

void func_021AA7AC(FieldEncount *encount, EffectEncount *effectEncount)
{
    effectEncount->fieldEffectSys = func_02188CD0(encount->fieldMap);
    func_021AA7DC(encount, effectEncount);
    func_021AAB74(encount, effectEncount);
}

void func_021AA7CC(FieldEncount *encount, EffectEncount *effectEncount)
{
    func_021AAB54(encount);
    func_021AAFFC(effectEncount);
}

void func_021AA7DC(FieldEncount *encount, EffectEncount *effectEncount)
{
    unsigned int effectKind = encount->encountData->effectKind;
    if (effectKind > 2) {
        effectKind = 0;
    }
    effectEncount->stepsNeeded = d_021D8E70[effectKind].stepsNeeded;
    effectEncount->spawnPercent = d_021D8E70[effectKind].spawnPercent;
}

/* Called once per player step: counts the step and, when the roll succeeds, picks a new spot. */
void func_021AA80C(FieldEncount *encount)
{
    EffectEncount *effectEncount = encount->effectEncount;
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);
    void *fieldWork;
    u16 playerZoneId;
    VecFx32 pos;
    int mapZoneId;

    if (encount == 0 || encount->encountData == 0 || !encount->encountData->enabled)
        return;
    fieldWork = func_02012974(encount->gameData);
    if (encount->fieldMap == 0 || fieldWork == 0)
        return;
    playerZoneId = func_02188C9C(encount->fieldMap);
    func_0216D88C(func_021A3074(func_02188CB4(encount->fieldMap)), &pos);
    if (func_02159C48((int)fieldWork, pos.x, pos.z) == 0)
        return;
    mapZoneId = func_02159BD4((int)fieldWork, pos.x, pos.z);
    if (playerZoneId == 0xFFFF || mapZoneId == 0xFFFF || playerZoneId != mapZoneId)
        return;
    if (func_0200C234(func_02012F08(encount->gameData), 0) == 0)
        return;
    if (func_02188CFC(encount->fieldMap) != 0)
        return;
    if (gimmick->spot.active != 0)
        return;
    if (func_021AABC4(gimmick, effectEncount) == 0)
        return;
    if (func_02005728(1000) >= effectEncount->spawnPercent * 10) {
        func_021AABEC(gimmick);
        return;
    }
    func_021AACD4(encount, effectEncount);
    if (effectEncount->candidateCount != 0)
        func_021AAE34(encount, effectEncount);
}

/* Removes the active spot and its effect object. */
void func_021AA8EC(FieldEncount *encount)
{
    func_021AAFA0(encount, encount->effectEncount);
}

/* Tail-call thunk: removes the active spot when a model stands on it. */
void func_021AA8F8(FieldEncount *encount)
{
    func_021AAF54(encount);
}

/* True when the active spot lies on the tile pos[0] (x), pos[1] (height), pos[2] (z). */
int func_021AA900(FieldEncount *encount, short *pos)
{
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);

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
int func_021AA944(FieldEncount *encount)
{
    EffectEncount *effectEncount = encount->effectEncount;
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);
    EffectEncountSpot *spot = &gimmick->spot;
    int isItemEvent = 0;
    GridPos playerPos;
    u16 roll;
    int started;
    struct FieldPlayer *player;

    if (gimmick->spot.active == 0)
        return isItemEvent;
    func_0216D828(func_021A3074(func_02188CB4(encount->fieldMap)), &playerPos);
    if (!isSpotAt(spot, &playerPos))
        return 0;
    roll = func_02005728(1000);
    if (spot->kind == 7) {
        if (roll < 200) {
            started = func_021A9F40(encount, 1);
        } else {
            started = func_021AB0AC(encount, func_021AB070());
            isItemEvent = 1;
        }
    } else if (spot->kind == 4) {
        if (roll < 400) {
            started = func_021A9F40(encount, 1);
        } else {
            started = func_021AB0AC(encount, func_021AB018());
            isItemEvent = 1;
        }
    } else {
        started = func_021A9F40(encount, 1);
    }
    if (started == 0) {
        func_021AAFA0(encount, effectEncount);
        return 0;
    }
    if (isItemEvent) {
        func_021AAFA0(encount, effectEncount);
    } else {
        if (spot->kind == 5 || spot->kind == 6)
            func_021AAB1C(encount, 1);
        spot->consumed = 1;
        player = func_02188CB4(encount->fieldMap);
        if (func_021A3624(player))
            func_021A3644(player);
    }
    return started;
}

/* Writes the larger of the x and z tile distance between the player and the active spot; 0 when there is no spot. */
int func_021AAA4C(FieldEncount *encount, short *out)
{
    EffectEncountSpot *spot = &func_02012A38(encount->gameData)->spot;
    GridPos playerPos;
    int distX, distZ;

    if (spot->active == 0) {
        *out = 0;
        return 0;
    }
    func_0216D828(func_021A3074(func_02188CB4(encount->fieldMap)), &playerPos);
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
void func_021AAABC(FieldEncount *encount)
{
    EffectEncountSpot *spot = &func_02012A38(encount->gameData)->spot;
    if (spot->active) {
        spot->consumed = 1;
        if (encount->effectEncount->effectObj != 0) {
            func_021ADB4C(encount->effectEncount->effectObj, 1);
        }
    }
}

/* Sets the pause state of the effect object of the active spot. */
void func_021AAAF0(FieldEncount *encount, int paused)
{
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);
    EffectEncount *effectEncount = encount->effectEncount;
    if (gimmick->spot.active && effectEncount->effectObj != 0) {
        func_021ADB4C(effectEncount->effectObj, paused);
    }
}

/* Sets the trigger flag of the effect object of the active spot. */
void func_021AAB1C(FieldEncount *encount, int flag)
{
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);
    EffectEncount *effectEncount = encount->effectEncount;
    if (gimmick->spot.active && effectEncount->effectObj != 0) {
        func_021ADB5C(effectEncount->effectObj, flag);
    }
}

u16 func_021AAB48(FieldEncount *encount)
{
    return encount->effectEncount->itemId;
}

/* Map exit: flags the active spot so that the next map entry recreates its effect object. */
void func_021AAB54(FieldEncount *encount)
{
    EffectEncountSpot *spot = &func_02012A38(encount->gameData)->spot;
    if (spot->active) {
        spot->needsRestore = 1;
    }
}

/* Map entry: recreates the effect object of a saved spot, or drops the spot when it no longer fits. */
void func_021AAB74(FieldEncount *encount, EffectEncount *effectEncount)
{
    EffectEncountSpot *spot = &func_02012A38(encount->gameData)->spot;
    unsigned short zoneId;

    if (spot->active == 0 || spot->needsRestore == 0)
        return;
    spot->needsRestore = 0;
    zoneId = func_02188C9C(encount->fieldMap);
    if (zoneId != spot->zoneId || spot->consumed != 0)
        func_02082BCC(spot, 0, 0x10);
    else
        func_021AAFC0(encount, effectEncount, spot);
}

/* Counts one step; true once the count reaches the steps needed for a roll. */
int func_021AABC4(EncountGimmickWork *gimmick, EffectEncount *effectEncount)
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

void func_021AABEC(EncountGimmickWork *gimmick)
{
    gimmick->effectStepCount = 0;
}

/* Fills the search window around the player; the window shape depends on the effect kind. */
void func_021AABF4(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountArea *area)
{
    struct Mmdl *player = func_021A3074(func_02188CB4(encount->fieldMap));
    const s8 *offsets;
    s16 minX;
    s16 maxX;
    s16 minZ;
    s16 maxZ;

    area->tileX = func_0216D83C(player);
    area->tileZ = func_0216D86C(player);
    area->blockOffsetX = area->tileX % 32;
    area->blockOffsetZ = area->tileZ % 32;
    area->blockX = area->tileX / 32;
    area->blockZ = area->tileZ / 32;
    area->originX = area->tileX - area->blockOffsetX;
    area->originZ = area->tileZ - area->blockOffsetZ;
    if (encount->encountData->effectKind != 2)
        offsets = d_021D8E76[func_02005728(4) + 1];
    else
        offsets = d_021D8E76[0];
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
void func_021AACD4(FieldEncount *encount, EffectEncount *effectEncount)
{
    VecFx32 cellPos;
    EffectEncountArea area;
    MapCellInfo cell;
    int blockIndex;
    int startX;
    s16 z;
    s16 x;
    struct FieldG3dMapper *mapper;
    int fixed;
    int kind;

    mapper = func_02188C98(encount->fieldMap);
    func_02082BCC(&effectEncount->candidateCount, 0, 0x5B0);
    cellPos.y = 0;
    blockIndex = func_0218D168(mapper);
    if (func_0218DBD4(mapper, blockIndex) == 0)
        return;
    func_021AABF4(encount, effectEncount, &area);
    z = area.minZ;
    if ((z << 4) > 0)
        fixed = func_0209C95C(0x3f000000, func_0209BDBC(z << 16));
    else
        fixed = func_0209CB8C(func_0209BDBC(z << 16), 0x3f000000);
    cellPos.z = func_0209C494(fixed) + 0x8000;
    if ((area.minX << 4) > 0)
        fixed = func_0209C95C(0x3f000000, func_0209BDBC(area.minX << 16));
    else
        fixed = func_0209CB8C(func_0209BDBC(area.minX << 16), 0x3f000000);
    startX = func_0209C494(fixed) + 0x8000;
    for (; z <= area.maxZ; z++) {
        cellPos.x = startX;
        for (x = area.minX; x <= area.maxX; x++) {
            func_0218DBAC(mapper, blockIndex, &cellPos, &cell);
            kind = func_021AB504(cell.attribute);
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
void func_021AAE34(FieldEncount *encount, EffectEncount *effectEncount)
{
    u16 index = func_02005728(effectEncount->candidateCount);
    EffectEncountCandidate *candidate = &effectEncount->candidates[index];
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);
    EffectEncountSpot *spot = &gimmick->spot;
    candidate->gridHeight = (candidate->heightFx >> 4) / 0x1000;
    if (func_021AAEC0(encount, candidate->gridX, candidate->gridHeight, candidate->gridZ, 0) == 0) {
        spot->gridX = candidate->gridX;
        spot->gridHeight = candidate->gridHeight;
        spot->gridZ = candidate->gridZ;
        spot->heightFx = candidate->heightFx;
        spot->kind = candidate->kind;
        spot->zoneId = func_02188C9C(encount->fieldMap);
        spot->active = 1;
        func_021AABEC(gimmick);
        func_021AAFC0(encount, effectEncount, spot);
    }
}

/* True when a model stands on the tile (and is not the player, if ignorePlayer is set). */
int func_021AAEC0(FieldEncount *encount, s16 gridX, s16 gridHeight, s16 gridZ, int ignorePlayer)
{
    GridPos pos;
    struct Mmdl *mmdl;
    u32 iter = 0;
    struct MmdlSys *mmdlSys;
    struct Mmdl *player;
    MmdlObjSize *size;

    player = func_021A3074(func_02188CB4(encount->fieldMap));
    mmdlSys = func_02188C7C(encount->fieldMap);
    for (;;) {
        if (!func_0216DD1C(mmdlSys, &mmdl, &iter))
            break;
        if (!func_0216D454(mmdl))
            continue;
        if (mmdl == player && ignorePlayer)
            continue;
        size = func_0216E3C4(mmdl);
        func_0216D828(mmdl, &pos);
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
int func_021AAF54(FieldEncount *encount)
{
    EffectEncountSpot *spot = &func_02012A38(encount->gameData)->spot;

    if (spot->active == 0)
        return 0;
    if (func_021AAEC0(encount, spot->gridX, spot->gridHeight, spot->gridZ, 1)) {
        func_021AAFA0(encount, encount->effectEncount);
        return 1;
    }
    return 0;
}

/* Deletes the effect object and clears the active spot. */
void func_021AAFA0(FieldEncount *encount, EffectEncount *effectEncount)
{
    EncountGimmickWork *gimmick = func_02012A38(encount->gameData);
    func_021AAFFC(effectEncount);
    func_02082BCC(&gimmick->spot, 0, 0x10);
}

/* Creates the effect object of the spot; clears the spot when the effect cannot start. */
void func_021AAFC0(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountSpot *spot)
{
    if (effectEncount->effectObj == 0) {
        /* stand-in: the (u16) casts make the loads ldrh as the original has them; the spot fields are s16 elsewhere */
        effectEncount->effectObj = func_021ADAAC(encount, effectEncount->fieldEffectSys, (u16)spot->gridX, (u16)spot->gridZ, spot->heightFx, spot->kind);
        if (effectEncount->effectObj == 0) {
            func_02082BCC(spot, 0, 0x10);
        }
    }
}

void func_021AAFFC(EffectEncount *effectEncount)
{
    if (effectEncount->effectObj != 0) {
        func_021AC154(effectEncount->effectObj);
        effectEncount->effectObj = 0;
    }
}

/* Item for a kind 4 spot: 10% from the rare table, 85% from item ids 548..564, 5% item 229. */
unsigned short func_021AB018(void)
{
    unsigned short roll = func_02005728(1000);

    if (roll < 100)
        return d_021D8E8A[(unsigned short)(func_02005728(1000) / 100)];
    if (roll < 950)
        return (unsigned short)((unsigned short)(func_02005728(1700) / 100) + 548);
    return 229;
}

/* Item for a kind 7 spot: 90% item ids 565..570, 10% item 571. */
u16 func_021AB070(void)
{
    if ((u16)func_02005728(1000) < 900) {
        return (u16)(func_02005728(600) / 100) + 565;
    }
    return 571;
}

/* Remembers the item and starts the item event script. */
int func_021AB0AC(FieldEncount *encount, u16 itemId)
{
    encount->effectEncount->itemId = itemId;
    return func_02158768(encount->gameSystem, 0x2795, 0, func_02188C84(encount->fieldMap));
}
