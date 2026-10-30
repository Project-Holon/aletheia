/*
 * file:     rail_slipdown.c
 * unit:     yes
 * function: RAIL_SLIPDOWN_Create, RAIL_SLIPDOWN_Delete, RAIL_SLIPDOWN_IsDone, RAIL_SLIPDOWN_TaskMain
 * address:  0x021F36C0
 * region:   ov063
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb  ov021
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitAttrGetOff  0x0216DC98  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   RAIL_SLIPDOWN_TaskMain  0x021F377C  thumb  ov063
 *   gRailSlipdownSourceFile     0x021F3D80  data  a1
 *   TCB_DeleteTask  0x02030EAC  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FLDMMDL_RAIL_GetDrawOffset 0x0219E764 thumb ov021
 *   VEC_Fx16Normalize 0x0207CDB8 arm
 *   FIELD_RAIL_WORK_GetPos 0x021B8028 thumb ov021
 *   FIELD_NOGRID_MAPPER_GetRailMan 0x021BB480 thumb ov021
 *   FIELD_RAIL_FindSegmentLocation 0x021B7A84 thumb ov021
 *   FIELD_RAIL_GetLocationWidthGrid 0x021B7D50 thumb ov021
 *   FIELD_NOGRID_MAPPER_GetAttribute 0x021BB3C4 thumb ov021
 *   MAP_ATTR_GetFlags 0x021AB0F8 thumb ov021
 *   FIELD_RAIL_GetLocationPos 0x021B7D38 thumb ov021
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Mag 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   FX_Div 0x0207C768 arm
 *   FX_Modf 0x0207D14C arm
 *   FIELD_CAMERA_EndDelay 0x0218F0A8 thumb ov021
 *   FIELD_CAMERA_IsDelayEnabled 0x0218F0E8 thumb ov021
 *   FIELD_CAMERA_StopTargetTrace 0x0218EC54 thumb ov021
 *   FIELD_CAMERA_SetMode 0x0218E13C thumb ov021
 *   FIELD_CAMERA_EnterMode 0x0218E124 thumb ov021
 *   FIELD_CAMERA_GetEyeRaw 0x0218ECE4 thumb ov021
 *   FIELD_CAMERA_GetTargetRaw 0x0218ECB4 thumb ov021
 *   FIELD_NOGRID_MAPPER_SetCameraLocation 0x021BB3D0 thumb ov021
 *   FIELD_CAMERA_GetTraceTarget 0x0218EC5C thumb ov021
 *   FIELD_CAMERA_SetTarget 0x0218EC90 thumb ov021
 *   FIELD_CAMERA_SetEyeRaw 0x0218ECF4 thumb ov021
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   FLDMMDL_SetMoveBit 0x0216D568 thumb ov010
 *   FLDEFF_KEMURI_Start 0x021AC528 thumb ov021
 *   FIELD_PLAYER_SetPos 0x021A3044 thumb ov021
 *   FLDMMDL_SetPos 0x0216D89C thumb ov010
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   FIELD_PLAYER_SetNogridRailLocation 0x021A36B0 thumb ov021
 *   FIELD_PLAYER_GetNogridRailPos 0x021A36D4 thumb ov021
 *   FIELD_NOGRID_MAPPER_SetActive 0x021BB260 thumb ov021
 *   FIELD_NOGRID_MAPPER_UpdateCameraForced 0x021BB388 thumb ov021
 *   FLDMMDL_RAIL_SetLocation 0x0219E2C0 thumb ov021
 *   FLDMMDL_ClearMoveBit 0x0216D570 thumb ov010
 *   FLDMMDL_OffMoveBitMovePause 0x0216DB04 thumb ov010
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../version.h"
#include "../ov021/fldmmdl_rail_types.h"
#include "rail_slipdown_types.h"

#include "../ov021/fieldmap.h"
struct FieldMap;
struct FieldNogridMapper;
#include "../ov021/fldmmdl_rail.h"
struct FieldEffectCont;
struct FieldCamera;
struct FieldPlayer;
#include "../ov021/field_player.h"
#include "../ov010/fldmmdl.h"
struct TcblSys;
#include "../arm9/gfl_heap_wrap.h"
struct TcbSystem;
struct TcbTask;
#include "../arm9/tcb_list.h"
void RAIL_SLIPDOWN_TaskMain(struct TcbTask *tcb, void *work);
RailSlipdown *RAIL_SLIPDOWN_Create(void *gameSystem, void *fieldMap, struct Mmdl *mmdl, int isPlayer);
void RAIL_SLIPDOWN_Delete(RailSlipdown *slipdown);
int RAIL_SLIPDOWN_IsDone(RailSlipdown *slipdown);
extern const char gRailSlipdownSourceFile[];
#include "../types.h"
#include "../arm9/fx_vec.h"
#include "../ov021/field_rail.h"
#include "../ov021/field_nogrid_mapper.h"
#include "../ov021/map_attr.h"
#include "../arm9/fx_cp.h"
#include "../arm9/fx.h"
#include "../ov021/field_camera.h"
#include "../arm9/gfl_use.h"
#include "../ov021/fldeff_kemuri.h"
/* Fixed-point multiply with rounding (12 fraction bits). */
static inline int fxmul(int a,int b) {return (int)(((s64)a*b+2048)>>12);}
static inline void setDir16(SlipdownDir *d,int x,int y,int z){d->x=x;d->y=y;d->z=z;}
static inline void setVec(VecFx32 *d,int x,int y,int z){d->x=x;d->y=y;d->z=z;}

