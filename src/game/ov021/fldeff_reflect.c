/*
 * file:     fldeff_reflect.c
 * unit:     yes
 * function: FLDEFF_REFLECT_Init, FLDEFF_REFLECT_Delete, FLDEFF_REFLECT_InitResource, FLDEFF_REFLECT_DeleteResource, FLDEFF_REFLECT_SetMMdl, FLDEFF_REFLECT_InitTask, FLDEFF_REFLECT_DeleteTask, FLDEFF_REFLECT_UpdateTask, FLDEFF_REFLECT_DrawTask, FLDEFF_REFLECT_UpdateActor, FLDEFF_REFLECT_GetZoneRotateOffset, FLDEFF_REFLECT_GetZoneHeightOffset
 * address:  0x021BBF78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BBF78 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_GetEntryElemId  0x020508C4  arm
 *   d_021DE320     0x021DE320  data  a4
 *   GFL_HEAP_Free  0x020307B0  arm
 *   gReflectTaskHeader  0x021D9B64  data
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FLDMMDL_BLACT_DeleteActorPos  0x0219C98C  thumb  ov021
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_BLACT_AddActorPosOrReserve  0x0219C928  thumb  ov021
 *   FLDMMDL_BLACT_GetActorSize  0x0219C9E0  thumb  ov021
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   BILLBOARD_ACT_GetEntryFlags  0x020507D0  arm
 *   BILLBOARD_ACT_SetEntryFlags  0x020507A0  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_GetDrawOffsetOutside  0x0216D8D0  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   BILLBOARD_GetElemId  0x0204F5E4  arm
 *   BILLBOARD_SetElemId  0x0204F604  arm
 *   BILLBOARD_GetElemCell  0x0204F654  arm
 *   BILLBOARD_SetElemCell  0x0204F66C  arm
 *   BILLBOARD_SetElemScale  0x0204F684  arm
 *   BILLBOARD_SetElemFlipT  0x0204F794  arm
 *   BILLBOARD_GetElemFlipS  0x0204F748  arm
 *   BILLBOARD_SetElemFlipS  0x0204F764  arm
 *   gReflectMdlSizeOffsetZ     0x021D9B40  data  a4
 *   gReflectTypeOffsetY     0x021D9B58  data  a4
 *   gReflectMdlSizeOffsetY     0x021D9B4C  data  a4
 *   GFL_HEAP_Alloc  0x02030734  arm
 */
struct ClactActor;
struct BbBoard;

#include "../types.h"

#include "../sdk_fx.h"

/* Reflection effect work (FLDEFF_CTRL effect slot 6). */
typedef struct ReflectEffectWork {
    u32 fieldEffectCtrl;
} ReflectEffectWork;

/* Add-task header copied into every reflection task. */
typedef struct ReflectTaskHead {
    ReflectEffectWork *effWork;
    u32 type;
    struct Mmdl *mmdl;
    struct MmdlSys *mmdlSys;
    struct BbActSys *bbActSys;
} ReflectTaskHead;

typedef struct ReflectTaskWork {
    int baseAngle;
    int angleY;
    int swayAngle;
    int swaySpeed;
    u8 actorAdded;
    u8 angleSet;
    u8 pad12[2];
    ReflectTaskHead head;
    u16 actorReq;
    u16 actorId;
    u8 checkInfo[4];
} ReflectTaskWork;

struct FieldEffectSys;

