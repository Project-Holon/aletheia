/*
 * file:     unit_021573C4_p03.c
 * unit:     yes
 * function: func_02158714, func_02158BB8, func_02158C68, func_02158DB0, func_02158E84, func_02158F84, func_02158FE4, func_021590BC, func_02159190
 * address:  0x02158714
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
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02157700  0x02157700  arm  ov009
 *   func_02157808  0x02157808  arm  ov009
 *   func_0215832C  0x0215832C  arm  ov009
 *   g_02150FEC     0x02150FEC  data
 *   g_021A86A4     0x021A86A4  data
 *   g_021A8328     0x021A8328  data
 *   g_021A826C     0x021A826C  data
 *   func_02082EA4  0x02082EA4  arm
 *   func_021579E8  0x021579E8  arm  ov009
 *   g_021A82D4  0x021A82D4  data
 *   func_021579BC            0x021579BC  arm  ov009
 *   func_02157FF8            0x02157FF8  arm  ov009
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   OS_DisableInterrupts     0x02087988  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   OS_WakeupThreadDirect    0x02085868  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   func_021578EC  0x021578EC  arm  ov009
 *   func_02157928  0x02157928  arm  ov009
 *   func_0215781C  0x0215781C  arm  ov009
 */
#include "cps_types.h"

