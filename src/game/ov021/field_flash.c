/*
 * file:     field_flash.c
 * unit:     yes
 * function: FIELD_TASK_MANAGER_SetSlot, FIELD_TASK_MANAGER_FreeSlot, FIELD_TASK_MANAGER_UpdateSlot, FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone, FIELD_TASK_MANAGER_FreeSlotIfFinished, FIELD_TASK_CreateCameraDistanceTween, FIELD_TASK_UpdateCameraDistanceTween, FIELD_TASK_CreateCameraYawTween, FIELD_TASK_CreateCameraPitchTween, FIELD_TASK_InitCameraAngleTween, FIELD_TASK_StepCameraAngleTween, FIELD_TASK_UpdateCameraAngleTween, FIELD_TASK_CreatePlayerSpinLinear, FIELD_TASK_CreateMmdlSpinLinear, FIELD_TASK_CreatePlayerSpinEaseIn, FIELD_TASK_CreatePlayerSpinEaseOut, FIELD_TASK_GetSpinAcmdLinear, FIELD_TASK_GetSpinAcmdEaseIn, FIELD_TASK_GetSpinAcmdEaseOut, FIELD_TASK_UpdateSpinLinear, FIELD_TASK_UpdateSpinEaseIn, FIELD_TASK_UpdateSpinEaseOut, FIELD_TASK_CreatePlayerPosTween, FIELD_TASK_UpdatePlayerPosTween, FIELD_TASK_CreatePlayerDrop, FIELD_TASK_CalcDropOffset, FIELD_TASK_UpdatePlayerDrop, func_021C77D8, FIELD_TASK_CreateFade, FIELD_TASK_UpdateFade, FIELD_TASK_CreatePlayerDrawOffsetTween, FIELD_TASK_CreateMmdlDrawOffsetTween, FIELD_TASK_CreateMmdlPosOffsetTween, FIELD_TASK_CalcOffsetByProgress, FIELD_TASK_UpdateMmdlDrawOffsetTween, FIELD_TASK_UpdateMmdlPosOffsetTween, FIELD_TASK_CreateCameraTargetTween, FIELD_TASK_UpdateCameraTargetTween, FIELD_TASK_CreateCameraLerp, FIELD_TASK_UpdateCameraLerp, FIELD_TASK_CreateRepeatPlayerEffect, FIELD_TASK_UpdateRepeatPlayerEffect, FIELD_FLASH_Create, FIELD_FLASH_Delete, FIELD_FLASH_Update, FIELD_FLASH_Apply, FIELD_FLASH_SetPendingCommand, FIELD_FLASH_GetState, FIELD_FLASH_InitTween, FIELD_FLASH_ClearTween, FIELD_FLASH_StartTween, FIELD_FLASH_StepTween, FIELD_FLASH_GetTweenSize, FIELD_FLASH_SetTweenSize, FIELD_FLASH_GetTweenAlpha, FIELD_FLASH_SetTweenAlpha, FIELD_FLASH_CmdInit, FIELD_FLASH_CmdExpand, func_021C7F44, FIELDSKILL_MAPEFF_Create, FIELDSKILL_MAPEFF_Delete, FIELDSKILL_MAPEFF_Update, FIELDSKILL_MAPEFF_Apply, FIELDSKILL_MAPEFF_GetFlash, FIELDSKILL_MAPEFF_InitFlash, FIELDSKILL_MAPEFF_FreeFlash, FIELDSKILL_MAPEFF_UpdateFlash, FIELDSKILL_MAPEFF_ApplyFlash, FLD_WIPE_3DOBJ_Create, FLD_WIPE_3DOBJ_Delete, FLD_WIPE_3DOBJ_Draw, SCRCMD_StartFld3dCi, SCRCMD_StartFld3dCiByVar, SCRCMD_RunFld3dCiMain, SCRCMD_StartFld3dCiByTable, FLD_WIPE_3DOBJ_CreateMapChangeEvent, FLD_WIPE_3DOBJ_MapChangeEventMain, FLD_WIPE_3DOBJ_FadeOutEventMain, PLEASURE_BOAT_Create, PLEASURE_BOAT_AckEvent, PLEASURE_BOAT_Update, PLEASURE_BOAT_AdvanceTime, PLEASURE_BOAT_GetStat
 * address:  0x021C6E5C
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
 *   FIELD_TASK_Delete  0x021C6CA8  thumb  ov021
 *   FIELD_TASK_Update  0x021C6CBC  thumb  ov021
 *   FIELD_TASK_Start  0x021C6CC4  thumb  ov021
 *   FIELD_TASK_GetState  0x021C6CE0  thumb  ov021
 *   FIELD_TASK_IsFinished  0x021C6CD0  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb
 *   _fgr           0x0209BBB0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   FIELD_CAMERA_GetYaw  0x0218ED40  thumb  ov021
 *   FIELD_CAMERA_GetPitch  0x0218ED2C  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   _ffixu         0x0209C4C8  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   gSpinAcmdLinear  0x021DAAC0  data  ov021  a2
 *   gSpinAcmdEaseIn  0x021DAAB8  data  ov021  a2
 *   gSpinAcmdEaseOut     0x021DAAC8  data  ov021  a2
 *   func_0209C5E0  0x0209C5E0  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   BUTTON_MAN_ScaleVec  0x020520A4  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   _ll_mul        0x0209C054  arm
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   FLDEFF_IWAKUDAKI_Start  0x021ADD7C  thumb  ov021
 *   gFieldFlashFileName  0x021DE4FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   gFlashCommandTable  0x021DAAD0  data  ov021  a4
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0207C768  0x0207C768  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   gFieldSkillMapEffFileName  0x021DE50C  data  ov021  a4
 *   gFldWipe3dObjFileName  0x021DE520  data  ov021  a4
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   func_02046EFC  0x02046EFC  arm
 *   G3D_SYSTEM_GetLookAt  0x02046AFC  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   func_02082B60  0x02082B60  arm
 *   G3D_SYSTEM_GetRenderObj  0x0204755C  arm
 *   func_0206E394  0x0206E394  arm
 *   func_0206E4FC  0x0206E4FC  arm
 *   func_0206E484  0x0206E484  arm
 *   func_0206E574  0x0206E574  arm
 *   func_0206E40C  0x0206E40C  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLD3D_CI_StartSequence  0x021C1CB0  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLD3D_CI_StartPartyMemberSequence  0x021C1D68  thumb  ov021
 *   FLD3D_CI_StartMessageSequence  0x021C30B8  thumb  ov021
 *   gFld3dCiKeyTable     0x021DAAE0  data  a2
 *   gFld3dCiIdTable     0x021DAAE2  data  a2
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   FIELD_CAMERA_PushStateConstrained  0x0218F848  thumb  ov021
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent  0x021BEA30  thumb  ov021
 *   EVENT_MAPCHANGE_CreateWarpEventToLocation  0x021854CC  thumb  ov020
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   func_02043658  0x02043658  arm
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   FIELD_PLACE_NAME_ShowForZone  0x021BC578  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FADE_IsActive  0x0204E804  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GIMMICK_INIT_SetCartLanesFlags  0x021F36C0  thumb  ov037
 *   gPleasureBoatFileName     0x021DE534  data  a4
 *   d_00000024     0x00000024  data  a4
 *   PLEASURE_BOAT_GetTimeEvent  0x021C87E0  thumb  ov021
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 */

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX32_ONE 0x1000
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;
typedef int fx32;
typedef float f32;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

/* Opaque handles owned by other files. */
typedef struct FieldTask FieldTask;         /* field_task.c: state, work, update function */
typedef struct FieldMap FieldMap;
typedef struct FieldCamera FieldCamera;
typedef struct FieldPlayer FieldPlayer;
typedef struct Mmdl Mmdl;
typedef struct MmdlSys MmdlSys;
typedef struct FieldEffectCtrl FieldEffectCtrl;
typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct ScriptVm ScriptVm;
typedef struct ScrCmdWork ScrCmdWork;
typedef struct ScriptSystem ScriptSystem;
typedef struct Fld3dCi Fld3dCi;
typedef struct MyStatus MyStatus;
typedef struct ZoneStartLocation {
    u8 data[0x1C];
} ZoneStartLocation;

/* The task update function receives its work pointer and returns 1 when finished. */
typedef int (*FieldTaskUpdateFunc)();

/* Task list (home: field_task_manager, see "field_task_manager.c" assert string).
 * A slot holds a task and, optionally, the parent task it waits for. */
typedef struct FieldTaskList {
    u8 count;
    u8 pad[3];
    FieldTask **tasks;
    u32 *parents;
} FieldTaskList;

/* Camera distance tween: linear in float from the current distance to the target. */
typedef struct CameraDistanceTween {
    FieldMap *fieldMap;
    u8 state;
    u8 pad5;
    u16 frame;
    u16 frames;
    u16 padA;
    fx32 startDistance;
    fx32 targetDistance;
} CameraDistanceTween;

enum CameraAngleAxis {
    CAMERA_ANGLE_AXIS_YAW = 0,
    CAMERA_ANGLE_AXIS_PITCH = 1
};

/* Camera angle tween: smoothstep from the current angle to the target angle. */
typedef struct CameraAngleTween {
    FieldMap *fieldMap;
    FieldCamera *camera;
    u32 axis;
    u8 state;
    u8 padD;
    u16 frame;
    u16 frames;
    u16 pad12;
    u32 from;
    u32 to;
} CameraAngleTween;