#include "field_effect.h"
struct FieldEffectObjFuncs;
struct FieldEffectObj;
struct BbActSys;
#include "../arm9/billboard_act.h"
#include "../arm9/gfl_heap_wrap.h"
struct MmdlSys;
#include "../ov010/fldmmdl.h"
struct BlactSys;
struct BbActSys;
#include "fldmmdl_blact.h"
struct MmdlCheckInfo;
struct Mmdl;
struct FieldMap;
#include "fieldmap.h"
struct VecFx32;
#include "../ov010/fldmmdl_move.h"
#include "map_attr.h"
struct FieldMap;
struct FieldCamera;
struct G3dCamera;
#include "field_camera.h"
#include "../arm9/g3d_camera.h"
#include "../arm9/billboard.h"
ReflectEffectWork *FLDEFF_REFLECT_Init(int fieldEffectCtrl, int heapId);
void FLDEFF_REFLECT_Delete(u32 fieldEffectCtrl, u8 *effWork);
void FLDEFF_REFLECT_InitResource(void);
void FLDEFF_REFLECT_DeleteResource(void *effWork);
void FLDEFF_REFLECT_SetMMdl(struct MmdlSys *mmdlSys, struct Mmdl *mmdl, struct FieldEffectSys *fieldEffectCtrl, u32 type);
void FLDEFF_REFLECT_InitTask(u32 task, ReflectTaskWork *work);
void FLDEFF_REFLECT_DeleteTask(int task, ReflectTaskWork *work);
void FLDEFF_REFLECT_UpdateTask(u32 task, ReflectTaskWork *work);
void FLDEFF_REFLECT_DrawTask(int task, ReflectTaskWork *work);
void FLDEFF_REFLECT_UpdateActor(u16 actId, ReflectTaskWork *work);
int FLDEFF_REFLECT_GetZoneRotateOffset(u32 zoneId);
int FLDEFF_REFLECT_GetZoneHeightOffset(int zoneId, int mdlSize);

extern int d_021DE320;
extern u8 gReflectTaskHeader[];
extern const fx32 gReflectMdlSizeOffsetZ[];
extern const fx32 gReflectTypeOffsetY[];
extern const fx32 gReflectMdlSizeOffsetY[];

ReflectEffectWork *FLDEFF_REFLECT_Init(int fieldEffectCtrl, int heapId)
{
    ReflectEffectWork *effWork = GFL_HEAP_Alloc(heapId, 4, 1, (const char *)&d_021DE320, 0x78);

    effWork->fieldEffectCtrl = fieldEffectCtrl;
    FLDEFF_REFLECT_InitResource();
    return effWork;
}

void FLDEFF_REFLECT_Delete(u32 fieldEffectCtrl, u8 *effWork)
{
    FLDEFF_REFLECT_DeleteResource(effWork);
    GFL_HEAP_Free(effWork);
}

void FLDEFF_REFLECT_InitResource(void)
{
}

void FLDEFF_REFLECT_DeleteResource(void *effWork)
{
}

void FLDEFF_REFLECT_SetMMdl(struct MmdlSys *mmdlSys, struct Mmdl *mmdl, struct FieldEffectSys *fieldEffectCtrl, u32 type)
{
    ReflectTaskHead head;

    head.type = type;
    head.mmdl = mmdl;
    head.mmdlSys = mmdlSys;
    head.bbActSys = (struct BbActSys *)FLDMMDL_BLACT_GetBbActSys((struct BlactSys *)FLDMMDL_SysGetBlActCont(mmdlSys));
    head.effWork = (ReflectEffectWork *)FIELD_EFFECT_GetResource(fieldEffectCtrl, 6);
    FIELD_EFFECT_AddObject(fieldEffectCtrl, (struct FieldEffectObjFuncs *)gReflectTaskHeader, (VecFx32 *)0, 0, &head, 0);
}

void FLDEFF_REFLECT_InitTask(u32 task, ReflectTaskWork *work)
{
    ReflectTaskHead *head = (ReflectTaskHead *)FIELD_EFFECT_GetObjectParam((struct FieldEffectObj *)task);

    work->head = *head;
    work->swaySpeed = 0x40;
    work->baseAngle = 0;
    work->swayAngle = 0;
    if (work->head.type == 2) {
        work->swaySpeed = 0;
    }
    FLDMMDL_GetCheckInfo((struct Mmdl *)head->mmdl, (struct MmdlCheckInfo *)work->checkInfo);
}

void FLDEFF_REFLECT_DeleteTask(int task, ReflectTaskWork *work)
{
    if (work->actorAdded) {
        work->actorAdded = 0;
        FLDMMDL_BLACT_DeleteActorPos((struct MmdlSys *)work->head.mmdlSys, &work->actorReq);
    }
}

