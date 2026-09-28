/*
 * function: func_02176AA8
 * address:  0x02176AA8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the argument at +0x678 of the module block.
 *
 * symbols:

 */

extern char *func_02175F3C(void);

void func_02176AA8(int v)
{
    *(int *)(func_02175F3C() + 0x678) = v;
}

