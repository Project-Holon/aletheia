/*
 * function: enter_computebound
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
 *   OS_SetThreadPriority  0x02085988  arm
 *   gCpsSslConfig  0x021A1D40  data
 *   g_02150FEC  0x02150FEC  data
 */

typedef struct {
	int pad0;
	void *current;
} ThreadInfo;

extern void *OS_GetThreadPriority(char *p);
extern int OS_SetThreadPriority(void *thread, unsigned long prio);
extern unsigned long gCpsSslConfig[2];
extern ThreadInfo g_02150FEC;

unsigned long enter_computebound(void)
{
	unsigned long old_priority;
	void *thread;

	if (gCpsSslConfig[1] >= 32) {
		return -1;
	}
	thread = g_02150FEC.current;
	old_priority = (long unsigned int)OS_GetThreadPriority(thread);
	OS_SetThreadPriority(thread, gCpsSslConfig[1]);
	return old_priority;
}
