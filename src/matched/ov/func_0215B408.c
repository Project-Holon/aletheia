/*
 * function: SCRCMD_WORK_CmdEndScriptStartCommProcB
 * address:  0x0215B408
 * packet:   pkt_0215B408
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   func_02011290  0x02011290  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_NETWORK_CreateCommProcEvent(void *p);
extern int SCRIPT_SYS_SetNextEventFromWork();
extern int func_02011290();

int SCRCMD_WORK_CmdEndScriptStartCommProcB(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215B414:
a0 = t6 + 0;
    v1 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215B41C:
    p = SCRCMD_NETWORK_CreateCommProcEvent(v0);
loc_0215B424:
    a0 = SCRIPT_SYS_SetNextEventFromWork(v1, p);
loc_0215B42C:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B432:
a0 = 1;
    return a0;}
