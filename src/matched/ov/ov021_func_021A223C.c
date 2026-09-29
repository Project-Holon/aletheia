/*
 * function: func_021A223C
 * address:  0x021A223C
 * packet:   pkt_ov021_021A223C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A2AB8 0x021A2AB8 thumb ov021
 */

extern int func_021A2AB8(unsigned char *o, int arg);

int func_021A223C(unsigned char *o, int arg)
{
    return func_021A2AB8(o + 0x4C, arg);
}
