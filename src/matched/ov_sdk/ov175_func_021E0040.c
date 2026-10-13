/*
 * function: sciReportBeginGlobalData
 * address:  0x021E0040
 * packet:   pkt_ov175_021E0040
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sciReportBeginGlobalData (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scireport.o), ov175.  Open a global-data block: state 2, and the running
 * +0x120 offset advanced past the header it just summed.
 */

typedef unsigned int u32;

int sciReportBeginGlobalData(u32 *p)
{
    u32 *q = (u32 *)p[0x124 / 4];

    p[0] = 2;
    p[0x120 / 4] = q[0x2c / 4] + 0x44 + q[0x30 / 4] + q[0x34 / 4];
    return 0;
}
