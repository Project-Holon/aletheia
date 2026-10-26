/*
 * file:     cps_network.c
 * unit:     yes
 * function: CPS_SetCheckNConfigCallback, reset_network_vars, OS_YieldThread__, empty_func, default_link_is_on, CPS_Startup, CPS_CalmDown, CPS_SetScavengerCallback, CPS_Cleanup, CPS_SetThreadPriority, calc_checksum_do, invert_checksum, calc_checksum, check_tcpudpsum, ip_islocal, get_targetip, is_broadcast, is_multicast, ip_isme, maccmp, send_packet, put_in_buffer, CPSi_RecvCallbackFunc, receive_packet, throw_packet, inq_arpcache, send_arprequest, arprequest, reg_arpcache, send_ether, send_ip_frag, send_ip, send_ping, send_udp, _send_tcp, reply_arp, dispatch_arp, reply_icmp, process_icmp_reply, valid_IP, dispatch_icmp, check_listener, check_socket, find_socket, parse_mss, no_need_inq, _tcp_send_handshake, _tcp_send_ack, _tcp_send_finack, _tcp_send_rst, dt_syn_LISTEN, find_specific_socket, dt_syn, dt_synack, mark_rwin_chunk, merge_rwin_chunks, pull_rwin_chunks, push_rwin_chunks, dt_ack, dt_fin, dt_rst, dispatch_tcp, dispatch_udp, check_frag, dispatch_ip, tcpip, CPS_SocGetEport, get_seqno, CPS_SocRegister, CPS_SocUnRegister, CPS_SocDatagramMode, CPS_SocBind, CPS_SocUse, CPS_SocRelease, CPS_SocDup, CPS_SetUdpCallback, CPSi_TcpConnectRaw, CPS_TcpConnect, CPSi_TcpShutdownRaw, CPS_TcpShutdown, CPS_TcpClose, udp_read_raw, CPSi_TcpReadRaw, CPS_SocRead, CPSi_SocConsumeRaw, CPS_SocConsume, tcp_write_do, tcp_write_do2, CPSi_TcpWrite2Raw, CPSi_SocWrite2, CPS_SocWrite, CPS_SocGetLength, CPS_SocFlush, garprequest, set_fixed_ip, scavenger, dacktimer_reschedule, dacktimer, dacktimer_alarmhandler, dhcp_setcommon, pad_mem, dhcp_send_discover, dhcp_send_request, dhcp_analyze_response, dhcp_discover_server, dhcp_request_server, dhcp_release_server, dns_skipname, resolve_common, strtol10, rawip, resolve_sub, CPS_Resolve
 * address:  0x02157280
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p -inline deferred
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged from the three unit files of network.o (0x02157280, 0x021573B8,
 * 0x021573C4; libcps.TWL.HYB.a).
 *
 * network.o was built with -inline deferred: mwccarm then emits the functions
 * in reverse definition order, so the definitions below run from the last
 * function in the image (CPS_Resolve) back to CPS_Startup. Deferred code
 * generation also registers every data object, the function-local statics
 * pingseq (send_ping) and sleep_save (dhcp_request_server) included, before
 * the first function is compiled; mwccarm heap-sorts that list by size (input
 * in reverse registration order), which gives the vendor .bss order with both
 * local statics inside the size groups. The file-scope definitions are in the
 * order that reproduces it.
 *
 * symbols:
 *   OSi_ReferSymbol                  0x02004eb0 arm
 *   OS_GetTick                       0x020870d0 arm
 *   WCM_GetMacAddress                0x021665e4 arm
 *   OS_CreateThread                  0x020853c0 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_CreateAlarm                   0x02087254 arm
 *   id_string                        0x020050ac data
 *   sCpsNetworkWfailed                          0x021a826c data
 *   empty_func                       0x021573b8 arm ov009
 *   CPSi_SslCleanup          0x02162FA4  arm  ov009
 *   OS_YieldThread           0x020858d8  arm
 *   OS_Sleep                 0x02085a38  arm
 *   default_link_is_on               0x021573bc arm ov009
 *   CPSMyMac                         0x021a82d4 data
 *   tcpip_thread                     0x021a86a4 data
 *   helper_threads_priority          0x021a1c98 data
 *   tcpip                            0x0215a900 arm ov009
 *   tcpip_stack                      0x021a9c40 data
 *   scavenger_thread                 0x021a85e4 data
 *   scavenger                        0x0215b67c arm ov009
 *   scavenger_stack                  0x021a9440 data
 *   dacktimer_alarm                  0x021a82fc data
 *   dacktimer                        0x0215bbb0 arm ov009
 *   dacktimer_thread                 0x021a8524 data
 *   dacktimer_stack                  0x021a8c40 data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsScavengerThread  0x021A85E4  data
 *   gCpsNetVars  0x021A826C  data
 *   OS_JoinThread  0x02085710  arm
 *   OS_DestroyThread  0x020855BC  arm
 *   OS_CancelAlarm  0x020873F8  arm
 *   reset_network_vars  0x02157290  arm  ov009
 *   gCpsTcpipThread  0x021A86A4  data
 *   gCpsDackTimerAlarm  0x021A82FC  data
 *   gCpsDackTimerThread  0x021A8524  data
 *   OS_SetThreadPriority             0x02085988 arm
 *   is_broadcast  0x021578EC  arm  ov009
 *   MI_CpuCopy  0x02082EA4  arm
 *   WCM_SendDCFDataEx  0x02166444  arm  ov009
 *   gCpsUdpHeaderTemplate  0x021A1CC0  data
 *   MI_CpuCopy                       0x02082ea4 arm
 *   OS_SleepThread  0x020857B0  arm
 *   OSi_ThreadInfo  0x02150FEC  data
 *   OS_GetTick  0x020870D0  arm
 *   CPSMyMac  0x021A82D4  data
 *   gCpsBroadcastMac  0x021A1CA1  data
 *   gCpsArpCache  0x021A8384  data
 *   g_021A838E  0x021A838E  data
 *   MI_CpuFill8              0x02082BCC  arm
 *   OS_Sleep  0x02085A38  arm
 *   gCpsRetryDelays  0x021A1CA8  data
 *   ip_islocal            0x02157888  arm  ov009
 *   get_targetip  0x021578C8  arm  ov009
 *   OS_DisableInterrupts     0x02087988  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   sCpsNetworkIpConflict  0x021A826D  data
 *   sCpsNetworkIpid  0x021A826E  data
 *   sCpsNetworkMymss  0x021A8270  data
 *   sCpsNetworkEport  0x021A8272  data
 *   _ZZ13func_02158524PhmP7_CPSSocE7pingseq  0x021A8274  data
 *   _ZZ13func_0215C350PmiE10sleep_save       0x021A82AC  data
 *   gCpsSendHeader     0x021A8328  data
 *   OSi_ThreadInfo                   0x02150fec data
 *   dacktimer_reschedule             0x0215bac0 arm
 *   _tcp_send_handshake              0x021593a8 arm
 *   gCpsSoc               0x021A8484  data
 *   find_socket  0x02159244  arm  ov009
 *   OS_YieldThread  0x020858D8  arm
 *   _tcp_send_ack  0x02159404  arm  ov009
 *   OS_YieldThread                   0x020858d8 arm
 *   dt_rst            0x0215A0CC  arm  ov009
 *   gCpsFragTable                       0x021a8a64 data
 *   MI_CpuFill8  0x02082BCC  arm
 *   CPSi_SslConnect  0x02162968  arm  ov009
 *   _tcp_send_finack                 0x02159494 arm
 *   CPSi_SslShutdown                 0x02162dd8 arm
 *   CPSi_SslClose  0x02162E5C  arm  ov009
 *   OS_YieldThread__  0x02157390  arm  ov009
 *   CPSi_SslRead  0x021629BC  arm  ov009
 *   MI_CpuMove               0x02083194  arm
 *   OS_Terminate             0x02088234  arm
 *   CPSi_SslConsume                  0x02162a94 arm
 *   CPSi_SocConsumeRaw               0x0215af14 arm
 *   tcp_write_do                     0x0215b09c arm
 *   tcp_write_do2                    0x0215b15c arm ov009
 *   CPSi_SslWrite2  0x02162CA0  arm  ov009
 *   MI_CpuMove  0x02083194  arm
 *   CPSi_SslGetLength  0x02162C28  arm  ov009
 *   d_021A826C     0x021A826C  data
 *   CPSi_SslPeriodical  0x02162EC4  arm  ov009
 *   gCpsRecvSoc     0x021A83E4  data
 *   gCpsRecvBuffer     0x021A88E4  data
 *   gCpsSendBuffer     0x021A8764  data
 *   OS_SetAlarm  0x0208738C  arm
 *   dacktimer_alarmhandler  0x0215BBF0  arm  ov009
 *   gCpsHostName               0x021A1CCC  data
 *   pad_mem  0x0215BD58  arm  ov009
 *   gCpsDhcpBuffer     0x021A878E  data
 *   CPS_SocConsume                    0x0215b064 arm ov009
 *   gCpsRetryCounts                       0x021a1c9c data
 *   CPSDhcpMode                      0x021a8278 data
 *   cps                              0x021a827c data
 *   OS_Sleep                         0x02085a38 arm
 *   dns_skipname                    0x0215c508 arm ov009
 *   strtol10  0x0215C7E0  arm  ov009
 *   CPSDnsIp                 0x021A82DC  data
 */
#define GAME_TYPES_U32_LONG
#include "ssl.h"
#include "cps_types.h"
typedef struct CpsArpEntry {
    unsigned long ip;
    unsigned char mac[6];
    unsigned short when;
} CpsArpEntry;

#define NET_THREAD (*(void *volatile *)&gCpsNetVars.thread)
#define BSWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define IPID gCpsNetVars.ipid
#define MYIP gCpsNetVars.myip
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SET32(p, v) (*(u16 *)(p) = HTONS((v) >> 16), *(u16 *)((p) + 2) = HTONS(v))
#define TCPDATA(p) ((p) + (((p)[12] & 0xF0u) >> 2))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define TICK() ((u32)(OS_GetTick() >> 16))
#define HI16(x) ((unsigned short)((x) >> 16))
#define LO16(x) ((unsigned short)(x))
#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))
#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))
struct CPSSoc;
#include "../sdk_math.h"

#include "../sdk_os.h"

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

typedef MATHRandContext32 RandCtx;