/* Spin task: turns a field model through its four facing animations. */
typedef struct MmdlSpinTask {
    FieldMap *fieldMap;
    Mmdl *mmdl;
    u16 frame;
    u16 frames;
    u8 spins;
    u8 padD;
    u16 endDirection;
} MmdlSpinTask;

typedef struct SpinAcmdTable {
    u16 acmd[4];
} SpinAcmdTable;

/* Linear tween of a position between two points (player or camera target). */
typedef struct PosTween {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    int frame;
    int frames;
    VecFx32 from;
    VecFx32 to;
} PosTween;

/* Player drop task: draw offset falls from a height to the ground. */
typedef struct PlayerDropTask {
    u8 state;
    FieldMap *fieldMap;
    u16 frame;
    u16 frames;
    float height;
    Mmdl *mmdl;
} PlayerDropTask;

typedef struct WaitTask {
    u16 frame;
    u16 frames;
} WaitTask;

typedef struct FadeTask {
    FieldMap *fieldMap;
    u32 fadeMode;
    u32 startBrightness;
    u32 endBrightness;
    u32 wait;
} FadeTask;

/* Field model offset tween (draw offset or position offset). */
typedef struct MmdlOffsetTween {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    int reverse;
    u16 frame;
    u16 frames;
    VecFx32 offset;
    VecFx32 startPos;
    Mmdl *mmdl;
} MmdlOffsetTween;

/* Camera target linear interpolation. */
typedef struct CameraLerpTask {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    u16 frame;
    u16 frames;
    VecFx32 start;
    VecFx32 end;
    VecFx32 delta;
    int savedFlag;
} CameraLerpTask;

/* Calls a player effect every `interval` frames for `frames` frames. */
typedef struct RepeatEffectTask {
    FieldMap *fieldMap;
    FieldEffectCtrl *effectCtrl;
    Mmdl *mmdl;
    u8 state;
    u8 padD;
    u16 frame;
    u16 frames;
    u16 interval;
} RepeatEffectTask;

/* FIELD_FLASH: the cave flash light. A tween drives the size and alpha of the mask model. */
typedef struct FlashTween {
    fx32 size;
    u8 alpha;
    u8 pad5;
    u16 frame;
    u16 frames;
    u8 padA[2];
    fx32 sizeStart;
    fx32 sizeDelta;
    s16 alphaStart;
    s16 alphaDelta;
} FlashTween;

typedef struct FldWipe3dObj FldWipe3dObj;

typedef struct FieldFlash {
    FldWipe3dObj *model;
    FlashTween tween;
    u16 state;
    u16 pendingCommand;
} FieldFlash;

enum FlashState {
    FLASH_STATE_OFF = 0,
    FLASH_STATE_READY = 1,
    FLASH_STATE_EXPANDING = 2,
    FLASH_STATE_EXPANDED = 3
};

enum FlashCommand {
    FLASH_CMD_INIT = 0,
    FLASH_CMD_EXPAND = 1,
    FLASH_CMD_SHOW_EXPANDED = 2,
    FLASH_CMD_HIDE = 3,
    FLASH_CMD_NONE = 4
};

/* FIELDSKILL_MAPEFF: holds the map effects a field skill can add; only the flash so far. */
typedef struct FieldSkillMapEff {
    FieldFlash *flash;
} FieldSkillMapEff;

/* FLD_WIPE_3DOBJ: resource archive and object of the flash mask model. */
struct FldWipe3dObj {
    void *resArc;
    void *object;
};

typedef struct G3dLookAt {
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 target;
} G3dLookAt; /* same layout as G3dLookAt in arm9/g3d_system_types.h */

typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct Mtx43 {
    int m[12];
} Mtx43;

typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    Mtx33 rotate;
} G3dObjectStatus; /* same layout as G3dObjectStatus in arm9/g3d_system_types.h */

typedef struct G3dRenderRef {
    int magic;
    void *rndObj;
} G3dRenderRef;

/* Wipe event work (wipe with a 3D cut-in and a map change). */
typedef struct CameraAnimFlags {
    u32 apply[6];
} CameraAnimFlags;

typedef struct CameraAnimParam {
    u32 padding0[3];
    VecFx32 targetPos;
    VecFx32 targetOffset;
    u16 pitch;
    u16 yaw;
    u32 distance;
    u16 fovy;
    u16 pad2E;
    CameraAnimFlags flags;
} CameraAnimParam;

typedef struct WipeMapChangeWork {
    GameSystem *gameSystem;
    u32 savedCameraBits;
    u32 zoneId;
    ZoneStartLocation startLocation;
    u32 cutInIdBefore;
    u32 cutInIdAfter;
} WipeMapChangeWork;

/* PLEASURE_BOAT work (0x1B8). */
typedef struct BoatPassenger {
    u8 info[0x18];
    int occupied;
} BoatPassenger;

typedef struct PleasureBoatWork {
    int eventPending;
    short timeTicks;
    u16 visitorCount;
    int periodCount;
    BoatPassenger passengers[15];
    u8 groupCount[4];
    int locked;
} PleasureBoatWork;

