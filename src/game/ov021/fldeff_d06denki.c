/*
 * file:     fldeff_d06denki.c
 * unit:     yes
 * function: func_021C8E68, func_021C8E8C, func_021C8EA0, func_021C8F38, func_021C8F7C, func_021C8FB8, func_021C8FDC, func_021C8FE0, func_021C8FF0, func_021C9064, func_021C909C, func_021C90AC, func_021C90D0, func_021C90E4, func_021C9164, func_021C9190, func_021C9208, func_021C9258, func_021C928C, func_021C92B0, func_021C9314, func_021C9334, func_021C9360
 * address:  0x021C8E68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C8E68: fldeff_d06denki.c __FILE__ anchor at 0x021C8E68.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   d_021DE544  0x021DE544  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DAB6C     0x021DAB6C  data  a4
 *   d_021DAB7C     0x021DAB7C  data  a4
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021DABA4  0x021DABA4  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0204784C  0x0204784C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047828  0x02047828  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DABCC     0x021DABCC  data  a4
 *   d_021DABB8  0x021DABB8  data  ov021  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_02047910  0x02047910  arm
 *   d_021DAC08     0x021DAC08  data  a4
 *   d_021DAB90  0x021DAB90  data  ov021  a4
 *   d_021DAC44  0x021DAC44  data  ov021  a4
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct VecFx32 { fx32 x, y, z; } VecFx32;
typedef struct MtxFx33 { fx32 m[3][3]; } MtxFx33;

/* Opaque types of other files. */
typedef struct ArcHandle ArcHandle;
typedef struct FieldEffectSys FieldEffectSys;           /* field effect system (field_effect.c) */
typedef struct FieldEffectObj FieldEffectObj;           /* one running effect (field_effect.c) */
typedef struct FieldEffectObjFuncs FieldEffectObjFuncs; /* callback table: unused, init, exit, update, draw */
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

/* Id of the D06 electric resources in the field effect system. */
#define FLDEFF_ID_D06DENKI 0xb

#define D06DENKI_MODEL_COUNT 4
#define D06DENKI_ANIME_COUNT 5

/* Sound effect of the spark. */
#define SE_D06DENKI_SPARK 0x6a2

/* Fixed-point step added to the animation frame each update (one frame). */
#define D06DENKI_ANIME_STEP 0x1000

/* D06DenkiSparkWork.state */
#define D06DENKI_SPARK_PLAYING  0
#define D06DENKI_SPARK_FINISHED 1

/* Files of the models and animations, read from data tables. */
typedef struct D06DenkiModelFiles { u32 fileId[D06DENKI_MODEL_COUNT]; } D06DenkiModelFiles;
typedef struct D06DenkiAnimeFiles { u32 fileId[D06DENKI_ANIME_COUNT]; } D06DenkiAnimeFiles;

/*
 * Resources shared by the three effects (0x34 bytes, allocated by
 * func_021C8E68). model[0] and anime[0] build the spark object; model[1],
 * anime[1], anime[2] and model[3] belong to the follow effect; model[2],
 * anime[3] and anime[4] belong to the pulse effect.
 */
typedef struct D06DenkiRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model[D06DENKI_MODEL_COUNT];      /* 0x04 */
    G3dResource *anime[D06DENKI_ANIME_COUNT];      /* 0x14 */
    G3dAnime *sparkAnime;                          /* 0x28 */
    G3dRender *sparkRender;                        /* 0x2C */
    G3dObject *sparkObject;                        /* 0x30 */
} D06DenkiRes;

/* Start parameter of the spark and pulse effects (0x10 bytes). */
typedef struct D06DenkiStartParam {
    D06DenkiRes *res;
    VecFx32 pos;
} D06DenkiStartParam;

/* Start parameter of the follow effect (0x14 bytes). */
typedef struct D06DenkiFollowParam {
    D06DenkiRes *res;
    VecFx32 pos;
    Mmdl *mmdl;                                    /* model the effect follows */
} D06DenkiFollowParam;

/* Work of the spark effect (0x0C bytes): plays the shared spark animation once. */
typedef struct D06DenkiSparkWork {
    D06DenkiRes *res;                              /* 0x00 */
    fx32 animeFrame;                               /* 0x04 */
    u32 state;                                     /* 0x08, D06DENKI_SPARK_* */
} D06DenkiSparkWork;

/* Work of the follow effect (0x3C bytes): two objects that track a model. */
typedef struct D06DenkiFollowWork {
    D06DenkiFollowParam param;                     /* 0x00, copy of the start parameter */
    u8 loopFrozen;                                 /* 0x14, set: the looping animation stops */
    u8 ending;                                     /* 0x15, set: the ending animation plays */
    u8 ended;                                      /* 0x16, set: the ending animation is done */
    u8 pad17;
    G3dObject *object;                             /* 0x18 */
    G3dAnime *anime[2];                            /* 0x1C, loop and ending animation */
    G3dRender *render;                             /* 0x24 */
    VecFx32 subPos;                                /* 0x28, position of the second object */
    G3dObject *subObject;                          /* 0x34 */
    G3dRender *subRender;                          /* 0x38 */
} D06DenkiFollowWork;

