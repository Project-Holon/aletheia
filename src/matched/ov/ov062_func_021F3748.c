/*
 * function: func_021F3748
 * address:  0x021F3748
 * packet:   pkt_ov062_021F3748
 * region:   ov062
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

void func_021F3748(void *p)
{
    int func_02188D2C(int *p);
    void func_021BE580(void *p);
    func_021BE580((void *)func_02188D2C(p));
}
