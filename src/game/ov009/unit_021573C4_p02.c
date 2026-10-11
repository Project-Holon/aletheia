/*
 * file:     unit_021573C4_p02.c
 * unit:     yes
 * function: func_02157FF8, func_02158134, func_02158204, func_0215832C, func_02158524, func_021585D8, func_02158714, func_02158BB8, func_02158C68, func_02158DB0, func_02158E84, func_02158F84, func_02158FE4, func_021590BC, func_02159190, func_02159244, func_021592A8, func_0215938C, func_021593A8, func_02159404, func_02159494, func_021594A4, func_021595C0, func_021596A8, func_02159720, func_021597F8, func_021598EC, func_0215993C, func_021599EC, func_02159A30, func_02159A80, func_02159FE8, func_0215A0CC, func_0215A108, func_0215A23C, func_0215A450, func_0215A71C, func_0215A900, func_0215A970, func_0215AA18, func_0215AA5C, func_0215AA70, func_0215AA88, func_0215AAB0, func_0215AB10, func_0215AB5C, func_0215AB7C, func_0215AB94, func_0215ABB0, func_0215AC60, func_0215ACA0, func_0215AD00, func_0215AD3C, func_0215ADC4, func_0215AE18, func_0215AEB0, func_0215AF14, func_0215B064, func_0215B09C, func_0215B15C, func_0215B198, func_0215B3A0, func_0215B470, func_0215B504, func_0215B584, func_0215B5C4, func_0215B644, func_0215B67C, func_0215BAC0, func_0215BBB0, func_0215BBF0, func_0215BC04, func_0215BD58, func_0215BD8C, func_0215BE80, func_0215BF88, func_0215C2F8, func_0215C350, func_0215C44C, func_0215C508, func_0215C538, func_0215C7E0, func_0215C814, func_0215C8B4, func_0215C910
 * address:  0x02157FF8
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
 *   func_02157888            0x02157888  arm  ov009
 *   func_02157928            0x02157928  arm  ov009
 *   OS_GetTick               0x020870D0  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A8384               0x021A8384  data
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157F60  0x02157F60  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_021579E8  0x021579E8  arm  ov009
 *   g_021A82D4  0x021A82D4  data
 *   func_0215781C            0x0215781C  arm  ov009
 *   OS_DisableInterrupts     0x02087988  arm
 *   func_02157A44            0x02157A44  arm  ov009
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   g_021A1CC0               0x021A1CC0  data
 *   func_02157700  0x02157700  arm  ov009
 *   func_02157808  0x02157808  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   wfailed  0x021A826C  data
 *   ip_conflict  0x021A826D  data
 *   ipid  0x021A826E  data
 *   mymss  0x021A8270  data
 *   eport  0x021A8272  data
 *   _ZZ13func_02158524PhmP3SocE7pingseq  0x021A8274  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_020870D0  0x020870D0  arm
 *   g_021A86A4     0x021A86A4  data
 *   g_021A8328     0x021A8328  data
 *   func_021579BC            0x021579BC  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   OS_WakeupThreadDirect    0x02085868  arm
 *   func_021578EC  0x021578EC  arm  ov009
 *   OSi_ThreadInfo                   0x02150fec data
 *   dacktimer_reschedule             0x0215bac0 arm
 *   _tcp_send_handshake              0x021593a8 arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   g_021A8484               0x021A8484  data
 *   func_02159244  0x02159244  arm  ov009
 *   func_020858D8  0x020858D8  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
 *   OS_YieldThread                   0x020858d8 arm
 *   func_02157838            0x02157838  arm  ov009
 *   func_0215A0CC            0x0215A0CC  arm  ov009
 *   g_021A8A64                       0x021a8a64 data
 *   func_0215793C                    0x0215793c arm ov009
 *   func_02157C7C  0x02157C7C  arm  ov009
 *   func_02157D48  0x02157D48  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_020857B0  0x020857B0  arm
 *   func_02162968  0x02162968  arm  ov009
 *   _tcp_send_finack                 0x02159494 arm
 *   CPSi_SslShutdown                 0x02162dd8 arm
 *   func_02162E5C  0x02162E5C  arm  ov009
 *   func_02157390  0x02157390  arm  ov009
 *   func_021629BC  0x021629BC  arm  ov009
 *   MI_CpuMove               0x02083194  arm
 *   OS_Terminate             0x02088234  arm
 *   CPSi_SslConsume                  0x02162a94 arm
 *   CPSi_SocConsumeRaw               0x0215af14 arm
 *   tcp_write_do                     0x0215b09c arm
 *   func_0215B15C                    0x0215b15c arm ov009
 *   func_02162CA0  0x02162CA0  arm  ov009
 *   func_02083194  0x02083194  arm
 *   func_02162C28  0x02162C28  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   d_021A826C     0x021A826C  data
 *   func_02157290  0x02157290  arm
 *   func_02162EC4  0x02162EC4  arm  ov009
 *   g_021A83E4     0x021A83E4  data
 *   g_021A88E4     0x021A88E4  data
 *   g_021A8764     0x021A8764  data
 *   func_020873F8  0x020873F8  arm
 *   func_0208738C  0x0208738C  arm
 *   g_021A82FC     0x021A82FC  data
 *   func_0215BBF0  0x0215BBF0  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   g_021A85E4  0x021A85E4  data
 *   dacktimer_thread                 0x021a8524 data ov009
 *   g_021A1CCC               0x021A1CCC  data
 *   func_0215BD58  0x0215BD58  arm  ov009
 *   g_021A878E     0x021A878E  data
 *   func_0215B064                    0x0215b064 arm ov009
 *   g_021A1C9C                       0x021a1c9c data
 *   pingseq                          0x021a8274 data
 *   CPSDhcpMode                      0x021a8278 data
 *   cps                              0x021a827c data
 *   OS_Sleep                         0x02085a38 arm
 *   func_0215C508                    0x0215c508 arm ov009
 *   func_0215C7E0  0x0215C7E0  arm  ov009
 *   CPSDnsIp                 0x021A82DC  data
 */
#include "cps_types.h"
#include "../../matched/include/G_ArpEntry.h"

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define IPID g_021A826C.ipid
#define MYIP g_021A826C.myip
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SET32(p, v) (*(u16 *)(p) = HTONS((v) >> 16), *(u16 *)((p) + 2) = HTONS(v))
#define TCPDATA(p) ((p) + (((p)[12] & 0xF0u) >> 2))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define TICK() ((u32)(OS_GetTick() >> 16))
#define HI16(x) ((unsigned short)((x) >> 16))
#define LO16(x) ((unsigned short)(x))
#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))
#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))
struct CPSSoc;
struct SocBuf {
	unsigned long len;
	unsigned char *data;
};

struct rwin {
    unsigned long a;
    unsigned long b;
    unsigned long order;
};

struct Chunk {
	unsigned long start;
	unsigned long len;
	unsigned long aux;
};

struct S { int a, b, c; };

struct _CPSRwin {
	unsigned long start;
	unsigned long len;
	unsigned long pad;
};

typedef struct {
    unsigned long ip;
    unsigned char mac[6];
    unsigned short when;
} CPSArpCache;

/* network.o .bss from 0x021A827C: the variables dhcp_analyze_response
 * stores, at their vendor offsets relative to that address */
struct CPSBss {
    u32 netmask;             /* 0x00 CPSNetMask */
    u8 pad04[4];             /* 0x04 CPSiAlloc */
    int (*link_is_on)(void); /* 0x08 link_is_on */
    u32 dhcp_server;         /* 0x0C CPSDhcpServerIp */
    u8 pad10[0x1c - 0x10];
    u32 gateway;             /* 0x1C CPSGatewayIp */
    u8 pad20[0x28 - 0x20];
    u32 offered_myip;        /* 0x28 offered_myip */
    u32 lease_time;          /* 0x2C lease_time */
    u8 pad30[0x40 - 0x30];
    u32 myip;                /* 0x40 CPSMyIp */
    u8 pad44[0x60 - 0x44];
    u32 dns[2];              /* 0x60 CPSDnsIp */
};

