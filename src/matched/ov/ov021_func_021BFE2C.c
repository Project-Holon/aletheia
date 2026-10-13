/*
 * function: EVENT_DISAPPEAR_RunWalkFall
 * address:  0x021BFE2C
 * packet:   pkt_ov021_021BFE2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_CollectEntriesInRect  0x0218C584  thumb  ov021
 *   FIELD_BUILDMODEL_CreateNodeFromEntry  0x0218C724  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_TASK_CreatePlayerPosTween  0x021C754C  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_BUILDMODEL_IsNodeSlotIdle  0x0218C8FC  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_CreateCameraDistanceTween  0x021C6F00  thumb  ov021
 *   FIELD_TASK_CreateFade  0x021C7814  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb  ov021
 */

typedef struct { int x, y, z; } Vec;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
typedef unsigned char  u8;
extern unsigned int FIELDMAP_GetEffect(u8 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern unsigned int FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, unsigned int s);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GFL_USE_GetSeSlot(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int *FIELD_BUILDMODEL_CollectEntriesInRect(int, int *, int, int *);
extern u8 *FIELD_BUILDMODEL_CreateNodeFromEntry(u8 *owner, u32 *obj);
extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c);
extern u32 func_020307B0(void *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *, struct VecFx32 *);
extern int FIELD_TASK_CreatePlayerPosTween(int, int, int *);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);
extern int FIELD_BUILDMODEL_IsNodeSlotIdle(unsigned char *p, int i);
extern unsigned int func_0203630C(void);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern void FLDEFF_KEMURI_Start(u32 a, u32 b);
extern int FIELD_TASK_MANAGER_IsEmpty(int);
extern void func_020061E4(u32 a);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FIELD_TASK_CreatePlayerDrawOffsetTween(u32 a, u32 b, u32 c);
extern void *FIELD_TASK_CreatePlayerSpinLinear(u32 a, u32 b, u32 c);
extern int FIELD_TASK_CreateCameraDistanceTween(int, int, int);
extern int FIELD_TASK_CreateFade(int, int, int, int, int);
extern void func_020061F8(int);
extern void FIELD_BUILDMODEL_DeleteNode(int);

int EVENT_DISAPPEAR_RunWalkFall(int task, int *state, int *q)
{
    void *s;
    void *t;
    int u;
    int h;
    int g;
    int *r;
    int dx;
    int dz;
    int k;
    int e;
    int keys;
    int n;
    int a;
    int b;
    int c;
    int d;
    int rect[4];
    int cnt;
    Vec v;
    Vec w;

    s = FIELDMAP_GetFieldPlayer((struct Obj00020 *)q[1]);
    t = FIELD_PLAYER_GetMmdl((void *)s);
    u = FIELDMAP_GetEffect((u8 *)q[1]);
    h = (int)FIELDMAP_GetCamera((void *)q[1]);

    switch (*state) {
    case 0:
        q[2] = FIELD_CAMERA_GetMode((u8 *)h);
        FIELD_CAMERA_SetMode((u8 *)h, 0);
        *state = 1;
        break;
    case 1:
        func_0200616C((void *)0x680, GFL_USE_GetSeSlot(0x680));
        g = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((u8 *)q[1]));
        rect[2] = q[5] - 0x20000;
        rect[3] = q[5] + 0x20000;
        rect[0] = q[7] - 0x20000;
        rect[1] = q[7] + 0x20000;
        r = FIELD_BUILDMODEL_CollectEntriesInRect(g, rect, 2, &cnt);
        if (*r != 0) {
            q[8] = (int)FIELD_BUILDMODEL_CreateNodeFromEntry((u8 *)g, (u32 *)(*r));
            FIELD_BUILDMODEL_PlayNodeSlot((unsigned char *)q[8], 0, 0);
        } else {
            q[8] = 0;
        }
        func_020307B0(r);
        *state = 2;
        break;
    case 2:
        FIELD_PLAYER_GetPos(s, (struct VecFx32 *)&v);
        dx = (v.x >> 12) / 16 - (q[5] >> 12) / 16;
        dz = (v.z >> 12) / 16 - (q[7] >> 12) / 16;
        if (dx < 0)
            dx = -dx;
        if (dz < 0)
            dz = -dz;
        if (dx == 0 && dz == 0)
            k = 0;
        else if (dx < 2 && dz < 2)
            k = 0x3c;
        else
            k = 0x78;
        if (k > 0) {
            e = FIELD_TASK_CreatePlayerPosTween(q[1], k, &q[5]);
            FIELD_TASK_MANAGER_AddTask((u8 *)FIELDMAP_GetTaskManager((u8 *)q[1]), (u32 *)e, 0);
            *state = 3;
        } else {
            *state = 4;
        }
        q[3] = 0;
        break;
    case 3:
        if (q[8] != 0 && FIELD_BUILDMODEL_IsNodeSlotIdle((unsigned char *)q[8], 0) != 0)
            FIELD_BUILDMODEL_PlayNodeSlot((unsigned char *)q[8], 0, 0);
        keys = func_0203630C();
        if (keys & 0x40)
            FLDMMDL_SetAcmd(t, 0x24);
        if (keys & 0x80)
            FLDMMDL_SetAcmd(t, 0x25);
        if (keys & 0x20)
            FLDMMDL_SetAcmd(t, 0x26);
        if (keys & 0x10)
            FLDMMDL_SetAcmd(t, 0x27);
        n = q[3];
        q[3] = n + 1;
        if (n % 10 == 0)
            FLDEFF_KEMURI_Start((u32)t, u);
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager((u8 *)q[1])) != 0)
            *state = 4;
        break;
    case 4:
        func_020061E4(0x7A0);
        FLDMMDL_SetMoveBit(t, 0x8000);
        w.x = 0;
        w.y = -0x1E000;
        w.z = 0;
        a = FIELD_TASK_CreatePlayerDrawOffsetTween(q[1], 0x22, (u32)(&w));
        b = (int)FIELD_TASK_CreatePlayerSpinLinear(q[1], 0x22, 5);
        c = FIELD_TASK_CreateCameraDistanceTween(q[1], 0x1e, 0xB4000);
        e = FIELD_TASK_CreateFade(q[1], 3, 0, 0x10, 0);
        d = FIELDMAP_GetTaskManager((u8 *)q[1]);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)a, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)b, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)c, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)e, c);
        q[3] = 0;
        *state = 5;
        break;
    case 5:
        if (FIELD_TASK_MANAGER_IsEmpty(FIELDMAP_GetTaskManager((u8 *)q[1])) != 0)
            *state = 6;
        break;
    case 6:
        func_020061F8(GFL_USE_GetSeSlot(0x680));
        FIELD_CAMERA_SetMode((u8 *)h, q[2]);
        if (q[8] != 0)
            FIELD_BUILDMODEL_DeleteNode(q[8]);
        return 1;
    }
    return 0;
}
