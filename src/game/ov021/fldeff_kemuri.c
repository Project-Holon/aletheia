/*
 * file:     fldeff_kemuri.c
 * unit:     yes
 * function: func_021AC494, func_021AC4B8, func_021AC4CC, func_021AC514, func_021AC528, func_021AC578, func_021AC62C, func_021AC660, func_021AC66C, func_021AC688
 * address:  0x021AC494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AC494: __FILE__ fldeff_kemuri.c on 0x021AC494 (init, first
 * function).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   tbl_020A1B38   0x020A1B38  data  a2
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   d_021DE038  0x021DE038  data
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021D90AC     0x021D90AC  data  a4
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */
#include "field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

/* Id of the smoke (kemuri) resource in the field effect system. */
#define FLDEFF_ID_KEMURI 1

/* Files of the smoke model and its animation in the effect archive. */
#define FLDEFF_KEMURI_MODEL_FILE 0x30
#define FLDEFF_KEMURI_ANIME_FILE 0x60

/* The smoke appears this far above the model and this far in front of it. */
#define FLDEFF_KEMURI_RAISE   0x1000
#define FLDEFF_KEMURI_FORWARD 0x6000

/* Fixed-point step added to the animation frame each update (one frame). */
#define FLDEFF_KEMURI_ANIME_STEP 0x1000

#define FIELD_G3DOBJ_ANIME_MAX 8

/* Opaque and shared types of field_g3dobj.c. */
typedef struct FieldG3dObjCtrl FieldG3dObjCtrl;

/* Files of one G3D resource: a model, a texture file and up to eight animations (0x24 bytes). */
typedef struct FieldG3dObjResDesc {
    u32 modelArc;
    u32 texArc;
    u32 anmArc;
    u16 modelFile;
    u16 texFile;
    u16 anmFile[FIELD_G3DOBJ_ANIME_MAX];
    u8  anmCount;
} FieldG3dObjResDesc;

/* Resource of the smoke effect (8 bytes): the G3D resource of the smoke model. */
typedef struct FldeffKemuri {
    FieldEffectSys *fieldEffect;          /* 0x00 */
    u16 resIdx;                           /* 0x04 resource index in the G3D object control */
    u8 pad06[2];
} FldeffKemuri;

/* Start parameter of one smoke (0x10 bytes). */
typedef struct FldeffKemuriParam {
    FldeffKemuri *kemuri;
    VecFx32 pos;
} FldeffKemuriParam;

