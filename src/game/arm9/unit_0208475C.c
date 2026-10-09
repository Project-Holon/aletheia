/*
 * file:     unit_0208475C.c
 * unit:     yes
 * function: func_0208475C, func_02084774, OS_GetIrqFunction, OSi_EnterDmaCallback, OSi_EnterNDmaCallback, OSi_EnterTimerCallback, OS_SetIrqMask, OS_EnableIrqMask, OS_DisableIrqMask, func_020849C8, func_020849F4
 * address:  0x0208475C
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
 *   g_02FE00A0  0x02FE00A0  data  a4
 *   g_02150F38                     0x02150F38  data
 *   g_02FE0020                     0x02FE0020  data
 *   OSi_EnterNDmaCallback_ltdmain  0x0273126C  arm
 *   OSi_IrqCallbackInfo  0x02150F38  data
 *   SDK_AUTOLOAD_DTCM_START        0x02FE0000  data
 *   SDK_IRQ_STACKSIZE              0x00000800  data
 */
#define OSi_IrqCallbackInfo g_02150F38
#define OS_IRQTable g_02FE0020
#define reg_OS_IME (*(vu16 *)0x04000208)
#define reg_OS_IE  (*(vu32 *)0x04000210)
#define reg_OS_IF  (*(vu32 *)0x04000214)
#define OSi_IRQ_STACK_TOP ((u32)SDK_AUTOLOAD_DTCM_START + 0x3F80)
typedef unsigned long u32;

typedef int BOOL;

typedef u32 OSIrqMask;

typedef void (*OSIrqFunction)(void);

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

typedef unsigned short u16;

typedef volatile u32 vu32;

typedef volatile u16 vu16;

extern void OSi_EnterNDmaCallback_ltdmain(u32 dmaNo, void (*callback)(void *), void *arg);
void func_0208475C(void);
void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function);
OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit);
void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg);
void OSi_EnterNDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg);
void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg);
OSIrqMask OS_SetIrqMask(OSIrqMask intr);
OSIrqMask OS_EnableIrqMask(OSIrqMask intr);
OSIrqMask OS_DisableIrqMask(OSIrqMask intr);
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr);
void OS_SetIrqStackChecker(void);
extern int g_02FE00A0[2];
extern OSIrqCallbackInfo g_02150F38[];   /* OSi_IrqCallbackInfo */
extern OSIrqFunction g_02FE0020[];       /* OS_IRQTable (DTCM) */
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];
extern char SDK_AUTOLOAD_DTCM_START[];
extern char SDK_IRQ_STACKSIZE[];






/*
 * note:     os_interrupt.o OS_InitIrqTable (zeroes OSi_IrqThreadQueue).
 */
void func_0208475C(void)
{
    g_02FE00A0[1] = 0;
    g_02FE00A0[0] = 0;
}



void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function)
{
    int i;
    OSIrqCallbackInfo *info;

    for (i = 0; i < 32; i++) {
        if (intrBit & 1) {
            info = 0;

            if (8 <= i && i <= 11) {
                info = &OSi_IrqCallbackInfo[i - 8];
            } else if (0x1C <= i && i <= 0x1F) {
                info = &OSi_IrqCallbackInfo[i - 0x18];
            } else if (3 <= i && i <= 6) {
                info = &OSi_IrqCallbackInfo[i - 3 + 8];
            } else {
                OS_IRQTable[i] = function;
            }

            if (info) {
                info->func = (void (*)(void *))function;
                info->arg = 0;
                info->enable = 1;
            }
        }
        intrBit >>= 1;
    }
}



OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit)
{
    int i;
    OSIrqFunction *funcPtr = &OS_IRQTable[0];

    for (i = 0; i < 32; i++) {
        if (intrBit & 1) {
            if (8 <= i && i <= 11) {
                return (OSIrqFunction)OSi_IrqCallbackInfo[i - 8].func;
            } else if (3 <= i && i <= 6) {
                return (OSIrqFunction)OSi_IrqCallbackInfo[i - 3 + 8].func;
            }
            return *funcPtr;
        }
        intrBit >>= 1;
        funcPtr++;
    }
    return 0;
}



void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg)
{
    OSIrqMask imask = (OSIrqMask)(1 << (dmaNo + 8));

    OSi_IrqCallbackInfo[dmaNo].func = callback;
    OSi_IrqCallbackInfo[dmaNo].arg = arg;
    OSi_IrqCallbackInfo[dmaNo].enable = OS_EnableIrqMask(imask) & imask;
}



void OSi_EnterNDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg)
{
    OSi_EnterNDmaCallback_ltdmain(dmaNo, callback, arg);
}






void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg)
{
    OSi_IrqCallbackInfo[timerNo + 8].func = callback;
    OSi_IrqCallbackInfo[timerNo + 8].arg = arg;
    (void)OS_EnableIrqMask((OSIrqMask)(1 << (timerNo + 3)));
    OSi_IrqCallbackInfo[timerNo + 8].enable = 1;
}






static inline BOOL OS_DisableIrq(void)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = 0;
    return (BOOL)prep;
}






static inline BOOL OS_RestoreIrq(BOOL enable)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = (u16)enable;
    return (BOOL)prep;
}






OSIrqMask OS_SetIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IE;
    reg_OS_IE = intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}





OSIrqMask OS_EnableIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IE;
    reg_OS_IE = prep | intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}




OSIrqMask OS_DisableIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IE;
    reg_OS_IE = prep & ~intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}




OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IF;
    reg_OS_IF = intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}




void OS_SetIrqStackChecker(void)
{
    *(u32 *)(OSi_IRQ_STACK_TOP - sizeof(u32)) = 0xFDDB597D;
    *(u32 *)(OSi_IRQ_STACK_TOP - (u32)SDK_IRQ_STACKSIZE) = 0x7BF9DD5B;
}
