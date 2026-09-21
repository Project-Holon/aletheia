/*
 * function: func_020637BC
 * address:  0x020637BC
 * packet:   pkt_020637BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (12 concrete bytes out)
 */

int func_020637BC(const unsigned int *arr, int idx)
{
    return arr[idx] != 0xFFFFFFFFU;
}
