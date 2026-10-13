/*
 * function: SCRCMD_MSGWIN_WaitBgWin
 * address:  0x021B1240
 * packet:   pkt_ov021_021B1240
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_BgWinMain  0x02191BE8  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned char  u8;
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern u32 FIELD_MSGBG_BgWinMain(u32 *p, u32 b);

int SCRCMD_MSGWIN_WaitBgWin(int a, int b)
{
    u32 x = SCRIPT_WORK_GetMsgBuffer(SCRCMD_WORK_GetScriptWork((void *)b));

    if (FIELD_MSGBG_BgWinMain((u32 *)SCRCMD_WORK_GetMsgWindow(b), x) == 1) {
        return 1;
    }
    return 0;
}
