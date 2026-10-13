/*
 * function: SCRCMD_MSGWIN_WaitBalloonWin
 * address:  0x021B0CEC
 * packet:   pkt_ov021_021B0CEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb
 *   SCRCMD_MSGWIN_UpdateBalloonPos  0x021B0B08  thumb  ov021
 */

typedef unsigned int u32;

extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern void SCRCMD_MSGWIN_UpdateBalloonPos(void *a, int b);
extern u32 FIELD_MSGBG_TalkWinMain(u32 *a);

int SCRCMD_MSGWIN_WaitBalloonWin(int a, int b)
{
    u32 t;

    t = SCRCMD_WORK_GetMsgWindow(b);
    SCRCMD_MSGWIN_UpdateBalloonPos((void *)b, 0);
    b = 0;
    if (FIELD_MSGBG_TalkWinMain((u32 *)t) == 1) {
        b = 1;
    }
    return b;
}
