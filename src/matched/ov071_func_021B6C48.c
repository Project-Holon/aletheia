/*
 * function: func_021B6C48
 * address:  0x021B6C48
 * packet:   pkt_ov071_021B6C48
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B6DB4(p, 2, a).  Address also resident in ov172;
 * region-qualified packet id.
 *
 * symbols:
 *   func_021B6DB4  0x021B6DB4  thumb  ov071
 */

void func_021B6C48(void *p, int a)
{
    void func_021B6DB4(void *, int, int);
    func_021B6DB4(p, 2, a);
}
