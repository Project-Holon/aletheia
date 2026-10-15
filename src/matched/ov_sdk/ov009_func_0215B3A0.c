/*
 * function: CPSi_SocWrite2
 * address:  0x0215B3A0
 * packet:   pkt_ov009_0215B3A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SocWrite2 (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   send_udp  0x021585D8  arm  ov009
 *   send_ping  0x02158524  arm  ov009
 *   CPSi_SslWrite2  0x02162CA0  arm  ov009
 *   CPSi_TcpWrite2Raw  0x0215B198  arm  ov009
 *   gMslRefToken  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 */

struct Soc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char ssl;
};

struct Thread {
	unsigned char pad0[0xa4];
	struct Soc *soc;
};

struct ThreadInfo {
	unsigned long pad;
	struct Thread *current;
};

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CPSSoc;
struct _CPSSoc;
extern void send_udp(unsigned char *data, unsigned long len, struct _CPSSoc *soc);
extern void send_ping(unsigned char *pattern, unsigned long len, struct Soc *soc);
extern unsigned long CPSi_SslWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct CPSSoc *soc);
extern u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);
extern struct ThreadInfo gMslRefToken;
extern unsigned char g_021A826C;

unsigned long CPSi_SocWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2)
{
	struct Soc *soc;
	unsigned long total_written;

	soc = gMslRefToken.current->soc;
	if (soc != 0) {
		if (soc->state == 10) {
			if (len)
				send_udp(buf, len, (struct _CPSSoc *)soc);
			if (len2)
				send_udp(buf2, len2, (struct _CPSSoc *)soc);
			total_written = len + len2;
		} else if (soc->state == 11) {
			if (len)
				send_ping(buf, len, soc);
			if (len2)
				send_ping(buf2, len2, soc);
			total_written = len + len2;
		} else if (soc->ssl) {
			total_written = CPSi_SslWrite2(buf, len, buf2, len2, (struct CPSSoc *)soc);
		} else {
			total_written = CPSi_TcpWrite2Raw(buf, len, buf2, len2, (struct _CPSSoc *)soc);
		}
		if (!g_021A826C)
			return total_written;
	}
	return 0;
}
