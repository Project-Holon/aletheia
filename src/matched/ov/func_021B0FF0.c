/*
 * function: SCRCMD_MSGWIN_WaitPlainWin
 * address:  0x021B0FF0
 * packet:   pkt_021B0FF0
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
 *   FIELD_MSGBG_PlainWinMain  0x021916E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern u32 FIELD_MSGBG_PlainWinMain(u32 *a);

int SCRCMD_MSGWIN_WaitPlainWin(u32 a, u32 b, u32 c, u32 d)
{
if (FIELD_MSGBG_PlainWinMain((u32 *)SCRCMD_WORK_GetMsgWindow(b)) == 1) {
    return 1;
}
return 0;
}

