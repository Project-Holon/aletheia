/*
 * function: _send_tcp
 * address:  0x02158714
 * packet:   pkt_ov009_02158714
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _send_tcp (libcps.TWL.HYB.a network.o, static)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_020870D0  0x020870D0  arm
 *   calc_checksum_do  0x02157700  arm  ov009
 *   invert_checksum  0x02157808  arm  ov009
 *   send_ip  0x0215832C  arm  ov009
 *   gMslRefToken     0x02150FEC  data
 *   g_021A86A4     0x021A86A4  data
 *   g_021A8328     0x021A8328  data
 *   g_021A826C     0x021A826C  data
 *
 * g_021A8328 is tmpbuf (90 bytes); the object addresses tmpbuf + 0x22.
 * g_021A826C is network.o's block of file statics (first symbol wfailed).
 *
 * The checksum goes through a u16 local: HTONS names its operand twice, and
 * with the calls inline the checksum is computed twice and len takes the
 * callee-saved register that flag has in the object.
 */

#include "../include/G_021A86A4.h"

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

extern struct thread_info gMslRefToken;
extern struct G_021A86A4 g_021A86A4;
extern u8 g_021A8328[90];
extern struct net_vars g_021A826C;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern unsigned long long func_020870D0(void);
extern u32 calc_checksum_do(u8 *s, u32 len, u32 sum);
extern u16 invert_checksum(u16 sum);
extern void send_ip(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto);

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SET32(p, v) (*(u16 *)(p) = HTONS((v) >> 16), *(u16 *)((p) + 2) = HTONS(v))

u32 _send_tcp(u8 *data, u32 len, CPSSoc *soc, u8 flag)
{
    u8 *hdr;
    u32 this_tcp_size;
    u16 sum;

    if ((flag & 5) == 0 && soc->state == 0)
        return len;

    if (gMslRefToken.current == ((u8 *)&g_021A86A4))
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
        enable = OS_DisableInterrupts();
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
        OS_RestoreInterrupts(enable);
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
    sum = invert_checksum(calc_checksum_do(data, len, calc_checksum_do(hdr - 12, this_tcp_size + 12, 0)));
    *(u16 *)(hdr + 16) = HTONS(sum);
    soc->seqno += len;
    if (flag & 3)
        soc->seqno++;
    send_ip(hdr, this_tcp_size, data, len, soc->remote_ip, 6);
    return len;
}
