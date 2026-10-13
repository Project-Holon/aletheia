/*
 * function: TOWNMAP_CursorSetSnapToTown
 * address:  0x021BA48C
 * packet:   pkt_021BA48C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void TOWNMAP_CursorSetSnapToTown(int *p, int x)
{
    p[4] = x;
}
