/*
 * function: func_021F621C
 * address:  0x021F621C
 * packet:   pkt_021F621C
 * region:   ov112
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021F621C(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    *(unsigned int *)((char *)p + 8) = (v & ~1u) | 1u;
}
