/*
 * file:     fldeff_namipoke.c
 * unit:     yes
 * function: func_021ACA38, func_021ACA5C, func_021ACA70, func_021ACB0C, func_021ACB38, func_021ACBB8, func_021ACBC8, func_021ACBE4, func_021ACC04, func_021ACC3C, func_021ACCAC, func_021ACCB0, func_021ACDC4, func_021ACFD8, func_021ACFF8, func_021AD274, func_021AD3D4, func_021AD3FC, func_021AD410, func_021AD530, func_021AD564, func_021AD598, func_021AD5CC, func_021AD5E0, func_021AD6A4, func_021AD6B8, func_021AD738
 * address:  0x021ACA38
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   d_021DE080  0x021DE080  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D915C     0x021D915C  data  a4
 *   d_021D9184     0x021D9184  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   d_021D9198     0x021D9198  data  a2
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021D91C8     0x021D91C8  data  a4
 *   d_021D91B0     0x021D91B0  data  a2
 *   func_021C6678  0x021C6678  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_020521BC  0x020521BC  arm
 *   d_021D9170  0x021D9170  data
 *   d_021D91F8     0x021D91F8  data  a4
 *   func_021C6694  0x021C6694  thumb  ov021
 */
#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

typedef struct MtxFx33 { fx32 m[3][3]; } MtxFx33;

/* Opaque types of other files. */
typedef struct ArcHandle ArcHandle;
typedef struct FieldG3dObjSys FieldG3dObjSys;           /* field 3D object system (arm9/ov021 field_g3dobj) */
typedef struct FieldEffectSys FieldEffectSys;           /* field effect system (field_effect.c) */
typedef struct FieldEffectObj FieldEffectObj;           /* one running effect (field_effect.c) */
typedef struct FieldEffectObjFuncs FieldEffectObjFuncs; /* callback table: work size, init, exit, update, draw */

/* Position, scale and rotation a field 3D object is drawn with. */
typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;

/* Resource description the field 3D object system builds a model from (9 words). */
typedef struct FieldG3dResDesc {
    u32 w[9];
} FieldG3dResDesc;

/* Ids of the resources in the field effect system. */
#define FLDEFF_ID_NAMIPOKE        3
#define FLDEFF_ID_NAMIPOKE_SPLASH 9

/* Facing directions of a field model. */
#define NAMIPOKE_DIR_UP    0
#define NAMIPOKE_DIR_DOWN  1
#define NAMIPOKE_DIR_LEFT  2
#define NAMIPOKE_DIR_RIGHT 3
#define NAMIPOKE_DIR_COUNT 4
#define NAMIPOKE_DIR_NONE  9

/* followMode of a surf Pokemon effect (the mode of the effect object). */
#define NAMIPOKE_MODE_STATIC       0 /* effect only shows itself at the model position */
#define NAMIPOKE_MODE_BOB          1 /* effect bobs and moves the model draw offset */
#define NAMIPOKE_MODE_MODEL_OFFSET 2 /* effect reads the model draw offset */

/* Bob height range in fixed point; two object codes sit higher. */
#define NAMIPOKE_BOB_MIN         0x1000
#define NAMIPOKE_BOB_MAX         0x4000
#define NAMIPOKE_TALL_OBJ_CODE_A 0xA0
#define NAMIPOKE_TALL_OBJ_CODE_B 0xA1

/* Longest wake in fixed point (4 tiles), and the step the wake tail moves with. */
#define NAMIPOKE_WAKE_MAX_LENGTH 0x40000
#define NAMIPOKE_WAKE_TAIL_STEP  0x4000

#define NAMIPOKE_SPLASH_TYPE_COUNT 5

/* Resources of the surf Pokemon effect (allocated 0xC bytes by func_021ACA38). */
typedef struct NamipokeRes {
    FieldEffectSys *fieldEffect; /* 0x00 */
    u16 waveResId;               /* 0x04 model of the wave around the Pokemon */
    u16 wakeResId;               /* 0x06 model of the wake, with 2 animations */
    u16 waveObjId;               /* 0x08 */
    u16 wakeObjId;               /* 0x0A */
} NamipokeRes;

/* Start parameter of the surf Pokemon effect (0x1C bytes). */
typedef struct NamipokeStartParam {
    NamipokeRes *res; /* 0x00 */
    Mmdl *mmdl;       /* 0x04 */
    u16 objId;        /* 0x08 */
    u16 zoneId;       /* 0x0A */
    u16 facing;       /* 0x0C */
    u16 pad0E;
    VecFx32 pos;      /* 0x10 */
} NamipokeStartParam;

/* State of the wake object behind the model. */
typedef struct NamipokeWake {
    u16 hidden;      /* 0x00 1 = wake not shown */
    u16 dir;         /* 0x02 facing the tail was laid in, NAMIPOKE_DIR_NONE at the start */
    VecFx32 tailPos; /* 0x04 where the end of the wake lies */
    VecFx32 lastPos; /* 0x10 model position of the last update */
    u16 objId;       /* 0x1C */
    u16 pad1E;
    VecFx32 scale;   /* 0x20 */
    VecFx32 offset;  /* 0x2C added to the wake position */
} NamipokeWake;

