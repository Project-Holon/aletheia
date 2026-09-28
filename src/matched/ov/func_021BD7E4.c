/*
 * function: func_021BD7E4
 * address:  0x021BD7E4
 * packet:   pkt_021BD7E4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Returns 1 when the ARM9 call at 0x0204B98C on the word at [p] comes back zero.
 */

extern int func_0204B98C(int);

int func_021BD7E4(int *p)
{
    return func_0204B98C(*p) == 0;
}
