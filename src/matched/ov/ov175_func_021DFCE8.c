/*
 * function: scReportBeginGlobalData
 * address:  0x021DFCE8
 * packet:   pkt_021DFCE8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciReportBeginGlobalData  0x021E0040  arm
 *   sciReportBeginGlobalData  0x_021E0040  arm
 *
 * ARM tail jump to the untraced 0x021E0040 block of ov175's data area.
 */

typedef unsigned int   u32;
extern int sciReportBeginGlobalData(u32 *p);

int scReportBeginGlobalData(u32 *a0)
{
    return sciReportBeginGlobalData(a0);
}

