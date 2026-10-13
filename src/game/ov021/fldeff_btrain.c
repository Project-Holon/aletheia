/*
 * file:     fldeff_btrain.c
 * unit:     yes
 * function: func_021D0140, func_021D0160, func_021D0174, func_021D01D8, func_021D0218, func_021D024C, func_021D028C, func_021D029C, func_021D0308, func_021D0328, func_021D034C
 * address:  0x021D0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021D0140 (lane L136, __FILE__ anchor fldeff_btrain.c at 021D0140 (d_021DE608); callback table g_021DB8DC targets 029C/0308/0328/034C).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DE608     0x021DE608  data  ov021  a4
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   data_021DB8C4  0x021DB8C4  data  a2
 *   data_021DB8CC  0x021DB8CC  data  a2
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021DB8DC     0x021DB8DC  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb
 *   func_02047804  0x02047804  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_020478B8  0x020478B8  arm
 *   data_021DB8F0  0x021DB8F0  data  ov021  a4
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 */
#include "../ov010/fldmmdl_types.h"
#include "field_effect_types.h"

/* Opaque types of other files. */
typedef struct MtxFx33 { fx32 m[3][3]; } MtxFx33;
typedef struct ArcHandle ArcHandle;
typedef struct G3dResource G3dResource;                 /* layouts in arm9/g3d_system_types.h */
typedef struct G3dRender G3dRender;
typedef struct G3dAnime G3dAnime;
typedef struct G3dObject G3dObject;

/* Position, scale and rotation an object is drawn with. */
typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;

/* Id of the Battle Subway train resources in the field effect system. */
#define FLDEFF_ID_BTRAIN 14

/* Train models (one per train kind) and animations shared by all of them. */
#define BTRAIN_MODEL_COUNT 8
#define BTRAIN_ANIME_COUNT 4

/* Animation index of the work while no animation is selected. */
#define BTRAIN_ANIME_NONE BTRAIN_ANIME_COUNT

/* Fixed-point step added to the animation frame each update (one frame). */
#define BTRAIN_ANIME_STEP 0x1000

/* Resources of the train effect (allocated 0x54 bytes by func_021D0140). The models load one by one. */
typedef struct BtrainRes {
    FieldEffectSys *fieldEffect;                    /* 0x00 */
    G3dResource *model[BTRAIN_MODEL_COUNT];         /* 0x04 */
    G3dResource *anime[BTRAIN_ANIME_COUNT];         /* 0x24 */
    G3dRender *render[BTRAIN_MODEL_COUNT];          /* 0x34 */
} BtrainRes;

/* Start parameter of the effect. */
typedef struct BtrainStartParam {
    BtrainRes *res;
    u32 modelIndex;                                 /* train kind */
} BtrainStartParam;

/* Work of the train effect (0x20 bytes, the first word of the callback table). */
typedef struct BtrainWork {
    u8 pad00;
    u8 hidden;                                      /* 0x01 1 = not drawn */
    u8 animeIndex;                                  /* 0x02 playing animation, BTRAIN_ANIME_NONE = none */
    u8 animeFinished;                               /* 0x03 1 = the playing animation reached its end */
    BtrainStartParam param;                         /* 0x04 */
    G3dObject *object;                              /* 0x0C */
    G3dAnime *anime[BTRAIN_ANIME_COUNT];            /* 0x10 */
} BtrainWork;

extern void func_0207ADC4(MtxFx33 *mtx);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern int func_02047AC8(G3dObject *obj, G3dObjectStatus *status);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern G3dResource *func_02046E24(ArcHandle *arc, u32 fileId);
extern int func_02046FF8(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern void func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *func_021AC1E0(FieldEffectObj *effect);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 func_02047804(G3dObject *obj, u16 anmIdx);
extern u32 func_020477A4(G3dObject *obj, u32 anmIdx);
extern int func_020477D4(G3dObject *obj, u32 anmIdx);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);
extern int func_020478B8(G3dObject *obj, int anmIdx, fx32 step);

BtrainRes *func_021D0140(FieldEffectSys *fieldEffect, u32 heapId);
void func_021D0160(FieldEffectSys *fieldEffect, BtrainRes *res);
void func_021D0174(BtrainRes *res, int modelIndex);
void func_021D01D8(BtrainRes *res);
void func_021D0218(FieldEffectSys *fieldEffect, u32 modelIndex, const VecFx32 *pos);
void func_021D024C(FieldEffectObj *effect, u32 animeIndex);
void func_021D028C(FieldEffectObj *effect, u32 hidden);
void func_021D029C(FieldEffectObj *effect, BtrainWork *work);
void func_021D0308(FieldEffectObj *effect, BtrainWork *work);
void func_021D0328(FieldEffectObj *effect, BtrainWork *work);
void func_021D034C(FieldEffectObj *effect, BtrainWork *work);

extern char d_021DE608[];                              /* source file name for the heap allocator */
extern const u16 data_021DB8CC[BTRAIN_MODEL_COUNT];    /* model file ids */
extern const u16 data_021DB8C4[BTRAIN_ANIME_COUNT];    /* animation file ids */
extern const FieldEffectObjFuncs d_021DB8DC;           /* train effect callbacks */
extern const G3dObjectStatus data_021DB8F0;            /* draw status template */