/* the ARP receive path reads the state block through its base address */
#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SET32(p, v) (*(u16 *)(p) = HTONS((v) >> 16), *(u16 *)((p) + 2) = HTONS(v))
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define GET16(p) SWAP16(*(unsigned short *)(p))
#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))
extern u32 func_02087988(void);
extern u32 func_0208799C(u32 state);
extern unsigned long long func_020870D0(void);
extern u32 func_02157700(u8 *s, u32 len, u32 sum);
extern u16 func_02157808(u16 sum);
extern void func_0215832C(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto);
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern int func_021579BC(unsigned short *a, unsigned short *b);
extern void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char *func_02157D8C(unsigned long ip);
extern void func_02157E54(unsigned long ip);
extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned long func_021578EC(unsigned long ip);
extern int func_02157928(unsigned v);
extern unsigned short func_0215781C(unsigned char *s, int len);
u32 func_02158714(u8 *data, u32 len, CPSSoc *soc, u8 flag);
void func_02158BB8(unsigned char *buf);
void func_02158C68(unsigned char *buf, unsigned long len);
void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
void func_02158E84(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
unsigned long func_02158F84(unsigned long ip1, unsigned long ip2);
void func_02158FE4(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
struct _CPSSoc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr);
extern u8 g_021A8328[90];
extern unsigned char g_021A82D4[6];




/*
 * sdk:      _send_tcp (libcps.TWL.HYB.a network.o, static)
 *
 * g_021A8328 is tmpbuf (90 bytes); the object addresses tmpbuf + 0x22.
 * g_021A826C is network.o's block of file statics (first symbol wfailed).
 *
 * The checksum goes through a u16 local: HTONS names its operand twice, and
 * with the calls inline the checksum is computed twice and len takes the
 * callee-saved register that flag has in the object.
 */
u32 func_02158714(u8 *data, u32 len, CPSSoc *soc, u8 flag)
{
    u8 *hdr;
    u32 this_tcp_size;
    u16 sum;

    if ((flag & 5) == 0 && soc->state == 0)
        return len;

    if (g_02150FEC.current == (struct _OSThread *)&g_021A86A4)
        hdr = g_021A8328 + 0x22;
    else
        hdr = soc->sndbuf.data + 0x22;

    if (flag & 2)
    {
        this_tcp_size = 28;
    }
    else if ((flag & 0x10) && soc->sack_enabled && soc->chunks[0].start)
    {
        long ci_order_prev, ci_order_max, ci;
        u32 sack_count;
        u32 enable;
        u32 mss;

        ci_order_prev = -1;
        ci_order_max = -1;
        sack_count = 0;
        enable = func_02087988();
        for (;;)
        {
            for (ci = 0; ci < 4 && soc->chunks[ci].start; ci++)
            {
                if ((ci_order_max < 0 || soc->chunks[ci_order_max].order < soc->chunks[ci].order) &&
                    (ci_order_prev < 0 || soc->chunks[ci].order < soc->chunks[ci_order_prev].order))
                    ci_order_max = ci;
            }
            if (ci_order_max < 0)
                break;
            SET32(hdr + 24 + sack_count * 8,
                  soc->ackno + soc->chunks[ci_order_max].start - soc->rcvbufp);
            SET32(hdr + 28 + sack_count * 8,
                  soc->ackno + soc->chunks[ci_order_max].start - soc->rcvbufp + soc->chunks[ci_order_max].len);
            sack_count++;
            ci_order_prev = ci_order_max;
            ci_order_max = -1;
        }
        func_0208799C(enable);
        SET32(hdr + 20, 0x01010500 | (sack_count * 8 + 2));
        this_tcp_size = 24 + sack_count * 8;
        mss = soc->remote_mss;
        if (mss >= g_021A826C.mymss)
            mss = g_021A826C.mymss;
        if (len > mss - 4 - sack_count * 8)
            len = (mss - 4 - sack_count * 8) & ~1;
    }
    else
    {
        this_tcp_size = 20;
    }

    SET32(hdr - 12, g_021A826C.myip);
    SET32(hdr - 8, soc->remote_ip);
    *(u16 *)(hdr - 4) = HTONS(6);
    *(u16 *)(hdr - 2) = HTONS(this_tcp_size + len);
    *(u16 *)(hdr + 0) = HTONS(soc->local_port);
    *(u16 *)(hdr + 2) = HTONS(soc->remote_port);
    SET32(hdr + 4, soc->seqno);
    SET32(hdr + 8, soc->ackno_sent = soc->ackno);
    hdr[12] = this_tcp_size << 2;
    hdr[13] = flag;
    soc->win_sent = soc->rcvbuf.size - soc->rcvbufp;
    *(u16 *)(hdr + 14) = HTONS(soc->win_sent);
    *(u16 *)(hdr + 16) = 0;
    *(u16 *)(hdr + 18) = 0;
    if (flag & 2)
    {
        SET32(hdr + 20, 0x02040000u + g_021A826C.mymss);
        SET32(hdr + 24, 0x01010402);
    }
    if (flag & 0x10)
    {
        soc->ack_pending = 0;
        soc->tick_acked = (u32)func_020870D0();
    }
    sum = func_02157808(func_02157700(data, len, func_02157700(hdr - 12, this_tcp_size + 12, 0)));
    *(u16 *)(hdr + 16) = HTONS(sum);
    soc->seqno += len;
    if (flag & 3)
        soc->seqno++;
    func_0215832C(hdr, this_tcp_size, data, len, soc->remote_ip, 6);
    return len;
}



#define BE32(p) (((unsigned long)SWAP16(*(unsigned short *)((p) + 0xc)) << 16) | SWAP16(*(unsigned short *)((p) + 0xe)))




/*
 * sdk:      reply_arp (libcps.TWL.HYB.a(network.o))
 */
void func_02158BB8(unsigned char *buf)
{
	unsigned short v;
	*(unsigned short *)(buf + 6) = 0x200;
	func_02082EA4(buf + 8, buf + 0x12, 10);
	func_02082EA4(g_021A82D4, buf + 8, 6);
	v = (unsigned short)(g_021A826C.myip >> 16);
	*(unsigned short *)(buf + 0xe) = (v >> 8) | (v << 8);
	v = (unsigned short)g_021A826C.myip;
	*(unsigned short *)(buf + 0x10) = (v >> 8) | (v << 8);
	func_02082EA4(buf + 0x12, buf - 0xe, 6);
	func_02082EA4(g_021A82D4, buf - 8, 6);
	func_021579E8(buf - 0xe, 0x2a, 0, 0);
}




/*
 * The link-up test reads the address word as long: read as unsigned long it
 * is common-subexpression-merged with the later compares and the image's
 * second load of the word disappears.
 */
/*
 * sdk:      dispatch_arp (libcps.TWL.HYB.a network.o)
 */
void func_02158C68(unsigned char *buf, unsigned long len)
{
	unsigned short op;
	unsigned long ipfrom;
	int from_me;
	int to_me;

	if (len < 0x1c)
		return;
	if (func_021579BC((short unsigned int *)(buf + 8), (short unsigned int *)g_021A82D4) == 0 || NV(0x50, long) == 0)
		return;
	if (*(unsigned short *)buf != 0x100 || *(unsigned short *)(buf + 2) != 8 || *(unsigned short *)(buf + 4) != 0x406)
		return;
	op = GET16(buf + 6);
	if (op != 1 && op != 2)
		return;
	ipfrom = GET32(buf + 0xe);
	from_me = (ipfrom == NV(0x50, unsigned long));
	to_me = (NV(0x50, unsigned long) == GET32(buf + 0x18));
	if (!from_me)
		func_02157FF8((unsigned char (*)[6])(buf + 8), ipfrom, to_me);
	if (op == 1 && to_me) {
		func_02158BB8(buf);
		return;
	}
	if (op == 2 && to_me && from_me)
		NV(1, unsigned char) = 1;
}




void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	unsigned long ip_reply_to = func_021578C8(BE32(iphdr));
	unsigned long sum;

	if (ip_reply_to == 0)
		return;
	if (func_02157D8C(ip_reply_to) == 0) {
		func_02157E54(ip_reply_to);
		return;
	}
	icmpdata[0] = 0;
	sum = *(unsigned short *)(icmpdata + 2) + 8;
	sum += sum >> 16;
	*(unsigned short *)(icmpdata + 2) = sum;
	func_0215832C(icmpdata, len, 0, 0, BE32(iphdr), 1);
}


