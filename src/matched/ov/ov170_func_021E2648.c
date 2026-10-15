/*
 * function: BOX2_SEQ_StateCloseBox
 * address:  0x021E2648
 * packet:   pkt_ov170_021E2648
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_StatePlayCry 0x021E9284 thumb
 *
 * State handler (table entry at 0x021EFABC) that forwards to
 * BOX2_SEQ_StatePlayCry.
 */

extern int BOX2_SEQ_StatePlayCry(char *p);

int BOX2_SEQ_StateCloseBox(unsigned char *p)
{
    return BOX2_SEQ_StatePlayCry((char *)p);
}
