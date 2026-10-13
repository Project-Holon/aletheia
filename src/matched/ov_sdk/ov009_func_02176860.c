/*
 * function: DWCi_GetTopologyType
 * address:  0x02176860
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x7b0 of the block func_02175F3C returns.
 *
 * symbols:

 */

extern int func_02175F3C(void);

int DWCi_GetTopologyType(void)
{
    return *(int *)(func_02175F3C() + 0x7b0);
}

