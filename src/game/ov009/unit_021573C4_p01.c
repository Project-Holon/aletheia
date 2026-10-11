/*
 * file:     unit_021573C4_p01.c
 * unit:     yes
 * function: func_021573C4, func_021575DC, func_02157630, func_02157640, func_021576C8, func_02157700, func_02157808, func_0215781C, func_02157838, func_02157888, func_021578C8, func_021578EC, func_02157928, func_0215793C, func_021579BC, func_021579E8, func_02157A44, func_02157C28, func_02157C7C, func_02157D48, func_02157D8C, func_02157E54, func_02157F60
 * address:  0x021573C4
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
 *   OSi_ReferSymbol                  0x02004eb0 arm
 *   OS_GetTick                       0x020870d0 arm
 *   WCM_GetMacAddress                0x021665e4 arm
 *   OS_CreateThread                  0x020853c0 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_CreateAlarm                   0x02087254 arm
 *   id_string                        0x020050ac data
 *   wfailed                          0x021a826c data
 *   empty_func                       0x021573b8 arm ov009
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
 *   func_02087988  0x02087988  arm
 *   func_0208574C  0x0208574C  arm
 *   func_02085868  0x02085868  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A85E4  0x021A85E4  data
 *   g_021A826C  0x021A826C  data
 *   func_02085710  0x02085710  arm
 *   func_020855BC  0x020855BC  arm
 *   func_020873F8  0x020873F8  arm
 *   func_02157290  0x02157290  arm  ov009
 *   g_021A86A4  0x021A86A4  data
 *   g_021A82FC  0x021A82FC  data
 *   g_021A8524  0x021A8524  data
 *   OS_SetThreadPriority             0x02085988 arm
 *   func_021578EC  0x021578EC  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_02166444  0x02166444  arm  ov009
 *   g_021A1CC0  0x021A1CC0  data
 *   MI_CpuCopy                       0x02082ea4 arm
 *   func_020857B0  0x020857B0  arm
 *   g_02150FEC  0x02150FEC  data
 *   func_020870D0  0x020870D0  arm
 *   g_021A82D4  0x021A82D4  data
 *   g_021A1CA1  0x021A1CA1  data
 *   g_021A8384  0x021A8384  data
 *   g_021A838E  0x021A838E  data
 *   MI_CpuFill8              0x02082BCC  arm
 *   func_02085A38  0x02085A38  arm
 *   g_021A1CA8  0x021A1CA8  data
 */
#include "cps_types.h"
#include "../../matched/include/G_ArpEntry.h"

#define NET_THREAD (*(void *volatile *)&g_021A826C.thread)
#define BSWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
typedef struct {
    u32 mode;
    void *(*alloc)(u32);
    void (*free)(void *);
    void (*dhcp_callback)(void);
    int (*link_is_on)(void);
    u64 random_seed;
    u8 *lan_buf;
    u32 lan_buflen;
    u32 mymss;
    u32 requested_ip;
    u32 yield_wait;
} CPSConfig;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

struct OSiAlarm { u8 opaque[0x2c]; };