/* Work of the pulse effect (0x24 bytes): one animation that restarts when triggered. */
typedef struct D06DenkiPulseWork {
    D06DenkiStartParam param;                      /* 0x00, copy of the start parameter */
    u8 triggered;                                  /* 0x10, set: the second animation plays */
    u8 pad11[3];
    G3dObject *object;                             /* 0x14 */
    G3dAnime *anime[2];                            /* 0x18 */
    G3dRender *render;                             /* 0x20 */
} D06DenkiPulseWork;

extern void func_020061E4(u32 seNo);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern G3dResource *func_02046E24(ArcHandle *arc, u32 fileId);
extern int func_02046FF8(G3dResource *res);
extern G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 func_020477A4(G3dObject *obj, u32 anmIdx);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);
extern int func_020470D0(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern void func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
extern void func_021AC154(FieldEffectObj *effect);
extern u32 func_0204784C(G3dObject *obj, u16 anmIdx, const fx32 *frame);
extern int func_020478B8(G3dObject *obj, int anmIdx, fx32 step);
extern u32 func_02047828(G3dObject *obj, u32 anmIdx, fx32 *frame);
extern void func_0207ADC4(MtxFx33 *mtx);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern int func_02047AC8(G3dObject *obj, G3dObjectStatus *status);
extern void *func_021AC1E0(FieldEffectObj *effect);
extern int func_0216DA30(Mmdl *mmdl);
extern int func_02047910(G3dObject *obj, int anmIdx, fx32 step);

D06DenkiRes *func_021C8E68(FieldEffectSys *fieldEffect, u32 heapId);
void func_021C8E8C(FieldEffectSys *fieldEffect, D06DenkiRes *res);
void func_021C8EA0(D06DenkiRes *res);
void func_021C8F38(D06DenkiRes *res);
void func_021C8F7C(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void func_021C8FB8(FieldEffectObj *effect, D06DenkiSparkWork *work);
void func_021C8FDC(void);
void func_021C8FE0(FieldEffectObj *effect, D06DenkiSparkWork *work);
void func_021C8FF0(FieldEffectObj *effect, D06DenkiSparkWork *work);
void func_021C9064(FieldEffectSys *fieldEffect, const VecFx32 *pos, Mmdl *mmdl);
void func_021C909C(FieldEffectObj *effect);
void func_021C90AC(FieldEffectObj *effect);
int func_021C90D0(FieldEffectObj *effect, u32 unusedA, u32 unusedB, u32 unusedC);
void func_021C90E4(FieldEffectObj *effect, D06DenkiFollowWork *work);
void func_021C9164(void *task, D06DenkiFollowWork *work);
void func_021C9190(FieldEffectObj *effect, D06DenkiFollowWork *work);
void func_021C9208(FieldEffectObj *effect, D06DenkiFollowWork *work);
void func_021C9258(FieldEffectSys *fieldEffect, const VecFx32 *pos);
void func_021C928C(FieldEffectObj *effect);
void func_021C92B0(FieldEffectObj *effect, D06DenkiPulseWork *work);
void func_021C9314(void *task, D06DenkiPulseWork *work);
void func_021C9334(void *task, D06DenkiPulseWork *work);
void func_021C9360(FieldEffectObj *effect, D06DenkiPulseWork *work);
extern char d_021DE544[];                              /* source file name for the heap allocator */
extern const D06DenkiModelFiles d_021DAB6C;
extern const D06DenkiAnimeFiles d_021DAB7C;
extern const FieldEffectObjFuncs d_021DABA4;           /* spark callbacks */
extern G3dObjectStatus d_021DABCC;                     /* spark draw status template */
extern const FieldEffectObjFuncs d_021DABB8;           /* follow callbacks */
extern G3dObjectStatus d_021DAC08;                     /* follow draw status template */
extern const FieldEffectObjFuncs d_021DAB90;           /* pulse callbacks */
extern G3dObjectStatus d_021DAC44;                     /* pulse draw status template */






/* Loads the resources of the three effects. */
D06DenkiRes *func_021C8E68(FieldEffectSys *fieldEffect, u32 heapId)
{
    D06DenkiRes *res = func_02030734(heapId, 0x34, 1, d_021DE544, 0xa9);
    res->fieldEffect = fieldEffect;
    func_021C8EA0(res);
    return res;
}






void func_021C8E8C(FieldEffectSys *fieldEffect, D06DenkiRes *res)
{
    func_021C8F38(res);
    func_020307B0(res);
}






void func_021C8EA0(D06DenkiRes *res)
{
    D06DenkiModelFiles modelFiles;
    D06DenkiAnimeFiles animeFiles;
    ArcHandle *arc;
    u32 i;

    modelFiles = d_021DAB6C;
    animeFiles = d_021DAB7C;
    arc = func_021ABE24(res->fieldEffect);
    for (i = 0; i < D06DENKI_MODEL_COUNT; i++) {
        res->model[i] = func_02046E24(arc, modelFiles.fileId[i]);
        func_02046FF8(res->model[i]);
    }
    for (i = 0; i < D06DENKI_ANIME_COUNT; i++) {
        res->anime[i] = func_02046E24(arc, animeFiles.fileId[i]);
    }
    res->sparkRender = func_02047400(res->model[0], 0, res->model[0]);
    res->sparkAnime = func_02047564(res->sparkRender, res->anime[0], 0);
    res->sparkObject = func_0204767C(res->sparkRender, &res->sparkAnime, 1);
    func_020477A4(res->sparkObject, 0);
}






void func_021C8F38(D06DenkiRes *res)
{
    u32 i;

    func_0204762C(res->sparkAnime);
    func_02047738(res->sparkObject);
    func_02047504(res->sparkRender);
    for (i = 0; i < D06DENKI_MODEL_COUNT; i++) {
        func_020470D0(res->model[i]);
        func_02046EFC(res->model[i]);
    }
    for (i = 0; i < D06DENKI_ANIME_COUNT; i++) {
        func_02046EFC(res->anime[i]);
    }
}




/* Starts a spark at the position of the model. */
void func_021C8F7C(const Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    VecFx32 pos;
    D06DenkiStartParam param;
    func_0216D88C(mmdl, &pos);
    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_D06DENKI);
    param.pos = pos;
    func_021ABFA8(fieldEffect, &d_021DABA4, 0, 0, &param, 0);
}





/* Spark effect: init. */
void func_021C8FB8(FieldEffectObj *effect, D06DenkiSparkWork *work)
{
    D06DenkiStartParam *param = func_021AC1AC(effect);
    work->res = param->res;
    func_021AC1CC(effect, &param->pos);
    func_020061E4(SE_D06DENKI_SPARK);
}


/* Spark effect: exit, nothing to release. */
void func_021C8FDC(void) {}






/* Spark effect: update, ends the effect when the animation is done. */
void func_021C8FE0(FieldEffectObj *effect, D06DenkiSparkWork *work)
{
    if (work->state == D06DENKI_SPARK_FINISHED)
        func_021AC154(effect);
}






/* Spark effect: draw, advances the shared spark animation. */
void func_021C8FF0(FieldEffectObj *effect, D06DenkiSparkWork *work)
{
    G3dObjectStatus status;
    G3dObject *object;

    if (work->state == D06DENKI_SPARK_PLAYING) {
        status = d_021DABCC;
        object = work->res->sparkObject;
        func_0204784C(object, 0, &work->animeFrame);
        if (func_020478B8(object, 0, D06DENKI_ANIME_STEP) == 0) {
            work->state = D06DENKI_SPARK_FINISHED;
        }
        if (func_02047828(object, 0, &work->animeFrame) == 0) {
            work->state = D06DENKI_SPARK_FINISHED;
        }
        func_0207ADC4(&status.rotate);
        func_021AC1B8(effect, &status.trans);
        func_02047AC8(object, &status);
    }
}






/* Starts a follow effect at the position, tracking the model. */
void func_021C9064(FieldEffectSys *fieldEffect, const VecFx32 *pos, Mmdl *mmdl)
{
    D06DenkiFollowParam param;
    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_D06DENKI);
    param.pos = *pos;
    param.mmdl = mmdl;
    func_021ABFA8(fieldEffect, &d_021DABB8, 0, 0, &param, 0);
}