extern void FIELD_TASK_Delete(FieldTask *task);
extern void FIELD_TASK_Update(FieldTask *task);
extern u32 FIELD_TASK_GetState(FieldTask *task);
extern void FIELD_TASK_Start(FieldTask *task);
extern int FIELD_TASK_IsFinished(FieldTask *task);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern FieldTask *FIELD_TASK_Create(u32 heapId, u32 size, FieldTaskUpdateFunc update);
extern void *FIELD_TASK_GetWork(FieldTask *task);
extern FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
extern fx32 FIELD_CAMERA_GetDistance(FieldCamera *camera);
extern u32 FIELD_CAMERA_GetMode(FieldCamera *camera);
extern void FIELD_CAMERA_SetMode(FieldCamera *camera, u32 value);
extern void FIELD_CAMERA_SetDistance(FieldCamera *camera, fx32 distance);
extern u16 FIELD_CAMERA_GetYaw(FieldCamera *camera);
extern u16 FIELD_CAMERA_GetPitch(FieldCamera *camera);
extern void FIELD_CAMERA_SetPitch(FieldCamera *camera, u16 angle);
extern void FIELD_CAMERA_SetYaw(FieldCamera *camera, u16 angle);
extern FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern double func_0209C5E0(double x);
extern void FLDMMDL_SetAcmd(Mmdl *mmdl, int acmd);
extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int direction);
extern void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *pos);
extern void FIELD_PLAYER_SetPos(FieldPlayer *player, VecFx32 *pos);
extern int FLDMMDL_MOVE_UpdateHeight(Mmdl *mmdl);
extern void BUTTON_MAN_ScaleVec(const VecFx32 *v, int scale, VecFx32 *out);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern FieldEffectCtrl *FIELDMAP_GetEffect(FieldMap *fieldMap);
extern void FLDMMDL_SetDrawOffset(Mmdl *mmdl, VecFx32 *offset);
extern void FLDEFF_KEMURI_Start(Mmdl *mmdl, FieldEffectCtrl *effectCtrl);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern void FADE_Start(u32 mode, u32 start, u32 end, u32 wait);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *pos);
extern void FLDMMDL_SetPos(Mmdl *mmdl, VecFx32 *pos);
extern void FIELD_CAMERA_GetTargetShift(FieldCamera *camera, VecFx32 *out);
extern void FIELD_CAMERA_SetTargetShift(FieldCamera *camera, VecFx32 *v);
extern void func_0207CA00(VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern void FIELD_CAMERA_SetTarget(FieldCamera *camera, VecFx32 *v);
extern void func_0207CEE4(int t, VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern void FLDEFF_IWAKUDAKI_Start(Mmdl *mmdl, FieldEffectCtrl *effectCtrl);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dst, int value, int size);
extern u32 func_0207C768(u32 a, u32 b);
extern void *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 mode);
extern void *G3D_SYSTEM_CreateRender(void *resArc, u32 index, void *param);
extern void *G3D_SYSTEM_CreateObject(void *render, u32 *anime, int count);
extern void func_02046EFC(void *resArc);
extern void G3D_SYSTEM_DeleteRender(void *render);
extern void G3D_SYSTEM_DeleteObject(void *object);
extern void *G3D_SYSTEM_GetObjectRender(void *object);
extern void G3D_SYSTEM_GetLookAt(G3dLookAt *dst);
extern void VEC_Normalize(VecFx32 *src, VecFx32 *dst);
extern u32 *NNS_G3dGlbGetInvCameraMtx(void);
extern void func_02082B60(Mtx43 *src, Mtx33 *dst);
extern G3dRenderRef *G3D_SYSTEM_GetRenderObj(void *render);
extern void func_0206E394(void *mdl, int a, int b);
extern void func_0206E4FC(void *mdl, int a, int b);
extern void func_0206E484(void *mdl, int a, int b);
extern void func_0206E574(void *mdl, int a, int b);
extern void func_0206E40C(void *mdl, int a, int b);
extern void G3D_SYSTEM_DrawObject(void *object, G3dObjectStatus *status);
extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrCmdWork *work);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern Fld3dCi *FIELDMAP_GetFld3dCi(FieldMap *fieldMap);
extern u16 func_02011330(ScriptVm *vm);
extern ScriptSystem *SCRCMD_WORK_GetScriptWork(ScrCmdWork *work);
extern GameEvent *FLD3D_CI_StartSequence(GameSystem *gameSystem, Fld3dCi *ci, int id);
extern void SCRIPT_SYS_CallEvent(ScriptSystem *scriptSys, GameEvent *event);
extern unsigned int SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrCmdWork *work);
extern GameEvent *FLD3D_CI_StartPartyMemberSequence(GameSystem *gameSystem, Fld3dCi *ci, int value);
extern GameEvent *FLD3D_CI_StartMessageSequence(GameSystem *gameSystem, Fld3dCi *ci, unsigned int value);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, int (*main)(), unsigned int workSize);
extern void *func_020124E8(GameEvent *event);
extern void *func_020120F4(GameSystem *gameSystem);
extern MyStatus *func_02012944(void *gameData);
extern u8 func_02008550(const MyStatus *myStatus);
extern void ZONEDATA_SetZoneStartLocation(ZoneStartLocation *location, int zoneId);
extern u32 FIELDMAP_GetNogridMapper(FieldMap *fieldMap);
extern void FIELD_CAMERA_SetAreasEnabled(FieldCamera *camera, u32 value);
extern u32 FIELD_CAMERA_GetTraceTarget(FieldCamera *camera);
extern void FIELD_CAMERA_EndDelay(FieldCamera *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(FieldCamera *camera);
extern void FIELD_NOGRID_MAPPER_SetActive(u32 bg, u32 value);
extern void FIELD_CAMERA_StopTargetTrace(FieldCamera *camera);
extern void FIELD_CAMERA_PushState(FieldCamera *camera);
extern void FIELD_CAMERA_PushStateConstrained(FieldCamera *camera);
extern void FIELD_CAMERA_StartMove(FieldCamera *camera, CameraAnimParam *param, int frames);
extern int FIELD_CAMERA_IsMoving(FieldCamera *camera);
extern MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);
extern void FLDMMDL_SysPauseMove(MmdlSys *mmdlSys);
extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);
extern u32 *FLDMMDL_SysResumeMove(MmdlSys *mmdlSys);
extern void FLDMMDL_SetStatusBitVanish(Mmdl *mmdl, unsigned int vanish);
extern void FIELD_CAMERA_PopState(FieldCamera *camera);
extern GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(GameSystem *gameSystem, FieldMap *fieldMap, u32 a, u32 b);
extern GameEvent *EVENT_MAPCHANGE_CreateWarpEventToLocation(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, ZoneStartLocation *location, u16 flag);
extern void *FIELDMAP_GetPlaceName(FieldMap *fieldMap);
extern int FIELD_PLACE_NAME_Cancel(void *msgBg);
extern u32 func_02043658(void);
extern void FIELDMAP_SetBgMode(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void FIELDMAP_ResetBgAffineShowMsg(FieldMap *fieldMap);
extern void FIELD_PLACE_NAME_ShowForZone(void *msgBg, int zoneId);
extern void FIELD_CAMERA_StartMoveToSaved(FieldCamera *camera, CameraAnimFlags *flags, u16 frames);
extern void FIELD_CAMERA_SetTraceTarget(FieldCamera *camera, u32 bits);
extern void FIELD_CAMERA_RestartDelay(FieldCamera *camera);
extern GameSystem *GAME_EVENT_GetGameSystem(GameEvent *event);
extern int FADE_IsActive(void);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(int overlayId);
extern void GIMMICK_INIT_SetCartLanesFlags(PleasureBoatWork *work);
extern int PLEASURE_BOAT_GetTimeEvent(PleasureBoatWork *work);
extern GameEvent *SCRIPT_SYS_CreateScriptEventSimple(GameSystem *gameSystem, int a, int b, int scriptId);

/* Spin acmd tables (u16 per facing direction) and the FLD3D_CI id table (key, id pairs). */
extern SpinAcmdTable gSpinAcmdLinear;
extern SpinAcmdTable gSpinAcmdEaseIn;
extern SpinAcmdTable gSpinAcmdEaseOut;
extern char gFieldFlashFileName[];
extern char gFieldSkillMapEffFileName[];
extern char gFldWipe3dObjFileName[];
extern unsigned short gFld3dCiKeyTable[];
extern unsigned short gFld3dCiIdTable[];
extern char gPleasureBoatFileName;
extern char d_00000024[];
extern void (*gFlashCommandTable[])(FieldFlash *flash);

void FIELD_TASK_MANAGER_SetSlot(FieldTaskList *list, int slot, FieldTask *task, u32 parent);
void FIELD_TASK_MANAGER_FreeSlot(FieldTaskList *list, int slot);
void FIELD_TASK_MANAGER_UpdateSlot(FieldTaskList *list, int slot);
void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(FieldTaskList *list, int slot);
void FIELD_TASK_MANAGER_FreeSlotIfFinished(FieldTaskList *list, int slot);
FieldTask *FIELD_TASK_CreateCameraDistanceTween(FieldMap *fieldMap, u16 frames, fx32 targetDistance);
int FIELD_TASK_UpdateCameraDistanceTween(CameraDistanceTween *tween);
FieldTask *FIELD_TASK_CreateCameraYawTween(FieldMap *fieldMap, u16 frames, u32 targetAngle);
FieldTask *FIELD_TASK_CreateCameraPitchTween(FieldMap *fieldMap, u16 frames, u32 targetAngle);
void FIELD_TASK_InitCameraAngleTween(CameraAngleTween *tween);
void FIELD_TASK_StepCameraAngleTween(CameraAngleTween *tween);
int FIELD_TASK_UpdateCameraAngleTween(CameraAngleTween *tween);
FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins);
FieldTask *FIELD_TASK_CreateMmdlSpinLinear(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl);
FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins);
FieldTask *FIELD_TASK_CreatePlayerSpinEaseOut(FieldMap *fieldMap, u16 frames, int spins, int endDirection);
u16 FIELD_TASK_GetSpinAcmdLinear(float frame, float frames, float spins);
u16 FIELD_TASK_GetSpinAcmdEaseIn(float frame, float frames, float spins);
u16 FIELD_TASK_GetSpinAcmdEaseOut(float frame, float frames, float spins);
int FIELD_TASK_UpdateSpinLinear(MmdlSpinTask *task);
int FIELD_TASK_UpdateSpinEaseIn(MmdlSpinTask *task);
int FIELD_TASK_UpdateSpinEaseOut(MmdlSpinTask *task);
FieldTask *FIELD_TASK_CreatePlayerPosTween(FieldMap *fieldMap, u32 frames, VecFx32 *to);
int FIELD_TASK_UpdatePlayerPosTween(PosTween *tween);
FieldTask *FIELD_TASK_CreatePlayerDrop(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);
void FIELD_TASK_CalcDropOffset(VecFx32 *out, float frame, float frames, float height);
int FIELD_TASK_UpdatePlayerDrop(PlayerDropTask *task);
FieldTask *func_021C77D8(FieldMap *fieldMap, u16 frames);
int FIELD_TASK_UpdateWait(WaitTask *task);
FieldTask *FIELD_TASK_CreateFade(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait);
int FIELD_TASK_UpdateFade(FadeTask *task);
FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset);
FieldTask *FIELD_TASK_CreateMmdlDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
FieldTask *FIELD_TASK_CreateMmdlPosOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
void FIELD_TASK_CalcOffsetByProgress(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames);
int FIELD_TASK_UpdateMmdlDrawOffsetTween(MmdlOffsetTween *tween);
int FIELD_TASK_UpdateMmdlPosOffsetTween(MmdlOffsetTween *tween);
FieldTask *FIELD_TASK_CreateCameraTargetTween(FieldMap *fieldMap, u32 frames, const VecFx32 *to);
int FIELD_TASK_UpdateCameraTargetTween(PosTween *tween);
FieldTask *FIELD_TASK_CreateCameraLerp(FieldMap *fieldMap, int frames, const VecFx32 *start, const VecFx32 *end);
int FIELD_TASK_UpdateCameraLerp(CameraLerpTask *task);
FieldTask *FIELD_TASK_CreateRepeatPlayerEffect(FieldMap *fieldMap, int unused, u16 frames, u16 interval);
int FIELD_TASK_UpdateRepeatPlayerEffect(RepeatEffectTask *task);
FieldFlash *FIELD_FLASH_Create(u32 heapId);
void FIELD_FLASH_Delete(FieldFlash *flash);
void FIELD_FLASH_Update(FieldFlash *flash);
void FIELD_FLASH_Apply(FieldFlash *flash);
void FIELD_FLASH_SetPendingCommand(FieldFlash *flash, u16 command);
u16 FIELD_FLASH_GetState(FieldFlash *flash);
void FIELD_FLASH_InitTween(FlashTween *tween);
void FIELD_FLASH_ClearTween(FlashTween *tween);
FlashTween *FIELD_FLASH_StartTween(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames);
int FIELD_FLASH_StepTween(FlashTween *tween);
u32 FIELD_FLASH_GetTweenSize(FlashTween *tween);
void FIELD_FLASH_SetTweenSize(FlashTween *tween, fx32 size);
u8 FIELD_FLASH_GetTweenAlpha(FlashTween *tween);
FlashTween *FIELD_FLASH_SetTweenAlpha(FlashTween *tween, u8 alpha);
void FIELD_FLASH_CmdInit(FieldFlash *flash);
void FIELD_FLASH_CmdExpand(FieldFlash *flash);
void func_021C7F44(FieldFlash *flash);
void func_021C7F60(FieldFlash *flash);
FieldSkillMapEff *FIELDSKILL_MAPEFF_Create(u32 flags, u32 heapId);
void FIELDSKILL_MAPEFF_Delete(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_Update(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_Apply(FieldSkillMapEff *mapEff);
FieldFlash *FIELDSKILL_MAPEFF_GetFlash(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_InitFlash(FieldSkillMapEff *mapEff, u32 flags, u32 heapId);
void FIELDSKILL_MAPEFF_FreeFlash(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_UpdateFlash(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_ApplyFlash(FieldSkillMapEff *mapEff);
FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId);
int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj);
void FLD_WIPE_3DOBJ_Draw(FldWipe3dObj *obj, int size, int alpha);
int SCRCMD_StartFld3dCi(ScriptVm *vm, ScrCmdWork *work);
int SCRCMD_StartFld3dCiByVar(ScriptVm *vm, ScrCmdWork *work);
int SCRCMD_RunFld3dCiMain(ScriptVm *vm, ScrCmdWork *work);
int SCRCMD_StartFld3dCiByTable(ScriptVm *vm, ScrCmdWork *work);
GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, int unused, int zoneId);
int FLD_WIPE_3DOBJ_MapChangeEventMain(GameEvent *event, int *seq, WipeMapChangeWork *work);
int FLD_WIPE_3DOBJ_FadeOutEventMain(GameEvent *event, int *seq);
PleasureBoatWork *PLEASURE_BOAT_Create(void);
void PLEASURE_BOAT_AckEvent(PleasureBoatWork *work);
GameEvent *PLEASURE_BOAT_Update(GameSystem *gameSystem, PleasureBoatWork *work);
void PLEASURE_BOAT_AdvanceTime(PleasureBoatWork *work, int seconds, int clamp);
int PLEASURE_BOAT_GetStat(PleasureBoatWork *work, int kind);

void FIELD_TASK_MANAGER_SetSlot(FieldTaskList *list, int slot, FieldTask *task, u32 parent)
{
    if (list->tasks[slot] == 0) {
        list->tasks[slot] = task;
        list->parents[slot] = parent;
    }
}

void FIELD_TASK_MANAGER_FreeSlot(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0) {
        FIELD_TASK_Delete(list->tasks[slot]);
        list->tasks[slot] = 0;
        list->parents[slot] = 0;
    }
}

void FIELD_TASK_MANAGER_UpdateSlot(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0)
        FIELD_TASK_Update(list->tasks[slot]);
}

