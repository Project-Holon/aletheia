/*
 * function: func_021B96CC
 * address:  0x021B96CC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Plain first-word field getter; a leaf that saves nothing, so the overlay
 * listing carries it only because something branches to it.
 */

int func_021B96CC(int *p)
{
    return *p;
}