/* Freezes the looping animation of a follow effect. */
void func_021C909C(FieldEffectObj *effect)
{
    if (effect != 0)
        ((D06DenkiFollowWork *)func_021AC1E0(effect))->loopFrozen = 1;
}






/* Starts the ending animation of a follow effect. */
void func_021C90AC(FieldEffectObj *effect)
{
    fx32 frame;
    D06DenkiFollowWork *work;
    if (effect != 0) {
        frame = 0;
        work = func_021AC1E0(effect);
        work->ending = 1;
        work->ended = 0;
        func_0204784C(work->object, 1, &frame);
    }
}






/* Returns nonzero when the ending animation of a follow effect is done (or the effect is gone). */
int func_021C90D0(FieldEffectObj *effect, u32 unusedA, u32 unusedB, u32 unusedC)
{
if (effect != 0) {
    return ((D06DenkiFollowWork *)func_021AC1E0(effect))->ended;
}
return 1;
}






/* Follow effect: init. */
void func_021C90E4(FieldEffectObj *effect, D06DenkiFollowWork *work)
{
    work->param = *(D06DenkiFollowParam *)func_021AC1AC(effect);
    func_021AC1CC(effect, &work->param.pos);
    work->render = func_02047400(work->param.res->model[1], 0, work->param.res->model[1]);
    work->anime[0] = func_02047564(work->render, work->param.res->anime[1], 0);
    work->anime[1] = func_02047564(work->render, work->param.res->anime[2], 0);
    work->object = func_0204767C(work->render, work->anime, 2);
    func_020477A4(work->object, 0);
    func_020477A4(work->object, 1);
    work->subRender = func_02047400(work->param.res->model[3], 0, work->param.res->model[3]);
    work->subObject = func_0204767C(work->subRender, 0, 0);
}






