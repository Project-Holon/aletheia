/*
 * function: sciReportBeginTeamData
 * address:  0x021E0080
 * packet:   pkt_ov175_021E0080
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sciReportBeginTeamData (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scireport.o), ov175.
 */

typedef unsigned int u32;

int sciReportBeginTeamData(u32 *p)
{
    p[0] = 4;
    return 0;
}
