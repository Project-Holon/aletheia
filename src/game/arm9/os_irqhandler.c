/*
 * file:     os_irqhandler.c
 * function: OS_WaitIrq, OS_IrqDummy
 * address:  0x0208459C
 * packet:   pkt_0208459C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      OS_WaitIrq (os_irqhandler.o)
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   OS_SleepThread           0x020857B0  arm
 *   SDK_AUTOLOAD_DTCM_START  0x02FE0000  data
 *   OSi_IrqThreadQueue       0x02FE00A0  data
 */

#include "../types.h"
#include "../sdk_os.h"

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

#include "../sdk_os_thread.h"

#include "os_system.h"
#include "os_thread.h"
extern OSThreadQueue OSi_IrqThreadQueue;

void OS_WaitIrq(BOOL clear, u32 irqFlags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (clear) {
        OSi_IRQ_CHECK_FLAG &= ~irqFlags;
    }
    (void)OS_RestoreInterrupts(enabled);

    while (!(irqFlags & OSi_IRQ_CHECK_FLAG)) {
        OS_SleepThread(&OSi_IrqThreadQueue);
    }
}

/* SDK name: OS_IrqDummy (os_irqhandler.o), the default empty IRQ handler. */
void OS_IrqDummy(void)
{
}
