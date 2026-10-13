/*
 * function: SCRCMD_MSGWIN_CloseSpWin
 * address:  0x021B13F8
 * packet:   pkt_ov021_021B13F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_DeleteSpWin  0x02192628  thumb  ov021
 */

typedef unsigned int u32;

extern int SCRIPT_WORK_CheckFlag(int a0);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
typedef unsigned char  u8;
extern void FIELD_MSGBG_DeleteSpWin(u32 *a);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

void SCRCMD_MSGWIN_CloseSpWin(u32 a)
{
    u32 id = 6;

    if (SCRIPT_WORK_CheckFlag(id)) {
        FIELD_MSGBG_DeleteSpWin((u32 *)SCRCMD_WORK_GetMsgWindow(a));
        SCRCMD_WORK_SetMsgWindow((u8 *)a, 0);
        SCRIPT_WORK_ResetCheckFlag(id);
    }
}