extern void OSi_ReferSymbol(void *sym);
extern u64 OS_GetTick(void);
extern void WCM_GetMacAddress(u8 *macAddress);
extern void OS_CreateThread(struct _OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern void OS_CreateAlarm(struct OSiAlarm *alarm);
extern unsigned long func_02087988(void);
extern int func_0208574C(void *thread);
extern void func_02085868(void *thread);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02085710(void *thread);
extern void func_020855BC(void *thread);
extern void func_020873F8(void *alarm);
extern void func_02157290(int arg);
extern int OS_SetThreadPriority(void *thread, unsigned long prio);
extern unsigned long func_021578EC(unsigned long ip);
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern long func_02166444(unsigned char *dst, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern void func_020857B0(void *queue);
extern unsigned long long func_020870D0(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void func_02085A38(unsigned long msec);
void func_021573C4(CPSConfig *config);
int func_021575DC(void);
void func_02157630(int v);
void func_02157640(void);
void CPS_SetThreadPriority(unsigned long new_prio);
unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
unsigned short func_02157808(unsigned short sum);
unsigned short func_0215781C(unsigned char *s, int len);
unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
int func_02157928(unsigned v);
unsigned long func_0215793C(unsigned long ip);
int func_021579BC(unsigned short *a, unsigned short *b);
void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
void func_02157A44(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2);
void func_02157C28(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, unsigned int size);
unsigned char *func_02157C7C(unsigned long *len);
void func_02157D48(void);
unsigned char *func_02157D8C(unsigned long ip);
void func_02157E54(unsigned long ip);
unsigned char *func_02157F60(unsigned long ip);
extern char id_string[21];
extern struct _OSThread dacktimer_thread;
extern struct _OSThread scavenger_thread;
extern struct _OSThread tcpip_thread;
extern u8 dacktimer_stack[0x800];
extern u8 scavenger_stack[0x800];
extern u8 tcpip_stack[0x800];
extern char g_021A82FC[];
extern unsigned long helper_threads_priority;
extern unsigned char wfailed;
extern u8 g_021A1CC0[];
extern unsigned char g_021A82D4[6];
extern unsigned char g_021A1CA1[6];
extern struct ArpEntry g_021A8384[8];
extern unsigned long g_021A1CA8[];





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




static int default_link_is_on(void);




static void tcpip(void *arg);




static void scavenger(void *arg);




static void dacktimer(void *arg);





static u8 ip_conflict = 0;



static u8 wfailed = 0;



static u16 eport = 0;



static u16 mymss = 0;



static u16 pingseq = 0;



static u16 ipid = 0;



static u32 wlan_buflen = 0;




static u32 scavenger_force_exit = 0;




static void *receiver_thread = 0;




u32 CPSMyIp = 0;




u32 CPSDhcpServerIp = 0;




static void *checkNConfig_callback = 0;




void (*CPSiFree)(void *) = 0;




static u32 sleep_save = 0;




u32 CPSGatewayIp = 0;




static void *scavenger_callback = 0;




static u32 offered_myip = 0;




u32 CPSNoIpReason = 0;




static u32 wlan_putpnt = 0;




static void (*dhcp_callback)(void) = 0;




static u32 yield_wait = 0;




static u8 *wlan_buf = 0;




u32 CPSNetMask = 0;




static int (*link_is_on)(void) = 0;




static u32 xid = 0;




static u32 lease_time = 0;




static u32 wlan_getpnt = 0;




u32 CPSDhcpMode = 0;




void *(*CPSiAlloc)(u32) = 0;




u8 CPSMyMac[6] = {0};




u32 CPSDnsIp[2] = {0};




MATHRandContext32 CPSiRand32ctx = {0};




static struct OSiAlarm dacktimer_alarm = {0};





static u32 helper_threads_priority = 10;





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
 *     with the OS_GetTick arm in the else.  Same shape for mymss (419-422),
 *     dhcp_callback (425-428), link_is_on (429-432): if/else, not ternaries
 *     (ternary callbacks cost 161 B).  `wlan_getpnt = 0;` (435) and
 *     `wlan_putpnt = 0;` (436) are separate statements; this is what keeps
 *     the late zero web born at +0xD0 instead of hoisted with the early one.
 *   - CPSVars was separate network.o .bss statics anchored at `wfailed`
 *     (vendor symtab); declarations below reproduce the vendor offsets under
 *     1.1p1's per-size-group reshuffle (checked with readelf on a --keep tu.o).
 *   - Stacks/threads are extern: the vendor keeps them in their own .bss
 *     sections.  aligned(32) on the stacks (lever 15) is inert here.
 *
 * sdk:      CPS_Startup (libcps.TWL.HYB.a network.o)
 */
void func_021573C4(CPSConfig *config)
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
        CPSiAlloc = (void *(*)(u32))empty_func;
        CPSiFree = (void (*)(void *))empty_func;
    }
    CPSDhcpMode = config->mode;
    if (config->mymss != 0)
        mymss = (u16)config->mymss;
    else
        mymss = 1460;
    offered_myip = config->requested_ip;
    yield_wait = config->yield_wait;
    if (config->dhcp_callback != 0)
        dhcp_callback = config->dhcp_callback;
    else
        dhcp_callback = empty_func;
    if (config->link_is_on != 0)
        link_is_on = config->link_is_on;
    else
        link_is_on = default_link_is_on;
    wlan_buf = config->lan_buf;
    wlan_buflen = config->lan_buflen;
    wlan_getpnt = 0;
    wlan_putpnt = 0;
    eport = (u16)(MATH_Rand32(&CPSiRand32ctx, 0xf88) + 0x400);
    WCM_GetMacAddress(CPSMyMac);
    ip_conflict = 0;
    OS_CreateThread(&tcpip_thread, tcpip, 0, tcpip_stack + sizeof(tcpip_stack), sizeof(tcpip_stack), helper_threads_priority);
    OS_CreateThread(&scavenger_thread, scavenger, 0, scavenger_stack + sizeof(scavenger_stack), sizeof(scavenger_stack), helper_threads_priority);
    OS_WakeupThreadDirect(&tcpip_thread);
    OS_WakeupThreadDirect(&scavenger_thread);
    OS_CreateAlarm(&dacktimer_alarm);
    OS_CreateThread(&dacktimer_thread, dacktimer, 0, dacktimer_stack + sizeof(dacktimer_stack), sizeof(dacktimer_stack), helper_threads_priority - 1);
}





/*
 * sdk:      CPS_CalmDown (libcps.TWL.HYB.a(network.o))
 */
int func_021575DC(void)
{
    unsigned long enable = func_02087988();
    int result = func_0208574C(((char *)&g_021A85E4));

    if (result == 0 && g_021A826C.calm == 0) {
        g_021A826C.calm = 1;
        func_02085868(((char *)&g_021A85E4));
    }
    func_0208799C(enable);
    return result;
}





/*
 * Stores a word at +0x34 of the module state block.
 */
void func_02157630(int v)
{
    g_021A826C.periodic = (void (*)(void))v;
}





/*
 * sdk:      CPS_Cleanup (libcps.TWL.HYB.a(network.o))
 */
void func_02157640(void)
{
    unsigned long enable;

    func_021575DC();
    func_02085710(((char *)&g_021A85E4));
    func_020855BC(((char *)&g_021A86A4));
    func_020873F8(g_021A82FC);
    enable = func_02087988();
    if (!func_0208574C(((char *)&g_021A8524)))
        func_02085868(((char *)&g_021A8524));
    func_0208799C(enable);
    func_02085710(((char *)&g_021A8524));
    g_021A826C.thread = 0;
    func_02157290(0);
    g_021A826C.buf = 0;
    g_021A826C.bufsize = 0;
}





void CPS_SetThreadPriority(unsigned long new_prio)
{
	helper_threads_priority = new_prio;
	OS_SetThreadPriority(&tcpip_thread, new_prio);
	OS_SetThreadPriority(&scavenger_thread, new_prio);
}





unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum)
{
	int align;
	unsigned long tmp;
	unsigned long tmp2;
	unsigned long tmps;

	tmp = 0;
	align = (unsigned long)s & 3;
	if (align != 0) {
		tmp2 = *(unsigned long *)((unsigned long)s & ~3);
		s = (unsigned char *)(((unsigned long)s & ~3) + 4);
		switch (align) {
		case 1:
			tmp2 &= 0xffffff00;
			if (len < 3) {
				len += 1;
				goto partial;
			}
			len -= 3;
			break;
		case 2:
			tmp2 &= 0xffff0000;
			if (len < 2) {
				len += 2;
				goto partial;
			}
			len -= 2;
			break;
		default:
			tmp2 &= 0xff000000;
			len -= 1;
			break;
		}
		tmp = tmp2;
	}
	while (len >= 4) {
		tmp2 = *(unsigned long *)s;
		len -= 4;
		tmp += tmp2;
		if (tmp < tmp2)
			tmp++;
		s += 4;
	}
	if (len != 0) {
		tmp2 = *(unsigned long *)s;
partial:
		if (len == 1)
			tmp2 &= 0xff;
		else if (len == 2)
			tmp2 &= 0xffff;
		else
			tmp2 &= 0xffffff;
		tmp += tmp2;
		if (tmp < tmp2)
			tmp++;
	}
	tmps = (tmp & 0xffff) + (tmp >> 16);
	tmps = (tmps & 0xffff) + (tmps >> 16);
	if ((align & 1) == 0)
		tmps = ((tmps << 8) & 0xff00) + (tmps >> 8);
	tmps += sum;
	return (tmps & 0xffff) + (tmps >> 16);
}





