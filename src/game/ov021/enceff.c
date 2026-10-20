/*
 * file:     enceff.c
 * unit:     yes
 * function: ENCEFF_Create, ENCEFF_Delete, ENCEFF_Start, ENCEFF_GetEffect, ENCEFF_RunUpdate, ENCEFF_AllocWork, ENCEFF_FreeWork, ENCEFF_GetWork, ENCEFF_LoadOverlay, ENCEFF_LoadOverlays4B4D, ENCEFF_LoadOverlay4B, ENCEFF_UnloadOverlays, ENCEFF_SelectEffectAndBgm, ENCEFF_SelectEffectAndBgmForTrainer
 * address:  0x021CF45C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): the earlier enceff.c split at 021CF7DC. __FILE__ anchor enceff.c at ENCEFF_Create 021CF47C and ENCEFF_AllocWork 021CF52C; the effect table d_021DB4FC and the bgm and effect tables d_021DB7E0/d_021DB7F6 belong to ENCEFF_* alone. The code after ENCEFF_SelectEffectAndBgmForTrainer (021CF7DC) changes module prefix and uses none of that data.
 *
 * symbols:
 *   d_021DE5FC     0x021DE5FC  data  ov021  a4
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GFL_HEAP_GetAllocatableSize  0x0203038C  arm
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   ov075_id       0x0000004B  data
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_GetParentZoneId  0x02013E40  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsAnyGrass  0x021AB2BC  thumb  ov021
 *   MAP_ATTR_IsSplashWaterB  0x021AB364  thumb  ov021
 *   MAP_ATTR_IsSandVariant  0x021AB37C  thumb  ov021
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   TPOKE_DATA_GetTrainerKind  0x0202A3FC  thumb
 *   TPOKE_DATA_FindTrainerType  0x0202A3D8  thumb
 *   FIELDMAP_GetAreaData  0x02188D58  thumb  ov021
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 */
#include "enceff_shared_types.h"

#include "../types.h"

struct FieldPlayer;

/* Encounter effect (ENCEFF): one effect plays before a battle. */
struct EncEffWork;

typedef void (*EncEffUpdateFunc)(struct EncEffWork *eff);

/* Work of one running effect (0x20 bytes). */
typedef struct EncEffWork {
    struct GameEvent *effect;    /* 0x00: effect event made by the builder */
    EncEffUpdateFunc update;     /* 0x04 */
    struct FieldMap *fieldMap;   /* 0x08 */
    u32 overlayIds[3];           /* 0x0C: overlays loaded for this effect */
    int overlayCount;            /* 0x18 */
    void *effectWork;            /* 0x1C: memory owned by the effect */
} EncEffWork;

/* One row of the effect table (0x14 bytes, ENCEFF_KIND_COUNT rows). */
typedef struct EncEffEntry {
    struct GameEvent *(*build)(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 arg);   /* 0x00 */
    EncEffUpdateFunc update;                                /* 0x04 */
    int overlayId;                                          /* 0x08: -1 for none */
    u32 buildArg;                                           /* 0x0C */
    u32 minLevel;                                           /* 0x10 */
} EncEffEntry;

enum {
    ENCEFF_KIND_COUNT = 0x25,
    ENCEFF_KIND_FALLBACK = 7,
    ENCEFF_MAX_OVERLAYS = 3
};

#include "../arm9/gfl_heap_wrap.h"


#include "fieldmap.h"

#include "../arm9/gfl_heap.h"

#include "../arm9/game_event.h"


#include "../arm9/gf_overlay.h"



extern u16 ZONEDATA_GetParentZoneId(u32 zoneId);


#include "field_player.h"

#include "map_attr.h"





#include "../arm9/tpoke_data.h"


struct AreaData;


extern u8 ZONEDATA_GetAreaInnerOuter(struct AreaData *areaData);

extern char d_021DE5FC[];

extern char abs_id_4b[];

extern char abs_id_4d[];

extern unsigned char ov075_id[];

extern const EncEffEntry d_021DB4FC[];

extern const u16 d_021DB7E0[];

extern const u8 d_021DB7F6[];

EncEffWork *ENCEFF_Create(u32 heapId, struct FieldMap *fieldMap);

int ENCEFF_Delete(EncEffWork *eff);

void ENCEFF_Start(EncEffWork *eff, struct GameEvent *parentEvent, int kind);

