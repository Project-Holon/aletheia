/*
 * function: DPW_BT_GetAsyncResult
 * address:  0x021C940C
 * packet:   pkt_ov114_021C940C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM leaf, labelled in wave D8 (called from ov116 0x021D70EC).  Extent
 * 0x021C940C..0x021C941C (16 bytes): ldr/ldr/bx plus one pool word naming
 * gDpwBtWork.  Same body as DPW_TR_GetAsyncResult over a different datum.
 *
 * symbols:
 *   gDpwBtWork  0x021D4084  data  a4
 */

extern unsigned int gDpwBtWork[];

int DPW_BT_GetAsyncResult(void)
{
    return gDpwBtWork[1];
}
