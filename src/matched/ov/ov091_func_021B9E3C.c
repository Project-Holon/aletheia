/*
 * function: POKELIST_EndMessageToExit
 * address:  0x021B9E3C
 * packet:   pkt_ov091_021B9E3C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: sets the state byte at +0xc to 0x13.
 */

void POKELIST_EndMessageToExit(char *p)
{
    p[0xc] = 0x13;
}
