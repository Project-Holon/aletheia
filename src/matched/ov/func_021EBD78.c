/*
 * function: BOX2_SEQ_PrintYesNo
 * address:  0x021EBD78
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_PrintMessageMsg  0x021EBA84  thumb  ov170
 *
 * Index 0x35 when the flag is clear, 0x36 when set.
 */


extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);
void BOX2_SEQ_PrintYesNo(char *p, int b)
{
    if (b == 0)
        BOX2_SEQ_PrintMessageMsg((unsigned char *)p, 0x35, 0x1b);
    else
        BOX2_SEQ_PrintMessageMsg((unsigned char *)p, 0x36, 0x1b);
}