void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0 && list->parents[slot] != 0) {
        if (FIELD_TASK_GetState(list->tasks[slot]) == 0 && FIELD_TASK_GetState((FieldTask *)list->parents[slot]) == 2)
            FIELD_TASK_Start(list->tasks[slot]);
    }
}

void FIELD_TASK_MANAGER_FreeSlotIfFinished(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0 && FIELD_TASK_IsFinished(list->tasks[slot]) == 1)
        FIELD_TASK_MANAGER_FreeSlot(list, slot);
}

FieldTask *FIELD_TASK_CreateCameraDistanceTween(FieldMap *fieldMap, u16 frames, fx32 targetDistance)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x14, FIELD_TASK_UpdateCameraDistanceTween);
    CameraDistanceTween *tween = (CameraDistanceTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    tween->targetDistance = targetDistance;
    return task;
}

int FIELD_TASK_UpdateCameraDistanceTween(CameraDistanceTween *tween)
{
    FieldCamera *camera;
    u32 savedBits;
    f32 t;
    f32 start;
    f32 target;
    f32 distance;
    camera = FIELDMAP_GetCamera(tween->fieldMap);
    switch (tween->state) {
    case 0:
        tween->startDistance = FIELD_CAMERA_GetDistance(camera);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        savedBits = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, 0);
        t = (f32)tween->frame / (f32)tween->frames;
        start = FX_FX32_TO_F32(tween->startDistance);
        target = FX_FX32_TO_F32(tween->targetDistance);
        distance = (1.0f - t) * start + t * target;
        FIELD_CAMERA_SetDistance(camera, FX_F32_TO_FX32(distance));
        FIELD_CAMERA_SetMode(camera, savedBits);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

FieldTask *FIELD_TASK_CreateCameraYawTween(FieldMap *fieldMap, u16 frames, u32 targetAngle)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x1c, FIELD_TASK_UpdateCameraAngleTween);
    CameraAngleTween *tween = (CameraAngleTween *)FIELD_TASK_GetWork(task);
    tween->fieldMap = fieldMap;
    tween->camera = FIELDMAP_GetCamera(fieldMap);
    tween->state = 0;
    tween->axis = CAMERA_ANGLE_AXIS_YAW;
    tween->frame = 0;
    tween->frames = frames;
    tween->to = targetAngle;
    return task;
}

FieldTask *FIELD_TASK_CreateCameraPitchTween(FieldMap *fieldMap, u16 frames, u32 targetAngle)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x1c, FIELD_TASK_UpdateCameraAngleTween);
    CameraAngleTween *tween = (CameraAngleTween *)FIELD_TASK_GetWork(task);
    tween->fieldMap = fieldMap;
    tween->camera = FIELDMAP_GetCamera(fieldMap);
    tween->state = 0;
    tween->axis = CAMERA_ANGLE_AXIS_PITCH;
    tween->frame = 0;
    tween->frames = frames;
    tween->to = targetAngle;
    return task;
}

/* Reads the current angle and moves the target by a full turn when the short way round crosses the wrap. */
void FIELD_TASK_InitCameraAngleTween(CameraAngleTween *tween)
{
    u32 axis = tween->axis;
    u32 from = (u32)tween->camera;
    u32 to = tween->to;
    u32 diff;
    if (axis == 0 || axis != 1)
        from = FIELD_CAMERA_GetYaw((FieldCamera *)from);
    else
        from = FIELD_CAMERA_GetPitch((FieldCamera *)from);
    if (from < to) {
        diff = to - from;
        if (diff > 0x8000)
            from += 0x10000;
    } else if (to < from) {
        diff = from - to;
        if (diff > 0x8000)
            to += 0x10000;
    }
    tween->from = from;
    tween->to = to;
}

void FIELD_TASK_StepCameraAngleTween(CameraAngleTween *tween)
{
    u16 frames;
    FieldCamera *camera;
    f32 t;
    f32 s;
    u16 angle;
    u32 savedBits;
    frames = tween->frames;
    camera = tween->camera;
    tween->frame++;
    if (tween->frame > frames)
        return;
    t = (f32)tween->frame / (f32)frames;
    s = (3.0f + -2.0f * t) * (t * t);
    angle = (u16)((1.0f - s) * (f32)tween->from + s * (f32)tween->to);
    savedBits = FIELD_CAMERA_GetMode(camera);
    FIELD_CAMERA_SetMode(camera, 0);
    switch (tween->axis) {
    case CAMERA_ANGLE_AXIS_YAW:
        FIELD_CAMERA_SetYaw(camera, angle);
        break;
    case CAMERA_ANGLE_AXIS_PITCH:
        FIELD_CAMERA_SetPitch(camera, angle);
        break;
    }
    FIELD_CAMERA_SetMode(camera, savedBits);
}

int FIELD_TASK_UpdateCameraAngleTween(CameraAngleTween *tween)
{
    switch (tween->state) {
    case 0:
        FIELD_TASK_InitCameraAngleTween(tween);
        tween->state++;
        break;
    case 1:
        FIELD_TASK_StepCameraAngleTween(tween);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Spin the player: linear rate of turn. */
FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins)
{
    u32 heapId = FIELDMAP_GetHeapId(fieldMap);
    FieldPlayer *player = FIELDMAP_GetFieldPlayer(fieldMap);
    FieldTask *task = FIELD_TASK_Create(heapId, 0x10, FIELD_TASK_UpdateSpinLinear);
    MmdlSpinTask *spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    Mmdl *mmdl;
    spin->fieldMap = fieldMap;
    mmdl = FIELD_PLAYER_GetMmdl(player);
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = FLDMMDL_GetDirDisp(mmdl);
    return task;
}

/* Spin the given model: linear rate of turn. */
FieldTask *FIELD_TASK_CreateMmdlSpinLinear(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x10, FIELD_TASK_UpdateSpinLinear);
    spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    spin->fieldMap = fieldMap;
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = FLDMMDL_GetDirDisp(mmdl);
    return task;
}

/* Spin the player: rate of turn grows (ease in). */
FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    u32 heapId;
    FieldPlayer *player;
    Mmdl *mmdl;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x10, FIELD_TASK_UpdateSpinEaseIn);
    spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    spin->fieldMap = fieldMap;
    mmdl = FIELD_PLAYER_GetMmdl(player);
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = FLDMMDL_GetDirDisp(mmdl);
    return task;
}

/* Spin the player: rate of turn drops (ease out); ends facing endDirection. */
FieldTask *FIELD_TASK_CreatePlayerSpinEaseOut(FieldMap *fieldMap, u16 frames, int spins, int endDirection)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    u32 heapId;
    FieldPlayer *player;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x10, FIELD_TASK_UpdateSpinEaseOut);
    spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    spin->fieldMap = fieldMap;
    spin->mmdl = FIELD_PLAYER_GetMmdl(player);
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = endDirection;
    return task;
}

