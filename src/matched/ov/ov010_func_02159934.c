/*
 * function: SCRIPT_WORK_CmdCallScriptEvent
 * address: 0x02159934
 * packet: pkt_ov010_02159934
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x0215995E.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_WORK_CreateCheckTask 0x02159204 thumb ov010
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRIPT_WORK_CreateCheckTask(void *);
extern void SCRIPT_SYS_CallEvent(void *, void *);
int SCRIPT_WORK_CmdCallScriptEvent(void *a, void *b)
{
    void *x = SCRCMD_WORK_GetScriptWork(b);
    void *t;
    SCRCMD_WORK_GetGameSystem(b);
    t = SCRIPT_WORK_CreateCheckTask(b);
    if (t == 0)
        return 1;
    SCRIPT_SYS_CallEvent(x, t);
    return 1;
}
