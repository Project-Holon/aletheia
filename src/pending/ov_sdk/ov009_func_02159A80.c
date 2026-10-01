/*
 * function: func_02159A80
 * address:  0x02159A80
 * packet:   pkt_ov009_02159A80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  8 concrete bytes: a sl/sb role swap.  The `char *e = (char *)soc +
 *           ci*12` base local (the same idiom as the EXACT neighbour
 *           ov009_func_02159A30 / push_rwin_chunks) now reproduces the image's
 *           whole body incl. the `enabled` spill and `soc+ci*12` hoist, at
 *           size 1384.  Only the two callee-saved homes are transposed: image
 *           wend=disconp+len in sb and e=soc+ci*12 in sl; this build has
 *           wend in sl and e in sb.  Declaration order of `e`/`wend`
 *           (before/after each other, function vs block scope) and a named
 *           `wend` local do not flip it - allocator tie, not a source shape.
 *
 * sdk:      dt_ack (libcps.TWL.HYB.a network.o, static)
 *
 * symbols:
 *   func_02159244  0x02159244  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_02082EA4  0x02082EA4  arm
 *   func_021598EC  0x021598EC  arm  ov009
 *   func_0215993C  0x0215993C  arm  ov009
 *   func_02159A30  0x02159A30  arm  ov009
 *   func_0208799C  0x0208799C  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
 *   func_021599EC  0x021599EC  arm  ov009
 *   func_02159494  0x02159494  arm  ov009
 *   func_020858D8  0x020858D8  arm
 *
 * notes (w5_o2): same size as the object (1384 B), control flow and block
 * order match; residue is register allocation, 820 concrete bytes. The object
 * spills `enabled` to [sp] (DWARF: [fb+0]) and keeps ci*12 in fp and
 * soc + ci*12 in sl across the out-of-order retry, whose back edge lands
 * after the address computation (0x118). This build keeps `enabled` in fp
 * and loops back to the mul (0x10C). Tried: goto retry, inner for(;;),
 * inner while(1), while+continue, ci-- retry, chunk pointer local, a
 * CPSSoc-offset pointer local (gets the sl base via mla but not fp), dup as
 * the window end, volatile enabled (experiment only). The top-of-loop reads
 * and the branch bodies use different address forms in the object (branch 2
 * reloads start through soc+0x70 + fp), which points at an undeclared
 * pointer or macro for the loop-top reads.
 *
 * U63 (measured): 820/1282 concrete bytes, size exact 1384.  The divergence
 * opens at +0A8, where the image SPILLS `enabled` to [fb+0] (`str r0, [sp]`)
 * and keeps `soc + ci*12` in sl across the inner loop (back edge 0x118); this
 * build keeps `enabled` in fp, `ci*12` in sb and rematerialises soc+ci*12
 * into r0 (back edge 0x10C).  Everything downstream is that one allocation
 * choice.  U63 tried, all inert: every declaration position/order sampled for
 * the ten locals (75 orders, 820-860), `dup` reused as the window end (818),
 * a fresh `wend` local (818), a per-iteration `CPSSocRcvBuf *chunk` (917,
 * size 1360), `chunks = soc->chunks` + chunks[ci] (1200/1416), do/while inner
 * loop (820), and `enabled` typed u8/u16/volatile/unsigned long
 * (821/1384, 300/1388 shifted, 806/1356, 820/1384).  Only the parked body
 * keeps the size at 1384, so the residue is the allocator's spill choice,
 * not the source's shape.
 */

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

extern CPSSoc *func_02159244(u8 *iphdr, u8 *tcphdr);
extern void func_021594A4(u8 *iphdr, u8 *tcphdr, u32 len);
extern u32 func_02087988(void);
extern void func_02082EA4(void *srcp, void *destp, u32 size);
extern void func_021598EC(CPSSoc *soc, long chunk);
extern void func_0215993C(CPSSoc *soc);
extern void func_02159A30(CPSSoc *soc, long chunk);
extern u32 func_0208799C(u32 state);
extern void func_02159404(CPSSoc *soc, int flush);
extern void func_02085868(void *thread);
extern void func_021599EC(CPSSoc *soc);
extern void func_02159494(CPSSoc *soc);
extern void func_020858D8(void);

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define GET16(p) HTONS(*(u16 *)(p))
#define GET32(p) (((u32)GET16(p) << 16) | GET16((p) + 2))
#define TCPDATA(p) ((p) + (((p)[12] & 0xF0u) >> 2))

