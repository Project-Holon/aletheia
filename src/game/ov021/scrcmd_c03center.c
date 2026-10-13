/*
 * file:     scrcmd_c03center.c
 * unit:     yes
 * function: func_021B5A18, func_021B5B0C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0218ED50  0x0218ED50  thumb  ov021
 *   func_0218FE70  0x0218FE70  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE25C     0x021DE25C  data  a1
 *   g_021EE724     0x021EE724  data  a2
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../arm9/script_vm_types.h"

struct ScrcmdWork;
struct GameSystem;
struct Tcb;

/*
 * Camera turn state of func_021B5A18 (0x10 bytes, heap block owned by the
 * TCB that func_021B5B0C steps).
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

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_02159B10(void *, void *);
extern void func_0216CDB8(u8 *p, u32 v);
extern void *func_0201210C(const struct GameSystem *p);
extern u32 func_02188D30(u8 *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern void *func_02188C7C(u8 *p);
extern u8 *func_0218ED50(u8 *p);
extern u8 *func_0218FE70(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(u32, void (*)(), void *, u32);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Tcb *tcb);
int func_021B5A18(struct ScriptVm *vm, struct ScrcmdWork *work);
void func_021B5B0C(struct Tcb *tcb, CameraTurnTask *turn);
extern const char d_021DE25C[];
extern u16 g_021EE724;
/* Second name for the same object: the pool needs a separate literal for the address handed to the map model system. */
extern u16 g_021EE724_ref;

/*
 * Script command: turn the field camera to the nearest quarter turn over a
 * number of frames. Allocates the CameraTurnTask that func_021B5B0C steps
 * and starts it as a TCB (its own matched source names the fields).
 *
 * Addresses are Black-image addresses.
 */
int func_021B5A18(struct ScriptVm *vm, struct ScrcmdWork *work)
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

    func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    func_0215A5E4(work);
    gameSystem = func_0201210C(gameSystem);
    tcbSys = func_02188D30(gameSystem);
    heapId = func_02188C84(gameSystem);
    camera = func_02188C58(gameSystem);
    mmdlSys = func_02188C7C(gameSystem);
    frameCount = func_02159B10(vm, work);
    turn = func_02030734(heapId, 0x10, 1, d_021DE25C, 0x5d);
    g_021EE724 = *(u16 *)func_0218ED50(camera);
    func_0216CDB8(mmdlSys, (u32)&g_021EE724_ref);
    cameraDirection = (FieldCameraDirection *)func_0218FE70(camera);
    turn->startAngle = g_021EE724;
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
    func_02030DA8(tcbSys, func_021B5B0C, turn, 0);
    return 0;
}

/* TCB function: advances the camera angle by one step of the turn. */
void func_021B5B0C(struct Tcb *tcb, CameraTurnTask *turn)
{
    turn->frame++;
    g_021EE724 = (turn->angleDelta * turn->frame) / turn->frameCount;
    g_021EE724 = g_021EE724 + (u16)turn->startAngle;
    if (turn->frame >= turn->frameCount) {
        func_020307B0(turn);
        func_02030EAC(tcb);
    }
}
