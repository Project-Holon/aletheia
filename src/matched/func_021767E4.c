/*
 * function: func_021767E4
 * address:  0x021767E4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x7c4 of the block func_02175F3C returns.
 *
 * symbols:

 */

extern char *func_02175F3C(void);

int func_021767E4(void)
{
    return *(int *)(func_02175F3C() + 0x7c4);
}

