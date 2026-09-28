/*
 * function: func_0217D388
 * address:  0x0217D388
 * packet:   pkt_0217D388
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200B078  0x0200B078  thumb
 */

extern int func_0200B078(int, int);

void func_0217D388(int *p, int *q)
{
    *(int *)((char *)p + 0x40) = func_0200B078(*(int *)((char *)q + 0x38), 2);
}
