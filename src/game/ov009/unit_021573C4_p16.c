/*
 * file:     unit_021573C4_p16.c
 * unit:     yes
 * function: func_021593A8, func_02159404, func_02159494, func_021594A4, func_021595C0, func_021596A8
 * address:  0x021593A8
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
 *   func_0215938C  0x0215938C  arm  ov009
 *   func_02158714  0x02158714  arm  ov009
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A86A4  0x021A86A4  data
 *   OS_GetTick                       0x020870d0 arm
 *   dacktimer_reschedule             0x0215bac0 arm
 *   _tcp_send_handshake              0x021593a8 arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   g_021A8484               0x021A8484  data
 *   func_020870D0  0x020870D0  arm
 *   func_021592A8  0x021592A8  arm  ov009
 *   func_02159244  0x02159244  arm  ov009
 */
#include "../../matched/include/G_021A86A4.h"

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define GET16(p) SWAP16(*(unsigned short *)(p))
#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))
struct _CPSSoc_021593A8;
struct _CPSSoc;
typedef unsigned int   u32;

typedef unsigned char  u8;

struct _CPSSoc_021593A8 {
	unsigned char pad0[0x24];
	unsigned long ackno;
	unsigned long ackno_sent;
	unsigned long tick_acked;
	unsigned short win_sent;
	unsigned char ack_pending;
	unsigned char pad1[0x15];
	unsigned long rcvbuf;
	unsigned char pad2[4];
	unsigned long rcvbufp;
};

struct _CPSSoc_02159494 {
	unsigned char pad0[0xa];
	unsigned short local_port;      /* 0x0a */
	unsigned char padc[0xc];
	unsigned short remote_port;     /* 0x18 */
	unsigned char pad1a[2];
	unsigned long remote_ip;        /* 0x1c */
	unsigned char pad20[4];
	unsigned long ackno;            /* 0x24 */
	unsigned char pad28[0xc];
	unsigned long seqno;            /* 0x34 */
	unsigned char pad38[0x68];
};

struct _CPSSoc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char pad1[7];
	unsigned long seqno;
	unsigned long local_ip;
	unsigned short remote_port;
	unsigned char pad2[2];
	unsigned long remote_ip;
	unsigned char pad3[4];
	unsigned long ackno;
};

extern unsigned long func_0215938C(unsigned long ip);
extern u32 func_02158714(u8 *data, u32 len, struct _CPSSoc_021593A8 *soc, u8 flag);
extern unsigned long func_021578C8(unsigned long ip);
extern void func_02157E54(unsigned long ip);
extern unsigned long long OS_GetTick(void);
extern void dacktimer_reschedule(void);
extern void _tcp_send_handshake(struct _CPSSoc_021593A8 *soc, unsigned char flag);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned long long func_020870D0(void);
extern void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc);
extern char *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
void func_021593A8(char *soc, unsigned char flag);
void func_02159494(int a);
void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern char g_02150FEC[];
extern struct G_021A86A4 g_021A86A4;
extern struct _CPSSoc_02159494 g_021A8484;




/*
 * sdk:      _tcp_send_handshake (libcps.TWL.HYB.a(network.o))
 */
void func_021593A8(char *soc, unsigned char flag)
{
    if (func_0215938C(*(unsigned long *)(soc + 0x1c)) != 0 || *(char **)(g_02150FEC + 4) != ((char *)&g_021A86A4)) {
        func_02158714(0, 0, (struct _CPSSoc_021593A8 *)soc, flag);
    } else {
        func_02157E54(func_021578C8(*(unsigned long *)(soc + 0x1c)));
    }
}




static void _tcp_send_ack(struct _CPSSoc_021593A8 *soc, int flush)
{
	if (flush == 2)
		goto send;
	if (soc->ackno_sent == soc->ackno &&
	    soc->win_sent == (unsigned short)(soc->rcvbuf - soc->rcvbufp))
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
	struct _CPSSoc_02159494 *soc;

	soc = &g_021A8484;
	MI_CpuFill8(soc, 0, sizeof(struct _CPSSoc_02159494));
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
	soc->seqno = (unsigned long)(func_020870D0() >> 16);
	soc->local_ip = BE32(iphdr, 0x10);
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
    char *soc = func_02159244(iphdr, tcphdr);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 1) {
            func_021595C0(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else if (*(unsigned char *)(soc + 8) == 3) {
            *(long *)(soc + 0x34) = *(long *)(soc + 0x34) - 1;
            func_021595C0(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else {
            func_021594A4(iphdr, tcphdr, len);
        }
        return 1;
    }
    return 0;
}
