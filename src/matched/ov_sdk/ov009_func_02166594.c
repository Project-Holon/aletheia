/*
 * function: WCMi_CpsifUnlockMutexInIRQ
 * address:  0x02166594
 * packet:   pkt_ov009_02166594
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_CpsifUnlockMutexInIRQ (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   OS_WakeupThread  0x02085800  arm
 *   OS_IrqHandler  0x01FF80F0  data
 *
 * Releases a mutex from IRQ context: drops one lock level owned by the IRQ handler and wakes waiters.
 */

typedef struct OSMutex {
    unsigned long queue;
    unsigned long queue2;
    void *thread;
    long count;
} OSMutex;

extern int OS_IrqHandler;
extern void OS_WakeupThread(void *queue);

void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex)
{
    if (mutex->thread == (void *)&OS_IrqHandler) {
        if (--mutex->count == 0) {
            mutex->thread = 0;
            OS_WakeupThread(mutex);
        }
    }
}
