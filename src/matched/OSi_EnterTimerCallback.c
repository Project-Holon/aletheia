/*
 * function: OSi_EnterTimerCallback
 * address:  0x020848F8
 * packet:   pkt_020848F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_interrupt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * OSi_IrqCallbackInfo (0x02150F38) is the 12-byte {func, enable, arg} table;
 * the timer entries start at index 8.
 *
 * symbols:
 *   OSi_IrqCallbackInfo  0x02150F38  data
 *   OS_EnableIrqMask     0x02084968  arm
 */

typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIrqMask;

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];
extern OSIrqMask OS_EnableIrqMask(OSIrqMask intr);

void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg)
{
    OSi_IrqCallbackInfo[timerNo + 8].func = callback;
    OSi_IrqCallbackInfo[timerNo + 8].arg = arg;
    (void)OS_EnableIrqMask((OSIrqMask)(1 << (timerNo + 3)));
    OSi_IrqCallbackInfo[timerNo + 8].enable = 1;
}