/*
 * Picks one of four halfwords from a table by (int)(4*c/b*a) % 4, in soft float.
 * The last multiply keeps its operand order only through a named float local;
 * inline it and the compiler swaps to a * f.
 */
u16 FIELD_TASK_GetSpinAcmdLinear(float frame, float frames, float spins)
{
    SpinAcmdTable table = gSpinAcmdLinear;
    float turnsPerFrame = 4.0f * spins / frames;
    int index = (int)(turnsPerFrame * frame);
    return table.acmd[index % 4];
}

u16 FIELD_TASK_GetSpinAcmdEaseIn(float frame, float frames, float spins)
{
    SpinAcmdTable table = gSpinAcmdEaseIn;
    float turnsPerFrame = 4.0f * spins / (frames * frames);
    float turns = turnsPerFrame * frame;
    int index = (int)(frame * turns);
    return table.acmd[index % 4];
}

u16 FIELD_TASK_GetSpinAcmdEaseOut(float frame, float frames, float spins)
{
    SpinAcmdTable table = gSpinAcmdEaseOut;
    float fullTurns = 4.0f * spins;
    float rate = fullTurns * fullTurns / frames;
    int index = (int)(float)func_0209C5E0((double)(rate * frame));
    return table.acmd[index % 4];
}

int FIELD_TASK_UpdateSpinLinear(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    int acmd;
    mmdl = task->mmdl;
    FLDMMDL_SetAcmd(mmdl, FIELD_TASK_GetSpinAcmdLinear((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        switch (task->endDirection) {
        default:
        case 0: acmd = 0; break;
        case 1: acmd = 1; break;
        case 2: acmd = 2; break;
        case 3: acmd = 3; break;
        }
        FLDMMDL_SetAcmd(mmdl, acmd);
        return 1;
    }
    return 0;
}

int FIELD_TASK_UpdateSpinEaseIn(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    int acmd;
    mmdl = task->mmdl;
    FLDMMDL_SetAcmd(mmdl, FIELD_TASK_GetSpinAcmdEaseIn((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        switch (task->endDirection) {
        default:
        case 0: acmd = 0; break;
        case 1: acmd = 1; break;
        case 2: acmd = 2; break;
        case 3: acmd = 3; break;
        }
        FLDMMDL_SetAcmd(mmdl, acmd);
        return 1;
    }
    return 0;
}

int FIELD_TASK_UpdateSpinEaseOut(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    mmdl = task->mmdl;
    FLDMMDL_SetAcmd(mmdl, FIELD_TASK_GetSpinAcmdEaseOut((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        FLDMMDL_SetDirDispCheckPause(mmdl, task->endDirection);
        return 1;
    }
    return 0;
}

/* The inline setter evaluates its arguments right to left, which puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void setVec(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Tween the player position to a point. */
FieldTask *FIELD_TASK_CreatePlayerPosTween(FieldMap *fieldMap, u32 frames, VecFx32 *to)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x28, FIELD_TASK_UpdatePlayerPosTween);
    PosTween *tween = (PosTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    setVec(&tween->to, to->x, to->y, to->z);
    return task;
}

int FIELD_TASK_UpdatePlayerPosTween(PosTween *tween)
{
    FieldPlayer *player;
    Mmdl *mmdl;
    fx32 t;
    VecFx32 fromPart;
    VecFx32 toPart;
    VecFx32 pos;
    player = FIELDMAP_GetFieldPlayer(tween->fieldMap);
    mmdl = FIELD_PLAYER_GetMmdl(player);
    switch (tween->state) {
    case 0:
        FIELD_PLAYER_GetPos(player, &tween->from);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        t = FX_F32_TO_FX32((f32)tween->frame / (f32)tween->frames);
        BUTTON_MAN_ScaleVec(&tween->from, FX32_ONE - t, &fromPart);
        BUTTON_MAN_ScaleVec(&tween->to, t, &toPart);
        func_0207C9D0(&fromPart, &toPart, &pos);
        FIELD_PLAYER_SetPos(player, &pos);
        FLDMMDL_MOVE_UpdateHeight(mmdl);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Player drop: the draw offset falls from `height` to the ground. */
FieldTask *FIELD_TASK_CreatePlayerDrop(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height)
{
    FieldTask *task;
    PlayerDropTask *drop;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x14, FIELD_TASK_UpdatePlayerDrop);
    drop = (PlayerDropTask *)FIELD_TASK_GetWork(task);
    drop->state = 0;
    drop->fieldMap = fieldMap;
    drop->frame = 0;
    drop->frames = frames;
    drop->height = (float)height;
    drop->mmdl = mmdl;
    return task;
}

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
/* Draw offset y of a falling model: height * (1 - (frame / frames)^2). */
void FIELD_TASK_CalcDropOffset(VecFx32 *out, float frame, float frames, float height)
{
    float rate = height / (frames * frames);
    float drop = rate * frame;
    float offsetY = height - frame * drop;
    out->x = 0;
    out->y = FX_F32_TO_FX32(offsetY);
    out->z = 0;
}

int FIELD_TASK_UpdatePlayerDrop(PlayerDropTask *task)
{
    VecFx32 offset;
    Mmdl *mmdl;
    FIELDMAP_GetFieldPlayer(task->fieldMap);
    mmdl = task->mmdl;
    switch (task->state) {
    case 0:
        FIELD_TASK_CalcDropOffset(&offset, (float)(u32)task->frame, (float)(u32)task->frames, task->height);
        FLDMMDL_SetDrawOffset(mmdl, &offset);
        GFL_USE_PlaySeDefaultVolume(0x681);
        task->state = task->state + 1;
        break;
    case 1:
        task->frame = task->frame + 1;
        FIELD_TASK_CalcDropOffset(&offset, (float)(u32)task->frame, (float)(u32)task->frames, task->height);
        FLDMMDL_SetDrawOffset(mmdl, &offset);
        if (task->frames <= task->frame) {
            FLDEFF_KEMURI_Start(mmdl, FIELDMAP_GetEffect(task->fieldMap));
            GFL_USE_PlaySeDefaultVolume(0x682);
            return 1;
        }
        break;
    }
    return 0;
}

FieldTask *func_021C77D8(FieldMap *fieldMap, u16 frames)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 4, FIELD_TASK_UpdateWait);
    WaitTask *wait = (WaitTask *)FIELD_TASK_GetWork(task);
    wait->frame = 0;
    wait->frames = frames;
    return task;
}

int FIELD_TASK_UpdateWait(WaitTask *task)
{
    task->frame++;
    if (task->frames <= task->frame)
        return 1;
    return 0;
}

FieldTask *FIELD_TASK_CreateFade(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x14, FIELD_TASK_UpdateFade);
    FadeTask *fade = (FadeTask *)FIELD_TASK_GetWork(task);
    fade->fieldMap = fieldMap;
    fade->fadeMode = fadeMode;
    fade->startBrightness = startBrightness;
    fade->endBrightness = endBrightness;
    fade->wait = wait;
    return task;
}

int FIELD_TASK_UpdateFade(FadeTask *task)
{
    FADE_Start(task->fadeMode, task->startBrightness, task->endBrightness, task->wait);
    return 1;
}

FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset)
{
    return FIELD_TASK_CreateMmdlDrawOffsetTween(fieldMap, frames, offset, FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)));
}

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

/* Draw offset of a model slides from zero to `offset` (negative frames: from `offset` back to zero). */
FieldTask *FIELD_TASK_CreateMmdlDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl)
{
    MmdlOffsetTween *tween;
    FieldTask *task;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x2c, FIELD_TASK_UpdateMmdlDrawOffsetTween);
    tween = (MmdlOffsetTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->mmdl = mmdl;
    FLDMMDL_GetPos(mmdl, &tween->startPos);
    if (frames >= 0) {
        tween->reverse = 0;
        tween->frame = 0;
        tween->frames = frames;
    } else {
        tween->reverse = 1;
        tween->frame = 0;
        tween->frames = -frames;
    }
    setVec(&tween->offset, offset->x, offset->y, offset->z);
    return task;
}

/* Position of a model slides by `offset` from its start position. */
FieldTask *FIELD_TASK_CreateMmdlPosOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl)
{
    MmdlOffsetTween *tween;
    FieldTask *task;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x2c, FIELD_TASK_UpdateMmdlPosOffsetTween);
    tween = (MmdlOffsetTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->mmdl = mmdl;
    FLDMMDL_GetPos(mmdl, &tween->startPos);
    if (frames >= 0) {
        tween->reverse = 0;
        tween->frame = 0;
        tween->frames = frames;
    } else {
        tween->reverse = 1;
        tween->frame = 0;
        tween->frames = -frames;
    }
    setVec(&tween->offset, offset->x, offset->y, offset->z);
    return task;
}

/* out = offset * (frame / frames) in fixed point. */
void FIELD_TASK_CalcOffsetByProgress(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames)
{
    fx32 t;
    t = FX_F32_TO_FX32((f32)frame / (f32)frames);
    out->x = (fx32)(((long long)offset->x * t + 0x800) >> 12);
    out->y = (fx32)(((long long)offset->y * t + 0x800) >> 12);
    out->z = (fx32)(((long long)offset->z * t + 0x800) >> 12);
}

