/*
 * function: send_ip_frag
 * address:  0x02158204
 * packet:   pkt_ov009_02158204
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_ip_frag (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   calc_checksum            0x0215781C  arm  ov009
 *   send_ether            0x02158134  arm  ov009
 *   is_multicast            0x02157928  arm  ov009
 *   MI_CpuCopy               0x02082EA4  arm
 *   OS_DisableInterrupts     0x02087988  arm
 *   put_in_buffer            0x02157A44  arm  ov009
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   gCpsNetVars               0x021A826C  data
 *   gCpsUdpHeaderTemplate               0x021A1CC0  data
 *   CPSMyMac               0x021A82D4  data
 */

extern unsigned short calc_checksum(unsigned char *s, unsigned long len);
extern void send_ether(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
extern int is_multicast(unsigned v);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned long OS_DisableInterrupts(void);
extern void put_in_buffer(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned char gCpsNetVars;
extern char gCpsUdpHeaderTemplate[];
extern unsigned char CPSMyMac[6];

#define NV(off, type) (*(type *)((char *)&gCpsNetVars + (off)))
static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}

void send_ip_frag(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset)
{
	unsigned long enabled;

	*(unsigned short *)(hdr - 0x12) = swap16((unsigned short)(hdr_len + 0x14 + body_len));
	*(unsigned short *)(hdr - 0xe) = swap16((unsigned short)offset);
	*(unsigned short *)(hdr - 0xa) = 0;
	*(unsigned short *)(hdr - 0xa) = swap16(calc_checksum(hdr - 0x14, 0x14));
	if (ip_to != 0x7f000001 && ip_to != NV(0x50, unsigned long))
		send_ether(hdr - 0x14, hdr_len + 0x14, body, body_len, ip_to, 0x800);
	if (ip_to != 0x7f000001 && ip_to != NV(0x50, unsigned long) && !is_multicast(ip_to))
		return;
	MI_CpuCopy(gCpsUdpHeaderTemplate, hdr - 0x1c, 8);
	enabled = OS_DisableInterrupts();
	put_in_buffer(CPSMyMac, CPSMyMac, hdr - 0x1c, hdr_len + 0x1c, body, body_len);
	OS_RestoreInterrupts(enabled);
}
