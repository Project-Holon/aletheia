/*
 * function: WIFIBATTLEMATCH_NET_ReportAddTeam
 * address: 0x021DB160
 * packet: pkt_ov175_021DB160
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021DB216..021DB218 is two zero alignment bytes.
 * symbols:
 *   func_021DF420 0x021DF420 arm ov175
 *   DWC_ScReportAddIntValue 0x021DF3E8 arm ov175
 */
extern int func_021DF420(int, int, int);
extern int DWC_ScReportAddIntValue(int, int, int);
void WIFIBATTLEMATCH_NET_ReportAddTeam(int *ctx, int *input, int invert)
{
    int flip = 0, skip = 0;
    int first, second;
    int present = 1;
    if (input[2] == 0 && input[3] == 0) present = 0;
    switch (input[1]) {
    case 0: case 3: first = 0; second = 1; flip = 1; break;
    case 1: case 4: first = 1; second = 0; flip = 1; break;
    case 2: first = 0; second = 0; skip = 1; break;
    case 5: case 6: default: first = 0; second = 0; break;
    }
    if (!invert && flip) { first ^= 1; second ^= 1; }
    if (!skip && func_021DF420(ctx[1], 0x15, 1)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x16, first)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x17, second)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x18, present != 0)) return;
    DWC_ScReportAddIntValue(ctx[1], 0x1c, -1);
}