typedef struct {
	unsigned long long x;
	unsigned long long mul;
	unsigned long long add;
} RandCtx;

extern unsigned long func_02157888(unsigned long ip);
extern int func_02157928(unsigned v);
extern u64 OS_GetTick(void);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char *func_02157D8C(unsigned long ip);
extern unsigned char *func_02157F60(unsigned long ip);
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern unsigned short func_0215781C(unsigned char *s, int len);
extern unsigned long OS_DisableInterrupts(void);
extern void func_02157A44(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
extern unsigned short func_02157808(unsigned short sum);
extern u32 func_02087988(void);
extern u32 func_0208799C(u32 state);
extern unsigned long long func_020870D0(void);
extern int func_021579BC(unsigned short *a, unsigned short *b);
extern void func_02157E54(unsigned long ip);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern unsigned long func_021578EC(unsigned long ip);
extern void dacktimer_reschedule(void);
extern void _tcp_send_handshake(struct _CPSSoc *soc, unsigned char flag);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern CPSSoc *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_020858D8(void);
extern void func_02159404(struct _CPSSoc *soc, int flush);
extern void func_02085868(void *thread);
extern void OS_YieldThread(void);
extern unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
extern void func_0215A0CC(unsigned char *iphdr, unsigned char *tcphdr);
extern u32 func_0215793C(u32 ip);
extern unsigned char *func_02157C7C(unsigned long *len);
extern void func_02157D48(void);
extern void func_02082BCC(void *dst, unsigned char data, unsigned long size);
extern void func_020857B0(void *queue);
extern unsigned long func_02162968(struct _CPSSoc *soc);
extern void _tcp_send_finack(struct _CPSSoc *soc);
extern void CPSi_SslShutdown(struct _CPSSoc *soc);
extern void func_02162E5C(void *soc);
extern void func_02157390(void);
extern unsigned char *func_021629BC(unsigned long *len, struct _CPSSoc *soc);
extern void MI_CpuMove(void *srcp, void *destp, unsigned long size);
extern void OS_Terminate(void);
extern void CPSi_SslConsume(unsigned long len, struct _CPSSoc *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);
extern unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct _CPSSoc *soc, int need_probe);
extern void func_0215B15C(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc, int need_probe);
extern unsigned long func_02162CA0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct _CPSSoc *soc);
extern void func_02083194(void *src, void *dst, unsigned long size);
extern long func_02162C28(struct CPSSoc *soc);
extern void func_02085A38(unsigned long msec);
extern void func_02157290(int);
extern void func_02162EC4(unsigned long now);
extern void func_020873F8(void *alarm);
extern void func_0208738C(void *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern void func_0215BBF0(void *arg);
extern int func_0208574C(void *thread);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern void func_0215B064(u32 len);
extern void OS_Sleep(u32 msec);
extern u8 *func_0215C508(u8 *p);
extern unsigned long func_0215C7E0(unsigned char *s, unsigned char **end);
void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset);
void func_0215832C(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto);
void func_02158524(unsigned char *pattern, unsigned long len, struct _CPSSoc *soc);
void func_021585D8(unsigned char *data, unsigned long len, struct _CPSSoc *soc);
u32 func_02158714(u8 *data, u32 len, CPSSoc *soc, u8 flag);
void func_02158BB8(unsigned char *buf);
void func_02158C68(unsigned char *buf, unsigned long len);
void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
void func_02158E84(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
unsigned long func_02158F84(unsigned long ip1, unsigned long ip2);
void func_02158FE4(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
struct _CPSSoc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr);
void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc);
unsigned long func_0215938C(unsigned long ip);
void func_021593A8(char *soc, unsigned char flag);
void func_02159494(int a);
void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021598EC(struct _CPSSoc *soc, long chunk);
void func_0215993C(struct _CPSSoc *soc);
void func_021599EC(char *p);
void func_02159A30(CPSSoc *soc, long i);
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
void func_0215B67C(void);
void func_0215BAC0(void);
void func_0215BBB0(void);
void dacktimer_alarmhandler(void);
unsigned char *func_0215BC04(unsigned char *d, int type);
unsigned long func_0215BD8C(void);
unsigned long func_0215BE80(int mode);
int func_0215BF88(u32 id, int retry);
int func_0215C2F8(void);
int func_0215C350(unsigned long *sleep, int mode);
void func_0215C44C(void);
u32 func_0215C538(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max);
unsigned long func_0215C814(unsigned char *name, unsigned long *pip);
unsigned long func_0215C8B4(unsigned char *name, unsigned long dnsip, unsigned short id);
unsigned long func_0215C910(char *name);
extern struct ArpEntry g_021A8384[8];
extern unsigned char g_021A82D4[6];
extern u8 g_021A1CC0[];
extern u8 g_021A8328[90];
extern int OSi_ThreadInfo;
extern struct _CPSSoc g_021A8484;
extern u8 d_021A826C[];
extern CPSSoc g_021A83E4;
extern unsigned char g_021A88E4[384];
extern unsigned char g_021A8764[384];
extern unsigned char g_021A82FC[];
extern struct _OSThread dacktimer_thread;
extern char g_021A1CCC[];
extern unsigned char g_021A878E[];
extern u8 g_021A1C9C[];
extern unsigned long CPSDnsIp[2];

static inline unsigned short SWAP16(unsigned short v)
{
	return (v >> 8) | (v << 8);
}



#define GET16(p) SWAP16(*(unsigned short *)(p))



#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))
















/*
 * sdk:      reg_arpcache (libcps.TWL.HYB.a network.o)
 */
void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry)
{
	unsigned long i;
	unsigned long candidate;
	unsigned short now;
	unsigned short oldest_time;

	if (ip == 0x7f000001 || ip == g_021A826C.myip)
		return;
	if (!func_02157888(ip))
		return;
	if (func_02157928(ip))
		return;
	now = (unsigned short)(OS_GetTick() >> 16);
	for (i = 0; i < 8; i++) {
		if (g_021A8384[i].ip == ip) {
			g_021A8384[i].when = now;
			MI_CpuCopy(mac, g_021A8384[i].mac, 6);
			return;
		}
	}
	if (!new_entry)
		return;
	oldest_time = 0;
	candidate = 0;
	for (i = 0; i < 8; i++) {
		if (g_021A8384[i].ip == 0) {
			candidate = i;
			break;
		}
		if ((short)(now - g_021A8384[i].when) > oldest_time) {
			candidate = i;
			oldest_time = now - g_021A8384[i].when;
		}
	}
	g_021A8384[candidate].ip = ip;
	MI_CpuCopy(mac, g_021A8384[candidate].mac, 6);
	g_021A8384[candidate].when = now;
}
















/*
 * sdk:      send_ether (libcps.TWL.HYB.a(network.o))
 */
void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type)
{
	unsigned char *mac_to;

	*(unsigned short *)(hdr - 2) = (type >> 8) | (type << 8);
	if (!func_02157928(ip_to)) {
		ip_to = func_021578C8(ip_to);
		if (ip_to == 0)
			return;
		mac_to = func_02157D8C(ip_to);
		if (mac_to == 0)
			mac_to = func_02157F60(ip_to);
		if (mac_to == 0)
			return;
		func_02082EA4(mac_to, hdr - 0xe, 6);
	} else {
		hdr[-0xe] = 1;
		hdr[-0xd] = 0;
		hdr[-0xc] = 0x5e;
		hdr[-0xb] = (ip_to >> 16) & 0x7f;
		hdr[-0xa] = ip_to >> 8;
		hdr[-9] = ip_to;
	}
	func_02082EA4(g_021A82D4, hdr - 8, 6);
	func_021579E8(hdr - 0xe, hdr_len + 0xe, body, body_len);
}








