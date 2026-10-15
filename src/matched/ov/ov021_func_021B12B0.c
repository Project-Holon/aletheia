/*
 * function: SCRCMD_MSGWIN_CmdBgWinMsg
 * address:  0x021B12B0
 * packet:   pkt_ov021_021B12B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdBgWinMsg  0x021B12B0  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   FIELD_MSGBG_CreateBgWin  0x02191A04  thumb  ov021
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRCMD_MSGWIN_WaitBgWin  0x021B1240  thumb
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
struct Stream;
struct WordSet;
extern u16 VM_GetU16(struct Stream *s);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern unsigned int SCRCMD_WORK_GetMsgData(unsigned char *p);
extern int FIELD_MSGBG_CreateBgWin(int, int);
extern void SCRCMD_WORK_SetMsgWindow(unsigned char *p, unsigned int v);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void VM_SetWait(char *p, int val);
extern void SCRIPT_WORK_SetCheckFlag(int);
extern int SCRCMD_MSGWIN_WaitBgWin(int, int);

int SCRCMD_MSGWIN_CmdBgWinMsg(int a, unsigned char *b)
{
    void *o;
    int s0, s1, s2;
    int *q;
    int x, y, z;
    o = SCRCMD_WORK_GetScriptWork((void *)b);
    s0 = VM_GetU16((struct Stream *)a);
    s1 = VM_GetU16((struct Stream *)a);
    q = (int *)SCRIPT_WORK_ResetFieldParam((int)o);
    s2 = SCRCMD_WORK_GetMsgData(b);
    SCRCMD_WORK_SetMsgWindow(b, FIELD_MSGBG_CreateBgWin(*q, s1));
    x = SCRIPT_WORK_GetMsgBuffer(o);
    y = (int)SCRIPT_WORK_GetWordSet(o);
    z = SCRIPT_WORK_GetTempBuffer(o);
    MSGDATA_ReadString((struct MsgBank *)s2, s0, (void *)z);
    WORDSET_CopyTaggedText((struct WordSet *)y, (void *)x, (void *)z);
    VM_SetWait((char *)a, (int)SCRCMD_MSGWIN_WaitBgWin);
    SCRIPT_WORK_SetCheckFlag(4);
    return 1;
}
