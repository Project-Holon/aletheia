/*
 * file:     fldeff_encount.c
 * unit:     yes
 * function: FLDEFF_ENCOUNT_CreateKind0, FLDEFF_ENCOUNT_CreateKind1, FLDEFF_ENCOUNT_CreateKind2, FLDEFF_ENCOUNT_CreateKind3, FLDEFF_ENCOUNT_CreateKind4, FLDEFF_ENCOUNT_CreateKind5, FLDEFF_ENCOUNT_Delete, FLDEFF_ENCOUNT_Create, FLDEFF_ENCOUNT_LoadKind, FLDEFF_ENCOUNT_BuildDrawSet, FLDEFF_ENCOUNT_DeleteDrawSet, FLDEFF_ENCOUNT_LoadKind0Models, FLDEFF_ENCOUNT_LoadModels, FLDEFF_ENCOUNT_FreeResources, FLDEFF_ENCOUNT_Start, FLDEFF_ENCOUNT_SetPaused, FLDEFF_ENCOUNT_SetDrawHidden, FLDEFF_ENCOUNT_Init, FLDEFF_ENCOUNT_Exit, FLDEFF_ENCOUNT_Update, FLDEFF_ENCOUNT_PlaySound, FLDEFF_ENCOUNT_DrawSlotObject
 * address:  0x021AD758
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_namipoke.c at 0x021AD758 (lane FXC, CL127: __FILE__ fldeff_encount.c on 0x021AD7B4; 021AD758..021AD7A0 are its resource wrappers). Includes the slot object draw 021ADC6C (CL126).
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_GetObjectMode  0x021AC1A0  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   sFldeffEncountFileName  0x021DE0E8  data
 *   sEncountModelDescs     0x021DE094  data  a2
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   FIELD_EFFECT_GetModelBaseOffset  0x021ABE28  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   FIELD_EFFECT_GetModelBaseOffsetAlt  0x021ABE2C  thumb  ov021
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   sEncountResourceIndex     0x021D9238  data  a1
 *   sEncountFuncs     0x021D9240  data  a4
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   EFFECT_ENCOUNT_GetSpotDistance  0x021AAA4C  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlotWithOwner  0x02028ACC  thumb
 *   sEncountVolumes     0x021D9234  data   a1
 *   sEncounterDrawSlotStatus  0x021D9254  data
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm  arm9
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm  arm9
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm  arm9
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm  arm9
 *   MTX_Identity33_  0x0207ADC4  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 */
#include "../arm9/billboard_act_types.h"
#include "../arm9/g3d_system_types.h"
#include "../ov010/fldmmdl_types.h"

#include "../sdk_fx.h"

/* Opaque types of other files. */
typedef struct ArcHandle ArcHandle;
typedef struct FieldMap FieldMap;                       /* field map (fieldmap.c) */
typedef struct FieldEffectSys FieldEffectSys;           /* field effect system (field_effect.c) */
typedef struct FieldEffectObj FieldEffectObj;           /* one running effect (field_effect.c) */
typedef struct FieldEffectObjFuncs FieldEffectObjFuncs; /* callback table: work size, init, exit, update, draw */
typedef struct SoundSys SoundSys;

/* Partial view of the encounter system (effect_encount.c): only the field the sound call reads. */
typedef struct EncountSys {
    u8 pad00[8];
    const void *gameData; /* 0x08 */
} EncountSys;

#define FLDEFF_ID_ENCOUNT_FIRST   0x12

/* Models and animations of one kind of the rustling-spot effect. */
typedef struct EncountModelDesc {
    u8 animeCount;         /* animations per model */
    u8 modelCount : 3;
    u8 modelStride : 3;    /* file id distance between two models */
    u8 useBaseOffset : 1;  /* add the model base offset of the effect system */
    u8 useBaseOffsetAlt : 1;
    u16 seId;              /* sound played when the animation restarts */
    u16 modelFile;
    u16 animeFile[4];
} EncountModelDesc;