static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}









/*
 * sdk:      send_ip_frag (libcps.TWL.HYB.a network.o)
 */
void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset)
{
	unsigned long enabled;

	*(unsigned short *)(hdr - 0x12) = swap16((unsigned short)(hdr_len + 0x14 + body_len));
	*(unsigned short *)(hdr - 0xe) = swap16((unsigned short)offset);
	*(unsigned short *)(hdr - 0xa) = 0;
	*(unsigned short *)(hdr - 0xa) = swap16(func_0215781C(hdr - 0x14, 0x14));
	if (ip_to != 0x7f000001 && ip_to != g_021A826C.myip)
		func_02158134(hdr - 0x14, hdr_len + 0x14, body, body_len, ip_to, 0x800);
	if (ip_to != 0x7f000001 && ip_to != g_021A826C.myip && !func_02157928(ip_to))
		return;
	MI_CpuCopy(g_021A1CC0, hdr - 0x1c, 8);
	enabled = OS_DisableInterrupts();
	func_02157A44(g_021A82D4, g_021A82D4, hdr - 0x1c, hdr_len + 0x1c, body, body_len);
	OS_RestoreInterrupts(enabled);
}









/*
 * sdk:      send_ip (libcps.TWL.HYB.a network.o)
 */
void func_0215832C(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto)
{
    u16 offset;
    u8 *bodytmp;
    u32 this_len;

    offset = 0;
    hdr[-0x14] = 0x45;
    hdr[-0x13] = 0;
    IPID++;
    *(u16 *)(hdr - 0x10) = HTONS(IPID);
    hdr[-0xc] = 0x80;
    hdr[-0xb] = proto;
    *(u16 *)(hdr - 8) = HTONS(MYIP >> 16);
    *(u16 *)(hdr - 6) = HTONS(MYIP);
    *(u16 *)(hdr - 4) = HTONS(ip_to >> 16);
    *(u16 *)(hdr - 2) = HTONS(ip_to);

    if (hdr_len > 0x5c8) {
        bodytmp = hdr;
        while (hdr_len > 0x5c8) {
            func_02158204(hdr, 0, bodytmp, 0x5c8, ip_to, offset | 0x2000);
            bodytmp += 0x5c8;
            hdr_len -= 0x5c8;
            offset += 0xb9;
        }
        if (hdr_len != 0) {
            if (body_len != 0)
                func_02158204(hdr, 0, bodytmp, hdr_len, ip_to, offset | 0x2000);
            else
                func_02158204(hdr, 0, bodytmp, hdr_len, ip_to, offset);
            offset += hdr_len >> 3;
            hdr_len = 0;
        }
    }
    while (hdr_len + body_len > 0x5c8) {
        this_len = 0x5c8 - hdr_len;
        func_02158204(hdr, hdr_len, body, this_len, ip_to, offset | 0x2000);
        body_len -= this_len;
        hdr_len = 0;
        body += this_len;
        offset += 0xb9;
    }
    if (hdr_len + body_len == 0)
        return;
    func_02158204(hdr, hdr_len, body, body_len, ip_to, offset);
}









static u8 ip_conflict = 0;









static u8 wfailed = 0;









static u16 eport = 0;









static u16 mymss = 0;









static u16 ipid = 0;













/*
 * u21: the defining object network.o is .comment 4.0.0.1024 -> dsi/1.1p1 and the size is already
 *      exact (180 B). The 46 concrete bytes are instruction ORDER in the prologue: the image loads
 *      both pool bases (wfailed, OSi_ThreadInfo) and the second OSi_ThreadInfo word before the
 *      first strh, 1.1p1 schedules the store first. First divergence +0018
 *      image `ldr r2, [pc, #0x90]` | ours `strh r4, [r5, #0x22]`.
 * u1: re-measured, unchanged (180 B, 46 concrete B).
 *
 * near miss (w2_s1): 46 bytes differ, schedule and register naming only: original loads the two pool bases (netvars, then OSi_ThreadInfo) before the first strh and keeps soc/icmp in r6/r5; 30+ statement orders and the chained-assignment forms tried.
 *
 * w8: recovered the vendor object's own DWARF via tools/sdkobj.py send_ping --region ov009
 *     (sdk/TwlWiFi/lib/ARM9-TS/Rom/libcps.TWL.HYB.a(network.o)). Its .debug_line gives the
 *     original statement order: 1229 icmp=soc->sndbuf.data, 1230 icmp+0x22=8, 1231 icmp+0x26=
 *     OSi_ThreadInfo[1], 1232 icmp+0x24=0, 1233 soc->local_port=seq=wfailed.ping_seq, 1234
 *     icmp+0x28/ping_seq++, 1235 checksum store, 1236 send_ip. Its .debug_info lists exactly ONE
 *     local (unsigned char *icmp) and declares wfailed as `unsigned char`, OSi_ThreadInfo as `int`.
 *     Ordering to the vendor line order flips the literal-pool emission (OSi_ThreadInfo first)
 *     because 1.1p1 materialises the first-referenced constant; the image keeps netvars first.
 *     `const` on OSi_ThreadInfo hoists its base above the first strh but also flips the pair.
 *     across the first strh (vendor hoists both bases; ours sinks the second) plus the seq home
 *     (vendor lr, ours ip). DWARF order reproduced gets the pool words right but not the schedule.
 *
 * w8 re-probed-2 (all parked at 46 B unless stated): making g_021A826C `const` AND storing ping_seq
 *     through a const-stripping cast does NOT let its base win the materialisation race -- still
 *     OSi first, same as OSi const alone, so the flip is not about the write. A `const unsigned
 *     long *osi = g_02150FEC` local with `(u16)osi[1]` also leaves 46 B. DWARF order plus
 *     `soc->local_port = seq = ...` chained = 55 B. Loading OSi[1] into a u16 local *ahead of* the
 *     0x22 store DOES hoist both bases with netvars first (pool pair correct) but overshoots: the
 *     netvars value load goes to the very top, 60 B. Decision: pure 1.1p1 pre-RA scheduling.
 *
 * w8 re-probed (all still 46 concrete B): `const` on g_02150FEC hoists BOTH bases above the
 *     first strh -- the schedule half of the residue -- but materialises OSi_ThreadInfo first,
 *     flipping the pool pair (netvars must stay first). const-read/const-pointer-local of either
 *     base, a named local for the loaded OSi word, and moving the netvars store earlier all fail
 *     to hoist without flipping the pair; DWARF statement order gives 56 B (OSi first, load sunk).
 *
 * lane03 (2026-10-01): network.o's symbol table has
 *     `_ZZ9send_pingPhmP7_CPSSocE7pingseq`, a FUNCTION-LOCAL `static u16 pingseq`
 *     at .bss+8 (the "wfailed" relocation is the .bss section base). As a
 *     local static whose address is never taken it cannot alias the icmp
 *     stores, so 1.1p1 hoists its load and increment above them exactly as the
 *     image does; no `seq`/`ck` stand-ins remain (DWARF: icmp only; the byte
 *     swap is a static inline, a macro would call the checksum twice).
 *     46 B -> 2 B. Residue: our .bss holds only pingseq, so it sits at +0 and
 *     the two halfword accesses use #0 where the image uses #8; the .bss
 *     relocation stays wildcarded (the vendor `.bss` route is ARM9-only).
 *     File-scope copies of the five leading statics (wfailed, ip_conflict,
 *     ipid, mymss, eport) are always laid out after a function static, and
 *     file-scope or struct-member pingseq loses the no-alias hoist (184 B).
 *
 * lane17 (2026-10-01): EXACT. network.o's leading .bss statics written as
 *     zero-initialised file statics (wfailed, ip_conflict, ipid, mymss,
 *     eport, declared in the order 1.1p1's size-group reshuffle lays out as
 *     +0..+6), so pingseq lands at .bss+8 as in the vendor symtab; each
 *     static named in symbols: so the .bss reloc resolves (6 agree on base).
 *
 * sdk:      send_ping (libcps.TWL.HYB.a(network.o))
 */
