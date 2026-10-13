/*
 * function: SCRCMD_MSGWIN_CmdInfoSysWinMsgNow
 * address:  0x021B0530
 * packet:   pkt_ov021_021B0530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_MSGWIN_OpenInfoSysWin  0x021B03E4  thumb  ov021
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_ClearInfoSysWin  0x02191164  thumb  ov021
 *   FIELD_MSGBG_InfoSysWinPrintStrNow  0x02191184  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct P;
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
typedef unsigned short u16;
struct MsgBank;
struct Q;
struct Stream;
struct WordSet;
extern u16 VM_GetU16(struct Stream *s);
extern void SCRCMD_MSGWIN_OpenInfoSysWin(u32, u32);
extern u32 SCRCMD_WORK_GetMsgData(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern void FIELD_MSGBG_ClearInfoSysWin(struct P *p);
extern void FIELD_MSGBG_InfoSysWinPrintStrNow(struct Q *q, u32 b, int c, u32 d);

int SCRCMD_MSGWIN_CmdInfoSysWinMsgNow(u32 a, u32 b)
{
    u32 s, x, y, z, w;
    void *t;

    t = SCRCMD_WORK_GetScriptWork((void *)b);
    s = SCRIPT_WORK_GetMsgBuffer(t);
    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRCMD_MSGWIN_OpenInfoSysWin(b, (u8)VM_GetU16((struct Stream *)a));
    y = SCRCMD_WORK_GetMsgData((u8 *)b);
    z = (u32)SCRIPT_WORK_GetWordSet(t);
    w = SCRIPT_WORK_GetTempBuffer(t);
    MSGDATA_ReadString((struct MsgBank *)y, x, (void *)w);
    func_0201F250((struct WordSet *)z, (void *)s, (void *)w);
    y = SCRCMD_WORK_GetMsgWindow(b);
    FIELD_MSGBG_ClearInfoSysWin((void *)y);
    FIELD_MSGBG_InfoSysWinPrintStrNow((struct Q *)y, 0, 0, s);
    return 0;
}
