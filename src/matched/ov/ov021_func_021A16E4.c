/*
 * function: func_021A16E4
 * address:  0x021A16E4
 * packet:   pkt_ov021_021A16E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (str r1,[r0,#0x14]; bx lr), filed for the ov026 lane.
 *
 * symbols:
 *   func_021A16E4 0x021A16E4 thumb ov021
 */

void func_021A16E4(unsigned char *p, unsigned int v)
{
    *(unsigned int *)(p + 0x14) = v;
}