void func_02158524(unsigned char *pattern, unsigned long len, struct _CPSSoc *soc)
{
	static unsigned short pingseq;
	unsigned char *icmp;

	icmp = soc->sndbuf.data;
	*(unsigned short *)(icmp + 0x22) = 8;
	*(unsigned short *)(icmp + 0x26) = (u32)g_02150FEC.current;
	*(unsigned short *)(icmp + 0x24) = 0;
	soc->local_port = pingseq;
	*(unsigned short *)(icmp + 0x28) = pingseq++;
	*(unsigned short *)(icmp + 0x24) = SWAP16(func_02157808((unsigned short)func_02157700(pattern, len, func_02157700(icmp + 0x22, 8, 0))));
	func_0215832C(icmp + 0x22, 8, pattern, len, soc->remote_ip, 1);
}









/*
 * sdk:      send_udp (libcps.TWL.HYB.a network.o)
 */
void func_021585D8(unsigned char *data, unsigned long len, struct _CPSSoc *soc)
{
	unsigned char *hdr;

	hdr = soc->sndbuf.data + 0x22;
	*(unsigned short *)(hdr - 0xc) = swap16((unsigned short)(g_021A826C.myip >> 16));
	*(unsigned short *)(hdr - 0xa) = swap16((unsigned short)g_021A826C.myip);
	*(unsigned short *)(hdr - 0x8) = swap16((unsigned short)(soc->remote_ip >> 16));
	*(unsigned short *)(hdr - 0x6) = swap16((unsigned short)soc->remote_ip);
	*(unsigned short *)(hdr - 0x4) = 0x1100;
	*(unsigned short *)(hdr + 4) = swap16((unsigned short)(len + 8));
	*(unsigned short *)(hdr - 0x2) = *(unsigned short *)(hdr + 4);
	*(unsigned short *)(hdr + 2) = swap16(soc->remote_port);
	*(unsigned short *)(hdr + 0) = swap16(soc->local_port);
	*(unsigned short *)(hdr + 6) = 0;
	*(unsigned short *)(hdr + 6) = swap16(func_02157808((unsigned short)func_02157700(data, len, func_02157700(hdr - 0xc, 0x14, 0))));
	func_0215832C(hdr, 8, data, len, soc->remote_ip, 0x11);
}







/* the ARP receive path reads the state block through its base address */
#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))










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






#undef BE32





#undef BE32




#undef BE32



#undef BE32


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






#undef BE32





#undef BE32




#undef BE32



#undef BE32


#undef BE32

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







static struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc *soc;
	struct _OSThread *t;

	t = *(struct _OSThread **)((char *)&OSi_ThreadInfo + 8);
	while (t != 0) {
		soc = *(struct _CPSSoc **)((char *)t + 0xa4);

		if (soc != 0 && *(struct _OSThread **)soc != 0) {
			if (check_socket(iphdr, tcphdr, soc) != 0)
				return soc;
		}
		t = *(struct _OSThread **)((char *)t + 0x68);
	}
	return 0;
}







void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc)
{
	long len;
	unsigned char *p;

	soc->remote_mss = 536;
	len = ((tcphdr[0xc] & 0xf0) / 4) - 20;
	p = tcphdr + 0x14;
	while (len-- > 0) {
		switch (*p++) {
		case 0:
			return;
		case 1:
			break;
		case 2:
			if (len <= 2)
				return;
			if (p[0] != 4)
				return;
			soc->remote_mss = (p[1] << 8) | p[2];
			p += 3;
			len -= 3;
			break;
		case 4:
			if (len <= 0)
				return;
			if (p[0] != 2)
				return;
			soc->sack_enabled = 1;
			p++;
			len--;
			break;
		default: {
			unsigned long l;

			if (len <= 0)
				return;
			l = p[0];
			if (l < 2)
				return;
			l--;
			len -= l;
			p += l;
		}
		}
	}
}







/*
 * One when the test fails, else the second call.
 */
unsigned long func_0215938C(unsigned long ip)
{
    unsigned long gateway = func_021578C8(ip);

    if (gateway == 0) {
        return 1;
    }

    return (unsigned long)func_02157D8C(gateway);
}




#undef BE32



#undef BE32


#undef BE32

#undef BE32
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))







/*
 * sdk:      _tcp_send_handshake (libcps.TWL.HYB.a(network.o))
 */
void func_021593A8(char *soc, unsigned char flag)
{
    if (func_0215938C(*(unsigned long *)(soc + 0x1c)) != 0 || g_02150FEC.current != (struct _OSThread *)&g_021A86A4) {
        func_02158714(0, 0, (struct _CPSSoc *)soc, flag);
    } else {
        func_02157E54(func_021578C8(*(unsigned long *)(soc + 0x1c)));
    }
}







static void _tcp_send_ack(struct _CPSSoc *soc, int flush)
{
	if (flush == 2)
		goto send;
	if (soc->ackno_sent == soc->ackno &&
	    soc->win_sent == (unsigned short)(soc->rcvbuf.size - soc->rcvbufp))
		return;
	if (flush == 1)
		goto send;
	soc->ack_pending++;
	if ((unsigned char)soc->ack_pending >= 2)
		goto send;
	if ((unsigned long)OS_GetTick() - soc->tick_acked >= 0x1991b)
		goto send;
	dacktimer_reschedule();
	return;

send:
	_tcp_send_handshake(soc, 0x10);
}







/*
 * Tail call that supplies the second argument 0x11.
 */
void func_02159494(int a)
{
    func_021593A8((char *)a, 0x11);
}







/*
 * sdk:      _tcp_send_rst (libcps.TWL.HYB.a network.o)
 */
void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	soc = &g_021A8484;
	MI_CpuFill8(soc, 0, sizeof(struct _CPSSoc));
	soc->local_port = GET16(tcphdr + 2);
	soc->remote_port = GET16(tcphdr);
	soc->remote_ip = GET32(iphdr + 0xc);
	if (tcphdr[0xd] & 0x10) {
		soc->seqno = GET32(tcphdr + 8);
		func_021593A8((char *)soc, 4);
		return;
	}
	soc->seqno = 0;
	soc->ackno = GET32(tcphdr + 4) + len;
	if (tcphdr[0xd] & 3)
		soc->ackno++;
	func_021593A8((char *)soc, 0x14);
}







/*
 * sdk:      dt_syn_LISTEN (libcps.TWL.HYB.a(network.o))
 */
void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc)
{
	soc->state = 3;
	soc->when = (unsigned long)(func_020870D0() >> 16);
	soc->local_ip_real = BE32(iphdr, 0x10);
	soc->remote_port = SWAP16(*(unsigned short *)tcphdr);
	soc->remote_ip = BE32(iphdr, 0xc);
	soc->ackno = BE32(tcphdr, 4) + 1;
	func_021592A8(tcphdr, soc);
	func_021593A8((char *)soc, 0x12);
}







/*
 * sdk:      find_specific_socket (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
    CPSSoc *soc = func_02159244(iphdr, tcphdr);

    if (soc != 0) {
        if (soc->state == 1) {
            func_021595C0(iphdr, tcphdr, soc);
        } else if (soc->state == 3) {
            soc->seqno = soc->seqno - 1;
            func_021595C0(iphdr, tcphdr, soc);
        } else {
            func_021594A4(iphdr, tcphdr, len);
        }
        return 1;
    }
    return 0;
}







/*
 * sdk:      dt_syn (libcps.TWL.HYB.start(network.o))
 */
