#ifndef GAME_OV009_CPS_NETWORK_H
#define GAME_OV009_CPS_NETWORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cps_network.c, prototypes copied from their definitions. */

struct CPSSoc;

#include "../types.h"
#include "../ov009/cps_types.h"

unsigned long CPS_Resolve(char *name);
unsigned long resolve_sub(unsigned char *name, unsigned long dnsip, unsigned short id);
unsigned long rawip(unsigned char *name, unsigned long *pip);
u32 resolve_common(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max);
void dhcp_release_server(void);
int dhcp_request_server(unsigned long *sleep, int mode);
int dhcp_discover_server(void);
int dhcp_analyze_response(u32 id, int retry);
unsigned long dhcp_send_request(int mode);
unsigned long dhcp_send_discover(void);
unsigned char *dhcp_setcommon(unsigned char *d, int type);
void dacktimer_alarmhandler(void * unused0);
void dacktimer(void * unused0);
void dacktimer_reschedule(void);
void scavenger(void * unused0);
void set_fixed_ip(void);
int garprequest(void);
void CPS_SocFlush(void);
long CPS_SocGetLength(void);
unsigned long CPS_SocWrite(unsigned char *buf, unsigned long len);
unsigned long CPSi_SocWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);
u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct CPSSoc *soc);
unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct CPSSoc *soc, int need_probe);
void CPS_SocConsume(unsigned long len);
void CPSi_SocConsumeRaw(unsigned long len, struct CPSSoc *soc);
unsigned char *CPS_SocRead(unsigned long *len);
unsigned char *CPSi_TcpReadRaw(unsigned long *len, CPSSoc *soc);
unsigned char *udp_read_raw(unsigned long *len, struct CPSSoc *soc);
void CPS_TcpClose(void);
void CPS_TcpShutdown(void);
void CPSi_TcpShutdownRaw(struct CPSSoc *soc);
unsigned long CPS_TcpConnect(void);
unsigned long CPSi_TcpConnectRaw(struct CPSSoc *soc);
void CPS_SetUdpCallback(int (*callback)(unsigned char *, unsigned long, struct CPSSoc *));
void CPS_SocDup(char *dst);
void CPS_SocRelease(void);
void CPS_SocUse(void);
void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
void CPS_SocDatagramMode(void);
void CPS_SocUnRegister(void);
void CPS_SocRegister(void *v);
unsigned long get_seqno(void);
unsigned short CPS_SocGetEport(void);
void tcpip(void * unused0);
void dispatch_ip(u8 *buf, u32 len);
u8 *check_frag(u8 *buf, u32 *fragmented);
void dispatch_udp(u8 *iphdr, u8 *udphdr, u32 len);
void dispatch_tcp(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_fin(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_ack(u8 *iphdr, u8 *tcphdr, u32 len);
void push_rwin_chunks(CPSSoc *soc, long i);
void pull_rwin_chunks(CPSSoc *p);
void merge_rwin_chunks(struct CPSSoc *soc);
void mark_rwin_chunk(struct CPSSoc *soc, long chunk);
void dt_synack(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_syn(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
unsigned long find_specific_socket(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void dt_syn_LISTEN(unsigned char *iphdr, unsigned char *tcphdr, struct CPSSoc *soc);
void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void _tcp_send_finack(struct CPSSoc *a);
void _tcp_send_handshake(CPSSoc *soc, unsigned char flag);
unsigned long no_need_inq(unsigned long ip);
void parse_mss(unsigned char *tcphdr, struct CPSSoc *soc);
struct CPSSoc *check_listener(unsigned char *iphdr, unsigned char *tcphdr);
void dispatch_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
unsigned long valid_IP(unsigned long ip1, unsigned long ip2);
void process_icmp_reply(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
void reply_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
void dispatch_arp(unsigned char *buf, unsigned long len);
void reply_arp(unsigned char *buf);
u32 _send_tcp(u8 *data, u32 len, CPSSoc *soc, u8 flag);
void send_udp(unsigned char *data, unsigned long len, struct CPSSoc *soc);
void send_ping(unsigned char *pattern, unsigned long len, struct CPSSoc *soc);
void send_ip(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto);
void send_ip_frag(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset);
void send_ether(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
unsigned char *arprequest(unsigned long ip);
void send_arprequest(unsigned long ip);
unsigned char *inq_arpcache(unsigned long ip);
void throw_packet(void);
unsigned char *receive_packet(unsigned long *len);
void CPSi_RecvCallbackFunc(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, long size);
void put_in_buffer(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2);
void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
int maccmp(unsigned short *a, unsigned short *b);
unsigned long ip_isme(unsigned long ip);
int is_multicast(unsigned v);
unsigned long check_tcpudpsum(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
unsigned short calc_checksum(unsigned char *s, int len);
unsigned short invert_checksum(unsigned short sum);
unsigned long calc_checksum_do(unsigned char *s, unsigned long len, unsigned long sum);
void CPS_SetThreadPriority(unsigned long new_prio);
void CPS_Cleanup(void);
void CPS_SetScavengerCallback(void (*callback)(void));
int CPS_CalmDown(void);
void CPS_Startup(CPSConfig *config);
void CPS_SetCheckNConfigCallback(int (*callback)(void));
/* END mkheaders: generated region */

#endif
