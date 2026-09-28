/*
 * function: func_021B9A44
 * address:  0x021B9A44
 * packet:   pkt_ov069_021B9A44
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word loaded from offset 0x4.
 *
 * symbols:
 *   func_0202CA0C  0x0202CA0C  thumb
 */

void func_021B9A44(void *p)
{
    void func_0202CA0C(void *);
    func_0202CA0C(*(void **)((char *)p + 4));
}
