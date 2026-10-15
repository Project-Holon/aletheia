/*
 * function: BOX2_SEQ_PrintMenuRow
 * address:  0x021EBD1C
 * packet:   pkt_ov170_021EBD1C
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
 * Maps a menu row to its message index, then tail-calls the printer.
 */

extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);

void BOX2_SEQ_PrintMenuRow(char *p, int row, int b)
{
    switch (row) {
    case 2:
        row = 0x2d;
        break;
    case 3:
        row = 0x2e;
        break;
    case 4:
        row = 0x31;
        break;
    case 6:
        row = 0x33;
        break;
    }
    BOX2_SEQ_PrintMessageMsg((unsigned char *)p, row, b);
}
