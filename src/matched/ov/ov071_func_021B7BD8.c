/*
 * function: func_021B7BD8
 * address:  0x021B7BD8
 * packet:   pkt_ov071_021B7BD8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B7070(word at 0x4, a + 0x24).
 *
 * symbols:
 *   func_021B7070  0x021B7070  thumb  ov071
 */

void func_021B7BD8(void *p, int a)
{
    void func_021B7070(int *p, int *out);
    func_021B7070(*(void **)((char *)p + 4), (int *)(a + 0x24));
}
