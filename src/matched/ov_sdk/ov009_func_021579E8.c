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
 *   func_02082EA4  0x02082EA4  arm
 *   func_02166444  0x02166444  arm  ov009
 *   g_021A1CC0  0x021A1CC0  data
 *   g_021A826C  0x021A826C  data
 */

extern char g_021A1CC0[];
extern unsigned char g_021A826C;
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern long func_02166444(unsigned char *dst, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);

void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len)
{
    func_02082EA4(g_021A1CC0, hdr + 6, 6);
    g_021A826C = func_02166444(hdr, hdr + 6, hdr_len - 6, body, body_len) < 0;
}
