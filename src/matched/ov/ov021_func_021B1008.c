/*
 * function: SCRCMD_MSGWIN_OpenPlainWinMsg
 * address:  0x021B1008
 * packet:   pkt_ov021_021B1008
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_OpenPlainWinMsg  0x021B1008  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_MSGWIN_ExpandMessage  0x021B162C  thumb
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_ClearPlainWin  0x021915EC  thumb  ov021
 *   FIELD_MSGBG_CreatePlainWin  0x02191558  thumb  ov021
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   FIELD_MSGBG_PlainWinPrintStream  0x021916A8  thumb  ov021
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitPlainWin  0x021B0FF0  thumb
 */
#include "../include/Obj12833.h"

typedef unsigned char u8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct R;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u32 SCRCMD_MSGWIN_ExpandMessage(u32 a, u32 b, u32 c);
extern int SCRIPT_WORK_CheckFlag(int);
extern int SCRCMD_WORK_GetMsgWindow(int);
extern void FIELD_MSGBG_ClearPlainWin(struct R *r);
extern int FIELD_MSGBG_CreatePlainWin(int, int, int, int, int, int, int);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void FIELD_MSGBG_PlainWinPrintStream(struct R *r, u32 b, u16 c, u32 d);
extern void SCRIPT_WORK_SetCheckFlag(int);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitPlainWin(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_MSGWIN_OpenPlainWinMsg(void *a, int b, int c)
{
    void *o;
    int n, r, t, m;
    int *q;
    u8 *p;
    o = SCRCMD_WORK_GetScriptWork((void *)b);
    q = (int *)SCRIPT_WORK_ResetFieldParam((int)o);
    t = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    p = *(u8 * *)&((struct Obj12833 *)a)->f14;
    n = *p;
    *(u8 * *)&((struct Obj12833 *)a)->f14 = p + 1;
    r = 1;
    m = SCRCMD_MSGWIN_ExpandMessage(b, (u32)o, t);
    if (n != 1) {
        r = 0x13;
    }
    if (SCRIPT_WORK_CheckFlag(3) != 0) {
        r = SCRCMD_WORK_GetMsgWindow(b);
        FIELD_MSGBG_ClearPlainWin((struct R *)r);
    } else {
        r = FIELD_MSGBG_CreatePlainWin(*q, 0, c, 1, r, 0x1e, 4);
        SCRCMD_WORK_SetMsgWindow((u8 *)b, r);
    }
    FIELD_MSGBG_PlainWinPrintStream((struct R *)r, 8, 0, m);
    SCRIPT_WORK_SetCheckFlag(3);
    VM_SetWait(a, (int)SCRCMD_MSGWIN_WaitPlainWin);
    return 1;
}
