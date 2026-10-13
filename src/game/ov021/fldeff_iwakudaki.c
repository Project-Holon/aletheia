/*
 * file:     fldeff_iwakudaki.c
 * unit:     yes
 * function: func_021ADCB8, func_021ADCDC, func_021ADCF0, func_021ADD38, func_021ADD64, func_021ADD7C, func_021ADDE8, func_021ADE4C, func_021ADE70, func_021ADEA0
 * address:  0x021ADCB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DE10C  0x021DE10C  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02047180  0x02047180  arm
 *   func_020056A0  0x020056A0  thumb
 *   d_021DE0FC     0x021DE0FC  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9290     0x021D9290  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D92A4  0x021D92A4  data
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02030734  0x02030734  arm
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

/* Id of the Rock Smash resources in the field effect system. */
#define FLDEFF_ID_IWAKUDAKI 10

#define IWAKUDAKI_ANIME_COUNT 4

/* File of the model in the effect archive. */
#define IWAKUDAKI_MODEL_FILE 0x4d

/* Offset of the effect from the smashed rock's model position. */
#define IWAKUDAKI_OFFSET_Y 0x1000
#define IWAKUDAKI_OFFSET_Z 0xc000

/* Fixed-point step added to the animation frame each update (one frame). */
#define IWAKUDAKI_ANIME_STEP 0x1000

/* Resources of the Rock Smash effect (allocated 0x20 bytes by func_021ADCB8). */
typedef struct IwakudakiRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model;                            /* 0x04 */
    G3dResource *anime[IWAKUDAKI_ANIME_COUNT];     /* 0x08 */
    void *uploadTask;                              /* 0x18 uploads the textures once */
    u32 texturesUploaded;                          /* 0x1C */
} IwakudakiRes;

/* Start parameter of the effect. */
typedef struct IwakudakiStartParam {
    IwakudakiRes *res;
    VecFx32 pos;
} IwakudakiStartParam;

/* Work of the Rock Smash effect: four animations of one model that play to their end. */
typedef struct IwakudakiWork {
    IwakudakiRes *res;                             /* 0x00 */
    G3dObject *object;                             /* 0x04 */
    G3dAnime *anime[IWAKUDAKI_ANIME_COUNT];        /* 0x08 */
    G3dRender *render;                             /* 0x18 */
} IwakudakiWork;

/* Position of a model on the map grid. */
typedef struct GridPos {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
} GridPos;

typedef int (*TrainerEyeSightFunc)(int range, const GridPos *trainerPos, const GridPos *targetPos);

extern void func_0207ADC4(MtxFx33 *mtx);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern int func_02047AC8(G3dObject *obj, G3dObjectStatus *status);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern G3dResource *func_02046E24(ArcHandle *arc, u32 fileId);
extern int func_02047180(G3dResource *res);
extern void *func_020056A0(void (*func)(void *task, void *work), void *work, int priority);
extern void func_02046EFC(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern void func_02030EAC(void *task);
extern int func_02047204(G3dResource *res);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern int func_021ABE8C(FieldEffectSys *fieldEffect, int effectId);
extern void func_021ABE30(FieldEffectSys *fieldEffect, int *effectIds, int count);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern void func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
extern void func_021AC154(FieldEffectObj *effect);
extern G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 func_020477A4(G3dObject *obj, u32 anmIdx);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);
extern int func_020478B8(G3dObject *obj, int anmIdx, fx32 step);