void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	if (func_02158F84(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	if (func_021596A8(iphdr, tcphdr, len) != 0)
		return;
	soc = (struct _CPSSoc *)func_021590BC(iphdr, tcphdr);
	if (soc != 0) {
		func_021595C0(iphdr, tcphdr, soc);
		return;
	}
	func_020858D8();
	soc = (struct _CPSSoc *)func_021590BC(iphdr, tcphdr);
	if (soc != 0)
		func_021595C0(iphdr, tcphdr, soc);
}







/*
 * sdk:      dt_synack (libcps.TWL.HYB.start(network.o))
 */
void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	soc = (struct _CPSSoc *)func_02159244(iphdr, tcphdr);
	if (soc == 0 || soc->state != 2) {
		func_021594A4(iphdr, tcphdr, len);
		return;
	}
	func_020858D8();
	soc->ackno = BE32(tcphdr, 4) + 1;
	soc->remote_ackno = BE32(tcphdr, 8);
	soc->remote_win = SWAP16(*(unsigned short *)(tcphdr + 0xe));
	func_021592A8(tcphdr, soc);
	func_02159404(soc, 2);
	soc->state = 4;
	if (soc->block_type == 1) {
		soc->block_type = 0;
		func_02085868(soc->thread);
	}
}







void func_021598EC(struct _CPSSoc *soc, long chunk)
{
    long ci;
    unsigned long order_max = 0;

    for (ci = 0; ci < 3 && soc->chunks[ci].start != 0; ci++) {
        if (order_max < soc->chunks[ci].order)
            order_max = soc->chunks[ci].order;
    }
    soc->chunks[chunk].order = order_max + 1;
}







/*
 * sdk:      merge_rwin_chunks (libcps.TWL.HYB.start(network.o))
 */
void func_0215993C(struct _CPSSoc *soc)
{
	long ci;

again:
	if (soc->chunks[0].start != 0 && soc->rcvbufp >= soc->chunks[0].start) {
		soc->ackno += soc->chunks[0].start + soc->chunks[0].len - soc->rcvbufp;
		soc->rcvbufp = soc->chunks[0].start + soc->chunks[0].len;
		soc->chunks[0].start = 0;
		func_021599EC((char *)soc);
	}
	for (ci = 0; ci < 3; ci++) {
		if (soc->chunks[ci].start != 0 && soc->chunks[ci + 1].start != 0 &&
		    soc->chunks[ci].start + soc->chunks[ci].len >= soc->chunks[ci + 1].start) {
			soc->chunks[ci].len = soc->chunks[ci + 1].start + soc->chunks[ci + 1].len - soc->chunks[ci].start;
			soc->chunks[ci + 1].start = 0;
			func_021599EC((char *)soc);
			goto again;
		}
	}
}







/*
 * For every one of the three 0xc-byte records whose +0x70 triple is zero,
 * pulls the +0x7c triple down into +0x70 and clears +0x7c.
 */
void func_021599EC(char *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        char *e = p + i * 0xc;

        if (*(int *)(e + 0x70) == 0) {
            *(struct S *)(e + 0x70) = *(struct S *)(e + 0x7c);
            *(int *)(e + 0x7c) = 0;
        }
    }
}







/*
 * Shifts the 0xc-byte records above index i one slot up (each record's
 * +0x70 triple moving to +0x7c) and clears the +0x70 triple of slot i.
 */
void func_02159A30(CPSSoc *soc, long i)
{
    int j;

    for (j = 2; j >= i; j--) {
        soc->chunks[j + 1] = soc->chunks[j];
    }
    soc->chunks[i].start = 0;
}



#undef GET16


#undef GET16

#undef GET16
#define GET16(p) HTONS(*(u16 *)(p))



#undef GET32


#undef GET32

