/*
 * function: send_packet
 * address:  0x021579E8
 * packet:   pkt_ov009_021579E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_packet (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   MI_CpuCopy  0x02082EA4  arm
 *   WCM_SendDCFDataEx  0x02166444  arm  ov009
 *   gCpsUdpHeaderTemplate  0x021A1CC0  data
 *   gCpsNetVars  0x021A826C  data
 */

extern char gCpsUdpHeaderTemplate[];
extern unsigned char gCpsNetVars;
extern void MI_CpuCopy(void *src, void *dst, unsigned long size);
extern long WCM_SendDCFDataEx(unsigned char *dst, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);

void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len)
{
    MI_CpuCopy(gCpsUdpHeaderTemplate, hdr + 6, 6);
    gCpsNetVars = WCM_SendDCFDataEx(hdr, hdr + 6, hdr_len - 6, body, body_len) < 0;
}
