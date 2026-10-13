/*
 * function: EVENT_COMM_COMMON_CmdCallExitSyncEvent
 * address: 0x0217F648
 * packet: pkt_ov018_0217F648
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F67A.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   EVENT_COMM_COMMON_CreateExitSyncEvent 0x0217F67C thumb ov018
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
typedef unsigned short u16;
extern void *SCRCMD_WORK_GetScriptWork(void *);
extern void *SCRCMD_WORK_GetGameSystem(void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *, void *);
extern void *EVENT_COMM_COMMON_CreateExitSyncEvent(void *, u16 *);
extern void SCRIPT_SYS_CallEvent(void *, void *);
int EVENT_COMM_COMMON_CmdCallExitSyncEvent(void *a, void *vm)
{
    void *owner = SCRCMD_WORK_GetScriptWork(vm);
    void *sys = SCRCMD_WORK_GetGameSystem(vm);
    SCRIPT_SYS_CallEvent(owner, EVENT_COMM_COMMON_CreateExitSyncEvent(sys, SCRIPT_WORK_ReadWorkPointer(a, vm)));
    return 1;
}
