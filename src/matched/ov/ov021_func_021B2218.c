/*
 * function: SCRCMD_FLDMMDL_StartMmdlSpinRise
 * address:  0x021B2218
 * packet:   pkt_ov021_021B2218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_TASK_CreateMmdlDrawOffsetTween  0x021C7878  thumb  ov021
 *   FIELD_TASK_CreateMmdlSpinLinear  0x021C7220  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 FIELD_TASK_CreateMmdlDrawOffsetTween(u32, u32, void *, u32);
extern void *FIELD_TASK_CreateMmdlSpinLinear(u32 a, u16 b, int c, u32 d);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);

int SCRCMD_FLDMMDL_StartMmdlSpinRise(u32 a, u32 b)
{
    int v[3];
    void *t;
    u32 o;
    u32 e;
    u32 g;
    u32 p;

    t = SCRCMD_WORK_GetScriptWork((void *)b);
    o = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o = (u32)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo((void *)b), o);
    e = ((u32 *)SCRIPT_WORK_ResetFieldParam((int)t))[1];
    g = FIELDMAP_GetTaskManager((u8 *)e);
    GFL_USE_PlaySeDefaultVolume(0x676);
    v[0] = 0;
    v[1] = 0x96 << 12;
    v[2] = 0;
    p = FIELD_TASK_CreateMmdlDrawOffsetTween(e, 0x18, v, o);
    FIELD_TASK_MANAGER_AddTask((u8 *)g, (u32 *)FIELD_TASK_CreateMmdlSpinLinear(e, 0x18, 3, o), 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)g, (u32 *)p, 0);
    return 0;
}
