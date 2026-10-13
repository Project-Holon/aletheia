/*
 * function: TRCARD_SYS_ScrCmdRunScriptTask
 * address:  0x0216F8DC
 * packet:   pkt_0216F8DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GIMMICK65_CallWaitEvent  0x021F38BC  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GIMMICK65_CallWaitEvent();
extern int SCRIPT_SYS_CallEvent();

int TRCARD_SYS_ScrCmdRunScriptTask(int a0, int a1)
{    int t5;
    void *task;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216F8E6:
a0 = t5 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216F8EE:
    task = GIMMICK65_CallWaitEvent(v1);
loc_0216F8F2:
    a0 = SCRIPT_SYS_CallEvent(v0, task);
loc_0216F8FA:
a0 = 1;
    return a0;}