void func_02159A80(u8 *iphdr, u8 *tcphdr, u32 len)
{
    CPSSoc *soc;
    u8 flag;
    u32 remote_seqno;
    u32 bufok;
    u32 remote_ackno;
    u32 enabled;
    u32 dup;
    u32 disconp;
    u32 reorder_nextp;
    u32 wend;
    char *e;
    long ci;

    dup = 0;
    soc = func_02159244(iphdr, tcphdr);
    if (soc == 0)
    {
        func_021594A4(iphdr, tcphdr, len);
        return;
    }

    remote_ackno = GET32(tcphdr + 8);
    flag = tcphdr[13];
    if ((long)(remote_ackno - soc->remote_ackno) > 0)
        soc->remote_ackno = remote_ackno;
    remote_seqno = GET32(tcphdr + 4);

    enabled = func_02087988();
    if (soc->state == 4 && soc->ackno != remote_seqno)
    {
        if ((long)(remote_seqno - soc->ackno) < 0)
        {
            dup = soc->ackno - remote_seqno;
        }
        else
        {
            if (!(flag & 1))
            {
                disconp = soc->rcvbufp + remote_seqno - soc->ackno;
                if (soc->rcvbufp < disconp && disconp < soc->rcvbuf.size)
                {
                    if (len > soc->rcvbuf.size - disconp)
                        len = soc->rcvbuf.size - disconp;
                    if (len != 0)
                    {
                        wend = disconp + len;
                        for (ci = 0; ci < 4; ci++)
                        {
                            e = (char *)soc + ci * 12;

                            for (;;)
                            {
                                if (((CPSSocRcvBuf *)(e + 0x70))->start == 0)
                                {
                                    func_02082EA4(TCPDATA(tcphdr), soc->rcvbuf.data + disconp, len);
                                    soc->chunks[ci].start = disconp;
                                    soc->chunks[ci].len = len;
                                    func_021598EC(soc, ci);
                                    func_0215993C(soc);
                                    goto done;
                                }
                                reorder_nextp = ((CPSSocRcvBuf *)(e + 0x70))->start + ((CPSSocRcvBuf *)(e + 0x70))->len;
                                if (disconp < soc->chunks[ci].start && soc->chunks[ci].start <= disconp + len)
                                {
                                    func_02082EA4(TCPDATA(tcphdr), soc->rcvbuf.data + disconp, soc->chunks[ci].start - disconp);
                                    soc->chunks[ci].len += soc->chunks[ci].start - disconp;
                                    soc->chunks[ci].start = disconp;
                                    func_021598EC(soc, ci);
                                    func_0215993C(soc);
                                    goto done;
                                }
                                if (disconp <= reorder_nextp && reorder_nextp < disconp + len)
                                {
                                    func_02082EA4(TCPDATA(tcphdr) + reorder_nextp - disconp, soc->rcvbuf.data + reorder_nextp, disconp + len - reorder_nextp);
                                    soc->chunks[ci].len += disconp + len - reorder_nextp;
                                    func_0215993C(soc);
                                    func_021598EC(soc, ci);
                                    goto done;
                                }
                                if (soc->chunks[ci].start <= disconp && disconp + len <= reorder_nextp)
                                    goto done;
                                if (disconp >= soc->chunks[ci].start)
                                    break;
                                func_02159A30(soc, ci);
                            }
                        }
                    }
                }
            }
        done:
            func_0208799C(enabled);
            func_02159404(soc, 2);
            return;
        }
    }

    if (dup > len)
        return;
    len -= dup;
    soc->remote_win = GET16(tcphdr + 14);

    switch (soc->state)
    {
    case 0:
    case 2:
        func_0208799C(enabled);
        func_021594A4(iphdr, tcphdr, len);
        break;
    case 3:
        soc->state = 4;
        if (soc->block_type == 1)
        {
            soc->block_type = 0;
            func_02085868(soc->thread);
        }
        if (len == 0)
        {
            func_0208799C(enabled);
            break;
        }
        /* fall through */
    case 4:
        soc->ackrcvd++;
        if (len > soc->rcvbuf.size - soc->rcvbufp)
        {
            bufok = 0;
            len = soc->rcvbuf.size - soc->rcvbufp;
        }
        else
        {
            bufok = 1;
        }
        if (len != 0)
        {
            if (soc->chunks[0].start != 0 && soc->chunks[0].start <= soc->rcvbufp + len)
            {
                if (!(flag & 1))
                {
                    func_02082EA4(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, soc->chunks[0].start - soc->rcvbufp);
                    len = soc->chunks[0].start + soc->chunks[0].len - soc->rcvbufp;
                }
                else
                {
                    func_02082EA4(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, len);
                }
                soc->chunks[0].start = 0;
                func_021599EC(soc);
            }
            else
            {
                func_02082EA4(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, len);
            }
            soc->rcvbufp += len;
            soc->ackno += len;
            func_0215993C(soc);
            if (soc->block_type == 2)
            {
                soc->block_type = 0;
                func_02085868(soc->thread);
            }
        }
        if (bufok && (flag & 1))
        {
            soc->ackno++;
            soc->state = 6;
            func_0208799C(enabled);
            func_02159494(soc);
            if (len == 0 && soc->block_type == 2)
            {
                soc->block_type = 0;
                func_02085868(soc->thread);
            }
        }
        else
        {
            func_0208799C(enabled);
            if (len != 0)
                func_02159404(soc, 0);
        }
        break;
    case 7:
    case 8:
        if (flag & 1)
        {
            soc->ackno += len + 1;
            func_0208799C(enabled);
            func_02159404(soc, 2);
            soc->state = 0;
            if (soc->block_type == 2)
            {
                soc->block_type = 0;
                func_02085868(soc->thread);
            }
        }
        else
        {
            soc->state = 8;
            func_0208799C(enabled);
            if (len != 0)
            {
                soc->ackno += len;
                func_02159404(soc, 2);
            }
        }
        break;
    case 6:
    case 9:
        soc->state = 0;
        func_0208799C(enabled);
        if (soc->block_type == 2)
        {
            soc->block_type = 0;
            func_02085868(soc->thread);
        }
        break;
    default:
        func_0208799C(enabled);
        if (flag & 1)
            soc->ackno++;
        func_02159404(soc, 2);
        break;
    }
    func_020858D8();
}