#include "../arm9/crt0.h"
#include "../arm9/os_tick.h"
#include "wcm_cpsif.h"
#include "../arm9/os_alarm.h"
#include "../arm9/os_system.h"
static unsigned long is_broadcast(unsigned long ip);
#include "../arm9/mi_memory.h"
static unsigned long ip_islocal(unsigned long ip);
static unsigned long get_targetip(unsigned long ip);
extern void dacktimer_reschedule(void);
void _tcp_send_handshake(CPSSoc *soc, unsigned char flag);
static CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
static void _tcp_send_ack(struct CPSSoc *soc, int flush);
static void dt_rst(unsigned char *iphdr, unsigned char *tcphdr);
extern unsigned long CPSi_SslConnect(struct CPSSoc *soc);
void _tcp_send_finack(struct CPSSoc *a);
extern void CPSi_SslShutdown(struct CPSSoc *soc);
extern unsigned char *CPSi_SslRead(unsigned long *len, struct CPSSoc *soc);
#include "../arm9/os_terminate_processor.h"
extern void CPSi_SslConsume(unsigned long len, struct CPSSoc *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct CPSSoc *soc);
extern unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct CPSSoc *soc, int need_probe);
static void tcp_write_do2(u8 *buf, u32 len, u8 *buf2, u32 len2, struct CPSSoc *soc, int need_probe);
extern unsigned long CPSi_SslWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct CPSSoc *soc);
extern long CPSi_SslGetLength(struct CPSSoc *soc);
extern void CPSi_SslPeriodical(unsigned long now);
void dacktimer_alarmhandler(void * unused0);
static unsigned char *pad_mem(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern void CPS_SocConsume(u32 len);
static u8 *dns_skipname(u8 *p);
static unsigned long strtol10(unsigned char *s, unsigned char **end);
void CPS_Startup(CPSConfig *config);
int CPS_CalmDown(void);
void CPS_SetScavengerCallback(void (*callback)(void));
void CPS_Cleanup(void);
void CPS_SetThreadPriority(unsigned long new_prio);
unsigned long calc_checksum_do(unsigned char *s, unsigned long len, unsigned long sum);
unsigned short invert_checksum(unsigned short sum);
unsigned short calc_checksum(unsigned char *s, int len);
unsigned long check_tcpudpsum(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
int is_multicast(unsigned v);
unsigned long ip_isme(unsigned long ip);
int maccmp(unsigned short *a, unsigned short *b);
void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
void put_in_buffer(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2);
void CPSi_RecvCallbackFunc(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, long size);
unsigned char *receive_packet(unsigned long *len);
void throw_packet(void);
unsigned char *inq_arpcache(unsigned long ip);
void send_arprequest(unsigned long ip);
unsigned char *arprequest(unsigned long ip);
void reg_arpcache(unsigned char (*mac)[6], unsigned long ip, int new_entry);
void send_ether(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
void send_ip_frag(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset);
void send_ip(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto);
void send_ping(unsigned char *pattern, unsigned long len, struct CPSSoc *soc);
void send_udp(unsigned char *data, unsigned long len, struct CPSSoc *soc);
u32 _send_tcp(u8 *data, u32 len, CPSSoc *soc, u8 flag);
void reply_arp(unsigned char *buf);
void dispatch_arp(unsigned char *buf, unsigned long len);
void reply_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
void process_icmp_reply(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
unsigned long valid_IP(unsigned long ip1, unsigned long ip2);
void dispatch_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
struct CPSSoc *check_listener(unsigned char *iphdr, unsigned char *tcphdr);
void parse_mss(unsigned char *tcphdr, struct CPSSoc *soc);
unsigned long no_need_inq(unsigned long ip);
void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_syn_LISTEN(unsigned char *iphdr, unsigned char *tcphdr, struct CPSSoc *soc);
unsigned long find_specific_socket(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_syn(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_synack(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void mark_rwin_chunk(struct CPSSoc *soc, long chunk);
void merge_rwin_chunks(struct CPSSoc *soc);
void pull_rwin_chunks(CPSSoc *p);
void push_rwin_chunks(CPSSoc *soc, long i);
void dt_ack(u8 *iphdr, u8 *tcphdr, u32 len);
void dt_fin(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dispatch_tcp(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dispatch_udp(u8 *iphdr, u8 *udphdr, u32 len);
u8 *check_frag(u8 *buf, u32 *fragmented);
void dispatch_ip(u8 *buf, u32 len);
void tcpip(void * unused0);
unsigned short CPS_SocGetEport(void);
unsigned long get_seqno(void);
void CPS_SocRegister(void *v);
void CPS_SocUnRegister(void);
void CPS_SocDatagramMode(void);
void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
void CPS_SocUse(void);
void CPS_SocRelease(void);
void CPS_SocDup(char *dst);
void CPS_SetUdpCallback(int (*callback)(unsigned char *, unsigned long, struct CPSSoc *));
unsigned long CPSi_TcpConnectRaw(struct CPSSoc *soc);
unsigned long CPS_TcpConnect(void);
void CPSi_TcpShutdownRaw(struct CPSSoc *soc);
void CPS_TcpShutdown(void);
void CPS_TcpClose(void);
unsigned char *udp_read_raw(unsigned long *len, struct CPSSoc *soc);
unsigned char *CPSi_TcpReadRaw(unsigned long *len, CPSSoc *soc);
unsigned char *CPS_SocRead(unsigned long *len);
u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct CPSSoc *soc);
unsigned long CPSi_SocWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);
unsigned long CPS_SocWrite(unsigned char *buf, unsigned long len);
long CPS_SocGetLength(void);
void CPS_SocFlush(void);
int garprequest(void);
void set_fixed_ip(void);
void scavenger(void * unused0);
void dacktimer(void * unused0);
unsigned char *dhcp_setcommon(unsigned char *d, int type);
unsigned long dhcp_send_discover(void);
unsigned long dhcp_send_request(int mode);
int dhcp_analyze_response(u32 id, int retry);
int dhcp_discover_server(void);
int dhcp_request_server(unsigned long *sleep, int mode);
void dhcp_release_server(void);
u32 resolve_common(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max);
unsigned long rawip(unsigned char *name, unsigned long *pip);
unsigned long resolve_sub(unsigned char *name, unsigned long dnsip, unsigned short id);
unsigned long CPS_Resolve(char *name);
extern char id_string[21];
extern struct _OSThread dacktimer_thread;
extern struct _OSThread scavenger_thread;
extern struct _OSThread tcpip_thread;
extern u8 dacktimer_stack[0x800];
extern u8 scavenger_stack[0x800];
extern u8 tcpip_stack[0x800];
extern char gCpsDackTimerAlarm[];
extern u8 gCpsUdpHeaderTemplate[];
extern unsigned char CPSMyMac[6];
extern unsigned char gCpsBroadcastMac[6];
extern CpsArpEntry gCpsArpCache[8];
extern unsigned long gCpsRetryDelays[];
extern u8 gCpsSendHeader[90];
extern struct CPSSoc gCpsSoc;
extern CPSSoc gCpsRecvSoc;
extern unsigned char gCpsRecvBuffer[384];
extern unsigned char gCpsSendBuffer[384];
extern char gCpsHostName[];
extern unsigned char gCpsDhcpBuffer[];
extern u8 gCpsRetryCounts[];






static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3;
}






static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max == 0)
        return (u32)(context->x >> 32);
    else
        return (u32)(((context->x >> 32) * max) >> 32);
}






static void empty_func(void);
#ifndef __MWERKS__
static void empty_func_dhcp_callback_pc(void)
{
}

static void *empty_func_alloc_pc(u32 size)
{
    (void)size;
    return 0;
}

static void empty_func_free_pc(void *ptr)
{
    (void)ptr;
}
#endif
static void reset_network_vars(int reason);
static void OS_YieldThread__(void);
extern void CPSi_SslCleanup(void);





static int default_link_is_on(void);





















u32 CPSGatewayIp = 0;
static int (*checkNConfig_callback)(void) = 0;
u32 CPSNetMask = 0;
static u32 wlan_getpnt = 0;
static u32 wlan_putpnt = 0;
static u32 wlan_buflen = 0;
static u32 scavenger_force_exit = 0;
static void *receiver_thread = 0;
u32 CPSMyIp = 0;
u32 CPSNoIpReason = 0;
static int (*link_is_on)(void) = 0;
void (*CPSiFree)(void *) = 0;
static u16 sCpsNetworkEport = 0;
static u8 sCpsNetworkWfailed = 0;
static u16 sCpsNetworkIpid = 0;
static u8 sCpsNetworkIpConflict = 0;
static u16 sCpsNetworkMymss = 0;
static void *scavenger_callback = 0;
static u32 offered_myip = 0;
static u32 yield_wait = 0;
static u8 *wlan_buf = 0;
u32 CPSDhcpServerIp = 0;
u32 CPSDhcpMode = 0;
void *(*CPSiAlloc)(u32) = 0;
static void (*dhcp_callback)(void) = 0;
static u32 xid = 0;
static u32 lease_time = 0;
static u32 helper_threads_priority = 0x10;
u8 CPSMyMac[6] = {0};
u32 CPSDnsIp[2] = {0};
MATHRandContext32 CPSiRand32ctx = {0};
static struct OSiAlarm dacktimer_alarm = {0};







static inline void *cur_thread(void)
{
	void *volatile t = OSi_ThreadInfo.current;
	return t;
}






static inline void put_ip(unsigned char *p, unsigned long v)
{
	*(unsigned short *)p = BSWAP16((unsigned short)(v >> 16));
	*(unsigned short *)(p + 2) = BSWAP16((unsigned short)v);
}


static inline unsigned short SWAP16(unsigned short v)
{
	return (v >> 8) | (v << 8);
}




#define GET16(p) SWAP16(*(unsigned short *)(p))




#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))









static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}








/* the ARP receive path reads the state block through its base address */
#define NV(off, type) (*(type *)((char *)&gCpsNetVars + (off)))







static inline int dhcp_denied(void)
{
    return gCpsNetVars.dhcp_callback ? gCpsNetVars.dhcp_callback() == 0 : 0;
}




static inline u16 get16(u8 *p)
{
    return (u16)((p[0] << 8) | p[1]);
}

















static inline unsigned long rand32(RandCtx *context, unsigned long max)
{
	context->x = context->mul * context->x + context->add;
	return (unsigned long)(max ? (((context->x >> 32) * max) >> 32) : (context->x >> 32));
}

static unsigned long check_socket(unsigned char *iphdr, unsigned char *tcphdr, struct CPSSoc *soc);
/*
 * closed (2026-10-01, ov SDK wave 3 lane30): the rand context is network.o's
 *   global CPSiRand32ctx (.bss+0x78, reached through the sCpsNetworkWfailed anchor), not a
 *   field of an extern struct. Modelled as the network.o .bss statics (list from
 *   02157290; sCpsNetworkIpConflict before sCpsNetworkWfailed so the 1-byte group keeps sCpsNetworkWfailed at
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
 * `unsigned short id[2] =;





/*
 * closed (2026-10-01, ov SDK wave 3 lane30): the rand context is network.o's
 *   global CPSiRand32ctx (.bss+0x78, reached through the sCpsNetworkWfailed anchor), not a
 *   field of an extern struct. Modelled as the network.o .bss statics (list from
 *   02157290; sCpsNetworkIpConflict before sCpsNetworkWfailed so the 1-byte group keeps sCpsNetworkWfailed at
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
 * the read-only extern `gCpsDnsIp[2]` blows up to 384/159.  Reverted to the
 * 24-byte state.  This is the list scheduler's slot tie-break, not a body
 * shape: all 7 relocations resolve and every instruction opcode is right.
 *
 * lane W8.3 (2026-10-01).  Confirmed this is the same list-scheduler tie the
 * sibling rand32 consumer in this very overlay already documents:
 * docs/idioms/a-pool-word-order-residue-is-a-list-scheduler-tie.md
 * (DWCi_GetMathRand32.c, DWCi_GetMathRand32, identical 64-bit LCG rand32
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
unsigned long CPS_Resolve(char *name)
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
	if (rawip((unsigned char *)name, &ip))
		return ip;
	ask_this[0] = 1;
	ask_this[1] = 1;
	for (; retries < 3; retries++) {
		for (server = 0; server < 2; server++) {
			if (!ask_this[server])
				continue;
			if (CPSDnsIp[server] == 0 || (t = get_targetip(CPSDnsIp[server])) == 0) {
				ask_this[server] = 0;
				continue;
			}
			if (inq_arpcache(t) == 0 && arprequest(t) == 0) {
				ask_this[server] = 0;
				continue;
			}
			ip = resolve_sub((unsigned char *)name, CPSDnsIp[server], id[server]);
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




/*
 * sdk:      resolve_sub (libcps.TWL.HYB.a(network.o))
 */
unsigned long resolve_sub(unsigned char *name, unsigned long dnsip, unsigned short id)
{
    unsigned long ip;

    if (dnsip == 0)
        return 0xffffffff;
    CPS_SocUse();
    CPS_SocDatagramMode();
    CPS_SocBind(0, 0x35, dnsip);
    ip = resolve_common(name, 1, id, 0, 0);
    CPS_SocRelease();
    return ip;
}




/*
 * sdk:      rawip (libcps.TWL.HYB.a(network.o))
 */
unsigned long rawip(unsigned char *name, unsigned long *pip)
{
    unsigned long ip = 0;
    int i = 0;
    unsigned long field;
    unsigned char *next;

    do {
        field = strtol10(name, &next);
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
 * sdk:      resolve_common (libcps.TWL.HYB.a network.o)
 */
u32 resolve_common(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max)
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
    CPS_SocWrite(outbuf, d + 5 - outbuf);
    start = TICK();
    while (gCpsNetVars.link_is_on() && ip == 0 && (int)(TICK() - start) < 0xf) {
        if (CPS_SocGetLength() == 0) {
            OS_Sleep(10);
            continue;
        }
        buf = CPS_SocRead(&len);
        if (len > 12 && HTONS(*(u16 *)buf) == id) {
            if ((buf[3] & 0xf) == 3) {
                ip = 0xffffffff;
            } else if ((buf[3] & 0xf) == 0) {
                end = buf + len;
                d = buf + 12;
                cnt = (u16)(buf[5] | (buf[4] << 8));
                while (cnt-- != 0)
                    d = dns_skipname(d) + 4;
                while (d < end) {
                    d = dns_skipname(d);
                    cnt = get16(d + 8);
                    if (get16(d) == type) {
                        if (type != 0xc) {
                            ip = ((u32)get16((u8 *)(d + 6 + cnt)) << 16) | get16((u8 *)((uptr)d + 8 + cnt));
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
        CPS_SocConsume(len);
    }
    return ip;
}







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






/*
 * sdk:      dhcp_release_server (libcps.TWL.HYB.a(network.o))
 */
void dhcp_release_server(void)
{
	unsigned char *buf;
	unsigned char *d;

	CPS_SocUse();
	CPS_SocDatagramMode();
	CPS_SocBind(0x44, 0x43, gCpsNetVars.dhcp_server_ip);
	buf = gCpsDhcpBuffer;
	d = dhcp_setcommon(buf, 7);
	*d++ = 0x36;
	*d++ = 4;
	*d++ = (unsigned short)(gCpsNetVars.dhcp_server_ip >> 16) >> 8;
	*d++ = gCpsNetVars.dhcp_server_ip >> 16;
	*d++ = (unsigned short)gCpsNetVars.dhcp_server_ip >> 8;
	*d++ = gCpsNetVars.dhcp_server_ip;
	*d++ = 0xff;
	d = pad_mem(0, 300, d, d - buf);
	CPS_SocWrite(buf, d - buf);
	CPS_SocRelease();
}






/*
 * sdk:      dhcp_request_server (libcps.TWL.HYB.a(network.o))
 */
int dhcp_request_server(unsigned long *sleep, int mode)
{
	static unsigned long sleep_save;
	int result;
	int retry;
	unsigned long save;

	CPS_SocUse();
	CPS_SocDatagramMode();
	if (mode == 1)
		CPS_SocBind(0x44, 0x43, CPSDhcpServerIp);
	else
		CPS_SocBind(0x44, 0x43, 0xffffffff);
	for (retry = 0; retry < 5; retry++) {
		result = dhcp_analyze_response(dhcp_send_request(mode), retry);
		if (result != 0 && result != 1)
			break;
	}
	CPS_SocRelease();
	if (result == 2) {
		*sleep = lease_time >> 1;
		sleep_save = (lease_time * 3) >> 3;
		return 1;
	}
	save = sleep_save >> 1;
	sleep_save = save;
	*sleep = save;
	switch (mode) {
	case 1:
		if (save < 0x3c) {
			*sleep = 1;
			sleep_save = lease_time >> 3;
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
 * sdk:      dhcp_discover_server (libcps.TWL.HYB.a(network.o))
 */
int dhcp_discover_server(void)
{
    int result;
    int retry;

    CPS_SocUse();
    CPS_SocDatagramMode();
    CPS_SocBind(0x44, 0x43, 0xffffffff);
    for (retry = 0; retry < 5; retry++) {
        result = dhcp_analyze_response(dhcp_send_discover(), retry);
        if (result == 1)
            break;
    }
    CPS_SocRelease();
    return result == 1;
}






















/*
 * lane04 (2026-10-01): EXACT. The old p/mode r3<->ip swap came from modelling
 *           network.o's .bss as one struct: the vendor variables are separate
 *           objects, so 1.1p1 proves the in-loop stores cannot alias
 *           CPSDhcpMode and hoists `CPSDhcpMode & 2` itself (the optimizer's
 *           temporary takes ip, the bumped s takes r3). The .bss is modelled
 *           as zero-initialised file statics laid out at the vendor offsets
 *           (mwcc sorts .bss by size; definition order below gives the vendor
 *           order), stores grouped in one struct `cps` after CPSDhcpMode. All
 *           anchor on .bss+0 = sCpsNetworkWfailed, as in the vendor. Only DWARF locals
 *           remain: the bump reads s[0xef] into `c` before `s += 0xf0`.
 *
 * sdk:      dhcp_analyze_response (libcps.TWL.HYB.a network.o)
 */
int dhcp_analyze_response(u32 id, int retry)
{
    u8 *s;
    u8 *end;
    u32 len;
    u32 start;
    int result;
    u32 myip_tmp;
    u8 c;
    long timeout;

    timeout = gCpsRetryCounts[retry] * 7;
    start = TICK();
    result = 0;
    while (link_is_on() && result == 0 && (long)(TICK() - start) < timeout) {
        if (CPS_SocGetLength() == 0) {
            OS_YieldThread__();
            continue;
        }
        s = CPS_SocRead(&len);
        if (len > 0xf0 && s[0] == 2 && NTOHL(s + 4) == id && maccmp((short unsigned int *)(s + 0x1c), (short unsigned int *)CPSMyMac) == 0) {
            myip_tmp = G32(s + 0x10);
            end = s + len;
            result = 3;
            if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 && (c = s[0xef], s += 0xf0, c == 0x63)) {
                while (s < end && (c = *s++) != 0xff) {
                    if (c == 0)
                        continue;
                    switch (c) {
                    case 1:
                        CPSNetMask = G32(s + 1);
                        break;
                    case 3:
                        CPSGatewayIp = G32(s + 1);
                        break;
                    case 6:
                        if ((CPSDhcpMode & 2) == 0) {
                            if (s[0] < 8)
                                CPSDnsIp[1] = 0;
                            else
                                CPSDnsIp[1] = G32(s + 5);
                            CPSDnsIp[0] = G32(s + 1);
                        }
                        break;
                    case 0x33:
                        lease_time = G32(s + 1);
                        break;
                    case 0x35:
                        switch (s[1]) {
                        case 2:
                            result = 1;
                            offered_myip = myip_tmp;
                            break;
                        case 5:
                            result = 2;
                            CPSMyIp = myip_tmp;
                            break;
                        }
                        break;
                    case 0x36:
                        CPSDhcpServerIp = G32(s + 1);
                        break;
                    }
                    s += *s + 1;
                }
            }
        }
        CPS_SocConsume(len);
    }
    return result;
}








/*
 * sdk:      dhcp_send_request (libcps.TWL.HYB.a network.o)
 */
unsigned long dhcp_send_request(int mode)
{
	unsigned char *buf;
	unsigned char *d;

	buf = gCpsDhcpBuffer;
	d = dhcp_setcommon(buf, 3);
	if (mode == 0) {
		d[0] = 0x32;
		d[1] = 4;
		d[2] = (unsigned char)(HI16(gCpsNetVars.offered_myip) >> 8);
		d[3] = (unsigned char)HI16(gCpsNetVars.offered_myip);
		d[4] = (unsigned char)(LO16(gCpsNetVars.offered_myip) >> 8);
		d[5] = (unsigned char)LO16(gCpsNetVars.offered_myip);
		d[6] = 0x36;
		d[7] = 4;
		d[8] = (unsigned char)(HI16(gCpsNetVars.dhcp_server_ip) >> 8);
		d[9] = (unsigned char)HI16(gCpsNetVars.dhcp_server_ip);
		d[10] = (unsigned char)(LO16(gCpsNetVars.dhcp_server_ip) >> 8);
		d[11] = (unsigned char)LO16(gCpsNetVars.dhcp_server_ip);
		d += 12;
	}
	*d++ = 0xff;
	d = pad_mem(0, 300, d, d - buf);
	CPS_SocWrite(buf, d - buf);
	return gCpsNetVars.xid;
}








/*
 * sdk:      dhcp_send_discover (libcps.TWL.HYB.a(network.o))
 */
unsigned long dhcp_send_discover(void)
{
	unsigned char *buf = gCpsDhcpBuffer;
	unsigned char *d;

	gCpsNetVars.rand_state = gCpsNetVars.rand_mult * gCpsNetVars.rand_state + gCpsNetVars.rand_inc;
	gCpsNetVars.xid = (unsigned long)(gCpsNetVars.rand_state >> 32);
	d = dhcp_setcommon(buf, 1);
	if (gCpsNetVars.offered_myip != 0) {
		*d++ = 0x32;
		*d++ = 4;
		*d++ = (unsigned short)(gCpsNetVars.offered_myip >> 16) >> 8;
		*d++ = gCpsNetVars.offered_myip >> 16;
		*d++ = (unsigned short)gCpsNetVars.offered_myip >> 8;
		*d++ = gCpsNetVars.offered_myip;
	}
	*d++ = 0xff;
	d = pad_mem(0, 300, d, d - buf);
	CPS_SocWrite(buf, d - buf);
	return gCpsNetVars.xid;
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
 * sdk:      dhcp_setcommon (libcps.TWL.HYB.a network.o)
 */
unsigned char *dhcp_setcommon(unsigned char *d, int type)
{
	MI_CpuFill8(d, 0, 0xec);
	*(unsigned short *)(d + 0) = 0x0101;
	d[2] = 6;
	*(unsigned short *)(d + 4) = SWAP16((unsigned short)(gCpsNetVars.xid >> 16));
	*(unsigned short *)(d + 6) = SWAP16((unsigned short)gCpsNetVars.xid);
	*(unsigned short *)(d + 12) = SWAP16((unsigned short)(gCpsNetVars.myip >> 16));
	*(unsigned short *)(d + 14) = SWAP16((unsigned short)gCpsNetVars.myip);
	MI_CpuCopy(CPSMyMac, d + 0x1c, 6);
	*(unsigned short *)(d + 0xec) = 0x8263;
	*(unsigned short *)(d + 0xee) = 0x6353;
	*(unsigned short *)(d + 0xf0) = 0x0135;
	d[0xf2] = (unsigned char)type;
	d[0xf3] = 0x3d;
	d[0xf4] = 7;
	d[0xf5] = 1;
	MI_CpuCopy(CPSMyMac, d + 0xf6, 6);
	d += 0xfc;
	if (type != 7) {
		d[0] = 0x0c;
		d[1] = 10;
		MI_CpuCopy(gCpsHostName, d + 2, 10);
		d[12] = 0x37;
		d[13] = 3;
		d[14] = 1;
		d[15] = 3;
		d[16] = 6;
		d += 17;
	}
	return d;
}








void dacktimer_alarmhandler(void * unused0)
{
	OS_WakeupThreadDirect(&dacktimer_thread);
}








/*
 * sdk:      dacktimer (libcps.TWL.HYB.a(network.o))
 */
void dacktimer(void * unused0)
{
    if (OS_IsThreadTerminated(&gCpsScavengerThread))
        return;
    do {
        dacktimer_reschedule();
        OS_SleepThread(0);
    } while (!OS_IsThreadTerminated(&gCpsScavengerThread));
}








/*
 * sdk:      dacktimer_reschedule (libcps.TWL.HYB.a(network.o))
 */
void dacktimer_reschedule(void)
{
	unsigned long nextdelay = 0xffffffff;
	unsigned long diff;
	struct CPSSoc *soc;
	struct _OSThread *t;
	unsigned long enabled;
	unsigned long tick;

	enabled = OS_DisableInterrupts();
	tick = (unsigned long)OS_GetTick();
	for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
		soc = t->specific[0];
		if (soc != 0 && soc->thread != 0 && soc->state == 4 && soc->ack_pending != 0) {
			diff = tick - soc->tick_acked;
			if (diff >= 0x1991b) {
				_tcp_send_ack(soc, 1);
			} else if (0x1991bULL - diff < nextdelay) {
				nextdelay = 0x1991b - diff;
			}
		}
	}
	if (nextdelay != 0xffffffff) {
		OS_CancelAlarm((struct OSiAlarm *)gCpsDackTimerAlarm);
		OS_SetAlarm((struct OSiAlarm *)gCpsDackTimerAlarm, nextdelay, dacktimer_alarmhandler, 0);
	}
	OS_RestoreInterrupts(enabled);
}







/*
 * sdk:      scavenger (libcps.TWL.HYB.a network.o, static)
 *
 * gCpsNetVars is network.o's block of file statics (first symbol sCpsNetworkWfailed);
 * the fields below are named by the offsets this function touches.
 *
 * Case 0 spells the callback test out with a flag; cases 1 and 2 use the
 * ternary helper. The object compiles the two shapes differently.
 */
void scavenger(void * unused0)
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
    gCpsNetVars.calm = 0;
    MI_CpuFill8(&gCpsRecvSoc, 0, sizeof(CPSSoc));
    gCpsRecvSoc.rcvbuf.size = sizeof(gCpsRecvBuffer);
    gCpsRecvSoc.rcvbuf.data = gCpsRecvBuffer;
    gCpsRecvSoc.sndbuf.size = sizeof(gCpsSendBuffer);
    gCpsRecvSoc.sndbuf.data = gCpsSendBuffer;
    CPS_SocRegister(&gCpsRecvSoc);
    gwcache_sleep = 1;
    dhcp_sleep = 1;
    first = 1;
    gCpsNetVars.dhcp_state = 1;

    for (;;)
    {
        OS_Sleep(1000);
        if (gCpsNetVars.calm)
            break;
        now = (unsigned long)(OS_GetTick() >> 16);

        if (gCpsNetVars.link_is_on())
        {
            if (--dhcp_sleep == 0)
            {
                if (gCpsNetVars.mode & 1)
                {
                    if (dhcp_state == 0)
                    {
                        set_fixed_ip();
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
                            gCpsNetVars.dhcp_state = 2;
                            first = 0;
                        }
                        if (!dhcp_discover_server() || !dhcp_request_server(&dhcp_sleep, 0))
                        {
                            set_fixed_ip();
                            dhcp_state = 3;
                        }
                        else
                        {
                            denied = 0;
                            if (gCpsNetVars.dhcp_callback)
                            {
                                if (gCpsNetVars.dhcp_callback() == 0)
                                    denied = 1;
                            }
                            if (denied)
                            {
                                reset_network_vars(5);
                                set_fixed_ip();
                                dhcp_state = 3;
                            }
                            else
                            {
                                dhcp_state = 1;
                                if (!garprequest())
                                {
                                    reset_network_vars(4);
                                    dhcp_state = 3;
                                }
                            }
                        }
                        break;
                    case 1:
                        if (!dhcp_request_server(&dhcp_sleep, 1) && dhcp_sleep < 60)
                        {
                            dhcp_state = 2;
                        }
                        else if (dhcp_denied())
                        {
                            reset_network_vars(5);
                            set_fixed_ip();
                            dhcp_state = 3;
                        }
                        else if (!garprequest())
                        {
                            reset_network_vars(4);
                            dhcp_state = 3;
                        }
                        break;
                    case 2:
                        if (dhcp_request_server(&dhcp_sleep, 2))
                        {
                            if (dhcp_denied())
                            {
                                reset_network_vars(5);
                                set_fixed_ip();
                                dhcp_state = 3;
                            }
                            else
                            {
                                dhcp_state = 1;
                                if (!garprequest())
                                {
                                    reset_network_vars(4);
                                    dhcp_state = 3;
                                }
                            }
                        }
                        else if (dhcp_sleep < 60)
                        {
                            reset_network_vars(3);
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
            reset_network_vars(1);
            dhcp_sleep = 1;
            dhcp_state = 0;
        }

        for (i = 0; i < 8; i++)
        {
            arp = &((CPSArpCache *)gCpsArpCache)[i];
            if (arp->ip && (short)(now - arp->when) > 957)
                arp->ip = 0;
        }

        if (gCpsNetVars.gateway_ip && --gwcache_sleep == 0)
        {
            send_arprequest(gCpsNetVars.gateway_ip);
            gwcache_sleep = 105;
        }

        for (t = OSi_ThreadInfo.list; t; t = t->next)
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
                        OS_WakeupThreadDirect(soc->thread);
                    }
                }
                else if (soc->state != 4 && soc->block_type == 2)
                {
                    soc->block_type = 0;
                    OS_WakeupThreadDirect(soc->thread);
                }
            }
        }

        for (i = 0; i < 8; i++)
        {
            CPSFragTable *f = &gCpsFragTable[i];
            if (f->count && (long)(now - f->time) > 239)
            {
                gCpsNetVars.free(f->buf);
                f->count = 0;
            }
        }

        CPSi_SslPeriodical(now);
        if (gCpsNetVars.periodic)
            gCpsNetVars.periodic();
    }

    if (!(gCpsNetVars.mode & 1) && dhcp_state != 3)
        dhcp_release_server();
    CPS_SocUnRegister();
}







/*
 * Addresses are Black-image addresses.
 */
void set_fixed_ip(void)
{
    gCpsNetVars.fixed_ip_hook();
    if (gCpsNetVars.myip == 0)
        return;
    if (garprequest() != 0)
        return;
    reset_network_vars(4);
}







/*
 * sdk:      garprequest (libcps.TWL.HYB.a(network.o))
 */
int garprequest(void)
{
    unsigned long start;

    send_arprequest(gCpsNetVars.myip);
    OS_Sleep(100);
    send_arprequest(gCpsNetVars.myip);
    start = (unsigned long)(OS_GetTick() >> 16);
    while (gCpsNetVars.link_is_on() != 0 && (int)((unsigned long)(OS_GetTick() >> 16) - start) < 0x17) {
        if (gCpsNetVars.ip_conflict != 0)
            return 0;
        OS_Sleep(100);
    }
    return 1;
}







/*
 * sdk:      CPS_SocFlush (libcps.TWL.HYB.a(network.o))
 */
void CPS_SocFlush(void)
{
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

    if (soc != 0 && soc->outbufp != 0) {
        CPSi_SocWrite2(soc->outbuf.data, soc->outbufp, 0, 0);
        soc->outbufp = 0;
    }
}







/*
 * sdk:      CPS_SocGetLength (libcps.TWL.HYB.a(network.o))
 */
long CPS_SocGetLength(void)
{
    long count;
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

    if (soc != 0) {
        if (soc->state == 4)
            _tcp_send_ack(soc, 1);
        if (soc->ssl != 0)
            return CPSi_SslGetLength(soc);
        count = soc->rcvbufp;
        if (count != 0)
            return count;
        if (soc->state == 4)
            return count;
        if (soc->state == 10 || soc->state == 11)
            return count;
        return -1;
    }
    return 0;
}







/*
 * sdk:      CPS_SocWrite (libcps.TWL.HYB.a(network.o))
 */
unsigned long CPS_SocWrite(unsigned char *buf, unsigned long len)
{
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];
    unsigned long pend;
    unsigned long n;
    unsigned long left;

    if (soc != 0) {
        pend = soc->outbufp;
        if (pend != 0) {
            n = CPSi_SocWrite2(soc->outbuf.data, pend, buf, len);
            left = soc->outbufp;
            if (n >= left) {
                soc->outbufp = 0;
                return n - left;
            }
            MI_CpuMove(soc->outbuf.data + n, soc->outbuf.data, left - n);
            soc->outbufp = soc->outbufp - n;
            return 0;
        }
        return CPSi_SocWrite2(buf, len, 0, 0);
    }
    return 0;
}







unsigned long CPSi_SocWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2)
{
	struct CPSSoc *soc;
	unsigned long total_written;

	soc = OSi_ThreadInfo.current->specific[0];
	if (soc != 0) {
		if (soc->state == 10) {
			if (len)
				send_udp(buf, len, (struct CPSSoc *)soc);
			if (len2)
				send_udp(buf2, len2, (struct CPSSoc *)soc);
			total_written = len + len2;
		} else if (soc->state == 11) {
			if (len)
				send_ping(buf, len, soc);
			if (len2)
				send_ping(buf2, len2, soc);
			total_written = len + len2;
		} else if (soc->ssl) {
			total_written = CPSi_SslWrite2(buf, len, buf2, len2, (struct CPSSoc *)soc);
		} else {
			total_written = CPSi_TcpWrite2Raw(buf, len, buf2, len2, (struct CPSSoc *)soc);
		}
		if (!gCpsNetVars.wfailed)
			return total_written;
	}
	return 0;
}









/*
 * sdk:      CPSi_TcpWrite2Raw (libcps.TWL.HYB.a network.o)
 */
u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct CPSSoc *soc)
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
    while (gCpsNetVars.link_is_on() && len != 0 && soc->state == 4 && (int)(TICK() - start_time) < 0x9f) {
        seqno = soc->seqno;
        tcp_write_do2(buf, len, buf2, len2, soc, need_probe);
        {
            u32 t = TICK();
            do {
                OS_YieldThread__();
                if (!gCpsNetVars.link_is_on())
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
                while (gCpsNetVars.link_is_on() && (int)(TICK() - t) < 0xf) {
                    OS_YieldThread__();
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









static void tcp_write_do2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct CPSSoc *soc, int need_probe)
{
	if (tcp_write_do(buf, len, soc, need_probe) != 0 && len2 != 0)
		tcp_write_do(buf2, len2, soc, 0);
}









unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct CPSSoc *soc, int need_probe)
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
		if (gCpsNetVars.mymss < thislen)
			thislen = gCpsNetVars.mymss;
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
		thislen = _send_tcp(buf, thislen, (struct CPSSoc *)soc, 0x18);
		OS_YieldThread();
		remote_win -= thislen;
		buf += thislen;
		len -= thislen;
	}
	return thislen;
}











void CPS_SocConsume(unsigned long len)
{
	struct CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslConsume(len, soc);
	else
		CPSi_SocConsumeRaw(len, soc);
}











/*
 * sdk:      CPSi_SocConsumeRaw (libcps.TWL.HYB.a network.o)
 */
void CPSi_SocConsumeRaw(unsigned long len, struct CPSSoc *soc)
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
			_tcp_send_ack((CPSSoc *)soc, 0);
	}
}











/*
 * sdk:      CPS_SocRead (libcps.TWL.HYB.a(network.o))
 */
unsigned char *CPS_SocRead(unsigned long *len)
{
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

    if (soc != 0) {
        if (soc->state == 10 || soc->state == 11)
            return udp_read_raw(len, soc);
        if (soc->ssl != 0)
            return CPSi_SslRead(len, soc);
        return CPSi_TcpReadRaw(len, soc);
    }
    *len = 0;
    return 0;
}











/*
 * sdk:      CPSi_TcpReadRaw (libcps.TWL.HYB.a(network.o))
 */
unsigned char *CPSi_TcpReadRaw(unsigned long *len, CPSSoc *soc)
{
    unsigned long enable;
    unsigned long n;

    if (soc->state == 4)
        _tcp_send_ack(soc, 1);
    if (soc->rcvbufp == 0 && soc->state == 4) {
        enable = OS_DisableInterrupts();
        while (soc->rcvbufp == 0 && soc->state == 4) {
            soc->block_type = 2;
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(enable);
    } else {
        OS_YieldThread();
    }
    n = soc->rcvbufp;
    *len = n;
    if (n != 0)
        return soc->rcvbuf.data;
    return 0;
}











/*
 * sdk:      udp_read_raw (libcps.TWL.HYB.a(network.o))
 */
unsigned char *udp_read_raw(unsigned long *len, struct CPSSoc *soc)
{
    unsigned long tmp;
    unsigned long enable = OS_DisableInterrupts();

    tmp = soc->rcvbufp;

    while (tmp == 0) {
        soc->block_type = 3;
        OS_SleepThread(0);
        tmp = soc->rcvbufp;
    }
    OS_RestoreInterrupts(enable);
    *len = tmp;
    return soc->rcvbuf.data;
}











/*
 * sdk:      CPS_TcpClose (libcps.TWL.HYB.a(network.o))
 */
void CPS_TcpClose(void)
{
    unsigned long start;
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

    if (soc == 0)
        return;
    if (soc->ssl != 0)
        CPSi_SslClose(soc);
    start = (unsigned long)(OS_GetTick() >> 16);
    while (gCpsNetVars.link_is_on() != 0 && soc->state != 0 &&
           (int)((unsigned long)(OS_GetTick() >> 16) - start) < 0x27)
        OS_YieldThread__();
    soc->state = 0;
}











void CPS_TcpShutdown(void)
{
	struct CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslShutdown(soc);
	CPSi_TcpShutdownRaw(soc);
}












void CPSi_TcpShutdownRaw(struct CPSSoc *soc)
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












/*
 * sdk:      CPS_TcpConnect (libcps.TWL.HYB.a(network.o))
 */
unsigned long CPS_TcpConnect(void)
{
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

    if (soc != 0) {
        if (soc->ssl != 0)
            return CPSi_SslConnect(soc);
        return CPSi_TcpConnectRaw(soc);
    }
    return 1;
}












/*
 * sdk:      CPSi_TcpConnectRaw (libcps.TWL.HYB.a(network.o))
 */
unsigned long CPSi_TcpConnectRaw(struct CPSSoc *soc)
{
	unsigned long retry;
	unsigned long seqno;
	unsigned long enabled;

	seqno = get_seqno();
	for (retry = 0; retry < 3; retry++) {
		soc->seqno = seqno;
		soc->state = 2;
		soc->when = (unsigned long)(OS_GetTick() >> 16);
		_tcp_send_handshake(soc, 2);
		enabled = OS_DisableInterrupts();
		if (soc->state == 2 && gCpsNetVars.myip != 0) {
			soc->block_type = 1;
			OS_SleepThread(0);
		}
		OS_RestoreInterrupts(enabled);
		if (soc->state == 4)
			return 0;
		if (gCpsNetVars.myip == 0)
			break;
	}
	return 1;
}











void CPS_SetUdpCallback(int (*callback)(unsigned char *, unsigned long, struct CPSSoc *))
{
	CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

	if (soc != 0)
		soc->udpread_callback = callback;
}











void CPS_SocDup(char *dst)
{
	((struct _OSThread *)dst)->specific[0] = OSi_ThreadInfo.current->specific[0];
}












/*
 * Clears the word the object at +0xa4 points to, when it is there.
 */
void CPS_SocRelease(void)
{
    CPSSoc *q = OSi_ThreadInfo.current->specific[0];

    if (q) {
        q->thread = 0;
    }
}












/*
 * sdk:      CPS_SocUse (libcps.TWL.HYB.a(network.o))
 */
void CPS_SocUse(void)
{
    struct _OSThread *cur = OSi_ThreadInfo.current;
    CPSSoc *soc = cur->specific[0];

    if (soc == 0)
        return;
    soc->thread = cur;
    soc->state = 0;
    soc->rcvbufp = 0;
    MI_CpuFill8(soc->chunks, 0, 0x30);
    soc->outbufp = 0;
    soc->udpread_callback = 0;
    soc->sack_enabled = 0;
}













/*
 * sdk:      CPS_SocBind (libcps.TWL.HYB.a(network.o))
 */
void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip)
{
    CPSSoc *soc = OSi_ThreadInfo.current->specific[0];

    if (soc == 0)
        return;
    if (remote_ip == 0x7f000001)
        remote_ip = gCpsNetVars.myip;
    soc->remote_port_bound = remote_port;
    soc->remote_port = soc->remote_port_bound;
    soc->remote_ip_bound = remote_ip;
    soc->remote_ip = remote_ip;
    if (local_port != 0)
        soc->local_port = local_port;
    else
        soc->local_port = CPS_SocGetEport();
}













/*
 * Puts the object at +0xa4 of the current root into mode 0xa and clears its
 * +0x50 word.
 */
void CPS_SocDatagramMode(void)
{
    CPSSoc *q = OSi_ThreadInfo.current->specific[0];

    if (q != 0) {
        q->state = 0xa;
        q->rcvbufp = 0;
    }
}













/*
 * Clears the word at +0xa4 of the block the state object holds.
 */
void CPS_SocUnRegister(void)
{
    OSi_ThreadInfo.current->specific[0] = 0;
}













/*
 * Stores a word at +0xa4 of the block held in the second word of the module state block.
 */
void CPS_SocRegister(void *v)
{
    OSi_ThreadInfo.current->specific[0] = v;
}














unsigned long get_seqno(void)
{
    gCpsNetVars.rand_state = gCpsNetVars.rand_mult * gCpsNetVars.rand_state + gCpsNetVars.rand_inc;
    return (unsigned long)(gCpsNetVars.rand_state >> 32);
}















unsigned short CPS_SocGetEport(void)
{
	unsigned long conflict;
	struct CPSSoc *soc;
	struct _OSThread *t;

	do {
		conflict = 0;
		gCpsNetVars.eport++;
		if (gCpsNetVars.eport < 0x400 || gCpsNetVars.eport >= 5000)
			gCpsNetVars.eport = 0x400;
		for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
			soc = t->specific[0];
			if (soc != 0 && soc->thread != 0 && soc->local_port == gCpsNetVars.eport) {
				conflict = 1;
				break;
			}
		}
	} while (conflict);
	return gCpsNetVars.eport;
}
















/*
 * sdk:      tcpip (libcps.TWL.HYB.a(network.o))
 */
void tcpip(void * unused0)
{
    unsigned long len;
    unsigned char *buf;

    for (;;) {
        buf = receive_packet(&len);
        if (len > 0x22) {
            unsigned short t = *(unsigned short *)(buf + 0xc);
            unsigned short type = (unsigned short)((t >> 8) | (t << 8));

            switch (type) {
            case 0x800:
                dispatch_ip(buf + 0xe, len - 0xe);
                break;
            case 0x806:
                dispatch_arp(buf + 0xe, len - 0xe);
                break;
            }
        }
        throw_packet();
    }
}
















/*
 * sdk:      dispatch_ip (libcps.TWL.HYB.a network.o)
 */
void dispatch_ip(u8 *buf, u32 len)
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
        if (ip_isme(NTOHL(buf + 0x10)) == 0)
            return;
        if (calc_checksum(buf, (buf[0] & 0xf) << 2) != 0xffff)
            return;
        if (gCpsNetVars.myip == NTOHL(buf + 0x10))
            reg_arpcache((u8 (*)[6])(buf - 8), NTOHL(buf + 0xc), 1);
    }
    buf = check_frag(buf, &fragmented);
    if (buf == 0)
        return;
    header_len = (buf[0] & 0xf) << 2;
    type = buf[9];
    data = buf + header_len;
    len = NTOHS(buf + 2) - header_len;
    if (type == 0x11) {
        dispatch_udp(buf, data, len);
    } else if (gCpsNetVars.myip != 0) {
        if (type == 1)
            dispatch_icmp(buf, data, len);
        else if (type == 6)
            dispatch_tcp(buf, data, len);
    }
    if (fragmented)
        gCpsNetVars.free(buf - 14);
}

















/*
 * sdk:      check_frag (libcps.TWL.HYB.a network.o)
 */
u8 *check_frag(u8 *buf, u32 *fragmented)
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
    p = gCpsFragTable;
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
        p->buf = gCpsNetVars.alloc(header_len + 0xe + 0x1000);
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
        gCpsNetVars.free(p->buf);
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
 * sdk:      dispatch_udp (libcps.TWL.HYB.a network.o)
 */
void dispatch_udp(u8 *iphdr, u8 *udphdr, u32 len)
{
    struct CPSSoc *soc;
    struct _OSThread *t;
    u32 enabled;

    if (len < 8)
        return;
    if (*(u16 *)(udphdr + 6) != 0 && check_tcpudpsum(udphdr, len, iphdr, 0x11) != 0)
        return;
    enabled = OS_DisableInterrupts();
    for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
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
 * sdk:      dispatch_tcp (libcps.TWL.HYB.a network.o)
 */
void dispatch_tcp(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	if (len < 20)
		return;
	if ((tcphdr[0xc] & 0xf0) < 0x50)
		return;
	if (len < ((unsigned long)(tcphdr[0xc] & 0xf0) >> 2))
		return;
	if (check_tcpudpsum(tcphdr, len, iphdr, 6) != 0)
		return;
	len -= (unsigned long)(tcphdr[0xc] & 0xf0) >> 2;
	switch (tcphdr[0xd] & 0x17) {
	case 0x02:
		if (tcphdr[0xd] & 0x28)
			return;
		dt_syn(iphdr, tcphdr, len);
		break;
	case 0x12:
		if (tcphdr[0xd] & 0x28)
			return;
		dt_synack(iphdr, tcphdr, len);
		break;
	case 0x10:
	case 0x11:
		dt_ack(iphdr, tcphdr, len);
		break;
	case 0x01:
		dt_fin(iphdr, tcphdr, len);
		break;
	default:
		if (tcphdr[0xd] & 0x04)
			dt_rst(iphdr, tcphdr);
		else
			_tcp_send_rst(iphdr, tcphdr, len);
		break;
	}
}

















static void dt_rst(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct CPSSoc *soc = find_socket(iphdr, tcphdr);

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
 * sdk:      dt_fin (libcps.TWL.HYB.a(network.o))
 */
void dt_fin(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct CPSSoc *soc;
	unsigned long enabled;

	soc = (struct CPSSoc *)find_socket(iphdr, tcphdr);
	if (soc == 0)
		return;
	enabled = OS_DisableInterrupts();
	switch (soc->state) {
	case 7:
		soc->ackno++;
		soc->state = 9;
		OS_RestoreInterrupts(enabled);
		_tcp_send_ack((CPSSoc *)soc, 2);
		break;
	case 8:
		soc->ackno++;
		OS_RestoreInterrupts(enabled);
		_tcp_send_ack((CPSSoc *)soc, 2);
		soc->state = 0;
		if (soc->block_type == 2) {
			soc->block_type = 0;
			OS_WakeupThreadDirect(soc->thread);
		}
		break;
	case 4:
		soc->ackno++;
		soc->state = 6;
		OS_RestoreInterrupts(enabled);
		_tcp_send_finack(soc);
		break;
	default:
		OS_RestoreInterrupts(enabled);
		_tcp_send_rst(iphdr, tcphdr, len);
		break;
	}
}




































#ifdef __MWERKS__
enum { CPS_SOC_CHUNKS_OFFSET = 0x70 };
#else
enum { CPS_SOC_CHUNKS_OFFSET = BW_OFFSETOF(CPSSoc, chunks) };
#endif

void dt_ack(u8 *iphdr, u8 *tcphdr, u32 len)
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
    soc = find_socket(iphdr, tcphdr);
    if (soc == 0)
    {
        _tcp_send_rst(iphdr, tcphdr, len);
        return;
    }

    remote_ackno = GET32(tcphdr + 8);
    flag = tcphdr[13];
    if ((long)(remote_ackno - soc->remote_ackno) > 0)
        soc->remote_ackno = remote_ackno;
    remote_seqno = GET32(tcphdr + 4);

    enabled = OS_DisableInterrupts();
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
                                if (((CPSSocRcvBuf *)(e + CPS_SOC_CHUNKS_OFFSET))->start == 0)
                                {
                                    MI_CpuCopy(TCPDATA(tcphdr), soc->rcvbuf.data + disconp, len);
                                    soc->chunks[ci].start = disconp;
                                    soc->chunks[ci].len = len;
                                    mark_rwin_chunk((struct CPSSoc *)soc, ci);
                                    merge_rwin_chunks((struct CPSSoc *)soc);
                                    goto done;
                                }
                                reorder_nextp = ((CPSSocRcvBuf *)(e + CPS_SOC_CHUNKS_OFFSET))->start + ((CPSSocRcvBuf *)(e + CPS_SOC_CHUNKS_OFFSET))->len;
                                if (disconp < soc->chunks[ci].start && soc->chunks[ci].start <= wend)
                                {
                                    MI_CpuCopy(TCPDATA(tcphdr), soc->rcvbuf.data + disconp, soc->chunks[ci].start - disconp);
                                    soc->chunks[ci].len += soc->chunks[ci].start - disconp;
                                    soc->chunks[ci].start = disconp;
                                    mark_rwin_chunk((struct CPSSoc *)soc, ci);
                                    merge_rwin_chunks((struct CPSSoc *)soc);
                                    goto done;
                                }
                                if (disconp <= reorder_nextp && reorder_nextp < wend)
                                {
                                    MI_CpuCopy(TCPDATA(tcphdr) + reorder_nextp - disconp, soc->rcvbuf.data + reorder_nextp, wend - reorder_nextp);
                                    soc->chunks[ci].len += wend - reorder_nextp;
                                    merge_rwin_chunks((struct CPSSoc *)soc);
                                    mark_rwin_chunk((struct CPSSoc *)soc, ci);
                                    goto done;
                                }
                                if (soc->chunks[ci].start <= disconp && wend <= reorder_nextp)
                                    goto done;
                                if (disconp >= soc->chunks[ci].start)
                                    break;
                                push_rwin_chunks(soc, ci);
                            }
                        }
                    }
                }
            }
        done:
            OS_RestoreInterrupts(enabled);
            _tcp_send_ack(soc, 2);
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
        OS_RestoreInterrupts(enabled);
        _tcp_send_rst(iphdr, tcphdr, len);
        break;
    case 3:
        soc->state = 4;
        if (soc->block_type == 1)
        {
            soc->block_type = 0;
            OS_WakeupThreadDirect(soc->thread);
        }
        if (len == 0)
        {
            OS_RestoreInterrupts(enabled);
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
                    MI_CpuCopy(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, soc->chunks[0].start - soc->rcvbufp);
                    len = soc->chunks[0].start + soc->chunks[0].len - soc->rcvbufp;
                }
                else
                {
                    MI_CpuCopy(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, len);
                }
                soc->chunks[0].start = 0;
                pull_rwin_chunks(soc);
            }
            else
            {
                MI_CpuCopy(TCPDATA(tcphdr) + dup, soc->rcvbuf.data + soc->rcvbufp, len);
            }
            soc->rcvbufp += len;
            soc->ackno += len;
            merge_rwin_chunks((struct CPSSoc *)soc);
            if (soc->block_type == 2)
            {
                soc->block_type = 0;
                OS_WakeupThreadDirect(soc->thread);
            }
        }
        if (bufok && (flag & 1))
        {
            soc->ackno++;
            soc->state = 6;
            OS_RestoreInterrupts(enabled);
            _tcp_send_finack(soc);
            if (len == 0 && soc->block_type == 2)
            {
                soc->block_type = 0;
                OS_WakeupThreadDirect(soc->thread);
            }
        }
        else
        {
            OS_RestoreInterrupts(enabled);
            if (len != 0)
                _tcp_send_ack(soc, 0);
        }
        break;
    case 7:
    case 8:
        if (flag & 1)
        {
            soc->ackno += len + 1;
            OS_RestoreInterrupts(enabled);
            _tcp_send_ack(soc, 2);
            soc->state = 0;
            if (soc->block_type == 2)
            {
                soc->block_type = 0;
                OS_WakeupThreadDirect(soc->thread);
            }
        }
        else
        {
            soc->state = 8;
            OS_RestoreInterrupts(enabled);
            if (len != 0)
            {
                soc->ackno += len;
                _tcp_send_ack(soc, 2);
            }
        }
        break;
    case 6:
    case 9:
        soc->state = 0;
        OS_RestoreInterrupts(enabled);
        if (soc->block_type == 2)
        {
            soc->block_type = 0;
            OS_WakeupThreadDirect(soc->thread);
        }
        break;
    default:
        OS_RestoreInterrupts(enabled);
        if (flag & 1)
            soc->ackno++;
        _tcp_send_ack(soc, 2);
        break;
    }
    OS_YieldThread();
}








