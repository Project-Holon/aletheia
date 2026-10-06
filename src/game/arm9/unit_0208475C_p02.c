/*
 * file:     unit_0208475C_p02.c
 * unit:     yes
 * function: OSi_EnterTimerCallback, OS_SetIrqMask, OS_EnableIrqMask, OS_DisableIrqMask, func_020849C8, func_020849F4
 * address:  0x020848F8
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
 *   OSi_IrqCallbackInfo  0x02150F38  data
 *   SDK_AUTOLOAD_DTCM_START        0x02FE0000  data
 *   SDK_IRQ_STACKSIZE              0x00000800  data
 */
typedef unsigned long u32;

typedef int BOOL;

typedef u32 OSIrqMask;

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

typedef unsigned short u16;

typedef volatile u32 vu32;

typedef volatile u16 vu16;

void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg);
OSIrqMask OS_SetIrqMask(OSIrqMask intr);
OSIrqMask OS_EnableIrqMask(OSIrqMask intr);
OSIrqMask OS_DisableIrqMask(OSIrqMask intr);
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr);
void OS_SetIrqStackChecker(void);
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];
extern char SDK_AUTOLOAD_DTCM_START[];
extern char SDK_IRQ_STACKSIZE[];





void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg)
{
    OSi_IrqCallbackInfo[timerNo + 8].func = callback;
    OSi_IrqCallbackInfo[timerNo + 8].arg = arg;
    (void)OS_EnableIrqMask((OSIrqMask)(1 << (timerNo + 3)));
    OSi_IrqCallbackInfo[timerNo + 8].enable = 1;
}





#define reg_OS_IME (*(vu16 *)0x04000208)




#define reg_OS_IE  (*(vu32 *)0x04000210)




#define reg_OS_IF  (*(vu32 *)0x04000214)





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




#define reg_OS_IME (*(vu16 *)0x04000208)



#define reg_OS_IE  (*(vu32 *)0x04000210)




OSIrqMask OS_EnableIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IE;
    reg_OS_IE = prep | intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}



#define reg_OS_IME (*(vu16 *)0x04000208)


#define reg_OS_IE  (*(vu32 *)0x04000210)


#define reg_OS_IF  (*(vu32 *)0x04000214)



OSIrqMask OS_DisableIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IE;
    reg_OS_IE = prep & ~intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}



#define reg_OS_IME (*(vu16 *)0x04000208)


#define reg_OS_IE  (*(vu32 *)0x04000210)


#define reg_OS_IF  (*(vu32 *)0x04000214)



OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IF;
    reg_OS_IF = intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}



#define OSi_IRQ_STACK_TOP ((u32)SDK_AUTOLOAD_DTCM_START + 0x3F80)



void OS_SetIrqStackChecker(void)
{
    *(u32 *)(OSi_IRQ_STACK_TOP - sizeof(u32)) = 0xFDDB597D;
    *(u32 *)(OSi_IRQ_STACK_TOP - (u32)SDK_IRQ_STACKSIZE) = 0x7BF9DD5B;
}
