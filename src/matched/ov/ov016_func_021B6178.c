/*
 * function: DWC_RAPUTIL_Main
 * address:  0x021B6178
 * packet:   pkt_021B6178
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   DWC_RAPUTIL_RunUtility  0x021B6100  thumb
 */

void DWC_RAPUTIL_RunUtility(int x);

int DWC_RAPUTIL_Main(void)
{
    DWC_RAPUTIL_RunUtility(0xf);
    return 1;
}
