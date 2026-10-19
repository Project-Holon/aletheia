/*
 * file:     fldeff_namipoke.c
 * unit:     yes
 * function: FLDEFF_NAMIPOKE_Create, FLDEFF_NAMIPOKE_Delete, FLDEFF_NAMIPOKE_LoadResources, FLDEFF_NAMIPOKE_FreeResources, FLDEFF_NAMIPOKE_Start, FLDEFF_NAMIPOKE_SetFollowMode, FLDEFF_NAMIPOKE_SetWakeEnabled, FLDEFF_NAMIPOKE_GetWakeScale, FLDEFF_NAMIPOKE_GetWakeLength, FLDEFF_NAMIPOKE_Init, FLDEFF_NAMIPOKE_Exit, FLDEFF_NAMIPOKE_PlaceObjects, FLDEFF_NAMIPOKE_UpdateGrid, FLDEFF_NAMIPOKE_DrawGrid, FLDEFF_NAMIPOKE_UpdateRail, FLDEFF_NAMIPOKE_DrawRail, FLDEFF_NAMIPOKE_SPLASH_Create, FLDEFF_NAMIPOKE_SPLASH_Delete, FLDEFF_NAMIPOKE_SPLASH_LoadResources, FLDEFF_NAMIPOKE_SPLASH_FreeResources, FLDEFF_NAMIPOKE_SPLASH_StartOnEffect, FLDEFF_NAMIPOKE_SPLASH_StartAtPos, FLDEFF_NAMIPOKE_SPLASH_IsFinished, FLDEFF_NAMIPOKE_SPLASH_Init, FLDEFF_NAMIPOKE_SPLASH_Exit, FLDEFF_NAMIPOKE_SPLASH_Update, FLDEFF_NAMIPOKE_SPLASH_Draw
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
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_GetObjectMode  0x021AC1A0  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   sFldeffNamipokeFileName  0x021DE080  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectManualDraw  0x021C67D8  thumb  ov021
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sNamipokeRailFuncs     0x021D915C  data  a4
 *   sNamipokeGridFuncs     0x021D9184  data  a4
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 *   sNamipokeWaveAngles     0x021D9198  data  a2
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov021
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   sNamipokeWakeOffsets     0x021D91C8  data  a4
 *   sNamipokeWakeAngles     0x021D91B0  data  a2
 *   FIELD_G3DOBJ_SetObjectHidden  0x021C6678  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 *   FLDMMDL_GetDrawOffsetOutside  0x0216D8D0  thumb  ov010
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FIELD_G3DOBJ_LoopAnimeFrame  0x021C66EC  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_G3DOBJ_DrawObject  0x021C67F4  thumb  ov021
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   BUTTON_MAN_MakeLookAtMtx  0x020521BC  arm
 *   sNamipokeSplashFuncs  0x021D9170  data
 *   sNamipokeSplashOffsets     0x021D91F8  data  a4
 *   FIELD_G3DOBJ_IncAnimeFrame  0x021C6694  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
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

/* Resources of the surf Pokemon effect (allocated 0xC bytes by FLDEFF_NAMIPOKE_Create). */
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

/* Models of the splash effects around the surf Pokemon (allocated 0x10 bytes by FLDEFF_NAMIPOKE_SPLASH_Create). */
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

