/*
 * function: func_0219327C
 * address:  0x0219327C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the byte one before the sum of the block and the count.
 *
 * symbols:

 */

extern void func_02094860(char *p, int b);

void func_0219327C(char *p, int b, int n)
{
    func_02094860(p, b);
    *(char *)(p + n - 1) = 0;
}

