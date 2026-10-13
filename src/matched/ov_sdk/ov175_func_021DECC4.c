/*
 * function: sakeiGetSpecificRecordsFreeData
 * address:  0x021DECC4
 * packet:   pkt_021DECC4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiFreeOutputRecords  0x021DE8AC  arm
 *
 * Forward the +0x08 block's fifth word and the +0x0c cursor's two head words
 * to sakeiFreeOutputRecords; a null cursor is a no-op.
 */

extern void sakeiFreeOutputRecords(int, int, int);

void sakeiGetSpecificRecordsFreeData(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    sakeiFreeOutputRecords(r[4], q[0], q[1]);
}

