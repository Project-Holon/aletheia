/*
 * function: DWCi_IsServerChanging
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

extern int func_02175F3C(void);

int DWCi_IsServerChanging(void)
{
    unsigned int v = *(unsigned int *)(func_02175F3C() + 0x61c) - 9;

    return v <= 2;
}

