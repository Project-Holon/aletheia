/*
 * function: sakeiGetMyRecordsValidateInput
 * address:  0x021DEB1C
 * packet:   pkt_021DEB1C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiValidateRequestFieldNames  0x021DE14C  arm
 *
 * Pre-flight check of the +0x08 block: a missing head or an empty count is
 * rejected with 4, a non-positive count with 6, a missing name table with 5;
 * otherwise the table is checked word by word by sakeiValidateRequestFieldNames.
 */

extern int sakeiValidateRequestFieldNames(char **names, int n);

int sakeiGetMyRecordsValidateInput(char *p)
{
    int *q = *(int **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[2] <= 0)
        return 6;
    if (q[1] == 0)
        return 5;
    return sakeiValidateRequestFieldNames((char **)q[1], q[2]);
}

