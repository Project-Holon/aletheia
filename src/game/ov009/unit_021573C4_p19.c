/*
 * file:     unit_021573C4_p19.c
 * unit:     yes
 * function: func_02159FE8, func_0215A0CC, func_0215A108, func_0215A23C, func_0215A450
 * address:  0x02159FE8
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
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
 *   func_02159494  0x02159494  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 *   find_socket                      0x02159244 arm
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   func_02157838            0x02157838  arm  ov009
 *   func_02159720            0x02159720  arm  ov009
 *   func_021597F8            0x021597F8  arm  ov009
 *   func_02159A80            0x02159A80  arm  ov009
 *   func_0215A0CC            0x0215A0CC  arm  ov009
 *   OS_DisableInterrupts             0x02087988 arm
 *   MI_CpuCopy                       0x02082ea4 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   g_02150FEC                       0x02150fec data
 *   OS_GetTick                       0x020870d0 arm
 *   g_021A8A64                       0x021a8a64 data
 *   g_021A826C                       0x021a826c data
 */
#include "../../matched/include/G_CPSFragTable.h"

struct _OSThread;
struct _CPSSoc;
struct _CPSSoc_02159FE8 {
	void *thread;
	unsigned long waiting;
	unsigned char state;
	unsigned char pad0[0x1b];
	unsigned long ackno;
};

struct _CPSSoc_0215A0CC {
	struct _OSThread *thread;
	unsigned long block_type;
	unsigned char state;
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

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

struct CPSVars {
    u8 pad0[0x14];
    void *(*alloc)(u32);
    u8 pad18[0x44 - 0x18];
    void (*free)(void *);
};

extern struct _CPSSoc_02159FE8 *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02159404(struct _CPSSoc_02159FE8 *soc, int flush);
extern void func_02085868(void *thread);
extern void func_02159494(int a);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern struct _CPSSoc_0215A0CC *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
extern void OS_YieldThread(void);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
extern void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_02159A80(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_0215A0CC(unsigned char *iphdr, unsigned char *tcphdr);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 enabled);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern unsigned long long OS_GetTick(void);
/* * sdk: dt_fin (libcps.TWL.HYB.a(network.o)) */ void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
/* * sdk: dispatch_tcp (libcps.TWL.HYB.a network.o) */ void func_0215A108(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_0215A23C(u8 *iphdr, u8 *udphdr, u32 len);
u8 *func_0215A450(u8 *buf, u32 *fragmented);
extern struct OSThreadInfo g_02150FEC;
extern struct CPSFragTable g_021A8A64[8];
extern struct CPSVars g_021A826C;




/*
 * sdk:      dt_fin (libcps.TWL.HYB.a(network.o))
 */
void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc_02159FE8 *soc;
	unsigned long enabled;

	soc = func_02159244(iphdr, tcphdr);
	if (soc == 0)
		return;
	enabled = func_02087988();
	switch (soc->state) {
	case 7:
		soc->ackno++;
		soc->state = 9;
		func_0208799C(enabled);
		func_02159404(soc, 2);
		break;
	case 8:
		soc->ackno++;
		func_0208799C(enabled);
		func_02159404(soc, 2);
		soc->state = 0;
		if (soc->waiting == 2) {
			soc->waiting = 0;
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
	struct _CPSSoc_0215A0CC *soc = find_socket(iphdr, tcphdr);

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



#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))


#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))



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


#define TICK() ((u32)(OS_GetTick() >> 16))

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))


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
