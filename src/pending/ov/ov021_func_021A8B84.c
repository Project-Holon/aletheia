/*
 * function: func_021A8B84
 * address:  0x021A8B84
 * packet:   pkt_ov021_021A8B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   d_021D8D24  0x021D8D24  data  a4
 */

extern int d_021D8D24[][7];

/*
 * 2026-10-01: DIFF only in the preheader schedule: the original tests row[0]
 * with ldr [base, off] and forms the row pointer (adds r3, r3, r4) after the
 * guard; this source forms it before. for/while/do-guard variants tried.
 */
int func_021A8B84(int idx)
{
    int i;
    int n;
    n = 0;
    for (i = 0; d_021D8D24[idx][i] != 0; i++) {
        if (d_021D8D24[idx][i] != 7) {
            n++;
        }
    }
    return n;
}