IwakudakiRes *func_021ADCB8(FieldEffectSys *fieldEffect, u32 heapId);
void func_021ADCDC(FieldEffectSys *fieldEffect, IwakudakiRes *res);
void func_021ADCF0(IwakudakiRes *res);
void func_021ADD38(IwakudakiRes *res);
void func_021ADD64(void *task, void *work);
void func_021ADD7C(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void func_021ADDE8(FieldEffectObj *effect, IwakudakiWork *work);
void func_021ADE4C(void *task, IwakudakiWork *work);
void func_021ADE70(FieldEffectObj *effect, IwakudakiWork *work);
void func_021ADEA0(FieldEffectObj *effect, IwakudakiWork *work);

extern char d_021DE10C[];                              /* source file name for the heap allocator */
extern int d_021DE0FC[IWAKUDAKI_ANIME_COUNT];          /* animation file ids */
extern const FieldEffectObjFuncs d_021D9290;           /* Rock Smash effect callbacks */
extern G3dObjectStatus d_021D92A4;                     /* draw status template */

/* ------------------------------------------------------------------ */
/* fldeff_iwakudaki.c                                                  */
/* ------------------------------------------------------------------ */

/* Loads the resources of the Rock Smash effect. */
IwakudakiRes *func_021ADCB8(FieldEffectSys *fieldEffect, u32 heapId)
{
    IwakudakiRes *res = func_02030734(heapId, 0x20, 1, d_021DE10C, 0x67);
    res->fieldEffect = fieldEffect;
    func_021ADCF0(res);
    return res;
}

void func_021ADCDC(FieldEffectSys *fieldEffect, IwakudakiRes *res)
{
    func_021ADD38(res);
    func_020307B0(res);
}

void func_021ADCF0(IwakudakiRes *res)
{
    ArcHandle *arc = func_021ABE24(res->fieldEffect);
    int i;

    res->model = func_02046E24(arc, IWAKUDAKI_MODEL_FILE);
    func_02047180(res->model);
    res->uploadTask = func_020056A0(func_021ADD64, res, 0);
    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        res->anime[i] = func_02046E24(arc, d_021DE0FC[i]);
}

void func_021ADD38(IwakudakiRes *res)
{
    int i;

    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        func_02046EFC(res->anime[i]);
    func_020470D0(res->model);
    func_02046EFC(res->model);
    func_02030EAC(res->uploadTask);
}

/* Task: uploads the model textures to VRAM once. */
void func_021ADD64(void *task, void *work)
{
    IwakudakiRes *res = work;

    if (res->texturesUploaded == 0) {
        func_02047204(res->model);
        res->texturesUploaded = 1;
    }
}

/* Starts the effect at the model position. */
void func_021ADD7C(const Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    VecFx32 pos;
    IwakudakiStartParam param;
    int effectId;

    func_0216D88C(mmdl, &pos);
    pos.y += IWAKUDAKI_OFFSET_Y;
    pos.z += IWAKUDAKI_OFFSET_Z;
    if (func_021ABE8C(fieldEffect, FLDEFF_ID_IWAKUDAKI) == 0) {
        effectId = FLDEFF_ID_IWAKUDAKI;
        func_021ABE30(fieldEffect, &effectId, 1);
    }
    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_IWAKUDAKI);
    param.pos = pos;
    func_021ABFA8(fieldEffect, &d_021D9290, 0, 0, &param, 0);
}

/* Effect init. */
void func_021ADDE8(FieldEffectObj *effect, IwakudakiWork *work)
{
    IwakudakiStartParam *param = func_021AC1AC(effect);
    int i;

    work->res = param->res;
    func_021AC1CC(effect, &param->pos);
    work->render = func_02047400(work->res->model, 0, work->res->model);
    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        work->anime[i] = func_02047564(work->render, work->res->anime[i], 0);
    work->object = func_0204767C(work->render, work->anime, IWAKUDAKI_ANIME_COUNT);
    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        func_020477A4(work->object, (u16)i);
}

/* Effect exit. */
void func_021ADE4C(void *task, IwakudakiWork *work)
{
    int i;

    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        func_0204762C(work->anime[i]);
    func_02047738(work->object);
    func_02047504(work->render);
}

/* Effect update: advances the animations and ends the effect when all are done. */
void func_021ADE70(FieldEffectObj *effect, IwakudakiWork *work)
{
    int done = 1;
    int i;

    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++) {
        if (func_020478B8(work->object, (u16)i, IWAKUDAKI_ANIME_STEP) == 1)
            done = 0;
    }
    if (done)
        func_021AC154(effect);
}

/* Effect draw. */
void func_021ADEA0(FieldEffectObj *effect, IwakudakiWork *work)
{
    G3dObjectStatus status = d_021D92A4;

    func_0207ADC4(&status.rotate);
    func_021AC1B8(effect, &status.trans);
    func_02047AC8(work->object, &status);
}