/*
 * The zeroed VecFx32 is a block-scope declaration with an initialiser: that is
 * what materialises `add r6, sp, #0xc` before the three stores and keeps r6
 * across the FLDMMDL_GetObjCodeParam call (plain element stores fold to sp-relative).
 */
void FLDEFF_REFLECT_UpdateTask(u32 task, ReflectTaskWork *work)
{
    u16 angle[2];
    int mmdlActId;

    if (FLDMMDL_CheckCheckInfo((struct Mmdl *)work->head.mmdl, (struct MmdlCheckInfo *)work->checkInfo) == 0 || FLDMMDL_CheckMoveBitReflect((void *)work->head.mmdl) == 0) {
        FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)task);
        return;
    }
    mmdlActId = FLDMMDL_CallDrawGetProc((void *)work->head.mmdl, 0);
    if (work->actorAdded == 0) {
        if (mmdlActId == 0xFFFF) return;
        {
            VecFx32 pos = {0, 0, 0};
            FLDMMDL_BLACT_AddActorPosOrReserve(work->head.mmdlSys, FLDMMDL_GetObjCodeParam((void *)work->head.mmdl), &work->actorReq, &pos,
                          (BlactAddActorHook)FLDEFF_REFLECT_UpdateActor, (uptr)work);
        }
        work->actorAdded = 1;
    }
    if (work->actorId == 0xFFFF) return;
    if (work->angleSet == 0) {
        int angleX;
        FLDMMDL_BLACT_GetActorSize((struct Mmdl *)work->head.mmdl, &angle[1], &angle[0]);
        angleX = angle[1];
        work->baseAngle = angleX;
        work->angleY = angle[0];
        work->swayAngle = angleX;
        work->angleSet = 1;
    }
    work->swayAngle += work->swaySpeed;
    if (work->swayAngle >= work->baseAngle + 0x400) {
        work->swayAngle = work->baseAngle + 0x400;
        work->swaySpeed = -work->swaySpeed;
        return;
    }
    if (work->swayAngle <= work->baseAngle - 0x400) {
        work->swayAngle = work->baseAngle - 0x400;
        work->swaySpeed = -work->swaySpeed;
    }
}

void FLDEFF_REFLECT_DrawTask(int task, ReflectTaskWork *work)
{
    if (FLDMMDL_CheckCheckInfo((struct Mmdl *)work->head.mmdl, (struct MmdlCheckInfo *)work->checkInfo) == 1 && work->actorAdded != 0 && work->actorId != 0xFFFF) {
        FLDEFF_REFLECT_UpdateActor(work->actorId, work);
    }
}

/*
 * Witnesses: arm9 leaves BILLBOARD_ACT_GetBoard, BILLBOARD_ACT_GetEntryFlags, BILLBOARD_ACT_SetEntryEnabled,
 * BILLBOARD_ACT_GetEntryElemId, BILLBOARD_GetElemCell filed in src/matched/arm9 (wave A1).
 *
 * The u16 mmdlElem local is what truncates BILLBOARD_ACT_GetEntryFlags's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 */