int FIELD_TASK_UpdateMmdlDrawOffsetTween(MmdlOffsetTween *tween)
{
    Mmdl *mmdl = tween->mmdl;
    VecFx32 offset;
    if (tween->state == 0) {
        tween->frame = tween->frame + 1;
        if (tween->reverse == 0) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frame, &tween->offset, tween->frames);
        } else if (tween->reverse == 1) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frames - tween->frame, &tween->offset, tween->frames);
        }
        FLDMMDL_SetDrawOffset(mmdl, &offset);
        if (tween->frames <= tween->frame) {
            return 1;
        }
    }
    return 0;
}

int FIELD_TASK_UpdateMmdlPosOffsetTween(MmdlOffsetTween *tween)
{
    Mmdl *mmdl = tween->mmdl;
    VecFx32 offset;
    if (tween->state == 0) {
        tween->frame = tween->frame + 1;
        if (tween->reverse == 0) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frame, &tween->offset, tween->frames);
        } else if (tween->reverse == 1) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frames - tween->frame, &tween->offset, tween->frames);
        }
        func_0207C9D0(&offset, &tween->startPos, &offset);
        FLDMMDL_SetPos(mmdl, &offset);
        if (tween->frames <= tween->frame) {
            return 1;
        }
    }
    return 0;
}

/*
 * The source vector is const: the const lets the scheduler hoist each
 * load above the preceding store (ldr x; str frames; ldr y; str x; ...).  The
 * sibling FIELD_TASK_CreatePlayerPosTween takes a plain pointer and keeps loads after the frames store.
 */
FieldTask *FIELD_TASK_CreateCameraTargetTween(FieldMap *fieldMap, u32 frames, const VecFx32 *to)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x28, FIELD_TASK_UpdateCameraTargetTween);
    PosTween *tween = (PosTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    setVec(&tween->to, to->x, to->y, to->z);
    return task;
}

/* Tween the camera target offset between two points. */
int FIELD_TASK_UpdateCameraTargetTween(PosTween *tween)
{
    FieldCamera *camera;
    fx32 t;
    VecFx32 fromPart;
    VecFx32 toPart;
    VecFx32 pos;
    camera = FIELDMAP_GetCamera(tween->fieldMap);
    switch (tween->state) {
    case 0:
        FIELD_CAMERA_GetTargetShift(camera, &tween->from);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        t = FX_F32_TO_FX32((f32)tween->frame / (f32)tween->frames);
        BUTTON_MAN_ScaleVec(&tween->from, FX32_ONE - t, &fromPart);
        BUTTON_MAN_ScaleVec(&tween->to, t, &toPart);
        func_0207C9D0(&fromPart, &toPart, &pos);
        FIELD_CAMERA_SetTargetShift(camera, &pos);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Move the camera along a line from `start` to `end`. */
FieldTask *FIELD_TASK_CreateCameraLerp(FieldMap *fieldMap, int frames, const VecFx32 *start, const VecFx32 *end)
{
    int heapId;
    FieldTask *task;
    CameraLerpTask *lerp;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    FIELDMAP_GetCamera(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x34, FIELD_TASK_UpdateCameraLerp);
    lerp = (CameraLerpTask *)FIELD_TASK_GetWork(task);
    lerp->state = 0;
    lerp->fieldMap = fieldMap;
    lerp->frame = 0;
    lerp->frames = frames;
    lerp->start = *start;
    lerp->end = *end;
    func_0207CA00(&lerp->end, &lerp->start, &lerp->delta);
    return task;
}

int FIELD_TASK_UpdateCameraLerp(CameraLerpTask *task)
{
    FieldCamera *camera;
    int t;
    float progress;
    VecFx32 pos;
    camera = FIELDMAP_GetCamera(task->fieldMap);
    switch (task->state) {
    case 0:
        task->savedFlag = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, 0);
        task->state = task->state + 1;
        break;
    case 1:
        task->frame = task->frame + 1;
        progress = (float)(u32)task->frame / (float)(u32)task->frames;
        if (progress > 0.0f) {
            t = (int)(4096.0f * progress + 0.5f);
        } else {
            t = (int)(4096.0f * progress - 0.5f);
        }
        func_0207CEE4(t, &task->delta, &task->start, &pos);
        FIELD_CAMERA_SetTarget(camera, &pos);
        if (task->frames <= task->frame) {
            FIELD_CAMERA_SetMode(camera, task->savedFlag);
            return 1;
        }
        break;
    }
    return 0;
}

/* Run the player effect every `interval` frames for `frames` frames. */
FieldTask *FIELD_TASK_CreateRepeatPlayerEffect(FieldMap *fieldMap, int unused, u16 frames, u16 interval)
{
    int heapId;
    FieldPlayer *player;
    FieldTask *task;
    RepeatEffectTask *effect;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x14, FIELD_TASK_UpdateRepeatPlayerEffect);
    effect = (RepeatEffectTask *)FIELD_TASK_GetWork(task);
    effect->fieldMap = fieldMap;
    effect->effectCtrl = FIELDMAP_GetEffect(fieldMap);
    effect->mmdl = FIELD_PLAYER_GetMmdl(player);
    effect->state = 0;
    effect->frame = 0;
    effect->frames = frames;
    effect->interval = interval;
    return task;
}

int FIELD_TASK_UpdateRepeatPlayerEffect(RepeatEffectTask *task)
{
    if (task->state == 0) {
        if (task->frame % task->interval == 0)
            FLDEFF_IWAKUDAKI_Start(task->mmdl, task->effectCtrl);
        if (task->frames <= task->frame++)
            return 1;
    }
    return 0;
}

FieldFlash *FIELD_FLASH_Create(u32 heapId)
{
    FieldFlash *flash = func_02030734(heapId, sizeof(FieldFlash), 1, gFieldFlashFileName, 0x7a);
    flash->model = FLD_WIPE_3DOBJ_Create(heapId);
    flash->state = FLASH_STATE_OFF;
    flash->pendingCommand = FLASH_CMD_NONE;
    FIELD_FLASH_InitTween(&flash->tween);
    return flash;
}

void FIELD_FLASH_Delete(FieldFlash *flash)
{
    if (flash != 0) {
        FIELD_FLASH_ClearTween(&flash->tween);
        FLD_WIPE_3DOBJ_Delete(flash->model);
        func_020307B0(flash);
    }
}

/* Runs a pending command, then steps the tween while it expands. */
void FIELD_FLASH_Update(FieldFlash *flash)
{
    if (flash != 0) {
        if (flash->pendingCommand != FLASH_CMD_NONE) {
            gFlashCommandTable[flash->pendingCommand](flash);
            flash->pendingCommand = FLASH_CMD_NONE;
        }
        if (flash->state == FLASH_STATE_EXPANDING && FIELD_FLASH_StepTween(&flash->tween))
            flash->state = FLASH_STATE_EXPANDED;
    }
}

/* Applies the tween size and alpha to the mask model. */
void FIELD_FLASH_Apply(FieldFlash *flash)
{
    u32 size;
    if (flash != 0) {
        size = FIELD_FLASH_GetTweenSize(&flash->tween);
        FLD_WIPE_3DOBJ_Draw(flash->model, size, FIELD_FLASH_GetTweenAlpha(&flash->tween));
    }
}

void FIELD_FLASH_SetPendingCommand(FieldFlash *flash, u16 command)
{
    flash->pendingCommand = command;
}

/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (FIELD_FLASH_SetPendingCommand sets +0x1E).
 * Sole blocker of ov010 MOVE_POKEMON_FlashEventMain's MATCH.
 */
u16 FIELD_FLASH_GetState(FieldFlash *flash)
{
    return flash->state;
}

/* Tail-call thunk: pins arguments 2 and 3 to 0 and 24. */
void FIELD_FLASH_InitTween(FlashTween *tween)
{
    MI_CpuFill8(tween, 0, 24);
}

void FIELD_FLASH_ClearTween(FlashTween *tween)
{
    MI_CpuFill8(tween, 0, 24);
}

/* Starts a tween of size sizeStart..sizeEnd and alpha alphaStart..alphaEnd over `frames`. */
FlashTween *FIELD_FLASH_StartTween(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames)
{
    tween->size = sizeStart;
    tween->sizeStart = sizeStart;
    tween->sizeDelta = (sizeEnd - sizeStart);
    tween->alpha = alphaStart;
    tween->alphaStart = alphaStart;
    tween->alphaDelta = (alphaEnd - alphaStart);
    tween->frame = 0;
    tween->frames = frames;
    return tween;
}

/* Returns 1 once the tween has run its frames. */
int FIELD_FLASH_StepTween(FlashTween *tween)
{
    if (tween->frame < tween->frames) {
        tween->frame = tween->frame + 1;
        tween->size = tween->sizeStart + func_0207C768((int)(((long long)tween->sizeDelta * (tween->frame << 12) + 0x800) >> 12), tween->frames << 12);
        tween->alpha = tween->alphaStart + tween->alphaDelta * tween->frame / tween->frames;
        return 0;
    }
    return 1;
}

u32 FIELD_FLASH_GetTweenSize(FlashTween *tween)
{
    return tween->size;
}

void FIELD_FLASH_SetTweenSize(FlashTween *tween, fx32 size)
{
    tween->size = size;
}

u8 FIELD_FLASH_GetTweenAlpha(FlashTween *tween)
{
    return tween->alpha;
}