/*
 * Shifts the 0xc-byte records above index i one slot up (each record's
 * +0x70 triple moving to +0x7c) and clears the +0x70 triple of slot i.
 */
void push_rwin_chunks(CPSSoc *soc, long i)
{
    int j;

    for (j = 2; j >= i; j--) {
        soc->chunks[j + 1] = soc->chunks[j];
    }
    soc->chunks[i].start = 0;
}








/*
 * For every one of the three 0xc-byte records whose +0x70 triple is zero,
 * pulls the +0x7c triple down into +0x70 and clears +0x7c.
 */
void pull_rwin_chunks(CPSSoc *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->chunks[i].start == 0) {
            p->chunks[i] = p->chunks[i + 1];
            p->chunks[i + 1].start = 0;
        }
    }
}








/*
 * sdk:      merge_rwin_chunks (libcps.TWL.HYB.start(network.o))
 */
void merge_rwin_chunks(struct CPSSoc *soc)
{
	long ci;

again:
	if (soc->chunks[0].start != 0 && soc->rcvbufp >= soc->chunks[0].start) {
		soc->ackno += soc->chunks[0].start + soc->chunks[0].len - soc->rcvbufp;
		soc->rcvbufp = soc->chunks[0].start + soc->chunks[0].len;
		soc->chunks[0].start = 0;
		pull_rwin_chunks(soc);
	}
	for (ci = 0; ci < 3; ci++) {
		if (soc->chunks[ci].start != 0 && soc->chunks[ci + 1].start != 0 &&
		    soc->chunks[ci].start + soc->chunks[ci].len >= soc->chunks[ci + 1].start) {
			soc->chunks[ci].len = soc->chunks[ci + 1].start + soc->chunks[ci + 1].len - soc->chunks[ci].start;
			soc->chunks[ci + 1].start = 0;
			pull_rwin_chunks(soc);
			goto again;
		}
	}
}