void FLDEFF_REFLECT_UpdateActor(u16 actId, ReflectTaskWork *work)
{
    VecFx32 pos;
    VecFx32 offset;
    VecFx32 camUp;
    int height;
    u32 flag;
    s16 rot[4];
    u16 zoneId;
    struct BbActSys *bbActSys;
    uptr board;
    int mmdlActId;
    struct Mmdl *mmdl;
    const MmdlObjCodeParam *objCode;
    u32 mmdlBoardElem;
    u32 boardElem;
    u16 mmdlElem;

    bbActSys = work->head.bbActSys;
    board = (uptr)BILLBOARD_ACT_GetBoard((struct BbActSys *)bbActSys);
    mmdlActId = FLDMMDL_CallDrawGetProc((void *)work->head.mmdl, 0);
    if (actId == 0xFFFF) {
        return;
    }
    zoneId = FIELDMAP_GetZoneId((struct FieldMap *)FIELD_EFFECT_GetFieldMap((struct FieldEffectSys *)work->head.effWork->fieldEffectCtrl));
    mmdlElem = BILLBOARD_ACT_GetEntryFlags(bbActSys, mmdlActId);
    BILLBOARD_ACT_SetEntryFlags((void *)bbActSys, actId, mmdlElem);
    BILLBOARD_ACT_SetEntryEnabled((void *)bbActSys, actId, 0);
    mmdl = work->head.mmdl;
    objCode = FLDMMDL_GetObjCodeParam((void *)mmdl);
    FLDMMDL_GetPos((struct Mmdl *)mmdl, (struct VecFx32 *)&pos);
    pos.z += gReflectMdlSizeOffsetZ[objCode->mdlSize];
    FLDMMDL_GetDrawOffset((struct Mmdl *)mmdl, (struct VecFx32 *)(&offset));
    pos.x += offset.x;
    pos.z -= offset.z;
    if (FLDMMDL_MOVE_GetMapHeight((struct Mmdl *)mmdl, &pos, &height) == 1) {
        pos.y = height;
    }
    pos.y += gReflectTypeOffsetY[work->head.type];
    FLDMMDL_GetDrawOffsetOutside((struct Mmdl *)mmdl, (struct VecFx32 *)(&offset));
    pos.x += offset.x;
    pos.y -= offset.y;
    pos.z -= offset.z;
    pos.y += gReflectMdlSizeOffsetY[objCode->mdlSize];
    if (objCode->mdlSize == 2) {
        if (MAP_ATTR_GetFlags(FLDMMDL_GetNowAttr((void *)mmdl)) & 0x40) {
            pos.y -= 0x3800;
        } else {
            pos.y -= 0x8000;
        }
    }
    pos.y += FLDEFF_REFLECT_GetZoneHeightOffset(zoneId, objCode->mdlSize);
    G3D_CAMERA_GetCamTarget(FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera((void *)FIELD_EFFECT_GetFieldMap((struct FieldEffectSys *)work->head.effWork->fieldEffectCtrl))), &camUp);
    pos.x += (pos.x / 4096 - camUp.x / 4096) * 298;
    BILLBOARD_SetElemPos((struct BbBoard *)board, actId, &pos);
    flag = 1;
    mmdlBoardElem = BILLBOARD_ACT_GetEntryElemId(bbActSys, mmdlActId);
    boardElem = BILLBOARD_ACT_GetEntryElemId(bbActSys, actId);
    rot[3] = work->swayAngle;
    rot[2] = work->angleY;
    rot[2] += (s16)FLDEFF_REFLECT_GetZoneRotateOffset(zoneId);
    rot[1] = 0;
    rot[0] = 0;
    BILLBOARD_GetElemId((struct BbBoard *)board, mmdlBoardElem, (u16 *)(&rot[1]));
    BILLBOARD_SetElemId((void *)board, boardElem, (u16 *)(&rot[1]));
    BILLBOARD_GetElemCell((struct BbBoard *)board, mmdlBoardElem, (unsigned short *)(&rot[0]));
    BILLBOARD_SetElemCell((struct BbBoard *)board, boardElem, (unsigned short *)((&rot[0])));
    BILLBOARD_SetElemScale((struct BbBoard *)board, boardElem, &rot[3], &rot[2]);
    BILLBOARD_SetElemFlipT((void *)board, boardElem, &flag);
    flag = BILLBOARD_GetElemFlipS((struct BbBoard *)board, mmdlBoardElem);
    BILLBOARD_SetElemFlipS((void *)board, boardElem, &flag);
}

int FLDEFF_REFLECT_GetZoneRotateOffset(u32 zoneId)
{
    return (~255);
}

int FLDEFF_REFLECT_GetZoneHeightOffset(int zoneId, int mdlSize)
{
    int ofs = 0;

    if (zoneId == 0x71 || zoneId == 0x159) {
        if (mdlSize == 0) {
            ofs = -0x800;
        }
    } else if (zoneId == 0x8f) {
        if (mdlSize == 0) {
            ofs = 2 << 10;
        }
    } else if (zoneId == 0x159 + 0x12) {
        if (mdlSize == 0) {
            ofs = -0x5800;
        }
    } else {
        if (mdlSize == 0) {
            ofs = 6 << 10;
        }
    }
    return ofs;
}