/* One drawable model: render, animations and the object that plays them. */
typedef struct EncountDrawSet {
    G3dObject *object;  /* 0x00 */
    G3dAnime *anime[4]; /* 0x04 */
    G3dRender *render;  /* 0x14 */
} EncountDrawSet;

/* Resources of one kind of the rustling-spot effect (allocated 0x98 bytes). */
typedef struct EncountModelSet {
    FieldEffectSys *fieldEffect; /* 0x00 */
    int unused04;
    G3dResource *model[4];       /* 0x08 */
    G3dResource *anime[4];       /* 0x18 index = model * animeCount + animation */
    EncountDrawSet draw[4];      /* 0x28 */
    EncountModelDesc desc;       /* 0x88 */
} EncountModelSet;

/* Start parameter of the rustling-spot effect (0x28 bytes). */
typedef struct EncountStartParam {
    EncountSys *encount;  /* 0x00 */
    EncountModelSet *res; /* 0x04 */
    void *mmdlSys;        /* 0x08 */
    int unused0C;
    u16 gridX;            /* 0x10 */
    u16 gridZ;            /* 0x12 */
    int kind;             /* 0x14 effect resource index */
    u8 setIndex;          /* 0x18 draw set that plays when kind is 0 */
    u8 pad19[3];
    VecFx32 pos;          /* 0x1C */
} EncountStartParam;

/* Work of the rustling-spot effect (0x38 bytes). */
typedef struct EncountWork {
    u16 modeIsZero;          /* 0x00 */
    u8 paused;               /* 0x02 */
    u8 drawHidden;           /* 0x03 set by the encounter system */
    EncountStartParam param; /* 0x04 */
    int pad2C[2];
    EncountSys *encount;     /* 0x34 */
} EncountWork;

#include "../arm9/gfl_heap_wrap.h"
#include "field_effect.h"
#include "../arm9/g3d_system.h"
#include "fieldmap.h"
struct MmdlSys;
#include "../arm9/mi_memory.h"
struct FieldEncount;
#include "effect_encount.h"
struct GameData;
#include "../arm9/game_data.h"
struct FieldSoundSystem;
#include "../arm9/field_sound_system.h"

