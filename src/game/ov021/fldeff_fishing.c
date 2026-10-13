/*
 * file:     fldeff_fishing.c
 * unit:     yes
 * function: func_021ADEDC, func_021ADF00, func_021ADF14, func_021ADF68, func_021ADF94, func_021AE01C, func_021AE030, func_021AE04C, func_021AE050, func_021AE090
 * address:  0x021ADEDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_iwakudaki.c at 0x021ADEDC (lane FXC, CL126: __FILE__ fldeff_fishing.c on 0x021ADEFC, resources 0x18, caller field_g3dobj.c is the fishing event).
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   d_021DE124  0x021DE124  data
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DE120     0x021DE120  data  a2
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   d_021D92E0     0x021D92E0  data  a1
 *   d_021D92E8     0x021D92E8  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   d_021D92FC  0x021D92FC  data
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

/* Converts a float constant to 20.12 fixed point, rounding away from zero. */
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

/* Id of the fishing rod resources in the field effect system. */
#define FLDEFF_ID_FISHING 13

/* File of the model in the effect archive. */
#define FISHING_MODEL_FILE 0x54

/* Depth offset of the rod per rod kind, for each side of the cast. */
typedef struct FishingRodOffsets {
    u8 offset[2][4];
} FishingRodOffsets;

/* Resources of the fishing rod effect (allocated 0x18 bytes by func_021ADEDC). */
typedef struct FishingRodRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model;                            /* 0x04 */
    G3dResource *anime;                            /* 0x08 */
    G3dObject *object;                             /* 0x0C */
    G3dAnime *animeObj;                            /* 0x10 */
    G3dRender *render;                             /* 0x14 */
} FishingRodRes;

/* Start parameter of the effect. */
typedef struct FishingRodStartParam {
    FishingRodRes *res;
    VecFx32 pos;
} FishingRodStartParam;

/* Work of the fishing rod effect. */
typedef struct FishingRodWork {
    FishingRodRes *res;                               /* 0x00 */
    u16 animeSpeed;                                /* 0x04 frame step is 2 * animeSpeed + 1 */
    u16 animeSpeedSet;                             /* 0x06 */
} FishingRodWork;

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
extern int func_02046FF8(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern void func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
extern void *func_021AC1E0(FieldEffectObj *effect);
extern G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 func_020477A4(G3dObject *obj, u32 anmIdx);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);
extern int func_02047910(G3dObject *obj, int anmIdx, fx32 step);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);

FishingRodRes *func_021ADEDC(FieldEffectSys *fieldEffect, u32 heapId);
void func_021ADF00(FieldEffectSys *fieldEffect, FishingRodRes *res);
void func_021ADF14(FishingRodRes *res);
void func_021ADF68(FishingRodRes *res);
void func_021ADF94(FieldEffectSys *fieldEffect, const VecFx32 *pos, u32 rodKind, u32 side);
void func_021AE01C(FieldEffectObj *effect, u16 animeSpeed);
void func_021AE030(FieldEffectObj *effect, FishingRodWork *work);
void func_021AE04C(void);
void func_021AE050(FieldEffectObj *effect, FishingRodWork *work);
void func_021AE090(FieldEffectObj *effect, FishingRodWork *work);

extern char d_021DE124[];                              /* source file name for the heap allocator */
extern u16 d_021DE120;                                 /* animation file id */
extern FishingRodOffsets d_021D92E0;                   /* rod depth offsets */
extern const FieldEffectObjFuncs d_021D92E8;           /* fishing rod effect callbacks */
extern G3dObjectStatus d_021D92FC;                     /* draw status template */
/* Loads the resources of the fishing rod effect. */
FishingRodRes *func_021ADEDC(FieldEffectSys *fieldEffect, u32 heapId)
{
    FishingRodRes *res = func_02030734(heapId, 0x18, 1, d_021DE124, 0x60);
    res->fieldEffect = fieldEffect;
    func_021ADF14(res);
    return res;
}

void func_021ADF00(FieldEffectSys *fieldEffect, FishingRodRes *res)
{
    func_021ADF68(res);
    func_020307B0(res);
}

void func_021ADF14(FishingRodRes *res)
{
    ArcHandle *arc = func_021ABE24(res->fieldEffect);

    res->model = func_02046E24(arc, FISHING_MODEL_FILE);
    func_02046FF8(res->model);
    res->anime = func_02046E24(arc, d_021DE120);
    res->render = func_02047400(res->model, 0, res->model);
    res->animeObj = func_02047564(res->render, res->anime, 0);
    res->object = func_0204767C(res->render, &res->animeObj, 1);
    func_020477A4(res->object, 0);
}

void func_021ADF68(FishingRodRes *res)
{
    func_02047738(res->object);
    func_0204762C(res->animeObj);
    func_02047504(res->render);
    func_02046EFC(res->anime);
    func_020470D0(res->model);
    func_02046EFC(res->model);
}

/* Starts the rod effect; the depth depends on the rod kind and the side of the cast. */
void func_021ADF94(FieldEffectSys *fieldEffect, const VecFx32 *pos, u32 rodKind, u32 side)
{
    FishingRodOffsets offsets = d_021D92E0;
    FishingRodStartParam param;
    int offset;
    int fixed;

    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_FISHING);
    param.pos = *pos;
    offset = offsets.offset[side][rodKind];
    if (offset != 0) {
        fixed = func_0209C95C(0x3f000000, func_0209BDBC(offset << 12));
    } else {
        fixed = func_0209CB8C(func_0209BDBC(offset << 12), 0x3f000000);
    }
    param.pos.z += func_0209C494(fixed);
    func_021ABFA8(fieldEffect, &d_021D92E8, 0, 0, &param, 0);
}

/* Sets the animation speed level of the rod effect (1 when a fish bites). */
void func_021AE01C(FieldEffectObj *effect, u16 animeSpeed)
{
    FishingRodWork *work;

    if (effect != 0) {
        work = func_021AC1E0(effect);
        work->animeSpeedSet = 1;
        work->animeSpeed = animeSpeed;
    }
}

/* Effect init. */
void func_021AE030(FieldEffectObj *effect, FishingRodWork *work)
{
    FishingRodStartParam *param = func_021AC1AC(effect);

    work->res = param->res;
    func_021AC1CC(effect, &param->pos);
}

/* Effect exit. */
void func_021AE04C(void)
{
}

/* Effect update: loops the animation at a speed of 2 * animeSpeed + 1 frames. */
void func_021AE050(FieldEffectObj *effect, FishingRodWork *work)
{
    FishingRodRes *res = work->res;
    func_02047910(res->object, 0, FX_F32_TO_FX32(work->animeSpeed * 2 + 1));
}

/* Effect draw. */
void func_021AE090(FieldEffectObj *effect, FishingRodWork *work)
{
    FishingRodRes *res = work->res;
    G3dObjectStatus status = d_021D92FC;

    func_0207ADC4(&status.rotate);
    func_021AC1B8(effect, &status.trans);
    func_02047AC8(res->object, &status);
}
