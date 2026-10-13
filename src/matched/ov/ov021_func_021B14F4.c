/*
 * function: SCRCMD_MSGWIN_CmdCloseAllWins
 * address:  0x021B14F4
 * packet:   pkt_ov021_021B14F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_MSGWIN_CloseInfoSysWin  0x021B0480  thumb  ov021
 *   SCRCMD_MSGWIN_ClosePlainWin  0x021B10A4  thumb  ov021
 *   SCRCMD_MSGWIN_CloseBgWin  0x021B1268  thumb  ov021
 *   SCRCMD_MSGWIN_CloseSpWin  0x021B13F8  thumb  ov021
 *   SCRCMD_MSGWIN_StartCloseTalkWin  0x021B0A88  thumb  ov021
 */

int SCRIPT_WORK_CheckFlag(int a);
typedef unsigned int   u32;
void SCRCMD_MSGWIN_CloseInfoSysWin(u32 a);
void SCRCMD_MSGWIN_ClosePlainWin(void *p);
void SCRCMD_MSGWIN_CloseBgWin(void *p);
void SCRCMD_MSGWIN_CloseSpWin(u32 a);
void SCRCMD_MSGWIN_StartCloseTalkWin(u32 a, u32 b);

int SCRCMD_MSGWIN_CmdCloseAllWins(int a, int b)
{
    if (SCRIPT_WORK_CheckFlag(1)) {
        SCRCMD_MSGWIN_CloseInfoSysWin(b);
    }
    if (SCRIPT_WORK_CheckFlag(3)) {
        SCRCMD_MSGWIN_ClosePlainWin((void *)b);
    }
    if (SCRIPT_WORK_CheckFlag(4)) {
        SCRCMD_MSGWIN_CloseBgWin((void *)b);
    }
    if (SCRIPT_WORK_CheckFlag(6)) {
        SCRCMD_MSGWIN_CloseSpWin(b);
    }
    if (SCRIPT_WORK_CheckFlag(2)) {
        SCRCMD_MSGWIN_StartCloseTalkWin(a, b);
    }
    return 1;
}