/* Work of the surf Pokemon effect (0x70 bytes, the first word of the callback tables). */
typedef struct NamipokeWork {
    u8 pad00[9];
    u8 followMode;            /* 0x09 NAMIPOKE_MODE_* */
    u8 wakeDisabled;          /* 0x0A 1 = no wake */
    u8 pad0B;
    u16 facing;               /* 0x0C */
    u8 pad0E[2];
    s32 bobHeight;            /* 0x10 */
    s32 bobStep;              /* 0x14 */
    u16 waveObjId;            /* 0x18 */
    u8 pad1A[2];
    NamipokeStartParam param; /* 0x1C */
    NamipokeWake wake;        /* 0x38 */
} NamipokeWork;

/* Rotation of an object for each facing direction. */
typedef struct NamipokeAngle {
    u16 x, y, z;
} NamipokeAngle;

typedef struct NamipokeAngleTable {
    NamipokeAngle dir[NAMIPOKE_DIR_COUNT];
} NamipokeAngleTable;

typedef struct NamipokeOffsetTable {
    VecFx32 dir[NAMIPOKE_DIR_COUNT];
} NamipokeOffsetTable;

/* Models of the splash effects around the surf Pokemon (allocated 0x10 bytes by func_021AD3D4). */
typedef struct NamipokeSplashRes {
    FieldEffectSys *fieldEffect;                /* 0x00 */
    u16 modelResId[NAMIPOKE_SPLASH_TYPE_COUNT]; /* 0x04 */
} NamipokeSplashRes;

/* Start parameter of a splash effect. */
typedef struct NamipokeSplashStartParam {
    u32 deleteWhenDone;     /* 1 = the effect ends with its animation */
    NamipokeSplashRes *res;
    int type;
    FieldEffectObj *parent; /* effect it follows, 0 = none */
} NamipokeSplashStartParam;

/* Work of a splash effect (0x24 bytes). */
typedef struct NamipokeSplashWork {
    VecFx32 offset;                 /* 0x00 added to the parent position */
    int finished;                   /* 0x0C 1 = the single animation has played */
    u16 objId;                      /* 0x10 */
    u16 pad12;
    NamipokeSplashStartParam param; /* 0x14 */
} NamipokeSplashWork;

typedef struct NamipokeSplashOffsets {
    VecFx32 type[NAMIPOKE_SPLASH_TYPE_COUNT];
} NamipokeSplashOffsets;

extern u16 func_0216D588(Mmdl *mmdl);
extern u16 func_0216D590(Mmdl *mmdl);
extern int func_0216D55C(Mmdl *mmdl, int bits);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern u16 func_0216D598(Mmdl *mmdl);
extern void func_0216D8E0(Mmdl *mmdl, VecFx32 *offset);
extern void func_0216D8D0(Mmdl *mmdl, VecFx32 *offset);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern void func_02197CCC(Mmdl *mmdl, VecFx32 *out);
extern void func_0219E784(Mmdl *mmdl, u32 dir, s16 *out);
extern void func_0207CDB8(s16 *in, s16 *out);
extern s32 func_0207CF3C(const VecFx32 *a, const VecFx32 *b);
extern void func_020520FC(int ax, int ay, int az, MtxFx33 *dst);
extern void func_020521BC(const VecFx32 *v, MtxFx33 *dst);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern FieldG3dObjSys *func_021ABE18(FieldEffectSys *fieldEffect);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern FieldEffectObj *func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void func_021AC154(FieldEffectObj *effect);
extern void func_021AC178(FieldEffectObj *effect);
extern int func_021AC1A0(FieldEffectObj *effect);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1B8(FieldEffectObj *effect, VecFx32 *out);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
extern void *func_021AC1E0(FieldEffectObj *effect);
extern void func_021C6AE0(FieldG3dResDesc *desc);
extern int func_021C6AF0(FieldG3dResDesc *desc, ArcHandle *arc, u32 modelFile);
extern void func_021C6AF8(FieldG3dResDesc *desc, ArcHandle *arc);
extern void func_021C6AFC(FieldG3dResDesc *desc, u32 animeFile);
extern int func_021C6574(FieldG3dObjSys *g3dObjSys, FieldG3dResDesc *desc, u32 flags);
extern u16 func_021C6590(FieldG3dObjSys *g3dObjSys, u32 resId, u32 arg2, u32 arg3);
extern void func_021C67D8(FieldG3dObjSys *g3dObjSys, u32 objId, u32 manualDraw);
extern u32 func_021C6628(FieldG3dObjSys *g3dObjSys, u32 objId);
extern void func_021C6580(FieldG3dObjSys *g3dObjSys, int resId);
extern G3dObjectStatus *func_021C6658(FieldG3dObjSys *g3dObjSys, u32 objId);
extern void func_021C6678(FieldG3dObjSys *g3dObjSys, u32 objId, u32 hidden);
extern int func_021C66EC(FieldG3dObjSys *g3dObjSys, int objId, int step);
extern int func_021C6694(FieldG3dObjSys *g3dObjSys, int objId, int step);
extern void func_021C67F4(FieldG3dObjSys *g3dObjSys, u32 objId);