FlashTween *FIELD_FLASH_SetTweenAlpha(FlashTween *tween, u8 alpha)
{
    tween->alpha = alpha;
    return tween;
}

/* Command 0: small lit area (size 3.0, full alpha). */
void FIELD_FLASH_CmdInit(FieldFlash *flash)
{
    flash->state = FLASH_STATE_READY;
    FIELD_FLASH_SetTweenSize(&flash->tween, (3 << 12));
    FIELD_FLASH_SetTweenAlpha(&flash->tween, 31);
}

/* Command 1: grow the lit area to size 10.6 in 15 frames (flash was just used). */
void FIELD_FLASH_CmdExpand(FieldFlash *flash)
{
    flash->state = FLASH_STATE_EXPANDING;
    FIELD_FLASH_StartTween(&flash->tween, 0x3000, 0xaa00, 0x1f, 0x1f, 0xf);
    GFL_USE_PlaySeDefaultVolume(0x767);
}

/* Command 2: show the expanded lit area at once (flash was already active). */
void func_021C7F44(FieldFlash *flash)
{
    flash->state = FLASH_STATE_EXPANDED;
    FIELD_FLASH_SetTweenSize(&flash->tween, 0xaa00);
    FIELD_FLASH_SetTweenAlpha(&flash->tween, 0x1f);
}

/* Command 3: hide the mask. */
void func_021C7F60(FieldFlash *flash)
{
    flash->state = FLASH_STATE_OFF;
    FIELD_FLASH_SetTweenSize(&flash->tween, 0);
}

FieldSkillMapEff *FIELDSKILL_MAPEFF_Create(u32 flags, u32 heapId)
{
    FieldSkillMapEff *mapEff = func_02030734(heapId, sizeof(FieldSkillMapEff), 1, gFieldSkillMapEffFileName, 0x49);
    FIELDSKILL_MAPEFF_InitFlash(mapEff, flags, heapId);
    return mapEff;
}

void FIELDSKILL_MAPEFF_Delete(FieldSkillMapEff *mapEff)
{
    FIELDSKILL_MAPEFF_FreeFlash(mapEff);
    func_020307B0(mapEff);
}

/* Tail-call thunk: forwards to FIELDSKILL_MAPEFF_UpdateFlash with no argument change. */
void FIELDSKILL_MAPEFF_Update(FieldSkillMapEff *mapEff)
{
    FIELDSKILL_MAPEFF_UpdateFlash(mapEff);
}

/* Tail-call thunk: forwards to FIELDSKILL_MAPEFF_ApplyFlash with no argument change. */
void FIELDSKILL_MAPEFF_Apply(FieldSkillMapEff *mapEff)
{
    FIELDSKILL_MAPEFF_ApplyFlash(mapEff);
}

/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the first word of its argument.
 * Sole blocker of ov010 MOVE_POKEMON_FlashEventMain's MATCH.
 */
FieldFlash *FIELDSKILL_MAPEFF_GetFlash(FieldSkillMapEff *mapEff)
{
    return mapEff->flash;
}

/* Creates the flash when the map effect mask has bit 0 or 1; bit 1 starts it already expanded. */
void FIELDSKILL_MAPEFF_InitFlash(FieldSkillMapEff *mapEff, u32 flags, u32 heapId)
{
    if (flags & 3) {
        mapEff->flash = FIELD_FLASH_Create(heapId);
        if (flags & 2)
            FIELD_FLASH_SetPendingCommand(mapEff->flash, FLASH_CMD_SHOW_EXPANDED);
        else
            FIELD_FLASH_SetPendingCommand(mapEff->flash, FLASH_CMD_INIT);
    } else {
        mapEff->flash = 0;
    }
}

void FIELDSKILL_MAPEFF_FreeFlash(FieldSkillMapEff *mapEff)
{
    FIELD_FLASH_Delete(mapEff->flash);
    mapEff->flash = 0;
}

/* Tail-call thunk: forwards the flash to FIELD_FLASH_Update. */
void FIELDSKILL_MAPEFF_UpdateFlash(FieldSkillMapEff *mapEff)
{
    FIELD_FLASH_Update(mapEff->flash);
}

/* Tail-call thunk: forwards the flash to FIELD_FLASH_Apply. */
void FIELDSKILL_MAPEFF_ApplyFlash(FieldSkillMapEff *mapEff)
{
    FIELD_FLASH_Apply(mapEff->flash);
}

FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId)
{
    FldWipe3dObj *obj = func_02030734(heapId, sizeof(FldWipe3dObj), 1, gFldWipe3dObjFileName, 0x24);
    obj->resArc = G3D_SYSTEM_CreateResourceArc(0x4a, 0);
    obj->object = G3D_SYSTEM_CreateObject(G3D_SYSTEM_CreateRender(obj->resArc, 0, 0), 0, 0);
    return obj;
}

int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj)
{
    G3D_SYSTEM_DeleteRender(G3D_SYSTEM_GetObjectRender(obj->object));
    G3D_SYSTEM_DeleteObject(obj->object);
    func_02046EFC(obj->resArc);
    return func_020307B0(obj);
}

/* Draws the mask model as a camera-facing billboard of the given size and alpha. */
void FLD_WIPE_3DOBJ_Draw(FldWipe3dObj *obj, int size, int alpha)
{
    G3dObjectStatus status;
    G3dLookAt lookAt;
    VecFx32 viewDir;
    int viewY;
    void *mdl;
    if (size == 0) {
        return;
    }
    G3D_SYSTEM_GetLookAt(&lookAt);
    status.trans = lookAt.camPos;
    func_0207CA00(&lookAt.target, &lookAt.camPos, &viewDir);
    VEC_Normalize(&viewDir, &viewDir);
    viewY = viewDir.y;
    if (viewY <= 0) {
        viewY = -viewY;
    }
    status.scale.x = size;
    status.scale.y = (int)(((long long)size * viewY + 0x800) >> 12);
    status.scale.z = 0x4000;
    func_02082B60((Mtx43 *)NNS_G3dGlbGetInvCameraMtx(), &status.rotate);
    mdl = G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(obj->object))->rndObj;
    func_0206E394(mdl, 0, 0);
    func_0206E4FC(mdl, 0, 0);
    func_0206E484(mdl, 0, 2);
    func_0206E574(mdl, 0, alpha);
    func_0206E40C(mdl, 0, 0);
    G3D_SYSTEM_DrawObject(obj->object, &status);
}

/* Script command: start the FLD3D_CI sequence whose id is the next script halfword. */
int SCRCMD_StartFld3dCi(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int ciId;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(func_0201210C(gameSystem));
    ciId = func_02011330(vm);
    scriptSys = SCRCMD_WORK_GetScriptWork(work);
    event = FLD3D_CI_StartSequence(gameSystem, ci, (unsigned char)ciId);
    if (event) {
        SCRIPT_SYS_CallEvent(scriptSys, event);
    }
    return 1;
}

/* Script command: start the FLD3D_CI sequence whose id is read from a script value. */
int SCRCMD_StartFld3dCiByVar(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int ciId;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(func_0201210C(gameSystem));
    ciId = SCRIPT_WORK_ReadWorkValue(vm, work);
    scriptSys = SCRCMD_WORK_GetScriptWork(work);
    event = FLD3D_CI_StartPartyMemberSequence(gameSystem, ci, (unsigned char)ciId);
    if (event) {
        SCRIPT_SYS_CallEvent(scriptSys, event);
    }
    return 1;
}

/* Script command: run the FLD3D_CI main function with a script value. */
int SCRCMD_RunFld3dCiMain(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int value;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(func_0201210C(gameSystem));
    value = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    scriptSys = SCRCMD_WORK_GetScriptWork(work);
    event = FLD3D_CI_StartMessageSequence(gameSystem, ci, value);
    if (event) {
        SCRIPT_SYS_CallEvent(scriptSys, event);
    }
    return 1;
}

/* Script command: map a script value through the 17-entry key table to a FLD3D_CI id and start it. */
int SCRCMD_StartFld3dCiByTable(ScriptVm *vm, ScrCmdWork *work)
{
    GameSystem *gameSystem;
    Fld3dCi *ci;
    int value;
    int found;
    int i;
    ScriptSystem *scriptSys;
    unsigned short ciId;
    GameEvent *event;
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    ci = FIELDMAP_GetFld3dCi(func_0201210C(gameSystem));
    value = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (value == gFld3dCiKeyTable[i * 2]) {
            found = 1;
            ciId = gFld3dCiIdTable[i * 2];
            break;
        }
    }
    if (found) {
        scriptSys = SCRCMD_WORK_GetScriptWork(work);
        event = FLD3D_CI_StartSequence(gameSystem, ci, (unsigned char)ciId);
        if (event) {
            SCRIPT_SYS_CallEvent(scriptSys, event);
        }
    }
    return 1;
}

/* Creates the wipe event: picks the two FLD3D_CI ids by player outfit and remembers the destination zone. */
GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, int unused, int zoneId)
{
    GameEvent *event;
    WipeMapChangeWork *work;
    int cutInIdAfter;
    event = func_020122C0(gameSystem, 0, FLD_WIPE_3DOBJ_MapChangeEventMain, 0x30);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 0x30);
    work->gameSystem = gameSystem;
    work->zoneId = zoneId;
    if (func_02008550(func_02012944(func_020120F4(gameSystem))) == 0) {
        work->cutInIdBefore = 11;
        cutInIdAfter = 12;
    } else {
        work->cutInIdBefore = 18;
        cutInIdAfter = 19;
    }
    work->cutInIdAfter = cutInIdAfter;
    ZONEDATA_SetZoneStartLocation(&work->startLocation, (unsigned short)zoneId);
    return event;
}

