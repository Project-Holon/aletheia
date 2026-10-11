/*
 * file:     unit_021573C4_p06.c
 * unit:     yes
 * function: func_02159A80, func_02159FE8, func_0215A0CC, func_0215A108, func_0215A23C, func_0215A450, func_0215A71C, func_0215A900, func_0215A970, func_0215AA18, func_0215AA5C, func_0215AA70, func_0215AA88, func_0215AAB0, func_0215AB10, func_0215AB5C, func_0215AB7C, func_0215AB94, func_0215ABB0, func_0215AC60, func_0215ACA0, func_0215AD00, func_0215AD3C, func_0215ADC4, func_0215AE18, func_0215AEB0, func_0215AF14, func_0215B064, func_0215B09C, func_0215B15C, func_0215B198, func_0215B3A0, func_0215B470, func_0215B504, func_0215B584, func_0215B5C4, func_0215B644
 * address:  0x02159A80
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
 *   find_socket                      0x02159244 arm
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   func_02157838            0x02157838  arm  ov009
 *   func_02159720            0x02159720  arm  ov009
 *   func_021597F8            0x021597F8  arm  ov009
 *   func_0215A0CC            0x0215A0CC  arm  ov009
 *   OS_DisableInterrupts             0x02087988 arm
 *   MI_CpuCopy                       0x02082ea4 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   g_02150FEC                       0x02150fec data
 *   OS_GetTick                       0x020870d0 arm
 *   g_021A8A64                       0x021a8a64 data
 *   g_021A826C                       0x021a826c data
 *   func_0215793C                    0x0215793c arm ov009
 *   func_0215781C                    0x0215781c arm ov009
 *   func_02157FF8                    0x02157ff8 arm ov009
 *   func_02158FE4                    0x02158fe4 arm ov009
 *   func_02157C7C  0x02157C7C  arm  ov009
 *   func_02158C68  0x02158C68  arm  ov009
 *   func_02157D48  0x02157D48  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_020870D0  0x020870D0  arm
 *   func_021593A8  0x021593A8  arm  ov009
 *   func_020857B0  0x020857B0  arm
 *   func_02162968  0x02162968  arm  ov009
 *   _tcp_send_finack                 0x02159494 arm
 *   _tcp_send_ack                    0x02159404 arm
 *   CPSi_SslShutdown                 0x02162dd8 arm
 *   OSi_ThreadInfo                   0x02150fec data
 *   func_02162E5C  0x02162E5C  arm  ov009
 *   func_02157390  0x02157390  arm  ov009
 *   func_021629BC  0x021629BC  arm  ov009
 *   MI_CpuMove               0x02083194  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   OS_Terminate             0x02088234  arm
 *   CPSi_SslConsume                  0x02162a94 arm
 *   CPSi_SocConsumeRaw               0x0215af14 arm
 *   func_02158714  0x02158714  arm  ov009
 *   tcp_write_do                     0x0215b09c arm
 *   func_0215B15C                    0x0215b15c arm ov009
 *   func_021585D8  0x021585D8  arm  ov009
 *   func_02158524  0x02158524  arm  ov009
 *   func_02162CA0  0x02162CA0  arm  ov009
 *   func_02083194  0x02083194  arm
 *   func_02162C28  0x02162C28  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   d_021A826C     0x021A826C  data
 *   func_02157290  0x02157290  arm
 */
#include "cps_types.h"
#include "../../matched/include/G_CPSFragTable.h"

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define GET16(p) HTONS(*(u16 *)(p))
#define GET32(p) (((u32)GET16(p) << 16) | GET16((p) + 2))
#define TCPDATA(p) ((p) + (((p)[12] & 0xF0u) >> 2))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define TICK() ((u32)(OS_GetTick() >> 16))
struct CPSSoc;
typedef struct {
    u32 ipfrom;
    u16 count;
    u16 id;
    u16 last;
    u16 size;
    u16 ofs[8];
    u16 end[8];
    u32 time;
    u8 *data;
    u8 *buf;
} CPSFragTable;

struct _CPSRwin {
	unsigned long start;
	unsigned long len;
	unsigned long pad;
};

