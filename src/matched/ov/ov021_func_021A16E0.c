/*
 * function: func_021A16E0
 * address:  0x021A16E0
 * packet:   pkt_ov021_021A16E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (str r1,[r0,#0x10]; bx lr), filed for the ov026 lane.
 *
 * symbols:
 *   func_021A16E0 0x021A16E0 thumb ov021
 */

void func_021A16E0(unsigned char *p, unsigned int v)
{
    *(unsigned int *)(p + 0x10) = v;
}
