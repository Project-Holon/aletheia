/*
 * function: exit_computebound
 * address:  0x021600E4
 * packet:   pkt_ov009_021600E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      exit_computebound (ssl.o)
 *
 * symbols:
 *   OS_SetThreadPriority  0x02085988  arm
 *   OSi_ThreadInfo        0x02150FEC  data
*/

typedef unsigned short u16;
typedef unsigned long u32;

typedef struct OSThread OSThread;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

extern OSThreadInfo OSi_ThreadInfo;
extern void OS_SetThreadPriority(OSThread *thread, u32 prio);

static void exit_computebound(unsigned long old_priority)
{
    if (old_priority >= 0x20)
        return;
    OS_SetThreadPriority(OSi_ThreadInfo.current, old_priority);
}
