/*
 * function: DoGet
 * address:  0x02193CB0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pointer at +0xc when the word at +4 is 2, otherwise +0xc itself; null in, null out.
 */

char *DoGet(char *p)
{
    if (p == 0)
        return 0;
    if (*(int *)(p + 4) == 2)
        return *(char **)(p + 0xc);
    return p + 0xc;
}
