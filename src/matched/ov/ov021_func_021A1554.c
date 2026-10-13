/*
 * function: FIELD_SUBSCREEN_CheckReportSaveCounter
 * address:  0x021A1554
 * packet:   pkt_ov021_021A1554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_CheckSaveCounter  0x021F009C  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern unsigned REPORT_CheckSaveCounter(char *p);

int FIELD_SUBSCREEN_CheckReportSaveCounter(u32 *p)
{
    return REPORT_CheckSaveCounter((char *)p[8]);
}