extern u16 FLDMMDL_GetObjId(Mmdl *mmdl);
extern u16 FLDMMDL_GetZoneId(Mmdl *mmdl);
struct Mmdl;
extern u32 FLDMMDL_CheckStatusBit(struct Mmdl *mmdl, u32 bit);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
struct MmdlVec;
extern void FLDMMDL_SetDrawOffsetOutside(struct Mmdl *mmdl, struct MmdlVec *offset);
extern void FLDMMDL_GetDrawOffsetOutside(struct Mmdl *mmdl, struct MmdlVec *out);
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern void FLDMMDL_ACMD_GetDrawPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern void FLDMMDL_RAIL_GetDrawOffsetByDir(Mmdl *mmdl, u32 dir, s16 *out);
extern void VEC_Fx16Normalize(s16 *in, s16 *out);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, MtxFx33 *dst);
extern void BUTTON_MAN_MakeLookAtMtx(const VecFx32 *v, MtxFx33 *dst);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern FieldG3dObjSys *FIELD_EFFECT_GetFieldMapData(FieldEffectSys *fieldEffect);
extern u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern s32 FIELD_EFFECT_GetResource(struct FieldEffectSys *sys, s32 id);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void FIELD_EFFECT_DeleteObject(FieldEffectObj *effect);
extern void FIELD_EFFECT_UpdateObject(FieldEffectObj *effect);
extern int FIELD_EFFECT_GetObjectMode(FieldEffectObj *effect);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern void FIELD_EFFECT_GetObjectPos(FieldEffectObj *effect, VecFx32 *out);
extern void FIELD_EFFECT_SetObjectPos(FieldEffectObj *effect, const VecFx32 *pos);
extern void *FIELD_EFFECT_GetObjectWork(FieldEffectObj *effect);
struct FieldG3dObjResDesc;
extern void FIELD_G3DOBJ_InitResDesc(struct FieldG3dObjResDesc *desc);
extern int FIELD_G3DOBJ_SetResDescModel(FieldG3dResDesc *desc, ArcHandle *arc, u32 modelFile);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(struct FieldG3dObjResDesc *desc, u32 arc);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(struct FieldG3dObjResDesc *desc, u16 file);
struct FieldG3dObjCtrl;
extern int FIELD_G3DOBJ_AddResourceDefaultPal(struct FieldG3dObjCtrl *ctrl, struct FieldG3dObjResDesc *desc, s32 mode);
extern u16 FIELD_G3DOBJ_AddObject(FieldG3dObjSys *g3dObjSys, u32 resId, u32 modelIdx, u32 pos);
extern void FIELD_G3DOBJ_SetObjectManualDraw(struct FieldG3dObjCtrl *ctrl, s32 objIdx, s32 manualDraw);
extern u32 FIELD_G3DOBJ_DeleteObject(FieldG3dObjSys *g3dObjSys, u32 objId);
extern void FIELD_G3DOBJ_DeleteResource(struct FieldG3dObjCtrl *ctrl, s32 resIdx);
extern G3dObjectStatus *FIELD_G3DOBJ_GetObjectTrans(FieldG3dObjSys *g3dObjSys, u32 objId);
extern void FIELD_G3DOBJ_SetObjectHidden(struct FieldG3dObjCtrl *ctrl, s32 objIdx, s32 hidden);
extern int FIELD_G3DOBJ_LoopAnimeFrame(struct FieldG3dObjCtrl *ctrl, s32 objIdx, s32 speed);
extern int FIELD_G3DOBJ_IncAnimeFrame(struct FieldG3dObjCtrl *ctrl, s32 objIdx, s32 speed);
extern void FIELD_G3DOBJ_DrawObject(struct FieldG3dObjCtrl *ctrl, s32 objIdx);