RailSlipdown *RAIL_SLIPDOWN_Create(void *gameSystem, void *fieldMap, struct Mmdl *mmdl, int isPlayer)
{
    RailSlipdown *slipdown;

    slipdown = GFL_HEAP_Alloc(FIELDMAP_GetHeapId(fieldMap), sizeof(*slipdown), 1, gRailSlipdownSourceFile, 0x80);
    slipdown->nogridMapper = FIELDMAP_GetNogridMapper(fieldMap);
    slipdown->mmdl = mmdl;
    slipdown->railWork = FLDMMDL_RAIL_GetRailWork(mmdl);
    slipdown->effectSys = (struct FieldEffectSys *)FIELDMAP_GetEffect(fieldMap);
    slipdown->camera = FIELDMAP_GetCamera(fieldMap);
    if (isPlayer != 0) {
        slipdown->player = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_ResetMoveWork(slipdown->player);
    } else {
        slipdown->player = 0;
    }
    FLDMMDL_SetStatusBitHeightGetOff(slipdown->mmdl, 1);
    FLDMMDL_SetStatusBitAttrGetOff(slipdown->mmdl, 1);
    FLDMMDL_SetStatusBitFellowHit(slipdown->mmdl, 0);
    FLDMMDL_OnMoveBitMovePause(slipdown->mmdl);
    slipdown->task = TCB_AddTask((struct TcbSystem *)FIELDMAP_GetTcblSys(fieldMap), RAIL_SLIPDOWN_TaskMain, slipdown, 0);
    return slipdown;
}

void RAIL_SLIPDOWN_Delete(RailSlipdown *slipdown)
{
    TCB_DeleteTask(slipdown->task);
    GFL_HEAP_Free(slipdown);
}

int RAIL_SLIPDOWN_IsDone(RailSlipdown *slipdown)
{
    if (slipdown->state == SLIPDOWN_STATE_DONE) {
        return 1;
    }
    return 0;
}

/*
 * Task of RAIL_SLIPDOWN_Create. Finds the landing place below the model,
 * then slides the model (and the camera with it) from start to end in steps.
 */
