/*
 * function: DWCi_TempNewNodeInfo_Clear
 * address:  0x0217653C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the block 0x554 bytes into the module block.
 *
 * symbols:
 *   DWCi_NodeInfo_Clear  0x0217656C  arm

 */

extern int func_02175F3C(void);
extern void DWCi_NodeInfo_Clear(void *p);

void DWCi_TempNewNodeInfo_Clear(void)
{
    DWCi_NodeInfo_Clear((void *)(func_02175F3C() + 0x554));
}