void mark_rwin_chunk(struct CPSSoc *soc, long chunk)
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
 * sdk:      dt_synack (libcps.TWL.HYB.start(network.o))
 */
void dt_synack(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct CPSSoc *soc;

	soc = (struct CPSSoc *)find_socket(iphdr, tcphdr);
	if (soc == 0 || soc->state != 2) {
		_tcp_send_rst(iphdr, tcphdr, len);
		return;
	}
	OS_YieldThread();
	soc->ackno = BE32(tcphdr, 4) + 1;
	soc->remote_ackno = BE32(tcphdr, 8);
	soc->remote_win = SWAP16(*(unsigned short *)(tcphdr + 0xe));
	parse_mss(tcphdr, soc);
	_tcp_send_ack(soc, 2);
	soc->state = 4;
	if (soc->block_type == 1) {
		soc->block_type = 0;
		OS_WakeupThreadDirect(soc->thread);
	}
}








/*
 * sdk:      dt_syn (libcps.TWL.HYB.start(network.o))
 */
void dt_syn(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct CPSSoc *soc;

	if (valid_IP(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	if (find_specific_socket(iphdr, tcphdr, len) != 0)
		return;
	soc = (struct CPSSoc *)check_listener(iphdr, tcphdr);
	if (soc != 0) {
		dt_syn_LISTEN(iphdr, tcphdr, soc);
		return;
	}
	OS_YieldThread();
	soc = (struct CPSSoc *)check_listener(iphdr, tcphdr);
	if (soc != 0)
		dt_syn_LISTEN(iphdr, tcphdr, soc);
}








/*
 * sdk:      find_specific_socket (libcps.TWL.HYB.a(network.o))
 */
unsigned long find_specific_socket(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
    CPSSoc *soc = find_socket(iphdr, tcphdr);

    if (soc != 0) {
        if (soc->state == 1) {
            dt_syn_LISTEN(iphdr, tcphdr, soc);
        } else if (soc->state == 3) {
            soc->seqno = soc->seqno - 1;
            dt_syn_LISTEN(iphdr, tcphdr, soc);
        } else {
            _tcp_send_rst(iphdr, tcphdr, len);
        }
        return 1;
    }
    return 0;
}








/*
 * sdk:      dt_syn_LISTEN (libcps.TWL.HYB.a(network.o))
 */
void dt_syn_LISTEN(unsigned char *iphdr, unsigned char *tcphdr, struct CPSSoc *soc)
{
	soc->state = 3;
	soc->when = (unsigned long)(OS_GetTick() >> 16);
	soc->local_ip_real = BE32(iphdr, 0x10);
	soc->remote_port = SWAP16(*(unsigned short *)tcphdr);
	soc->remote_ip = BE32(iphdr, 0xc);
	soc->ackno = BE32(tcphdr, 4) + 1;
	parse_mss(tcphdr, soc);
	_tcp_send_handshake(soc, 0x12);
}








/*
 * sdk:      _tcp_send_rst (libcps.TWL.HYB.a network.o)
 */
void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct CPSSoc *soc;

	soc = &gCpsSoc;
	MI_CpuFill8(soc, 0, sizeof(struct CPSSoc));
	soc->local_port = GET16(tcphdr + 2);
	soc->remote_port = GET16(tcphdr);
	soc->remote_ip = GET32(iphdr + 0xc);
	if (tcphdr[0xd] & 0x10) {
		soc->seqno = GET32(tcphdr + 8);
		_tcp_send_handshake(soc, 4);
		return;
	}
	soc->seqno = 0;
	soc->ackno = GET32(tcphdr + 4) + len;
	if (tcphdr[0xd] & 3)
		soc->ackno++;
	_tcp_send_handshake(soc, 0x14);
}








/*
 * Tail call that supplies the second argument 0x11.
 */
void _tcp_send_finack(struct CPSSoc *a)
{
    _tcp_send_handshake(a, 0x11);
}








static void _tcp_send_ack(struct CPSSoc *soc, int flush)
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
 * sdk:      _tcp_send_handshake (libcps.TWL.HYB.a(network.o))
 */
void _tcp_send_handshake(CPSSoc *soc, unsigned char flag)
{
    if (no_need_inq(soc->remote_ip) != 0 || OSi_ThreadInfo.current != (struct _OSThread *)&gCpsTcpipThread) {
        _send_tcp(0, 0, soc, flag);
    } else {
        send_arprequest(get_targetip(soc->remote_ip));
    }
}








/*
 * One when the test fails, else the second call.
 */
unsigned long no_need_inq(unsigned long ip)
{
    unsigned long gateway = get_targetip(ip);

    if (gateway == 0) {
        return 1;
    }

    return (uptr)inq_arpcache(gateway);
}








void parse_mss(unsigned char *tcphdr, struct CPSSoc *soc)
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








static struct CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct CPSSoc *soc;
	struct _OSThread *t;

	t = OSi_ThreadInfo.list;
	while (t != 0) {
		soc = t->specific[0];

		if (soc != 0 && *(struct _OSThread **)soc != 0) {
			if (check_socket(iphdr, tcphdr, soc) != 0)
				return soc;
		}
		t = t->next;
	}
	return 0;
}










