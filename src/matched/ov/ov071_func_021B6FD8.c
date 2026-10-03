/*
 * function: func_021B6FD8
 * address:  0x021B6FD8
 * packet:   pkt_ov071_021B6FD8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_0204B3B4.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */

struct Obj;
void func_021B6FD8(void *p)
{
    void func_0204B3B4(struct Obj *p);
    func_0204B3B4(p);
}