/* Follow effect: exit. */
void func_021C9164(void *task, D06DenkiFollowWork *work)
{
    func_0204762C(work->anime[0]);
    func_0204762C(work->anime[1]);
    func_02047738(work->object);
    func_02047504(work->render);
    func_02047738(work->subObject);
    func_02047504(work->subRender);
}






/* Follow effect: update, tracks the model while it is in use. */
void func_021C9190(FieldEffectObj *effect, D06DenkiFollowWork *work)
{
    VecFx32 pos;

    if (func_0216DA30(work->param.mmdl) != 0) {
        func_0216D88C(work->param.mmdl, &pos);
        work->subPos = pos;
        func_021AC1CC(effect, &pos);
        work->subPos.y -= 0x4000;
        work->subPos.z += 0x2800;
        if (work->loopFrozen == 0) {
            func_02047910(work->object, 0, D06DENKI_ANIME_STEP);
        }
        if (work->ending == 1 && work->ended == 0) {
            if (func_020478B8(work->object, 1, D06DENKI_ANIME_STEP) == 0) {
                work->ended = 1;
            }
        }
    }
}






/* Follow effect: draw. */
void func_021C9208(FieldEffectObj *effect, D06DenkiFollowWork *work)
{
    G3dObjectStatus status = d_021DAC08;

    func_0207ADC4(&status.rotate);
    func_021AC1B8(effect, &status.trans);
    func_02047AC8(work->object, &status);
    status.trans = work->subPos;
    func_02047AC8(work->subObject, &status);
}






/* Starts a pulse effect at the position. */
void func_021C9258(FieldEffectSys *fieldEffect, const VecFx32 *pos)
{
    D06DenkiStartParam param;
    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_D06DENKI);
    param.pos = *pos;
    func_021ABFA8(fieldEffect, &d_021DAB90, 0, 0, &param, 0);
}






/* Triggers the second animation of a pulse effect, once. */
void func_021C928C(FieldEffectObj *effect)
{
    fx32 frame;
    D06DenkiPulseWork *work;
    if (effect != 0) {
        work = func_021AC1E0(effect);
        if (work->triggered == 0) {
            frame = 0;
            work->triggered = 1;
            func_0204784C(work->object, 1, &frame);
        }
    }
}






/* Pulse effect: init. */
void func_021C92B0(FieldEffectObj *effect, D06DenkiPulseWork *work)
{
    work->param = *(D06DenkiStartParam *)func_021AC1AC(effect);
    func_021AC1CC(effect, &work->param.pos);
    work->render = func_02047400(work->param.res->model[2], 0, work->param.res->model[2]);
    work->anime[0] = func_02047564(work->render, work->param.res->anime[3], 0);
    work->anime[1] = func_02047564(work->render, work->param.res->anime[4], 0);
    work->object = func_0204767C(work->render, work->anime, 2);
    func_020477A4(work->object, 0);
    func_020477A4(work->object, 1);
}






/* Pulse effect: exit. */
void func_021C9314(void *task, D06DenkiPulseWork *work)
{
    func_0204762C(work->anime[0]);
    func_0204762C(work->anime[1]);
    func_02047738(work->object);
    func_02047504(work->render);
}






/* Pulse effect: update, loops the first animation; the second one runs once after a trigger. */
void func_021C9334(void *task, D06DenkiPulseWork *work)
{
    func_02047910(work->object, 0, D06DENKI_ANIME_STEP);
    if (work->triggered == 1 && func_020478B8(work->object, 1, D06DENKI_ANIME_STEP) == 0)
        work->triggered = 0;
}






/* Pulse effect: draw. */
void func_021C9360(FieldEffectObj *effect, D06DenkiPulseWork *work)
{
    G3dObjectStatus status = d_021DAC44;
    func_0207ADC4(&status.rotate);
    func_021AC1B8(effect, &status.trans);
    func_02047AC8(work->object, &status);
}
