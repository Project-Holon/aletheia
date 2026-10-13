/*
 * function: DWCi_TempNewNodeInfo_IsValid
 * address:  0x02176554
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Prepares the block 0x554 bytes into the module block.
 *
 * symbols:
 *   DWCi_NodeInfo_IsValid  0x02176580  arm

 */

extern int func_02175F3C(void);
extern int DWCi_NodeInfo_IsValid(const int *p);

int DWCi_TempNewNodeInfo_IsValid(void)
{
    return DWCi_NodeInfo_IsValid((const int *)(func_02175F3C() + 0x554));
}