EncountModelSet *FLDEFF_ENCOUNT_CreateKind0(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind1(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind2(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind3(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind4(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind5(FieldEffectSys *fieldEffect, int heapId);
void FLDEFF_ENCOUNT_Delete(FieldEffectSys *fieldEffect, EncountModelSet *set);
EncountModelSet *FLDEFF_ENCOUNT_Create(FieldEffectSys *fieldEffect, int heapId, u32 kind);
void FLDEFF_ENCOUNT_LoadKind(EncountModelSet *set, u32 kind);
void FLDEFF_ENCOUNT_BuildDrawSet(EncountDrawSet *draw, EncountModelSet *set, int modelIndex);
void FLDEFF_ENCOUNT_DeleteDrawSet(EncountDrawSet *draw, EncountModelSet *set);
void FLDEFF_ENCOUNT_LoadKind0Models(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc);
void FLDEFF_ENCOUNT_LoadModels(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc);
void FLDEFF_ENCOUNT_FreeResources(EncountModelSet *set);
FieldEffectObj *FLDEFF_ENCOUNT_Start(EncountSys *encount, FieldEffectSys *fieldEffect, int gridX, int gridZ, int y, int setIndex);
void FLDEFF_ENCOUNT_SetPaused(FieldEffectObj *effect, int paused);
void FLDEFF_ENCOUNT_SetDrawHidden(FieldEffectObj *effect, int hidden);
void FLDEFF_ENCOUNT_Init(FieldEffectObj *effect, EncountWork *work);
void FLDEFF_ENCOUNT_Exit(void);
void FLDEFF_ENCOUNT_Update(FieldEffectObj *effect, EncountWork *work);
void FLDEFF_ENCOUNT_PlaySound(EncountWork *work, EncountModelSet *set);
extern char sFldeffEncountFileName[];                           /* source file name for the heap allocator */
extern EncountModelDesc sEncountModelDescs[];               /* models and animations of each kind */
extern u8 sEncountResourceIndex[];                             /* effect resource index of each start selector */
extern const FieldEffectObjFuncs sEncountFuncs;        /* rustling-spot effect callbacks */
extern u8 sEncountVolumes[];                             /* sound volume of each strength step */
#include "../arm9/fx_mtx33.h"
extern G3dObjectStatus sEncounterDrawSlotStatus;                     /* draw status template of the slot object */

EncountModelSet *FLDEFF_ENCOUNT_CreateKind0(FieldEffectSys *fieldEffect, int heapId)
{
    return FLDEFF_ENCOUNT_Create(fieldEffect, heapId, 0);
}

EncountModelSet *FLDEFF_ENCOUNT_CreateKind1(FieldEffectSys *fieldEffect, int heapId)
{
    return FLDEFF_ENCOUNT_Create(fieldEffect, heapId, 1);
}

EncountModelSet *FLDEFF_ENCOUNT_CreateKind2(FieldEffectSys *fieldEffect, int heapId)
{
    return FLDEFF_ENCOUNT_Create(fieldEffect, heapId, 2);
}

EncountModelSet *FLDEFF_ENCOUNT_CreateKind3(FieldEffectSys *fieldEffect, int heapId)
{
    return FLDEFF_ENCOUNT_Create(fieldEffect, heapId, 3);
}

EncountModelSet *FLDEFF_ENCOUNT_CreateKind4(FieldEffectSys *fieldEffect, int heapId)
{
    return FLDEFF_ENCOUNT_Create(fieldEffect, heapId, 4);
}

EncountModelSet *FLDEFF_ENCOUNT_CreateKind5(FieldEffectSys *fieldEffect, int heapId)
{
    return FLDEFF_ENCOUNT_Create(fieldEffect, heapId, 5);
}

/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void FLDEFF_ENCOUNT_Delete(FieldEffectSys *fieldEffect, EncountModelSet *set)
{
    FLDEFF_ENCOUNT_FreeResources(set);
    GFL_HEAP_Free(set);
}

/* Creates the resources of one kind of the rustling-spot effect. */
EncountModelSet *FLDEFF_ENCOUNT_Create(FieldEffectSys *fieldEffect, int heapId, u32 kind)
{
    EncountModelSet *set;

    set = GFL_HEAP_Alloc(heapId, 0x98, 1, sFldeffEncountFileName, 0x11e);
    set->fieldEffect = fieldEffect;
    FLDEFF_ENCOUNT_LoadKind(set, kind);
    return set;
}

void FLDEFF_ENCOUNT_LoadKind(EncountModelSet *set, u32 kind)
{
    ArcHandle *arc;

    set->desc = sEncountModelDescs[kind];
    arc = FIELD_EFFECT_GetArcHandle(set->fieldEffect);
    if (kind == 0) {
        FLDEFF_ENCOUNT_LoadKind0Models(set, &set->desc, arc);
    } else {
        FLDEFF_ENCOUNT_LoadModels(set, &set->desc, arc);
    }
}

/*
 * Lever: G3D_SYSTEM_CreateObject takes three arguments (see UNION_EFF_CreateAnimObj); the
 * third is set->desc.animeCount, which is what keeps the loop bound in r2.
 */
/* Builds the render, animations and object of one model. */
void FLDEFF_ENCOUNT_BuildDrawSet(EncountDrawSet *draw, EncountModelSet *set, int modelIndex)
{
    int i = 0;

    draw->render = G3D_SYSTEM_CreateRender(set->model[modelIndex], 0, set->model[modelIndex]);
    for (; i < set->desc.animeCount; i++)
        draw->anime[i] = G3D_SYSTEM_CreateAnime(draw->render, set->anime[modelIndex * set->desc.animeCount + i], 0);
    draw->object = G3D_SYSTEM_CreateObject(draw->render, draw->anime, set->desc.animeCount);
    for (i = 0; i < set->desc.animeCount; i++)
        G3D_SYSTEM_EnableObjectAnime(draw->object, (u16)i);
}

void FLDEFF_ENCOUNT_DeleteDrawSet(EncountDrawSet *draw, EncountModelSet *set)
{
    int i;

    for (i = 0; i < set->desc.animeCount; i++)
        G3D_SYSTEM_DeleteAnime(draw->anime[i]);
    G3D_SYSTEM_DeleteObject(draw->object);
    G3D_SYSTEM_DeleteRender(draw->render);
}

/* Loads the models of kind 0: the first with the base offset, the second one stride on, the last without. */
void FLDEFF_ENCOUNT_LoadKind0Models(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc)
{
    int offset;

    offset = FIELD_EFFECT_GetModelBaseOffset(set->fieldEffect);
    set->model[0] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->modelFile + offset);
    G3D_SYSTEM_TransVramTexture(set->model[0]);
    set->anime[0] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->animeFile[0] + offset);
    FLDEFF_ENCOUNT_BuildDrawSet(&set->draw[0], set, 0);
    offset += desc->modelStride;
    set->model[1] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->modelFile + offset);
    G3D_SYSTEM_TransVramTexture(set->model[1]);
    set->anime[1] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->animeFile[0] + offset);
    FLDEFF_ENCOUNT_BuildDrawSet(&set->draw[1], set, 1);
    set->model[2] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->modelFile);
    G3D_SYSTEM_TransVramTexture(set->model[2]);
    set->anime[2] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->animeFile[0]);
    FLDEFF_ENCOUNT_BuildDrawSet(&set->draw[2], set, 2);
}

