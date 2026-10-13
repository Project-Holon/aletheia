/*
 * function: scReportBeginNewPlayer
 * address:  0x021DFD0C
 * packet:   pkt_021DFD0C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciReportBeginNewPlayer  0x021E0000  arm
 *   sciReportBeginNewPlayer  0x_021E0000  arm  ov175
 *
 * ARM tail jump to the ov175 block copy sciReportBeginNewPlayer.
 */

typedef unsigned char  u8;
extern int sciReportBeginNewPlayer(u8 *p);

int scReportBeginNewPlayer(u8 *a0)
{
    return sciReportBeginNewPlayer(a0);
}

