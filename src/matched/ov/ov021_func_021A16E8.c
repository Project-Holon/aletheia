/*
 * function: func_021A16E8
 * address:  0x021A16E8
 * packet:   pkt_ov021_021A16E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (str r1,[r0,#0x18]; bx lr), filed for the ov026 lane.
 *
 * symbols:
 *   func_021A16E8 0x021A16E8 thumb ov021
 */

void func_021A16E8(unsigned char *p, unsigned int v)
{
    *(unsigned int *)(p + 0x18) = v;
}
