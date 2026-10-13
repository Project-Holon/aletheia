/*
 * function: DWCi_IsFullMesh
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

extern int func_02175F3C(void);

int DWCi_IsFullMesh(void)
{
    return *(int *)(func_02175F3C() + 0x7b0) == 2;
}

