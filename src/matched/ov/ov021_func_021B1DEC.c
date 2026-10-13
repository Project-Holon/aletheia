/*
 * function: SCRCMD_FLDMMDL_StartPlayerOffsetTaskAgain
 * address:  0x021B1DEC
 * packet:   pkt_ov021_021B1DEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_TASK_CreateMmdlPosOffsetTween  0x021C78DC  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELD_TASK_CreateMmdlPosOffsetTween(u32, int, void *, void *);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);

int SCRCMD_FLDMMDL_StartPlayerOffsetTaskAgain(u32 a, u32 b)
{
    struct { int x, y, z; } v;
    u32 x;
    u32 y;
    int neg;
    int q;
    int p;
    int z;
    int zero;
    void *w;

    x = ((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1];
    y = FIELDMAP_GetTaskManager((u8 *)x);
    neg = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    p = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    q = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    if (neg != 0)
        p = -p;
    if (z == 0) {
        zero = 0;
        v.x = zero;
        v.y = -q << 12;
        v.z = zero;
    } else {
        zero = 0;
        v.x = zero;
        v.y = q << 12;
        v.z = zero;
    }
    w = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)x));
    FIELD_TASK_MANAGER_AddTask((u8 *)y, (u32 *)FIELD_TASK_CreateMmdlPosOffsetTween(x, p, &v, w), 0);
    return 0;
}
