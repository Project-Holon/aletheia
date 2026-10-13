/*
 * function: SCRCMD_MSGWIN_WaitTalkWinClose
 * address:  0x021B0A60
 * packet:   pkt_021B0A60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * SCRCMD_WORK_SetMsgWindow (0x0215A614) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void SCRIPT_WORK_ResetCheckFlag(int n);
extern u32 SCRCMD_WORK_SetMsgWindow(u32, u32);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern u32 FIELD_MSGBG_WaitTalkWinClose(u32);

int SCRCMD_MSGWIN_WaitTalkWinClose(u32 a, u32 b, u32 c, u32 d)
{
if (FIELD_MSGBG_WaitTalkWinClose(SCRCMD_WORK_GetMsgWindow(b)) == 1) {
    SCRCMD_WORK_SetMsgWindow(b, 0);
    SCRIPT_WORK_ResetCheckFlag(2);
    return 1;
}
return 0;
}

