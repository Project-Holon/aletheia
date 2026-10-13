/*
 * function: EVENT_APPEAR_RunSpinZoomSmoke
 * address:  0x021BFA6C
 * packet:   pkt_ov021_021BFA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseOut  0x021C72AC  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam  0x0218FEC0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb  ov021
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 */

typedef struct {
    int w[8];
} V8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    V8 v10;
    V8 v30;
    int f50;
    int f54;
    int f58;
} Q;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void *FIELD_TASK_CreatePlayerSpinEaseOut(u32 a, u16 b, int c, int d);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);
extern void *FIELD_CAMERA_ANIME_Create(void *a);
extern void FIELD_CAMERA_ANIME_SetData(u8 *p, u32 v);
extern void FIELD_CAMERA_ANIME_Setup(int);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(int, V8 *);
extern void FIELD_CAMERA_ANIME_ApplyStartParam(u8 *o);
extern int FIELD_CAMERA_ANIME_Start(u32 a);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_TASK_MANAGER_IsEmpty(int);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FLDEFF_KEMURI_Start(u32 a, u32 b);
extern void FIELD_CAMERA_ANIME_Restore(u8 *a);
extern void FIELD_CAMERA_ANIME_Delete(void *a0);

int EVENT_APPEAR_RunSpinZoomSmoke(int task, int *state, Q *q)
{
    int q0;
    int obj;
    int h;
    int d;
    int r0;
    void *t;

    q0 = q->f0;
    obj = q->f4;
    h = (int)FIELDMAP_GetCamera((void *)obj);
    d = FIELDMAP_GetTaskManager((u8 *)obj);

    switch (*state) {
    case 0:
        FIELD_CAMERA_EndDelay((u8 *)h);
        (*state)++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled((u8 *)h) == 0)
            (*state)++;
        break;
    case 2:
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)FIELD_TASK_CreatePlayerSpinEaseOut(obj, 0x3c, 8, 1), 0);
        r0 = (int)FIELD_CAMERA_ANIME_Create((void *)obj);
        q->fc = 60;
        q->f50 = 1;
        q->f54 = 1;
        q->f58 = r0;
        FIELD_CAMERA_ANIME_SetData((u8 *)r0, (u32)(&q->fc));
        FIELD_CAMERA_ANIME_Setup(q->f58);
        FIELD_CAMERA_ANIME_GetCurrentParam(h, &q->v30);
        q->v10 = q->v30;
        q->v10.w[1] = q->v10.w[1] - 0x64000;
        FIELD_CAMERA_ANIME_ApplyStartParam((u8 *)q->f58);
        FIELD_CAMERA_ANIME_Start(q->f58);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)task, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)q0, obj, 0, 1, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        if (FIELD_TASK_MANAGER_IsEmpty(d) != 0) {
            t = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)obj));
            FLDEFF_KEMURI_Start((u32)t, FIELDMAP_GetEffect((u8 *)obj));
            (*state)++;
        }
        break;
    case 5:
        FIELD_CAMERA_ANIME_Restore((u8 *)q->f58);
        FIELD_CAMERA_ANIME_Delete((void *)q->f58);
        return 1;
    }
    return 0;
}
