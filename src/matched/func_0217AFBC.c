/*
 * function: func_0217AFBC
 * address:  0x0217AFBC
 * packet:   pkt_0217AFBC
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E867C  0x021E867C  thumb  ov177
 *   func_0201C4E4  0x0201C4E4  thumb
 */

extern void func_021E867C(int);
extern void func_0201C4E4(int);

void func_0217AFBC(int *p)
{
    func_021E867C(*(int *)((char *)p + 8));
    func_0201C4E4(*(int *)((char *)p + 0x14));
}
