/*
 * function: scReportAddIntValue
 * address:  0x021DFDFC
 * packet:   pkt_021DFDFC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciReportAddIntValue  0x021E02F0  arm
 *   sciReportAddIntValue  0x_021E02F0  arm  ov175
 *
 * ARM tail jump to sciReportAddIntValue in the ov175 writer group.
 */

extern void sciReportAddIntValue(void);

void scReportAddIntValue(void)
{
    sciReportAddIntValue();
}

