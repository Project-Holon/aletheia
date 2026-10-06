/*
 * unit:     yes
 * function: func_021BA024, func_021BA030
 * address:  0x021BA024
 * packet:   pkt_ov068_021BA024
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two identical wrappers around func_02082BCC(p, 0, 0x20).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

void func_021BA024(void *p, int heap)
{
    void func_02082BCC(void *, int, int);
    func_02082BCC(p, 0, 0x20);
}

void func_021BA030(void *p)
{
    void func_02082BCC(void *, int, int);
    func_02082BCC(p, 0, 0x20);
}
