/*
 * function: SCRCMD_PopBgm
 * address:  0x021AF130
 * packet:   pkt_ov021_021AF130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_PopBgm(u32 a, u32 b)
{
    u32 u;
    void *x;
    void *p;

    x = SCRCMD_WORK_GetGameSystem((void *)b);
    p = SCRCMD_WORK_GetScriptWork((void *)b);
    u = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_SYS_CallEvent(p, (void *)FIELD_SOUND_SYSTEM_StartPopAndWaitTask(x, u, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)));
    SCRIPT_WORK_ResetCheckFlag(10);
    return 1;
}
