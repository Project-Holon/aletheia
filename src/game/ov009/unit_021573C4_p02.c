/*
 * file:     unit_021573C4_p02.c
 * unit:     yes
 * function: func_02157630, func_02157640, func_021576C8, func_02157700, func_02157808, func_0215781C, func_02157838, func_02157888, func_021578C8, func_021578EC, func_02157928, func_0215793C
 * address:  0x02157630
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
 *   g_021A826C  0x021A826C  data
 *   func_021575DC  0x021575DC  arm  ov009
 *   func_02085710  0x02085710  arm
 *   func_020855BC  0x020855BC  arm
 *   func_020873F8  0x020873F8  arm
 *   func_02087988  0x02087988  arm
 *   func_0208574C  0x0208574C  arm
 *   func_02085868  0x02085868  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02157290  0x02157290  arm  ov009
 *   g_021A85E4  0x021A85E4  data
 *   g_021A86A4  0x021A86A4  data
 *   g_021A82FC  0x021A82FC  data
 *   g_021A8524  0x021A8524  data
 *   OS_SetThreadPriority             0x02085988 arm
 *   helper_threads_priority          0x021a1c98 data
 *   tcpip_thread                     0x021a86a4 data
 *   scavenger_thread                 0x021a85e4 data
 *   wfailed                          0x021a826c data
 *   func_021578EC  0x021578EC  arm  ov009
 */
#include "../../matched/include/G_021A85E4.h"
#include "../../matched/include/G_021A86A4.h"
#include "../../matched/include/G__OSThread.h"

extern int func_021575DC(void);
extern void func_02085710(void *thread);
extern void func_020855BC(void *thread);
extern void func_020873F8(void *alarm);
extern unsigned long func_02087988(void);
extern int func_0208574C(void *thread);
extern void func_02085868(void *thread);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02157290(int arg);
extern int OS_SetThreadPriority(void *thread, unsigned long prio);
extern unsigned long func_021578EC(unsigned long ip);
void func_02157630(int v);
/* * sdk: CPS_Cleanup (libcps.TWL.HYB.a(network.o)) */ void func_02157640(void);
void CPS_SetThreadPriority(unsigned long new_prio);
unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
/* * Maps the 0xffff sentinel onto itself and everything else onto its complement. */ unsigned int func_02157808(unsigned int x);
/* * The halfword the three-argument call lands on, tested. */ int func_0215781C(int a, int b);
/* * sdk: check_tcpudpsum (libcps.TWL.HYB.a(network.o)) */ unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
int func_02157928(unsigned v);
unsigned long func_0215793C(unsigned long ip);
extern char g_021A826C[];
extern struct G_021A85E4 g_021A85E4;
extern struct G_021A86A4 g_021A86A4;
extern char g_021A82FC[];
extern struct _OSThread g_021A8524;
extern unsigned long helper_threads_priority;
extern int tcpip_thread;
extern int scavenger_thread;
extern unsigned char wfailed;




/*
 * Stores a word at +0x34 of the module state block.
 */
void func_02157630(int v)
{
    *(int *)(g_021A826C + 0x34) = v;
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
    *(unsigned long *)(g_021A826C + 0x54) = 0;
    func_02157290(0);
    *(unsigned long *)(g_021A826C + 0x20) = 0;
    *(unsigned long *)(g_021A826C + 0x5c) = 0;
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
 * Maps the 0xffff sentinel onto itself and everything else onto its complement.
 */
unsigned int func_02157808(unsigned int x)
{
    unsigned int y = x ^ 0xffffu;

    return y ? y : 0xffffu;
}




/*
 * The halfword the three-argument call lands on, tested.
 */
int func_0215781C(int a, int b)
{
    return func_02157808((unsigned short)func_02157700((unsigned char *)a, b, 0));
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
    unsigned long my = *(unsigned long *)(g_021A826C + 0x50);
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
