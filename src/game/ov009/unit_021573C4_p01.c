/*
 * file:     unit_021573C4_p01.c
 * unit:     yes
 * function: func_02157640, func_021576C8, func_02157700
 * address:  0x02157640
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
 *   g_021A826C  0x021A826C  data
 *   OS_SetThreadPriority             0x02085988 arm
 *   helper_threads_priority          0x021a1c98 data
 *   tcpip_thread                     0x021a86a4 data
 *   scavenger_thread                 0x021a85e4 data
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
void func_02157640(void);
void CPS_SetThreadPriority(unsigned long new_prio);
unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
extern struct G_021A85E4 g_021A85E4;
extern struct G_021A86A4 g_021A86A4;
extern char g_021A82FC[];
extern struct _OSThread g_021A8524;
extern char g_021A826C[];
extern unsigned long helper_threads_priority;
extern int tcpip_thread;
extern int scavenger_thread;


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
