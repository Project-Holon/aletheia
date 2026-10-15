/*
 * function: BOX2_SEQ_DrawFrameColor
 * address:  0x021EB6D8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_DrawWindowFrame  0x021EB378  thumb  ov170
 *
 * Range call with a fixed span and the caller's fourth value.
 */



extern void BOX2_SEQ_DrawWindowFrame(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon);
void BOX2_SEQ_DrawFrameColor(int a, int b, int c, int d)
{
    BOX2_SEQ_DrawWindowFrame((char *)a, b, c, 0, 0x3d80, d);
}