NamipokeRes *func_021ACA38(FieldEffectSys *fieldEffect, int heapId);
void func_021ACA5C(FieldEffectSys *fieldEffect, NamipokeRes *res);
void func_021ACA70(NamipokeRes *res);
void func_021ACB0C(NamipokeRes *res);
void func_021ACB38(FieldEffectSys *fieldEffect, u32 facing, const VecFx32 *pos, Mmdl *mmdl, u32 followMode);
void func_021ACBB8(FieldEffectObj *effect, u8 followMode);
void func_021ACBC8(FieldEffectObj *effect, int wakeEnabled);
int func_021ACBE4(int distance);
int func_021ACC04(const VecFx32 *from, const VecFx32 *to, u32 dir);
void func_021ACC3C(FieldEffectObj *effect, NamipokeWork *work);
void func_021ACCAC(void);
void func_021ACCB0(FieldEffectObj *effect, NamipokeWork *work);
void func_021ACDC4(FieldEffectObj *effect, NamipokeWork *work);
void func_021ACFD8(FieldEffectObj *effect, NamipokeWork *work);
void func_021ACFF8(FieldEffectObj *effect, NamipokeWork *work);
void func_021AD274(FieldEffectObj *effect, NamipokeWork *work);
NamipokeSplashRes *func_021AD3D4(FieldEffectSys *fieldEffect, int heapId);
void func_021AD3FC(FieldEffectSys *fieldEffect, NamipokeSplashRes *res);
void func_021AD410(NamipokeSplashRes *res);
void func_021AD530(NamipokeSplashRes *res);
void func_021AD564(FieldEffectSys *fieldEffect, int type, FieldEffectObj *parent);
void func_021AD598(FieldEffectSys *fieldEffect, int type, const VecFx32 *pos);
int func_021AD5CC(FieldEffectObj *effect);
void func_021AD5E0(FieldEffectObj *effect, NamipokeSplashWork *work);
int func_021AD6A4(FieldEffectObj *effect, NamipokeSplashWork *work, u32 unused0, u32 unused1);
void func_021AD6B8(FieldEffectObj *effect, NamipokeSplashWork *work);
void func_021AD738(FieldEffectObj *effect, NamipokeSplashWork *work);
extern char d_021DE080[];                           /* source file name for the heap allocator */
extern const FieldEffectObjFuncs d_021D915C;        /* surf Pokemon effect callbacks, rail models */
extern const FieldEffectObjFuncs d_021D9184;        /* surf Pokemon effect callbacks, grid models */
extern NamipokeAngleTable d_021D9198;               /* wave rotation of each facing */
extern NamipokeOffsetTable d_021D91C8;              /* wake offset of each facing */
extern NamipokeAngleTable d_021D91B0;               /* wake rotation of each facing */
extern const FieldEffectObjFuncs d_021D9170;        /* splash effect callbacks */
extern NamipokeSplashOffsets d_021D91F8;            /* splash offset of each type */

/* Creates the resources of the surf Pokemon effect. */
NamipokeRes *func_021ACA38(FieldEffectSys *fieldEffect, int heapId)
{
    NamipokeRes *res;

    res = func_02030734(heapId, 0xc, 1, d_021DE080, 0xac);
    res->fieldEffect = fieldEffect;
    func_021ACA70(res);
    return res;
}

/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ACA5C(FieldEffectSys *fieldEffect, NamipokeRes *res)
{
    func_021ACB0C(res);
    func_020307B0(res);
}

/* Loads the wave model, and the wake model with its two animations. */
void func_021ACA70(NamipokeRes *res)
{
    FieldG3dResDesc desc;
    FieldG3dObjSys *g3dObjSys = func_021ABE18(res->fieldEffect);
    ArcHandle *arc = func_021ABE24(res->fieldEffect);
    func_021C6AE0(&desc);
    func_021C6AF0(&desc, arc, 0x31);
    res->waveResId = func_021C6574(g3dObjSys, &desc, 0);
    res->waveObjId = func_021C6590(g3dObjSys, res->waveResId, 0, 0);
    func_021C67D8(g3dObjSys, res->waveObjId, 1);
    func_021C6AE0(&desc);
    func_021C6AF0(&desc, arc, 0x36);
    func_021C6AF8(&desc, arc);
    func_021C6AFC(&desc, 0x6b);
    func_021C6AFC(&desc, 0x85);
    res->wakeResId = func_021C6574(g3dObjSys, &desc, 0);
    res->wakeObjId = func_021C6590(g3dObjSys, res->wakeResId, 0, 0);
    func_021C67D8(g3dObjSys, res->wakeObjId, 1);
}