struct GameEvent *ENCEFF_GetEffect(EncEffWork *eff);

void ENCEFF_RunUpdate(EncEffWork *eff);

void ENCEFF_AllocWork(EncEffWork *eff, u32 size, u32 heapId);

void ENCEFF_FreeWork(EncEffWork *eff);

void *ENCEFF_GetWork(EncEffWork *eff);

void ENCEFF_LoadOverlay(EncEffWork *eff, u32 overlayId);

void ENCEFF_LoadOverlays4B4D(EncEffWork *eff);

void ENCEFF_LoadOverlay4B(EncEffWork *eff);

void ENCEFF_UnloadOverlays(EncEffWork *eff);

void ENCEFF_SelectEffectAndBgm(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId);

void ENCEFF_SelectEffectAndBgmForTrainer(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId);

EncEffWork *ENCEFF_Create(u32 heapId, struct FieldMap *fieldMap)
{
    EncEffWork *eff = GFL_HEAP_Alloc(heapId, sizeof(EncEffWork), 1, d_021DE5FC, 0x6c);

    eff->fieldMap = fieldMap;
    eff->overlayCount = 0;
    return eff;
}

int ENCEFF_Delete(EncEffWork *eff)
{
    ENCEFF_FreeWork(eff);
    ENCEFF_UnloadOverlays(eff);
    return GFL_HEAP_Free(eff);
}

/* Builds the effect of kind idx from the table, loading its overlay first. */
void ENCEFF_Start(EncEffWork *eff, struct GameEvent *parentEvent, int kind)
{
    struct GameEvent *effect;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap = eff->fieldMap;

    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    if (kind >= ENCEFF_KIND_COUNT) {
        kind = 0;
    }
    if (GFL_HEAP_GetAllocatableSize(0x15) < d_021DB4FC[kind].minLevel) {
        kind = ENCEFF_KIND_FALLBACK;
    }
    if (d_021DB4FC[kind].overlayId != -1) {
        ENCEFF_LoadOverlay(eff, d_021DB4FC[kind].overlayId);
    }
    effect = d_021DB4FC[kind].build(gameSystem, fieldMap, d_021DB4FC[kind].buildArg);
    GAME_EVENT_CallEvent(parentEvent, effect);
    eff->effect = GAME_EVENT_GetWork(effect);
    eff->update = d_021DB4FC[kind].update;
}

struct GameEvent *ENCEFF_GetEffect(EncEffWork *eff)
{
    return eff->effect;
}

/* Calls the update function of the effect, if it has one. */
void ENCEFF_RunUpdate(EncEffWork *eff)
{
    if (eff->update != 0) {
        eff->update(eff);
    }
}

void ENCEFF_AllocWork(EncEffWork *eff, u32 size, u32 heapId)
{
    eff->effectWork = GFL_HEAP_Alloc(heapId, size, 1, d_021DE5FC, 0xe3);
}

void ENCEFF_FreeWork(EncEffWork *eff)
{
    void *work = eff->effectWork;
    if (work != 0) {
        GFL_HEAP_Free(work);
        eff->effectWork = 0;
    }
}

void *ENCEFF_GetWork(EncEffWork *eff)
{
    return eff->effectWork;
}

/* Loads an overlay and remembers its id for the unload. */
void ENCEFF_LoadOverlay(EncEffWork *eff, u32 overlayId)
{
    GF_OVERLAY_Load(overlayId);
    eff->overlayIds[eff->overlayCount++] = overlayId;
}

void ENCEFF_LoadOverlays4B4D(EncEffWork *eff)
{
    ENCEFF_LoadOverlay(eff, (u32)abs_id_4b);
    ENCEFF_LoadOverlay(eff, (u32)abs_id_4d);
}

void ENCEFF_LoadOverlay4B(EncEffWork *eff)
{
    ENCEFF_LoadOverlay(eff, (u32)ov075_id);
}

/* Unloads the overlays in reverse order. */
void ENCEFF_UnloadOverlays(EncEffWork *eff)
{
    int i;

    if (eff->overlayCount > 0) {
        while (eff->overlayCount > 0) {
            i = eff->overlayCount - 1;
            if (eff->overlayIds[i] != 0) {
                GF_OVERLAY_Unload(eff->overlayIds[i]);
            }
            eff->overlayCount--;
        }
    }
}

