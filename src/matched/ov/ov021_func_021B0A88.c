/*
 * function: SCRCMD_MSGWIN_StartCloseTalkWin
 * address:  0x021B0A88
 * packet:   pkt_ov021_021B0A88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   SCRCMD_MSGWIN_WaitTalkWinClose  0x021B0A60  thumb  ov021
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int SCRIPT_WORK_CheckFlag(int a0);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern int FIELD_MSGBG_DeleteTalkWin(u32 a);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitTalkWinClose(u32 a, u32 b, u32 c, u32 d);

void SCRCMD_MSGWIN_StartCloseTalkWin(u32 a, u32 b)
{
    if (SCRIPT_WORK_CheckFlag(2) != 0) {
        FIELD_MSGBG_DeleteTalkWin(SCRCMD_WORK_GetMsgWindow(b));
        VM_SetWait((char *)a, (int)SCRCMD_MSGWIN_WaitTalkWinClose);
    }
}