#undef GET32
#define GET32(p) (((u32)GET16(p) << 16) | GET16((p) + 2))















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
    p = g_021A8A64;
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
    p->from[p->count] = frag_ofs;
    p->end[p->count] = frag_last;
    p->count++;
    MI_CpuCopy(buf + header_len, p->data + (frag_ofs << 3), frag_size);
    if (p->last == 0)
        return 0;
    size = 0;
    i = 0;
    while (i < p->count) {
        if (p->from[i] <= size && size < p->end[i]) {
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






static inline int dhcp_denied(void)
{
    return g_021A826C.dhcp_callback ? g_021A826C.dhcp_callback() == 0 : 0;
}






/*
 * sdk:      scavenger (libcps.TWL.HYB.a network.o, static)
 *
 * g_021A826C is network.o's block of file statics (first symbol wfailed);
 * the fields below are named by the offsets this function touches.
 *
 * Case 0 spells the callback test out with a flag; cases 1 and 2 use the
 * ternary helper. The object compiles the two shapes differently.
 */
void func_0215B67C(void)
{
    int i;
    int dhcp_state;
    unsigned long dhcp_sleep;
    unsigned long gwcache_sleep;
    int first;
    CPSSoc *soc;
    OSThread *t;
    CPSArpCache *arp;
    unsigned long now;
    int denied;

    dhcp_state = 0;
    g_021A826C.calm = 0;
    func_02082BCC(&g_021A83E4, 0, sizeof(CPSSoc));
    g_021A83E4.rcvbuf.size = sizeof(g_021A88E4);
    g_021A83E4.rcvbuf.data = g_021A88E4;
    g_021A83E4.sndbuf.size = sizeof(g_021A8764);
    g_021A83E4.sndbuf.data = g_021A8764;
    func_0215AA5C((int)(&g_021A83E4));
    gwcache_sleep = 1;
    dhcp_sleep = 1;
    first = 1;
    g_021A826C.dhcp_state = 1;

    for (;;)
    {
        func_02085A38(1000);
        if (g_021A826C.calm)
            break;
        now = (unsigned long)(func_020870D0() >> 16);

        if (g_021A826C.link_is_on())
        {
            if (--dhcp_sleep == 0)
            {
                if (g_021A826C.mode & 1)
                {
                    if (dhcp_state == 0)
                    {
                        func_0215B644();
                        dhcp_state = 1;
                    }
                }
                else
                {
                    switch (dhcp_state)
                    {
                    case 0:
                        if (first)
                        {
                            g_021A826C.dhcp_state = 2;
                            first = 0;
                        }
                        if (!func_0215C2F8() || !func_0215C350(&dhcp_sleep, 0))
                        {
                            func_0215B644();
                            dhcp_state = 3;
                        }
                        else
                        {
                            denied = 0;
                            if (g_021A826C.dhcp_callback)
                            {
                                if (g_021A826C.dhcp_callback() == 0)
                                    denied = 1;
                            }
                            if (denied)
                            {
                                func_02157290(5);
                                func_0215B644();
                                dhcp_state = 3;
                            }
                            else
                            {
                                dhcp_state = 1;
                                if (!func_0215B5C4())
                                {
                                    func_02157290(4);
                                    dhcp_state = 3;
                                }
                            }
                        }
                        break;
                    case 1:
                        if (!func_0215C350(&dhcp_sleep, 1) && dhcp_sleep < 60)
                        {
                            dhcp_state = 2;
                        }
                        else if (dhcp_denied())
                        {
                            func_02157290(5);
                            func_0215B644();
                            dhcp_state = 3;
                        }
                        else if (!func_0215B5C4())
                        {
                            func_02157290(4);
                            dhcp_state = 3;
                        }
                        break;
                    case 2:
                        if (func_0215C350(&dhcp_sleep, 2))
                        {
                            if (dhcp_denied())
                            {
                                func_02157290(5);
                                func_0215B644();
                                dhcp_state = 3;
                            }
                            else
                            {
                                dhcp_state = 1;
                                if (!func_0215B5C4())
                                {
                                    func_02157290(4);
                                    dhcp_state = 3;
                                }
                            }
                        }
                        else if (dhcp_sleep < 60)
                        {
                            func_02157290(3);
                            gwcache_sleep = 1;
                            dhcp_sleep = 1;
                            dhcp_state = 0;
                        }
                        break;
                    case 3:
                        break;
                    }
                }
            }
        }
        else
        {
            gwcache_sleep = 1;
            func_02157290(1);
            dhcp_sleep = 1;
            dhcp_state = 0;
        }

        for (i = 0; i < 8; i++)
        {
            arp = &((CPSArpCache *)g_021A8384)[i];
            if (arp->ip && (short)(now - arp->when) > 957)
                arp->ip = 0;
        }

        if (g_021A826C.gateway_ip && --gwcache_sleep == 0)
        {
            func_02157E54(g_021A826C.gateway_ip);
            gwcache_sleep = 105;
        }

        for (t = g_02150FEC.list; t; t = t->next)
        {
            soc = (CPSSoc *)t->specific[0];
            if (soc && soc->thread)
            {
                if (soc->state == 3 && (long)(now - soc->when) > 39)
                {
                    soc->state = 1;
                    soc->remote_port = soc->remote_port_bound;
                    soc->remote_ip = soc->remote_ip_bound;
                }
                else if (soc->state == 2 && (long)(now - soc->when) > 39)
                {
                    if (soc->block_type == 1)
                    {
                        soc->state = 0;
                        soc->block_type = 0;
                        func_02085868(soc->thread);
                    }
                }
                else if (soc->state != 4 && soc->block_type == 2)
                {
                    soc->block_type = 0;
                    func_02085868(soc->thread);
                }
            }
        }

        for (i = 0; i < 8; i++)
        {
            CPSFragTable *f = &g_021A8A64[i];
            if (f->count && (long)(now - f->time) > 239)
            {
                g_021A826C.free(f->buf);
                f->count = 0;
            }
        }

        func_02162EC4(now);
        if (g_021A826C.periodic)
            g_021A826C.periodic();
    }

    if (!(g_021A826C.mode & 1) && dhcp_state != 3)
        func_0215C44C();
    func_0215AA70();
}







/*
 * sdk:      dacktimer_reschedule (libcps.TWL.HYB.a(network.o))
 */
void func_0215BAC0(void)
{
	unsigned long nextdelay = 0xffffffff;
	unsigned long diff;
	struct _CPSSoc *soc;
	struct _OSThread *t;
	unsigned long enabled;
	unsigned long tick;

	enabled = func_02087988();
	tick = (unsigned long)func_020870D0();
	for (t = g_02150FEC.list; t != 0; t = t->next) {
		soc = t->specific[0];
		if (soc != 0 && soc->thread != 0 && soc->state == 4 && soc->ack_pending != 0) {
			diff = tick - soc->tick_acked;
			if (diff >= 0x1991b) {
				func_02159404(soc, 1);
			} else if (0x1991bULL - diff < nextdelay) {
				nextdelay = 0x1991b - diff;
			}
		}
	}
	if (nextdelay != 0xffffffff) {
		func_020873F8(g_021A82FC);
		func_0208738C(g_021A82FC, nextdelay, func_0215BBF0, 0);
	}
	func_0208799C(enabled);
}







/*
 * sdk:      dacktimer (libcps.TWL.HYB.a(network.o))
 */
void func_0215BBB0(void)
{
    if (func_0208574C(((char *)&g_021A85E4)))
        return;
    do {
        func_0215BAC0();
        func_020857B0(0);
    } while (!func_0208574C(((char *)&g_021A85E4)));
}







void dacktimer_alarmhandler(void)
{
	OS_WakeupThreadDirect(&dacktimer_thread);
}







/*
 * sdk:      dhcp_setcommon (libcps.TWL.HYB.a network.o)
 */
unsigned char *func_0215BC04(unsigned char *d, int type)
{
	MI_CpuFill8(d, 0, 0xec);
	*(unsigned short *)(d + 0) = 0x0101;
	d[2] = 6;
	*(unsigned short *)(d + 4) = SWAP16((unsigned short)(g_021A826C.xid >> 16));
	*(unsigned short *)(d + 6) = SWAP16((unsigned short)g_021A826C.xid);
	*(unsigned short *)(d + 12) = SWAP16((unsigned short)(g_021A826C.myip >> 16));
	*(unsigned short *)(d + 14) = SWAP16((unsigned short)g_021A826C.myip);
	MI_CpuCopy(g_021A82D4, d + 0x1c, 6);
	*(unsigned short *)(d + 0xec) = 0x8263;
	*(unsigned short *)(d + 0xee) = 0x6353;
	*(unsigned short *)(d + 0xf0) = 0x0135;
	d[0xf2] = (unsigned char)type;
	d[0xf3] = 0x3d;
	d[0xf4] = 7;
	d[0xf5] = 1;
	MI_CpuCopy(g_021A82D4, d + 0xf6, 6);
	d += 0xfc;
	if (type != 7) {
		d[0] = 0x0c;
		d[1] = 10;
		MI_CpuCopy(g_021A1CCC, d + 2, 10);
		d[12] = 0x37;
		d[13] = 3;
		d[14] = 1;
		d[15] = 3;
		d[16] = 6;
		d += 17;
	}
	return d;
}







static unsigned char *pad_mem(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen)
{
	unsigned long n;

	if (curlen < minimum) {
		n = minimum - curlen;
		MI_CpuFill8(d, pattern, n);
		d += n;
	}
	return d;
}







/*
 * sdk:      dhcp_send_discover (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215BD8C(void)
{
	unsigned char *buf = g_021A878E;
	unsigned char *d;

	g_021A826C.rand_state = g_021A826C.rand_mult * g_021A826C.rand_state + g_021A826C.rand_inc;
	g_021A826C.xid = (unsigned long)(g_021A826C.rand_state >> 32);
	d = func_0215BC04(buf, 1);
	if (g_021A826C.offered_myip != 0) {
		*d++ = 0x32;
		*d++ = 4;
		*d++ = (unsigned short)(g_021A826C.offered_myip >> 16) >> 8;
		*d++ = g_021A826C.offered_myip >> 16;
		*d++ = (unsigned short)g_021A826C.offered_myip >> 8;
		*d++ = g_021A826C.offered_myip;
	}
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	return g_021A826C.xid;
}







/*
 * sdk:      dhcp_send_request (libcps.TWL.HYB.a network.o)
 */
unsigned long func_0215BE80(int mode)
{
	unsigned char *buf;
	unsigned char *d;

	buf = g_021A878E;
	d = func_0215BC04(buf, 3);
	if (mode == 0) {
		d[0] = 0x32;
		d[1] = 4;
		d[2] = (unsigned char)(HI16(g_021A826C.offered_myip) >> 8);
		d[3] = (unsigned char)HI16(g_021A826C.offered_myip);
		d[4] = (unsigned char)(LO16(g_021A826C.offered_myip) >> 8);
		d[5] = (unsigned char)LO16(g_021A826C.offered_myip);
		d[6] = 0x36;
		d[7] = 4;
		d[8] = (unsigned char)(HI16(g_021A826C.dhcp_server_ip) >> 8);
		d[9] = (unsigned char)HI16(g_021A826C.dhcp_server_ip);
		d[10] = (unsigned char)(LO16(g_021A826C.dhcp_server_ip) >> 8);
		d[11] = (unsigned char)LO16(g_021A826C.dhcp_server_ip);
		d += 12;
	}
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	return g_021A826C.xid;
}






static u16 pingseq = 0;






static u32 CPSDhcpMode = 0;






static struct CPSBss cps = {0};







/*
 * lane04 (2026-10-01): EXACT. The old p/mode r3<->ip swap came from modelling
 *           network.o's .bss as one struct: the vendor variables are separate
 *           objects, so 1.1p1 proves the in-loop stores cannot alias
 *           CPSDhcpMode and hoists `CPSDhcpMode & 2` itself (the optimizer's
 *           temporary takes ip, the bumped s takes r3). The .bss is modelled
 *           as zero-initialised file statics laid out at the vendor offsets
 *           (mwcc sorts .bss by size; definition order below gives the vendor
 *           order), stores grouped in one struct `cps` after CPSDhcpMode. All
 *           anchor on .bss+0 = wfailed, as in the vendor. Only DWARF locals
 *           remain: the bump reads s[0xef] into `c` before `s += 0xf0`.
 *
 * sdk:      dhcp_analyze_response (libcps.TWL.HYB.a network.o)
 */
int func_0215BF88(u32 id, int retry)
{
    u8 *s;
    u8 *end;
    u32 len;
    u32 start;
    int result;
    u32 myip_tmp;
    u8 c;
    long timeout;

    timeout = g_021A1C9C[retry] * 7;
    start = TICK();
    result = 0;
    while (cps.link_is_on() && result == 0 && (long)(TICK() - start) < timeout) {
        if (func_0215B504() == 0) {
            func_02157390();
            continue;
        }
        s = func_0215AEB0(&len);
        if (len > 0xf0 && s[0] == 2 && NTOHL(s + 4) == id && func_021579BC((short unsigned int *)(s + 0x1c), (short unsigned int *)g_021A82D4) == 0) {
            myip_tmp = G32(s + 0x10);
            end = s + len;
            result = 3;
            if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 && (c = s[0xef], s += 0xf0, c == 0x63)) {
                while (s < end && (c = *s++) != 0xff) {
                    if (c == 0)
                        continue;
                    switch (c) {
                    case 1:
                        cps.netmask = G32(s + 1);
                        break;
                    case 3:
                        cps.gateway = G32(s + 1);
                        break;
                    case 6:
                        if ((CPSDhcpMode & 2) == 0) {
                            if (s[0] < 8)
                                cps.dns[1] = 0;
                            else
                                cps.dns[1] = G32(s + 5);
                            cps.dns[0] = G32(s + 1);
                        }
                        break;
                    case 0x33:
                        cps.lease_time = G32(s + 1);
                        break;
                    case 0x35:
                        switch (s[1]) {
                        case 2:
                            result = 1;
                            cps.offered_myip = myip_tmp;
                            break;
                        case 5:
                            result = 2;
                            cps.myip = myip_tmp;
                            break;
                        }
                        break;
                    case 0x36:
                        cps.dhcp_server = G32(s + 1);
                        break;
                    }
                    s += *s + 1;
                }
            }
        }
        func_0215B064(len);
    }
    return result;
}





/*
 * sdk:      dhcp_discover_server (libcps.TWL.HYB.a(network.o))
 */
int func_0215C2F8(void)
{
    int result;
    int retry;

    func_0215AB10();
    func_0215AA88();
    func_0215AAB0(0x44, 0x43, 0xffffffff);
    for (retry = 0; retry < 5; retry++) {
        result = func_0215BF88(func_0215BD8C(), retry);
        if (result == 1)
            break;
    }
    func_0215AB5C();
    return result == 1;
}





/*
 * sdk:      dhcp_request_server (libcps.TWL.HYB.a(network.o))
 */
int func_0215C350(unsigned long *sleep, int mode)
{
	int result;
	int retry;
	unsigned long save;

	func_0215AB10();
	func_0215AA88();
	if (mode == 1)
		func_0215AAB0(0x44, 0x43, g_021A826C.dhcp_server_ip);
	else
		func_0215AAB0(0x44, 0x43, 0xffffffff);
	for (retry = 0; retry < 5; retry++) {
		result = func_0215BF88(func_0215BE80(mode), retry);
		if (result != 0 && result != 1)
			break;
	}
	func_0215AB5C();
	if (result == 2) {
		*sleep = g_021A826C.lease_time >> 1;
		g_021A826C.lease_sleep = (g_021A826C.lease_time * 3) >> 3;
		return 1;
	}
	save = g_021A826C.lease_sleep >> 1;
	g_021A826C.lease_sleep = save;
	*sleep = save;
	switch (mode) {
	case 1:
		if (save < 0x3c) {
			*sleep = 1;
			g_021A826C.lease_sleep = g_021A826C.lease_time >> 3;
		}
		break;
	case 2:
		if (save < 0x3c)
			*sleep = 1;
		break;
	}
	return 0;
}





/*
 * sdk:      dhcp_release_server (libcps.TWL.HYB.a(network.o))
 */
void func_0215C44C(void)
{
	unsigned char *buf;
	unsigned char *d;

	func_0215AB10();
	func_0215AA88();
	func_0215AAB0(0x44, 0x43, g_021A826C.dhcp_server_ip);
	buf = g_021A878E;
	d = func_0215BC04(buf, 7);
	*d++ = 0x36;
	*d++ = 4;
	*d++ = (unsigned short)(g_021A826C.dhcp_server_ip >> 16) >> 8;
	*d++ = g_021A826C.dhcp_server_ip >> 16;
	*d++ = (unsigned short)g_021A826C.dhcp_server_ip >> 8;
	*d++ = g_021A826C.dhcp_server_ip;
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	func_0215AB5C();
}

#undef GET16
#define GET16(p) ((u16)((p)[1] | ((p)[0] << 8)))



static unsigned char *dns_skipname(unsigned char *s)
{
	unsigned char c;

	while ((c = *s++) != 0) {
		if ((c & 0xc0) == 0xc0) {
			s++;
			break;
		}
		s += c;
	}
	return s;
}



static inline u16 get16(u8 *p)
{
    return (u16)((p[0] << 8) | p[1]);
}



/*
 * sdk:      resolve_common (libcps.TWL.HYB.a network.o)
 */
u32 func_0215C538(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max)
{
    u8 outbuf[68];
    u8 *buf;
    u8 *d;
    u8 *d0;
    u32 len;
    u32 cnt;
    u8 c;
    u32 ip;
    u32 start;
    u8 *end;

    *(u16 *)(outbuf + 0) = HTONS(id);
    if (type != 0x20)
        *(u16 *)(outbuf + 2) = 0x0001;
    else
        *(u16 *)(outbuf + 2) = 0x1001;
    *(u16 *)(outbuf + 4) = 0x100;
    *(u16 *)(outbuf + 6) = 0;
    *(u16 *)(outbuf + 8) = 0;
    *(u16 *)(outbuf + 10) = 0;
    d0 = outbuf + 12;
    d = d0 + 1;
    len = 0;
    while ((c = *name++) != 0) {
        if (d - outbuf > 0x3c)
            return 0xffffffff;
        if (c != '.') {
            len++;
            *d++ = c;
        } else if (len != 0) {
            *d0 = len;
            d0 = d;
            len = 0;
            d++;
        }
    }
    *d0 = len;
    ip = 0;
    d[0] = 0;
    d[1] = type >> 8;
    d[2] = type;
    d[3] = 0;
    d[4] = 1;
    func_0215B470(outbuf, d + 5 - outbuf);
    start = TICK();
    while (g_021A826C.link_is_on() && ip == 0 && (int)(TICK() - start) < 0xf) {
        if (func_0215B504() == 0) {
            OS_Sleep(10);
            continue;
        }
        buf = func_0215AEB0(&len);
        if (len > 12 && HTONS(*(u16 *)buf) == id) {
            if ((buf[3] & 0xf) == 3) {
                ip = 0xffffffff;
            } else if ((buf[3] & 0xf) == 0) {
                end = buf + len;
                d = buf + 12;
                cnt = GET16(buf + 4);
                while (cnt-- != 0)
                    d = func_0215C508(d) + 4;
                while (d < end) {
                    d = func_0215C508(d);
                    cnt = get16(d + 8);
                    if (get16(d) == type) {
                        if (type != 0xc) {
                            ip = ((u32)get16((u8 *)((u32)d + 6 + cnt)) << 16) | get16((u8 *)((u32)d + 8 + cnt));
                        } else if (cnt > rname_max) {
                            ip = 2;
                        } else {
                            MI_CpuCopy(d + 10, rname, cnt);
                            ip = 1;
                        }
                        break;
                    }
                    d += cnt + 10;
                }
            }
        }
        func_0215B064(len);
    }
    return ip;
}



static unsigned long strtol10(unsigned char *s, unsigned char **endptr)
{
	unsigned long acc = 0;
	unsigned char c;

	*endptr = s;
	for (;;) {
		c = *s;
		if ((unsigned char)(c - '0') > 9)
			break;
		acc = acc * 10 + (unsigned char)(c - '0');
		s++;
		*endptr = s;
	}
	return acc;
}



/*
 * sdk:      rawip (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215C814(unsigned char *name, unsigned long *pip)
{
    unsigned long ip = 0;
    int i = 0;
    unsigned long field;
    unsigned char *next;

    do {
        field = func_0215C7E0(name, &next);
        if (name == next)
            return 0;
        name = next;
        if (field > 0xff)
            goto fail;
        if (i != 3) {
            unsigned char c = *name++;

            if (c != '.')
                goto fail;
        }
        if (i == 3) {
            if (*name != 0) {
fail:
                return 0;
            }
        }
        ip = field | (ip << 8);
        i++;
    } while (i < 4);
    *pip = ip;
    return 1;
}



/*
 * sdk:      resolve_sub (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215C8B4(unsigned char *name, unsigned long dnsip, unsigned short id)
{
    unsigned long ip;

    if (dnsip == 0)
        return 0xffffffff;
    func_0215AB10();
    func_0215AA88();
    func_0215AAB0(0, 0x35, dnsip);
    ip = func_0215C538(name, 1, id, 0, 0);
    func_0215AB5C();
    return ip;
}












RandCtx CPSiRand32ctx = {0};



static inline unsigned long rand32(RandCtx *context, unsigned long max)
{
	context->x = context->mul * context->x + context->add;
	return (unsigned long)(max ? (((context->x >> 32) * max) >> 32) : (context->x >> 32));
}



/*
 * closed (2026-10-01, ov SDK wave 3 lane30): the rand context is network.o's
 *   global CPSiRand32ctx (.bss+0x78, reached through the wfailed anchor), not a
 *   field of an extern struct. Modelled as the network.o .bss statics (list from
 *   02157290; ip_conflict before wfailed so the 1-byte group keeps wfailed at
 *   +0); as a distinct object the compiler proves the x stores do not alias and
 *   schedules them as the image. CPSDnsIp is a global (vendor STB_GLOBAL) with
 *   a prior extern declaration (public header), so 1.1p1 addresses it by name
 *   (own pool word, as in the vendor reloc list) instead of via the anchor.
 *   The 4-byte group order is not the vendor's (unreferenced here).
 *
 * old blocker (resolved): three one-slot schedule swaps around the inlined
 *           rand32 (see lane notes below).
 *
 * sdk:      CPS_Resolve (libcps.TWL.HYB.a network.o)
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets): 1.1p1
 * -O4,p at 380 bytes / 24 concrete bytes is the unique best (1.6sp1/sp2 give 30).
 * Residue already named in the blocker above (the two schedule swaps in the id
 * set-up); no new spelling was spent on it this wave.
 *
 * lane U41 (2026-09-30).  Re-measured: still 380 compiled / 380 extent with 24
 * concrete bytes, three one-slot schedule swaps:
 *   +0008  image `ldr r2, [pc, #0x164]` | ours `mov r1, #0`
 *   +006c  image `orr r7, r7, fp, lsr #16` | ours `str r6, [r2, #0x78]`
 *   +007c  image `mov sl, r0` | ours `str r4, [r2, #0x7c]`
 * Eleven more spellings measured, all 24 diffs: `retries = 0;` before `ip = 0;`,
 * the two id stores first, a split id[i] pair, `ask_this` before the ids,
 * `ip = 0, retries = 0;` comma, the initialisers moved into the declarations,
 * `retries` declared `long`, `0u`, and the loop counter fixed in the `for`
 * header.  The 5/5 pool words and all 7 relocations resolve; this is the list
 * scheduler's slot tie-break, not a body shape.
 *
 * lane W8 (2026-09-30).  Two more spellings against the same three one-slot
 * swaps, both no better: computing rand32's return into a temp BEFORE the
 * context->x store (the compute-a-stores-operands-before-the-store lever) is
 * still 24 (the front end canonicalises it back); an aggregate initialiser
 * `unsigned short id[2] = { rand32(...), rand32(...) };` disables the
 * cross-call interleaving and blows up to 97.  Residue unchanged; all 7
 * relocations resolve.
 *
 * lane W8.2 (2026-10-01).  Three more spellings, all still exactly these three
 * one-slot schedule swaps at 380/24: `rand32` rewritten to compute both the
 * LCG x and the return into named temps before the `context->x` store (the
 * store-operands-first lever) stays 24; `const char *name` on the read-only
 * source parameter (the const-source-pointer tie lever) stays 24; `const` on
 * the read-only extern `g_021A82DC[2]` blows up to 384/159.  Reverted to the
 * 24-byte state.  This is the list scheduler's slot tie-break, not a body
 * shape: all 7 relocations resolve and every instruction opcode is right.
 *
 * lane W8.3 (2026-10-01).  Confirmed this is the same list-scheduler tie the
 * sibling rand32 consumer in this very overlay already documents:
 * docs/idioms/a-pool-word-order-residue-is-a-list-scheduler-tie.md
 * (ov009_func_021685CC.c, DWCi_GetMathRand32, identical 64-bit LCG rand32
 * body).  The three residue slots (+0008 context ldr above mov r1,#0; +006c
 * orr above str r6; +007c mov sl above str r4) are all independent-issue
 * hoists around the inlined rand32 epilogue, i.e. the same scheduler
 * slot tie-break the idiom says no C shape reaches.  No new spelling spent;
 * 380/24 unchanged, all 7 relocations resolve.
 * lane 05 (2026-10-01): still 380/24.  New and inert: rand32 spelled as the
 * SDK's MATH_Rand32 if/else (max == 0 ? x>>32 : ...), moving ip/retries
 * around the id draws (97 when ip follows them), a `for (server...)` id
 * loop (not unrolled, 368/large).
 */
unsigned long func_0215C910(char *name)
{
	unsigned long ip;
	int retries;
	int server;
	unsigned short id[2];
	unsigned char ask_this[2];
	unsigned long t;

	ip = 0;
	retries = 0;
	id[0] = (unsigned short)rand32(&CPSiRand32ctx, 0x10000);
	id[1] = (unsigned short)rand32(&CPSiRand32ctx, 0x10000);
	if (func_0215C814((unsigned char *)name, &ip))
		return ip;
	ask_this[0] = 1;
	ask_this[1] = 1;
	for (; retries < 3; retries++) {
		for (server = 0; server < 2; server++) {
			if (!ask_this[server])
				continue;
			if (CPSDnsIp[server] == 0 || (t = func_021578C8(CPSDnsIp[server])) == 0) {
				ask_this[server] = 0;
				continue;
			}
			if (func_02157D8C(t) == 0 && func_02157F60(t) == 0) {
				ask_this[server] = 0;
				continue;
			}
			ip = func_0215C8B4((unsigned char *)name, CPSDnsIp[server], id[server]);
			if (ip != 0 && ip != 0xffffffff)
				goto done;
			if (ip == 0xffffffff)
				ask_this[server] = 0;
		}
	}
done:
	if (ip == 0xffffffff)
		ip = 0;
	return ip;
}
