/*
 * function: send_udp
 * address:  0x021585D8
 * packet:   pkt_ov009_021585D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_udp (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   calc_checksum_do            0x02157700  arm  ov009
 *   invert_checksum            0x02157808  arm  ov009
 *   send_ip            0x0215832C  arm  ov009
 *   g_021A826C               0x021A826C  data
 */

struct _CPSSoc {
	unsigned char pad0[0xa];
	unsigned short local_port;      /* 0x0a */
	unsigned char padc[0xc];
	unsigned short remote_port;     /* 0x18 */
	unsigned char pad1a[2];
	unsigned long remote_ip;        /* 0x1c */
	unsigned char pad20[0x38];
	unsigned char *sndbuf;          /* 0x58 */
};

extern unsigned long calc_checksum_do(unsigned char *s, unsigned long len, unsigned long sum);
extern unsigned short invert_checksum(unsigned short sum);
extern void send_ip(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned char proto);
extern unsigned char g_021A826C;

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}

void send_udp(unsigned char *data, unsigned long len, struct _CPSSoc *soc)
{
	unsigned char *hdr;

	hdr = soc->sndbuf + 0x22;
	*(unsigned short *)(hdr - 0xc) = swap16((unsigned short)(NV(0x50, unsigned long) >> 16));
	*(unsigned short *)(hdr - 0xa) = swap16((unsigned short)NV(0x50, unsigned long));
	*(unsigned short *)(hdr - 0x8) = swap16((unsigned short)(soc->remote_ip >> 16));
	*(unsigned short *)(hdr - 0x6) = swap16((unsigned short)soc->remote_ip);
	*(unsigned short *)(hdr - 0x4) = 0x1100;
	*(unsigned short *)(hdr + 4) = swap16((unsigned short)(len + 8));
	*(unsigned short *)(hdr - 0x2) = *(unsigned short *)(hdr + 4);
	*(unsigned short *)(hdr + 2) = swap16(soc->remote_port);
	*(unsigned short *)(hdr + 0) = swap16(soc->local_port);
	*(unsigned short *)(hdr + 6) = 0;
	*(unsigned short *)(hdr + 6) = swap16(invert_checksum((unsigned short)calc_checksum_do(data, len, calc_checksum_do(hdr - 0xc, 0x14, 0))));
	send_ip(hdr, 8, data, len, soc->remote_ip, 0x11);
}
