/*
 * function: DPW_TR_GetAsyncResult
 * address:  0x021C86A8
 * packet:   pkt_ov114_021C86A8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in a .word run.  Extent 0x021C86A8..0x021C86B8
 * (16 bytes): ldr/ldr/bx plus one pool word naming gDpwTrWork.
 *
 * symbols:
 *   gDpwTrWork  0x021D3D2C  data  a4
 */

extern unsigned int gDpwTrWork[];

int DPW_TR_GetAsyncResult(void)
{
    return gDpwTrWork[1];
}
