/*
 * function: FIELD_SUBSCREEN_IsReportReady
 * address:  0x021A1518
 * packet:   pkt_ov021_021A1518
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
 *   REPORT_IsReady  0x021F0044  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int REPORT_IsReady(int *p);

int FIELD_SUBSCREEN_IsReportReady(u32 *p)
{
    return REPORT_IsReady((int *)p[8]);
}
