/*
 * function: process_icmp_reply
 * address:  0x02158E84
 * packet:   pkt_ov009_02158E84
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      process_icmp_reply (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   OS_WakeupThreadDirect    0x02085868  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   g_02150FEC               0x02150FEC  data
 */

struct _OSThread;

struct _CPSSoc {
	struct _OSThread *thread;
	unsigned long state_wait;
	unsigned char state;
	unsigned char pad9;
	unsigned short local_port;
	unsigned char padc[0x10];
	unsigned long remote_ip;
	unsigned char pad20[0x28];
	unsigned long rcvbufsize;
	unsigned char *rcvbuf;
	unsigned long rcvlen;
};

extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int g_02150FEC;

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))

void process_icmp_reply(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	struct _CPSSoc *soc;
	struct _OSThread *t;
	unsigned long enable;

	enable = OS_DisableInterrupts();
	for (t = *(struct _OSThread **)((char *)&g_02150FEC + 8); t != 0; t = *(struct _OSThread **)((char *)t + 0x68)) {
		soc = *(struct _CPSSoc **)((char *)t + 0xa4);
		if (soc != 0 && soc->thread != 0 && soc->state == 0xb &&
		    *(unsigned short *)(icmpdata + 4) == (unsigned short)(unsigned long)soc->thread &&
		    soc->local_port == *(unsigned short *)(icmpdata + 6) &&
		    soc->rcvlen == 0 &&
		    soc->remote_ip == (((unsigned long)SWAP16(*(unsigned short *)(iphdr + 0xc)) << 16) | SWAP16(*(unsigned short *)(iphdr + 0xe)))) {
			if (len - 8 > soc->rcvbufsize)
				soc->rcvlen = soc->rcvbufsize;
			else
				soc->rcvlen = len - 8;
			MI_CpuCopy(icmpdata + 8, soc->rcvbuf, soc->rcvlen);
			if (soc->state_wait == 3) {
				soc->state_wait = 0;
				OS_WakeupThreadDirect(soc->thread);
			}
			break;
		}
	}
	OS_RestoreInterrupts(enable);
}