extern CPSSoc *func_02159244(u8 *iphdr, u8 *tcphdr);
extern void func_021594A4(u8 *iphdr, u8 *tcphdr, u32 len);
extern u32 func_02087988(void);
extern void func_02082EA4(void *srcp, void *destp, u32 size);
extern void func_021598EC(struct _CPSSoc *soc, long chunk);
extern void func_0215993C(struct _CPSSoc *soc);
extern void func_02159A30(CPSSoc *soc, long chunk);
extern u32 func_0208799C(u32 state);
extern void func_02159404(CPSSoc *soc, int flush);
extern void func_02085868(void *thread);
extern void func_021599EC(char *p);
extern void func_02159494(int a);
extern void func_020858D8(void);
extern struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
extern void OS_YieldThread(void);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
extern void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_0215A0CC(unsigned char *iphdr, unsigned char *tcphdr);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 enabled);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern unsigned long long OS_GetTick(void);
extern u32 func_0215793C(u32 ip);
extern unsigned short func_0215781C(unsigned char *s, int len);
extern void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern void func_02158FE4(u8 *iphdr, u8 *icmpdata, u32 len);
extern unsigned char *func_02157C7C(unsigned long *len);
extern void func_02158C68(unsigned char *buf, unsigned long len);
extern void func_02157D48(void);
extern void func_02082BCC(void *dst, unsigned char data, unsigned long size);
extern unsigned long long func_020870D0(void);
extern void func_021593A8(char *soc, unsigned char flag);
extern void func_020857B0(void *queue);
extern unsigned long func_02162968(struct _CPSSoc *soc);
extern void _tcp_send_finack(struct _CPSSoc *soc);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);
extern void CPSi_SslShutdown(struct _CPSSoc *soc);
extern void func_02162E5C(void *soc);
extern void func_02157390(void);
extern unsigned char *func_021629BC(unsigned long *len, struct _CPSSoc *soc);
extern void MI_CpuMove(void *srcp, void *destp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_Terminate(void);
extern void CPSi_SslConsume(unsigned long len, struct _CPSSoc *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);
extern u32 func_02158714(u8 *data, u32 len, struct _CPSSoc *soc, u8 flag);
extern unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct _CPSSoc *soc, int need_probe);
extern void func_0215B15C(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc, int need_probe);
extern void func_021585D8(unsigned char *data, unsigned long len, struct _CPSSoc *soc);
extern void func_02158524(unsigned char *pattern, unsigned long len, struct _CPSSoc *soc);
extern unsigned long func_02162CA0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct _CPSSoc *soc);
extern void func_02083194(void *src, void *dst, unsigned long size);
extern long func_02162C28(struct CPSSoc *soc);
extern void func_02157E54(unsigned long ip);
extern void func_02085A38(unsigned long msec);
extern void func_02157290(int);
void func_02159A80(u8 *iphdr, u8 *tcphdr, u32 len);
void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_0215A108(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_0215A23C(u8 *iphdr, u8 *udphdr, u32 len);
u8 *func_0215A450(u8 *buf, u32 *fragmented);
void func_0215A71C(u8 *buf, u32 len);
void func_0215A900(void);
unsigned short func_0215A970(void);
unsigned long func_0215AA18(void);
void func_0215AA5C(int v);
void func_0215AA70(void);
void func_0215AA88(void);
void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
void func_0215AB10(void);
void func_0215AB5C(void);
asm void CPS_SocDup(void);
asm void CPS_SetUdpCallback(void);
unsigned long func_0215ABB0(struct _CPSSoc *soc);
unsigned long func_0215AC60(void);
void CPSi_TcpShutdownRaw(struct _CPSSoc *soc);
void CPS_TcpShutdown(void);
void func_0215AD3C(void);
unsigned char *func_0215ADC4(unsigned long *len, struct _CPSSoc *soc);
unsigned char *func_0215AE18(unsigned long *len, char *soc);
unsigned char *func_0215AEB0(unsigned long *len);
void func_0215AF14(unsigned long len, struct _CPSSoc *soc);
void CPS_SocConsume(unsigned long len);
unsigned long func_0215B09C(unsigned char *buf, unsigned long len, struct _CPSSoc *soc, int need_probe);
u32 func_0215B198(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);
unsigned long func_0215B3A0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);
unsigned long func_0215B470(unsigned char *buf, unsigned long len);
long func_0215B504(void);
void func_0215B584(void);
int func_0215B5C4(void);
void func_0215B644(void);
extern struct CPSFragTable g_021A8A64[8];
extern int OSi_ThreadInfo;
extern u8 d_021A826C[];












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
                        for (ci = 0; ci < 4; ci++)
                        {
                            e = (char *)soc + ci * 12;
                            wend = disconp + len;

                            for (;;)
                            {
                                if (((CPSSocRcvBuf *)(e + 0x70))->start == 0)
                                {
                                    func_02082EA4(TCPDATA(tcphdr), soc->rcvbuf.data + disconp, len);
                                    soc->chunks[ci].start = disconp;
                                    soc->chunks[ci].len = len;
                                    func_021598EC((struct _CPSSoc *)soc, ci);
                                    func_0215993C((struct _CPSSoc *)soc);
                                    goto done;
                                }
                                reorder_nextp = ((CPSSocRcvBuf *)(e + 0x70))->start + ((CPSSocRcvBuf *)(e + 0x70))->len;
                                if (disconp < soc->chunks[ci].start && soc->chunks[ci].start <= wend)
                                {
                                    func_02082EA4(TCPDATA(tcphdr), soc->rcvbuf.data + disconp, soc->chunks[ci].start - disconp);
                                    soc->chunks[ci].len += soc->chunks[ci].start - disconp;
                                    soc->chunks[ci].start = disconp;
                                    func_021598EC((struct _CPSSoc *)soc, ci);
                                    func_0215993C((struct _CPSSoc *)soc);
                                    goto done;
                                }
                                if (disconp <= reorder_nextp && reorder_nextp < wend)
                                {
                                    func_02082EA4(TCPDATA(tcphdr) + reorder_nextp - disconp, soc->rcvbuf.data + reorder_nextp, wend - reorder_nextp);
                                    soc->chunks[ci].len += wend - reorder_nextp;
                                    func_0215993C((struct _CPSSoc *)soc);
                                    func_021598EC((struct _CPSSoc *)soc, ci);
                                    goto done;
                                }
                                if (soc->chunks[ci].start <= disconp && wend <= reorder_nextp)
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
                func_021599EC((char *)soc);
            }
            else
            {
                func_02082EA4(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, len);
            }
            soc->rcvbufp += len;
            soc->ackno += len;
            func_0215993C((struct _CPSSoc *)soc);
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
            func_02159494((int)soc);
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













/*
 * sdk:      dt_fin (libcps.TWL.HYB.a(network.o))
 */
void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;
	unsigned long enabled;

	soc = (struct _CPSSoc *)func_02159244(iphdr, tcphdr);
	if (soc == 0)
		return;
	enabled = func_02087988();
	switch (soc->state) {
	case 7:
		soc->ackno++;
		soc->state = 9;
		func_0208799C(enabled);
		func_02159404((CPSSoc *)soc, 2);
		break;
	case 8:
		soc->ackno++;
		func_0208799C(enabled);
		func_02159404((CPSSoc *)soc, 2);
		soc->state = 0;
		if (soc->block_type == 2) {
			soc->block_type = 0;
			func_02085868(soc->thread);
		}
		break;
	case 4:
		soc->ackno++;
		soc->state = 6;
		func_0208799C(enabled);
		func_02159494((int)soc);
		break;
	default:
		func_0208799C(enabled);
		func_021594A4(iphdr, tcphdr, len);
		break;
	}
}













