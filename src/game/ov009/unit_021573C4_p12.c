/*
 * file:     unit_021573C4_p12.c
 * unit:     yes
 * function: func_02158714, func_02158BB8, func_02158C68, func_02158DB0
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
 */
#include "../../matched/include/G_021A86A4.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct CPSSocBuf {
    u32 size;
    u8 *data;
} CPSSocBuf;

typedef struct CPSSocRcvBuf {
    u32 start;
    u32 len;
    u32 order;
} CPSSocRcvBuf;

typedef struct _CPSSoc {
    void *thread;             /* 0x00 */
    u32 block_type;           /* 0x04 */
    u8 state;                 /* 0x08 */
    u8 ssl;                   /* 0x09 */
    u16 local_port;           /* 0x0A */
    void *con;                /* 0x0C */
    u32 when;                 /* 0x10 */
    u32 local_ip_real;        /* 0x14 */
    u16 remote_port;          /* 0x18 */
    u16 remote_port_bound;    /* 0x1A */
    u32 remote_ip;            /* 0x1C */
    u32 remote_ip_bound;      /* 0x20 */
    u32 ackno;                /* 0x24 */
    u32 ackno_sent;           /* 0x28 */
    u32 tick_acked;           /* 0x2C */
    u16 win_sent;             /* 0x30 */
    u8 ack_pending;           /* 0x32 */
    u8 sack_enabled;          /* 0x33 */
    u32 seqno;                /* 0x34 */
    u16 remote_win;           /* 0x38 */
    u16 remote_mss;           /* 0x3A */
    u32 remote_ackno;         /* 0x3C */
    u32 ackrcvd;              /* 0x40 */
    void *udpread_callback;   /* 0x44 */
    CPSSocBuf rcvbuf;         /* 0x48 */
    u32 rcvbufp;              /* 0x50 */
    CPSSocBuf sndbuf;         /* 0x54 */
    CPSSocBuf linbuf;         /* 0x5C */
    CPSSocBuf outbuf;         /* 0x64 */
    u32 outbufp;              /* 0x6C */
    CPSSocRcvBuf chunks[4];   /* 0x70 */
} CPSSoc;

struct net_vars {
    u8 pad0[4];
    u16 mymss;                /* 0x04 */
    u8 pad6[0x50 - 6];
    u32 myip;                 /* 0x50 */
};

struct thread_info {
    u16 isNeedRescheduling;
    u16 irqDepth;
    void *current;            /* 0x04 */
};

struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

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
u32 func_02158714(u8 *data, u32 len, CPSSoc *soc, u8 flag);
/* * sdk: reply_arp (libcps.TWL.HYB.a(network.o)) */ void func_02158BB8(unsigned char *buf);
/* * The link-up test reads the address word as long: read as unsigned long it * is common-subexpression-merged with the later compares and the image's * second load of the word disappears. */ /* * sdk: dispatch_arp (libcps.TWL.HYB.a network.o) */ void func_02158C68(unsigned char *buf, unsigned long len);
void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
extern struct thread_info g_02150FEC;
extern struct G_021A86A4 g_021A86A4;
extern u8 g_021A8328[90];
extern struct net_vars g_021A826C;
extern unsigned char g_021A82D4[6];


#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define SET32(p, v) (*(u16 *)(p) = HTONS((v) >> 16), *(u16 *)((p) + 2) = HTONS(v))


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

    if (g_02150FEC.current == ((u8 *)&g_021A86A4))
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

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))

#define GET16(p) SWAP16(*(unsigned short *)(p))

#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))

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
