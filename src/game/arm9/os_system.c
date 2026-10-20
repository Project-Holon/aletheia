/*
 * file:     os_system.c
 * unit:     yes
 * function: OS_EnableInterrupts, OS_DisableInterrupts, OS_RestoreInterrupts, OS_DisableInterrupts_IrqAndFiq, OS_RestoreInterrupts_IrqAndFiq, OS_GetCpsrIrq, OS_GetProcMode, OS_SpinWaitCpuCycles, OS_SpinWaitSysCycles, OS_WaitInterrupt, OS_WaitVBlankIntr
 * address:  0x02087974
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_SpinWaitCpuCycles           0x020879F8  arm
 *   OS_Halt                        0x020882D0  arm
 *   SDK_AUTOLOAD_DTCM_START        0x02FE0000  data
 *   SVC_WaitByLoop                  0x02004490  thumb
 *   OS_WaitIrq                  0x0208459C  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_os.h"

extern void OS_SpinWaitCpuCycles(u32 cycle);
asm OSIntrMode OS_EnableInterrupts(void);
asm OSIntrMode OS_DisableInterrupts(void);
asm OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
asm OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
asm OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
asm unsigned int OS_GetCpsrIrq(void);
asm unsigned int OS_GetProcMode(void);
void OS_SpinWaitSysCycles(u32 cycle);
#include "os_terminate_processor.h"
extern char SDK_AUTOLOAD_DTCM_START[];
#include "svc_wait_by_loop.h"
#include "os_irqhandler.h"

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm OSIntrMode OS_EnableInterrupts(void)
{
    mrs	r0, cpsr
    bic	r1, r0, #0x80
    msr	cpsr_c, r1
    and	r0, r0, #0x80
    bx	lr
}

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm OSIntrMode OS_DisableInterrupts(void)
{
    mrs	r0, cpsr
    orr	r1, r0, #0x80
    msr	cpsr_c, r1
    and	r0, r0, #0x80
    bx	lr
}

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm OSIntrMode OS_RestoreInterrupts(OSIntrMode state)
{
    mrs	r1, cpsr
    bic	r2, r1, #0x80
    orr	r2, r2, r0
    msr	cpsr_c, r2
    and	r0, r1, #0x80
    bx	lr
}

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm OSIntrMode OS_DisableInterrupts_IrqAndFiq(void)
{
    mrs	r0, cpsr
    orr	r1, r0, #0xc0
    msr	cpsr_c, r1
    and	r0, r0, #0xc0
    bx	lr
}

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state)
{
    mrs	r1, cpsr
    bic	r2, r1, #0xc0
    orr	r2, r2, r0
    msr	cpsr_c, r2
    and	r0, r1, #0xc0
    bx	lr
}

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm unsigned int OS_GetCpsrIrq(void)
{
    mrs r0, cpsr
    and r0, r0, #0x80
    bx lr
}

/* hand-written in the original: mrs/msr on CPSR, one SDK line-table row per instruction */
asm unsigned int OS_GetProcMode(void)
{
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}

/* hand-written in the original: SDK OS_SpinWaitCpuCycles, cycle-exact subs/bhs delay loop */
asm void OS_SpinWaitCpuCycles(u32 cycle)
{
    subs	r0, r0, #4
    bhs	OS_SpinWaitCpuCycles
    bx	lr
}

#define reg_SCFG_CLK (*(vu16 *)REG_SCFG_CLK_ADDR)

void OS_SpinWaitSysCycles(u32 cycle)
{
    cycle <<= ((reg_SCFG_CLK & 1) == 1) ? 2 : 1;
    if (cycle > 16) {
        OS_SpinWaitCpuCycles(cycle - 16);
    }
}

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((uptr)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

#define reg_OS_IME (*(volatile u16 *)REG_IME_ADDR)

static inline BOOL OS_EnableIrq(void)
{
    u16 prep = reg_OS_IME;

    reg_OS_IME = 1;
    return (BOOL)prep;
}

static inline BOOL OS_RestoreIrq(BOOL enable)
{
    u16 prep = reg_OS_IME;

    reg_OS_IME = (u16)enable;
    return (BOOL)prep;
}

/*
 * sdk:      OS_WaitInterrupt (os_system.o)
 */
void OS_WaitInterrupt(BOOL clear, u32 irqFlags)
{
    OSIntrMode cpsrIrq = OS_DisableInterrupts();
    BOOL prevIrq = OS_EnableIrq();

    if (clear) {
        OSi_IRQ_CHECK_FLAG &= ~irqFlags;
    }

    while (!(irqFlags & OSi_IRQ_CHECK_FLAG)) {
        OS_Halt();
        (void)OS_EnableInterrupts();
        (void)OS_DisableInterrupts();
    }

    OSi_IRQ_CHECK_FLAG &= ~irqFlags;

    (void)OS_RestoreIrq(prevIrq);
    (void)OS_RestoreInterrupts(cpsrIrq);
}

void OS_WaitVBlankIntr(void)
{
    SVC_WaitByLoop(1);
    OS_WaitIrq(1, 1);
}
