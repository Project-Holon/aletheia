/*
 * function: EVENT_COMM_COMMON_CmdCallMissionInfoEvent
 * address: 0x0217F914
 * packet: pkt_ov018_0217F914
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow at 0x0217F936.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 *   EVENT_COMM_COMMON_CreateMissionInfoEvent 0x0217F938 thumb ov018
 */
extern void *SCRCMD_WORK_GetScriptWork(void *);
extern void *SCRCMD_WORK_GetGameSystem(void *);
extern void SCRIPT_SYS_CallEvent(void *, void *);
extern void *EVENT_COMM_COMMON_CreateMissionInfoEvent(void *);
int EVENT_COMM_COMMON_CmdCallMissionInfoEvent(void *unused, void *vm)
{
    void *owner;
    owner = SCRCMD_WORK_GetScriptWork(vm);
    SCRIPT_SYS_CallEvent(owner, EVENT_COMM_COMMON_CreateMissionInfoEvent(SCRCMD_WORK_GetGameSystem(vm)));
    return 1;
}