/* Work of one smoke (0x0C bytes). */
typedef struct FldeffKemuriWork {
    FldeffKemuri *kemuri;                 /* 0x00 */
    FieldG3dObjCtrl *g3dObjCtrl;          /* 0x04 */
    u16 objIdx;                           /* 0x08 object index in the G3D object control */
} FldeffKemuriWork;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern void *func_0216D67C(const Mmdl *mmdl);
extern void func_021C6AE0(FieldG3dObjResDesc *desc);
extern int func_021C6AF0(FieldG3dObjResDesc *desc, u32 arc, u32 file);
extern void func_021C6AF8(FieldG3dObjResDesc *desc, u32 arc);
extern void func_021C6AFC(FieldG3dObjResDesc *desc, u16 file);
extern int func_021C6574(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode);
extern u32 func_021C6580(FieldG3dObjCtrl *ctrl, int resIdx);
extern u32 func_0216D538(void *mmdlSys);
extern u32 func_021C6590(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos);
void func_021C6628(FieldG3dObjCtrl *ctrl, int objIdx);
extern int func_021C6694(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
FieldG3dObjCtrl *func_021ABE18(FieldEffectSys *sys);
int func_021ABE24(FieldEffectSys *sys);
void *func_021ABEA0(FieldEffectSys *sys, int id);
void func_021ABFA8(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void func_021AC154(FieldEffectObj *obj);
void *func_021AC1AC(FieldEffectObj *obj);
void func_021AC1CC(FieldEffectObj *obj, const VecFx32 *pos);
FldeffKemuri *func_021AC494(FieldEffectSys *sys, int heapId);
void func_021AC4B8(FieldEffectSys *sys, FldeffKemuri *kemuri);
void func_021AC4CC(FldeffKemuri *kemuri);
int func_021AC514(FldeffKemuri *kemuri);
void func_021AC528(Mmdl *mmdl, FieldEffectSys *sys);
void func_021AC578(Mmdl *mmdl, FieldEffectSys *sys);
void func_021AC62C(FieldEffectObj *obj, FldeffKemuriWork *work);
void func_021AC660(FieldEffectObj *obj, FldeffKemuriWork *work);
void func_021AC66C(FieldEffectObj *obj, FldeffKemuriWork *work);
void func_021AC688(void);
extern s16 tbl_020A1B38[];
extern char d_021DE038[];
extern FieldEffectObjFuncs d_021D90AC;

/* Resource creation: allocates the resource and loads the smoke model. */
FldeffKemuri *func_021AC494(FieldEffectSys *sys, int heapId)
{
    FldeffKemuri *kemuri;

    kemuri = func_02030734(heapId, sizeof(FldeffKemuri), 1, d_021DE038, 0x52);
    kemuri->fieldEffect = sys;
    func_021AC4CC(kemuri);
    return kemuri;
}








/* Resource deletion: frees the G3D resource and the resource. */
void func_021AC4B8(FieldEffectSys *sys, FldeffKemuri *kemuri)
{
    func_021AC514(kemuri);
    func_020307B0(kemuri);
}








/* Loads the smoke model and its animation into the G3D object control. */
void func_021AC4CC(FldeffKemuri *kemuri)
{
    FieldG3dObjResDesc desc;
    FieldG3dObjCtrl *g3dObjCtrl = func_021ABE18(kemuri->fieldEffect);
    int arcHandle = func_021ABE24(kemuri->fieldEffect);
    func_021C6AE0(&desc);
    func_021C6AF0(&desc, arcHandle, FLDEFF_KEMURI_MODEL_FILE);
    func_021C6AF8(&desc, arcHandle);
    func_021C6AFC(&desc, FLDEFF_KEMURI_ANIME_FILE);
    kemuri->resIdx = func_021C6574(g3dObjCtrl, &desc, 0);
}








/* Frees the G3D resource of the smoke model. */
int func_021AC514(FldeffKemuri *kemuri)
{
    return func_021C6580(func_021ABE18(kemuri->fieldEffect), kemuri->resIdx);
}








/* Starts a smoke in front of a model. */
void func_021AC528(Mmdl *mmdl, FieldEffectSys *sys)
{
    VecFx32 pos;
    FldeffKemuriParam param;
    func_0216D88C(mmdl, &pos);
    pos.y += FLDEFF_KEMURI_RAISE;
    pos.z += FLDEFF_KEMURI_FORWARD;
    param.kemuri = func_021ABEA0(sys, FLDEFF_ID_KEMURI);
    param.pos = pos;
    func_021ABFA8(sys, &d_021D90AC, 0, 0, &param, 0);
}






/* Starts a smoke on the side a model faces. */
void func_021AC578(Mmdl *mmdl, FieldEffectSys *sys)
{
    VecFx32 pos;
    FldeffKemuriParam param;
    int dirIndex;
    dirIndex = func_0216D538(func_0216D67C(mmdl));
    func_0216D88C(mmdl, &pos);
    pos.y += FLDEFF_KEMURI_RAISE;
    dirIndex = (dirIndex >> 4) * 2;
    pos.z += (s32)(((long long)tbl_020A1B38[dirIndex + 1] * FLDEFF_KEMURI_FORWARD + 0x800) >> 12);
    pos.x += (s32)(((long long)tbl_020A1B38[dirIndex] * FLDEFF_KEMURI_FORWARD + 0x800) >> 12);
    param.kemuri = func_021ABEA0(sys, FLDEFF_ID_KEMURI);
    param.pos = pos;
    func_021ABFA8(sys, &d_021D90AC, 0, 0, &param, 0);
}






/* Smoke effect: init, puts the smoke object at the start position. */
void func_021AC62C(FieldEffectObj *obj, FldeffKemuriWork *work)
{
    FldeffKemuriParam *param = func_021AC1AC(obj);
    work->kemuri = param->kemuri;
    work->g3dObjCtrl = func_021ABE18(work->kemuri->fieldEffect);
    func_021AC1CC(obj, &param->pos);
    work->objIdx = func_021C6590(work->g3dObjCtrl, work->kemuri->resIdx, 0, &param->pos);
}




/* Smoke effect: exit, deletes the smoke object. */
void func_021AC660(FieldEffectObj *obj, FldeffKemuriWork *work)
{
    func_021C6628(work->g3dObjCtrl, work->objIdx);
}




/* Smoke effect: update, plays the animation and ends the effect when it is over. */
void func_021AC66C(FieldEffectObj *obj, FldeffKemuriWork *work)
{
    if (func_021C6694(work->g3dObjCtrl, work->objIdx, FLDEFF_KEMURI_ANIME_STEP) == 0)
        func_021AC154(obj);
}




/* Smoke effect: draw, nothing to do (the G3D object control draws the object). */
void func_021AC688(void)
{
}
