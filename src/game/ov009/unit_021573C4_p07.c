/*
 * file:     unit_021573C4_p07.c
 * unit:     yes
 * function: func_0215B67C, func_0215BAC0, func_0215BBB0, func_0215BBF0, func_0215BC04, func_0215BD58, func_0215BD8C, func_0215BE80, func_0215BF88, func_0215C2F8, func_0215C350, func_0215C44C
 * address:  0x0215B67C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215AA5C  0x0215AA5C  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_020870D0  0x020870D0  arm
 *   func_0215B644  0x0215B644  arm  ov009
 *   func_02157290  0x02157290  arm  ov009
 *   func_0215B5C4  0x0215B5C4  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_02085868  0x02085868  arm
 *   func_02162EC4  0x02162EC4  arm  ov009
 *   func_0215AA70  0x0215AA70  arm  ov009
 *   g_021A83E4     0x021A83E4  data
 *   g_021A826C     0x021A826C  data
 *   g_021A88E4     0x021A88E4  data
 *   g_021A8764     0x021A8764  data
 *   g_021A8384     0x021A8384  data
 *   g_02150FEC     0x02150FEC  data
 *   g_021A8A64     0x021A8A64  data
 *   func_02087988  0x02087988  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_020873F8  0x020873F8  arm
 *   func_0208738C  0x0208738C  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A82FC     0x021A82FC  data
 *   func_0215BBF0  0x0215BBF0  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   func_020857B0  0x020857B0  arm
 *   g_021A85E4  0x021A85E4  data
 *   dacktimer_thread                 0x021a8524 data ov009
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A82D4               0x021A82D4  data
 *   g_021A1CCC               0x021A1CCC  data
 *   func_0215BD58  0x0215BD58  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   g_021A878E     0x021A878E  data
 *   OS_GetTick                       0x020870d0 arm
 *   func_0215B504                    0x0215b504 arm ov009
 *   func_02157390                    0x02157390 arm ov009
 *   func_0215AEB0                    0x0215aeb0 arm ov009
 *   func_021579BC                    0x021579bc arm ov009
 *   func_0215B064                    0x0215b064 arm ov009
 *   g_021A1C9C                       0x021a1c9c data
 *   wfailed                          0x021a826c data
 *   ip_conflict                      0x021a826d data
 *   ipid                             0x021a826e data
 *   mymss                            0x021a8270 data
 *   eport                            0x021a8272 data
 *   pingseq                          0x021a8274 data
 *   CPSDhcpMode                      0x021a8278 data
 *   cps                              0x021a827c data
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 */
#include "cps_types.h"
#include "../../matched/include/G_ArpEntry.h"
#include "../../matched/include/G_CPSFragTable.h"

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define HI16(x) ((unsigned short)((x) >> 16))
#define LO16(x) ((unsigned short)(x))
#define TICK() ((u32)(OS_GetTick() >> 16))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))
#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))
typedef struct {
    unsigned long ip;
    unsigned char mac[6];
    unsigned short when;
} CPSArpCache;

typedef struct {
    unsigned long ipfrom;
    unsigned short frags;
    unsigned short id;
    unsigned short last;
    unsigned short size;
    unsigned short from[8];
    unsigned short to[8];
    unsigned long when;
    unsigned char *ofs0;
    unsigned char *buf;
} CPSFragTable;

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

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_0215AA5C(int v);
extern void func_02085A38(unsigned long msec);
extern unsigned long long func_020870D0(void);
extern void func_0215B644(void);
extern void func_02157290(int reason);
extern int func_0215B5C4(void);
extern void func_02157E54(unsigned long ip);
extern void func_02085868(OSThread *thread);
extern void func_02162EC4(unsigned long now);
extern void func_0215AA70(void);
extern unsigned long func_02087988(void);
extern void func_02159404(struct _CPSSoc *soc, int flush);
extern void func_020873F8(void *alarm);
extern void func_0208738C(void *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern unsigned long func_0208799C(unsigned long state);
extern void func_0215BBF0(void *arg);
extern int func_0208574C(void *thread);
extern void func_020857B0(void *queue);
extern void OS_WakeupThreadDirect(void *thread);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern unsigned long long OS_GetTick(void);
extern long func_0215B504(void);
extern void func_02157390(void);
extern u8 *func_0215AEB0(u32 *len);
extern int func_021579BC(unsigned short *a, unsigned short *b);
extern void func_0215B064(u32 len);
extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern void func_0215AB5C(void);
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
extern CPSSoc g_021A83E4;
extern unsigned char g_021A88E4[384];
extern unsigned char g_021A8764[384];
extern struct ArpEntry g_021A8384[8];
extern struct CPSFragTable g_021A8A64[8];
extern unsigned char g_021A82FC[];
extern struct _OSThread dacktimer_thread;
extern unsigned char g_021A82D4[6];
extern char g_021A1CCC[];
extern unsigned char g_021A878E[];
extern u8 g_021A1C9C[];




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
            CPSFragTable *f = &((CPSFragTable *)g_021A8A64)[i];
            if (f->frags && (long)(now - f->when) > 239)
            {
                g_021A826C.free(f->buf);
                f->frags = 0;
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




static u8 ip_conflict = 0;




static u8 wfailed = 0;




static u16 eport = 0;




static u16 mymss = 0;




static u16 pingseq = 0;




static u16 ipid = 0;




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
