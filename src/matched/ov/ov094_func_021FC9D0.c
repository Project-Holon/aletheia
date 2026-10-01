/*
 * function: func_021FC9D0
 * address:  0x021FC9D0
 * packet:   pkt_ov094_021FC9D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wait callback: decrements the countdown at 0x1e4, done when it reaches zero.
 */
int func_021FC9D0(void *a, char *s)
{
    return --*(int *)(s + 0x1e4) <= 0;
}
