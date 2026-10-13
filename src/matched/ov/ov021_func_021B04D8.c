/*
 * function: SCRCMD_MSGWIN_CmdInfoSysWinMsg
 * address:  0x021B04D8
 * packet:   pkt_ov021_021B04D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_MSGWIN_OpenInfoSysWin  0x021B03E4  thumb  ov021
 *   SCRCMD_MSGWIN_ExpandMessage  0x021B162C  thumb  ov021
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_InfoSysWinPrintStr  0x02191084  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitInfoSysWin  0x021B04C0  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
typedef unsigned short u16;
struct P;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void SCRCMD_MSGWIN_OpenInfoSysWin(u32, u32);
extern u32 SCRCMD_MSGWIN_ExpandMessage(u32 a, u32 b, u32 c);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern void FIELD_MSGBG_InfoSysWinPrintStr(struct P *p, u32 b, u16 c, u32 d);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitInfoSysWin(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_MSGWIN_CmdInfoSysWinMsg(u32 a, u32 b)
{
    u32 x, y;
    void *t;

    t = SCRCMD_WORK_GetScriptWork((void *)b);
    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRCMD_MSGWIN_OpenInfoSysWin(b, (u8)VM_GetU16((struct Stream *)a));
    y = SCRCMD_MSGWIN_ExpandMessage(b, (u32)t, x);
    FIELD_MSGBG_InfoSysWinPrintStr((struct P *)SCRCMD_WORK_GetMsgWindow(b), 0, 0, y);
    VM_SetWait((char *)a, (u32)SCRCMD_MSGWIN_WaitInfoSysWin);
    return 1;
}
