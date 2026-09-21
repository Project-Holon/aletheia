/*
 * function: func_02072EA8
 * address:  0x02072EA8
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (15 concrete bytes out)
 */

void func_02072EA8(int **ptr)
{
    if (*ptr == 0) {
        return;
    }
    **ptr = 0;
    *ptr = 0;
}
