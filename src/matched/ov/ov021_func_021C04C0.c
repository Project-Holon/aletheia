/*
 * function: EVENT_DISAPPEAR_RunRisingSpin
 * address:  0x021C04C0
 * packet:   pkt_ov021_021C04C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_CreateFade  0x021C7814  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   FADE_IsActive  0x0204E804  arm
 */

typedef struct { int x, y, z; } Vec;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetCamera(void *p);
typedef unsigned char  u8;
extern unsigned int FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, unsigned int s);
extern void *FIELD_TASK_CreatePlayerSpinLinear(unsigned int a, unsigned int b, unsigned int c);
extern int FIELD_TASK_CreateFade(int, int, int, int, int);
extern int FIELD_TASK_CreatePlayerDrawOffsetTween(unsigned int a, unsigned int b, unsigned int c);
extern unsigned int FIELDMAP_GetTaskManager(u8 *p);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, unsigned int *a, unsigned int b);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FIELD_TASK_MANAGER_IsEmpty(int);
extern int FADE_IsActive(void);

int EVENT_DISAPPEAR_RunRisingSpin(int task, int *state, int *q)
{
    int obj;
    int h;
    int w;
    int e;
    int x;
    int d;

    obj = q[1];
    FIELDMAP_GetFieldPlayer((void *)obj);
    h = (int)FIELDMAP_GetCamera((void *)obj);

    switch (*state) {
    case 0:
        q[2] = FIELD_CAMERA_GetMode((u8 *)h);
        FIELD_CAMERA_SetMode((u8 *)h, 0);
        {
            Vec v;
            v.y = 0x96000;
            v.x = 0;
            v.z = 0;
            w = (int)FIELD_TASK_CreatePlayerSpinLinear(obj, 0x18, 3);
            e = FIELD_TASK_CreateFade(obj, 3, 0, 0x10, 1);
            x = FIELD_TASK_CreatePlayerDrawOffsetTween(obj, 0x18, (unsigned int)(&v));
        }
        d = FIELDMAP_GetTaskManager((u8 *)obj);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (unsigned int *)w, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (unsigned int *)x, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (unsigned int *)e, x);
        GFL_USE_PlaySeDefaultVolume(0x676);
        (*state)++;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager((u8 *)obj)) != 0 && FADE_IsActive() == 0)
            (*state)++;
        break;
    case 2:
        FIELD_CAMERA_SetMode((u8 *)h, q[2]);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
