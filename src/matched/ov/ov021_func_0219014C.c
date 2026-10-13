/*
 * function: FIELD_CAMERA_ANIME_StartMoveTasks
 * address:  0x0219014C
 * packet:   pkt_ov021_0219014C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_GetData  0x021901E8  thumb  ov021
 *   FIELD_TASK_CreateCameraPitchTween  0x021C7058  thumb  ov021
 *   FIELD_TASK_CreateCameraYawTween  0x021C701C  thumb  ov021
 *   FIELD_TASK_CreateCameraDistanceTween  0x021C6F00  thumb  ov021
 *   FIELD_TASK_CreateCameraLerp  0x021C7C10  thumb  ov021
 *   FIELD_TASK_CreateCameraTargetTween  0x021C7AE4  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09472.h"
#include "../include/Obj19581.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_CAMERA_ANIME_GetData(u8 *p);
extern u32 FIELD_TASK_CreateCameraPitchTween(u32 a, u32 b, u32 c);
extern u32 FIELD_TASK_CreateCameraYawTween(u32 a, u32 b, u32 c);
extern u32 FIELD_TASK_CreateCameraDistanceTween(u32 a, u16 b, u32 c);
extern u32 FIELD_TASK_CreateCameraLerp(u32 a, u16 b, void *c, void *d);
extern u32 FIELD_TASK_CreateCameraTargetTween(u32 a, u32 b, void *c);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);

void FIELD_CAMERA_ANIME_StartMoveTasks(u32 *a)
{
    u32 h = *a;
    u8 *o = (u8 *)FIELD_CAMERA_ANIME_GetData((u8 *)a);
    u32 k = ((struct Obj19581 *)o)->f0;
    u8 *q = o + 0x24;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = FIELD_TASK_CreateCameraPitchTween(h, k, ((struct Obj09472 *)q)->f0);
    v1 = FIELD_TASK_CreateCameraYawTween(h, k, ((struct Obj09472 *)q)->f2);
    v2 = FIELD_TASK_CreateCameraDistanceTween(h, k, ((struct Obj09472 *)q)->f4);
    v3 = FIELD_TASK_CreateCameraLerp(h, k, o + 0xc, q + 8);
    v4 = FIELD_TASK_CreateCameraTargetTween(h, k, q + 0x14);
    h = FIELDMAP_GetTaskManager((u8 *)h);
    FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)v0, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)v1, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)v2, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)v3, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)h, (u32 *)v4, 0);
}
