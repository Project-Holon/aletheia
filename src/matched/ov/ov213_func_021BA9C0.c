/*
 * function: func_021BA9C0
 * address:  0x021BA9C0
 * packet:   pkt_021BA9C0
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA9AC 0x021BA9AC thumb
 */

extern void func_021BA9AC(void *);

void func_021BA9C0(void *a)
{
    if (*(unsigned char *)((char *)a + 0xf))
        func_021BA9AC(a);
}