static unsigned long check_socket(unsigned char *iphdr, unsigned char *tcphdr, struct CPSSoc *soc)
{
	return (soc->state != 0xa && soc->state != 0xb) &&
	       soc->local_port == (unsigned short)((*(unsigned short *)(tcphdr + 2) >> 8) | (*(unsigned short *)(tcphdr + 2) << 8)) &&
	       soc->remote_port == (unsigned short)((*(unsigned short *)tcphdr >> 8) | (*(unsigned short *)tcphdr << 8)) &&
	       soc->remote_ip == (((unsigned long)(unsigned short)((*(unsigned short *)(iphdr + 0xc) >> 8) | (*(unsigned short *)(iphdr + 0xc) << 8)) << 16) |
	                          (unsigned short)((*(unsigned short *)(iphdr + 0xe) >> 8) | (*(unsigned short *)(iphdr + 0xe) << 8)));
}














































/*
 * sdk:      check_listener (libcps.TWL.HYB.a network.o)
 */
struct CPSSoc *check_listener(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct CPSSoc *soc;
	struct _OSThread *t;

	for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
		soc = t->specific[0];
		if (soc != 0 && soc->thread != 0 && soc->state == 1 &&
		    soc->local_port == SWAP16(*(unsigned short *)(tcphdr + 2)) &&
		    (soc->remote_port == 0 || soc->remote_port == SWAP16(*(unsigned short *)tcphdr)) &&
		    (soc->remote_ip == 0 || soc->remote_ip == BE32(iphdr, 0xc)))
			return soc;
	}
	return 0;
}