static void dt_rst(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc *soc = find_socket(iphdr, tcphdr);

	if (soc == 0)
		return;
	OS_YieldThread();
	soc->state = 0;
	if (soc->block_type - 1 <= 1) {
		soc->block_type = 0;
		OS_WakeupThreadDirect(soc->thread);
	}
}













/*
 * sdk:      dispatch_tcp (libcps.TWL.HYB.a network.o)
 */
void func_0215A108(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	if (len < 20)
		return;
	if ((tcphdr[0xc] & 0xf0) < 0x50)
		return;
	if (len < ((unsigned long)(tcphdr[0xc] & 0xf0) >> 2))
		return;
	if (func_02157838(tcphdr, len, iphdr, 6) != 0)
		return;
	len -= (unsigned long)(tcphdr[0xc] & 0xf0) >> 2;
	switch (tcphdr[0xd] & 0x17) {
	case 0x02:
		if (tcphdr[0xd] & 0x28)
			return;
		func_02159720(iphdr, tcphdr, len);
		break;
	case 0x12:
		if (tcphdr[0xd] & 0x28)
			return;
		func_021597F8(iphdr, tcphdr, len);
		break;
	case 0x10:
	case 0x11:
		func_02159A80(iphdr, tcphdr, len);
		break;
	case 0x01:
		func_02159FE8(iphdr, tcphdr, len);
		break;
	default:
		if (tcphdr[0xd] & 0x04)
			func_0215A0CC(iphdr, tcphdr);
		else
			func_021594A4(iphdr, tcphdr, len);
		break;
	}
}













/*
 * sdk:      dispatch_udp (libcps.TWL.HYB.a network.o)
 */
