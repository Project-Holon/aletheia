/*
 * file:     unit_02166384_p02.c
 * unit:     yes
 * function: func_02166594, func_021665CC
 * address:  0x02166594
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
 *   OS_WakeupThread  0x02085800  arm
 *   OS_IrqHandler  0x01FF80F0  data
 *   MI_CpuCopy                   0x02082EA4  arm
 */
typedef struct OSMutex {
    unsigned long queue;
    unsigned long queue2;
    void *thread;
    long count;
} OSMutex;

extern void OS_WakeupThread(void *queue);
extern void MI_CpuCopy(void);
void func_02166594(OSMutex *mutex);
asm void WCMi_CpsifSetMacAddress(void);
extern int OS_IrqHandler;


/*
 * sdk:      WCMi_CpsifUnlockMutexInIRQ (libwcm.TWL.HYB.a cpsif.o)
 *
 * Releases a mutex from IRQ context: drops one lock level owned by the IRQ handler and wakes waiters.
 */
void func_02166594(OSMutex *mutex)
{
    if (mutex->thread == (void *)&OS_IrqHandler) {
        if (--mutex->count == 0) {
            mutex->thread = 0;
            OS_WakeupThread(mutex);
        }
    }
}


asm void WCMi_CpsifSetMacAddress(void)
{
	ldr r1, =0x021AA80C
	ldr ip, =MI_CpuCopy
	mov r2, #6
	bx ip
}
