/*
 * function: SCRCMD_PROC_ResetEventSlot
 * address:  0x0215C6F0
 * packet:   pkt_0215C6F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_FreeUserWork  0x02158FBC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_FreeUserWork();

int SCRCMD_PROC_ResetEventSlot(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215C6F8:
    a0 = SCRIPT_WORK_FreeUserWork(v0);
loc_0215C6FC:
a0 = 1;
    return a0;}
