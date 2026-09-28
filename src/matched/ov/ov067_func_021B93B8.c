/*
 * function: func_021B93B8
 * address:  0x021B93B8
 * packet:   pkt_021B93B8
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Unlabelled leaf in ov067, printed as a .word run; signed halfword getter.
 * Blocker target of ov210's func_021BF728 (pkt_021BF728), reached across the
 * ov210/ov067 overlay pair.
 */

int func_021B93B8(char *p)
{
    return *(signed short *)(p + 0x62);
}
