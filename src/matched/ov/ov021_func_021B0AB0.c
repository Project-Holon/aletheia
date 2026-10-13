/*
 * function: SCRCMD_MSGWIN_CloseTalkWin
 * address:  0x021B0AB0
 * packet:   pkt_ov021_021B0AB0
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
 *   FIELD_MSGBG_ClearTalkWin  0x0219131C  thumb  ov021
 */

typedef unsigned int u32;

extern int SCRIPT_WORK_CheckFlag(int a0);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern int FIELD_MSGBG_ClearTalkWin(u32 a);
typedef unsigned char  u8;
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

void SCRCMD_MSGWIN_CloseTalkWin(u32 a)
{
    u32 id = 2;

    if (SCRIPT_WORK_CheckFlag(id)) {
        FIELD_MSGBG_ClearTalkWin(SCRCMD_WORK_GetMsgWindow(a));
        SCRCMD_WORK_SetMsgWindow((u8 *)a, 0);
        SCRIPT_WORK_ResetCheckFlag(id);
    }
}
