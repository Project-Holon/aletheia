/*
 * function: dacktimer_reschedule
 * address:  0x0215BAC0
 * packet:   pkt_ov009_0215BAC0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dacktimer_reschedule (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_020870D0  0x020870D0  arm
 *   _tcp_send_ack  0x02159404  arm  ov009
 *   OS_CancelAlarm  0x020873F8  arm
 *   func_0208738C  0x0208738C  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_02150FEC     0x02150FEC  data
 *   g_021A82FC     0x021A82FC  data
 *   dacktimer_alarmhandler  0x0215BBF0  arm  ov009
 */

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

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long long func_020870D0(void);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);
extern void OS_CancelAlarm(void *alarm);
extern void func_0208738C(void *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void dacktimer_alarmhandler(void *arg);
extern struct ThreadInfo g_02150FEC;
extern unsigned char g_021A82FC[];

void dacktimer_reschedule(void)
{
	unsigned long nextdelay = 0xffffffff;
	unsigned long diff;
	struct _CPSSoc *soc;
	struct _OSThread *t;
	unsigned long enabled;
	unsigned long tick;

	enabled = OS_DisableInterrupts();
	tick = (unsigned long)func_020870D0();
	for (t = g_02150FEC.list; t != 0; t = t->next) {
		soc = t->soc;
		if (soc != 0 && soc->first != 0 && soc->state == 4 && soc->ack_pending != 0) {
			diff = tick - soc->tick_acked;
			if (diff >= 0x1991b) {
				_tcp_send_ack(soc, 1);
			} else if (0x1991bULL - diff < nextdelay) {
				nextdelay = 0x1991b - diff;
			}
		}
	}
	if (nextdelay != 0xffffffff) {
		OS_CancelAlarm(g_021A82FC);
		func_0208738C(g_021A82FC, nextdelay, dacktimer_alarmhandler, 0);
	}
	OS_RestoreInterrupts(enabled);
}
