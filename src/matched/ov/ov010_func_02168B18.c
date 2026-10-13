/*
 * function: FLD_BTL_INST_TOOL_SetDoneFlag
 * address:  0x02168B18
 * packet:   pkt_ov010_02168B18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf callback (movs r1,#1; str r1,[r0]; bx lr); filed as the
 * sole blocker of FLD_BTL_INST_TOOL_CommResetEventMain (its pool word).
 *
 * symbols:
 */

void FLD_BTL_INST_TOOL_SetDoneFlag(int *p)
{
    *p = 1;
}
