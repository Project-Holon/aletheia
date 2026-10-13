/*
 * function: SCRCMD_MSGWIN_WaitSpWin
 * address:  0x021B1424
 * packet:   pkt_021B1424
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_SpWinWaitKey  0x021926D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int SCRCMD_WORK_GetMsgWindow(int a0);
struct U;
extern int FIELD_MSGBG_SpWinWaitKey(struct U *u);

int SCRCMD_MSGWIN_WaitSpWin(int a, int b, int c, int d)
{
if (FIELD_MSGBG_SpWinWaitKey((struct U *)SCRCMD_WORK_GetMsgWindow(b)) == 1) {
    return 1;
}
return 0;
}