void func_021ACB0C(NamipokeRes *res)
{
    FieldG3dObjSys *g3dObjSys = func_021ABE18(res->fieldEffect);

    func_021C6628(g3dObjSys, res->waveObjId);
    func_021C6628(g3dObjSys, res->wakeObjId);
    func_021C6580(g3dObjSys, res->waveResId);
    func_021C6580(g3dObjSys, res->wakeResId);
}

/* Starts a surf Pokemon effect on a model. */
void func_021ACB38(FieldEffectSys *fieldEffect, u32 facing, const VecFx32 *pos, Mmdl *mmdl, u32 followMode)
{
    NamipokeStartParam param;
    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_NAMIPOKE);
    param.mmdl = mmdl;
    param.objId = func_0216D588(mmdl);
    param.zoneId = func_0216D590(mmdl);
    param.facing = facing;
    param.pos = *pos;
    if (func_0216D55C(mmdl, MMDL_STABIT_RAIL_MOVE) != 0)
        func_021ABFA8(fieldEffect, &d_021D915C, &param.pos, followMode, &param, 0);
    else
        func_021ABFA8(fieldEffect, &d_021D9184, &param.pos, followMode, &param, 0);
}

void func_021ACBB8(FieldEffectObj *effect, u8 followMode)
{
    if (effect != 0)
        ((NamipokeWork *)func_021AC1E0(effect))->followMode = followMode;
}

void func_021ACBC8(FieldEffectObj *effect, int wakeEnabled)
{
    NamipokeWork *work;

    if (effect != 0) {
        work = func_021AC1E0(effect);
        if (wakeEnabled == 1)
            work->wakeDisabled = 0;
        else
            work->wakeDisabled = 1;
    }
}

/* Wake scale for a wake of the given length. */
int func_021ACBE4(int distance)
{
    if (distance > NAMIPOKE_WAKE_MAX_LENGTH)
        distance = NAMIPOKE_WAKE_MAX_LENGTH;
    return distance / 0xA3D * 0x28;
}

/* Length of the wake from the tail position to the model position, measured along the facing. */
int func_021ACC04(const VecFx32 *from, const VecFx32 *to, u32 dir)
{
    int distance = 0;

    switch (dir) {
    case NAMIPOKE_DIR_UP:
        distance = to->z - from->z;
        break;
    case NAMIPOKE_DIR_DOWN:
        distance = from->z - to->z;
        break;
    case NAMIPOKE_DIR_LEFT:
        distance = to->x - from->x;
        break;
    case NAMIPOKE_DIR_RIGHT:
        distance = from->x - to->x;
        break;
    }
    return distance;
}

/* Surf Pokemon effect init. */
void func_021ACC3C(FieldEffectObj *effect, NamipokeWork *work)
{
    NamipokeStartParam *param = func_021AC1AC(effect);
    NamipokeWake *wake;
    u32 unit = 0x1000;
    work->param = *param;
    func_021AC1CC(effect, &param->pos);
    work->facing = param->facing;
    func_021ABE18(work->param.res->fieldEffect);
    work->waveObjId = work->param.res->waveObjId;
    work->followMode = func_021AC1A0(effect);
    work->bobHeight = unit;
    work->bobStep = unit >> 2;
    wake = &work->wake;
    wake->objId = work->param.res->wakeObjId;
    work->wake.hidden = 1;
    wake->dir = NAMIPOKE_DIR_NONE;
    wake->scale.x = unit;
    wake->scale.y = unit;
    wake->scale.z = unit;
    func_021AC178(effect);
}

void func_021ACCAC(void) {}

/* Places the wave and the wake: rotates the wave to the facing and lays the wake behind the model. */
void func_021ACCB0(FieldEffectObj *effect, NamipokeWork *work)
{
    NamipokeAngleTable waveAngles = d_021D9198;
    NamipokeAngle *waveAngle = &waveAngles.dir[work->facing];
    FieldG3dObjSys *g3dObjSys;
    G3dObjectStatus *status;

    g3dObjSys = func_021ABE18(work->param.res->fieldEffect);
    status = func_021C6658(g3dObjSys, work->waveObjId);
    func_020520FC(waveAngle->x, waveAngle->y, waveAngle->z, &status->rotate);
    func_021AC1B8(effect, &status->trans);
    if (work->wake.hidden == 0) {
        NamipokeWake *wake = &work->wake;
        NamipokeOffsetTable wakeOffsets = d_021D91C8;
        NamipokeAngleTable wakeAngles = d_021D91B0;
        VecFx32 *wakeOffset = &wakeOffsets.dir[work->facing];
        NamipokeAngle *wakeAngle = &wakeAngles.dir[work->facing];
        status = func_021C6658(g3dObjSys, wake->objId);
        func_020520FC(wakeAngle->x, wakeAngle->y, wakeAngle->z, &status->rotate);
        func_021AC1B8(effect, &status->trans);
        status->trans.x = status->trans.x + (wake->offset.x + wakeOffset->x);
        status->trans.y = status->trans.y + (wake->offset.y + wakeOffset->y);
        status->trans.z = status->trans.z + (wake->offset.z + wakeOffset->z);
        status->scale = wake->scale;
        func_021C6678(g3dObjSys, wake->objId, 0);
    } else {
        func_021C6678(g3dObjSys, work->wake.objId, 1);
    }
}

