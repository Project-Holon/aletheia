/*
 * function: func_021B82FC
 * address:  0x021B82FC
 * packet:   pkt_ov071_021B82FC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B70C4((char *)p + 0x34).  Address also resident in
 * ov021; region-qualified packet id.
 *
 * symbols:
 *   func_021B70C4  0x021B70C4  thumb  ov071
 */

void func_021B82FC(void *p)
{
    void func_021B70C4(void *);
    func_021B70C4((char *)p + 0x34);
}
