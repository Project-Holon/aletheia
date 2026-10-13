/*
 * file:     fldeff_encount.c
 * unit:     yes
 * function: func_021AD758, func_021AD764, func_021AD770, func_021AD77C, func_021AD788, func_021AD794, func_021AD7A0, func_021AD7B4, func_021AD7E4, func_021AD82C, func_021AD8A4, func_021AD8DC, func_021AD96C, func_021ADA1C, func_021ADAAC, func_021ADB4C, func_021ADB5C, func_021ADB6C, func_021ADBAC, func_021ADBB0, func_021ADC04, func_021ADC6C
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021DE0E8  0x021DE0E8  data
 *   d_021DE094     0x021DE094  data  a2
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_021ABE2C  0x021ABE2C  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   d_021D9238     0x021D9238  data  a1
 *   d_021D9240     0x021D9240  data  a4
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   func_02047828  0x02047828  arm
 *   func_021AAA4C  0x021AAA4C  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   d_021D9234     0x021D9234  data   a1
 */
#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

typedef struct MtxFx33 { fx32 m[3][3]; } MtxFx33;

/* Opaque types of other files. */
typedef struct ArcHandle ArcHandle;
typedef struct FieldMap FieldMap;                       /* field map (fieldmap.c) */
typedef struct FieldEffectSys FieldEffectSys;           /* field effect system (field_effect.c) */
typedef struct FieldEffectObj FieldEffectObj;           /* one running effect (field_effect.c) */
typedef struct FieldEffectObjFuncs FieldEffectObjFuncs; /* callback table: work size, init, exit, update, draw */
typedef struct G3dResource G3dResource;                 /* layouts in arm9/g3d_system_types.h */
typedef struct G3dRender G3dRender;
typedef struct G3dAnime G3dAnime;
typedef struct G3dObject G3dObject;
typedef struct SoundSys SoundSys;