/*
 * Addresses are Black-image addresses.
 */
/* Surf Pokemon effect update for grid models: bobs, follows the model and stretches the wake. */
void func_021ACDC4(FieldEffectObj *effect, NamipokeWork *work)
{
    VecFx32 drawOffset = {0, 0, 0};
    VecFx32 pos;
    VecFx32 mmdlPos;
    NamipokeWake *wake;
    s32 distance;
    u16 objCode;

    if (work->followMode == NAMIPOKE_MODE_STATIC) {
        func_021ACCB0(effect, work);
        return;
    }
    work->facing = func_0216D5F8(work->param.mmdl);
    if (work->followMode == NAMIPOKE_MODE_BOB) {
        work->bobHeight += work->bobStep;
        if (work->bobHeight >= NAMIPOKE_BOB_MAX) {
            work->bobHeight = NAMIPOKE_BOB_MAX;
            work->bobStep = -work->bobStep;
        } else if (work->bobHeight <= NAMIPOKE_BOB_MIN) {
            work->bobHeight = NAMIPOKE_BOB_MIN;
            work->bobStep = -work->bobStep;
        }
        drawOffset.x = 0;
        drawOffset.y = work->bobHeight + 0x1000;
        drawOffset.z = 0x5000;
        objCode = func_0216D598(work->param.mmdl);
        if (objCode == NAMIPOKE_TALL_OBJ_CODE_A || objCode == NAMIPOKE_TALL_OBJ_CODE_B)
            drawOffset.y = work->bobHeight + 0x8000;
        func_0216D8E0(work->param.mmdl, &drawOffset);
    } else if (work->followMode == NAMIPOKE_MODE_MODEL_OFFSET) {
        func_0216D8D0(work->param.mmdl, &drawOffset);
    }
    func_02197CCC(work->param.mmdl, &pos);
    pos.x -= drawOffset.x;
    pos.y -= drawOffset.y;
    pos.z -= drawOffset.z;
    if (work->followMode != NAMIPOKE_MODE_MODEL_OFFSET)
        pos.y += work->bobHeight - 0x1000;
    func_021AC1CC(effect, &pos);
    if (work->followMode == NAMIPOKE_MODE_MODEL_OFFSET || work->wakeDisabled == 1) {
        wake = &work->wake;
        wake->dir = NAMIPOKE_DIR_NONE;
        if (work->wakeDisabled == 1)
            wake->hidden = 1;
    } else {
        wake = &work->wake;
        func_021C66EC(func_021ABE18(work->param.res->fieldEffect), wake->objId, 0x1000);
        func_0216D88C(work->param.mmdl, &mmdlPos);
        if (work->facing != wake->dir) {
            wake->dir = work->facing;
            wake->tailPos = mmdlPos;
        } else if (mmdlPos.x == wake->lastPos.x && mmdlPos.y == wake->lastPos.y && mmdlPos.z == wake->lastPos.z) {
            switch (wake->dir) {
            case NAMIPOKE_DIR_UP:
                wake->tailPos.z -= NAMIPOKE_WAKE_TAIL_STEP;
                if (wake->tailPos.z < mmdlPos.z)
                    wake->tailPos.z = mmdlPos.z;
                break;
            case NAMIPOKE_DIR_DOWN:
                wake->tailPos.z += NAMIPOKE_WAKE_TAIL_STEP;
                if (wake->tailPos.z > mmdlPos.z)
                    wake->tailPos.z = mmdlPos.z;
                break;
            case NAMIPOKE_DIR_LEFT:
                wake->tailPos.x -= NAMIPOKE_WAKE_TAIL_STEP;
                if (wake->tailPos.x < mmdlPos.x)
                    wake->tailPos.x = mmdlPos.x;
                break;
            case NAMIPOKE_DIR_RIGHT:
                wake->tailPos.x += NAMIPOKE_WAKE_TAIL_STEP;
                if (wake->tailPos.x > mmdlPos.x)
                    wake->tailPos.x = mmdlPos.x;
                break;
            }
        }
        distance = func_021ACC04(&mmdlPos, &wake->tailPos, wake->dir);
        if (distance >= NAMIPOKE_WAKE_MAX_LENGTH) {
            switch (wake->dir) {
            case NAMIPOKE_DIR_UP:
                wake->tailPos.z = mmdlPos.z + NAMIPOKE_WAKE_MAX_LENGTH;
                break;
            case NAMIPOKE_DIR_DOWN:
                wake->tailPos.z = mmdlPos.z - NAMIPOKE_WAKE_MAX_LENGTH;
                break;
            case NAMIPOKE_DIR_LEFT:
                wake->tailPos.x = mmdlPos.x + NAMIPOKE_WAKE_MAX_LENGTH;
                break;
            case NAMIPOKE_DIR_RIGHT:
                wake->tailPos.x = mmdlPos.x - NAMIPOKE_WAKE_MAX_LENGTH;
                break;
            }
        }
        distance = func_021ACBE4(distance);
        if (distance < 0x28) {
            wake->hidden = 1;
        } else {
            wake->hidden = 0;
            wake->scale.x = distance;
            wake->scale.y = distance;
            wake->scale.z = distance;
        }
        wake->lastPos = mmdlPos;
    }
    func_021ACCB0(effect, work);
}

