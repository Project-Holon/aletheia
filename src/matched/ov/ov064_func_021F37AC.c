/*
 * function: func_021F37AC
 * address:  0x021F37AC
 * packet:   pkt_021F37AC
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
*/

void func_021F37AC(void *p)
{
    void *func_02188D2C(void *p);
    void func_021BE580(void *p);
    func_021BE580(func_02188D2C(p));
}
