/*
 * function: SCRCMD_FLDMMDL_StartMmdlDropIn
 * address:  0x021B229C
 * packet:   pkt_ov021_021B229C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_FLDMMDL_StartMmdlDropIn  0x021B229C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FIELD_TASK_CreatePlayerDrop  0x021C7684  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   gScrcmdFldmmdlDropInDrawOffset     0x021D9424  data   a4
 */

typedef short s16;
typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

extern const Vec gScrcmdFldmmdlDropInDrawOffset;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
typedef unsigned char  u8;
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern int FLDMMDL_MOVE_GetMapHeight(u32 m, Vec *pos, int *h);
extern void FLDMMDL_InitGridPosition(u32 m, s16 x, s16 y, s16 z, u32 e);
extern void FLDMMDL_SetPos(u32, Vec *);
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern void *FIELD_TASK_CreatePlayerDrop(u32 a, u32 b, int c, int d);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);

int SCRCMD_FLDMMDL_StartMmdlDropIn(u32 a, u32 b)
{
    Vec pos;
    Vec rot;
    int h;
    u32 k0, k1, k2, k3, o, e, g;
    void *t;

    t = SCRCMD_WORK_GetScriptWork((void *)b);
    k0 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    k1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    k2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    k3 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o = (u32)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo((void *)b), k0);
    e = ((u32 *)SCRIPT_WORK_ResetFieldParam((int)t))[1];
    g = FIELDMAP_GetTaskManager((u8 *)e);
    if (o == 0) {
        return 0;
    }
    h = 0;
    pos.x = (k1 << 16) + 0x8000;
    pos.y = 0xFA000;
    pos.z = (k2 << 16) + 0x8000;
    FLDMMDL_MOVE_GetMapHeight(o, &pos, &h);
    pos.y = h;
    FLDMMDL_InitGridPosition(o, k1, (pos.y >> 4) / 0x1000, k2, k3);
    FLDMMDL_SetPos(o, &pos);
    rot = gScrcmdFldmmdlDropInDrawOffset;
    FLDMMDL_SetDrawOffset(o, &rot);
    FIELD_TASK_MANAGER_AddTask((u8 *)g, (u32 *)FIELD_TASK_CreatePlayerDrop(e, o, 0x28, 0xfa), 0);
    return 0;
}
