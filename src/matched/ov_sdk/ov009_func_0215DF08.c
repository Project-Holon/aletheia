/*
 * function: func_0215DF08
 * address:  0x0215DF08
 * packet:   pkt_ov009_0215DF08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_UdpRecvCallback (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_02082EA4  0x02082EA4  arm
 *   func_02085800  0x02085800  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A1CD8     0x021A1CD8  data
 *   g_021AA4A4     0x021AA4A4  data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

#include "../include/G_021A1CD8.h"

struct SOCLiUdpData {
	struct SOCLiUdpData *next;
	unsigned short len;
	unsigned short remote_port;
	unsigned long remote_ip;
	unsigned char data[1];
};

struct SOCLRecvPipe {
	unsigned char pad[0x100];
	struct SOCLiUdpData *volatile last;
	struct SOCLiUdpData *first;
	unsigned short used;
	unsigned short limit;
	unsigned char queue[1];
};

struct CPSSoc {
	unsigned char pad0[0xa];
	unsigned short local_port;
	unsigned char padc[0x18 - 0xc];
	unsigned short remote_port;
	unsigned short remote_port2;
	unsigned long remote_ip;
	unsigned long remote_ip2;
	unsigned char pad24[0xa0 - 0x24];
	struct SOCLRecvPipe *recv_pipe;
	unsigned char pada4[0xb0 - 0xa4];
	unsigned short socket_port;
};

extern struct G_021A1CD8 *g_021A1CD8;
extern unsigned long g_021AA4A4[2];

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);
extern void func_02085800(void *queue);

int func_0215DF08(unsigned char *data, unsigned long len, struct CPSSoc *soc)
{
	struct SOCLRecvPipe *pipe = soc->recv_pipe;
	struct SOCLiUdpData *udpheader;
	unsigned long enable;

	enable = func_02087988();
	if (pipe->limit >= pipe->used + len) {
		udpheader = g_021A1CD8->alloc(len + 12);
		if (udpheader != 0) {
			pipe->used += len;
			udpheader->next = 0;
			udpheader->len = len;
			udpheader->remote_port = soc->remote_port;
			udpheader->remote_ip = soc->remote_ip;
			func_02082EA4(data, udpheader->data, len);
			if (pipe->last != 0)
				pipe->last->next = udpheader;
			pipe->last = udpheader;
			if (pipe->first == 0)
				pipe->first = udpheader;
		} else {
			g_021AA4A4[0]++;
		}
	} else {
		g_021AA4A4[1]++;
	}
	soc->remote_port = soc->remote_port2;
	soc->remote_ip = soc->remote_ip2;
	if (soc->socket_port == 0)
		soc->socket_port = soc->local_port;
	func_02085800(pipe->queue);
	func_0208799C(enable);
	return 1;
}
