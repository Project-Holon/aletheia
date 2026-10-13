/*
 * function: SCRCMD_MSGWIN_CmdPlainWinMsg
 * address: 0x021B10D0
 * packet: pkt_ov021_021B10D0
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/scrcmd_screeneffects.c and filed here.
 *
 * symbols:
 *   SCRCMD_MSGWIN_OpenPlainWinMsg 0x021B1008 thumb
 */

int SCRCMD_MSGWIN_OpenPlainWinMsg(void *a, int b, int c);
int SCRCMD_MSGWIN_CmdPlainWinMsg(void *a, int b);

int SCRCMD_MSGWIN_CmdPlainWinMsg(void *a, int b) { return SCRCMD_MSGWIN_OpenPlainWinMsg(a, b, 0); }
