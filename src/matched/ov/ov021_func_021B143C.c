/*
 * function: SCRCMD_MSGWIN_CmdSpWinMsg
 * address:  0x021B143C
 * packet:   pkt_ov021_021B143C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdSpWinMsg  0x021B143C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_MSGWIN_ExpandMessage  0x021B162C  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELD_MSGBG_GetStrWidthChars  0x0219270C  thumb  ov021
 *   FIELD_MSGBG_GetStrHeightChars  0x0219272C  thumb  ov021
 *   FIELD_MSGBG_CreateSpWin  0x02192570  thumb  ov021
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   FIELD_MSGBG_SpWinPrintStr  0x0219269C  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitSpWin  0x021B1424  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
typedef unsigned int   u32;
struct Q;
struct T;
extern u32 SCRCMD_MSGWIN_ExpandMessage(u32 a, u32 b, u32 c);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELD_MSGBG_GetStrWidthChars(struct Q *q, int a, int n);
extern u32 FIELD_MSGBG_GetStrHeightChars(u16 *a, u32 b, u32 c);
extern u32 *FIELD_MSGBG_CreateSpWin(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void FIELD_MSGBG_SpWinPrintStr(struct T *t, u16 b, u16 c, u32 d);
extern void VM_SetWait(char *p, int val);
extern void SCRIPT_WORK_SetCheckFlag(int);
extern int SCRCMD_MSGWIN_WaitSpWin(int, int, int, int);

int SCRCMD_MSGWIN_CmdSpWinMsg(void *a, int b)
{
    void *o;
    int s0, k, n;
    u8 s1, s2;
    int *q;
    u16 h0, h1;
    u8 *p;
    u8 **pp =(u8 **)((char *)a + 0x14);
    o = SCRCMD_WORK_GetScriptWork((void *)b);
    s0 = VM_GetU16(a);
    s1 = **pp;
    (*pp)++;
    s2 = **pp;
    (*pp)++;
    k = VM_GetU16(a);
    n = SCRCMD_MSGWIN_ExpandMessage(b, (u32)o, s0);
    q = (int *)SCRIPT_WORK_ResetFieldParam((int)o);
    h0 = FIELD_MSGBG_GetStrWidthChars((struct Q *)(*q), n, 4);
    h1 = FIELD_MSGBG_GetStrHeightChars((u16 *)(*q), n, 4);
    {
        int m = (int)FIELD_MSGBG_CreateSpWin((u16 *)(*q), k, s1, s2, h0, h1);
        SCRCMD_WORK_SetMsgWindow((u8 *)b, m);
        FIELD_MSGBG_SpWinPrintStr((struct T *)m, 4, 4, n);
    }
    VM_SetWait(a, (int)SCRCMD_MSGWIN_WaitSpWin);
    SCRIPT_WORK_SetCheckFlag(6);
    return 1;
}