/*
 * Final step of the Internet checksum: the complement, with zero sent as 0xffff.
 */
unsigned short func_02157808(unsigned short sum)
{
    sum ^= 0xffff;
    if (sum == 0)
        sum = 0xffff;
    return sum;
}





/*
 * The halfword the three-argument call lands on, tested.
 */
unsigned short func_0215781C(unsigned char *s, int len)
{
    return func_02157808((unsigned short)func_02157700(s, len, 0));
}





/*
 * sdk:      check_tcpudpsum (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto)
{
    unsigned long sum = func_02157700(tcpudp_hdr, len, proto);

    sum = func_02157700(ip_hdr + 0xc, 8, sum);
    sum += len;
    if (sum & 0x10000)
        sum = (unsigned short)(sum + 1);
    return sum != 0xffff;
}





static unsigned long ip_islocal(unsigned long ip)
{
	unsigned long result = 1;

	if (ip != 0xffffffff && ip != 0x7f000001) {
		unsigned long mask = *(unsigned long *)((char *)&wfailed + 0x10);
		unsigned long myip = *(unsigned long *)((char *)&wfailed + 0x50);

		if ((ip & mask) != (myip & mask))
			result = 0;
	}
	return result;
}





static unsigned long get_targetip(unsigned long ip)
{
	if (ip_islocal(ip) == 0)
		ip = *(unsigned long *)((char *)&wfailed + 0x2c);
	return ip;
}





static unsigned long is_broadcast(unsigned long ip)
{
	unsigned long result = 0;

	if (ip_islocal(ip)) {
		unsigned long mask = *(unsigned long *)((char *)&wfailed + 0x10);

		if ((~mask & ip) == ~mask)
			result = 1;
	}
	return result;
}





int func_02157928(unsigned v)
{
    return (v & 0xF0000000u) == 0xE0000000u;
}





/*
 * sdk:      ip_isme (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215793C(unsigned long ip)
{
    unsigned long my = g_021A826C.myip;
    int d = 1;
    int c = 1;
    int b = 1;
    int a = 1;

    if (my != 0 && ip != my)
        a = 0;
    if (!a && ip != 0x7f000001)
        b = 0;
    if (!b && func_021578EC(ip) == 0)
        c = 0;
    if (!c && func_02157928(ip) == 0)
        d = 0;
    return d;
}



/*
 * Compares three halfwords through advancing cursors; 1 at the first
 * mismatch, 0 when all three agree.
 */
