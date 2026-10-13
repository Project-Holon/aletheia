/*
 * file:     fldeff_hide.c
 * unit:     yes
 * function: func_021D038C, func_021D03B0, func_021D03C4, func_021D0440, func_021D046C, func_021D04A4, func_021D04C4, func_021D04D8, func_021D0504, func_021D0520, func_021D0568
 * address:  0x021D038C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021D038C (lane L136, __FILE__ anchor fldeff_hide.c at 021D038C (d_021DE618); callback table g_021DB93C targets 04D8/0504/0520/0568).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021DE618     0x021DE618  data  ov021  a4
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   data_021DB92C  0x021DB92C  data  ov021  a2
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   d_021DB93C     0x021DB93C  data  ov021  a4
 *   d_021DB934     0x021DB934  data  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C6744  0x021C6744  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021C67A8  0x021C67A8  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 */
#include "../ov010/fldmmdl_types.h"
#include "field_effect_types.h"

/* Opaque types of other files. */
typedef struct FieldG3dObjSys FieldG3dObjSys;           /* field 3D object system (arm9/ov021 field_g3dobj) */
typedef struct ArcHandle ArcHandle;

/* Resource description the field 3D object system builds a model from (9 words). */
typedef struct FieldG3dResDesc {
    u32 w[9];
} FieldG3dResDesc;

/* Id of the hide resources in the field effect system. */
#define FLDEFF_ID_HIDE 15

/* Kinds of the hide effect: one model with one animation each. */
#define HIDE_KIND_COUNT 2

/* Fixed-point step added to the animation frame each draw (one frame). */
#define HIDE_ANIME_STEP 0x1000

/* Model and animation file of one hide kind in the effect archive. */
typedef struct HideFiles {
    u16 modelFile;
    u16 animeFile;
} HideFiles;

/* Resources of the hide effect (allocated 0xC bytes by func_021D038C). */
typedef struct HideRes {
    u16 resId[HIDE_KIND_COUNT];                  /* 0x00 model resource of each kind */
    FieldEffectSys *fieldEffect;                 /* 0x04 */
    u16 objId[HIDE_KIND_COUNT];                  /* 0x08 object of each kind, drawn by the effect */
} HideRes;

/* Start parameter of the effect. */
typedef struct HideStartParam {
    HideRes *res;
    FieldG3dObjSys *g3dObjSys;
    Mmdl *mmdl;                                  /* hidden model the effect follows */
    u32 kind;
} HideStartParam;

/* Work of the hide effect (0x24 bytes, the first word of the callback table). */
typedef struct HideWork {
    HideStartParam param;                        /* 0x00 */
    MmdlCheckInfo mmdlInfo;                      /* 0x10 identity of the model, taken at the start */
    u16 pad16;
    u16 objId;                                   /* 0x18 */
    u16 endRequested;                            /* 0x1A 1 = play the animation to its end */
    u16 finished;                                /* 0x1C 1 = the animation reached its end */
    u16 pad1E;
    u32 animeFrame;                              /* 0x20 */
} HideWork;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern FieldG3dObjSys *func_021ABE18(FieldEffectSys *fieldEffect);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern FieldEffectObj *func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *func_021AC1E0(FieldEffectObj *effect);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
extern void func_021AC154(FieldEffectObj *effect);
extern void func_021C6AE0(FieldG3dResDesc *desc);
extern int func_021C6AF0(FieldG3dResDesc *desc, ArcHandle *arc, u32 modelFile);
extern void func_021C6AF8(FieldG3dResDesc *desc, ArcHandle *arc);
extern void func_021C6AFC(FieldG3dResDesc *desc, u32 animeFile);
extern int func_021C6574(FieldG3dObjSys *g3dObjSys, FieldG3dResDesc *desc, u32 flags);
extern u16 func_021C6590(FieldG3dObjSys *g3dObjSys, u32 resId, u32 arg2, u32 arg3);
extern void func_021C67D8(FieldG3dObjSys *g3dObjSys, u32 objId, u32 manualDraw);
extern u32 func_021C6628(FieldG3dObjSys *g3dObjSys, u32 objId);
extern void func_021C6580(FieldG3dObjSys *g3dObjSys, int resId);
extern void func_021C6744(FieldG3dObjSys *g3dObjSys, int objId, int animeIndex, u32 frame);
extern int func_021C6694(FieldG3dObjSys *g3dObjSys, int objId, int step);
extern u32 func_021C67A8(FieldG3dObjSys *g3dObjSys, u32 objId, u32 animeIndex);
extern void func_021C6664(FieldG3dObjSys *g3dObjSys, u32 objId, VecFx32 *pos);
extern void func_021C67F4(FieldG3dObjSys *g3dObjSys, u32 objId);
extern void func_020061E4(u32 seId);
extern void func_0216E1A4(Mmdl *mmdl, MmdlCheckInfo *info);
extern int func_0216E1C4(Mmdl *mmdl, MmdlCheckInfo *info);
extern void func_0219BF3C(Mmdl *mmdl, FieldEffectObj *effect);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern int func_02163E58(const Mmdl *mmdl, VecFx32 *pos, int *outHeight);

