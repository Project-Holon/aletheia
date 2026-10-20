/*
 * file:     scrcmd_c03center.c
 * unit:     yes
 * function: SCRCMD_C03CENTER_TurnCameraToQuarter, SCRCMD_C03CENTER_CameraTurnTaskMain
 * address:  0x021B5A18
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDMMDL_SetAreaIdRef  0x0216CDB8  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_CAMERA_GetViewYawPtr  0x0218ED50  thumb  ov021
 *   FIELD_CAMERA_GetMoveGoal  0x0218FE70  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   sScrcmdC03centerFileName     0x021DE25C  data  a1
 *   gCameraTurnAngle     0x021EE724  data  a2
 *   GFL_HEAP_Free  0x020307B0  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 */
#include "../arm9/script_vm_types.h"

struct ScrcmdWork;
struct GameSystem;
struct TcbTask;

/*
 * Camera turn state of SCRCMD_C03CENTER_TurnCameraToQuarter (0x10 bytes, heap block owned by the
 * TCB that SCRCMD_C03CENTER_CameraTurnTaskMain steps).
 */
typedef struct CameraTurnTask {
    int startAngle;   /* 0x00: camera angle when the command started */
    int angleDelta;   /* 0x04: signed turn to the nearest quarter turn */
    int frame;        /* 0x08 */
    int frameCount;   /* 0x0C */
} CameraTurnTask;

/* Start of the field camera state: the angle sits at +0x26. */
typedef struct FieldCameraDirection {
    u8 reserved[0x26];
    u16 angle;        /* 0x26: 0x10000 is a full turn */
} FieldCameraDirection;
struct ScriptWork;

#include "../ov010/scrcmd_work.h"
struct GameData;
struct ScriptVm;
#include "../ov010/script_work_cmd.h"
struct MmdlSys;
#include "../ov010/fldmmdl.h"
#include "../arm9/gamesystem.h"
struct FieldMap;
struct TcbSystem;
#include "fieldmap.h"
struct FieldCamera;
#include "field_camera.h"
struct FieldCameraView;
#include "../arm9/gfl_heap_wrap.h"
struct TcbSystem;
struct TcbTask;
#include "../arm9/tcb_list.h"
int SCRCMD_C03CENTER_TurnCameraToQuarter(struct ScriptVm *vm, struct ScrcmdWork *work);
void SCRCMD_C03CENTER_CameraTurnTaskMain(struct TcbTask *tcb, CameraTurnTask *turn);
extern const char sScrcmdC03centerFileName[];
extern u16 gCameraTurnAngle;
/* Second name for the same object: the pool needs a separate literal for the address handed to the map model system. */
extern u16 g_021EE724_ref;

/*
 * Script command: turn the field camera to the nearest quarter turn over a
 * number of frames. Allocates the CameraTurnTask that SCRCMD_C03CENTER_CameraTurnTaskMain steps
 * and starts it as a TCB (its own matched source names the fields).
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_C03CENTER_TurnCameraToQuarter(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameSystem;
    u32 tcbSys;
    u32 heapId;
    u8 *camera;
    u8 *mmdlSys;
    CameraTurnTask *turn;
    u32 frameCount;
    FieldCameraDirection *cameraDirection;
    int angle;
    u32 remainder;
    int delta;

    SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    SCRCMD_WORK_GetGameData(work);
    gameSystem = GAMESYSTEM_GetFieldMap(gameSystem);
    tcbSys = (u32)FIELDMAP_GetTcblSys(gameSystem);
    heapId = FIELDMAP_GetHeapId(gameSystem);
    camera = (u8 *)FIELDMAP_GetCamera(gameSystem);
    mmdlSys = (u8 *)FIELDMAP_GetMmdlSys(gameSystem);
    frameCount = SCRIPT_WORK_ReadWorkValue(vm, work);
    turn = GFL_HEAP_Alloc(heapId, 0x10, 1, sScrcmdC03centerFileName, 0x5d);
    gCameraTurnAngle = *(u16 *)FIELD_CAMERA_GetViewYawPtr((struct FieldCamera *)camera);
    FLDMMDL_SetAreaIdRef((struct MmdlSys *)mmdlSys, (u16 *)&g_021EE724_ref);
    cameraDirection = (FieldCameraDirection *)FIELD_CAMERA_GetMoveGoal((struct FieldCamera *)camera);
    turn->startAngle = gCameraTurnAngle;
    angle = cameraDirection->angle;
    turn->angleDelta = angle;
    remainder = angle % 0x4000;
    if (remainder >= 0x2000) {
        turn->angleDelta = angle + (0x4000 - remainder);
    } else {
        turn->angleDelta = angle - remainder;
    }
    turn->angleDelta -= turn->startAngle;
    delta = turn->angleDelta;
    if ((delta < 0 ? -delta : delta) >= 0x8000) {
        if (delta > 0) {
            turn->angleDelta -= 0x10000;
        } else {
            turn->angleDelta += 0x10000;
        }
    }
    turn->frame = 0;
    turn->frameCount = frameCount;
    TCB_AddTask((struct TcbSystem *)tcbSys, (TcbFunc)SCRCMD_C03CENTER_CameraTurnTaskMain, turn, 0);
    return 0;
}

/* TCB function: advances the camera angle by one step of the turn. */
void SCRCMD_C03CENTER_CameraTurnTaskMain(struct TcbTask *tcb, CameraTurnTask *turn)
{
    turn->frame++;
    gCameraTurnAngle = (turn->angleDelta * turn->frame) / turn->frameCount;
    gCameraTurnAngle = gCameraTurnAngle + (u16)turn->startAngle;
    if (turn->frame >= turn->frameCount) {
        GFL_HEAP_Free(turn);
        TCB_DeleteTask((struct TcbTask *)tcb);
    }
}
