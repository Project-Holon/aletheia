/*
 * function: SCRCMD_MSGWIN_ClosePlainWin
 * address:  0x021B10A4
 * packet:   pkt_ov021_021B10A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_MSGWIN_ClosePlainWin  0x021B10A4  thumb
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_DeletePlainWin  0x021915B4  thumb  ov021
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 */

extern int SCRIPT_WORK_CheckFlag(int);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int FIELD_MSGBG_DeletePlainWin(void *a);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_ResetCheckFlag(int);

void SCRCMD_MSGWIN_ClosePlainWin(void *p)
{
    int n = 3;
    if (SCRIPT_WORK_CheckFlag(3) != 0) {
        FIELD_MSGBG_DeletePlainWin((void *)SCRCMD_WORK_GetMsgWindow((int)p));
        SCRCMD_WORK_SetMsgWindow(p, 0);
        SCRIPT_WORK_ResetCheckFlag(n);
    }
}