/*
 * sdk:      dispatch_icmp (libcps.TWL.HYB.a network.o)
 */
void dispatch_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	if (len < 8)
		return;
	if (calc_checksum(icmpdata, len) != 0xffff)
		return;
	if (valid_IP(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	switch (icmpdata[0]) {
	case 0:
		process_icmp_reply(iphdr, icmpdata, len);
		break;
	case 8:
		reply_icmp(iphdr, icmpdata, len);
		break;
	}
}











unsigned long valid_IP(unsigned long ip1, unsigned long ip2)
{
    if (ip1 != 0 && !is_broadcast(ip1) && !is_multicast(ip1) &&
        ip2 != 0 && !is_broadcast(ip2) && !is_multicast(ip2))
        return 1;
    return 0;
}
























































/*
 * sdk:      process_icmp_reply (libcps.TWL.HYB.a network.o)
 */
void process_icmp_reply(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	struct CPSSoc *soc;
	struct _OSThread *t;
	unsigned long enable;

	enable = OS_DisableInterrupts();
	for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
		soc = t->specific[0];
		if (soc != 0 && soc->thread != 0 && soc->state == 0xb &&
		    *(unsigned short *)(icmpdata + 4) == (unsigned short)(uptr)soc->thread &&
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











void reply_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	unsigned long ip_reply_to = get_targetip(BE32(iphdr, 0xc));
	unsigned long sum;

	if (ip_reply_to == 0)
		return;
	if (inq_arpcache(ip_reply_to) == 0) {
		send_arprequest(ip_reply_to);
		return;
	}
	icmpdata[0] = 0;
	sum = *(unsigned short *)(icmpdata + 2) + 8;
	sum += sum >> 16;
	*(unsigned short *)(icmpdata + 2) = sum;
	send_ip(icmpdata, len, 0, 0, BE32(iphdr, 0xc), 1);
}











/*
 * The link-up test reads the address word as long: read as unsigned long it
 * is common-subexpression-merged with the later compares and the image's
 * second load of the word disappears.
 */
/*
 * sdk:      dispatch_arp (libcps.TWL.HYB.a network.o)
 */
void dispatch_arp(unsigned char *buf, unsigned long len)
{
	unsigned short op;
	unsigned long ipfrom;
	int from_me;
	int to_me;

	if (len < 0x1c)
		return;
	if (maccmp((short unsigned int *)(buf + 8), (short unsigned int *)CPSMyMac) == 0 || NV(0x50, long) == 0)
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
		reg_arpcache((unsigned char (*)[6])(buf + 8), ipfrom, to_me);
	if (op == 1 && to_me) {
		reply_arp(buf);
		return;
	}
	if (op == 2 && to_me && from_me)
		NV(1, unsigned char) = 1;
}





















/*
 * sdk:      reply_arp (libcps.TWL.HYB.a(network.o))
 */
void reply_arp(unsigned char *buf)
{
	unsigned short v;
	*(unsigned short *)(buf + 6) = 0x200;
	MI_CpuCopy(buf + 8, buf + 0x12, 10);
	MI_CpuCopy(CPSMyMac, buf + 8, 6);
	v = (unsigned short)(gCpsNetVars.myip >> 16);
	*(unsigned short *)(buf + 0xe) = (v >> 8) | (v << 8);
	v = (unsigned short)gCpsNetVars.myip;
	*(unsigned short *)(buf + 0x10) = (v >> 8) | (v << 8);
	MI_CpuCopy(buf + 0x12, buf - 0xe, 6);
	MI_CpuCopy(CPSMyMac, buf - 8, 6);
	send_packet(buf - 0xe, 0x2a, 0, 0);
}











/*
 * sdk:      _send_tcp (libcps.TWL.HYB.a network.o, static)
 *
 * gCpsSendHeader is tmpbuf (90 bytes); the object addresses tmpbuf + 0x22.
 * gCpsNetVars is network.o's block of file statics (first symbol sCpsNetworkWfailed).
 *
 * The checksum goes through a u16 local: HTONS names its operand twice, and
 * with the calls inline the checksum is computed twice and len takes the
 * callee-saved register that flag has in the object.
 */
u32 _send_tcp(u8 *data, u32 len, CPSSoc *soc, u8 flag)
{
    u8 *hdr;
    u32 this_tcp_size;
    u16 sum;

    if ((flag & 5) == 0 && soc->state == 0)
        return len;

    if (OSi_ThreadInfo.current == (struct _OSThread *)&gCpsTcpipThread)
        hdr = gCpsSendHeader + 0x22;
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
        if (mss >= gCpsNetVars.mymss)
            mss = gCpsNetVars.mymss;
        if (len > mss - 4 - sack_count * 8)
            len = (mss - 4 - sack_count * 8) & ~1;
    }
    else
    {
        this_tcp_size = 20;
    }

    SET32(hdr - 12, gCpsNetVars.myip);
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
        SET32(hdr + 20, 0x02040000u + gCpsNetVars.mymss);
        SET32(hdr + 24, 0x01010402);
    }
    if (flag & 0x10)
    {
        soc->ack_pending = 0;
        soc->tick_acked = (u32)OS_GetTick();
    }
    sum = invert_checksum(calc_checksum_do(data, len, calc_checksum_do(hdr - 12, this_tcp_size + 12, 0)));
    *(u16 *)(hdr + 16) = HTONS(sum);
    soc->seqno += len;
    if (flag & 3)
        soc->seqno++;
    send_ip(hdr, this_tcp_size, data, len, soc->remote_ip, 6);
    return len;
}










/*
 * sdk:      send_udp (libcps.TWL.HYB.a network.o)
 */
void send_udp(unsigned char *data, unsigned long len, struct CPSSoc *soc)
{
	unsigned char *hdr;

	hdr = soc->sndbuf.data + 0x22;
	*(unsigned short *)(hdr - 0xc) = swap16((unsigned short)(gCpsNetVars.myip >> 16));
	*(unsigned short *)(hdr - 0xa) = swap16((unsigned short)gCpsNetVars.myip);
	*(unsigned short *)(hdr - 0x8) = swap16((unsigned short)(soc->remote_ip >> 16));
	*(unsigned short *)(hdr - 0x6) = swap16((unsigned short)soc->remote_ip);
	*(unsigned short *)(hdr - 0x4) = 0x1100;
	*(unsigned short *)(hdr + 4) = swap16((unsigned short)(len + 8));
	*(unsigned short *)(hdr - 0x2) = *(unsigned short *)(hdr + 4);
	*(unsigned short *)(hdr + 2) = swap16(soc->remote_port);
	*(unsigned short *)(hdr + 0) = swap16(soc->local_port);
	*(unsigned short *)(hdr + 6) = 0;
	*(unsigned short *)(hdr + 6) = swap16(invert_checksum((unsigned short)calc_checksum_do(data, len, calc_checksum_do(hdr - 0xc, 0x14, 0))));
	send_ip(hdr, 8, data, len, soc->remote_ip, 0x11);
}