NamipokeRes *FLDEFF_NAMIPOKE_Create(FieldEffectSys *fieldEffect, int heapId);
void FLDEFF_NAMIPOKE_Delete(FieldEffectSys *fieldEffect, NamipokeRes *res);
void FLDEFF_NAMIPOKE_LoadResources(NamipokeRes *res);
void FLDEFF_NAMIPOKE_FreeResources(NamipokeRes *res);
void FLDEFF_NAMIPOKE_Start(FieldEffectSys *fieldEffect, u32 facing, const VecFx32 *pos, Mmdl *mmdl, u32 followMode);
void FLDEFF_NAMIPOKE_SetFollowMode(FieldEffectObj *effect, u8 followMode);
void FLDEFF_NAMIPOKE_SetWakeEnabled(FieldEffectObj *effect, int wakeEnabled);
int FLDEFF_NAMIPOKE_GetWakeScale(int distance);
int FLDEFF_NAMIPOKE_GetWakeLength(const VecFx32 *from, const VecFx32 *to, u32 dir);
void FLDEFF_NAMIPOKE_Init(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_Exit(void);
void FLDEFF_NAMIPOKE_PlaceObjects(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_UpdateGrid(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_DrawGrid(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_UpdateRail(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_DrawRail(FieldEffectObj *effect, NamipokeWork *work);
NamipokeSplashRes *FLDEFF_NAMIPOKE_SPLASH_Create(FieldEffectSys *fieldEffect, int heapId);
void FLDEFF_NAMIPOKE_SPLASH_Delete(FieldEffectSys *fieldEffect, NamipokeSplashRes *res);
void FLDEFF_NAMIPOKE_SPLASH_LoadResources(NamipokeSplashRes *res);
void FLDEFF_NAMIPOKE_SPLASH_FreeResources(NamipokeSplashRes *res);
void FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FieldEffectSys *fieldEffect, int type, FieldEffectObj *parent);
void FLDEFF_NAMIPOKE_SPLASH_StartAtPos(FieldEffectSys *fieldEffect, int type, const VecFx32 *pos);
int FLDEFF_NAMIPOKE_SPLASH_IsFinished(FieldEffectObj *effect);
void FLDEFF_NAMIPOKE_SPLASH_Init(FieldEffectObj *effect, NamipokeSplashWork *work);
int FLDEFF_NAMIPOKE_SPLASH_Exit(FieldEffectObj *effect, NamipokeSplashWork *work, u32 unused0, u32 unused1);
void FLDEFF_NAMIPOKE_SPLASH_Update(FieldEffectObj *effect, NamipokeSplashWork *work);
void FLDEFF_NAMIPOKE_SPLASH_Draw(FieldEffectObj *effect, NamipokeSplashWork *work);
extern char sFldeffNamipokeFileName[];                           /* source file name for the heap allocator */
extern const FieldEffectObjFuncs sNamipokeRailFuncs;        /* surf Pokemon effect callbacks, rail models */
extern const FieldEffectObjFuncs sNamipokeGridFuncs;        /* surf Pokemon effect callbacks, grid models */
extern NamipokeAngleTable sNamipokeWaveAngles;               /* wave rotation of each facing */
extern NamipokeOffsetTable sNamipokeWakeOffsets;              /* wake offset of each facing */
extern NamipokeAngleTable sNamipokeWakeAngles;               /* wake rotation of each facing */
extern const FieldEffectObjFuncs sNamipokeSplashFuncs;        /* splash effect callbacks */
extern NamipokeSplashOffsets sNamipokeSplashOffsets;            /* splash offset of each type */

/* Creates the resources of the surf Pokemon effect. */
NamipokeRes *FLDEFF_NAMIPOKE_Create(FieldEffectSys *fieldEffect, int heapId)
{
    NamipokeRes *res;

    res = GFL_HEAP_Alloc(heapId, 0xc, 1, sFldeffNamipokeFileName, 0xac);
    res->fieldEffect = fieldEffect;
    FLDEFF_NAMIPOKE_LoadResources(res);
    return res;
}

/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void FLDEFF_NAMIPOKE_Delete(FieldEffectSys *fieldEffect, NamipokeRes *res)
{
    FLDEFF_NAMIPOKE_FreeResources(res);
    GFL_HEAP_Free(res);
}

/* Loads the wave model, and the wake model with its two animations. */
void FLDEFF_NAMIPOKE_LoadResources(NamipokeRes *res)
{
    FieldG3dResDesc desc;
    FieldG3dObjSys *g3dObjSys = FIELD_EFFECT_GetFieldMapData(res->fieldEffect);
    ArcHandle *arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&desc));
    FIELD_G3DOBJ_SetResDescModel(&desc, arc, 0x31);
    res->waveResId = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)(&desc), 0);
    res->waveObjId = FIELD_G3DOBJ_AddObject(g3dObjSys, res->waveResId, 0, 0);
    FIELD_G3DOBJ_SetObjectManualDraw((struct FieldG3dObjCtrl *)g3dObjSys, res->waveObjId, 1);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&desc));
    FIELD_G3DOBJ_SetResDescModel(&desc, arc, 0x36);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)(&desc), (u32)arc);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)(&desc), 0x6b);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)(&desc), 0x85);
    res->wakeResId = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)(&desc), 0);
    res->wakeObjId = FIELD_G3DOBJ_AddObject(g3dObjSys, res->wakeResId, 0, 0);
    FIELD_G3DOBJ_SetObjectManualDraw((struct FieldG3dObjCtrl *)g3dObjSys, res->wakeObjId, 1);
}

