/*
 * function: scReportAddByteValue
 * address:  0x021DFE08
 * packet:   pkt_021DFE08
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciReportAddByteValue  0x021E03F8  arm
 *   sciReportAddByteValue  0x_021E03F8  arm  ov175
 *
 * ARM tail jump to sciReportAddByteValue in the ov175 writer group.
 */

extern void sciReportAddByteValue(void);

void scReportAddByteValue(void)
{
    sciReportAddByteValue();
}

