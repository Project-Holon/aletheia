/*
 * function: func_021B70B8
 * address:  0x021B70B8
 * packet:   pkt_ov071_021B70B8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * func_0204B3B4 with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */

void func_021B70B8(void **p)
{
    void func_0204B3B4(void *);
    func_0204B3B4(*p);
}
