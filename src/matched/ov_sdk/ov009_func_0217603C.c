/*
 * function: DWCi_NodeInfoList_GetCount
 * address:  0x0217603C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x50 of the block func_02175F3C returns.
 *
 * symbols:

 */

extern int func_02175F3C(void);

int DWCi_NodeInfoList_GetCount(void)
{
    return *(int *)(func_02175F3C() + 0x50);
}

