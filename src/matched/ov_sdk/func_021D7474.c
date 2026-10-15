/*
 * function: DWCi_SetLedNormal
 * address:  0x021D7474
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SetLedNormal   0x021D7474  arm
 *   PMi_SendLEDPatternCommand  0x0208C6A4  arm  arm9
 *
 * Tail-call PMi_SendLEDPatternCommand with the constant 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SetLedNormal.c \
 *       --func DWCi_SetLedNormal --addr 0x021D7474 --region ov016 --cc dsi/1.1p1 --arm
 */

extern unsigned int PMi_SendLEDPatternCommand(unsigned int pattern);

void DWCi_SetLedNormal(void)
{
    PMi_SendLEDPatternCommand(1);
}
