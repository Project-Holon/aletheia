/*
 * function: SCRCMD_MSGWIN_CloseInfoSysWin
 * address:  0x021B0480
 * packet:   pkt_ov021_021B0480
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
 *   FIELD_MSGBG_DeleteInfoSysWin  0x02191008  thumb  ov021
 *   func_0215A630  0x0215A630  thumb  ov010
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int SCRIPT_WORK_CheckFlag(int a0);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern int FIELD_MSGBG_DeleteInfoSysWin(u32 a);
extern u32 func_0215A630(u8 *p);
extern void TIME_ICON_Delete(u8 *p);
extern void func_0215A624(u8 *p, u32 v);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

void SCRCMD_MSGWIN_CloseInfoSysWin(u32 a)
{
    u32 t;

    if (SCRIPT_WORK_CheckFlag(1)) {
        FIELD_MSGBG_DeleteInfoSysWin(SCRCMD_WORK_GetMsgWindow(a));
        t = func_0215A630((u8 *)a);
        if (t) {
            TIME_ICON_Delete((void *)t);
            func_0215A624((u8 *)a, 0);
        }
        SCRCMD_WORK_SetMsgWindow((u8 *)a, 0);
        SCRIPT_WORK_ResetCheckFlag(1);
    }
}
