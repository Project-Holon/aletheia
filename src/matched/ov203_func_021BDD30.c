/*
 * function: func_021BDD30
 * address:  0x021BDD30
 * packet:   pkt_021BDD30
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021BDD30(char *a)
{
    void **p = *(void ***)(a + 0xc);

    if (p)
        ((void (*)(void *))p[1])(a);
}