/* ------------------------------------------------------------------ */
/* fldeff_btrain.c                                                     */
/* ------------------------------------------------------------------ */

/* Allocates the resources of the Battle Subway train effect; nothing loads yet. */
BtrainRes *func_021D0140(FieldEffectSys *fieldEffect, u32 heapId)
{
    BtrainRes *res = func_02030734(heapId, sizeof(BtrainRes), 1, d_021DE608, 0x5f);

    res->fieldEffect = fieldEffect;
    return res;
}

void func_021D0160(FieldEffectSys *fieldEffect, BtrainRes *res)
{
    func_021D01D8(res);
    func_020307B0(res);
}

/* Loads the model of one train kind (once) and the shared animations. */
void func_021D0174(BtrainRes *res, int modelIndex)
{
    ArcHandle *arc;
    const u16 *modelFile;
    const u16 *animeFile;
    int i;

    arc = func_021ABE24(res->fieldEffect);
    modelFile = data_021DB8CC;
    if (res->model[modelIndex] == 0) {
        res->model[modelIndex] = func_02046E24(arc, modelFile[modelIndex]);
        func_02046FF8(res->model[modelIndex]);
        res->render[modelIndex] = func_02047400(res->model[modelIndex], 0, res->model[modelIndex]);
    }
    animeFile = data_021DB8C4;
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++, animeFile++) {
        if (res->anime[i] == 0) {
            res->anime[i] = func_02046E24(arc, *animeFile);
        }
    }
}

void func_021D01D8(BtrainRes *res)
{
    int i;

    for (i = 0; i < BTRAIN_MODEL_COUNT; i++) {
        if (res->model[i] != 0) {
            func_02047504(res->render[i]);
            func_020470D0(res->model[i]);
            func_02046EFC(res->model[i]);
        }
    }
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++) {
        if (res->anime[i] != 0) {
            func_02046EFC(res->anime[i]);
        }
    }
}

/* Starts the train effect of one train kind at pos. */
void func_021D0218(FieldEffectSys *fieldEffect, u32 modelIndex, const VecFx32 *pos)
{
    BtrainStartParam param;

    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_BTRAIN);
    param.modelIndex = modelIndex;
    func_021D0174(param.res, modelIndex);
    func_021ABFA8(fieldEffect, &d_021DB8DC, pos, 0, &param, 0);
}

/*
 * Selects the animation of the train (the doors, see the Battle Subway script
 * command) and restarts it. A null effect is ignored.
 */
void func_021D024C(FieldEffectObj *effect, u32 animeIndex)
{
    int i;
    BtrainWork *work;

    if (effect == 0)
        return;
    work = func_021AC1E0(effect);
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++) {
        func_02047804(work->object, (u16)i);
        if (i == animeIndex)
            func_020477A4(work->object, (u16)i);
        else
            func_020477D4(work->object, (u16)i);
    }
    work->animeIndex = animeIndex;
    work->animeFinished = 0;
}

/* Shows or hides the train. A null effect is ignored. */
void func_021D028C(FieldEffectObj *effect, u32 hidden)
{
    if (effect != 0)
        ((BtrainWork *)func_021AC1E0(effect))->hidden = hidden;
}

/* Effect init: one animation object per animation, all disabled. */
void func_021D029C(FieldEffectObj *effect, BtrainWork *work)
{
    BtrainStartParam *param = func_021AC1AC(effect);
    BtrainRes *res;
    int modelIndex;
    int j;
    int i;

    work->param = *param;
    res = work->param.res;
    modelIndex = work->param.modelIndex;
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++)
        work->anime[i] = func_02047564(res->render[modelIndex], res->anime[i], 0);
    work->animeIndex = BTRAIN_ANIME_NONE;
    work->object = func_0204767C(res->render[modelIndex], work->anime, BTRAIN_ANIME_COUNT);
    for (j = 0; j < BTRAIN_ANIME_COUNT; j++)
        func_020477D4(work->object, (u16)j);
}

/* Effect exit. */
void func_021D0308(FieldEffectObj *effect, BtrainWork *work)
{
    int i;

    func_02047738(work->object);
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++) {
        func_0204762C(work->anime[i]);
    }
}

/* Effect update: plays the selected animation and notes when it ends. */
void func_021D0328(FieldEffectObj *effect, BtrainWork *work)
{
    if (work->animeIndex != BTRAIN_ANIME_NONE) {
        work->animeFinished = 0;
        if (func_020478B8(work->object, work->animeIndex, BTRAIN_ANIME_STEP) == 0) {
            work->animeFinished = 1;
        }
    }
}

/* Effect draw. */
void func_021D034C(FieldEffectObj *effect, BtrainWork *work)
{
    G3dObjectStatus status;

    if (work->hidden == 0) {
        status = data_021DB8F0;
        func_0207ADC4(&status.rotate);
        func_021AC1B8(effect, &status.trans);
        func_02047AC8(work->object, &status);
    }
}
