/*
 * function: func_021A16DC
 * address:  0x021A16DC
 * packet:   pkt_ov021_021A16DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (str r1,[r0,#0xc]; bx lr), filed for the ov026 lane.
 *
 * symbols:
 *   func_021A16DC 0x021A16DC thumb ov021
 */

void func_021A16DC(unsigned char *p, unsigned int v)
{
    *(unsigned int *)(p + 0xC) = v;
}
