/*
 * function: BOX2_SEQ_PrintMessageC
 * address:  0x021EBB28
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_PrintMessageMsg  0x021EBA84  thumb  ov170
 *
 * Forward with index 43.
 */

extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);

void BOX2_SEQ_PrintMessageC(char *p, int b)
{
    BOX2_SEQ_PrintMessageMsg((unsigned char *)p, 0x2b, b);
}

