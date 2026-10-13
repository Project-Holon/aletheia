/*
 * function: SCRCMD_MSGWIN_CmdBalloonWinMsg
 * address:  0x021B0D14
 * packet:   pkt_ov021_021B0D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdBalloonWinMsg  0x021B0D14  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_MSGWIN_OpenBalloonWinMsg  0x021B0BAC  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitBalloonWin  0x021B0CEC  thumb
 */

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_MSGWIN_OpenBalloonWinMsg(int, int, int, int, int, int);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitBalloonWin(int, int);

int SCRCMD_MSGWIN_CmdBalloonWinMsg(int a, int b)
{
    int v0, v1, v2, v3, v4;
    v0 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v3 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    if (SCRCMD_MSGWIN_OpenBalloonWinMsg(b, v2, v0, v1, v3, v4) == 1) {
        VM_SetWait((char *)a, (int)SCRCMD_MSGWIN_WaitBalloonWin);
        return 1;
    }
    return 0;
}