HideRes *func_021D038C(FieldEffectSys *fieldEffect, u32 heapId);
void func_021D03B0(FieldEffectSys *fieldEffect, HideRes *res);
void func_021D03C4(HideRes *res);
void func_021D0440(HideRes *res);
FieldEffectObj *func_021D046C(FieldEffectSys *fieldEffect, Mmdl *mmdl, u32 kind);
void func_021D04A4(FieldEffectObj *effect);
int func_021D04C4(FieldEffectObj *effect);
void func_021D04D8(FieldEffectObj *effect, HideWork *work);
void func_021D0504(FieldEffectObj *effect, HideWork *work);
void func_021D0520(FieldEffectObj *effect, HideWork *work);
void func_021D0568(FieldEffectObj *effect, HideWork *work);

extern char d_021DE618[];                              /* source file name for the heap allocator */
extern const HideFiles data_021DB92C[HIDE_KIND_COUNT]; /* model and animation file of each kind */
extern const FieldEffectObjFuncs d_021DB93C;           /* hide effect callbacks */
extern u32 d_021DB934[HIDE_KIND_COUNT];                /* sound effect played when the effect ends */

/* ------------------------------------------------------------------ */
/* fldeff_hide.c                                                       */
/* ------------------------------------------------------------------ */

/* Loads the resources of the hide effect. */
HideRes *func_021D038C(FieldEffectSys *fieldEffect, u32 heapId)
{
    HideRes *res = func_02030734(heapId, sizeof(HideRes), 1, d_021DE618, 0x6b);

    res->fieldEffect = fieldEffect;
    func_021D03C4(res);
    return res;
}

void func_021D03B0(FieldEffectSys *fieldEffect, HideRes *res)
{
    func_021D0440(res);
    func_020307B0(res);
}

/* Loads the model of each kind and adds its object (drawn by the effect itself). */
void func_021D03C4(HideRes *res)
{
    FieldG3dResDesc desc;
    ArcHandle *arc;
    FieldG3dObjSys *g3dObjSys;
    int i = 0;
    const HideFiles *files = data_021DB92C;

    arc = func_021ABE24(res->fieldEffect);
    g3dObjSys = func_021ABE18(res->fieldEffect);
    for (; i < HIDE_KIND_COUNT; i++, files++) {
        func_021C6AE0(&desc);
        func_021C6AF0(&desc, arc, files->modelFile);
        func_021C6AF8(&desc, arc);
        func_021C6AFC(&desc, files->animeFile);
        res->resId[i] = func_021C6574(g3dObjSys, &desc, 0);
        res->objId[i] = func_021C6590(g3dObjSys, res->resId[i], 0, 0);
        func_021C67D8(g3dObjSys, res->objId[i], 1);
    }
}