/* Loads the models and animations of any other kind. */
void FLDEFF_ENCOUNT_LoadModels(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc)
{
    int base;
    int i;
    int j;
    int fileOffset;

    base = 0;
    if (desc->useBaseOffset) {
        base = FIELD_EFFECT_GetModelBaseOffset(set->fieldEffect);
    } else if (desc->useBaseOffsetAlt) {
        base = FIELD_EFFECT_GetModelBaseOffsetAlt(set->fieldEffect);
    }
    for (i = 0; i < desc->modelCount; i++) {
        fileOffset = base + i * desc->modelStride;
        set->model[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, desc->modelFile + fileOffset);
        G3D_SYSTEM_TransVramTexture(set->model[i]);
        for (j = 0; j < desc->animeCount; j++) {
            set->anime[i * desc->animeCount + j] = G3D_SYSTEM_CreateResourceArcHandle(arc, fileOffset + desc->animeFile[j]);
        }
        FLDEFF_ENCOUNT_BuildDrawSet(&set->draw[i], set, (u8)i);
    }
}

void FLDEFF_ENCOUNT_FreeResources(EncountModelSet *set)
{
    int i;

    for (i = 0; i < set->desc.modelCount; i++) {
        FLDEFF_ENCOUNT_DeleteDrawSet(&set->draw[i], set);
    }
    for (i = 0; i < set->desc.animeCount * set->desc.modelCount; i++) {
        G3D_SYSTEM_DeleteResource(set->anime[i]);
    }
    for (i = 0; i < set->desc.modelCount; i++) {
        G3D_SYSTEM_FreeVramTexture(set->model[i]);
        G3D_SYSTEM_DeleteResource(set->model[i]);
    }
}

/* Starts a rustling-spot effect on a tile; returns 0 when the map type or the resource does not allow it. */
FieldEffectObj *FLDEFF_ENCOUNT_Start(EncountSys *encount, FieldEffectSys *fieldEffect, int gridX, int gridZ, int y, int setIndex)
{
    FieldMap *fieldMap;
    int kind;
    EncountModelSet *res;
    EncountStartParam param;

    fieldMap = (struct FieldMap *)FIELD_EFFECT_GetFieldMap(fieldEffect);
    if (FIELDMAP_GetMoveKind(fieldMap) != 0) {
        return 0;
    }
    kind = sEncountResourceIndex[setIndex];
    res = (struct EncountModelSet *)FIELD_EFFECT_GetResource(fieldEffect, kind + FLDEFF_ID_ENCOUNT_FIRST);
    if (res == 0) {
        return 0;
    }
    MI_CpuFill8(&param, 0, 0x28);
    param.encount = encount;
    param.res = res;
    param.mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    param.gridX = gridX;
    param.gridZ = gridZ;
    param.kind = kind;
    if (kind == 0) {
        param.setIndex = setIndex;
    } else {
        param.setIndex = 0;
    }
    param.pos.x = (gridX << 16) + 0x8000;
    param.pos.z = (gridZ << 16) + 0x8000;
    param.pos.y = y;
    return FIELD_EFFECT_AddObject(fieldEffect, &sEncountFuncs, 0, 1, &param, 0);
}

