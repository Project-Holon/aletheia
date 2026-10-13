/*
 * function: scReportEnd
 * address:  0x021DFD18
 * packet:   pkt_021DFD18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciReportEnd  0x021E0098  arm
 *   sciReportEnd  0x_021E0098  arm  ov175
 *
 * ARM tail jump to sciReportEnd, the ov175 byte-read path.
 */

extern void sciReportEnd(void);

void scReportEnd(void)
{
    sciReportEnd();
}