/* Wipe event: camera swing and FLD3D_CI cut-in, map change, then the reverse cut-in. */
int FLD_WIPE_3DOBJ_MapChangeEventMain(GameEvent *event, int *seq, WipeMapChangeWork *work)
{
    FieldMap *fieldMap;
    FieldCamera *camera;
    Fld3dCi *ci;
    u32 bg;
    GameEvent *child;
    void *msgBg;
    u32 visiblePlanes;
    Mmdl *mmdl;
    CameraAnimParam param1;
    CameraAnimParam param2;
    VecFx32 playerPos1;
    VecFx32 playerPos2;
    CameraAnimFlags flags;
    fieldMap = func_0201210C(work->gameSystem);
    camera = FIELDMAP_GetCamera(fieldMap);
    ci = FIELDMAP_GetFld3dCi(fieldMap);
    bg = FIELDMAP_GetNogridMapper(fieldMap);
    switch (*seq) {
    case 0:
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
        work->savedCameraBits = FIELD_CAMERA_GetTraceTarget(camera);
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 1:
        if (work->savedCameraBits != 0 && FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive(bg, 0);
        FIELD_CAMERA_StopTargetTrace(camera);
        FIELD_CAMERA_PushState(camera);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos1);
        param1.pitch = 0x25d8;
        param1.yaw = 0;
        param1.distance = 0xed000;
        param1.targetOffset.x = 0;
        param1.targetOffset.y = 0x4000;
        param1.targetOffset.z = 0;
        param1.targetPos = playerPos1;
        param1.fovy = 0xe38;
        param1.flags.apply[0] = 1;
        param1.flags.apply[1] = 1;
        param1.flags.apply[2] = 0;
        param1.flags.apply[3] = 1;
        param1.flags.apply[4] = 1;
        param1.flags.apply[5] = 1;
        FIELD_CAMERA_StartMove(camera, &param1, 10);
        (*seq)++;
    case 2:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        child = FLD3D_CI_StartSequence(work->gameSystem, ci, (u8)work->cutInIdBefore);
        if (child != 0)
            GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 3:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
        FIELD_CAMERA_PopState(camera);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(work->gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventToLocation(work->gameSystem, fieldMap, work->zoneId, &work->startLocation, 1));
        (*seq)++;
        break;
    case 5:
        FIELD_PLACE_NAME_Cancel(FIELDMAP_GetPlaceName(fieldMap));
        work->savedCameraBits = FIELD_CAMERA_GetTraceTarget(camera);
        FIELD_CAMERA_EndDelay(camera);
        (*seq)++;
        break;
    case 6:
        if (work->savedCameraBits != 0 && FIELD_CAMERA_IsDelayEnabled(camera) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive(bg, 0);
        FIELD_CAMERA_StopTargetTrace(camera);
        FIELD_CAMERA_PushStateConstrained(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos2);
        param2.pitch = 0x25d8;
        param2.yaw = 0;
        param2.distance = 0xed000;
        param2.targetOffset.x = 0;
        param2.targetOffset.y = 0x4000;
        param2.targetOffset.z = 0;
        param2.targetPos = playerPos2;
        param2.fovy = 0xe38;
        param2.flags.apply[0] = 1;
        param2.flags.apply[1] = 1;
        param2.flags.apply[2] = 0;
        param2.flags.apply[3] = 1;
        param2.flags.apply[4] = 1;
        param2.flags.apply[5] = 1;
        FIELD_CAMERA_StartMove(camera, &param2, 1);
        (*seq)++;
    case 7:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
        visiblePlanes = func_02043658();
        FIELDMAP_SetBgMode();
        BG_SYS_SetMainVisiblePlanes(visiblePlanes);
        FIELDMAP_ResetBgAffineShowMsg(fieldMap);
        (*seq)++;
        break;
    case 8:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        child = FLD3D_CI_StartSequence(work->gameSystem, ci, (u8)work->cutInIdAfter);
        if (child != 0) {
            GAME_EVENT_CallEvent(event, child);
        } else {
            mmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
            FLDMMDL_SetStatusBitVanish(mmdl, 0);
            FLDMMDL_SetDirDispCheckPause(mmdl, 1);
            GAME_EVENT_CallEvent(event, func_020122C0(work->gameSystem, event, FLD_WIPE_3DOBJ_FadeOutEventMain, 0));
        }
        (*seq)++;
        break;
    case 9:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        FIELD_PLACE_NAME_ShowForZone(FIELDMAP_GetPlaceName(fieldMap), work->zoneId);
        flags.apply[0] = 1;
        flags.apply[1] = 1;
        flags.apply[2] = 0;
        flags.apply[3] = 1;
        flags.apply[4] = 1;
        flags.apply[5] = 1;
        FIELD_CAMERA_StartMoveToSaved(camera, &flags, 10);
        (*seq)++;
    case 10:
        if (FIELD_CAMERA_IsMoving(camera) != 0)
            break;
        if (work->savedCameraBits != 0)
            FIELD_CAMERA_SetTraceTarget(camera, work->savedCameraBits);
        FIELD_CAMERA_RestartDelay(camera);
        FIELD_NOGRID_MAPPER_SetActive(bg, 1);
        FIELD_CAMERA_PopState(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 1);
        return 1;
    }
    return 0;
}

/* Fades the screen out, then ends. */
int FLD_WIPE_3DOBJ_FadeOutEventMain(GameEvent *event, int *seq)
{
    func_0201210C(GAME_EVENT_GetGameSystem(event));
    switch (*seq) {
    case 0:
        FADE_Start(3, 0x10, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}

PleasureBoatWork *PLEASURE_BOAT_Create(void)
{
    PleasureBoatWork *work = func_02030734(5, sizeof(PleasureBoatWork), 1, &gPleasureBoatFileName, 0x31);
    work->eventPending = 0;
    work->timeTicks = 0;
    work->periodCount = 0;
    work->groupCount[0] = 0;
    work->groupCount[1] = 0;
    work->groupCount[2] = 0;
    work->groupCount[3] = 0;
    work->locked = 0;
    func_02034AC4((int)d_00000024); /* stand-in: overlay id passed as a raw address constant; a plain 0x24 changes the literal pool */
    GIMMICK_INIT_SetCartLanesFlags(work);
    func_02034A5C((int)d_00000024);
    return work;
}

/* Plays the arrival jingle and moves to the next period once the pending flag is set. */
void PLEASURE_BOAT_AckEvent(PleasureBoatWork *work)
{
    if (work != 0 && work->locked == 0 && work->eventPending != 0) {
        GFL_USE_PlaySeDefaultVolume(0x6dd);
        work->periodCount++;
        work->eventPending = 0;
    }
}

/* Advances the boat clock; returns the script event when the boat reaches a milestone. */
GameEvent *PLEASURE_BOAT_Update(GameSystem *gameSystem, PleasureBoatWork *work)
{
    GameEvent *event;
    int hasEvent;
    int milestone;
    if (work == 0) {
        return 0;
    }
    if (work->locked != 0) {
        return 0;
    }
    work->timeTicks = work->timeTicks + 1;
    milestone = PLEASURE_BOAT_GetTimeEvent(work);
    switch (milestone) {
    case 1:
        work->eventPending = 1;
        hasEvent = 0;
        break;
    case 2:
        event = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 1, 0, 0x8015);
        hasEvent = 1;
        break;
    default:
        hasEvent = 0;
        break;
    }
    if (hasEvent == 0) {
        event = 0;
    }
    return event;
}

/*
 * The sum is built in two statements (`r = f4 % 1350; r += b * 30;`) so
 * the multiply lands after the _s32_div_f call; one expression, or a
 * separate `t = b * 30` local, hoists it above the call into r4.
 * Adds `seconds` of boat time (30 ticks per second, 1350 ticks per period).
 * At a period end the clock stops one tick short (clamp) or enters the next period.
 */
void PLEASURE_BOAT_AdvanceTime(PleasureBoatWork *work, int seconds, int clamp)
{
    int ticks;
    ticks = work->timeTicks % 1350;
    ticks += seconds * 30;
    if (ticks >= 1350) {
        if (clamp) {
            work->timeTicks = (work->periodCount + 1) * 1350 - 1;
        } else {
            work->timeTicks = (work->periodCount + 1) * 1350;
            work->periodCount++;
        }
    } else {
        work->timeTicks += seconds * 30;
    }
}

/* Reads one boat statistic: kinds 0-3 are the group counters, 4 the visitor count, 5 the used passenger slots. */
int PLEASURE_BOAT_GetStat(PleasureBoatWork *work, int kind)
{
    int result;
    int i;
    switch (kind) {
    case 0:
        result = work->groupCount[0];
        break;
    case 1:
        result = work->groupCount[1];
        break;
    case 2:
        result = work->groupCount[2];
        break;
    case 3:
        result = work->groupCount[3];
        break;
    case 4:
        result = work->visitorCount;
        break;
    case 5:
        result = 0;
        for (i = 0; i < 15; i++) {
            if (work->passengers[i].occupied != 0) {
                result++;
            }
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