/*
 * u21: the defining object network.o is .comment 4.0.0.1024 -> dsi/1.1p1 and the size is already
 *      exact (180 B). The 46 concrete bytes are instruction ORDER in the prologue: the image loads
 *      both pool bases (sCpsNetworkWfailed, OSi_ThreadInfo) and the second OSi_ThreadInfo word before the
 *      first strh, 1.1p1 schedules the store first. First divergence +0018
 *      image `ldr r2, [pc, #0x90]` | ours `strh r4, [r5, #0x22]`.
 * u1: re-measured, unchanged (180 B, 46 concrete B).
 *
 * near miss (w2_s1): 46 bytes differ, schedule and register naming only: original loads the two pool bases (netvars, then OSi_ThreadInfo) before the first strh and keeps soc/icmp in r6/r5; 30+ statement orders and the chained-assignment forms tried.
 *
 * w8: recovered the vendor object's own DWARF via tools/sdkobj.py send_ping --region ov009
 *     (sdk/TwlWiFi/lib/ARM9-TS/Rom/libcps.TWL.HYB.a(network.o)). Its .debug_line gives the
 *     original statement order: 1229 icmp=soc->sndbuf.data, 1230 icmp+0x22=8, 1231 icmp+0x26=
 *     OSi_ThreadInfo[1], 1232 icmp+0x24=0, 1233 soc->local_port=seq=sCpsNetworkWfailed.ping_seq, 1234
 *     icmp+0x28/ping_seq++, 1235 checksum store, 1236 send_ip. Its .debug_info lists exactly ONE
 *     local (unsigned char *icmp) and declares sCpsNetworkWfailed as `unsigned char`, OSi_ThreadInfo as `int`.
 *     Ordering to the vendor line order flips the literal-pool emission (OSi_ThreadInfo first)
 *     because 1.1p1 materialises the first-referenced constant; the image keeps netvars first.
 *     `const` on OSi_ThreadInfo hoists its base above the first strh but also flips the pair.
 *     across the first strh (vendor hoists both bases; ours sinks the second) plus the seq home
 *     (vendor lr, ours ip). DWARF order reproduced gets the pool words right but not the schedule.
 *
 * w8 re-probed-2 (all parked at 46 B unless stated): making gCpsNetVars `const` AND storing ping_seq
 *     through a const-stripping cast does NOT let its base win the materialisation race -- still
 *     OSi first, same as OSi const alone, so the flip is not about the write. A `const unsigned
 *     long *osi = OSi_ThreadInfo` local with `(u16)osi[1]` also leaves 46 B. DWARF order plus
 *     `soc->local_port = seq = ...` chained = 55 B. Loading OSi[1] into a u16 local *ahead of* the
 *     0x22 store DOES hoist both bases with netvars first (pool pair correct) but overshoots: the
 *     netvars value load goes to the very top, 60 B. Decision: pure 1.1p1 pre-RA scheduling.
 *
 * w8 re-probed (all still 46 concrete B): `const` on OSi_ThreadInfo hoists BOTH bases above the
 *     first strh -- the schedule half of the residue -- but materialises OSi_ThreadInfo first,
 *     flipping the pool pair (netvars must stay first). const-read/const-pointer-local of either
 *     base, a named local for the loaded OSi word, and moving the netvars store earlier all fail
 *     to hoist without flipping the pair; DWARF statement order gives 56 B (OSi first, load sunk).
 *
 * lane03 (2026-10-01): network.o's symbol table has
 *     `_ZZ9send_pingPhmP7_CPSSocE7pingseq`, a FUNCTION-LOCAL `static u16 pingseq`
 *     at .bss+8 (the "sCpsNetworkWfailed" relocation is the .bss section base). As a
 *     local static whose address is never taken it cannot alias the icmp
 *     stores, so 1.1p1 hoists its load and increment above them exactly as the
 *     image does; no `seq`/`ck` stand-ins remain (DWARF: icmp only; the byte
 *     swap is a static inline, a macro would call the checksum twice).
 *     46 B -> 2 B. Residue: our .bss holds only pingseq, so it sits at +0 and
 *     the two halfword accesses use #0 where the image uses #8; the .bss
 *     relocation stays wildcarded (the vendor `.bss` route is ARM9-only).
 *     File-scope copies of the five leading statics (sCpsNetworkWfailed, sCpsNetworkIpConflict,
 *     sCpsNetworkIpid, sCpsNetworkMymss, sCpsNetworkEport) are always laid out after a function static, and
 *     file-scope or struct-member pingseq loses the no-alias hoist (184 B).
 *
 * lane17 (2026-10-01): EXACT. network.o's leading .bss statics written as
 *     zero-initialised file statics (sCpsNetworkWfailed, sCpsNetworkIpConflict, sCpsNetworkIpid, sCpsNetworkMymss,
 *     sCpsNetworkEport, declared in the order 1.1p1's size-group reshuffle lays out as
 *     +0..+6), so pingseq lands at .bss+8 as in the vendor symtab; each
 *     static named in symbols: so the .bss reloc resolves (6 agree on base).
 *
 * sdk:      send_ping (libcps.TWL.HYB.a(network.o))
 */
void send_ping(unsigned char *pattern, unsigned long len, struct CPSSoc *soc)
{
	static unsigned short pingseq;
	unsigned char *icmp;

	icmp = soc->sndbuf.data;
	*(unsigned short *)(icmp + 0x22) = 8;
	*(unsigned short *)(icmp + 0x26) = (uptr)OSi_ThreadInfo.current;
	*(unsigned short *)(icmp + 0x24) = 0;
	soc->local_port = pingseq;
	*(unsigned short *)(icmp + 0x28) = pingseq++;
	*(unsigned short *)(icmp + 0x24) = SWAP16(invert_checksum((unsigned short)calc_checksum_do(pattern, len, calc_checksum_do(icmp + 0x22, 8, 0))));
	send_ip(icmp + 0x22, 8, pattern, len, soc->remote_ip, 1);
}










/*
 * sdk:      send_ip (libcps.TWL.HYB.a network.o)
 */
void send_ip(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto)
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
            send_ip_frag(hdr, 0, bodytmp, 0x5c8, ip_to, offset | 0x2000);
            bodytmp += 0x5c8;
            hdr_len -= 0x5c8;
            offset += 0xb9;
        }
        if (hdr_len != 0) {
            if (body_len != 0)
                send_ip_frag(hdr, 0, bodytmp, hdr_len, ip_to, offset | 0x2000);
            else
                send_ip_frag(hdr, 0, bodytmp, hdr_len, ip_to, offset);
            offset += hdr_len >> 3;
            hdr_len = 0;
        }
    }
    while (hdr_len + body_len > 0x5c8) {
        this_len = 0x5c8 - hdr_len;
        send_ip_frag(hdr, hdr_len, body, this_len, ip_to, offset | 0x2000);
        body_len -= this_len;
        hdr_len = 0;
        body += this_len;
        offset += 0xb9;
    }
    if (hdr_len + body_len == 0)
        return;
    send_ip_frag(hdr, hdr_len, body, body_len, ip_to, offset);
}










/*
 * sdk:      send_ip_frag (libcps.TWL.HYB.a network.o)
 */
void send_ip_frag(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset)
{
	unsigned long enabled;

	*(unsigned short *)(hdr - 0x12) = swap16((unsigned short)(hdr_len + 0x14 + body_len));
	*(unsigned short *)(hdr - 0xe) = swap16((unsigned short)offset);
	*(unsigned short *)(hdr - 0xa) = 0;
	*(unsigned short *)(hdr - 0xa) = swap16(calc_checksum(hdr - 0x14, 0x14));
	if (ip_to != 0x7f000001 && ip_to != gCpsNetVars.myip)
		send_ether(hdr - 0x14, hdr_len + 0x14, body, body_len, ip_to, 0x800);
	if (ip_to != 0x7f000001 && ip_to != gCpsNetVars.myip && !is_multicast(ip_to))
		return;
	MI_CpuCopy(gCpsUdpHeaderTemplate, hdr - 0x1c, 8);
	enabled = OS_DisableInterrupts();
	put_in_buffer(CPSMyMac, CPSMyMac, hdr - 0x1c, hdr_len + 0x1c, body, body_len);
	OS_RestoreInterrupts(enabled);
}

















/*
 * sdk:      send_ether (libcps.TWL.HYB.a(network.o))
 */
void send_ether(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type)
{
	unsigned char *mac_to;

	*(unsigned short *)(hdr - 2) = (type >> 8) | (type << 8);
	if (!is_multicast(ip_to)) {
		ip_to = get_targetip(ip_to);
		if (ip_to == 0)
			return;
		mac_to = inq_arpcache(ip_to);
		if (mac_to == 0)
			mac_to = arprequest(ip_to);
		if (mac_to == 0)
			return;
		MI_CpuCopy(mac_to, hdr - 0xe, 6);
	} else {
		hdr[-0xe] = 1;
		hdr[-0xd] = 0;
		hdr[-0xc] = 0x5e;
		hdr[-0xb] = (ip_to >> 16) & 0x7f;
		hdr[-0xa] = ip_to >> 8;
		hdr[-9] = ip_to;
	}
	MI_CpuCopy(CPSMyMac, hdr - 8, 6);
	send_packet(hdr - 0xe, hdr_len + 0xe, body, body_len);
}

















/*
 * sdk:      reg_arpcache (libcps.TWL.HYB.a network.o)
 */
void reg_arpcache(unsigned char (*mac)[6], unsigned long ip, int new_entry)
{
	unsigned long i;
	unsigned long candidate;
	unsigned short now;
	unsigned short oldest_time;

	if (ip == 0x7f000001 || ip == gCpsNetVars.myip)
		return;
	if (!ip_islocal(ip))
		return;
	if (is_multicast(ip))
		return;
	now = (unsigned short)(OS_GetTick() >> 16);
	for (i = 0; i < 8; i++) {
		if (gCpsArpCache[i].ip == ip) {
			gCpsArpCache[i].when = now;
			MI_CpuCopy(mac, gCpsArpCache[i].mac, 6);
			return;
		}
	}
	if (!new_entry)
		return;
	oldest_time = 0;
	candidate = 0;
	for (i = 0; i < 8; i++) {
		if (gCpsArpCache[i].ip == 0) {
			candidate = i;
			break;
		}
		if ((short)(now - gCpsArpCache[i].when) > oldest_time) {
			candidate = i;
			oldest_time = now - gCpsArpCache[i].when;
		}
	}
	gCpsArpCache[candidate].ip = ip;
	MI_CpuCopy(mac, gCpsArpCache[candidate].mac, 6);
	gCpsArpCache[candidate].when = now;
}




unsigned char *arprequest(unsigned long ip)
{
    unsigned long retry1;
    unsigned long retry2;
    unsigned char *r;

    for (retry1 = 0; retry1 < 6; retry1++) {
        send_arprequest(ip);
        for (retry2 = 0; retry2 < gCpsRetryDelays[retry1] / 100; retry2++) {
            if (gCpsNetVars.myip == 0)
                return 0;
            OS_Sleep(100);
            r = inq_arpcache(ip);
            if (r != 0)
                return r;
        }
    }
    return 0;
}






/*
 * sdk:      send_arprequest (libcps.TWL.HYB.a network.o)
 */
void send_arprequest(unsigned long ip)
{
	unsigned char buf[42];

	MI_CpuFill8(buf, 0, 42);
	MI_CpuFill8(buf, 0xff, 6);
	MI_CpuCopy(CPSMyMac, buf + 6, 6);
	*(unsigned short *)(buf + 12) = 0x0608;
	buf[15] = 1;
	buf[16] = 8;
	*(unsigned short *)(buf + 18) = 0x0406;
	buf[21] = 1;
	MI_CpuCopy(CPSMyMac, buf + 22, 6);
	put_ip(buf + 28, gCpsNetVars.myip);
	put_ip(buf + 38, ip);
	send_packet(buf, 42, 0, 0);
}






/*
 * sdk:      inq_arpcache (libcps.TWL.HYB.a(network.o))
 */
unsigned char *inq_arpcache(unsigned long ip)
{
	unsigned long i;
	unsigned char (*result)[6];
	unsigned long enabled;

	enabled = OS_DisableInterrupts();
	result = 0;
	if (ip == 0x7f000001 || ip == gCpsNetVars.myip) {
		result = (unsigned char (*)[6])CPSMyMac;
	} else if (is_broadcast(ip) || is_multicast(ip)) {
		result = (unsigned char (*)[6])gCpsBroadcastMac;
	} else {
		for (i = 0; i < 8; i++) {
			if (ip == gCpsArpCache[i].ip) {
				gCpsArpCache[i].when = OS_GetTick() >> 16;
				result = &gCpsArpCache[i].mac;
				break;
			}
		}
	}
	OS_RestoreInterrupts(enabled);
	return (unsigned char *)result;
}






/*
 * sdk:      throw_packet (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void throw_packet(void)
{
    unsigned long en = OS_DisableInterrupts();

    gCpsNetVars.getpnt += *(unsigned short *)(gCpsNetVars.buf + gCpsNetVars.getpnt);
    if (gCpsNetVars.getpnt >= gCpsNetVars.bufsize)
        gCpsNetVars.getpnt = 0;
    OS_RestoreInterrupts(en);
}







/*
 * sdk:      receive_packet (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
unsigned char *receive_packet(unsigned long *len)
{
	unsigned short blocklen;
	unsigned long enable;
	unsigned char *buf;

	enable = OS_DisableInterrupts();
	while (gCpsNetVars.getpnt == gCpsNetVars.putpnt) {
		gCpsNetVars.thread = cur_thread();
		OS_SleepThread(0);
		gCpsNetVars.thread = 0;
	}
	OS_RestoreInterrupts(enable);
	buf = gCpsNetVars.buf;
	do {
		if (gCpsNetVars.bufsize - gCpsNetVars.getpnt < 2)
			gCpsNetVars.getpnt = 0;
		blocklen = *(unsigned short *)(buf + gCpsNetVars.getpnt);
		if (blocklen == 0)
			gCpsNetVars.getpnt = 0;
	} while (blocklen == 0);
	*len = blocklen - 2;
	return gCpsNetVars.buf + gCpsNetVars.getpnt + 2;
}








/*
 * sdk:      CPSi_RecvCallbackFunc (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void CPSi_RecvCallbackFunc(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, long size)
{
    put_in_buffer(srcAddr, dstAddr, buf, size, 0, 0);
    if (NET_THREAD != 0 && !OS_IsThreadTerminated((OSThread *)NET_THREAD))
        OS_WakeupThreadDirect(NET_THREAD);
}








/*
 * sdk:      put_in_buffer (libcps.TWL.HYB.a network.o)
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void put_in_buffer(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2)
{
    u32 size;
    u32 new_putpnt;
    u16 blocklen;

    if (gCpsNetVars.buf == 0 || gCpsNetVars.bufsize == 0)
        return;
    size = size1 + size2;
    if (size < 8 || size > 0x5e4)
        return;
    if (buf1[0] != gCpsUdpHeaderTemplate[0] || buf1[1] != gCpsUdpHeaderTemplate[1] || buf1[2] != gCpsUdpHeaderTemplate[2] || buf1[6] != 8)
        return;
    if (buf1[7] != 0 && buf1[7] != 6)
        return;
    blocklen = (u16)((size + 9) & ~1);
    new_putpnt = gCpsNetVars.putpnt + blocklen;
    if (gCpsNetVars.putpnt < gCpsNetVars.getpnt && gCpsNetVars.getpnt <= new_putpnt)
        return;
    if (new_putpnt == gCpsNetVars.bufsize) {
        new_putpnt = 0;
        if (gCpsNetVars.getpnt == 0)
            return;
    } else if (new_putpnt > gCpsNetVars.bufsize) {
        new_putpnt = blocklen;
        if (gCpsNetVars.getpnt <= blocklen)
            return;
    }
    if (gCpsNetVars.putpnt + blocklen > gCpsNetVars.bufsize) {
        if (gCpsNetVars.bufsize - gCpsNetVars.putpnt >= 2)
            *(u16 *)(gCpsNetVars.buf + gCpsNetVars.putpnt) = 0;
        gCpsNetVars.putpnt = 0;
    }
    *(u16 *)(gCpsNetVars.buf + gCpsNetVars.putpnt) = blocklen;
    MI_CpuCopy(dstAddr, gCpsNetVars.buf + gCpsNetVars.putpnt + 2, 6);
    MI_CpuCopy(srcAddr, gCpsNetVars.buf + gCpsNetVars.putpnt + 8, 6);
    MI_CpuCopy(buf1 + 6, gCpsNetVars.buf + gCpsNetVars.putpnt + 14, size1 - 6);
    if (buf2 != 0 && size2 != 0)
        MI_CpuCopy(buf2, gCpsNetVars.buf + gCpsNetVars.putpnt + 8 + size1, size2);
    gCpsNetVars.putpnt = new_putpnt;
}





/*
 * sdk:      send_packet (libcps.TWL.HYB.a(network.o))
 */
