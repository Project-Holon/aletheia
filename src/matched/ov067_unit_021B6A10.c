/*
 * unit:     yes
 * function: func_021B6A10, func_021B6A1C
 * address:  0x021B6A10
 * packet:   pkt_ov067_021B6A10
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two ARM9 tail calls on the pointer loaded from offset 0.
 *
 * symbols:
 *   func_0204B800  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 */

void func_021B6A10(void *p)
{
    void func_0204B800(void *);
    func_0204B800(*(void **)p);
}

void func_021B6A1C(void *p)
{
    void func_0204B84C(void *);
    func_0204B84C(*(void **)p);
}
