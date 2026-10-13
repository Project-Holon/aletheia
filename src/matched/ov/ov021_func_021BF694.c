/*
 * function: EVENT_APPEAR_RunPlayerDrop
 * address:  0x021BF694
 * packet:   pkt_ov021_021BF694
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_TASK_CreatePlayerDrop  0x021C7684  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   d_021DA080     0x021DA080  data   a4
 */

typedef struct { int x, y, z; } Vec;

extern const Vec d_021DA080;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FLDMMDL_SetDrawOffset(void *, Vec *);
typedef unsigned short u16;
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *FIELD_TASK_CreatePlayerDrop(u32 a, u32 b, int c, int d);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);
extern int FIELD_TASK_MANAGER_IsEmpty(int);

int EVENT_APPEAR_RunPlayerDrop(int a, int *s, int *q)
{
    int h = (int)FIELDMAP_GetCamera((void *)q[1]);
    Vec rot;
    void *t;
    int r;

    switch (s[0]) {
    case 0:
        q[2] = FIELD_CAMERA_GetMode((u8 *)h);
        FIELD_CAMERA_SetMode((u8 *)h, 0);
        rot = d_021DA080;
        t = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)q[1]));
        FLDMMDL_SetDrawOffset(t, &rot);
        FLDMMDL_SetAcmd(t, 1);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)q[0], q[1], 0, 1, 1, 0, 0));
        r = (int)FIELD_TASK_CreatePlayerDrop(q[1], (u32)FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)q[1])), 0x28, 0xfa);
        FIELD_TASK_MANAGER_AddTask((u8 *)FIELDMAP_GetTaskManager((u8 *)q[1]), (u32 *)r, 0);
        s[0] = s[0] + 1;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager((u8 *)q[1])) != 0)
            s[0] = s[0] + 1;
        break;
    case 2:
        FIELD_CAMERA_SetMode((u8 *)h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
