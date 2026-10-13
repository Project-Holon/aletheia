/*
 * function: SCRCMD_MSGWIN_CmdCloseTalkWin
 * address:  0x021B0EDC
 * packet:   pkt_021B0EDC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls SCRCMD_MSGWIN_StartCloseTalkWin() and returns 0x1.
 *
 * symbols:
 *   SCRCMD_MSGWIN_StartCloseTalkWin  0x021B0A88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void SCRCMD_MSGWIN_StartCloseTalkWin();

u32 SCRCMD_MSGWIN_CmdCloseTalkWin(void)
{
    SCRCMD_MSGWIN_StartCloseTalkWin();

    return 0x1;
}

