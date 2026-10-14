/*
 * function: GSYNC_DOWNLOAD_Process
 * address:  0x021D5D7C
 * packet:   pkt_021D5D7C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GSYNC_DOWNLOAD_CancelAsync  0x021D5CAC  thumb
 *   DWC_NdProcess  0x021C5AB8  arm  ov114
 *
 * Addresses are Black-image addresses.
 */

extern int GSYNC_DOWNLOAD_CancelAsync(char *p);
extern void DWC_NdProcess(void);

void GSYNC_DOWNLOAD_Process(char *p)
{
    if (GSYNC_DOWNLOAD_CancelAsync(p) != 0)
        DWC_NdProcess();
}
