/*
 * function: SCRCMD_MSGWIN_WaitKeyWithCursor
 * address:  0x021B1550
 * packet:   pkt_ov021_021B1550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   FIELD_MSGBG_SysWinDrawCursor  0x02191134  thumb  ov021
 *   FIELD_MSGBG_PlainWinDrawCursor  0x02191794  thumb  ov021
 *   FIELD_MSGBG_TalkWinDrawCursor  0x021914CC  thumb  ov021
 */

typedef unsigned int u32;

u32 KEY_GetTrg(void);
int SCRCMD_WORK_GetMsgWindow(int a);
void GFL_USE_PlaySeDefaultVolume(u32 a);
int SCRIPT_WORK_CheckFlag(int a);
struct P;
struct R;
struct S;
void FIELD_MSGBG_SysWinDrawCursor(struct P *p);
void FIELD_MSGBG_PlainWinDrawCursor(struct R *r);
void FIELD_MSGBG_TalkWinDrawCursor(struct S *s);

int SCRCMD_MSGWIN_WaitKeyWithCursor(int a, int b)
{
    int r5;
    int r4;

    r5 = KEY_GetTrg();
    r4 = SCRCMD_WORK_GetMsgWindow(b);
    if (r5 & 3) {
        GFL_USE_PlaySeDefaultVolume(0x547);
        return 1;
    }
    if (SCRIPT_WORK_CheckFlag(1)) {
        FIELD_MSGBG_SysWinDrawCursor((struct P *)r4);
    } else if (SCRIPT_WORK_CheckFlag(3)) {
        FIELD_MSGBG_PlainWinDrawCursor((struct R *)r4);
    } else if (SCRIPT_WORK_CheckFlag(2)) {
        FIELD_MSGBG_TalkWinDrawCursor((struct S *)r4);
    } else {
        return 1;
    }
    return 0;
}