int func_021579BC(unsigned short *a, unsigned short *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (*a++ != *b++) return 1;
    }
    return 0;
}




/*
 * sdk:      send_packet (libcps.TWL.HYB.a(network.o))
 */
void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len)
{
    func_02082EA4(g_021A1CC0, hdr + 6, 6);
    g_021A826C.wfailed = func_02166444(hdr, hdr + 6, hdr_len - 6, body, body_len) < 0;
}







/*
 * sdk:      put_in_buffer (libcps.TWL.HYB.a network.o)
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02157A44(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2)
{
    u32 size;
    u32 new_putpnt;
    u16 blocklen;

    if (g_021A826C.buf == 0 || g_021A826C.bufsize == 0)
        return;
    size = size1 + size2;
    if (size < 8 || size > 0x5e4)
        return;
    if (buf1[0] != g_021A1CC0[0] || buf1[1] != g_021A1CC0[1] || buf1[2] != g_021A1CC0[2] || buf1[6] != 8)
        return;
    if (buf1[7] != 0 && buf1[7] != 6)
        return;
    blocklen = (u16)((size + 9) & ~1);
    new_putpnt = g_021A826C.putpnt + blocklen;
    if (g_021A826C.putpnt < g_021A826C.getpnt && g_021A826C.getpnt <= new_putpnt)
        return;
    if (new_putpnt == g_021A826C.bufsize) {
        new_putpnt = 0;
        if (g_021A826C.getpnt == 0)
            return;
    } else if (new_putpnt > g_021A826C.bufsize) {
        new_putpnt = blocklen;
        if (g_021A826C.getpnt <= blocklen)
            return;
    }
    if (g_021A826C.putpnt + blocklen > g_021A826C.bufsize) {
        if (g_021A826C.bufsize - g_021A826C.putpnt >= 2)
            *(u16 *)(g_021A826C.buf + g_021A826C.putpnt) = 0;
        g_021A826C.putpnt = 0;
    }
    *(u16 *)(g_021A826C.buf + g_021A826C.putpnt) = blocklen;
    MI_CpuCopy(dstAddr, g_021A826C.buf + g_021A826C.putpnt + 2, 6);
    MI_CpuCopy(srcAddr, g_021A826C.buf + g_021A826C.putpnt + 8, 6);
    MI_CpuCopy(buf1 + 6, g_021A826C.buf + g_021A826C.putpnt + 14, size1 - 6);
    if (buf2 != 0 && size2 != 0)
        MI_CpuCopy(buf2, g_021A826C.buf + g_021A826C.putpnt + 8 + size1, size2);
    g_021A826C.putpnt = new_putpnt;
}







/*
 * sdk:      CPSi_RecvCallbackFunc (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02157C28(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, unsigned int size)
{
    func_02157A44(srcAddr, dstAddr, buf, size, 0, 0);
    if (NET_THREAD != 0 && !func_0208574C(NET_THREAD))
        func_02085868(NET_THREAD);
}






static inline void *cur_thread(void)
{
	void *volatile t = g_02150FEC.current;
	return t;
}






/*
 * sdk:      receive_packet (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
unsigned char *func_02157C7C(unsigned long *len)
{
	unsigned short blocklen;
	unsigned long enable;
	unsigned char *buf;

	enable = func_02087988();
	while (g_021A826C.getpnt == g_021A826C.putpnt) {
		g_021A826C.thread = cur_thread();
		func_020857B0(0);
		g_021A826C.thread = 0;
	}
	func_0208799C(enable);
	buf = g_021A826C.buf;
	do {
		if (g_021A826C.bufsize - g_021A826C.getpnt < 2)
			g_021A826C.getpnt = 0;
		blocklen = *(unsigned short *)(buf + g_021A826C.getpnt);
		if (blocklen == 0)
			g_021A826C.getpnt = 0;
	} while (blocklen == 0);
	*len = blocklen - 2;
	return g_021A826C.buf + g_021A826C.getpnt + 2;
}





/*
 * sdk:      throw_packet (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02157D48(void)
{
    unsigned long en = func_02087988();

    g_021A826C.getpnt += *(unsigned short *)(g_021A826C.buf + g_021A826C.getpnt);
    if (g_021A826C.getpnt >= g_021A826C.bufsize)
        g_021A826C.getpnt = 0;
    func_0208799C(en);
}





/*
 * sdk:      inq_arpcache (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_02157D8C(unsigned long ip)
{
	unsigned long i;
	unsigned char (*result)[6];
	unsigned long enabled;

	enabled = func_02087988();
	result = 0;
	if (ip == 0x7f000001 || ip == g_021A826C.myip) {
		result = (unsigned char (*)[6])g_021A82D4;
	} else if (func_021578EC(ip) || func_02157928(ip)) {
		result = (unsigned char (*)[6])g_021A1CA1;
	} else {
		for (i = 0; i < 8; i++) {
			if (ip == g_021A8384[i].ip) {
				g_021A8384[i].when = func_020870D0() >> 16;
				result = &g_021A8384[i].mac;
				break;
			}
		}
	}
	func_0208799C(enabled);
	return (unsigned char *)result;
}





static inline void put_ip(unsigned char *p, unsigned long v)
{
	*(unsigned short *)p = BSWAP16((unsigned short)(v >> 16));
	*(unsigned short *)(p + 2) = BSWAP16((unsigned short)v);
}





/*
 * sdk:      send_arprequest (libcps.TWL.HYB.a network.o)
 */
void func_02157E54(unsigned long ip)
{
	unsigned char buf[42];

	MI_CpuFill8(buf, 0, 42);
	MI_CpuFill8(buf, 0xff, 6);
	MI_CpuCopy(g_021A82D4, buf + 6, 6);
	*(unsigned short *)(buf + 12) = 0x0608;
	buf[15] = 1;
	buf[16] = 8;
	*(unsigned short *)(buf + 18) = 0x0406;
	buf[21] = 1;
	MI_CpuCopy(g_021A82D4, buf + 22, 6);
	put_ip(buf + 28, g_021A826C.myip);
	put_ip(buf + 38, ip);
	func_021579E8(buf, 42, 0, 0);
}



unsigned char *func_02157F60(unsigned long ip)
{
    unsigned long retry1;
    unsigned long retry2;
    unsigned char *r;

    for (retry1 = 0; retry1 < 6; retry1++) {
        func_02157E54(ip);
        for (retry2 = 0; retry2 < g_021A1CA8[retry1] / 100; retry2++) {
            if (g_021A826C.myip == 0)
                return 0;
            func_02085A38(100);
            r = func_02157D8C(ip);
            if (r != 0)
                return r;
        }
    }
    return 0;
}
