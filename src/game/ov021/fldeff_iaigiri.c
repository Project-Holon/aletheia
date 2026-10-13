/*
 * file:     fldeff_iaigiri.c
 * unit:     yes
 * function: func_021C94BC, func_021C94E0, func_021C94F4, func_021C952C, func_021C9550, func_021C95D8, func_021C963C, func_021C9660, func_021C9690
 * address:  0x021C94BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C94BC: fldeff_iaigiri.c __FILE__ anchor at 0x021C94BC.
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_020478B8  0x020478B8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DE578  0x021DE578  data  ov021  a4
 *   d_021DE56C  0x021DE56C  data  ov021  a4
 *   d_021DAC80     0x021DAC80  data  a4
 *   d_021DAC94  0x021DAC94  data  ov021  a4
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

/* Id of the Cut resources in the field effect system. */
#define FLDEFF_ID_IAIGIRI 0xc

#define IAIGIRI_ANIME_COUNT 3

/* File of the model in the effect archive. */
#define IAIGIRI_MODEL_FILE 0x52

/* Facing directions of a field model. */
#define IAIGIRI_DIR_UP    0
#define IAIGIRI_DIR_DOWN  1
#define IAIGIRI_DIR_LEFT  2
#define IAIGIRI_DIR_RIGHT 3

/* One tile in fixed point. */
#define IAIGIRI_TILE_SIZE 0x10000

/* Fixed-point step added to the animation frame each update (one frame). */
#define IAIGIRI_ANIME_STEP 0x1000

/* Resources of the Cut effect (allocated 0x1C bytes by func_021C94BC). */
typedef struct IaigiriRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model;                            /* 0x04 */
    G3dResource *anime[IAIGIRI_ANIME_COUNT];       /* 0x08 */
    u8 pad14[0x1C - 0x14];
} IaigiriRes;

/* Start parameter of the effect. */
typedef struct IaigiriStartParam {
    IaigiriRes *res;
    VecFx32 pos;
} IaigiriStartParam;

/* Work of the Cut effect: three animations of one model that play to their end. */
typedef struct IaigiriTaskWork {
    IaigiriRes *res;                               /* 0x00 */
    G3dObject *object;                             /* 0x04 */
    G3dAnime *anime[IAIGIRI_ANIME_COUNT];          /* 0x08 */
    G3dRender *render;                             /* 0x14 */
} IaigiriTaskWork;

extern u16 func_0216D5F8(const Mmdl *mmdl);
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
extern int func_020478B8(G3dObject *obj, int anmIdx, fx32 step);
extern void func_0207ADC4(MtxFx33 *mtx);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern int func_02047AC8(G3dObject *obj, G3dObjectStatus *status);

IaigiriRes *func_021C94BC(FieldEffectSys *fieldEffect, u32 heapId);
void func_021C94E0(FieldEffectSys *fieldEffect, IaigiriRes *res);
void func_021C94F4(IaigiriRes *res);
void func_021C952C(IaigiriRes *res);
void func_021C9550(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void func_021C95D8(FieldEffectObj *effect, IaigiriTaskWork *work);
void func_021C963C(void *task, IaigiriTaskWork *work);
void func_021C9660(FieldEffectObj *effect, IaigiriTaskWork *work);
void func_021C9690(FieldEffectObj *effect, IaigiriTaskWork *work);
extern char d_021DE578[];                              /* source file name for the heap allocator */
extern u32 d_021DE56C[IAIGIRI_ANIME_COUNT];            /* animation file ids */
extern const FieldEffectObjFuncs d_021DAC80;           /* effect callbacks */
extern G3dObjectStatus d_021DAC94;                     /* draw status template */






/* Loads the resources of the Cut effect. */
IaigiriRes *func_021C94BC(FieldEffectSys *fieldEffect, u32 heapId)
{
    IaigiriRes *res = func_02030734(heapId, 0x1c, 1, d_021DE578, 0x66);
    res->fieldEffect = fieldEffect;
    func_021C94F4(res);
    return res;
}






void func_021C94E0(FieldEffectSys *fieldEffect, IaigiriRes *res)
{
    func_021C952C(res);
    func_020307B0(res);
}






void func_021C94F4(IaigiriRes *res)
{
    ArcHandle *arc = func_021ABE24(res->fieldEffect);
    int i;
    res->model = func_02046E24(arc, IAIGIRI_MODEL_FILE);
    func_02046FF8(res->model);
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        res->anime[i] = func_02046E24(arc, d_021DE56C[i]);
}






void func_021C952C(IaigiriRes *res)
{
    int i;
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        func_02046EFC(res->anime[i]);
    func_020470D0(res->model);
    func_02046EFC(res->model);
}






/* Starts the effect on the tile in front of the model. */
void func_021C9550(const Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    VecFx32 pos;
    IaigiriStartParam param;

    func_0216D88C(mmdl, &pos);
    switch (func_0216D5F8(mmdl)) {
    case IAIGIRI_DIR_UP:
        pos.z -= IAIGIRI_TILE_SIZE;
        break;
    case IAIGIRI_DIR_DOWN:
        pos.z += IAIGIRI_TILE_SIZE;
        break;
    case IAIGIRI_DIR_LEFT:
        pos.x -= IAIGIRI_TILE_SIZE;
        break;
    case IAIGIRI_DIR_RIGHT:
        pos.x += IAIGIRI_TILE_SIZE;
        break;
    }
    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_IAIGIRI);
    param.pos = pos;
    func_021ABFA8(fieldEffect, &d_021DAC80, 0, 0, &param, 0);
}






/*
 * Effect init. The `adds r4, r6, #0` before the first loop is the second
 * loop's counter initialised to 0 and shared as the first loop's constant 0
 * argument; both loops use one counter i.
 */
void func_021C95D8(FieldEffectObj *effect, IaigiriTaskWork *work)
{
    IaigiriStartParam *param = func_021AC1AC(effect);
    int i;

    work->res = param->res;
    func_021AC1CC(effect, &param->pos);
    work->render = func_02047400(work->res->model, 0, work->res->model);
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        work->anime[i] = func_02047564(work->render, work->res->anime[i], 0);
    work->object = func_0204767C(work->render, work->anime, IAIGIRI_ANIME_COUNT);
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        func_020477A4(work->object, (u16)i);
}






/* Effect exit. */
void func_021C963C(void *task, IaigiriTaskWork *work)
{
    int i;
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        func_0204762C(work->anime[i]);
    func_02047738(work->object);
    func_02047504(work->render);
}






/* Effect update: advances the animations and ends the effect when all are done. */
void func_021C9660(FieldEffectObj *effect, IaigiriTaskWork *work)
{
    int done = 1;
    int i;
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++) {
        if (func_020478B8(work->object, (u16)i, IAIGIRI_ANIME_STEP) == 1)
            done = 0;
    }
    if (done)
        func_021AC154(effect);
}






/* Effect draw. */
void func_021C9690(FieldEffectObj *effect, IaigiriTaskWork *work)
{
    G3dObjectStatus status = d_021DAC94;
    func_0207ADC4(&status.rotate);
    func_021AC1B8(effect, &status.trans);
    func_02047AC8(work->object, &status);
}
