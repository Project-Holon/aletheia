/*
 * function: sciReportReturnZero
 * address:  0x021DFFF8
 * packet:   pkt_021DFFF8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbols:
 *   (none)
 *
 * ARM stub: the "not supported" return of the ov175 vtable pair that
 * sciSerializeInt16 (byte writer) and sciReportBeginNewPlayer (block copy) sit next to.
 */

int sciReportReturnZero(void)
{
    return 0;
}
