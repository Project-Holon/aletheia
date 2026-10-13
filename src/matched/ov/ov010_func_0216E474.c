/*
 * function: FLDMMDL_GetMovedPosSaveSize
 * address:  0x0216E474
 * packet:   pkt_ov010_0216E474
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Save-table size callback: returns 0x168, the size of the block that
 * FLDMMDL_InitMovedPosSave fills.  Pointer word 0x0216E475 at arm9 0x0209DC90.
 */

typedef unsigned int u32;

u32 FLDMMDL_GetMovedPosSaveSize(void)
{
    return 0x168;
}
