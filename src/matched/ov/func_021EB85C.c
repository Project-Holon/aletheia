/*
 * function: BOX2_SEQ_DrawOffsetName
 * address:  0x021EB85C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_DrawBoxName  0x021EB7E8  thumb  ov170
 *
 * Wrap the 0x19 counter and forward it with p.
 */



extern void BOX2_SEQ_DrawBoxName(char **p, unsigned box, int i);
void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    BOX2_SEQ_DrawBoxName((char **)p, v, 0);
}