void FLDEFF_NAMIPOKE_FreeResources(NamipokeRes *res)
{
    FieldG3dObjSys *g3dObjSys = FIELD_EFFECT_GetFieldMapData(res->fieldEffect);

    FIELD_G3DOBJ_DeleteObject(g3dObjSys, res->waveObjId);
    FIELD_G3DOBJ_DeleteObject(g3dObjSys, res->wakeObjId);
    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->waveResId);
    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->wakeResId);
}

/* Starts a surf Pokemon effect on a model. */
void FLDEFF_NAMIPOKE_Start(FieldEffectSys *fieldEffect, u32 facing, const VecFx32 *pos, Mmdl *mmdl, u32 followMode)
{
    NamipokeStartParam param;
    param.res = (struct NamipokeRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_NAMIPOKE);
    param.mmdl = mmdl;
    param.objId = FLDMMDL_GetObjId(mmdl);
    param.zoneId = FLDMMDL_GetZoneId(mmdl);
    param.facing = facing;
    param.pos = *pos;
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_RAIL_MOVE) != 0)
        FIELD_EFFECT_AddObject(fieldEffect, &sNamipokeRailFuncs, &param.pos, followMode, &param, 0);
    else
        FIELD_EFFECT_AddObject(fieldEffect, &sNamipokeGridFuncs, &param.pos, followMode, &param, 0);
}

void FLDEFF_NAMIPOKE_SetFollowMode(FieldEffectObj *effect, u8 followMode)
{
    if (effect != 0)
        ((NamipokeWork *)FIELD_EFFECT_GetObjectWork(effect))->followMode = followMode;
}

void FLDEFF_NAMIPOKE_SetWakeEnabled(FieldEffectObj *effect, int wakeEnabled)
{
    NamipokeWork *work;

    if (effect != 0) {
        work = FIELD_EFFECT_GetObjectWork(effect);
        if (wakeEnabled == 1)
            work->wakeDisabled = 0;
        else
            work->wakeDisabled = 1;
    }
}

/* Wake scale for a wake of the given length. */
int FLDEFF_NAMIPOKE_GetWakeScale(int distance)
{
    if (distance > NAMIPOKE_WAKE_MAX_LENGTH)
        distance = NAMIPOKE_WAKE_MAX_LENGTH;
    return distance / 0xA3D * 0x28;
}

/* Length of the wake from the tail position to the model position, measured along the facing. */
int FLDEFF_NAMIPOKE_GetWakeLength(const VecFx32 *from, const VecFx32 *to, u32 dir)
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
void FLDEFF_NAMIPOKE_Init(FieldEffectObj *effect, NamipokeWork *work)
{
    NamipokeStartParam *param = FIELD_EFFECT_GetObjectParam(effect);
    NamipokeWake *wake;
    u32 unit = 0x1000;
    work->param = *param;
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
    work->facing = param->facing;
    FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect);
    work->waveObjId = work->param.res->waveObjId;
    work->followMode = FIELD_EFFECT_GetObjectMode(effect);
    work->bobHeight = unit;
    work->bobStep = unit >> 2;
    wake = &work->wake;
    wake->objId = work->param.res->wakeObjId;
    work->wake.hidden = 1;
    wake->dir = NAMIPOKE_DIR_NONE;
    wake->scale.x = unit;
    wake->scale.y = unit;
    wake->scale.z = unit;
    FIELD_EFFECT_UpdateObject(effect);
}

void FLDEFF_NAMIPOKE_Exit(void) {}