void func_021D0440(HideRes *res)
{
    int i = 0;
    FieldG3dObjSys *g3dObjSys = func_021ABE18(res->fieldEffect);

    for (; i < HIDE_KIND_COUNT; i++) {
        func_021C6628(g3dObjSys, res->objId[i]);
        func_021C6580(g3dObjSys, res->resId[i]);
    }
}

/* Starts the hide effect of one kind on a model; returns the effect. */
FieldEffectObj *func_021D046C(FieldEffectSys *fieldEffect, Mmdl *mmdl, u32 kind)
{
    HideStartParam param;

    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_HIDE);
    param.g3dObjSys = func_021ABE18(fieldEffect);
    param.mmdl = mmdl;
    param.kind = kind;
    return func_021ABFA8(fieldEffect, &d_021DB93C, 0, 0, &param, 0);
}

/*
 * Blocked: d_021DB934 (u32 table indexed by the kind) is contested: another
 * overlay in the window starts an object at 0x021DB934 and this function has
 * no overlay_id site, so the ABS32 word stays wildcarded.
 */
/* Asks the effect to play its animation to the end and plays the sound. A null effect is ignored. */
void func_021D04A4(FieldEffectObj *effect)
{
    HideWork *work;

    if (effect != 0) {
        work = func_021AC1E0(effect);
        work->endRequested = 1;
        func_020061E4(d_021DB934[work->param.kind]);
    }
}

/* 1 when the animation has played to its end, or when there is no effect. */
int func_021D04C4(FieldEffectObj *effect)
{
    if (effect != 0) {
        return ((HideWork *)func_021AC1E0(effect))->finished;
    }
    return 1;
}

/* Effect init. */
void func_021D04D8(FieldEffectObj *effect, HideWork *work)
{
    work->param = *(HideStartParam *)func_021AC1AC(effect);
    func_0216E1A4(work->param.mmdl, &work->mmdlInfo);
    work->objId = work->param.res->objId[work->param.kind];
}

/* Effect exit: the model no longer holds the effect. */
void func_021D0504(FieldEffectObj *effect, HideWork *work)
{
    if (func_0216E1C4(work->param.mmdl, &work->mmdlInfo) == 1) {
        func_0219BF3C(work->param.mmdl, 0);
    }
}

/* Effect update: follows the model on the map height and ends when the model is gone. */
void func_021D0520(FieldEffectObj *effect, HideWork *work)
{
    int mapHeight;
    VecFx32 pos;

    if (func_0216E1C4(work->param.mmdl, &work->mmdlInfo) == 0) {
        func_021AC154(effect);
        return;
    }
    func_0216D88C(work->param.mmdl, &pos);
    if (func_02163E58(work->param.mmdl, &pos, &mapHeight) == 1) {
        pos.y = mapHeight;
    }
    func_021AC1CC(effect, &pos);
}

/* Effect draw: plays the animation once the end is requested, then draws at the effect position. */
void func_021D0568(FieldEffectObj *effect, HideWork *work)
{
    VecFx32 pos;

    if (work->endRequested == 1 && work->finished == 0) {
        func_021C6744(work->param.g3dObjSys, work->objId, 0, work->animeFrame);
        if (func_021C6694(work->param.g3dObjSys, work->objId, HIDE_ANIME_STEP) == 0) {
            work->finished = 1;
        }
        work->animeFrame = func_021C67A8(work->param.g3dObjSys, work->objId, 0);
    } else {
        func_021C6744(work->param.g3dObjSys, work->objId, 0, work->animeFrame);
    }
    func_021AC1B8(effect, &pos);
    func_021C6664(work->param.g3dObjSys, work->objId, &pos);
    func_021C67F4(work->param.g3dObjSys, work->objId);
}