void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len)
{
    MI_CpuCopy(gCpsUdpHeaderTemplate, hdr + 6, 6);
    gCpsNetVars.wfailed = WCM_SendDCFDataEx(hdr, hdr + 6, hdr_len - 6, body, body_len) < 0;
}




/*
 * Compares three halfwords through advancing cursors; 1 at the first
 * mismatch, 0 when all three agree.
 */
int maccmp(unsigned short *a, unsigned short *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (*a++ != *b++) return 1;
    }
    return 0;
}






/*
 * sdk:      ip_isme (libcps.TWL.HYB.a(network.o))
 */
unsigned long ip_isme(unsigned long ip)
{
    unsigned long my = gCpsNetVars.myip;
    int d = 1;
    int c = 1;
    int b = 1;
    int a = 1;

    if (my != 0 && ip != my)
        a = 0;
    if (!a && ip != 0x7f000001)
        b = 0;
    if (!b && is_broadcast(ip) == 0)
        c = 0;
    if (!c && is_multicast(ip) == 0)
        d = 0;
    return d;
}






int is_multicast(unsigned v)
{
    return (v & 0xF0000000u) == 0xE0000000u;
}






static unsigned long is_broadcast(unsigned long ip)
{
	unsigned long result = 0;

	if (ip_islocal(ip)) {
		unsigned long mask = *(unsigned long *)((char *)&sCpsNetworkWfailed + 0x10);

		if ((~mask & ip) == ~mask)
			result = 1;
	}
	return result;
}






static unsigned long get_targetip(unsigned long ip)
{
	if (ip_islocal(ip) == 0)
		ip = *(unsigned long *)((char *)&sCpsNetworkWfailed + 0x2c);
	return ip;
}






static unsigned long ip_islocal(unsigned long ip)
{
	unsigned long result = 1;

	if (ip != 0xffffffff && ip != 0x7f000001) {
		unsigned long mask = *(unsigned long *)((char *)&sCpsNetworkWfailed + 0x10);
		unsigned long myip = *(unsigned long *)((char *)&sCpsNetworkWfailed + 0x50);

		if ((ip & mask) != (myip & mask))
			result = 0;
	}
	return result;
}






/*
 * sdk:      check_tcpudpsum (libcps.TWL.HYB.a(network.o))
 */
unsigned long check_tcpudpsum(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto)
{
    unsigned long sum = calc_checksum_do(tcpudp_hdr, len, proto);

    sum = calc_checksum_do(ip_hdr + 0xc, 8, sum);
    sum += len;
    if (sum & 0x10000)
        sum = (unsigned short)(sum + 1);
    return sum != 0xffff;
}






/*
 * The halfword the three-argument call lands on, tested.
 */
unsigned short calc_checksum(unsigned char *s, int len)
{
    return invert_checksum((unsigned short)calc_checksum_do(s, len, 0));
}






/*
 * Final step of the Internet checksum: the complement, with zero sent as 0xffff.
 */
unsigned short invert_checksum(unsigned short sum)
{
    sum ^= 0xffff;
    if (sum == 0)
        sum = 0xffff;
    return sum;
}






unsigned long calc_checksum_do(unsigned char *s, unsigned long len, unsigned long sum)
{
	int align;
	unsigned long acc;
	unsigned long word;
	unsigned long tmps;

	acc = 0;
	align = (uptr)s & 3;
	if (align != 0) {
		word = *(unsigned long *)((uptr)s & ~3);
		s = (unsigned char *)(((uptr)s & ~3) + 4);
		switch (align) {
		case 1:
			word &= 0xffffff00;
			if (len < 3) {
				len += 1;
				goto partial;
			}
			len -= 3;
			break;
		case 2:
			word &= 0xffff0000;
			if (len < 2) {
				len += 2;
				goto partial;
			}
			len -= 2;
			break;
		default:
			word &= 0xff000000;
			len -= 1;
			break;
		}
		acc = word;
	}
	while (len >= 4) {
		word = *(unsigned long *)s;
		len -= 4;
		acc += word;
		if (acc < word)
			acc++;
		s += 4;
	}
	if (len != 0) {
		word = *(unsigned long *)s;
partial:
		if (len == 1)
			word &= 0xff;
		else if (len == 2)
			word &= 0xffff;
		else
			word &= 0xffffff;
		acc += word;
		if (acc < word)
			acc++;
	}
	tmps = (acc & 0xffff) + (acc >> 16);
	tmps = (tmps & 0xffff) + (tmps >> 16);
	if ((align & 1) == 0)
		tmps = ((tmps << 8) & 0xff00) + (tmps >> 8);
	tmps += sum;
	return (tmps & 0xffff) + (tmps >> 16);
}






void CPS_SetThreadPriority(unsigned long new_prio)
{
	helper_threads_priority = new_prio;
	OS_SetThreadPriority(&tcpip_thread, new_prio);
	OS_SetThreadPriority(&scavenger_thread, new_prio);
}






/*
 * sdk:      CPS_Cleanup (libcps.TWL.HYB.a(network.o))
 */
void CPS_Cleanup(void)
{
    unsigned long enable;

    CPS_CalmDown();
    OS_JoinThread(&gCpsScavengerThread);
    OS_DestroyThread(&gCpsTcpipThread);
    OS_CancelAlarm((struct OSiAlarm *)gCpsDackTimerAlarm);
    enable = OS_DisableInterrupts();
    if (!OS_IsThreadTerminated(&gCpsDackTimerThread))
        OS_WakeupThreadDirect((struct _OSThread *)(((char *)&gCpsDackTimerThread)));
    OS_RestoreInterrupts(enable);
    OS_JoinThread(&gCpsDackTimerThread);
    gCpsNetVars.thread = 0;
    reset_network_vars(0);
    gCpsNetVars.buf = 0;
    gCpsNetVars.bufsize = 0;
}






/*
 * Stores a word at +0x34 of the module state block.
 */
void CPS_SetScavengerCallback(void (*callback)(void))
{
    gCpsNetVars.periodic = callback;
}






/*
 * sdk:      CPS_CalmDown (libcps.TWL.HYB.a(network.o))
 */
int CPS_CalmDown(void)
{
    unsigned long enable = OS_DisableInterrupts();
    int result = OS_IsThreadTerminated(&gCpsScavengerThread);

    if (result == 0 && gCpsNetVars.calm == 0) {
        gCpsNetVars.calm = 1;
        OS_WakeupThreadDirect((struct _OSThread *)(((char *)&gCpsScavengerThread)));
    }
    OS_RestoreInterrupts(enable);
    return result;
}







































































































































































/*
 * notes:    EXACT 2026-10-01 after the two network.o static leaves its pool
 *           words name (empty_func 0x021573B8, default_link_is_on 0x021573BC) were
 *           seeded in layout/function_starts.txt, added to symbols_sdk.json and
 *           matched (user-approved; SDK denominator +2 functions / +12 B).
 *
 * 2026-10-01 (w3 lane14): 160 B -> 0 concrete.  What closed it:
 *   - .debug_line of network.o (CPS_Startup at line 400): the OS_GetTick call
 *     and the merged context stores sit on line 406, the second arm of a
 *     403-406 if/else, so the seed test is `if (config->random_seed != 0)`
 *     with the OS_GetTick arm in the else.  Same shape for sCpsNetworkMymss (419-422),
 *     dhcp_callback (425-428), link_is_on (429-432): if/else, not ternaries
 *     (ternary callbacks cost 161 B).  `wlan_getpnt = 0;` (435) and
 *     `wlan_putpnt = 0;` (436) are separate statements; this is what keeps
 *     the late zero web born at +0xD0 instead of hoisted with the early one.
 *   - CPSVars was separate network.o .bss statics anchored at `sCpsNetworkWfailed`
 *     (vendor symtab); declarations below reproduce the vendor offsets under
 *     1.1p1's per-size-group reshuffle (checked with readelf on a --keep tu.o).
 *   - Stacks/threads are extern: the vendor keeps them in their own .bss
 *     sections.  aligned(32) on the stacks (lever 15) is inert here.
 *
 * sdk:      CPS_Startup (libcps.TWL.HYB.a network.o)
 */
void CPS_Startup(CPSConfig *config)
{
    OSi_ReferSymbol(id_string);
    if (config->random_seed != 0)
        MATH_InitRand32(&CPSiRand32ctx, config->random_seed);
    else
        MATH_InitRand32(&CPSiRand32ctx, OS_GetTick());
    if (config->alloc != 0 && config->free != 0) {
        CPSiAlloc = config->alloc;
        CPSiFree = config->free;
    } else {
#ifdef __MWERKS__
        CPSiAlloc = (void *(*)(u32))empty_func;
        CPSiFree = (void (*)(void *))empty_func;
#else
        CPSiAlloc = empty_func_alloc_pc;
        CPSiFree = empty_func_free_pc;
#endif
    }
    CPSDhcpMode = config->mode;
    if (config->mymss != 0)
        sCpsNetworkMymss = (u16)config->mymss;
    else
        sCpsNetworkMymss = 1460;
    offered_myip = config->requested_ip;
    yield_wait = config->yield_wait;
    if (config->dhcp_callback != 0)
        dhcp_callback = config->dhcp_callback;
    else
#ifdef __MWERKS__
        dhcp_callback = empty_func;
#else
        dhcp_callback = empty_func_dhcp_callback_pc;
#endif
    if (config->link_is_on != 0)
        link_is_on = config->link_is_on;
    else
        link_is_on = default_link_is_on;
    wlan_buf = config->lan_buf;
    wlan_buflen = config->lan_buflen;
    wlan_getpnt = 0;
    wlan_putpnt = 0;
    sCpsNetworkEport = (u16)(MATH_Rand32(&CPSiRand32ctx, 0xf88) + 0x400);
    WCM_GetMacAddress(CPSMyMac);
    sCpsNetworkIpConflict = 0;
    OS_CreateThread(&tcpip_thread, tcpip, 0, tcpip_stack + sizeof(tcpip_stack), sizeof(tcpip_stack), helper_threads_priority);
    OS_CreateThread(&scavenger_thread, scavenger, 0, scavenger_stack + sizeof(scavenger_stack), sizeof(scavenger_stack), helper_threads_priority);
    OS_WakeupThreadDirect(&tcpip_thread);
    OS_WakeupThreadDirect(&scavenger_thread);
    OS_CreateAlarm(&dacktimer_alarm);
    OS_CreateThread(&dacktimer_thread, dacktimer, 0, dacktimer_stack + sizeof(dacktimer_stack), sizeof(dacktimer_stack), helper_threads_priority - 1);
}


static int default_link_is_on(void)
{
    return 1;
}

static void empty_func(void)
{
}

static void OS_YieldThread__(void)
{
    if (yield_wait == 0)
        OS_YieldThread();
    else
        OS_Sleep(yield_wait);
}

static void reset_network_vars(int reason)
{
    OSThread *t;
    CPSSoc *soc;
    int i;
    int had_ip;

    had_ip = CPSMyIp != 0;
    CPSNoIpReason = reason;
    CPSMyIp = 0;
    CPSNetMask = 0;
    CPSGatewayIp = 0;
    CPSDnsIp[0] = 0;
    CPSDnsIp[1] = 0;
    CPSDhcpServerIp = 0;
    if (!had_ip)
        return;
    MI_CpuFill8(gCpsArpCache, 0, 0x60);
    for (t = OSi_ThreadInfo.list; t != 0; t = t->next) {
        soc = t->specific[0];
        if (soc != 0 && soc->thread != 0) {
            if (soc->state != 0xa && soc->state != 0xb)
                soc->state = 0;
            if (soc->block_type != 0) {
                soc->block_type = 0;
                OS_WakeupThreadDirect(soc->thread);
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (gCpsFragTable[i].count != 0) {
            CPSiFree(gCpsFragTable[i].buf);
            gCpsFragTable[i].count = 0;
        }
    }
    CPSi_SslCleanup();
}

void CPS_SetCheckNConfigCallback(int (*callback)(void))
{
    checkNConfig_callback = callback;
}
