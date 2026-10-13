/*
 * function: sakeiUpdateRecordValidateInput
 * address:  0x021DE038
 * packet:   pkt_021DE038
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiValidateRequestFields  0x021DDB38  arm
 *
 * Pre-flight check of the +0x08 block: a missing head or an empty count is
 * rejected with 4, a non-positive count with 6, a missing name table with 5;
 * otherwise the table is checked word by word by sakeiValidateRequestFields.
 */

extern int sakeiValidateRequestFields(char **names, int n);

int sakeiUpdateRecordValidateInput(char *p)
{
    int *q = *(int **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[3] <= 0)
        return 6;
    if (q[2] == 0)
        return 5;
    return sakeiValidateRequestFields((char **)q[2], q[3]);
}
