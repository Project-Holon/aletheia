/*
 * file:     unit_021573C4_p31.c
 * unit:     yes
 * function: func_0215BAC0, func_0215BBB0, func_0215BBF0, func_0215BC04
 * address:  0x0215BAC0
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
 *   func_02087988  0x02087988  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_020873F8  0x020873F8  arm
 *   func_0208738C  0x0208738C  arm
 *   func_0208799C  0x0208799C  arm
 *   g_02150FEC     0x02150FEC  data
 *   g_021A82FC     0x021A82FC  data
 *   func_0215BBF0  0x0215BBF0  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   func_020857B0  0x020857B0  arm
 *   g_021A85E4  0x021A85E4  data
 *   dacktimer_thread                 0x021a8524 data ov009
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A82D4               0x021A82D4  data
 *   g_021A1CCC               0x021A1CCC  data
 */
#include "../../matched/include/G_021A85E4.h"

struct _CPSSoc {
	unsigned long first;
	unsigned char pad0[4];
	unsigned char state;
	unsigned char pad1[0x23];
	unsigned long tick_acked;
	unsigned char pad2[2];
	unsigned char ack_pending;
};

struct _OSThread {
	unsigned char pad0[0x68];
	struct _OSThread *next;
	unsigned char pad1[0x38];
	struct _CPSSoc *soc;
};

struct ThreadInfo {
	unsigned char pad0[8];
	struct _OSThread *list;
};

extern unsigned long func_02087988(void);
extern unsigned long long func_020870D0(void);
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
void func_0215BAC0(void);
/* * sdk: dacktimer (libcps.TWL.HYB.a(network.o)) */ void func_0215BBB0(void);
void dacktimer_alarmhandler(void);
unsigned char *func_0215BC04(unsigned char *d, int type);
extern struct ThreadInfo g_02150FEC;
extern unsigned char g_021A82FC[];
extern struct G_021A85E4 g_021A85E4;
extern unsigned char dacktimer_thread[];
extern unsigned char g_021A826C;
extern unsigned char g_021A82D4[6];
extern char g_021A1CCC[];



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
		soc = t->soc;
		if (soc != 0 && soc->first != 0 && soc->state == 4 && soc->ack_pending != 0) {
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
	OS_WakeupThreadDirect(dacktimer_thread);
}


#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))


/*
 * sdk:      dhcp_setcommon (libcps.TWL.HYB.a network.o)
 */
unsigned char *func_0215BC04(unsigned char *d, int type)
{
	MI_CpuFill8(d, 0, 0xec);
	*(unsigned short *)(d + 0) = 0x0101;
	d[2] = 6;
	*(unsigned short *)(d + 4) = SWAP16((unsigned short)(NV(0x30, unsigned long) >> 16));
	*(unsigned short *)(d + 6) = SWAP16((unsigned short)NV(0x30, unsigned long));
	*(unsigned short *)(d + 12) = SWAP16((unsigned short)(NV(0x50, unsigned long) >> 16));
	*(unsigned short *)(d + 14) = SWAP16((unsigned short)NV(0x50, unsigned long));
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