void func_0215A23C(u8 *iphdr, u8 *udphdr, u32 len)
{
    struct _CPSSoc *soc;
    struct _OSThread *t;
    u32 enabled;

    if (len < 8)
        return;
    if (*(u16 *)(udphdr + 6) != 0 && func_02157838(udphdr, len, iphdr, 0x11) != 0)
        return;
    enabled = OS_DisableInterrupts();
    for (t = g_02150FEC.list; t != 0; t = t->next) {
        soc = t->specific[0];
        if (soc != 0 && soc->thread != 0 && soc->state == 10 &&
            soc->local_port == NTOHS(udphdr + 2) &&
            (soc->remote_port == 0 || soc->remote_port == NTOHS(udphdr)) &&
            (soc->remote_ip == 0 || soc->remote_ip == 0xffffffff || soc->remote_ip == NTOHL(iphdr + 0xc))) {
            soc->local_ip_real = NTOHL(iphdr + 0x10);
            if (soc->remote_ip == 0) {
                soc->remote_ip = NTOHL(iphdr + 0xc);
                soc->remote_port = NTOHS(udphdr);
            }
            if (soc->rcvbufp == 0) {
                if (len - 8 > soc->rcvbuf.size)
                    soc->rcvbufp = soc->rcvbuf.size;
                else
                    soc->rcvbufp = len - 8;
                MI_CpuCopy(udphdr + 8, soc->rcvbuf.data, soc->rcvbufp);
                if (soc->block_type == 3) {
                    soc->block_type = 0;
                    OS_WakeupThreadDirect(soc->thread);
                } else if (soc->udpread_callback != 0 &&
                           soc->udpread_callback(soc->rcvbuf.data, soc->rcvbufp, soc) != 0) {
                    soc->rcvbufp = 0;
                }
            }
            break;
        }
    }
    OS_RestoreInterrupts(enabled);
}













/*
 * sdk:      check_frag (libcps.TWL.HYB.a network.o)
 */
u8 *func_0215A450(u8 *buf, u32 *fragmented)
{
    u32 i;
    u32 frag;
    u32 id;
    u32 frag_size;
    u32 frag_ofs;
    u32 frag_last;
    u32 header_len;
    CPSFragTable *unused;
    CPSFragTable *p;
    u32 size;
    u32 ipfrom;

    *fragmented = 0;
    unused = 0;
    frag = NTOHS(buf + 6);
    if ((frag & 0x3fff) == 0)
        return buf;
    header_len = (buf[0] & 0xf) << 2;
    ipfrom = NTOHL(buf + 0xc);
    id = *(u16 *)(buf + 4);
    p = ((CPSFragTable *)g_021A8A64);
    for (i = 0; i < 8; i++, p++) {
        if (p->count != 0 && p->ipfrom == ipfrom && p->id == id)
            break;
        if (p->count == 0 && unused == 0)
            unused = p;
    }
    frag_size = NTOHS(buf + 2) - header_len;
    frag_ofs = frag & 0x1fff;
    size = frag_size + (frag_ofs << 3);
    if (i == 8) {
        if (unused == 0 || size > 0x1000)
            return 0;
        p = unused;
        p->buf = g_021A826C.alloc(header_len + 0xe + 0x1000);
        if (p->buf == 0)
            return 0;
        p->ipfrom = ipfrom;
        p->id = id;
        p->last = 0;
        p->time = TICK();
        p->data = p->buf + 0xe + header_len;
        MI_CpuCopy(buf, p->buf + 0xe, header_len);
    }
    if (p->count == 8 || size > 0x1000) {
        p->count = 0;
        g_021A826C.free(p->buf);
        return 0;
    }
    frag_last = frag_ofs + ((frag_size + 7) >> 3);
    if ((frag & 0x2000) == 0) {
        p->size = size;
        p->last = frag_last;
    }
    p->ofs[p->count] = frag_ofs;
    p->end[p->count] = frag_last;
    p->count++;
    MI_CpuCopy(buf + header_len, p->data + (frag_ofs << 3), frag_size);
    if (p->last == 0)
        return 0;
    size = 0;
    i = 0;
    while (i < p->count) {
        if (p->ofs[i] <= size && size < p->end[i]) {
            size = p->end[i];
            i = 0;
        } else {
            i++;
        }
    }
    if (size < p->last)
        return 0;
    buf = p->buf + 0xe;
    *(u16 *)(buf + 2) = HTONS(p->size + ((buf[0] & 0xf) << 2));
    p->count = 0;
    *fragmented = 1;
    return buf;
}












/*
 * sdk:      dispatch_ip (libcps.TWL.HYB.a network.o)
 */