/* Surf Pokemon effect draw for grid models. */
void func_021ACFD8(FieldEffectObj *effect, NamipokeWork *work)
{
    FieldG3dObjSys *g3dObjSys = func_021ABE18(work->param.res->fieldEffect);

    func_021C67F4(g3dObjSys, work->waveObjId);
    func_021C67F4(g3dObjSys, work->wake.objId);
}

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

/* Surf Pokemon effect update for rail models: the facing is a direction vector. */
void func_021ACFF8(FieldEffectObj *effect, NamipokeWork *work)
{
    VecFx32 drawOffset = {0, 0, 0};
    VecFx32 pos;
    VecFx32 mmdlPos;
    s16 baseDir[3];
    s16 faceDir[3];
    NamipokeWake *wake;
    s32 distance;
    s32 scale;

    if (work->followMode == NAMIPOKE_MODE_STATIC)
        return;
    work->facing = func_0216D5F8(work->param.mmdl);
    func_0219E784(work->param.mmdl, 0, baseDir);
    func_0219E784(work->param.mmdl, work->facing, faceDir);
    baseDir[1] = 0;
    func_0207CDB8(baseDir, baseDir);
    faceDir[1] = 0;
    func_0207CDB8(faceDir, faceDir);
    if (work->followMode == NAMIPOKE_MODE_BOB) {
        work->bobHeight += work->bobStep;
        if (work->bobHeight >= NAMIPOKE_BOB_MAX) {
            work->bobHeight = NAMIPOKE_BOB_MAX;
            work->bobStep = -work->bobStep;
        } else if (work->bobHeight <= NAMIPOKE_BOB_MIN) {
            work->bobHeight = NAMIPOKE_BOB_MIN;
            work->bobStep = -work->bobStep;
        }
        drawOffset.x = FX_Mul(-baseDir[0], 0x7000);
        drawOffset.y = work->bobHeight + 0x5000;
        drawOffset.z = FX_Mul(-baseDir[2], 0x7000);
        func_0216D8E0(work->param.mmdl, &drawOffset);
    }
    func_02197CCC(work->param.mmdl, &pos);
    pos.x -= drawOffset.x;
    pos.y -= drawOffset.y;
    pos.z -= drawOffset.z;
    pos.y += work->bobHeight - 0x1000;
    func_021AC1CC(effect, &pos);
    if (work->followMode == NAMIPOKE_MODE_MODEL_OFFSET || work->wakeDisabled == 1) {
        wake = &work->wake;
        wake->dir = NAMIPOKE_DIR_NONE;
        if (work->wakeDisabled == 1)
            wake->hidden = 1;
    } else {
        wake = &work->wake;
        func_021C66EC(func_021ABE18(work->param.res->fieldEffect), wake->objId, 0x1000);
        func_0216D88C(work->param.mmdl, &mmdlPos);
        if (work->facing != wake->dir) {
            wake->dir = work->facing;
            wake->tailPos = mmdlPos;
        } else if (mmdlPos.x == wake->lastPos.x && mmdlPos.y == wake->lastPos.y && mmdlPos.z == wake->lastPos.z) {
            wake->tailPos.x += FX_Mul(faceDir[0], NAMIPOKE_WAKE_TAIL_STEP);
            wake->tailPos.z += FX_Mul(faceDir[2], NAMIPOKE_WAKE_TAIL_STEP);
            wake->tailPos.y = mmdlPos.y;
            if (faceDir[0] > 0) {
                if (wake->tailPos.x > mmdlPos.x)
                    wake->tailPos.x = mmdlPos.x;
            } else if (faceDir[0] < 0) {
                if (wake->tailPos.x < mmdlPos.x)
                    wake->tailPos.x = mmdlPos.x;
            }
            if (faceDir[2] > 0) {
                if (wake->tailPos.z > mmdlPos.z)
                    wake->tailPos.z = mmdlPos.z;
            } else if (faceDir[2] < 0) {
                if (wake->tailPos.z < mmdlPos.z)
                    wake->tailPos.z = mmdlPos.z;
            }
        }
        distance = func_0207CF3C(&mmdlPos, &wake->tailPos);
        if (distance >= NAMIPOKE_WAKE_MAX_LENGTH) {
            wake->tailPos.x = mmdlPos.x - FX_Mul(faceDir[0], NAMIPOKE_WAKE_MAX_LENGTH);
            wake->tailPos.z = mmdlPos.z - FX_Mul(faceDir[2], NAMIPOKE_WAKE_MAX_LENGTH);
        }
        scale = func_021ACBE4(distance);
        if (scale <= 0x28) {
            wake->hidden = 1;
        } else {
            wake->hidden = 0;
            wake->scale.x = scale;
            wake->scale.y = scale;
            wake->scale.z = scale;
        }
        wake->lastPos = mmdlPos;
    }
}

