/*
 * function: SCRCMD_PROC_FLD_WaitCameraIdle
 * address:  0x021B54FC
 * packet:   pkt_ov021_021B54FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_PROC_FLD_PollCameraIdle  0x021B55F0  thumb  ov021
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern int SCRCMD_PROC_FLD_PollCameraIdle(void *a);

int SCRCMD_PROC_FLD_WaitCameraIdle(void *a, void *b)
{
    void *s = SCRCMD_WORK_GetScriptWork(b);
    void *d = SCRCMD_WORK_GetGameSystem(b);

    SCRIPT_SYS_CallEvent(s, func_020122C0(d, 0, SCRCMD_PROC_FLD_PollCameraIdle, 0));
    return 1;
}
