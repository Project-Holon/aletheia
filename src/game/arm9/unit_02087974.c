/*
 * file:     unit_02087974.c
 * unit:     yes
 * function: func_02087974, func_02087988, func_0208799C, func_020879B4, func_020879C8, func_020879E0, func_020879EC, func_020879F8, OS_SpinWaitSysCycles, func_02087A3C, func_02087AE4
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
 *   func_02004490                  0x02004490  thumb
 *   func_0208459C                  0x0208459C  arm
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef volatile u16 vu16;

extern void OS_SpinWaitCpuCycles(u32 cycle);
asm OSIntrMode OS_EnableInterrupts(void);
asm OSIntrMode OS_DisableInterrupts(void);
asm OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
asm void OS_DisableInterrupts_IrqAndFiq(void);
asm void OS_RestoreInterrupts_IrqAndFiq(void);
asm unsigned int OS_GetCpsrIrq(void);
asm unsigned int OS_GetProcMode(void);
asm void func_020879F8(void);
void OS_SpinWaitSysCycles(u32 cycle);
extern void OS_Halt(void);
extern char SDK_AUTOLOAD_DTCM_START[];
extern void func_02004490(int v);
extern void func_0208459C(int clear, u32 irqFlags);



asm OSIntrMode OS_EnableInterrupts(void)
{
    mrs	r0, cpsr
    bic	r1, r0, #0x80
    msr	cpsr_c, r1
    and	r0, r0, #0x80
    bx	lr
}



asm OSIntrMode OS_DisableInterrupts(void)
{
    mrs	r0, cpsr
    orr	r1, r0, #0x80
    msr	cpsr_c, r1
    and	r0, r0, #0x80
    bx	lr
}



asm OSIntrMode OS_RestoreInterrupts(OSIntrMode state)
{
    mrs	r1, cpsr
    bic	r2, r1, #0x80
    orr	r2, r2, r0
    msr	cpsr_c, r2
    and	r0, r1, #0x80
    bx	lr
}



asm void OS_DisableInterrupts_IrqAndFiq(void)
{
    mrs	r0, cpsr
    orr	r1, r0, #0xc0
    msr	cpsr_c, r1
    and	r0, r0, #0xc0
    bx	lr
}



asm void OS_RestoreInterrupts_IrqAndFiq(void)
{
    mrs	r1, cpsr
    bic	r2, r1, #0xc0
    orr	r2, r2, r0
    msr	cpsr_c, r2
    and	r0, r1, #0xc0
    bx	lr
}



asm unsigned int OS_GetCpsrIrq(void)
{
    mrs r0, cpsr
    and r0, r0, #0x80
    bx lr
}



asm unsigned int OS_GetProcMode(void)
{
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}




/* hand-written in the original: SDK OS_SpinWaitCpuCycles, cycle-exact subs/bhs delay loop */
asm void func_020879F8(void)
{
    subs	r0, r0, #4
    bhs	func_020879F8
    bx	lr
}


#define reg_SCFG_CLK (*(vu16 *)0x04004004)


void OS_SpinWaitSysCycles(u32 cycle)
{
    cycle <<= ((reg_SCFG_CLK & 1) == 1) ? 2 : 1;
    if (cycle > 16) {
        OS_SpinWaitCpuCycles(cycle - 16);
    }
}

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))


#define reg_OS_IME (*(volatile u16 *)0x04000208)

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
void func_02087A3C(BOOL clear, u32 irqFlags)
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

void func_02087AE4(void)
{
    func_02004490(1);
    func_0208459C(1, 1);
}
