/*
 * function: func_02084614
 * address:  0x02084614
 * packet:   pkt_02084614
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      OSi_IrqCallback (os_irqtable.o)
 *
 * symbols:
 *   OS_DisableIrqMask         0x02084998  arm
 *   OSi_IrqCallbackInfo       0x02150F38  data
 *   OSi_IrqCallbackInfoIndex  0x020A868C  data
 *   SDK_AUTOLOAD_DTCM_START   0x02FE0000  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];
extern u16 OSi_IrqCallbackInfoIndex[];
extern u32 OS_DisableIrqMask(u32 intr);

void func_02084614(int index)
{
    u32 imask = 1UL << OSi_IrqCallbackInfoIndex[index];
    void (*callback)(void *) = OSi_IrqCallbackInfo[index].func;

    OSi_IrqCallbackInfo[index].func = 0;
    if (callback) {
        callback(OSi_IrqCallbackInfo[index].arg);
    }

    OSi_IRQ_CHECK_FLAG |= imask;

    if (!OSi_IrqCallbackInfo[index].enable) {
        (void)OS_DisableIrqMask(imask);
    }
}
