/*
 * file:     unit_021573C4_p06.c
 * unit:     yes
 * function: func_02158E84, func_02158F84, func_02158FE4
 * address:  0x02158E84
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   OS_WakeupThreadDirect    0x02085868  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   g_02150FEC               0x02150FEC  data
 *   func_021578EC  0x021578EC  arm  ov009
 *   func_02157928  0x02157928  arm  ov009
 *   func_0215781C  0x0215781C  arm  ov009
 *   func_02158DB0  0x02158DB0  arm  ov009
 */
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))
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
extern unsigned long func_021578EC(unsigned long ip);
extern int func_02157928(unsigned v);
extern int func_0215781C(int a, int b);
extern void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
void func_02158E84(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
unsigned long func_02158F84(unsigned long ip1, unsigned long ip2);
void func_02158FE4(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
extern int g_02150FEC;


/*
 * sdk:      process_icmp_reply (libcps.TWL.HYB.a network.o)
 */
void func_02158E84(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
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


unsigned long func_02158F84(unsigned long ip1, unsigned long ip2)
{
    if (ip1 != 0 && !func_021578EC(ip1) && !func_02157928(ip1) &&
        ip2 != 0 && !func_021578EC(ip2) && !func_02157928(ip2))
        return 1;
    return 0;
}


/*
 * sdk:      dispatch_icmp (libcps.TWL.HYB.a network.o)
 */
void func_02158FE4(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	if (len < 8)
		return;
	if (func_0215781C((int)icmpdata, len) != 0xffff)
		return;
	if (func_02158F84(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	switch (icmpdata[0]) {
	case 0:
		func_02158E84(iphdr, icmpdata, len);
		break;
	case 8:
		func_02158DB0(iphdr, icmpdata, len);
		break;
	}
}
