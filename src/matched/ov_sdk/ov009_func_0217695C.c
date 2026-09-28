/*
 * function: func_0217695C
 * address:  0x0217695C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set when the word at +0x7b0 of the module block is two.
 *
 * symbols:

 */

extern char *func_02175F3C(void);

int func_0217695C(void)
{
    return *(int *)(func_02175F3C() + 0x7b0) == 2;
}

