/*
 * function: OS_RescheduleThread
 * address:  0x020858BC
 * packet:   pkt_020858BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_thread.o OS_RescheduleThread.
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988  arm
 *   OSi_RescheduleThread   0x020851A0  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 */

int OS_DisableInterrupts(void);
void OSi_RescheduleThread(void);
int OS_RestoreInterrupts(int last);

void OS_RescheduleThread(void)
{
    int bak_intr = OS_DisableInterrupts();
    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(bak_intr);
}
