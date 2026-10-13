/*
 * function: DWC_RAP_EvalCallbackAccept
 * address:  0x02155D7C
 * packet:   pkt_ov009_02155D7C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a callback by DWC_RAP_StartMatchWithKey / DWC_RAP_StartMatchWithFilter.
 */

int DWC_RAP_EvalCallbackAccept(void)
{
    return 1;
}
