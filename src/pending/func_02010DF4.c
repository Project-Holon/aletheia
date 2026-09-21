/*
 * function: func_02010DF4
 * address:  0x02010DF4
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (14 concrete bytes out)
 *
 * symbols:
 *   func_02010F50  0x02010F50  thumb
 */

extern void func_02010F50(int);

void func_02010DF4(void)
{
    int i = 0;
    if (i < 13) {
        do {
            func_02010F50(i);
            i++;
        } while (i < 13);
    }
}
