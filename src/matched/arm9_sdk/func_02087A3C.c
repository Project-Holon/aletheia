/*
 * function: OS_WaitInterrupt
 * address:  0x02087A3C
 * packet:   pkt_02087A3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_WaitInterrupt (os_system.o)
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   OS_EnableInterrupts      0x02087974  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   OS_Halt                  0x020882D0  arm
 *   SDK_AUTOLOAD_DTCM_START  0x02FE0000  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_EnableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_Halt(void);

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
