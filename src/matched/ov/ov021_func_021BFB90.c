/*
 * function: EVENT_APPEAR_RunDescendingSpin
 * address:  0x021BFB90
 * packet:   pkt_ov021_021BFB90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef struct { int x, y, z; } Vec;

typedef unsigned char  u8;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
extern unsigned int FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, unsigned int s);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void FLDMMDL_SetDrawOffset(void *, Vec *);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *FIELD_TASK_CreatePlayerSpinLinear(unsigned int a, unsigned int b, unsigned int c);
extern int FIELD_TASK_CreatePlayerDrawOffsetTween(unsigned int a, unsigned int b, unsigned int c);
extern unsigned int FIELDMAP_GetTaskManager(u8 *p);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, unsigned int *a, unsigned int b);
extern int FIELD_TASK_MANAGER_IsEmpty(int);
extern unsigned int FIELDMAP_GetEffect(u8 *p);
extern void FLDEFF_KEMURI_Start(unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);

int EVENT_APPEAR_RunDescendingSpin(int task, int *state, int *q)
{
    int obj;
    int h;
    void *t;
    int w;
    int x;
    int d;

    obj = q[1];
    h = (int)FIELDMAP_GetCamera((void *)obj);

    switch (*state) {
    case 0:
        q[2] = FIELD_CAMERA_GetMode((u8 *)h);
        FIELD_CAMERA_SetMode((u8 *)h, 0);
        t = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)obj));
        {
            Vec v;
            v.y = 0xA000;
            v.x = 0;
            v.z = 0;
            FLDMMDL_SetDrawOffset(t, &v);
        }
        GAME_EVENT_CallEvent((struct Evt *)task, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)q[0], obj, 0, 1, 1, 0, 0));
        {
            Vec v2;
            v2.y = 0x96000;
            v2.x = 0;
            v2.z = 0;
            w = (int)FIELD_TASK_CreatePlayerSpinLinear(obj, 0x18, 3);
            x = FIELD_TASK_CreatePlayerDrawOffsetTween(obj, -0x18, (unsigned int)(&v2));
        }
        d = FIELDMAP_GetTaskManager((u8 *)obj);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (unsigned int *)w, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (unsigned int *)x, 0);
        (*state)++;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager((u8 *)obj)) != 0)
            (*state)++;
        break;
    case 2:
        t = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)obj));
        FLDEFF_KEMURI_Start((unsigned int)t, FIELDMAP_GetEffect((u8 *)q[1]));
        func_020061E4(0x67B);
        (*state)++;
        break;
    case 3:
        FIELD_CAMERA_SetMode((u8 *)h, q[2]);
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