/* Surf Pokemon effect draw for rail models: places the wave and the wake along the direction vector, then draws. */
void func_021AD274(FieldEffectObj *effect, NamipokeWork *work)
{
    VecFx32 forward;
    VecFx32 backward;
    MtxFx33 forwardMtx;
    MtxFx33 backwardMtx;
    s16 faceDir[3];
    NamipokeWake *wake = &work->wake;
    FieldG3dObjSys *g3dObjSys;
    G3dObjectStatus *status;

    func_0219E784(work->param.mmdl, work->facing, faceDir);
    forward.x = faceDir[0];
    forward.y = 0;
    forward.z = faceDir[2];
    backward.x = -faceDir[0];
    backward.y = 0;
    backward.z = -faceDir[2];
    func_020521BC(&forward, &forwardMtx);
    func_020521BC(&backward, &backwardMtx);
    g3dObjSys = func_021ABE18(work->param.res->fieldEffect);
    status = func_021C6658(g3dObjSys, work->waveObjId);
    status->rotate = forwardMtx;
    func_021AC1B8(effect, &status->trans);
    if (work->wake.hidden == 0) {
        func_021C6678(g3dObjSys, wake->objId, 0);
        status = func_021C6658(g3dObjSys, wake->objId);
        status->rotate = backwardMtx;
        func_021AC1B8(effect, &status->trans);
        status->trans.x = status->trans.x + (wake->offset.x - FX_Mul(forward.x, 0xE000));
        status->trans.y = status->trans.y + (wake->offset.y - 0x4000 - FX_Mul(forward.y, 0xE000));
        status->trans.z = status->trans.z + (wake->offset.z - FX_Mul(forward.z, 0xE000));
        status->scale = wake->scale;
    } else {
        func_021C6678(g3dObjSys, wake->objId, 1);
    }
    func_021C67F4(g3dObjSys, work->waveObjId);
    func_021C67F4(g3dObjSys, wake->objId);
}

/* Creates the resources of the splash effects. */
NamipokeSplashRes *func_021AD3D4(FieldEffectSys *fieldEffect, int heapId)
{
    NamipokeSplashRes *res;

    res = func_02030734(heapId, 0x10, 1, d_021DE080, 0x3cf);
    res->fieldEffect = fieldEffect;
    func_021AD410(res);
    return res;
}

/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD3FC(FieldEffectSys *fieldEffect, NamipokeSplashRes *res)
{
    func_021AD530(res);
    func_020307B0(res);
}

/*
 * Addresses are Black-image addresses.
 *
 * The buffer handle desc is assigned after the func_021ABE24 call, but the
 * first func_021C6AE0 call takes the buffer itself, so a call lies between
 * the assignment and the first read of desc. That keeps desc a register variable
 * (r7) instead of a rematerialised address, and the repeated 0 argument is
 * rebuilt per call. See docs/idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md.
 */
/* Loads the five splash models, each with two animations. */
void func_021AD410(NamipokeSplashRes *res)
{
    FieldG3dResDesc buf;
    FieldG3dObjSys *g3dObjSys;
    ArcHandle *arc;
    u32 desc;
    g3dObjSys = func_021ABE18(res->fieldEffect);
    arc = func_021ABE24(res->fieldEffect);
    desc = (u32)&buf;
    func_021C6AE0(&buf);
    func_021C6AF0((FieldG3dResDesc *)desc, arc, 0x37);
    func_021C6AF8((FieldG3dResDesc *)desc, arc);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x80);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x6c);
    res->modelResId[0] = func_021C6574(g3dObjSys, (FieldG3dResDesc *)desc, 0);
    func_021C6AE0(&buf);
    func_021C6AF0((FieldG3dResDesc *)desc, arc, 0x3a);
    func_021C6AF8((FieldG3dResDesc *)desc, arc);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x6f);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x63);
    res->modelResId[1] = func_021C6574(g3dObjSys, (FieldG3dResDesc *)desc, 0);
    func_021C6AE0(&buf);
    func_021C6AF0((FieldG3dResDesc *)desc, arc, 0x39);
    func_021C6AF8((FieldG3dResDesc *)desc, arc);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x6e);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x62);
    res->modelResId[3] = func_021C6574(g3dObjSys, (FieldG3dResDesc *)desc, 0);
    func_021C6AE0(&buf);
    func_021C6AF0((FieldG3dResDesc *)desc, arc, 0x3b);
    func_021C6AF8((FieldG3dResDesc *)desc, arc);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x70);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x64);
    res->modelResId[2] = func_021C6574(g3dObjSys, (FieldG3dResDesc *)desc, 0);
    func_021C6AE0(&buf);
    func_021C6AF0((FieldG3dResDesc *)desc, arc, 0x38);
    func_021C6AF8((FieldG3dResDesc *)desc, arc);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x6d);
    func_021C6AFC((FieldG3dResDesc *)desc, 0x61);
    res->modelResId[4] = func_021C6574(g3dObjSys, (FieldG3dResDesc *)desc, 0);
}