/* Places the wave and the wake: rotates the wave to the facing and lays the wake behind the model. */
void FLDEFF_NAMIPOKE_PlaceObjects(FieldEffectObj *effect, NamipokeWork *work)
{
    NamipokeAngleTable waveAngles = sNamipokeWaveAngles;
    NamipokeAngle *waveAngle = &waveAngles.dir[work->facing];
    FieldG3dObjSys *g3dObjSys;
    G3dObjectStatus *status;

    g3dObjSys = FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect);
    status = FIELD_G3DOBJ_GetObjectTrans(g3dObjSys, work->waveObjId);
    BUTTON_MAN_MakeRotMtxXYZ(waveAngle->x, waveAngle->y, waveAngle->z, &status->rotate);
    FIELD_EFFECT_GetObjectPos(effect, &status->trans);
    if (work->wake.hidden == 0) {
        NamipokeWake *wake = &work->wake;
        NamipokeOffsetTable wakeOffsets = sNamipokeWakeOffsets;
        NamipokeAngleTable wakeAngles = sNamipokeWakeAngles;
        VecFx32 *wakeOffset = &wakeOffsets.dir[work->facing];
        NamipokeAngle *wakeAngle = &wakeAngles.dir[work->facing];
        status = FIELD_G3DOBJ_GetObjectTrans(g3dObjSys, wake->objId);
        BUTTON_MAN_MakeRotMtxXYZ(wakeAngle->x, wakeAngle->y, wakeAngle->z, &status->rotate);
        FIELD_EFFECT_GetObjectPos(effect, &status->trans);
        status->trans.x = status->trans.x + (wake->offset.x + wakeOffset->x);
        status->trans.y = status->trans.y + (wake->offset.y + wakeOffset->y);
        status->trans.z = status->trans.z + (wake->offset.z + wakeOffset->z);
        status->scale = wake->scale;
        FIELD_G3DOBJ_SetObjectHidden((struct FieldG3dObjCtrl *)g3dObjSys, wake->objId, 0);
    } else {
        FIELD_G3DOBJ_SetObjectHidden((struct FieldG3dObjCtrl *)g3dObjSys, work->wake.objId, 1);
    }
}

/*
 * Addresses are Black-image addresses.
 */
/* Surf Pokemon effect update for grid models: bobs, follows the model and stretches the wake. */
void FLDEFF_NAMIPOKE_UpdateGrid(FieldEffectObj *effect, NamipokeWork *work)
{
    VecFx32 drawOffset = {0, 0, 0};
    VecFx32 pos;
    VecFx32 mmdlPos;
    NamipokeWake *wake;
    s32 distance;
    u16 objCode;

    if (work->followMode == NAMIPOKE_MODE_STATIC) {
        FLDEFF_NAMIPOKE_PlaceObjects(effect, work);
        return;
    }
    work->facing = FLDMMDL_GetDirDisp(work->param.mmdl);
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
        objCode = FLDMMDL_GetObjCode(work->param.mmdl);
        if (objCode == NAMIPOKE_TALL_OBJ_CODE_A || objCode == NAMIPOKE_TALL_OBJ_CODE_B)
            drawOffset.y = work->bobHeight + 0x8000;
        FLDMMDL_SetDrawOffsetOutside(work->param.mmdl, (struct MmdlVec *)(&drawOffset));
    } else if (work->followMode == NAMIPOKE_MODE_MODEL_OFFSET) {
        FLDMMDL_GetDrawOffsetOutside(work->param.mmdl, (struct MmdlVec *)(&drawOffset));
    }
    FLDMMDL_ACMD_GetDrawPos(work->param.mmdl, (struct MmdlVec *)(&pos));
    pos.x -= drawOffset.x;
    pos.y -= drawOffset.y;
    pos.z -= drawOffset.z;
    if (work->followMode != NAMIPOKE_MODE_MODEL_OFFSET)
        pos.y += work->bobHeight - 0x1000;
    FIELD_EFFECT_SetObjectPos(effect, &pos);
    if (work->followMode == NAMIPOKE_MODE_MODEL_OFFSET || work->wakeDisabled == 1) {
        wake = &work->wake;
        wake->dir = NAMIPOKE_DIR_NONE;
        if (work->wakeDisabled == 1)
            wake->hidden = 1;
    } else {
        wake = &work->wake;
        FIELD_G3DOBJ_LoopAnimeFrame((struct FieldG3dObjCtrl *)(FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect)), wake->objId, 0x1000);
        FLDMMDL_GetPos(work->param.mmdl, (struct MmdlVec *)(&mmdlPos));
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
        distance = FLDEFF_NAMIPOKE_GetWakeLength(&mmdlPos, &wake->tailPos, wake->dir);
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
        distance = FLDEFF_NAMIPOKE_GetWakeScale(distance);
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
    FLDEFF_NAMIPOKE_PlaceObjects(effect, work);
}

/* Surf Pokemon effect draw for grid models. */
void FLDEFF_NAMIPOKE_DrawGrid(FieldEffectObj *effect, NamipokeWork *work)
{
    FieldG3dObjSys *g3dObjSys = FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect);

    FIELD_G3DOBJ_DrawObject((struct FieldG3dObjCtrl *)g3dObjSys, work->waveObjId);
    FIELD_G3DOBJ_DrawObject((struct FieldG3dObjCtrl *)g3dObjSys, work->wake.objId);
}

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

