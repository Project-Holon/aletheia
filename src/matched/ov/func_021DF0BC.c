/*
 * function: BOX2_MAIN_ClearCursorBox
 * address:  0x021DF0BC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_MAIN_ResetBoxView  0x021DF040  thumb  ov170
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb  ov170
 *
 * Reset, clear the state, mark the 0x16 field.
 */



extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
void BOX2_MAIN_ClearCursorBox(unsigned char *p)
{
    BOX2_MAIN_ResetBoxView((char *)p);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    p[0x16] = 0xff;
}