void func_021AD530(NamipokeSplashRes *res)
{
    FieldG3dObjSys *g3dObjSys = func_021ABE18(res->fieldEffect);

    func_021C6580(g3dObjSys, res->modelResId[0]);
    func_021C6580(g3dObjSys, res->modelResId[1]);
    func_021C6580(g3dObjSys, res->modelResId[3]);
    func_021C6580(g3dObjSys, res->modelResId[2]);
    func_021C6580(g3dObjSys, res->modelResId[4]);
}

/* Starts a splash of the type that follows another effect and ends with it. */
void func_021AD564(FieldEffectSys *fieldEffect, int type, FieldEffectObj *parent)
{
    NamipokeSplashStartParam param;

    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_NAMIPOKE_SPLASH);
    param.type = type;
    param.parent = parent;
    param.deleteWhenDone = 0;
    func_021ABFA8(fieldEffect, &d_021D9170, 0, 0, &param, 1);
}

/* Starts a splash of the type at a position; it ends with its animation. */
void func_021AD598(FieldEffectSys *fieldEffect, int type, const VecFx32 *pos)
{
    NamipokeSplashStartParam param;

    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_NAMIPOKE_SPLASH);
    param.type = type;
    param.parent = 0;
    param.deleteWhenDone = 1;
    func_021ABFA8(fieldEffect, &d_021D9170, pos, 0, &param, 1);
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
/* Returns 1 when the splash has played its animation, or the effect is gone. */
int func_021AD5CC(FieldEffectObj *effect)
{
    if (effect != 0) {
        return ((NamipokeSplashWork *)func_021AC1E0(effect))->finished;
    }
    return 1;
}

/* Splash init: takes the parameter, makes the model object and offsets it from the parent. */
void func_021AD5E0(FieldEffectObj *effect, NamipokeSplashWork *work)
{
    VecFx32 parentPos;
    NamipokeSplashOffsets offsets;
    FieldG3dObjSys *g3dObjSys;
    int modelResId;
    NamipokeSplashRes *res;

    work->param = *(NamipokeSplashStartParam *)func_021AC1AC(effect);
    res = work->param.res;
    g3dObjSys = func_021ABE18(res->fieldEffect);
    switch (work->param.type) {
    case 0:
        modelResId = work->param.res->modelResId[0];
        break;
    case 1:
        modelResId = work->param.res->modelResId[1];
        break;
    case 2:
        modelResId = work->param.res->modelResId[3];
        break;
    case 3:
        modelResId = work->param.res->modelResId[2];
        break;
    case 4:
        modelResId = work->param.res->modelResId[4];
        break;
    default:
        goto moveToParent;
    }
    work->objId = func_021C6590(g3dObjSys, modelResId, 0, 0);
moveToParent:
    if (work->param.parent != 0) {
        offsets = d_021D91F8;
        work->offset = offsets.type[work->param.type];
        func_021AC1B8(work->param.parent, &parentPos);
        parentPos.x += work->offset.x;
        parentPos.y += work->offset.y;
        parentPos.z += work->offset.z;
        func_021AC1CC(effect, &parentPos);
    }
}

/* Splash exit: deletes the model object. */
int func_021AD6A4(FieldEffectObj *effect, NamipokeSplashWork *work, u32 unused0, u32 unused1)
{
    return func_021C6628(func_021ABE18(work->param.res->fieldEffect), work->objId);
}

/* Splash update: plays the animation and follows the parent. */
void func_021AD6B8(FieldEffectObj *effect, NamipokeSplashWork *work)
{
    VecFx32 parentPos;
    FieldG3dObjSys *g3dObjSys;

    if (work->finished == 1 && work->param.deleteWhenDone == 1) {
        func_021AC154(effect);
        return;
    }
    g3dObjSys = func_021ABE18(work->param.res->fieldEffect);
    if (work->param.type == 0) {
        if (work->finished == 0) {
            if (func_021C6694(g3dObjSys, work->objId, 0x1000) == 0) {
                work->finished = 1;
            }
        }
    } else {
        func_021C66EC(g3dObjSys, work->objId, 0x1000);
    }
    if (work->param.parent != 0) {
        func_021AC1B8(work->param.parent, &parentPos);
        parentPos.x += work->offset.x;
        parentPos.y += work->offset.y;
        parentPos.z += work->offset.z;
        func_021AC1CC(effect, &parentPos);
    }
}

/* Splash draw: moves the model object to the effect position. */
void func_021AD738(FieldEffectObj *effect, NamipokeSplashWork *work)
{
    func_021AC1B8(effect, &func_021C6658(func_021ABE18(work->param.res->fieldEffect), work->objId)->trans);
}
