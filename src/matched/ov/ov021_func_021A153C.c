/*
 * function: FIELD_SUBSCREEN_IsReportSaveAnimDone
 * address:  0x021A153C
 * packet:   pkt_ov021_021A153C
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
 *   REPORT_IsSaveAnimDone  0x021F00F0  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int REPORT_IsSaveAnimDone(char *p);

int FIELD_SUBSCREEN_IsReportSaveAnimDone(u32 *p)
{
    return REPORT_IsSaveAnimDone((char *)p[8]);
}