/* Surf Pokemon effect update for rail models: the facing is a direction vector. */
void FLDEFF_NAMIPOKE_UpdateRail(FieldEffectObj *effect, NamipokeWork *work)
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
    work->facing = FLDMMDL_GetDirDisp(work->param.mmdl);
    FLDMMDL_RAIL_GetDrawOffsetByDir(work->param.mmdl, 0, baseDir);
    FLDMMDL_RAIL_GetDrawOffsetByDir(work->param.mmdl, work->facing, faceDir);
    baseDir[1] = 0;
    VEC_Fx16Normalize(baseDir, baseDir);
    faceDir[1] = 0;
    VEC_Fx16Normalize(faceDir, faceDir);
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
        FLDMMDL_SetDrawOffsetOutside(work->param.mmdl, (struct MmdlVec *)(&drawOffset));
    }
    FLDMMDL_ACMD_GetDrawPos(work->param.mmdl, (struct MmdlVec *)(&pos));
    pos.x -= drawOffset.x;
    pos.y -= drawOffset.y;
    pos.z -= drawOffset.z;
    pos.y += work->bobHeight - 0x1000;
    FIELD_EFFECT_SetObjectPos(effect, &pos);
    if (work->followMode == NAMIPOKE_MODE_MODEL_OFFSET || work->wakeDisabled == 1) {
        wake = &work->wake;
        wake->dir = NAMIPOKE_DIR_NONE;
        if (work->wakeDisabled == 1)
            wake->hidden = 1;
    } else {
        wake = &work->wake;
        FIELD_G3DOBJ_LoopAnimeFrame((struct FieldG3dObjCtrl *)(FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect)), wake->objId, 0x1000);
        FLDMMDL_GetPos(work->param.mmdl, (struct MmdlVec *)(&mmdlPos));
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
        distance = VEC_Distance(&mmdlPos, &wake->tailPos);
        if (distance >= NAMIPOKE_WAKE_MAX_LENGTH) {
            wake->tailPos.x = mmdlPos.x - FX_Mul(faceDir[0], NAMIPOKE_WAKE_MAX_LENGTH);
            wake->tailPos.z = mmdlPos.z - FX_Mul(faceDir[2], NAMIPOKE_WAKE_MAX_LENGTH);
        }
        scale = FLDEFF_NAMIPOKE_GetWakeScale(distance);
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
void FLDEFF_NAMIPOKE_DrawRail(FieldEffectObj *effect, NamipokeWork *work)
{
    VecFx32 forward;
    VecFx32 backward;
    MtxFx33 forwardMtx;
    MtxFx33 backwardMtx;
    s16 faceDir[3];
    NamipokeWake *wake = &work->wake;
    FieldG3dObjSys *g3dObjSys;
    G3dObjectStatus *status;

    FLDMMDL_RAIL_GetDrawOffsetByDir(work->param.mmdl, work->facing, faceDir);
    forward.x = faceDir[0];
    forward.y = 0;
    forward.z = faceDir[2];
    backward.x = -faceDir[0];
    backward.y = 0;
    backward.z = -faceDir[2];
    BUTTON_MAN_MakeLookAtMtx(&forward, &forwardMtx);
    BUTTON_MAN_MakeLookAtMtx(&backward, &backwardMtx);
    g3dObjSys = FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect);
    status = FIELD_G3DOBJ_GetObjectTrans(g3dObjSys, work->waveObjId);
    status->rotate = forwardMtx;
    FIELD_EFFECT_GetObjectPos(effect, &status->trans);
    if (work->wake.hidden == 0) {
        FIELD_G3DOBJ_SetObjectHidden((struct FieldG3dObjCtrl *)g3dObjSys, wake->objId, 0);
        status = FIELD_G3DOBJ_GetObjectTrans(g3dObjSys, wake->objId);
        status->rotate = backwardMtx;
        FIELD_EFFECT_GetObjectPos(effect, &status->trans);
        status->trans.x = status->trans.x + (wake->offset.x - FX_Mul(forward.x, 0xE000));
        status->trans.y = status->trans.y + (wake->offset.y - 0x4000 - FX_Mul(forward.y, 0xE000));
        status->trans.z = status->trans.z + (wake->offset.z - FX_Mul(forward.z, 0xE000));
        status->scale = wake->scale;
    } else {
        FIELD_G3DOBJ_SetObjectHidden((struct FieldG3dObjCtrl *)g3dObjSys, wake->objId, 1);
    }
    FIELD_G3DOBJ_DrawObject((struct FieldG3dObjCtrl *)g3dObjSys, work->waveObjId);
    FIELD_G3DOBJ_DrawObject((struct FieldG3dObjCtrl *)g3dObjSys, wake->objId);
}

