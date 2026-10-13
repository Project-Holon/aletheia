/*
 * function: scReportBeginPlayerData
 * address:  0x021DFCF4
 * packet:   pkt_021DFCF4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciReportBeginPlayerData  0x021E0070  arm
 *   sciReportBeginPlayerData  0x_021E0070  arm
 *
 * ARM tail jump to the untraced 0x021E0070 block of ov175's data area.
 */

typedef unsigned int   u32;
extern int sciReportBeginPlayerData(u32 *p);

int scReportBeginPlayerData(u32 *a0)
{
    return sciReportBeginPlayerData(a0);
}

