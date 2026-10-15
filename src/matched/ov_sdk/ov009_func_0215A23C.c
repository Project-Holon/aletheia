/*
 * function: dispatch_udp
 * address:  0x0215A23C
 * packet:   pkt_ov009_0215A23C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispatch_udp (libcps.TWL.HYB.a network.o)
 * symbols:
 *   check_tcpudpsum                    0x02157838 arm ov009
 *   OS_DisableInterrupts             0x02087988 arm
 *   MI_CpuCopy                       0x02082ea4 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   gMslRefToken                       0x02150fec data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct _CPSSoc;

struct _OSThread {
    u8 pad0[0x68];
    struct _OSThread *next;
    u8 pad1[0xa4 - 0x6c];
    struct _CPSSoc *specific;
};

struct _CPSSoc {
    struct _OSThread *thread;
    u32 block_type;
    u8 state;
    u8 pad0;
    u16 local_port;
    u8 pad1[0x14 - 0xc];
    u32 local_ip_real;
    u16 remote_port;
    u8 pad2[2];
    u32 remote_ip;
    u8 pad3[0x44 - 0x20];
    int (*udpread_callback)(u8 *buf, u32 len, struct _CPSSoc *soc);
    u32 rcvbufsize;
    u8 *rcvbuf;
    u32 rcvbufp;
};

struct OSThreadInfo {
    u8 pad0[8];
    struct _OSThread *list;
};

extern struct OSThreadInfo gMslRefToken;
extern u32 check_tcpudpsum(u8 *tcpudp_hdr, u32 len, u8 *ip_hdr, u16 proto);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 enabled);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);

#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))

void dispatch_udp(u8 *iphdr, u8 *udphdr, u32 len)
{
    struct _CPSSoc *soc;
    struct _OSThread *t;
    u32 enabled;

    if (len < 8)
        return;
    if (*(u16 *)(udphdr + 6) != 0 && check_tcpudpsum(udphdr, len, iphdr, 0x11) != 0)
        return;
    enabled = OS_DisableInterrupts();
    for (t = gMslRefToken.list; t != 0; t = t->next) {
        soc = t->specific;
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
                if (len - 8 > soc->rcvbufsize)
                    soc->rcvbufp = soc->rcvbufsize;
                else
                    soc->rcvbufp = len - 8;
                MI_CpuCopy(udphdr + 8, soc->rcvbuf, soc->rcvbufp);
                if (soc->block_type == 3) {
                    soc->block_type = 0;
                    OS_WakeupThreadDirect(soc->thread);
                } else if (soc->udpread_callback != 0 &&
                           soc->udpread_callback(soc->rcvbuf, soc->rcvbufp, soc) != 0) {
                    soc->rcvbufp = 0;
                }
            }
            break;
        }
    }
    OS_RestoreInterrupts(enabled);
}
