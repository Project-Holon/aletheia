/*
 * function: func_021BD38C
 * address:  0x021BD38C
 * packet:   pkt_021BD38C
 * region:   ov217
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

typedef unsigned short u16;

extern void *func_02025538(unsigned int a0, void *a1);

void func_021BD38C(char *p)
{
    int i = 0x47;
    *(int *)(p + (i << 2) + 0x10) =
        func_02025538(*(u16 *)(p + 8), *(void **)(p + (i << 2)));
}
