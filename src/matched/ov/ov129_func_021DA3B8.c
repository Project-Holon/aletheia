/*
 * function: func_021DA3B8
 * address:  0x021DA3B8
 * packet:   pkt_021DA3B8
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02025538  0x02025538  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void *func_02025538(unsigned int a0, void *a1);

void func_021DA3B8(char *p)
{
    void *x = func_02025538(0x32, *(void **)(p + 0x25c));

    *(void **)(p + 0x300) = x;
}
