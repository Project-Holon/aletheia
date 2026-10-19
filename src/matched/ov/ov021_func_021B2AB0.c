/*
 * function: SCRCMD_SCREENEFFECTS_StartRecoveryPartyEvent
 * address:  0x021B2AB0
 * packet:   pkt_ov021_021B2AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   EVENT_RECOVERY_CreatePartyEvent  0x021C0AA0  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetEvent(void *p);
extern void *EVENT_RECOVERY_CreatePartyEvent(void *p, int a1);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_SCREENEFFECTS_StartRecoveryPartyEvent(u32 a, u32 b)
{
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRIPT_SYS_CallEvent(s, EVENT_RECOVERY_CreatePartyEvent(d, (int)SCRIPT_WORK_GetEvent((void *)s)));
    return 1;
}
