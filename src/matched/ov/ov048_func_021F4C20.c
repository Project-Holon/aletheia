/*
 * function: GIMMICK_OBJ_ELBOARD_CameraEventMain
 * address:  0x021F4C20
 * packet:   pkt_ov048_021F4C20
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_CAMERA_GetPitch  0x0218ED2C  thumb  ov021
 *   FIELD_CAMERA_GetYaw  0x0218ED40  thumb  ov021
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_GIMMICK_GATE_GetBoardFacing  0x021F3790  thumb  ov048
 *   FIELD_TASK_CreateCameraDistanceTween  0x021C6F00  thumb  ov021
 *   FIELD_TASK_CreateCameraPitchTween  0x021C7058  thumb  ov021
 *   FIELD_TASK_CreateCameraYawTween  0x021C701C  thumb  ov021
 *   FIELD_TASK_CreateCameraTargetTween  0x021C7AE4  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x; int y; int z; } Vec;

typedef struct W {
    int f0;
    u32 f4;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u32 f10;
    Vec v14;
} W;

extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern u16 FIELD_CAMERA_GetPitch(u8 *p);
extern u16 FIELD_CAMERA_GetYaw(u8 *p);
extern u32 FIELD_CAMERA_GetDistance(u8 *p);
extern void FIELD_CAMERA_GetTargetShift(u32 a, void *b);
extern u8 FIELD_GIMMICK_GATE_GetBoardFacing(char *p);
extern u32 FIELD_TASK_CreateCameraDistanceTween(u32 a, u16 b, u32 c);
extern u32 FIELD_TASK_CreateCameraPitchTween(u32 a, u16 b, u16 c);
extern u32 FIELD_TASK_CreateCameraYawTween(u32 a, u16 b, u16 c);
extern u32 FIELD_TASK_CreateCameraTargetTween(u32 a, u16 b, void *c);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);
extern int FIELD_TASK_MANAGER_IsEmpty(u32 a);
extern u32 func_020362DC(void);

int GIMMICK_OBJ_ELBOARD_CameraEventMain(int a0, int *state, W *w)
{
    u32 cam;
    u32 obj;
    u32 h;
    u32 v;

    cam = w->f4;
    obj = (u32)FIELDMAP_GetCamera((void *)cam);
    h = FIELDMAP_GetTaskManager((u8 *)cam);
    switch (*state) {
    case 0:
        w->hA = FIELD_CAMERA_GetPitch((u8 *)obj);
        w->hC = FIELD_CAMERA_GetYaw((u8 *)obj);
        w->f10 = FIELD_CAMERA_GetDistance((u8 *)obj);
        FIELD_CAMERA_GetTargetShift(obj, &w->v14);
        (*state)++;
        break;
    case 1: {
        Vec vec;
        int ang1;
        int ang2;
        u32 dist;
        u32 r0;
        u32 r1;
        u32 r2;
        u32 r3;

        switch (FIELD_GIMMICK_GATE_GetBoardFacing((char *)cam)) {
        case 1:
        default:
            ang1 = 0xEE5;
            dist = 0x86000;
            ang2 = 0;
            vec.x = 0;
            vec.y = 0x1B000;
            vec.z = -0x6C000;
            break;
        case 3:
            ang1 = 0xEE5;
            dist = 0x86000;
            ang2 = 0x3FFF;
            vec.x = -0x6C000;
            vec.y = 0x1B000;
            vec.z = 0;
            break;
        }
        r0 = FIELD_TASK_CreateCameraDistanceTween(cam, w->h8, dist);
        r1 = FIELD_TASK_CreateCameraPitchTween(cam, w->h8, ang1);
        r2 = FIELD_TASK_CreateCameraYawTween(cam, w->h8, ang2);
        r3 = FIELD_TASK_CreateCameraTargetTween(cam, w->h8, &vec);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r0, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r1, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r2, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r3, 0);
        (*state)++;
        break;
    }
    case 2:
        if (FIELD_TASK_MANAGER_IsEmpty(h))
            (*state)++;
        break;
    case 3:
        v = func_020362DC();
        if ((v & 0x20) || (v & 0x10) || (v & 0x80) || (v & 2))
            (*state)++;
        break;
    case 4: {
        u32 r0;
        u32 r1;
        u32 r2;
        u32 r3;

        r0 = FIELD_TASK_CreateCameraDistanceTween(cam, w->h8, w->f10);
        r1 = FIELD_TASK_CreateCameraPitchTween(cam, w->h8, w->hA);
        r2 = FIELD_TASK_CreateCameraYawTween(cam, w->h8, w->hC);
        r3 = FIELD_TASK_CreateCameraTargetTween(cam, w->h8, &w->v14);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r0, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r1, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r2, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)r3, 0);
        (*state)++;
        break;
    }
    case 5:
        if (FIELD_TASK_MANAGER_IsEmpty(h))
            (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
