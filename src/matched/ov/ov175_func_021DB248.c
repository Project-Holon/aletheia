/*
 * function: WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss
 * address:  0x021DB248
 * packet:   pkt_021DB248
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_ScReportAddByteValue  0x021DF3E8  arm
 *
 * Report callback: adds byte key 0x1c with value -1 to the report at +0x4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char s8;

extern int DWC_ScReportAddByteValue(u32 report, u16 keyId, s8 value);

int WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss(u32 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1c, -1);
}
