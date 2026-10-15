/*
 * function: BOX2_SEQ_PrintMessage
 * address:  0x021EBB1C
 * packet:   pkt_ov170_021EBB1C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb
 *
 * Prints message 0x16 into window i.
 */

extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);

void BOX2_SEQ_PrintMessage(unsigned char *p, int i)
{
    BOX2_SEQ_PrintMessageMsg(p, 0x16, i);
}
