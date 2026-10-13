/*
 * function: SCRCMD_MSGWIN_CmdDeleteSubWinMsg
 * address:  0x021B11D8
 * packet:   pkt_ov021_021B11D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_MSGBG_DeleteSubMsgWin  0x0219196C  thumb  ov021
 *   FIELD_MSGBG_ExistsSubMsgWin  0x021919AC  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Stream;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 VM_GetU16(struct Stream *s);
extern void FIELD_MSGBG_DeleteSubMsgWin(u32, u32);
extern int FIELD_MSGBG_ExistsSubMsgWin(u8 *p);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_MSGWIN_CmdDeleteSubWinMsg(u32 a, u32 b)
{
    u32 *p = (u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b));

    FIELD_MSGBG_DeleteSubMsgWin(*p, VM_GetU16((struct Stream *)a));
    if (FIELD_MSGBG_ExistsSubMsgWin((u8 *)(*p)) == 0) {
        SCRIPT_WORK_ResetCheckFlag(5);
    }
    return 0;
}
