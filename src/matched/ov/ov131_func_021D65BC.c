/*
 * function: P_STATUS_ProcMain
 * address:  0x021D65BC
 * packet:   pkt_021D65BC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   P_STATUS_MainSeq  0x021D44C8  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int P_STATUS_MainSeq(char *p);

int P_STATUS_ProcMain(int a, int b, int c, int d)
{
    int r = P_STATUS_MainSeq((char *)d);

    if (r == 1)
        return 1;
    if (r == 2)
        return 1;
    return 0;
}