/*
 * Picks the effect kind (index into the effect table) and the battle BGM
 * for a battle against a wild or scripted opponent. Legendary species have
 * their own kinds; other battles depend on the tile the player stands on.
 */
void ENCEFF_SelectEffectAndBgm(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId)
{
    u32 attr;
    u16 tileType;
    u16 parentZoneId;
    u32 effectKind;
    u16 bgmId;

    parentZoneId = ZONEDATA_GetParentZoneId(FIELDMAP_GetZoneId(fieldMap));
    switch (species) {
    case 0x23B:
        *outBgmId = 0x469;
        *outEffectKind = 0x23;
        return;
    case 0x283:
        *outBgmId = 0x474;
        *outEffectKind = 0x20;
        return;
    case 0x284:
        *outBgmId = 0x475;
        *outEffectKind = 0x20;
        return;
    case 0x286:
        *outBgmId = 0x476;
        *outEffectKind = 0x20;
        return;
    case 0x27D:
        *outBgmId = 0x468;
        *outEffectKind = 0x1f;
        return;
    case 0x1EE:
        *outBgmId = 0x478;
        *outEffectKind = 0x1f;
        return;
    case 0x27E:
    case 0x27F:
    case 0x280:
    case 0x287:
        *outBgmId = 0x478;
        *outEffectKind = 0x22;
        return;
    case 0x281:
    case 0x282:
    case 0x285:
        *outBgmId = 0x477;
        *outEffectKind = 0x21;
        return;
    }
    if (effectId == 1) {
        *outBgmId = 0x469;
        *outEffectKind = 0x1f;
        return;
    }
    if (effectId == 4) {
        if (parentZoneId == 0xd6) {
            *outBgmId = 0x469;
        } else {
            *outBgmId = 0x468;
        }
        *outEffectKind = 2;
        return;
    }
    attr = FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(fieldMap));
    tileType = MAP_ATTR_GetTerrainId(attr);
    if (MAP_ATTR_GetFlags(attr) & 2) {
        bgmId = 0x468;
        effectKind = 2;
    } else if (MAP_ATTR_IsAnyGrass(tileType)) {
        if (hasWildOpponent) {
            bgmId = 0x469;
            effectKind = 1;
        } else {
            bgmId = 0x468;
            effectKind = 0;
        }
    } else if (MAP_ATTR_IsSplashWaterB(tileType)) {
        bgmId = 0x468;
        effectKind = 0;
    } else {
        if (MAP_ATTR_IsSandVariant(tileType)) {
            bgmId = 0x468;
            effectKind = 4;
        } else {
            bgmId = 0x468;
            effectKind = 3;
        }
    }
    *outEffectKind = effectKind;
    if (parentZoneId == 0xd6) {
        *outBgmId = 0x469;
    } else {
        *outBgmId = bgmId;
    }
}

/*
 * Picks the effect kind and the battle BGM for a trainer battle: from the
 * trainer's two class groups when the first is below 11, otherwise from the
 * tile and the area the player stands in.
 */
void ENCEFF_SelectEffectAndBgmForTrainer(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId)
{
    int areaIsInner = 1;
    u32 trainerClass = TPOKE_DATA_GetRecordField(trainerData, 1);
    u32 bgmGroup = TPOKE_DATA_GetTrainerKind(trainerClass);
    u32 effectGroup = TPOKE_DATA_FindTrainerType(trainerClass);
    int effectKind;

    if (bgmGroup < 0xb) {
        *outBgmId = d_021DB7E0[bgmGroup];
        *outEffectKind = d_021DB7F6[effectGroup];
        return;
    }
    {
        u32 attr = FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(fieldMap));
        u32 tileType = MAP_ATTR_GetTerrainId(attr);

        if (MAP_ATTR_GetFlags(attr) & 2) {
            effectKind = 6;
        } else if (MAP_ATTR_IsSandVariant(tileType) != 0) {
            effectKind = 8;
        } else {
            if (ZONEDATA_GetAreaInnerOuter(FIELDMAP_GetAreaData(fieldMap)) == 0) {
                areaIsInner = 0;
            }
            effectKind = 5;
            if (areaIsInner == 0) {
                effectKind = 7;
            }
        }
    }
    *outBgmId = 0x46a;
    *outEffectKind = effectKind;
}
