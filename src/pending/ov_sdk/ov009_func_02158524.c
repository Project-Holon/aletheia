/*
 * function: func_02158524
 * address:  0x02158524
 * packet:   pkt_ov009_02158524
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * u21: the defining object network.o is .comment 4.0.0.1024 -> dsi/1.1p1 and the size is already
 *      exact (180 B). The 46 concrete bytes are instruction ORDER in the prologue: the image loads
 *      both pool bases (wfailed, OSi_ThreadInfo) and the second OSi_ThreadInfo word before the
 *      first strh, 1.1p1 schedules the store first. First divergence +0018
 *      image `ldr r2, [pc, #0x90]` | ours `strh r4, [r5, #0x22]`.
 * u1: re-measured, unchanged (180 B, 46 concrete B).
 *
 * near miss (w2_s1): 46 bytes differ, schedule and register naming only: original loads the two pool bases (netvars, then OSi_ThreadInfo) before the first strh and keeps soc/icmp in r6/r5; 30+ statement orders and the chained-assignment forms tried.
 *
 * sdk:      send_ping (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02157700  0x02157700  arm  ov009
 *   func_02157808  0x02157808  arm  ov009
 *   func_0215832C  0x0215832C  arm  ov009
 *   g_021A826C  0x021A826C  data
 *   g_02150FEC  0x02150FEC  data
 */

struct NetVars {
	unsigned char pad0[8];
	unsigned short ping_seq;
};

struct SocBuf {
	unsigned long len;
	unsigned char *data;
};

struct Soc {
	unsigned char pad0[0xa];
	unsigned short local_port;
	unsigned char pad1[0x10];
	unsigned long remote_ip;
	unsigned char pad2[0x34];
	struct SocBuf sndbuf;
};

extern unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
extern unsigned short func_02157808(unsigned short sum);
extern void func_0215832C(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned char proto);
extern struct NetVars g_021A826C;
extern unsigned long g_02150FEC[];

void func_02158524(unsigned char *pattern, unsigned long len, struct Soc *soc)
{
	unsigned char *icmp = soc->sndbuf.data;
	unsigned short seq;
	unsigned short ck;

	*(unsigned short *)(icmp + 0x22) = 8;
	seq = g_021A826C.ping_seq;
	*(unsigned short *)(icmp + 0x26) = g_02150FEC[1];
	soc->local_port = seq;
	*(unsigned short *)(icmp + 0x24) = 0;
	g_021A826C.ping_seq = seq + 1;
	*(unsigned short *)(icmp + 0x28) = seq;
	ck = func_02157808((unsigned short)func_02157700(pattern, len, func_02157700(icmp + 0x22, 8, 0)));
	*(unsigned short *)(icmp + 0x24) = (ck >> 8) | (ck << 8);
	func_0215832C(icmp + 0x22, 8, pattern, len, soc->remote_ip, 1);
}
