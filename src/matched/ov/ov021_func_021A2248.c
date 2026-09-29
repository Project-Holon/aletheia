/*
 * function: func_021A2248
 * address:  0x021A2248
 * packet:   pkt_ov021_021A2248
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for lane S30 (callee of ov027 functions).
 *
 * symbols:
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A2B8C 0x021A2B8C thumb ov021
 */

extern int func_021A2B8C(unsigned char *o, int arg);

int func_021A2248(unsigned char *o, int arg)
{
    return func_021A2B8C(o + 0x4C, arg);
}
