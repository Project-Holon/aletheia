/*
 * function: func_021C0CC8
 * address:  0x021C0CC8
 * packet:   pkt_ov217_021C0CC8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020215A0  0x020215A0  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void func_020215A0(int obj, int n);

void func_021C0CC8(int *p)
{
    int obj;
    obj = p[10];
    func_020215A0(obj, 0);
    func_020215A0(obj, 2);
    func_020215A0(obj, 1);
    func_020215A0(obj, 3);
}