void RAIL_SLIPDOWN_TaskMain(struct TcbTask *tcb, void *work)
{
    RailSlipdown *slipdown = work;
    int stepFixed;
    struct RailManager *railMan;
    int widthLimit, slideY, valid, i;
    u16 bound;
    int scale, top, slideZ;
    VecFx32 origin, slope, point, eye, target, finalPos;
    SlipdownDir facing;
    RailLocation cell;
    int length;
    switch (slipdown->state) {
    case SLIPDOWN_STATE_FIND_LANDING:
        FLDMMDL_RAIL_GetDrawOffset(slipdown->mmdl, (s16 *)(&facing));
        facing.y = 0;
        VEC_Fx16Normalize((const VecFx16 *)&facing, (VecFx16 *)&facing);
        FIELD_RAIL_WORK_GetPos(slipdown->railWork, &origin);
        slipdown->start.x = origin.x + fxmul(facing.x, 0x10000);
        slipdown->start.y = origin.y + fxmul(facing.y, 0x10000);
        slipdown->start.z = origin.z + fxmul(facing.z, 0x10000);
        top = slipdown->start.y + 0xa000;
        slipdown->end.y = -0xa000;
        scale = fxmul(top, 0x127b);
        slipdown->end.x = slipdown->start.x + fxmul(facing.x, scale);
        slipdown->end.z = slipdown->start.z + fxmul(facing.z, scale);
        railMan = FIELD_NOGRID_MAPPER_GetRailMan(slipdown->nogridMapper);
        if (FIELD_RAIL_FindSegmentLocation(railMan, &slipdown->start, &slipdown->end, &slipdown->landing, &slipdown->end) == 0) {
            slipdown->state = SLIPDOWN_STATE_DONE;
            return;
        }
        cell = slipdown->landing;
        widthLimit = FIELD_RAIL_GetLocationWidthGrid(railMan, &slipdown->landing);
#if LANGUAGE != LANGUAGE_JAPANESE
        valid = 0;
        if (!(MAP_ATTR_GetFlags(FIELD_NOGRID_MAPPER_GetAttribute(slipdown->nogridMapper, &cell)) & 1)) valid = 1;
#endif
        cell.widthGrid += 2;
        if (cell.widthGrid > widthLimit) cell.widthGrid = widthLimit;
        bound = widthLimit + cell.widthGrid;
        for (i = 0; i < bound; i++) {
            cell.widthGrid--;
            if (MAP_ATTR_GetFlags(FIELD_NOGRID_MAPPER_GetAttribute(slipdown->nogridMapper, &cell)) & 1) break;
            slipdown->landing = cell;
#if LANGUAGE != LANGUAGE_JAPANESE
            valid = 1;
#endif
        }
#if LANGUAGE != LANGUAGE_JAPANESE
        if (!valid) {
            slipdown->state = SLIPDOWN_STATE_DONE;
            return;
        }
#endif
        FIELD_RAIL_GetLocationPos(railMan, &slipdown->landing, &slipdown->end);
        VEC_Subtract(&slipdown->end, &slipdown->start, &slope);
        length = VEC_Mag(&slope);
        VEC_Normalize(&slope, &slope);
        setDir16(&slipdown->dir, slope.x, slope.y, slope.z);
        length = FX_Div(length, 0x8000);
        if (FX_Modf(length, &length) == 0) slipdown->count = length>>12;
        else slipdown->count = (length>>12) + 1;
        slipdown->step = 0;
        if (slipdown->player != 0) {
            FIELD_CAMERA_EndDelay(slipdown->camera);
            slipdown->state = SLIPDOWN_STATE_WAIT_CAMERA;
        } else slipdown->state = SLIPDOWN_STATE_START_SLIDE;
        break;
    case SLIPDOWN_STATE_WAIT_CAMERA:
        if (FIELD_CAMERA_IsDelayEnabled(slipdown->camera) != 0) break;
        FIELD_CAMERA_StopTargetTrace(slipdown->camera);
        FIELD_CAMERA_SetMode(slipdown->camera, 2);
        FIELD_CAMERA_GetEyeRaw(slipdown->camera, &slipdown->eyeStart);
        FIELD_CAMERA_GetTargetRaw(slipdown->camera, &slipdown->targetStart);
        FIELD_NOGRID_MAPPER_SetCameraLocation(slipdown->nogridMapper, &slipdown->landing);
        if (FIELD_CAMERA_GetTraceTarget(slipdown->camera) != 0) {
            FIELD_CAMERA_SetTarget(slipdown->camera, &slipdown->end);
            FIELD_CAMERA_StopTargetTrace(slipdown->camera);
        }
        FIELD_CAMERA_SetMode(slipdown->camera, 2);
        FIELD_CAMERA_GetEyeRaw(slipdown->camera, &slipdown->eyeDelta);
        FIELD_CAMERA_GetTargetRaw(slipdown->camera, &slipdown->targetDelta);
        VEC_Subtract(&slipdown->eyeDelta, &slipdown->eyeStart, &slipdown->eyeDelta);
        VEC_Subtract(&slipdown->targetDelta, &slipdown->targetStart, &slipdown->targetDelta);
        FIELD_NOGRID_MAPPER_SetActive(slipdown->nogridMapper, 0);
        FIELD_CAMERA_EnterMode(slipdown->camera, 2);
        FIELD_CAMERA_StopTargetTrace(slipdown->camera);
        FIELD_CAMERA_SetTarget(slipdown->camera, &slipdown->targetStart);
        FIELD_CAMERA_SetEyeRaw(slipdown->camera, &slipdown->eyeStart);
        slipdown->state = SLIPDOWN_STATE_START_SLIDE;
        break;
    case SLIPDOWN_STATE_START_SLIDE:
        GFL_USE_PlaySeDefaultVolume(0x6ed);
        slipdown->state = SLIPDOWN_STATE_SLIDE;
        FLDMMDL_SetMoveBit(slipdown->mmdl, 0x8000);
    case SLIPDOWN_STATE_SLIDE:
        slipdown->step++;
        if ((u32) slipdown->step >= (u32) slipdown->count) {
            setVec(&point, slipdown->end.x, slipdown->end.y, slipdown->end.z);
            slipdown->state = SLIPDOWN_STATE_FINISH;
        } else {
            if (slipdown->step>0) stepFixed = (int)(0.5f + (float)(slipdown->step<<12));
            else stepFixed = (int)((float)(slipdown->step<<12)-0.5f);
            scale = fxmul(stepFixed, 0x8000);
            slideZ = slipdown->start.z + fxmul(slipdown->dir.z, scale);
            slideY = slipdown->start.y + fxmul(slipdown->dir.y, scale);
            point.x = slipdown->start.x + fxmul(slipdown->dir.x, scale);
            point.y = slideY;
            point.z = slideZ;
            if (slipdown->step % 2 == 0) FLDEFF_KEMURI_Start(slipdown->mmdl, slipdown->effectSys);
        }
        if (slipdown->player != 0) FIELD_PLAYER_SetPos(slipdown->player, &point);
        else FLDMMDL_SetPos(slipdown->mmdl, &point);
        if (slipdown->player == 0) break;
        {
            int y, z;
            z = slipdown->eyeStart.z + FX_Div(fxmul(slipdown->eyeDelta.z, slipdown->step<<12), slipdown->count<<12);
            y = slipdown->eyeStart.y + FX_Div(fxmul(slipdown->eyeDelta.y, slipdown->step<<12), slipdown->count<<12);
            eye.x = slipdown->eyeStart.x + FX_Div(fxmul(slipdown->eyeDelta.x, slipdown->step<<12), slipdown->count<<12);
            eye.y = y;
            eye.z = z;
        }
        {
            int y, z;
            z = slipdown->targetStart.z + FX_Div(fxmul(slipdown->targetDelta.z, slipdown->step<<12), slipdown->count<<12);
            y = slipdown->targetStart.y + FX_Div(fxmul(slipdown->targetDelta.y, slipdown->step<<12), slipdown->count<<12);
            target.x = slipdown->targetStart.x + FX_Div(fxmul(slipdown->targetDelta.x, slipdown->step<<12), slipdown->count<<12);
            target.y = y;
            target.z = z;
        }
        FIELD_CAMERA_SetTarget(slipdown->camera, &target);
        FIELD_CAMERA_SetEyeRaw(slipdown->camera, &eye);
        break;
    case SLIPDOWN_STATE_FINISH:
        GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(0x6ed));
        if (slipdown->player != 0) {
            FIELD_PLAYER_SetNogridRailLocation(slipdown->player, &slipdown->landing);
            FIELD_PLAYER_GetNogridRailPos(slipdown->player, &finalPos);
            FIELD_PLAYER_SetPos(slipdown->player, &finalPos);
            FIELD_NOGRID_MAPPER_SetActive(slipdown->nogridMapper, 1);
            FIELD_NOGRID_MAPPER_UpdateCameraForced(slipdown->nogridMapper);
        } else FLDMMDL_RAIL_SetLocation(slipdown->mmdl, &slipdown->landing);
        FLDMMDL_ClearMoveBit(slipdown->mmdl, 0x8000);
        FLDMMDL_SetStatusBitHeightGetOff(slipdown->mmdl, 0);
        FLDMMDL_SetStatusBitAttrGetOff(slipdown->mmdl, 0);
        FLDMMDL_SetStatusBitFellowHit(slipdown->mmdl, 1);
        FLDMMDL_OffMoveBitMovePause(slipdown->mmdl);
        slipdown->state = SLIPDOWN_STATE_DONE;
        break;
    case 2:
    case 3:
    case 6:
    case 7:
    case SLIPDOWN_STATE_DONE:
        break;
    }
}
