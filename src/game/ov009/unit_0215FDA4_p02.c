/*
 * file:     unit_0215FDA4_p02.c
 * unit:     yes
 * function: func_0216009C, func_021600E4
 * address:  0x0216009C
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
 *   func_02085A30  0x02085A30  arm
 *   func_02085988  0x02085988  arm
 *   g_021A1D40  0x021A1D40  data
 *   g_02150FEC  0x02150FEC  data
 *   OS_SetThreadPriority  0x02085988  arm
 *   OSi_ThreadInfo        0x02150FEC  data
 */
typedef struct {
	int pad0;
	void *current;
} ThreadInfo;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct OSThread OSThread;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

extern void *func_02085A30(char *p);
extern int func_02085988(void *thread, unsigned long prio);
extern void OS_SetThreadPriority(OSThread *thread, u32 prio);
unsigned long func_0216009C(void);
extern unsigned long g_021A1D40[2];
extern ThreadInfo g_02150FEC;
extern OSThreadInfo OSi_ThreadInfo;


/*
 * sdk:      enter_computebound (libssl.TWL.HYB.a(ssl.o))
 */
unsigned long func_0216009C(void)
{
	unsigned long old_priority;
	void *thread;

	if (g_021A1D40[1] >= 32) {
		return -1;
	}
	thread = g_02150FEC.current;
	old_priority = (long unsigned int)func_02085A30(thread);
	func_02085988(thread, g_021A1D40[1]);
	return old_priority;
}


static void exit_computebound(unsigned long old_priority)
{
    if (old_priority >= 0x20)
        return;
    OS_SetThreadPriority(OSi_ThreadInfo.current, old_priority);
}
