/*
 * function: SCRCMD_MSGWIN_OpenInfoSysWin
 * address:  0x021B03E4
 * packet:   pkt_ov021_021B03E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_ClearInfoSysWin  0x02191164  thumb  ov021
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   SCRCMD_WORK_GetWindowState  0x0215A654  thumb  ov010
 *   FIELD_MSGBG_CreateInfoSysWin  0x02190FA0  thumb  ov021
 *   SCRCMD_WORK_SetWindowState  0x0215A660  thumb  ov010
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 */

typedef unsigned int u32;

struct P;
extern int SCRIPT_WORK_CheckFlag(int a0);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern void FIELD_MSGBG_ClearInfoSysWin(struct P *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned char  u8;
struct Fx;
struct Obj2;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 SCRCMD_WORK_GetMsgData(u8 *p);
extern u32 SCRCMD_WORK_GetWindowState(u8 *p);
extern struct Obj2 *FIELD_MSGBG_CreateInfoSysWin(struct Fx *a, u32 b, u32 c);
extern void SCRCMD_WORK_SetWindowState(u8 *p, u32 v);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_SetCheckFlag(int n);

void SCRCMD_MSGWIN_OpenInfoSysWin(u32 a, u32 b)
{
    u32 x, r4, r5;
    u32 *p;

    r5 = 1;
    if (SCRIPT_WORK_CheckFlag(1)) {
        FIELD_MSGBG_ClearInfoSysWin((void *)SCRCMD_WORK_GetMsgWindow(a));
        return;
    }
    p = (u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)a));
    x = SCRCMD_WORK_GetMsgData((u8 *)a);
    r4 = b;
    if (b == 1) {
    } else if (b == 2) {
        r5 = 0x13;
    } else if (b == 0) {
        switch (SCRCMD_WORK_GetWindowState((u8 *)a)) {
        case 1:
        case 3:
        case 5:
            r4 = r5;
            break;
        case 2:
        case 4:
        case 6:
            r5 = 0x13;
            r4 = 2;
            break;
        case 7:
            r5 = 0x13;
            r4 = 2;
            break;
        default:
            r5 = 0x13;
            r4 = 2;
            break;
        }
    } else {
        r5 = 0x13;
        r4 = 2;
    }
    r5 = (u32)FIELD_MSGBG_CreateInfoSysWin((struct Fx *)(*p), x, r5);
    SCRCMD_WORK_SetWindowState((u8 *)a, r4);
    SCRCMD_WORK_SetMsgWindow((u8 *)a, r5);
    SCRIPT_WORK_SetCheckFlag(1);
}
