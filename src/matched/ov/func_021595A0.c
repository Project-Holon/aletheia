/*
 * function: SCRIPT_WORK_WaitChildScript
 * address:  0x021595A0
 * packet:   pkt_021595A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetChildScriptIndex  0x0215AA4C  thumb  ov010
 *   SCRIPT_SYS_HasVm  0x021587E0  thumb  ov010
 *   SCRCMD_WORK_RestoreScriptState  0x0215AA34  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u8 SCRCMD_WORK_GetChildScriptIndex(void *p);
extern int SCRIPT_SYS_HasVm(int a, int b);
extern int SCRCMD_WORK_RestoreScriptState(int a0);

int SCRIPT_WORK_WaitChildScript(int a0, int a1)
{    int t5;
    void *v0;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_021595AA:
a0 = t5 + 0;
    a0 = SCRCMD_WORK_GetChildScriptIndex((void *)a0);
loc_021595B2:
a1 = a0 + 0;
    a0 = SCRIPT_SYS_HasVm((int)v0, a1);
loc_021595BA:
    if (a0 != 0) goto loc_021595C8;
loc_021595BE:
a0 = t5 + 0;
    a0 = SCRCMD_WORK_RestoreScriptState(a0);
loc_021595C4:
a0 = 1;
    return a0;
loc_021595C8:
a0 = 0;
    return a0;}
