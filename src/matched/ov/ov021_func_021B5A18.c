/*
 * function: SCRCMD_C03CENTER_TurnCameraToQuarter
 * address:  0x021B5A18
 * packet:   pkt_ov021_021B5A18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the Ramp record SCRCMD_C03CENTER_CameraTurnTaskMain steps (its own matched source
 * names the fields) and starts it as a task.
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
 *   SCRCMD_C03CENTER_CameraTurnTaskMain  0x021B5B0C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   sScrcmdC03centerFileName     0x021DE25C  data  a1
 *   gCameraTurnAngle     0x021EE724  data  a2
 *   g_021EE724_ref 0x021EE724  data  a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20016.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Ramp;

extern const char sScrcmdC03centerFileName[];
extern u16 gCameraTurnAngle;
extern u16 g_021EE724_ref;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void FLDMMDL_SetAreaIdRef(u8 *p, u32 v);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u8 *FIELD_CAMERA_GetViewYawPtr(u8 *p);
extern u8 *FIELD_CAMERA_GetMoveGoal(u8 *p);
extern void SCRCMD_C03CENTER_CameraTurnTaskMain(int a0, Ramp *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(u32, void (*)(), void *, u32);

int SCRCMD_C03CENTER_TurnCameraToQuarter(void *a, void *b)
{
    void *sys;
    u32 task;
    u32 heap;
    u8 *obj;
    u8 *snd;
    Ramp *p;
    u32 n;
    u8 *q;
    int v;
    u32 m;
    int d;

    SCRCMD_WORK_GetScriptWork(b);
    sys = SCRCMD_WORK_GetGameSystem(b);
    SCRCMD_WORK_GetGameData(b);
    sys = GAMESYSTEM_GetFieldMap(sys);
    task = FIELDMAP_GetTcblSys(sys);
    heap = FIELDMAP_GetHeapId(sys);
    obj = FIELDMAP_GetCamera(sys);
    snd = FIELDMAP_GetMmdlSys(sys);
    n = SCRIPT_WORK_ReadWorkValue(a, b);
    p = func_02030734(heap, 0x10, 1, sScrcmdC03centerFileName, 0x5d);
    gCameraTurnAngle = *(u16 *)FIELD_CAMERA_GetViewYawPtr(obj);
    FLDMMDL_SetAreaIdRef(snd, (u32)&g_021EE724_ref);
    q = FIELD_CAMERA_GetMoveGoal(obj);
    p->f0 = gCameraTurnAngle;
    v = ((struct Obj20016 *)q)->f26;
    p->f4 = v;
    m = v % 0x4000;
    if (m >= 0x2000) {
        p->f4 = v + (0x4000 - m);
    } else {
        p->f4 = v - m;
    }
    p->f4 -= p->f0;
    d = p->f4;
    if ((d < 0 ? -d : d) >= 0x8000) {
        if (d > 0) {
            p->f4 -= 0x10000;
        } else {
            p->f4 += 0x10000;
        }
    }
    p->f8 = 0;
    p->fc = n;
    func_02030DA8(task, (void (*)())SCRCMD_C03CENTER_CameraTurnTaskMain, p, 0);
    return 0;
}
