/*
 * function: FIELD_SUBSCREEN_StopReportSaveAnim
 * address:  0x021A1548
 * packet:   pkt_ov021_021A1548
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: byte-correct; tail-call target is an unlabelled ov034 Thumb function (listing reads it as ARM), no witness.
 *
 * symbols:
 *   REPORT_StopSaveAnim  0x021F0108  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void REPORT_StopSaveAnim(int *p);

void FIELD_SUBSCREEN_StopReportSaveAnim(u32 *p)
{
    REPORT_StopSaveAnim((int *)p[8]);
}
