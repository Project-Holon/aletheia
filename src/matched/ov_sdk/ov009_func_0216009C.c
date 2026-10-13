/*
 * function: func_0216009C
 * address:  0x0216009C
 * packet:   pkt_ov009_0216009C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      enter_computebound (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   OS_GetThreadPriority  0x02085A30  arm
 *   func_02085988  0x02085988  arm
 *   g_021A1D40  0x021A1D40  data
 *   g_02150FEC  0x02150FEC  data
 */

typedef struct {
	int pad0;
	void *current;
} ThreadInfo;

extern void *OS_GetThreadPriority(char *p);
extern int func_02085988(void *thread, unsigned long prio);
extern unsigned long g_021A1D40[2];
extern ThreadInfo g_02150FEC;

unsigned long func_0216009C(void)
{
	unsigned long old_priority;
	void *thread;

	if (g_021A1D40[1] >= 32) {
		return -1;
	}
	thread = g_02150FEC.current;
	old_priority = (long unsigned int)OS_GetThreadPriority(thread);
	func_02085988(thread, g_021A1D40[1]);
	return old_priority;
}