void func_0215A71C(u8 *buf, u32 len)
{
    u8 *data;
    u32 header_len;
    u8 type;
    u32 fragmented;

    if (NTOHL(buf + 0x10) != NTOHL(buf + 0xc)) {
        if (len < 20)
            return;
        if ((buf[0] & 0xf) < 5)
            return;
        if (NTOHS(buf + 2) < (buf[0] & 0xf) * 4)
            return;
        if (len < NTOHS(buf + 2))
            return;
        if (func_0215793C(NTOHL(buf + 0x10)) == 0)
            return;
        if (func_0215781C(buf, (buf[0] & 0xf) << 2) != 0xffff)
            return;
        if (g_021A826C.myip == NTOHL(buf + 0x10))
            func_02157FF8((u8 (*)[6])(buf - 8), NTOHL(buf + 0xc), 1);
    }
    buf = func_0215A450(buf, &fragmented);
    if (buf == 0)
        return;
    header_len = (buf[0] & 0xf) << 2;
    type = buf[9];
    data = buf + header_len;
    len = NTOHS(buf + 2) - header_len;
    if (type == 0x11) {
        func_0215A23C(buf, data, len);
    } else if (g_021A826C.myip != 0) {
        if (type == 1)
            func_02158FE4(buf, data, len);
        else if (type == 6)
            func_0215A108(buf, data, len);
    }
    if (fragmented)
        g_021A826C.free(buf - 14);
}












/*
 * sdk:      tcpip (libcps.TWL.HYB.a(network.o))
 */
void func_0215A900(void)
{
    unsigned long len;
    unsigned char *buf;

    for (;;) {
        buf = func_02157C7C(&len);
        if (len > 0x22) {
            unsigned short t = *(unsigned short *)(buf + 0xc);
            unsigned short type = (unsigned short)((t >> 8) | (t << 8));

            switch (type) {
            case 0x800:
                func_0215A71C(buf + 0xe, len - 0xe);
                break;
            case 0x806:
                func_02158C68(buf + 0xe, len - 0xe);
                break;
            }
        }
        func_02157D48();
    }
}











unsigned short func_0215A970(void)
{
	unsigned long conflict;
	struct _CPSSoc *soc;
	struct _OSThread *t;

	do {
		conflict = 0;
		g_021A826C.eport++;
		if (g_021A826C.eport < 0x400 || g_021A826C.eport >= 5000)
			g_021A826C.eport = 0x400;
		for (t = g_02150FEC.list; t != 0; t = t->next) {
			soc = t->specific[0];
			if (soc != 0 && soc->thread != 0 && soc->local_port == g_021A826C.eport) {
				conflict = 1;
				break;
			}
		}
	} while (conflict);
	return g_021A826C.eport;
}










unsigned long func_0215AA18(void)
{
    g_021A826C.rand_state = g_021A826C.rand_mult * g_021A826C.rand_state + g_021A826C.rand_inc;
    return (unsigned long)(g_021A826C.rand_state >> 32);
}









/*
 * Stores a word at +0xa4 of the block held in the second word of the module state block.
 */
void func_0215AA5C(int v)
{
    int blk = (int)g_02150FEC.current;

    *(int *)(blk + 0xa4) = v;
}









/*
 * Clears the word at +0xa4 of the block the state object holds.
 */
void func_0215AA70(void)
{
    int *p = (int *)g_02150FEC.current;

    *(int *)((char *)p + 0xa4) = 0;
}









/*
 * Puts the object at +0xa4 of the current root into mode 0xa and clears its
 * +0x50 word.
 */
void func_0215AA88(void)
{
    char *q = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (q != 0) {
        *(unsigned char *)(q + 8) = 0xa;
        *(int *)(q + 0x50) = 0;
    }
}









/*
 * sdk:      CPS_SocBind (libcps.TWL.HYB.a(network.o))
 */
void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip)
{
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (soc == 0)
        return;
    if (remote_ip == 0x7f000001)
        remote_ip = g_021A826C.myip;
    *(unsigned short *)(soc + 0x1a) = remote_port;
    *(unsigned short *)(soc + 0x18) = *(unsigned short *)(soc + 0x1a);
    *(unsigned long *)(soc + 0x20) = remote_ip;
    *(unsigned long *)(soc + 0x1c) = remote_ip;
    if (local_port != 0)
        *(unsigned short *)(soc + 0xa) = local_port;
    else
        *(unsigned short *)(soc + 0xa) = func_0215A970();
}








/*
 * sdk:      CPS_SocUse (libcps.TWL.HYB.a(network.o))
 */
void func_0215AB10(void)
{
    char *cur = (char *)g_02150FEC.current;
    char *soc = *(char **)(cur + 0xa4);

    if (soc == 0)
        return;
    *(char **)soc = cur;
    *(unsigned char *)(soc + 8) = 0;
    *(unsigned long *)(soc + 0x50) = 0;
    func_02082BCC(soc + 0x70, 0, 0x30);
    *(unsigned long *)(soc + 0x6c) = 0;
    *(unsigned long *)(soc + 0x44) = 0;
    *(unsigned char *)(soc + 0x33) = 0;
}








/*
 * Clears the word the object at +0xa4 points to, when it is there.
 */