/* Position, scale and rotation a field 3D object is drawn with. */
typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern FieldMap *func_021ABE14(FieldEffectSys *fieldEffect);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern u8 func_021ABE28(FieldEffectSys *fieldEffect);
extern u8 func_021ABE2C(FieldEffectSys *fieldEffect);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern FieldEffectObj *func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void func_021AC178(FieldEffectObj *effect);
extern int func_021AC1A0(FieldEffectObj *effect);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
extern void *func_021AC1E0(FieldEffectObj *effect);
extern G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 func_020477A4(G3dObject *obj, u32 anmIdx);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);
extern G3dResource *func_02046E24(ArcHandle *arc, u32 fileId);
extern int func_02046FF8(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern int func_02188CFC(FieldMap *fieldMap);
extern void *func_02188C7C(FieldMap *fieldMap);
extern int func_02188BE8(FieldMap *fieldMap);
extern void *func_02082BCC(void *dst, u8 value, unsigned size);
extern int func_02047910(G3dObject *obj, int anmIdx, int step);
extern u32 func_02047828(G3dObject *obj, u32 anmIdx, s32 *frame);
extern int func_021AAA4C(EncountSys *encount, short *out);
extern u16 func_0209C0A4(int a, int b);
extern SoundSys *func_02012A30(const void *gameData);
extern void func_02028ACC(SoundSys *soundSys, u32 id, u32 volume);

EncountModelSet *func_021AD758(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *func_021AD764(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *func_021AD770(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *func_021AD77C(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *func_021AD788(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *func_021AD794(FieldEffectSys *fieldEffect, int heapId);
void func_021AD7A0(FieldEffectSys *fieldEffect, EncountModelSet *set);
EncountModelSet *func_021AD7B4(FieldEffectSys *fieldEffect, int heapId, u32 kind);
void func_021AD7E4(EncountModelSet *set, u32 kind);
void func_021AD82C(EncountDrawSet *draw, EncountModelSet *set, int modelIndex);
void func_021AD8A4(EncountDrawSet *draw, EncountModelSet *set);
void func_021AD8DC(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc);
void func_021AD96C(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc);
void func_021ADA1C(EncountModelSet *set);
FieldEffectObj *func_021ADAAC(EncountSys *encount, FieldEffectSys *fieldEffect, int gridX, int gridZ, int y, int setIndex);
void func_021ADB4C(FieldEffectObj *effect, int paused);
void func_021ADB5C(FieldEffectObj *effect, int hidden);
void func_021ADB6C(FieldEffectObj *effect, EncountWork *work);
void func_021ADBAC(void);
void func_021ADBB0(FieldEffectObj *effect, EncountWork *work);
void func_021ADC04(EncountWork *work, EncountModelSet *set);
extern char d_021DE0E8[];                           /* source file name for the heap allocator */
extern EncountModelDesc d_021DE094[];               /* models and animations of each kind */
extern u8 d_021D9238[];                             /* effect resource index of each start selector */
extern const FieldEffectObjFuncs d_021D9240;        /* rustling-spot effect callbacks */
extern u8 d_021D9234[];                             /* sound volume of each strength step */
extern void func_0207ADC4(MtxFx33 *mtx);
extern int func_02047AC8(G3dObject *obj, G3dObjectStatus *status);
extern G3dObjectStatus d_021D9254;                     /* draw status template of the slot object */

EncountModelSet *func_021AD758(FieldEffectSys *fieldEffect, int heapId)
{
    return func_021AD7B4(fieldEffect, heapId, 0);
}

EncountModelSet *func_021AD764(FieldEffectSys *fieldEffect, int heapId)
{
    return func_021AD7B4(fieldEffect, heapId, 1);
}

EncountModelSet *func_021AD770(FieldEffectSys *fieldEffect, int heapId)
{
    return func_021AD7B4(fieldEffect, heapId, 2);
}

EncountModelSet *func_021AD77C(FieldEffectSys *fieldEffect, int heapId)
{
    return func_021AD7B4(fieldEffect, heapId, 3);
}

EncountModelSet *func_021AD788(FieldEffectSys *fieldEffect, int heapId)
{
    return func_021AD7B4(fieldEffect, heapId, 4);
}

EncountModelSet *func_021AD794(FieldEffectSys *fieldEffect, int heapId)
{
    return func_021AD7B4(fieldEffect, heapId, 5);
}

/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD7A0(FieldEffectSys *fieldEffect, EncountModelSet *set)
{
    func_021ADA1C(set);
    func_020307B0(set);
}

/* Creates the resources of one kind of the rustling-spot effect. */
EncountModelSet *func_021AD7B4(FieldEffectSys *fieldEffect, int heapId, u32 kind)
{
    EncountModelSet *set;

    set = func_02030734(heapId, 0x98, 1, d_021DE0E8, 0x11e);
    set->fieldEffect = fieldEffect;
    func_021AD7E4(set, kind);
    return set;
}

void func_021AD7E4(EncountModelSet *set, u32 kind)
{
    ArcHandle *arc;

    set->desc = d_021DE094[kind];
    arc = func_021ABE24(set->fieldEffect);
    if (kind == 0) {
        func_021AD8DC(set, &set->desc, arc);
    } else {
        func_021AD96C(set, &set->desc, arc);
    }
}

/*
 * Lever: func_0204767C takes three arguments (see ov019_func_0217FA10); the
 * third is set->desc.animeCount, which is what keeps the loop bound in r2.
 */
/* Builds the render, animations and object of one model. */
void func_021AD82C(EncountDrawSet *draw, EncountModelSet *set, int modelIndex)
{
    int i = 0;

    draw->render = func_02047400(set->model[modelIndex], 0, set->model[modelIndex]);
    for (; i < set->desc.animeCount; i++)
        draw->anime[i] = func_02047564(draw->render, set->anime[modelIndex * set->desc.animeCount + i], 0);
    draw->object = func_0204767C(draw->render, draw->anime, set->desc.animeCount);
    for (i = 0; i < set->desc.animeCount; i++)
        func_020477A4(draw->object, (u16)i);
}

void func_021AD8A4(EncountDrawSet *draw, EncountModelSet *set)
{
    int i;

    for (i = 0; i < set->desc.animeCount; i++)
        func_0204762C(draw->anime[i]);
    func_02047738(draw->object);
    func_02047504(draw->render);
}

/* Loads the models of kind 0: the first with the base offset, the second one stride on, the last without. */
void func_021AD8DC(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc)
{
    int offset;

    offset = func_021ABE28(set->fieldEffect);
    set->model[0] = func_02046E24(arc, desc->modelFile + offset);
    func_02046FF8(set->model[0]);
    set->anime[0] = func_02046E24(arc, desc->animeFile[0] + offset);
    func_021AD82C(&set->draw[0], set, 0);
    offset += desc->modelStride;
    set->model[1] = func_02046E24(arc, desc->modelFile + offset);
    func_02046FF8(set->model[1]);
    set->anime[1] = func_02046E24(arc, desc->animeFile[0] + offset);
    func_021AD82C(&set->draw[1], set, 1);
    set->model[2] = func_02046E24(arc, desc->modelFile);
    func_02046FF8(set->model[2]);
    set->anime[2] = func_02046E24(arc, desc->animeFile[0]);
    func_021AD82C(&set->draw[2], set, 2);
}

/* Loads the models and animations of any other kind. */
void func_021AD96C(EncountModelSet *set, EncountModelDesc *desc, ArcHandle *arc)
{
    int base;
    int i;
    int j;
    int fileOffset;

    base = 0;
    if (desc->useBaseOffset) {
        base = func_021ABE28(set->fieldEffect);
    } else if (desc->useBaseOffsetAlt) {
        base = func_021ABE2C(set->fieldEffect);
    }
    for (i = 0; i < desc->modelCount; i++) {
        fileOffset = base + i * desc->modelStride;
        set->model[i] = func_02046E24(arc, desc->modelFile + fileOffset);
        func_02046FF8(set->model[i]);
        for (j = 0; j < desc->animeCount; j++) {
            set->anime[i * desc->animeCount + j] = func_02046E24(arc, fileOffset + desc->animeFile[j]);
        }
        func_021AD82C(&set->draw[i], set, (u8)i);
    }
}

void func_021ADA1C(EncountModelSet *set)
{
    int i;

    for (i = 0; i < set->desc.modelCount; i++) {
        func_021AD8A4(&set->draw[i], set);
    }
    for (i = 0; i < set->desc.animeCount * set->desc.modelCount; i++) {
        func_02046EFC(set->anime[i]);
    }
    for (i = 0; i < set->desc.modelCount; i++) {
        func_020470D0(set->model[i]);
        func_02046EFC(set->model[i]);
    }
}

/* Starts a rustling-spot effect on a tile; returns 0 when the map type or the resource does not allow it. */
FieldEffectObj *func_021ADAAC(EncountSys *encount, FieldEffectSys *fieldEffect, int gridX, int gridZ, int y, int setIndex)
{
    FieldMap *fieldMap;
    int kind;
    EncountModelSet *res;
    EncountStartParam param;

    fieldMap = func_021ABE14(fieldEffect);
    if (func_02188CFC(fieldMap) != 0) {
        return 0;
    }
    kind = d_021D9238[setIndex];
    res = func_021ABEA0(fieldEffect, kind + FLDEFF_ID_ENCOUNT_FIRST);
    if (res == 0) {
        return 0;
    }
    func_02082BCC(&param, 0, 0x28);
    param.encount = encount;
    param.res = res;
    param.mmdlSys = func_02188C7C(fieldMap);
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
    return func_021ABFA8(fieldEffect, &d_021D9240, 0, 1, &param, 0);
}

void func_021ADB4C(FieldEffectObj *effect, int paused)
{
    if (effect != 0)
        ((EncountWork *)func_021AC1E0(effect))->paused = paused;
}

void func_021ADB5C(FieldEffectObj *effect, int hidden)
{
    if (effect != 0)
        ((EncountWork *)func_021AC1E0(effect))->drawHidden = hidden;
}

/* Rustling-spot effect init. */
void func_021ADB6C(FieldEffectObj *effect, EncountWork *work)
{
    EncountStartParam *param = func_021AC1AC(effect);

    work->encount = param->encount;
    work->param = *param;
    func_021AC1CC(effect, &param->pos);
    if (func_021AC1A0(effect) == 0) {
        work->modeIsZero = 1;
    }
    func_021AC178(effect);
}

void func_021ADBAC(void) {}

/* Rustling-spot effect update: while the map is ready and not paused, plays the sound and advances the animations. */
void func_021ADBB0(FieldEffectObj *effect, EncountWork *work)
{
    int i;
    EncountModelSet *set = work->param.res;

    if (func_02188BE8(func_021ABE14(set->fieldEffect)) != 0 && work->paused == 0) {
        func_021ADC04(work, set);
        for (i = 0; i < set->desc.animeCount; i++) {
            func_02047910(set->draw[work->param.setIndex].object, (u16)i, 0x1000);
        }
    }
}

/*
 * Levers: func_02047828's second parameter is an index (the zero stored to
 * strength is passed in r1), not &strength; the final call's arguments are named
 * locals with the inner call bound to a local after them, which keeps both
 * loads above the call in callee-saved registers.
 */
/* Plays the sound of the spot, louder for a higher strength, when the animation is at its start. */
void func_021ADC04(EncountWork *work, EncountModelSet *set)
{
    u16 strength;
    int frame;
    u8 volume;
    u16 seId;
    SoundSys *soundSys;

    strength = 0;
    func_02047828(set->draw[work->param.setIndex].object, 0, &frame);
    if (frame == 0 && func_021AAA4C(work->encount, (short *)&strength) != 0) {
        strength = func_0209C0A4(strength, 5);
        if (strength > 3)
            strength = 3;
        volume = d_021D9234[strength];
        seId = set->desc.seId;
        soundSys = func_02012A30(work->encount->gameData);
        func_02028ACC(soundSys, seId, volume);
    }
}


/* Draw of the effect object that shows one object of the slot table. */
void func_021ADC6C(FieldEffectObj *effect, EncountWork *work)
{
    G3dObjectStatus status = d_021D9254;
    EncountModelSet *set = work->param.res;

    if (work->drawHidden == 0) {
        func_0207ADC4(&status.rotate);
        func_021AC1B8(effect, &status.trans);
        func_02047AC8(set->draw[work->param.setIndex].object, &status);
    }
}
