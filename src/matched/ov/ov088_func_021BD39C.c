/*
 * function: SAVE_CONTROL_INTR_NoOp
 * address:  0x021BD39C
 * packet:   pkt_ov088_021BD39C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in a .word run at ov088:021BD39C: `bx lr` (2 bytes),
 * an empty function called as a no-op by INTRO_CMD_CmdSaveNoOp.  ov088 is the only
 * overlay in the window not overlapping the caller's ov204.
 */

void SAVE_CONTROL_INTR_NoOp(int a0)
{
}
