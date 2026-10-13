/*
 * function: DWCi_IsShutdownMatch
 * address:  0x0216F370
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set when the module block is absent.
 *
 * symbols:

 */

extern int func_02175F3C(void);

int DWCi_IsShutdownMatch(void)
{
    return func_02175F3C() == 0;
}