#undef BE32

#undef BE32
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))




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
		    soc->rcvbufp == 0 &&
		    soc->remote_ip == (((unsigned long)SWAP16(*(unsigned short *)(iphdr + 0xc)) << 16) | SWAP16(*(unsigned short *)(iphdr + 0xe)))) {
			if (len - 8 > soc->rcvbuf.size)
				soc->rcvbufp = soc->rcvbuf.size;
			else
				soc->rcvbufp = len - 8;
			MI_CpuCopy(icmpdata + 8, soc->rcvbuf.data, soc->rcvbufp);
			if (soc->block_type == 3) {
				soc->block_type = 0;
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
	if (func_0215781C(icmpdata, len) != 0xffff)
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

#undef BE32
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))



/*
 * sdk:      check_listener (libcps.TWL.HYB.a network.o)
 */
struct _CPSSoc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc *soc;
	struct _OSThread *t;

	for (t = g_02150FEC.list; t != 0; t = t->next) {
		soc = t->specific[0];
		if (soc != 0 && soc->thread != 0 && soc->state == 1 &&
		    soc->local_port == SWAP16(*(unsigned short *)(tcphdr + 2)) &&
		    (soc->remote_port == 0 || soc->remote_port == SWAP16(*(unsigned short *)tcphdr)) &&
		    (soc->remote_ip == 0 || soc->remote_ip == BE32(iphdr, 0xc)))
			return soc;
	}
	return 0;
}



static unsigned long check_socket(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc)
{
	return (soc->state != 0xa && soc->state != 0xb) &&
	       soc->local_port == (unsigned short)((*(unsigned short *)(tcphdr + 2) >> 8) | (*(unsigned short *)(tcphdr + 2) << 8)) &&
	       soc->remote_port == (unsigned short)((*(unsigned short *)tcphdr >> 8) | (*(unsigned short *)tcphdr << 8)) &&
	       soc->remote_ip == (((unsigned long)(unsigned short)((*(unsigned short *)(iphdr + 0xc) >> 8) | (*(unsigned short *)(iphdr + 0xc) << 8)) << 16) |
	                          (unsigned short)((*(unsigned short *)(iphdr + 0xe) >> 8) | (*(unsigned short *)(iphdr + 0xe) << 8)));
}
