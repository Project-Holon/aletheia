/*
 * function: SOCLi_UdpRecvCallback
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuCopy  0x02082EA4  arm
 *   OS_WakeupThread  0x02085800  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gSoclConfig     0x021A1CD8  data
 *   gSoclUdpDropCounts     0x021AA4A4  data
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

extern struct G_021A1CD8 *gSoclConfig;
extern unsigned long gSoclUdpDropCounts[2];

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void OS_WakeupThread(void *queue);

int SOCLi_UdpRecvCallback(unsigned char *data, unsigned long len, struct CPSSoc *soc)
{
	struct SOCLRecvPipe *pipe = soc->recv_pipe;
	struct SOCLiUdpData *udpheader;
	unsigned long enable;

	enable = OS_DisableInterrupts();
	if (pipe->limit >= pipe->used + len) {
		udpheader = gSoclConfig->alloc(len + 12);
		if (udpheader != 0) {
			pipe->used += len;
			udpheader->next = 0;
			udpheader->len = len;
			udpheader->remote_port = soc->remote_port;
			udpheader->remote_ip = soc->remote_ip;
			MI_CpuCopy(data, udpheader->data, len);
			if (pipe->last != 0)
				pipe->last->next = udpheader;
			pipe->last = udpheader;
			if (pipe->first == 0)
				pipe->first = udpheader;
		} else {
			gSoclUdpDropCounts[0]++;
		}
	} else {
		gSoclUdpDropCounts[1]++;
	}
	soc->remote_port = soc->remote_port2;
	soc->remote_ip = soc->remote_ip2;
	if (soc->socket_port == 0)
		soc->socket_port = soc->local_port;
	OS_WakeupThread(pipe->queue);
	OS_RestoreInterrupts(enable);
	return 1;
}
