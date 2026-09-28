/*
 * function: func_02085638
 * address:  0x02085638
 * packet:   pkt_02085638
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_thread.o OS_KillThread.
 *
 * symbols:
 *   OS_GetThreadPriority       0x02085A30  arm
 *   OS_KillThreadWithPriority  0x0208565C  arm
 */

int OS_GetThreadPriority(const void *thread);
void OS_KillThreadWithPriority(void *thread, void *arg, int priority);

void func_02085638(void *thread, void *arg)
{
    OS_KillThreadWithPriority(thread, arg, OS_GetThreadPriority(thread));
}
