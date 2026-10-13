/*
 * function: SCRCMD_WORK_SetWindowKind
 * address:  0x0215A678
 * packet:   pkt_ov010_0215A678
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Writes the byte at +0x105 of the object at +0x20 (setter twin of
 * SCRCMD_WORK_GetWindowKind). Unlabelled leaf, blocker of ov021 SCRCMD_MSGWIN_OpenBalloonWinMsg.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;

void SCRCMD_WORK_SetWindowKind(u8 *p, u8 v)
{
    (*(u8 **)(p + 0x20))[0x105] = v;
}
