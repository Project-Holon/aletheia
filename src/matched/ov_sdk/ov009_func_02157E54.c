/*
 * function: send_arprequest
 * address:  0x02157E54
 * packet:   pkt_ov009_02157E54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_arprequest (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   MI_CpuFill8              0x02082BCC  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   send_packet            0x021579E8  arm  ov009
 *   g_021A82D4               0x021A82D4  data
 *   g_021A826C               0x021A826C  data
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern unsigned char g_021A82D4[6];
extern unsigned char g_021A826C;

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))

static inline void put_ip(unsigned char *p, unsigned long v)
{
	*(unsigned short *)p = SWAP16((unsigned short)(v >> 16));
	*(unsigned short *)(p + 2) = SWAP16((unsigned short)v);
}

void send_arprequest(unsigned long ip)
{
	unsigned char buf[42];

	MI_CpuFill8(buf, 0, 42);
	MI_CpuFill8(buf, 0xff, 6);
	MI_CpuCopy(g_021A82D4, buf + 6, 6);
	*(unsigned short *)(buf + 12) = 0x0608;
	buf[15] = 1;
	buf[16] = 8;
	*(unsigned short *)(buf + 18) = 0x0406;
	buf[21] = 1;
	MI_CpuCopy(g_021A82D4, buf + 22, 6);
	put_ip(buf + 28, NV(0x50, unsigned long));
	put_ip(buf + 38, ip);
	send_packet(buf, 42, 0, 0);
}
