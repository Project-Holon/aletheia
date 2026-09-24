/*
 * function: func_02175EFC
 * address:  0x02175EFC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set while the mode word is one of three values.
 *
 * symbols:

 */

extern char *func_02175F3C(void);

int func_02175EFC(void)
{
    unsigned int v = *(unsigned int *)(func_02175F3C() + 0x61c) - 9;

    return v <= 2;
}

