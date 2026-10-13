/*
 * function: DWCi_IPTlEnd
 * address:  0x021D6538
 * packet:   pkt_021D6538
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_IPTlEnd 0x021D6538 arm
 *   TP_RequestAutoSamplingStopAsync  0x0208AD14  arm  arm9
 *   TP_WaitBusy  0x0208B220  arm  arm9
 *   TP_CheckError  0x0208B238  arm  arm9
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * Drain the channel-4 queue, then post the event at 0x021DE68C.
 * Addresses are Black-image addresses.
 */

extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_WaitBusy(unsigned int command_flgs);
extern unsigned int TP_CheckError(unsigned int command_flgs);
extern void DWCi_HEAPlFree_(void **mem);

void DWCi_IPTlEnd(void)
{
    int v = 4;

    do {
        TP_RequestAutoSamplingStopAsync();
        TP_WaitBusy(v);
    } while (TP_CheckError(v) != 0);
    DWCi_HEAPlFree_((void *)0x021DE68C);
}
