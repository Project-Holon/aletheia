/*
 * function: SCRCMD_MSGWIN_CmdWaitMsgKey
 * address:  0x021B15B8
 * packet:   pkt_ov021_021B15B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitKeyWithCursor  0x021B1550  thumb  ov021
 */

typedef unsigned int u32;

extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitKeyWithCursor(int a, int b);

int SCRCMD_MSGWIN_CmdWaitMsgKey(u32 a)
{
    VM_SetWait((char *)a, (u32)SCRCMD_MSGWIN_WaitKeyWithCursor);
    return 1;
}
