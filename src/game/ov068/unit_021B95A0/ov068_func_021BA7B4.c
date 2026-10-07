/*
 * function: func_021BA7B4
 * address:  0x021BA7B4
 * packet:   pkt_ov068_021BA7B4
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_02082BCC(p, 0, 0x58).  Address also resident in ov217;
 * region-qualified packet id.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

void func_021BA7B4(void *p)
{
    void func_02082BCC(void *, int, int);
    func_02082BCC(p, 0, 0x58);
}