/* Creates the resources of the splash effects. */
NamipokeSplashRes *FLDEFF_NAMIPOKE_SPLASH_Create(FieldEffectSys *fieldEffect, int heapId)
{
    NamipokeSplashRes *res;

    res = GFL_HEAP_Alloc(heapId, 0x10, 1, sFldeffNamipokeFileName, 0x3cf);
    res->fieldEffect = fieldEffect;
    FLDEFF_NAMIPOKE_SPLASH_LoadResources(res);
    return res;
}

/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void FLDEFF_NAMIPOKE_SPLASH_Delete(FieldEffectSys *fieldEffect, NamipokeSplashRes *res)
{
    FLDEFF_NAMIPOKE_SPLASH_FreeResources(res);
    GFL_HEAP_Free(res);
}

/*
 * Addresses are Black-image addresses.
 *
 * The buffer handle desc is assigned after the FIELD_EFFECT_GetArcHandle call, but the
 * first FIELD_G3DOBJ_InitResDesc call takes the buffer itself, so a call lies between
 * the assignment and the first read of desc. That keeps desc a register variable
 * (r7) instead of a rematerialised address, and the repeated 0 argument is
 * rebuilt per call. See docs/idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md.
 */
/* Loads the five splash models, each with two animations. */
void FLDEFF_NAMIPOKE_SPLASH_LoadResources(NamipokeSplashRes *res)
{
    FieldG3dResDesc buf;
    FieldG3dObjSys *g3dObjSys;
    ArcHandle *arc;
    u32 desc;
    g3dObjSys = FIELD_EFFECT_GetFieldMapData(res->fieldEffect);
    arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    desc = (u32)&buf;
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&buf));
    FIELD_G3DOBJ_SetResDescModel((FieldG3dResDesc *)desc, arc, 0x37);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)desc, (u32)arc);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x80);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x6c);
    res->modelResId[0] = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)desc, 0);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&buf));
    FIELD_G3DOBJ_SetResDescModel((FieldG3dResDesc *)desc, arc, 0x3a);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)desc, (u32)arc);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x6f);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x63);
    res->modelResId[1] = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)desc, 0);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&buf));
    FIELD_G3DOBJ_SetResDescModel((FieldG3dResDesc *)desc, arc, 0x39);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)desc, (u32)arc);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x6e);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x62);
    res->modelResId[3] = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)desc, 0);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&buf));
    FIELD_G3DOBJ_SetResDescModel((FieldG3dResDesc *)desc, arc, 0x3b);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)desc, (u32)arc);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x70);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x64);
    res->modelResId[2] = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)desc, 0);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&buf));
    FIELD_G3DOBJ_SetResDescModel((FieldG3dResDesc *)desc, arc, 0x38);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)desc, (u32)arc);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x6d);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)desc, 0x61);
    res->modelResId[4] = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)desc, 0);
}

void FLDEFF_NAMIPOKE_SPLASH_FreeResources(NamipokeSplashRes *res)
{
    FieldG3dObjSys *g3dObjSys = FIELD_EFFECT_GetFieldMapData(res->fieldEffect);

    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->modelResId[0]);
    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->modelResId[1]);
    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->modelResId[3]);
    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->modelResId[2]);
    FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->modelResId[4]);
}

/* Starts a splash of the type that follows another effect and ends with it. */
void FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FieldEffectSys *fieldEffect, int type, FieldEffectObj *parent)
{
    NamipokeSplashStartParam param;

    param.res = (struct NamipokeSplashRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_NAMIPOKE_SPLASH);
    param.type = type;
    param.parent = parent;
    param.deleteWhenDone = 0;
    FIELD_EFFECT_AddObject(fieldEffect, &sNamipokeSplashFuncs, 0, 0, &param, 1);
}

