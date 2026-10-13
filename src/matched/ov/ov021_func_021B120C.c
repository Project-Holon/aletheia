/*
 * function: SCRCMD_MSGWIN_DeleteAllSubWins
 * address:  0x021B120C
 * packet:   pkt_ov021_021B120C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_MSGBG_DeleteAllSubMsgWin  0x02191978  thumb  ov021
 */

typedef unsigned int u32;

extern int SCRIPT_WORK_CheckFlag(int a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct P;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void FIELD_MSGBG_DeleteAllSubMsgWin(struct P *p);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

void SCRCMD_MSGWIN_DeleteAllSubWins(u32 a)
{
    u32 id = 5;

    if (SCRIPT_WORK_CheckFlag(id)) {
        FIELD_MSGBG_DeleteAllSubMsgWin((struct P *)(*((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)a)))));
        SCRIPT_WORK_ResetCheckFlag(id);
    }
}
