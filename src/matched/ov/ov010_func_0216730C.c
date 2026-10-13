/*
 * function: EVENT_RESEARCH_RADAR_GetReportMessageId
 * address:  0x0216730C
 * packet:   pkt_ov010_0216730C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int EVENT_RESEARCH_RADAR_GetReportMessageId(unsigned int n)
{
    switch (n) {
    case 0:
        return 0x174;
    case 1:
        return 0x175;
    case 2:
        return 0x176;
    case 3:
        return 0x177;
    case 4:
        return 0x178;
    case 5:
        return 0x179;
    }
    return 0;
}
