/*
 * function: DWCi_SetLedWireless
 * address:  0x021D7448
 * packet:   pkt_ov016_021D7448
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetLedWireless (libdwcutil.TWL.HYB.a(sub.o))
 *
 * symbols:
 *   PM_GetLEDPattern  0x0208C6C0  arm
 *   PMi_SendLEDPatternCommand  0x0208C6A4  arm
 */

extern unsigned long PM_GetLEDPattern(int *patternBuf);
extern unsigned long PMi_SendLEDPatternCommand(int pattern);

void DWCi_SetLedWireless(void)
{
	int pat;

	if (PM_GetLEDPattern(&pat) != 0)
		return;
	if (pat != 15)
		PMi_SendLEDPatternCommand(15);
}
