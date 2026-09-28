/*
 * function: func_02175FC8
 * address:  0x02175FC8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cleared when the word at +0x7b0 of the module block is one.
 *
 * symbols:

 */

extern char *func_02175F3C(void);

int func_02175FC8(void)
{
    return *(int *)(func_02175F3C() + 0x7b0) != 1;
}

