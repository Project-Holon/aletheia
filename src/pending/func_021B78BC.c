/*
 * function: func_021B78BC
 * address:  0x021B78BC
 * packet:   pkt_021B78BC
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021B7C04  0x021B7C04  thumb  ov105
 *
 * blocker: Target 0x021B7C04 is unlabelled in ov105; sole witness is this function's own pool word. Byte-correct.
 */

void func_021B7C04(int);

void func_021B78BC(int x)
{
    func_021B7C04(x + 4);
}
