/*
 * function: SCRCMD_MSGWIN_CloseBgWin
 * address:  0x021B1268
 * packet:   pkt_ov021_021B1268
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CloseBgWin  0x021B1268  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_DeleteBgWin  0x02191B14  thumb  ov021
 *   SCRIPT_WORK_GetMsgData  0x02158F84  thumb  ov010
 *   SCRIPT_WORK_SetMsgData  0x02158F80  thumb  ov010
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_CheckFlag(int);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void FIELD_MSGBG_DeleteBgWin(u32 *a);
extern u32 SCRIPT_WORK_GetMsgData(u8 *p);
extern void SCRIPT_WORK_SetMsgData(u8 *p, u32 v);
extern u32 GF_FONT_Delete(void *ptr);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_ResetCheckFlag(int);

void SCRCMD_MSGWIN_CloseBgWin(void *p)
{
    void *q = SCRCMD_WORK_GetScriptWork(p);
    void *r;
    if (SCRIPT_WORK_CheckFlag(4) != 0) {
        FIELD_MSGBG_DeleteBgWin((void *)SCRCMD_WORK_GetMsgWindow((int)p));
        r = (void *)SCRIPT_WORK_GetMsgData(q);
        SCRIPT_WORK_SetMsgData(q, 0);
        if (r != 0) {
            GF_FONT_Delete(r);
        }
        SCRCMD_WORK_SetMsgWindow(p, 0);
        SCRIPT_WORK_ResetCheckFlag(4);
    }
}