/* Starts a splash of the type at a position; it ends with its animation. */
void FLDEFF_NAMIPOKE_SPLASH_StartAtPos(FieldEffectSys *fieldEffect, int type, const VecFx32 *pos)
{
    NamipokeSplashStartParam param;

    param.res = (struct NamipokeSplashRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_NAMIPOKE_SPLASH);
    param.type = type;
    param.parent = 0;
    param.deleteWhenDone = 1;
    FIELD_EFFECT_AddObject(fieldEffect, &sNamipokeSplashFuncs, pos, 0, &param, 1);
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
/* Returns 1 when the splash has played its animation, or the effect is gone. */
int FLDEFF_NAMIPOKE_SPLASH_IsFinished(FieldEffectObj *effect)
{
    if (effect != 0) {
        return ((NamipokeSplashWork *)FIELD_EFFECT_GetObjectWork(effect))->finished;
    }
    return 1;
}

/* Splash init: takes the parameter, makes the model object and offsets it from the parent. */
void FLDEFF_NAMIPOKE_SPLASH_Init(FieldEffectObj *effect, NamipokeSplashWork *work)
{
    VecFx32 parentPos;
    NamipokeSplashOffsets offsets;
    FieldG3dObjSys *g3dObjSys;
    int modelResId;
    NamipokeSplashRes *res;

    work->param = *(NamipokeSplashStartParam *)FIELD_EFFECT_GetObjectParam(effect);
    res = work->param.res;
    g3dObjSys = FIELD_EFFECT_GetFieldMapData(res->fieldEffect);
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
    work->objId = FIELD_G3DOBJ_AddObject(g3dObjSys, modelResId, 0, 0);
moveToParent:
    if (work->param.parent != 0) {
        offsets = sNamipokeSplashOffsets;
        work->offset = offsets.type[work->param.type];
        FIELD_EFFECT_GetObjectPos(work->param.parent, &parentPos);
        parentPos.x += work->offset.x;
        parentPos.y += work->offset.y;
        parentPos.z += work->offset.z;
        FIELD_EFFECT_SetObjectPos(effect, &parentPos);
    }
}

/* Splash exit: deletes the model object. */
int FLDEFF_NAMIPOKE_SPLASH_Exit(FieldEffectObj *effect, NamipokeSplashWork *work, u32 unused0, u32 unused1)
{
    return FIELD_G3DOBJ_DeleteObject(FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect), work->objId);
}

/* Splash update: plays the animation and follows the parent. */
void FLDEFF_NAMIPOKE_SPLASH_Update(FieldEffectObj *effect, NamipokeSplashWork *work)
{
    VecFx32 parentPos;
    FieldG3dObjSys *g3dObjSys;

    if (work->finished == 1 && work->param.deleteWhenDone == 1) {
        FIELD_EFFECT_DeleteObject(effect);
        return;
    }
    g3dObjSys = FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect);
    if (work->param.type == 0) {
        if (work->finished == 0) {
            if (FIELD_G3DOBJ_IncAnimeFrame((struct FieldG3dObjCtrl *)g3dObjSys, work->objId, 0x1000) == 0) {
                work->finished = 1;
            }
        }
    } else {
        FIELD_G3DOBJ_LoopAnimeFrame((struct FieldG3dObjCtrl *)g3dObjSys, work->objId, 0x1000);
    }
    if (work->param.parent != 0) {
        FIELD_EFFECT_GetObjectPos(work->param.parent, &parentPos);
        parentPos.x += work->offset.x;
        parentPos.y += work->offset.y;
        parentPos.z += work->offset.z;
        FIELD_EFFECT_SetObjectPos(effect, &parentPos);
    }
}

/* Splash draw: moves the model object to the effect position. */
void FLDEFF_NAMIPOKE_SPLASH_Draw(FieldEffectObj *effect, NamipokeSplashWork *work)
{
    FIELD_EFFECT_GetObjectPos(effect, &FIELD_G3DOBJ_GetObjectTrans(FIELD_EFFECT_GetFieldMapData(work->param.res->fieldEffect), work->objId)->trans);
}
