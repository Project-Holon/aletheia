/*
 * function: FIELD_SUBSCREEN_StartReportSaveAnim
 * address:  0x021A1530
 * packet:   pkt_ov021_021A1530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_StartSaveAnim  0x021F00BC  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void REPORT_StartSaveAnim(int *p);

void FIELD_SUBSCREEN_StartReportSaveAnim(u32 *p)
{
    REPORT_StartSaveAnim((int *)p[8]);
}