void FLDEFF_ENCOUNT_SetPaused(FieldEffectObj *effect, int paused)
{
    if (effect != 0)
        ((EncountWork *)FIELD_EFFECT_GetObjectWork(effect))->paused = paused;
}

void FLDEFF_ENCOUNT_SetDrawHidden(FieldEffectObj *effect, int hidden)
{
    if (effect != 0)
        ((EncountWork *)FIELD_EFFECT_GetObjectWork(effect))->drawHidden = hidden;
}

/* Rustling-spot effect init. */
void FLDEFF_ENCOUNT_Init(FieldEffectObj *effect, EncountWork *work)
{
    EncountStartParam *param = FIELD_EFFECT_GetObjectParam(effect);

    work->encount = param->encount;
    work->param = *param;
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
    if (FIELD_EFFECT_GetObjectMode(effect) == 0) {
        work->modeIsZero = 1;
    }
    FIELD_EFFECT_UpdateObject(effect);
}

void FLDEFF_ENCOUNT_Exit(void) {}

/* Rustling-spot effect update: while the map is ready and not paused, plays the sound and advances the animations. */
void FLDEFF_ENCOUNT_Update(FieldEffectObj *effect, EncountWork *work)
{
    int i;
    EncountModelSet *set = work->param.res;

    if (FIELDMAP_IsReady((struct FieldMap *)FIELD_EFFECT_GetFieldMap(set->fieldEffect)) != 0 && work->paused == 0) {
        FLDEFF_ENCOUNT_PlaySound(work, set);
        for (i = 0; i < set->desc.animeCount; i++) {
            G3D_SYSTEM_LoopObjectAnimeFrame(set->draw[work->param.setIndex].object, (u16)i, 0x1000);
        }
    }
}

/*
 * Levers: G3D_SYSTEM_GetObjectAnimeFrame's second parameter is an index (the zero stored to
 * strength is passed in r1), not &strength; the final call's arguments are named
 * locals with the inner call bound to a local after them, which keeps both
 * loads above the call in callee-saved registers.
 */
/* Plays the sound of the spot, louder for a higher strength, when the animation is at its start. */
void FLDEFF_ENCOUNT_PlaySound(EncountWork *work, EncountModelSet *set)
{
    u16 strength;
    int frame;
    u8 volume;
    u16 seId;
    SoundSys *soundSys;

    strength = 0;
    G3D_SYSTEM_GetObjectAnimeFrame(set->draw[work->param.setIndex].object, 0, &frame);
    if (frame == 0 && EFFECT_ENCOUNT_GetSpotDistance((struct FieldEncount *)work->encount, (short *)&strength) != 0) {
        strength = strength / 5;
        if (strength > 3)
            strength = 3;
        volume = sEncountVolumes[strength];
        seId = set->desc.seId;
        soundSys = (struct SoundSys *)GAME_DATA_GetBgmInfo((struct GameData *)work->encount->gameData);
        FIELD_SOUND_SYSTEM_ClaimSlotWithOwner((struct FieldSoundSystem *)soundSys, seId, volume);
    }
}


/* Draw of the effect object that shows one object of the slot table. */
void FLDEFF_ENCOUNT_DrawSlotObject(FieldEffectObj *effect, EncountWork *work)
{
    G3dObjectStatus status = sEncounterDrawSlotStatus;
    EncountModelSet *set = work->param.res;

    if (work->drawHidden == 0) {
        MTX_Identity33_(&status.rotate);
        FIELD_EFFECT_GetObjectPos(effect, &status.trans);
        G3D_SYSTEM_DrawObjectCulling(set->draw[work->param.setIndex].object, &status);
    }
}
