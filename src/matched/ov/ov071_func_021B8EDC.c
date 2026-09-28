/*
 * function: func_021B8EDC
 * address:  0x021B8EDC
 * packet:   pkt_ov071_021B8EDC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B70C4((char *)p + 0x48).
 *
 * symbols:
 *   func_021B70C4  0x021B70C4  thumb  ov071
 */

void func_021B8EDC(void *p)
{
    void func_021B70C4(void *);
    func_021B70C4((char *)p + 0x48);
}