void func_0215AB5C(void)
{
    char *p = (char *)g_02150FEC.current;
    int *q = *(int **)(p + 0xa4);

    if (q) {
        *q = 0;
    }
}







asm void CPS_SocDup(void)
{
	ldr r1, =0x02150FEC
	ldr r1, [r1, #4]
	ldr r1, [r1, #0xa4]
	str r1, [r0, #0xa4]
	bx lr
}







asm void CPS_SetUdpCallback(void)
{
	ldr r1, =0x02150FEC
	ldr r1, [r1, #4]
	ldr r1, [r1, #0xa4]
	cmp r1, #0
	strne r0, [r1, #0x44]
	bx lr
}








/*
 * sdk:      CPSi_TcpConnectRaw (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215ABB0(struct _CPSSoc *soc)
{
	unsigned long retry;
	unsigned long seqno;
	unsigned long enabled;

	seqno = func_0215AA18();
	for (retry = 0; retry < 3; retry++) {
		soc->seqno = seqno;
		soc->state = 2;
		soc->when = (unsigned long)(func_020870D0() >> 16);
		func_021593A8((char *)soc, 2);
		enabled = func_02087988();
		if (soc->state == 2 && g_021A826C.myip != 0) {
			soc->block_type = 1;
			func_020857B0(0);
		}
		func_0208799C(enabled);
		if (soc->state == 4)
			return 0;
		if (g_021A826C.myip == 0)
			break;
	}
	return 1;
}








/*
 * sdk:      CPS_TcpConnect (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215AC60(void)
{
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 9) != 0)
            return func_02162968((struct _CPSSoc *)soc);
        return func_0215ABB0((struct _CPSSoc *)soc);
    }
    return 1;
}








void CPSi_TcpShutdownRaw(struct _CPSSoc *soc)
{
	unsigned long enable;
	unsigned char state;

	OS_YieldThread();
	enable = OS_DisableInterrupts();
	state = soc->state;
	if ((unsigned char)(state + 0xfd) <= 1) {
		soc->state = 7;
		OS_RestoreInterrupts(enable);
		_tcp_send_finack(soc);
	} else if (state != 0) {
		OS_RestoreInterrupts(enable);
		_tcp_send_ack(soc, 2);
	} else {
		OS_RestoreInterrupts(enable);
	}
}







void CPS_TcpShutdown(void)
{
	struct _CPSSoc *soc = *(struct _CPSSoc **)((char *)*(unsigned long *)((char *)&OSi_ThreadInfo + 4) + 0xa4);

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslShutdown(soc);
	CPSi_TcpShutdownRaw(soc);
}







/*
 * sdk:      CPS_TcpClose (libcps.TWL.HYB.a(network.o))
 */
void func_0215AD3C(void)
{
    unsigned long start;
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (soc == 0)
        return;
    if (*(unsigned char *)(soc + 9) != 0)
        func_02162E5C(soc);
    start = (unsigned long)(func_020870D0() >> 16);
    while (g_021A826C.link_is_on() != 0 && *(unsigned char *)(soc + 8) != 0 &&
           (int)((unsigned long)(func_020870D0() >> 16) - start) < 0x27)
        func_02157390();
    *(unsigned char *)(soc + 8) = 0;
}







/*
 * sdk:      udp_read_raw (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_0215ADC4(unsigned long *len, struct _CPSSoc *soc)
{
    unsigned long tmp;
    unsigned long enable = func_02087988();

    tmp = soc->rcvbufp;

    while (tmp == 0) {
        soc->block_type = 3;
        func_020857B0(0);
        tmp = soc->rcvbufp;
    }
    func_0208799C(enable);
    *len = tmp;
    return soc->rcvbuf.data;
}







/*
 * sdk:      CPSi_TcpReadRaw (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_0215AE18(unsigned long *len, char *soc)
{
    unsigned long enable;
    unsigned long n;

    if (*(unsigned char *)(soc + 8) == 4)
        func_02159404((CPSSoc *)soc, 1);
    if (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
        enable = func_02087988();
        while (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
            *(unsigned long *)(soc + 4) = 2;
            func_020857B0(0);
        }
        func_0208799C(enable);
    } else {
        func_020858D8();
    }
    n = *(unsigned long *)(soc + 0x50);
    *len = n;
    if (n != 0)
        return *(unsigned char **)(soc + 0x4c);
    return 0;
}







/*
 * sdk:      CPS_SocRead (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_0215AEB0(unsigned long *len)
{
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return func_0215ADC4(len, (struct _CPSSoc *)soc);
        if (*(unsigned char *)(soc + 9) != 0)
            return func_021629BC(len, (struct _CPSSoc *)soc);
        return func_0215AE18(len, soc);
    }
    *len = 0;
    return 0;
}







/*
 * sdk:      CPSi_SocConsumeRaw (libcps.TWL.HYB.a network.o)
 */
void func_0215AF14(unsigned long len, struct _CPSSoc *soc)
{
	unsigned char *d;
	unsigned char *s;
	unsigned long enabled;
	long ci;
	int was_full;
	unsigned long old;

	enabled = OS_DisableInterrupts();
	old = soc->rcvbufp;
	was_full = 0;
	if (old == soc->rcvbuf.size && len != 0)
		was_full = 1;
	if (len >= old) {
		soc->rcvbufp = 0;
	} else {
		soc->rcvbufp = old - len;
		MI_CpuMove(soc->rcvbuf.data + len, soc->rcvbuf.data, old - len);
	}
	if (soc->chunks[0].start != 0 && (old -= soc->rcvbufp) != 0) {
		for (ci = 0; ci < 4 && soc->chunks[ci].start != 0; ci++)
			;
		if (soc->chunks[0].start > old) {
			s = soc->rcvbuf.data + soc->chunks[0].start;
			d = s - old;
			ci--;
			MI_CpuMove(s, d, soc->chunks[ci].start + soc->chunks[ci].len - soc->chunks[0].start);
			for (ci = 0; ci < 4 && soc->chunks[ci].start != 0; ci++)
				soc->chunks[ci].start -= old;
		} else {
			MI_CpuFill8(soc->chunks, 0, sizeof(soc->chunks));
			OS_Terminate();
		}
	}
	OS_RestoreInterrupts(enabled);
	if (soc->state != 0xa && soc->state != 0xb) {
		if (soc->rcvbufp == 0 || was_full)
			func_02159404((CPSSoc *)soc, 0);
	}
}







void CPS_SocConsume(unsigned long len)
{
	struct _CPSSoc *soc = *(struct _CPSSoc **)((char *)*(unsigned long *)((char *)&OSi_ThreadInfo + 4) + 0xa4);

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslConsume(len, soc);
	else
		CPSi_SocConsumeRaw(len, soc);
}





unsigned long func_0215B09C(unsigned char *buf, unsigned long len, struct _CPSSoc *soc, int need_probe)
{
	unsigned long thislen;
	unsigned long remote_win;
	unsigned long ackrcvd_save;
	unsigned long limit;
	unsigned long r;
	unsigned long ackno;

	ackrcvd_save = soc->ackrcvd;
	if (need_probe)
		remote_win = 1;
	else
		remote_win = soc->remote_win;
	limit = ackrcvd_save * 2 + 4;
	while (len != 0 && soc->state == 4) {
		thislen = soc->remote_mss;
		if (thislen >= remote_win)
			thislen = remote_win;
		if (g_021A826C.mymss < thislen)
			thislen = g_021A826C.mymss;
		if (!need_probe)
			thislen &= ~1;
		if (len < thislen)
			thislen = len;
		ackno = soc->ackrcvd;
		limit += ackno - ackrcvd_save;
		r = limit;
		limit = r - 1;
		ackrcvd_save = ackno;
		if (r == 0)
			thislen = 0;
		if (thislen == 0)
			break;
		thislen = func_02158714(buf, thislen, (struct _CPSSoc *)soc, 0x18);
		func_020858D8();
		remote_win -= thislen;
		buf += thislen;
		len -= thislen;
	}
	return thislen;
}





static void tcp_write_do2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct _CPSSoc *soc, int need_probe)
{
	if (tcp_write_do(buf, len, soc, need_probe) != 0 && len2 != 0)
		tcp_write_do(buf2, len2, soc, 0);
}





/*
 * sdk:      CPSi_TcpWrite2Raw (libcps.TWL.HYB.a network.o)
 */
u32 func_0215B198(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc)
{
    u32 total_written;
    u32 seqno;
    u32 start_time;
    u32 acked_len;
    int need_probe;

    total_written = 0;
    need_probe = 0;
    soc->ackrcvd = 0;
    start_time = TICK();
    while (g_021A826C.link_is_on() && len != 0 && soc->state == 4 && (int)(TICK() - start_time) < 0x9f) {
        seqno = soc->seqno;
        func_0215B15C(buf, len, buf2, len2, soc, need_probe);
        {
            u32 t = TICK();
            do {
                func_02157390();
                if (!g_021A826C.link_is_on())
                    break;
                if (soc->state != 4)
                    break;
                if (soc->seqno == soc->remote_ackno)
                    break;
                if ((int)(TICK() - t) >= 0xf)
                    break;
            } while (need_probe == 0 || soc->remote_win == 0);
        }
        acked_len = soc->remote_ackno - seqno;
        if (acked_len > soc->seqno - seqno)
            acked_len = 0;
        total_written += acked_len;
        if (acked_len != 0)
            start_time = TICK();
        soc->seqno = soc->remote_ackno;
        if (soc->state == 4 && soc->remote_win == 0 && acked_len == 0) {
            if (need_probe == 0) {
                u32 t = TICK();
                while (g_021A826C.link_is_on() && (int)(TICK() - t) < 0xf) {
                    func_02157390();
                    if (soc->remote_win != 0)
                        break;
                }
                if (soc->remote_win == 0)
                    need_probe = 1;
            }
        } else {
            need_probe = 0;
        }
        if (acked_len < len) {
            buf += acked_len;
            len -= acked_len;
        } else {
            buf = buf2 + (acked_len - len);
            len = len2 - (acked_len - len);
            buf2 = 0;
            len2 = 0;
        }
    }
    return total_written;
}



unsigned long func_0215B3A0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2)
{
	struct _CPSSoc *soc;
	unsigned long total_written;

	soc = g_02150FEC.current->specific[0];
	if (soc != 0) {
		if (soc->state == 10) {
			if (len)
				func_021585D8(buf, len, (struct _CPSSoc *)soc);
			if (len2)
				func_021585D8(buf2, len2, (struct _CPSSoc *)soc);
			total_written = len + len2;
		} else if (soc->state == 11) {
			if (len)
				func_02158524(buf, len, soc);
			if (len2)
				func_02158524(buf2, len2, soc);
			total_written = len + len2;
		} else if (soc->ssl) {
			total_written = func_02162CA0(buf, len, buf2, len2, (struct _CPSSoc *)soc);
		} else {
			total_written = func_0215B198(buf, len, buf2, len2, (struct _CPSSoc *)soc);
		}
		if (!g_021A826C.wfailed)
			return total_written;
	}
	return 0;
}



/*
 * sdk:      CPS_SocWrite (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215B470(unsigned char *buf, unsigned long len)
{
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);
    unsigned long pend;
    unsigned long n;
    unsigned long left;

    if (soc != 0) {
        pend = *(unsigned long *)(soc + 0x6c);
        if (pend != 0) {
            n = func_0215B3A0(*(unsigned char **)(soc + 0x68), pend, buf, len);
            left = *(unsigned long *)(soc + 0x6c);
            if (n >= left) {
                *(unsigned long *)(soc + 0x6c) = 0;
                return n - left;
            }
            func_02083194(*(unsigned char **)(soc + 0x68) + n, *(unsigned char **)(soc + 0x68), left - n);
            *(unsigned long *)(soc + 0x6c) = *(unsigned long *)(soc + 0x6c) - n;
            return 0;
        }
        return func_0215B3A0(buf, len, 0, 0);
    }
    return 0;
}



/*
 * sdk:      CPS_SocGetLength (libcps.TWL.HYB.a(network.o))
 */
long func_0215B504(void)
{
    long count;
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 4)
            func_02159404((CPSSoc *)soc, 1);
        if (*(unsigned char *)(soc + 9) != 0)
            return func_02162C28((struct CPSSoc *)soc);
        count = *(long *)(soc + 0x50);
        if (count != 0)
            return count;
        if (*(unsigned char *)(soc + 8) == 4)
            return count;
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return count;
        return -1;
    }
    return 0;
}



/*
 * sdk:      CPS_SocFlush (libcps.TWL.HYB.a(network.o))
 */
void func_0215B584(void)
{
    char *soc = *(char **)((char *)g_02150FEC.current + 0xa4);

    if (soc != 0 && *(unsigned long *)(soc + 0x6c) != 0) {
        func_0215B3A0(*(unsigned char **)(soc + 0x68), *(unsigned long *)(soc + 0x6c), 0, 0);
        *(unsigned long *)(soc + 0x6c) = 0;
    }
}



/*
 * sdk:      garprequest (libcps.TWL.HYB.a(network.o))
 */
int func_0215B5C4(void)
{
    unsigned long start;

    func_02157E54(g_021A826C.myip);
    func_02085A38(100);
    func_02157E54(g_021A826C.myip);
    start = (unsigned long)(func_020870D0() >> 16);
    while (g_021A826C.link_is_on() != 0 && (int)((unsigned long)(func_020870D0() >> 16) - start) < 0x17) {
        if (g_021A826C.ip_conflict != 0)
            return 0;
        func_02085A38(100);
    }
    return 1;
}



/*
 * Addresses are Black-image addresses.
 */
void func_0215B644(void)
{
    ((void (*)(void))(*(unsigned int *)(d_021A826C + 0x28)))();
    if (*(unsigned int *)(d_021A826C + 0x50) == 0)
        return;
    if (func_0215B5C4() != 0)
        return;
    func_02157290(4);
}
